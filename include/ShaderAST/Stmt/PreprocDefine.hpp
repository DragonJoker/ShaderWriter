/*
See LICENSE file in root folder
*/
#ifndef ___AST_PreprocDefine_H___
#define ___AST_PreprocDefine_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class PreprocDefine
		: public Stmt
	{
	public:
		SDAST_API PreprocDefine( EntityName nameId
			, expr::ExprPtr expr );

		PreprocDefine( uint32_t id
			, std::string name
			, expr::ExprPtr expr )
			: PreprocDefine{ { id, std::move( name ) }, std::move( expr ) }
		{
		}

		SDAST_API void accept( VisitorPtr vis )override;

		inline uint32_t getId()const
		{
			return m_nameId.id;
		}

		inline std::string const & getName()const
		{
			return m_nameId.name;
		}

		inline expr::Expr * getExpr()const
		{
			return m_expr.get();
		}

	private:
		EntityName m_nameId;
		expr::ExprPtr m_expr;
	};
	using PreprocDefinePtr = std::unique_ptr< PreprocDefine >;

	inline PreprocDefinePtr makePreprocDefine( EntityName nameId
		, std::string name
		, expr::ExprPtr expr )
	{
		return std::make_unique< PreprocDefine >( std::move( nameId )
			, std::move( expr ) );
	}

	inline PreprocDefinePtr makePreprocDefine( uint32_t id
		, std::string name
		, expr::ExprPtr expr )
	{
		return std::make_unique< PreprocDefine >( EntityName{ id, std::move( name ) }
			, std::move( expr ) );
	}
}

#endif
