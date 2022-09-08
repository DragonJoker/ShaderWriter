/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_ShaderStageFlag_H___
#define ___SDWVK_ShaderStageFlag_H___

#include "VulkanLayer.hpp"

#include <ShaderAST/ShaderASTPrerequisites.hpp>

namespace ast::vk
{
	enum class ShaderStageFlag
		: uint32_t
	{
		eNone = 0x00u,
		eVertex = 0x01u << int( ShaderStage::eVertex ),
		eTessellationControl = 0x01u << int( ShaderStage::eTessellationControl ),
		eTessellationEvaluation = 0x01u << int( ShaderStage::eTessellationEvaluation ),
		eGeometry = 0x01u << int( ShaderStage::eGeometry ),
		eFragment = 0x01u << int( ShaderStage::eFragment ),
		eCompute = 0x01u << int( ShaderStage::eCompute ),
		eTaskNV = 0x01u << int( ShaderStage::eTaskNV ),
		eMeshNV = 0x01u << int( ShaderStage::eMeshNV ),
		eTask = 0x01u << int( ShaderStage::eTask ),
		eMesh = 0x01u << int( ShaderStage::eMesh ),
		eRayGeneration = 0x01u << int( ShaderStage::eRayGeneration ),
		eRayAnyHit = 0x01u << int( ShaderStage::eRayAnyHit ),
		eRayClosestHit = 0x01u << int( ShaderStage::eRayClosestHit ),
		eRayMiss = 0x01u << int( ShaderStage::eRayMiss ),
		eRayIntersection = 0x01u << int( ShaderStage::eRayIntersection ),
		eCallable = 0x01u << int( ShaderStage::eCallable ),
	};

	using ShaderStageFlags = uint32_t;

	inline ShaderStageFlags operator|( ShaderStageFlags lhs, ShaderStageFlag rhs )
	{
		return lhs | ShaderStageFlags( rhs );
	}

	inline ShaderStageFlags operator|( ShaderStageFlag lhs, ShaderStageFlags rhs )
	{
		return ShaderStageFlags( lhs ) | rhs;
	}

	inline ShaderStageFlags operator|( ShaderStageFlag lhs, ShaderStageFlag rhs )
	{
		return ShaderStageFlags( lhs ) | ShaderStageFlags( rhs );
	}

	inline ShaderStageFlags makeFlag( ShaderStage stage )
	{
		return ShaderStageFlags{ 0x01u << int( stage ) };
	}
}

#endif
