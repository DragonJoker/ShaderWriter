/*
See LICENSE file in root folder
*/
#include "ShaderAST/Debug/DebugCommon.hpp"

#include "ShaderAST/Expr/Expr.hpp"
#include "ShaderAST/Stmt/PreprocExtension.hpp"
#include "ShaderAST/Stmt/StmtInOutVariableDecl.hpp"
#include "ShaderAST/Type/TypeArray.hpp"
#include "ShaderAST/Type/TypeImage.hpp"
#include "ShaderAST/Type/TypeSampledImage.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"
#include "ShaderAST/Var/Variable.hpp"

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <sstream>
#pragma warning( pop )

namespace ast::debug
{
	namespace
	{
		std::string getName( type::ImageDim value )
		{
			switch ( value )
			{
			case type::ImageDim::e1D:
				return "1D";
			case type::ImageDim::e2D:
				return "2D";
			case type::ImageDim::e3D:
				return "3D";
			case type::ImageDim::eCube:
				return "CUBE";
			case type::ImageDim::eRect:
				return "RECT";
			case type::ImageDim::eBuffer:
				return "BUFFER";
			default:
				AST_Failure( "Unsupported type::ImageDim" );
				return "UNDEFINED";
			}
		}

		std::string getName( type::Trinary value
			, std::string const & trueTxt = "TRUE"
			, std::string const & falseTxt = "FALSE"
			, std::string const & dontCareTxt = "DONTCARE" )
		{
			switch ( value )
			{
			case type::Trinary::eTrue:
				return trueTxt;
			case type::Trinary::eFalse:
				return falseTxt;
			default:
				return dontCareTxt;
			}
		}

		std::string getName( type::AccessKind value )
		{
			switch ( value )
			{
			case type::AccessKind::eRead:
				return "R";
			case type::AccessKind::eWrite:
				return "W";
			default:
				return "RW";
			}
		}

		std::string getName( bool value
			, std::string const & trueTxt = "TRUE"
			, std::string const & falseTxt = "FALSE" )
		{
			return value
				? trueTxt
				: falseTxt;
		}

		std::string join( std::string const & lhs
			, std::string const & rhs )
		{
			if ( !rhs.empty() && !lhs.empty() )
			{
				return lhs + rhs;
			}

			return std::string{};
		}

		std::string getName( type::ImageConfiguration const & config )
		{
			static std::string const empty;
			std::string result;
			result += getName( config.dimension );
			result += "," + debug::getName( config.format );
			result += join( ",", getName( config.isDepth, "Depth", empty, empty ) );
			result += join( ",", getName( config.isSampled, "Sampled", empty, empty ) );
			result += join( ",", getName( config.isArrayed, "Array", empty ) );
			result += join( ",", getName( config.isMS, "MS", empty ) );
			result += join( ",", getName( config.accessKind ) );
			return result;
		}

		std::string getName( type::Struct const & type )
		{
			return type.getName()
				+ "," + ast::debug::getName( type.getMemoryLayout() );
		}

		std::string computeArray( uint32_t arraySize )
		{
			std::string result;

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

	std::string getName( type::MemoryLayout value )
	{
		switch ( value )
		{
		case type::MemoryLayout::eStd140:
			return "STD140";
		case type::MemoryLayout::eStd430:
			return "STD430";
		case type::MemoryLayout::eC:
			return "C";
		case type::MemoryLayout::eScalar:
			return "SCALAR";
		case type::MemoryLayout::eShaderRecord:
			return "SHADERRECORD";
		default:
			AST_Failure( "Unsupported type::MemoryLayout" );
			return "UNDEFINED";
		}
	}

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
		case type::Kind::eRayDesc:
			result = "RAYDESC";
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
			result = "UINT32";
			break;
		case type::Kind::eUInt64:
			result = "UINT64";
			break;
		case type::Kind::eFloat:
			result = "FLOAT";
			break;
		case type::Kind::eDouble:
			result = "DOUBLE";
			break;
		case type::Kind::eHalf:
			result = "HALF";
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
			result = "U32VEC2";
			break;
		case type::Kind::eVec3U:
			result = "U32VEC3";
			break;
		case type::Kind::eVec4U:
			result = "U32VEC4";
			break;
		case type::Kind::eVec2U64:
			result = "U64VEC2";
			break;
		case type::Kind::eVec3U64:
			result = "U64VEC3";
			break;
		case type::Kind::eVec4U64:
			result = "U64VEC4";
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
		case type::Kind::eVec2H:
			result = "HVEC2";
			break;
		case type::Kind::eVec4H:
			result = "HVEC4";
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
		case type::Kind::eImage:
			result = "IMAGE";
			break;
		case type::Kind::eSampler:
			result = "SAMPLER";
			break;
		case type::Kind::eSampledImage:
			result = "SAMPLEDIMG";
			break;
		case type::Kind::eArray:
			result = "ARRAY";
			break;
		case type::Kind::ePointer:
			result = "POINTER";
			break;
		case type::Kind::eGeometryInput:
			result = "GEOMIN";
			break;
		case type::Kind::eGeometryOutput:
			result = "GEOMOUT";
			break;
		case type::Kind::eTessellationControlInput:
			result = "TESSCIN";
			break;
		case type::Kind::eTessellationControlOutput:
			result = "TESSCOUT";
			break;
		case type::Kind::eTessellationEvaluationInput:
			result = "TESSEIN";
			break;
		case type::Kind::eTessellationInputPatch:
			result = "PATCHIN";
			break;
		case type::Kind::eTessellationOutputPatch:
			result = "PATCHOUT";
			break;
		case type::Kind::eComputeInput:
			result = "COMPIN";
			break;
		case type::Kind::eFragmentInput:
			result = "FRAGIN";
			break;
		case type::Kind::eAccelerationStructure:
			result = "ACCST";
			break;
		case type::Kind::eMeshVertexOutput:
			result = "MESHVTXOUT";
			break;
		case type::Kind::eMeshPrimitiveOutput:
			result = "MESHPRIMOUT";
			break;
		default:
			assert( false );
			result = "UNKNOWN";
			break;
		}

		return result;
	}

	std::string getName( type::TypePtr type )
	{
		return getName( *type );
	}

	std::string getName( type::Kind kind
		, uint32_t arraySize )
	{
		return getName( kind ) + computeArray( arraySize );
	}

	std::string getName( type::ImageFormat value )
	{
		switch ( value )
		{
		case ast::type::ImageFormat::eUnknown:
			return "UNKNOWN";
		case ast::type::ImageFormat::eRgba32f:
			return "RGBA32F";
		case ast::type::ImageFormat::eRgba16f:
			return "RGBA16F";
		case ast::type::ImageFormat::eRg32f:
			return "RG32F";
		case ast::type::ImageFormat::eRg16f:
			return "RG16F";
		case ast::type::ImageFormat::eR32f:
			return "R32F";
		case ast::type::ImageFormat::eR16f:
			return "R16F";
		case ast::type::ImageFormat::eRgba32i:
			return "RGBA32I";
		case ast::type::ImageFormat::eRgba16i:
			return "RGBA16I";
		case ast::type::ImageFormat::eRgba8i:
			return "RGBA8I";
		case ast::type::ImageFormat::eRg32i:
			return "RG32I";
		case ast::type::ImageFormat::eRg16i:
			return "RG16I";
		case ast::type::ImageFormat::eRg8i:
			return "RG8I";
		case ast::type::ImageFormat::eR32i:
			return "R32I";
		case ast::type::ImageFormat::eR16i:
			return "R16I";
		case ast::type::ImageFormat::eR8i:
			return "R8I";
		case ast::type::ImageFormat::eRgba32u:
			return "RGBA32U";
		case ast::type::ImageFormat::eRgba16u:
			return "RGBA16U";
		case ast::type::ImageFormat::eRgba8u:
			return "RGBA8U";
		case ast::type::ImageFormat::eRg32u:
			return "RG32U";
		case ast::type::ImageFormat::eRg16u:
			return "RG16U";
		case ast::type::ImageFormat::eRg8u:
			return "RG8U";
		case ast::type::ImageFormat::eR32u:
			return "R32U";
		case ast::type::ImageFormat::eR16u:
			return "R16U";
		case ast::type::ImageFormat::eR8u:
			return "R8U";
		default:
			AST_Failure( "Unsupported type::ImageFormat" );
			return "UNDEFINED";
		}
	}

	std::string getName( ast::type::ImageFormat format
		, ast::type::ImageDim dim
		, bool arrayed
		, bool depth
		, bool ms )
	{
		return getName( dim )
			+ getName( format )
			+ getName( arrayed, "Array", "" )
			+ getName( depth, "Shadow", "" )
			+ getName( ms, "MS", "" );
	}

	std::string getName( ast::type::ImageFormat format
		, ast::type::AccessKind access
		, ast::type::ImageDim dim
		, bool arrayed
		, bool depth
		, bool ms )
	{
		return getName( dim )
			+ getName( format )
			+ getName( arrayed, "Array", "" )
			+ getName( depth, "Shadow", "" )
			+ getName( ms, "MS", "" )
			+ getName( access );
	}

	std::string getName( type::Type const & type )
	{
		std::string result;

		switch ( type.getRawKind() )
		{
		case type::Kind::eArray:
			result = getName( *static_cast< type::Array const & >( type ).getType() );
			result += computeArray( static_cast< type::Array const & >( type ).getArraySize() );
			break;
		case type::Kind::ePointer:
			if ( static_cast< type::Pointer const & >( type ).isForward() )
			{
				result = "FWD";
			}
			result += getName( *static_cast< type::Pointer const & >( type ).getPointerType() );
			break;
		case type::Kind::eRayPayload:
			result = getName( *static_cast< type::RayPayload const & >( type ).getDataType() );
			result += "<" + std::to_string( static_cast< type::RayPayload const & >( type ).getLocation() ) + ">";
			break;
		case type::Kind::eCallableData:
			result = getName( *static_cast< type::CallableData const & >( type ).getDataType() );
			result += "<" + std::to_string( static_cast< type::CallableData const & >( type ).getLocation() ) + ">";
			break;
		case type::Kind::eHitAttribute:
			result = getName( *static_cast< type::HitAttribute const & >( type ).getDataType() );
			break;
		case type::Kind::eStruct:
		case type::Kind::eRayDesc:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::Struct const & >( type ) );
			result += ")";
			break;
		case type::Kind::eImage:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::Image const & >( type ).getConfig() );
			result += ")";
			break;
		case type::Kind::eSampledImage:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::SampledImage const & >( type ).getConfig() );
			result += ")";
			break;
		case type::Kind::eFragmentInput:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::FragmentInput const & >( type ).getCenter() );
			result += ", " + getName( static_cast< type::FragmentInput const & >( type ).getOrigin() );
			result += ")";
			break;
		case type::Kind::eGeometryInput:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::GeometryInput const & >( type ).getLayout() );
			result += ")";
			break;
		case type::Kind::eGeometryOutput:
			result = getName( getNonArrayKind( type ) );
			result += "<" + std::to_string( static_cast< type::GeometryOutput const & >( type ).getCount() );
			result += ">(" + getName( static_cast< type::GeometryOutput const & >( type ).getLayout() );
			result += ")";
			break;
		case type::Kind::eTessellationControlInput:
			result = getName( getNonArrayKind( type ) );
			result += "<" + std::to_string( static_cast< type::TessellationControlInput const & >( type ).getInputVertices() );
			result += ">";
			break;
		case type::Kind::eTessellationControlOutput:
			result = getName( getNonArrayKind( type ) );
			result += "<" + std::to_string( static_cast< type::TessellationControlOutput const & >( type ).getOutputVertices() );
			result += ">(" + getName( static_cast< type::TessellationControlOutput const & >( type ).getDomain() );
			result += ", " + getName( static_cast< type::TessellationControlOutput const & >( type ).getPartitioning() );
			result += ", " + getName( static_cast< type::TessellationControlOutput const & >( type ).getOrder() );
			result += ", " + getName( static_cast< type::TessellationControlOutput const & >( type ).getTopology() );
			result += ")";
			break;
		case type::Kind::eTessellationOutputPatch:
			result = getName( getNonArrayKind( type ) );
			result += "(" + std::to_string( static_cast< type::TessellationOutputPatch const & >( type ).getLocation() );
			result += ")";
			break;
		case type::Kind::eTessellationEvaluationInput:
			result = getName( getNonArrayKind( type ) );
			result += "<" + std::to_string( static_cast< type::TessellationEvaluationInput const & >( type ).getInputVertices() );
			result += ">(" + getName( static_cast< type::TessellationEvaluationInput const & >( type ).getDomain() );
			result += ", " + getName( static_cast< type::TessellationEvaluationInput const & >( type ).getPartitioning() );
			result += ", " + getName( static_cast< type::TessellationEvaluationInput const & >( type ).getPrimitiveOrdering() );
			result += ")";
			break;
		case type::Kind::eTessellationInputPatch:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::TessellationInputPatch const & >( type ).getDomain() );
			result += ", " + std::to_string( static_cast< type::TessellationInputPatch const & >( type ).getLocation() );
			result += ")";
			break;
		case type::Kind::eMeshVertexOutput:
			result = getName( getNonArrayKind( type ) );
			result += "(" + std::to_string( static_cast< type::MeshVertexOutput const & >( type ).getMaxVertices() );
			result += ")";
			break;
		case type::Kind::eMeshPrimitiveOutput:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::MeshPrimitiveOutput const & >( type ).getTopology() );
			result += ", " + std::to_string( static_cast< type::MeshPrimitiveOutput const & >( type ).getMaxPrimitives() );
			result += ")";
			break;
		default:
			result = getName( type.getKind() );
			break;
		}

		return result;
	}

	std::string getName( type::InputLayout value )
	{
		switch ( value )
		{
		case type::InputLayout::ePointList:
			return "POINTLIST";
		case type::InputLayout::eLineList:
			return "LINELIST";
		case type::InputLayout::eLineStrip:
			return "LINESTRIP";
		case type::InputLayout::eTriangleList:
			return "TRIANGLELIST";
		case type::InputLayout::eTriangleStrip:
			return "TRIANGLESTRIP";
		case type::InputLayout::eTriangleFan:
			return "TRIANGLEFAN";
		case type::InputLayout::eLineListWithAdjacency:
			return "LINELISTWA";
		case type::InputLayout::eLineStripWithAdjacency:
			return "LINESTRIPWA";
		case type::InputLayout::eTriangleListWithAdjacency:
			return "TRIANGLELISTWA";
		case type::InputLayout::eTriangleStripWithAdjacency:
			return "TRIANGLESTRIPWA";
		default:
			AST_Failure( "Unsupported input layout." );
			return "UNDEFINED";
		}
	}

	std::string getName( type::OutputLayout value )
	{
		switch ( value )
		{
		case type::OutputLayout::ePointList:
			return "POINTLIST";
		case type::OutputLayout::eLineStrip:
			return "LINESTRIP";
		case type::OutputLayout::eTriangleStrip:
			return "TRIANGLESTRIP";
		default:
			AST_Failure( "Unsupported output layout." );
			return "UNDEFINED";
		}
	}

	std::string getName( type::PatchDomain value )
	{
		switch ( value )
		{
		case type::PatchDomain::eIsolines:
			return "ISOLINES";
		case type::PatchDomain::eTriangles:
			return "TRIANGLES";
		case type::PatchDomain::eQuads:
			return "QUADS";
		default:
			AST_Failure( "Unsupported type::PatchDomain." );
			return "UNDEFINED";
		}
	}

	std::string getName( type::Partitioning value )
	{
		switch ( value )
		{
		case type::Partitioning::eEqual:
			return "EQUAL";
		case type::Partitioning::eFractionalEven:
			return "FRACTIONALEVEN";
		case type::Partitioning::eFractionalOdd:
			return "FRACTIONALODD";
		default:
			AST_Failure( "Unsupported type::Partitioning." );
			return "UNDEFINED";
		}
	}

	std::string getName( type::OutputTopology value )
	{
		switch ( value )
		{
		case type::OutputTopology::ePoint:
			return "POINT";
		case type::OutputTopology::eLine:
			return "LINE";
		case type::OutputTopology::eTriangle:
			return "TRIANGLE";
		case type::OutputTopology::eQuad:
			return "QUAD";
		default:
			AST_Failure( "Unsupported type::Partitioning." );
			return "UNDEFINED";
		}
	}

	std::string getName( type::PrimitiveOrdering value )
	{
		switch ( value )
		{
		case type::PrimitiveOrdering::eCW:
			return "CW";
		case type::PrimitiveOrdering::eCCW:
			return "CCW";
		default:
			AST_Failure( "Unsupported type::PrimitiveOrdering." );
			return "UNDEFINED";
		}
	}

	std::string getName( FragmentOrigin value )
	{
		switch ( value )
		{
		case ast::FragmentOrigin::eLowerLeft:
			return "LOWER_LEFT";
		case ast::FragmentOrigin::eUpperLeft:
			return "UPPER_LEFT";
		default:
			AST_Failure( "Unsupported FragmentOrigin" );
			return "UNDEFINED";
		}
	}

	std::string getName( FragmentCenter value )
	{
		switch ( value )
		{
		case ast::FragmentCenter::eHalfPixel:
			return "HALF_PIXEL";
		case ast::FragmentCenter::eCenterInteger:
			return "CENTER_INTEGER";
		default:
			AST_Failure( "Unsupported FragmentCenter" );
			return "UNDEFINED";
		}
	}

	std::string displayVar( ast::var::Variable const & var )
	{
		std::string result = "VAR(";
		std::string sep;

		if ( var.isInputParam() )
		{
			result += sep + "IN";
			sep = ",";
		}

		if ( var.isOutputParam() )
		{
			result += sep + "OUT";
			sep = ",";
		}

		if ( var.isParam() )
		{
			result += sep + "ARG";
			sep = ",";
		}

		if ( var.isShaderInput() )
		{
			result += sep + "INATTR";
			sep = ",";
		}

		if ( var.isShaderOutput() )
		{
			result += sep + "OUTATTR";
			sep = ",";
		}

		if ( var.isConstant() )
		{
			result += sep + "CONST";
			sep = ",";
		}

		if ( var.isShaderConstant() )
		{
			result += sep + "SHDRCONST";
			sep = ",";
		}

		if ( var.isPushConstant() )
		{
			result += sep + "PUSH";
			sep = ",";
		}

		if ( var.isUniform() )
		{
			result += sep + "UNIFORM";
			sep = ",";
		}

		if ( var.isBuiltin() )
		{
			result += sep + "BUILTIN";
			sep = ",";
		}

		if ( var.isImplicit() )
		{
			result += sep + "IMPLICIT";
			sep = ",";
		}

		if ( var.isStatic() )
		{
			result += sep + "STATIC";
			sep = ",";
		}

		if ( var.isSpecialisationConstant() )
		{
			result += sep + "SPECCONST";
			sep = ",";
		}

		if ( var.isLocale() )
		{
			result += sep + "LOCALE";
			sep = ",";
		}

		if ( var.isMember() )
		{
			result += sep + "MEMBER";
			sep = ",";
		}

		if ( var.isFlat() )
		{
			result += sep + "FLAT";
			sep = ",";
		}

		if ( var.isPatchInput() )
		{
			result += sep + "PATCHIN";
			sep = ",";
		}

		if ( var.isPatchOutput() )
		{
			result += sep + "PATCHOUT";
			sep = ",";
		}

		if ( var.isCentroid() )
		{
			result += sep + "CENTROID";
			sep = ",";
		}

		if ( var.isPerSample() )
		{
			result += sep + "PERSAMPLE";
			sep = ",";
		}

		if ( var.isGeometryStream() )
		{
			result += sep + "GEOMSTREAM";
			sep = ",";
		}

		if ( var.isBlendIndex() )
		{
			result += sep + "BLENDIDX";
			sep = ",";
		}

		if ( var.isStorageBuffer() )
		{
			result += sep + "STORBUFFER";
			sep = ",";
		}

		if ( var.isIncomingRayPayload() )
		{
			result += sep + "INRAYPAYLOAD";
			sep = ",";
		}

		if ( var.isRayPayload() )
		{
			result += sep + "RAYPAYLOAD";
			sep = ",";
		}

		if ( var.isIncomingCallableData() )
		{
			result += sep + "INCALLDATA";
			sep = ",";
		}

		if ( var.isCallableData() )
		{
			result += sep + "CALLDATA";
			sep = ",";
		}

		if ( var.isHitAttribute() )
		{
			result += sep + "HITATTR";
			sep = ",";
		}

		if ( var.isBufferReference() )
		{
			result += sep + "BUFFREF";
			sep = ",";
		}

		if ( var.isPerPrimitive() )
		{
			result += sep + "PERPRIM";
			sep = ",";
		}

		if ( var.isPerView() )
		{
			result += sep + "PERVIEW";
			sep = ",";
		}

		result += sep + getName( *var.getType() );
		result += ") " + var.getName();
		return result;
	}

	std::string displayVar( ast::var::VariablePtr var )
	{
		return displayVar( *var );
	}
}
