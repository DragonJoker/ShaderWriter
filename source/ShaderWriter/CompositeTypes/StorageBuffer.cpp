/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StorageBuffer.hpp"

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	StorageBuffer::StorageBuffer( ShaderWriter & writer
		, std::string name
		, uint32_t bind
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled )
		: m_writer{ writer }
		, m_shader{ m_writer.getShader() }
		, m_name{ std::move( name ) }
		, m_interface{ writer.getTypesCache(), layout, m_name + "Block" }
		, m_info{ m_interface.getType(), bind, set }
		, m_var{ writer.getShader().registerName( m_name, m_interface.getType(), var::Flag::eStorageBuffer ) }
		, m_stmt{ stmt::makeShaderBufferDecl( m_var, bind, set ) }
		, m_enabled{ enabled }
	{
	}

	void StorageBuffer::end()
	{
		if ( isEnabled() )
		{
			addStmt( m_shader, std::move( m_stmt ) );
			m_shader.registerSsbo( m_name, m_info );
		}
	}

	StructInstance StorageBuffer::declStructMember( std::string name
		, Struct const & s
		, bool enabled )
	{
		auto type = m_interface.registerMember( name, s.getType() );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return StructInstance{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	Array< StructInstance > StorageBuffer::declStructMember( std::string name
		, Struct const & s
		, uint32_t dimension
		, bool enabled )
	{
		auto type = m_interface.registerMember( name, s.getType(), dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Array< StructInstance >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled};
	}
}
