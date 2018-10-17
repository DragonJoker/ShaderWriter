/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T Pcb::declMember( std::string const & name )
	{
		registerName( m_shader, name, typeEnum< T > );
		m_info.registerMember( name, typeEnum< T > );
		auto var = var::makeVariable( type::makeType( typeEnum< T > ), name );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Pcb::declMember( std::string const & name
		, uint32_t dimension )
	{
		registerName( m_shader, name, typeEnum< T > );
		m_info.registerMember( name, typeEnum< T > );
		auto var = var::makeVariable( type::makeType( typeEnum< T >, dimension ), name );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Pcb::declMemberArray( std::string const & name )
	{
		registerName( m_shader, name, typeEnum< T > );
		m_info.registerMember( name, typeEnum< T > );
		auto var = var::makeVariable( type::makeType( typeEnum< T >, type::UnknownArraySize ), name );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Pcb::declMember( std::string const & name
		, bool enabled )
	{
		registerName( m_shader, name, typeEnum< T > );
		m_info.registerMember( name, typeEnum< T > );
		auto var = var::makeVariable( type::makeType( typeEnum< T > ), name );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Pcb::declMember( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		registerName( m_shader, name, typeEnum< T > );
		m_info.registerMember( name, typeEnum< T > );
		auto var = var::makeVariable( type::makeType( typeEnum< T >, dimension ), name );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Pcb::declMemberArray( std::string const & name
		, bool enabled )
	{
		registerName( m_shader, name, typeEnum< T > );
		m_info.registerMember( name, typeEnum< T > );
		auto var = var::makeVariable( type::makeType( typeEnum< T >, type::UnknownArraySize ), name );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline T Pcb::getMember( std::string const & name )
	{
		checkNameExists( m_shader, name, typeEnum< T > );
		return T{ &m_shader
			, makeExpr( var::makeVariable( type::makeType( typeEnum< T > ), name ) ) };
	}

	template< typename T >
	inline Array< T > Pcb::getMember( std::string const & name
		, uint32_t dimension )
	{
		checkNameExists( m_shader, name, typeEnum< T > );
		return Array< T >{ &m_shader
			, makeExpr( var::makeVariable( type::makeType( typeEnum< T >, dimension ), name ) ) };
	}

	template< typename T >
	inline Array< T > Pcb::getMemberArray( std::string const & name )
	{
		checkNameExists( m_shader, name, typeEnum< T > );
		return Array< T >{ &m_shader
			, makeExpr( var::makeVariable( type::makeType( typeEnum< T >, type::UnknownArraySize ), name ) ) };
	}

	template< typename T >
	inline Optional< T > Pcb::getMember( std::string const & name
		, bool enabled )
	{
		checkNameExists( m_shader, name, typeEnum< T > );
		return Optional< T >{ &m_shader
			, makeExpr( var::makeVariable( type::makeType( typeEnum< T > ), name ) )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Pcb::getMember( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		checkNameExists( m_shader, name, typeEnum< T > );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var::makeVariable( type::makeType( typeEnum< T >, dimension ), name ) )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Pcb::getMemberArray( std::string const & name
		, bool enabled )
	{
		checkNameExists( m_shader, name, typeEnum< T > );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var::makeVariable( type::makeType( typeEnum< T >, type::UnknownArraySize ), name ) )
			, enabled };
	}
}
