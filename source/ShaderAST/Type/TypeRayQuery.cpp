/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeRayQuery.hpp"

namespace ast::type
{
	uint32_t operator|( RayFlag lhs, RayFlag rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	uint32_t operator|( uint32_t lhs, RayFlag rhs )
	{
		return lhs | uint32_t( rhs );
	}

	uint32_t operator|( RayFlag lhs, uint32_t rhs )
	{
		return uint32_t( lhs ) | rhs;
	}

	RayFlag operator&( uint32_t lhs, RayFlag rhs )
	{
		return RayFlag( lhs & uint32_t( rhs ) );
	}

	RayQuery::RayQuery( TypesCache & typesCache
			, uint32_t baseFlags )
		: Type{ typesCache, Kind::eRayQuery, false }
		, m_baseFlags{ baseFlags }
	{
	}
}
