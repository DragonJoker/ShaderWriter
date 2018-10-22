/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslExprAdapter.hpp"

#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/HLSL/HlslVariableReplacer.hpp"
#include "ShaderWriter/HLSL/HlslImageAccessConfig.hpp"
#include "ShaderWriter/HLSL/HlslIntrinsicConfig.hpp"
#include "ShaderWriter/HLSL/HlslTextureAccessConfig.hpp"

namespace sdw::hlsl
{
	namespace
	{
		static std::map< std::string, std::string > const TypeCtorNames
		{
			{ "bool", "bool" },
			{ "bvec2", "bool2" },
			{ "bvec3", "bool3" },
			{ "bvec4", "bool4" },
			{ "int", "int" },
			{ "ivec2", "int2" },
			{ "ivec3", "int3" },
			{ "ivec4", "int4" },
			{ "uint", "uint" },
			{ "uvec2", "uint2" },
			{ "uvec3", "uint3" },
			{ "uvec4", "uint4" },
			{ "float", "float" },
			{ "vec2", "float2" },
			{ "vec3", "float3" },
			{ "vec4", "float4" },
			{ "mat2", "float2x2" },
			{ "mat2x3", "float2x3" },
			{ "mat2x4", "float2x4" },
			{ "mat3x2", "float3x2" },
			{ "mat3", "float3x3" },
			{ "mat3x4", "float3x4" },
			{ "mat4x2", "float4x2" },
			{ "mat4x3", "float4x3" },
			{ "mat4", "float4x4" },
			{ "double", "double" },
			{ "dvec2", "double2" },
			{ "dvec3", "double3" },
			{ "dvec4", "double4" },
		};

		var::VariablePtr adaptName( var::VariablePtr var )
		{
			auto it = TypeCtorNames.find( var->getName() );

			if ( it != TypeCtorNames.end() )
			{
				return var::makeVariable( var->getType(), it->second );
			}

			return var;
		}

		expr::IdentifierPtr adaptName( expr::Identifier const & ident )
		{
			return makeIdent( adaptName( ident.getVariable() ) );
		}

		bool isMatrix( type::Kind kind )
		{
			return kind >= type::Kind::eMat2x2F
				&& kind <= type::Kind::eMat4x4D;
		}
	}

	expr::ExprPtr ExprAdapter::submit( expr::Expr * expr
		, Config & config
		, LinkedVars const & linkedVars
		, VariableExprMap const & inputMembers
		, VariableExprMap const & outputMembers )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, config, linkedVars, inputMembers, outputMembers };
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr ExprAdapter::submit( expr::ExprPtr const & expr
		, Config & config
		, LinkedVars const & linkedVars
		, VariableExprMap const & inputMembers
		, VariableExprMap const & outputMembers )
	{
		return submit( expr.get()
			, config
			, linkedVars
			, inputMembers
			, outputMembers );
	}

	ExprAdapter::ExprAdapter( expr::ExprPtr & result
		, Config & config
		, LinkedVars const & linkedVars
		, VariableExprMap const & inputMembers
		, VariableExprMap const & outputMembers )
		: ExprCloner{ result }
		, m_config{ config }
		, m_linkedVars{ linkedVars }
		, m_inputMembers{ inputMembers }
		, m_outputMembers{ outputMembers }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, m_config, m_linkedVars, m_inputMembers, m_outputMembers };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( expr::Identifier * expr )
	{
		auto itInputs = m_inputMembers.find( expr->getVariable() );
		auto itOutputs = m_outputMembers.find( expr->getVariable() );

		if ( m_inputMembers.end() != itInputs )
		{
			m_result = makeExpr( itInputs->second );
		}
		else if ( m_outputMembers.end() != itOutputs )
		{
			m_result = makeExpr( itOutputs->second );
		}
		else
		{
			m_result = expr::makeIdentifier( expr->getVariable() );
		}
	}

	void ExprAdapter::visitFnCallExpr( expr::FnCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			auto ident = findIdentifier( arg );

			if ( ident )
			{
				auto it = m_linkedVars.find( ident->getVariable() );

				if ( m_linkedVars.end() != it )
				{
					args.emplace_back( VariableReplacer::submit( arg, ident->getVariable(), it->second.first ) );
					args.emplace_back( VariableReplacer::submit( arg, ident->getVariable(), it->second.second ) );
				}
				else
				{
					args.emplace_back( doSubmit( arg.get() ) );
				}
			}
			else
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = expr::makeFnCall( expr->getType()
			, adaptName( *expr->getFn() )
			, std::move( args ) );
	}

	void ExprAdapter::visitImageAccessCallExpr( expr::ImageAccessCall * expr )
	{
		getHlslConfig( expr->getImageAccess(), m_config );
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = expr::makeImageAccessCall( expr->getType()
			, expr->getImageAccess()
			, std::move( args ) );
	}

	void ExprAdapter::visitIntrinsicCallExpr( expr::IntrinsicCall * expr )
	{
		auto instantChange = getHlslConfig( expr->getIntrinsic(), m_config );

		if ( instantChange.toOperator )
		{
			switch ( instantChange.operatorKind )
			{
			case expr::Kind::eLess:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeLess( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;
				
			case expr::Kind::eLessEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeLessEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eGreater:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeGreater( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eGreaterEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeGreaterEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eNotEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeNotEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eLogNot:
				assert( expr->getArgList().size() == 1u );
				m_result = expr::makeLogNot( doSubmit( expr->getArgList()[0].get() ) );
				break;

			case expr::Kind::eTimes:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeTimes( expr->getArgList()[0].get()->getType()
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			default:
				assert( false && "Unexpected operator type." );
				break;
			}
		}
		else
		{
			expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = expr::makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		getHlslConfig( expr->getTextureAccess(), m_config );
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			if ( arg->getKind() == expr::Kind::eIdentifier )
			{
				auto ident = findIdentifier( arg );
				auto it = m_linkedVars.find( ident->getVariable() );

				if ( m_linkedVars.end() != it )
				{
					args.emplace_back( makeIdent( it->second.first ) );
					args.emplace_back( makeIdent( it->second.second ) );
				}
				else
				{
					args.emplace_back( doSubmit( arg.get() ) );
				}
			}
			else
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	void ExprAdapter::visitTimesExpr( expr::Times * expr )
	{
		if ( isMatrix( expr->getType()->getKind() ) )
		{
			expr::ExprList argsList;
			argsList.emplace_back( doSubmit( expr->getLHS() ) );
			argsList.emplace_back( doSubmit( expr->getRHS() ) );
			m_result = expr::makeFnCall( expr->getType()
				, expr::makeIdentifier( var::makeVariable( type::getFunction(), "mul" ) )
				, std::move( argsList ) );
		}
		else
		{
			m_result = expr::makeTimes( expr->getType()
				, doSubmit( expr->getLHS() )
				, doSubmit( expr->getRHS() ) );
		}
	}
}
