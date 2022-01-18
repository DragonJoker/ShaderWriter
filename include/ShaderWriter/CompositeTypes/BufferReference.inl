/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename BufferT >
	BufferReferenceT< BufferT >::BufferReferenceT( ShaderWriter & writer
		, std::string const & name
		, ast::type::MemoryLayout layout
		, ast::type::Storage storage
		, bool enabled )
		: m_writer{ writer }
		, m_type{ BufferT::makeType( getTypesCache( writer ), name, layout, enabled ) }
		, m_pointer{ getTypesCache( writer ).getForwardPointerType( m_type, storage ) }
		, m_enabled{ enabled }
	{
		if ( enabled )
		{
			if ( auto structType = getStructType( m_type ) )
			{
				if ( auto inner = getStructType( getNonArrayType( structType->front().type ) ) )
				{
					sdw::addStmt( writer, sdw::makeStructDecl( inner ) );
				}
			}

			sdw::addStmt( writer, sdw::makeBufferReferenceDecl( m_pointer ) );
		}
	}

	template< typename BufferT >
	BufferT BufferReferenceT< BufferT >::operator()( std::string const & instanceName
		, UInt64 address )
	{
		return BufferT{ m_writer
			, instanceName
			, sdw::makeCast( getTypesCache( m_writer ).getPointerType( m_type, static_cast< ast::type::Pointer const & >( *m_pointer ).getStorage() )
				, makeExpr( address ) )
			, isEnabled() };
	}
}
