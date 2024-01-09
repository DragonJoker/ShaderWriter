/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtShaderBufferDecl_H___
#define ___AST_StmtShaderBufferDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class ShaderBufferDecl
		: public Compound
	{
	public:
		SDAST_API ShaderBufferDecl( StmtCache & stmtCache
			, var::VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );
		SDAST_API void add( VariableDeclPtr decl );
		SDAST_API type::MemoryLayout getMemoryLayout()const;
		SDAST_API std::string getSsboName()const;
		SDAST_API type::StructPtr getType()const;

		SDAST_API void accept( VisitorPtr vis )const override;

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
		using Compound::addStmt;

	private:
		var::VariablePtr m_variable;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
}

#endif
