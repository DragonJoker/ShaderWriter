/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprMbrSelect.hpp>

namespace sdw
{
	template< typename T >
	inline T StructInstance::getMember( std::string const & name )
	{
		auto member = m_type->getMember( name );
		return T{ findShader( *this )
			, expr::makeMbrSelect( makeExpr( *this )
				, expr::makeIdentifier( var::makeVariable( member.type, member.name ) ) ) };
	}

	template< typename T >
	inline Array< T > StructInstance::getMember( std::string const & name, uint32_t dimension )
	{
		auto member = m_type->getMember( name );
		return Array< T >{ findShader( *this )
			, expr::makeMbrSelect( makeExpr( *this )
				, expr::makeIdentifier( var::makeVariable( member.type, member.name ) ) ) };
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( std::string const & name )
	{
		auto member = m_type->getMember( name );
		return Array< T >{ findShader( *this )
			, expr::makeMbrSelect( makeExpr( *this )
				, expr::makeIdentifier( var::makeVariable( member.type, member.name ) ) ) };
	}
}
