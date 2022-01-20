/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/RayDesc.hpp"

namespace sdw
{
	RayDesc::RayDesc( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: sdw::StructInstance{ writer, std::move( expr ), enabled }
		, origin{ getMember< Vec3 >( "Origin" ) }
		, tMin{ getMember< Float >( "TMin" ) }
		, direction{ getMember< Vec3 >( "Direction" ) }
		, tMax{ getMember< Float >( "TMax" ) }
	{
	}

	type::RayDescPtr RayDesc::makeType( type::TypesCache & cache )
	{
		return cache.getRayDesc();
	}
}
