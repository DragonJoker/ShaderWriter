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

		void forStmt( Type && p_init, Expr const & p_cond, Expr const & p_incr, std::function< void() > p_function );
		void whileStmt( Expr const & p_cond, std::function< void() > p_function );
		GlslWriter & ifStmt( Expr const & p_cond, std::function< void() > p_function );
		GlslWriter & elseIfStmt( Expr const & p_cond, std::function< void() > p_function );
		void elseStmt( std::function< void() > p_function );
		Struct getStruct( std::string const & name );
		void emitVertex();
		void endPrimitive();
		void discard();
		void inputGeometryLayout( std::string const & p_layout );
		void outputGeometryLayout( std::string const & p_layout );
		void outputGeometryLayout( std::string const & p_layout, uint32_t p_count );
		void outputVertexCount( uint32_t p_count );
	};

#define FOR( Writer, Type, Name, Init, Cond, Incr )\
	{\
		Type Name( &Writer, cuT( #Name ) );\
		Name.m_value << Type().m_type << cuT( #Name ) << cuT( " = " ) << cuT( #Init );\
		( Writer ).forStmt( std::move( Name ), sdw::Expr( &( Writer ), std::string( Cond ) ), sdw::Expr( &( Writer ), std::string( Incr ) ), [&]()

#define ROF\
	 );\
	}

#define WHILE( Writer, Cond )\
	{\
		( Writer ).whileStmt( sdw::Expr( &( Writer ), std::string( Cond ) ), [&]()

#define ELIHW\
	 );\
	}

#define IF( Writer, Condition )\
	( Writer ).ifStmt( sdw::Expr( &( Writer ), std::string( Condition ) ), [&]()

#define ELSE\
 ).elseStmt( [&]()

#define ELSEIF( Writer, Condition )\
 ).elseIfStmt( sdw::Expr( &( Writer ), std::string( Condition ) ), [&]()

#define FI\
 );
}

#define TERNARY( Writer, ExprType, Condition, Left, Right )\
	Writer.ternary< ExprType >( Condition, Left, Right )

#include "Writer.inl"

#endif
