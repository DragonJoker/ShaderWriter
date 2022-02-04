/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeSampledImage_H___
#define ___AST_TypeSampledImage_H___
#pragma once

#include "TypeImage.hpp"

#include <vector>

namespace ast::expr
{
	class SampledImageAccessCall;
}

namespace ast::type
{
	class SampledImage
		: public Type
	{
	public:
		SDAST_API SampledImage( TypesCache & cache
			, ImageConfiguration config
			, Trinary comparison = Trinary::eDontCare );

		ImagePtr getImageType()const
		{
			return m_imageType;
		}

		ImageConfiguration const & getConfig()const
		{
			return m_imageType->getConfig();
		}

		Trinary const & getDepth()const
		{
			return m_depth;
		}

	private:
		ImagePtr m_imageType;
		Trinary m_depth;

		friend class ast::expr::SampledImageAccessCall;
	};
	using SampledImagePtr = std::shared_ptr< SampledImage >;
}

#endif
