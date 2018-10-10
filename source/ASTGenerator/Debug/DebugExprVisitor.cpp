/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugExprVisitor.hpp"

#include "ASTGenerator/Var/Variable.hpp"

#include <sstream>

namespace ast
{
	namespace
	{
		std::string getTypeName( Type type )
		{
			std::string result;

			switch ( type )
			{
			case Type::eUndefined:
				result = "undefined";
				break;
			case Type::eFunction:
				result = "function";
				break;
			case Type::eBoolean:
				result = "bool";
				break;
			case Type::eInt:
				result = "int";
				break;
			case Type::eUInt:
				result = "uint";
				break;
			case Type::eFloat:
				result = "float";
				break;
			case Type::eVec2B:
				result = "bvec2";
				break;
			case Type::eVec3B:
				result = "bvec3";
				break;
			case Type::eVec4B:
				result = "bvec4";
				break;
			case Type::eVec2I:
				result = "ivec2";
				break;
			case Type::eVec3I:
				result = "ivec3";
				break;
			case Type::eVec4I:
				result = "ivec4";
				break;
			case Type::eVec2UI:
				result = "uivec2";
				break;
			case Type::eVec3UI:
				result = "uivec3";
				break;
			case Type::eVec4UI:
				result = "uivec4";
				break;
			case Type::eVec2F:
				result = "vec2";
				break;
			case Type::eVec3F:
				result = "vec3";
				break;
			case Type::eVec4F:
				result = "vec4";
				break;
			case Type::eMat2x2B:
				result = "bmat2";
				break;
			case Type::eMat3x3B:
				result = "bmat3";
				break;
			case Type::eMat4x4B:
				result = "bmat4";
				break;
			case Type::eMat2x2I:
				result = "imat2";
				break;
			case Type::eMat3x3I:
				result = "imat3";
				break;
			case Type::eMat4x4I:
				result = "imat4";
				break;
			case Type::eMat2x2UI:
				result = "uimat2";
				break;
			case Type::eMat3x3UI:
				result = "uimat3";
				break;
			case Type::eMat4x4UI:
				result = "uimat4";
				break;
			case Type::eMat2x2F:
				result = "mat2";
				break;
			case Type::eMat3x3F:
				result = "mat3";
				break;
			case Type::eMat4x4F:
				result = "mat4";
				break;
			case Type::eConstantsBuffer:
				result = "uniform";
				break;
			case Type::eShaderBuffer:
				result = "buffer";
				break;
			case Type::eSamplerBuffer:
				result = "samplerBuffer";
				break;
			case Type::eSampler1D:
				result = "sampler1D";
				break;
			case Type::eSampler2D:
				result = "sampler2D";
				break;
			case Type::eSampler3D:
				result = "sampler3D";
				break;
			case Type::eSamplerCube:
				result = "samplerCube";
				break;
			case Type::eSampler2DRect:
				result = "sampler2DRect";
				break;
			case Type::eSampler1DArray:
				result = "sampler1DArray";
				break;
			case Type::eSampler2DArray:
				result = "sampler2DArray";
				break;
			case Type::eSamplerCubeArray:
				result = "samplerCubeArray";
				break;
			case Type::eSampler1DShadow:
				result = "sampler1DShadow";
				break;
			case Type::eSampler2DShadow:
				result = "sampler2DShadow";
				break;
			case Type::eSamplerCubeShadow:
				result = "samplerCubeShadow";
				break;
			case Type::eSampler2DRectShadow:
				result = "sampler2DRectArrayShadow";
				break;
			case Type::eSampler1DArrayShadow:
				result = "sampler1DArrayShadow";
				break;
			case Type::eSampler2DArrayShadow:
				result = "sampler2DArrayShadow";
				break;
			case Type::eSamplerCubeArrayShadow:
				result = "samplerCubeArrayShadow";
				break;
			}

			return result;
		}

		std::string getOperatorName( Expr::Kind kind )
		{
			std::string result;

			switch ( kind )
			{
			case Expr::Kind::eAdd:
				result = "+";
				break;
			case Expr::Kind::eMinus:
				result = "-";
				break;
			case Expr::Kind::eTimes:
				result = "*";
				break;
			case Expr::Kind::eDivide:
				result = "/";
				break;
			case Expr::Kind::eModulo:
				result = "%";
				break;
			case Expr::Kind::eLShift:
				result = "<<";
				break;
			case Expr::Kind::eRShift:
				result = ">>";
				break;
			case Expr::Kind::eBitAnd:
				result = "&";
				break;
			case Expr::Kind::eBitNot:
				result = "~";
				break;
			case Expr::Kind::eBitOr:
				result = "|";
				break;
			case Expr::Kind::eBitXor:
				result = "^";
				break;
			case Expr::Kind::eLogAnd:
				result = "&&";
				break;
			case Expr::Kind::eLogNot:
				result = "!";
				break;
			case Expr::Kind::eLogOr:
				result = "||";
				break;
			case Expr::Kind::eCast:
				result = "cast";
				break;
			case Expr::Kind::eEqual:
				result = "==";
				break;
			case Expr::Kind::eGreater:
				result = ">";
				break;
			case Expr::Kind::eGreaterEqual:
				result = ">=";
				break;
			case Expr::Kind::eLess:
				result = "<";
				break;
			case Expr::Kind::eLessEqual:
				result = "<=";
				break;
			case Expr::Kind::eNotEqual:
				result = "!=";
				break;
			case Expr::Kind::eComma:
				result = ",";
				break;
			case Expr::Kind::eMbrSelect:
				result = ".";
				break;
			case Expr::Kind::ePreIncrement:
				result = "++";
				break;
			case Expr::Kind::ePreDecrement:
				result = "--";
				break;
			case Expr::Kind::ePostIncrement:
				result = "++";
				break;
			case Expr::Kind::ePostDecrement:
				result = "--";
				break;
			case Expr::Kind::eUnaryMinus:
				result = "-";
				break;
			case Expr::Kind::eUnaryPlus:
				result = "+";
				break;
			case Expr::Kind::eAssign:
				result = "=";
				break;
			case Expr::Kind::eAddAssign:
				result = "+=";
				break;
			case Expr::Kind::eMinusAssign:
				result = "-=";
				break;
			case Expr::Kind::eTimesAssign:
				result = "*=";
				break;
			case Expr::Kind::eDivideAssign:
				result = "/=";
				break;
			case Expr::Kind::eModuloAssign:
				result = "%=";
				break;
			case Expr::Kind::eLShiftAssign:
				result = "<<=";
				break;
			case Expr::Kind::eRShiftAssign:
				result = ">>=";
				break;
			case Expr::Kind::eAndAssign:
				result = "&=";
				break;
			case Expr::Kind::eNotAssign:
				result = "!=";
				break;
			case Expr::Kind::eOrAssign:
				result = "|=";
				break;
			case Expr::Kind::eXorAssign:
				result = "^=";
				break;
			default:
				throw std::runtime_error{ "Non operatin expression" };
			}

			return result;
		}

		bool isUnaryPre( Expr::Kind kind )
		{
			bool result;

			switch ( kind )
			{
			case Expr::Kind::eMbrSelect:
			case Expr::Kind::ePostIncrement:
			case Expr::Kind::ePostDecrement:
				result = false;
				break;
			case Expr::Kind::eBitNot:
			case Expr::Kind::eLogNot:
			case Expr::Kind::eCast:
			case Expr::Kind::ePreIncrement:
			case Expr::Kind::ePreDecrement:
			case Expr::Kind::eUnaryMinus:
			case Expr::Kind::eUnaryPlus:
				result = true;
				break;
			default:
				throw std::runtime_error{ "Non unary expression" };
			}

			return result;
		}
	}

	DebugExprVisitor::DebugExprVisitor( std::string & result )
		: m_result{ result }
	{
	}

	std::string DebugExprVisitor::submit( Expr * expr )
	{
		std::string result;
		DebugExprVisitor vis{ result };
		expr->accept( &vis );
		return result;
	}

	void DebugExprVisitor::visitUnaryExpr( ExprUnary * expr )
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

	void DebugExprVisitor::visitBinaryExpr( ExprBinary * expr )
	{
		m_result += "(";
		expr->getLHS()->accept( this );
		m_result += ") " + getOperatorName( expr->getKind() ) + " (";
		expr->getRHS()->accept( this );
		m_result += ")";
	}

	void DebugExprVisitor::visitCastExpr( ExprCast * expr )
	{
		m_result += getTypeName( expr->getType() ) + "(";
		expr->getOperand()->accept( this );
		m_result += ")";
	}

	void DebugExprVisitor::visitMbrSelectExpr( ExprMbrSelect * expr )
	{
		m_result += expr->getOuterVar().getName() + ".";
		expr->getOperand()->accept( this );
	}

	void DebugExprVisitor::visitFnCallExpr( ExprFnCall * expr )
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

	void DebugExprVisitor::visitIdentifierExpr( ExprIdentifier * expr )
	{
		m_result += expr->getVariable()->getName();
	}

	void DebugExprVisitor::visitInitExpr( ExprInit * expr )
	{
		m_result += getTypeName( expr->getType() ) + " ";
		expr->getIdentifier()->accept( this );
		m_result += " = ";
		expr->getInitialiser()->accept( this );
	}

	void DebugExprVisitor::visitLiteralExpr( ExprLiteral * expr )
	{
		std::locale loc{ "C" };
		std::stringstream stream;
		stream.imbue( loc );

		switch ( expr->getValueType() )
		{
		case ExprLiteral::ValueType::eBool:
			stream << ( expr->getValue< ExprLiteral::ValueType::eBool >()
				? std::string{ "true" }
				: std::string{ "false" } );
			break;
		case ExprLiteral::ValueType::eInt:
			stream << expr->getValue< ExprLiteral::ValueType::eInt >();
			break;
		case ExprLiteral::ValueType::eUInt:
			stream << expr->getValue< ExprLiteral::ValueType::eUInt >();
			break;
		case ExprLiteral::ValueType::eFloat:
			stream << expr->getValue< ExprLiteral::ValueType::eFloat >();
			break;
		}

		m_result += stream.str();
	}

	void DebugExprVisitor::visitQuestionExpr( ExprQuestion *expr )
	{
		m_result += "((";
		expr->getCtrlExpr()->accept( this );
		m_result += ") ? (";
		expr->getTrueExpr()->accept( this );
		m_result += ") : (";
		expr->getFalseExpr()->accept( this ); 
		m_result += "))";
	}

	void DebugExprVisitor::visitSwitchCaseExpr( ExprSwitchCase *expr )
	{
		expr->getLabel()->accept( this );
	}

	void DebugExprVisitor::visitSwitchTestExpr( ExprSwitchTest *expr )
	{
		expr->getValue()->accept( this );
	}
}
