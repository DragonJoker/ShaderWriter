/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HitAttribute_H___
#define ___SDW_HitAttribute_H___
#pragma once

#include "ShaderWriter/BaseTypes/Boolean.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/BaseTypes/ReturnWrapper.hpp"

namespace sdw
{
	struct HitAttribute
	{
		SDW_API HitAttribute( ShaderWriter & writer
			, expr::Expr const * expr
			, bool enabled );

		SDW_API ReturnWrapperT< Boolean > reportIntersection( Float const tHit
			, UInt32 const hitKind )const;

		ShaderWriter * getWriter()const
		{
			return m_plWriter;
		}

		ast::expr::Expr const * getExpr()const
		{
			return m_plExpr;
		}

		bool isEnabled()const
		{
			return m_plEnabled;
		}

	private:
		ShaderWriter * m_plWriter;
		expr::Expr const * m_plExpr;
		bool m_plEnabled;
	};

	template< typename ValueT >
	struct HitAttributeT
		: public ValueT
	{
		SDW_DeclValue( , HitAttributeT );

		template< typename ... ParamsT >
		HitAttributeT( ShaderWriter & writer
			, ParamsT && ... params );
		HitAttributeT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		HitAttributeT & operator=( ValueT const & rhs );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		ReturnWrapperT< Boolean > reportIntersection( Float tHit
			, UInt32 const & hitKind );

	private:
		HitAttribute m_internal;
	};

	SDW_API expr::ExprPtr makeExpr( HitAttribute const & value );

	template< typename ValueT >
	expr::ExprPtr makeExpr( HitAttributeT< ValueT > const & value );
}

#include "HitAttribute.inl"

#endif
