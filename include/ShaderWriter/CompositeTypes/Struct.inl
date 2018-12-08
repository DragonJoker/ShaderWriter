/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename InstanceT >
	InstanceT Struct::getInstance( std::string const & name )const
	{
		auto var = m_shader->registerBlockVariable( name, m_type );
		addStmt( *m_shader, sdw::makeVariableDecl( var ) );
		return InstanceT{ m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline void Struct::declMember( std::string const & name )
	{
		m_type->declMember( name
			, T::makeType( getType()->getCache() ) );
	}

	template< typename T >
	inline void Struct::declMember( std::string const & name
		, uint32_t dimension )
	{
		m_type->declMember( name
			, typeEnum< T >
			, dimension );
	}
}
