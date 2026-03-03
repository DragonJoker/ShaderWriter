/*
See LICENSE file in root folder
*/
#include "WriterInt.hpp"

namespace sdw
{
	ShaderWriter *& doGetCurrentWriter()noexcept
	{
		thread_local ShaderWriter * current = nullptr;
		return current;
	}
}
