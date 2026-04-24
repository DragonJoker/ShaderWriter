/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT >::ArrayStorageBufferT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_builder{ sdw::getBuilder( writer ) }
		, m_buffer{ static_cast< type::StorageBuffer * >( getNonArrayType( m_expr->getType() ) ) }
		, m_dataType{ getNonArrayType( m_buffer->getDataType()->getMember( 0u ).type ) }
		, m_var{ findIdentifier( *m_expr )->getVariable() }
	{
		assert( getArraySize( m_buffer->getDataType()->getMember( 0u ).type ) == ast::type::UnknownArraySize );
	}

	template< typename InstanceT >
	ReturnWrapperT< InstanceT > ArrayStorageBufferT< InstanceT >::operator[]( uint32_t index )const
	{
		auto & writer = findWriterMandat( *this );
		return ReturnWrapperT< InstanceT >{ writer
			, sdw::makeArrayAccess( m_dataType
				, sdw::makeMbrSelect( sdw::makeIdent( getExprCache( writer ), getTypesCache( writer ), m_var )
					, 0u
					, m_var->getFlags() )
				, makeExpr( writer, index ) )
			, isEnabled() };
	}

	template< typename InstanceT >
	ReturnWrapperT< InstanceT > ArrayStorageBufferT< InstanceT >::operator[]( UInt32 const & index )const
	{
		auto & writer = findWriterMandat( *this );
		return ReturnWrapperT< InstanceT >{ writer
			, sdw::makeArrayAccess( m_dataType
				, sdw::makeMbrSelect( sdw::makeIdent( getExprCache( writer ), getTypesCache( writer ), m_var )
					, 0u
					, m_var->getFlags() )
				, makeExpr( writer, index ) )
			, isEnabled() };
	}

	template< typename InstanceT >
	template< typename ... ParamsT >
	ast::type::StorageBufferPtr ArrayStorageBufferT< InstanceT >::makeType( ast::type::TypesCache & cache
		, std::string const & name
		, ast::type::MemoryLayout layout
		, ParamsT && ... params )
	{
		auto type = StorageBuffer::makeType( cache
			, name + "Type"
			, layout
			, true );
		if ( type->empty() )
			type->registerMember( "data"
				, InstanceT::makeType( cache, std::forward< ParamsT >( params )... )
				, type::UnknownArraySize );
		return type;
	}
}
