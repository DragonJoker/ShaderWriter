/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Void.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Void::Void( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
		if ( shader )
		{
			shader->addStmt( makeSimple( makeExpr( *this ) ) );
		}
	}

	Void::Void( Void && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Void::Void( Void const & rhs )
		: Value{ rhs }
	{
	}

	Void::Void( Value const & rhs )
		: Value{ rhs }
	{
	}
}
