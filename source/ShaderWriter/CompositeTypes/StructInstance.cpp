/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	StructInstance::StructInstance( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
		, m_type{ std::static_pointer_cast< type::Struct >( getType() ) }
	{
	}
}
