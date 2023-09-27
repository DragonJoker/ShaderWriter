/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeCombinedImage_H___
#define ___AST_TypeCombinedImage_H___
#pragma once

#include "TypeImage.hpp"
#include "TypeSampler.hpp"

#include <vector>

namespace ast::type
{
	class CombinedImage
		: public Type
	{
	public:
		SDAST_API CombinedImage( TypesCache & typesCache
			, ImageConfiguration config
			, bool isComparison );

		ImagePtr getImageType()const
		{
			return m_imageType;
		}

		SamplerPtr getSamplerType()const
		{
			return m_samplerType;
		}

		ImageConfiguration getConfig()const
		{
			return m_imageType->getConfig();
		}

		bool isComparison()const
		{
			return m_samplerType->isComparison();
		}

	private:
		ImagePtr m_imageType;
		SamplerPtr m_samplerType;
	};
	using CombinedImagePtr = std::shared_ptr< CombinedImage >;
}

#endif
