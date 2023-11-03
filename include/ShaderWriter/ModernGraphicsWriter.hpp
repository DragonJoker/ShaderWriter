/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ModernGraphicsWriter_H___
#define ___SDW_ModernGraphicsWriter_H___

#if !defined( SDW_PreferredMeshShadingExtension )
#	error "You must define SDW_PreferredMeshShadingExtension to either SDW_MeshShadingEXT or SDW_MeshShadingNV"
#endif

#if SDW_PreferredMeshShadingExtension == SDW_MeshShadingEXT
#	include "ShaderWriter/ModernGraphicsWriterEXT.hpp"
#else
#	include "ShaderWriter/ModernGraphicsWriterNV.hpp"
#endif

#include "ShaderWriter/MeshWriter.hpp"
#include "ShaderWriter/TaskWriter.hpp"

namespace sdw
{
#if SDW_PreferredMeshShadingExtension == SDW_MeshShadingEXT
	using ModernGraphicsWriter = ModernGraphicsWriterEXT;
	static constexpr ast::ShaderStage ModernGraphicsStage = ast::ShaderStage::eModernGraphicsEXT;
#else
	using ModernGraphicsWriter = ModernGraphicsWriterNV;
	static constexpr ast::ShaderStage ModernGraphicsStage = ast::ShaderStage::eModernGraphicsNV;
#endif
}

#endif
