/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtShaderBufferDecl_H___
#define ___AST_StmtShaderBufferDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

namespace ast::stmt
{
	class ShaderBufferDecl
		: public Compound
	{
	public:
		ShaderBufferDecl( std::string const & ssboName
			, var::VariablePtr ssboInstance
			, var::VariablePtr data
			, uint32_t bindingPoint
			, uint32_t bindingSet );
		void add( VariableDeclPtr decl );

		void accept( VisitorPtr vis )override;

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
		var::VariablePtr m_ssboInstance;
		var::VariablePtr m_data;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using ShaderBufferDeclPtr = std::unique_ptr< ShaderBufferDecl >;

	inline ShaderBufferDeclPtr makeShaderBufferDecl( std::string const & ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< ShaderBufferDecl >( std::move( ssboName )
			, std::move( ssboInstance )
			, std::move( data )
			, bindingPoint
			, bindingSet );
	}
}

#endif
