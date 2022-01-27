/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T Pcb::declMember( std::string name
		, bool enabled )
	{
		auto type = m_info.registerMember( name
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
	inline Array< T > Pcb::declMember( std::string name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = m_info.registerMember( name
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
	inline Array< T > Pcb::declMemberArray( std::string name
		, bool enabled )
	{
		auto type = m_info.registerMember< typeEnum< T > >( name, type::UnknownArraySize );
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
	inline T Pcb::getMember( std::string_view name
		, bool enabled )
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return T{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline Array< T > Pcb::getMemberArray( std::string_view name
		, bool enabled )
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
