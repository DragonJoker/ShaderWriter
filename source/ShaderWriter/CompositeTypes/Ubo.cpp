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
		, ast::type::MemoryLayout layout
		, bool enabled )
		: m_writer{ writer }
		, m_shader{ m_writer.getShader() }
		, m_stmt{ stmt::makeConstantBufferDecl( name, layout, bind, set ) }
		, m_name{ name }
		, m_interface{ m_writer.getTypesCache(), layout, name }
		, m_info{ m_interface.getType(), bind, set }
		, m_var{ writer.getShader().registerName( m_name, m_info.type, var::Flag::eUniform ) }
		, m_enabled{ enabled }
	{
	}

	void Ubo::end()
	{
		if ( isEnabled() )
		{
			addStmt( m_shader, std::move( m_stmt ) );
			m_shader.registerUbo( m_name, m_info );
		}
	}

	StructInstance Ubo::declStructMember( std::string const & name
		, Struct const & s
		, bool enabled )
	{
		auto type = m_interface.registerMember( name, s.getType() );
		auto var = registerMember( m_writer, m_var, name, type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return StructInstance{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	Array< StructInstance > Ubo::declStructMember( std::string const & name
		, Struct const & s
		, uint32_t dimension
		, bool enabled )
	{
		auto type = m_interface.registerMember( name, s.getType(), dimension );
		auto var = registerMember( m_writer, m_var, name, type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Array< StructInstance >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
