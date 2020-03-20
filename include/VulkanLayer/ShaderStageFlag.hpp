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
