/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayDesc_H___
#define ___SDW_RayDesc_H___
#pragma once

#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"
#include "ShaderWriter/VecTypes/Vec3.hpp"

#include <functional>

namespace sdw
{
	struct RayDesc
		: public StructInstance
	{
	public:
		SDW_DeclStructInstance( SDW_API, RayDesc );

		SDW_API RayDesc( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		SDW_API static sdw::type::RayDescPtr makeType( sdw::type::TypesCache & cache );

		sdw::Vec3 origin;
		sdw::Float tMin;
		sdw::Vec3 direction;
		sdw::Float tMax;
	};
}

#endif
