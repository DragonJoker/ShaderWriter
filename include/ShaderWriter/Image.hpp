/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Image_H___
#define ___SDW_Image_H___

#include "Value.hpp"

namespace sdw
{
	template< ImageType ST >
	struct ImageT
		: public Value
	{
		inline ImageT( Shader * shader
			, expr::ExprPtr expr );
		template< typename T > inline ImageT & operator=( T const & rhs );
		inline operator uint32_t();
	};
}

#include "Image.inl"

#endif
