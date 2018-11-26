/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructuredSsbo.hpp"

#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Type/TypeArray.hpp>

namespace sdw
{
	namespace
	{
		type::StructPtr getSsboType( std::string const & name
			, type::StructPtr dataType )
		{
			type::StructPtr result = type::makeStructType( dataType->getMemoryLayout(), name );
			result->declMember( name + "Data", dataType, type::UnknownArraySize );
			return result;
		}
	}

	StructuredSsbo::StructuredSsbo( ShaderWriter & writer
		, std::string const & name
		, Struct const & dataType
		, uint32_t bind
		, uint32_t set )
		: m_shader{ writer.getShader() }
		, m_name{ name }
		, m_info{ std::move( dataType.getType() ), bind, set }
		, m_ssboType{ getSsboType( m_name, m_info.getType() ) }
		, m_dataVar{ var::makeVariable( m_ssboType->getMember( m_name + "Data" ).type, m_name + "Data", var::Flag::eUniform ) }
		, m_ssboVar{ var::makeVariable( m_ssboType, m_name + "Inst", var::Flag::eUniform ) }
	{
		auto stmt = stmt::makeShaderStructBufferDecl( m_name
			, m_ssboVar
			, m_dataVar
			, bind
			, set );
		addStmt( m_shader, std::move( stmt ) );
		m_shader.registerSsbo( m_name, m_info );
	}

	StructInstance StructuredSsbo::operator[]( uint32_t index )
	{
		return StructInstance{ &m_shader
			, sdw::makeArrayAccess( m_info.getType()
				, sdw::makeMbrSelect( makeIdent( m_ssboVar )
					, 0u
					, makeIdent( m_dataVar ) )
				, expr::makeLiteral( index ) ) };
	}

	StructInstance StructuredSsbo::operator[]( UInt index )
	{
		return StructInstance{ &m_shader
			, sdw::makeArrayAccess( m_info.getType()
				, sdw::makeMbrSelect( makeIdent( m_ssboVar )
					, 0u
					, makeIdent( m_dataVar ) )
				, makeExpr( index ) ) };
	}
}
