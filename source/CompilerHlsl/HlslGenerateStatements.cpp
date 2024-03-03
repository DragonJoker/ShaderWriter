/*
See LICENSE file in root folder
*/
#include "HlslGenerateStatements.hpp"

#include "HlslIntrinsicNames.hpp"
#include "HlslStorageImageAccessNames.hpp"
#include "HlslCombinedImageAccessNames.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>

#pragma warning( disable:4365 )
#pragma warning( disable:5262 )
#include <cmath>
#include <iomanip>
#include <sstream>

#pragma GCC diagnostic ignored "-Wrestrict"

namespace hlsl
{
	namespace vis
	{
		namespace helpers
		{
			static std::string removeSemantics( std::string const & name )
			{
				if ( auto it = name.find_last_of( ":" );
					it != std::string::npos )
				{
					return name.substr( 0, it );
				}

				return name;
			}

			static bool isNonMatchingOuterProduct( ast::expr::Intrinsic value )
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

			static std::string getName( ast::type::PatchDomain value )
			{
				switch ( value )
				{
				case ast::type::PatchDomain::eIsolines:
					return "isoline";
				case ast::type::PatchDomain::eTriangles:
					return "tri";
				case ast::type::PatchDomain::eQuads:
					return "quad";
				default:
					AST_Failure( "Unsupported type::PatchDomain." );
					return "undefined";
				}
			}

			static std::string getName( ast::type::Partitioning value )
			{
				switch ( value )
				{
				case ast::type::Partitioning::eEqual:
					return "integer";
				case ast::type::Partitioning::eFractionalEven:
					return "fractionaleven";
				case ast::type::Partitioning::eFractionalOdd:
					return "fractionalodd";
				default:
					AST_Failure( "Unsupported type::Partitioning." );
					return "undefined";
				}
			}

			static std::string getName( ast::type::OutputTopology domain
				, ast::type::PrimitiveOrdering order )
			{
				switch ( domain )
				{
				case ast::type::OutputTopology::ePoint:
					return "point";
				case ast::type::OutputTopology::eLine:
					return "line";
				case ast::type::OutputTopology::eTriangle:
					switch ( order )
					{
					case ast::type::PrimitiveOrdering::eCW:
						return "triangle_cw";
					case ast::type::PrimitiveOrdering::eCCW:
						return "triangle_ccw";
					default:
						AST_Failure( "Unsupported type::PrimitiveOrdering." );
						return "UNDEFINED";
					}
				default:
					AST_Failure( "Unsupported type::OutputTopology." );
					return "UNDEFINED";
				}
			}

			static std::string getName( ast::type::OutputTopology topology )
			{
				switch ( topology )
				{
				case ast::type::OutputTopology::ePoint:
					return "point";
				case ast::type::OutputTopology::eLine:
					return "line";
				case ast::type::OutputTopology::eTriangle:
					return "triangle";
				default:
					AST_Failure( "Unsupported type::OutputTopology." );
					return "UNDEFINED";
				}
			}

			static std::string writeIOMember( ast::ShaderStage stage
				, ast::type::TypePtr type
				, std::string const & name
				, ast::Builtin builtin
				, bool isInput
				, uint32_t builtinIndex
				, uint32_t location
				, Semantic & intSem
				, Semantic & fltSem )
			{
				auto & typesCache = type->getTypesCache();
				std::string semantic;

				if ( builtin == ast::Builtin::eClipDistance )
				{
					type = typesCache.getVec4F();
					semantic = ": SV_ClipDistance";

					if ( builtinIndex != ast::type::Struct::InvalidLocation )
					{
						semantic += std::to_string( builtinIndex );
					}
				}
				else if ( builtin == ast::Builtin::eCullDistance )
				{
					// Merged with SV_ClipDistance ?
				}
				else
				{
					if ( isSignedIntType( getNonArrayType( type )->getKind() )
						|| isUnsignedIntType( getNonArrayType( type )->getKind() ) )
					{
						semantic = ": " + getSemantic( stage, builtin, isInput, location, type, intSem );
					}
					else
					{
						semantic = ": " + getSemantic( stage, builtin, isInput, location, type, fltSem );
					}
				}

				if ( semantic.empty() )
				{
					return semantic;
				}

				std::string result;

				if ( isMeshStage( stage )
					&& ( builtin == ast::Builtin::ePrimitiveIndicesNV
						|| builtin == ast::Builtin::ePrimitivePointIndices
						|| builtin == ast::Builtin::ePrimitiveLineIndices
						|| builtin == ast::Builtin::ePrimitiveTriangleIndices ) )
				{
					result += "indices ";
				}

				result += getTypeName( type ) + " ";
				result += adaptName( name );
				result += getTypeArraySize( type );

				if ( builtin != ast::Builtin::ePrimitiveIndicesNV
					&& builtin != ast::Builtin::ePrimitivePointIndices
					&& builtin != ast::Builtin::ePrimitiveLineIndices
					&& builtin != ast::Builtin::ePrimitiveTriangleIndices )
				{
					result += semantic;
				}

				return result;
			}

			static std::string writeIOMember( ast::ShaderStage stage
				, ast::type::Struct::Member const & member
				, bool isInput
				, Semantic & intSem
				, Semantic & fltSem )
			{
				auto result = writeIOMember( stage
					, member.type
					, member.name
					, member.builtin
					, isInput
					, member.builtinIndex
					, member.location
					, intSem
					, fltSem );

				if ( !result.empty() )
				{
					result += ";\n";
				}

				return result;
			}

			static std::string writeIOMembers( ast::ShaderStage stage
				, std::string const & indent
				, ast::type::Struct const & structType )
			{
				Semantic rintSem = { "BLENDINDICES", 0u };
				Semantic rfltSem = { "TEXCOORD", 0u };
				Semantic * pintSem = &rintSem;
				Semantic * pfltSem = &rfltSem;
				std::string result;
				bool isInput = true;

				if ( structType.isShaderOutput() )
				{
					isInput = false;

					if ( stage == ast::ShaderStage::eFragment )
					{
						rintSem.name = "SV_Target";
						pfltSem = &rintSem;
					}
				}

				for ( auto & mbr : structType )
				{
					if ( mbr.builtin == ast::Builtin::eMeshViewIndicesNV
						|| mbr.builtin == ast::Builtin::eMeshViewCountNV
						|| mbr.builtin == ast::Builtin::ePrimitiveIndicesNV
						|| mbr.builtin == ast::Builtin::ePrimitivePointIndices
						|| mbr.builtin == ast::Builtin::ePrimitiveLineIndices
						|| mbr.builtin == ast::Builtin::ePrimitiveTriangleIndices )
					{
						continue;
					}

					auto member = writeIOMember( stage, mbr, isInput, *pintSem, *pfltSem );

					if ( !member.empty() )
					{
						result += indent + member;
					}
				}

				return result;
			}

			static std::string writeBaseMember( ast::type::Struct::Member const & member )
			{
				std::string result = getTypeName( member.type ) + " ";
				auto name = adaptName( member.name );

				if ( auto index = name.find( ":" );
					index != std::string::npos )
				{
					// There are semantics for this variable.
					name = name.substr( 0, index )
						+ getTypeArraySize( member.type )
						+ name.substr( index );
				}
				else
				{
					name += getTypeArraySize( member.type );
				}

				result += name + ";\n";
				return result;
			}

			static std::string writeBaseMembers( std::string const & indent
				, ast::type::Struct const & structType )
			{
				std::string result;

				for ( auto & mbr : structType )
				{
					result += indent + writeBaseMember( mbr );
				}

				return result;
			}

			static std::string writeMembers( ast::ShaderStage stage
				, std::string const & indent
				, ast::type::Struct const & structType )
			{
				if ( structType.isShaderInput()
					|| ( structType.isShaderOutput() && !structType.isPerTaskNV() && !structType.isPerTask() )
					|| structType.isPatchInput() )
				{
					return writeIOMembers( stage
						, indent
						, static_cast< ast::type::IOStruct const & >( structType ) );
				}

				return writeBaseMembers( indent, structType );
			}

			static std::string writeTessEvalIn( ast::type::TessellationInputPatch const & tesscType
				, std::string const & indent )
			{
				std::string result;
				result += indent + "[domain(\"" + getName( tesscType.getDomain() ) + "\")]\n";
				return result;
			}

			static std::string writeTessCtrlOut( ast::type::TessellationControlOutput const & tesscType
				, RoutineMap const & patchRoutines
				, std::string const & indent )
			{
				std::string result;
				result += indent + "[domain(\"" + getName( tesscType.getDomain() ) + "\")]\n";
				result += indent + "[partitioning(\"" + getName( tesscType.getPartitioning() ) + "\")]\n";
				result += indent + "[outputtopology(\"" + getName( tesscType.getTopology(), tesscType.getOrder() ) + "\")]\n";
				result += indent + "[outputcontrolpoints(" + std::to_string( tesscType.getOutputVertices() ) + ")]\n";

				if ( !patchRoutines.empty() )
				{
					auto rit = std::find_if( patchRoutines.begin()
						, patchRoutines.end()
						, []( auto & lookup )
						{
							return !lookup.second->isMain;
						} );

					if ( rit != patchRoutines.end() )
					{
						result += indent + "[patchconstantfunc(\"" + ( rit->first ) + "\")]\n";
					}
				}

				return result;
			}

			static std::string writeMeshPrimOut( RoutineMap const & routines
				, std::string const & indent )
			{
				auto it = std::find_if( routines.begin()
					, routines.end()
					, []( auto & lookup )
					{
						return lookup.second->isMain;
					} );
				std::string result;

				if ( it != routines.end() )
				{
					result += indent + "[outputtopology(\"" + getName( it->second->getOutputTopology() ) + "\")]\n";
				}

				return result;
			}

			static std::string printVersion( uint32_t major = MAIN_VERSION_MAJOR
				, uint32_t minor = MAIN_VERSION_MINOR
				, uint32_t build = MAIN_VERSION_BUILD
				, uint32_t year = MAIN_VERSION_YEAR )
			{
				std::stringstream stream;
				stream.imbue( std::locale{ "C" } );
				stream << major << "." << minor << "." << build << "-" << year;
				return stream.str();
			}
		}

		class ExprVisitor
			: public ast::expr::SimpleVisitor
		{
		public:
			static std::string submit( HlslConfig const & writerConfig
				, ast::expr::Expr const & expr
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases )
			{
				std::string result;
				ExprVisitor vis{ writerConfig, aliases, result };
				expr.accept( &vis );
				return result;
			}

		private:
			ExprVisitor( HlslConfig const & writerConfig
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
				, std::string & result )
				: m_writerConfig{ writerConfig }
				, m_result{ result }
				, m_aliases{ aliases }
			{
			}

			std::string doSubmit( ast::expr::Expr const & expr )
			{
				return submit( m_writerConfig, expr, m_aliases );
			}

			void wrap( ast::expr::Expr const & expr )
			{
				bool noParen = expr.getKind() == ast::expr::Kind::eFnCall
					|| expr.getKind() == ast::expr::Kind::eAggrInit
					|| expr.getKind() == ast::expr::Kind::eIdentifier
					|| expr.getKind() == ast::expr::Kind::eLiteral
					|| expr.getKind() == ast::expr::Kind::eMbrSelect
					|| expr.getKind() == ast::expr::Kind::eCast
					|| expr.getKind() == ast::expr::Kind::eSwizzle
					|| expr.getKind() == ast::expr::Kind::eArrayAccess
					|| expr.getKind() == ast::expr::Kind::eIntrinsicCall
					|| expr.getKind() == ast::expr::Kind::eCombinedImageAccessCall
					|| expr.getKind() == ast::expr::Kind::eImageAccessCall
					|| expr.getKind() == ast::expr::Kind::eUnaryMinus
					|| expr.getKind() == ast::expr::Kind::eUnaryPlus
					|| expr.getKind() == ast::expr::Kind::eCopy;

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

			void visitAssignmentExpr( ast::expr::Binary const & expr )
			{
				wrap( *expr.getLHS() );
				m_result += " " + getOperatorName( expr.getKind() ) + " ";
				m_result += doSubmit( *expr.getRHS() );
			}

			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				if ( isUnaryPre( expr->getKind() ) )
				{
					m_result += getOperatorName( expr->getKind() );
					wrap( *expr->getOperand() );
				}
				else
				{
					wrap( *expr->getOperand() );
					m_result += getOperatorName( expr->getKind() );
				}
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				wrap( *expr->getLHS() );
				m_result += " " + getOperatorName( expr->getKind() ) + " ";
				wrap( *expr->getRHS() );
			}

			void visitAddAssignExpr( ast::expr::AddAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitAndAssignExpr( ast::expr::AndAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitAssignExpr( ast::expr::Assign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitDivideAssignExpr( ast::expr::DivideAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitLShiftAssignExpr( ast::expr::LShiftAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitMinusAssignExpr( ast::expr::MinusAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitModuloAssignExpr( ast::expr::ModuloAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitOrAssignExpr( ast::expr::OrAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitRShiftAssignExpr( ast::expr::RShiftAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitTimesAssignExpr( ast::expr::TimesAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}
			void visitXorAssignExpr( ast::expr::XorAssign const * expr )override
			{
				visitAssignmentExpr( *expr );
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					if ( expr->isConstant() )
					{
						m_result += "static const ";
					}

					m_result += getTypeName( expr->getType() ) + " ";
					m_result += doSubmit( expr->getIdentifier() );
					m_result += getTypeArraySize( expr->getIdentifier().getType() );
					m_result += " = ";
				}

				m_result += "{";
				std::string sep;

				for ( auto & init : expr->getInitialisers() )
				{
					m_result += sep + doSubmit( *init );
					sep = ", ";
				}

				m_result += "}";
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
			{
				wrap( *expr->getLHS() );
				m_result += "[";
				wrap( *expr->getRHS() );
				m_result += "]";
			}

			void visitCastExpr( ast::expr::Cast const * expr )override
			{
				m_result += "((" + getTypeName( expr->getType() ) + ")(";
				m_result += doSubmit( *expr->getOperand() );
				m_result += "))";
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
			{
				assert( expr->getComposite() != ast::expr::CompositeType::eCombine
					&& "Unexpected combine() at this point" );
				m_result += getCtorName( expr->getComposite(), getScalarType( expr->getComponent() ) ) + "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( *arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				wrap( *expr->getOuterExpr() );
				m_result += ".";
				auto it = m_result.find( ".." );

				while ( it != std::string::npos )
				{
					m_result.replace( it, 2, "." );
					it = m_result.find( ".." );
				}

				m_result += adaptName( helpers::removeSemantics( expr->getOuterType()->getMember( expr->getMemberIndex() ).name ) );
			}

			void visitFnCallExpr( ast::expr::FnCall const * expr )override
			{
				if ( expr->isMember() )
				{
					wrap( *expr->getInstance() );
					m_result += ".";
				}

				m_result += doSubmit( *expr->getFn() );
				m_result += "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( *arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				auto it = m_aliases.find( expr->getVariable() );

				if ( it != m_aliases.end() )
				{
					wrap( *it->second );
				}
				else
				{
					m_result += adaptName( expr->getVariable()->getName() );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
			{
				if ( expr->getImageAccess() < ast::expr::StorageImageAccess::eImageLoad1DF
					|| expr->getImageAccess() > ast::expr::StorageImageAccess::eImageLoad2DMSArrayU )
				{
					m_result += getHlslName( expr->getImageAccess() ) + "(";
					std::string sep;

					for ( auto & arg : expr->getArgList() )
					{
						m_result += sep;
						m_result += doSubmit( *arg );
						sep = ", ";
					}

					m_result += ")";
				}
				else
				{
					m_result += doSubmit( *expr->getArgList()[0] );
					m_result += "." + getHlslName( expr->getImageAccess() ) + "(";
					m_result += doSubmit( *expr->getArgList()[1] );

					for ( size_t i = 2; i < expr->getArgList().size(); ++i )
					{
						auto & arg = expr->getArgList()[i];
						m_result += ", ";
						m_result += doSubmit( *arg );
					}

					m_result += ")";
				}
			}

			void visitInitExpr( ast::expr::Init const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					if ( expr->isConstant() )
					{
						m_result += "static const ";
					}

					m_result += getTypeName( expr->getType() ) + " ";
					m_result += doSubmit( expr->getIdentifier() );
					m_result += getTypeArraySize( expr->getIdentifier().getType() );
					m_result += " = ";
				}

				m_result += doSubmit( *expr->getInitialiser() );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
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
						args.push_back( doSubmit( *arg ) );
					}

					auto mbrArg = std::move( args.front() );
					args.erase( args.begin() );

					m_result += mbrArg;
					m_result += "." + getHlslName( expr->getIntrinsic() ) + "(";
					std::string sep;

					for ( auto const & arg : args )
					{
						m_result += sep;
						m_result += arg;
						sep = ", ";
					}

					m_result += ")";
				}
				else
				{
					if ( helpers::isNonMatchingOuterProduct( expr->getIntrinsic() ) )
					{
						doProcessNonMatchingOuterProduct( *expr );
					}
					else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier )
					{
						doProcessControlBarrier( *expr );
					}
					else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
					{
						doProcessMemoryBarrier( *expr );
					}
					else
					{
						m_result += getHlslName( expr->getIntrinsic() ) + "(";
						std::string sep;

						for ( auto & arg : expr->getArgList() )
						{
							m_result += sep;
							m_result += doSubmit( *arg );
							sep = ", ";
						}

						m_result += ")";
					}
				}
			}

			void visitLiteralExpr( ast::expr::Literal const * expr )override
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

			void visitQuestionExpr( ast::expr::Question const * expr )override
			{
				m_result += "(";
				wrap( *expr->getCtrlExpr() );
				m_result += " ? ";
				wrap( *expr->getTrueExpr() );
				m_result += " : ";
				wrap( *expr->getFalseExpr() );
				m_result += ")";
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
			{
				assert( expr->getOperand()->getKind() == ast::expr::Kind::eComma );
				auto & commaExpr = static_cast< ast::expr::Comma const & >( *expr->getOperand() );

				m_result += doSubmit( *commaExpr.getLHS() );
				m_result += "." + getHlslName( ast::expr::Intrinsic::eEmitVertex );
				m_result += "(" + doSubmit( *commaExpr.getRHS() );
				m_result += ")";
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
			{
				m_result += doSubmit( *expr->getLabel() );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
			{
				m_result += doSubmit( *expr->getValue() );
			}

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				wrap( *expr->getOuterExpr() );
				m_result += "." + getName( expr->getSwizzle() );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
			{
				if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureSize1DF
					&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU )
				{
					doProcessNonMemberTexture( *expr );
				}
				else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGather2DF
					&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU )
				{
					doProcessTextureGather( *expr );
				}
				else
				{
					doProcessMemberTexture( *expr );
				}
			}

			void visitAliasExpr( ast::expr::Alias const * expr )override
			{
				// The alias var may have been turned to regular var, in adaptation.
				if ( expr->hasIdentifier() )
				{
					if ( expr->getIdentifier().getVariable()->isAlias() )
					{
						m_aliases.try_emplace( expr->getIdentifier().getVariable(), expr->getAliasedExpr() );
					}
					else
					{
						if ( expr->isConstant() )
						{
							m_result += "static const ";
						}

						m_result += getTypeName( expr->getType() ) + " ";
						m_result += doSubmit( expr->getIdentifier() );
						m_result += getTypeArraySize( expr->getIdentifier().getType() );
						m_result += " = ";
						m_result += doSubmit( *expr->getAliasedExpr() );
					}
				}
				else
				{
					m_result += doSubmit( *expr->getAliasedExpr() );
				}
			}

			void doProcessControlBarrier( ast::expr::IntrinsicCall const & expr )
			{
				if ( expr.getArgList().size() < 3u )
				{
					throw ast::Exception{ "Wrong number of parameters for a control barrier" };
				}

				auto memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[1] ) );
				auto semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[2] ) );

				if ( m_writerConfig.shaderStage == ast::ShaderStage::eTessellationControl )
				{
					if ( memory == ast::type::Scope::eWorkgroup
						|| memory == ast::type::Scope::eSubgroup )
					{
						m_result += "GroupMemoryBarrier()";
					}
					else if ( ( semantics & ast::type::MemorySemanticsMask::eWorkgroupMemory ) == ast::type::MemorySemanticsMask::eWorkgroupMemory
						|| ( semantics & ast::type::MemorySemanticsMask::eSubgroupMemory ) == ast::type::MemorySemanticsMask::eSubgroupMemory )
					{
						m_result += "AllMemoryBarrier()";
					}
					else
					{
						m_result += "DeviceMemoryBarrier()";
					}
				}
				else
				{
					if ( memory == ast::type::Scope::eWorkgroup
						|| memory == ast::type::Scope::eSubgroup )
					{
						m_result += "GroupMemoryBarrierWithGroupSync()";
					}
					else if ( ( semantics & ast::type::MemorySemanticsMask::eWorkgroupMemory ) == ast::type::MemorySemanticsMask::eWorkgroupMemory
						|| ( semantics & ast::type::MemorySemanticsMask::eSubgroupMemory ) == ast::type::MemorySemanticsMask::eSubgroupMemory )
					{
						m_result += "AllMemoryBarrierWithGroupSync()";
					}
					else
					{
						m_result += "DeviceMemoryBarrierWithGroupSync()";
					}
				}
			}

			void doProcessMemoryBarrier( ast::expr::IntrinsicCall const & expr )
			{
				if ( expr.getArgList().size() < 2u )
				{
					throw ast::Exception{ "Wrong number of parameters for a memory barrier" };
				}

				auto memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[0] ) );
				auto semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[1] ) );

				if ( memory == ast::type::Scope::eWorkgroup
					|| memory == ast::type::Scope::eSubgroup )
				{
					m_result += "GroupMemoryBarrier()";
				}
				else if ( ( semantics & ast::type::MemorySemanticsMask::eWorkgroupMemory ) == ast::type::MemorySemanticsMask::eWorkgroupMemory
					|| ( semantics & ast::type::MemorySemanticsMask::eSubgroupMemory ) == ast::type::MemorySemanticsMask::eSubgroupMemory )
				{
					m_result += "AllMemoryBarrier()";
				}
				else
				{
					m_result += "DeviceMemoryBarrier()";
				}
			}

			void doProcessNonMatchingOuterProduct( ast::expr::IntrinsicCall const & expr )
			{
				m_result += "transpose(" + getHlslName( expr.getIntrinsic() ) + "(";
				auto lhs = doSubmit( *expr.getArgList().front() );
				auto rhs = doSubmit( *expr.getArgList().back() );

				if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x3F )
				{
					m_result += "float2x1(" + lhs + "), float1x3(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x4F )
				{
					m_result += "float2x1(" + lhs + "), float1x4(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x2F )
				{
					m_result += "float3x1(" + lhs + "), float1x2(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x4F )
				{
					m_result += "float3x1(" + lhs + "), float1x4(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x2F )
				{
					m_result += "float4x1(" + lhs + "), float1x2(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x3F )
				{
					m_result += "float4x1(" + lhs + "), float1x3(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x3D )
				{
					m_result += "double2x1(" + lhs + "), double1x3(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct2x4D )
				{
					m_result += "double2x1(" + lhs + "), double1x4(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x2D )
				{
					m_result += "double3x1(" + lhs + "), double1x2(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct3x4D )
				{
					m_result += "double3x1(" + lhs + "), double1x4(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x2D )
				{
					m_result += "double4x1(" + lhs + "), double1x2(" + rhs + ")";
				}
				else if ( expr.getIntrinsic() == ast::expr::Intrinsic::eOuterProduct4x3D )
				{
					m_result += "double4x1(" + lhs + "), double1x3(" + rhs + ")";
				}

				m_result += "))";
			}

			void doProcessMemberTexture( ast::expr::CombinedImageAccessCall const & expr )
			{
				m_result += doSubmit( *expr.getArgList()[0] );
				m_result += "." + getHlslName( expr.getCombinedImageAccess() ) + "(";
				m_result += doSubmit( *expr.getArgList()[1] );

				for ( size_t i = 2; i < expr.getArgList().size(); ++i )
				{
					auto & arg = expr.getArgList()[i];
					m_result += ", ";
					m_result += doSubmit( *arg );
				}

				m_result += ")";
			}

			void doProcessNonMemberTexture( ast::expr::CombinedImageAccessCall const & expr )
			{
				m_result += getHlslName( expr.getCombinedImageAccess() ) + "(";
				std::string sep;

				for ( auto & arg : expr.getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( *arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void doProcessTextureGather( ast::expr::CombinedImageAccessCall const & expr )
			{
				// Image
				m_result += doSubmit( *expr.getArgList()[0] );
				uint32_t compValue = 0u;

				// Component value will determine Gather function name.
				if ( auto component = expr.getArgList()[2].get();
					component->getKind() == ast::expr::Kind::eLiteral )
				{
					auto lit = static_cast< ast::expr::Literal const * >( component );

					if ( lit->getLiteralType() == ast::expr::LiteralType::eInt32 )
					{
						compValue = uint32_t( lit->getValue< ast::expr::LiteralType::eInt32 >() );
					}
					else
					{
						assert( lit->getLiteralType() == ast::expr::LiteralType::eUInt32 );
						compValue = uint32_t( lit->getValue< ast::expr::LiteralType::eUInt32 >() );
					}
				}

				auto name = getHlslName( expr.getCombinedImageAccess() );

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
				default:
					AST_Failure( "Unsupported count to determine Gather function name" );
					throw ast::Exception{ "Unsupported count to determine Gather function name" };
				}

				m_result += "." + name + "(";
				// Sampler
				m_result += doSubmit( *expr.getArgList()[1] );
				// Coord
				m_result += ", ";
				m_result += doSubmit( *expr.getArgList()[3] );
				auto index = 4u;

				while ( index < expr.getArgList().size() )
				{
					auto & arg = expr.getArgList()[index];
					m_result += ", ";
					m_result += doSubmit( *arg );
					++index;
				}

				m_result += ")";
			}

		private:
			HlslConfig const & m_writerConfig;
			std::string & m_result;
			std::map< ast::var::VariablePtr, ast::expr::Expr const * > & m_aliases;
		};

		class StmtVisitor
			: public ast::stmt::Visitor
		{
		public:
			static std::string submit( HlslConfig const & writerConfig
				, RoutineMap const & routines
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
				, ast::stmt::Stmt const & stmt
				, std::string indent = std::string{} )
			{
				std::string result;
				result += "// This shader was generated using ShaderWriter version " + helpers::printVersion() + "\n";
				StmtVisitor vis{ writerConfig, routines, aliases, std::move( indent ), result };
				stmt.accept( &vis );
				return result;
			}

		private:
			StmtVisitor( HlslConfig const & writerConfig
				, RoutineMap const & routines
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
				, std::string indent
				, std::string & result )
				: m_writerConfig{ writerConfig }
				, m_routines{ routines }
				, m_aliases{ aliases }
				, m_indent{ std::move( indent ) }
				, m_result{ result }
			{
			}

			std::string doSubmit( ast::expr::Expr const & expr )
			{
				return ExprVisitor::submit( m_writerConfig, expr, m_aliases );
			}

			void doAppendLineEnd()
			{
				if ( m_appendLineEnd && !m_result.empty() )
				{
					m_result += "\n";
				}

				m_appendLineEnd = false;
			}

			void visitContainerStmt( ast::stmt::Container const * stmt )override
			{
				for ( auto & curStmt : *stmt )
				{
					curStmt->accept( this );
				}
			}

			void visitBreakStmt( ast::stmt::Break const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "break;\n";
			}

			void visitContinueStmt( ast::stmt::Continue const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "continue;\n";
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl const * stmt )override
			{
				if ( !stmt->empty() )
				{
					m_appendLineEnd = true;
					doAppendLineEnd();
					m_result += m_indent + "cbuffer " + stmt->getName() + ": register(b" + std::to_string( stmt->getBindingPoint() ) + ")";
					m_appendSemiColon = true;
					visitCompoundStmt( stmt );
					m_appendLineEnd = true;
				}
			}

			void visitDemoteStmt( ast::stmt::Demote const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "discard;\n";
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "DispatchMesh";
				m_result += "(" + doSubmit( *stmt->getNumGroupsX() );
				m_result += ", " + doSubmit( *stmt->getNumGroupsY() );
				m_result += ", " + doSubmit( *stmt->getNumGroupsZ() );

				if ( stmt->getPayload() )
				{
					m_result += ", " + doSubmit( *stmt->getPayload() );
				}

				m_result += ");\n";
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "discard;\n";
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl const * stmt )override
			{
				if ( !stmt->empty() )
				{
					m_appendLineEnd = true;
					doAppendLineEnd();
					m_result += m_indent + "cbuffer " + stmt->getName();
					m_appendSemiColon = true;
					visitCompoundStmt( stmt );
					m_appendLineEnd = true;
				}
			}

			void visitCommentStmt( ast::stmt::Comment const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + stmt->getText() + "\n";
			}

			void visitCompoundStmt( ast::stmt::Compound const * stmt )override
			{
				doAppendLineEnd();
				m_result += "\n" + m_indent + "{\n";
				auto save = m_indent;
				m_indent += "\t";
				visitContainerStmt( stmt );
				m_indent = save;

				if ( m_appendSemiColon )
				{
					m_result += m_indent + "};\n";
				}
				else
				{
					m_result += m_indent + "}\n";
				}
			}

			void visitDoWhileStmt( ast::stmt::DoWhile const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "do";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_result += m_indent + "while (" + doSubmit( *stmt->getCtrlExpr() ) + ");\n";
				m_appendLineEnd = true;
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				m_result += m_indent + "else if (" + doSubmit( *stmt->getCtrlExpr() ) + ")";
				m_appendSemiColon = false;
				m_appendLineEnd = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				m_result += m_indent + "else";
				m_appendSemiColon = false;
				m_appendLineEnd = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitForStmt( ast::stmt::For const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "for (" + doSubmit( *stmt->getInitExpr() ) + "; ";
				m_result += doSubmit( *stmt->getCtrlExpr() ) + "; ";
				m_result += doSubmit( *stmt->getIncrExpr() ) + ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout const * stmt )override
			{
				AST_Failure( "ast::stmt::FragmentLayout unexpected at that point" );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				auto type = stmt->getType();
				ast::var::VariableList params;

				if ( stmt->isEntryPoint() )
				{
					for ( auto & mbr : *type )
					{
						auto argType = mbr->getType();

						if ( argType->getKind() == ast::type::Kind::eGeometryOutput )
						{
							auto maxVertexCount = static_cast< ast::type::GeometryOutput const & >( *argType ).getCount();
							m_result += m_indent + "[maxvertexcount(" + std::to_string( maxVertexCount ) + ")]\n";
							params.push_back( mbr );
						}
						else if ( argType->getKind() == ast::type::Kind::eComputeInput )
						{
							if ( !isMeshStage( m_writerConfig.shaderStage ) )
							{
								auto & compType = static_cast< ast::type::ComputeInput const & >( *argType );

								if ( compType.getLocalSizeX() == ast::stmt::InputComputeLayout::Uninit )
								{
									if ( compType.getLocalSizeY() == ast::stmt::InputComputeLayout::Uninit )
									{
										m_result += m_indent + "[numthreads( " + std::to_string( compType.getLocalSizeX() ) + " )]\n";
									}
									else
									{
										m_result += m_indent + "[numthreads( " + std::to_string( compType.getLocalSizeX() )
											+ ", " + std::to_string( compType.getLocalSizeY() ) + " )]\n";
									}
								}
								else
								{
									m_result += m_indent + "[numthreads( " + std::to_string( compType.getLocalSizeX() )
										+ ", " + std::to_string( compType.getLocalSizeY() )
										+ ", " + std::to_string( compType.getLocalSizeZ() ) + " )]\n";
								}
							}

							params.push_back( mbr );
						}
						else if ( argType->getKind() == ast::type::Kind::eFragmentInput )
						{
							// Fragment layouts unsupported in HLSL :/
							auto & fragType = static_cast< ast::type::FragmentInput const & >( *argType );
							argType = fragType.getType();

							if ( argType->getKind() != ast::type::Kind::eVoid
								&& ( argType->getKind() != ast::type::Kind::eStruct
									|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
							{
								params.push_back( mbr );
							}
						}
						else if ( argType->getKind() == ast::type::Kind::eTessellationControlInput )
						{
							auto & tessciType = static_cast< ast::type::TessellationControlInput const & >( *argType );
							argType = tessciType.getType();

							if ( argType->getKind() != ast::type::Kind::eVoid
								&& ( argType->getKind() != ast::type::Kind::eStruct
									|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
							{
								params.push_back( mbr );
							}
						}
						else if ( argType->getKind() == ast::type::Kind::eTessellationControlOutput )
						{
							auto & tesscoType = static_cast< ast::type::TessellationControlOutput const & >( *argType );
							m_result += helpers::writeTessCtrlOut( tesscoType
								, m_routines
								, m_indent );
							argType = tesscoType.getType();

							if ( argType->getKind() != ast::type::Kind::eVoid
								&& ( argType->getKind() != ast::type::Kind::eStruct
									|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
							{
								params.push_back( mbr );
							}
						}
						else if ( argType->getKind() == ast::type::Kind::eTessellationInputPatch )
						{
							auto & tesseiType = static_cast< ast::type::TessellationInputPatch const & >( *argType );
							m_result += helpers::writeTessEvalIn( tesseiType, m_indent );
							argType = tesseiType.getType();

							if ( argType->getKind() != ast::type::Kind::eVoid
								&& ( argType->getKind() != ast::type::Kind::eStruct
									|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
							{
								params.push_back( mbr );
							}
						}
						else if ( argType->getKind() == ast::type::Kind::eMeshVertexOutput )
						{
							auto & meshType = static_cast< ast::type::MeshVertexOutput const & >( *argType );
							argType = meshType.getType();

							if ( argType->getKind() != ast::type::Kind::eVoid
								&& ( argType->getKind() != ast::type::Kind::eStruct
									|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
							{
								params.push_back( mbr );
							}
						}
						else if ( argType->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
						{
							auto & meshType = static_cast< ast::type::MeshPrimitiveOutput const & >( *argType );
							argType = meshType.getType();

							if ( argType->getKind() != ast::type::Kind::eVoid
								&& ( argType->getKind() != ast::type::Kind::eStruct
									|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
							{
								params.push_back( mbr );
							}
						}
						else if ( argType->getKind() == ast::type::Kind::eTaskPayloadIn )
						{
							auto & taskType = static_cast< ast::type::TaskPayloadIn const & >( *argType );
							argType = taskType.getType();

							if ( argType->getKind() != ast::type::Kind::eVoid
								&& ( argType->getKind() != ast::type::Kind::eStruct
									|| !static_cast< ast::type::Struct const & >( *argType ).empty() ) )
							{
								params.push_back( mbr );
							}
						}
						else
						{
							params.push_back( mbr );
						}
					}

					if ( m_writerConfig.shaderStage == ast::ShaderStage::eMeshNV
						|| m_writerConfig.shaderStage == ast::ShaderStage::eMesh )
					{
						m_result += helpers::writeMeshPrimOut( m_routines
							, m_indent );
					}

					if ( m_writerConfig.shaderStage == ast::ShaderStage::eCallable )
					{
						m_result += m_indent + "[shader(\"callable\")]\n";
					}
					else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayAnyHit )
					{
						m_result += m_indent + "[shader(\"anyhit\")]\n";
					}
					else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayClosestHit )
					{
						m_result += m_indent + "[shader(\"closesthit\")]\n";
					}
					else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayGeneration )
					{
						m_result += m_indent + "[shader(\"raygeneration\")]\n";
					}
					else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayIntersection )
					{
						m_result += m_indent + "[shader(\"intersection\")]\n";
					}
					else if ( m_writerConfig.shaderStage == ast::ShaderStage::eRayMiss )
					{
						m_result += m_indent + "[shader(\"miss\")]\n";
					}
				}
				else
				{
					params.insert( params.end(), type->begin(), type->end() );
				}

				auto retType = type->getReturnType();

				if ( retType->getKind() == ast::type::Kind::eTessellationControlOutput )
				{
					auto & tesscoType = static_cast< ast::type::TessellationControlOutput const & >( *retType );
					m_result += helpers::writeTessCtrlOut( tesscoType
						, m_routines
						, m_indent );
				}

				m_result += m_indent + getTypeName( retType );
				m_result += " " + stmt->getName() + "(";
				std::string sep;
				Semantic sem{ "", 0u };

				for ( auto const & param : params )
				{
					if ( param->isBuiltin() )
					{
						m_result += sep + getDirectionName( *param )
							+ helpers::writeIOMember( m_writerConfig.shaderStage
								, param->getType()
								, param->getName()
								, param->getBuiltin()
								, true
								, ast::type::Struct::InvalidLocation
								, ast::type::Struct::InvalidLocation
								, sem
								, sem );
					}
					else
					{
						m_result += sep + getDirectionName( *param )
							+ getAttributeName( param->getType() )
							+ getTypeName( param->getType() ) + " "
							+ adaptName( param->getName() )
							+ getTypeArraySize( param->getType() );
					}

					sep = m_indent + "\n\t, ";
				}

				m_result += ")";
				m_appendSemiColon = false;
				doAppendLineEnd();
				m_result += "\n" + m_indent + "{\n";
				auto save = m_indent;
				m_indent += "\t";
				visitContainerStmt( stmt );

				if ( stmt->getName() == "SDW_main"
					&& m_writerConfig.shaderStage == ast::ShaderStage::eVertex
					&& m_writerConfig.flipVertY )
				{
					m_result += m_indent + "sdwOutput.gl_Position.y = -sdwOutput.gl_Position.y;\n";
				}

				m_indent = save;
				m_result += m_indent + "}\n";
				m_appendLineEnd = true;
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent;
				auto const & var = *stmt->getVariable();
				m_result += getTypeName( var.getType() ) + " ";
				m_result += var.getName();
				m_result += ": register(t" + std::to_string( stmt->getBindingPoint() ) + ")";
				m_result += ";\n";
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl const * stmt )override
			{
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
				declareVariable( stmt->getVariable() );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
			{
				declareVariable( stmt->getVariable() );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
				declareVariable( stmt->getVariable() );
			}

			void visitIfStmt( ast::stmt::If const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "if (" + doSubmit( *stmt->getCtrlExpr() ) + ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );

				for ( auto & elseIf : stmt->getElseIfList() )
				{
					elseIf->accept( this );
				}

				if ( stmt->getElse() )
				{
					stmt->getElse()->accept( this );
				}

				m_appendLineEnd = true;
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent;
				m_result += getTypeName( stmt->getVariable()->getType() ) + " ";
				m_result += stmt->getVariable()->getName();
				m_result += getTypeArraySize( stmt->getVariable()->getType() );

				if ( stmt->getVariable()->isImplicit() )
				{
					m_result += ": register(t" + std::to_string( stmt->getBindingPoint() ) + ")";
				}
				else
				{
					m_result += ": register(u" + std::to_string( stmt->getBindingPoint() ) + ")";
				}

				m_result += ";\n";
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection const * stmt )override
			{
				m_result += m_indent + "IgnoreHit();\n";
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
			{
				AST_Failure( "ast::stmt::InOutVariableDecl unexpected at that point" );
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl const * stmt )override
			{
				AST_Failure( "ast::stmt::SpecialisationConstantDecl unexpected at that point" );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout const * stmt )override
			{
				doAppendLineEnd();
				m_result += "\n";

				if ( stmt->getWorkGroupsZ() == ast::stmt::InputComputeLayout::Uninit )
				{
					if ( stmt->getWorkGroupsY() == ast::stmt::InputComputeLayout::Uninit )
					{
						m_result += m_indent + "[numthreads( " + std::to_string( stmt->getWorkGroupsX() ) + " )]";
					}
					else
					{
						m_result += m_indent + "[numthreads( " + std::to_string( stmt->getWorkGroupsX() )
							+ ", " + std::to_string( stmt->getWorkGroupsY() ) + " )]";
					}
				}
				else
				{
					m_result += m_indent + "[numthreads( " + std::to_string( stmt->getWorkGroupsX() )
						+ ", " + std::to_string( stmt->getWorkGroupsY() )
						+ ", " + std::to_string( stmt->getWorkGroupsZ() ) + " )]";
				}
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout const * stmt )override
			{
				AST_Failure( "ast::stmt::InputGeometryLayout unexpected at that point" );
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout const * stmt )override
			{
				AST_Failure( "ast::stmt::InputTessellationEvaluationLayout unexpected at that point" );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout const * stmt )override
			{
				AST_Failure( "ast::stmt::OutputGeometryLayout unexpected at that point" );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout const * stmt )override
			{
				AST_Failure( "ast::stmt::OutputMeshLayout unexpected at that point" );
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout const * stmt )override
			{
				AST_Failure( "ast::stmt::visitOutputTessellationControlLayoutStmt unexpected at that point" );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl const * stmt )override
			{
				AST_Failure( "ast::stmt::PerPrimitiveDecl unexpected at that point" );
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl const * stmt )override
			{
				AST_Failure( "ast::stmt::PerVertexDecl unexpected at that point" );
			}

			void visitReturnStmt( ast::stmt::Return const * stmt )override
			{
				doAppendLineEnd();

				if ( auto expr = stmt->getExpr() )
				{
					m_result += m_indent + "return " + doSubmit( *expr ) + ";\n";
				}
				else
				{
					m_result += m_indent + "return;\n";
				}
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
			{
				AST_Failure( "ast::stmt::CombinedImageDecl unexpected at that point" );
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
				m_result += getTypeArraySize( stmt->getVariable()->getType() );
				m_result += ": register(t" + std::to_string( stmt->getBindingPoint() ) + ");\n";
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl const * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
				m_result += getTypeArraySize( stmt->getVariable()->getType() );
				m_result += ": register(s" + std::to_string( stmt->getBindingPoint() ) + ");\n";
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "RWByteAddressBuffer "
					+ stmt->getSsboName()
					+ ": register(u" + std::to_string( stmt->getBindingPoint() ) + ");\n";
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "RWStructuredBuffer<" + getTypeName( stmt->getData()->getType() ) + "> "
					+ stmt->getData()->getName()
					+ ": register(u" + std::to_string( stmt->getBindingPoint() ) + ");\n";
			}

			void visitSimpleStmt( ast::stmt::Simple const * stmt )override
			{
				if ( stmt->getExpr()->getKind() == ast::expr::Kind::eAlias )
				{
					auto result = doSubmit( *stmt->getExpr() );

					if ( !result.empty() )
					{
						m_result += m_indent + doSubmit( *stmt->getExpr() ) + ";\n";
					}
				}
				else if ( stmt->getExpr()->getKind() != ast::expr::Kind::eIdentifier )
				{
					doAppendLineEnd();
					m_result += m_indent + doSubmit( *stmt->getExpr() ) + ";\n";
				}
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
				if ( !stmt->getType()->empty() )
				{
					m_appendLineEnd = true;
					doAppendLineEnd();
					m_result += m_indent + "struct " + stmt->getType()->getName();

					m_result += "\n" + m_indent + "{\n";
					auto save = m_indent;
					m_indent += "\t";

					m_result += helpers::writeMembers( m_writerConfig.shaderStage
						, m_indent
						, *stmt->getType() );

					m_indent = save;
					m_result += m_indent + "};\n";
				}
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase const * stmt )override
			{
				doAppendLineEnd();

				if ( stmt->getCaseExpr() )
				{
					m_result += m_indent + "case " + doSubmit( *stmt->getCaseExpr() ) + ":";
				}
				else
				{
					m_result += m_indent + "default:";
				}

				m_appendSemiColon = false;

				if ( !stmt->empty() )
				{
					visitCompoundStmt( stmt );
				}
				else
				{
					m_result += "\n";
				}

				m_result += m_indent + "break;\n";
				m_appendLineEnd = true;
			}

			void visitSwitchStmt( ast::stmt::Switch const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "switch (" + doSubmit( *stmt->getTestExpr() ) + ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay const * stmt )override
			{
				m_result += m_indent + "AcceptHitAndEndSearch();\n";
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
				declareVariable( stmt->getVariable() );
			}

			void visitWhileStmt( ast::stmt::While const * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "while (" + doSubmit( *stmt->getCtrlExpr() ) + ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension const * preproc )override
			{
				AST_Failure( "ast::stmt::PreprocExtension unexpected at that point" );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
				AST_Failure( "ast::stmt::PreprocVersion unexpected at that point" );
			}

			void declareVariable( ast::var::VariablePtr pvar )
			{
				doAppendLineEnd();
				m_result += m_indent;
				auto const & var = *pvar;

				if ( var.isStatic() )
				{
					m_result += "static ";
				}

				if ( var.isPerTaskNV()
					|| var.isPerTask()
					|| var.isShared() )
				{
					m_result += "groupshared ";
				}

				m_result += getTypeName( var.getType() ) + " ";
				m_result += var.getName();
				m_result += getTypeArraySize( var.getType() );
				m_result += ";\n";
			}

		private:
			HlslConfig const & m_writerConfig;
			RoutineMap const & m_routines;
			std::map< ast::var::VariablePtr, ast::expr::Expr const * > & m_aliases;
			std::string m_indent;
			std::string & m_result;
			bool m_appendSemiColon{ false };
			bool m_appendLineEnd{ false };
		};
	}

	std::string generateStatements( HlslConfig const & writerConfig
		, RoutineMap const & routines
		, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
		, ast::stmt::Stmt const & stmt
		, std::string indent )
	{
		return vis::StmtVisitor::submit( writerConfig, routines, aliases, stmt, std::move( indent ) );
	}
}
