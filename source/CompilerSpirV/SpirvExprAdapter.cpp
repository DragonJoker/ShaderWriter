/*
See LICENSE file in root folder
*/
#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include "SpirvTextureAccessNames.hpp"

namespace spirv
{
	ast::expr::ExprPtr ExprAdapter::submit( ast::expr::Expr * expr
		, PreprocContext const & context )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ result, context };
		expr->accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( ast::expr::ExprPtr & result
		, PreprocContext const & context )
		: ExprCloner{ result }
		, m_context{ context }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ result, m_context };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto it = m_context.defines.find( expr->getVariable()->getName() );

		if ( it != m_context.defines.end() )
		{
			if ( it->second->getKind() == ast::expr::Kind::eLiteral )
			{
				m_result = getLiteral( expr, m_context );
			}
			else
			{
				m_result = ExprCloner::submit( it->second );
			}
		}
		else
		{
			m_result = ExprCloner::submit( expr );
		}
	}

	void ExprAdapter::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		uint32_t imageOperandsIndex = 0u;
		auto op = getSpirVName( kind, imageOperandsIndex );

		if ( op == spv::Op::OpImageGather )
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( submit( arg.get(), m_context ) );
			}

			if ( !hasComp( kind ) )
			{
				// Comp parameter of textureGather can be implicitly 0, in GLSL.
				// Hence add it to args.
				args.emplace_back( ast::expr::makeLiteral( 0 ) );
				kind = getCompAccess( kind );
			}

			// Comp parameter is the last one in GLSL whilst it is the last before
			// optional ones in SPIR-V, hence we move it to the right place.
			args.emplace( args.begin() + imageOperandsIndex - 1u, std::move( args.back() ) );
			args.erase( args.begin() + args.size() - 1u );

			m_result = ast::expr::makeTextureAccessCall( expr->getType()
				, kind
				, std::move( args ) );
		}
		else
		{
			m_result = ExprCloner::submit( expr );
		}
	}
}
