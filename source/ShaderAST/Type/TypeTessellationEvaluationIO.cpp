/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeTessellationEvaluationIO.hpp"

namespace ast::type
{
	//*************************************************************************

	TessellationInputPatch::TessellationInputPatch( TypePtr type
		, PatchDomain domain
		, uint32_t location )
		: Type{ type->getCache(), Kind::eTessellationInputPatch }
		, m_type{ type }
		, m_domain{ domain }
		, m_location{ location }
	{
	}

	//*************************************************************************

	TessellationEvaluationInput::TessellationEvaluationInput( TypePtr type
		, uint32_t inputVertices )
		: Type{ type->getCache(), Kind::eTessellationEvaluationInput }
		, m_type{ std::move( type ) }
		, m_inputVertices{ inputVertices }
	{
	}

	//*************************************************************************
}
