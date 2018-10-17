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
			result = "UNDEF";
			break;
		case type::Kind::eVoid:
			result = "VOID";
			break;
		case type::Kind::eStruct:
			result = "STRUCT";
			break;
		case type::Kind::eFunction:
			result = "FUNC";
			break;
		case type::Kind::eBoolean:
			result = "BOOL";
			break;
		case type::Kind::eInt:
			result = "INT";
			break;
		case type::Kind::eUInt:
			result = "UINT";
			break;
		case type::Kind::eFloat:
			result = "FLOAT";
			break;
		case type::Kind::eVec2B:
			result = "BVEC2";
			break;
		case type::Kind::eVec3B:
			result = "BVEC3";
			break;
		case type::Kind::eVec4B:
			result = "BVEC4";
			break;
		case type::Kind::eVec2I:
			result = "IVEC2";
			break;
		case type::Kind::eVec3I:
			result = "IVEC3";
			break;
		case type::Kind::eVec4I:
			result = "IVEC4";
			break;
		case type::Kind::eVec2UI:
			result = "UVEC2";
			break;
		case type::Kind::eVec3UI:
			result = "UVEC3";
			break;
		case type::Kind::eVec4UI:
			result = "UVEC4";
			break;
		case type::Kind::eVec2F:
			result = "FVEC2";
			break;
		case type::Kind::eVec3F:
			result = "FVEC3";
			break;
		case type::Kind::eVec4F:
			result = "FVEC4";
			break;
		case type::Kind::eMat2x2B:
			result = "BMAT2";
			break;
		case type::Kind::eMat3x3B:
			result = "BMAT3";
			break;
		case type::Kind::eMat4x4B:
			result = "BMAT4";
			break;
		case type::Kind::eMat2x2I:
			result = "IMAT2";
			break;
		case type::Kind::eMat3x3I:
			result = "IMAT3";
			break;
		case type::Kind::eMat4x4I:
			result = "IMAT4";
			break;
		case type::Kind::eMat2x2UI:
			result = "UMAT2";
			break;
		case type::Kind::eMat3x3UI:
			result = "UMAT3";
			break;
		case type::Kind::eMat4x4UI:
			result = "UMAT4";
			break;
		case type::Kind::eMat2x2F:
			result = "FMAT2";
			break;
		case type::Kind::eMat3x3F:
			result = "FMAT3";
			break;
		case type::Kind::eMat4x4F:
			result = "FMAT4";
			break;
		case type::Kind::eConstantsBuffer:
			result = "CBUFF";
			break;
		case type::Kind::eShaderBuffer:
			result = "SBUFF";
			break;
		case type::Kind::eSamplerBuffer:
			result = "TBUFF";
			break;
		case type::Kind::eSampler1D:
			result = "TEX1D";
			break;
		case type::Kind::eSampler2D:
			result = "TEX2D";
			break;
		case type::Kind::eSampler3D:
			result = "TEX3D";
			break;
		case type::Kind::eSamplerCube:
			result = "TEXCUBE";
			break;
		case type::Kind::eSampler2DRect:
			result = "TEX2DRECT";
			break;
		case type::Kind::eSampler1DArray:
			result = "TEX1DARRAY";
			break;
		case type::Kind::eSampler2DArray:
			result = "TEX2DARRAY";
			break;
		case type::Kind::eSamplerCubeArray:
			result = "TEXCUBEARRAY";
			break;
		case type::Kind::eSampler1DShadow:
			result = "TEX1DSHADOW";
			break;
		case type::Kind::eSampler2DShadow:
			result = "TEX2DSHADOW";
			break;
		case type::Kind::eSamplerCubeShadow:
			result = "TEXCUBESHADOW";
			break;
		case type::Kind::eSampler2DRectShadow:
			result = "TEX2DRECTARRAYSHADOW";
			break;
		case type::Kind::eSampler1DArrayShadow:
			result = "TEX1DARRAYSHADOW";
			break;
		case type::Kind::eSampler2DArrayShadow:
			result = "TEX2DARRAYSHADOW";
			break;
		case type::Kind::eSamplerCubeArrayShadow:
			result = "TEXCUBEARRAYSHADOW";
			break;
		}

		return result;
	}

	std::string getName( type::TypePtr type )
	{
		return getName( *type );
	}

	std::string getName( type::Type const & type )
	{
		std::string result;

		switch ( type.getKind() )
		{
		case type::Kind::eStruct:
			static_cast< type::Struct const & >( type ).getName();
			break;
		default:
			result = getName( type.getKind() );
			break;
		}

		auto arraySize = type.getArraySize();

		if ( arraySize != type::NotArray )
		{
			result += "[";

			if ( arraySize != type::UnknownArraySize )
			{
				result += std::to_string( arraySize );
			}

			result += "]";
		}

		return result;
	}
}
