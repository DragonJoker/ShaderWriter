/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeRayPayload_H___
#define ___AST_TypeRayPayload_H___
#pragma once

#include "Type.hpp"

#include <vector>

namespace ast::type
{
	class RayPayload
		: public Type
	{
	public:
		SDAST_API RayPayload( TypePtr dataType
			, uint32_t location );

		Kind getKind()const override
		{
			return m_dataType->getKind();
		}

		TypePtr getDataType()const
		{
			return m_dataType;
		}

		uint32_t getLocation()const
		{
			return m_location;
		}

	private:
		TypePtr m_dataType;
		uint32_t m_location;
	};
	using RayPayloadPtr = std::shared_ptr< RayPayload >;
}

#endif
