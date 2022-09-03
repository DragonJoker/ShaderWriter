/*
See LICENSE file in root folder
*/
#include "GlslExprVisitor.hpp"

#include "GlslHelpers.hpp"
#include "GlslIntrinsicNames.hpp"
#include "GlslStorageImageAccessNames.hpp"
#include "GlslCombinedImageAccessNames.hpp"

#include <cmath>
#pragma warning( push )
#pragma warning( disable: 4365 )
#include <sstream>
#pragma warning( pop )
#include <iomanip>

namespace glsl
{
	namespace
	{
		std::string adaptName( std::string const & name
			, GlslConfig const & writerConfig )
		{
			if ( writerConfig.vulkanGlsl )
			{
				static std::map< std::string, std::string > const toVkNames
				{
					{ "gl_InstanceID", "gl_InstanceIndex" },
					{ "gl_VertexID", "gl_VertexIndex" },
					{ "gl_DrawIndex", "gl_DrawID" },
					{ "gl_LaunchID", "gl_LaunchIDEXT" },
					{ "gl_LaunchSize", "gl_LaunchSizeEXT" },
					{ "gl_InstanceCustomIndex", "gl_InstanceCustomIndexEXT" },
					{ "gl_GeometryIndex", "gl_GeometryIndexEXT" },
					{ "gl_WorldRayOrigin", "gl_WorldRayOriginEXT" },
					{ "gl_WorldRayDirection", "gl_WorldRayDirectionEXT" },
					{ "gl_ObjectRayOrigin", "gl_ObjectRayOriginEXT" },
					{ "gl_ObjectRayDirection", "gl_ObjectRayDirectionEXT" },
					{ "gl_RayTmin", "gl_RayTminEXT" },
					{ "gl_RayTmax", "gl_RayTmaxEXT" },
					{ "gl_IncomingRayFlags", "gl_IncomingRayFlagsEXT" },
					{ "gl_HitKind", "gl_HitKindEXT" },
					{ "gl_ObjectToWorld", "gl_ObjectToWorldEXT" },
					{ "gl_WorldToObject", "gl_WorldToObjectEXT" },
					{ "gl_SubgroupLocalInvocationID", "gl_SubgroupInvocationID" },
				};
				auto it = toVkNames.find( name );

				if ( it != toVkNames.end() )
				{
					return it->second;
				}
			}
			else
			{
				static std::map< std::string, std::string > const toGlNames
				{
					{ "gl_InstanceIndex", "gl_InstanceID" },
					{ "gl_VertexIndex", "gl_VertexID" },
					{ "gl_DrawIndex", "gl_DrawID" },
					{ "gl_LaunchID", "gl_LaunchIDEXT" },
					{ "gl_LaunchSize", "gl_LaunchSizeEXT" },
					{ "gl_InstanceCustomIndex", "gl_InstanceCustomIndexEXT" },
					{ "gl_GeometryIndex", "gl_GeometryIndexEXT" },
					{ "gl_WorldRayOrigin", "gl_WorldRayOriginEXT" },
					{ "gl_WorldRayDirection", "gl_WorldRayDirectionEXT" },
					{ "gl_ObjectRayOrigin", "gl_ObjectRayOriginEXT" },
					{ "gl_ObjectRayDirection", "gl_ObjectRayDirectionEXT" },
					{ "gl_RayTmin", "gl_RayTminEXT" },
					{ "gl_RayTmax", "gl_RayTmaxEXT" },
					{ "gl_IncomingRayFlags", "gl_IncomingRayFlagsEXT" },
					{ "gl_HitKind", "gl_HitKindEXT" },
					{ "gl_ObjectToWorld", "gl_ObjectToWorldEXT" },
					{ "gl_WorldToObject", "gl_WorldToObjectEXT" },
					{ "gl_SubgroupLocalInvocationID", "gl_SubgroupInvocationID" },
				};
				auto it = toGlNames.find( name );

				if ( it != toGlNames.end() )
				{
					return it->second;
				}
			}

			return name;
		}
	}

	//*************************************************************************

	std::string ExprVisitor::submit( ast::expr::Expr * expr
		, GlslConfig const & writerConfig
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases )
	{
		std::string result;
		ExprVisitor vis{ writerConfig, aliases, result };
		expr->accept( &vis );
		return result;
	}

	ExprVisitor::ExprVisitor( GlslConfig const & writerConfig
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, std::string & result )
		: m_writerConfig{ writerConfig }
		, m_aliases{ aliases }
		, m_result{ result }
	{
	}

	std::string ExprVisitor::doSubmit( ast::expr::Expr * expr )
	{
		return submit( expr, m_writerConfig, m_aliases );
	}

	void ExprVisitor::wrap( ast::expr::Expr * expr )
	{
		bool noParen = expr->getKind() == ast::expr::Kind::eFnCall
			|| expr->getKind() == ast::expr::Kind::eIdentifier
			|| expr->getKind() == ast::expr::Kind::eLiteral
			|| expr->getKind() == ast::expr::Kind::eMbrSelect
			|| expr->getKind() == ast::expr::Kind::eCast
			|| expr->getKind() == ast::expr::Kind::eSwizzle
			|| expr->getKind() == ast::expr::Kind::eArrayAccess
			|| expr->getKind() == ast::expr::Kind::eIntrinsicCall
			|| expr->getKind() == ast::expr::Kind::eCombinedImageAccessCall
			|| expr->getKind() == ast::expr::Kind::eImageAccessCall
			|| expr->getKind() == ast::expr::Kind::eUnaryMinus
			|| expr->getKind() == ast::expr::Kind::eUnaryPlus
			|| expr->getKind() == ast::expr::Kind::eCopy;

		if ( noParen )
		{
			m_result += doSubmit( expr );
		}
		else
		{
			m_result += "(";
			m_result += doSubmit( expr );
			m_result += ")";
		}
	}

	void ExprVisitor::visitAssignmentExpr( ast::expr::Binary * expr )
	{
		wrap( expr->getLHS() );
		m_result += " " + getOperatorName( expr->getKind() ) + " ";
		m_result += doSubmit( expr->getRHS() );
	}

	void ExprVisitor::visitUnaryExpr( ast::expr::Unary * expr )
	{
		if ( expr->isNonUniform()
			&& !expr->getOperand()->isNonUniform() )
		{
			m_result += "nonuniformEXT(";
		}

		if ( isUnaryPre( expr->getKind() ) )
		{
			m_result += getOperatorName( expr->getKind() );
			wrap( expr->getOperand() );
		}
		else
		{
			wrap( expr->getOperand() );
			m_result += getOperatorName( expr->getKind() );
		}

		if ( expr->isNonUniform()
			&& !expr->getOperand()->isNonUniform() )
		{
			m_result += ")";
		}

	}

	void ExprVisitor::visitBinaryExpr( ast::expr::Binary * expr )
	{
		wrap( expr->getLHS() );
		m_result += " " + getOperatorName( expr->getKind() ) + " ";
		wrap( expr->getRHS() );
	}

	void ExprVisitor::visitAddAssignExpr( ast::expr::AddAssign * expr )
	{
		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitAndAssignExpr( ast::expr::AndAssign * expr )
	{
		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitAssignExpr( ast::expr::Assign * expr )
	{
		auto lhs = doSubmit( expr->getLHS() );
		auto rhs = doSubmit( expr->getRHS() );

		if ( lhs == rhs )
		{
			return;
		}

		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitDivideAssignExpr( ast::expr::DivideAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitMinusAssignExpr( ast::expr::MinusAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitModuloAssignExpr( ast::expr::ModuloAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitOrAssignExpr( ast::expr::OrAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitTimesAssignExpr( ast::expr::TimesAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitXorAssignExpr( ast::expr::XorAssign * expr )
	{
		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		if ( expr->getIdentifier() )
		{
			if ( expr->isConstant() )
			{
				m_result += "const ";
			}

			m_result += getTypeName( expr->getType() ) + " ";
			m_result += doSubmit( expr->getIdentifier() );
			m_result += getTypeArraySize( expr->getType() );
			m_result += " = ";
		}

		m_result += getTypeName( expr->getType() ) + "[](";
		std::string sep;

		for ( auto & init : expr->getInitialisers() )
		{
			m_result += sep + doSubmit( init.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitArrayAccessExpr( ast::expr::ArrayAccess * expr )
	{
		wrap( expr->getLHS() );
		m_result += "[";
		wrap( expr->getRHS() );
		m_result += "]";
	}

	void ExprVisitor::visitCastExpr( ast::expr::Cast * expr )
	{
		m_result += getTypeName( expr->getType() ) + "(";
		m_result += doSubmit( expr->getOperand() );
		m_result += ")";
	}

	void ExprVisitor::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
		{
			m_result += getCtorName( *expr->getArgList()[0]
				, *expr->getArgList()[1] );
		}
		else
		{
			m_result += getCtorName( expr->getComposite(), expr->getComponent() );
		}

		m_result += "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			m_result += doSubmit( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		wrap( expr->getOuterExpr() );

		if ( !m_result.empty() )
		{
			m_result += ".";
		}

		auto mbr = expr->getOuterType()->getMember( expr->getMemberIndex() );

		if ( mbr.builtin != ast::Builtin::eNone )
		{
			m_result += "gl_" + getName( mbr.builtin );
		}
		else
		{
			m_result += mbr.name;
		}
	}

	void ExprVisitor::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		if ( expr->isMember() )
		{
			wrap( expr->getInstance() );
			m_result += ".";
		}

		m_result += doSubmit( expr->getFn() );
		m_result += "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			m_result += doSubmit( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto it = m_aliases.find( expr->getVariable() );

		if ( it != m_aliases.end() )
		{
			wrap( it->second );
		}
		else
		{
			m_result += adaptName( expr->getVariable()->getName(), m_writerConfig );
		}
	}

	void ExprVisitor::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		m_result += getGlslName( expr->getImageAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			m_result += doSubmit( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitInitExpr( ast::expr::Init * expr )
	{
		if ( expr->isConstant() )
		{
			m_result += "const ";
		}

		m_result += getTypeName( expr->getType() ) + " ";
		m_result += doSubmit( expr->getIdentifier() );
		m_result += getTypeArraySize( expr->getIdentifier()->getType() );
		m_result += " = ";
		m_result += doSubmit( expr->getInitialiser() );
	}

	void ExprVisitor::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		m_result += getGlslName( expr->getIntrinsic() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			m_result += doSubmit( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitLiteralExpr( ast::expr::Literal * expr )
	{
		std::locale loc{ "C" };
		std::stringstream stream;
		stream.imbue( loc );

		switch ( expr->getLiteralType() )
		{
		case ast::expr::LiteralType::eBool:
			stream << ( expr->getValue< ast::expr::LiteralType::eBool >()
				? std::string{ "true" }
				: std::string{ "false" } );
			break;
		case ast::expr::LiteralType::eInt8:
			stream << "int8_t(" << int16_t( expr->getValue< ast::expr::LiteralType::eInt8 >() ) << ")";
			break;
		case ast::expr::LiteralType::eInt16:
			stream << "int16_t(" << expr->getValue< ast::expr::LiteralType::eInt16 >() << ")";
			break;
		case ast::expr::LiteralType::eInt32:
			stream << expr->getValue< ast::expr::LiteralType::eInt32 >();
			break;
		case ast::expr::LiteralType::eInt64:
			stream << expr->getValue< ast::expr::LiteralType::eInt64 >() << "l";
			break;
		case ast::expr::LiteralType::eUInt8:
			stream << "uint8_t(" << uint16_t( expr->getValue< ast::expr::LiteralType::eUInt8 >() ) << "u)";
			break;
		case ast::expr::LiteralType::eUInt16:
			stream << "uint16_t(" << expr->getValue< ast::expr::LiteralType::eUInt16 >() << "u)";
			break;
		case ast::expr::LiteralType::eUInt32:
			stream << expr->getValue< ast::expr::LiteralType::eUInt32 >() << "u";
			break;
		case ast::expr::LiteralType::eUInt64:
			stream << expr->getValue< ast::expr::LiteralType::eUInt64 >() << "ul";
			break;
		case ast::expr::LiteralType::eFloat:
			{
				auto v = expr->getValue< ast::expr::LiteralType::eFloat >();
				stream << std::setprecision( 12u ) << v;

				if ( v == std::floor( v )
					&& stream.str().find( 'e' ) == std::string::npos )
				{
					stream << ".0";
				}

				stream << "f";
			}
			break;
		case ast::expr::LiteralType::eDouble:
			{
				auto v = expr->getValue< ast::expr::LiteralType::eDouble >();
				stream << std::setprecision( 16u ) << v;

				if ( v == std::floor( v )
					&& stream.str().find( 'e' ) == std::string::npos )
				{
					stream << ".0";
				}
			}
			break;
		default:
			AST_Failure( "Unsupported literal type" );
			break;
		}

		m_result += stream.str();
	}

	void ExprVisitor::visitQuestionExpr( ast::expr::Question *expr )
	{
		m_result += "(";
		wrap( expr->getCtrlExpr() );
		m_result += " ? ";
		wrap( expr->getTrueExpr() );
		m_result += " : ";
		wrap( expr->getFalseExpr() );
		m_result += ")";
	}

	void ExprVisitor::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		AST_Failure( "Unexpected ast::expr::StreamAppend expression." );
	}

	void ExprVisitor::visitSwitchCaseExpr( ast::expr::SwitchCase *expr )
	{
		m_result += doSubmit( expr->getLabel() );
	}

	void ExprVisitor::visitSwitchTestExpr( ast::expr::SwitchTest *expr )
	{
		m_result += doSubmit( expr->getValue() );
	}

	void ExprVisitor::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		wrap( expr->getOuterExpr() );
		m_result += "." + getName( expr->getSwizzle() );
	}

	void ExprVisitor::visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )
	{
		m_result += getGlslName( expr->getCombinedImageAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			m_result += doSubmit( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitAliasExpr( ast::expr::Alias * expr )
	{
		m_aliases.emplace( expr->getLHS()->getVariable(), expr->getRHS() );
	}

	//*************************************************************************
}
