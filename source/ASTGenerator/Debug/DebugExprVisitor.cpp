/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugExprVisitor.hpp"

#include "ASTGenerator/Debug/DebugCommon.hpp"
#include "ASTGenerator/Var/Variable.hpp"

#include <sstream>

namespace ast::debug
{
	ExprVisitor::ExprVisitor( std::string & result )
		: m_result{ result }
	{
	}

	std::string ExprVisitor::submit( expr::Expr * expr )
	{
		std::string result;
		ExprVisitor vis{ result };
		expr->accept( &vis );
		return result;
	}

	void ExprVisitor::wrap( expr::Expr * expr )
	{
		bool noParen = expr->getKind() == expr::Kind::eFnCall
			|| expr->getKind() == expr::Kind::eIdentifier
			|| expr->getKind() == expr::Kind::eLiteral
			|| expr->getKind() == expr::Kind::eMbrSelect;

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

	void ExprVisitor::visitUnaryExpr( expr::Unary * expr )
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

	void ExprVisitor::visitBinaryExpr( expr::Binary * expr )
	{
		wrap( expr->getLHS() );
		m_result += " " + getOperatorName( expr->getKind() ) + " ";
		wrap( expr->getRHS() );
	}

	void ExprVisitor::visitAssignmentExpr( expr::Binary * expr )
	{
		wrap( expr->getLHS() );
		m_result += " " + getOperatorName( expr->getKind() ) + " ";
		expr->getRHS()->accept( this );
	}

	void ExprVisitor::visitAddAssignExpr( expr::AddAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitAndAssignExpr( expr::AndAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitAssignExpr( expr::Assign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitDivideAssignExpr( expr::DivideAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitLShiftAssignExpr( expr::LShiftAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitMinusAssignExpr( expr::MinusAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitModuloAssignExpr( expr::ModuloAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitOrAssignExpr( expr::OrAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitRShiftAssignExpr( expr::RShiftAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitTimesAssignExpr( expr::TimesAssign * expr )
	{
		visitAssignmentExpr( expr );
	}
	void ExprVisitor::visitXorAssignExpr( expr::XorAssign * expr )
	{
		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitAggrInitExpr( expr::AggrInit * expr )
	{
		m_result += getTypeName( expr->getType() ) + " ";
		expr->getIdentifier()->accept( this );
		auto arraySize = expr->getIdentifier()->getType()->getArraySize();

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				m_result += "[]";
			}
			else
			{
				m_result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		m_result += " = " + getTypeName( expr->getType() ) + "[](";
		std::string sep;

		for ( auto & init : expr->getInitialisers() )
		{
			m_result += sep + submit( init.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitArrayAccessExpr( expr::ArrayAccess * expr )
	{
		wrap( expr->getLHS() );
		m_result += "[";
		wrap( expr->getRHS() );
		m_result += "]";
	}

	void ExprVisitor::visitCastExpr( expr::Cast * expr )
	{
		m_result += getTypeName( expr->getType() ) + "(";
		expr->getOperand()->accept( this );
		m_result += ")";
	}

	void ExprVisitor::visitMbrSelectExpr( expr::MbrSelect * expr )
	{
		wrap( expr->getOuterExpr() );
		m_result += ".";
		expr->getOperand()->accept( this );
	}

	void ExprVisitor::visitFnCallExpr( expr::FnCall * expr )
	{
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

	void ExprVisitor::visitIdentifierExpr( expr::Identifier * expr )
	{
		m_result += expr->getVariable()->getName();
	}

	void ExprVisitor::visitInitExpr( expr::Init * expr )
	{
		m_result += getTypeName( expr->getType() ) + " ";
		expr->getIdentifier()->accept( this );
		auto arraySize = expr->getIdentifier()->getType()->getArraySize();

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				m_result += "[]";
			}
			else
			{
				m_result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		m_result += " = ";
		expr->getInitialiser()->accept( this );
	}

	void ExprVisitor::visitLiteralExpr( expr::Literal * expr )
	{
		std::locale loc{ "C" };
		std::stringstream stream;
		stream.imbue( loc );

		switch ( expr->getValue() )
		{
		case expr::Literal::ValueType::eBool:
			stream << ( expr->getValue< expr::Literal::ValueType::eBool >()
				? std::string{ "true" }
				: std::string{ "false" } );
			break;
		case expr::Literal::ValueType::eInt:
			stream << expr->getValue< expr::Literal::ValueType::eInt >();
			break;
		case expr::Literal::ValueType::eUInt:
			stream << expr->getValue< expr::Literal::ValueType::eUInt >() << "u";
			break;
		case expr::Literal::ValueType::eFloat:
			{
				float f = expr->getValue< expr::Literal::ValueType::eFloat >();
				stream << f;

				if ( f == int64_t( f ) )
				{
					stream << ".0";
				}
			}
			break;
		}

		m_result += stream.str();
	}

	void ExprVisitor::visitQuestionExpr( expr::Question *expr )
	{
		m_result += "(";
		wrap( expr->getCtrlExpr() );
		m_result += " ? ";
		wrap( expr->getTrueExpr() );
		m_result += " : ";
		wrap( expr->getFalseExpr() );
		m_result += ")";
	}

	void ExprVisitor::visitSwitchCaseExpr( expr::SwitchCase *expr )
	{
		expr->getLabel()->accept( this );
	}

	void ExprVisitor::visitSwitchTestExpr( expr::SwitchTest *expr )
	{
		expr->getValue()->accept( this );
	}
}
