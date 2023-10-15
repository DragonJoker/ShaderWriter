/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/DebugDisplayStatements.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"
#include "ShaderAST/Expr/GetCombinedImageAccessName.hpp"
#include "ShaderAST/Expr/GetIntrinsicName.hpp"
#include "ShaderAST/Expr/GetStorageImageAccessName.hpp"
#include "ShaderAST/Stmt/StmtVisitor.hpp"

#include <cmath>
#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <sstream>
#include <unordered_set>
#pragma warning( pop )

#pragma GCC diagnostic ignored "-Wrestrict"
#pragma GCC diagnostic ignored "-Wstringop-overflow"

namespace ast::debug
{
	namespace helpers
	{
		static std::string getImageFormatName( type::ImageFormat value )
		{
			switch ( value )
			{
			case ast::type::ImageFormat::eUnknown:
				return "Unknown";
			case ast::type::ImageFormat::eRgba32f:
				return "RGBA32f";
			case ast::type::ImageFormat::eRgba16f:
				return "RGBA16f";
			case ast::type::ImageFormat::eRg32f:
				return "RG32f";
			case ast::type::ImageFormat::eRg16f:
				return "RG16f";
			case ast::type::ImageFormat::eR32f:
				return "R32f";
			case ast::type::ImageFormat::eR16f:
				return "R16f";
			case ast::type::ImageFormat::eRgba32i:
				return "RGBA32i";
			case ast::type::ImageFormat::eRgba16i:
				return "RGBA16i";
			case ast::type::ImageFormat::eRgba8i:
				return "RGBA8i";
			case ast::type::ImageFormat::eRg32i:
				return "RG32i";
			case ast::type::ImageFormat::eRg16i:
				return "RG16i";
			case ast::type::ImageFormat::eRg8i:
				return "RG8i";
			case ast::type::ImageFormat::eR32i:
				return "R32i";
			case ast::type::ImageFormat::eR16i:
				return "R16i";
			case ast::type::ImageFormat::eR8i:
				return "R8i";
			case ast::type::ImageFormat::eRgba32u:
				return "RGBA32u";
			case ast::type::ImageFormat::eRgba16u:
				return "RGBA16u";
			case ast::type::ImageFormat::eRgba8u:
				return "RGBA8u";
			case ast::type::ImageFormat::eRg32u:
				return "RG32u";
			case ast::type::ImageFormat::eRg16u:
				return "RG16u";
			case ast::type::ImageFormat::eRg8u:
				return "RG8u";
			case ast::type::ImageFormat::eR32u:
				return "R32u";
			case ast::type::ImageFormat::eR16u:
				return "R16u";
			case ast::type::ImageFormat::eR8u:
				return "R8u";
			default:
				AST_Failure( "Unsupported type::ImageFormat" );
				return "Undefined";
			}
		}

		static std::string getImageDimName( type::ImageDim value )
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
				return "Cube";
			case type::ImageDim::eRect:
				return "Rect";
			case type::ImageDim::eBuffer:
				return "Buffer";
			default:
				AST_Failure( "Unsupported type::ImageDim" );
				return "Undefined";
			}
		}

		static std::string getTrinaryName( type::Trinary value
			, std::string const & trueTxt = "True"
			, std::string const & falseTxt = "False"
			, std::string const & dontCareTxt = "DontCare" )
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

		static std::string getAccessName( type::AccessKind value )
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

		static std::string getBoolName( bool value
			, std::string const & trueTxt = "True"
			, std::string const & falseTxt = "False" )
		{
			return value
				? trueTxt
				: falseTxt;
		}

		static std::string getImageTypeName( ast::type::ImageFormat format
			, ast::type::ImageDim dim
			, bool arrayed
			, bool ms )
		{
			return getImageDimName( dim )
				+ getImageFormatName( format )
				+ getBoolName( arrayed, "Array", "" )
				+ getBoolName( ms, "MS", "" );
		}

		static std::string getImageTypeName( ast::type::ImageFormat format
			, ast::type::ImageDim dim
			, bool arrayed
			, bool ms
			, bool depth )
		{
			return getImageTypeName( format, dim, arrayed, ms )
				+ getBoolName( depth, "Shadow", "" );
		}

		static std::string getImageTypeName( ast::type::ImageFormat format
			, ast::type::AccessKind access
			, ast::type::ImageDim dim
			, bool arrayed
			, bool ms )
		{
			return getImageTypeName( format, dim, arrayed, ms )
				+ getAccessName( access );
		}

		static std::string join( std::string const & lhs
			, std::string const & rhs )
		{
			if ( !rhs.empty() && !lhs.empty() )
			{
				return lhs + rhs;
			}

			return std::string{};
		}

		static std::string getImageConfigName( type::ImageConfiguration const & config )
		{
			static std::string const empty;
			std::string result;
			result += getImageDimName( config.dimension );
			result += "," + getImageFormatName( config.format );
			result += join( ",", getTrinaryName( config.isSampled, "Sampled", empty, empty ) );
			result += join( ",", getBoolName( config.isArrayed, "Array", empty ) );
			result += join( ",", getBoolName( config.isMS, "MS", empty ) );
			result += join( ",", getAccessName( config.accessKind ) );
			return result;
		}

		static std::string getMemoryLayoutName( type::MemoryLayout value )
		{
			switch ( value )
			{
			case type::MemoryLayout::eStd140:
				return "Std140";
			case type::MemoryLayout::eStd430:
				return "Std430";
			case type::MemoryLayout::eC:
				return "C";
			case type::MemoryLayout::eScalar:
				return "Scalar";
			case type::MemoryLayout::eShaderRecord:
				return "ShaderRecord";
			default:
				AST_Failure( "Unsupported type::MemoryLayout" );
				return "Undefined";
			}
		}

		static std::string computeArray( uint32_t arraySize )
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

		static std::string getTypeName( type::Kind kind )
		{
			std::string result;

			switch ( kind )
			{
			case type::Kind::eUndefined:
				result = "Undefined";
				break;
			case type::Kind::eVoid:
				result = "Void";
				break;
			case type::Kind::eStruct:
				result = "Struct";
				break;
			case type::Kind::eRayDesc:
				result = "RayDesc";
				break;
			case type::Kind::eFunction:
				result = "Function";
				break;
			case type::Kind::eBoolean:
				result = "Boolean";
				break;
			case type::Kind::eInt8:
				result = "Int8";
				break;
			case type::Kind::eInt16:
				result = "Int16";
				break;
			case type::Kind::eInt32:
				result = "Int32";
				break;
			case type::Kind::eInt64:
				result = "Int64";
				break;
			case type::Kind::eUInt8:
				result = "UInt8";
				break;
			case type::Kind::eUInt16:
				result = "UInt16";
				break;
			case type::Kind::eUInt32:
				result = "UInt32";
				break;
			case type::Kind::eUInt64:
				result = "UInt64";
				break;
			case type::Kind::eFloat:
				result = "Float";
				break;
			case type::Kind::eDouble:
				result = "Double";
				break;
			case type::Kind::eHalf:
				result = "Half";
				break;
			case type::Kind::eVec2B:
				result = "Vec2B";
				break;
			case type::Kind::eVec3B:
				result = "Vec3B";
				break;
			case type::Kind::eVec4B:
				result = "Vec4B";
				break;
			case type::Kind::eVec2I8:
				result = "Vec2I8";
				break;
			case type::Kind::eVec3I8:
				result = "Vec3I8";
				break;
			case type::Kind::eVec4I8:
				result = "Vec4I8";
				break;
			case type::Kind::eVec2I16:
				result = "Vec2I16";
				break;
			case type::Kind::eVec3I16:
				result = "Vec3I16";
				break;
			case type::Kind::eVec4I16:
				result = "Vec4I16";
				break;
			case type::Kind::eVec2I32:
				result = "Vec2I32";
				break;
			case type::Kind::eVec3I32:
				result = "Vec3I32";
				break;
			case type::Kind::eVec4I32:
				result = "Vec4I32";
				break;
			case type::Kind::eVec2I64:
				result = "Vec2I64";
				break;
			case type::Kind::eVec3I64:
				result = "Vec3I64";
				break;
			case type::Kind::eVec4I64:
				result = "Vec4I64";
				break;
			case type::Kind::eVec2U8:
				result = "Vec2U8";
				break;
			case type::Kind::eVec3U8:
				result = "Vec3U8";
				break;
			case type::Kind::eVec4U8:
				result = "Vec4U8";
				break;
			case type::Kind::eVec2U16:
				result = "Vec2U16";
				break;
			case type::Kind::eVec3U16:
				result = "Vec3U16";
				break;
			case type::Kind::eVec4U16:
				result = "Vec4U16";
				break;
			case type::Kind::eVec2U32:
				result = "Vec2U32";
				break;
			case type::Kind::eVec3U32:
				result = "Vec3U32";
				break;
			case type::Kind::eVec4U32:
				result = "Vec4U32";
				break;
			case type::Kind::eVec2U64:
				result = "Vec2U64";
				break;
			case type::Kind::eVec3U64:
				result = "Vec3U64";
				break;
			case type::Kind::eVec4U64:
				result = "Vec4U64";
				break;
			case type::Kind::eVec2F:
				result = "Vec2F";
				break;
			case type::Kind::eVec3F:
				result = "Vec3F";
				break;
			case type::Kind::eVec4F:
				result = "Vec4F";
				break;
			case type::Kind::eVec2D:
				result = "Vec2D";
				break;
			case type::Kind::eVec3D:
				result = "Vec3D";
				break;
			case type::Kind::eVec4D:
				result = "Vec4D";
				break;
			case type::Kind::eVec2H:
				result = "Vec2H";
				break;
			case type::Kind::eVec4H:
				result = "Vec4H";
				break;
			case type::Kind::eMat2x2F:
				result = "Mat2x2F";
				break;
			case type::Kind::eMat2x3F:
				result = "Mat2x3F";
				break;
			case type::Kind::eMat2x4F:
				result = "Mat2x4F";
				break;
			case type::Kind::eMat3x2F:
				result = "Mat3x2F";
				break;
			case type::Kind::eMat3x3F:
				result = "Mat3x3F";
				break;
			case type::Kind::eMat3x4F:
				result = "Mat3x4F";
				break;
			case type::Kind::eMat4x2F:
				result = "Mat4x2F";
				break;
			case type::Kind::eMat4x3F:
				result = "Mat4x3F";
				break;
			case type::Kind::eMat4x4F:
				result = "Mat4x4F";
				break;
			case type::Kind::eMat2x2D:
				result = "Mat2x2D";
				break;
			case type::Kind::eMat2x3D:
				result = "Mat2x3D";
				break;
			case type::Kind::eMat2x4D:
				result = "Mat2x4D";
				break;
			case type::Kind::eMat3x2D:
				result = "Mat3x2D";
				break;
			case type::Kind::eMat3x3D:
				result = "Mat3x3D";
				break;
			case type::Kind::eMat3x4D:
				result = "Mat3x4D";
				break;
			case type::Kind::eMat4x2D:
				result = "Mat4x2D";
				break;
			case type::Kind::eMat4x3D:
				result = "Mat4x3D";
				break;
			case type::Kind::eMat4x4D:
				result = "Mat4x4D";
				break;
			case type::Kind::eImage:
				result = "Image";
				break;
			case type::Kind::eSampler:
				result = "Sampler";
				break;
			case type::Kind::eCombinedImage:
				result = "CombinedImage";
				break;
			case type::Kind::eSampledImage:
				result = "SampledImage";
				break;
			case type::Kind::eArray:
				result = "Array";
				break;
			case type::Kind::ePointer:
				result = "Pointer";
				break;
			case type::Kind::eGeometryInput:
				result = "GeometryInput";
				break;
			case type::Kind::eGeometryOutput:
				result = "GeometryOutput";
				break;
			case type::Kind::eTessellationControlInput:
				result = "TessellationControlInput";
				break;
			case type::Kind::eTessellationControlOutput:
				result = "TessellationControlOutput";
				break;
			case type::Kind::eTessellationEvaluationInput:
				result = "TessellationEvaluationInput";
				break;
			case type::Kind::eTessellationInputPatch:
				result = "TessellationInputPatch";
				break;
			case type::Kind::eTessellationOutputPatch:
				result = "TessellationOutputPatch";
				break;
			case type::Kind::eComputeInput:
				result = "ComputeInput";
				break;
			case type::Kind::eFragmentInput:
				result = "FragmentInput";
				break;
			case type::Kind::eAccelerationStructure:
				result = "AccelerationStructure";
				break;
			case type::Kind::eMeshVertexOutput:
				result = "MeshVertexOutput";
				break;
			case type::Kind::eMeshPrimitiveOutput:
				result = "MeshPrimitiveOutput";
				break;
			case type::Kind::eTaskPayloadNV:
				result = "TaskPayloadOutNV";
				break;
			case type::Kind::eTaskPayload:
				result = "TaskPayloadOut";
				break;
			case type::Kind::eTaskPayloadInNV:
				result = "TaskPayloadInNV";
				break;
			case type::Kind::eTaskPayloadIn:
				result = "TaskPayloadIn";
				break;
			default:
				assert( false );
				result = "Unknown";
				break;
			}

			return result;
		}

		static std::string getTypeName( type::Type const & type );

		static std::string getInputLayoutName( type::InputLayout value )
		{
			switch ( value )
			{
			case type::InputLayout::ePointList:
				return "PointList";
			case type::InputLayout::eLineList:
				return "LineList";
			case type::InputLayout::eLineStrip:
				return "LineStrip";
			case type::InputLayout::eTriangleList:
				return "TriangleList";
			case type::InputLayout::eTriangleStrip:
				return "TriangleStrip";
			case type::InputLayout::eTriangleFan:
				return "TriangleFan";
			case type::InputLayout::eLineListWithAdjacency:
				return "LineListWithAdjacency";
			case type::InputLayout::eLineStripWithAdjacency:
				return "LineStripWithAdjacency";
			case type::InputLayout::eTriangleListWithAdjacency:
				return "TriangleListWithAdjacency";
			case type::InputLayout::eTriangleStripWithAdjacency:
				return "TriangleStripWithAdjacency";
			default:
				AST_Failure( "Unsupported input layout." );
				return "Undefined";
			}
		}

		static std::string getOutputLayoutName( type::OutputLayout value )
		{
			switch ( value )
			{
			case type::OutputLayout::ePointList:
				return "PointList";
			case type::OutputLayout::eLineStrip:
				return "LineStrip";
			case type::OutputLayout::eTriangleStrip:
				return "TriangleStrip";
			default:
				AST_Failure( "Unsupported output layout." );
				return "Undefined";
			}
		}

		static std::string getDomainName( type::PatchDomain value )
		{
			switch ( value )
			{
			case type::PatchDomain::eIsolines:
				return "Isolines";
			case type::PatchDomain::eTriangles:
				return "Triangles";
			case type::PatchDomain::eQuads:
				return "Quads";
			default:
				AST_Failure( "Unsupported type::PatchDomain." );
				return "Undefined";
			}
		}

		static std::string getPartitioningName( type::Partitioning value )
		{
			switch ( value )
			{
			case type::Partitioning::eEqual:
				return "Equal";
			case type::Partitioning::eFractionalEven:
				return "FractionalEven";
			case type::Partitioning::eFractionalOdd:
				return "FractionalOdd";
			default:
				AST_Failure( "Unsupported type::Partitioning." );
				return "Undefined";
			}
		}

		static std::string getTopologyName( type::OutputTopology value )
		{
			switch ( value )
			{
			case type::OutputTopology::ePoint:
				return "Point";
			case type::OutputTopology::eLine:
				return "Line";
			case type::OutputTopology::eTriangle:
				return "Triangle";
			case type::OutputTopology::eQuad:
				return "Quad";
			default:
				AST_Failure( "Unsupported type::Partitioning." );
				return "Undefined";
			}
		}

		static std::string getOrderingName( type::PrimitiveOrdering value )
		{
			switch ( value )
			{
			case type::PrimitiveOrdering::eCW:
				return "CW";
			case type::PrimitiveOrdering::eCCW:
				return "CCW";
			default:
				AST_Failure( "Unsupported type::PrimitiveOrdering." );
				return "Undefined";
			}
		}

		static std::string getOriginName( FragmentOrigin value )
		{
			switch ( value )
			{
			case ast::FragmentOrigin::eLowerLeft:
				return "LowerLeft";
			case ast::FragmentOrigin::eUpperLeft:
				return "UpperLeft";
			default:
				AST_Failure( "Unsupported FragmentOrigin" );
				return "Undefined";
			}
		}

		static std::string getCenterName( FragmentCenter value )
		{
			switch ( value )
			{
			case ast::FragmentCenter::eHalfPixel:
				return "HalfPixel";
			case ast::FragmentCenter::eCenterInteger:
				return "CenterInteger";
			default:
				AST_Failure( "Unsupported FragmentCenter" );
				return "Undefined";
			}
		}

		static std::string getTypeName( type::Type const & type )
		{
			std::string result;

			switch ( type.getRawKind() )
			{
			case type::Kind::eArray:
				result = getTypeName( *static_cast< type::Array const & >( type ).getType() );
				result += computeArray( static_cast< type::Array const & >( type ).getArraySize() );
				break;
			case type::Kind::ePointer:
				if ( static_cast< type::Pointer const & >( type ).isForward() )
				{
					result = "FWD";
				}
				result += getTypeName( *static_cast< type::Pointer const & >( type ).getPointerType() );
				break;
			case type::Kind::eRayPayload:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getTypeName( *static_cast< type::RayPayload const & >( type ).getDataType() );
				result += "<" + std::to_string( static_cast< type::RayPayload const & >( type ).getLocation() ) + ">";
				result += ")";
				break;
			case type::Kind::eCallableData:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getTypeName( *static_cast< type::CallableData const & >( type ).getDataType() );
				result += "<" + std::to_string( static_cast< type::CallableData const & >( type ).getLocation() ) + ">";
				result += ")";
				break;
			case type::Kind::eHitAttribute:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getTypeName( *static_cast< type::HitAttribute const & >( type ).getDataType() );
				result += ")";
				break;
			case type::Kind::eRayDesc:
			case type::Kind::eStruct:
				result = static_cast< type::Struct const & >( type ).getName();
				break;
			case type::Kind::eImage:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getImageConfigName( static_cast< type::Image const & >( type ).getConfig() );
				result += ")";
				break;
			case type::Kind::eCombinedImage:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getImageConfigName( static_cast< type::CombinedImage const & >( type ).getConfig() );
				result += ")";
				break;
			case type::Kind::eSampledImage:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getImageConfigName( static_cast< type::SampledImage const & >( type ).getConfig() );
				result += ")";
				break;
			case type::Kind::eFragmentInput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getCenterName( static_cast< type::FragmentInput const & >( type ).getCenter() );
				result += ", " + getOriginName( static_cast< type::FragmentInput const & >( type ).getOrigin() );
				result += ")";
				break;
			case type::Kind::eGeometryInput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getInputLayoutName( static_cast< type::GeometryInput const & >( type ).getLayout() );
				result += ")";
				break;
			case type::Kind::eGeometryOutput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + std::to_string( static_cast< type::GeometryOutput const & >( type ).getCount() );
				result += ", " + getOutputLayoutName( static_cast< type::GeometryOutput const & >( type ).getLayout() );
				result += ")";
				break;
			case type::Kind::eTessellationControlInput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "<" + std::to_string( static_cast< type::TessellationControlInput const & >( type ).getInputVertices() );
				result += ">";
				break;
			case type::Kind::eTessellationControlOutput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "<" + std::to_string( static_cast< type::TessellationControlOutput const & >( type ).getOutputVertices() );
				result += ">(" + getDomainName( static_cast< type::TessellationControlOutput const & >( type ).getDomain() );
				result += ", " + getPartitioningName( static_cast< type::TessellationControlOutput const & >( type ).getPartitioning() );
				result += ", " + getOrderingName( static_cast< type::TessellationControlOutput const & >( type ).getOrder() );
				result += ", " + getTopologyName( static_cast< type::TessellationControlOutput const & >( type ).getTopology() );
				result += ")";
				break;
			case type::Kind::eTessellationOutputPatch:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + std::to_string( static_cast< type::TessellationOutputPatch const & >( type ).getLocation() );
				result += ")";
				break;
			case type::Kind::eTessellationEvaluationInput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "<" + std::to_string( static_cast< type::TessellationEvaluationInput const & >( type ).getInputVertices() );
				result += ">(" + getDomainName( static_cast< type::TessellationEvaluationInput const & >( type ).getDomain() );
				result += ", " + getPartitioningName( static_cast< type::TessellationEvaluationInput const & >( type ).getPartitioning() );
				result += ", " + getOrderingName( static_cast< type::TessellationEvaluationInput const & >( type ).getPrimitiveOrdering() );
				result += ")";
				break;
			case type::Kind::eTessellationInputPatch:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getDomainName( static_cast< type::TessellationInputPatch const & >( type ).getDomain() );
				result += ", " + std::to_string( static_cast< type::TessellationInputPatch const & >( type ).getLocation() );
				result += ")";
				break;
			case type::Kind::eMeshVertexOutput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + std::to_string( static_cast< type::MeshVertexOutput const & >( type ).getMaxVertices() );
				result += ")";
				break;
			case type::Kind::eMeshPrimitiveOutput:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getTopologyName( static_cast< type::MeshPrimitiveOutput const & >( type ).getTopology() );
				result += ", " + std::to_string( static_cast< type::MeshPrimitiveOutput const & >( type ).getMaxPrimitives() );
				result += ")";
				break;
			case type::Kind::eTaskPayload:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getTypeName( *static_cast< type::TaskPayload const & >( type ).getType() );
				result += ")";
				break;
			case type::Kind::eTaskPayloadIn:
				result = getTypeName( getNonArrayKind( type ) );
				result += "(" + getTypeName( *static_cast< type::TaskPayloadIn const & >( type ).getType() );
				result += ")";
				break;
			default:
				result = getTypeName( type.getKind() );
				break;
			}

			return result;
		}

		static std::string displayVar( ast::var::Variable const & var )
		{
			return debug::getTypeName( var.getType() ) + " " + var.getName();
		}

		static std::string displayVar( ast::var::VariablePtr var )
		{
			return displayVar( *var );
		}

		static std::string getOperatorName( expr::Kind kind )
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

		static std::string getCompositeName( expr::CompositeType value )
		{
			std::string result;

			switch ( value )
			{
			case ast::expr::CompositeType::eVec2:
				result = "Vec2";
				break;
			case ast::expr::CompositeType::eVec3:
				result = "Vec3";
				break;
			case ast::expr::CompositeType::eVec4:
				result = "Vec4";
				break;
			case ast::expr::CompositeType::eMat2x2:
				result = "Mat2X2";
				break;
			case ast::expr::CompositeType::eMat2x3:
				result = "Mat2X3";
				break;
			case ast::expr::CompositeType::eMat2x4:
				result = "Mat2X4";
				break;
			case ast::expr::CompositeType::eMat3x2:
				result = "Mat3X2";
				break;
			case ast::expr::CompositeType::eMat3x3:
				result = "Mat3X3";
				break;
			case ast::expr::CompositeType::eMat3x4:
				result = "Mat3X4";
				break;
			case ast::expr::CompositeType::eMat4x2:
				result = "Mat4X2";
				break;
			case ast::expr::CompositeType::eMat4x3:
				result = "Mat4X3";
				break;
			case ast::expr::CompositeType::eMat4x4:
				result = "Mat4X4";
				break;
			case ast::expr::CompositeType::eCombine:
				result = "Combine";
				break;
			default:
				throw std::runtime_error{ "Unsupported expr::CompositeType" };
			}

			return result;
		}
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

		template< typename ExprT >
		static std::string submit( expr::ExprPtrT< ExprT > const & expr )
		{
			return submit( expr.get() );
		}

	private:
		explicit ExprVisitor( std::string & result )
			: m_result{ result }
		{
		}

		void wrap( ast::expr::Expr * expr )
		{
			bool noParen = expr->getKind() == ast::expr::Kind::eFnCall
				|| expr->getKind() == ast::expr::Kind::eIdentifier
				|| expr->getKind() == ast::expr::Kind::eCompositeConstruct
				|| expr->getKind() == ast::expr::Kind::eLiteral
				|| expr->getKind() == ast::expr::Kind::eMbrSelect
				|| expr->getKind() == ast::expr::Kind::eCast
				|| expr->getKind() == ast::expr::Kind::eSwizzle
				|| expr->getKind() == ast::expr::Kind::eArrayAccess
				|| expr->getKind() == ast::expr::Kind::eIntrinsicCall
				|| expr->getKind() == ast::expr::Kind::eCombinedImageAccessCall
				|| expr->getKind() == ast::expr::Kind::eImageAccessCall
				|| expr->getKind() == ast::expr::Kind::eUnaryMinus
				|| expr->getKind() == ast::expr::Kind::eUnaryPlus
				|| expr->getKind() == ast::expr::Kind::eCopy;

			if ( expr->isNonUniform() )
			{
				m_result += "[nonuniform] ";
			}

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
			m_result += helpers::getOperatorName( expr->getKind() ) + " ";
			wrap( expr->getOperand() );
		}

		void visitBinaryExpr( expr::Binary * expr )override
		{
			wrap( expr->getLHS() );

			if ( expr->getKind() == expr::Kind::eArrayAccess )
			{
			}
			else if ( expr->getKind() == expr::Kind::eAlias )
			{
				m_result += " = ";
				wrap( expr->getRHS() );
			}
			else
			{
				m_result += " " + helpers::getOperatorName( expr->getKind() ) + " ";
				wrap( expr->getRHS() );
			}
		}

		void visitAggrInitExpr( expr::AggrInit * expr )override
		{
			m_result += getTypeName( expr->getType() ) + " ";

			if ( expr->getIdentifier() )
			{
				if ( expr->getIdentifier()->getVariable()->isStatic() )
				{
					m_result += "constexpr ";
				}

				wrap( expr->getIdentifier() );
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

		void visitAliasExpr( expr::Alias * expr )override
		{
			wrap( expr->getLHS() );
			m_result += " = ";
			wrap( expr->getRHS() );
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
			m_result += "cast<";
			m_result += getTypeName( expr->getType() ) + ">(";
			wrap( expr->getOperand() );
			m_result += ")";
		}

		void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
		{
			m_result += "ctor<";
			m_result += helpers::getCompositeName( expr->getComposite() ) + ", ";
			m_result += helpers::getTypeName( expr->getComponent() ) + ">(";
			std::string sep;

			for ( auto & arg : expr->getArgList() )
			{
				m_result += sep;
				arg->accept( this );
				sep = ", ";
			}

			m_result += ")";
		}

		void visitMbrSelectExpr( expr::MbrSelect * expr )override
		{
			wrap( expr->getOuterExpr() );
			m_result += ".";
			m_result += expr->getOuterType()->getMember( expr->getMemberIndex() ).name;
		}

		void visitFnCallExpr( expr::FnCall * expr )override
		{
			if ( expr->isMember() )
			{
				wrap( expr->getInstance() );
				m_result += ".";
			}

			wrap( expr->getFn() );
			m_result += "(";
			std::string sep;

			for ( auto & arg : expr->getArgList() )
			{
				m_result += sep;
				wrap( arg.get() );
				sep = ", ";
			}

			m_result += ")";
		}

		void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
		{
			m_result += getName( expr->getIntrinsic() ) + "(";
			std::string sep;

			for ( auto & arg : expr->getArgList() )
			{
				m_result += sep;
				wrap( arg.get() );
				sep = ", ";
			}

			m_result += ")";
		}

		void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall * expr )override
		{
			m_result += getName( expr->getCombinedImageAccess() ) + "(";
			std::string sep;

			for ( auto & arg : expr->getArgList() )
			{
				m_result += sep;
				wrap( arg.get() );
				sep = ", ";
			}

			m_result += ")";
		}

		void visitImageAccessCallExpr( expr::StorageImageAccessCall * expr )override
		{
			m_result += getName( expr->getImageAccess() ) + "(";
			std::string sep;

			for ( auto & arg : expr->getArgList() )
			{
				m_result += sep;
				wrap( arg.get() );
				sep = ", ";
			}

			m_result += ")";
		}

		void visitIdentifierExpr( expr::Identifier * expr )override
		{
			auto var = expr->getVariable();
			auto name = var->getName();

			while ( var->getOuter() )
			{
				var = var->getOuter();
				name = var->getName() + "::" + name;
			}

			m_result += name;
		}

		void visitInitExpr( expr::Init * expr )override
		{
			m_result += getTypeName( expr->getType() ) + " ";

			if ( expr->getIdentifier()
				&& expr->getIdentifier()->getVariable()->isConstant()
				&& expr->getIdentifier()->getVariable()->isStatic() )
			{
				m_result += "constexpr ";
			}

			wrap( expr->getIdentifier() );
			m_result += " = ";
			wrap( expr->getInitialiser() );
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
			case expr::LiteralType::eInt8:
				stream << int( expr->getValue< expr::LiteralType::eInt8 >() ) << "i8";
				break;
			case expr::LiteralType::eInt16:
				stream << expr->getValue< expr::LiteralType::eInt16 >() << "i16";
				break;
			case expr::LiteralType::eInt32:
				stream << expr->getValue< expr::LiteralType::eInt32 >() << "i32";
				break;
			case expr::LiteralType::eInt64:
				stream << expr->getValue< expr::LiteralType::eInt64 >() << "i64";
				break;
			case expr::LiteralType::eUInt8:
				stream << uint32_t( expr->getValue< expr::LiteralType::eUInt32 >() ) << "u8";
				break;
			case expr::LiteralType::eUInt16:
				stream << expr->getValue< expr::LiteralType::eUInt16 >() << "u16";
				break;
			case expr::LiteralType::eUInt32:
				stream << expr->getValue< expr::LiteralType::eUInt32 >() << "u32";
				break;
			case expr::LiteralType::eUInt64:
				stream << expr->getValue< expr::LiteralType::eUInt64 >() << "u64";
				break;
			case expr::LiteralType::eFloat:
				{
					auto v = expr->getValue< expr::LiteralType::eFloat >();
					stream << v;

					if ( v == std::floor( v ) )
					{
						stream << ".0";
					}
				}
				break;
			case expr::LiteralType::eDouble:
				{
					auto v = expr->getValue< expr::LiteralType::eDouble >();
					stream << v;

					if ( v == std::floor( v ) )
					{
						stream << ".0";
					}
				}
				break;
			default:
				AST_Failure( "Unsupported literal type" );
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

		void visitStreamAppendExpr( expr::StreamAppend * expr )override
		{
			m_result += "Append ";
			wrap( expr->getOperand() );
		}

		void visitSwitchCaseExpr( expr::SwitchCase *expr )override
		{
			wrap( expr->getLabel() );
		}

		void visitSwitchTestExpr( expr::SwitchTest *expr )override
		{
			wrap( expr->getValue() );
		}

		void visitSwizzleExpr( expr::Swizzle * expr )override
		{
			wrap( expr->getOuterExpr() );
			m_result += "." + getName( expr->getSwizzle() );
		}

	private:
		std::string & m_result;
	};

	class StmtVisitor
		: public stmt::Visitor
	{
	public:
		static std::string submit( stmt::Stmt * stmt
			, std::string indent = std::string{} )
		{
			std::string result;
			StmtVisitor vis{ result, std::move( indent ) };
			stmt->accept( &vis );
			return result;
		}

		void declareStruct( type::StructPtr structType )
		{
			if ( m_declaredStructs.insert( structType->getName() ).second )
			{
				for ( auto & member : *structType )
				{
					if ( auto subStructType = getStructType( getNonArrayType( member.type ) ) )
					{
						declareStruct( subStructType );
					}
				}
				
				addStatement( "Structure " + structType->getName() );
				auto save = beginScope();

				for ( auto & mbr : *structType )
				{
					std::string text;

					if ( mbr.builtin != ast::Builtin::eNone )
					{
						text += "[Builtin=" + getName( mbr.builtin ) + "] ";
					}
					else if ( mbr.location != ast::type::Struct::InvalidLocation )
					{
						text += "[Location=" + std::to_string( mbr.location ) + "] ";
					}

					addStatement( text + getTypeName( mbr.type ) + " " + mbr.name );
				}

				endScope( save );
			}
		}

		void declareStruct( type::TypePtr type )
		{
			if ( auto structType = getStructType( type ) )
			{
				declareStruct( structType );
			}
		}

	private:
		StmtVisitor( std::string & result
			, std::string indent )
			: m_indent{ std::move( indent ) }
			, m_result{ result }
		{
		}

		void addStatement( std::string text )
		{
			m_result += m_indent + std::move( text ) + "\n";
		}

		std::string beginScope()
		{
			addStatement( "{" );
			auto save = m_indent;
			m_indent += "\t";
			return save;
		}

		void endScope( std::string oldIndent )
		{
			m_indent = std::move( oldIndent );
			addStatement( "}" );
		}

		std::string doSubmit( ast::expr::Expr * expr )
		{
			declareStruct( expr->getType() );
			return ExprVisitor::submit( expr );
		}

		std::string doSubmit( ast::expr::ExprPtr expr )
		{
			declareStruct( expr->getType() );
			return ExprVisitor::submit( expr.get() );
		}

		void visitAccelerationStructureDeclStmt( stmt::AccelerationStructureDecl * stmt )override
		{
			declareStruct( stmt->getVariable()->getType() );
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( "AccelerationStructure " + helpers::displayVar( stmt->getVariable() ) );
		}

		void visitBreakStmt( stmt::Break * stmt )override
		{
			addStatement( "Break" );
		}

		void visitBufferReferenceDeclStmt( stmt::BufferReferenceDecl * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "BufferReference(" + getTypeName( stmt->getType() ) + ")" );
		}

		void visitCommentStmt( stmt::Comment * stmt )override
		{
			addStatement( "// " + stmt->getText() );
		}

		void visitCompoundStmt( stmt::Compound * stmt )override
		{
			auto save = beginScope();
			visitContainerStmt( stmt );
			endScope( save );
		}

		void visitConstantBufferDeclStmt( stmt::ConstantBufferDecl * stmt )override
		{
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( "[Layout=" + helpers::getMemoryLayoutName( stmt->getMemoryLayout() ) + "]" );
			addStatement( "ConstantsBuffer " + stmt->getName() );
			visitCompoundStmt( stmt );
		}

		void visitContainerStmt( stmt::Container * stmt )override
		{
			for ( auto & curStmt : *stmt )
			{
				curStmt->accept( this );
			}
		}

		void visitContinueStmt( stmt::Continue * stmt )override
		{
			addStatement( "Continue" );
		}

		void visitDemoteStmt( stmt::Demote * stmt )override
		{
			addStatement( "Demote" );
		}

		void visitDispatchMeshStmt( stmt::DispatchMesh * stmt )override
		{
			addStatement( "DispatchMesh "
				+ doSubmit( stmt->getNumGroupsX() ) + ", "
				+ doSubmit( stmt->getNumGroupsY() ) + ", "
				+ doSubmit( stmt->getNumGroupsZ() ) + ", "
				+ doSubmit( stmt->getPayload() ) );
		}

		void visitTerminateInvocationStmt( stmt::TerminateInvocation * stmt )override
		{
			addStatement( "Terminate" );
		}

		void visitDoWhileStmt( stmt::DoWhile * stmt )override
		{
			addStatement( "Do" );
			visitCompoundStmt( stmt );
			addStatement( "While (" + doSubmit( stmt->getCtrlExpr() ) + ")" );
		}

		void visitElseIfStmt( stmt::ElseIf * stmt )override
		{
			addStatement( "ElseIf (" + doSubmit( stmt->getCtrlExpr() ) + ")" );
			visitCompoundStmt( stmt );
		}

		void visitElseStmt( stmt::Else * stmt )override
		{
			addStatement( "Else" );
			visitCompoundStmt( stmt );
		}

		void visitForStmt( stmt::For * stmt )override
		{
			addStatement( "For ("
				+ doSubmit( stmt->getInitExpr() ) + ", "
				+ doSubmit( stmt->getCtrlExpr() ) + ", "
				+ doSubmit( stmt->getIncrExpr() ) + ")" );
			visitCompoundStmt( stmt );
		}

		void visitFragmentLayoutStmt( stmt::FragmentLayout * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[Origin=" + helpers::getOriginName( stmt->getFragmentOrigin() ) + ", Center=" + helpers::getCenterName( stmt->getFragmentCenter() ) + "]" );
		}

		void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override
		{
			std::string text;
			auto type = stmt->getType();
			declareStruct( type->getReturnType() );
			text += helpers::getTypeName( *type->getReturnType() );
			text += " " + stmt->getName() + "(";
			std::string sep;

			for ( auto & param : *type )
			{
				declareStruct( param->getType() );
				text += sep;
				text += helpers::displayVar( param );
				sep = ", ";
			}

			text += ")";
			addStatement( std::move( text ) );
			visitCompoundStmt( stmt );
		}

		void visitIfStmt( stmt::If * stmt )override
		{
			addStatement( "If (" + doSubmit( stmt->getCtrlExpr() ) + ")" );
			visitCompoundStmt( stmt );

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
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( helpers::displayVar( stmt->getVariable() ) );
		}

		void visitIgnoreIntersectionStmt( stmt::IgnoreIntersection * stmt )override
		{
			addStatement( "IgnoreIntersection" );
		}

		void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override
		{
			declareStruct( stmt->getVariable()->getType() );
			std::string text = "[";

			if ( stmt->getVariable()->isShaderConstant() )
			{
				text += "Const, Location=";
			}
			else if ( stmt->getVariable()->isPushConstant() )
			{
				text += "Push, Location=";
			}
			else if ( stmt->getVariable()->isShaderInput()
				|| stmt->getVariable()->isShaderOutput() )
			{
				text += "Location=";
			}

			text += std::to_string( stmt->getLocation() );

			if ( stmt->getVariable()->isBlendIndex() )
			{
				text += ", BlendIndex=" + std::to_string( stmt->getBlendIndex() );
			}

			if ( stmt->getVariable()->isGeometryStream() )
			{
				text += ", StreamIndex=" + std::to_string( stmt->getStreamIndex() );
			}

			text += "]";
			addStatement( std::move( text ) );
			addStatement( "InOutVariable " + helpers::displayVar( stmt->getVariable() ) );
		}

		void visitSpecialisationConstantDeclStmt( stmt::SpecialisationConstantDecl * stmt )override
		{
			declareStruct( stmt->getVariable()->getType() );
			addStatement( "[Location=" + std::to_string( stmt->getLocation() ) + "]" );
			addStatement( "SpecialisationConstant " + helpers::displayVar( stmt->getVariable() ) + "=" + doSubmit( stmt->getValue() ) );
		}

		void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[X=" + std::to_string( stmt->getWorkGroupsX() )
				+ ", Y(" + std::to_string( stmt->getWorkGroupsY() )
				+ ", Z(" + std::to_string( stmt->getWorkGroupsZ() ) + "]" );
			addStatement( "Compute" );
		}

		void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[Layout=" + helpers::getInputLayoutName( stmt->getLayout() ) + "]" );
			addStatement( "GeometryInput" );
		}

		void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[Domain=" + helpers::getDomainName( stmt->getDomain() )
				+ ", Partitioning=" + helpers::getPartitioningName( stmt->getPartitioning() )
				+ ", Oredering=" + helpers::getOrderingName( stmt->getPrimitiveOrdering() ) + "]" );
			addStatement( "TessEvalInput" );
		}

		void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[Layout=" + helpers::getOutputLayoutName( stmt->getLayout() )
				+ ", Count=" + std::to_string( stmt->getPrimCount() ) + "]" );
			addStatement( "GeometryOutput" );
		}

		void visitOutputMeshLayoutStmt( stmt::OutputMeshLayout * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[Topology=" + helpers::getTopologyName( stmt->getTopology() )
				+ ", MaxVertices=" + std::to_string( stmt->getMaxVertices() )
				+ ", MaxPrimitives=" + std::to_string( stmt->getMaxPrimitives() ) + "]" );
			addStatement( "MeshOutput" );
		}

		void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[Domain=" + helpers::getDomainName( stmt->getDomain() )
				+ ", Partitioning" + helpers::getPartitioningName( stmt->getPartitioning() )
				+ ", Topology=" + helpers::getTopologyName( stmt->getTopology() )
				+ ", Ordering=" + helpers::getOrderingName( stmt->getPrimitiveOrdering() )
				+ ", Vertices=(" + std::to_string( stmt->getOutputVertices() ) + "]" );
			addStatement( "TessControlOutput" );
		}

		void visitPerPrimitiveDeclStmt( stmt::PerPrimitiveDecl * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "PerPrimitive " + getTypeName( stmt->getType() ) );
		}

		void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override
		{
			declareStruct( stmt->getType() );
			std::string text = "PerVertex [";

			switch ( stmt->getSource() )
			{
			case stmt::PerVertexDecl::Source::eVertexOutput:
				text += "VertOut";
				break;
			case stmt::PerVertexDecl::Source::eTessellationControlInput:
				text += "TessControlIn";
				break;
			case stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
				text += "TessEvalIn";
				break;
			case stmt::PerVertexDecl::Source::eTessellationControlOutput:
				text += "TessControlOut";
				break;
			case stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
				text += "TessEvalOut";
				break;
			case stmt::PerVertexDecl::Source::eGeometryInput:
				text += "GeomIn";
				break;
			case stmt::PerVertexDecl::Source::eGeometryOutput:
				text += "GeomOut";
				break;
			case stmt::PerVertexDecl::Source::eMeshOutput:
				text += "MeshOut";
				break;
			}

			addStatement( text + "]" + getTypeName( stmt->getType() ) );
		}

		void visitPushConstantsBufferDeclStmt( stmt::PushConstantsBufferDecl * stmt )override
		{
			addStatement( "PushContants " + stmt->getName() );
			visitCompoundStmt( stmt );
		}

		void visitHitAttributeVariableDeclStmt( stmt::HitAttributeVariableDecl * stmt )override
		{
			declareStruct( stmt->getVariable()->getType() );
			addStatement( "HitAttribute " + helpers::displayVar( stmt->getVariable() ) );
		}

		void visitInOutCallableDataVariableDeclStmt( stmt::InOutCallableDataVariableDecl * stmt )override
		{
			declareStruct( stmt->getVariable()->getType() );
			addStatement( "[Loc=" + std::to_string( stmt->getLocation() ) + "]" );
			addStatement( "Callable " + helpers::displayVar( stmt->getVariable() ) );
		}

		void visitInOutRayPayloadVariableDeclStmt( stmt::InOutRayPayloadVariableDecl * stmt )override
		{
			declareStruct( stmt->getVariable()->getType() );
			addStatement( "[Loc=" + std::to_string( stmt->getLocation() ) + "]" );
			addStatement( "RayPayload " + helpers::displayVar( stmt->getVariable() ) );
		}

		void visitReturnStmt( stmt::Return * stmt )override
		{
			std::string text;

			if ( stmt->getExpr() )
			{
				declareStruct( stmt->getExpr()->getType() );
				text += " " + doSubmit( stmt->getExpr() );
			}

			addStatement( "Return" + text );
		}

		void visitCombinedImageDeclStmt( stmt::CombinedImageDecl * stmt )override
		{
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( helpers::displayVar( stmt->getVariable() ) );
			m_result += "\n";
		}

		void visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )override
		{
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( helpers::displayVar( stmt->getVariable() ) );
		}

		void visitSamplerDeclStmt( stmt::SamplerDecl * stmt )override
		{
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( helpers::displayVar( stmt->getVariable() ) );
		}

		void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override
		{
			declareStruct( stmt->getType() );
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( "[Layout=" + helpers::getMemoryLayoutName( stmt->getMemoryLayout() ) + "]" );
			addStatement( "StorageBuffer " + stmt->getSsboName() + " " + helpers::displayVar( stmt->getVariable() ) );
			visitCompoundStmt( stmt );
		}

		void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )override
		{
			declareStruct( stmt->getSsboInstance()->getType() );
			declareStruct( stmt->getData()->getType() );
			addStatement( "[Binding=" + std::to_string( stmt->getBindingPoint() ) + ", Set=" + std::to_string( stmt->getDescriptorSet() ) + "]" );
			addStatement( "[Layout=" + helpers::getMemoryLayoutName( stmt->getMemoryLayout() ) + "]" );
			addStatement( "StorageBuffer " + stmt->getSsboName() + " " + helpers::displayVar( stmt->getSsboInstance() ) );
			addStatement( "BufferInstance " + helpers::displayVar( stmt->getData() ) );
		}

		void visitSimpleStmt( stmt::Simple * stmt )override
		{
			addStatement( doSubmit( stmt->getExpr() ) );
		}

		void visitStructureDeclStmt( stmt::StructureDecl * stmt )override
		{
			declareStruct( stmt->getType() );
		}

		void visitSwitchCaseStmt( stmt::SwitchCase * stmt )override
		{
			if ( stmt->getCaseExpr() )
			{
				addStatement( "Case " + doSubmit( stmt->getCaseExpr() ) );
			}
			else
			{
				addStatement( "Default" );
			}

			if ( !stmt->empty() )
			{
				visitCompoundStmt( stmt );
			}
		}

		void visitSwitchStmt( stmt::Switch * stmt )override
		{
			addStatement( "Switch " + doSubmit( stmt->getTestExpr() ) );
			visitCompoundStmt( stmt );
		}

		void visitTerminateRayStmt( stmt::TerminateRay * stmt )override
		{
			addStatement( "TerminateRay" );
		}

		void visitVariableDeclStmt( stmt::VariableDecl * stmt )override
		{
			declareStruct( stmt->getVariable()->getType() );
			addStatement( helpers::displayVar( stmt->getVariable() ) );
		}

		void visitWhileStmt( stmt::While * stmt )override
		{
			addStatement( "While (" + doSubmit( stmt->getCtrlExpr() ) + ")" );
			visitCompoundStmt( stmt );
		}

		void visitPreprocExtension( stmt::PreprocExtension * preproc )override
		{
			std::string type;

			switch ( preproc->getStatus() )
			{
			case stmt::PreprocExtension::ExtStatus::eDisabled:
				type += ": Disabled";
				break;

			case stmt::PreprocExtension::ExtStatus::eEnabled:
				type += ": Enabled";
				break;

			case stmt::PreprocExtension::ExtStatus::eRequired:
				type += ": Required";
				break;

			}

			addStatement( "ppExtension " + preproc->getName() + type );
		}

		void visitPreprocVersion( stmt::PreprocVersion * preproc )override
		{
			addStatement( "ppVersion " + preproc->getName() );
		}

	private:
		std::string m_indent;
		std::string& m_result;
		std::unordered_set< std::string > m_declaredStructs;
	};

	std::string displayStatements( stmt::Stmt * stmt )
	{
		return StmtVisitor::submit( stmt );
	}

	std::string displayExpression( expr::Expr * expr )
	{
		return ExprVisitor::submit( expr );
	}

	std::string getTypeName( type::TypePtr type )
	{
		return helpers::getTypeName( *type );
	}

	std::string getTypeName( type::Kind kind )
	{
		return helpers::getTypeName( kind );
	}

	std::string getImageFormatName( type::ImageFormat value )
	{
		return helpers::getImageFormatName( value );
	}

	std::string getImageTypeName( ast::type::ImageFormat format
		, ast::type::ImageDim dim
		, bool arrayed
		, bool ms
		, bool depth )
	{
		return helpers::getImageTypeName( format
			, dim
			, arrayed
			, ms
			, depth );
	}

	std::string getImageTypeName( ast::type::ImageFormat format
		, ast::type::ImageDim dim
		, bool arrayed
		, bool ms )
	{
		return helpers::getImageTypeName( format
			, dim
			, arrayed
			, ms );
	}

	std::string getImageTypeName( ast::type::ImageFormat format
		, ast::type::AccessKind access
		, ast::type::ImageDim dim
		, bool arrayed
		, bool ms )
	{
		return helpers::getImageTypeName( format
			, access
			, dim
			, arrayed
			, ms );
	}
}
