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

	var::VariablePtr PipelineWriter::registerInput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		return getShader().registerInput( entryPoint
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
		return getShader().registerOutput( entryPoint
			, std::move( name )
			, location
			, attributes
			, type );
	}
}
