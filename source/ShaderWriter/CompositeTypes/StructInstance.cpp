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

	StructInstance & StructInstance::operator=( StructInstance const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}
}
