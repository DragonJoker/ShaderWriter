#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;

	std::string getName( type::ImageDim dimension
		, type::ImageFormat format
		, type::Trinary isSampled
		, type::AccessKind accessKind
		, bool isArrayed
		, bool isMS
		, bool isDepth )
	{
		return debug::getImageTypeName( format
			, accessKind
			, dimension
			, isSampled
			, isArrayed
			, isMS
			, isDepth );
	}

	type::ImageConfiguration makeConfig( type::TypesCache & typesCache
		, type::ImageDim dimension
		, type::ImageFormat format
		, type::Trinary isSampled
		, type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		return type::ImageConfiguration{ typesCache.getSampledType( format )->getKind()
			, dimension
			, format
			, isSampled
			, isArrayed
			, isMS
			, accessKind };
	}

	bool operator==( type::ImageConfiguration const & lhs
		, type::ImageConfiguration const & rhs )noexcept
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
		, type::ImageDim dimension
		, type::ImageFormat format
		, type::Trinary isSampled
		, type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		astTestBegin( "testImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS, false ) );
		type::TypesCache typesCache;
		auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
		auto type = typesCache.getImage( config );
		astCheckNoThrow( debug::getTypeName( type ) )
		astCheckNoThrow( debug::getTypeName( type->getKind() ) )
		astCheck( type->getRawKind() == type::Kind::eImage )
		astCheck( type->getKind() == type::Kind::eImage )
		astCheck( type->getConfig() == config )

		auto type2 = typesCache.getImage( config );
		astCheck( type2 == type )
		astTestEnd()
	}

	void testSampledImage( test::TestCounts & testCounts
		, type::ImageDim dimension
		, type::ImageFormat format
		, type::Trinary isSampled
		, type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		astTestBegin( "testSampledImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS, false ) );
		type::TypesCache typesCache;
		auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
		auto type = typesCache.getSampledImage( config, type::Trinary::eTrue );
		astCheckNoThrow( debug::getTypeName( type ) )
		astCheckNoThrow( debug::getTypeName( type->getKind() ) )
		astCheck( type->getRawKind() == type::Kind::eSampledImage )
		astCheck( type->getKind() == type::Kind::eSampledImage )
		astCheck( type->getDepth() == type::Trinary::eTrue )
		astCheck( type->getImageType() == typesCache.getImage( config ) )
		astCheck( type->getConfig() == config )
		{
			auto type2 = typesCache.getSampledImage( config, type::Trinary::eTrue );
			astCheck( type2 == type )
			type->updateComparison( false );
			astCheck( type->getDepth() == type::Trinary::eDontCare )
		}
		{
			type::SampledImage sampled{ typesCache, config, type::Trinary::eTrue };
			sampled.updateComparison( true );
			astCheck( sampled.getDepth() == type::Trinary::eTrue )
		}
		{
			type::SampledImage sampled{ typesCache, config, type::Trinary::eDontCare };
			sampled.updateComparison( false );
			astCheck( sampled.getDepth() == type::Trinary::eDontCare )
		}
		{
			type::SampledImage sampled{ typesCache, config, type::Trinary::eDontCare };
			sampled.updateComparison( true );
			astCheck( sampled.getDepth() == type::Trinary::eDontCare )
		}
		{
			type::SampledImage sampled{ typesCache, config, type::Trinary::eFalse };
			sampled.updateComparison( false );
			astCheck( sampled.getDepth() == type::Trinary::eFalse )
		}
		{
			type::SampledImage sampled{ typesCache, config, type::Trinary::eFalse };
			sampled.updateComparison( true );
			astCheck( sampled.getDepth() == type::Trinary::eDontCare )
		}

		astTestEnd()
	}

	void testCombinedImage( test::TestCounts & testCounts
		, type::ImageDim dimension
		, type::ImageFormat format
		, type::Trinary isSampled
		, type::AccessKind accessKind
		, bool isArrayed
		, bool isMS
		, bool isDepth )
	{
		astTestBegin( "testCombinedImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS, isDepth ) );
		{
			type::TypesCache typesCache;
			auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
			auto type = typesCache.getCombinedImage( config, isDepth );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == type::Kind::eCombinedImage )
			astCheck( type->getKind() == type::Kind::eCombinedImage )
			astCheck( type->getImageType() == typesCache.getImage( config ) )
			astCheck( type->getSamplerType() == typesCache.getSampler( isDepth ) )
			astCheck( type->getConfig() == config )
			astCheck( type->isComparison() == isDepth )

			auto type2 = typesCache.getCombinedImage( config, isDepth );
			astCheck( type2 == type )
		}
		astTestEnd()
	}
}

astTestSuiteMain( TestASTImageTypes )
{
	astTestSuiteBegin()
	for ( uint8_t dim = uint8_t( type::ImageDim::eMin ); dim <= uint8_t( type::ImageDim::eMax ); ++dim )
	{
		for ( uint8_t fmt = uint8_t( type::ImageFormat::eMin ); fmt <= uint8_t( type::ImageFormat::eMax ); ++fmt )
		{
			for ( uint8_t spl = uint8_t( type::Trinary::eMin ); spl <= uint8_t( type::Trinary::eMax ); ++spl )
			{
				for ( uint8_t acc = uint8_t( type::AccessKind::eMin ); acc <= uint8_t( type::AccessKind::eMax ); ++acc )
				{
					testImage( testCounts, type::ImageDim( dim ), type::ImageFormat( fmt ), type::Trinary( spl ), type::AccessKind( acc ), false, false );
					testImage( testCounts, type::ImageDim( dim ), type::ImageFormat( fmt ), type::Trinary( spl ), type::AccessKind( acc ), false, true );
					testImage( testCounts, type::ImageDim( dim ), type::ImageFormat( fmt ), type::Trinary( spl ), type::AccessKind( acc ), true, false );
					testImage( testCounts, type::ImageDim( dim ), type::ImageFormat( fmt ), type::Trinary( spl ), type::AccessKind( acc ), true, true );
				}
			}
		}
	}
	testSampledImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, false, false );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, false, false, false );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, false, false, true );
	testSampledImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, false, true );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, false, true, false );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, false, true, true );
	testSampledImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, true, false );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, true, false, false );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, true, false, true );
	testSampledImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, true, true );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, true, true, false );
	testCombinedImage( testCounts, type::ImageDim::e2D, type::ImageFormat::eRgba32f, type::Trinary::eTrue, type::AccessKind::eRead, true, true, true );
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTImageTypes )
