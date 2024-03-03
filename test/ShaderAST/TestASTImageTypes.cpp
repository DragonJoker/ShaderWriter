#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	std::string getName( ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS
		, bool isDepth )
	{
		return ast::debug::getImageTypeName( format
			, accessKind
			, dimension
			, isSampled
			, isArrayed
			, isMS
			, isDepth );
	}

	ast::type::ImageConfiguration makeConfig( ast::type::TypesCache & typesCache
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		return ast::type::ImageConfiguration{ typesCache.getSampledType( format )->getKind()
			, dimension
			, format
			, isSampled
			, isArrayed
			, isMS
			, accessKind };
	}

	bool operator==( ast::type::ImageConfiguration const & lhs
		, ast::type::ImageConfiguration const & rhs )noexcept
	{
		return lhs.sampledType == rhs.sampledType
			&& lhs.dimension == rhs.dimension
			&& lhs.format == rhs.format
			&& lhs.isSampled == rhs.isSampled
			&& lhs.isArrayed == rhs.isArrayed
			&& lhs.isMS == rhs.isMS
			&& lhs.accessKind == rhs.accessKind;
	}
	void testImage( test::TestCounts & testCounts
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		testBegin( "testImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS, false ) );
		ast::type::TypesCache typesCache;
		auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
		auto type = typesCache.getImage( config );
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getRawKind() == ast::type::Kind::eImage )
		check( type->getKind() == ast::type::Kind::eImage )
		check( type->getConfig() == config )

		auto type2 = typesCache.getImage( config );
		check( type2 == type )
		testEnd()
	}

	void testSampledImage( test::TestCounts & testCounts
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		testBegin( "testSampledImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS, false ) );
		ast::type::TypesCache typesCache;
		auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
		auto type = typesCache.getSampledImage( config, ast::type::Trinary::eTrue );
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getRawKind() == ast::type::Kind::eSampledImage )
		check( type->getKind() == ast::type::Kind::eSampledImage )
		check( type->getDepth() == ast::type::Trinary::eTrue )
		check( type->getImageType() == typesCache.getImage( config ) )
		check( type->getConfig() == config )
		{
			auto type2 = typesCache.getSampledImage( config, ast::type::Trinary::eTrue );
			check( type2 == type )
			type->updateComparison( false );
			check( type->getDepth() == ast::type::Trinary::eDontCare )
		}
		{
			ast::type::SampledImage sampled{ typesCache, config, ast::type::Trinary::eTrue };
			sampled.updateComparison( true );
			check( sampled.getDepth() == ast::type::Trinary::eTrue )
		}
		{
			ast::type::SampledImage sampled{ typesCache, config, ast::type::Trinary::eDontCare };
			sampled.updateComparison( false );
			check( sampled.getDepth() == ast::type::Trinary::eDontCare )
		}
		{
			ast::type::SampledImage sampled{ typesCache, config, ast::type::Trinary::eDontCare };
			sampled.updateComparison( true );
			check( sampled.getDepth() == ast::type::Trinary::eDontCare )
		}
		{
			ast::type::SampledImage sampled{ typesCache, config, ast::type::Trinary::eFalse };
			sampled.updateComparison( false );
			check( sampled.getDepth() == ast::type::Trinary::eFalse )
		}
		{
			ast::type::SampledImage sampled{ typesCache, config, ast::type::Trinary::eFalse };
			sampled.updateComparison( true );
			check( sampled.getDepth() == ast::type::Trinary::eDontCare )
		}

		testEnd()
	}

	void testCombinedImage( test::TestCounts & testCounts
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS
		, bool isDepth )
	{
		testBegin( "testCombinedImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS, isDepth ) );
		{
			ast::type::TypesCache typesCache;
			auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
			auto type = typesCache.getCombinedImage( config, isDepth );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eCombinedImage )
			check( type->getKind() == ast::type::Kind::eCombinedImage )
			check( type->getImageType() == typesCache.getImage( config ) )
			check( type->getSamplerType() == typesCache.getSampler( isDepth ) )
			check( type->getConfig() == config )
			check( type->isComparison() == isDepth )

			auto type2 = typesCache.getCombinedImage( config, isDepth );
			check( type2 == type )
		}
		testEnd()
	}
}

testSuiteMain( TestASTImageTypes )
{
	testSuiteBegin()
	for ( uint8_t dim = uint8_t( ast::type::ImageDim::eMin ); dim <= uint8_t( ast::type::ImageDim::eMax ); ++dim )
	{
		for ( uint8_t fmt = uint8_t( ast::type::ImageFormat::eMin ); fmt <= uint8_t( ast::type::ImageFormat::eMax ); ++fmt )
		{
			for ( uint8_t spl = uint8_t( ast::type::Trinary::eMin ); spl <= uint8_t( ast::type::Trinary::eMax ); ++spl )
			{
				for ( uint8_t acc = uint8_t( ast::type::AccessKind::eMin ); acc <= uint8_t( ast::type::AccessKind::eMax ); ++acc )
				{
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, false );
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, true );
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, false );
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, true );
				}
			}
		}
	}
	testSampledImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, false, false );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, false, false, false );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, false, false, true );
	testSampledImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, false, true );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, false, true, false );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, false, true, true );
	testSampledImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, true, false );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, true, false, false );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, true, false, true );
	testSampledImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, true, true );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, true, true, false );
	testCombinedImage( testCounts, ast::type::ImageDim::e2D, ast::type::ImageFormat::eRgba32f, ast::type::Trinary::eTrue, ast::type::AccessKind::eRead, true, true, true );
	testSuiteEnd()
}

testSuiteLaunch( TestASTImageTypes )
