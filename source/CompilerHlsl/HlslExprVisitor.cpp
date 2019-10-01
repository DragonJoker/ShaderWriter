/*
See LICENSE file in root folder
*/
#include "HlslExprVisitor.hpp"

#include "HlslImageAccessNames.hpp"
#include "HlslIntrinsicNames.hpp"
#include "HlslTextureAccessNames.hpp"

#include <iomanip>
#include <sstream>

namespace hlsl
{
	std::string ExprVisitor::submit( ast::expr::Expr * expr )
	{
		std::string result;
		ExprVisitor vis{ result };
		expr->accept( &vis );
		return result;
	}

	ExprVisitor::ExprVisitor( std::string & result )
		: m_result{ result }
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
			|| expr->getKind() == ast::expr::Kind::eArrayAccess
			|| expr->getKind() == ast::expr::Kind::eIntrinsicCall
			|| expr->getKind() == ast::expr::Kind::eTextureAccessCall
			|| expr->getKind() == ast::expr::Kind::eImageAccessCall
			|| expr->getKind() == ast::expr::Kind::eUnaryMinus
			|| expr->getKind() == ast::expr::Kind::eUnaryPlus;

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
			if ( expr->isConstant() )
			{
				m_result += "static const ";
			}

			m_result += getTypeName( expr->getType() ) + " ";
			expr->getIdentifier()->accept( this );
			m_result += getTypeArraySize( expr->getIdentifier()->getType() );
			m_result += " = ";
		}
		else
		{
			m_result += getTypeName( expr->getType() );
			m_result += getTypeArraySize( expr->getType() );
		}

		m_result += "{";
		std::string sep;

		for ( auto & init : expr->getInitialisers() )
		{
			m_result += sep + submit( init.get() );
			sep = ", ";
		}

		m_result += "}";
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
		m_result += "((" + getTypeName( expr->getType() ) + ")(";
		expr->getOperand()->accept( this );
		m_result += "))";
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
		//if ( expr->getVariable()->isMember() 
		//	&& getOutermost( expr->getVariable() )->isUniform() )
		//{
		//	auto result = expr->getVariable()->getName();
		//	auto outer = expr->getVariable()->getOuter();

		//	while ( outer )
		//	{
		//		result = outer->getName() + "." + result;
		//		outer = outer->getOuter();
		//	}

		//	m_result += result;
		//}
		//else
		{
			m_result += expr->getVariable()->getName();
		}
	}

	void ExprVisitor::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		if ( expr->getImageAccess() < ast::expr::ImageAccess::eImageLoad1DF
			|| expr->getImageAccess() > ast::expr::ImageAccess::eImageLoad2DMSArrayU )
		{
			m_result += getHlslName( expr->getImageAccess() ) + "(";
			std::string sep;

			for ( auto & arg : expr->getArgList() )
			{
				m_result += sep;
				arg->accept( this );
				sep = ", ";
			}

			m_result += ")";
		}
		else
		{
			expr->getArgList()[0]->accept( this );
			m_result += "." + getHlslName( expr->getImageAccess() ) + "(";
			expr->getArgList()[1]->accept( this );

			for ( size_t i = 2; i < expr->getArgList().size(); ++i )
			{
				auto & arg = expr->getArgList()[i];
				m_result += ", ";
				arg->accept( this );
			}

			m_result += ")";
		}
	}

	void ExprVisitor::visitInitExpr( ast::expr::Init * expr )
	{
		if ( expr->isConstant() )
		{
			m_result += "static const ";
		}

		m_result += getTypeName( expr->getType() ) + " ";
		expr->getIdentifier()->accept( this );
		m_result += getTypeArraySize( expr->getIdentifier()->getType() );
		m_result += " = ";
		expr->getInitialiser()->accept( this );
	}

	void ExprVisitor::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		m_result += getHlslName( expr->getIntrinsic() ) + "(";
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
				stream << std::setprecision( 12u ) << v;

				if ( v == int64_t( v )
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

				if ( v == int64_t( v )
					&& stream.str().find( 'e' ) == std::string::npos )
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
		if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureSize1DF
				&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayU )
		{
			doProcessNonMemberTexture( expr );
		}
		else if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureGather2DF
				&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp )
		{
			doProcessTextureGather( expr );
		}
		else
		{
			doProcessMemberTexture( expr );
		}
	}

	void ExprVisitor::doProcessMemberTexture( ast::expr::TextureAccessCall * expr )
	{
		expr->getArgList()[0]->accept( this );
		m_result += "." + getHlslName( expr->getTextureAccess() ) + "(";
		expr->getArgList()[1]->accept( this );

		for ( size_t i = 2; i < expr->getArgList().size(); ++i )
		{
			auto & arg = expr->getArgList()[i];
			m_result += ", ";
			arg->accept( this );
		}

		m_result += ")";
	}

	void ExprVisitor::doProcessNonMemberTexture( ast::expr::TextureAccessCall * expr )
	{
		m_result += getHlslName( expr->getTextureAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			arg->accept( this );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::doProcessTextureGather( ast::expr::TextureAccessCall * expr )
	{
		expr->getArgList()[0]->accept( this );
		uint32_t compValue = 0u;

		// Component value will determine Gather function name.
		auto component = expr->getArgList().back().get();

		if ( component->getKind() == ast::expr::Kind::eLiteral )
		{
			auto lit = static_cast< ast::expr::Literal const * >( component );

			if ( lit->getLiteralType() == ast::expr::LiteralType::eInt )
			{
				compValue = uint32_t( lit->getValue< ast::expr::LiteralType::eInt >() );
			}
			else
			{
				assert( lit->getLiteralType() == ast::expr::LiteralType::eUInt );
				compValue = lit->getValue< ast::expr::LiteralType::eUInt >();
			}
		}

		auto name = getHlslName( expr->getTextureAccess() );

		switch ( compValue )
		{
		case 0:
			name = "GatherRed";
			break;
		case 1:
			name = "GatherGreen";
			break;
		case 2:
			name = "GatherBlue";
			break;
		case 3:
			name = "GatherAlpha";
			break;
		}

		m_result += "." + name + "(";
		// Sampler
		expr->getArgList()[1]->accept( this );
		// Coord
		m_result += ", ";
		expr->getArgList()[2]->accept( this );

		for ( size_t i = 3u; i < expr->getArgList().size() - 1u; ++i )
		{
			auto & arg = expr->getArgList()[i];
			m_result += ", ";
			arg->accept( this );
		}

		m_result += ")";
	}
}
