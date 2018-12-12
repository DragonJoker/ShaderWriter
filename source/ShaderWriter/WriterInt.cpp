/*
See LICENSE file in root folder
*/
#include "WriterInt.hpp"

namespace sdw
{
	ShaderWriter *& doGetCurrentWriter()
	{
		static ShaderWriter * current = nullptr;
		return current;
	}
}
