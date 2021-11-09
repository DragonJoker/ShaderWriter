/*
See LICENSE file in root folder
*/
#include "ShaderWriter/FragmentWriter.hpp"

namespace sdw
{
	FragmentWriter::FragmentWriter()
		: ShaderWriter{ ast::ShaderStage::eFragment }
	{
	}

	void FragmentWriter::implementMain( FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementMainT( function );
	}

	void FragmentWriter::implementMain( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< VoidT, VoidT > const & function )
	{
		implementMainT( origin, center, function );
	}
}
