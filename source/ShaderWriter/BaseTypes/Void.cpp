/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Void.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Void::Void( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
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

	ast::type::TypePtr Void::makeType( ast::type::TypesCache & cache )
	{
		return cache.getVoid();
	}
}
