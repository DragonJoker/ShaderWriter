/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprMbrSelect.hpp>

namespace sdw
{
	template< typename T >
	inline void Struct::declMember( std::string const & name )
	{
		m_type->addMember( type::makeType( TypeTraits< T >::TypeEnum ), name );
	}

	template< typename T >
	inline void Struct::declMember( std::string const & name
		, uint32_t dimension )
	{
		m_type->addMember( type::makeType( TypeTraits< T >::TypeEnum, dimension ), name );
	}

	template< typename T >
	inline void Struct::declMemberArray( std::string const & name )
	{
		m_type->addMember( type::makeType( TypeTraits< T >::TypeEnum, type::UnknownArraySize ), name );
	}

	template< typename T >
	inline T Struct::getMember( std::string const & name )
	{
		auto member = m_type->getMember( name );
		return T{ &m_container
			, expr::makeMbrSelect( make( m_expr )
				, expr::makeIdentifier( var::makeVariable( member.type, member.name ) ) ) };
	}

	template< typename T >
	inline Array< T > Struct::getMember( std::string const & name, uint32_t dimension )
	{
		auto member = m_type->getMember( name );
		return Array< T >{ &m_container
			, expr::makeMbrSelect( make( m_expr )
				, expr::makeIdentifier( var::makeVariable( member.type, member.name ) ) ) };
	}

	template< typename T >
	inline Array< T > Struct::getMemberArray( std::string const & name )
	{
		auto member = m_type->getMember( name );
		return Array< T >{ &m_container
			, expr::makeMbrSelect( make( m_expr )
				, expr::makeIdentifier( var::makeVariable( member.type, member.name ) ) ) };
	}
}
