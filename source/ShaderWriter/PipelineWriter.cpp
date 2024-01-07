/*
See LICENSE file in root folder
*/
#include "ShaderWriter/PipelineWriter.hpp"

namespace sdw
{
	PipelineWriter::PipelineWriter( ast::ShaderStage type
		, ShaderAllocator * allocator )
		: ShaderWriter{ type, allocator }
	{
	}

	PipelineWriter::PipelineWriter( ShaderBuilder & builder )
		: ShaderWriter{ builder }
	{
		if ( builder.getType() != ast::ShaderStage::eTraditionalGraphics
			&& builder.getType() != ast::ShaderStage::eModernGraphicsEXT
			&& builder.getType() != ast::ShaderStage::eModernGraphicsNV
			&& builder.getType() != ast::ShaderStage::eRayTrace )
		{
			throw ast::Exception{ "Can't create a PipelineWriter from this kind of builder." };
		}
	}

	var::VariablePtr PipelineWriter::registerInput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		return getBuilder().registerInput( entryPoint
			, std::move( name )
			, location
			, attributes
			, type );
	}

	var::VariablePtr PipelineWriter::registerOutput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		return getBuilder().registerOutput( entryPoint
			, std::move( name )
			, location
			, attributes
			, type );
	}
}
