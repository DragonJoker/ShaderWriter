/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtShaderBufferDecl_H___
#define ___AST_StmtShaderBufferDecl_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Type/TypeStorageBuffer.hpp"
#include "ShaderAST/Var/Variable.hpp"

namespace ast::stmt
{
	class ShaderBufferDecl
		: public Stmt
	{
	public:
		SDAST_API ShaderBufferDecl( StmtCache & stmtCache
			, var::VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		SDAST_API void accept( VisitorPtr vis )const override;

		var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		type::TypePtr getInstanceType()const
		{
			return m_variable->getType();
		}

		std::string const & getInstanceName()const
		{
			return m_variable->getName();
		}

		type::MemoryLayout getMemoryLayout()const
		{
			return m_type->getMemoryLayout();
		}

		type::StorageBufferPtr getBuffer()const
		{
			return m_type;
		}

		uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		uint32_t getDescriptorSet()const
		{
			return m_bindingSet;
		}

		uint32_t getArraySize()const
		{
			return m_arraySize;
		}

	private:
		var::VariablePtr m_variable;
		type::StorageBufferPtr m_type;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
		uint32_t m_arraySize;
	};
}

#endif
