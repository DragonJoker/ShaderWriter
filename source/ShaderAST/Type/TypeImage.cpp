/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeImage.hpp"

namespace ast::type
{
	Image::Image( TypesCache * cache
		, ImageConfiguration config )
		: Type{ cache, Kind::eImage }
		, m_config{ std::move( config ) }
	{
	}
}
