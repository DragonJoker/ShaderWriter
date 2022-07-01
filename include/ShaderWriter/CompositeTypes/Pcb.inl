/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT, typename ... ParamsT >
	inline ValueT Pcb::declMember( std::string name
		, bool enabled
		, ParamsT ... params )
	{
		auto type = m_info.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer )
				, std::forward< ParamsT >( params )... ) );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return ValueT{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > Pcb::declMember( std::string name
		, uint32_t dimension
		, bool enabled
		, ParamsT ... params )
	{
		auto type = m_info.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer )
				, std::forward< ParamsT >( params )... )
			, dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > Pcb::declMemberArray( std::string name
		, bool enabled
		, ParamsT ... params )
	{
		auto type = m_info.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer )
				, std::forward< ParamsT >( params )... )
			, type::UnknownArraySize );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT >
	inline ValueT Pcb::getMember( std::string_view name
		, bool enabled )const
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return ValueT{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT >
	inline Array< ValueT > Pcb::getMemberArray( std::string_view name
		, bool enabled )const
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
