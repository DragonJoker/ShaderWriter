/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeSampledImage_H___
#define ___AST_TypeSampledImage_H___
#pragma once

#include "TypeImage.hpp"

#include <optional>
#include <vector>

namespace ast::expr
{
	class CompositeConstruct;
}

namespace ast::type
{
	class SampledImage
		: public Type
	{
	public:
		SDAST_API SampledImage( TypesCache & typesCache
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

		Trinary getDepth()const
		{
			return m_depth;
		}

		void updateComparison( bool comparison )
		{
			if ( ( Trinary::eTrue == m_depth && !comparison )
				|| ( Trinary::eFalse == m_depth && comparison ) )
			{
				m_depth = Trinary::eDontCare;
			}
		}

	private:
		ImagePtr m_imageType;
		Trinary m_depth;
	};
	using SampledImagePtr = std::shared_ptr< SampledImage >;
}

#endif
