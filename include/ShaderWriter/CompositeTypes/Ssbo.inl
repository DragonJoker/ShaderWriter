/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T Ssbo::declMember( std::string const & name )
	{
		static_assert( !IsSameV< T, Bool >, "Bool is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported inside a SSBO" );
		auto type = m_info.registerMember< typeEnum< T > >( name );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::declMember( std::string const & name
		, uint32_t dimension )
	{
		static_assert( !IsSameV< T, Bool >, "Bool is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported inside a SSBO" );
		auto type = m_info.registerMember< typeEnum< T > >( name, dimension );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::declMemberArray( std::string const & name )
	{
		static_assert( !IsSameV< T, Bool >, "Bool is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported inside a SSBO" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported inside a SSBO" );
		auto type = m_info.registerMember< typeEnum< T > >( name, type::UnknownArraySize );
		auto var = registerMember( m_shader, m_var, name, type );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline T Ssbo::getMember( std::string const & name )
	{
		auto var = getVar( m_shader, name );
		return T{ &m_shader
			, makeExpr( m_shader, var ) };
	}

	template< typename T >
	inline Array< T > Ssbo::getMemberArray( std::string const & name )
	{
		auto var = getVar( m_shader, name );
		return Array< T >{ &m_shader
			, makeExpr( m_shader, var ) };
	}
}
