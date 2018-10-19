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
		case type::Kind::eDouble:
			result = "DOUBLE";
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
		case type::Kind::eVec2U:
			result = "UVEC2";
			break;
		case type::Kind::eVec3U:
			result = "UVEC3";
			break;
		case type::Kind::eVec4U:
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
		case type::Kind::eVec2D:
			result = "DVEC2";
			break;
		case type::Kind::eVec3D:
			result = "DVEC3";
			break;
		case type::Kind::eVec4D:
			result = "DVEC4";
			break;
		case type::Kind::eMat2x2F:
			result = "FMAT2x2";
			break;
		case type::Kind::eMat2x3F:
			result = "FMAT2X3";
			break;
		case type::Kind::eMat2x4F:
			result = "FMAT2X4";
			break;
		case type::Kind::eMat3x2F:
			result = "FMAT3X2";
			break;
		case type::Kind::eMat3x3F:
			result = "FMAT3X3";
			break;
		case type::Kind::eMat3x4F:
			result = "FMAT3X4";
			break;
		case type::Kind::eMat4x2F:
			result = "FMAT4X2";
			break;
		case type::Kind::eMat4x3F:
			result = "FMAT4X3";
			break;
		case type::Kind::eMat4x4F:
			result = "FMAT4X4";
			break;
		case type::Kind::eMat2x2D:
			result = "DMAT2x2";
			break;
		case type::Kind::eMat2x3D:
			result = "DMAT2X3";
			break;
		case type::Kind::eMat2x4D:
			result = "DMAT2X4";
			break;
		case type::Kind::eMat3x2D:
			result = "DMAT3X2";
			break;
		case type::Kind::eMat3x3D:
			result = "DMAT3X3";
			break;
		case type::Kind::eMat3x4D:
			result = "DMAT3X4";
			break;
		case type::Kind::eMat4x2D:
			result = "DMAT4X2";
			break;
		case type::Kind::eMat4x3D:
			result = "DMAT4X3";
			break;
		case type::Kind::eMat4x4D:
			result = "DMAT4X4";
			break;
		case type::Kind::eConstantsBuffer:
			result = "CBUFF";
			break;
		case type::Kind::eShaderBuffer:
			result = "SBUFF";
			break;
		case type::Kind::eSamplerBufferF:
			result = "TEXBUFFERF";
			break;
		case type::Kind::eSampler1DF:
			result = "TEX1DF";
			break;
		case type::Kind::eSampler2DF:
			result = "TEX2DF";
			break;
		case type::Kind::eSampler3DF:
			result = "TEX3DF";
			break;
		case type::Kind::eSamplerCubeF:
			result = "TEXCUBEF";
			break;
		case type::Kind::eSampler2DRectF:
			result = "TEX2DRECTF";
			break;
		case type::Kind::eSampler1DArrayF:
			result = "TEX1DARRAYF";
			break;
		case type::Kind::eSampler2DArrayF:
			result = "TEX2DARRAYF";
			break;
		case type::Kind::eSamplerCubeArrayF:
			result = "TEXCUBEARRAYF";
			break;
		case type::Kind::eSampler1DShadowF:
			result = "TEX1DSHADOWF";
			break;
		case type::Kind::eSampler2DShadowF:
			result = "TEX2DSHADOWF";
			break;
		case type::Kind::eSamplerCubeShadowF:
			result = "TEXCUBESHADOWF";
			break;
		case type::Kind::eSampler2DRectShadowF:
			result = "TEX2DRECTARRAYSHADOWF";
			break;
		case type::Kind::eSampler1DArrayShadowF:
			result = "TEX1DARRAYSHADOWF";
			break;
		case type::Kind::eSampler2DArrayShadowF:
			result = "TEX2DARRAYSHADOWF";
			break;
		case type::Kind::eSamplerCubeArrayShadowF:
			result = "TEXCUBEARRAYSHADOWF";
			break;
		case type::Kind::eSamplerBufferI:
			result = "TEXBUFFERI";
			break;
		case type::Kind::eSampler1DI:
			result = "TEX1DI";
			break;
		case type::Kind::eSampler2DI:
			result = "TEX2DI";
			break;
		case type::Kind::eSampler3DI:
			result = "TEX3DI";
			break;
		case type::Kind::eSamplerCubeI:
			result = "TEXCUBEI";
			break;
		case type::Kind::eSampler2DRectI:
			result = "TEX2DRECTI";
			break;
		case type::Kind::eSampler1DArrayI:
			result = "TEX1DARRAYI";
			break;
		case type::Kind::eSampler2DArrayI:
			result = "TEX2DARRAYI";
			break;
		case type::Kind::eSamplerCubeArrayI:
			result = "TEXCUBEARRAYI";
			break;
		case type::Kind::eSamplerBufferU:
			result = "TEXBUFFERU";
			break;
		case type::Kind::eSampler1DU:
			result = "TEX1DU";
			break;
		case type::Kind::eSampler2DU:
			result = "TEX2DU";
			break;
		case type::Kind::eSampler3DU:
			result = "TEX3DU";
			break;
		case type::Kind::eSamplerCubeU:
			result = "TEXCUBEU";
			break;
		case type::Kind::eSampler2DRectU:
			result = "TEX2DRECTU";
			break;
		case type::Kind::eSampler1DArrayU:
			result = "TEX1DARRAYU";
			break;
		case type::Kind::eSampler2DArrayU:
			result = "TEX2DARRAYU";
			break;
		case type::Kind::eSamplerCubeArrayU:
			result = "TEXCUBEARRAYU";
			break;
		case type::Kind::eImageBufferF:
			result = "IMGBUFFERF";
			break;
		case type::Kind::eImage1DF:
			result = "IMG1DF";
			break;
		case type::Kind::eImage2DF:
			result = "IMG2DF";
			break;
		case type::Kind::eImage3DF:
			result = "IMG3DF";
			break;
		case type::Kind::eImageCubeF:
			result = "IMGCUBEF";
			break;
		case type::Kind::eImage2DRectF:
			result = "IMG2DRECTF";
			break;
		case type::Kind::eImage1DArrayF:
			result = "IMG1DARRAYF";
			break;
		case type::Kind::eImage2DArrayF:
			result = "IMG2DARRAYF";
			break;
		case type::Kind::eImageCubeArrayF:
			result = "IMGCUBEARRAYF";
			break;
		case type::Kind::eImage2DMSF:
			result = "IMG2DMSF";
			break;
		case type::Kind::eImage2DMSArrayF:
			result = "IMG2DMSARRAYF";
			break;
		case type::Kind::eImageBufferI:
			result = "IMGBUFFERI";
			break;
		case type::Kind::eImage1DI:
			result = "IMG1DI";
			break;
		case type::Kind::eImage2DI:
			result = "IMG2DI";
			break;
		case type::Kind::eImage3DI:
			result = "IMG3DI";
			break;
		case type::Kind::eImageCubeI:
			result = "IMGCUBEI";
			break;
		case type::Kind::eImage2DRectI:
			result = "IMG2DRECTI";
			break;
		case type::Kind::eImage1DArrayI:
			result = "IMG1DARRAYI";
			break;
		case type::Kind::eImage2DArrayI:
			result = "IMG2DARRAYI";
			break;
		case type::Kind::eImageCubeArrayI:
			result = "IMGCUBEARRAYI";
			break;
		case type::Kind::eImage2DMSI:
			result = "IMG2DMSI";
			break;
		case type::Kind::eImage2DMSArrayI:
			result = "IMG2DMSARRAYI";
			break;
		case type::Kind::eImageBufferU:
			result = "IMGBUFFERU";
			break;
		case type::Kind::eImage1DU:
			result = "IMG1DU";
			break;
		case type::Kind::eImage2DU:
			result = "IMG2DU";
			break;
		case type::Kind::eImage3DU:
			result = "IMG3DU";
			break;
		case type::Kind::eImageCubeU:
			result = "IMGCUBEU";
			break;
		case type::Kind::eImage2DRectU:
			result = "IMG2DRECTU";
			break;
		case type::Kind::eImage1DArrayU:
			result = "IMG1DARRAYU";
			break;
		case type::Kind::eImage2DArrayU:
			result = "IMG2DARRAYU";
			break;
		case type::Kind::eImageCubeArrayU:
			result = "IMGCUBEARRAYU";
			break;
		case type::Kind::eImage2DMSU:
			result = "IMG2DMSU";
			break;
		case type::Kind::eImage2DMSArrayU:
			result = "IMG2DMSARRAYU";
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
