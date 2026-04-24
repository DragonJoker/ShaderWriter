/*
See LICENSE file in root folder
*/
#ifndef ___AST_BoInfo_H___
#define ___AST_BoInfo_H___
#pragma once

#include "ShaderAST/Type/TypeAccelerationStructure.hpp"
#include "ShaderAST/Type/TypeArray.hpp"
#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast
{
	using PcbInfo = type::InterfaceBlock;
	using UboInfo = DescriptorInfoT< type::UniformBuffer >;
	using SsboInfo = DescriptorInfoT< type::StorageBuffer >;
	using ShaderRecordInfo = DescriptorInfoT< type::BaseStruct >;

	struct AccStructInfo
		: DescriptorInfoT< type::AccelerationStructure >
	{
		AccStructInfo()
			: DescriptorInfoT{ nullptr, { ~0u, ~0u } }
		{
		}

		AccStructInfo( type::AccelerationStructurePtr ptype
			, uint32_t bind
			, uint32_t set )
			: DescriptorInfoT{ ptype, { bind, set } }
		{
		}

		bool isValid()const
		{
			return type != nullptr;
		}
	};
}

#endif
