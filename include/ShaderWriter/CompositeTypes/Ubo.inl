/*
See LICENSE file in root folder
*/
namespace sdw
{
	inline Ubo::Ubo( ShaderWriter & writer
		, std::string name
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled )
		: Ubo{ writer
		, std::move( name )
		, location.binding
		, location.set
		, layout
		, enabled }
	{
	}

	template< typename T >
	inline T Ubo::declMember( std::string name
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
	inline Array< T > Ubo::declMember( std::string name
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
	inline Array< T > Ubo::declMemberArray( std::string name
		, bool enabled )
	{
		auto type = m_interface.registerMember< typeEnum< T > >( name, type::UnknownArraySize );
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
