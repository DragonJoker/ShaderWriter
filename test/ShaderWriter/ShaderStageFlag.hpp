/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_ShaderStageFlag_H___
#define ___SDWVK_ShaderStageFlag_H___

#include "VulkanLayer.hpp"

#include <ShaderAST/ShaderASTPrerequisites.hpp>

namespace test::vk
{
	enum class ShaderStageFlag
		: uint32_t
	{
		eNone = 0x00u,
		eVertex = 0x01u << int( ast::ShaderStage::eVertex ),
		eTessellationControl = 0x01u << int( ast::ShaderStage::eTessellationControl ),
		eTessellationEvaluation = 0x01u << int( ast::ShaderStage::eTessellationEvaluation ),
		eGeometry = 0x01u << int( ast::ShaderStage::eGeometry ),
		eFragment = 0x01u << int( ast::ShaderStage::eFragment ),
		eCompute = 0x01u << int( ast::ShaderStage::eCompute ),
		eTaskNV = 0x01u << int( ast::ShaderStage::eTaskNV ),
		eMeshNV = 0x01u << int( ast::ShaderStage::eMeshNV ),
		eTask = 0x01u << int( ast::ShaderStage::eTask ),
		eMesh = 0x01u << int( ast::ShaderStage::eMesh ),
		eRayGeneration = 0x01u << int( ast::ShaderStage::eRayGeneration ),
		eRayAnyHit = 0x01u << int( ast::ShaderStage::eRayAnyHit ),
		eRayClosestHit = 0x01u << int( ast::ShaderStage::eRayClosestHit ),
		eRayMiss = 0x01u << int( ast::ShaderStage::eRayMiss ),
		eRayIntersection = 0x01u << int( ast::ShaderStage::eRayIntersection ),
		eCallable = 0x01u << int( ast::ShaderStage::eCallable ),
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

	inline ShaderStageFlags makeFlag( ast::ShaderStage stage )
	{
		return ShaderStageFlags{ 0x01u << int( stage ) };
	}
}

#endif
