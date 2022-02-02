/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtTextureDecl_H___
#define ___AST_StmtTextureDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class TextureDecl
		: public Stmt
	{
	public:
		SDAST_API TextureDecl( var::VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		SDAST_API void accept( VisitorPtr vis )override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		inline uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		inline uint32_t getDescriptorSet()const
		{
			return m_bindingSet;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using TextureDeclPtr = std::unique_ptr< TextureDecl >;

	inline TextureDeclPtr makeTextureDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< TextureDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}
}

#endif
