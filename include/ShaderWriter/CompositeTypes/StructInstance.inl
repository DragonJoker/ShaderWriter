/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T StructInstance::getMember( std::string const & name )const
	{
		auto member = m_type->getMember( name );
		auto & writer = *findWriter( *this );
		return T{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, 0u )
			, true};
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( std::string const & name )const
	{
		auto member = m_type->getMember( name );
		auto & writer = *findWriter( *this );
		return Array< T >{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, 0u )
			, true };
	}
}
