/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline void Struct::declMember( std::string const & name )
	{
		m_type->declMember( name, typeEnum< T > );
	}

	template< typename T >
	inline void Struct::declMember( std::string const & name
		, uint32_t dimension )
	{
		m_type->declMember( name, typeEnum< T >, dimension );
	}

	template< typename T >
	inline void Struct::declMemberArray( std::string const & name )
	{
		m_type->declMember( name, typeEnum< T >, type::UnknownArraySize );
	}
}
