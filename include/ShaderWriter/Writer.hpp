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
		void inlineComment( std::string const & comment );
		void multilineComment( std::string const & comment );
		void enableExtension( std::string const & name, uint32_t inCoreVersion );
		std::string getInstanceID();
		std::string getVertexID();
		sdw::Vec2 ashesBottomUpToTopDown( sdw::Vec2 const & texCoord );
		sdw::Vec2 ashesTopDownToBottomUp( sdw::Vec2 const & texCoord );
		sdw::Vec3 ashesBottomUpToTopDown( sdw::Vec3 const & texCoord );
		sdw::Vec3 ashesTopDownToBottomUp( sdw::Vec3 const & texCoord );

		Struct getStruct( std::string const & name );
		void emitVertex();
		void endPrimitive();
		void discard();
		void inputGeometryLayout( std::string const & p_layout );
		void outputGeometryLayout( std::string const & p_layout );
		void outputGeometryLayout( std::string const & p_layout, uint32_t p_count );
		void outputVertexCount( uint32_t p_count );
	};
}

#include "Writer.inl"

#endif
