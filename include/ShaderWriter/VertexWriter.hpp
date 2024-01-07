/*
See LICENSE file in root folder
*/
#ifndef ___SDW_VertexWriter_H___
#define ___SDW_VertexWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"

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
		: public InputT< EntryPoint::eVertex, DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< EntryPoint::eVertex, DataT >::FlagT;

		template< typename ... ParamsT >
		explicit VertexInT( ShaderWriter & writer
			, ParamsT && ... params );
		VertexInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! in int gl_VertexIndex / SV_VertexID;
		Int32 const vertexIndex;
		//! in int gl_InstanceIndex / SV_InstanceID;
		Int32 const instanceIndex;
		//! in int gl_DrawID;
		Int32 const drawID;
		//! in int gl_BaseVertex;
		Int32 const baseVertex;
		//! in int gl_BaseInstance;
		Int32 const baseInstance;
	};
	/**
	*	Holds per vertex output data.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct VertexOutT
		: public OutputT< EntryPoint::eVertex, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eVertex, DataT >::FlagT;

		template< typename ... ParamsT >
		explicit VertexOutT( ShaderWriter & writer
			, ParamsT && ... params );
		VertexOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		PerVertex vtx;
	};

	using VertexIn = VertexInT< VoidT >;
	using VertexOut = VertexOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	using VertexMainFuncT = std::function< void( VertexInT< InT >, VertexOutT< OutT > ) >;

	class VertexWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit VertexWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit VertexWriter( ShaderBuilder & builder );

		SDW_API void implementMain( VertexMainFuncT< VoidT, VoidT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( VertexMainFuncT< InT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( VertexInT< InT > in
			, VertexOutT< OutT > out
			, VertexMainFuncT< InT, OutT > const & function );
	};
	/**@}*/
}

#include "VertexWriter.inl"

#endif
