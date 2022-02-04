/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeTexture_H___
#define ___AST_TypeTexture_H___
#pragma once

#include "TypeImage.hpp"
#include "TypeSampler.hpp"

#include <vector>

namespace ast::type
{
	class Texture
		: public Type
	{
	public:
		SDAST_API Texture( TypesCache & cache
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
	using TexturePtr = std::shared_ptr< Texture >;
}

#endif
