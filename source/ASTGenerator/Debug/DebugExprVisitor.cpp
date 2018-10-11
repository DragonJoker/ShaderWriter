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

	void ExprVisitor::visitUnaryExpr( expr::Unary * expr )
	{
		if ( isUnaryPre( expr->getKind() ) )
		{
			m_result += getOperatorName( expr->getKind() ) + "(";
			expr->getOperand()->accept( this );
			m_result += ")";
		}
		else
		{
			m_result += "(";
			expr->getOperand()->accept( this );
			m_result += ")" + getOperatorName( expr->getKind() );
		}
	}

	void ExprVisitor::visitBinaryExpr( expr::Binary * expr )
	{
		m_result += "(";
		expr->getLHS()->accept( this );
		m_result += ") " + getOperatorName( expr->getKind() ) + " (";
		expr->getRHS()->accept( this );
		m_result += ")";
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
		m_result += "(";
		expr->getLHS()->accept( this );
		m_result += ") [";
		expr->getRHS()->accept( this );
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
		m_result += "(";
		expr->getOuterExpr()->accept( this );
		m_result += ").";
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
		m_result += expr->getVariable()->getTypeName();
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
			stream << expr->getValue< expr::Literal::ValueType::eUInt >();
			break;
		case expr::Literal::ValueType::eFloat:
			stream << expr->getValue< expr::Literal::ValueType::eFloat >();
			break;
		}

		m_result += stream.str();
	}

	void ExprVisitor::visitQuestionExpr( expr::Question *expr )
	{
		m_result += "((";
		expr->getCtrlExpr()->accept( this );
		m_result += ") ? (";
		expr->getTrueExpr()->accept( this );
		m_result += ") : (";
		expr->getFalseExpr()->accept( this ); 
		m_result += "))";
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
