/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	T Ubo::declStructMember( std::string const & name )
	{
		auto type = m_interface.registerMember( name
			, T::makeType( getTypesCache( m_writer ) ) );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Array< T > Ubo::declStructMember( std::string const & name
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
	inline T Ubo::declMember( std::string const & name )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Array< T > Ubo::declMember( std::string const & name
		, uint32_t dimension )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name, dimension );
		auto var = registerMember( m_writer, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Optional< T > Ubo::declMember( std::string const & name
		, bool enabled )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name );
		auto var = registerMember( m_writer, m_var, name, type );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< T >{ m_writer
			, makeExpr( m_writer, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Ubo::declMember( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name, dimension );
		auto var = registerMember( m_writer, m_var, name, type );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >{ m_writer
			, makeExpr( m_writer, var )
			, enabled };
	}

	template< typename T >
	inline T Ubo::getMember( std::string const & name )
	{
		auto var = getVar( m_writer, name );
		return T{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Array< T > Ubo::getMemberArray( std::string const & name )
	{
		auto var = getVar( m_writer, name );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var ) };
	}

	template< typename T >
	inline Optional< T > Ubo::getMember( std::string const & name
		, bool enabled )
	{
		auto var = getVar( m_writer, name );
		return Optional< T >{ m_writer
			, makeExpr( m_writer, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Ubo::getMemberArray( std::string const & name
		, bool enabled )
	{
		auto var = getVar( m_writer, name );
		return Optional< Array< T > >{ m_writer
			, makeExpr( m_writer, var )
			, enabled };
	}
}
