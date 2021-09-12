/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/PerVertex.hpp"

#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Expr/ExprArrayAccess.hpp>
#include <ShaderAST/Expr/ExprIdentifier.hpp>

namespace sdw
{
	namespace
	{
		InterfaceBlock doGetInfo( ast::type::TypesCache & cache )
		{
			InterfaceBlock result{ cache, type::MemoryLayout::eStd430, "gl_PerVertex" };

			if ( !result.hasMember( "gl_Position" ) )
			{
				result.registerMember< type::Kind::eVec4F >( "gl_Position" );
				result.registerMember< type::Kind::eFloat >( "gl_PointSize" );
				result.registerMember< type::Kind::eFloat >( "gl_ClipDistance", 8u );
				result.registerMember< type::Kind::eFloat >( "gl_CullDistance", 8u );
			}

			return result;
		}

		expr::ExprPtr getMbr( Value const & outer
			, uint32_t mbrIndex )
		{
			auto type = std::static_pointer_cast< type::Struct >( getNonArrayType( outer.getType() ) );
			var::VariablePtr var;

			if ( outer.getExpr()->getKind() == expr::Kind::eArrayAccess )
			{
				auto & arrayAccess = static_cast< expr::ArrayAccess const & >( *outer.getExpr() );
				assert( arrayAccess.getLHS()->getKind() == expr::Kind::eIdentifier );
				auto ident = static_cast< expr::Identifier * >( arrayAccess.getLHS() );
				var = ident->getVariable();
			}
			else
			{
				assert( outer.getExpr()->getKind() == expr::Kind::eIdentifier );
				auto ident = static_cast< expr::Identifier * >( outer.getExpr() );
				var = ident->getVariable();
			}

			return sdw::makeMbrSelect( makeExpr( outer )
				, mbrIndex
				, ( var::Flag::eBuiltin
					| ( var->isShaderInput()
						? var::Flag::eShaderInput
						: var::Flag::eShaderOutput ) ) );
		}
	}

	PerVertex::PerVertex( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), true }
		, position{ writer, getMbr( *this, 0u ), true }
		, pointSize{ writer, getMbr( *this, 1u ), true }
		, clipDistance{ writer, getMbr( *this, 2u ), true }
		, cullDistance{ writer, getMbr( *this, 3u ), true }
	{
	}

	PerVertex::PerVertex( ShaderWriter & writer
		, stmt::PerVertexDecl::Source source )
		: PerVertex{ writer
			, makeExpr( writer, var::makeVariable( getBaseType( writer.getTypesCache() ), "" ) ) }
	{
	}

	ast::type::StructPtr PerVertex::getBaseType( ast::type::TypesCache & cache )
	{
		return doGetInfo( cache ).getType();
	}

	ast::type::ArrayPtr PerVertex::getArrayType( ast::type::TypesCache & cache, uint32_t count )
	{
		return cache.getArray( getBaseType( cache ), count );
	}

	ast::type::TypePtr PerVertex::makeType( ast::type::TypesCache & cache )
	{
		return getBaseType( cache );
	}
}
