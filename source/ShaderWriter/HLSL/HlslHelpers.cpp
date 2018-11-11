/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslHelpers.hpp"

#include "ASTGenerator/Type/TypeImage.hpp"
#include "ASTGenerator/Type/TypeSampler.hpp"

namespace sdw::hlsl
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
		case type::Kind::eImage:
			result = "Texture";
			break;
		case type::Kind::eSampler:
			assert( false && "Unsupported type::Kind" );
			break;
		case type::Kind::eSampledImage:
			result = "SampledImage";
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

	std::string getSampledName( type::Kind value )
	{
		std::string result;

		switch ( value )
		{
		case ast::type::Kind::eFloat:
			result = "float4";
			break;
		case ast::type::Kind::eInt:
			result = "int4";
			break;
		case ast::type::Kind::eUInt:
			result = "uint4";
			break;
		default:
			assert( false && "Unsupported type::Kind" );
			result = "Undefined";
			break;
		}

		return result;
	}

	std::string getName( type::ImageDim value )
	{
		std::string result;

		switch ( value )
		{
		case ast::type::ImageDim::e1D:
			result = "1D";
			break;
		case ast::type::ImageDim::e2D:
		case ast::type::ImageDim::eRect:
			result = "2D";
			break;
		case ast::type::ImageDim::e3D:
			result = "3D";
			break;
		case ast::type::ImageDim::eCube:
			result = "Cube";
			break;
		default:
			assert( false && "Unsupported type::ImageDim" );
			result = "Undefined";
			break;
		}

		return result;
	}

	std::string getTypeName( type::ImagePtr type )
	{
		std::string result;
		auto & config = type->getConfig();

		if ( config.accessKind != type::AccessKind::eRead )
		{
			result += "RW";
		}

		if ( config.dimension == type::ImageDim::eBuffer )
		{
			result += "Buffer";
		}
		else
		{
			result += "Texture";
			result += getName( config.dimension );
		}

		if ( config.isArrayed )
		{
			result += "Array";
		}

		result += "<" + getSampledName( config.sampledType ) + ">";
		return result;
	}

	std::string getTypeName( type::SamplerPtr type )
	{
		std::string result;

		if ( type->isComparison() )
		{
			result = "SamplerComparisonState";
		}
		else
		{
			result = "SamplerState";
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
		case type::Kind::eImage:
			result = getTypeName( std::static_pointer_cast< type::Image >( type ) );
			break;
		case type::Kind::eSampler:
			result = getTypeName( std::static_pointer_cast< type::Sampler >( type ) );
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
