/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugCommon.hpp"

#include "ASTGenerator/Expr/Expr.hpp"
#include "ASTGenerator/Stmt/PreprocExtension.hpp"
#include "ASTGenerator/Stmt/StmtInOutVariableDecl.hpp"
#include "ASTGenerator/Type/TypeStruct.hpp"
#include "ASTGenerator/Var/Variable.hpp"

#include <sstream>

namespace ast::debug
{
	std::string getName( type::Kind kind )
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
		case type::Kind::eVec2UI:
			result = "uvec2";
			break;
		case type::Kind::eVec3UI:
			result = "uvec3";
			break;
		case type::Kind::eVec4UI:
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
		case type::Kind::eMat2x2B:
			result = "bmat2";
			break;
		case type::Kind::eMat3x3B:
			result = "bmat3";
			break;
		case type::Kind::eMat4x4B:
			result = "bmat4";
			break;
		case type::Kind::eMat2x2I:
			result = "imat2";
			break;
		case type::Kind::eMat3x3I:
			result = "imat3";
			break;
		case type::Kind::eMat4x4I:
			result = "imat4";
			break;
		case type::Kind::eMat2x2UI:
			result = "umat2";
			break;
		case type::Kind::eMat3x3UI:
			result = "umat3";
			break;
		case type::Kind::eMat4x4UI:
			result = "umat4";
			break;
		case type::Kind::eMat2x2F:
			result = "mat2";
			break;
		case type::Kind::eMat3x3F:
			result = "mat3";
			break;
		case type::Kind::eMat4x4F:
			result = "mat4";
			break;
		case type::Kind::eConstantsBuffer:
			result = "uniform";
			break;
		case type::Kind::eShaderBuffer:
			result = "buffer";
			break;
		case type::Kind::eSamplerBuffer:
			result = "samplerBuffer";
			break;
		case type::Kind::eSampler1D:
			result = "sampler1D";
			break;
		case type::Kind::eSampler2D:
			result = "sampler2D";
			break;
		case type::Kind::eSampler3D:
			result = "sampler3D";
			break;
		case type::Kind::eSamplerCube:
			result = "samplerCube";
			break;
		case type::Kind::eSampler2DRect:
			result = "sampler2DRect";
			break;
		case type::Kind::eSampler1DArray:
			result = "sampler1DArray";
			break;
		case type::Kind::eSampler2DArray:
			result = "sampler2DArray";
			break;
		case type::Kind::eSamplerCubeArray:
			result = "samplerCubeArray";
			break;
		case type::Kind::eSampler1DShadow:
			result = "sampler1DShadow";
			break;
		case type::Kind::eSampler2DShadow:
			result = "sampler2DShadow";
			break;
		case type::Kind::eSamplerCubeShadow:
			result = "samplerCubeShadow";
			break;
		case type::Kind::eSampler2DRectShadow:
			result = "sampler2DRectArrayShadow";
			break;
		case type::Kind::eSampler1DArrayShadow:
			result = "sampler1DArrayShadow";
			break;
		case type::Kind::eSampler2DArrayShadow:
			result = "sampler2DArrayShadow";
			break;
		case type::Kind::eSamplerCubeArrayShadow:
			result = "samplerCubeArrayShadow";
			break;
		}

		return result;
	}

	std::string getName( type::TypePtr type )
	{
		std::string result;

		switch ( type->getKind() )
		{
		case type::Kind::eUndefined:
			result = "undefined";
			break;
		case type::Kind::eVoid:
			result = "void";
			break;
		case type::Kind::eStruct:
			static_cast< type::Struct const & >( *type ).getName();
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
		case type::Kind::eVec2UI:
			result = "uvec2";
			break;
		case type::Kind::eVec3UI:
			result = "uvec3";
			break;
		case type::Kind::eVec4UI:
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
		case type::Kind::eMat2x2B:
			result = "bmat2";
			break;
		case type::Kind::eMat3x3B:
			result = "bmat3";
			break;
		case type::Kind::eMat4x4B:
			result = "bmat4";
			break;
		case type::Kind::eMat2x2I:
			result = "imat2";
			break;
		case type::Kind::eMat3x3I:
			result = "imat3";
			break;
		case type::Kind::eMat4x4I:
			result = "imat4";
			break;
		case type::Kind::eMat2x2UI:
			result = "umat2";
			break;
		case type::Kind::eMat3x3UI:
			result = "umat3";
			break;
		case type::Kind::eMat4x4UI:
			result = "umat4";
			break;
		case type::Kind::eMat2x2F:
			result = "mat2";
			break;
		case type::Kind::eMat3x3F:
			result = "mat3";
			break;
		case type::Kind::eMat4x4F:
			result = "mat4";
			break;
		case type::Kind::eConstantsBuffer:
			result = "uniform";
			break;
		case type::Kind::eShaderBuffer:
			result = "buffer";
			break;
		case type::Kind::eSamplerBuffer:
			result = "samplerBuffer";
			break;
		case type::Kind::eSampler1D:
			result = "sampler1D";
			break;
		case type::Kind::eSampler2D:
			result = "sampler2D";
			break;
		case type::Kind::eSampler3D:
			result = "sampler3D";
			break;
		case type::Kind::eSamplerCube:
			result = "samplerCube";
			break;
		case type::Kind::eSampler2DRect:
			result = "sampler2DRect";
			break;
		case type::Kind::eSampler1DArray:
			result = "sampler1DArray";
			break;
		case type::Kind::eSampler2DArray:
			result = "sampler2DArray";
			break;
		case type::Kind::eSamplerCubeArray:
			result = "samplerCubeArray";
			break;
		case type::Kind::eSampler1DShadow:
			result = "sampler1DShadow";
			break;
		case type::Kind::eSampler2DShadow:
			result = "sampler2DShadow";
			break;
		case type::Kind::eSamplerCubeShadow:
			result = "samplerCubeShadow";
			break;
		case type::Kind::eSampler2DRectShadow:
			result = "sampler2DRectArrayShadow";
			break;
		case type::Kind::eSampler1DArrayShadow:
			result = "sampler1DArrayShadow";
			break;
		case type::Kind::eSampler2DArrayShadow:
			result = "sampler2DArrayShadow";
			break;
		case type::Kind::eSamplerCubeArrayShadow:
			result = "samplerCubeArrayShadow";
			break;
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
			throw std::runtime_error{ "Non operatin expression" };
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
}
