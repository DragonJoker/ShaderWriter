/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/TypeImage.hpp"

namespace ast::type
{
	Image::Image( ImageConfiguration config
		, uint32_t arraySize )
		: Type{ Kind::eImage, arraySize }
		, m_config{ std::move( config ) }
	{
	}
}
