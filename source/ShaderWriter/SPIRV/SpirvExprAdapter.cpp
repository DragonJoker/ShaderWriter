/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvExprAdapter.hpp"
#include "ShaderWriter/SPIRV/SpirvExprEvaluator.hpp"

#include "ShaderWriter/SPIRV/SpirvTextureAccessNames.hpp"

namespace sdw::spirv
{
	expr::ExprPtr ExprAdapter::submit( expr::Expr * expr
		, PreprocContext const & context )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, context };
		expr->accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( expr::ExprPtr & result
		, PreprocContext const & context )
		: ExprCloner{ result }
		, m_context{ context }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, m_context };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( expr::Identifier * expr )
	{
		auto it = m_context.defines.find( expr->getVariable()->getName() );

		if ( it != m_context.defines.end() )
		{
			if ( it->second->getKind() == expr::Kind::eLiteral )
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

	void ExprAdapter::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		uint32_t imageOperandsIndex = 0u;
		auto op = getSpirVName( kind, imageOperandsIndex );

		if ( op == spv::Op::OpImageGather )
		{
			if ( !hasComp( kind ) )
			{
				// Comp parameter of textureGather can be implicitly 0, in GLSL.
				// Hence add it to args.
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( submit( arg.get(), m_context ) );
				}

				args.insert( args.begin() + ( imageOperandsIndex - 1u ), expr::makeLiteral( 0 ) );
				kind = getCompAccess( kind );

				m_result = expr::makeTextureAccessCall( expr->getType()
					, kind
					, std::move( args ) );
			}
			else
			{
				m_result = ExprCloner::submit( expr );
			}
		}
		else
		{
			m_result = ExprCloner::submit( expr );
		}
	}
}
