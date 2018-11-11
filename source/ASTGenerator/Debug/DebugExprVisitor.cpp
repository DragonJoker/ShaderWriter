/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugExprVisitor.hpp"

#include "ASTGenerator/Debug/DebugCommon.hpp"
#include "ASTGenerator/Var/Variable.hpp"

#include "ASTGenerator/Expr/GetImageAccessName.hpp"
#include "ASTGenerator/Expr/GetIntrinsicName.hpp"
#include "ASTGenerator/Expr/GetTextureAccessName.hpp"

#include <sstream>

namespace ast::debug
{
	namespace
	{
		std::string getName( expr::Kind kind )
		{
			std::string result;

			switch ( kind )
			{
			case expr::Kind::eAdd:
				result = "ADD";
				break;
			case expr::Kind::eMinus:
				result = "MINUS";
				break;
			case expr::Kind::eTimes:
				result = "TIMES";
				break;
			case expr::Kind::eDivide:
				result = "DIVIDE";
				break;
			case expr::Kind::eModulo:
				result = "MODULO";
				break;
			case expr::Kind::eLShift:
				result = "LSHIFT";
				break;
			case expr::Kind::eRShift:
				result = "RSHIFT";
				break;
			case expr::Kind::eBitAnd:
				result = "BITAND";
				break;
			case expr::Kind::eBitNot:
				result = "BITNOT";
				break;
			case expr::Kind::eBitOr:
				result = "BITOR";
				break;
			case expr::Kind::eBitXor:
				result = "BITXOR";
				break;
			case expr::Kind::eLogAnd:
				result = "LOGAND";
				break;
			case expr::Kind::eLogNot:
				result = "LOGNOT";
				break;
			case expr::Kind::eLogOr:
				result = "LOGOR";
				break;
			case expr::Kind::eCast:
				result = "CAST";
				break;
			case expr::Kind::eInit:
				result = "INIT";
				break;
			case expr::Kind::eAggrInit:
				result = "AGGRINIT";
				break;
			case expr::Kind::eFnCall:
				result = "FNCALL";
				break;
			case expr::Kind::eIntrinsicCall:
				result = "INTRCALL";
				break;
			case expr::Kind::eTextureAccessCall:
				result = "TEXINTRCALL";
				break;
			case expr::Kind::eImageAccessCall:
				result = "IMGINTRCALL";
				break;
			case expr::Kind::eEqual:
				result = "EQUAL";
				break;
			case expr::Kind::eGreater:
				result = "GREATER";
				break;
			case expr::Kind::eGreaterEqual:
				result = "GEQUAL";
				break;
			case expr::Kind::eLess:
				result = "LESS";
				break;
			case expr::Kind::eLessEqual:
				result = "LEQUAL";
				break;
			case expr::Kind::eNotEqual:
				result = "NEQUAL";
				break;
			case expr::Kind::eComma:
				result = "COMMA";
				break;
			case expr::Kind::eIdentifier:
				result = "IDENT";
				break;
			case expr::Kind::eLiteral:
				result = "LITERAL";
				break;
			case expr::Kind::eMbrSelect:
				result = "MBRSELECT";
				break;
			case expr::Kind::eSwizzle:
				result = "SWIZZLE";
				break;
			case expr::Kind::eSwitchTest:
				result = "SWTEST";
				break;
			case expr::Kind::eSwitchCase:
				result = "SWCASE";
				break;
			case expr::Kind::eQuestion:
				result = "QUESTION";
				break;
			case expr::Kind::ePreIncrement:
				result = "PREINC";
				break;
			case expr::Kind::ePreDecrement:
				result = "PREDEC";
				break;
			case expr::Kind::ePostIncrement:
				result = "POSTINC";
				break;
			case expr::Kind::ePostDecrement:
				result = "POSTDEC";
				break;
			case expr::Kind::eUnaryMinus:
				result = "UNMINUS";
				break;
			case expr::Kind::eUnaryPlus:
				result = "UNPLUS";
				break;
			case expr::Kind::eAssign:
				result = "ASSIGN";
				break;
			case expr::Kind::eAddAssign:
				result = "ADDASSIGN";
				break;
			case expr::Kind::eMinusAssign:
				result = "MINUSASSIGN";
				break;
			case expr::Kind::eTimesAssign:
				result = "TIMESASSIGN";
				break;
			case expr::Kind::eDivideAssign:
				result = "DIVIDEASSIGN";
				break;
			case expr::Kind::eModuloAssign:
				result = "MODULOASSIGN";
				break;
			case expr::Kind::eLShiftAssign:
				result = "LSHIFTASSIGN";
				break;
			case expr::Kind::eRShiftAssign:
				result = "RSHIFTASSIGN";
				break;
			case expr::Kind::eAndAssign:
				result = "ANDASSIGN";
				break;
			case expr::Kind::eNotAssign:
				result = "NOTASSIGN";
				break;
			case expr::Kind::eOrAssign:
				result = "ORASSIGN";
				break;
			case expr::Kind::eXorAssign:
				result = "XORASSIGN";
				break;
			case expr::Kind::eArrayAccess:
				result = "ARRAYACCESS";
				break;
			default:
				throw std::runtime_error{ "Non operation expression" };
			}

			return result;
		}
	}

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
		m_result += "(";
		expr->accept( this );
		m_result += ")";
	}

	void ExprVisitor::visitUnaryExpr( expr::Unary * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getOperand() );
	}

	void ExprVisitor::visitBinaryExpr( expr::Binary * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getLHS() );
		m_result += " ";
		wrap( expr->getRHS() );
	}

	void ExprVisitor::visitAggrInitExpr( expr::AggrInit * expr )
	{
		m_result += getName( expr->getKind() ) + " ";

		if ( expr->getIdentifier() )
		{
			wrap( expr->getIdentifier() );
		}

		m_result += " (";
		std::string sep;

		for ( auto & init : expr->getInitialisers() )
		{
			m_result += sep + submit( init.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitCastExpr( expr::Cast * expr )
	{
		m_result += getName( expr->getKind() ) + "(";
		m_result += getName( expr->getType() ) + ") ";
		wrap( expr->getOperand() );
	}

	void ExprVisitor::visitMbrSelectExpr( expr::MbrSelect * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getOuterExpr() );
		m_result += " ";
		wrap( expr->getOperand() );
	}

	void ExprVisitor::visitFnCallExpr( expr::FnCall * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getFn() );
		m_result += " (";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			wrap( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitIntrinsicCallExpr( expr::IntrinsicCall * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		m_result += getName( expr->getIntrinsic() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			wrap( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		m_result += getName( expr->getTextureAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			wrap( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitImageAccessCallExpr( expr::ImageAccessCall * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		m_result += getName( expr->getImageAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			wrap( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::visitIdentifierExpr( expr::Identifier * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		m_result += expr->getVariable()->getName();
	}

	void ExprVisitor::visitInitExpr( expr::Init * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getIdentifier() );
		m_result += " ";
		wrap( expr->getInitialiser() );
	}

	void ExprVisitor::visitLiteralExpr( expr::Literal * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		std::locale loc{ "C" };
		std::stringstream stream;
		stream.imbue( loc );

		switch ( expr->getLiteralType() )
		{
		case expr::LiteralType::eBool:
			stream << ( expr->getValue< expr::LiteralType::eBool >()
				? std::string{ "true" }
				: std::string{ "false" } );
			break;
		case expr::LiteralType::eInt:
			stream << expr->getValue< expr::LiteralType::eInt >();
			break;
		case expr::LiteralType::eUInt:
			stream << expr->getValue< expr::LiteralType::eUInt >() << "u";
			break;
		case expr::LiteralType::eFloat:
			{
				auto v = expr->getValue< expr::LiteralType::eFloat >();
				stream << v;

				if ( v == int64_t( v ) )
				{
					stream << ".0";
				}
			}
			break;
		case expr::LiteralType::eDouble:
			{
				auto v = expr->getValue< expr::LiteralType::eDouble >();
				stream << v;

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

	void ExprVisitor::visitQuestionExpr( expr::Question *expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getCtrlExpr() );
		m_result += " ";
		wrap( expr->getTrueExpr() );
		m_result += " ";
		wrap( expr->getFalseExpr() );
	}

	void ExprVisitor::visitSwitchCaseExpr( expr::SwitchCase *expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getLabel() );
	}

	void ExprVisitor::visitSwitchTestExpr( expr::SwitchTest *expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		wrap( expr->getValue() );
	}

	void ExprVisitor::visitSwizzleExpr( expr::Swizzle * expr )
	{
		m_result += getName( expr->getKind() ) + " ";
		m_result += getName( expr->getSwizzle() ) + " ";
		wrap( expr->getOuterExpr() );
	}
}
