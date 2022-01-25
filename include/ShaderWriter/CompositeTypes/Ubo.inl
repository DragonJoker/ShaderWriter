/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	T Ubo::declStructMember( std::string name
		, bool enabled )
	{
		auto type = m_interface.registerMember( name
			, T::makeType( getTypesCache( m_writer ) ) );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return T{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline Array< T > Ubo::declStructMember( std::string name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = m_interface.registerMember( name
			, T::makeType( getTypesCache( m_writer ) )
			, dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Array< T >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline T Ubo::declMember( std::string name
		, bool enabled )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return T{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline Array< T > Ubo::declMember( std::string name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name, dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Array< T >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline T Ubo::getMember( std::string_view name
		, bool enabled )
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return T{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline Array< T > Ubo::getMemberArray( std::string_view name
		, bool enabled )
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
