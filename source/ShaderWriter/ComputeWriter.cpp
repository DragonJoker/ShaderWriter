/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ComputeWriter.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

namespace sdw
{
	//*********************************************************************************************

	U32Vec3 getWorkGroupSize( ast::type::TypePtr type )
	{
		assert( type->getKind() == ast::type::Kind::eComputeInput );
		auto & compType = static_cast< ast::type::ComputeInput const & >( *type );
		return uvec3( UInt32{ compType.getLocalSizeX() }
			, UInt32{ compType.getLocalSizeY() }
			, UInt32{ compType.getLocalSizeZ() } );
	}

	//*********************************************************************************************

	ComputeWriter::ComputeWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eCompute, allocator }
	{
	}

	ComputeWriter::ComputeWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eCompute, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eCompute )
		{
			throw ast::Exception{ "Can't create a ComputeWriter from this kind of builder." };
		}
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
		implementMainT( localSizeX, localSizeY, function );
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, ComputeMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, localSizeY, localSizeZ, function );
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
		implementMainT( localSizeX, localSizeY, function );
	}

	void ComputeWriter::implementMain( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, SubgroupMainFuncT< VoidT > const & function )
	{
		implementMainT( localSizeX, localSizeY, localSizeZ, function );
	}

	//*********************************************************************************************
}
