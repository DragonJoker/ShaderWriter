/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslExprAdapter.hpp"

#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/GLSL/GlslTextureAccessConfig.hpp"

#include "ShaderWriter/Intrinsics.hpp"

namespace sdw::glsl
{
	expr::ExprPtr ExprAdapter::submit( expr::Expr * expr
		, IntrinsicsConfig const & config )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, config };
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr ExprAdapter::submit( expr::ExprPtr const & expr
		, IntrinsicsConfig const & config )
	{
		return submit( expr.get()
			, config );
	}

	ExprAdapter::ExprAdapter( expr::ExprPtr & result
		, IntrinsicsConfig const & config )
		: ExprCloner{ result }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, m_config };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		if ( expr->getTextureAccess() >= expr::TextureAccess::eTexture1DShadowF
			&& expr->getTextureAccess() <= expr::TextureAccess::eTextureProjGradOffset2DRectShadowF )
		{
			doProcessTextureShadow( expr );
		}
		else
		{
			expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = expr::makeTextureAccessCall( expr->getType()
				, expr->getTextureAccess()
				, std::move( args ) );
		}
	}

	void ExprAdapter::doProcessTextureShadow( expr::TextureAccessCall * expr )
	{
		expr::ExprList args;
		// First parameter is the sampled image
		args.emplace_back( doSubmit( expr->getArgList()[0].get() ) );
		// For texture shadow functions, dref value is put inside the coords parameter, instead of being aside.
		assert( expr->getArgList().size() >= 3u );
		// Merge second and third parameters to the appropriate vector type (float=>vec2, vec2=>vec3, vec3=>vec4).
		expr::ExprList merged;
		merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
		merged.emplace_back( doSubmit( expr->getArgList()[2].get() ) );

		switch ( merged[0]->getType()->getKind() )
		{
		case type::Kind::eFloat:
			args.emplace_back( sdw::makeFnCall( type::makeType( typeEnum< Vec2 > )
				, sdw::makeIdent( var::makeFunction( "vec2" ) )
				, std::move( merged ) ) );
			break;
		case type::Kind::eVec2F:
			args.emplace_back( sdw::makeFnCall( type::makeType( typeEnum< Vec3 > )
				, sdw::makeIdent( var::makeFunction( "vec3" ) )
				, std::move( merged ) ) );
			break;
		case type::Kind::eVec3F:
			args.emplace_back( sdw::makeFnCall( type::makeType( typeEnum< Vec4 > )
				, sdw::makeIdent( var::makeFunction( "vec4" ) )
				, std::move( merged ) ) );
			break;
		}

		// Other parameters remain unchanged.
		for ( size_t i = 3u; i < expr->getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( expr->getArgList()[i].get() ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}
}
