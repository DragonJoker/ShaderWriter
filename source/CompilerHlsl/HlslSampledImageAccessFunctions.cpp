/*
See LICENSE file in root folder
*/
#include "HlslSampledImageAccessFunctions.hpp"
#include "HlslTextureAccessFunctions.hpp"

namespace hlsl
{
	void compileHlslSampledImageAccessAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
		if ( config.requiresProjectTexCoords2 )
		{
			details::writeProjectTexCoords2( container );
		}
		if ( config.requiresProjectTexCoords3 )
		{
			details::writeProjectTexCoords3( container );
		}
		if ( config.requiresProjectTexCoords4To1 )
		{
			details::writeProjectTexCoords4To1( container );
		}
		if ( config.requiresProjectTexCoords4To2 )
		{
			details::writeProjectTexCoords4To2( container );
		}
		if ( config.requiresProjectTexCoords4 )
		{
			details::writeProjectTexCoords4( container );
		}
	}
}
