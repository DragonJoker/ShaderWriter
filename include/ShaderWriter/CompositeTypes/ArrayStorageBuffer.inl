/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

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
				, sdw::makeMbrSelect( makeExpr( *this ), 0u, m_var->getFlags() )
				, makeExpr( writer, index ) )
			, isEnabled() };
	}

	template< typename InstanceT >
	ReturnWrapperT< InstanceT > ArrayStorageBufferT< InstanceT >::operator[]( UInt32 const & index )const
	{
		auto & writer = findWriterMandat( *this );
		return ReturnWrapperT< InstanceT >{ writer
			, sdw::makeArrayAccess( m_dataType
				, sdw::makeMbrSelect( makeExpr( *this ), 0u, m_var->getFlags() )
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
		auto type = makeStorageBufferType( cache
			, name + "Type"
			, layout
			, true );
		if ( type->empty() )
			type->registerMember( "data"
				, InstanceT::makeType( cache, std::forward< ParamsT >( params )... )
				, type::UnknownArraySize );
		return type;
	}

	//*********************************************************************************************

	template< typename InstanceT >
	expr::ExprPtr makeExpr( ArrayStorageBufferT< InstanceT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************

	template< typename InstanceT >
	Array< ArrayStorageBufferT< InstanceT > >::Array( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< typename InstanceT >
	template< ast::type::Kind KindT >
	ArrayStorageBufferT< InstanceT > Array< ArrayStorageBufferT< InstanceT > >::operator[]( IntegerValue< KindT > const & offset )const
	{
		ShaderWriter & writer = sdw::findWriterMandat( *this, offset );
		return ValueT{ writer
			, sdw::makeArrayAccess( ast::type::getNonArrayType( this->getType() )
				, sdw::makeExpr( writer, *this )
				, sdw::makeExpr( writer, offset ) )
			, sdw::areOptionalEnabled( *this, offset ) };
	}

	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT > Array< ArrayStorageBufferT< InstanceT > >::operator[]( int32_t offset )const
	{
		ShaderWriter & writer = sdw::findWriterMandat( *this, offset );
		return ValueT{ writer
			, sdw::makeArrayAccess( ast::type::getNonArrayType( this->getType() )
				, sdw::makeExpr( writer, *this )
				, sdw::makeExpr( writer, offset ) )
			, sdw::areOptionalEnabled( *this, offset ) };
	}

	template< typename InstanceT >
	ArrayStorageBufferT< InstanceT > Array< ArrayStorageBufferT< InstanceT > >::operator[]( uint32_t offset )const
	{
		ShaderWriter & writer = sdw::findWriterMandat( *this, offset );
		return ValueT{ writer
			, sdw::makeArrayAccess( ast::type::getNonArrayType( this->getType() )
				, sdw::makeExpr( writer, *this )
				, sdw::makeExpr( writer, offset ) )
			, sdw::areOptionalEnabled( *this, offset ) };
	}

	//*********************************************************************************************
}
