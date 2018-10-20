/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterGlsl.hpp"

#include "ShaderWriter/Shader.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>
#include <ASTGenerator/Stmt/StmtVisitor.hpp>

#include "ShaderWriter/GlslImageAccessNames.hpp"
#include "ShaderWriter/GlslIntrinsicNames.hpp"
#include "ShaderWriter/GlslTextureAccessNames.hpp"

#include <sstream>

namespace sdw
{
	namespace glsl
	{
		std::string getTypeName( type::Kind kind )
		{
			std::string result;

			switch ( kind )
			{
			case type::Kind::eUndefined:
				result = "undefined";
				break;
			case type::Kind::eVoid:
				result = "void";
				break;
			case type::Kind::eStruct:
				result = "struct";
				break;
			case type::Kind::eFunction:
				result = "function";
				break;
			case type::Kind::eBoolean:
				result = "bool";
				break;
			case type::Kind::eInt:
				result = "int";
				break;
			case type::Kind::eUInt:
				result = "uint";
				break;
			case type::Kind::eFloat:
				result = "float";
				break;
			case type::Kind::eDouble:
				result = "double";
				break;
			case type::Kind::eVec2B:
				result = "bvec2";
				break;
			case type::Kind::eVec3B:
				result = "bvec3";
				break;
			case type::Kind::eVec4B:
				result = "bvec4";
				break;
			case type::Kind::eVec2I:
				result = "ivec2";
				break;
			case type::Kind::eVec3I:
				result = "ivec3";
				break;
			case type::Kind::eVec4I:
				result = "ivec4";
				break;
			case type::Kind::eVec2U:
				result = "uvec2";
				break;
			case type::Kind::eVec3U:
				result = "uvec3";
				break;
			case type::Kind::eVec4U:
				result = "uvec4";
				break;
			case type::Kind::eVec2F:
				result = "vec2";
				break;
			case type::Kind::eVec3F:
				result = "vec3";
				break;
			case type::Kind::eVec4F:
				result = "vec4";
				break;
			case type::Kind::eVec2D:
				result = "dvec2";
				break;
			case type::Kind::eVec3D:
				result = "dvec3";
				break;
			case type::Kind::eVec4D:
				result = "dvec4";
				break;
			case type::Kind::eMat2x2F:
				result = "mat2";
				break;
			case type::Kind::eMat2x3F:
				result = "mat2x3";
				break;
			case type::Kind::eMat2x4F:
				result = "mat2x4";
				break;
			case type::Kind::eMat3x3F:
				result = "mat3";
				break;
			case type::Kind::eMat3x2F:
				result = "mat3x2";
				break;
			case type::Kind::eMat3x4F:
				result = "mat3x4";
				break;
			case type::Kind::eMat4x4F:
				result = "mat4";
				break;
			case type::Kind::eMat4x2F:
				result = "mat4x2";
				break;
			case type::Kind::eMat4x3F:
				result = "mat4x3";
				break;
			case type::Kind::eMat2x2D:
				result = "dmat2";
				break;
			case type::Kind::eMat2x3D:
				result = "dmat2x3";
				break;
			case type::Kind::eMat2x4D:
				result = "dmat2x4";
				break;
			case type::Kind::eMat3x3D:
				result = "dmat3";
				break;
			case type::Kind::eMat3x2D:
				result = "dmat3x2";
				break;
			case type::Kind::eMat3x4D:
				result = "dmat3x4";
				break;
			case type::Kind::eMat4x4D:
				result = "dmat4";
				break;
			case type::Kind::eMat4x2D:
				result = "dmat4x2";
				break;
			case type::Kind::eMat4x3D:
				result = "dmat4x3";
				break;
			case type::Kind::eConstantsBuffer:
				result = "uniform";
				break;
			case type::Kind::eShaderBuffer:
				result = "buffer";
				break;
			case type::Kind::eSamplerBufferF:
				result = "samplerBuffer";
				break;
			case type::Kind::eSampler1DF:
				result = "sampler1D";
				break;
			case type::Kind::eSampler2DF:
				result = "sampler2D";
				break;
			case type::Kind::eSampler3DF:
				result = "sampler3D";
				break;
			case type::Kind::eSamplerCubeF:
				result = "samplerCube";
				break;
			case type::Kind::eSampler2DRectF:
				result = "sampler2DRect";
				break;
			case type::Kind::eSampler1DArrayF:
				result = "sampler1DArray";
				break;
			case type::Kind::eSampler2DArrayF:
				result = "sampler2DArray";
				break;
			case type::Kind::eSamplerCubeArrayF:
				result = "samplerCubeArray";
				break;
			case type::Kind::eSampler1DShadowF:
				result = "sampler1DShadow";
				break;
			case type::Kind::eSampler2DShadowF:
				result = "sampler2DShadow";
				break;
			case type::Kind::eSamplerCubeShadowF:
				result = "samplerCubeShadow";
				break;
			case type::Kind::eSampler2DRectShadowF:
				result = "sampler2DRectArrayShadow";
				break;
			case type::Kind::eSampler1DArrayShadowF:
				result = "sampler1DArrayShadow";
				break;
			case type::Kind::eSampler2DArrayShadowF:
				result = "sampler2DArrayShadow";
				break;
			case type::Kind::eSamplerCubeArrayShadowF:
				result = "samplerCubeArrayShadow";
				break;
			case type::Kind::eSamplerBufferI:
				result = "isamplerBuffer";
				break;
			case type::Kind::eSampler1DI:
				result = "isampler1D";
				break;
			case type::Kind::eSampler2DI:
				result = "isampler2D";
				break;
			case type::Kind::eSampler3DI:
				result = "isampler3D";
				break;
			case type::Kind::eSamplerCubeI:
				result = "isamplerCube";
				break;
			case type::Kind::eSampler2DRectI:
				result = "isampler2DRect";
				break;
			case type::Kind::eSampler1DArrayI:
				result = "isampler1DArray";
				break;
			case type::Kind::eSampler2DArrayI:
				result = "isampler2DArray";
				break;
			case type::Kind::eSamplerCubeArrayI:
				result = "isamplerCubeArray";
				break;
			case type::Kind::eSamplerBufferU:
				result = "usamplerBuffer";
				break;
			case type::Kind::eSampler1DU:
				result = "usampler1D";
				break;
			case type::Kind::eSampler2DU:
				result = "usampler2D";
				break;
			case type::Kind::eSampler3DU:
				result = "usampler3D";
				break;
			case type::Kind::eSamplerCubeU:
				result = "usamplerCube";
				break;
			case type::Kind::eSampler2DRectU:
				result = "usampler2DRect";
				break;
			case type::Kind::eSampler1DArrayU:
				result = "usampler1DArray";
				break;
			case type::Kind::eSampler2DArrayU:
				result = "usampler2DArray";
				break;
			case type::Kind::eSamplerCubeArrayU:
				result = "usamplerCubeArray";
				break;
			case type::Kind::eImageBufferF:
				result = "imageBuffer";
				break;
			case type::Kind::eImage1DF:
				result = "image1D";
				break;
			case type::Kind::eImage2DF:
				result = "image2D";
				break;
			case type::Kind::eImage3DF:
				result = "image3D";
				break;
			case type::Kind::eImageCubeF:
				result = "imageCube";
				break;
			case type::Kind::eImage2DRectF:
				result = "image2DRect";
				break;
			case type::Kind::eImage1DArrayF:
				result = "image1DArray";
				break;
			case type::Kind::eImage2DArrayF:
				result = "image2DArray";
				break;
			case type::Kind::eImageCubeArrayF:
				result = "imageCubeArray";
				break;
			case type::Kind::eImage2DMSF:
				result = "image2DMS";
				break;
			case type::Kind::eImage2DMSArrayF:
				result = "image2DMSArray";
				break;
			case type::Kind::eImageBufferI:
				result = "iimageBuffer";
				break;
			case type::Kind::eImage1DI:
				result = "iimage1D";
				break;
			case type::Kind::eImage2DI:
				result = "iimage2D";
				break;
			case type::Kind::eImage3DI:
				result = "iimage3D";
				break;
			case type::Kind::eImageCubeI:
				result = "iimageCube";
				break;
			case type::Kind::eImage2DRectI:
				result = "iimage2DRect";
				break;
			case type::Kind::eImage1DArrayI:
				result = "iimage1DArray";
				break;
			case type::Kind::eImage2DArrayI:
				result = "iimage2DArray";
				break;
			case type::Kind::eImageCubeArrayI:
				result = "iimageCubeArray";
				break;
			case type::Kind::eImage2DMSI:
				result = "iimage2DMS";
				break;
			case type::Kind::eImage2DMSArrayI:
				result = "iimage2DMSArray";
				break;
			case type::Kind::eImageBufferU:
				result = "uimageBuffer";
				break;
			case type::Kind::eImage1DU:
				result = "uimage1D";
				break;
			case type::Kind::eImage2DU:
				result = "uimage2D";
				break;
			case type::Kind::eImage3DU:
				result = "uimage3D";
				break;
			case type::Kind::eImageCubeU:
				result = "uimageCube";
				break;
			case type::Kind::eImage2DRectU:
				result = "uimage2DRect";
				break;
			case type::Kind::eImage1DArrayU:
				result = "uimage1DArray";
				break;
			case type::Kind::eImage2DArrayU:
				result = "uimage2DArray";
				break;
			case type::Kind::eImageCubeArrayU:
				result = "uimageCubeArray";
				break;
			case type::Kind::eImage2DMSU:
				result = "uimage2DMS";
				break;
			case type::Kind::eImage2DMSArrayU:
				result = "uimage2DMSArray";
				break;
			}

			return result;
		}

		std::string getTypeName( type::TypePtr type )
		{
			std::string result;

			switch ( type->getKind() )
			{
			case type::Kind::eStruct:
				static_cast< type::Struct const & >( *type ).getName();
				break;
			default:
				result = getTypeName( type->getKind() );
				break;
			}

			return result;
		}

		std::string getLocationName( var::Variable const & var )
		{
			std::string result;

			if ( var.isShaderConstant() )
			{
				result = "constant_id";
			}
			else if ( var.isShaderInput()
				|| var.isShaderOutput() )
			{
				result = "location";
			}

			return result;
		}

		std::string getDirectionName( var::Variable const & var )
		{
			std::string result;

			if ( var.isInputParam()
				&& var.isOutputParam() )
			{
				result = "inout";
			}
			else if ( var.isInputParam()
				|| var.isShaderInput() )
			{
				result = "in";
			}
			else if ( var.isOutputParam()
				|| var.isShaderOutput() )
			{
				result = "out";
			}
			else if ( var.isShaderConstant() )
			{
				result = "const";
			}

			return result;
		}

		std::string getStatusName( stmt::PreprocExtension::Status status )
		{
			std::string result;

			switch ( status )
			{
			case stmt::PreprocExtension::Status::eDisabled:
				result = "disable";
				break;

			case stmt::PreprocExtension::Status::eEnabled:
				result = "enable";
				break;

			case stmt::PreprocExtension::Status::eRequired:
				result = "required";
				break;

			}

			return result;
		}

		std::string getOperatorName( expr::Kind kind )
		{
			std::string result;

			switch ( kind )
			{
			case expr::Kind::eAdd:
				result = "+";
				break;
			case expr::Kind::eMinus:
				result = "-";
				break;
			case expr::Kind::eTimes:
				result = "*";
				break;
			case expr::Kind::eDivide:
				result = "/";
				break;
			case expr::Kind::eModulo:
				result = "%";
				break;
			case expr::Kind::eLShift:
				result = "<<";
				break;
			case expr::Kind::eRShift:
				result = ">>";
				break;
			case expr::Kind::eBitAnd:
				result = "&";
				break;
			case expr::Kind::eBitNot:
				result = "~";
				break;
			case expr::Kind::eBitOr:
				result = "|";
				break;
			case expr::Kind::eBitXor:
				result = "^";
				break;
			case expr::Kind::eLogAnd:
				result = "&&";
				break;
			case expr::Kind::eLogNot:
				result = "!";
				break;
			case expr::Kind::eLogOr:
				result = "||";
				break;
			case expr::Kind::eCast:
				result = "cast";
				break;
			case expr::Kind::eEqual:
				result = "==";
				break;
			case expr::Kind::eGreater:
				result = ">";
				break;
			case expr::Kind::eGreaterEqual:
				result = ">=";
				break;
			case expr::Kind::eLess:
				result = "<";
				break;
			case expr::Kind::eLessEqual:
				result = "<=";
				break;
			case expr::Kind::eNotEqual:
				result = "!=";
				break;
			case expr::Kind::eComma:
				result = ",";
				break;
			case expr::Kind::eMbrSelect:
				result = ".";
				break;
			case expr::Kind::ePreIncrement:
				result = "++";
				break;
			case expr::Kind::ePreDecrement:
				result = "--";
				break;
			case expr::Kind::ePostIncrement:
				result = "++";
				break;
			case expr::Kind::ePostDecrement:
				result = "--";
				break;
			case expr::Kind::eUnaryMinus:
				result = "-";
				break;
			case expr::Kind::eUnaryPlus:
				result = "+";
				break;
			case expr::Kind::eAssign:
				result = "=";
				break;
			case expr::Kind::eAddAssign:
				result = "+=";
				break;
			case expr::Kind::eMinusAssign:
				result = "-=";
				break;
			case expr::Kind::eTimesAssign:
				result = "*=";
				break;
			case expr::Kind::eDivideAssign:
				result = "/=";
				break;
			case expr::Kind::eModuloAssign:
				result = "%=";
				break;
			case expr::Kind::eLShiftAssign:
				result = "<<=";
				break;
			case expr::Kind::eRShiftAssign:
				result = ">>=";
				break;
			case expr::Kind::eAndAssign:
				result = "&=";
				break;
			case expr::Kind::eNotAssign:
				result = "!=";
				break;
			case expr::Kind::eOrAssign:
				result = "|=";
				break;
			case expr::Kind::eXorAssign:
				result = "^=";
				break;
			default:
				throw std::runtime_error{ "Non operation expression" };
			}

			return result;
		}

		std::string getLayoutName( stmt::InputLayout layout )
		{
			std::string result;

			switch ( layout )
			{
			case ast::stmt::InputLayout::ePointList:
				result = "points";
				break;
			case ast::stmt::InputLayout::eLineList:
				result = "lines";
				break;
			case ast::stmt::InputLayout::eLineStrip:
				result = "lines";
				break;
			case ast::stmt::InputLayout::eTriangleList:
				result = "triangles";
				break;
			case ast::stmt::InputLayout::eTriangleStrip:
				result = "triangles";
				break;
			case ast::stmt::InputLayout::eTriangleFan:
				result = "triangles";
				break;
			case ast::stmt::InputLayout::eLineListWithAdjacency:
				result = "lines_adjacency";
				break;
			case ast::stmt::InputLayout::eLineStripWithAdjacency:
				result = "lines_adjacency";
				break;
			case ast::stmt::InputLayout::eTriangleListWithAdjacency:
				result = "triangles_adjacency";
				break;
			case ast::stmt::InputLayout::eTriangleStripWithAdjacency:
				result = "triangles_adjacency";
				break;
			default:
				throw std::runtime_error{ "Unsupported input layout." };
			}

			return result;
		}

		std::string getLayoutName( stmt::OutputLayout layout )
		{
			std::string result;

			switch ( layout )
			{
			case ast::stmt::OutputLayout::ePointList:
				result = "points";
				break;
			case ast::stmt::OutputLayout::eLineStrip:
				result = "line_strip";
				break;
			case ast::stmt::OutputLayout::eTriangleStrip:
				result = "triangle_strip";
				break;
			default:
				throw std::runtime_error{ "Unsupported output layout." };
			}

			return result;
		}

		bool isUnaryPre( expr::Kind kind )
		{
			bool result;

			switch ( kind )
			{
			case expr::Kind::eMbrSelect:
			case expr::Kind::ePostIncrement:
			case expr::Kind::ePostDecrement:
				result = false;
				break;
			case expr::Kind::eBitNot:
			case expr::Kind::eLogNot:
			case expr::Kind::eCast:
			case expr::Kind::ePreIncrement:
			case expr::Kind::ePreDecrement:
			case expr::Kind::eUnaryMinus:
			case expr::Kind::eUnaryPlus:
				result = true;
				break;
			default:
				throw std::runtime_error{ "Non unary expression" };
			}

			return result;
		}

		class ExprVisitor
			: public expr::SimpleVisitor
		{
		public:
			static std::string submit( expr::Expr * expr )
			{
				std::string result;
				ExprVisitor vis{ result };
				expr->accept( &vis );
				return result;
			}

		private:
			ExprVisitor( std::string & result )
				: m_result{ result }
			{
			}

			void wrap( expr::Expr * expr )
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

			void visitUnaryExpr( expr::Unary * expr )override
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

			void visitBinaryExpr( expr::Binary * expr )override
			{
				wrap( expr->getLHS() );
				m_result += " " + getOperatorName( expr->getKind() ) + " ";
				wrap( expr->getRHS() );
			}

			void visitAssignmentExpr( expr::Binary * expr )
			{
				wrap( expr->getLHS() );
				m_result += " " + getOperatorName( expr->getKind() ) + " ";
				expr->getRHS()->accept( this );
			}

			void visitAddAssignExpr( expr::AddAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitAndAssignExpr( expr::AndAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitAssignExpr( expr::Assign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitDivideAssignExpr( expr::DivideAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitLShiftAssignExpr( expr::LShiftAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitMinusAssignExpr( expr::MinusAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitModuloAssignExpr( expr::ModuloAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitOrAssignExpr( expr::OrAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitRShiftAssignExpr( expr::RShiftAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitTimesAssignExpr( expr::TimesAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}
			void visitXorAssignExpr( expr::XorAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
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

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				wrap( expr->getLHS() );
				m_result += "[";
				wrap( expr->getRHS() );
				m_result += "]";
			}

			void visitCastExpr( expr::Cast * expr )override
			{
				m_result += getTypeName( expr->getType() ) + "(";
				expr->getOperand()->accept( this );
				m_result += ")";
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				wrap( expr->getOuterExpr() );
				m_result += ".";
				expr->getOperand()->accept( this );
			}

			void visitFnCallExpr( expr::FnCall * expr )override
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

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				m_result += expr->getVariable()->getName();
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override
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

			void visitInitExpr( expr::Init * expr )override
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

			void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
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

			void visitLiteralExpr( expr::Literal * expr )override
			{
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

			void visitQuestionExpr( expr::Question *expr )override
			{
				m_result += "(";
				wrap( expr->getCtrlExpr() );
				m_result += " ? ";
				wrap( expr->getTrueExpr() );
				m_result += " : ";
				wrap( expr->getFalseExpr() );
				m_result += ")";
			}

			void visitSwitchCaseExpr( expr::SwitchCase *expr )override
			{
				expr->getLabel()->accept( this );
			}

			void visitSwitchTestExpr( expr::SwitchTest *expr )override
			{
				expr->getValue()->accept( this );
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override
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

		private:
			std::string & m_result;
		};

		class StmtVisitor
			: public stmt::Visitor
		{
		public:
			static std::string submit( stmt::Stmt * stmt
				, std::string indent = std::string{} )
			{
				std::string result;
				StmtVisitor vis{ result, std::move( indent ) };
				stmt->accept( &vis );
				return result;
			}

		private:
			StmtVisitor( std::string & result
				, std::string indent )
				: m_result{ result }
				, m_indent{ std::move( indent ) }
			{
			}

			void doAppendLineEnd()
			{
				if ( m_appendLineEnd && !m_result.empty() )
				{
					m_result += "\n";
				}

				m_appendLineEnd = false;
			}

			void visitContainerStmt( stmt::Container * stmt )override
			{
				for ( auto & stmt : *stmt )
				{
					stmt->accept( this );
				}
			}

			void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent;
				m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
				m_result += "uniform " + stmt->getName();
				m_appendSemiColon = true;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitDiscardStmt( stmt::Discard * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "discard;\n";
			}

			void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent;
				m_result += "layout(push_constant) ";
				m_result += "uniform " + stmt->getName();
				m_appendSemiColon = true;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitCompoundStmt( stmt::Compound * stmt )override
			{
				doAppendLineEnd();

				if ( stmt->empty() )
				{
					m_result += ";\n";
				}
				else
				{
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
			}

			void visitDoWhileStmt( stmt::DoWhile * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "do";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ");\n";
				m_appendLineEnd = true;
			}

			void visitElseIfStmt( stmt::ElseIf * stmt )override
			{
				m_result += m_indent + "else if (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
				m_appendSemiColon = false;
				m_appendLineEnd = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitElseStmt( stmt::Else * stmt )override
			{
				m_result += m_indent + "else";
				m_appendSemiColon = false;
				m_appendLineEnd = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitForStmt( stmt::For * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "for (" + ExprVisitor::submit( stmt->getInitExpr() ) + "; ";
				m_result += ExprVisitor::submit( stmt->getCtrlExpr() ) + "; ";
				m_result += ExprVisitor::submit( stmt->getIncrExpr() ) + ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + getTypeName( stmt->getRet() );
				m_result += " " + stmt->getName() + "(";
				std::string sep;

				for ( auto & param : stmt->getParameters() )
				{
					m_result += sep + getDirectionName( *param )
						+ " " + getTypeName( param->getType() )
						+ " " + param->getName();
					sep = ", ";
				}

				m_result += ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitIfStmt( stmt::If * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "if (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
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

			void visitImageDeclStmt( stmt::ImageDecl * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent;
				m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
				m_result += getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
				auto arraySize = stmt->getVariable()->getType()->getArraySize();

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

				m_result += ";\n";
			}

			void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent;
				m_result += "layout(" + getLocationName( *stmt->getVariable() ) + "=" + std::to_string( stmt->getLocation() ) + ") ";
				m_result += getDirectionName( *stmt->getVariable() ) + " ";
				m_result += getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
				auto arraySize = stmt->getVariable()->getType()->getArraySize();

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

				m_result += ";\n";
			}

			void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "layout(local_size_x=" + std::to_string( stmt->getWorkGroupsX() )
					+ ", local_size_y=" + std::to_string( stmt->getWorkGroupsY() )
					+ ", local_size_z=" + std::to_string( stmt->getWorkGroupsZ() ) + ") in;\n";
			}

			void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ") in;\n";
			}

			void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + "layout(" + getLayoutName( stmt->getLayout() ) + ", max_vertices = " + std::to_string( stmt->getPrimCount() ) + ") out;\n";
			}

			void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				std::string decl;
				decl += "gl_PerVertex\n";
				decl += m_indent + "{\n";
				decl += m_indent + "	vec4 gl_Position;\n";
				decl += m_indent + "	float gl_PointSize;\n";
				decl += m_indent + "	float gl_ClipDistance[];\n";
				decl += m_indent + "}";
				switch ( stmt->getSource() )
				{
				case stmt::PerVertexDecl::Source::eVertexOutput:
					m_result += m_indent + "out " + decl + ";\n";
					break;
				case stmt::PerVertexDecl::Source::eTessellationControlInput:
				case stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
					m_result += m_indent + "in " + decl + " gl_in[gl_MaxPatchVertices];\n";
					break;
				case stmt::PerVertexDecl::Source::eTessellationControlOutput:
					m_result += m_indent + "out " + decl + " gl_out[];\n";
					break;
				case stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
					m_result += m_indent + "out " + decl + ";\n";
					break;
				case stmt::PerVertexDecl::Source::eGeometryInput:
					m_result += m_indent + "in " + decl + " gl_in[];\n";
					break;
				case stmt::PerVertexDecl::Source::eGeometryOutput:
					m_result += m_indent + "out " + decl + ";\n";
					break;
				}
			}

			void visitReturnStmt( stmt::Return * stmt )override
			{
				doAppendLineEnd();

				if ( stmt->getExpr() )
				{
					m_result += m_indent + "return " + ExprVisitor::submit( stmt->getExpr() ) + ";\n";
				}
				else
				{
					m_result += m_indent + "return;\n";
				}
			}

			void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent;
				m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
				m_result += getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
				auto arraySize = stmt->getVariable()->getType()->getArraySize();

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

				m_result += ";\n";
			}

			void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent;
				m_result += "layout(binding=" + std::to_string( stmt->getBindingPoint() ) + ", set=" + std::to_string( stmt->getBindingSet() ) + ") ";
				m_result += "buffer " + stmt->getName();
				m_appendSemiColon = true;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitSimpleStmt( stmt::Simple * stmt )
			{
				doAppendLineEnd();
				m_result += m_indent + ExprVisitor::submit( stmt->getExpr() ) + ";\n";
			}

			void visitStructureDeclStmt( stmt::StructureDecl * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "struct " + stmt->getType().getName();

				if ( !stmt->getType().empty() )
				{
					m_result += "\n" + m_indent + "{\n";
					auto save = m_indent;
					m_indent += "\t";

					for ( auto & member : stmt->getType() )
					{
						m_result += m_indent + getTypeName( member.type ) + " " + member.name;
						auto arraySize = member.type->getArraySize();

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

						m_result += ";\n";
					}

					m_indent = save;
					m_result += m_indent + "};\n";
				}
				else
				{
					m_result += ";\n";
				}
			}

			void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override
			{
				doAppendLineEnd();

				if ( stmt->getCaseExpr() )
				{
					m_result += m_indent + "case " + ExprVisitor::submit( stmt->getCaseExpr() ) + ":";
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

			void visitSwitchStmt( stmt::Switch * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "switch (" + ExprVisitor::submit( stmt->getTestExpr() ) + ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitVariableDeclStmt( stmt::VariableDecl * stmt )override
			{
				doAppendLineEnd();
				m_result += m_indent + getTypeName( stmt->getVariable()->getType() ) + " " + stmt->getVariable()->getName();
				auto arraySize = stmt->getVariable()->getType()->getArraySize();

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

				m_result += ";\n";
			}

			void visitWhileStmt( stmt::While * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "while (" + ExprVisitor::submit( stmt->getCtrlExpr() ) + ")";
				m_appendSemiColon = false;
				visitCompoundStmt( stmt );
				m_appendLineEnd = true;
			}

			void visitPreprocDefine( stmt::PreprocDefine * preproc )override
			{
				doAppendLineEnd();
				m_result += "#define " + preproc->getName() + " " + ExprVisitor::submit( preproc->getExpr() ) + "\n";
			}

			void visitPreprocElif( stmt::PreprocElif * preproc )override
			{
				doAppendLineEnd();
				m_result += "#elif " + ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
			}

			void visitPreprocElse( stmt::PreprocElse * preproc )override
			{
				doAppendLineEnd();
				m_result += "#else\n";
			}

			void visitPreprocEndif( stmt::PreprocEndif * preproc )override
			{
				doAppendLineEnd();
				m_result += "#endif\n";
			}

			void visitPreprocExtension( stmt::PreprocExtension * preproc )override
			{
				doAppendLineEnd();
				m_result += "#extension " + preproc->getName() + ": " + getStatusName( preproc->getStatus() ) + "\n";
			}

			void visitPreprocIf( stmt::PreprocIf * preproc )override
			{
				doAppendLineEnd();
				m_result += "#if " + ExprVisitor::submit( preproc->getCtrlExpr() ) + "\n";
			}

			void visitPreprocIfDef( stmt::PreprocIfDef * preproc )override
			{
				doAppendLineEnd();
				m_result += "#ifdef " + ExprVisitor::submit( preproc->getIdentExpr() ) + "\n";
			}

			void visitPreprocVersion( stmt::PreprocVersion * preproc )override
			{
				doAppendLineEnd();
				m_result += "#version " + preproc->getName() + "\n";
			}
		private:
			std::string m_indent;
			bool m_appendSemiColon{ false };
			bool m_appendLineEnd{ false };
			std::string & m_result;
		};
	}

	std::string writeGlsl( Shader & shader, ShaderType type )
	{
		return glsl::StmtVisitor::submit( shader.getStatements() );
	}
}
