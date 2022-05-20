/*
See LICENSE file in root folder
*/
namespace sdw
{
	inline Ssbo::Ssbo( ShaderWriter & writer
		, std::string name
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled )
		: Ssbo( writer
		, std::move( name )
		, location.binding
		, location.set
		, layout
		, enabled )
	{
	}

	template< typename ValueT, typename ... ParamsT >
	inline ValueT Ssbo::declMember( std::string name
		, bool enabled
		, ParamsT ... params )
	{
		auto type = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer ), std::forward< ParamsT >( params )... ) );
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
	inline Array< ValueT > Ssbo::declMember( std::string name
		, uint32_t dimension
		, bool enabled
		, ParamsT ... params )
	{
		auto type = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer ), std::forward< ParamsT >( params )... )
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
	inline Array< ValueT > Ssbo::declMemberArray( std::string name
		, bool enabled
		, ParamsT ... params )
	{
		auto type = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer ), std::forward< ParamsT >( params )... )
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
	inline ValueT Ssbo::getMember( std::string_view name
		, bool enabled )
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return ValueT{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT >
	inline Array< ValueT > Ssbo::getMemberArray( std::string_view name
		, bool enabled )
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
