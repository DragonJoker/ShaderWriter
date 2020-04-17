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

	PerVertex::PerVertex( ast::Shader * shader
		, ast::expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
		, position{ shader, getMbr( *this, 0u, "gl_Position" ) }
		, pointSize{ shader, getMbr( *this, 1u, "gl_PointSize" ) }
		, clipDistance{ shader, getMbr( *this, 2u, "gl_ClipDistance" ) }
		, cullDistance{ shader, getMbr( *this, 3u, "gl_CullDistance" ) }
	{
	}

	PerVertex::PerVertex( ShaderWriter & writer
		, stmt::PerVertexDecl::Source source )
		: PerVertex{ &writer.getShader()
			, makeExpr( writer.getShader(), var::makeVariable( getBaseType( writer.getTypesCache() ), "" ) ) }
	{
	}

	ast::type::StructPtr PerVertex::getBaseType( ast::type::TypesCache & cache )
	{
		return doGetInfo( cache ).getType();
	}

	ast::type::ArrayPtr PerVertex::getArrayType( ast::type::TypesCache & cache )
	{
		return cache.getArray( getBaseType( cache ) );
	}

	ast::type::TypePtr PerVertex::makeType( ast::type::TypesCache & cache )
	{
		return getBaseType( cache );
	}
}
