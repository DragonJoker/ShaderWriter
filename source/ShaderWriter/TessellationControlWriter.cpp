/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TessellationControlWriter.hpp"

namespace sdw
{
	uint32_t getOuterArraySize( ast::type::OutputDomain domain )
	{
		switch ( domain )
		{
		case ast::type::OutputDomain::eIsolines:
			return 2u;
		case ast::type::OutputDomain::eTriangles:
			return 3u;
		case ast::type::OutputDomain::eQuads:
			return 4u;
		default:
			return 1u;
		}
	}

	uint32_t getInnerArraySize( ast::type::OutputDomain domain )
	{
		switch ( domain )
		{
		case ast::type::OutputDomain::eIsolines:
			return 0u;
		case ast::type::OutputDomain::eTriangles:
			return 1u;
		case ast::type::OutputDomain::eQuads:
			return 2u;
		default:
			return 0u;
		}
	}

	bool hasInnerLevel( ast::type::OutputDomain domain )
	{
		return domain != ast::type::OutputDomain::eIsolines;
	}

	TessellationControlWriter::TessellationControlWriter()
		: ShaderWriter{ ast::ShaderStage::eTessellationControl }
	{
	}
}
