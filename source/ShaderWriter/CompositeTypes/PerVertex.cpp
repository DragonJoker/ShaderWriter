/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/PerVertex.hpp"

#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Expr/ExprIdentifier.hpp>

namespace sdw
{
	namespace
	{
		InterfaceBlock doGetInfo( ast::type::TypesCache & cache )
		{
			InterfaceBlock result{ cache, type::MemoryLayout::eStd430, "gl_PerVertex" };
			result.registerMember< type::Kind::eVec4F >( "gl_Position" );
			result.registerMember< type::Kind::eFloat >( "gl_PointSize" );
			result.registerMember< type::Kind::eFloat >( "gl_ClipDistance", 8u );
			result.registerMember< type::Kind::eFloat >( "gl_CullDistance", 8u );
			return result;
		}

		bool isInput( stmt::PerVertexDecl::Source source )
		{
			return source == stmt::PerVertexDecl::Source::eGeometryInput
				|| source == stmt::PerVertexDecl::Source::eTessellationControlInput
				|| source == stmt::PerVertexDecl::Source::eTessellationEvaluationInput;
		}

		var::Flag getBuiltinFlag( stmt::PerVertexDecl::Source source )
		{
			return isInput( source )
				? var::Flag::eShaderInput
				: var::Flag::eShaderOutput;
		}

		expr::ExprPtr getMbr( Value const & outer
			, uint32_t mbrIndex
			, std::string const & mbrName )
		{
			auto ident = static_cast< expr::Identifier * >( outer.getExpr() );
			auto var = ident->getVariable();
			auto shader = outer.getShader();
			auto type = std::static_pointer_cast< type::Struct >( outer.getType() );
			return sdw::makeMbrSelect( makeExpr( outer )
				, mbrIndex
				, makeIdent( shader->getTypesCache()
					, shader->registerMember( var
						, mbrName
						, type->getMember( mbrName ).type
						, var::Flag::eBuiltin
							| ( var->isShaderInput()
								? var::Flag::eShaderInput
								: var::Flag::eShaderOutput ) ) ) );
		}
	}

	gl_PerVertex::gl_PerVertex( ast::Shader * shader
		, ast::expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
		, gl_Position{ shader, getMbr( *this, 0u, "gl_Position" ) }
		, gl_PointSize{ shader, getMbr( *this, 1u, "gl_PointSize" ) }
		, gl_ClipDistance{ shader, getMbr( *this, 2u, "gl_ClipDistance" ) }
		, gl_CullDistance{ shader, getMbr( *this, 3u, "gl_CullDistance" ) }
	{
	}

	gl_PerVertex::gl_PerVertex( ShaderWriter & writer
		, stmt::PerVertexDecl::Source source )
		: gl_PerVertex{ &writer.getShader()
			, makeExpr( writer.getShader(), var::makeVariable( getBaseType( writer.getTypesCache() ), "" ) ) }
	{
	}

	ast::type::StructPtr gl_PerVertex::getBaseType( ast::type::TypesCache & cache )
	{
		return doGetInfo( cache ).getType();
	}

	ast::type::ArrayPtr gl_PerVertex::getArrayType( ast::type::TypesCache & cache )
	{
		return cache.getArray( getBaseType( cache ) );
	}
}
