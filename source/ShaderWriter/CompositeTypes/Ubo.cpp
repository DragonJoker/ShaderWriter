/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Ubo.hpp"

#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"
#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Type/TypeStruct.hpp>

namespace sdw
{
	Ubo::Ubo( ShaderWriter & writer
		, std::string const & name
		, uint32_t bind
		, uint32_t set
		, ast::type::MemoryLayout layout )
		: m_shader{ writer.getShader() }
		, m_stmt{ stmt::makeConstantBufferDecl( name, layout, bind, set ) }
		, m_name{ name }
		, m_interface{ writer.getTypesCache(), layout, name }
		, m_info{ m_interface.getType(), bind, set }
		, m_var{ var::makeVariable( m_info.type, m_name, var::Flag::eUniform ) }
	{
	}

	void Ubo::end()
	{
		addStmt( m_shader, std::move( m_stmt ) );
		m_shader.registerUbo( m_name, m_info );
	}

	StructInstance Ubo::declStructMember( std::string const & name
		, Struct const & s )
	{
		auto type = m_interface.registerMember( name, s.getType() );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return StructInstance{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	Array< StructInstance > Ubo::declStructMember( std::string const & name
		, Struct const & s
		, uint32_t dimension )
	{
		auto type = m_interface.registerMember( name, s.getType(), dimension );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< StructInstance >{ &m_shader
			, makeExpr( m_shader, var ) };
	}
}
