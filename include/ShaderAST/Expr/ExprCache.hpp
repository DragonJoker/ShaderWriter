/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCache_H___
#define ___AST_ExprCache_H___
#pragma once

#include "ShaderAST/ShaderAllocator.hpp"
#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Expr/EnumCombinedImageAccess.hpp"
#include "ShaderAST/Expr/EnumIntrinsic.hpp"
#include "ShaderAST/Expr/EnumStorageImageAccess.hpp"
#include "ShaderAST/Expr/IntrinsicCallHelpers.hpp"
#include "ShaderAST/Expr/SwizzleKind.hpp"

#include <memory>
#include <vector>

namespace ast::expr
{
	class ExprCache
	{
	public:
		SDAST_API explicit ExprCache( ShaderAllocatorBlock & allocator );
		SDAST_API ~ExprCache() = default;

		SDAST_API AddPtr makeAdd( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API AddAssignPtr makeAddAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API AggrInitPtr makeAggrInit( IdentifierPtr identifier, ExprList initialisers );
		SDAST_API AggrInitPtr makeAggrInit( type::TypePtr type, ExprList initialisers );
		SDAST_API AliasPtr makeAlias( type::TypePtr type, IdentifierPtr lhs, ExprPtr rhs );
		SDAST_API AndAssignPtr makeAndAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API ArrayAccessPtr makeArrayAccess( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API AssignPtr makeAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API BitAndPtr makeBitAnd( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API BitNotPtr makeBitNot( ExprPtr operand );
		SDAST_API BitOrPtr makeBitOr( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API BitXorPtr makeBitXor( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API CastPtr makeCast( type::TypePtr dstType, ExprPtr operand );
		SDAST_API CombinedImageAccessCallPtr makeCombinedImageAccessCall( type::TypePtr type, CombinedImageAccess texelAccess, ExprList argList );
		SDAST_API CommaPtr makeComma( ExprPtr lhs, ExprPtr rhs );
		SDAST_API CompositeConstructPtr makeCompositeConstruct( CompositeType composite, type::Kind component, ExprList argList );
		SDAST_API CompositeConstructPtr makeCompositeConstruct( ExprPtr image, ExprPtr sampler );
		SDAST_API CopyPtr makeCopy( ExprPtr op );
		SDAST_API DividePtr makeDivide( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API DivideAssignPtr makeDivideAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API EqualPtr makeEqual( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API FnCallPtr makeFnCall( type::TypePtr type, IdentifierPtr fn, ExprList argList );
		SDAST_API FnCallPtr makeMemberFnCall( type::TypePtr type, IdentifierPtr fn, ExprPtr instance, ExprList argList );
		SDAST_API GreaterPtr makeGreater( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API GreaterEqualPtr makeGreaterEqual( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API IdentifierPtr makeIdentifier( type::TypesCache & typesCache, var::VariablePtr var );
		SDAST_API InitPtr makeInit( IdentifierPtr identifier, ExprPtr initialiser );
		SDAST_API IntrinsicCallPtr makeIntrinsicCall( type::TypePtr type, Intrinsic intrinsic, ExprList argList );
		SDAST_API LessPtr makeLess( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LessEqualPtr makeLessEqual( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, bool value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, signed char value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, signed short value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, signed int value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, signed long value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, signed long long value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, unsigned char value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, unsigned short value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, unsigned int value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, unsigned long value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, unsigned long long value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, float value );
		SDAST_API LiteralPtr makeLiteral( type::TypesCache & typesCache, double value );
		SDAST_API LogAndPtr makeLogAnd( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LogNotPtr makeLogNot( type::TypesCache & typesCache, ExprPtr operand );
		SDAST_API LogOrPtr makeLogOr( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LShiftPtr makeLShift( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LShiftAssignPtr makeLShiftAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API MbrSelectPtr makeMbrSelect( ExprPtr outer, uint32_t memberIndex, uint64_t flags );
		SDAST_API MinusPtr makeMinus( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API MinusAssignPtr makeMinusAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API ModuloPtr makeModulo( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API ModuloAssignPtr makeModuloAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API NotEqualPtr makeNotEqual( type::TypesCache & typesCache, ExprPtr lhs, ExprPtr rhs );
		SDAST_API OrAssignPtr makeOrAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API PostDecrementPtr makePostDecrement( ExprPtr operand );
		SDAST_API PostIncrementPtr makePostIncrement( ExprPtr operand );
		SDAST_API PreDecrementPtr makePreDecrement( ExprPtr operand );
		SDAST_API PreIncrementPtr makePreIncrement( ExprPtr operand );
		SDAST_API QuestionPtr makeQuestion( type::TypePtr type, ExprPtr ctrlExpr, ExprPtr trueExpr, ExprPtr falseExpr );
		SDAST_API RShiftPtr makeRShift( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API RShiftAssignPtr makeRShiftAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API StorageImageAccessCallPtr makeStorageImageAccessCall( type::TypePtr type, StorageImageAccess imageAccess, ExprList argList );
		SDAST_API StreamAppendPtr makeStreamAppend( ExprPtr operand );
		SDAST_API SwitchCasePtr makeSwitchCase( LiteralPtr label );
		SDAST_API SwitchTestPtr makeSwitchTest( ExprPtr value );
		SDAST_API SwizzlePtr makeSwizzle( ExprPtr outer, SwizzleKind swizzle );
		SDAST_API TimesPtr makeTimes( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API TimesAssignPtr makeTimesAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API UnaryMinusPtr makeUnaryMinus( ExprPtr operand );
		SDAST_API UnaryPlusPtr makeUnaryPlus( ExprPtr operand );
		SDAST_API XorAssignPtr makeXorAssign( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API ExprPtr makeDummyExpr( type::TypePtr type );

		SDAST_API LiteralPtr makeLiteral( Literal const & rhs );
		SDAST_API IdentifierPtr makeIdentifier( Identifier const & rhs );

		SDAST_API EqualPtr makeEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API GreaterPtr makeGreater( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API GreaterEqualPtr makeGreaterEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LessPtr makeLess( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LessEqualPtr makeLessEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API NotEqualPtr makeNotEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LogAndPtr makeLogAnd( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );
		SDAST_API LogNotPtr makeLogNot( type::TypePtr type, ExprPtr operand );
		SDAST_API LogOrPtr makeLogOr( type::TypePtr type, ExprPtr lhs, ExprPtr rhs );

		template< typename ... Params >
		CombinedImageAccessCallPtr makeCombinedImageAccessCall( type::TypePtr type
			, CombinedImageAccess texelAccess
			, Params && ... args )
		{
			ExprList argList;
			( argList.emplace_back( std::forward< Params >( args ) ), ... );
			return makeCombinedImageAccessCall( std::move( type )
				, texelAccess
				, std::move( argList ) );
		}

		template< typename ... Params >
		StorageImageAccessCallPtr makeStorageImageAccessCall( type::TypePtr type
			, StorageImageAccess imageAccess
			, Params && ... args )
		{
			ExprList argList;
			( argList.emplace_back( std::forward< Params >( args ) ), ... );
			return makeStorageImageAccessCall( std::move( type )
				, imageAccess
				, std::move( argList ) );
		}

		template< typename ... Params >
		IntrinsicCallPtr makeIntrinsicCall( type::TypePtr type
			, Intrinsic intrinsic
			, Params && ... args )
		{
			ExprList argList;
			( argList.emplace_back( std::forward< Params >( args ) ), ... );
			return makeIntrinsicCall( std::move( type )
				, intrinsic
				, std::move( argList ) );
		}

		template< typename ExprT
			, typename ... ParamsT >
		std::unique_ptr< ExprT, DeleteExpr > makeExpr( ParamsT && ... params )
		{
			auto mem = m_allocator.allocate( sizeof( ExprT ) );
			return std::unique_ptr< ExprT, DeleteExpr >{ new ( mem )ExprT{ *this, std::forward< ParamsT >( params )... } };
		}

		ShaderAllocatorBlock & getAllocator()const
		{
			return m_allocator;
		}

	private:
		friend struct DeleteExpr;

		void freeExpr( Expr * expr )noexcept;

	private:
		ShaderAllocatorBlock & m_allocator;
	};
}

#endif
