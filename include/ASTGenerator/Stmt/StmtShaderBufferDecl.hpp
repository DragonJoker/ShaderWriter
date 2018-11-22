/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtShaderBufferDecl_H___
#define ___AST_StmtShaderBufferDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

#include "ASTGenerator/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class ShaderBufferDecl
		: public Compound
	{
	public:
		ShaderBufferDecl( std::string const & ssboName
			, type::MemoryLayout layout
			, uint32_t bindingPoint
			, uint32_t bindingSet );
		void add( VariableDeclPtr decl );

		void accept( VisitorPtr vis )override;

		inline std::string const & getSsboName()const
		{
			return m_ssboName;
		}

		inline type::MemoryLayout getMemoryLayout()const
		{
			return m_layout;
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
		std::string m_ssboName;
		type::MemoryLayout m_layout;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using ShaderBufferDeclPtr = std::unique_ptr< ShaderBufferDecl >;

	inline ShaderBufferDeclPtr makeShaderBufferDecl( std::string const & ssboName
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< ShaderBufferDecl >( std::move( ssboName )
			, layout
			, bindingPoint
			, bindingSet );
	}
}

#endif
