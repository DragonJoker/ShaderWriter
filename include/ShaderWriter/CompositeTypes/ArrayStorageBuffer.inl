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

		template< typename InstanceT, typename ... ParamsT >
		inline ast::type::BaseStructPtr makeSsboType( ShaderWriter & writer
			, bool enabled
			, ParamsT && ... params )
		{
			auto & cache = getTypesCache( writer );
			ast::type::BaseStructPtr result = InstanceT::makeType( cache
				, std::forward< ParamsT >( params )... );

			if ( enabled )
			{
				sdw::addStmt( writer, makeStructureDecl( getStmtCache( writer ), result ) );
			}

			return result;
		}
	}

	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, std::string instanceName
		, ast::type::TypePtr dataType
		, ast::type::MemoryLayout layout
		, uint32_t bind
		, uint32_t set
		, bool enabled )
		: m_writer{ writer }
		, m_builder{ sdw::getBuilder( m_writer ) }
		, m_name{ std::move( instanceName ) }
		, m_redeclare{ hasVariable( m_builder, m_name + "Inst", false ) }
		, m_interface{ details::getSsboType( getTypesCache( writer ), m_name, dataType, layout ) }
		, m_info{ m_interface.getType(), bind, set }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ ( m_redeclare
			? getVariable( m_builder, m_name + "Data", false )
			: registerName( m_builder, m_name + "Data", m_ssboType->getMember( m_name + "Data" ).type, var::Flag::eStorageBuffer ) ) }
		, m_ssboVar{ ( m_redeclare
			? getVariable( m_builder, m_name + "Inst", false )
			: registerName( m_builder, m_name + "Inst", m_ssboType, var::Flag::eStorageBuffer ) ) }
		, m_enabled{ enabled }
	{
		if ( isEnabled() && !m_redeclare )
		{
			addStmt( m_writer
				, makeShaderStructBufferDecl( getStmtCache( m_writer )
					, m_name
					, m_ssboVar
					, m_dataVar
					, bind
					, set ) );
			registerSsbo( m_writer, m_name, m_info );
		}
	}

	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, std::string instanceName
		, ast::type::BaseStructPtr dataType
		, uint32_t bind
		, uint32_t set
		, bool enabled )
		: m_writer{ writer }
		, m_builder{ sdw::getBuilder( m_writer ) }
		, m_name{ std::move( instanceName ) }
		, m_redeclare{ hasVariable( m_builder, m_name + "Inst", false ) }
		, m_interface{ details::getSsboType( getTypesCache( writer ), m_name, dataType ) }
		, m_info{ m_interface.getType(), bind, set }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ ( m_redeclare
			? getVariable( m_builder, m_name + "Data", false )
			: registerName( m_builder, m_name + "Data", m_ssboType->getMember( m_name + "Data" ).type, var::Flag::eStorageBuffer ) ) }
		, m_ssboVar{ ( m_redeclare
			? getVariable( m_builder, m_name + "Inst", false )
			: registerName( m_builder, m_name + "Inst", m_ssboType, var::Flag::eStorageBuffer ) ) }
		, m_enabled{ enabled }
	{
		if ( isEnabled() && !m_redeclare )
		{
			addStmt( m_writer
				, makeShaderStructBufferDecl( getStmtCache( m_writer )
					, m_name
					, m_ssboVar
					, m_dataVar
					, bind
					, set ) );
			registerSsbo( m_writer, m_name, m_info );
		}
	}

	template< typename InstanceT >
	template< typename ... ParamsT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, std::string instanceName
		, uint32_t bind
		, uint32_t set
		, bool enabled
		, ParamsT && ... params )
		: ArrayStorageBufferT{ writer
			, std::move( instanceName )
			, details::makeSsboType< InstanceT >( writer
				, enabled
				, std::forward< ParamsT >( params )... )
			, bind
			, set
			, enabled }
	{
	}

	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, std::string instanceName
		, ast::expr::ExprPtr addressExpr
		, bool enabled )
		: m_writer{ writer }
		, m_builder{ sdw::getBuilder( m_writer ) }
		, m_name{ std::move( instanceName ) }
		, m_redeclare{ hasVariable( m_builder, m_name, false ) }
		, m_interface{ std::static_pointer_cast< ast::type::BaseStruct >( static_cast< ast::type::Pointer const & >( *addressExpr->getType() ).getPointerType() ) }
		, m_info{ m_interface.getType(), ~0u, ~0u }
		, m_ssboType{ m_interface.getType() }
		, m_dataVar{ ( m_redeclare
			? getVariable( m_builder, m_name + "Data", false )
			: registerName( m_builder, m_name + "Data", m_ssboType->getMember( m_interface.getType()->getName() + "Data" ).type ) ) }
		, m_ssboVar{ ( m_redeclare
			? getVariable( m_builder, m_name, false )
			: registerName( m_builder, m_name, m_ssboType ) ) }
		, m_enabled{ enabled }
	{
		if ( isEnabled() && !m_redeclare )
		{
			addStmt( m_writer
				, sdw::makeSimple( getStmtCache( m_writer )
					, sdw::makeInit( sdw::registerName( m_writer, m_name, m_interface.getType() )
						, std::move( addressExpr ) ) ) );
			registerSsbo( m_writer, m_name, m_info );
		}
	}
	
	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, std::string instanceName
		, ast::type::TypePtr dataType
		, ast::type::MemoryLayout layout
		, LocationHelper location
		, bool enabled )
		: ArrayStorageBufferT{ writer
			, std::move( instanceName )
			, std::move( dataType )
			, layout
			, location.binding
			, location.set
			, enabled }
	{
	}

	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, std::string instanceName
		, ast::type::BaseStructPtr dataType
		, LocationHelper location
		, bool enabled )
		: ArrayStorageBufferT{ writer
			, std::move( instanceName )
			, std::move( dataType )
			, location.binding
			, location.set
			, enabled }
	{
	}

	template< typename InstanceT >
	template< typename ... ParamsT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, std::string instanceName
		, LocationHelper location
		, bool enabled
		, ParamsT && ... params )
		: ArrayStorageBufferT{ writer
			, std::move( instanceName )
			, location.binding
			, location.set
			, enabled
			, std::forward< ParamsT >( params )... }
	{
	}

	template< typename InstanceT >
	InstanceT ArrayStorageBufferT< InstanceT >::operator[]( uint32_t index )const
	{
		return InstanceT{ m_writer
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( sdw::makeIdent( getExprCache( m_writer ), getTypesCache( m_writer ), m_ssboVar )
					, 0u
					, m_dataVar->getFlags() )
				, makeExpr( m_writer, index ) )
			, isEnabled() };
	}

	template< typename InstanceT >
	InstanceT ArrayStorageBufferT< InstanceT >::operator[]( UInt32 const & index )const
	{
		return InstanceT{ m_writer
			, sdw::makeArrayAccess( getNonArrayType( m_dataVar->getType() )
				, sdw::makeMbrSelect( sdw::makeIdent( getExprCache( m_writer ), getTypesCache( m_writer ), m_ssboVar )
					, 0u
					, m_dataVar->getFlags() )
				, makeExpr( m_writer, index ) )
			, isEnabled() };
	}

	template< typename InstanceT >
	template< typename ... ParamsT >
	sdw::type::BaseStructPtr ArrayStorageBufferT< InstanceT >::makeType( ast::type::TypesCache & cache
		, std::string const & name
		, ast::type::MemoryLayout layout
		, bool enabled
		, ParamsT && ... params )
	{
		return details::getSsboType( cache
			, name
			, InstanceT::makeType( cache, std::forward< ParamsT >( params )... )
			, layout );
	}
}
