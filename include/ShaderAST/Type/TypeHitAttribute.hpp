/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeHitAttribute_H___
#define ___AST_TypeHitAttribute_H___
#pragma once

#include "Type.hpp"

#include <vector>

namespace ast::type
{
	class HitAttribute
		: public Type
	{
	public:
		SDAST_API explicit HitAttribute( TypePtr dataType );

		Kind getKind()const override
		{
			return m_dataType->getKind();
		}

		TypePtr getDataType()const
		{
			return m_dataType;
		}

	private:
		TypePtr m_dataType;
	};
	using HitAttributePtr = std::shared_ptr< HitAttribute >;
}

#endif
