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
		Image( ImageConfiguration config );

		ImageConfiguration const & getConfig()const
		{
			return m_config;
		}

	private:
		ImageConfiguration m_config;
	};
	using ImagePtr = std::shared_ptr< Image >;

	inline ImagePtr makeImageType( ImageConfiguration config )
	{
		return std::make_shared< Image >( std::move( config ) );
	}
}

#endif
