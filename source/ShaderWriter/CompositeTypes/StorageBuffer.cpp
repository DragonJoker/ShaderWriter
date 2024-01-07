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
		, std::string const & blockName
		, std::string variableName
		, uint32_t bind
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled )
		: m_writer{ writer }
		, m_builder{ m_writer.getBuilder() }
		, m_name{ std::move( variableName ) }
		, m_interface{ writer.getTypesCache(), layout, blockName }
		, m_info{ m_interface.getType(), bind, set }
		, m_redeclare{ m_builder.hasVariable( m_name, false ) }
		, m_var{ m_redeclare ? m_builder.getVariable( m_name, false ) : m_builder.registerName( m_name, m_interface.getType(), var::Flag::eStorageBuffer ) }
		, m_stmt{ m_redeclare ? nullptr : getStmtCache( m_writer ).makeShaderBufferDecl( m_var, bind, set ) }
		, m_enabled{ enabled }
	{
	}

	void StorageBuffer::end()
	{
		if ( isEnabled() && m_stmt )
		{
			addStmt( m_builder, std::move( m_stmt ) );
			m_builder.registerSsbo( m_name, m_info );
		}
	}

	StructInstance StorageBuffer::declStructMember( std::string name
		, Struct const & s
		, bool enabled )
	{
		auto [type, added] = m_interface.registerMember( name, s.getType() );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled && m_stmt && added )
		{
			m_stmt->add( getStmtCache( m_writer ).makeVariableDecl( var ) );
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
		auto [type, added] = m_interface.registerMember( name, s.getType(), dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled && m_stmt && added )
		{
			m_stmt->add( getStmtCache( m_writer ).makeVariableDecl( var ) );
		}

		return Array< StructInstance >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled};
	}
}
