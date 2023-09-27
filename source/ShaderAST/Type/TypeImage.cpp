/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeImage.hpp"

namespace ast::type
{
	Image::Image( TypesCache & typesCache
		, ImageConfiguration config )
		: Type{ typesCache, Kind::eImage }
		, m_config{ std::move( config ) }
	{
	}
}
