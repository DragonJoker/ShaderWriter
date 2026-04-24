/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		template< typename BufferT, typename ... ParamsT >
		static type::TypePtr getBufferReferenceType( type::TypesCache & cache
			, std::string const & name
			, ast::type::MemoryLayout layout
			, ParamsT && ... params )
		{
			type::TypePtr result = BufferT::makeType( cache
				, name, layout
				, std::forward< ParamsT >( params )... );

			if ( result->getKind() == type::Kind::eStorageBuffer )
			{
				result = static_cast< type::StorageBuffer * >( result )->getDataType();
				assert( result->getKind() == type::Kind::eStruct );
			}

			return result;
		}
	}

	template< typename BufferT >
	template< typename ... ParamsT >
	BufferReferenceT< BufferT >::BufferReferenceT( ShaderWriter & writer
		, std::string name
		, ast::type::MemoryLayout layout
		, ast::type::Storage storage
		, bool enabled
		, ParamsT && ... params )
		: m_writer{ writer }
		, m_name{ std::move( name ) }
		, m_layout{ layout }
		, m_type{ details::getBufferReferenceType< BufferT >( getTypesCache( writer )
			, m_name, m_layout
			, std::forward< ParamsT >( params )... ) }
		, m_pointer{ getTypesCache( writer ).getForwardPointerType( m_type, storage ) }
		, m_enabled{ enabled }
	{
		if ( enabled )
		{
			if ( auto structType = getStructType( m_type ) )
			{
				if ( auto inner = getStructType( getNonArrayType( structType->front().type ) ) )
				{
					sdw::addStmt( writer, makeStructureDecl( getStmtCache( writer ), inner ) );
				}
			}

			sdw::addStmt( writer, makeBufferReferenceDecl( getStmtCache( writer ), m_pointer ) );
		}
	}

	template< typename BufferT >
	BufferT BufferReferenceT< BufferT >::operator()( std::string instanceName
		, UInt64 address )
	{
		auto & builder = sdw::getBuilder( m_writer );
		bool enabled = m_enabled && address.isEnabled();
		if ( hasVariable( builder, instanceName, true ) )
		{
			return BufferT{ m_writer
				, makeExpr( m_writer, getVariable( builder, std::move( instanceName ), true ) )
				, enabled };
		}

		auto type = makeArrayStorageBufferType( getTypesCache( m_writer )
			, m_name, m_layout
			, m_type );
		auto var = registerStorageBuffer( m_writer
			, instanceName
			, type
			, ~0u
			, ~0u
			, var::Flag::eNone
			, enabled );

		if ( enabled )
		{
			auto addressExpr = sdw::makeCast( getTypesCache( m_writer ).getPointerType( m_type, static_cast< ast::type::Pointer const & >( *m_pointer ).getStorage() )
				, makeExpr( address ) );
			auto dataType = static_cast< ast::type::BaseStruct * >( static_cast< ast::type::Pointer const & >( *addressExpr->getType() ).getPointerType() );
			addStmt( m_writer
				, sdw::makeSimple( getStmtCache( m_writer )
					, sdw::makeInit( sdw::registerName( m_writer, instanceName, dataType ), std::move( addressExpr ) ) ) );
		}

		return BufferT{ m_writer
			, makeExpr( m_writer, var )
			, enabled };
	}
}
