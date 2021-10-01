/*
See LICENSE file in root folder
*/
#include "SpirvExprAdapter.hpp"
#include "SpirvExprEvaluator.hpp"

#include "SpirvGetSwizzleComponents.hpp"
#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"
#include "SpirvMakeAccessChain.hpp"

#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <stdexcept>

namespace spirv
{
	ast::expr::ExprPtr ExprAdapter::submit( ast::expr::Expr * expr
		, ast::stmt::Container * container
		, PreprocContext const & context
		, ModuleConfig const & config )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis
		{
			expr->getCache(),
			container,
			context,
			config,
			result
		};
		expr->accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, ast::stmt::Container * container
		, PreprocContext const & context
		, ModuleConfig const & config
		, ast::expr::ExprPtr & result )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_container{ container }
		, m_context{ context }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ m_cache, m_container, m_context, m_config, result };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto it = m_context.constExprs.find( expr->getVariable()->getName() );

		if ( it != m_context.constExprs.end() )
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
		IntrinsicConfig config;
		getSpirVConfig( kind, config );
		auto returnType = expr->getType();

		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( submit( arg.get(), m_container, m_context, m_config ) );
		}

		if ( getBias( kind ) == spv::ImageOperandsBiasMask )
		{
			// Bias is the last parameter in GLSL, but it has to be the first one after the ImageOperands in SPIR-V.
			if ( args.size() > config.imageOperandsIndex + 1u )
			{
				auto biasArg = std::move( args.back() );
				args.pop_back();
				args.emplace( args.begin() + config.imageOperandsIndex, std::move( biasArg ) );
			}
		}

#if !defined( NDEBUG )
		for ( auto & arg : args )
		{
			assert( arg != nullptr );
		}
#endif

		m_result = ast::expr::makeTextureAccessCall( returnType
			, kind
			, std::move( args ) );
	}
}
