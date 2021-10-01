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
		SDAST_API ShaderBufferDecl( var::VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );
		SDAST_API void add( VariableDeclPtr decl );
		SDAST_API type::MemoryLayout getMemoryLayout()const;
		SDAST_API std::string getSsboName()const;
		SDAST_API type::StructPtr getType()const;

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
		using Compound::addStmt;

	private:
		var::VariablePtr m_variable;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using ShaderBufferDeclPtr = std::unique_ptr< ShaderBufferDecl >;

	inline ShaderBufferDeclPtr makeShaderBufferDecl( type::TypesCache & cache
		, std::string const & ssboName
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet
		, uint32_t nextVarId )
	{
		auto type = cache.getStruct( layout, ssboName );
		assert( type != nullptr );
		return std::make_unique< ShaderBufferDecl >( var::makeVariable( nextVarId, type, ssboName + "_data" )
			, bindingPoint
			, bindingSet );
	}

	inline ShaderBufferDeclPtr makeShaderBufferDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< ShaderBufferDecl >( var
			, bindingPoint
			, bindingSet );
	}
}

#endif
