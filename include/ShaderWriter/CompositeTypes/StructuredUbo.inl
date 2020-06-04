/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		inline ast::type::StructPtr getUboType( ast::type::TypesCache & cache
			, std::string const & name
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout )
		{
			ast::type::ArrayPtr arrayType = cache.getArray( dataType, type::UnknownArraySize );
			ast::type::StructPtr result = cache.getStruct( layout, name );
			result->declMember( name + "Data", arrayType );
			return result;
		}

		inline ast::type::StructPtr getUboType( ast::type::TypesCache & cache
			, std::string const & name
			, ast::type::StructPtr dataType )
		{
			ast::type::StructPtr result = cache.getStruct( dataType->getMemoryLayout(), name );
			result->declMember( name + "Data", dataType, type::UnknownArraySize );
			return result;
		}
	}

	template< typename InstanceT >
	ArrayUboT< InstanceT >::ArrayUboT( ShaderWriter & writer
		, std::string const & name
		, ast::type::TypePtr dataType
		, ast::type::MemoryLayout layout
		, uint32_t bind
		, uint32_t set )
		: m_shader{ sdw::getShader( writer ) }
		, m_name{ name }
		, m_interface{ details::getUboType( getTypesCache( writer ), m_name, dataType, layout ) }
		, m_info{ m_interface.getType(), bind, set }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ var::makeVariable( m_ssboType->getMember( m_name + "Data" ).type, m_name + "Data", var::Flag::eUniform ) }
		, m_ssboVar{ var::makeVariable( m_ssboType, m_name + "Inst", var::Flag::eUniform ) }
	{
		addStmt( m_shader
			, sdw::makeShaderStructBufferDecl( m_name
				, m_ssboVar
				, m_dataVar
				, bind
				, set ) );
		registerSsbo( m_shader, m_name, m_info );
	}

	template< typename InstanceT >
	ArrayUboT< InstanceT >::ArrayUboT( ShaderWriter & writer
		, std::string const & name
		, ast::type::StructPtr dataType
		, uint32_t bind
		, uint32_t set )
		: m_shader{ sdw::getShader( writer ) }
		, m_name{ name }
		, m_interface{ details::getSsboType( getTypesCache( writer ), m_name, dataType ) }
		, m_info{ m_interface.getType(), bind, set }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ var::makeVariable( m_ssboType->getMember( m_name + "Data" ).type, m_name + "Data", var::Flag::eUniform ) }
		, m_ssboVar{ var::makeVariable( m_ssboType, m_name + "Inst", var::Flag::eUniform ) }
	{
		addStmt( m_shader
			, sdw::makeShaderStructBufferDecl( m_name
				, m_ssboVar
				, m_dataVar
				, bind
				, set ) );
		registerSsbo( m_shader, m_name, m_info );
	}

	template< typename InstanceT >
	InstanceT ArrayUboT< InstanceT >::operator[]( uint32_t index )
	{
		return InstanceT{ &m_shader
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( sdw::makeIdent( getTypesCache( m_shader ), m_ssboVar )
					, 0u
					, m_dataVar->getFlags() )
				, makeExpr( m_shader, index ) ) };
	}

	template< typename InstanceT >
	InstanceT ArrayUboT< InstanceT >::operator[]( UInt const & index )
	{
		return InstanceT{ &m_shader
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( sdw::makeIdent( getTypesCache( m_shader ), m_ssboVar )
					, 0u
					, m_dataVar->getFlags() )
				, makeExpr( m_shader, index ) ) };
	}
}
