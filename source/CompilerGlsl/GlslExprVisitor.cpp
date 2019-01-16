/*
See LICENSE file in root folder
*/
#include "GlslExprVisitor.hpp"

#include "GlslHelpers.hpp"
#include "GlslImageAccessNames.hpp"
#include "GlslIntrinsicNames.hpp"
#include "GlslTextureAccessNames.hpp"

#include <sstream>
#include <iomanip>

namespace glsl
{
	namespace
	{
		std::string adaptName( std::string const & name
			, GlslConfig const & writerConfig )
		{
			static std::map< std::string, std::string > const names
			{
				{ "gl_InstanceID", "gl_InstanceIndex" },
				{ "gl_VertexID", "gl_VertexIndex" },
			};

			if ( writerConfig.vulkanGlsl )
			{
				auto it = names.find( name );

				if ( it != names.end() )
				{
					return it->second;
				}
			}

			return name;
		}
	}

	std::string ExprVisitor::submit( ast::expr::Expr * expr
		, GlslConfig const & writerConfig )
	{
		std::string result;
		ExprVisitor vis{ writerConfig, result };
		expr->accept( &vis );
		return result;
	}

	ExprVisitor::ExprVisitor( GlslConfig const & writerConfig
		, std::string & result )
		: m_writerConfig{ writerConfig }
		, m_result{ result }
	{
	}

	void ExprVisitor::wrap( ast::expr::Expr * expr )
	{
		bool noParen = expr->getKind() == ast::expr::Kind::eFnCall
			|| expr->getKind() == ast::expr::Kind::eIdentifier
			|| expr->getKind() == ast::expr::Kind::eLiteral
			|| expr->getKind() == ast::expr::Kind::eMbrSelect
			|| expr->getKind() == ast::expr::Kind::eCast
			|| expr->getKind() == ast::expr::Kind::eSwizzle
			|| expr->getKind() == ast::expr::Kind::eArrayAccess;

		if ( noParen )
		{
			expr->accept( this );
		}
		else
		{
			m_result += "(";
			expr->accept( this );
			m_result += ")";
		}
	}

	void ExprVisitor::visitAssignmentExpr( ast::expr::Binary * expr )
	{
		wrap( expr->getLHS() );
		m_result += " " + getOperatorName( expr->getKind() ) + " ";
		expr->getRHS()->accept( this );
	}

	void ExprVisitor::visitUnaryExpr( ast::expr::Unary * expr )
	{
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
			m_result += getTypeName( expr->getType() ) + " ";
			expr->getIdentifier()->accept( this );
			m_result += getTypeArraySize( expr->getType() );
			m_result += " = ";
		}

		m_result += getTypeName( expr->getType() ) + "[](";
		std::string sep;

		for ( auto & init : expr->getInitialisers() )
		{
			m_result += sep + submit( init.get(), m_writerConfig );
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
		expr->getOperand()->accept( this );
		m_result += ")";
	}

	void ExprVisitor::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		m_result += getCtorName( expr->getComposite(), expr->getComponent() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			arg->accept( this );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		wrap( expr->getOuterExpr() );
		m_result += ".";
		expr->getOperand()->accept( this );
	}

	void ExprVisitor::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		if ( expr->isMember() )
		{
			wrap( expr->getInstance() );
			m_result += ".";
		}

		expr->getFn()->accept( this );
		m_result += "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			arg->accept( this );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		m_result += adaptName( expr->getVariable()->getName(), m_writerConfig );
	}

	void ExprVisitor::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		m_result += getGlslName( expr->getImageAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			arg->accept( this );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitInitExpr( ast::expr::Init * expr )
	{
		m_result += getTypeName( expr->getType() ) + " ";
		expr->getIdentifier()->accept( this );
		m_result += getTypeArraySize( expr->getIdentifier()->getType() );
		m_result += " = ";
		expr->getInitialiser()->accept( this );
	}

	void ExprVisitor::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		m_result += getGlslName( expr->getIntrinsic() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			arg->accept( this );
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
		case ast::expr::LiteralType::eInt:
			stream << expr->getValue< ast::expr::LiteralType::eInt >();
			break;
		case ast::expr::LiteralType::eUInt:
			stream << expr->getValue< ast::expr::LiteralType::eUInt >() << "u";
			break;
		case ast::expr::LiteralType::eFloat:
			{
				auto v = expr->getValue< ast::expr::LiteralType::eFloat >();
				stream << std::setprecision( 8u ) << v;

				if ( v == int64_t( v ) )
				{
					stream << ".0";
				}
			}
			break;
		case ast::expr::LiteralType::eDouble:
			{
				auto v = expr->getValue< ast::expr::LiteralType::eDouble >();
				stream << std::setprecision( 12u ) << v;

				if ( v == int64_t( v ) )
				{
					stream << ".0";
				}
			}
			break;
		default:
			assert( false && "Unsupported literal type" );
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

	void ExprVisitor::visitSwitchCaseExpr( ast::expr::SwitchCase *expr )
	{
		expr->getLabel()->accept( this );
	}

	void ExprVisitor::visitSwitchTestExpr( ast::expr::SwitchTest *expr )
	{
		expr->getValue()->accept( this );
	}

	void ExprVisitor::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		wrap( expr->getOuterExpr() );
		m_result += "." + getName( expr->getSwizzle() );
	}

	void ExprVisitor::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		m_result += getGlslName( expr->getTextureAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			arg->accept( this );
			sep = ", ";
		}

		m_result += ")";
	}
}
