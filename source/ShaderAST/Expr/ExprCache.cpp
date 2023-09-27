/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprCache.hpp"

#include "ShaderAST/Expr/ExprAdd.hpp"
#include "ShaderAST/Expr/ExprAddAssign.hpp"
#include "ShaderAST/Expr/ExprAggrInit.hpp"
#include "ShaderAST/Expr/ExprAlias.hpp"
#include "ShaderAST/Expr/ExprAndAssign.hpp"
#include "ShaderAST/Expr/ExprArrayAccess.hpp"
#include "ShaderAST/Expr/ExprAssign.hpp"
#include "ShaderAST/Expr/ExprBitAnd.hpp"
#include "ShaderAST/Expr/ExprBitNot.hpp"
#include "ShaderAST/Expr/ExprBitOr.hpp"
#include "ShaderAST/Expr/ExprBitXor.hpp"
#include "ShaderAST/Expr/ExprCast.hpp"
#include "ShaderAST/Expr/ExprCombinedImageAccessCall.hpp"
#include "ShaderAST/Expr/ExprComma.hpp"
#include "ShaderAST/Expr/ExprCompositeConstruct.hpp"
#include "ShaderAST/Expr/ExprCopy.hpp"
#include "ShaderAST/Expr/ExprDivide.hpp"
#include "ShaderAST/Expr/ExprDivideAssign.hpp"
#include "ShaderAST/Expr/ExprEqual.hpp"
#include "ShaderAST/Expr/ExprFnCall.hpp"
#include "ShaderAST/Expr/ExprGreater.hpp"
#include "ShaderAST/Expr/ExprGreaterEqual.hpp"
#include "ShaderAST/Expr/ExprIdentifier.hpp"
#include "ShaderAST/Expr/ExprInit.hpp"
#include "ShaderAST/Expr/ExprIntrinsicCall.hpp"
#include "ShaderAST/Expr/ExprLShift.hpp"
#include "ShaderAST/Expr/ExprLShiftAssign.hpp"
#include "ShaderAST/Expr/ExprLess.hpp"
#include "ShaderAST/Expr/ExprLessEqual.hpp"
#include "ShaderAST/Expr/ExprLiteral.hpp"
#include "ShaderAST/Expr/ExprLogAnd.hpp"
#include "ShaderAST/Expr/ExprLogNot.hpp"
#include "ShaderAST/Expr/ExprLogOr.hpp"
#include "ShaderAST/Expr/ExprMbrSelect.hpp"
#include "ShaderAST/Expr/ExprMinus.hpp"
#include "ShaderAST/Expr/ExprMinusAssign.hpp"
#include "ShaderAST/Expr/ExprModulo.hpp"
#include "ShaderAST/Expr/ExprModuloAssign.hpp"
#include "ShaderAST/Expr/ExprNotEqual.hpp"
#include "ShaderAST/Expr/ExprOrAssign.hpp"
#include "ShaderAST/Expr/ExprPostDecrement.hpp"
#include "ShaderAST/Expr/ExprPostIncrement.hpp"
#include "ShaderAST/Expr/ExprPreDecrement.hpp"
#include "ShaderAST/Expr/ExprPreIncrement.hpp"
#include "ShaderAST/Expr/ExprQuestion.hpp"
#include "ShaderAST/Expr/ExprRShift.hpp"
#include "ShaderAST/Expr/ExprRShiftAssign.hpp"
#include "ShaderAST/Expr/ExprStorageImageAccessCall.hpp"
#include "ShaderAST/Expr/ExprStreamAppend.hpp"
#include "ShaderAST/Expr/ExprSwitchCase.hpp"
#include "ShaderAST/Expr/ExprSwitchTest.hpp"
#include "ShaderAST/Expr/ExprSwizzle.hpp"
#include "ShaderAST/Expr/ExprTimes.hpp"
#include "ShaderAST/Expr/ExprTimesAssign.hpp"
#include "ShaderAST/Expr/ExprUnaryMinus.hpp"
#include "ShaderAST/Expr/ExprUnaryPlus.hpp"
#include "ShaderAST/Expr/ExprXorAssign.hpp"

#include <iostream>

namespace ast::expr
{
	//*********************************************************************************************

	namespace details
	{
		BuddyAllocator::BuddyAllocator( uint32_t numLevels
			, uint32_t minBlockSize )
			: m_memory{ minBlockSize * ( 1u << numLevels ) }
			, m_numLevels{ numLevels }
			, m_minBlockSize{ minBlockSize }
		{
			assert( numLevels < 32 );
			m_freeLists.resize( m_numLevels + 1 );
			m_freeLists[0u].push_back( getPointer( 0u ) );
		}

		BuddyAllocator::~BuddyAllocator()
		{
			for ( auto & alloc : m_allocated )
			{
				std::cout << "Leaked block at " << alloc.first << ", for level " << alloc.second << std::endl;
			}
		}

		bool BuddyAllocator::hasAvailable( size_t size )const
		{
			auto level = doGetLevel( size );
			bool result = !size;

			if ( !result && size <= getTotalSize() )
			{
				auto it = m_freeLists.rend() - ( level + 1 );

				while ( it != m_freeLists.rend() && it->empty() )
				{
					++it;
				}

				result = it != m_freeLists.rend();
			}

			return result;
		}

		BuddyAllocator::PointerType BuddyAllocator::allocate( size_t size )
		{
			PointerType result{};

			if ( size <= getTotalSize() )
			{
				auto level = doGetLevel( size );
				result = doAllocate( level );
				auto offset = getOffset( result );
				m_allocated.emplace_back( offset, level );
			}
			else
			{
				throw std::bad_alloc{};
			}

			return result;
		}

		bool BuddyAllocator::deallocate( PointerType pointer )
		{
			auto offset = getOffset( pointer );
			auto it = std::find_if( m_allocated.begin()
				, m_allocated.end()
				, [offset]( PointerLevel const & ptrLevel )
				{
					return ptrLevel.first == offset;
				} );
			bool result = it != m_allocated.end();

			if ( result )
			{
				auto level = it->second;
				auto index = uint32_t( offset / doGetLevelSize( level ) );
				PointerType block{ pointer };
				m_allocated.erase( it );
				doMergeLevel( block, index, level );
			}
			else
			{
				std::cout << "Double delete at " << offset << std::endl;
			}

			return result;
		}

		size_t BuddyAllocator::getTotalSize()const
		{
			return m_memory.size();
		}

		size_t BuddyAllocator::getAlignSize()const
		{
			return m_minBlockSize;
		}

		BuddyAllocator::PointerType BuddyAllocator::getPointer( uint32_t offset )
		{
			return m_memory.data() + offset;
		}

		size_t BuddyAllocator::getOffset( PointerType pointer )const
		{
			return size_t( pointer - m_memory.data() );
		}

		uint32_t BuddyAllocator::doGetLevel( size_t size )const
		{
			auto levelSize = getTotalSize();
			uint32_t level = 0;

			while ( size < levelSize )
			{
				levelSize >>= 1;
				++level;
			}

			if ( size > levelSize )
			{
				--level;
			}

			return std::min( level, m_numLevels );
		}

		size_t BuddyAllocator::doGetLevelSize( uint32_t level )const
		{
			return getTotalSize() / size_t( 1ull << level );
		}

		BuddyAllocator::PointerType BuddyAllocator::doAllocate( uint32_t level )
		{
			auto & freeList = m_freeLists[level];

			if ( freeList.empty() )
			{
				if ( level == 0 )
				{
					return { nullptr };
				}

				auto buddy = doAllocate( level - 1 );

				if ( !buddy )
				{
					return buddy;
				}

				freeList.push_back( PointerType( buddy ) );
				freeList.push_back( PointerType( buddy + doGetLevelSize( level ) ) );
			}

			auto buddy = freeList.front();
			freeList.erase( freeList.begin() );
			return buddy;
		}

		void BuddyAllocator::doMergeLevel( PointerType const & block
			, uint32_t index
			, uint32_t level )
		{
			auto & freeList = m_freeLists[level];
			PointerType lhs;
			PointerType rhs;
			typename FreeList::iterator it;

			if ( index % 2u )
			{
				// RHS block => find LHS in free blocks of same level.
				lhs = PointerType( block - doGetLevelSize( level ) );
				it = std::find_if( freeList.begin()
					, freeList.end()
					, [lhs]( PointerType const & lookUp )
					{
						return lookUp == lhs;
					} );
				rhs = block;
			}
			else
			{
				// LHS block => find RHS in free blocks of same level.
				lhs = block;
				rhs = PointerType( block + doGetLevelSize( level ) );
				it = std::find_if( freeList.begin()
					, freeList.end()
					, [rhs]( PointerType const & lookUp )
					{
						return lookUp == rhs;
					} );
			}

			if ( it != freeList.end() )
			{
				// remove the other block from the list.
				freeList.erase( it );
				// add lhs to lower level list.
				auto offset = getOffset( lhs );
				auto newIndex = uint32_t( offset / doGetLevelSize( level - 1u ) );
				// merge lower level.
				doMergeLevel( lhs, newIndex, level - 1u );
			}
			else
			{
				freeList.push_back( block );
			}
		}
	}

	//*********************************************************************************************

	void DeleteExpr::operator()( Expr * expr )noexcept
	{
		if ( expr )
		{
			expr->getExprCache().freeExpr( expr );
		}
	}

	//*********************************************************************************************

	ExprCache::ExprCache( CacheMode cacheMode )
		: m_cacheMode{ cacheMode }
	{
	}

	AddPtr ExprCache::makeAdd( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Add >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	AddAssignPtr ExprCache::makeAddAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< AddAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	AggrInitPtr ExprCache::makeAggrInit( IdentifierPtr identifier
		, ExprList initialisers )
	{
		return makeExpr< AggrInit >( std::move( identifier )
			, std::move( initialisers ) );
	}

	AggrInitPtr ExprCache::makeAggrInit( type::TypePtr type
		, ExprList initialisers )
	{
		return makeExpr< AggrInit >( std::move( type )
			, std::move( initialisers ) );
	}

	AliasPtr ExprCache::makeAlias( type::TypePtr type
		, IdentifierPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Alias >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	AndAssignPtr ExprCache::makeAndAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< AndAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	ArrayAccessPtr ExprCache::makeArrayAccess( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		assert( lhs->getType()->getKind() == type::Kind::eArray
			|| lhs->getType()->getKind() == type::Kind::eGeometryInput
			|| lhs->getType()->getKind() == type::Kind::eTessellationControlInput
			|| lhs->getType()->getKind() == type::Kind::eTessellationControlOutput
			|| lhs->getType()->getKind() == type::Kind::eTessellationEvaluationInput
			|| lhs->getType()->getKind() == type::Kind::eMeshVertexOutput
			|| lhs->getType()->getKind() == type::Kind::eMeshPrimitiveOutput
			|| isVectorType( lhs->getType()->getKind() )
			|| isMatrixType( lhs->getType()->getKind() ) );
		return makeExpr< ArrayAccess >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	AssignPtr ExprCache::makeAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Assign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	BitAndPtr ExprCache::makeBitAnd( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< BitAnd >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	BitNotPtr ExprCache::makeBitNot( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< BitNot >( std::move( type )
			, std::move( operand ) );
	}

	BitOrPtr ExprCache::makeBitOr( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< BitOr >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	BitXorPtr ExprCache::makeBitXor( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< BitXor >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	CastPtr ExprCache::makeCast( type::TypePtr dstType
		, ExprPtr operand )
	{
		return makeExpr< Cast >( std::move( dstType )
			, std::move( operand ) );
	}

	CombinedImageAccessCallPtr ExprCache::makeCombinedImageAccessCall( type::TypePtr type
		, CombinedImageAccess texelAccess
		, ExprList argList )
	{
		return makeExpr< CombinedImageAccessCall >( std::move( type )
			, texelAccess
			, std::move( argList ) );
	}

	CommaPtr ExprCache::makeComma( ExprPtr lhs
		, ExprPtr rhs )
	{
		auto type = rhs->getType();
		return makeExpr< Comma >( type
			, std::move( lhs )
			, std::move( rhs ) );
	}

	CompositeConstructPtr ExprCache::makeCompositeConstruct( CompositeType composite
		, type::Kind component
		, ExprList argList )
	{
		return makeExpr< CompositeConstruct >( composite
			, component
			, std::move( argList ) );
	}

	CompositeConstructPtr ExprCache::makeCompositeConstruct( ExprPtr image
		, ExprPtr sampler )
	{
		return makeExpr< CompositeConstruct >( std::move( image )
			, std::move( sampler ) );
	}

	CopyPtr ExprCache::makeCopy( ExprPtr operand )
	{
		return makeExpr< Copy >( std::move( operand ) );
	}

	DividePtr ExprCache::makeDivide( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Divide >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	DivideAssignPtr ExprCache::makeDivideAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< DivideAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	EqualPtr ExprCache::makeEqual( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Equal >( typesCache.getVector( type::Kind::eBoolean, type::getComponentCount( lhs->getType() ) )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	FnCallPtr ExprCache::makeFnCall( type::TypePtr type
		, IdentifierPtr fn
		, ExprList argList )
	{
		return makeExpr< FnCall >( std::move( type )
			, std::move( fn )
			, std::move( argList ) );
	}

	FnCallPtr ExprCache::makeMemberFnCall( type::TypePtr type
		, IdentifierPtr fn
		, ExprPtr instance
		, ExprList argList )
	{
		return makeExpr< FnCall >( std::move( type )
			, std::move( fn )
			, std::move( instance )
			, std::move( argList ) );
	}

	GreaterPtr ExprCache::makeGreater( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Greater >( typesCache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}

	GreaterEqualPtr ExprCache::makeGreaterEqual( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< GreaterEqual >( typesCache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}

	IdentifierPtr ExprCache::makeIdentifier( type::TypesCache & typesCache
		, var::VariablePtr var )
	{
		return makeExpr< Identifier >( typesCache
			, std::move( var ) );
	}

	InitPtr ExprCache::makeInit( IdentifierPtr identifier
		, ExprPtr initialiser )
	{
		return makeExpr< Init >( std::move( identifier )
			, std::move( initialiser ) );
	}

	IntrinsicCallPtr ExprCache::makeIntrinsicCall( type::TypePtr type
		, Intrinsic intrinsic
		, ExprList argList )
	{
		return makeExpr< IntrinsicCall >( std::move( type )
			, intrinsic
			, std::move( argList ) );
	}

	LessPtr ExprCache::makeLess( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Less >( typesCache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}

	LessEqualPtr ExprCache::makeLessEqual( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< LessEqual >( typesCache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, bool value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, signed char value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, signed short value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, signed int value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, signed long value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, signed long long value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, unsigned char value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, unsigned short value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, unsigned int value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, unsigned long value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, unsigned long long value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, float value )
	{
		return makeExpr< Literal >( typesCache, value );
	}

	LiteralPtr ExprCache::makeLiteral( type::TypesCache & typesCache, double value )
	{
		return makeExpr< Literal >( typesCache, value );
	}


	LogAndPtr ExprCache::makeLogAnd( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< LogAnd >( typesCache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}

	LogNotPtr ExprCache::makeLogNot( type::TypesCache & typesCache
		, ExprPtr operand )
	{
		return makeExpr< LogNot >( typesCache.getBool()
			, std::move( operand ) );
	}

	LogOrPtr ExprCache::makeLogOr( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< LogOr >( typesCache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}

	LShiftPtr ExprCache::makeLShift( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< LShift >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	LShiftAssignPtr ExprCache::makeLShiftAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< LShiftAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	MbrSelectPtr ExprCache::makeMbrSelect( ExprPtr outer
		, uint32_t memberIndex
		, uint64_t flags )
	{
		return makeExpr< MbrSelect >( std::move( outer )
			, memberIndex
			, flags );
	}

	MinusPtr ExprCache::makeMinus( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Minus >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	MinusAssignPtr ExprCache::makeMinusAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< MinusAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	ModuloPtr ExprCache::makeModulo( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Modulo >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	ModuloAssignPtr ExprCache::makeModuloAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< ModuloAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	NotEqualPtr ExprCache::makeNotEqual( type::TypesCache & typesCache
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< NotEqual >( typesCache.getBool()
			, std::move( lhs )
			, std::move( rhs ) );
	}

	OrAssignPtr ExprCache::makeOrAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< OrAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	PostDecrementPtr ExprCache::makePostDecrement( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< PostDecrement >( std::move( type )
			, std::move( operand ) );
	}

	PostIncrementPtr ExprCache::makePostIncrement( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< PostIncrement >( std::move( type )
			, std::move( operand ) );
	}

	PreDecrementPtr ExprCache::makePreDecrement( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< PreDecrement >( std::move( type )
			, std::move( operand ) );
	}

	PreIncrementPtr ExprCache::makePreIncrement( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< PreIncrement >( std::move( type )
			, std::move( operand ) );
	}

	QuestionPtr ExprCache::makeQuestion( type::TypePtr type
		, ExprPtr ctrlExpr
		, ExprPtr trueExpr
		, ExprPtr falseExpr )
	{
		return makeExpr< Question >( std::move( type )
			, std::move( ctrlExpr )
			, std::move( trueExpr )
			, std::move( falseExpr ) );
	}

	RShiftPtr ExprCache::makeRShift( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< RShift >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	RShiftAssignPtr ExprCache::makeRShiftAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< RShiftAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	StorageImageAccessCallPtr ExprCache::makeStorageImageAccessCall( type::TypePtr type
		, StorageImageAccess imageAccess
		, ExprList argList )
	{
		return makeExpr< StorageImageAccessCall >( std::move( type )
			, imageAccess
			, std::move( argList ) );
	}

	StreamAppendPtr ExprCache::makeStreamAppend( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< StreamAppend >( std::move( type )
			, std::move( operand ) );
	}

	SwitchCasePtr ExprCache::makeSwitchCase( LiteralPtr label )
	{
		return makeExpr< SwitchCase >( std::move( label ) );
	}

	SwitchTestPtr ExprCache::makeSwitchTest( ExprPtr value )
	{
		return makeExpr< SwitchTest >( std::move( value ) );
	}

	SwizzlePtr ExprCache::makeSwizzle( ExprPtr outer
		, SwizzleKind swizzle )
	{
		assert( type::isVectorType( outer->getType() )
			|| ( type::isScalarType( outer->getType() )
				&& ( swizzle == SwizzleKind::e0
					|| swizzle == SwizzleKind::e00
					|| swizzle == SwizzleKind::e000
					|| swizzle == SwizzleKind::e0000 ) ) );
		return makeExpr< Swizzle >( std::move( outer )
			, swizzle );
	}

	TimesPtr ExprCache::makeTimes( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< Times >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	TimesAssignPtr ExprCache::makeTimesAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< TimesAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	UnaryMinusPtr ExprCache::makeUnaryMinus( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< UnaryMinus >( std::move( type )
			, std::move( operand ) );
	}

	UnaryPlusPtr ExprCache::makeUnaryPlus( ExprPtr operand )
	{
		auto type = operand->getType();
		return makeExpr< UnaryPlus >( std::move( type )
			, std::move( operand ) );
	}

	XorAssignPtr ExprCache::makeXorAssign( type::TypePtr type
		, ExprPtr lhs
		, ExprPtr rhs )
	{
		return makeExpr< XorAssign >( std::move( type )
			, std::move( lhs )
			, std::move( rhs ) );
	}

	ExprPtr ExprCache::makeDummyExpr( type::TypePtr type )
	{
		auto & typesCache = type->getTypesCache();
		return makeExpr< Expr >( sizeof( Expr )
			, typesCache
			, std::move( type )
			, Kind::eIdentifier
			, Flag::eDummy );
	}

	LiteralPtr ExprCache::makeLiteral( Literal const & rhs )
	{
		return makeExpr< Literal >( rhs );
	}

	IdentifierPtr ExprCache::makeIdentifier( Identifier const & rhs )
	{
		return makeExpr< Identifier >( rhs );
	}
	EqualPtr ExprCache::makeEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< Equal >( type, std::move( lhs ), std::move( rhs ) );
	}

	GreaterPtr ExprCache::makeGreater( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< Greater >( type, std::move( lhs ), std::move( rhs ) );
	}

	GreaterEqualPtr ExprCache::makeGreaterEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< GreaterEqual >( type, std::move( lhs ), std::move( rhs ) );
	}

	LessPtr ExprCache::makeLess( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< Less >( type, std::move( lhs ), std::move( rhs ) );
	}

	LessEqualPtr ExprCache::makeLessEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< LessEqual >( type, std::move( lhs ), std::move( rhs ) );
	}

	NotEqualPtr ExprCache::makeNotEqual( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< NotEqual >( type, std::move( lhs ), std::move( rhs ) );
	}

	LogAndPtr ExprCache::makeLogAnd( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< LogAnd >( type, std::move( lhs ), std::move( rhs ) );
	}

	LogNotPtr ExprCache::makeLogNot( type::TypePtr type, ExprPtr operand )
	{
		return makeExpr< LogNot >( type, std::move( operand ) );
	}

	LogOrPtr ExprCache::makeLogOr( type::TypePtr type, ExprPtr lhs, ExprPtr rhs )
	{
		return makeExpr< LogOr >( type, std::move( lhs ), std::move( rhs ) );
	}

	void * ExprCache::allocExpr( size_t size )
	{
		if ( m_cacheMode == CacheMode::eNone )
		{
			return malloc( size );
		}

		if ( m_cacheMode == CacheMode::eArena )
		{
			if ( !m_currentMemory
				|| size > m_currentMemory->data->size() - m_currentMemory->index )
			{
				m_currentMemory = &m_memory.emplace_back();
			}

			auto result = m_currentMemory->data->data() + m_currentMemory->index;
			m_currentMemory->index += size;
			return result;
		}

		auto it = m_pools.emplace( size, nullptr ).first;

		if ( !it->second )
		{
			it->second = std::make_unique < details::BuddyAllocator >( 16u, uint32_t( size ) );
		}

		auto & pool = *it->second;
		auto result =  pool.allocate( size );
		assert( result != nullptr );
		return result;
	}

	void ExprCache::freeExpr( Expr * expr )
	{
		if ( m_cacheMode == CacheMode::eNone )
		{
			expr->~Expr();
			free( expr );
		}

		if ( m_cacheMode == CacheMode::eBuddy )
		{
			auto size = expr->getSize();
			auto it = m_pools.find( size );

			if ( it != m_pools.end() )
			{
				expr->~Expr();
				it->second->deallocate( reinterpret_cast< std::byte * >( expr ) );
			}
		}
	}

	//*********************************************************************************************
}
