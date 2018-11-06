/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeImage_H___
#define ___AST_TypeImage_H___
#pragma once

#include "Type.hpp"
#include "ImageConfiguration.hpp"

#include <vector>

namespace ast::type
{
	class Image
		: public Type
	{
	public:
		Image( ImageConfiguration config
			, uint32_t arraySize = NotArray );

		ImageConfiguration const & getConfig()const
		{
			return m_config;
		}

	private:
		ImageConfiguration m_config;
	};
	using ImagePtr = std::shared_ptr< Image >;

	inline ImagePtr makeImageType( ImageConfiguration config
		, uint32_t arraySize = NotArray )
	{
		return std::make_shared< Image >( std::move( config )
			, arraySize );
	}
}

#endif
