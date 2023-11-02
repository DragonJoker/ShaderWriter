/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp"
#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	void registerSsbo( ShaderWriter & writer
		, std::string name
		, SsboInfo const & info )
	{
		writer.getBuilder().registerSsbo( std::move( name ), info );
	}
}
