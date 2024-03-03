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
#include <ShaderAST/Stmt/StmtInputComputeLayout.hpp>
#include <ShaderAST/Stmt/StmtReturn.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Stmt/StmtStructureDecl.hpp>
#include <ShaderAST/Type/TypeGeometryIO.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampler.hpp>
#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <stdexcept>

namespace hlsl
{
	namespace HlslHelpersInternal
	{
		static std::string getTypeName( ast::type::ImageConfiguration const & config )
		{
			std::string result;

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

		static std::string getTypeName( ast::type::ImagePtr type )
		{
			return getTypeName( type->getConfig() );
		}

		static std::string getTypeName( ast::type::SampledImagePtr type )
		{
			return getTypeName( type->getConfig() );
		}

		static std::string getTypeName( ast::type::SamplerPtr type )
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

		static bool isHighFreq( ast::Builtin builtin
			, bool isInput )
		{
			switch ( builtin )
			{
			case ast::Builtin::eNone:
			case ast::Builtin::ePosition:
			case ast::Builtin::ePointSize:
			case ast::Builtin::eClipDistance:
			case ast::Builtin::eCullDistance:
			case ast::Builtin::eTessLevelInner:
			case ast::Builtin::eTessLevelOuter:
				return true;
			case ast::Builtin::eLayer:
			case ast::Builtin::eViewportIndex:
			case ast::Builtin::ePrimitiveID:
				return !isInput;
			default:
				return false;
			}
		}

		static bool isShaderInput( ast::Builtin builtin
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

		static bool isShaderOutput( ast::Builtin builtin
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

		static ast::type::TypePtr getNonNull( ast::type::TypePtr const & lhs
			, ast::type::TypePtr const & rhs )
		{
			return lhs ? lhs : rhs;
		}

		static bool needsSeparate( IOMappingMode mode )
		{
			return mode != IOMappingMode::eNoSeparate
				&& mode != IOMappingMode::eNoSeparateDistinctParams
				&& mode != IOMappingMode::eLocalReturn;
		}

		static IOMappingMode getMode( ast::ShaderStage stage
			, bool isInput
			, bool isHighFreq
			, bool isPrimitiveIndices )
		{
			if ( isPrimitiveIndices )
			{
				return IOMappingMode::eNoSeparate;
			}

			if ( !isHighFreq
				&& !isMeshStage( stage ) )
			{
				return IOMappingMode::eNoSeparateDistinctParams;
			}

			if ( stage == ast::ShaderStage::eGeometry
				&& !isInput )
			{
				return IOMappingMode::eLocalSeparateVar;
			}

			if ( stage == ast::ShaderStage::eTessellationControl
				&& !isInput )
			{
				return IOMappingMode::eLocalReturn;
			}

			if ( stage == ast::ShaderStage::eTessellationEvaluation
				&& !isInput )
			{
				return IOMappingMode::eLocalReturn;
			}

			return IOMappingMode::eNoSeparate;
		}

		static void declareStruct( ast::stmt::Container & stmt
			, ast::type::StructPtr const & structType
			, ast::UnorderedStringSet & declaredStructs )
		{
			if ( declaredStructs.emplace( structType->getName() ).second )
			{
				stmt.addStmt( stmt.getStmtCache().makeStructureDecl( structType ) );
			}
		}

		static std::string getFuncName( bool isMain )
		{
			return ( isMain
				? std::string{ "Main" }
			: std::string{ "" } );
		}

		static bool isSupported( ast::Builtin builtin
			, ast::ShaderStage stage
			, bool isInput )
		{
			switch ( builtin )
			{
			case ast::Builtin::eLocalInvocationID:
			case ast::Builtin::eLocalInvocationIndex:
			case ast::Builtin::eWorkGroupID:
			case ast::Builtin::eTessCoord:
			case ast::Builtin::eGlobalInvocationID:
			case ast::Builtin::eFragDepth:
			case ast::Builtin::eSampleMask:
			case ast::Builtin::eSampleMaskIn:
			case ast::Builtin::eCullDistance:
			case ast::Builtin::eClipDistance:
			case ast::Builtin::eTessLevelInner:
			case ast::Builtin::eInstanceIndex:
			case ast::Builtin::eFrontFacing:
			case ast::Builtin::ePosition:
			case ast::Builtin::eFragCoord:
			case ast::Builtin::eSampleID:
			case ast::Builtin::eFragStencilRefEXT:
			case ast::Builtin::eTessLevelOuter:
			case ast::Builtin::eVertexIndex:
				return true;
			case ast::Builtin::eViewportIndex:
				return stage == ast::ShaderStage::eGeometry;
			case ast::Builtin::ePrimitiveID:
				return ( isInput
						&& ( stage == ast::ShaderStage::eTessellationControl
							|| stage == ast::ShaderStage::eTessellationEvaluation ) )
					|| ( !isInput
						&& stage == ast::ShaderStage::eGeometry );
			case ast::Builtin::ePrimitiveIDIn:
				return isInput
					&& stage == ast::ShaderStage::eGeometry;
			case ast::Builtin::eLayer:
				return stage == ast::ShaderStage::eGeometry;
			default:
				return false;
			}
		}
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
		case ast::type::Kind::eRayDesc:
			result = "struct";
			break;
		case ast::type::Kind::eFunction:
			result = "function";
			break;
		case ast::type::Kind::eBoolean:
			result = "bool";
			break;
		case ast::type::Kind::eInt8:
			result = "int8_t";
			break;
		case ast::type::Kind::eInt16:
			result = "int16_t";
			break;
		case ast::type::Kind::eInt32:
			result = "int";
			break;
		case ast::type::Kind::eInt64:
			result = "int64_t";
			break;
		case ast::type::Kind::eUInt8:
			result = "uint8_t";
			break;
		case ast::type::Kind::eUInt16:
			result = "uint16_t";
			break;
		case ast::type::Kind::eUInt32:
			result = "uint";
			break;
		case ast::type::Kind::eUInt64:
			result = "uint64_t";
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
		case ast::type::Kind::eVec2I8:
			result = "int8_t2";
			break;
		case ast::type::Kind::eVec3I8:
			result = "int8_t3";
			break;
		case ast::type::Kind::eVec4I8:
			result = "int8_t4";
			break;
		case ast::type::Kind::eVec2I16:
			result = "int16_t2";
			break;
		case ast::type::Kind::eVec3I16:
			result = "int16_t3";
			break;
		case ast::type::Kind::eVec4I16:
			result = "int16_t4";
			break;
		case ast::type::Kind::eVec2I32:
			result = "int2";
			break;
		case ast::type::Kind::eVec3I32:
			result = "int3";
			break;
		case ast::type::Kind::eVec4I32:
			result = "int4";
			break;
		case ast::type::Kind::eVec2I64:
			result = "int64_t2";
			break;
		case ast::type::Kind::eVec3I64:
			result = "int64_t3";
			break;
		case ast::type::Kind::eVec4I64:
			result = "int64_t4";
			break;
		case ast::type::Kind::eVec2U8:
			result = "uint8_t2";
			break;
		case ast::type::Kind::eVec3U8:
			result = "uint8_t3";
			break;
		case ast::type::Kind::eVec4U8:
			result = "uint8_t4";
			break;
		case ast::type::Kind::eVec2U16:
			result = "uint16_t2";
			break;
		case ast::type::Kind::eVec3U16:
			result = "uint16_t3";
			break;
		case ast::type::Kind::eVec4U16:
			result = "uint16_t4";
			break;
		case ast::type::Kind::eVec2U32:
			result = "uint2";
			break;
		case ast::type::Kind::eVec3U32:
			result = "uint3";
			break;
		case ast::type::Kind::eVec4U32:
			result = "uint4";
			break;
		case ast::type::Kind::eVec2U64:
			result = "uint64_t2";
			break;
		case ast::type::Kind::eVec3U64:
			result = "uint64_t3";
			break;
		case ast::type::Kind::eVec4U64:
			result = "uint64_t4";
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
			result = "SamplerState";
			break;
		case ast::type::Kind::eSampledImage:
			result = "SampledImage";
			break;
		case ast::type::Kind::eCombinedImage:
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
		case ast::type::Kind::eAccelerationStructure:
			result = "RaytracingAccelerationStructure";
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

		if ( var.isIncomingRayPayload()
			|| var.isIncomingCallableData()
			|| ( var.isInputParam() && var.isOutputParam() ) )
		{
			result = "inout ";
		}
		else if ( var.isPerTaskNV() || var.isPerTask() )
		{
			result = "groupshared ";
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
		case ast::expr::Kind::eCopy:
			break;
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
		case ast::expr::Kind::eOrAssign:
			result = "|=";
			break;
		case ast::expr::Kind::eXorAssign:
			result = "^=";
			break;
		default:
			throw ast::Exception{ "Non operation expression" };
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
			throw ast::Exception{ "Unsupported input layout." };
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
			throw ast::Exception{ "Unsupported output layout." };
		}

		return result;
	}

	std::string getLayoutName( ast::type::OutputTopology layout )
	{
		std::string result;

		switch ( layout )
		{
		case ast::type::OutputTopology::ePoint:
			result = "point";
			break;
		case ast::type::OutputTopology::eLine:
			result = "line";
			break;
		case ast::type::OutputTopology::eTriangle:
			result = "triangle";
			break;
		default:
			throw ast::Exception{ "Unsupported output topology." };
		}

		return result;
	}

	std::string getAttributeName( ast::type::TypePtr type )
	{
		std::string result;

		if ( type->getKind() == ast::type::Kind::eMeshVertexOutput )
		{
			result = "vertices ";
		}
		else if ( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
		{
			result = "primitives ";
		}
		else if ( type->getKind() == ast::type::Kind::eTaskPayload
			|| type->getKind() == ast::type::Kind::eTaskPayloadNV )
		{
			result = "payload ";
		}
		else if ( type->getKind() == ast::type::Kind::eTaskPayloadIn
			|| type->getKind() == ast::type::Kind::eTaskPayloadInNV )
		{
			result = "payload ";
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

		switch ( type->getRawKind() )
		{
		case ast::type::Kind::eStruct:
		case ast::type::Kind::eRayDesc:
			result = static_cast< ast::type::Struct const & >( *type ).getName();
			break;
		case ast::type::Kind::eImage:
			result = HlslHelpersInternal::getTypeName( std::static_pointer_cast< ast::type::Image >( type ) );
			break;
		case ast::type::Kind::eSampler:
			result = HlslHelpersInternal::getTypeName( std::static_pointer_cast< ast::type::Sampler >( type ) );
			break;
		case ast::type::Kind::eSampledImage:
			result = HlslHelpersInternal::getTypeName( std::static_pointer_cast< ast::type::SampledImage >( type ) );
			break;
		case ast::type::Kind::eGeometryInput:
			result = getLayoutName( static_cast< ast::type::GeometryInput const & >( *type ).getLayout() )
				+ " " + getTypeName( static_cast< ast::type::GeometryInput const & >( *type ).getType() );
			break;
		case ast::type::Kind::eGeometryOutput:
			result = getLayoutName( static_cast< ast::type::GeometryOutput const & >( *type ).getLayout() )
				+ "<" + getTypeName( static_cast< ast::type::GeometryOutput const & >( *type ).getType() ) + ">";
			break;
		case ast::type::Kind::eTessellationControlInput:
			result = std::string{ "InputPatch" }
				+ "<" + getTypeName( static_cast< ast::type::TessellationControlInput const & >( *type ).getType() )
				+ ", " + std::to_string( static_cast< ast::type::TessellationControlInput const & >( *type ).getInputVertices() ) + ">";
			break;
		case ast::type::Kind::eTessellationControlOutput:
			result = getTypeName( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType() );
			break;
		case ast::type::Kind::eTessellationEvaluationInput:
			result = std::string{ "OutputPatch" }
				+ "<" + getTypeName( static_cast< ast::type::TessellationEvaluationInput const & >( *type ).getType() )
				+ ", " + std::to_string( static_cast< ast::type::TessellationEvaluationInput const & >( *type ).getInputVertices() ) + ">";
			break;
		case ast::type::Kind::eTessellationInputPatch:
			result = getTypeName( static_cast< ast::type::TessellationInputPatch const & >( *type ).getType() );
			break;
		case ast::type::Kind::eTessellationOutputPatch:
			result = getTypeName( static_cast< ast::type::TessellationOutputPatch const & >( *type ).getType() );
			break;
		case ast::type::Kind::eFragmentInput:
			result = getTypeName( static_cast< ast::type::FragmentInput const & >( *type ).getType() );
			break;
		case ast::type::Kind::eComputeInput:
			result = getTypeName( static_cast< ast::type::ComputeInput const & >( *type ).getType() );
			break;
		case ast::type::Kind::eRayPayload:
			result = getTypeName( static_cast< ast::type::RayPayload const & >( *type ).getDataType() );
			break;
		case ast::type::Kind::eCallableData:
			result = getTypeName( static_cast< ast::type::CallableData const & >( *type ).getDataType() );
			break;
		case ast::type::Kind::eHitAttribute:
			result = getTypeName( static_cast< ast::type::HitAttribute const & >( *type ).getDataType() );
			break;
		case ast::type::Kind::eMeshVertexOutput:
			result = getTypeName( static_cast< ast::type::MeshVertexOutput const & >( *type ).getType() );
			break;
		case ast::type::Kind::eMeshPrimitiveOutput:
			result = getTypeName( static_cast< ast::type::MeshPrimitiveOutput const & >( *type ).getType() );
			break;
		case ast::type::Kind::eTaskPayloadNV:
			result = getTypeName( static_cast< ast::type::TaskPayloadNV const & >( *type ).getType() );
			break;
		case ast::type::Kind::eTaskPayload:
			result = getTypeName( static_cast< ast::type::TaskPayload const & >( *type ).getType() );
			break;
		case ast::type::Kind::eTaskPayloadInNV:
			result = getTypeName( static_cast< ast::type::TaskPayloadInNV const & >( *type ).getType() );
			break;
		case ast::type::Kind::eTaskPayloadIn:
			result = getTypeName( static_cast< ast::type::TaskPayloadIn const & >( *type ).getType() );
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
			return "[" + std::to_string( ast::type::getArraySize( static_cast< ast::type::GeometryInput const & >( *type ).getLayout() ) ) + "]";
		}
		else if ( type->getKind() == ast::type::Kind::eMeshVertexOutput )
		{
			return "[" + std::to_string( static_cast< ast::type::MeshVertexOutput const & >( *type ).getMaxVertices() ) + "]";
		}
		else if ( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
		{
			return "[" + std::to_string( static_cast< ast::type::MeshPrimitiveOutput const & >( *type ).getMaxPrimitives() ) + "]";
		}

		std::string result;

		if ( auto arraySize = getArraySize( type );
			arraySize != ast::type::NotArray )
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
			case ast::type::Kind::eInt8:
				result = "int8_t2";
				break;
			case ast::type::Kind::eInt16:
				result = "int16_t2";
				break;
			case ast::type::Kind::eInt32:
				result = "int2";
				break;
			case ast::type::Kind::eInt64:
				result = "int64_t2";
				break;
			case ast::type::Kind::eUInt8:
				result = "uint8_t2";
				break;
			case ast::type::Kind::eUInt16:
				result = "uint16_t2";
				break;
			case ast::type::Kind::eUInt32:
				result = "uint2";
				break;
			case ast::type::Kind::eUInt64:
				result = "uint64_t2";
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
			case ast::type::Kind::eInt8:
				result = "int8_t3";
				break;
			case ast::type::Kind::eInt16:
				result = "int16_t3";
				break;
			case ast::type::Kind::eInt32:
				result = "int3";
				break;
			case ast::type::Kind::eInt64:
				result = "int64_t3";
				break;
			case ast::type::Kind::eUInt8:
				result = "uint8_t3";
				break;
			case ast::type::Kind::eUInt16:
				result = "uint16_t3";
				break;
			case ast::type::Kind::eUInt32:
				result = "uint3";
				break;
			case ast::type::Kind::eUInt64:
				result = "uint64_t3";
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
			case ast::type::Kind::eInt8:
				result = "int8_t4";
				break;
			case ast::type::Kind::eInt16:
				result = "int16_t4";
				break;
			case ast::type::Kind::eInt32:
				result = "int4";
				break;
			case ast::type::Kind::eInt64:
				result = "int64_t4";
				break;
			case ast::type::Kind::eUInt8:
				result = "uint8_t4";
				break;
			case ast::type::Kind::eUInt16:
				result = "uint16_t4";
				break;
			case ast::type::Kind::eUInt32:
				result = "uint4";
				break;
			case ast::type::Kind::eUInt64:
				result = "uint64_t4";
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
			throw ast::Exception{ "Unsupported composite type." };
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
			result = ast::type::Kind::eUInt32;
		}

		return result;
	}

	std::string getSemantic( ast::ShaderStage stage
		, ast::Builtin builtin
		, bool isInput
		, uint32_t location
		, ast::type::TypePtr type
		, Semantic & defaultSemantic )
	{
		static std::map< ast::Builtin, std::string > const NamesMap
		{
			{ ast::Builtin::eLocalInvocationID, "SV_GroupThreadID" },
			{ ast::Builtin::eLocalInvocationIndex, "SV_GroupIndex" },
			{ ast::Builtin::eWorkGroupID, "SV_GroupID" },
			{ ast::Builtin::eTessCoord, "SV_DomainLocation" },
			{ ast::Builtin::eGlobalInvocationID, "SV_DispatchThreadID" },
			{ ast::Builtin::eFragDepth, "SV_Depth" },
			{ ast::Builtin::eSampleMask, "SV_Coverage" },
			{ ast::Builtin::eSampleMaskIn, "SV_Coverage" },
			{ ast::Builtin::eCullDistance, "SV_CullDistance" },
			{ ast::Builtin::eClipDistance, "SV_ClipDistance" },
			{ ast::Builtin::eTessLevelInner, "SV_InsideTessFactor" },
			{ ast::Builtin::eInstanceIndex, "SV_InstanceID" },
			{ ast::Builtin::eFrontFacing, "SV_IsFrontFace" },
			{ ast::Builtin::ePosition, "SV_Position" },
			{ ast::Builtin::eFragCoord, "SV_Position" },
			{ ast::Builtin::ePrimitiveID, "SV_PrimitiveID" },
			{ ast::Builtin::ePrimitiveIDIn, "SV_PrimitiveID" },
			{ ast::Builtin::eLayer, "SV_RenderTargetArrayIndex" },
			{ ast::Builtin::eSampleID, "SV_SampleIndex" },
			{ ast::Builtin::eFragStencilRefEXT, "SV_StencilRef" },
			{ ast::Builtin::eTessLevelOuter, "SV_TessFactor" },
			{ ast::Builtin::eVertexIndex, "SV_VertexID" },
			{ ast::Builtin::eViewportIndex, "SV_ViewportArrayIndex" },
		};
		std::string result;
		auto it = NamesMap.find( builtin );

		if ( builtin == ast::Builtin::ePosition )
		{
			if ( !isInput
				&& stage == ast::ShaderStage::eTessellationControl )
			{
				return "BEZIERPOS";
			}

			return "SV_Position";
		}
		else if ( builtin == ast::Builtin::eInvocationID )
		{
			if ( stage == ast::ShaderStage::eGeometry )
			{
				return "SV_GSInstanceID";
			}

			return "SV_OutputControlPointID";
		}
		else if ( it != NamesMap.end() )
		{
			result = it->second;
		}
		else if ( location == ast::type::Struct::InvalidLocation )
		{
			result = defaultSemantic.name + std::to_string( defaultSemantic.index );
			uint32_t inc = 1u;

			if ( isMatrixType( type->getKind() ) )
			{
				inc = getComponentCount( type );
			}

			if ( auto arraySize = getArraySize( type );
				arraySize != ast::type::NotArray )
			{
				inc *= arraySize;
			}

			defaultSemantic.index += inc;
		}
		else
		{
			result = defaultSemantic.name + std::to_string( location );
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
		case ast::expr::Kind::eCopy:
		case ast::expr::Kind::ePreIncrement:
		case ast::expr::Kind::ePreDecrement:
		case ast::expr::Kind::eUnaryMinus:
		case ast::expr::Kind::eUnaryPlus:
			result = true;
			break;
		default:
			throw ast::Exception{ "Non unary expression" };
		}

		return result;
	}

	std::string adaptName( std::string const & name )
	{
		if ( name == "texture"
			|| name == "point" )
		{
			return "_" + name;
		}

		return name;
	}

	LinkedVars::iterator updateLinkedVars( ast::var::VariablePtr var
		, LinkedVars & linkedVars
		, uint32_t & nextVarId )
	{
		auto it = linkedVars.find( var );

		if ( auto type = getNonArrayType( var->getType() );
			isTextureType( type->getKind() ) && it == linkedVars.end() )
		{
			auto sampledType = std::static_pointer_cast< ast::type::CombinedImage >( type );

			if ( sampledType->getConfig().dimension != ast::type::ImageDim::eBuffer )
			{
				++nextVarId;
				auto texture = ast::var::makeVariable( nextVarId
					, sampledType->getImageType()
					, var->getName() + "_texture" );
				++nextVarId;
				auto sampler = ast::var::makeVariable( nextVarId
					, sampledType->getSamplerType()
					, var->getName() + "_sampler" );
				it = linkedVars.try_emplace( var, texture, sampler ).first;
			}
		}

		return it;
	}

	//*********************************************************************************************

	IOMapping::IOMapping( ast::expr::ExprCache & pexprCache
		, HlslShader & pshader
		, IOMappingMode pmode
		, bool pisInput
		, bool pisPatch
		, std::string const & infix )
		: exprCache{ pexprCache }
		, shader{ &pshader }
		, stage{ shader->getType() }
		, isInput{ pisInput }
		, isPatch{ pisPatch }
		, mode{ pmode }
	{
		auto suffix = infix + ( isInput ? std::string{ "Input" } : std::string{ "Output" } );
		auto type = ( isPatch ? std::string{ "Patch" } : std::string{ "" } );
		auto flag = ( isPatch
			? ( isInput ? ast::var::Flag::ePatchInput : ast::var::Flag::ePatchOutput )
			: ( isInput ? ast::var::Flag::eShaderInput : ast::var::Flag::eShaderOutput ) );
		auto paramFlag = isInput ? ast::var::Flag::eInputParam : ast::var::Flag::eOutputParam;
		paramStruct = shader->getTypesCache().getIOStruct( "HLSL_SDW_" + infix
			, getEntryPointType( shader->getType() )
			, flag );
		uint64_t flags = flag | paramFlag;

		if ( !isInput )
		{
			if ( stage == ast::ShaderStage::eGeometry )
			{
				flags = flags | ast::var::Flag::eInputParam | ast::var::Flag::eShaderInput;
			}
			else if ( stage == ast::ShaderStage::eTaskNV )
			{
				flags = flags | ast::var::Flag::ePerTaskNV;
			}
			else if ( stage == ast::ShaderStage::eTask )
			{
				flags = flags | ast::var::Flag::ePerTask;
			}
		}

		paramVar = shader->registerName( "sdw" + suffix + type
			, paramStruct
			, flags );

		if ( HlslHelpersInternal::needsSeparate( mode ) )
		{
			separateStruct = shader->getTypesCache().getStruct( ast::type::MemoryLayout::eC
				, "HLSL_SDWParam_" + suffix );
			separateVar = shader->registerName( "sdwParam" + suffix
				, separateStruct
				, ast::var::Flag::eNone );
			mainVar = separateVar;
		}
		else
		{
			mainVar = paramVar;
		}
	}

	void IOMapping::writeGlobals( ast::stmt::Container & stmt
		, ast::UnorderedStringSet & declaredStructs )const
	{
		switch ( mode )
		{
		case hlsl::IOMappingMode::eNoSeparate:
			if ( !paramStruct->empty() )
			{
				HlslHelpersInternal::declareStruct( stmt, paramStruct, declaredStructs );
			}
			break;
		case hlsl::IOMappingMode::eNoSeparateDistinctParams:
			if ( !unsupportedBuiltins.empty() )
			{
				for ( auto & builtin : unsupportedBuiltins )
				{
					stmt.addStmt( stmt.getStmtCache().makeVariableDecl( ast::var::makeVariable( builtin->getEntityName()
						, builtin->getType()
						, builtin->getFlags() | ast::var::Flag::eStatic ) ) );
				}
			}
			break;
		case hlsl::IOMappingMode::eLocalReturn:
			if ( !paramStruct->empty() )
			{
				HlslHelpersInternal::declareStruct( stmt, paramStruct, declaredStructs );
			}
			break;
		case hlsl::IOMappingMode::eLocalSeparateVar:
			if ( !paramStruct->empty() )
			{
				HlslHelpersInternal::declareStruct( stmt, paramStruct, declaredStructs );
			}
			if ( hasSeparate() )
			{
				HlslHelpersInternal::declareStruct( stmt, separateStruct, declaredStructs );
			}
			break;
		}
	}

	void IOMapping::writeLocalesBegin( ast::stmt::Container & stmt )const
	{
		switch ( mode )
		{
		case hlsl::IOMappingMode::eNoSeparate:
		case hlsl::IOMappingMode::eNoSeparateDistinctParams:
			break;
		case hlsl::IOMappingMode::eLocalReturn:
			if ( !paramStruct->empty() )
			{
				stmt.addStmt( stmt.getStmtCache().makeVariableDecl( paramVar ) );
			}
			break;
		case hlsl::IOMappingMode::eLocalSeparateVar:
			if ( separateVar && !isInput )
			{
				assert( mainVar == separateVar );
				stmt.addStmt( stmt.getStmtCache().makeVariableDecl( separateVar ) );
			}
			break;
		}
	}

	void IOMapping::writeLocalesEnd( ast::stmt::Container & stmt )const
	{
		auto & typesCache = shader->getTypesCache();

		switch ( mode )
		{
		case hlsl::IOMappingMode::eNoSeparate:
		case hlsl::IOMappingMode::eNoSeparateDistinctParams:
			break;
		case hlsl::IOMappingMode::eLocalReturn:
			if ( !paramStruct->empty() )
			{
				stmt.addStmt( stmt.getStmtCache().makeReturn( exprCache.makeIdentifier( typesCache
					, paramVar ) ) );
			}
			break;
		case hlsl::IOMappingMode::eLocalSeparateVar:
			break;
		}
	}

	ast::type::TypePtr IOMapping::fillParameters( ast::var::VariableList & parameters
		, ast::stmt::Container & stmt )const
	{
		ast::type::TypePtr result = nullptr;

		switch ( mode )
		{
		case hlsl::IOMappingMode::eNoSeparate:
		case hlsl::IOMappingMode::eLocalSeparateVar:
			if ( paramVar && !paramStruct->empty() )
			{
				parameters.push_back( paramVar );
			}
			break;
		case hlsl::IOMappingMode::eLocalReturn:
			if ( paramVar && !paramStruct->empty() )
			{
				result = paramVar->getType();
			}
			break;
		case hlsl::IOMappingMode::eNoSeparateDistinctParams:
			parameters.insert( parameters.end()
				, distinctParams.begin()
				, distinctParams.end() );
			break;
		}

		if ( paramVar->getType()->getKind() == ast::type::Kind::eComputeInput )
		{
			auto & compType = static_cast< ast::type::ComputeInput const & >( *paramVar->getType() );
			stmt.addStmt( stmt.getStmtCache().makeInputComputeLayout( compType.getType()
				, compType.getLocalSizeX()
				, compType.getLocalSizeY()
				, compType.getLocalSizeZ() ) );
		}

		return result;
	}

	void IOMapping::initialiseMainVar( ast::var::VariablePtr srcVar
		, ast::type::TypePtr type
		, VarVarMap & paramToEntryPoint )const
	{
		paramVar->updateType( type );
		paramToEntryPoint.try_emplace( srcVar, mainVar );
	}

	void IOMapping::initialisePatchVar( ast::var::VariablePtr srcVar
		, ast::type::TypePtr type
		, uint64_t flags
		, VarVarMap & paramToEntryPoint )
	{
		initialiseMainVar( srcVar, type, paramToEntryPoint );

		if ( isStructType( srcVar->getType() ) )
		{
			auto structType = getStructType( srcVar->getType() );
			uint32_t mbrIndex = 0u;

			for ( auto & mbr : *structType )
			{
				std::vector< PendingMbrIO >::iterator it;
				addPendingMbr( srcVar
					, mbrIndex
					, flags
					, mbr.location );
				processPendingMbrOuter( srcVar
					, mbrIndex
					, it );
				++mbrIndex;
			}
		}
	}

	void IOMapping::addPending( ast::var::VariablePtr pendingVar
		, uint32_t location )
	{
		auto [it, res] = m_pending.try_emplace( pendingVar->getName() );

		if ( res )
		{
			it->second.location = location;
			it->second.var = pendingVar;
		}
	}

	void IOMapping::addPendingMbr( ast::var::VariablePtr outerVar
		, uint32_t mbrIndex
		, uint64_t flags
		, uint32_t location )
	{
		auto it = std::find_if( m_pendingMbr.begin()
			, m_pendingMbr.end()
			, [&outerVar, &mbrIndex]( PendingMbrIO const & lookup )
			{
				return lookup.index == mbrIndex
					&& lookup.outer == outerVar;
			} );

		if ( it == m_pendingMbr.end() )
		{
			PendingIO io{};
			io.location = location;
			io.flags = flags;
			m_pendingMbr.emplace_back( outerVar, mbrIndex, std::move( io ) );
		}
	}

	void IOMapping::addPendingMbr( ast::expr::Expr const & outer
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

	ast::expr::ExprPtr IOMapping::processPendingMbr( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, ExprAdapter & adapter )
	{
		if ( !flags.isShaderInput() && !flags.isShaderOutput() )
		{
			return nullptr;
		}

		auto ident = ast::findIdentifier( outer );

		if ( !ident )
		{
			return nullptr;
		}

		std::vector< PendingMbrIO >::iterator it;
		auto result = processPendingMbrOuter( ident->getVariable()
			, mbrIndex
			, it );

		if ( it == m_pendingMbr.end() )
		{
			return result;
		}

		auto const & mbr = *it;

		if ( outer.getKind() != ast::expr::Kind::eArrayAccess )
		{
			return exprCache.makeMbrSelect( std::move( result )
				, mbr.io.result.mbrIndex
				, mbr.io.result.flags );
		}

		auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( outer );
		auto type = getNonArrayType( result->getType() );
		return exprCache.makeMbrSelect( exprCache.makeArrayAccess( type
				, std::move( result )
				, adapter.doSubmit( arrayAccess.getRHS() ) )
			, mbr.io.result.mbrIndex
			, mbr.io.result.flags );
	}

	ast::expr::ExprPtr IOMapping::processPending( std::string const & name )
	{
		auto it = m_pending.find( name );

		if ( m_pending.end() == it )
		{
			return nullptr;
		}

		auto & [_, mbr] = *it;
		auto const & pendingVar = *mbr.var;
		auto type = pendingVar.getType();
		auto location = it->second.location;

		if ( mbr.result.mbrIndex == ast::type::Struct::NotFound )
		{
			mbr.result = processPendingType( type
				, pendingVar.getName()
				, pendingVar.isBuiltin() ? pendingVar.getBuiltin() : ast::Builtin::eNone
				, mbr.flags
				, location );
		}

		if ( mbr.result.expr )
		{
			return ast::ExprCloner::submit( exprCache, *mbr.result.expr );
		}

		auto & typesCache = shader->getTypesCache();
		auto outerIdent = exprCache.makeIdentifier( typesCache, mainVar );
		return exprCache.makeMbrSelect( std::move( outerIdent )
			, mbr.result.mbrIndex
			, mbr.result.flags );
	}

	ast::expr::ExprPtr IOMapping::processPending( ast::var::VariablePtr srcVar )
	{
		if ( auto result = processPending( srcVar->getName() ) )
		{
			return result;
		}

		return exprCache.makeIdentifier( shader->getTypesCache()
				, srcVar );
	}

	bool IOMapping::isValid( ast::Builtin builtin )const
	{
		if ( isInput )
		{
			return HlslHelpersInternal::isShaderInput( builtin, stage );
		}

		return HlslHelpersInternal::isShaderOutput( builtin, stage );
	}

	bool IOMapping::hasSeparate()const
	{
		return separateVar
			&& !separateStruct->empty();
	}

	PendingResult IOMapping::processPendingType( ast::type::TypePtr type
		, std::string const & name
		, ast::Builtin builtin
		, uint64_t flags
		, uint32_t location
		, uint32_t arraySize
		, ast::type::IOStruct & structType )const
	{
		if ( builtin != ast::Builtin::eNone )
		{
			auto res = structType.findMember( builtin );

			if ( res != ast::type::Struct::NotFound )
			{
				return { res, flags };
			}
		}
		else
		{
			auto res = structType.findMember( name );

			if ( res != ast::type::Struct::NotFound )
			{
				return { res, flags };
			}
		}

		auto resultIndex = uint32_t( structType.size() );
		auto resultFlags = flags;

		if ( builtin == ast::Builtin::eClipDistance )
		{
			auto nonArray = shader->getTypesCache().getVec4F();

			for ( uint32_t i = 0u; i < 2u; ++i )
			{
				structType.declMember( builtin
					, nonArray->getKind()
					, ast::type::NotArray
					, i );
			}
		}
		else if ( builtin != ast::Builtin::eNone )
		{
			structType.declMember( builtin
				, getNonArrayType( type )->getKind()
				, getArraySize( type ) );
		}
		else
		{
			auto nonArray = getNonArrayType( type );

			if ( arraySize != ast::type::NotArray
				&& isInput
				&& ( stage == ast::ShaderStage::eGeometry
					|| stage == ast::ShaderStage::eTessellationControl
					|| stage == ast::ShaderStage::eTessellationEvaluation ) )
			{
				arraySize = ast::type::NotArray;
			}

			if ( nonArray->getKind() == ast::type::Kind::eStruct
				|| nonArray->getKind() == ast::type::Kind::eRayDesc )
			{
				structType.declMember( name
					, std::static_pointer_cast< ast::type::Struct >( nonArray )
					, arraySize );
			}
			else
			{
				structType.declMember( name
					, nonArray->getKind()
					, arraySize
					, location );
			}
		}

		if ( separateStruct )
		{
			// Separate variable needed.
			resultIndex = uint32_t( separateStruct->size() );
			resultFlags = 0u;
			separateStruct->declMember( name
				, getNonArrayType( type )->getKind()
				, getArraySize( type ) );
		}

		return { resultIndex, resultFlags };
	}

	PendingResult IOMapping::processPendingType( ast::type::TypePtr type
		, std::string const & name
		, ast::Builtin builtin
		, uint64_t flags
		, uint32_t location )
	{
		auto arraySize = getArraySize( type );
		type = getNonArrayType( type );

		if ( auto compType = getComponentType( type );
			( stage != ast::ShaderStage::eVertex || !isInput )
				&& !isMeshStage( stage )
				&& !isRayTraceStage( stage )
				&& ( isUnsignedIntType( compType ) || isSignedIntType( compType ) ) )
		{
			flags = flags | ast::var::Flag::eFlat;
		}

		if ( builtin != ast::Builtin::eNone )
		{
			type = shader->getTypesCache().getBasicType( getBuiltinHlslKind( builtin, type->getKind() ) );

			if ( arraySize != ast::type::NotArray )
			{
				type = shader->getTypesCache().getArray( type, arraySize );
			}
		}

		if ( mode == IOMappingMode::eNoSeparateDistinctParams )
		{
			auto it = std::find_if( distinctParams.begin()
				, distinctParams.end()
				, [&name, &builtin]( ast::var::VariablePtr const & lookup )
				{
					return ( ( builtin != ast::Builtin::eNone ) && lookup->getBuiltin() == builtin )
						|| ( ( builtin == ast::Builtin::eNone ) && lookup->getName() == name );
				} );

			if ( distinctParams.end() == it )
			{
				if ( builtin != ast::Builtin::eNone )
				{
					if ( HlslHelpersInternal::isSupported( builtin, stage, isInput ) )
					{
						distinctParams.push_back( shader->registerBuiltin( builtin, type, flags ) );
						it = std::next( distinctParams.begin(), ptrdiff_t( distinctParams.size() ) - 1 );
					}
					else
					{
						unsupportedBuiltins.push_back( shader->registerBuiltin( builtin, type, flags ) );
						it = std::next( unsupportedBuiltins.begin(), ptrdiff_t( unsupportedBuiltins.size() ) - 1 );
					}
				}
				else
				{
					distinctParams.push_back( shader->registerName( name, type, flags ) );
					it = std::next( distinctParams.begin(), ptrdiff_t( distinctParams.size() ) - 1 );
				}

			}

			return { 0u, 0u, exprCache.makeIdentifier( shader->getTypesCache(), *it ) };
		}

		if ( separateStruct )
		{
			auto res = separateStruct->findMember( name );

			if ( res != ast::type::Struct::NotFound )
			{
				return { res, 0u };
			}
		}

		return processPendingType( type
			, name
			, builtin
			, flags
			, location
			, arraySize
			, *paramStruct );
	}

	PendingResult IOMapping::processPendingType( ast::type::Struct const & structType
		, uint32_t mbrIndex
		, uint64_t mbrFlags
		, uint32_t mbrLocation )
	{
		auto & mbr = *std::next( structType.begin(), ptrdiff_t( mbrIndex ) );
		return processPendingType( mbr.type
			, mbr.name
			, mbr.builtin
			, mbrFlags
			, mbrLocation );
	}

	ast::expr::ExprPtr IOMapping::processPendingMbrOuter( ast::var::VariablePtr outerVar
		, uint32_t mbrIndex
		, std::vector< PendingMbrIO >::iterator & it )
	{
		it = m_pendingMbr.end();
		auto & typesCache = shader->getTypesCache();

		it = std::find_if( m_pendingMbr.begin()
			, m_pendingMbr.end()
			, [&outerVar, &mbrIndex]( PendingMbrIO const & lookup )
			{
				return lookup.index == mbrIndex
					&& lookup.outer == outerVar;
			} );

		if ( m_pendingMbr.end() == it )
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

		if ( !mbr.io.result.expr )
		{
			mbr.io.result.expr = exprCache.makeIdentifier( typesCache, mainVar );
		}

		if ( !isStructType( mbr.io.result.expr->getType() ) )
		{
			it = m_pendingMbr.end();
		}

		return ast::ExprCloner::submit( exprCache, *mbr.io.result.expr );
	}

	//*********************************************************************************************

	Routine::Routine( ast::expr::ExprCache & pexprCache
		, HlslShader & pshader
		, AdaptationData * pparent
		, bool pisMain )
		: exprCache{ pexprCache }
		, shader{ &pshader }
		, parent{ pparent }
		, isMain{ pisMain }
		, m_highFreqOutputs{ exprCache 
			, *shader
			, HlslHelpersInternal::getMode( shader->getType(), false, true, false )
			, false
			, false
			, HlslHelpersInternal::getFuncName( isMain ) }
		, m_lowFreqInputs{ exprCache 
			, *shader
			, HlslHelpersInternal::getMode( shader->getType(), true, false, false )
			, true
			, false
			, HlslHelpersInternal::getFuncName( isMain ) }
		, m_lowFreqOutputs{ exprCache 
			, *shader
			, HlslHelpersInternal::getMode( shader->getType(), false, false, false )
			, false
			, isMeshStage( shader->getType() )
			, HlslHelpersInternal::getFuncName( isMain ) }
	{
	}

	void Routine::initialiseHFOutput( ast::var::VariablePtr srcVar
		, ast::type::GeometryOutput const & geomType )
	{
		m_highFreqOutputs.initialiseMainVar( srcVar
			, ast::type::makeGeometryOutputType( m_highFreqOutputs.paramStruct
				, geomType.getLayout()
				, geomType.getCount() )
			, paramToEntryPoint );
	}

	void Routine::initialiseHFOutput( ast::var::VariablePtr srcVar
		, ast::type::TessellationControlOutput const & tessType )
	{
		m_highFreqOutputs.initialiseMainVar( srcVar
			, ast::type::makeTessellationControlOutputType( m_highFreqOutputs.paramStruct
				, tessType.getDomain()
				, tessType.getPartitioning()
				, tessType.getTopology()
				, tessType.getOrder()
				, tessType.getOutputVertices() )
			, paramToEntryPoint );
	}

	void Routine::initialiseHFOutput( ast::var::VariablePtr srcVar
		, ast::type::MeshVertexOutput const & meshType )
	{
		m_highFreqOutputs.initialiseMainVar( srcVar
			, ast::type::makeMeshVertexOutputType( m_highFreqOutputs.paramStruct
				, meshType.getMaxVertices() )
			, paramToEntryPoint );
	}

	void Routine::initialiseHFOutput( ast::var::VariablePtr srcVar
		, ast::type::TessellationOutputPatch const & patchType )
	{
		m_highFreqOutputs.initialiseMainVar( srcVar
			, ast::type::makeTessellationOutputPatchType( m_highFreqOutputs.paramStruct
				, patchType.getLocation() )
			, paramToEntryPoint );
	}

	void Routine::initialiseHFOutput( ast::var::VariablePtr srcVar
		, ast::type::TaskPayload const & )
	{
		m_highFreqOutputs.initialiseMainVar( srcVar
			, ast::type::makeTaskPayloadType( m_highFreqOutputs.paramStruct )
			, paramToEntryPoint );
	}

	void Routine::initialiseLFOutput( ast::var::VariablePtr srcVar
		, ast::type::MeshPrimitiveOutput const & meshType )
	{
		m_lowFreqOutputs.initialiseMainVar( srcVar
			, ast::type::makeMeshPrimitiveOutputType( m_lowFreqOutputs.paramStruct
				, meshType.getTopology()
				, meshType.getMaxPrimitives() )
			, paramToEntryPoint );
	}

	void Routine::writeGlobals( ast::stmt::Container & cont
		, ast::UnorderedStringSet & declaredStructs )
	{
		m_highFreqOutputs.writeGlobals( cont, declaredStructs );
		m_lowFreqInputs.writeGlobals( cont, declaredStructs );
		m_lowFreqOutputs.writeGlobals( cont, declaredStructs );
		globalDeclarations = &cont;
	}

	void Routine::writeLocalesBegin( ast::stmt::Container & cont )const
	{
		m_highFreqOutputs.writeLocalesBegin( cont );
		m_lowFreqInputs.writeLocalesBegin( cont );
		m_lowFreqOutputs.writeLocalesBegin( cont );
	}

	void Routine::writeLocalesEnd( ast::stmt::Container & cont )const
	{
		m_highFreqOutputs.writeLocalesEnd( cont );
		m_lowFreqInputs.writeLocalesEnd( cont );
		m_lowFreqOutputs.writeLocalesEnd( cont );
	}

	ast::type::TypePtr Routine::fillParameters( ast::var::VariableList & parameters
		, ast::stmt::Container & stmt )const
	{
		auto result = HlslHelpersInternal::getNonNull( m_highFreqOutputs.fillParameters( parameters, stmt ), nullptr );
		result = HlslHelpersInternal::getNonNull( m_lowFreqInputs.fillParameters( parameters, stmt ), result );
		result = HlslHelpersInternal::getNonNull( m_lowFreqOutputs.fillParameters( parameters, stmt ), result );

		if ( m_primitiveIndices.io.var )
		{
			parameters.push_back( m_primitiveIndices.io.var );
		}

		return result;
	}

	ast::expr::ExprPtr Routine::processPendingMbr( ast::expr::Expr const & outer
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

		if ( flags.isShaderOutput() )
		{
			return processPendingMbrOutput( outer
				, mbrIndex
				, flags
				, adapter );
		}

		return nullptr;
	}

	ast::expr::ExprPtr Routine::processPending( ast::var::VariablePtr var )
	{
		if ( auto it = paramToEntryPoint.find( var );
			it != paramToEntryPoint.end() )
		{
			return exprCache.makeIdentifier( shader->getTypesCache()
				, it->second );
		}

		if ( var->isShaderInput() )
		{
			return processPendingInput( var );
		}

		if ( var->isShaderOutput() )
		{
			return processPendingOutput( var );
		}

		return nullptr;
	}

	void Routine::addMbrBuiltin( ast::expr::Expr const & outer
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

	IOMapping & Routine::getLFInputs()
	{
		return m_lowFreqInputs;
	}

	void Routine::addInputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		m_lowFreqInputs.addPending( var, location );
	}

	bool Routine::hasSeparateLFInput()const
	{
		return m_lowFreqInputs.hasSeparate();
	}

	void Routine::addPendingInput( ast::var::VariablePtr var
		, uint32_t location )
	{
		m_lowFreqInputs.addPending( var, location );
	}

	void Routine::addPendingMbrInput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location )
	{
		m_lowFreqInputs.addPendingMbr( outer
			, mbrIndex
			, flags
			, location );
	}

	ast::expr::ExprPtr Routine::processPendingInput( std::string const & name )
	{
		return m_lowFreqInputs.processPending( name );
	}

	ast::expr::ExprPtr Routine::processPendingInput( ast::var::VariablePtr var )
	{
		return m_lowFreqInputs.processPending( var );
	}

	ast::expr::ExprPtr Routine::processPendingMbrInput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, ExprAdapter & adapter )
	{
		return m_lowFreqInputs.processPendingMbr( outer
			, mbrIndex
			, flags
			, adapter );
	}

	IOMapping & Routine::getHFOutputs()
	{
		return m_highFreqOutputs;
	}

	IOMapping & Routine::getLFOutputs()
	{
		return m_lowFreqOutputs;
	}

	bool Routine::isOutput( ast::Builtin builtin )const
	{
		return m_highFreqOutputs.isValid( builtin );
	}

	bool Routine::hasSeparateHFOutput()const
	{
		return m_highFreqOutputs.hasSeparate();
	}

	void Routine::addOutputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		if ( !var->isBuiltin()
			|| HlslHelpersInternal::isHighFreq( var->getBuiltin(), false ) )
		{
			m_highFreqOutputs.addPending( var, location );
		}
		else
		{
			m_lowFreqOutputs.addPending( var, location );
		}
	}

	bool Routine::hasSeparateLFOutput()const
	{
		return m_lowFreqOutputs.hasSeparate();
	}

	void Routine::addPendingOutput( ast::var::VariablePtr var
		, uint32_t location )
	{
		if ( !var->isBuiltin()
			|| HlslHelpersInternal::isHighFreq( var->getBuiltin(), false ) )
		{
			m_highFreqOutputs.addPending( var, location );
		}
		else
		{
			m_lowFreqOutputs.addPending( var, location );
		}
	}

	void Routine::addPendingMbrOutput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location )
	{
		auto mbr = getStructType( outer.getType() )->getMember( mbrIndex );

		if ( !flags.isBuiltin()
			|| HlslHelpersInternal::isHighFreq( mbr.builtin, false ) )
		{
			m_highFreqOutputs.addPendingMbr( outer
				, mbrIndex
				, flags
				, location );
		}
		else if ( mbr.builtin == ast::Builtin::ePrimitiveIndicesNV
			|| mbr.builtin == ast::Builtin::ePrimitivePointIndices
			|| mbr.builtin == ast::Builtin::ePrimitiveLineIndices
			|| mbr.builtin == ast::Builtin::ePrimitiveTriangleIndices )
		{
			//m_primitiveIndices.addPendingMbr( outer
			//	, mbrIndex
			//	, flags
			//	, location );
		}
		else
		{
			m_lowFreqOutputs.addPendingMbr( outer
				, mbrIndex
				, flags
				, location );
		}
	}

	ast::expr::ExprPtr Routine::processPendingOutput( std::string const & name )
	{
		auto result = m_highFreqOutputs.processPending( name );

		if ( !result )
		{
			result = m_lowFreqOutputs.processPending( name );
		}

		return result;
	}

	ast::expr::ExprPtr Routine::processPendingOutput( ast::var::VariablePtr var )
	{
		auto result = m_highFreqOutputs.processPending( var );

		if ( !result )
		{
			result = m_lowFreqOutputs.processPending( var );
		}

		return result;
	}

	ast::expr::ExprPtr Routine::processPendingMbrOutput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, ExprAdapter & adapter )
	{
		auto result = m_highFreqOutputs.processPendingMbr( outer
			, mbrIndex
			, flags
			, adapter );

		if ( !result )
		{
			auto mbr = getStructType( outer.getType() )->getMember( mbrIndex );

			if ( mbr.builtin == ast::Builtin::ePrimitiveIndicesNV
				|| mbr.builtin == ast::Builtin::ePrimitivePointIndices
				|| mbr.builtin == ast::Builtin::ePrimitiveLineIndices
				|| mbr.builtin == ast::Builtin::ePrimitiveTriangleIndices )
			{
				assert( outer.getKind() == ast::expr::Kind::eArrayAccess );
				auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( outer );
				auto type = getNonArrayType( m_primitiveIndices.io.var->getType() );
				result = exprCache.makeArrayAccess( type
					, exprCache.makeIdentifier( shader->getTypesCache(), m_primitiveIndices.io.var )
					, adapter.doSubmit( arrayAccess.getRHS() ) );
			}
			else
			{
				result = m_lowFreqOutputs.processPendingMbr( outer
					, mbrIndex
					, flags
					, adapter );
			}
		}

		return result;
	}

	void Routine::registerInputMbr( ast::var::VariablePtr var
		, uint64_t outerFlags
		, ast::Builtin mbrBuiltin
		, uint32_t mbrIndex
		, uint32_t mbrLocation )
	{
		auto mbrFlags = ( outerFlags
			| ( ( mbrBuiltin == ast::Builtin::eNone )
				? ast::var::Flag::eNone
				: ast::var::Flag::eBuiltin ) );
		mbrLocation = ( ( mbrBuiltin == ast::Builtin::eNone )
			? mbrLocation
			: ast::type::Struct::InvalidLocation );
		m_lowFreqInputs.addPendingMbr( var
			, mbrIndex
			, mbrFlags
			, mbrLocation );
	}

	void Routine::registerOutputMbr( ast::var::VariablePtr var
		, uint64_t outerFlags
		, ast::Builtin mbrBuiltin
		, uint32_t mbrIndex
		, uint32_t mbrLocation )
	{
		auto mbrFlags = ( outerFlags
			| ( ( mbrBuiltin == ast::Builtin::eNone )
				? ast::var::Flag::eNone
				: ast::var::Flag::eBuiltin ) );
		mbrLocation = ( ( mbrBuiltin == ast::Builtin::eNone )
			? mbrLocation
			: ast::type::Struct::InvalidLocation );

		if (HlslHelpersInternal::isHighFreq( mbrBuiltin, false ) )
		{
			m_highFreqOutputs.addPendingMbr( var
				, mbrIndex
				, mbrFlags
				, mbrLocation );
		}
		else if ( mbrBuiltin == ast::Builtin::ePrimitiveIndicesNV
			|| mbrBuiltin == ast::Builtin::ePrimitivePointIndices
			|| mbrBuiltin == ast::Builtin::ePrimitiveLineIndices
			|| mbrBuiltin == ast::Builtin::ePrimitiveTriangleIndices )
		{
			auto type = var->getType();
			assert( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput );
			auto & meshType = static_cast< ast::type::MeshPrimitiveOutput const & >( *type );
			auto mbr = getStructType( type )->getMember( mbrIndex );
			PendingIO io{};
			io.location = mbrLocation;
			io.flags = mbrFlags;
			io.var = shader->registerBuiltin( mbrBuiltin
				, shader->getTypesCache().getArray( mbr.type, meshType.getMaxPrimitives() )
				, mbrFlags );
			m_primitiveIndices = IOMapping::PendingMbrIO{ var, mbrIndex, std::move( io ) };
		}
		else
		{
			m_lowFreqOutputs.addPendingMbr( var
				, mbrIndex
				, mbrFlags
				, mbrLocation );
		}
	}

	//*********************************************************************************************

	AdaptationData::AdaptationData( ast::expr::ExprCache & pexprCache
		, HlslShader & pshader )
		: exprCache{ pexprCache }
		, m_highFreqInputs{ exprCache, pshader, HlslHelpersInternal::getMode( pshader.getType(), true, true, false ), true, false, "Global" }
		, m_patchInputs{ ( pshader.getType() == ast::ShaderStage::eTessellationEvaluation
			? std::make_unique< IOMapping >( exprCache, pshader, HlslHelpersInternal::getMode( pshader.getType(), true, true, false ), true, true, "Global" )
			: nullptr ) }
		, shader{ &pshader }
	{
		m_routines.try_emplace( "main"
			, std::make_unique< Routine >( exprCache, pshader, this, true ) );
		m_mainEntryPoint = m_routines["main"].get();
	}

	void AdaptationData::addEntryPoint( ast::stmt::FunctionDecl const & stmt )
	{
		m_routines.try_emplace( stmt.getName()
			, std::make_unique< Routine >( exprCache
				, *shader
				, this
				, stmt.isEntryPoint() ) );
	}

	void AdaptationData::updateCurrentEntryPoint( ast::stmt::FunctionDecl const * stmt )
	{
		if ( stmt )
		{
			if ( !stmt->isEntryPoint() )
			{
				m_currentRoutine = m_routines[stmt->getName()].get();
			}
			else
			{
				m_currentRoutine = m_mainEntryPoint;
			}
		}
		else
		{
			m_currentRoutine = nullptr;
		}
	}

	void AdaptationData::initialiseEntryPoint( ast::stmt::FunctionDecl const & stmt )
	{
		assert( m_currentRoutine );
		auto funcType = stmt.getType();

		for ( auto & param : *funcType )
		{
			auto type = param->getType();

			switch ( type->getKind() )
			{
			case ast::type::Kind::eFragmentInput:
				registerParam( param, static_cast< ast::type::FragmentInput const & >( *type ) );
				break;
			case ast::type::Kind::eGeometryOutput:
				registerParam( param, static_cast< ast::type::GeometryOutput const & >( *type ) );
				break;
			case ast::type::Kind::eGeometryInput:
				registerParam( param, static_cast< ast::type::GeometryInput const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationInputPatch:
				registerParam( param, static_cast< ast::type::TessellationInputPatch const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationControlInput:
				registerParam( param, static_cast< ast::type::TessellationControlInput const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationEvaluationInput:
				registerParam( param, static_cast< ast::type::TessellationEvaluationInput const & >( *type ) );
				break;
			case ast::type::Kind::eComputeInput:
				registerParam( param, static_cast< ast::type::ComputeInput const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationOutputPatch:
				registerParam( param, static_cast< ast::type::TessellationOutputPatch const & >( *type ) );
				break;
			case ast::type::Kind::eTessellationControlOutput:
				registerParam( param, static_cast< ast::type::TessellationControlOutput const & >( *type ) );
				break;
			case ast::type::Kind::eMeshVertexOutput:
				registerParam( param, static_cast< ast::type::MeshVertexOutput const & >( *type ) );
				break;
			case ast::type::Kind::eMeshPrimitiveOutput:
				registerParam( param, static_cast< ast::type::MeshPrimitiveOutput const & >( *type ) );
				break;
			case ast::type::Kind::eTaskPayloadNV:
			case ast::type::Kind::eTaskPayload:
				break;
			case ast::type::Kind::eTaskPayloadInNV:
				registerParam( param, static_cast< ast::type::TaskPayloadInNV const & >( *type ) );
				break;
			case ast::type::Kind::eTaskPayloadIn:
				registerParam( param, static_cast< ast::type::TaskPayloadIn const & >( *type ) );
				break;
			default:
				{
					if ( type->getKind() == ast::type::Kind::eArray )
					{
						auto & arrayType = static_cast< ast::type::Array const & >( *type );
						type = arrayType.getType();
					}

					if ( isStructType( type ) )
					{
						auto structType = getStructType( type );

						if ( structType->isShaderInput() )
						{
							registerInput( param, static_cast< ast::type::IOStruct const & >( *structType ) );
						}
						else if ( structType->isShaderOutput() )
						{
							registerOutput( param, static_cast< ast::type::IOStruct const & >( *structType ) );
						}
						else
						{
							uint32_t index = 0u;

							for ( auto & mbr : *structType )
							{
								if ( mbr.builtin != ast::Builtin::eNone )
								{
									if ( HlslHelpersInternal::isShaderInput( mbr.builtin, shader->getType() ) )
									{
										registerInputMbr( param
											, uint64_t( ast::var::Flag::eShaderInput )
											, mbr.builtin
											, index
											, mbr.location );
									}
									else
									{
										registerInputMbr( param
											, uint64_t( ast::var::Flag::eShaderOutput )
											, mbr.builtin
											, index
											, mbr.location );
									}

									++index;
								}
							}
						}
					}
				}
				break;
			}
		}
	}

	ast::stmt::ContainerPtr AdaptationData::writeGlobals( ast::stmt::StmtCache & stmtCache
		, ast::UnorderedStringSet & declaredStructs )
	{
		auto cont = stmtCache.makeContainer();
		assert( m_currentRoutine );

		if ( m_currentRoutine == m_mainEntryPoint )
		{
			m_highFreqInputs.writeGlobals( *cont
				, declaredStructs );
		}

		if ( m_patchInputs )
		{
			m_patchInputs->writeGlobals( *cont
				, declaredStructs );
		}

		m_currentRoutine->writeGlobals( *cont
			, declaredStructs );
		return cont;
	}

	ast::stmt::ContainerPtr AdaptationData::writeLocalesBegin( ast::stmt::StmtCache & stmtCache )const
	{
		auto cont = stmtCache.makeContainer();
		assert( m_currentRoutine );

		if ( m_currentRoutine == m_mainEntryPoint )
		{
			m_highFreqInputs.writeLocalesBegin( *cont );
		}

		if ( m_patchInputs )
		{
			m_patchInputs->writeLocalesBegin( *cont );
		}

		m_currentRoutine->writeLocalesBegin( *cont );
		return cont;
	}

	ast::stmt::ContainerPtr AdaptationData::writeLocalesEnd( ast::stmt::StmtCache & stmtCache )const
	{
		auto cont = stmtCache.makeContainer();
		assert( m_currentRoutine );

		if ( m_currentRoutine == m_mainEntryPoint )
		{
			m_highFreqInputs.writeLocalesEnd( *cont );
		}

		if ( m_patchInputs )
		{
			m_patchInputs->writeLocalesEnd( *cont );
		}

		m_currentRoutine->writeLocalesEnd( *cont );
		return cont;
	}

	ast::type::TypePtr AdaptationData::fillParameters( ast::var::VariableList & parameters
		, ast::stmt::Container & stmt )const
	{
		auto result = HlslHelpersInternal::getNonNull( m_highFreqInputs.fillParameters( parameters, stmt ), nullptr );

		if ( m_patchInputs )
		{
			result = HlslHelpersInternal::getNonNull( m_patchInputs->fillParameters( parameters, stmt ), nullptr );
		}

		assert( m_currentRoutine );
		result = HlslHelpersInternal::getNonNull( m_currentRoutine->fillParameters( parameters, stmt ), result );
		return result;
	}

	ast::expr::ExprPtr AdaptationData::processPendingMbr( ast::expr::Expr const & outer
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

		if ( flags.isShaderOutput() )
		{
			return processPendingMbrOutput( outer
				, mbrIndex
				, flags
				, adapter );
		}

		return nullptr;
	}

	ast::expr::ExprPtr AdaptationData::processPending( ast::var::VariablePtr var )
	{
		if ( !m_currentRoutine )
		{
			return nullptr;
		}

		if ( auto it = m_currentRoutine->paramToEntryPoint.find( var );
			it != m_currentRoutine->paramToEntryPoint.end() )
		{
			return exprCache.makeIdentifier( shader->getTypesCache()
				, it->second );
		}

		if ( var->isShaderInput() )
		{
			return processPendingInput( var );
		}

		if ( var->isShaderOutput() )
		{
			return processPendingOutput( var );
		}

		return nullptr;
	}

	void AdaptationData::addMbrBuiltin( ast::expr::Expr const & outer
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

	IOMapping & AdaptationData::getHFInputs()
	{
		return m_highFreqInputs;
	}

	IOMapping & AdaptationData::getLFInputs()
	{
		assert( m_currentRoutine );
		return m_currentRoutine->getLFInputs();
	}

	void AdaptationData::addInputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		if ( !var->isBuiltin()
			|| HlslHelpersInternal::isHighFreq( var->getBuiltin(), true ) )
		{
			if ( m_patchInputs && var->isPatchInput() )
			{
				m_patchInputs->addPending( var, location );
			}
			else
			{
				m_highFreqInputs.addPending( var, location );
			}
		}
		else
		{
			auto & entryPoint = m_currentRoutine
				? *m_currentRoutine
				: *m_mainEntryPoint;
			entryPoint.addInputVar( var, location );
		}
	}

	bool AdaptationData::isInput( ast::Builtin builtin )const
	{
		return m_highFreqInputs.isValid( builtin );
	}

	bool AdaptationData::hasSeparateHFInput()const
	{
		return m_highFreqInputs.hasSeparate();
	}

	bool AdaptationData::hasSeparateLFInput()const
	{
		assert( m_currentRoutine );
		return m_currentRoutine->hasSeparateLFInput();
	}

	void AdaptationData::addPendingInput( ast::var::VariablePtr var
		, uint32_t location )
	{
		auto & entryPoint = m_currentRoutine
			? *m_currentRoutine
			: *m_mainEntryPoint;

		if ( !var->isBuiltin()
			|| HlslHelpersInternal::isHighFreq( var->getBuiltin(), true ) )
		{
			if ( m_patchInputs && var->isPatchInput() )
			{
				m_patchInputs->addPending( var, location );
			}
			else
			{
				m_highFreqInputs.addPending( var, location );
			}
		}
		else
		{
			entryPoint.addPendingInput( var, location );
		}
	}

	void AdaptationData::addPendingMbrInput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location )
	{
		assert( m_currentRoutine );
		auto mbr = getStructType( outer.getType() )->getMember( mbrIndex );

		if ( HlslHelpersInternal::isHighFreq( mbr.builtin, true ) )
		{
			if ( m_patchInputs && flags.isPatchInput() )
			{
				m_patchInputs->addPendingMbr( outer
					, mbrIndex
					, flags
					, location );
			}
			else
			{
				m_highFreqInputs.addPendingMbr( outer
					, mbrIndex
					, flags
					, location );
			}
		}
		else
		{
			m_currentRoutine->addPendingMbrInput( outer
				, mbrIndex
				, flags
				, location );
		}
	}

	ast::expr::ExprPtr AdaptationData::processPendingInput( std::string const & name )
	{
		assert( m_currentRoutine );
		auto result = m_highFreqInputs.processPending( name );

		if ( m_patchInputs && !result )
		{
			result = m_patchInputs->processPending( name );
		}

		if ( !result )
		{
			result = m_currentRoutine->processPendingInput( name );
		}

		return result;
	}

	ast::expr::ExprPtr AdaptationData::processPendingInput( ast::var::VariablePtr var )
	{
		assert( m_currentRoutine );
		auto result = m_highFreqInputs.processPending( var );

		if ( m_patchInputs && !result )
		{
			result = m_patchInputs->processPending( var );
		}

		if ( !result )
		{
			result = m_currentRoutine->processPendingInput( var );
		}

		return result;
	}

	ast::expr::ExprPtr AdaptationData::processPendingMbrInput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, ExprAdapter & adapter )
	{
		assert( m_currentRoutine );
		auto result = m_highFreqInputs.processPendingMbr( outer
			, mbrIndex
			, flags
			, adapter );

		if ( m_patchInputs && !result )
		{
			result = m_patchInputs->processPendingMbr( outer
				, mbrIndex
				, flags
				, adapter );
		}

		if ( !result )
		{
			result = m_currentRoutine->processPendingMbrInput( outer
				, mbrIndex
				, flags
				, adapter );
		}

		return result;
	}

	IOMapping & AdaptationData::getHFOutputs()
	{
		assert( m_currentRoutine );
		return m_currentRoutine->getHFOutputs();
	}

	IOMapping & AdaptationData::getLFOutputs()
	{
		assert( m_currentRoutine );
		return m_currentRoutine->getLFOutputs();
	}

	void AdaptationData::addOutputVar( ast::var::VariablePtr var
		, uint32_t location )
	{
		auto & entryPoint = m_currentRoutine
			? *m_currentRoutine
			: *m_mainEntryPoint;
		entryPoint.addOutputVar( var, location );
	}

	bool AdaptationData::isOutput( ast::Builtin builtin )const
	{
		assert( m_currentRoutine );
		return m_currentRoutine->isOutput( builtin );
	}

	bool AdaptationData::hasSeparateHFOutput()const
	{
		assert( m_currentRoutine );
		return m_currentRoutine->hasSeparateHFOutput();
	}

	bool AdaptationData::hasSeparateLFOutput()const
	{
		assert( m_currentRoutine );
		return m_currentRoutine->hasSeparateLFOutput();
	}

	void AdaptationData::addPendingOutput( ast::var::VariablePtr var
		, uint32_t location )
	{
		auto & entryPoint = m_currentRoutine
			? *m_currentRoutine
			: *m_mainEntryPoint;
		entryPoint.addPendingOutput( var, location );
	}

	void AdaptationData::addPendingMbrOutput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, uint32_t location )
	{
		assert( m_currentRoutine );
		m_currentRoutine->addPendingMbrOutput( outer
			, mbrIndex
			, flags
			, location );
	}

	ast::expr::ExprPtr AdaptationData::processPendingOutput( std::string const & name )
	{
		assert( m_currentRoutine );
		return m_currentRoutine->processPendingOutput( name );
	}

	ast::expr::ExprPtr AdaptationData::processPendingOutput( ast::var::VariablePtr var )
	{
		assert( m_currentRoutine );
		return m_currentRoutine->processPendingOutput( var );
	}

	ast::expr::ExprPtr AdaptationData::processPendingMbrOutput( ast::expr::Expr const & outer
		, uint32_t mbrIndex
		, ast::var::FlagHolder const & flags
		, ExprAdapter & adapter )
	{
		assert( m_currentRoutine );
		return m_currentRoutine->processPendingMbrOutput( outer
			, mbrIndex
			, flags
			, adapter );
	}

	void AdaptationData::declareStruct( ast::type::StructPtr const & structType
		, ast::stmt::Container * stmt )
	{
		if ( stmt
			&& m_declaredStructs.emplace( structType ).second )
		{
			stmt->addStmt( stmt->getStmtCache().makeStructureDecl( structType ) );
		}
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::FragmentInput const & fragType )
	{
		assert( m_currentRoutine );

		if ( auto type = fragType.getType();
			isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_highFreqInputs.initialiseMainVar( var
			, ast::type::makeFragmentInputType( m_highFreqInputs.paramStruct
				, fragType.getOrigin()
				, fragType.getCenter() )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::ComputeInput const & compType )
	{
		assert( m_currentRoutine );

		if ( auto type = compType.getType();
			isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_currentRoutine->m_lowFreqInputs.initialiseMainVar( var
			, ast::type::makeComputeInputType( m_currentRoutine->m_lowFreqInputs.paramStruct
				, compType.getLocalSizeX()
				, compType.getLocalSizeY()
				, compType.getLocalSizeZ() )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::GeometryInput const & geomType )
	{
		assert( m_currentRoutine );

		if ( auto type = geomType.getType();
			isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_highFreqInputs.initialiseMainVar( var
			, ast::type::makeGeometryInputType( m_highFreqInputs.paramStruct
				, geomType.getLayout() )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::GeometryOutput const & geomType )
	{
		assert( m_currentRoutine );

		if ( auto type = geomType.getType();
			isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_currentRoutine->initialiseHFOutput( var, geomType );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationInputPatch const & patchType )
	{
		assert( m_currentRoutine );
		assert( m_patchInputs );

		if ( auto type = patchType.getType();
			isStructType( type ) )
		{
			auto structType = getStructType( type );
			declareStruct( structType
				, m_currentRoutine->globalDeclarations );
		}

		m_patchInputs->initialisePatchVar( var
			, ast::type::makeTessellationInputPatchType( m_patchInputs->paramStruct
				, patchType.getDomain()
				, patchType.getLocation() )
			, uint64_t( ast::var::Flag::eShaderInput )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationOutputPatch const & patchType )
	{
		assert( m_currentRoutine );

		if ( auto type = patchType.getType();
			isStructType( type ) )
		{
			declareStruct( getStructType( type )
				, m_currentRoutine->globalDeclarations );
		}

		m_currentRoutine->initialiseHFOutput( var, patchType );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationControlInput const & tessType )
	{
		assert( m_currentRoutine );
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_highFreqInputs.initialiseMainVar( var
			, ast::type::makeTessellationControlInputType( m_highFreqInputs.paramStruct
				, tessType.getInputVertices() )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationControlOutput const & tessType )
	{
		assert( m_currentRoutine );
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_currentRoutine->initialiseHFOutput( var, tessType );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::TessellationEvaluationInput const & tessType )
	{
		assert( m_currentRoutine );
		auto type = tessType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_highFreqInputs.initialiseMainVar( var
			, ast::type::makeTessellationEvaluationInputType( m_highFreqInputs.paramStruct
				, tessType.getDomain()
				, tessType.getPartitioning()
				, tessType.getPrimitiveOrdering()
				, tessType.getInputVertices() )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::MeshVertexOutput const & meshType )
	{
		assert( m_currentRoutine );
		auto type = meshType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_currentRoutine->initialiseHFOutput( var, meshType );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::MeshPrimitiveOutput const & meshType )
	{
		assert( m_currentRoutine );
		auto type = meshType.getType();
		m_currentRoutine->setOutputTopology( meshType.getTopology() );

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderOutput() );
			registerOutput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_currentRoutine->initialiseLFOutput( var, meshType );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::TaskPayloadInNV const & taskType )
	{
		assert( m_currentRoutine );
		auto type = taskType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_highFreqInputs.initialiseMainVar( var
			, ast::type::makeTaskPayloadInNVType( m_highFreqInputs.paramStruct )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerParam( ast::var::VariablePtr var
		, ast::type::TaskPayloadIn const & taskType )
	{
		assert( m_currentRoutine );
		auto type = taskType.getType();

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			type = static_cast< ast::type::Array const & >( *type ).getType();
		}

		if ( isStructType( type ) )
		{
			auto const & structType = *getStructType( type );
			assert( structType.isShaderInput() );
			registerInput( var, static_cast< ast::type::IOStruct const & >( structType ) );
		}

		m_highFreqInputs.initialiseMainVar( var
			, ast::type::makeTaskPayloadInType( m_highFreqInputs.paramStruct )
			, m_currentRoutine->paramToEntryPoint );
	}

	void AdaptationData::registerInput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType )
	{
		uint32_t mbrIndex = 0u;

		for ( auto & mbr : structType )
		{
			registerInputMbr( var
				, structType.getFlag()
				, mbr.builtin
				, mbrIndex
				, mbr.location );
			++mbrIndex;
		}
	}

	void AdaptationData::registerOutput( ast::var::VariablePtr var
		, ast::type::IOStruct const & structType )
	{
		uint32_t mbrIndex = 0u;

		for ( auto & mbr : structType )
		{
			registerOutputMbr( var
				, structType.getFlag()
				, mbr.builtin
				, mbrIndex
				, mbr.location );
			++mbrIndex;
		}
	}

	void AdaptationData::registerInputMbr( ast::var::VariablePtr var
		, uint64_t outerFlags
		, ast::Builtin mbrBuiltin
		, uint32_t mbrIndex
		, uint32_t mbrLocation )
	{
		assert( m_currentRoutine );
		auto mbrFlags = ( outerFlags
			| ( ( mbrBuiltin == ast::Builtin::eNone )
				? ast::var::Flag::eNone
				: ast::var::Flag::eBuiltin ) );
		mbrLocation = ( ( mbrBuiltin == ast::Builtin::eNone )
			? mbrLocation
			: ast::type::Struct::InvalidLocation );

		if ( HlslHelpersInternal::isHighFreq( mbrBuiltin, true ) )
		{
			if ( m_patchInputs && checkFlag( outerFlags, ast::var::Flag::ePatchInput ) )
			{
				m_patchInputs->addPendingMbr( var
					, mbrIndex
					, mbrFlags
					, mbrLocation );
			}
			else
			{
				m_highFreqInputs.addPendingMbr( var
					, mbrIndex
					, mbrFlags
					, mbrLocation );
			}
		}
		else
		{
			m_currentRoutine->registerInputMbr( var
				, outerFlags
				, mbrBuiltin
				, mbrIndex
				, mbrLocation );
		}
	}

	void AdaptationData::registerOutputMbr( ast::var::VariablePtr var
		, uint64_t outerFlags
		, ast::Builtin mbrBuiltin
		, uint32_t mbrIndex
		, uint32_t mbrLocation )
	{
		assert( m_currentRoutine );
		m_currentRoutine->registerOutputMbr( var
			, outerFlags
			, mbrBuiltin
			, mbrIndex
			, mbrLocation );
	}

	void checkType( ast::type::TypePtr ptype
		, IntrinsicsConfig & config )
	{
		ast::type::traverseType( ptype, 1u
			, [&config]( ast::type::TypePtr type
				, [[maybe_unused]] uint32_t arraySize )
			{
				switch ( type->getRawKind() )
				{
				case ast::type::Kind::eImage:
				case ast::type::Kind::eSampler:
				case ast::type::Kind::eCombinedImage:
				case ast::type::Kind::eSampledImage:
				case ast::type::Kind::eAccelerationStructure:
					return;
				default:
					break;
				}

				auto component = getComponentType( type );

				while ( !isScalarType( component ) )
				{
					component = getComponentType( component );
				}

				if ( component == ast::type::Kind::eDouble )
				{
					config.requiresDouble = true;
				}

				if ( component == ast::type::Kind::eInt8
					|| component == ast::type::Kind::eUInt8 )
				{
					config.requiresInt8 = true;
				}

				if ( component == ast::type::Kind::eInt16
					|| component == ast::type::Kind::eUInt16 )
				{
					config.requiresInt16 = true;
				}

				if ( component == ast::type::Kind::eInt64 )
				{
					config.requiresSInt64 = true;
				}

				if ( component == ast::type::Kind::eUInt64 )
				{
					config.requiresUInt64 = true;
				}
			} );
	}

	//*********************************************************************************************
}
