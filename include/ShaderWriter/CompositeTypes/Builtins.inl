/*
See LICENSE file in root folder
*/
#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Expr/ExprStreamAppend.hpp>
#include <ShaderAST/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region I/O
	/**
	*name
	*	I/O.
	*/
	/**@{*/
	template< ast::var::Flag FlagT >
	VoidT< FlagT >::VoidT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::var::Flag FlagT >
	ast::type::TypePtr VoidT< FlagT >::makeType( ast::type::TypesCache & cache )
	{
		return Void::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PatchInT< DataT >::PatchInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr PatchInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PatchOutT< DataT >::PatchOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr PatchOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	InputT< DataT >::InputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr InputT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	OutputT< DataT >::OutputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr OutputT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
#pragma region Vertex shader
	/**
	*name
	*	Vertex shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, vertexIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_VertexIndex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, instanceIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_InstanceIndex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, drawID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_DrawID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, baseVertex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_BaseVertex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, baseInstance{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_BaseInstance"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer )
		: VertexInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "vertIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr VertexInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( ""
					, PerVertex::getBaseType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer )
		: VertexOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "vertOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eVertexOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr VertexOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
#pragma region Tessellation control shader
	/**
	*name
	*	Tessellation control shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	TessControlInT< DataT, MaxPointsT >::TessControlInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< InputT< DataT > >{ writer, std::move( expr ), enabled }
		, patchVerticesIn{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_PatchVerticesIn"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_PrimitiveID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, invocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_InvocationID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_in"
					, PerVertex::getArrayType( getTypesCache( writer ), MaxPointsT )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	TessControlInT< DataT, MaxPointsT >::TessControlInT( ShaderWriter & writer
		, bool fromEntryPoint )
		: TessControlInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscIn"
					, getTypesCache( writer ).getArray( makeType( getTypesCache( writer ) ), MaxPointsT )
					, FlagT ) ) }
	{
		if ( fromEntryPoint )
		{
			addStmt( findWriterMandat( *this )
				, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlInput
					, vtx.getType() ) );
		}
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	ast::type::TypePtr TessControlInT< DataT, MaxPointsT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlOutT< DataT >::TessControlOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, tessLevelOuter{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_TessLevelOuter"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat(), 4u )
					, FlagT ) )
			, true }
		, tessLevelInner{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_TessLevelInner"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat(), 2u )
					, FlagT ) )
			, true }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_out"
					, PerVertex::getArrayType( getTypesCache( writer ), 32u )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlOutT< DataT >::TessControlOutT( ShaderWriter & writer )
		: TessControlOutT{ writer
		, makeExpr( writer
			, getShader( writer ).registerName( "tesscOut"
				, makeType( getTypesCache( writer ) )
				, FlagT ) ) }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr TessControlOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessPatchOutT< DataT >::TessPatchOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PatchOutT< DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessPatchOutT< DataT >::TessPatchOutT( ShaderWriter & writer )
		: TessPatchOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscPatch"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr TessPatchOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return PatchOutT< DataT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
#pragma region Geometry shader
	/**
	*name
	*	Geometry shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	GeometryInT< DataT, LayoutT >::GeometryInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< InputT< DataT > >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_in"
					, PerVertex::getArrayType( getTypesCache( writer ), getArraySize( LayoutT ) )
					, FlagT ) )
			, true }
		, primitiveIDIn{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_PrimitiveIDIn"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, invocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_InvocationID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	GeometryInT< DataT, LayoutT >::GeometryInT( ShaderWriter & writer )
		: GeometryInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomIn"
					, ast::type::makeGeometryInputType( makeType( getTypesCache( writer ) )
						, LayoutT )
					, FlagT ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryInput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	ast::type::TypePtr GeometryInT< DataT, LayoutT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	GeometryOutT< DataT >::GeometryOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ""
					, PerVertex::getBaseType( getTypesCache( writer ) )
					, FlagT ) ) }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_PrimitiveID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, layer{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_Layer"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, viewportIndex{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_ViewportIndex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	GeometryOutT< DataT >::GeometryOutT( ShaderWriter & writer
		, type::OutputLayout layout
		, uint32_t count )
		: GeometryOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomOut"
					, ast::type::makeGeometryOutputType( makeType( getTypesCache( writer ) )
						, layout
						, count )
					, FlagT ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	void GeometryOutT< DataT >::append()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( ast::expr::makeStreamAppend( sdw::makeExpr( *this ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	void GeometryOutT< DataT >::restartStrip()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( ast::expr::makeEndPrimitive( getTypesCache( writer ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr GeometryOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PointStreamT< DataT >::PointStreamT( ShaderWriter & writer
		, uint32_t count )
		: GeometryOutT< DataT >{ writer, type::OutputLayout::ePointList, count }
	{
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	LineStreamT< DataT >::LineStreamT( ShaderWriter & writer
		, uint32_t count )
		: GeometryOutT< DataT >{ writer, type::OutputLayout::eLineStrip, count }
	{
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TriangleStreamT< DataT >::TriangleStreamT( ShaderWriter & writer
		, uint32_t count )
		: GeometryOutT< DataT >{ writer, type::OutputLayout::eTriangleStrip, count }
	{
	}
	/**@}*/
#pragma endregion
#pragma region Fragment shader
	/**
	*name
	*	Fragment shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentInT< DataT >::FragmentInT( ShaderWriter & writer )
		: FragmentInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "fragIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentInT< DataT >::FragmentInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, fragCoord{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_FragCoord"
					, getTypesCache( writer ).getVec4F()
					, FlagT ) )
			, true }
		, frontFacing{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_FrontFacing"
					, getTypesCache( writer ).getBool()
					, FlagT ) )
			, true }
		, pointCoord{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_PointCoord"
					, getTypesCache( writer ).getVec2F()
					, FlagT ) )
			, true }
		, sampleID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_SampleID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, samplePosition{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_SamplePosition"
					, getTypesCache( writer ).getVec2F()
					, FlagT ) )
			, true }
		, sampleMaskIn{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_SampleMaskIn"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getInt() )
					, FlagT ) )
			, true }
		, clipDistance{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_ClipDistance"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat() )
					, FlagT ) )
			, true }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_PrimitiveID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, layer{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_Layer"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, viewportIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_ViewportIndex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr FragmentInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentOutT< DataT >::FragmentOutT( ShaderWriter & writer )
		: FragmentOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "fragOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentOutT< DataT >::FragmentOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, fragDepth{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_FragDepth"
					, getTypesCache( writer ).getFloat()
					, FlagT ) )
			, true }
		, sampleMask{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_SampleMask"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getInt() )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr FragmentOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
#pragma region Compute shader
	/**
	*name
	*	Compute shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	ComputeInT< DataT >::ComputeInT( ShaderWriter & writer )
		: ComputeInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "compIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ComputeInT< DataT >::ComputeInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, numWorkGroups{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_NumWorkGroups"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, workGroupID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_WorkGroupID"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, localInvocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_LocalInvocationID"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, globalInvocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_GlobalInvocationID"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, localInvocationIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_LocalInvocationIndex"
					, getTypesCache( writer ).getUInt()
					, FlagT ) )
			, true }
		, workGroupSize{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_WorkGroupSize"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr ComputeInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
}
