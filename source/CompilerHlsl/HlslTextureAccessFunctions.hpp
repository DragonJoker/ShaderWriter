/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslTextureAccessFunctions_H___
#define ___AST_HlslTextureAccessFunctions_H___
#pragma once

#include "HlslHelpers.hpp"

namespace hlsl
{
	namespace details
	{
		void writeProjectTexCoords2( ast::stmt::Container * container );
		void writeProjectTexCoords3( ast::stmt::Container * container );
		void writeProjectTexCoords4To1( ast::stmt::Container * container );
		void writeProjectTexCoords4To2( ast::stmt::Container * container );
		void writeProjectTexCoords4( ast::stmt::Container * container );
	}

	void compileHlslTextureAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config );
}

#endif
