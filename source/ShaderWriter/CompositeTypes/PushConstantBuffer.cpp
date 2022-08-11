/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/PushConstantBuffer.hpp"

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	PushConstantBuffer::PushConstantBuffer( ShaderWriter & writer
		, std::string name
		, ast::type::MemoryLayout layout
		, bool enabled )
		: m_writer{ writer }
		, m_shader{ m_writer.getShader() }
		, m_stmt{ stmt::makePushConstantsBufferDecl( name, layout ) }
		, m_name{ std::move( name ) }
		, m_info{ writer.getTypesCache(), layout, m_name }
		, m_var{ writer.getShader().registerName( m_name, m_info.getType(), var::Flag::ePushConstant ) }
		, m_enabled{ enabled }
	{
	}

	void PushConstantBuffer::end()
	{
		if ( isEnabled() )
		{
			addStmt( m_shader, std::move( m_stmt ) );
			m_shader.registerPcb( m_name, m_info );
		}
	}

	StructInstance PushConstantBuffer::declStructMember( std::string name
		, Struct const & s
		, bool enabled )
	{
		auto type = m_info.registerMember( name, s.getType() );
		auto var = registerMember( m_writer, m_var, name, type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return StructInstance{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	Array< StructInstance > PushConstantBuffer::declStructMember( std::string name
		, Struct const & s
		, uint32_t dimension
		, bool enabled )
	{
		auto type = m_info.registerMember( name, s.getType(), dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Array< StructInstance >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
