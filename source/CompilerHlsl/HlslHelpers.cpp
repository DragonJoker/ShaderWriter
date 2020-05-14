/*
See LICENSE file in root folder
*/
#include "HlslHelpers.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampler.hpp>

#include <stdexcept>

namespace hlsl
{
	std::string getTypeName( ast::type::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case ast::type::Kind::eUndefined:
			result = "undefined";
			break;
		case ast::type::Kind::eVoid:
			result = "void";
			break;
		case ast::type::Kind::eStruct:
			result = "struct";
			break;
		case ast::type::Kind::eFunction:
			result = "function";
			break;
		case ast::type::Kind::eBoolean:
			result = "bool";
			break;
		case ast::type::Kind::eInt:
			result = "int";
			break;
		case ast::type::Kind::eUInt:
			result = "uint";
			break;
		case ast::type::Kind::eFloat:
			result = "float";
			break;
		case ast::type::Kind::eDouble:
			result = "double";
			break;
		case ast::type::Kind::eVec2B:
			result = "bool2";
			break;
		case ast::type::Kind::eVec3B:
			result = "bool3";
			break;
		case ast::type::Kind::eVec4B:
			result = "bool4";
			break;
		case ast::type::Kind::eVec2I:
			result = "int2";
			break;
		case ast::type::Kind::eVec3I:
			result = "int3";
			break;
		case ast::type::Kind::eVec4I:
			result = "int4";
			break;
		case ast::type::Kind::eVec2U:
			result = "uint2";
			break;
		case ast::type::Kind::eVec3U:
			result = "uint3";
			break;
		case ast::type::Kind::eVec4U:
			result = "uint4";
			break;
		case ast::type::Kind::eVec2F:
			result = "float2";
			break;
		case ast::type::Kind::eVec3F:
			result = "float3";
			break;
		case ast::type::Kind::eVec4F:
			result = "float4";
			break;
		case ast::type::Kind::eVec2D:
			result = "double2";
			break;
		case ast::type::Kind::eVec3D:
			result = "double3";
			break;
		case ast::type::Kind::eVec4D:
			result = "double4";
			break;
		case ast::type::Kind::eMat2x2F:
			result = "float2x2";
			break;
		case ast::type::Kind::eMat2x3F:
			result = "float2x3";
			break;
		case ast::type::Kind::eMat2x4F:
			result = "float2x4";
			break;
		case ast::type::Kind::eMat3x3F:
			result = "float3x3";
			break;
		case ast::type::Kind::eMat3x2F:
			result = "float3x2";
			break;
		case ast::type::Kind::eMat3x4F:
			result = "float3x4";
			break;
		case ast::type::Kind::eMat4x4F:
			result = "float4x4";
			break;
		case ast::type::Kind::eMat4x2F:
			result = "float4x2";
			break;
		case ast::type::Kind::eMat4x3F:
			result = "float4x3";
			break;
		case ast::type::Kind::eMat2x2D:
			result = "double2x2";
			break;
		case ast::type::Kind::eMat2x3D:
			result = "double2x3";
			break;
		case ast::type::Kind::eMat2x4D:
			result = "double2x4";
			break;
		case ast::type::Kind::eMat3x3D:
			result = "double3x3";
			break;
		case ast::type::Kind::eMat3x2D:
			result = "double3x2";
			break;
		case ast::type::Kind::eMat3x4D:
			result = "double3x4";
			break;
		case ast::type::Kind::eMat4x4D:
			result = "double4x4";
			break;
		case ast::type::Kind::eMat4x2D:
			result = "double4x2";
			break;
		case ast::type::Kind::eMat4x3D:
			result = "double4x3";
			break;
		case ast::type::Kind::eImage:
			result = "Texture";
			break;
		case ast::type::Kind::eSampler:
			assert( false && "Unsupported ast::type::Kind" );
			break;
		case ast::type::Kind::eSampledImage:
			result = "SampledImage";
			break;
		case ast::type::Kind::eHalf:
			result = "half";
			break;
		case ast::type::Kind::eVec2H:
			result = "vector<half, 2>";
			break;
		case ast::type::Kind::eVec3H:
			result = "vector<half, 3>";
			break;
		case ast::type::Kind::eVec4H:
			result = "vector<half, 4>";
			break;
		default:
			break;
		}

		return result;
	}

	std::string getSampledName( ast::type::ImageFormat value )
	{
		std::string result;

		switch ( value )
		{
		case ast::type::ImageFormat::eUnknown:
			result = "float4";
			break;
		case ast::type::ImageFormat::eRgba32f:
		case ast::type::ImageFormat::eRgba16f:
			result = "float4";
			break;
		case ast::type::ImageFormat::eRg32f:
		case ast::type::ImageFormat::eRg16f:
			result = "float2";
			break;
		case ast::type::ImageFormat::eR32f:
		case ast::type::ImageFormat::eR16f:
			result = "float";
			break;
		case ast::type::ImageFormat::eRgba32i:
		case ast::type::ImageFormat::eRgba16i:
		case ast::type::ImageFormat::eRgba8i:
			result = "int4";
			break;
		case ast::type::ImageFormat::eRg32i:
		case ast::type::ImageFormat::eRg16i:
		case ast::type::ImageFormat::eRg8i:
			result = "int2";
			break;
		case ast::type::ImageFormat::eR32i:
		case ast::type::ImageFormat::eR16i:
		case ast::type::ImageFormat::eR8i:
			result = "int";
			break;
		case ast::type::ImageFormat::eRgba32u:
		case ast::type::ImageFormat::eRgba16u:
		case ast::type::ImageFormat::eRgba8u:
			result = "uint4";
			break;
		case ast::type::ImageFormat::eRg32u:
		case ast::type::ImageFormat::eRg16u:
		case ast::type::ImageFormat::eRg8u:
			result = "uint2";
			break;
		case ast::type::ImageFormat::eR32u:
		case ast::type::ImageFormat::eR16u:
		case ast::type::ImageFormat::eR8u:
			result = "uint";
			break;
		default:
			break;
		}

		return result;
	}

	std::string getSampledName( ast::type::Kind value )
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
			assert( false && "Unsupported ast::type::Kind" );
			result = "Undefined";
			break;
		}

		return result;
	}

	std::string getName( ast::type::ImageDim value )
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
		case ast::type::ImageDim::eBuffer:
			result = "Buffer";
			break;
		default:
			assert( false && "Unsupported ast::type::ImageDim" );
			result = "Undefined";
			break;
		}

		return result;
	}

	std::string getTypeName( ast::type::ImagePtr type )
	{
		std::string result;
		auto & config = type->getConfig();

		if ( config.isSampled != ast::type::Trinary::eTrue )
		{
			result += "RW";

			if ( config.dimension == ast::type::ImageDim::eBuffer )
			{
				result += "Buffer";
			}
			else if( config.dimension == ast::type::ImageDim::eCube )
			{
				result += "Texture2DArray";
			}
			else
			{
				result += "Texture";
				result += getName( config.dimension );

				if ( config.isArrayed )
				{
					result += "Array";
				}
			}
		}
		else
		{
			if ( config.dimension == ast::type::ImageDim::eBuffer )
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
		}

		//result += "<" + getSampledName( config.sampledType ) + ">";
		result += "<" + getSampledName( config.format ) + ">";
		return result;
	}

	std::string getTypeName( ast::type::SamplerPtr type )
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

	std::string getTypeName( ast::type::TypePtr type )
	{
		std::string result;

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = std::static_pointer_cast< ast::type::Array >( type )->getType();
		}

		switch ( type->getKind() )
		{
		case ast::type::Kind::eStruct:
			result = static_cast< ast::type::Struct const & >( *type ).getName();
			break;
		case ast::type::Kind::eImage:
			result = getTypeName( std::static_pointer_cast< ast::type::Image >( type ) );
			break;
		case ast::type::Kind::eSampler:
			result = getTypeName( std::static_pointer_cast< ast::type::Sampler >( type ) );
			break;
		default:
			result = getTypeName( type->getKind() );
			break;
		}

		return result;
	}

	std::string getTypeArraySize( ast::type::TypePtr type )
	{
		std::string result;
		auto arraySize = getArraySize( type );

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				result += "[]";
			}
			else
			{
				result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		return result;
	}

	std::string getLocationName( ast::var::Variable const & var )
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

	std::string getDirectionName( ast::var::Variable const & var )
	{
		std::string result;

		if ( var.isStatic() )
		{
			result = "static ";
		}

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

	std::string getOperatorName( ast::expr::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case ast::expr::Kind::eAdd:
			result = "+";
			break;
		case ast::expr::Kind::eMinus:
			result = "-";
			break;
		case ast::expr::Kind::eTimes:
			result = "*";
			break;
		case ast::expr::Kind::eDivide:
			result = "/";
			break;
		case ast::expr::Kind::eModulo:
			result = "%";
			break;
		case ast::expr::Kind::eLShift:
			result = "<<";
			break;
		case ast::expr::Kind::eRShift:
			result = ">>";
			break;
		case ast::expr::Kind::eBitAnd:
			result = "&";
			break;
		case ast::expr::Kind::eBitNot:
			result = "~";
			break;
		case ast::expr::Kind::eBitOr:
			result = "|";
			break;
		case ast::expr::Kind::eBitXor:
			result = "^";
			break;
		case ast::expr::Kind::eLogAnd:
			result = "&&";
			break;
		case ast::expr::Kind::eLogNot:
			result = "!";
			break;
		case ast::expr::Kind::eLogOr:
			result = "||";
			break;
		case ast::expr::Kind::eCast:
			result = "";
			break;
		case ast::expr::Kind::eEqual:
			result = "==";
			break;
		case ast::expr::Kind::eGreater:
			result = ">";
			break;
		case ast::expr::Kind::eGreaterEqual:
			result = ">=";
			break;
		case ast::expr::Kind::eLess:
			result = "<";
			break;
		case ast::expr::Kind::eLessEqual:
			result = "<=";
			break;
		case ast::expr::Kind::eNotEqual:
			result = "!=";
			break;
		case ast::expr::Kind::eComma:
			result = ",";
			break;
		case ast::expr::Kind::eMbrSelect:
			result = ".";
			break;
		case ast::expr::Kind::ePreIncrement:
			result = "++";
			break;
		case ast::expr::Kind::ePreDecrement:
			result = "--";
			break;
		case ast::expr::Kind::ePostIncrement:
			result = "++";
			break;
		case ast::expr::Kind::ePostDecrement:
			result = "--";
			break;
		case ast::expr::Kind::eUnaryMinus:
			result = "-";
			break;
		case ast::expr::Kind::eUnaryPlus:
			result = "+";
			break;
		case ast::expr::Kind::eAssign:
			result = "=";
			break;
		case ast::expr::Kind::eAddAssign:
			result = "+=";
			break;
		case ast::expr::Kind::eMinusAssign:
			result = "-=";
			break;
		case ast::expr::Kind::eTimesAssign:
			result = "*=";
			break;
		case ast::expr::Kind::eDivideAssign:
			result = "/=";
			break;
		case ast::expr::Kind::eModuloAssign:
			result = "%=";
			break;
		case ast::expr::Kind::eLShiftAssign:
			result = "<<=";
			break;
		case ast::expr::Kind::eRShiftAssign:
			result = ">>=";
			break;
		case ast::expr::Kind::eAndAssign:
			result = "&=";
			break;
		case ast::expr::Kind::eNotAssign:
			result = "!=";
			break;
		case ast::expr::Kind::eOrAssign:
			result = "|=";
			break;
		case ast::expr::Kind::eXorAssign:
			result = "^=";
			break;
		default:
			throw std::runtime_error{ "Non operation expression" };
		}

		return result;
	}

	std::string getLayoutName( ast::stmt::InputLayout layout )
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

	std::string getLayoutName( ast::stmt::OutputLayout layout )
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

	std::string getCtorName( ast::expr::CompositeType composite
		, ast::type::Kind component )
	{
		std::string result;

		switch ( composite )
		{
		case ast::expr::CompositeType::eVec2:
			switch ( component )
			{
			case ast::type::Kind::eBoolean:
				result = "bool2";
				break;
			case ast::type::Kind::eInt:
				result = "int2";
				break;
			case ast::type::Kind::eUInt:
				result = "uint2";
				break;
			case ast::type::Kind::eFloat:
				result = "float2";
				break;
			case ast::type::Kind::eDouble:
				result = "double2";
				break;
			case ast::type::Kind::eHalf:
				result = "vector<half, 2>";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eVec3:
			switch ( component )
			{
			case ast::type::Kind::eBoolean:
				result = "bool3";
				break;
			case ast::type::Kind::eInt:
				result = "int3";
				break;
			case ast::type::Kind::eUInt:
				result = "uint3";
				break;
			case ast::type::Kind::eFloat:
				result = "float3";
				break;
			case ast::type::Kind::eDouble:
				result = "double3";
				break;
			case ast::type::Kind::eHalf:
				result = "vector<half, 3>";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eVec4:
			switch ( component )
			{
			case ast::type::Kind::eBoolean:
				result = "bool4";
				break;
			case ast::type::Kind::eInt:
				result = "int4";
				break;
			case ast::type::Kind::eUInt:
				result = "uint4";
				break;
			case ast::type::Kind::eFloat:
				result = "float4";
				break;
			case ast::type::Kind::eDouble:
				result = "double4";
				break;
			case ast::type::Kind::eHalf:
				result = "vector<half, 4>";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat2x2:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float2x2";
				break;
			case ast::type::Kind::eDouble:
				result = "double2x2";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat2x3:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float2x3";
				break;
			case ast::type::Kind::eDouble:
				result = "double2x3";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat2x4:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float2x4";
				break;
			case ast::type::Kind::eDouble:
				result = "double2x4";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat3x2:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float3x2";
				break;
			case ast::type::Kind::eDouble:
				result = "double3x2";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat3x3:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float3x3";
				break;
			case ast::type::Kind::eDouble:
				result = "double3x3";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat3x4:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float3x4";
				break;
			case ast::type::Kind::eDouble:
				result = "double3x4";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat4x2:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float4x2";
				break;
			case ast::type::Kind::eDouble:
				result = "double4x2";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat4x3:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float4x3";
				break;
			case ast::type::Kind::eDouble:
				result = "double4x3";
				break;
			default:
				break;
			}
			break;
		case ast::expr::CompositeType::eMat4x4:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "float4x4";
				break;
			case ast::type::Kind::eDouble:
				result = "double4x4";
				break;
			default:
				break;
			}
			break;
		default:
			throw std::runtime_error{ "Unsupported composite type." };
		}

		return result;
	}

	std::string getSemantic( std::string const & name
		, std::string const & defaultName
		, uint32_t index )
	{
		static std::map< std::string, std::string > const NamesMap
		{
			{ "gl_InvocationID", "SV_GSInstanceID" },
			{ "gl_LocalInvocationID", "SV_GroupThreadID" },
			{ "gl_LocalInvocationIndex", "SV_GroupIndex" },
			{ "gl_WorkGroupID", "SV_GroupID" },
			{ "gl_TessCord", "SV_DomainLocation" },
			{ "gl_GlobalInvocationID", "SV_DispatchThreadID" },
			{ "gl_FragDepth", "SV_Depth" },
			{ "gl_SampleMask", "SV_Coverage" },
			{ "gl_SampleMaskIn", "SV_Coverage" },
			{ "gl_CullDistance", "SV_CullDistance" },
			{ "gl_ClipDistance", "SV_ClipDistance" },
			{ "gl_TessLevelInner", "SV_InsideTessFactor" },
			{ "gl_InstanceID", "SV_InstanceID" },
			{ "gl_InstanceIndex", "SV_InstanceID" },
			{ "gl_FrontFacing", "SV_IsFrontFace" },
			{ "gl_Position", "SV_Position" },
			{ "gl_FragCoord", "SV_Position" },
			{ "gl_PrimitiveID", "SV_PrimitiveID" },
			{ "gl_Layer", "SV_RenderTargetArrayIndex" },
			{ "gl_SampleID", "SV_SampleIndex" },
			{ "gl_FragStencilRef", "SV_StencilRef" },
			{ "gl_TessLevelOuter", "SV_TessFactor" },
			{ "gl_VertexID", "SV_VertexID" },
			{ "gl_VertexIndex", "SV_VertexID" },
			{ "gl_ViewportIndex", "SV_ViewportArrayIndex" },
		};
		std::string result;
		auto it = NamesMap.find( name );

		if ( it != NamesMap.end() )
		{
			result = it->second;
		}
		else
		{
			result = defaultName + std::to_string( index );
		}

		return result;
	}

	bool isUnaryPre( ast::expr::Kind kind )
	{
		bool result;

		switch ( kind )
		{
		case ast::expr::Kind::eMbrSelect:
		case ast::expr::Kind::ePostIncrement:
		case ast::expr::Kind::ePostDecrement:
			result = false;
			break;
		case ast::expr::Kind::eBitNot:
		case ast::expr::Kind::eLogNot:
		case ast::expr::Kind::eCast:
		case ast::expr::Kind::ePreIncrement:
		case ast::expr::Kind::ePreDecrement:
		case ast::expr::Kind::eUnaryMinus:
		case ast::expr::Kind::eUnaryPlus:
			result = true;
			break;
		default:
			throw std::runtime_error{ "Non unary expression" };
		}

		return result;
	}

	LinkedVars::iterator updateLinkedVars( ast::var::VariablePtr var, LinkedVars & linkedVars )
	{
		auto it = linkedVars.find( var );
		auto type = getNonArrayType( var->getType() );

		if ( isSampledImageType( type->getKind() )
			&& it == linkedVars.end() )
		{
			auto sampledType = std::static_pointer_cast< ast::type::SampledImage >( type );

			if ( sampledType->getConfig().dimension != ast::type::ImageDim::eBuffer )
			{
				auto texture = ast::var::makeVariable( sampledType->getImageType()
					, var->getName() + "_texture" );
				auto sampler = ast::var::makeVariable( sampledType->getSamplerType()
					, var->getName() + "_sampler" );
				it = linkedVars.emplace( var, std::make_pair( texture, sampler ) ).first;
			}
		}

		return it;
	}
}
