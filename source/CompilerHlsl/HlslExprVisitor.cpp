/*
See LICENSE file in root folder
*/
#include "HlslExprVisitor.hpp"

#include "HlslIntrinsicNames.hpp"
#include "HlslStorageImageAccessNames.hpp"
#include "HlslCombinedImageAccessNames.hpp"

#include <cmath>
#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <iomanip>
#include <sstream>
#pragma warning( pop )

#pragma GCC diagnostic ignored "-Wrestrict"

namespace hlsl
{
	namespace
	{
		std::string removeSemantics( std::string const & name )
		{
			auto it = name.find_last_of( ":" );

			if ( it != std::string::npos )
			{
				return name.substr( 0, it );
			}

			return name;
		}

		bool isNonMatchingOuterProduct( ast::expr::Intrinsic value )
		{
			return value == ast::expr::Intrinsic::eOuterProduct2x3F
				|| value == ast::expr::Intrinsic::eOuterProduct2x4F
				|| value == ast::expr::Intrinsic::eOuterProduct3x2F
				|| value == ast::expr::Intrinsic::eOuterProduct3x4F
				|| value == ast::expr::Intrinsic::eOuterProduct4x2F
				|| value == ast::expr::Intrinsic::eOuterProduct4x3F
				|| value == ast::expr::Intrinsic::eOuterProduct2x3D
				|| value == ast::expr::Intrinsic::eOuterProduct2x4D
				|| value == ast::expr::Intrinsic::eOuterProduct3x2D
				|| value == ast::expr::Intrinsic::eOuterProduct3x4D
				|| value == ast::expr::Intrinsic::eOuterProduct4x2D
				|| value == ast::expr::Intrinsic::eOuterProduct4x3D;
		}
	}

	std::string ExprVisitor::submit( ast::expr::Expr * expr
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases )
	{
		std::string result;
		ExprVisitor vis{ aliases, result };
		expr->accept( &vis );
		return result;
	}

	ExprVisitor::ExprVisitor( std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, std::string & result )
		: m_result{ result }
		, m_aliases{ aliases }
	{
	}

	std::string ExprVisitor::doSubmit( ast::expr::Expr * expr )
	{
		return submit( expr, m_aliases );
	}

	void ExprVisitor::wrap( ast::expr::Expr * expr )
	{
		bool noParen = expr->getKind() == ast::expr::Kind::eFnCall
			|| expr->getKind() == ast::expr::Kind::eAggrInit
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
			m_result += doSubmit( expr->getIdentifier() );
			m_result += getTypeArraySize( expr->getIdentifier()->getType() );
			m_result += " = ";
		}

		m_result += "{";
		std::string sep;

		for ( auto & init : expr->getInitialisers() )
		{
			m_result += sep + doSubmit( init.get() );
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
		m_result += doSubmit( expr->getOperand() );
		m_result += "))";
	}

	void ExprVisitor::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		assert( expr->getComposite() != ast::expr::CompositeType::eCombine
			&& "Unexpected combine() at this point" );
		m_result += getCtorName( expr->getComposite(), getScalarType( expr->getComponent() ) ) + "(";
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
		m_result += ".";
		auto it = m_result.find( ".." );
		
		while ( it != std::string::npos )
		{
			m_result.replace( it, 2, "." );
			it = m_result.find( ".." );
		}

		m_result += adaptName( removeSemantics( expr->getOuterType()->getMember( expr->getMemberIndex() ).name ) );
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
			m_result += adaptName( expr->getVariable()->getName() );
		}
	}

	void ExprVisitor::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		if ( expr->getImageAccess() < ast::expr::StorageImageAccess::eImageLoad1DF
			|| expr->getImageAccess() > ast::expr::StorageImageAccess::eImageLoad2DMSArrayU )
		{
			m_result += getHlslName( expr->getImageAccess() ) + "(";
			std::string sep;

			for ( auto & arg : expr->getArgList() )
			{
				m_result += sep;
				m_result += doSubmit( arg.get() );
				sep = ", ";
			}

			m_result += ")";
		}
		else
		{
			m_result += doSubmit( expr->getArgList()[0].get() );
			m_result += "." + getHlslName( expr->getImageAccess() ) + "(";
			m_result += doSubmit( expr->getArgList()[1].get() );

			for ( size_t i = 2; i < expr->getArgList().size(); ++i )
			{
				auto & arg = expr->getArgList()[i];
				m_result += ", ";
				m_result += doSubmit( arg.get() );
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
		m_result += doSubmit( expr->getIdentifier() );
		m_result += getTypeArraySize( expr->getIdentifier()->getType() );
		m_result += " = ";
		m_result += doSubmit( expr->getInitialiser() );
	}

	void ExprVisitor::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		if ( expr->getIntrinsic() == ast::expr::Intrinsic::eEndPrimitive
			|| expr->getIntrinsic() == ast::expr::Intrinsic::eEmitStreamVertex
			|| expr->getIntrinsic() == ast::expr::Intrinsic::eEndStreamPrimitive )
		{
			auto & argsList = expr->getArgList();
			assert( argsList.size() >= 1u );
			std::vector< std::string > args;

			for ( auto & arg : argsList )
			{
				args.push_back( doSubmit( arg.get() ) );
			}

			auto mbrArg = std::move( args.front() );
			args.erase( args.begin() );

			m_result += mbrArg;
			m_result += "." + getHlslName( expr->getIntrinsic() ) + "(";
			std::string sep;

			for ( auto & arg : args )
			{
				m_result += sep;
				m_result += arg;
				sep = ", ";
			}

			m_result += ")";
		}
		else
		{
			if ( isNonMatchingOuterProduct( expr->getIntrinsic() ) )
			{
				m_result += "transpose(" + getHlslName( expr->getIntrinsic() ) + "(";
				auto lhs = doSubmit( expr->getArgList().front().get() );
				auto rhs = doSubmit( expr->getArgList().back().get() );

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x3F )
				{
					m_result += "float2x1(" + lhs + "), float1x3(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x4F )
				{
					m_result += "float2x1(" + lhs + "), float1x4(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x2F )
				{
					m_result += "float3x1(" + lhs + "), float1x2(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x4F )
				{
					m_result += "float3x1(" + lhs + "), float1x4(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x2F )
				{
					m_result += "float4x1(" + lhs + "), float1x2(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x3F )
				{
					m_result += "float4x1(" + lhs + "), float1x3(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x3D )
				{
					m_result += "double2x1(" + lhs + "), double1x3(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x4D )
				{
					m_result += "double2x1(" + lhs + "), double1x4(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x2D )
				{
					m_result += "double3x1(" + lhs + "), double1x2(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x4D )
				{
					m_result += "double3x1(" + lhs + "), double1x4(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x2D )
				{
					m_result += "double4x1(" + lhs + "), double1x2(" + rhs + ")";
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x3D )
				{
					m_result += "double4x1(" + lhs + "), double1x3(" + rhs + ")";
				}

				m_result += "))";
			}
			else
			{
				m_result += getHlslName( expr->getIntrinsic() ) + "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( arg.get() );
					sep = ", ";
				}

				m_result += ")";
			}
		}
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
			stream << expr->getValue< ast::expr::LiteralType::eInt32 >() << "l";
			break;
		case ast::expr::LiteralType::eInt64:
			stream << expr->getValue< ast::expr::LiteralType::eInt64 >() << "ll";
			break;
		case ast::expr::LiteralType::eUInt8:
			stream << "uint8_t(" << uint16_t( expr->getValue< ast::expr::LiteralType::eUInt8 >() ) << ")";
			break;
		case ast::expr::LiteralType::eUInt16:
			stream << "uint16_t(" << expr->getValue< ast::expr::LiteralType::eUInt16 >() << ")";
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
		assert( expr->getOperand()->getKind() == ast::expr::Kind::eComma );
		auto & commaExpr = static_cast< ast::expr::Comma const & >( *expr->getOperand() );

		m_result += doSubmit( commaExpr.getLHS() );
		m_result += "." + getHlslName( ast::expr::Intrinsic::eEmitVertex );
		m_result += "(" + doSubmit( commaExpr.getRHS() );
		m_result += ")";
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
		if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureSize1DF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU )
		{
			doProcessNonMemberTexture( expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGather2DF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectU )
		{
			doProcessTextureGather( expr );
		}
		else
		{
			doProcessMemberTexture( expr );
		}
	}

	void ExprVisitor::visitAliasExpr( ast::expr::Alias * expr )
	{
		// The alias var may have been turned to regular var, in adaptation.
		if ( expr->getLHS()->getVariable()->isAlias() )
		{
			m_aliases.emplace( expr->getLHS()->getVariable(), expr->getRHS() );
		}
		else
		{
			if ( expr->isConstant() )
			{
				m_result += "static const ";
			}

			m_result += getTypeName( expr->getType() ) + " ";
			m_result += doSubmit( expr->getLHS() );
			m_result += getTypeArraySize( expr->getLHS()->getType() );
			m_result += " = ";
			m_result += doSubmit( expr->getRHS() );
		}
	}

	void ExprVisitor::doProcessMemberTexture( ast::expr::CombinedImageAccessCall * expr )
	{
		m_result += doSubmit( expr->getArgList()[0].get() );
		m_result += "." + getHlslName( expr->getCombinedImageAccess() ) + "(";
		m_result += doSubmit( expr->getArgList()[1].get() );

		for ( size_t i = 2; i < expr->getArgList().size(); ++i )
		{
			auto & arg = expr->getArgList()[i];
			m_result += ", ";
			m_result += doSubmit( arg.get() );
		}

		m_result += ")";
	}

	void ExprVisitor::doProcessNonMemberTexture( ast::expr::CombinedImageAccessCall * expr )
	{
		m_result += getHlslName( expr->getCombinedImageAccess() ) + "(";
		std::string sep;

		for ( auto & arg : expr->getArgList() )
		{
			m_result += sep;
			m_result += doSubmit( arg.get() );
			sep = ", ";
		}

		m_result += ")";
	}

	void ExprVisitor::doProcessTextureGather( ast::expr::CombinedImageAccessCall * expr )
	{
		// Image
		m_result += doSubmit( expr->getArgList()[0].get() );
		uint32_t compValue = 0u;

		// Component value will determine Gather function name.
		auto component = expr->getArgList()[2].get();

		if ( component->getKind() == ast::expr::Kind::eLiteral )
		{
			auto lit = static_cast< ast::expr::Literal const * >( component );

			if ( lit->getLiteralType() == ast::expr::LiteralType::eInt32 )
			{
				compValue = uint32_t( lit->getValue< ast::expr::LiteralType::eInt32 >() );
			}
			else
			{
				assert( lit->getLiteralType() == ast::expr::LiteralType::eUInt32 );
				compValue = lit->getValue< ast::expr::LiteralType::eUInt32 >();
			}
		}

		auto name = getHlslName( expr->getCombinedImageAccess() );

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
		m_result += doSubmit( expr->getArgList()[1].get() );
		// Coord
		m_result += ", ";
		m_result += doSubmit( expr->getArgList()[3].get() );
		auto index = 4u;

		while ( index < expr->getArgList().size() )
		{
			auto & arg = expr->getArgList()[index];
			m_result += ", ";
			m_result += doSubmit( arg.get() );
			++index;
		}

		m_result += ")";
	}
}
