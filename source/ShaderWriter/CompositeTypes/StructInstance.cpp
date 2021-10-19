/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	StructInstance::StructInstance( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_type{ getStructType( getType() ) }
	{
	}
}
