/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T Pcb::declMember( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Pcb::declMember( std::string const & name
		, uint32_t dimension )
	{
		auto type = type::makeType( typeEnum< T >, dimension );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Pcb::declMemberArray( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T >, type::UnknownArraySize );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Pcb::declMember( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );

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
		auto type = type::makeType( typeEnum< T >, dimension );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );

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
		auto type = type::makeType( typeEnum< T >, type::UnknownArraySize );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );

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
		auto type = type::makeType( typeEnum< T > );
		auto var = getVar( m_shader, name, type );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Pcb::getMember( std::string const & name
		, uint32_t dimension )
	{
		auto type = type::makeType( typeEnum< T >, dimension );
		auto var = getVar( m_shader, name, type );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Pcb::getMemberArray( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T >, type::UnknownArraySize );
		auto var = getVar( m_shader, name, type );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Pcb::getMember( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = getVar( m_shader, name, type );
		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Pcb::getMember( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >, dimension );
		auto var = getVar( m_shader, name, type );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Pcb::getMemberArray( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >, type::UnknownArraySize );
		auto var = getVar( m_shader, name, type );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
}
