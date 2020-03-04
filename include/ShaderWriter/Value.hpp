/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Value_H___
#define ___SDW_Value_H___

#include "ShaderWriterPrerequisites.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

namespace sdw
{
	template< typename T > struct is_type : public std::false_type {};

	struct Value
	{
		SDW_API Value( Shader * shader
			, expr::ExprPtr expr );
		SDW_API Value( Value && rhs );
		SDW_API Value( Value const & rhs );
		SDW_API virtual ~Value();
		SDW_API Value & operator=( Value const & rhs );
		SDW_API void updateContainer( Value const & variable );
		SDW_API stmt::Container * getContainer()const;
		SDW_API void updateExpr( expr::ExprPtr expr );

		inline type::TypePtr getType()const
		{
			return m_expr->getType();
		}

		inline expr::Expr * getExpr()const
		{
			return m_expr.get();
		}

		inline Shader * getShader()const
		{
			return m_shader;
		}

		template< typename OutputT >
		static inline expr::ExprPtr ctorCast( expr::ExprPtr op )
		{
			auto isSubComponent = []( type::Kind sub, type::Kind comp )
			{
				switch ( comp )
				{
				case ast::type::Kind::eVec2B:
					return sub == ast::type::Kind::eBoolean;
				case ast::type::Kind::eVec3B:
					return sub == ast::type::Kind::eBoolean
						|| sub == ast::type::Kind::eVec2B;
				case ast::type::Kind::eVec4B:
					return sub == ast::type::Kind::eBoolean
						|| sub == ast::type::Kind::eVec2B
						|| sub == ast::type::Kind::eVec3B;
				case ast::type::Kind::eVec2I:
					return sub == ast::type::Kind::eInt;
				case ast::type::Kind::eVec3I:
					return sub == ast::type::Kind::eInt
						|| sub == ast::type::Kind::eVec2I;
				case ast::type::Kind::eVec4I:
					return sub == ast::type::Kind::eInt
						|| sub == ast::type::Kind::eVec2I
						|| sub == ast::type::Kind::eVec3I;
				case ast::type::Kind::eVec2U:
					return sub == ast::type::Kind::eUInt;
				case ast::type::Kind::eVec3U:
					return sub == ast::type::Kind::eUInt
						|| sub == ast::type::Kind::eVec2U;
				case ast::type::Kind::eVec4U:
					return sub == ast::type::Kind::eUInt
						|| sub == ast::type::Kind::eVec2U
						|| sub == ast::type::Kind::eVec3U;
				case ast::type::Kind::eVec2H:
					return sub == ast::type::Kind::eHalf;
				case ast::type::Kind::eVec3H:
					return sub == ast::type::Kind::eHalf
						|| sub == ast::type::Kind::eVec2H;
				case ast::type::Kind::eVec4H:
					return sub == ast::type::Kind::eHalf
						|| sub == ast::type::Kind::eVec2H
						|| sub == ast::type::Kind::eVec3H;
				case ast::type::Kind::eVec2F:
					return sub == ast::type::Kind::eFloat;
				case ast::type::Kind::eVec3F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec2F;
				case ast::type::Kind::eVec4F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec2F
						|| sub == ast::type::Kind::eVec3F;
				case ast::type::Kind::eVec2D:
					return sub == ast::type::Kind::eDouble;
				case ast::type::Kind::eVec3D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec2D;
				case ast::type::Kind::eVec4D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec2D
						|| sub == ast::type::Kind::eVec3D;
				case ast::type::Kind::eMat2x2F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec2F;
				case ast::type::Kind::eMat2x3F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec3F;
				case ast::type::Kind::eMat2x4F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec4F;
				case ast::type::Kind::eMat3x2F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec2F;
				case ast::type::Kind::eMat3x3F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec3F;
				case ast::type::Kind::eMat3x4F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec4F;
				case ast::type::Kind::eMat4x2F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec2F;
				case ast::type::Kind::eMat4x3F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec3F;
				case ast::type::Kind::eMat4x4F:
					return sub == ast::type::Kind::eFloat
						|| sub == ast::type::Kind::eVec4F;
				case ast::type::Kind::eMat2x2D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec2F;
				case ast::type::Kind::eMat2x3D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec3F;
				case ast::type::Kind::eMat2x4D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec4F;
				case ast::type::Kind::eMat3x2D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec2F;
				case ast::type::Kind::eMat3x3D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec3F;
				case ast::type::Kind::eMat3x4D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec4F;
				case ast::type::Kind::eMat4x2D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec2F;
				case ast::type::Kind::eMat4x3D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec3F;
				case ast::type::Kind::eMat4x4D:
					return sub == ast::type::Kind::eDouble
						|| sub == ast::type::Kind::eVec4F;
				case ast::type::Kind::eArray:
				case ast::type::Kind::eUndefined:
				case ast::type::Kind::eVoid:
				case ast::type::Kind::eBoolean:
				case ast::type::Kind::eInt:
				case ast::type::Kind::eUInt:
				case ast::type::Kind::eHalf:
				case ast::type::Kind::eFloat:
				case ast::type::Kind::eDouble:
				case ast::type::Kind::eFunction:
				case ast::type::Kind::eStruct:
				case ast::type::Kind::eSampler:
				case ast::type::Kind::eImage:
				case ast::type::Kind::eSampledImage:
				default:
					return sub == comp;
				}
			};

			if ( op->getType()->getKind() == typeEnum< OutputT >
				|| isSubComponent( typeEnum< OutputT >, op->getType()->getKind() ) )
			{
				return std::move( op );
			}

			auto & cache = op->getCache();
			return sdw::makeCast( cache.getBasicType( typeEnum< OutputT > )
				, std::move( op ) );
		}

		template< typename OutputT >
		static inline Value ctorCast( Value op )
		{
			return Value{ op.m_shader
				, ctorCast< OutputT >( std::move( op.m_expr ) ) };
		}

	private:
		expr::ExprPtr m_expr;
		Shader * m_shader;
		stmt::Container * m_container;
	};

	template< typename ... ValuesT >
	inline stmt::Container * findContainer( ValuesT const & ... values );
	template< typename ... ValuesT >
	inline Shader * findShader( ValuesT const & ... values );
	template< typename ... ValuesT >
	inline ast::type::TypesCache & findTypesCache( ValuesT const & ... values );

	SDW_API expr::ExprPtr makeExpr( Value const & variable
		, bool force = true );
	SDW_API expr::ExprPtr makeExpr( Shader const & shader
		, Value const & variable
		, bool force = true );
	SDW_API expr::ExprList makeFnArg( Shader const & shader
		, Value const & variable );

	template< typename ReturnT, typename OperandT, typename CreatorT >
	inline ReturnT writeUnOperator( OperandT const & operand
		, CreatorT creator );

	template< typename ReturnT, typename LhsT, typename RhsT, typename CreatorT >
	inline ReturnT writeBinOperator( LhsT const & lhs
		, RhsT const & rhs
		, CreatorT creator );
}

#include "Value.inl"

#endif
