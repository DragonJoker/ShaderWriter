#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma GCC diagnostic ignored "-Wdisabled-optimization"
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

	void testCombinedImage( test::TestCounts & testCounts
		, type::ImageDim dimension
		, type::ImageFormat format
		, type::Trinary isSampled
		, type::AccessKind accessKind
		, bool isArrayed
		, bool isMS
		, bool isDepth )
	{
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
	}

	struct CombinedImageType
	{
		type::ImageDim dimension;
		type::ImageFormat format;
		type::Trinary isSampled;
		type::AccessKind accessKind;
		bool isArrayed;
		bool isMS;
		bool isDepth;

		constexpr CombinedImageType( type::ImageDim dimension
			, type::ImageFormat format
			, type::Trinary isSampled
			, type::AccessKind accessKind
			, bool isArrayed
			, bool isMS
			, bool isDepth )
			: dimension{ dimension }
			, format{ format }
			, isSampled{ isSampled }
			, accessKind{ accessKind }
			, isArrayed{ isArrayed }
			, isMS{ isMS }
			, isDepth{ isDepth }
		{}

		CombinedImageType & operator+( int i )
		{
			if ( !isDepth )
			{
				isDepth = true;
				return *this;
			}
			isDepth = false;

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
		friend bool operator<( CombinedImageType const & lhs, CombinedImageType const & rhs )
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
													&& ( uint8_t( lhs.isMS ) < uint8_t( rhs.isMS )
														|| ( lhs.isMS == rhs.isMS
															&& ( uint8_t( lhs.isDepth ) < uint8_t( rhs.isDepth ) ) ) ) ) ) ) ) ) ) ) ) ) );
		}
	};
	static constexpr CombinedImageType minCombinedImageType{ type::ImageDim::eMin
		, type::ImageFormat::eMin
		, type::Trinary::eMin
		, type::AccessKind::eMin
		, false
		, false
		, false };

	static constexpr CombinedImageType maxCombinedImageType{ type::ImageDim::eMax
		, type::ImageFormat::eMax
		, type::Trinary::eMax
		, type::AccessKind::eMax
		, true
		, true
		, true };

	std::string getCombinedImageTypeName( CombinedImageType const & v )
	{
		return debug::getImageTypeName( v.format
			, v.accessKind
			, v.dimension
			, v.isSampled
			, v.isArrayed
			, v.isMS
			, v.isDepth );
	}

	using CombinedImageTypes = testing::TestWithParam< CombinedImageType >;

	TEST_P( CombinedImageTypes, CombinedImage )
	{
		auto param = GetParam();
		astTestBegin( "testCombinedImage" + getCombinedImageTypeName( param ) );
		testCombinedImage( testCounts, param.dimension, param.format, param.isSampled, param.accessKind, param.isArrayed, param.isMS, param.isDepth );
		astTestEnd()
	}
}

INSTANTIATE_TEST_SUITE_P( TestASTImageTypes, CombinedImageTypes
	, testing::Range( minCombinedImageType, maxCombinedImageType )
	, astTestNameP( CombinedImageType, getCombinedImageTypeName ) );

astTestSuiteMain()
