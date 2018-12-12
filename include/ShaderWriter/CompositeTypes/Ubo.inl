/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T Ubo::declMember( std::string const & name )
	{
		static_assert( !IsSameV< T, Bool >, "Bool is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported inside a UBO" );
		auto type = m_info.registerMember< typeEnum< T > >( name );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline Array< T > Ubo::declMember( std::string const & name
		, uint32_t dimension )
	{
		static_assert( !IsSameV< T, Bool >, "Bool is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported inside a UBO" );
		auto type = m_info.registerMember< typeEnum< T > >( name, dimension );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline Optional< T > Ubo::declMember( std::string const & name
		, bool enabled )
	{
		static_assert( !IsSameV< T, Bool >, "Bool is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported inside a UBO" );
		auto type = m_info.registerMember< typeEnum< T > >( name );
		auto var = registerMember( m_shader, m_var, name, type );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( m_shader, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Ubo::declMember( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		static_assert( !IsSameV< T, Bool >, "Bool is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported inside a UBO" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported inside a UBO" );
		auto type = m_info.registerMember< typeEnum< T > >( name, dimension );
		auto var = registerMember( m_shader, m_var, name, type );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( m_shader, var )
			, enabled };
	}

	template< typename T >
	inline T Ubo::getMember( std::string const & name )
	{
		auto var = getVar( m_shader, name );
		return T{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline Array< T > Ubo::getMemberArray( std::string const & name )
	{
		auto var = getVar( m_shader, name );
		return Array< T >{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline Optional< T > Ubo::getMember( std::string const & name
		, bool enabled )
	{
		auto var = getVar( m_shader, name );
		return Optional< T >{ &m_shader
			, makeExpr( m_shader, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Ubo::getMemberArray( std::string const & name
		, bool enabled )
	{
		auto var = getVar( m_shader, name );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( m_shader, var )
			, enabled };
	}
}
