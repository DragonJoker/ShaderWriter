/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		inline ast::type::BaseStructPtr getSsboType( ast::type::TypesCache & cache
			, std::string const & name
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout )
		{
			ast::type::ArrayPtr arrayType = cache.getArray( dataType, type::UnknownArraySize );
			auto result = cache.getStruct( layout, name );
			result->declMember( name + "Data", arrayType );
			return result;
		}

		inline ast::type::BaseStructPtr getSsboType( ast::type::TypesCache & cache
			, std::string const & name
			, ast::type::BaseStructPtr dataType )
		{
			auto result = cache.getStruct( dataType->getMemoryLayout(), name );
			result->declMember( name + "Data", dataType, type::UnknownArraySize );
			return result;
		}

		template< typename InstanceT >
		inline ast::type::BaseStructPtr makeSsboType( ShaderWriter & writer
			, bool enabled )
		{
			auto & cache = getTypesCache( writer );
			ast::type::BaseStructPtr result = InstanceT::makeType( cache );

			if ( enabled )
			{
				sdw::addStmt( writer, sdw::makeStructDecl( result ) );
			}

			return result;
		}
	}

	template< typename InstanceT >
	ArraySsboT< InstanceT >::ArraySsboT( ShaderWriter & writer
		, std::string const & instanceName
		, ast::type::TypePtr dataType
		, ast::type::MemoryLayout layout
		, uint32_t bind
		, uint32_t set
		, bool enabled )
		: m_writer{ writer }
		, m_shader{ sdw::getShader( m_writer ) }
		, m_name{ instanceName }
		, m_interface{ details::getSsboType( getTypesCache( writer ), m_name, dataType, layout ) }
		, m_info{ m_interface.getType(), bind, set }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ var::makeVariable( getNextVarId( writer )
			, m_ssboType->getMember( m_name + "Data" ).type
			, m_name + "Data"
			, var::Flag::eStorageBuffer ) }
		, m_ssboVar{ var::makeVariable( getNextVarId( writer )
			, m_ssboType
			, m_name + "Inst"
			, var::Flag::eStorageBuffer ) }
		, m_enabled{ enabled }
	{
		if ( isEnabled() )
		{
			addStmt( m_writer
				, sdw::makeShaderStructBufferDecl( m_name
					, m_ssboVar
					, m_dataVar
					, bind
					, set ) );
			registerSsbo( m_writer, m_name, m_info );
		}
	}

	template< typename InstanceT >
	ArraySsboT< InstanceT >::ArraySsboT( ShaderWriter & writer
		, std::string const & instanceName
		, ast::type::BaseStructPtr dataType
		, uint32_t bind
		, uint32_t set
		, bool enabled )
		: m_writer{ writer }
		, m_shader{ sdw::getShader( m_writer ) }
		, m_name{ instanceName }
		, m_interface{ details::getSsboType( getTypesCache( writer ), m_name, dataType ) }
		, m_info{ m_interface.getType(), bind, set }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ var::makeVariable( getNextVarId( writer )
			, m_ssboType->getMember( m_name + "Data" ).type
			, m_name + "Data"
			, var::Flag::eStorageBuffer ) }
		, m_ssboVar{ var::makeVariable( getNextVarId( writer )
			, m_ssboType
			, m_name + "Inst"
			, var::Flag::eStorageBuffer ) }
		, m_enabled{ enabled }
	{
		if ( isEnabled() )
		{
			addStmt( m_writer
				, sdw::makeShaderStructBufferDecl( m_name
					, m_ssboVar
					, m_dataVar
					, bind
					, set ) );
			registerSsbo( m_writer, m_name, m_info );
		}
	}

	template< typename InstanceT >
	ArraySsboT< InstanceT >::ArraySsboT( ShaderWriter & writer
		, std::string const & instanceName
		, uint32_t bind
		, uint32_t set
		, bool enabled )
		: ArraySsboT{ writer
			, instanceName
			, details::makeSsboType< InstanceT >( writer, enabled )
			, bind
			, set
			, enabled }
	{
	}

	template< typename InstanceT >
	ArraySsboT< InstanceT >::ArraySsboT( ShaderWriter & writer
		, std::string const & instanceName
		, ast::expr::ExprPtr addressExpr
		, bool enabled )
		: m_writer{ writer }
		, m_shader{ sdw::getShader( m_writer ) }
		, m_name{ instanceName }
		, m_interface{ std::static_pointer_cast< ast::type::BaseStruct >( static_cast< ast::type::Pointer const & >( *addressExpr->getType() ).getPointerType() ) }
		, m_info{ m_interface.getType(), ~0u, ~0u }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ var::makeVariable( getNextVarId( writer )
			, m_ssboType->getMember( m_interface.getType()->getName() + "Data" ).type
			, m_name + "Data"
			, var::Flag::eStorageBuffer ) }
		, m_ssboVar{ var::makeVariable( getNextVarId( writer )
			, m_ssboType
			, m_name + "Inst"
			, var::Flag::eStorageBuffer ) }
		, m_enabled{ enabled }
	{
		if ( isEnabled() )
		{
			addStmt( m_writer
				, sdw::makeSimple( sdw::makeInit( m_shader.registerName( instanceName, m_interface.getType() )
					, std::move( addressExpr ) ) ) );
			registerSsbo( m_writer, m_name, m_info );
		}
	}

	template< typename InstanceT >
	InstanceT ArraySsboT< InstanceT >::operator[]( uint32_t index )
	{
		return InstanceT{ m_writer
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( sdw::makeIdent( getTypesCache( m_writer ), m_ssboVar )
					, 0u
					, m_dataVar->getFlags() )
				, makeExpr( m_writer, index ) )
			, isEnabled() };
	}

	template< typename InstanceT >
	InstanceT ArraySsboT< InstanceT >::operator[]( UInt const & index )
	{
		return InstanceT{ m_writer
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( sdw::makeIdent( getTypesCache( m_writer ), m_ssboVar )
					, 0u
					, m_dataVar->getFlags() )
				, makeExpr( m_writer, index ) )
			, isEnabled() };
	}

	template< typename InstanceT >
	sdw::type::BaseStructPtr ArraySsboT< InstanceT >::makeType( ast::type::TypesCache & cache
		, std::string const & name
		, ast::type::MemoryLayout layout
		, bool enabled )
	{
		return details::getSsboType( cache
			, name
			, InstanceT::makeType( cache )
			, layout );
	}
}
