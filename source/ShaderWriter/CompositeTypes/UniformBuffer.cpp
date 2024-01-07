/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/UniformBuffer.hpp"

#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"
#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Type/TypeStruct.hpp>

namespace sdw
{
	UniformBuffer::UniformBuffer( ShaderWriter & writer
		, std::string const & blockName
		, std::string variableName
		, uint32_t bind
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled )
		: m_writer{ writer }
		, m_builder{ m_writer.getBuilder() }
		, m_stmt{ m_builder.hasVariable( variableName, false ) ? nullptr : getStmtCache( m_writer ).makeConstantBufferDecl( variableName, layout, bind, set ) }
		, m_name{ std::move( variableName ) }
		, m_interface{ m_writer.getTypesCache(), layout, blockName }
		, m_info{ m_interface.getType(), bind, set }
		, m_var{ m_builder.registerName( m_name, m_info.type, var::Flag::eUniform ) }
		, m_enabled{ enabled }
	{
	}

	void UniformBuffer::end()
	{
		if ( isEnabled() && m_stmt )
		{
			addStmt( m_builder, std::move( m_stmt ) );
			m_builder.registerUbo( m_name, m_info );
		}
	}

	StructInstance UniformBuffer::declStructMember( std::string name
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

	Array< StructInstance > UniformBuffer::declStructMember( std::string name
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
			, isEnabled() && enabled };
	}
}
