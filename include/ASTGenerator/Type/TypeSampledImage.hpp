/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeSampledImage_H___
#define ___AST_TypeSampledImage_H___
#pragma once

#include "TypeImage.hpp"
#include "TypeSampler.hpp"

#include <vector>

namespace ast::type
{
	class SampledImage
		: public Type
	{
	public:
		SampledImage( ImageConfiguration config
			, uint32_t arraySize = NotArray );

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

	private:
		ImagePtr m_imageType;
		SamplerPtr m_samplerType;
	};
	using SampledImagePtr = std::shared_ptr< SampledImage >;

	inline SampledImagePtr makeSampledImageType( ImageConfiguration config
		, uint32_t arraySize = NotArray )
	{
		return std::make_shared< SampledImage >( std::move( config )
			, arraySize );
	}
}

#endif
