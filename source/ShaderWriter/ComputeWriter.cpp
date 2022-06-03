/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ComputeWriter.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

namespace sdw
{
	//*********************************************************************************************

	UVec3 getWorkGroupSize( ast::type::TypePtr type )
	{
		assert( type->getKind() == ast::type::Kind::eComputeInput );
		auto & compType = static_cast< ast::type::ComputeInput const & >( *type );
		return uvec3( UInt{ compType.getLocalSizeX() }
			, UInt{ compType.getLocalSizeY() }
			, UInt{ compType.getLocalSizeZ() } );
	}

	//*********************************************************************************************

	ComputeWriter::ComputeWriter()
		: ShaderWriter{ ast::ShaderStage::eCompute }
	{
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, ComputeMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, function );
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, uint32_t localSizeY
		, ComputeMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, localSizeX, function );
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, ComputeMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, localSizeX, localSizeZ, function );
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, SubgroupMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, function );
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, uint32_t localSizeY
		, SubgroupMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, localSizeX, function );
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, SubgroupMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, localSizeX, localSizeZ, function );
	}

	//*********************************************************************************************
}
