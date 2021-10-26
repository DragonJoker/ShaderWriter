/*
See LICENSE file in root folder
*/
#include "HlslHelpers.hpp"

#include "HlslShader.hpp"
#include "HlslExprAdapter.hpp"

#include <ShaderAST/Expr/ExprArrayAccess.hpp>
#include <ShaderAST/Expr/ExprIdentifier.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Expr/ExprMbrSelect.hpp>
#include <ShaderAST/Stmt/StmtStructureDecl.hpp>
#include <ShaderAST/Type/TypeGeometryIO.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampler.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <stdexcept>

namespace hlsl
{
	namespace
	{
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
				else if ( config.dimension == ast::type::ImageDim::eCube )
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

			result += "<" + hlsl::getSampledName( config.format ) + ">";
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

		bool isShaderInput( ast::Builtin builtin
			, ast::ShaderStage type )
		{
			return
				( type == ast::ShaderStage::eCompute
					&& ( builtin == ast::Builtin::eNumWorkGroups
						|| builtin == ast::Builtin::eWorkGroupID
						|| builtin == ast::Builtin::eLocalInvocationID
						|| builtin == ast::Builtin::eGlobalInvocationID
						|| builtin == ast::Builtin::eLocalInvocationIndex ) )
				|| ( type == ast::ShaderStage::eFragment
					&& ( builtin == ast::Builtin::eFragCoord
						|| builtin == ast::Builtin::eFrontFacing
						|| builtin == ast::Builtin::ePointCoord
						|| builtin == ast::Builtin::eSampleID
						|| builtin == ast::Builtin::eSamplePosition
						|| builtin == ast::Builtin::eSampleMaskIn
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eLayer
						|| builtin == ast::Builtin::eViewportIndex ) )
				|| ( type == ast::ShaderStage::eGeometry
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::ePrimitiveIDIn
						|| builtin == ast::Builtin::eInvocationID ) )
				|| ( type == ast::ShaderStage::eTessellationControl
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::ePatchVerticesIn
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eInvocationID ) )
				|| ( type == ast::ShaderStage::eTessellationEvaluation
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eTessCoord
						|| builtin == ast::Builtin::ePatchVerticesIn
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eTessLevelInner
						|| builtin == ast::Builtin::eTessLevelOuter ) )
				|| ( type == ast::ShaderStage::eVertex
					&& ( builtin == ast::Builtin::eVertexIndex
						|| builtin == ast::Builtin::eInstanceIndex
						|| builtin == ast::Builtin::eDrawIndex
						|| builtin == ast::Builtin::eBaseVertex
						|| builtin == ast::Builtin::eBaseInstance
						|| builtin == ast::Builtin::eTessLevelOuter ) );
		}

		bool isShaderOutput( ast::Builtin builtin
			, ast::ShaderStage type )
		{
			return
				( type == ast::ShaderStage::eFragment
					&& ( builtin == ast::Builtin::eFragDepth
						|| builtin == ast::Builtin::eSampleMask
						|| builtin == ast::Builtin::eFragStencilRefEXT ) )
				|| ( type == ast::ShaderStage::eGeometry
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eCullDistance
						|| builtin == ast::Builtin::ePrimitiveID
						|| builtin == ast::Builtin::eLayer
						|| builtin == ast::Builtin::eViewportIndex ) )
				|| ( type == ast::ShaderStage::eTessellationControl
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eCullDistance
						|| builtin == ast::Builtin::eTessLevelInner
						|| builtin == ast::Builtin::eTessLevelOuter ) )
				|| ( type == ast::ShaderStage::eTessellationEvaluation
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance ) )
				|| ( type == ast::ShaderStage::eVertex
					&& ( builtin == ast::Builtin::ePosition
						|| builtin == ast::Builtin::ePointSize
						|| builtin == ast::Builtin::eClipDistance
						|| builtin == ast::Builtin::eCullDistance ) );
		}
	}

	bool needsSeparateMain( ast::ShaderStage stage
		, bool isMain )
	{
		return stage == ast::ShaderStage::eFragment
			|| stage == ast::ShaderStage::eVertex
			|| ( stage == ast::ShaderStage::eTessellationControl && !isMain )
			|| stage == ast::ShaderStage::eTessellationEvaluation;
	}

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
			AST_Failure( "Unsupported ast::type::Kind" );
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
			AST_Failure( "Unsupported ast::type::ImageDim" );
			result = "Undefined";
			break;
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

	std::string getLayoutName( ast::type::InputLayout layout )
	{
		std::string result;

		switch ( layout )
		{
		case ast::type::InputLayout::ePointList:
			result = "point";
			break;
		case ast::type::InputLayout::eLineList:
		case ast::type::InputLayout::eLineStrip:
			result = "line";
			break;
		case ast::type::InputLayout::eTriangleList:
		case ast::type::InputLayout::eTriangleStrip:
		case ast::type::InputLayout::eTriangleFan:
			result = "triangle";
			break;
		case ast::type::InputLayout::eLineListWithAdjacency:
		case ast::type::InputLayout::eLineStripWithAdjacency:
			result = "lineadj";
			break;
		case ast::type::InputLayout::eTriangleListWithAdjacency:
		case ast::type::InputLayout::eTriangleStripWithAdjacency:
			result = "triangleadj";
			break;
		default:
			throw std::runtime_error{ "Unsupported input layout." };
		}

		return result;
	}

	std::string getLayoutName( ast::type::OutputLayout layout )
	{
		std::string result;

		switch ( layout )
		{
		case ast::type::OutputLayout::ePointList:
			result = "PointStream";
			break;
		case ast::type::OutputLayout::eLineStrip:
			result = "LineStream";
			break;
		case ast::type::OutputLayout::eTriangleStrip:
			result = "TriangleStream";
			break;
		default:
			throw std::runtime_error{ "Unsupported output layout." };
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
		case ast::type::Kind::eGeometryInput:
			result = getLayoutName( static_cast< ast::type::GeometryInput const & >( *type ).layout )
				+ " " + getTypeName( static_cast< ast::type::GeometryInput const & >( *type ).type );
			break;
		case ast::type::Kind::eGeometryOutput:
			result = getLayoutName( static_cast< ast::type::GeometryOutput const & >( *type ).layout )
				+ "<" + getTypeName( static_cast< ast::type::GeometryOutput const & >( *type ).type ) + ">";
			break;
		case ast::type::Kind::eTessellationControlInput:
			result = std::string{ "InputPatch" }
				+ "<" + getTypeName( static_cast< ast::type::TessellationControlInput const & >( *type ).getType() )
				+ ", " + std::to_string( static_cast< ast::type::TessellationControlInput const & >( *type ).getInputVertices() ) + ">";
			break;
		case ast::type::Kind::eTessellationControlOutput:
			result = getTypeName( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType() );
			break;
		case ast::type::Kind::eComputeInput:
			result = getTypeName( static_cast< ast::type::ComputeInput const & >( *type ).getType() );
			break;
		default:
			result = getTypeName( type->getKind() );
			break;
		}

		return result;
	}

	std::string getTypeArraySize( ast::type::TypePtr type )
	{
		if ( type->getKind() == ast::type::Kind::eGeometryInput )
		{
			return "[" + std::to_string( ast::type::getArraySize( static_cast< ast::type::GeometryInput const & >( *type ).layout ) ) + "]";
		}

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

	ast::type::Kind getBuiltinHlslKind( ast::Builtin builtin
		, ast::type::Kind input )
	{
		ast::type::Kind result = input;

		if ( builtin == ast::Builtin::eVertexIndex
			|| builtin == ast::Builtin::eInstanceIndex
			|| builtin == ast::Builtin::eDrawIndex
			|| builtin == ast::Builtin::eBaseVertex
			|| builtin == ast::Builtin::eBaseInstance
			|| builtin == ast::Builtin::ePrimitiveID
			|| builtin == ast::Builtin::eInvocationID
			|| builtin == ast::Builtin::eSampleID
			|| builtin == ast::Builtin::eLayer
			|| builtin == ast::Builtin::eViewportIndex
			|| builtin == ast::Builtin::ePatchVerticesIn
			|| builtin == ast::Builtin::ePrimitiveIDIn )
		{
			result = ast::type::Kind::eUInt;
		}

		return result;
	}

	std::string getSemantic( ast::Builtin builtin
		, uint32_t location
		, ast::type::TypePtr type
		, Semantic & defaultSemantic )
	{
		static std::map< ast::Builtin, std::string > const NamesMap
		{
			{ ast::Builtin::eInvocationID, "SV_GSInstanceID" },
			{ ast::Builtin::eLocalInvocationID, "SV_GroupThreadID" },
			{ ast::Builtin::eLocalInvocationIndex, "SV_GroupIndex" },
			{ ast::Builtin::eWorkGroupID, "SV_GroupID" },
			{ ast::Builtin::eTessCoord, "SV_DomainLocation" },
			{ ast::Builtin::eGlobalInvocationID, "SV_DispatchThreadID" },
			{ ast::Builtin::eFragDepth, "SV_Depth" },
			{ ast::Builtin::eSampleMask, "SV_Coverage" },
			{ ast::Builtin::eCullDistance, "SV_CullDistance" },
			{ ast::Builtin::eClipDistance, "SV_ClipDistance" },
			{ ast::Builtin::eTessLevelInner, "SV_InsideTessFactor" },
			{ ast::Builtin::eInstanceIndex, "SV_InstanceID" },
			{ ast::Builtin::eInstanceIndex, "SV_InstanceID" },
			{ ast::Builtin::eFrontFacing, "SV_IsFrontFace" },
			{ ast::Builtin::ePosition, "SV_Position" },
			{ ast::Builtin::eFragCoord, "SV_Position" },
			{ ast::Builtin::ePrimitiveID, "SV_PrimitiveID" },
			{ ast::Builtin::eLayer, "SV_RenderTargetArrayIndex" },
			{ ast::Builtin::eSampleID, "SV_SampleIndex" },
			{ ast::Builtin::eFragStencilRefEXT, "SV_StencilRef" },
			{ ast::Builtin::eTessLevelOuter, "SV_TessFactor" },
			{ ast::Builtin::eVertexIndex, "SV_VertexID" },
			{ ast::Builtin::eVertexIndex, "SV_VertexID" },
			{ ast::Builtin::eViewportIndex, "SV_ViewportArrayIndex" },
		};
		std::string result;
		auto it = NamesMap.find( builtin );

		if ( it != NamesMap.end() )
		{
			result = it->second;
		}
		else
		{
			result = defaultSemantic.name + std::to_string( location );
			uint32_t inc = 1u;

			if ( isMatrixType( type->getKind() ) )
			{
				inc = getComponentCount( type );
			}

			auto arraySize = getArraySize( type );

			if ( arraySize != ast::type::NotArray )
			{
				inc *= arraySize;
			}

			defaultSemantic.index += inc;
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

	LinkedVars::iterator updateLinkedVars( ast::var::VariablePtr var
		, LinkedVars & linkedVars
		, uint32_t & nextVarId )
	{
		auto it = linkedVars.find( var );
		auto type = getNonArrayType( var->getType() );

		if ( isSampledImageType( type->getKind() )
			&& it == linkedVars.end() )
		{
			auto sampledType = std::static_pointer_cast< ast::type::SampledImage >( type );

			if ( sampledType->getConfig().dimension != ast::type::ImageDim::eBuffer )
			{
				auto texture = ast::var::makeVariable( ++nextVarId
					, sampledType->getImageType()
					, var->getName() + "_texture" );
				auto sampler = ast::var::makeVariable( ++nextVarId
					, sampledType->getSamplerType()
					, var->getName() + "_sampler" );
				it = linkedVars.emplace( var, std::make_pair( texture, sampler ) ).first;
			}
		}

		return it;
	}

	//*********************************************************************************************

	static uint32_t constexpr BuiltinIndex = 128u;

	IOMapping::IOMapping( HlslShader & pshader
		, bool needsSeparateFunc
		, bool pisInput )
		: shader{ &pshader }
		, stage{ shader->getType() }
		, isInput{ pisInput }
	{
		auto suffix = ( isInput ? std::string{ "Input" } : std::string{ "Output" } );
		auto flag = isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderInput;
		paramStruct = shader->getTypesCache().getIOStruct( ast::type::MemoryLayout::eC
			, "HLSL_SDW_Param" + suffix
			, flag );
		paramVar = shader->registerName( "sdw" + suffix + "Param"
			, paramStruct
			, flag );

		if ( needsSeparateFunc )
		{
			globalStruct = shader->getTypesCache().getStruct( ast::type::MemoryLayout::eC
				, "HLSL_SDW_" + suffix );
			globalVar = shader->registerName( "sdw" + suffix
				, globalStruct
				, ast::var::Flag::eStatic );
			mainVar = globalVar;
		}
		else
		{
			mainVar = paramVar;
		}
	}

	void IOMapping::declare( bool needsSeparateFunc
		, ast::stmt::Container & stmt )
	{
		stmt.addStmt( ast::stmt::makeStructureDecl( paramStruct ) );

		if ( needsSeparateFunc )
		{
			stmt.addStmt( ast::stmt::makeStructureDecl( globalStruct ) );
		}

		if ( globalVar && !globalStruct->empty() )
		{
			assert( mainVar == globalVar );
			stmt.addStmt( ast::stmt::makeVariableDecl( globalVar ) );
		}
	}

	ast::var::VariablePtr IOMapping::initialiseMainVar( ast::var::VariablePtr srcVar
		, ast::type::TypePtr type
		, uint32_t flags
		, VarVarMap & paramToEntryPoint )
	{
		mainVar->updateType( type );
		paramToEntryPoint.emplace( srcVar, mainVar );
		return mainVar;
	}

	void IOMapping::addPending( ast::var::VariablePtr pendingVar
		, uint32_t location )
	{
		auto ires = pending.emplace( pendingVar->getName(), PendingIO{} );

		if ( ires.second )
		{
			auto it = ires.first;
			it->second.location = location;
			it->second.var = pendingVar;
		}
	}

	void IOMapping::addPendingMbr( ast::var::VariablePtr outerVar
		, uint32_t mbrIndex
		, uint32_t flags
		, uint32_t location )
	{
		auto it = std::find_if( pendingMbr.begin()
			, pendingMbr.end()
			, [&outerVar, &mbrIndex]( PendingMbrIO const & lookup )
			{
				return lookup.index == mbrIndex
					&& lookup.outer == outerVar;
			} );

		if ( it == pendingMbr.end() )
		{
			PendingIO io{};
			io.location = location;
			io.flags = flags;
			pendingMbr.push_back( { outerVar, mbrIndex, io } );
		}
	}

	void IOMapping::addPendingMbr( ast::expr::Expr * outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location )
	{
		auto ident = ast::findIdentifier( outer );
		assert( ident );
		addPendingMbr( ident->getVariable()
			, mbrIndex
			, flags.getFlags()
			, location );
	}

	ast::expr::ExprPtr IOMapping::processPendingMbr( ast::expr::Expr * outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & pflags
		, ExprAdapter & adapter )
	{
		if ( !pflags.isShaderInput() && !pflags.isShaderOutput() )
		{
			return nullptr;
		}

		auto ident = ast::findIdentifier( outer );

		if ( !ident )
		{
			return nullptr;
		}

		auto outerVar = ident->getVariable();
		auto it = std::find_if( pendingMbr.begin()
			, pendingMbr.end()
			, [&outerVar, &mbrIndex]( PendingMbrIO const & lookup )
			{
				return lookup.index == mbrIndex
					&& lookup.outer == outerVar;
			} );

		if ( pendingMbr.end() == it )
		{
			return nullptr;
		}

		auto & mbr = *it;

		if ( mbr.io.result.mbrIndex == ast::type::Struct::NotFound )
		{
			auto structType = getStructType( mbr.outer->getType() );
			mbr.io.result = processPendingType( *structType
				, mbr.index
				, mbr.io.flags
				, mbr.io.location );
		}

		auto & cache = mbr.outer->getType()->getCache();
		auto outerIdent = ast::expr::makeIdentifier( cache, mainVar );

		if ( outer->getKind() != ast::expr::Kind::eArrayAccess )
		{
			return ast::expr::makeMbrSelect( std::move( outerIdent )
				, mbr.io.result.mbrIndex
				, mbr.io.result.flags );
		}

		auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
		return ast::expr::makeMbrSelect( ast::expr::makeArrayAccess( arrayAccess.getType()
				, std::move( outerIdent )
				, adapter.doSubmit( static_cast< ast::expr::ArrayAccess const & >( *outer ).getRHS() ) )
			, mbr.io.result.mbrIndex
			, mbr.io.result.flags );
	}

	ast::expr::ExprPtr IOMapping::processPending( std::string const & name )
	{
		auto it = pending.find( name );

		if ( pending.end() == it )
		{
			return nullptr;
		}

		auto & mbr = *it;
		auto pendingVar = mbr.second.var;
		auto type = pendingVar->getType();
		auto location = it->second.location;

		if ( mbr.second.result.mbrIndex == ast::type::Struct::NotFound )
		{
			mbr.second.result = processPendingType( type
				, pendingVar->getName()
				, pendingVar->isBuiltin() ? pendingVar->getBuiltin() : ast::Builtin::eNone
				, mbr.second.flags
				, location );
		}

		auto & cache = type->getCache();
		auto outerIdent = ast::expr::makeIdentifier( cache, mainVar );
		return ast::expr::makeMbrSelect( std::move( outerIdent )
			, mbr.second.result.mbrIndex
			, mbr.second.result.flags );
	}

	ast::expr::ExprPtr IOMapping::processPending( ast::var::VariablePtr srcVar )
	{
		auto result = processPending( srcVar->getName() );

		if ( result )
		{
			return result;
		}

		return ast::expr::makeIdentifier( srcVar->getType()->getCache()
				, srcVar );
	}

	bool IOMapping::isValid( ast::Builtin builtin )
	{
		if ( isInput )
		{
			return isShaderInput( builtin, stage );
		}

		return isShaderOutput( builtin, stage );
	}

	PendingResult IOMapping::processPendingType( ast::type::TypePtr type
		, std::string const & name
		, ast::Builtin builtin
		, uint32_t flags
		, uint32_t location )
	{
		if ( globalStruct )
		{
			auto res = globalStruct->findMember( name );

			if ( res != ast::type::Struct::NotFound )
			{
				return { res, 0u };
			}
		}

		if ( builtin != ast::Builtin::eNone )
		{
			auto res = paramStruct->findMember( builtin );

			if ( res != ast::type::Struct::NotFound )
			{
				return { res, flags };
			}
		}
		else
		{
			auto res = paramStruct->findMember( name );

			if ( res != ast::type::Struct::NotFound )
			{
				return { res, flags };
			}
		}

		auto resultIndex = uint32_t( paramStruct->size() );
		auto resultFlags = flags;

		if ( builtin != ast::Builtin::eNone )
		{
			paramStruct->declMember( builtin
				, getNonArrayType( type )->getKind()
				, getArraySize( type ) );
		}
		else
		{
			paramStruct->declMember( name
				, getNonArrayType( type )->getKind()
				, getArraySize( type )
				, location );
		}

		if ( globalStruct )
		{
			// Separate function needed.
			resultIndex = uint32_t( globalStruct->size() );
			resultFlags = 0u;
			globalStruct->declMember( name
				, getNonArrayType( type )->getKind()
				, getArraySize( type ) );
		}

		return { resultIndex, resultFlags };
	}

	PendingResult IOMapping::processPendingType( ast::type::Struct const & structType
		, uint32_t mbrIndex
		, uint32_t mbrFlags
		, uint32_t mbrLocation )
	{
		auto & mbr = *std::next( structType.begin(), ptrdiff_t( mbrIndex ) );
		return processPendingType( mbr.type
			, mbr.name
			, mbr.builtin
			, mbrFlags
			, mbrLocation );
	}

	//*********************************************************************************************

	EntryPoint::EntryPoint( HlslShader & pshader
		, AdaptationData * pparent
		, bool pisMain )
		: shader{ &pshader }
		, parent{ pparent }
		, isMain{ pisMain }
		, inputs{ *shader, needsSeparateMain( shader->getType(), isMain ), true }
		, outputs{ *shader, needsSeparateMain( shader->getType(), isMain ), false }
	{
	}

	void EntryPoint::initialise( ast::stmt::FunctionDecl const & stmt )
	{
		auto funcType = stmt.getType();
		auto isEntryPoint = stmt.isEntryPoint();

		for ( auto & param : *funcType )
		{
			auto type = param->getType();

			if ( type->getKind() == ast::type::Kind::eComputeInput )
			{
				registerComputeInput( param
					, static_cast< ast::type::ComputeInput const & >( *type ) );
			}
			else if ( type->getKind() == ast::type::Kind::eGeometryInput )
			{
				registerGeometryInput( param
					, static_cast< ast::type::GeometryInput const & >( *type ) );
			}
			else if ( type->getKind() == ast::type::Kind::eGeometryOutput )
			{
				registerGeometryOutput( param
					, static_cast< ast::type::GeometryOutput const & >( *type ) );
			}
			else if ( type->getKind() == ast::type::Kind::eTessellationControlInput )
			{
				registerTessellationControlInput( param
					, static_cast< ast::type::TessellationControlInput const & >( *type )
					, isEntryPoint );
			}
			else if ( type->getKind() == ast::type::Kind::eTessellationControlOutput )
			{
				registerTessellationControlOutput( param
					, static_cast< ast::type::TessellationControlOutput const & >( *type )
					, isEntryPoint );
			}
			else if ( type->getKind() == ast::type::Kind::eTessellationOutputPatch )
			{
				registerOutputPatch( param
					, static_cast< ast::type::TessellationOutputPatch const & >( *type )
					, isEntryPoint );
			}
			else
			{
				uint32_t arraySize = ast::type::NotArray;

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					auto & arrayType = static_cast< ast::type::Array const & >( *type );
					type = arrayType.getType();
					arraySize = arrayType.getArraySize();
				}

				if ( type->getKind() == ast::type::Kind::eStruct )
				{
					auto structType = std::static_pointer_cast< ast::type::Struct >( type );

					if ( structType->isShaderInput() )
					{
						registerInput( param
							, static_cast< ast::type::IOStruct const & >( *structType )
							, isEntryPoint );
					}
					else if ( structType->isShaderOutput() )
					{
						registerOutput( param
							, static_cast< ast::type::IOStruct const & >( *structType )
							, isEntryPoint );
					}
					else if ( param->isPatchInput() )
					{
						registerInputPatch( param
							, structType
							, isEntryPoint );
					}
				}
			}
		}
	}

	ast::stmt::ContainerPtr EntryPoint::declare()
	{
		auto cont = ast::stmt::makeContainer();
		inputs.declare( needsSeparateFunc, *cont );
		outputs.declare( needsSeparateFunc, *cont );
		inOutDeclarations = cont.get();
		return cont;
	}

	void EntryPoint::addInputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		inputs.addPending( var, location );

		if ( needsSeparateFunc )
		{
			inputs.processPending( var );
		}
	}

	void EntryPoint::addOutputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		outputs.addPending( var, location );

		if ( needsSeparateFunc )
		{
			outputs.processPending( var );
		}
	}

	ast::expr::ExprPtr EntryPoint::processPendingMbr( ast::expr::Expr * outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, ExprAdapter & adapter )
	{
		if ( flags.isShaderInput() )
		{
			return processPendingMbrInput( outer
				, mbrIndex
				, flags
				, adapter );
		}

		return processPendingMbrOutput( outer
			, mbrIndex
			, flags
			, adapter );
	}

	ast::expr::ExprPtr EntryPoint::processPending( ast::var::VariablePtr var )
	{
		auto it = paramToEntryPoint.find( var );

		if ( it != paramToEntryPoint.end() )
		{
			return ast::expr::makeIdentifier( var->getType()->getCache()
				, it->second );
		}

		if ( var->isShaderInput() )
		{
			return processPendingInput( var );
		}

		return processPendingOutput( var );
	}

	bool EntryPoint::isInput( ast::Builtin builtin )
	{
		return inputs.isValid( builtin );
	}

	bool EntryPoint::isOutput( ast::Builtin builtin )
	{
		return outputs.isValid( builtin );
	}

	void EntryPoint::addMbrBuiltin( ast::expr::Expr * outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location )
	{
		if ( flags.isShaderOutput() )
		{
			addPendingMbrOutput( outer
				, mbrIndex
				, flags
				, location );
		}
		else
		{
			addPendingMbrInput( outer
				, mbrIndex
				, flags
				, location );
		}
	}

	void EntryPoint::addBuiltin( ast::var::VariablePtr var )
	{
		//auto & cache = var->getType()->getCache();

		//if ( isInput( var->getBuiltin() ) )
		//{
		//	auto hlslKind = getBuiltinHlslKind( var->getBuiltin()
		//		, var->getType()->getKind() );

		//	if ( hlslKind != var->getType()->getKind() )
		//	{
		//		var = shader->registerName( var->getName()
		//			, cache.getBasicType( hlslKind ) );
		//	}

		//	addInputBuiltin( var );
		//}

		//if ( isOutput( var->getBuiltin() ) )
		//{
		//	auto hlslKind = getBuiltinHlslKind( var->getBuiltin()
		//		, var->getType()->getKind() );

		//	if ( hlslKind != var->getType()->getKind() )
		//	{
		//		var = shader->registerName( var->getName()
		//			, cache.getBasicType( hlslKind ) );
		//	}

		//	addOutputBuiltin( var );
		//}
	}

	void EntryPoint::registerComputeInput( ast::var::VariablePtr var
		, ast::type::ComputeInput const & compType )
	{
		auto type = compType.getType();

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, true );
		}

		inputs.initialiseMainVar( var
			, ast::type::makeComputeInputType( inputs.paramStruct
				, compType.getLocalSizeX()
				, compType.getLocalSizeY()
				, compType.getLocalSizeZ() )
			, ast::var::Flag::eInputParam | ast::var::Flag::eShaderInput
			, paramToEntryPoint );
	}

	void EntryPoint::registerGeometryInput( ast::var::VariablePtr var
		, ast::type::GeometryInput const & geomType )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, true );
		}

		inputs.initialiseMainVar( var
			, ast::type::makeGeometryInputType( inputs.paramStruct
				, geomType.layout )
			, ast::var::Flag::eInputParam | ast::var::Flag::eShaderInput
			, paramToEntryPoint );
	}

	void EntryPoint::registerGeometryOutput( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType )
	{
		auto type = geomType.type;

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderOutput() );
			registerOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, true );
		}

		outputs.initialiseMainVar( var
			, ast::type::makeGeometryOutputType( outputs.paramStruct
				, geomType.layout
				, geomType.count )
			, ast::var::Flag::eInputParam | ast::var::Flag::eOutputParam | ast::var::Flag::eShaderOutput
			, paramToEntryPoint );
	}

	void EntryPoint::registerTessellationControlInput( ast::var::VariablePtr var
		, ast::type::TessellationControlInput const & tessType
		, bool isEntryPoint )
	{
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderInput() );
			registerInput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, isEntryPoint );
		}

		inputs.initialiseMainVar( var
			, ast::type::makeTessellationControlInputType( inputs.paramStruct
				, tessType.getInputVertices() )
			, ast::var::Flag::eInputParam | ast::var::Flag::eShaderInput
			, paramToEntryPoint );
	}

	void EntryPoint::registerTessellationControlOutput( ast::var::VariablePtr var
		, ast::type::TessellationControlOutput const & tessType
		, bool isEntryPoint )
	{
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			auto & structType = static_cast< ast::type::Struct const & >( *type );
			assert( structType.isShaderOutput() );
			registerOutput( var
				, static_cast< ast::type::IOStruct const & >( structType )
				, isEntryPoint );
		}

		outputs.initialiseMainVar( var
			, ast::type::makeTessellationControlOutputType( outputs.paramStruct
				, tessType.getDomain()
				, tessType.getPartitioning()
				, tessType.getTopology()
				, tessType.getOrder()
				, tessType.getOutputVertices() )
			, ast::var::Flag::eInputParam | ast::var::Flag::eOutputParam | ast::var::Flag::eShaderOutput
			, paramToEntryPoint );
	}

	void EntryPoint::registerInput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType
		, bool isEntryPoint )
	{
		uint32_t index = 0u;
		auto flags = structType.getFlag();

		for ( auto & mbr : structType )
		{
			inputs.addPendingMbr( var
				, index++
				, ( flags
					| ( ( mbr.builtin == ast::Builtin::eNone )
						? ast::var::Flag::eNone
						: ast::var::Flag::eBuiltin ) )
				, ( ( mbr.builtin == ast::Builtin::eNone )
					? mbr.location
					: ast::type::Struct::InvalidLocation ) );
		}
	}

	void EntryPoint::registerOutput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType
		, bool isEntryPoint )
	{
		uint32_t index = 0u;
		auto flags = structType.getFlag();

		for ( auto & mbr : structType )
		{
			outputs.addPendingMbr( var
				, index++
				, ( flags
					| ( ( mbr.builtin == ast::Builtin::eNone )
						? ast::var::Flag::eNone
						: ast::var::Flag::eBuiltin ) )
				, ( ( mbr.builtin == ast::Builtin::eNone )
					? mbr.location
					: ast::type::Struct::InvalidLocation ) );
		}
	}

	void EntryPoint::registerInputPatch( ast::var::VariablePtr var
		, ast::type::StructPtr const & structType
		, bool isEntryPoint )
	{
		parent->declareStruct( structType, inOutDeclarations );
	}

	void EntryPoint::registerOutputPatch( ast::var::VariablePtr var
		, ast::type::TessellationOutputPatch const & patchType
		, bool isEntryPoint )
	{
		auto type = patchType.getType();

		if ( type->getKind() == ast::type::Kind::eStruct )
		{
			parent->declareStruct( std::static_pointer_cast< ast::type::Struct >( type )
				, inOutDeclarations );
		}
	}

	//*********************************************************************************************

	AdaptationData::AdaptationData( HlslShader & shader )
	{
		entryPoints.emplace( "main"
			, std::make_unique< EntryPoint >( shader, this, true ) );
		mainEntryPoint = entryPoints["main"].get();
	}

	void AdaptationData::declareStruct( ast::type::StructPtr const & structType
		, ast::stmt::Container * stmt )
	{
		if ( stmt
			&& m_declaredStructs.emplace( structType ).second )
		{
			stmt->addStmt( ast::stmt::makeStructureDecl( structType ) );
		}
	}

	//*********************************************************************************************
}
