/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename InstanceT >
	InstanceT Struct::getInstance( std::string const & name )const
	{
		auto var = registerBlockVariable( *m_shader, name, m_type );
		addStmt( *m_shader, sdw::makeVariableDecl( var ) );
		return InstanceT{ m_shader
			, makeExpr( *m_shader, var ) };
	}

	template< typename T >
	inline void Struct::declMember( std::string const & name )
	{
		static_assert( typeEnum< T > != type::Kind::eBoolean, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec2B, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec3B, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec4B, "Can't put a boolean type inside a structure" );
		m_type->declMember( name
			, T::makeType( getTypesCache( *m_shader ) ) );
	}

	template< typename T >
	inline void Struct::declMember( std::string const & name
		, uint32_t dimension )
	{
		static_assert( typeEnum< T > != type::Kind::eBoolean, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec2B, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec3B, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec4B, "Can't put a boolean type inside a structure" );
		m_type->declMember( name
			, typeEnum< T >
			, dimension );
	}
}
