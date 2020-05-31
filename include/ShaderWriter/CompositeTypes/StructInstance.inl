/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T StructInstance::getMember( std::string const & name )const
	{
		auto member = m_type->getMember( name );
		auto & shader = *findShader( *this );
		return T{ &shader
			, sdw::makeMbrSelect( makeExpr( shader, *this )
				, member.type->getIndex()
				, 0u ) };
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( std::string const & name )const
	{
		auto member = m_type->getMember( name );
		auto & shader = *findShader( *this );
		return Array< T >{ &shader
			, sdw::makeMbrSelect( makeExpr( shader, *this )
				, member.type->getIndex()
				, 0u ) };
	}
}
