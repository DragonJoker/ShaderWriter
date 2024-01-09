/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtShaderStructBufferDecl_H___
#define ___AST_StmtShaderStructBufferDecl_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Type/TypeStruct.hpp"
#include "ShaderAST/Var/Variable.hpp"

namespace ast::stmt
{
	class ShaderStructBufferDecl
		: public Stmt
	{
	public:
		SDAST_API ShaderStructBufferDecl( StmtCache & stmtCache
			, std::string ssboName
			, var::VariablePtr ssboInstance
			, var::VariablePtr data
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline std::string const & getSsboName()const
		{
			return m_ssboName;
		}

		inline var::VariablePtr const & getSsboInstance()const
		{
			return m_ssboInstance;
		}

		inline var::VariablePtr getData()const
		{
			return m_data;
		}

		inline type::MemoryLayout getMemoryLayout()const
		{
			return std::static_pointer_cast< type::Struct >( m_ssboInstance->getType() )->getMemoryLayout();
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
		std::string m_ssboName;
		var::VariablePtr m_ssboInstance;
		var::VariablePtr m_data;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
}

#endif
