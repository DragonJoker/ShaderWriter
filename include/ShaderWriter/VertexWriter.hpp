/*
See LICENSE file in root folder
*/
#ifndef ___SDW_VertexWriter_H___
#define ___SDW_VertexWriter_H___

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	/**
	*name
	*	Vertex.
	*/
	/**@{*/
	/**
	*	Holds input data for a vertex shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct VertexInT
		: public InputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		VertexInT( ShaderWriter & writer );
		VertexInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_VertexIndex;
		Int const vertexIndex;
		//in int gl_InstanceIndex;
		Int const instanceIndex;
		//in int gl_DrawID;
		Int const drawID;
		//in int gl_BaseVertex;
		Int const baseVertex;
		//in int gl_BaseInstance;
		Int const baseInstance;
	};
	/**
	*	Holds per vertex output data.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct VertexOutT
		: public OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		VertexOutT( ShaderWriter & writer );
		VertexOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		PerVertex vtx;
	};

	using VertexIn = VertexInT< VoidT >;
	using VertexOut = VertexOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	using VertexMainFuncT = std::function< void( VertexInT< InT >, VertexOutT< OutT > ) >;

	class VertexWriter
		: public ShaderWriter
	{
	public:
		SDW_API VertexWriter();

		SDW_API void implementMain( VertexMainFuncT< VoidT, VoidT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( VertexMainFuncT< InT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( VertexInT< InT > in
			, VertexOutT< OutT > out
			, VertexMainFuncT< InT, OutT > const & function );
	};
	/**@}*/
}

#include "VertexWriter.inl"

#endif
