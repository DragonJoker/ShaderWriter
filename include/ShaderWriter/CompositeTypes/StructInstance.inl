/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T StructInstance::getMember( std::string const & name )
	{
		auto member = m_type->getMember( name );
		auto & shader = *findShader( *this );
		return T{ &shader
			, sdw::makeMbrSelect( makeExpr( shader, *this )
				, member.type->getIndex()
				, sdw::makeIdent( shader.getTypesCache()
					, var::makeVariable( member.type, member.name ) ) ) };
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( std::string const & name )
	{
		auto member = m_type->getMember( name );
		auto & shader = *findShader( *this );
		return Array< T >{ &shader
			, sdw::makeMbrSelect( makeExpr( shader, *this )
				, member.type->getIndex()
				, sdw::makeIdent( shader.getTypesCache()
					, var::makeVariable( member.type, member.name ) ) ) };
	}
}
