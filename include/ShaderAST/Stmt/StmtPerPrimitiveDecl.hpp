/*
See LICENSE file in root folder
*/
#ifndef ___AST_PerPrimitiveDecl_H___
#define ___AST_PerPrimitiveDecl_H___
#pragma once

#include "Stmt.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class PerPrimitiveDecl
		: public Stmt
	{
	public:
		SDAST_API PerPrimitiveDecl( type::TypePtr type );

		SDAST_API void accept( VisitorPtr vis )override;

		inline type::TypePtr getType()const
		{
			return m_type;
		}

	private:
		type::TypePtr m_type;
	};
	using PerPrimitiveDeclPtr = std::unique_ptr< PerPrimitiveDecl >;

	inline PerPrimitiveDeclPtr makePerPrimitiveDecl( type::TypePtr type )
	{
		return std::make_unique< PerPrimitiveDecl >( std::move( type ) );
	}
}

#endif
