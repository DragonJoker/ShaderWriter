/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Pcb.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	Pcb::Pcb( ShaderWriter & writer
		, std::string const & name )
		: m_shader{ writer.getShader() }
		, m_stmt{ stmt::makePushConstantsBufferDecl( name ) }
		, m_name{ name }
		, m_info{ type::MemoryLayout::eStd430, name, 0u, 0u }
		, m_var{ var::makeVariable( m_info.getType(), m_name, var::Flag::eShaderConstant ) }
	{
	}

	void Pcb::end()
	{
		addStmt( m_shader, std::move( m_stmt ) );
	}

	StructInstance Pcb::declMember( std::string const & name, Struct const & s )
	{
		auto type = m_info.registerMember( name, s.getType() );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return StructInstance{ &m_shader
			, makeExpr( var ) };
	}
}
