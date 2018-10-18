/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T Ssbo::declMember( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::declMember( std::string const & name
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
	inline Array< T > Ssbo::declMemberArray( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T >, type::UnknownArraySize );
		auto var = registerName( m_shader, name, type );
		m_info.registerMember( name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Ssbo::declMember( std::string const & name
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
	inline Optional< Array< T > > Ssbo::declMember( std::string const & name
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
	inline Optional< Array< T > > Ssbo::declMemberArray( std::string const & name
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
	inline T Ssbo::getMember( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = getVar( m_shader, name, type );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::getMember( std::string const & name
		, uint32_t dimension )
	{
		auto type = type::makeType( typeEnum< T >, dimension );
		auto var = getVar( m_shader, name, type );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::getMemberArray( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T >, type::UnknownArraySize );
		auto var = getVar( m_shader, name, type );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Ssbo::getMember( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = getVar( m_shader, name, type );
		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Ssbo::getMember( std::string const & name
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
	inline Optional< Array< T > > Ssbo::getMemberArray( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >, type::UnknownArraySize );
		auto var = getVar( m_shader, name, type );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
}
