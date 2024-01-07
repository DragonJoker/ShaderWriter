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
		, std::string const & blockName
		, std::string variableName
		, ast::type::MemoryLayout layout
		, bool enabled )
		: m_writer{ writer }
		, m_builder{ m_writer.getBuilder() }
		, m_stmt{ m_builder.hasVariable( variableName, false ) ? nullptr : getStmtCache( m_writer ).makePushConstantsBufferDecl( variableName, layout ) }
		, m_name{ std::move( variableName ) }
		, m_info{ writer.getTypesCache(), layout, blockName }
		, m_var{ writer.getBuilder().registerName( m_name, m_info.getType(), var::Flag::ePushConstant ) }
		, m_enabled{ enabled }
	{
	}

	PushConstantBuffer::PushConstantBuffer( ShaderWriter & writer
		, std::string const & name
		, ast::type::MemoryLayout layout
		, bool enabled )
		: PushConstantBuffer{ writer
			, name + "Block"
			, name
			, layout
			, enabled }
	{
	}

	void PushConstantBuffer::end()
	{
		if ( isEnabled() && m_stmt )
		{
			addStmt( m_builder, std::move( m_stmt ) );
			m_builder.registerPcb( m_name, m_info );
		}
	}

	StructInstance PushConstantBuffer::declStructMember( std::string name
		, Struct const & s
		, bool enabled )
	{
		auto [type, added] = m_info.registerMember( name, s.getType() );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled && m_stmt && added )
		{
			m_stmt->add( getStmtCache( m_writer ).makeVariableDecl( var ) );
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
		auto [type, added] = m_info.registerMember( name, s.getType(), dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled && m_stmt && added )
		{
			m_stmt->add( getStmtCache( m_writer ).makeVariableDecl( var ) );
		}

		return Array< StructInstance >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
