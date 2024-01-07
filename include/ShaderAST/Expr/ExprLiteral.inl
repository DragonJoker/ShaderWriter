/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCache.hpp"

#include <functional>
#include <stdexcept>

namespace ast::expr
{
	//*********************************************************************************************

	namespace details
	{
		template< LiteralType T >
		LiteralValueType< T > valueGetter( Literal::Value const & lit );

		template<>
		inline bool valueGetter< LiteralType::eBool >( Literal::Value const & lit )
		{
			return lit.boolv;
		}

		template<>
		inline int8_t valueGetter< LiteralType::eInt8 >( Literal::Value const & lit )
		{
			return lit.int8v;
		}

		template<>
		inline int16_t valueGetter< LiteralType::eInt16 >( Literal::Value const & lit )
		{
			return lit.int16v;
		}

		template<>
		inline int32_t valueGetter< LiteralType::eInt32 >( Literal::Value const & lit )
		{
			return lit.int32v;
		}

		template<>
		inline int64_t valueGetter< LiteralType::eInt64 >( Literal::Value const & lit )
		{
			return lit.int64v;
		}

		template<>
		inline uint8_t valueGetter< LiteralType::eUInt8 >( Literal::Value const & lit )
		{
			return lit.uint8v;
		}

		template<>
		inline uint16_t valueGetter< LiteralType::eUInt16 >( Literal::Value const & lit )
		{
			return lit.uint16v;
		}

		template<>
		inline uint32_t valueGetter< LiteralType::eUInt32 >( Literal::Value const & lit )
		{
			return lit.uint32v;
		}

		template<>
		inline uint64_t valueGetter< LiteralType::eUInt64 >( Literal::Value const & lit )
		{
			return lit.uint64v;
		}

		template<>
		inline float valueGetter< LiteralType::eFloat >( Literal::Value const & lit )
		{
			return lit.floatv;
		}

		template<>
		inline double valueGetter< LiteralType::eDouble >( Literal::Value const & lit )
		{
			return lit.doublev;
		}

		template< expr::LiteralType TargetT, typename SourceT >
		expr::LiteralValueType< TargetT > convert( SourceT const & v )
		{
			if constexpr ( std::is_same_v< expr::LiteralValueType< TargetT >, SourceT > )
			{
				return v;
			}
			else if constexpr ( ( TargetT == expr::LiteralType::eBool ) && !std::is_same_v< SourceT, bool > )
			{
				return v != SourceT{};
			}
			else if constexpr ( ( TargetT != expr::LiteralType::eBool ) && std::is_same_v< SourceT, bool > )
			{
				return v ? expr::LiteralValueType< TargetT >( 1 ) : expr::LiteralValueType< TargetT >{};
			}
			else
			{
				return expr::LiteralValueType< TargetT >( v );
			}
		}

		template< typename T = void >
		struct lshift
		{
			constexpr T operator()( const T & lhs, const T & rhs )const
			{
				return T( lhs << rhs );
			}
		};

		template<>
		struct lshift< void >
		{
			template< typename T >
			constexpr T operator()( T const & lhs, T const & rhs )const
			{
				return T( lhs << rhs );
			}
		};

		template< typename T = void >
		struct rshift
		{
			constexpr T operator()( const T & lhs, const T & rhs )const
			{
				return T( lhs >> rhs );
			}
		};

		template<>
		struct rshift< void >
		{
			template< typename T >
			constexpr T operator()( T const & lhs, T const & rhs )const
			{
				return T( lhs >> rhs );
			}
		};

		template< typename OperatorT, typename LhsTypeT >
		static expr::LiteralPtr binLogOp( ExprCache & exprCache
			, type::TypesCache & typesCache
			, LhsTypeT const & lhs
			, expr::Literal const & rhs
			, OperatorT op = OperatorT{} )
		{
			switch ( rhs.getLiteralType() )
			{
			case expr::LiteralType::eBool:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, rhs.getValue< expr::LiteralType::eBool >() ) );
			case expr::LiteralType::eInt8:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eInt8 >() ) ) );
			case expr::LiteralType::eInt16:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eInt16 >() ) ) );
			case expr::LiteralType::eInt32:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eInt32 >() ) ) );
			case expr::LiteralType::eInt64:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eInt64 >() ) ) );
			case expr::LiteralType::eUInt8:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt8 >() ) ) );
			case expr::LiteralType::eUInt16:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt16 >() ) ) );
			case expr::LiteralType::eUInt32:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt32 >() ) ) );
			case expr::LiteralType::eUInt64:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eUInt64 >() ) ) );
			case expr::LiteralType::eFloat:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eFloat >() ) ) );
			case expr::LiteralType::eDouble:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, convert< expr::LiteralType::eBool >( rhs.getValue< expr::LiteralType::eDouble >() ) ) );
			default:
				AST_Failure( "Unexpected operand type for a binary logical operator" );
				return nullptr;
			}
		}

		template< typename OperatorT, typename LhsTypeT >
		static expr::LiteralPtr binIntArithOp( ExprCache & exprCache
			, type::TypesCache & typesCache
			, LhsTypeT const & lhs
			, expr::Literal const & rhs
			, OperatorT op = OperatorT{} )
		{
			switch ( rhs.getLiteralType() )
			{
			case expr::LiteralType::eInt8:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eInt8 >( lhs )
						, rhs.getValue< expr::LiteralType::eInt8 >() ) );
			case expr::LiteralType::eInt16:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eInt16 >( lhs )
						, rhs.getValue< expr::LiteralType::eInt16 >() ) );
			case expr::LiteralType::eInt32:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eInt32 >( lhs )
						, rhs.getValue< expr::LiteralType::eInt32 >() ) );
			case expr::LiteralType::eInt64:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eInt64 >( lhs )
						, rhs.getValue< expr::LiteralType::eInt64 >() ) );
			case expr::LiteralType::eUInt8:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eUInt8 >( lhs )
						, rhs.getValue< expr::LiteralType::eUInt8 >() ) );
			case expr::LiteralType::eUInt16:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eUInt16 >( lhs )
						, rhs.getValue< expr::LiteralType::eUInt16 >() ) );
			case expr::LiteralType::eUInt32:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eUInt32 >( lhs )
						, rhs.getValue< expr::LiteralType::eUInt32 >() ) );
			case expr::LiteralType::eUInt64:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eUInt64 >( lhs )
						, rhs.getValue< expr::LiteralType::eUInt64 >() ) );
			default:
				AST_Failure( "Unexpected operand type for a binary integral arithmetic operator operator" );
				return nullptr;
			}
		}

		template< typename OperatorT, typename LhsTypeT >
		static expr::LiteralPtr binArithOp( ExprCache & exprCache
			, type::TypesCache & typesCache
			, LhsTypeT const & lhs
			, expr::Literal const & rhs
			, OperatorT op = OperatorT{} )
		{
			switch ( rhs.getLiteralType() )
			{
			case expr::LiteralType::eInt8:
			case expr::LiteralType::eInt16:
			case expr::LiteralType::eInt32:
			case expr::LiteralType::eInt64:
			case expr::LiteralType::eUInt8:
			case expr::LiteralType::eUInt16:
			case expr::LiteralType::eUInt32:
			case expr::LiteralType::eUInt64:
				return binIntArithOp( exprCache, typesCache, lhs, rhs, op );
			case expr::LiteralType::eFloat:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eFloat >( lhs )
						, rhs.getValue< expr::LiteralType::eFloat >() ) );
			case expr::LiteralType::eDouble:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eDouble >( lhs )
						, rhs.getValue< expr::LiteralType::eDouble >() ) );
			default:
				AST_Failure( "Unexpected operand type for a binary arithmetic operator operator" );
				return nullptr;
			}
		}

		template< typename OperatorT, typename LhsTypeT >
		static expr::LiteralPtr binCompOp( ExprCache & exprCache
			, type::TypesCache & typesCache
			, LhsTypeT const & lhs
			, expr::Literal const & rhs
			, OperatorT op = OperatorT{} )
		{
			switch ( rhs.getLiteralType() )
			{
			case expr::LiteralType::eInt8:
			case expr::LiteralType::eInt16:
			case expr::LiteralType::eInt32:
			case expr::LiteralType::eInt64:
			case expr::LiteralType::eUInt8:
			case expr::LiteralType::eUInt16:
			case expr::LiteralType::eUInt32:
			case expr::LiteralType::eUInt64:
			case expr::LiteralType::eFloat:
			case expr::LiteralType::eDouble:
				return binArithOp( exprCache, typesCache, lhs, rhs, op );
			case expr::LiteralType::eBool:
				return exprCache.makeLiteral( typesCache
					, op( convert< expr::LiteralType::eBool >( lhs )
						, rhs.getValue< expr::LiteralType::eBool >() ) );
			default:
				AST_Failure( "Unexpected operand type for a binary arithmetic operator operator" );
				return nullptr;
			}
		}

		template< typename LhsTypeT >
		struct AddLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binArithOp< std::plus<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct DivideLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binArithOp< std::divides<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct SubtractLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binArithOp< std::minus<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct MultiplyLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binArithOp< std::multiplies<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct ModuloLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binIntArithOp< std::modulus<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct LShiftLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binIntArithOp< lshift<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct RShiftLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binIntArithOp< rshift<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct BitAndLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binIntArithOp< std::bit_and<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct BitOrLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binIntArithOp< std::bit_or<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct BitXorLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binIntArithOp< std::bit_xor<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct LogAndLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binLogOp< std::logical_and<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct LogOrLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binLogOp< std::logical_or<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct CompEqualLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binCompOp< std::equal_to<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct CompNEqualLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binCompOp< std::not_equal_to<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct CompLessLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binCompOp< std::less<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct CompLEqualLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binCompOp< std::less_equal<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct CompGreaterLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binCompOp< std::greater<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		template< typename LhsTypeT >
		struct CompGEqualLiterals
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, LhsTypeT const & lhs
				, expr::Literal const & rhs )
			{
				return binCompOp< std::greater_equal<> >( exprCache, typesCache, lhs, rhs );
			}
		};

		struct ArithNegateLiteral
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return exprCache.makeLiteral( typesCache
						, !operand.getValue< expr::LiteralType::eBool >() );
				case expr::LiteralType::eInt8:
					return exprCache.makeLiteral( typesCache
						, -operand.getValue< expr::LiteralType::eInt8 >() );
				case expr::LiteralType::eInt16:
					return exprCache.makeLiteral( typesCache
						, -operand.getValue< expr::LiteralType::eInt16 >() );
				case expr::LiteralType::eInt32:
					return exprCache.makeLiteral( typesCache
						, -operand.getValue< expr::LiteralType::eInt32 >() );
				case expr::LiteralType::eInt64:
					return exprCache.makeLiteral( typesCache
						, -operand.getValue< expr::LiteralType::eInt64 >() );
				case expr::LiteralType::eUInt8:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eUInt8 >() );
				case expr::LiteralType::eUInt32:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eUInt32 >() );
				case expr::LiteralType::eUInt64:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eUInt64 >() );
				case expr::LiteralType::eFloat:
					return exprCache.makeLiteral( typesCache
						, -operand.getValue< expr::LiteralType::eFloat >() );
				case expr::LiteralType::eDouble:
					return exprCache.makeLiteral( typesCache
						, -operand.getValue< expr::LiteralType::eDouble >() );
				default:
					AST_Failure( "Unexpected operand type for ^ operator" );
					return nullptr;
				}
			}
		};

		struct PreIncrementLiteral
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eInt8:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt8 >() + 1 );
				case expr::LiteralType::eInt16:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt16 >() + 1 );
				case expr::LiteralType::eInt32:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt32 >() + 1 );
				case expr::LiteralType::eInt64:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt64 >() + 1 );
				case expr::LiteralType::eUInt8:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt8 >() + 1u );
				case expr::LiteralType::eUInt16:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt16 >() + 1u );
				case expr::LiteralType::eUInt32:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt32 >() + 1u );
				case expr::LiteralType::eUInt64:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt64 >() + 1u );
				case expr::LiteralType::eFloat:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eFloat >() + 1.0f );
				case expr::LiteralType::eDouble:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eDouble >() + 1.0 );
				default:
					AST_Failure( "Unexpected operand type for pre-increment" );
					return nullptr;
				}
			}
		};

		struct PreDecrementLiteral
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eInt8:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt8 >() - 1 );
				case expr::LiteralType::eInt16:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt16 >() - 1 );
				case expr::LiteralType::eInt32:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt32 >() - 1 );
				case expr::LiteralType::eInt64:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt64 >() - 1 );
				case expr::LiteralType::eUInt8:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt8 >() - 1u );
				case expr::LiteralType::eUInt16:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt16 >() - 1u );
				case expr::LiteralType::eUInt32:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt32 >() - 1u );
				case expr::LiteralType::eUInt64:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt64 >() - 1u );
				case expr::LiteralType::eFloat:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eFloat >() - 1.0f );
				case expr::LiteralType::eDouble:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eDouble >() - 1.0 );
				default:
					AST_Failure( "Unexpected operand type for pre-increment" );
					return nullptr;
				}
			}
		};

		struct BitNegateLiteral
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return exprCache.makeLiteral( typesCache
						, !operand.getValue< expr::LiteralType::eBool >() );
				case expr::LiteralType::eInt8:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eInt8 >() );
				case expr::LiteralType::eInt16:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eInt16 >() );
				case expr::LiteralType::eInt32:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eInt32 >() );
				case expr::LiteralType::eInt64:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eInt64 >() );
				case expr::LiteralType::eUInt8:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eUInt8 >() );
				case expr::LiteralType::eUInt16:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eUInt16 >() );
				case expr::LiteralType::eUInt32:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eUInt32 >() );
				case expr::LiteralType::eUInt64:
					return exprCache.makeLiteral( typesCache
						, ~operand.getValue< expr::LiteralType::eUInt64 >() );
				default:
					AST_Failure( "Unexpected operand type for unary not" );
					return nullptr;
				}
			}
		};

		struct LogNegateLiteral
		{
			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::Literal const & operand )
			{
				switch ( operand.getLiteralType() )
				{
				case expr::LiteralType::eBool:
					return exprCache.makeLiteral( typesCache
						, !operand.getValue < expr::LiteralType::eBool >() );
				case expr::LiteralType::eInt8:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt8 >() == 0 );
				case expr::LiteralType::eInt16:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt16 >() == 0 );
				case expr::LiteralType::eInt32:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt32 >() == 0 );
				case expr::LiteralType::eInt64:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eInt64 >() == 0 );
				case expr::LiteralType::eUInt8:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt8 >() == 0u );
				case expr::LiteralType::eUInt16:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt16 >() == 0u );
				case expr::LiteralType::eUInt32:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt32 >() == 0u );
				case expr::LiteralType::eUInt64:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eUInt64 >() == 0ull );
				case expr::LiteralType::eFloat:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eFloat >() == 0.0f );
				case expr::LiteralType::eDouble:
					return exprCache.makeLiteral( typesCache
						, operand.getValue< expr::LiteralType::eDouble >() == 0.0 );
				default:
					AST_Failure( "Unexpected operand type for unary not" );
					return nullptr;
				}
			}
		};

		struct CastLiteral
		{
			template< typename OutputT >
			struct CastTo
			{
				template< typename InputT >
				static expr::LiteralPtr castLiteral( ExprCache & exprCache
					, type::TypesCache & typesCache
					, InputT const & value )
				{
					return exprCache.makeLiteral( typesCache, OutputT( value ) );
				}

				static expr::LiteralPtr castLiteral( ExprCache & exprCache
					, type::TypesCache & typesCache
					, bool const & value )
				{
					return exprCache.makeLiteral( typesCache, value ? OutputT{ 1 } : OutputT{ 0 } );
				}

				static expr::LiteralPtr cast( ExprCache & exprCache
					, type::TypesCache & typesCache
					, expr::Literal const & operand )
				{
					switch ( operand.getLiteralType() )
					{
					case expr::LiteralType::eBool:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eBool >() );
					case expr::LiteralType::eInt8:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eInt8 >() );
					case expr::LiteralType::eInt16:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eInt16 >() );
					case expr::LiteralType::eInt32:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eInt32 >() );
					case expr::LiteralType::eInt64:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eInt64 >() );
					case expr::LiteralType::eUInt8:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eUInt8 >() );
					case expr::LiteralType::eUInt16:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eUInt16 >() );
					case expr::LiteralType::eUInt32:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eUInt32 >() );
					case expr::LiteralType::eUInt64:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eUInt64 >() );
					case expr::LiteralType::eFloat:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eFloat >() );
					case expr::LiteralType::eDouble:
						return castLiteral( exprCache, typesCache
							, operand.getValue< expr::LiteralType::eDouble >() );
					default:
						AST_Failure( "Unexpected operand type for unary not" );
						return nullptr;
					}
				}
			};

			static expr::LiteralPtr replace( ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::LiteralType output
				, expr::Literal const & operand )
			{
				switch ( output )
				{
				case expr::LiteralType::eBool:
					return CastTo< bool >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eInt8:
					return CastTo< int8_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eInt16:
					return CastTo< int16_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eInt32:
					return CastTo< int32_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eInt64:
					return CastTo< int64_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eUInt8:
					return CastTo< uint8_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eUInt16:
					return CastTo< uint16_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eUInt32:
					return CastTo< uint32_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eUInt64:
					return CastTo< uint64_t >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eFloat:
					return CastTo< float >::cast( exprCache, typesCache, operand );
				case expr::LiteralType::eDouble:
					return CastTo< double >::cast( exprCache, typesCache, operand );
				default:
					AST_Failure( "Unexpected operand type for unary not" );
					return nullptr;
				}
			}
		};

		template< template< typename TypeT > typename FuncT >
		expr::LiteralPtr replaceLiterals( ExprCache & exprCache
			, type::TypesCache & typesCache
			, expr::Literal const & lhs
			, expr::Literal const & rhs )
		{
			switch ( lhs.getLiteralType() )
			{
			case expr::LiteralType::eBool:
				return FuncT< bool >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eBool >(), rhs );
			case expr::LiteralType::eInt8:
				return FuncT< int8_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eInt8 >(), rhs );
			case expr::LiteralType::eInt16:
				return FuncT< int16_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eInt16 >(), rhs );
			case expr::LiteralType::eInt32:
				return FuncT< int32_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eInt32 >(), rhs );
			case expr::LiteralType::eInt64:
				return FuncT< int64_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eInt64 >(), rhs );
			case expr::LiteralType::eUInt8:
				return FuncT< uint8_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eUInt8 >(), rhs );
			case expr::LiteralType::eUInt16:
				return FuncT< uint16_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eUInt16 >(), rhs );
			case expr::LiteralType::eUInt32:
				return FuncT< uint32_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eUInt32 >(), rhs );
			case expr::LiteralType::eUInt64:
				return FuncT< uint64_t >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eUInt64 >(), rhs );
			case expr::LiteralType::eFloat:
				return FuncT< float >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eFloat >(), rhs );
			case expr::LiteralType::eDouble:
				return FuncT< double >::replace( exprCache, typesCache, lhs.getValue< expr::LiteralType::eDouble >(), rhs );
			default:
				AST_Failure( "Unexpected operand type" );
				return nullptr;
			}
		}

		template< typename FuncT >
		expr::LiteralPtr replaceLiteral( ExprCache & exprCache
			, type::TypesCache & typesCache
			, expr::LiteralType output
			, expr::Literal const & operand )
		{
			return FuncT::replace( exprCache, typesCache, output, operand );
		}

		template< typename FuncT >
		expr::LiteralPtr replaceLiteral( ExprCache & exprCache
			, type::TypesCache & typesCache
			, expr::Literal const & operand )
		{
			return FuncT::replace( exprCache, typesCache, operand );
		}
	}

	//*********************************************************************************************

	template< LiteralType T >
	inline LiteralValueType< T > Literal::getValue()const
	{
		assert( m_valueType == T );
		return details::valueGetter< T >( m_value );
	}

	template< LiteralType T >
	LiteralValueType< T > getLiteralValue( Expr const & expr )
	{
		if ( expr.getKind() != Kind::eLiteral )
		{
			throw Exception{ "Expected a literal expression" };
		}

		return static_cast< Literal const & >( expr ).getValue< T >();
	}

	//*********************************************************************************************
}
