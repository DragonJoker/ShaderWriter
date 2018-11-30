/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		inline ast::type::StructPtr getSsboType( std::string const & name
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout )
		{
			ast::type::ArrayPtr arrayType = type::makeArrayType( dataType, type::UnknownArraySize );
			ast::type::StructPtr result = type::makeStructType( layout, name );
			result->declMember( name + "Data", arrayType );
			return result;
		}

		inline ast::type::StructPtr getSsboType( std::string const & name
			, ast::type::StructPtr dataType )
		{
			ast::type::StructPtr result = type::makeStructType( dataType->getMemoryLayout(), name );
			result->declMember( name + "Data", dataType, type::UnknownArraySize );
			return result;
		}
	}

	template< typename InstanceT >
	ArraySsboT< InstanceT >::ArraySsboT( ShaderWriter & writer
		, std::string const & name
		, ast::type::TypePtr dataType
		, ast::type::MemoryLayout layout
		, uint32_t bind
		, uint32_t set )
		: m_shader{ writer.getShader() }
		, m_name{ name }
		, m_info{ details::getSsboType( m_name, dataType, layout ), bind, set }
		, m_ssboType{ m_info.getType() }
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

	template< typename InstanceT >
	ArraySsboT< InstanceT >::ArraySsboT( ShaderWriter & writer
		, std::string const & name
		, ast::type::StructPtr dataType
		, uint32_t bind
		, uint32_t set )
		: m_shader{ writer.getShader() }
		, m_name{ name }
		, m_info{ details::getSsboType( m_name, dataType ), bind, set }
		, m_ssboType{ m_info.getType() }
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

	template< typename InstanceT >
	InstanceT ArraySsboT< InstanceT >::operator[]( uint32_t index )
	{
		return InstanceT{ &m_shader
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( makeIdent( m_ssboVar )
					, 0u
					, makeIdent( m_dataVar ) )
				, makeExpr( index ) ) };
	}

	template< typename InstanceT >
	InstanceT ArraySsboT< InstanceT >::operator[]( UInt const & index )
	{
		return InstanceT{ &m_shader
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( makeIdent( m_ssboVar )
					, 0u
					, makeIdent( m_dataVar ) )
				, makeExpr( index ) ) };
	}
}
