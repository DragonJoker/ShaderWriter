#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;

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

	void testSampledImage( test::TestCounts & testCounts
		, type::ImageDim dimension
		, type::ImageFormat format
		, type::Trinary isSampled
		, type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
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
	}

	struct SampledImageType
	{
		type::ImageDim dimension;
		type::ImageFormat format;
		type::Trinary isSampled;
		type::AccessKind accessKind;
		bool isArrayed;
		bool isMS;

		constexpr SampledImageType( type::ImageDim dimension
			, type::ImageFormat format
			, type::Trinary isSampled
			, type::AccessKind accessKind
			, bool isArrayed
			, bool isMS )
			: dimension{ dimension }
			, format{ format }
			, isSampled{ isSampled }
			, accessKind{ accessKind }
			, isArrayed{ isArrayed }
			, isMS{ isMS }
		{}

		SampledImageType & operator+( int i )
		{
			if ( !isMS )
			{
				isMS = true;
				return *this;
			}
			isMS = false;

			if ( !isArrayed )
			{
				isArrayed = true;
				return *this;
			}
			isArrayed = false;

			if ( accessKind != type::AccessKind::eMax )
			{
				accessKind = type::AccessKind( uint8_t( accessKind ) + 1 );
				return *this;
			}
			accessKind = type::AccessKind::eMin;

			if ( isSampled != type::Trinary::eMax )
			{
				isSampled = type::Trinary( uint8_t( isSampled ) + 1 );
				return *this;
			}
			isSampled = type::Trinary::eMin;

			if ( format != type::ImageFormat::eMax )
			{
				format = type::ImageFormat( uint8_t( format ) + 1 );
				return *this;
			}
			format = type::ImageFormat::eMin;

			if ( dimension != type::ImageDim::eMax )
			{
				dimension = type::ImageDim( uint8_t( dimension ) + 1 );
				return *this;
			}
			dimension = type::ImageDim::eMin;

			return *this;
		}

	private:
		friend bool operator<( SampledImageType const & lhs, SampledImageType const & rhs )
		{
			return ( uint8_t( lhs.dimension ) < uint8_t( rhs.dimension )
				|| ( lhs.dimension == rhs.dimension
					&& ( uint8_t( lhs.format ) < uint8_t( rhs.format )
						|| ( lhs.format == rhs.format
							&& ( uint8_t( lhs.isSampled ) < uint8_t( rhs.isSampled )
								|| ( lhs.isSampled == rhs.isSampled
									&& ( uint8_t( lhs.accessKind ) < uint8_t( rhs.accessKind )
										|| ( lhs.accessKind == rhs.accessKind
											&& ( uint8_t( lhs.isArrayed ) < uint8_t( rhs.isArrayed )
												|| ( lhs.isArrayed == rhs.isArrayed
													&& uint8_t( lhs.isMS ) < uint8_t( rhs.isMS ) ) ) ) ) ) ) ) ) ) );
		}
	};

	static constexpr SampledImageType minSampledImageType{ type::ImageDim::eMin
		, type::ImageFormat::eMin
		, type::Trinary::eMin
		, type::AccessKind::eMin
		, false
		, false };

	static constexpr SampledImageType maxSampledImageType{ type::ImageDim::eMax
		, type::ImageFormat::eMax
		, type::Trinary::eMax
		, type::AccessKind::eMax
		, true
		, true };

	std::string getSampledImageTypeName( SampledImageType const & v )
	{
		return debug::getImageTypeName( v.format
			, v.accessKind
			, v.dimension
			, v.isSampled
			, v.isArrayed
			, v.isMS
			, false );
	}

	using SampledImageTypes = testing::TestWithParam< SampledImageType >;

	TEST_P( SampledImageTypes, SampledImage )
	{
		auto param = GetParam();
		astTestBegin( "testSampledImage" + getSampledImageTypeName( param ) );
		testSampledImage( testCounts, param.dimension, param.format, param.isSampled, param.accessKind, param.isArrayed, param.isMS );
		astTestEnd()
	}
}

INSTANTIATE_TEST_SUITE_P( TestASTSampledImageTypes, SampledImageTypes
	, testing::Range( minSampledImageType, maxSampledImageType )
	, astTestNameP( SampledImageType, getSampledImageTypeName ) );
