/*
See LICENSE file in root folder
*/
#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Expr/ExprStreamAppend.hpp>
#include <ShaderAST/Expr/MakeIntrinsic.hpp>

namespace sdw
{
	//*************************************************************************

	template< typename InputDataT >
	InputT< InputDataT >::InputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputDataT{ writer, std::move( expr ), enabled }
	{
	}

	//*************************************************************************

	template< typename InputDataT, type::InputLayout LayoutT >
	InputArrayT< InputDataT, LayoutT >::InputArrayT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< InputT< InputDataT > >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_in"
					, PerVertex::getArrayType( getTypesCache( writer ), getArraySize( LayoutT ) )
					, var::Flag::eShaderInput ) )
			, true }
	{
	}

	template< typename InputDataT, type::InputLayout LayoutT >
	InputArrayT< InputDataT, LayoutT >::InputArrayT( ShaderWriter & writer )
		: InputArrayT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomIn"
					, ast::type::makeGeometryInputType( makeType( getTypesCache( writer ) )
						, LayoutT )
					, var::Flag::eShaderInput ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryInput
				, vtx.getType() ) );
	}

	template< typename InputDataT, type::InputLayout LayoutT >
	ast::type::TypePtr InputArrayT< InputDataT, LayoutT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< InputDataT >::makeType( cache );
	}

	//*************************************************************************

	template< typename StreamDataT >
	OutputStreamT< StreamDataT >::OutputStreamT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StreamDataT{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ""
					, PerVertex::getBaseType( getTypesCache( writer ) )
					, var::Flag::eShaderOutput ) ) }
	{
	}

	template< typename StreamDataT >
	OutputStreamT< StreamDataT >::OutputStreamT( ShaderWriter & writer
		, type::OutputLayout layout
		, uint32_t count )
		: OutputStreamT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomOut"
					, ast::type::makeGeometryOutputType( makeType( getTypesCache( writer ) )
						, layout
						, count ) ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, vtx.getType() ) );
	}

	template< typename StreamDataT >
	void OutputStreamT< StreamDataT >::append()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, ast::stmt::makeSimple( ast::expr::makeStreamAppend( sdw::makeExpr( *this ) ) ) );
	}

	template< typename StreamDataT >
	void OutputStreamT< StreamDataT >::restartStrip()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, ast::stmt::makeSimple( ast::expr::makeEndPrimitive( getTypesCache( writer ) ) ) );
	}

	//*************************************************************************

	template< typename StreamDataT >
	PointStreamT< StreamDataT >::PointStreamT( ShaderWriter & writer
		, uint32_t count )
		: OutputStreamT< StreamDataT >{ writer, type::OutputLayout::ePointList, count }
	{
	}

	//*************************************************************************

	template< typename StreamDataT >
	LineStreamT< StreamDataT >::LineStreamT( ShaderWriter & writer
		, uint32_t count )
		: OutputStreamT< StreamDataT >{ writer, type::OutputLayout::eLineStrip, count }
	{
	}

	//*************************************************************************

	template< typename StreamDataT >
	TriangleStreamT< StreamDataT >::TriangleStreamT( ShaderWriter & writer
		, uint32_t count )
		: OutputStreamT< StreamDataT >{ writer, type::OutputLayout::eTriangleStrip, count }
	{
	}

	//*************************************************************************
}
