/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslHelpers.hpp"

namespace sdw::hlsl
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
		case type::Kind::eHalf:
			result = "half";
			break;
		case type::Kind::eVec2H:
			result = "vector<half, 2>";
			break;
		case type::Kind::eVec3H:
			result = "vector<half, 3>";
			break;
		case type::Kind::eVec4H:
			result = "vector<half, 4>";
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
}
