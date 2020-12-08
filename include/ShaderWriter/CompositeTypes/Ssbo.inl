/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	T Ssbo::declStructMember( std::string const & name )
	{
		auto type = m_interface.registerMember( name
			, T::makeType( getTypesCache( m_writer ) ) );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::declStructMember( std::string const & name
		, uint32_t dimension )
	{
		auto type = m_interface.registerMember( name
			, T::makeType( getTypesCache( m_writer ) )
			, dimension );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline T Ssbo::declMember( std::string const & name )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::declMember( std::string const & name
		, uint32_t dimension )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name, dimension );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::declMemberArray( std::string const & name )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name, type::UnknownArraySize );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline T Ssbo::getMember( std::string const & name )
	{
		auto var = getVar( m_writer, name );
		return T{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::getMemberArray( std::string const & name )
	{
		auto var = getVar( m_writer, name );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var ) };
	}
}
