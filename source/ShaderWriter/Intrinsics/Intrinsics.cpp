/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

#include "ShaderWriter/Helpers.hpp"

namespace sdw
{
	RetVoid controlBarrier( ShaderWriter & writer
		, type::Scope executionScope
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return RetVoid{ writer
			, expr::makeControlBarrier( findTypesCache( writer )
				, executionScope
				, memoryScope
				, semantics )
			, true };
	}

	RetVoid memoryBarrier( ShaderWriter & writer
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return RetVoid{ writer
			, expr::makeMemoryBarrier( findTypesCache( writer )
				, memoryScope
				, semantics )
			, true };
	}
}
