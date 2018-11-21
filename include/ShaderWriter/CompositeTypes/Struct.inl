/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline void Struct::declMember( std::string const & name )
	{
		m_type->declMember( name
			, type::makeType( typeEnum< T > ) );
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
