/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Ubo.hpp"

#include "ShaderWriter/Struct.hpp"
#include "ShaderWriter/StructInstance.hpp"
#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	Ubo::Ubo( ShaderWriter & writer
		, std::string const & name
		, uint32_t bind
		, uint32_t set )
		: m_shader{ writer.getShader() }
		, m_stmt{ stmt::makeConstantBufferDecl( name, bind, set ) }
		, m_name{ name }
		, m_info{ type::MemoryLayout::eStd140, name, bind, set }
		, m_var{ var::makeVariable( m_info.getType(), m_name, var::Flag::eBound ) }
	{
	}

	void Ubo::end()
	{
		addStmt( m_shader, std::move( m_stmt ) );
		m_shader.registerUbo( m_name, m_info );
	}

	StructInstance Ubo::declMember( std::string const & name, Struct const & s )
	{
		auto type = m_info.registerMember( name, s.getType() );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return StructInstance{ &m_shader
			, makeExpr( var ) };
	}
}
