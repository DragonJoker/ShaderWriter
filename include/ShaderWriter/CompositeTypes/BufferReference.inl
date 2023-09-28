/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename BufferT >
	template< typename ... ParamsT >
	BufferReferenceT< BufferT >::BufferReferenceT( ShaderWriter & writer
		, std::string name
		, ast::type::MemoryLayout layout
		, ast::type::Storage storage
		, bool enabled
		, ParamsT && ... params )
		: m_writer{ writer }
		, m_type{ BufferT::makeType( getTypesCache( writer )
			, std::move( name )
			, layout
			, enabled
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
		return BufferT{ m_writer
			, std::move( instanceName )
			, sdw::makeCast( getTypesCache( m_writer ).getPointerType( m_type, static_cast< ast::type::Pointer const & >( *m_pointer ).getStorage() )
				, makeExpr( address ) )
			, isEnabled() };
	}
}
