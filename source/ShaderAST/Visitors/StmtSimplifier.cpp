/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/StmtSimplifier.hpp"

#include "ShaderAST/Visitors/CloneExpr.hpp"

namespace ast
{
	namespace
	{
		expr::LiteralType getLiteralType( type::Type const & type )
		{
			type::Kind kind = type.getKind();

			switch ( kind )
			{
			case type::Kind::eBoolean:
				return expr::LiteralType::eBool;
			case type::Kind::eInt:
				return expr::LiteralType::eInt;
			case type::Kind::eUInt:
				return expr::LiteralType::eUInt;
			case type::Kind::eUInt64:
				return expr::LiteralType::eUInt64;
			case type::Kind::eFloat:
				return expr::LiteralType::eFloat;
			case type::Kind::eDouble:
				return expr::LiteralType::eDouble;
			default:
				AST_Failure( "Unsupported kind for a literal" );
				return expr::LiteralType::eFloat;
			}
		}

		std::vector< expr::SwizzleKind > getSwizzleValues( expr::SwizzleKind swizzle )
		{
			auto count = swizzle.getComponentsCount();
			std::vector< expr::SwizzleKind > result;
			result.push_back( swizzle.getFirstValue() );

			if ( count >= 2u )
			{
				result.push_back( swizzle.getSecondValue() );
			}

			if ( count >= 3u )
			{
				result.push_back( swizzle.getThirdValue() );
			}

			if ( count >= 4u )
			{
				result.push_back( swizzle.getFourthValue() );
			}

			return result;
		}

		uint32_t getSwizzleIndex( expr::SwizzleKind swizzle )
		{
			assert( swizzle.isOneComponent()
				&& "Invalid swizzle for components indexing" );

			return swizzle == expr::SwizzleKind::e0
				? 0u
				: ( swizzle == expr::SwizzleKind::e1
					? 1u
					: ( swizzle == expr::SwizzleKind::e2
						? 2u
						: 3u ) );
		}

		std::vector< uint32_t > getSwizzleIndices( expr::SwizzleKind swizzle )
		{
			std::vector< uint32_t > result;
			result.push_back( getSwizzleIndex( swizzle.getFirstValue() ) );
			auto count = swizzle.getComponentsCount();

			if ( count >= 2u )
			{
				result.push_back( getSwizzleIndex( swizzle.getSecondValue() ) );
			}

			if ( count >= 3u )
			{
				result.push_back( getSwizzleIndex( swizzle.getThirdValue() ) );
			}

			if ( count >= 4u )
			{
				result.push_back( getSwizzleIndex( swizzle.getFourthValue() ) );
			}

			return result;
		}

		expr::SwizzleKind getFinalSwizzle( std::vector< expr::SwizzleKind > const & values
			, std::vector< uint32_t > const & indices )
		{
			expr::SwizzleKind result;
			uint32_t shift = 0u;

			for ( auto & index : indices )
			{
				assert( index < values.size() );
				result |= values[index] >> shift;
				shift += 4u;
			}

			return result;
		}

		template< expr::LiteralType TargetT
			, typename SourceT
			, typename Enable = void >
		struct Converter
		{
			static expr::LiteralValueType< TargetT > convert( SourceT const & v )
			{
				return expr::LiteralValueType< TargetT >( v );
			}
		};

		template< expr::LiteralType TargetT
			, typename SourceT >
		struct Converter< TargetT, SourceT, std::enable_if_t< ( TargetT == expr::LiteralType::eBool ) && !std::is_same_v< SourceT, bool > > >
		{
			static expr::LiteralValueType< TargetT > convert( SourceT const & v )
			{
				return v != SourceT{};
			}
		};

		template< expr::LiteralType TargetT
			, typename SourceT >
			struct Converter< TargetT, SourceT, std::enable_if_t< ( TargetT == expr::LiteralType::eBool ) && std::is_same_v< SourceT, bool > > >
		{
			static expr::LiteralValueType< TargetT > convert( SourceT const & v )
			{
				return v;
			}
		};

		template< expr::LiteralType TargetT
			, typename SourceT >
			struct Converter< TargetT, SourceT, std::enable_if_t< ( TargetT != expr::LiteralType::eBool ) && std::is_same_v< SourceT, bool > > >
		{
			static expr::LiteralValueType< TargetT > convert( SourceT const & v )
			{
				return v ? expr::LiteralValueType< TargetT >( 1 ) : expr::LiteralValueType< TargetT >{};
			}
		};

		template< expr::LiteralType TargetT, typename SourceT >
		expr::LiteralValueType< TargetT > convert( SourceT const & v )
		{
			return Converter< TargetT, SourceT >::convert( v );
		}

		template< typename LhsTypeT >
		struct AddLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							+ rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							+ rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							+ rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							+ rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							+ rhs.getValue< expr::LiteralType::eDouble >() ) );
				case expr::LiteralType::eBool:
				default:
					AST_Failure( "Unexpected operand type for + operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct DivideLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							/ rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							/ rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							/ rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							/ rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							/ rhs.getValue< expr::LiteralType::eDouble >() ) );
				case expr::LiteralType::eBool:
				default:
					AST_Failure( "Unexpected operand type for / operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct SubtractLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							- rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							- rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							- rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							- rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							- rhs.getValue< expr::LiteralType::eDouble >() ) );
				case expr::LiteralType::eBool:
				default:
					AST_Failure( "Unexpected operand type for - operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct MultiplyLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							* rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							* rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							* rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							* rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							* rhs.getValue< expr::LiteralType::eDouble >() ) );
				case expr::LiteralType::eBool:
				default:
					AST_Failure( "Unexpected operand type for * operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct ModuloLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				expr::LiteralPtr result;

				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							% rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							% rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							% rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eBool:
				case expr::LiteralType::eFloat:
				case expr::LiteralType::eDouble:
				default:
					AST_Failure( "Unexpected operand type for % operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct LShiftLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							<< rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							<< rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							<< rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eBool:
				case expr::LiteralType::eFloat:
				case expr::LiteralType::eDouble:
				default:
					AST_Failure( "Unexpected operand type for << operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct RShiftLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							>> rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							>> rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							>> rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eBool:
				case expr::LiteralType::eFloat:
				case expr::LiteralType::eDouble:
				default:
					AST_Failure( "Unexpected operand type for >> operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct BitAndLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							& rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							& rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							& rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eBool:
				case expr::LiteralType::eFloat:
				case expr::LiteralType::eDouble:
				default:
					AST_Failure( "Unexpected operand type for & operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct BitOrLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							| rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							| rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							| rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eBool:
				case expr::LiteralType::eFloat:
				case expr::LiteralType::eDouble:
				default:
					AST_Failure( "Unexpected operand type for | operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct BitXorLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							^ rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							^ rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							^ rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eBool:
				case expr::LiteralType::eFloat:
				case expr::LiteralType::eDouble:
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct LogAndLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							&& rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							&& convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eInt >() ) ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							&& convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt >() ) ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							&& convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt64 >() ) ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							&& convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eFloat >() ) ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							&& convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eDouble >() ) ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct LogOrLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							|| rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							|| convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eInt >() ) ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							|| convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt >() ) ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							|| convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt64 >() ) ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							|| convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eFloat >() ) ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							|| convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eDouble >() ) ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct CompEqualLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							== rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							== rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							== rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							== rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							== rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							== rhs.getValue< expr::LiteralType::eDouble >() ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct CompNEqualLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							!= rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							!= rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							!= rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							!= rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							!= rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							!= rhs.getValue< expr::LiteralType::eDouble >() ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct CompLessLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							< rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							< rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							< rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							< rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							< rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							< rhs.getValue< expr::LiteralType::eDouble >() ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct CompLEqualLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							<= rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							<= rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							<= rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							<= rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							<= rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							<= rhs.getValue< expr::LiteralType::eDouble >() ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct CompGreaterLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							> rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							> rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							> rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							> rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							> rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							> rhs.getValue< expr::LiteralType::eDouble >() ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< typename LhsTypeT >
		struct CompGEqualLiterals
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				switch ( rhs.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eBool >( lhs )
							>= rhs.getValue< expr::LiteralType::eBool >() ) );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eInt >( lhs )
							>= rhs.getValue< expr::LiteralType::eInt >() ) );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt >( lhs )
							>= rhs.getValue< expr::LiteralType::eUInt >() ) );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eUInt64 >( lhs )
							>= rhs.getValue< expr::LiteralType::eUInt64 >() ) );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eFloat >( lhs )
							>= rhs.getValue< expr::LiteralType::eFloat >() ) );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, ( convert< expr::LiteralType::eDouble >( lhs )
							>= rhs.getValue< expr::LiteralType::eDouble >() ) );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		template< template< typename TypeT > typename FuncT >
		expr::LiteralPtr replaceLiterals( type::TypesCache & cache
			, expr::Literal const & lhs
			, expr::Literal const & rhs )
		{
			switch ( lhs.getLiteralType() )
			{
			case expr::LiteralType::eBool:
				return FuncT< bool >::replace( cache, lhs.getValue< expr::LiteralType::eBool >(), rhs );
			case expr::LiteralType::eInt:
				return FuncT< int32_t >::replace( cache, lhs.getValue< expr::LiteralType::eInt >(), rhs );
			case expr::LiteralType::eUInt:
				return FuncT< uint32_t >::replace( cache, lhs.getValue< expr::LiteralType::eUInt >(), rhs );
			case expr::LiteralType::eUInt64:
				return FuncT< uint64_t >::replace( cache, lhs.getValue< expr::LiteralType::eUInt64 >(), rhs );
			case expr::LiteralType::eFloat:
				return FuncT< float >::replace( cache, lhs.getValue< expr::LiteralType::eFloat >(), rhs );
			case expr::LiteralType::eDouble:
				return FuncT< double >::replace( cache, lhs.getValue< expr::LiteralType::eDouble >(), rhs );
			default:
				AST_Failure( "Unexpected operand type" );
				return nullptr;
			}
		}

		struct NegateLiteral
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, !operand.getValue< expr::LiteralType::eBool >() );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, -operand.getValue< expr::LiteralType::eInt >() );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ~operand.getValue< expr::LiteralType::eUInt >() );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ~operand.getValue< expr::LiteralType::eUInt64 >() );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, -operand.getValue< expr::LiteralType::eFloat >() );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, -operand.getValue< expr::LiteralType::eDouble >() );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		struct BitNegateLiteral
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, !operand.getValue< expr::LiteralType::eBool >() );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, ~operand.getValue< expr::LiteralType::eInt >() );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, ~operand.getValue< expr::LiteralType::eUInt >() );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, ~operand.getValue< expr::LiteralType::eUInt64 >() );
				case expr::LiteralType::eFloat:
				case expr::LiteralType::eDouble:
				default:
					AST_Failure( "Unexpected operand type for unary not" );
					return nullptr;
				}
			}
		};

		struct LogNegateLiteral
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return expr::makeLiteral( cache
						, !operand.getValue < expr::LiteralType::eBool >() );
				case expr::LiteralType::eInt:
					return expr::makeLiteral( cache
						, operand.getValue< expr::LiteralType::eInt >() == 0 );
				case expr::LiteralType::eUInt:
					return expr::makeLiteral( cache
						, operand.getValue< expr::LiteralType::eUInt >() == 0u );
				case expr::LiteralType::eUInt64:
					return expr::makeLiteral( cache
						, operand.getValue< expr::LiteralType::eUInt64 >() == 0ull );
				case expr::LiteralType::eFloat:
					return expr::makeLiteral( cache
						, operand.getValue< expr::LiteralType::eFloat >() == 0.0f );
				case expr::LiteralType::eDouble:
					return expr::makeLiteral( cache
						, operand.getValue< expr::LiteralType::eDouble >() == 0.0 );
				default:
					AST_Failure( "Unexpected operand type for unary not" );
					return nullptr;
				}
			}
		};
		
		template< typename OutputT >
		struct CastLiteralTo
		{
			template< typename InputT >
			static expr::LiteralPtr castLiteral( type::TypesCache & cache
				, InputT const & value )
			{
				return expr::makeLiteral( cache, OutputT( value ) );
			}

			static expr::LiteralPtr castLiteral( type::TypesCache & cache
				, bool const & value )
			{
				return expr::makeLiteral( cache, value ? OutputT{ 1 } : OutputT{ 0 } );
			}

			static expr::LiteralPtr cast( type::TypesCache & cache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return castLiteral( cache
						, operand.getValue< expr::LiteralType::eBool >() );
				case expr::LiteralType::eInt:
					return castLiteral( cache
						, operand.getValue< expr::LiteralType::eInt >() );
				case expr::LiteralType::eUInt:
					return castLiteral( cache
						, operand.getValue< expr::LiteralType::eUInt >() );
				case expr::LiteralType::eUInt64:
					return castLiteral( cache
						, operand.getValue< expr::LiteralType::eUInt64 >() );
				case expr::LiteralType::eFloat:
					return castLiteral( cache
						, operand.getValue< expr::LiteralType::eFloat >() );
				case expr::LiteralType::eDouble:
					return castLiteral( cache
						, operand.getValue< expr::LiteralType::eDouble >() );
				default:
					AST_Failure( "Unexpected operand type for unary not" );
					return nullptr;
				}
			}
		};
		
		struct CastLiteral
		{
			static expr::LiteralPtr replace( type::TypesCache & cache
				, expr::LiteralType output
				, expr::Literal const & operand )
			{
				switch ( output )
				{
				case expr::LiteralType::eBool:
					return CastLiteralTo< bool >::cast( cache, operand );
				case expr::LiteralType::eInt:
					return CastLiteralTo< int32_t >::cast( cache, operand );
				case expr::LiteralType::eUInt:
					return CastLiteralTo< uint32_t >::cast( cache, operand );
				case expr::LiteralType::eUInt64:
					return CastLiteralTo< uint64_t >::cast( cache, operand );
				case expr::LiteralType::eFloat:
					return CastLiteralTo< float >::cast( cache, operand );
				case expr::LiteralType::eDouble:
					return CastLiteralTo< double >::cast( cache, operand );
				default:
					AST_Failure( "Unexpected operand type for unary not" );
					return nullptr;
				}
			}
		};

		template< typename FuncT >
		expr::LiteralPtr replaceLiteral( type::TypesCache & cache
			, expr::LiteralType output
			, expr::Literal const & operand )
		{
			return FuncT::replace( cache, output, operand );
		}
		
		template< typename FuncT >
		expr::LiteralPtr replaceLiteral( type::TypesCache & cache
			, expr::Literal const & operand )
		{
			return FuncT::replace( cache, operand );
		}

		class ExprSimplifier
			: public ExprCloner
		{
		public:
			static expr::ExprPtr submit( type::TypesCache & cache
				, std::map< var::VariablePtr, expr::Literal * > & literalVars
				, expr::Expr * expr )
			{
				expr::ExprPtr result;
				ExprSimplifier vis{ cache, literalVars, result };
				expr->accept( &vis );
				return result;
			}

		private:
			ExprSimplifier( type::TypesCache & cache
				, std::map< var::VariablePtr, expr::Literal * > & literalVars
				, expr::ExprPtr & result )
				: ExprCloner{ result }
				, m_cache{ cache }
				, m_literalVars{ literalVars }
			{
			}

		private:
			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				expr::ExprPtr result;
				ExprSimplifier vis{ m_cache, m_literalVars, result };
				expr->accept( &vis );

				if ( expr->isNonUniform() )
				{
					result->updateFlag( expr::Flag::eNonUniform );
				}

				return result;
			}

			expr::ExprPtr doSubmit( expr::ExprPtr expr )
			{
				return doSubmit( expr.get() );
			}

			void visitUnaryExpr( expr::Unary * expr )
			{
				auto op = doSubmit( expr->getOperand() );

				if ( op->getKind() == expr::Kind::eLiteral )
				{
					auto & literal = static_cast< expr::Literal const & >( *op );

					switch ( expr->getKind() )
					{
					case expr::Kind::eUnaryMinus:
						m_result = replaceLiteral< NegateLiteral >( expr->getCache(), literal );
						break;
					case expr::Kind::eUnaryPlus:
						m_result = std::move( op );
						break;
					case expr::Kind::eBitNot:
						m_result = replaceLiteral< BitNegateLiteral >( expr->getCache(), literal );
						break;
					case expr::Kind::eLogNot:
						m_result = replaceLiteral< LogNegateLiteral >( expr->getCache(), literal );
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
						m_result = ExprCloner::submit( expr );
						break;
					}
				}
				else
				{
					m_result = ExprCloner::submit( expr );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )
			{
				auto lhs = doSubmit( expr->getLHS() );
				auto rhs = doSubmit( expr->getRHS() );

				if ( lhs->getKind() == expr::Kind::eLiteral
					&& rhs->getKind() == expr::Kind::eLiteral )
				{
					auto & lhsLiteral = static_cast< expr::Literal const & >( *lhs );
					auto & rhsLiteral = static_cast< expr::Literal const & >( *rhs );

					switch ( expr->getKind() )
					{
					case expr::Kind::eAdd:
						m_result = replaceLiterals< AddLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eBitAnd:
						m_result = replaceLiterals< BitAndLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eBitOr:
						m_result = replaceLiterals< BitOrLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eBitXor:
						m_result = replaceLiterals< BitXorLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eDivide:
						m_result = replaceLiterals< DivideLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eLShift:
						m_result = replaceLiterals< LShiftLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eMinus:
						m_result = replaceLiterals< SubtractLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eModulo:
						m_result = replaceLiterals< ModuloLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eRShift:
						m_result = replaceLiterals< RShiftLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eTimes:
						m_result = replaceLiterals< MultiplyLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eLogAnd:
						m_result = replaceLiterals< LogAndLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eLogOr:
						m_result = replaceLiterals< LogOrLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eLess:
						m_result = replaceLiterals< CompLessLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eLessEqual:
						m_result = replaceLiterals< CompLEqualLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eGreater:
						m_result = replaceLiterals< CompGreaterLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eGreaterEqual:
						m_result = replaceLiterals< CompGEqualLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eEqual:
						m_result = replaceLiterals< CompEqualLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					case expr::Kind::eNotEqual:
						m_result = replaceLiterals< CompNEqualLiterals >( expr->getCache(), lhsLiteral, rhsLiteral );
						break;
					default:
						AST_Failure( "Unexpected binary expression" );
						m_result = ExprCloner::submit( expr );
						break;
					}
				}
				else
				{
					switch ( expr->getKind() )
					{
					case expr::Kind::eAdd:
						m_result = expr::makeAdd( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitAnd:
						m_result = expr::makeBitAnd( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitOr:
						m_result = expr::makeBitOr( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitXor:
						m_result = expr::makeBitXor( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eDivide:
						m_result = expr::makeDivide( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLShift:
						m_result = expr::makeLShift( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eMinus:
						m_result = expr::makeMinus( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eModulo:
						m_result = expr::makeModulo( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eRShift:
						m_result = expr::makeRShift( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eTimes:
						m_result = expr::makeTimes( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLogAnd:
						m_result = expr::makeLogAnd( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLogOr:
						m_result = expr::makeLogOr( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLess:
						m_result = expr::makeLess( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLessEqual:
						m_result = expr::makeLessEqual( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eGreater:
						m_result = expr::makeGreater( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eGreaterEqual:
						m_result = expr::makeGreaterEqual( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eEqual:
						m_result = expr::makeEqual( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eNotEqual:
						m_result = expr::makeNotEqual( expr->getCache(), std::move( lhs ), std::move( rhs ) );
						break;
					default:
						AST_Failure( "Unexpected binary expression" );
						m_result = ExprCloner::submit( expr );
						break;
					}
				}
			}

			void visitCastExpr( expr::Cast * expr )override
			{
				auto operand = doSubmit( expr->getOperand() );

				if ( operand->getKind() == expr::Kind::eLiteral
					&& getComponentType( expr->getType() ) != type::Kind::eHalf )
				{
					auto & literal = static_cast< expr::Literal const & >( *operand );
					m_result = replaceLiteral< CastLiteral >( expr->getCache()
						, getLiteralType( *expr->getType() )
						, literal );
				}
				else
				{
					m_result = expr::makeCast( expr->getType()
						, std::move( operand ) );
				}
			}

			void visitAddExpr( expr::Add * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitBitAndExpr( expr::BitAnd * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitBitNotExpr( expr::BitNot * expr )override
			{
				visitUnaryExpr( expr );
			}

			void visitBitOrExpr( expr::BitOr * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitBitXorExpr( expr::BitXor * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitDivideExpr( expr::Divide * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitEqualExpr( expr::Equal * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitGreaterExpr( expr::Greater * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitGreaterEqualExpr( expr::GreaterEqual * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				bool processed{ false };

				if ( expr->getVariable()->isConstant() )
				{
					auto it = m_literalVars.find( expr->getVariable() );

					if ( it != m_literalVars.end() )
					{
						m_result = doSubmit( it->second );
						processed = true;
					}
				}

				if ( !processed )
				{
					ExprCloner::visitIdentifierExpr( expr );
				}
			}

			void visitInitExpr( expr::Init * expr )override
			{
				auto init = doSubmit( expr->getInitialiser() );

				if ( init->getKind() == expr::Kind::eLiteral
					&& expr->getIdentifier()->getVariable()->isConstant() )
				{
					m_literalVars.emplace( expr->getIdentifier()->getVariable(), static_cast< expr::Literal * >( init.get() ) );
				}

				m_result = expr::makeInit( std::make_unique< expr::Identifier >( *expr->getIdentifier() )
					, std::move( init ) );
			}

			void visitLessExpr( expr::Less * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitLessEqualExpr( expr::LessEqual * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				ExprCloner::visitLiteralExpr( expr );
			}

			void visitLogAndExpr( expr::LogAnd * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitLogNotExpr( expr::LogNot * expr )override
			{
				visitUnaryExpr( expr );
			}

			void visitLogOrExpr( expr::LogOr * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitLShiftExpr( expr::LShift * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitMinusExpr( expr::Minus * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitModuloExpr( expr::Modulo * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitNotEqualExpr( expr::NotEqual * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitRShiftExpr( expr::RShift * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitTimesExpr( expr::Times * expr )override
			{
				visitBinaryExpr( expr );
			}

			void visitUnaryMinusExpr( expr::UnaryMinus * expr )override
			{
				visitUnaryExpr( expr );
			}

			void visitUnaryPlusExpr( expr::UnaryPlus * expr )override
			{
				m_result = doSubmit( expr->getOperand() );
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				if ( expr->getLHS()->getKind() == expr::Kind::eSwizzle
					&& expr->getRHS()->getKind() == expr::Kind::eLiteral )
				{
					uint32_t index = 0u;
					auto & lit = static_cast< expr::Literal const & >( *expr->getRHS() );
					assert( lit.getLiteralType() == expr::LiteralType::eInt
						|| lit.getLiteralType() == expr::LiteralType::eUInt
						|| lit.getLiteralType() == expr::LiteralType::eUInt64 );

					if ( lit.getLiteralType() == expr::LiteralType::eInt )
					{
						index = uint32_t( lit.getValue< expr::LiteralType::eInt >() );
					}
					else if ( lit.getLiteralType() == expr::LiteralType::eUInt )
					{
						index = lit.getValue< expr::LiteralType::eUInt >();
					}
					else
					{
						index = uint32_t( lit.getValue< expr::LiteralType::eUInt64 >() );
					}

					auto & outer = static_cast< expr::Swizzle & >( *expr->getLHS() );
					auto newOuter = doSubmit( outer.getOuterExpr() );
					m_result = doSubmit( expr::makeSwizzle( std::move( newOuter )
							, outer.getSwizzle()[index] ) );
				}
				else
				{
					ExprCloner::visitArrayAccessExpr( expr );
				}
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				if ( expr->getOuterExpr()->getKind() == expr::Kind::eSwizzle )
				{
					auto & outer = static_cast< ast::expr::Swizzle const & >( *expr->getOuterExpr() );

					if ( ast::expr::SwizzleKind::Value( expr->getSwizzle() ) == ast::expr::SwizzleKind::Value( outer.getSwizzle() )
						&& expr->getType() == outer.getType() )
					{
						m_result = ast::expr::makeSwizzle( doSubmit( outer.getOuterExpr() )
							, outer.getSwizzle() );
					}
					else
					{
						auto values = getSwizzleValues( outer.getSwizzle() );
						auto indices = getSwizzleIndices( expr->getSwizzle() );
						m_result = expr::makeSwizzle( doSubmit( outer.getOuterExpr() )
							, getFinalSwizzle( values, indices ) );
					}
				}

				if ( !m_result )
				{
					auto outer = expr->getOuterExpr();

					if ( outer->getKind() == expr::Kind::eCompositeConstruct
						&& ( expr->getSwizzle() == expr::SwizzleKind::e0
							|| expr->getSwizzle() == expr::SwizzleKind::e1
							|| expr->getSwizzle() == expr::SwizzleKind::e2
							|| expr->getSwizzle() == expr::SwizzleKind::e3 ) )
					{
						auto & compositeConstruct = static_cast< expr::CompositeConstruct const & >( *outer );

						if ( compositeConstruct.getArgList().size() == 1u
							&& type::isScalarType( compositeConstruct.getArgList().front()->getType() ) )
						{
							m_result = doSubmit( compositeConstruct.getArgList().begin()->get() );
						}
						else if ( compositeConstruct.getArgList().size() == type::getComponentCount( compositeConstruct.getType() ) )
						{
							m_result = doSubmit( std::next( compositeConstruct.getArgList().begin()
								, ptrdiff_t( expr->getSwizzle().toIndex() ) )->get() );
						}
					}
				}

				if ( !m_result )
				{
					m_result = expr::makeSwizzle( doSubmit( expr->getOuterExpr() )
						, expr->getSwizzle() );
				}
			}

		private:
			type::TypesCache & m_cache;
			std::map< var::VariablePtr, expr::Literal * > & m_literalVars;
		};
	}

	stmt::ContainerPtr StmtSimplifier::submit( type::TypesCache & cache
		, stmt::Container * stmt )
	{
		std::map< var::VariablePtr, expr::Literal * > literalVars;
		return submit( cache, stmt, literalVars );
	}

	stmt::ContainerPtr StmtSimplifier::submit( type::TypesCache & cache
		, stmt::Container * stmt
		, std::map< var::VariablePtr, expr::Literal * > & literalVars )
	{
		auto result = stmt::makeContainer();
		StmtSimplifier vis{ cache, literalVars, result };
		stmt->accept( &vis );
		return result;
	}

	StmtSimplifier::StmtSimplifier( type::TypesCache & cache
		, std::map< var::VariablePtr, expr::Literal * > & literalVars
		, stmt::ContainerPtr & result )
		: StmtCloner{ result }
		, m_cache{ cache }
		, m_literalVars{ literalVars }
	{
	}

	expr::ExprPtr StmtSimplifier::doSubmit( expr::Expr * expr )
	{
		return ExprSimplifier::submit( m_cache, m_literalVars, expr );
	}
}
