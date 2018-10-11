#include <ASTGenerator/Var/Variable.hpp>

namespace sdw
{
	template< typename T >
	inline T Ssbo::declMember( std::string const & name )
	{
		using type = typename TypeOf< T >::Type;
		registerName( m_container, name, TypeTraits< T >::TypeEnum );
		m_info.registerMember( name, TypeTraits< T >::TypeEnum );
		auto var = var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum ), name );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return T( &m_container
			, var );
	}

	template< typename T >
	inline Array< T > Ssbo::declMember( std::string const & name
		, uint32_t dimension )
	{
		using type = typename TypeOf< T >::Type;
		registerName( m_container, name, TypeTraits< T >::TypeEnum );
		m_info.registerMember( name, TypeTraits< T >::TypeEnum );
		auto var = var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, dimension ), name );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >( &m_container
			, var );
	}

	template< typename T >
	inline Array< T > Ssbo::declMemberArray( std::string const & name )
	{
		using type = typename TypeOf< T >::Type;
		registerName( m_container, name, TypeTraits< T >::TypeEnum );
		m_info.registerMember( name, TypeTraits< T >::TypeEnum );
		auto var = var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, type::UnknownArraySize ), name );
		m_stmt->add( stmt::makeVariableDecl( var ) );
		return Array< T >( &m_container
			, var );
	}

	template< typename T >
	inline Optional< T > Ssbo::declMember( std::string const & name
		, bool enabled )
	{
		using type = typename TypeOf< T >::Type;
		registerName( m_container, name, TypeTraits< T >::TypeEnum );
		m_info.registerMember( name, TypeTraits< T >::TypeEnum );
		auto var = var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum ), name );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< T >( &m_container
			, var
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > Ssbo::declMember( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		using type = typename TypeOf< T >::Type;
		registerName( m_container, name, TypeTraits< T >::TypeEnum );
		m_info.registerMember( name, TypeTraits< T >::TypeEnum );
		auto var = var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, dimension ), name );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >( &m_container
			, var
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > Ssbo::declMemberArray( std::string const & name
		, bool enabled )
	{
		using type = typename TypeOf< T >::Type;
		registerName( m_container, name, TypeTraits< T >::TypeEnum );
		m_info.registerMember( name, TypeTraits< T >::TypeEnum );
		auto var = var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, type::UnknownArraySize ), name );

		if ( enabled )
		{
			m_stmt->add( stmt::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >( &m_container
			, var
			, enabled );
	}

	template< typename T >
	inline T Ssbo::getMember( std::string const & name )
	{
		checkNameExists( m_container, name, TypeTraits< T >::TypeEnum );
		return T( &m_container
			, var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum ), name ) );
	}

	template< typename T >
	inline Array< T > Ssbo::getMember( std::string const & name
		, uint32_t dimension )
	{
		checkNameExists( m_container, name, TypeTraits< T >::TypeEnum );
		return Array< T >( &m_container
			, var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, dimension ), name ) );
	}

	template< typename T >
	inline Array< T > Ssbo::getMemberArray( std::string const & name )
	{
		checkNameExists( m_container, name, TypeTraits< T >::TypeEnum );
		return Array< T >( &m_container
			, var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, type::UnknownArraySize ), name ) );
	}

	template< typename T >
	inline Optional< T > Ssbo::getMember( std::string const & name
		, bool enabled )
	{
		checkNameExists( m_container, name, TypeTraits< T >::TypeEnum );
		return Optional< T >( &m_container
			, var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum ), name )
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > Ssbo::getMember( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		checkNameExists( m_container, name, TypeTraits< T >::TypeEnum );
		return Optional< Array< T > >( &m_container
			, var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, dimension ), name )
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > Ssbo::getMemberArray( std::string const & name
		, bool enabled )
	{
		checkNameExists( m_container, name, TypeTraits< T >::TypeEnum );
		return Optional< Array< T > >( &m_container
			, var::makeVariable( type::makeType( TypeTraits< T >::TypeEnum, type::UnknownArraySize ), name )
			, enabled );
	}
}
