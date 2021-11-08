/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeTessellationEvaluationIO_H___
#define ___AST_TypeTessellationEvaluationIO_H___
#pragma once

#include "TypeTessellationControlIO.hpp"

namespace ast::type
{
	class TessellationInputPatch
		: public Type
	{
	public:
		SDAST_API TessellationInputPatch( TypePtr type
			, PatchDomain domain
			, uint32_t location );

		type::TypePtr getType()const
		{
			return m_type;
		}

		PatchDomain getDomain()const
		{
			return m_domain;
		}

		uint32_t getLocation()const
		{
			return m_location;
		}

	private:
		TypePtr m_type;
		PatchDomain m_domain;
		uint32_t m_location;
	};
	using TessellationInputPatchPtr = std::shared_ptr< TessellationInputPatch >;

	inline TessellationInputPatchPtr makeTessellationInputPatchType( TypePtr type
		, PatchDomain domain
		, uint32_t location )
	{
		return std::make_shared< TessellationInputPatch >( type
			, domain
			, location );
	}

	class TessellationEvaluationInput
		: public Type
	{
	public:
		SDAST_API TessellationEvaluationInput( TypePtr type
			, uint32_t inputVertices );

		type::TypePtr getType()const
		{
			return m_type;
		}

		uint32_t getInputVertices()const
		{
			return m_inputVertices;
		}

	private:
		TypePtr m_type;
		uint32_t m_inputVertices;
	};
	using TessellationEvaluationInputPtr = std::shared_ptr< TessellationEvaluationInput >;

	inline TessellationEvaluationInputPtr makeTessellationEvaluationInputType( TypePtr type
		, uint32_t inputVertices )
	{
		return std::make_shared< TessellationEvaluationInput >( type
			, inputVertices );
	}
}

#endif
