/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Writer_H___
#define ___Writer_Writer_H___

#include "Function.hpp"
#include "InputLayout.hpp"
#include "OutputLayout.hpp"
#include "Shader.hpp"
#include "Struct.hpp"

#include <map>
#include <locale>

namespace sdw
{
	class GlslWriter
	{
		friend struct IndentBlock;
		friend class Pcb;
		friend class Ubo;
		friend class Ssbo;

	public:
		GlslWriter();

		Struct getStruct( std::string const & name );
		void outputVertexCount( uint32_t p_count );
	};
}

#include "Writer.inl"

#endif
