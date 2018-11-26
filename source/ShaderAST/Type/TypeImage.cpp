/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeImage.hpp"

namespace ast::type
{
	Image::Image( ImageConfiguration config )
		: Type{ Kind::eImage }
		, m_config{ std::move( config ) }
	{
	}
}
