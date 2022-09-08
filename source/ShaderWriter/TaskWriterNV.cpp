/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TaskWriterNV.hpp"

namespace sdw
{
	TaskWriterNV::TaskWriterNV()
		: ShaderWriter{ ast::ShaderStage::eTaskNV }
	{
	}

	void TaskWriterNV::implementMain( uint32_t localSizeX
		, TaskNVMainFunc const & function )
	{
		implementMainT< VoidT >( localSizeX
			, TaskPayloadOutNV{ *this }
			, function );
	}

	void TaskWriterNV::implementMain( uint32_t localSizeX
		, TaskNVSubgroupMainFunc const & function )
	{
		implementMainT< VoidT >( localSizeX
			, TaskPayloadOutNV{ *this }
			, function );
	}

	//*************************************************************************
}
