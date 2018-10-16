/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprMbrSelect.hpp>

namespace sdw
{
	template< typename T >
	inline void Struct::declMember( std::string const & name )
	{
		m_type->addMember( type::makeType( typeEnum< T > ), name );
	}

	template< typename T >
	inline void Struct::declMember( std::string const & name
		, uint32_t dimension )
	{
		m_type->addMember( type::makeType( typeEnum< T >, dimension ), name );
	}

	template< typename T >
	inline void Struct::declMemberArray( std::string const & name )
	{
		m_type->addMember( type::makeType( typeEnum< T >, type::UnknownArraySize ), name );
	}
}
