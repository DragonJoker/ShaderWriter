/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterHlsl.hpp"

#include "ShaderWriter/CloneExpr.hpp"
#include "ShaderWriter/Shader.hpp"

#include <ASTGenerator/Expr/ExprVisitor.hpp>
#include <ASTGenerator/Stmt/StmtVisitor.hpp>

#include "ShaderWriter/HlslImageAccessNames.hpp"
#include "ShaderWriter/HlslIntrinsicNames.hpp"
#include "ShaderWriter/HlslTextureAccessNames.hpp"

#include <sstream>

namespace sdw
{
	namespace hlsl
	{
		bool isSampler( type::Kind kind )
		{
			switch ( kind )
			{
			case ast::type::Kind::eSampler1DF:
			case ast::type::Kind::eSampler2DF:
			case ast::type::Kind::eSampler3DF:
			case ast::type::Kind::eSamplerCubeF:
			case ast::type::Kind::eSampler2DRectF:
			case ast::type::Kind::eSampler1DArrayF:
			case ast::type::Kind::eSampler2DArrayF:
			case ast::type::Kind::eSamplerCubeArrayF:
			case ast::type::Kind::eSampler1DShadowF:
			case ast::type::Kind::eSampler2DShadowF:
			case ast::type::Kind::eSamplerCubeShadowF:
			case ast::type::Kind::eSampler2DRectShadowF:
			case ast::type::Kind::eSampler1DArrayShadowF:
			case ast::type::Kind::eSampler2DArrayShadowF:
			case ast::type::Kind::eSamplerCubeArrayShadowF:
			case ast::type::Kind::eSampler1DI:
			case ast::type::Kind::eSampler2DI:
			case ast::type::Kind::eSampler3DI:
			case ast::type::Kind::eSamplerCubeI:
			case ast::type::Kind::eSampler2DRectI:
			case ast::type::Kind::eSampler1DArrayI:
			case ast::type::Kind::eSampler2DArrayI:
			case ast::type::Kind::eSamplerCubeArrayI:
			case ast::type::Kind::eSampler1DU:
			case ast::type::Kind::eSampler2DU:
			case ast::type::Kind::eSampler3DU:
			case ast::type::Kind::eSamplerCubeU:
			case ast::type::Kind::eSampler2DRectU:
			case ast::type::Kind::eSampler1DArrayU:
			case ast::type::Kind::eSampler2DArrayU:
			case ast::type::Kind::eSamplerCubeArrayU:
			case ast::type::Kind::eCount:
				return true;

			default:
				return false;
			}
		}

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
				result = "bool2";
				break;
			case type::Kind::eVec3B:
				result = "bool3";
				break;
			case type::Kind::eVec4B:
				result = "bool4";
				break;
			case type::Kind::eVec2I:
				result = "int2";
				break;
			case type::Kind::eVec3I:
				result = "int3";
				break;
			case type::Kind::eVec4I:
				result = "int4";
				break;
			case type::Kind::eVec2U:
				result = "uint2";
				break;
			case type::Kind::eVec3U:
				result = "uint3";
				break;
			case type::Kind::eVec4U:
				result = "uint4";
				break;
			case type::Kind::eVec2F:
				result = "float2";
				break;
			case type::Kind::eVec3F:
				result = "float3";
				break;
			case type::Kind::eVec4F:
				result = "float4";
				break;
			case type::Kind::eVec2D:
				result = "double2";
				break;
			case type::Kind::eVec3D:
				result = "double3";
				break;
			case type::Kind::eVec4D:
				result = "double4";
				break;
			case type::Kind::eMat2x2F:
				result = "float2x2";
				break;
			case type::Kind::eMat2x3F:
				result = "float2x3";
				break;
			case type::Kind::eMat2x4F:
				result = "float2x4";
				break;
			case type::Kind::eMat3x3F:
				result = "float3x3";
				break;
			case type::Kind::eMat3x2F:
				result = "float3x2";
				break;
			case type::Kind::eMat3x4F:
				result = "float3x4";
				break;
			case type::Kind::eMat4x4F:
				result = "float4x4";
				break;
			case type::Kind::eMat4x2F:
				result = "float4x2";
				break;
			case type::Kind::eMat4x3F:
				result = "float4x3";
				break;
			case type::Kind::eMat2x2D:
				result = "double2x2";
				break;
			case type::Kind::eMat2x3D:
				result = "double2x3";
				break;
			case type::Kind::eMat2x4D:
				result = "double2x4";
				break;
			case type::Kind::eMat3x3D:
				result = "double3x3";
				break;
			case type::Kind::eMat3x2D:
				result = "double3x2";
				break;
			case type::Kind::eMat3x4D:
				result = "double3x4";
				break;
			case type::Kind::eMat4x4D:
				result = "double4x4";
				break;
			case type::Kind::eMat4x2D:
				result = "double4x2";
				break;
			case type::Kind::eMat4x3D:
				result = "double4x3";
				break;
			case type::Kind::eConstantsBuffer:
				result = "cbuffer";
				break;
			case type::Kind::eShaderBuffer:
				result = "buffer";
				break;
			case type::Kind::eSamplerBufferF:
				result = "Buffer<float4>";
				break;
			case type::Kind::eSampler1DF:
				result = "Texture1D<float4>";
				break;
			case type::Kind::eSampler2DF:
				result = "Texture2D<float4>";
				break;
			case type::Kind::eSampler3DF:
				result = "Texture3D<float4>";
				break;
			case type::Kind::eSamplerCubeF:
				result = "TextureCube<float4>";
				break;
			case type::Kind::eSampler2DRectF:
				result = "Texture2D<float4>";
				break;
			case type::Kind::eSampler1DArrayF:
				result = "Texture1DArray<float4>";
				break;
			case type::Kind::eSampler2DArrayF:
				result = "Texture2DArray<float4>";
				break;
			case type::Kind::eSamplerCubeArrayF:
				result = "TextureCubeArray<float4>";
				break;
			case type::Kind::eSampler1DShadowF:
				result = "Texture1D<float4>";
				break;
			case type::Kind::eSampler2DShadowF:
				result = "Texture2D<float4>";
				break;
			case type::Kind::eSamplerCubeShadowF:
				result = "TextureCube<float4>";
				break;
			case type::Kind::eSampler2DRectShadowF:
				result = "Texture2DArray<float4>";
				break;
			case type::Kind::eSampler1DArrayShadowF:
				result = "Texture1DArray<float4>";
				break;
			case type::Kind::eSampler2DArrayShadowF:
				result = "Texture2DArray<float4>";
				break;
			case type::Kind::eSamplerCubeArrayShadowF:
				result = "TextureCubeArray<float4>";
				break;
			case type::Kind::eSamplerBufferI:
				result = "Buffer<int4>";
				break;
			case type::Kind::eSampler1DI:
				result = "Texture1D<int4>";
				break;
			case type::Kind::eSampler2DI:
				result = "Texture2D<int4>";
				break;
			case type::Kind::eSampler3DI:
				result = "Texture3D<int4>";
				break;
			case type::Kind::eSamplerCubeI:
				result = "TextureCube<int4>";
				break;
			case type::Kind::eSampler2DRectI:
				result = "Texture2D<int4>";
				break;
			case type::Kind::eSampler1DArrayI:
				result = "Texture1DArray<int4>";
				break;
			case type::Kind::eSampler2DArrayI:
				result = "Texture2DArray<int4>";
				break;
			case type::Kind::eSamplerCubeArrayI:
				result = "TextureCubeArray<int4>";
				break;
			case type::Kind::eSamplerBufferU:
				result = "Buffer<uint4>";
				break;
			case type::Kind::eSampler1DU:
				result = "Texture1D<uint4>";
				break;
			case type::Kind::eSampler2DU:
				result = "Texture2D<uint4>";
				break;
			case type::Kind::eSampler3DU:
				result = "Texture3D<uint4>";
				break;
			case type::Kind::eSamplerCubeU:
				result = "TextureCube<uint4>";
				break;
			case type::Kind::eSampler2DRectU:
				result = "Texture2D<uint4>";
				break;
			case type::Kind::eSampler1DArrayU:
				result = "Texture1DArray<uint4>";
				break;
			case type::Kind::eSampler2DArrayU:
				result = "Texture2DArray<uint4>";
				break;
			case type::Kind::eSamplerCubeArrayU:
				result = "TextureCubeArray<uint4>";
				break;
			case type::Kind::eImageBufferF:
				result = "RWBuffer<float4>";
				break;
			case type::Kind::eImage1DF:
				result = "RWTexture1D<float4>";
				break;
			case type::Kind::eImage2DF:
				result = "RWTexture2D<float4>";
				break;
			case type::Kind::eImage3DF:
				result = "RWTexture3D<float4>";
				break;
			case type::Kind::eImageCubeF:
				result = "RWTexture2DArray<float4>";
				break;
			case type::Kind::eImage2DRectF:
				result = "RWTexture2D<float4>";
				break;
			case type::Kind::eImage1DArrayF:
				result = "RWTexture1DArray<float4>";
				break;
			case type::Kind::eImage2DArrayF:
				result = "RWTexture2DArray<float4>";
				break;
			case type::Kind::eImageCubeArrayF:
				result = "RWTexture2DArray<float4>";
				break;
			case type::Kind::eImage2DMSF:
				result = "Texture2DMS<float4>";
				break;
			case type::Kind::eImage2DMSArrayF:
				result = "Texture2DMSArray<float4>";
				break;
			case type::Kind::eImageBufferI:
				result = "RWBuffer<int4>";
				break;
			case type::Kind::eImage1DI:
				result = "RWTexture1D<int4>";
				break;
			case type::Kind::eImage2DI:
				result = "RWTexture2D<int4>";
				break;
			case type::Kind::eImage3DI:
				result = "RWTexture3D<int4>";
				break;
			case type::Kind::eImageCubeI:
				result = "RWTexture2DArray<int4>";
				break;
			case type::Kind::eImage2DRectI:
				result = "RWTexture2D<int4>";
				break;
			case type::Kind::eImage1DArrayI:
				result = "RWTexture1DArray<int4>";
				break;
			case type::Kind::eImage2DArrayI:
				result = "RWTexture2DArray<int4>";
				break;
			case type::Kind::eImageCubeArrayI:
				result = "RWTexture2DArray<int4>";
				break;
			case type::Kind::eImage2DMSI:
				result = "Texture2DMS<int4>";
				break;
			case type::Kind::eImage2DMSArrayI:
				result = "Texture2DMSArray<int4>";
				break;
			case type::Kind::eImageBufferU:
				result = "RWBuffer<uint4>";
				break;
			case type::Kind::eImage1DU:
				result = "RWTexture1D<uint4>";
				break;
			case type::Kind::eImage2DU:
				result = "RWTexture2D<uint4>";
				break;
			case type::Kind::eImage3DU:
				result = "RWTexture3D<uint4>";
				break;
			case type::Kind::eImageCubeU:
				result = "RWTexture2DArray<uint4>";
				break;
			case type::Kind::eImage2DRectU:
				result = "RWTexture2D<uint4>";
				break;
			case type::Kind::eImage1DArrayU:
				result = "RWTexture1DArray<uint4>";
				break;
			case type::Kind::eImage2DArrayU:
				result = "RWTexture2DArray<uint4>";
				break;
			case type::Kind::eImageCubeArrayU:
				result = "RWTexture2DArray<uint4>";
				break;
			case type::Kind::eImage2DMSU:
				result = "Texture2DMS<uint4>";
				break;
			case type::Kind::eImage2DMSArrayU:
				result = "Texture2DMSArray<uint4>";
				break;
			case type::Kind::eCount:
				result = "SamplerState";
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
				result = static_cast< type::Struct const & >( *type ).getName();
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
				result = "inout ";
			}
			else if ( var.isInputParam()
				|| var.isShaderInput() )
			{
				result = "in ";
			}
			else if ( var.isOutputParam()
				|| var.isShaderOutput() )
			{
				result = "out ";
			}
			else if ( var.isShaderConstant() )
			{
				result = "const ";
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
				result = "";
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
				result = "point";
				break;
			case ast::stmt::InputLayout::eLineList:
			case ast::stmt::InputLayout::eLineStrip:
				result = "line";
				break;
			case ast::stmt::InputLayout::eTriangleList:
			case ast::stmt::InputLayout::eTriangleStrip:
			case ast::stmt::InputLayout::eTriangleFan:
				result = "triangle";
				break;
			case ast::stmt::InputLayout::eLineListWithAdjacency:
			case ast::stmt::InputLayout::eLineStripWithAdjacency:
				result = "lineadj";
				break;
			case ast::stmt::InputLayout::eTriangleListWithAdjacency:
			case ast::stmt::InputLayout::eTriangleStripWithAdjacency:
				result = "triangleadj";
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
				result = "PointStream";
				break;
			case ast::stmt::OutputLayout::eLineStrip:
				result = "LineStream";
				break;
			case ast::stmt::OutputLayout::eTriangleStrip:
				result = "TriangleStream";
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

				m_result += " = {";
				std::string sep;

				for ( auto & init : expr->getInitialisers() )
				{
					m_result += sep + submit( init.get() );
					sep = ", ";
				}

				m_result += "}";
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

		private:
			std::string & m_result;
		};

		class StmtVisitor
			: public stmt::Visitor
		{
		public:
			static std::string submit( stmt::Stmt * stmt
				, ShaderType type
				, std::string indent = std::string{} )
			{
				std::string result;
				StmtVisitor vis{ result, type, std::move( indent ) };
				stmt->accept( &vis );
				return result;
			}

		private:
			StmtVisitor( std::string & result
				, ShaderType type
				, std::string indent )
				: m_result{ result }
				, m_indent{ std::move( indent ) }
				, m_type{ type }
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
				m_result += m_indent + "cbuffer " + stmt->getName() + ": register(b" + std::to_string( stmt->getBindingPoint() ) + ")";
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
						+ getTypeName( param->getType() ) + " "
						+ param->getName();
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
				m_result += getTypeName( stmt->getVariable()->getType() ) + " ";
				m_result += stmt->getVariable()->getName() + ": register(u" + std::to_string( stmt->getBindingPoint() ) + ")";

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
				m_result += getDirectionName( *stmt->getVariable() );
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
				m_result += m_indent + "SamplerState " + stmt->getVariable()->getName() + ": register(s" + std::to_string( stmt->getBindingPoint() ) + ");\n";
			}

			void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override
			{
				m_appendLineEnd = true;
				doAppendLineEnd();
				m_result += m_indent + "struct " + stmt->getName() + "Struct";
				m_appendSemiColon = true;
				visitCompoundStmt( stmt );
				m_result += m_indent + "StructuredBuffer<" + stmt->getName() + "Struct> " + stmt->getName() + ": register(u" + std::to_string( stmt->getBindingPoint() ) + ");\n";
			}

			void visitSimpleStmt( stmt::Simple * stmt )override
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
			}

		private:
			std::string m_indent;
			std::string & m_result;
			bool m_appendSemiColon{ false };
			bool m_appendLineEnd{ false };
			ShaderType m_type;
		};

		using LinkedVars = std::map< var::VariablePtr, std::pair< var::VariablePtr, var::VariablePtr > >;
		using VariableExprMap = std::map< var::VariablePtr, expr::ExprPtr >;

		class VariableReplacer
			: public ExprCloner
		{
		public:
			static expr::ExprPtr submit( expr::Expr * expr
				, var::VariablePtr origin
				, var::VariablePtr replacement )
			{
				expr::ExprPtr result;
				VariableReplacer vis{ result, origin, replacement };
				expr->accept( &vis );
				return result;
			}
			
			static expr::ExprPtr submit( expr::ExprPtr const & expr
				, var::VariablePtr origin
				, var::VariablePtr replacement )
			{
				return submit( expr.get(), origin, replacement );
			}

		private:
			VariableReplacer( expr::ExprPtr & result
				, var::VariablePtr origin
				, var::VariablePtr replacement )
				: ExprCloner{ result }
				, m_origin{ origin }
				, m_replacement{ replacement }
			{
			}

			ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override
			{
				expr::ExprPtr result;
				VariableReplacer vis{ result, m_origin, m_replacement };
				expr->accept( &vis );
				return result;
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				if ( expr->getVariable() == m_origin )
				{
					m_result = expr::makeIdentifier( m_replacement );
				}
				else
				{
					m_result = expr::makeIdentifier( expr->getVariable() );
				}
			}

		private:
			var::VariablePtr m_origin;
			var::VariablePtr m_replacement;
		};

		class ExprAdapter
			: public ExprCloner
		{
		public:
			static expr::ExprPtr submit( expr::Expr * expr
				, LinkedVars const & linkedVars
				, VariableExprMap const & inputMembers
				, VariableExprMap const & outputMembers )
			{
				expr::ExprPtr result;
				ExprAdapter vis{ result, linkedVars, inputMembers, outputMembers };
				expr->accept( &vis );
				return result;
			}
			
			static expr::ExprPtr submit( expr::ExprPtr const & expr
				, LinkedVars const & linkedVars
				, VariableExprMap const & inputMembers
				, VariableExprMap const & outputMembers )
			{
				return submit( expr.get()
					, linkedVars
					, inputMembers
					, outputMembers );
			}

		private:
			ExprAdapter( expr::ExprPtr & result
				, LinkedVars const & linkedVars
				, VariableExprMap const & inputMembers
				, VariableExprMap const & outputMembers )
				: ExprCloner{ result }
				, m_linkedVars{ linkedVars }
				, m_inputMembers{ inputMembers }
				, m_outputMembers{ outputMembers }
			{
			}

			ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override
			{
				expr::ExprPtr result;
				ExprAdapter vis{ result, m_linkedVars, m_inputMembers, m_outputMembers };
				expr->accept( &vis );
				return result;
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				auto itInputs = m_inputMembers.find( expr->getVariable() );
				auto itOutputs = m_outputMembers.find( expr->getVariable() );

				if ( m_inputMembers.end() != itInputs )
				{
					m_result = makeExpr( itInputs->second );
				}
				else if ( m_outputMembers.end() != itOutputs )
				{
					m_result = makeExpr( itOutputs->second );
				}
				else
				{
					m_result = expr::makeIdentifier( expr->getVariable() );
				}
			}

			void visitFnCallExpr( expr::FnCall * expr )override
			{
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					auto ident = findIdentifier( arg );

					if ( ident )
					{
						auto it = m_linkedVars.find( ident->getVariable() );

						if ( m_linkedVars.end() != it )
						{
							args.emplace_back( VariableReplacer::submit( arg, ident->getVariable(), it->second.first ) );
							args.emplace_back( VariableReplacer::submit( arg, ident->getVariable(), it->second.second ) );
						}
						else
						{
							args.emplace_back( doSubmit( arg.get() ) );
						}
					}
					else
					{
						args.emplace_back( doSubmit( arg.get() ) );
					}
				}

				m_result = expr::makeFnCall( expr->getType()
					, std::make_unique< expr::Identifier >( *expr->getFn() )
					, std::move( args ) );
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * expr )override
			{
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					if ( arg->getKind() == expr::Kind::eIdentifier )
					{
						auto ident = findIdentifier( arg );
						auto it = m_linkedVars.find( ident->getVariable() );

						if ( m_linkedVars.end() != it )
						{
							args.emplace_back( makeIdent( it->second.first ) );
							args.emplace_back( makeIdent( it->second.second ) );
						}
						else
						{
							args.emplace_back( doSubmit( arg.get() ) );
						}
					}
					else
					{
						args.emplace_back( doSubmit( arg.get() ) );
					}
				}

				m_result = expr::makeTextureAccessCall( expr->getType()
					, expr->getTextureAccess()
					, std::move( args ) );
			}

		private:
			LinkedVars const & m_linkedVars;
			VariableExprMap const & m_inputMembers;
			VariableExprMap const & m_outputMembers;
		};

		class SamplerState
			: public type::Type
		{
		public:
			SamplerState()
				: type::Type{ type::Kind::eCount }
			{
			}
		};
		using SamplerStatePtr = std::shared_ptr< SamplerState >;
		SamplerStatePtr makeSampler()
		{
			return std::make_shared< SamplerState >();
		}

		class StmtAdapter
			: public stmt::Visitor
		{
		public:
			static stmt::ContainerPtr submit( Shader & shader, ShaderType type )
			{
				auto result = stmt::makeContainer();
				StmtAdapter vis{ shader, type, result.get() };
				shader.getStatements()->accept( &vis );
				return result;
			}

		private:
			StmtAdapter( Shader & shader
				, ShaderType type
				, stmt::Container * result )
				: m_shader{ shader }
				, m_result{ result }
				, m_type{ type }
			{
				m_inputStruct = type::makeStructType( "HLSL_SDW_Input" );
				m_outputStruct = type::makeStructType( "HLSL_SDW_Output" );
				m_result->addStmt( stmt::makeStructureDecl( m_inputStruct ) );
				m_result->addStmt( stmt::makeStructureDecl( m_outputStruct ) );
				m_inputVar = m_shader.registerName( "sdwInput", m_inputStruct, var::Flag::eInputParam );
				m_outputVar = m_shader.registerName( "sdwOutput", m_outputStruct );
			}

			void visitContainerStmt( stmt::Container * cont )override
			{
				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}
			}

			void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeConstantBufferDecl( stmt->getName()
					, stmt->getBindingPoint()
					, stmt->getBindingSet() );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitDiscardStmt( stmt::Discard * stmt )override
			{
				m_result->addStmt( stmt::makeDiscard() );
			}

			void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makePushConstantsBufferDecl( stmt->getName() );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitCompoundStmt( stmt::Compound * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeContainer();
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitDoWhileStmt( stmt::DoWhile * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeDoWhile( ExprAdapter::submit( stmt->getCtrlExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitElseIfStmt( stmt::ElseIf * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeElseIf( ExprAdapter::submit( stmt->getCtrlExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitElseStmt( stmt::Else * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeElse();
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitForStmt( stmt::For * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeFor( ExprAdapter::submit( stmt->getInitExpr()
						, m_linkedVars
						, m_inputMembers
						, m_outputMembers )
					, ExprAdapter::submit( stmt->getCtrlExpr()
						, m_linkedVars
						, m_inputMembers
						, m_outputMembers )
					, ExprAdapter::submit( stmt->getIncrExpr()
						, m_linkedVars
						, m_inputMembers
						, m_outputMembers ) );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override
			{
				auto save = m_result;
				stmt::FunctionDeclPtr cont;
				auto linkedVars = m_linkedVars;

				if ( stmt->getName() == "main" )
				{
					std::string outputName = "TEXCOORD";
					std::string inputName = "TEXCOORD";
					uint32_t index = 0u;

					for ( auto & input : m_inputVars )
					{
						m_inputStruct->addMember( input.second->getType(), input.second->getName() + ": " + inputName + std::to_string( index++ ) );
					}

					index = 0u;

					if ( m_type == ShaderType::eFragment )
					{
						outputName = "SV_TARGET";
					}
					else if ( m_type == ShaderType::eCompute )
					{
					}

					for ( auto & output : m_outputVars )
					{
						if ( output.second->getName() == "gl_Position" )
						{
							m_outputStruct->addMember( output.second->getType(), output.second->getName() + ": SV_POSITION" );
						}
						else
						{
							m_outputStruct->addMember( output.second->getType(), output.second->getName() + ": " + outputName + std::to_string( index++ ) );
						}
					}

					assert( stmt->getParameters().empty() );
					assert( stmt->getRet()->getKind() == type::Kind::eVoid );
					var::VariableList parameters;
					parameters.emplace_back( m_inputVar );
					cont = stmt::makeFunctionDecl( m_outputStruct
						, stmt->getName()
						, parameters );
					cont->addStmt( stmt::makeVariableDecl( m_outputVar ) );
				}
				else
				{
					var::VariableList params;

					for ( auto & param : stmt->getParameters() )
					{
						if ( isSampler( param->getType()->getKind() ) )
						{
							auto texture = var::makeVariable( param->getType()
								, param->getName() + "_texture" );
							auto sampler = var::makeVariable( makeSampler()
								, param->getName() + "_sampler" );
							m_linkedVars.emplace( param, std::make_pair( texture, sampler ) );
							params.push_back( texture );
							params.push_back( sampler );
						}
						else
						{
							params.push_back( param );
						}
					}

					cont = stmt::makeFunctionDecl( stmt->getRet()
						, stmt->getName()
						, params );
				}

				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;

				if ( stmt->getName() == "main" )
				{
					cont->addStmt( stmt::makeReturn( expr::makeIdentifier( m_outputVar ) ) );
				}

				m_result->addStmt( std::move( cont ) );
				m_linkedVars = linkedVars;
			}

			void visitIfStmt( stmt::If * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeElseIf( ExprAdapter::submit( stmt->getCtrlExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );

				for ( auto & elseIf : stmt->getElseIfList() )
				{
					elseIf->accept( this );
				}

				if ( stmt->getElse() )
				{
					stmt->getElse()->accept( this );
				}
			}

			void visitImageDeclStmt( stmt::ImageDecl * stmt )override
			{
				m_result->addStmt( stmt::makeImageDecl( stmt->getVariable()
					, stmt->getBindingPoint()
					, stmt->getBindingSet() ) );
			}

			void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override
			{
				auto & var = stmt->getVariable();

				if ( var->isShaderInput() )
				{
					m_inputVars.emplace( stmt->getLocation(), var );
					m_inputMembers.emplace( var, expr::makeMbrSelect( makeIdent( m_inputVar ), makeIdent( var ) ) );
				}
				else if ( var->isShaderOutput() )
				{
					m_outputVars.emplace( stmt->getLocation(), var );
					m_outputMembers.emplace( var, expr::makeMbrSelect( makeIdent( m_outputVar ), makeIdent( var ) ) );
				}
			}

			void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override
			{
				m_inputComputeLayout = stmt;
			}

			void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override
			{
				m_inputGeometryLayout = stmt;
			}

			void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override
			{
				m_outputGeometryLayout = stmt;
			}

			void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override
			{
				auto index = 128u;

				for ( auto & member : *stmt->getType() )
				{
					if ( member.name == "gl_Position" )
					{
						auto outputVar = m_shader.getVar( member.name, member.type );
						m_outputMembers.emplace( outputVar, expr::makeMbrSelect( makeIdent( m_outputVar ), makeIdent( outputVar ) ) );
						m_outputVars.emplace( index++, outputVar );
					}
				}
			}

			void visitReturnStmt( stmt::Return * stmt )override
			{
				if ( stmt->getExpr() )
				{
					m_result->addStmt( stmt::makeReturn( ExprAdapter::submit( stmt->getExpr()
						, m_linkedVars
						, m_inputMembers
						, m_outputMembers ) ) );
				}
				else
				{
					m_result->addStmt( stmt::makeReturn() );
				}
			}

			void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override
			{
				auto originalVar = stmt->getVariable();
				auto textureVar = m_shader.registerImage( stmt->getVariable()->getName() + "_texture"
					, stmt->getVariable()->getType()
					, stmt->getBindingPoint()
					, stmt->getBindingSet() );
				m_result->addStmt( stmt::makeImageDecl( textureVar
					, stmt->getBindingPoint()
					, stmt->getBindingSet() ) );

				if ( stmt->getVariable()->getType()->getKind() != type::Kind::eSamplerBufferF
					&& stmt->getVariable()->getType()->getKind() != type::Kind::eSamplerBufferI
					&& stmt->getVariable()->getType()->getKind() != type::Kind::eSamplerBufferU )
				{
					auto samplerVar = m_shader.registerSampler( stmt->getVariable()->getName() + "_sampler"
						, makeSampler()
						, stmt->getBindingPoint()
						, stmt->getBindingSet() );
					linkVars( originalVar, textureVar, samplerVar );
					m_result->addStmt( stmt::makeSamplerDecl( samplerVar
						, stmt->getBindingPoint()
						, stmt->getBindingSet() ) );
				}
			}

			void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeShaderBufferDecl( stmt->getName()
					, stmt->getBindingPoint()
					, stmt->getBindingSet() );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitSimpleStmt( stmt::Simple * stmt )override
			{
				m_result->addStmt( stmt::makeSimple( ExprAdapter::submit( stmt->getExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) ) );
			}

			void visitStructureDeclStmt( stmt::StructureDecl * stmt )override
			{
				m_result->addStmt( stmt::makeStructureDecl( std::make_shared< type::Struct >( stmt->getType() ) ) );
			}

			void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeSwitchCase( expr::makeSwitchCase( std::make_unique< expr::Literal >( *stmt->getCaseExpr()->getLabel() ) ) );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitSwitchStmt( stmt::Switch * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeSwitch( expr::makeSwitchTest( ExprAdapter::submit( stmt->getTestExpr()->getValue()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) ) );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitVariableDeclStmt( stmt::VariableDecl * stmt )override
			{
				m_result->addStmt( stmt::makeVariableDecl( stmt->getVariable() ) );
			}

			void visitWhileStmt( stmt::While * stmt )override
			{
				auto save = m_result;
				auto cont = stmt::makeWhile( ExprAdapter::submit( stmt->getCtrlExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) );
				m_result = cont.get();
				visitContainerStmt( stmt );
				m_result = save;
				m_result->addStmt( std::move( cont ) );
			}

			void visitPreprocDefine( stmt::PreprocDefine * preproc )override
			{
				m_result->addStmt( stmt::makePreprocDefine( preproc->getName(), ExprAdapter::submit( preproc->getExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) ) );
			}

			void visitPreprocElif( stmt::PreprocElif * preproc )override
			{
				m_result->addStmt( stmt::makePreprocElif( ExprAdapter::submit( preproc->getCtrlExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) ) );
			}

			void visitPreprocElse( stmt::PreprocElse * preproc )override
			{
				m_result->addStmt( stmt::makePreprocElse() );
			}

			void visitPreprocEndif( stmt::PreprocEndif * preproc )override
			{
				m_result->addStmt( stmt::makePreprocEndif() );
			}

			void visitPreprocExtension( stmt::PreprocExtension * preproc )override
			{
			}

			void visitPreprocIf( stmt::PreprocIf * preproc )override
			{
				m_result->addStmt( stmt::makePreprocIf( ExprAdapter::submit( preproc->getCtrlExpr()
					, m_linkedVars
					, m_inputMembers
					, m_outputMembers ) ) );
			}

			void visitPreprocIfDef( stmt::PreprocIfDef * preproc )override
			{
				m_result->addStmt( stmt::makePreprocIfDef( makeIdent( preproc->getIdentExpr()->getVariable() ) ) );
			}

			void visitPreprocVersion( stmt::PreprocVersion * preproc )override
			{
			}

			void linkVars( var::VariablePtr textureSampler, var::VariablePtr texture, var::VariablePtr sampler )
			{
				m_linkedVars.emplace( std::move( textureSampler ), std::make_pair( std::move( texture ), std::move( sampler ) ) );
			}

		private:
			Shader & m_shader;
			stmt::Container * m_result;
			std::map< uint32_t, var::VariablePtr > m_inputVars;
			std::map< uint32_t, var::VariablePtr > m_outputVars;
			stmt::InputComputeLayout * m_inputComputeLayout{ nullptr };
			stmt::InputGeometryLayout * m_inputGeometryLayout{ nullptr };
			stmt::OutputGeometryLayout * m_outputGeometryLayout{ nullptr };
			type::StructPtr m_inputStruct;
			type::StructPtr m_outputStruct;
			var::VariablePtr m_inputVar;
			var::VariablePtr m_outputVar;
			VariableExprMap m_inputMembers;
			VariableExprMap m_outputMembers;
			LinkedVars m_linkedVars;
			ShaderType m_type;
		};
	}

	std::string writeHlsl( Shader & shader, ShaderType type )
	{
		auto dxStatements = hlsl::StmtAdapter::submit( shader, type );
		return hlsl::StmtVisitor::submit( dxStatements.get(), type );
	}
}
