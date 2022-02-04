/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeSampledImage_H___
#define ___AST_TypeSampledImage_H___
#pragma once

#include "TypeImage.hpp"

#include <vector>

namespace ast::type
{
	class SampledImage
		: public Type
	{
	public:
		SDAST_API SampledImage( TypesCache & cache
			, ImageConfiguration config );

		ImagePtr getImageType()const
		{
			return m_imageType;
		}

		ImageConfiguration const & getConfig()const
		{
			return m_imageType->getConfig();
		}

	private:
		ImagePtr m_imageType;
	};
	using SampledImagePtr = std::shared_ptr< SampledImage >;
}

#endif
