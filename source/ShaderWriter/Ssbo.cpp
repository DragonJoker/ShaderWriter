/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Ssbo.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	Ssbo::Ssbo( ShaderWriter & writer
		, std::string const & name
		, uint32_t bind
		, uint32_t set
		, ast::type::MemoryLayout layout )
		: m_shader{ writer.getShader() }
		, m_stmt{ stmt::makeShaderBufferDecl( name, bind, set ) }
		, m_name{ name }
		, m_info{ layout, name, bind, set }
		, m_var{ var::makeVariable( m_info.getType(), m_name, var::Flag::eUniform ) }
	{
	}

	void Ssbo::end()
	{
		addStmt( m_shader, std::move( m_stmt ) );
		m_shader.registerSsbo( m_name, m_info );
	}

	StructInstance Ssbo::declMember( std::string const & name, Struct const & s )
	{
		auto type = m_info.registerMember( name, s.getType() );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return StructInstance{ &m_shader
			, makeExpr( var ) };
	}
}
