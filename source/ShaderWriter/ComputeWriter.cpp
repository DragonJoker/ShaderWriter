/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ComputeWriter.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

namespace sdw
{
	UVec3 getWorkGroupSize( ast::type::TypePtr type )
	{
		assert( type->getKind() == ast::type::Kind::eComputeInput );
		auto & compType = static_cast< ast::type::ComputeInput const & >( *type );
		return uvec3( UInt{ compType.getLocalSizeX() }
			, UInt{ compType.getLocalSizeY() }
			, UInt{ compType.getLocalSizeZ() } );
	}

	ComputeWriter::ComputeWriter()
		: ShaderWriter{ ast::ShaderStage::eCompute }
	{
	}
}
