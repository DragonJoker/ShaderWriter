/*
See LICENSE file in root folder
*/
#include "GenerateGlslStatements.hpp"

#include "GlslStatementsHelpers.hpp"
#include "GlslCombinedImageAccessNames.hpp"
#include "GlslIntrinsicNames.hpp"
#include "GlslStorageImageAccessNames.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <iomanip>
#include <sstream>
#pragma warning( pop )

namespace glsl
{
	namespace gstvis
	{
		//*****************************************************************************************

		namespace helpers
		{
			static uint32_t constexpr InvalidIndex = ~( 0u );

			static std::string adaptName( std::string const & name
				, StmtConfig const & writerConfig )
			{
				if ( writerConfig.vulkanGlsl )
				{
					static std::map< std::string, std::string > const toVkNames
					{
						{ "gl_InstanceID", "gl_InstanceIndex" },
						{ "gl_VertexID", "gl_VertexIndex" },
						{ "gl_DrawIndex", "gl_DrawID" },
						{ "gl_LaunchID", "gl_LaunchIDEXT" },
						{ "gl_LaunchSize", "gl_LaunchSizeEXT" },
						{ "gl_InstanceCustomIndex", "gl_InstanceCustomIndexEXT" },
						{ "gl_GeometryIndex", "gl_GeometryIndexEXT" },
						{ "gl_WorldRayOrigin", "gl_WorldRayOriginEXT" },
						{ "gl_WorldRayDirection", "gl_WorldRayDirectionEXT" },
						{ "gl_ObjectRayOrigin", "gl_ObjectRayOriginEXT" },
						{ "gl_ObjectRayDirection", "gl_ObjectRayDirectionEXT" },
						{ "gl_RayTmin", "gl_RayTminEXT" },
						{ "gl_RayTmax", "gl_RayTmaxEXT" },
						{ "gl_IncomingRayFlags", "gl_IncomingRayFlagsEXT" },
						{ "gl_HitKind", "gl_HitKindEXT" },
						{ "gl_ObjectToWorld", "gl_ObjectToWorldEXT" },
						{ "gl_WorldToObject", "gl_WorldToObjectEXT" },
						{ "gl_SubgroupLocalInvocationID", "gl_SubgroupInvocationID" },
					};
					auto it = toVkNames.find( name );

					if ( it != toVkNames.end() )
					{
						return it->second;
					}
				}
				else
				{
					static std::map< std::string, std::string > const toGlNames
					{
						{ "gl_InstanceIndex", "gl_InstanceID" },
						{ "gl_VertexIndex", "gl_VertexID" },
						{ "gl_DrawIndex", "gl_DrawID" },
						{ "gl_LaunchID", "gl_LaunchIDEXT" },
						{ "gl_LaunchSize", "gl_LaunchSizeEXT" },
						{ "gl_InstanceCustomIndex", "gl_InstanceCustomIndexEXT" },
						{ "gl_GeometryIndex", "gl_GeometryIndexEXT" },
						{ "gl_WorldRayOrigin", "gl_WorldRayOriginEXT" },
						{ "gl_WorldRayDirection", "gl_WorldRayDirectionEXT" },
						{ "gl_ObjectRayOrigin", "gl_ObjectRayOriginEXT" },
						{ "gl_ObjectRayDirection", "gl_ObjectRayDirectionEXT" },
						{ "gl_RayTmin", "gl_RayTminEXT" },
						{ "gl_RayTmax", "gl_RayTmaxEXT" },
						{ "gl_IncomingRayFlags", "gl_IncomingRayFlagsEXT" },
						{ "gl_HitKind", "gl_HitKindEXT" },
						{ "gl_ObjectToWorld", "gl_ObjectToWorldEXT" },
						{ "gl_WorldToObject", "gl_WorldToObjectEXT" },
						{ "gl_SubgroupLocalInvocationID", "gl_SubgroupInvocationID" },
					};
					auto it = toGlNames.find( name );

					if ( it != toGlNames.end() )
					{
						return it->second;
					}
				}

				return name;
			}

			static std::string getBuiltinName( ast::Builtin builtin )
			{
				switch ( builtin )
				{
				case ast::Builtin::ePosition:
					return "gl_Position";
				case ast::Builtin::ePointSize:
					return "gl_PointSize";
				case ast::Builtin::eClipDistance:
					return "gl_ClipDistance";
				case ast::Builtin::eCullDistance:
					return "gl_CullDistance";
				case ast::Builtin::ePrimitiveID:
					return "gl_PrimitiveID";
				case ast::Builtin::ePrimitiveIDIn:
					return "gl_PrimitiveIDIn";
				case ast::Builtin::eInvocationID:
					return "gl_InvocationID";
				case ast::Builtin::eLayer:
					return "gl_Layer";
				case ast::Builtin::eViewportIndex:
					return "gl_ViewportIndex";
				case ast::Builtin::eTessLevelOuter:
					return "gl_TessLevelOuter";
				case ast::Builtin::eTessLevelInner:
					return "gl_TessLevelInner";
				case ast::Builtin::eTessCoord:
					return "gl_TessCoord";
				case ast::Builtin::ePatchVertices:
					return "gl_PatchVertices";
				case ast::Builtin::ePatchVerticesIn:
					return "gl_PatchVerticesIn";
				case ast::Builtin::eFragCoord:
					return "gl_FragCoord";
				case ast::Builtin::ePointCoord:
					return "gl_PointCoord";
				case ast::Builtin::eFrontFacing:
					return "gl_FrontFacing";
				case ast::Builtin::eSampleID:
					return "gl_SampleID";
				case ast::Builtin::eSamplePosition:
					return "gl_SamplePosition";
				case ast::Builtin::eSampleMask:
					return "gl_SampleMask";
				case ast::Builtin::eSampleMaskIn:
					return "gl_SampleMaskIn";
				case ast::Builtin::eFragDepth:
					return "gl_FragDepth";
				case ast::Builtin::eHelperInvocation:
					return "gl_HelperInvocation";
				case ast::Builtin::eNumWorkGroups:
					return "gl_NumWorkGroups";
				case ast::Builtin::eWorkGroupSize:
					return "gl_WorkGroupSize";
				case ast::Builtin::eWorkGroupID:
					return "gl_WorkGroupID";
				case ast::Builtin::eLocalInvocationID:
					return "gl_LocalInvocationID";
				case ast::Builtin::eGlobalInvocationID:
					return "gl_GlobalInvocationID";
				case ast::Builtin::eLocalInvocationIndex:
					return "gl_LocalInvocationIndex";
				case ast::Builtin::eWorkDim:
					return "gl_WorkDim";
				case ast::Builtin::eGlobalSize:
					return "gl_GlobalSize";
				case ast::Builtin::eEnqueuedWorkgroupSize:
					return "gl_EnqueuedWorkgroupSize";
				case ast::Builtin::eGlobalLinearID:
					return "gl_GlobalLinearID";
				case ast::Builtin::eSubgroupSize:
					return "gl_SubgroupSize";
				case ast::Builtin::eSubgroupMaxSize:
					return "gl_SubgroupMaxSize";
				case ast::Builtin::eNumSubgroups:
					return "gl_NumSubgroups";
				case ast::Builtin::eNumEnqueuedSubgroups:
					return "gl_NumEnqueuedSubgroups";
				case ast::Builtin::eSubgroupID:
					return "gl_SubgroupID";
				case ast::Builtin::eSubgroupLocalInvocationID:
					return "gl_SubgroupLocalInvocationID";
				case ast::Builtin::eVertexIndex:
					return "gl_VertexIndex";
				case ast::Builtin::eInstanceIndex:
					return "gl_InstanceIndex";
				case ast::Builtin::eInstanceID:
					return "gl_InstanceID";
				case ast::Builtin::eSubgroupEqMask:
					return "gl_SubgroupEqMask";
				case ast::Builtin::eSubgroupGeMask:
					return "gl_SubgroupGeMask";
				case ast::Builtin::eSubgroupGtMask:
					return "gl_SubgroupGtMask";
				case ast::Builtin::eSubgroupLeMask:
					return "gl_SubgroupLeMask";
				case ast::Builtin::eSubgroupLtMask:
					return "gl_SubgroupLtMask";
				case ast::Builtin::eBaseVertex:
					return "gl_BaseVertex";
				case ast::Builtin::eBaseInstance:
					return "gl_BaseInstance";
				case ast::Builtin::eDrawIndex:
					return "gl_DrawIndex";
				case ast::Builtin::eDeviceIndex:
					return "gl_DeviceIndex";
				case ast::Builtin::eViewIndex:
					return "gl_ViewIndex";
				case ast::Builtin::eBaryCoordNoPerspAMD:
					return "gl_BaryCoordNoPerspAMD";
				case ast::Builtin::eBaryCoordNoPerspCentroidAMD:
					return "gl_BaryCoordNoPerspCentroidAMD";
				case ast::Builtin::eBaryCoordNoPerspSampleAMD:
					return "gl_BaryCoordNoPerspSampleAMD";
				case ast::Builtin::eBaryCoordSmoothAMD:
					return "gl_BaryCoordSmoothAMD";
				case ast::Builtin::eBaryCoordSmoothCentroidAMD:
					return "gl_BaryCoordSmoothCentroidAMD";
				case ast::Builtin::eBaryCoordSmoothSampleAMD:
					return "gl_BaryCoordSmoothSampleAMD";
				case ast::Builtin::eBaryCoordPullModelAMD:
					return "gl_BaryCoordPullModelAMD";
				case ast::Builtin::eFragStencilRefEXT:
					return "gl_FragStencilRefEXT";
				case ast::Builtin::eViewportMaskNV:
					return "gl_ViewportMaskNV";
				case ast::Builtin::eSecondaryPositionNV:
					return "gl_SecondaryPositionNV";
				case ast::Builtin::eSecondaryViewportMaskNV:
					return "gl_SecondaryViewportMaskNV";
				case ast::Builtin::ePositionPerViewNV:
					return "gl_PositionPerViewNV";
				case ast::Builtin::eViewportMaskPerViewNV:
					return "gl_ViewportMaskPerViewNV";
				case ast::Builtin::ePrimitiveIndicesNV:
					return "gl_PrimitiveIndicesNV";
				case ast::Builtin::ePrimitiveCountNV:
					return "gl_PrimitiveCountNV";
				case ast::Builtin::eTaskCountNV:
					return "gl_TaskCountNV";
				case ast::Builtin::eClipDistancePerViewNV:
					return "gl_ClipDistancePerViewNV";
				case ast::Builtin::eCullDistancePerViewNV:
					return "gl_CullDistancePerViewNV";
				case ast::Builtin::eLayerPerViewNV:
					return "gl_LayerPerViewNV";
				case ast::Builtin::eMeshViewCountNV:
					return "gl_MeshViewCountNV";
				case ast::Builtin::eMeshViewIndicesNV:
					return "gl_MeshViewIndicesNV";
				case ast::Builtin::eLaunchID:
					return "gl_LaunchID";
				case ast::Builtin::eLaunchSize:
					return "gl_LaunchSize";
				case ast::Builtin::eInstanceCustomIndex:
					return "gl_InstanceCustomIndex";
				case ast::Builtin::eGeometryIndex:
					return "gl_GeometryIndex";
				case ast::Builtin::eWorldRayOrigin:
					return "gl_WorldRayOrigin";
				case ast::Builtin::eWorldRayDirection:
					return "gl_WorldRayDirection";
				case ast::Builtin::eObjectRayOrigin:
					return "gl_ObjectRayOrigin";
				case ast::Builtin::eObjectRayDirection:
					return "gl_ObjectRayDirection";
				case ast::Builtin::eRayTmin:
					return "gl_RayTmin";
				case ast::Builtin::eRayTmax:
					return "gl_RayTmax";
				case ast::Builtin::eIncomingRayFlags:
					return "gl_IncomingRayFlags";
				case ast::Builtin::eHitKind:
					return "gl_HitKind";
				case ast::Builtin::eObjectToWorld:
					return "gl_ObjectToWorld";
				case ast::Builtin::eWorldToObject:
					return "gl_WorldToObject";
				case ast::Builtin::ePrimitivePointIndices:
					return "gl_PrimitivePointIndices";
				case ast::Builtin::ePrimitiveLineIndices:
					return "gl_PrimitiveLineIndices";
				case ast::Builtin::ePrimitiveTriangleIndices:
					return "gl_PrimitiveTriangleIndices";
				case ast::Builtin::eCullPrimitive:
					return "gl_CullPrimitive";
				default:
					return "gl_Unknown";
				}
			}

			static std::string getTypeArraySize( ast::type::TypePtr type );

			static std::string getTypeArraySize( ast::type::ArrayPtr type )
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
						result += "[" + writeValue( arraySize ) + "]";
					}
				}

				return getTypeArraySize( type->getType() ) + result;
			}

			static std::string getDimension( ast::type::ImageDim value )
			{
				switch ( value )
				{
				case ast::type::ImageDim::e1D:
					return "1D";
				case ast::type::ImageDim::e2D:
					return "2D";
				case ast::type::ImageDim::e3D:
					return "3D";
				case ast::type::ImageDim::eCube:
					return "Cube";
				case ast::type::ImageDim::eRect:
					return "2DRect";
				case ast::type::ImageDim::eBuffer:
					return "Buffer";
				default:
					AST_Failure( "Unsupported ast::type::ImageDim" );
					return "Undefined";
				}
			}

			static std::string getPrefix( ast::type::Kind value )
			{
				switch ( value )
				{
				case ast::type::Kind::eInt8:
					return "i8";
				case ast::type::Kind::eInt16:
					return "i16";
				case ast::type::Kind::eInt32:
					return "i";
				case ast::type::Kind::eInt64:
					return "i64";
				case ast::type::Kind::eUInt8:
					return "u8";
				case ast::type::Kind::eUInt16:
					return "u16";
				case ast::type::Kind::eUInt32:
					return "u";
				case ast::type::Kind::eUInt64:
					return "ul";
				case ast::type::Kind::eFloat:
					return std::string{};
				case ast::type::Kind::eHalf:
					return "h";
				default:
					AST_Failure( "Unsupported ast::type::Kind" );
					return std::string{};
				}
			}

			static std::string getArray( bool value )
			{
				return value
					? "Array"
					: std::string{};
			}

			static std::string getMS( bool value )
			{
				return value
					? "MS"
					: std::string{};
			}

			static std::string getType( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config )
			{
				return ( kind == ast::type::Kind::eImage )
					? "image"
					: ( ( kind == ast::type::Kind::eSampledImage )
						? "texture"
						: "sampler" );
			}

			static std::string getShadow( bool isComparison )
			{
				return isComparison
					? "Shadow"
					: std::string{};
			}

			static std::string getShadow( ast::type::Trinary comparison )
			{
				return comparison == ast::type::Trinary::eTrue
					? "Shadow"
					: std::string{};
			}

			static std::string getTypeArraySize( ast::type::TypePtr type )
			{
				std::string result;

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					result = getTypeArraySize( std::static_pointer_cast< ast::type::Array >( type ) );
				}

				return result;
			}

			static std::string getInterpolationQualifier( ast::var::Variable const & var )
			{
				std::string result;

				if ( var.isFlat() )
				{
					result = "flat";
				}
				else if ( var.isNoPerspective() )
				{
					result = "noperspective";
				}
				else if ( var.isPatchInput()
					|| var.isPatchOutput() )
				{
					result = "patch";
				}
				else if ( var.isCentroid() )
				{
					result = "centroid";
				}
				else if ( var.isPerSample() )
				{
					result = "sample";
				}
				else if ( var.isShared() )
				{
					result = "shared";
				}
				else if ( var.isPerPrimitive() )
				{
					result = "perprimitiveEXT";
				}

				return result;
			}

			static std::string getLocationName( ast::var::Variable const & var )
			{
				std::string result;

				if ( var.isShaderConstant() )
				{
					result = "constant_id";
				}
				else if ( var.isShaderInput()
					|| var.isShaderOutput()
					|| var.isPatchOutput()
					|| var.isPatchInput() )
				{
					result = "location";
				}

				return result;
			}

			static std::string getAccessQualifierName( ast::type::ImageConfiguration const & config )
			{
				std::string result;

				if ( config.accessKind == ast::type::AccessKind::eRead )
				{
					result = "readonly";
				}
				else if ( config.accessKind == ast::type::AccessKind::eWrite )
				{
					result = "writeonly";
				}
				else
				{
					result = "readonly writeonly";
				}

				return result;
			}

			static std::string getDirectionName( ast::var::Variable const & var )
			{
				std::string result;

				if ( isOpaqueType( var.getType() ) )
				{
					if ( isImageType( var.getType()->getKind() ) )
					{
						auto & imageType = static_cast< ast::type::Image const & >( *var.getType() );
						return getAccessQualifierName( imageType.getConfig() );
					}

					return result;
				}

				if ( var.isInputParam()
					&& var.isOutputParam() )
				{
					result = "inout";
				}
				else if ( var.isInputParam()
					|| var.isShaderInput()
					|| var.isPatchInput() )
				{
					result = "in";
				}
				else if ( var.isOutputParam()
					|| var.isShaderOutput()
					|| var.isPatchOutput() )
				{
					result = "out";
				}
				else if ( var.isShaderConstant() )
				{
					result = "const";
				}

				return result;
			}

			static std::string getFormatName( ast::type::ImageFormat format )
			{
				switch ( format )
				{
				case ast::type::ImageFormat::eUnknown:
					return "rgba32f";
				case ast::type::ImageFormat::eRgba32f:
					return "rgba32f";
				case ast::type::ImageFormat::eRgba16f:
					return "rgba16f";
				case ast::type::ImageFormat::eRg32f:
					return "rg32f";
				case ast::type::ImageFormat::eRg16f:
					return "rg16f";
				case ast::type::ImageFormat::eR32f:
					return "r32f";
				case ast::type::ImageFormat::eR16f:
					return "r16f";
				case ast::type::ImageFormat::eRgba32i:
					return "rgba32i";
				case ast::type::ImageFormat::eRgba16i:
					return "rgba16i";
				case ast::type::ImageFormat::eRgba8i:
					return "rgba8i";
				case ast::type::ImageFormat::eRg32i:
					return "rg32i";
				case ast::type::ImageFormat::eRg16i:
					return "rg16i";
				case ast::type::ImageFormat::eRg8i:
					return "rg8i";
				case ast::type::ImageFormat::eR32i:
					return "r32i";
				case ast::type::ImageFormat::eR16i:
					return "r16i";
				case ast::type::ImageFormat::eR8i:
					return "r8i";
				case ast::type::ImageFormat::eRgba32u:
					return "rgba32ui";
				case ast::type::ImageFormat::eRgba16u:
					return "rgba16ui";
				case ast::type::ImageFormat::eRgba8u:
					return "rgba8ui";
				case ast::type::ImageFormat::eRg32u:
					return "rg32ui";
				case ast::type::ImageFormat::eRg16u:
					return "rg16ui";
				case ast::type::ImageFormat::eRg8u:
					return "rg8ui";
				case ast::type::ImageFormat::eR32u:
					return "r32ui";
				case ast::type::ImageFormat::eR16u:
					return "r16ui";
				case ast::type::ImageFormat::eR8u:
					return "r8ui";
				default:
					AST_Failure( "Unsupported ast::type::ImageFormat" );
					return "rgba32f";
				}
			}

			static std::string getMemoryLayoutName( ast::type::MemoryLayout layout )
			{
				switch ( layout )
				{
				case ast::type::MemoryLayout::eStd140:
				case ast::type::MemoryLayout::eC:
					return "std140";
				case ast::type::MemoryLayout::eStd430:
					return "std430";
				case ast::type::MemoryLayout::eScalar:
					return "scalar";
				default:
					AST_Failure( "Unsupported ast::type::MemoryLayout" );
					return "std140";
				}
			}

			static bool hasExtension( StmtConfig const & config
				, GlslExtension const & extension )
			{
				return config.availableExtensions.end() != config.availableExtensions.find( extension );
			}

			static std::string getInOutLayout( StmtConfig const & config
				, ast::stmt::InOutVariableDecl const & stmt )
			{
				std::string result = "layout(";
				std::string sep;

				if ( hasExtension( config, ARB_explicit_attrib_location )
					&& hasExtension( config, ARB_separate_shader_objects ) )
				{
					result += getLocationName( *stmt.getVariable() ) + "=" + writeValue( stmt.getLocation() );
					sep = ", ";
				}

				if ( config.shaderStage == ast::ShaderStage::eGeometry
					&& stmt.getVariable()->isGeometryStream() )
				{
					result += sep + "stream=" + writeValue( stmt.getStreamIndex() );
					sep = ", ";
				}

				if ( config.shaderStage == ast::ShaderStage::eFragment
					&& stmt.getVariable()->isBlendIndex() )
				{
					result += sep + "index=" + writeValue( stmt.getBlendIndex() );
				}

				result += ")";

				if ( result == "layout()" )
				{
					result.clear();
				}

				return result;
			}

			static std::string getLayoutName( ast::FragmentOrigin value )
			{
				switch ( value )
				{
				case ast::FragmentOrigin::eLowerLeft:
					return "origin_lower_left";
				case ast::FragmentOrigin::eUpperLeft:
					return "origin_upper_left";
				default:
					AST_Failure( "Unsupported FragmentOrigin" );
					return std::string{};
				}
			}

			static std::string getLayoutName( ast::FragmentCenter value )
			{
				switch ( value )
				{
				case ast::FragmentCenter::eHalfPixel:
					return std::string{};
				case ast::FragmentCenter::eCenterInteger:
					return "pixel_center_integer";
				default:
					AST_Failure( "Unsupported FragmentCenter" );
					return std::string{};
				}
			}

			static std::string getOperatorName( ast::expr::Kind kind )
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
					result = "cast";
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

			static std::string getLayoutName( ast::type::InputLayout layout )
			{
				std::string result;

				switch ( layout )
				{
				case ast::type::InputLayout::ePointList:
					result = "points";
					break;
				case ast::type::InputLayout::eLineList:
					result = "lines";
					break;
				case ast::type::InputLayout::eLineStrip:
					result = "lines";
					break;
				case ast::type::InputLayout::eTriangleList:
					result = "triangles";
					break;
				case ast::type::InputLayout::eTriangleStrip:
					result = "triangles";
					break;
				case ast::type::InputLayout::eTriangleFan:
					result = "triangles";
					break;
				case ast::type::InputLayout::eLineListWithAdjacency:
					result = "lines_adjacency";
					break;
				case ast::type::InputLayout::eLineStripWithAdjacency:
					result = "lines_adjacency";
					break;
				case ast::type::InputLayout::eTriangleListWithAdjacency:
					result = "triangles_adjacency";
					break;
				case ast::type::InputLayout::eTriangleStripWithAdjacency:
					result = "triangles_adjacency";
					break;
				default:
					throw std::runtime_error{ "Unsupported input layout." };
				}

				return result;
			}

			static std::string getLayoutName( ast::type::OutputLayout layout )
			{
				std::string result;

				switch ( layout )
				{
				case ast::type::OutputLayout::ePointList:
					result = "points";
					break;
				case ast::type::OutputLayout::eLineStrip:
					result = "line_strip";
					break;
				case ast::type::OutputLayout::eTriangleStrip:
					result = "triangle_strip";
					break;
				default:
					throw std::runtime_error{ "Unsupported output layout." };
				}

				return result;
			}

			static std::string getLayoutName( ast::type::PatchDomain value )
			{
				switch ( value )
				{
				case ast::type::PatchDomain::eIsolines:
					return "isolines";
				case ast::type::PatchDomain::eTriangles:
					return "triangles";
				case ast::type::PatchDomain::eQuads:
					return "quads";
				default:
					throw std::runtime_error{ "Unsupported ast::type::PatchDomain." };
				}
			}

			static std::string getLayoutName( ast::type::PrimitiveOrdering value )
			{
				switch ( value )
				{
				case ast::type::PrimitiveOrdering::eCW:
					return "cw";
				case ast::type::PrimitiveOrdering::eCCW:
					return "ccw";
				default:
					throw std::runtime_error{ "Unsupported ast::type::PatchDomain." };
				}
			}

			static std::string getLayoutName( ast::type::Partitioning value )
			{
				switch ( value )
				{
				case ast::type::Partitioning::eEqual:
					return "equal_spacing";
				case ast::type::Partitioning::eFractionalEven:
					return "fractional_even_spacing";
				case ast::type::Partitioning::eFractionalOdd:
					return "fractional_odd_spacing";
				default:
					throw std::runtime_error{ "Unsupported ast::type::Partitioning." };
				}
			}

			static std::string getLayoutName( ast::type::OutputTopology value )
			{
				switch ( value )
				{
				case ast::type::OutputTopology::ePoint:
					return "points";
				case ast::type::OutputTopology::eLine:
					return "lines";
				case ast::type::OutputTopology::eTriangle:
					return "triangles";
				case ast::type::OutputTopology::eQuad:
					return "quads";
				default:
					throw std::runtime_error{ "Unsupported ast::type::OutputTopology." };
				}
			}

			static std::string getQualifiedName( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config )
			{
				return getPrefix( config.sampledType )
					+ getType( kind, config )
					+ getDimension( config.dimension )
					+ getMS( config.isMS )
					+ getArray( config.isArrayed );
			}

			static std::string getQualifiedName( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config
				, bool isComparison )
			{
				return getQualifiedName( kind, config )
					+ getShadow( isComparison );
			}

			static std::string getQualifiedName( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config
				, ast::type::Trinary comparison )
			{
				return getQualifiedName( kind, config )
					+ getShadow( comparison );
			}

			static std::string getStatusName( ast::stmt::PreprocExtension::ExtStatus status )
			{
				std::string result;

				switch ( status )
				{
				case ast::stmt::PreprocExtension::ExtStatus::eDisabled:
					result = "disable";
					break;

				case ast::stmt::PreprocExtension::ExtStatus::eEnabled:
					result = "enable";
					break;

				case ast::stmt::PreprocExtension::ExtStatus::eRequired:
					result = "require";
					break;

				}

				return result;
			}

			static std::string printVersion( uint32_t major = MAIN_VERSION_MAJOR
				, uint32_t minor = MAIN_VERSION_MINOR
				, uint32_t build = MAIN_VERSION_BUILD
				, uint32_t year = MAIN_VERSION_YEAR )
			{
				std::stringstream stream;
				stream.imbue( std::locale{ "C" } );
				stream << major << "." << minor << "." << build << "-" << year;
				return stream.str();
			}

			static void join( std::string & lhs
				, std::string const & rhs
				, std::string const & sep )
			{
				if ( lhs.empty() )
				{
					lhs = rhs;
					return;
				}

				if ( rhs.empty() )
				{
					return;
				}

				lhs = lhs + sep + rhs;
			}

			static bool isUnaryPre( ast::expr::Kind kind )
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
					throw std::runtime_error{ "Non unary expression" };
				}

				return result;
			}

			static std::string getCtorName( ast::expr::Expr const & image
				, ast::expr::Expr const & sampler )
			{
				if ( image.getType()->getKind() == ast::type::Kind::eSampledImage
					&& sampler.getType()->getKind() == ast::type::Kind::eSampler )
				{
					auto & config = static_cast< ast::type::SampledImage const & >( *image.getType() ).getConfig();
					auto isComparison = static_cast< ast::type::Sampler const & >( *sampler.getType() ).isComparison();
					return getPrefix( config.sampledType )
						+ getType( ast::type::Kind::eSampler, config )
						+ getDimension( config.dimension )
						+ getMS( config.isMS )
						+ getArray( config.isArrayed )
						+ getShadow( isComparison );
				}

				return "combine";
			}

			static std::string getCtorName( ast::expr::CompositeType composite
				, ast::type::Kind component )
			{
				std::string result;

				switch ( composite )
				{
				case ast::expr::CompositeType::eVec2:
					switch ( component )
					{
					case ast::type::Kind::eBoolean:
						result = "bvec2";
						break;
					case ast::type::Kind::eInt8:
						result = "i8vec2";
						break;
					case ast::type::Kind::eInt16:
						result = "i16vec2";
						break;
					case ast::type::Kind::eInt32:
						result = "ivec2";
						break;
					case ast::type::Kind::eInt64:
						result = "i64vec2";
						break;
					case ast::type::Kind::eUInt8:
						result = "u8vec2";
						break;
					case ast::type::Kind::eUInt16:
						result = "u16vec2";
						break;
					case ast::type::Kind::eUInt32:
						result = "uvec2";
						break;
					case ast::type::Kind::eUInt64:
						result = "u64vec2";
						break;
					case ast::type::Kind::eFloat:
						result = "vec2";
						break;
					case ast::type::Kind::eDouble:
						result = "dvec2";
						break;
					case ast::type::Kind::eHalf:
						result = "f16vec2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eVec3:
					switch ( component )
					{
					case ast::type::Kind::eBoolean:
						result = "bvec3";
						break;
					case ast::type::Kind::eInt8:
						result = "i8vec3";
						break;
					case ast::type::Kind::eInt16:
						result = "i16vec3";
						break;
					case ast::type::Kind::eInt32:
						result = "ivec3";
						break;
					case ast::type::Kind::eInt64:
						result = "i64vec3";
						break;
					case ast::type::Kind::eUInt8:
						result = "u8vec3";
						break;
					case ast::type::Kind::eUInt16:
						result = "u16vec3";
						break;
					case ast::type::Kind::eUInt32:
						result = "uvec3";
						break;
					case ast::type::Kind::eUInt64:
						result = "u64vec3";
						break;
					case ast::type::Kind::eFloat:
						result = "vec3";
						break;
					case ast::type::Kind::eDouble:
						result = "dvec3";
						break;
					case ast::type::Kind::eHalf:
						result = "f16vec3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eVec4:
					switch ( component )
					{
					case ast::type::Kind::eBoolean:
						result = "bvec4";
						break;
					case ast::type::Kind::eInt8:
						result = "i8vec4";
						break;
					case ast::type::Kind::eInt16:
						result = "i16vec4";
						break;
					case ast::type::Kind::eInt32:
						result = "ivec4";
						break;
					case ast::type::Kind::eInt64:
						result = "i64vec4";
						break;
					case ast::type::Kind::eUInt8:
						result = "u8vec4";
						break;
					case ast::type::Kind::eUInt16:
						result = "u16vec4";
						break;
					case ast::type::Kind::eUInt32:
						result = "uvec4";
						break;
					case ast::type::Kind::eUInt64:
						result = "u64vec4";
						break;
					case ast::type::Kind::eFloat:
						result = "vec4";
						break;
					case ast::type::Kind::eDouble:
						result = "dvec4";
						break;
					case ast::type::Kind::eHalf:
						result = "f16vec4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat2x2:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat2";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat2x3:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat2x3";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat2x3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat2x4:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat2x4";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat2x4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat3x2:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat3x2";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat3x2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat3x3:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat3";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat3x4:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat3x4";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat3x4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat4x2:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat4x2";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat4x2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat4x3:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat4x3";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat4x3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat4x4:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat4";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eCombine:
					result = "combine";
					break;
				default:
					AST_Failure( "Unsupported expr::CompositeType" );
					break;
				}

				return result;
			}

			static bool isScopeBeginStatement( StatementType value )
			{
				switch ( value )
				{
				case glsl::StatementType::eNone:
				case glsl::StatementType::eStructureDecl:
				case glsl::StatementType::eStructureMemberDecl:
				case glsl::StatementType::eFunctionDecl:
				case glsl::StatementType::eVariableDecl:
				case glsl::StatementType::eScopeLine:
				case glsl::StatementType::eStructureScopeEnd:
				case glsl::StatementType::eFunctionScopeEnd:
				case glsl::StatementType::eLexicalScopeEnd:
				case glsl::StatementType::eControlBegin:
				case glsl::StatementType::eControlEnd:
					return false;
				case glsl::StatementType::eStructureScopeBegin:
				case glsl::StatementType::eFunctionScopeBegin:
				case glsl::StatementType::eLexicalScopeBegin:
					return true;
				default:
					AST_Failure( "Unsupported StatementType." );
					return false;
				}
			}

			static bool isScopeEndStatement( StatementType value )
			{
				switch ( value )
				{
				case glsl::StatementType::eNone:
				case glsl::StatementType::eStructureDecl:
				case glsl::StatementType::eStructureMemberDecl:
				case glsl::StatementType::eFunctionDecl:
				case glsl::StatementType::eVariableDecl:
				case glsl::StatementType::eScopeLine:
				case glsl::StatementType::eStructureScopeBegin:
				case glsl::StatementType::eFunctionScopeBegin:
				case glsl::StatementType::eLexicalScopeBegin:
				case glsl::StatementType::eControlBegin:
					return false;
				case glsl::StatementType::eStructureScopeEnd:
				case glsl::StatementType::eFunctionScopeEnd:
				case glsl::StatementType::eLexicalScopeEnd:
				case glsl::StatementType::eControlEnd:
					return true;
				default:
					AST_Failure( "Unsupported StatementType." );
					return false;
				}
			}

			static bool isScopeDeclStatement( StatementType value )
			{
				switch ( value )
				{
				case glsl::StatementType::eNone:
				case glsl::StatementType::eScopeLine:
				case glsl::StatementType::eStructureScopeBegin:
				case glsl::StatementType::eStructureScopeEnd:
				case glsl::StatementType::eFunctionScopeBegin:
				case glsl::StatementType::eFunctionScopeEnd:
				case glsl::StatementType::eLexicalScopeBegin:
				case glsl::StatementType::eLexicalScopeEnd:
				case glsl::StatementType::eStructureMemberDecl:
				case glsl::StatementType::eVariableDecl:
				case glsl::StatementType::eControlEnd:
					return false;
				case glsl::StatementType::eStructureDecl:
				case glsl::StatementType::eFunctionDecl:
				case glsl::StatementType::eControlBegin:
					return true;
				default:
					AST_Failure( "Unsupported StatementType." );
					return false;
				}
			}
		}

		//*****************************************************************************************

		class ExprVisitor
			: public ast::expr::SimpleVisitor
		{
		public:
			static std::string submit( ast::expr::Expr * expr
				, StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases )
			{
				std::string result;
				ExprVisitor vis{ result, config, aliases };
				expr->accept( &vis );
				return result;
			}

		private:
			ExprVisitor( std::string & result
				, StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases )
				: m_result{ result }
				, m_config{ config }
				, m_aliases{ aliases }
			{
			}

			std::string doSubmit( ast::expr::Expr * expr )
			{
				return submit( expr, m_config, m_aliases );
			}

			std::string doSubmit( ast::expr::ExprPtr const & expr )
			{
				return doSubmit( expr.get() );
			}

			void wrap( ast::expr::Expr * expr )
			{
				bool noParen = expr->getKind() == ast::expr::Kind::eFnCall
					|| expr->getKind() == ast::expr::Kind::eIdentifier
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

				if ( noParen )
				{
					m_result += doSubmit( expr );
				}
				else
				{
					m_result += "(";
					m_result += doSubmit( expr );
					m_result += ")";
				}
			}

			void visitAssignmentExpr( ast::expr::Binary * expr )
			{
				wrap( expr->getLHS() );
				m_result += " " + helpers::getOperatorName( expr->getKind() ) + " ";
				m_result += doSubmit( expr->getRHS() );
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				if ( expr->isNonUniform()
					&& !expr->getOperand()->isNonUniform() )
				{
					m_result += "nonuniformEXT(";
				}

				if ( helpers::isUnaryPre( expr->getKind() ) )
				{
					m_result += helpers::getOperatorName( expr->getKind() );
					wrap( expr->getOperand() );
				}
				else
				{
					wrap( expr->getOperand() );
					m_result += helpers::getOperatorName( expr->getKind() );
				}

				if ( expr->isNonUniform()
					&& !expr->getOperand()->isNonUniform() )
				{
					m_result += ")";
				}
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				wrap( expr->getLHS() );
				m_result += " " + helpers::getOperatorName( expr->getKind() ) + " ";
				wrap( expr->getRHS() );
			}

			void visitAddAssignExpr( ast::expr::AddAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAndAssignExpr( ast::expr::AndAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAssignExpr( ast::expr::Assign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override
			{
				auto lhs = doSubmit( expr->getLHS() );
				auto rhs = doSubmit( expr->getRHS() );

				if ( lhs == rhs )
				{
					return;
				}

				visitAssignmentExpr( expr );
			}

			void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitOrAssignExpr( ast::expr::OrAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitXorAssignExpr( ast::expr::XorAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAggrInitExpr( ast::expr::AggrInit * expr )override
			{
				if ( expr->getIdentifier() )
				{
					if ( expr->isConstant() )
					{
						m_result += "const ";
					}

					m_result += getTypeName( expr->getType() ) + " ";
					m_result += doSubmit( expr->getIdentifier() );
					m_result += helpers::getTypeArraySize( expr->getType() );
					m_result += " = ";
				}

				m_result += getTypeName( expr->getType() ) + "[](";
				std::string sep;

				for ( auto & init : expr->getInitialisers() )
				{
					m_result += sep + doSubmit( init );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				wrap( expr->getLHS() );
				m_result += "[";
				wrap( expr->getRHS() );
				m_result += "]";
			}

			void visitCastExpr( ast::expr::Cast * expr )override
			{
				m_result += getTypeName( expr->getType() ) + "(";
				m_result += doSubmit( expr->getOperand() );
				m_result += ")";
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
				{
					m_result += helpers::getCtorName( *expr->getArgList()[0]
						, *expr->getArgList()[1] );
				}
				else
				{
					m_result += helpers::getCtorName( expr->getComposite()
						, getScalarType( expr->getComponent() ) );
				}

				m_result += "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				wrap( expr->getOuterExpr() );

				if ( !m_result.empty() )
				{
					m_result += ".";
				}

				auto mbr = expr->getOuterType()->getMember( expr->getMemberIndex() );

				if ( mbr.builtin != ast::Builtin::eNone )
				{
					m_result += "gl_" + getName( mbr.builtin );
				}
				else
				{
					m_result += mbr.name;
				}
			}

			void visitFnCallExpr( ast::expr::FnCall * expr )override
			{
				if ( expr->isMember() )
				{
					wrap( expr->getInstance() );
					m_result += ".";
				}

				m_result += doSubmit( expr->getFn() );
				m_result += "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				auto it = m_aliases.find( expr->getVariable() );

				if ( it != m_aliases.end() )
				{
					wrap( it->second );
				}
				else
				{
					m_result += visitVariable( expr->getVariable() );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override
			{
				m_result += getGlslName( expr->getImageAccess() ) + "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitInitExpr( ast::expr::Init * expr )override
			{
				if ( expr->isConstant() )
				{
					m_result += "const ";
				}

				m_result += getTypeName( expr->getType() ) + " ";
				m_result += doSubmit( expr->getIdentifier() );
				m_result += helpers::getTypeArraySize( expr->getIdentifier()->getType() );
				m_result += " = ";
				m_result += doSubmit( expr->getInitialiser() );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
			{
				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier
					|| expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
				{
					ast::type::Scope memory;
					ast::type::MemorySemantics semantics;
					bool isControlBarrier = ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );

					if ( isControlBarrier )
					{
						if ( expr->getArgList().size() < 3u )
						{
							throw std::runtime_error{ "Wrong number of parameters for a control barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
						semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[2] ) );
					}
					else
					{
						if ( expr->getArgList().size() < 2u )
						{
							throw std::runtime_error{ "Wrong number of parameters for a memory barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[0] ) );
						semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
					}

					if ( memory == ast::type::Scope::eWorkgroup )
					{
						if ( checkAllMemoryBarrier( semantics ) )
						{
							m_result = "groupMemoryBarrier()";
						}
						else
						{
							m_result = "barrier()";
						}
					}
					else if ( memory == ast::type::Scope::eSubgroup )
					{
						if ( checkAllMemoryBarrier( semantics ) )
						{
							if ( isControlBarrier )
							{
								m_result = "subgroupBarrier()";
							}
							else
							{
								m_result = "subgroupMemoryBarrier()";
							}
						}
						else if ( checkBufferMemoryBarrier( semantics ) )
						{
							m_result = "subgroupMemoryBarrierBuffer()";
						}
						else if ( checkSharedMemoryBarrier( semantics ) )
						{
							m_result = "subgroupMemoryBarrierShared()";
						}
						else if ( checkImageMemoryBarrier( semantics ) )
						{
							m_result = "subgroupMemoryBarrierImage()";
						}
						else
						{
							m_result = "subgroupBarrier()";
						}
					}
					else
					{
						if ( checkAllMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrier()";
						}
						else if ( checkBufferMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrierBuffer()";
						}
						else if ( checkSharedMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrierShared()";
						}
						else if ( checkImageMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrierImage()";
						}
						else
						{
							m_result = "barrier()";
						}
					}
				}
				else
				{
					m_result += getGlslName( expr->getIntrinsic() ) + "(";
					std::string sep;

					for ( auto & arg : expr->getArgList() )
					{
						m_result += sep;
						m_result += doSubmit( arg );
						sep = ", ";
					}

					m_result += ")";
				}
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				std::locale loc{ "C" };
				std::stringstream stream;
				stream.imbue( loc );

				switch ( expr->getLiteralType() )
				{
				case ast::expr::LiteralType::eBool:
					stream << ( expr->getValue< ast::expr::LiteralType::eBool >()
						? std::string{ "true" }
						: std::string{ "false" } );
					break;
				case ast::expr::LiteralType::eInt8:
					stream << "int8_t(" << int16_t( expr->getValue< ast::expr::LiteralType::eInt8 >() ) << ")";
					break;
				case ast::expr::LiteralType::eInt16:
					stream << "int16_t(" << expr->getValue< ast::expr::LiteralType::eInt16 >() << ")";
					break;
				case ast::expr::LiteralType::eInt32:
					stream << expr->getValue< ast::expr::LiteralType::eInt32 >();
					break;
				case ast::expr::LiteralType::eInt64:
					stream << expr->getValue< ast::expr::LiteralType::eInt64 >() << "l";
					break;
				case ast::expr::LiteralType::eUInt8:
					stream << "uint8_t(" << uint16_t( expr->getValue< ast::expr::LiteralType::eUInt8 >() ) << "u)";
					break;
				case ast::expr::LiteralType::eUInt16:
					stream << "uint16_t(" << expr->getValue< ast::expr::LiteralType::eUInt16 >() << "u)";
					break;
				case ast::expr::LiteralType::eUInt32:
					stream << expr->getValue< ast::expr::LiteralType::eUInt32 >() << "u";
					break;
				case ast::expr::LiteralType::eUInt64:
					stream << expr->getValue< ast::expr::LiteralType::eUInt64 >() << "ul";
					break;
				case ast::expr::LiteralType::eFloat:
				{
					auto v = expr->getValue< ast::expr::LiteralType::eFloat >();
					stream << std::setprecision( 12u ) << v;

					if ( v == std::floor( v )
						&& stream.str().find( 'e' ) == std::string::npos )
					{
						stream << ".0";
					}

					stream << "f";
				}
				break;
				case ast::expr::LiteralType::eDouble:
				{
					auto v = expr->getValue< ast::expr::LiteralType::eDouble >();
					stream << std::setprecision( 16u ) << v;

					if ( v == std::floor( v )
						&& stream.str().find( 'e' ) == std::string::npos )
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

			void visitQuestionExpr( ast::expr::Question * expr )override
			{
				m_result += "(";
				wrap( expr->getCtrlExpr() );
				m_result += " ? ";
				wrap( expr->getTrueExpr() );
				m_result += " : ";
				wrap( expr->getFalseExpr() );
				m_result += ")";
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend expression." );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
			{
				m_result += doSubmit( expr->getLabel() );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
			{
				m_result += doSubmit( expr->getValue() );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				wrap( expr->getOuterExpr() );
				m_result += "." + getName( expr->getSwizzle() );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override
			{
				m_result += getGlslName( expr->getCombinedImageAccess() ) + "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					m_result += doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitAliasExpr( ast::expr::Alias * expr )override
			{
				m_aliases.emplace( expr->getLHS()->getVariable(), expr->getRHS() );
			}

		private:
			std::string visitVariable( ast::var::VariablePtr var )
			{
				return ( var->getOuter()
					? visitVariable( var->getOuter() ) + "." + var->getName()
					: ( var->isBuiltin()
						? helpers::getBuiltinName( var->getBuiltin() )
						: helpers::adaptName( var->getName(), m_config ) ) );
			}

		private:
			std::string & m_result;
			StmtConfig const & m_config;
			std::map< ast::var::VariablePtr, ast::expr::Expr * > & m_aliases;
		};

		//*****************************************************************************************

		class StmtVisitor
			: public ast::stmt::Visitor
		{
		public:
			static Statements submit( StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
				, ast::stmt::Stmt * stmt )
			{
				Statements result{ std::string{}, StatementsList{} };
				submit( config, aliases, stmt, result );
				return result;
			}

		private:
			static void submit( StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
				, ast::stmt::Stmt * stmt
				, Statements & result )
			{
				StmtVisitor vis{ config, aliases, result };
				stmt->accept( &vis );
			}

			StmtVisitor( StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
				, Statements & result )
				: m_config{ config }
				, m_aliases{ aliases }
				, m_result{ result }
			{
			}

			std::string doSubmit( ast::expr::Expr * expr )
			{
				return ExprVisitor::submit( expr, m_config, m_aliases );
			}

			ast::stmt::Stmt * getCurrentScope()
			{
				return m_scopes.back();
			}

			void doAddStatement( std::string text
				, StatementType type
				, ast::stmt::Stmt * stmt
				, ast::stmt::Stmt * scope = nullptr )
			{
				if ( helpers::isScopeEndStatement( m_lastStmtType )
					&& !helpers::isScopeEndStatement( type ) )
				{
					++m_currentLine;
					m_result.source += "\n";
				}
				else if ( helpers::isScopeDeclStatement( type )
					&& !helpers::isScopeBeginStatement( m_lastStmtType ) )
				{
					++m_currentLine;
					m_result.source += "\n";
				}

				Statement current;
				current.type = type;
				current.stmt = stmt;
				auto length = uint32_t( text.size() );
				m_result.source += m_indents.back() + std::move( text ) + "\n";
				current.source.lineStart = m_currentLine;
				current.source.columnStart = uint32_t( m_indents.back().size() );
				current.source.columnEnd = current.source.columnStart + length;
				current.source.scope = scope ? scope : getCurrentScope();
				m_result.statements.push_back( std::move( current ) );

				++m_currentLine;
				m_lastStmtType = type;
				m_currentText.clear();
			}

			void doAddSimpleStatement( std::string const & text
				, ast::stmt::Stmt * stmt )
			{
				doAddStatement( text + ";", m_scopeLines.back(), stmt );
			}

			void doAddVariableDeclStatement( std::string const & text
				, ast::stmt::Stmt * stmt )
			{
				doAddStatement( text + ";", StatementType::eVariableDecl, stmt );
			}

			void doBeginScope( ast::stmt::Stmt * stmt
				, StatementType scopeBegin
				, StatementType scopeLine )
			{
				m_scopes.push_back( stmt );
				doAddStatement( "{", scopeBegin, stmt, stmt );
				m_scopeLines.push_back( scopeLine );
				m_indents.push_back( m_indents.back() + "    " );
			}

			void doEndScope( ast::stmt::Stmt * stmt
				, StatementType scopeEnd )
			{
				m_indents.pop_back();
				m_scopeLines.pop_back();

				if ( scopeEnd == StatementType::eStructureDecl )
				{
					doAddStatement( "};", scopeEnd, stmt, stmt );
				}
				else
				{
					doAddStatement( "}", scopeEnd, stmt, stmt );
				}

				m_scopes.pop_back();
			}

			void doParseScope( ast::stmt::Compound * stmt
				, StatementType scopeBegin
				, StatementType scopeLine
				, StatementType scopeEnd
				, std::string preEndLine = std::string{} )
			{
				doBeginScope( stmt, scopeBegin, scopeLine );
				visitCompoundStmt( stmt );

				if ( !preEndLine.empty() )
				{
					doAddSimpleStatement( std::move( preEndLine ), stmt );
				}

				doEndScope( stmt, scopeEnd );
			}

			void doParseStruct( ast::stmt::Stmt * stmt
				, ast::type::Struct const & structType )
			{
				if ( structType.empty() )
				{
					return;
				}

				doAddStatement( "struct " + structType.getName(), StatementType::eStructureDecl, stmt );
				doBeginScope( stmt, StatementType::eStructureScopeBegin, StatementType::eStructureMemberDecl );

				for ( auto & mbr : structType )
				{
					std::string text;

					if ( mbr.location != ast::type::Struct::InvalidLocation
						&& !hasFlag( structType.getFlag(), ast::var::Flag::ePatchOutput )
						&& !hasFlag( structType.getFlag(), ast::var::Flag::ePatchInput ) )
					{
						text += "layout( location=" + writeValue( mbr.location ) + " ) ";
						text += ( structType.isShaderInput()
							? std::string{ "in" }
						: std::string{ "out" } ) + " ";
					}

					text += getTypeName( mbr.type ) + " " + mbr.name;
					text += helpers::getTypeArraySize( mbr.type );
					doAddSimpleStatement( std::move( text ), stmt );
				}

				doEndScope( stmt, StatementType::eStructureScopeEnd );
			}

			void visitContainerStmt( ast::stmt::Container * stmt )override
			{
				for ( auto & curStmt : *stmt )
				{
					curStmt->accept( this );
				}
			}

			void visitBreakStmt( ast::stmt::Break * stmt )override
			{
				doAddSimpleStatement( "break", stmt );
			}

			void visitContinueStmt( ast::stmt::Continue * stmt )override
			{
				doAddSimpleStatement( "continue", stmt );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override
			{
				if ( !stmt->empty() )
				{
					doAddStatement( "struct " + stmt->getName() + "Block", StatementType::eStructureDecl, stmt );
					doParseScope( stmt
						, StatementType::eStructureScopeBegin
						, StatementType::eStructureMemberDecl
						, StatementType::eStructureScopeEnd );
					std::string text = "layout(";
					text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
					doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
					text += ") uniform " + stmt->getName() + "Block " + stmt->getName();
					doAddVariableDeclStatement( std::move( text ), stmt );
				}
			}

			void visitDemoteStmt( ast::stmt::Demote * stmt )override
			{
				if ( m_config.vulkanGlsl )
				{
					doAddSimpleStatement( "demote", stmt );
				}
				else
				{
					doAddSimpleStatement( "discard", stmt );
				}
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh * stmt )override
			{
				std::string text = "EmitMeshTasksEXT";
				text += "(" + doSubmit( stmt->getNumGroupsX() );
				text += ", " + doSubmit( stmt->getNumGroupsY() );
				text += ", " + doSubmit( stmt->getNumGroupsZ() );
				text += ")";
				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )override
			{
				if ( m_config.vulkanGlsl )
				{
					doAddSimpleStatement( "terminate", stmt );
				}
				else
				{
					doAddSimpleStatement( "discard", stmt );
				}
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override
			{
				if ( !stmt->empty() )
				{
					doAddStatement( "struct " + stmt->getName() + "Block", StatementType::eStructureDecl, stmt );
					doParseScope( stmt
						, StatementType::eStructureScopeBegin
						, StatementType::eStructureMemberDecl
						, StatementType::eStructureScopeEnd );
					std::string text = "layout(push_constant) ";
					text += "uniform " + stmt->getName() + "Block " + stmt->getName();
					doAddVariableDeclStatement( std::move( text ), stmt );
				}
			}

			void visitCommentStmt( ast::stmt::Comment * stmt )override
			{
			}

			void visitCompoundStmt( ast::stmt::Compound * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile * stmt )override
			{
				doAddStatement( "do", StatementType::eControlBegin, stmt, stmt );
				doParseScope( stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
				std::string text = "while (";

				if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
				{
					text += "bool(" + doSubmit( stmt->getCtrlExpr() ) + "));";
				}
				else
				{
					text += "(" + doSubmit( stmt->getCtrlExpr() ) + ");";
				}

				doAddStatement( std::move( text ), StatementType::eControlEnd, stmt, stmt );
			}

			void visitElseIfStmt( ast::stmt::ElseIf * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else * stmt )override
			{
				doAddStatement( "else", StatementType::eControlBegin, stmt, stmt );
				doParseScope( stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
			}

			void visitForStmt( ast::stmt::For * stmt )override
			{
				AST_Failure( "Unexpected For statement." );
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )override
			{
				std::string origin = helpers::getLayoutName( stmt->getFragmentOrigin() );
				std::string center = helpers::getLayoutName( stmt->getFragmentCenter() );

				if ( !origin.empty() || !center.empty() )
				{
					std::string text = "layout(";
					text += origin;
					text += ( ( origin.empty() || center.empty() )
						? std::string{}
						: std::string{ ", " } );
					text += center;
					text += ") in vec4 gl_FragCoord";
					doAddVariableDeclStatement( std::move( text ), stmt );
				}
				else
				{
					doAddSimpleStatement( std::string{}, stmt );
				}
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override
			{
				auto type = stmt->getType();
				std::string text = getTypeName( type->getReturnType() );
				text += " " + stmt->getName() + "(";
				std::string sep;

				for ( auto & param : *type )
				{
					text += sep + helpers::getDirectionName( *param )
						+ " " + getTypeName( param->getType() )
						+ " " + param->getName() + helpers::getTypeArraySize( param->getType() );
					sep = ", ";
				}

				text += ")";
				std::string preEndText;

				if ( stmt->isEntryPoint()
					&& m_config.shaderStage == ast::ShaderStage::eVertex )
				{
					if ( m_config.flipVertY )
					{
						preEndText += "gl_Position.y = -gl_Position.y";
					}

					if ( m_config.fixupClipDepth )
					{
						preEndText += "gl_Position.z = (gl_Position.z + gl_Position.w) * 0.5";
					}
				}

				doAddStatement( std::move( text ), StatementType::eFunctionDecl, stmt );
				doParseScope( stmt
					, StatementType::eFunctionScopeBegin
					, StatementType::eScopeLine
					, StatementType::eFunctionScopeEnd
					, preEndText );
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )override
			{
				std::string text = "hitAttributeEXT";
				helpers::join( text, getTypeName( stmt->getVariable()->getType() ), " " );
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitIfStmt( ast::stmt::If * stmt )override
			{
				std::string text = "if (";

				if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
				{
					text += "bool(" + doSubmit( stmt->getCtrlExpr() ) + "))";
				}
				else
				{
					text += doSubmit( stmt->getCtrlExpr() ) + ")";
				}

				doAddStatement( std::move( text ), StatementType::eControlBegin, stmt, stmt );
				doParseScope( stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );

				if ( stmt->getElse() )
				{
					stmt->getElse()->accept( this );
				}
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override
			{
				auto type = stmt->getVariable()->getType();

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					type = std::static_pointer_cast< ast::type::Array >( type )->getType();
				}

				assert( type->getKind() == ast::type::Kind::eImage );
				auto image = std::static_pointer_cast< ast::type::Image >( type );
				std::string text = "layout(";
				text += helpers::getFormatName( image->getConfig().format );

				if ( helpers::hasExtension( m_config, ARB_shading_language_420pack ) )
				{
					doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				}

				text += ") ";
				text += "uniform ";
				//text += getAccessQualifierName( image->getConfig() ) + " ";
				text += helpers::getQualifiedName( ast::type::Kind::eImage, image->getConfig() ) + " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )override
			{
				doAddSimpleStatement( "ignoreIntersectionEXT", stmt );
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )override
			{
				std::string text = "layout(buffer_reference";

				if ( auto structType = getStructType( stmt->getType() ) )
				{
					text += ", " + helpers::getMemoryLayoutName( structType->getMemoryLayout() );
					text += ") buffer " + getTypeName( stmt->getType() ) + " { ";
					text += getTypeName( structType->front().type ) + " " + structType->front().name + helpers::getTypeArraySize( structType->front().type ) + "; }";
				}
				else
				{
					text += ") buffer " + getTypeName( stmt->getType() ) + "s { ";
					text += getTypeName( stmt->getType() ) + helpers::getTypeArraySize( stmt->getType() ) + "; }";
				}

				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * stmt )override
			{
				std::string text = "layout(";
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
				text += ") uniform accelerationStructureEXT";
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )override
			{
				auto var = stmt->getVariable();
				std::string name = "callableDataEXT";

				if ( var->isIncomingCallableData() )
				{
					name = "callableDataInEXT";
				}

				std::string text = "layout(" + helpers::getLocationName( *var ) + "=" + writeValue( stmt->getLocation() ) + ")";
				helpers::join( text, name, " " );
				helpers::join( text, getTypeName( var->getType() ), " " );
				helpers::join( text, var->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )override
			{
				auto var = stmt->getVariable();
				std::string name = "rayPayloadEXT";

				if ( var->isIncomingRayPayload() )
				{
					name = "rayPayloadInEXT";
				}

				std::string text = "layout(" + helpers::getLocationName( *var ) + "=" + writeValue( stmt->getLocation() ) + ")";
				helpers::join( text, name, " " );
				helpers::join( text, getTypeName( stmt->getVariable()->getType() ), " " );
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override
			{
				if ( !stmt->getVariable()->isBuiltin() )
				{
					std::string text = helpers::getInOutLayout( m_config, *stmt );
					helpers::join( text, helpers::getInterpolationQualifier( *stmt->getVariable() ), " " );
					helpers::join( text, helpers::getDirectionName( *stmt->getVariable() ), " " );
					helpers::join( text, getTypeName( stmt->getVariable()->getType() ), " " );
					helpers::join( text, stmt->getVariable()->getName(), " " );

					if ( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eArray
						&& ( m_config.shaderStage == ast::ShaderStage::eTessellationControl
							|| m_config.shaderStage == ast::ShaderStage::eTessellationEvaluation ) )
					{
						text += "[]";
					}
					else
					{
						text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
					}

					doAddVariableDeclStatement( std::move( text ), stmt );
				}
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override
			{
				AST_Failure( "No specialisation constant should remain at this stage" );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override
			{
				std::string text;

				if ( stmt->getWorkGroupsZ() == 1 )
				{
					if ( stmt->getWorkGroupsY() == 1 )
					{
						text = "layout(local_size_x=" + writeValue( stmt->getWorkGroupsX() ) + ") in";
					}
					else
					{
						text = "layout(local_size_x=" + writeValue( stmt->getWorkGroupsX() )
							+ ", local_size_y=" + writeValue( stmt->getWorkGroupsY() ) + ") in";
					}
				}
				else
				{
					text = "layout(local_size_x=" + writeValue( stmt->getWorkGroupsX() )
						+ ", local_size_y=" + writeValue( stmt->getWorkGroupsY() )
						+ ", local_size_z=" + writeValue( stmt->getWorkGroupsZ() ) + ") in";
				}

				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getLayout() ) + ") in", stmt );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getLayout() ) + ", max_vertices = " + writeValue( stmt->getPrimCount() ) + ") out", stmt );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getTopology() ) + ") out", stmt );
				doAddSimpleStatement( "layout(max_vertices = " + writeValue( stmt->getMaxVertices() ) + ", max_primitives = " + writeValue( stmt->getMaxPrimitives() ) + ") out", stmt );
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override
			{
				doAddSimpleStatement( "layout(vertices=" + writeValue( stmt->getOutputVertices() ) + ") out", stmt );
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )override
			{
				std::string text = "layout(" + helpers::getLayoutName( stmt->getDomain() );
				text += ", " + helpers::getLayoutName( stmt->getPartitioning() );
				text += ", " + helpers::getLayoutName( stmt->getPrimitiveOrdering() );
				text += ") in";
				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )override
			{
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override
			{
				if ( stmt->getSource() != ast::stmt::PerVertexDecl::Source::eMeshOutput )
				{
					std::string decl;
					decl += m_indents.back() + "gl_PerVertex\n";
					decl += m_indents.back() + "{\n";
					decl += m_indents.back() + "	vec4 gl_Position;\n";
					decl += m_indents.back() + "	float gl_PointSize;\n";
					decl += m_indents.back() + "	float gl_ClipDistance[];\n";
					decl += m_indents.back() + "	float gl_CullDistance[];\n";
					decl += m_indents.back() + "}";

					switch ( stmt->getSource() )
					{
					case ast::stmt::PerVertexDecl::Source::eVertexOutput:
						doAddVariableDeclStatement( "out " + decl, stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eTessellationControlInput:
					case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
						doAddVariableDeclStatement( "in " + decl + " gl_in[gl_MaxPatchVertices]", stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eTessellationControlOutput:
						doAddVariableDeclStatement( "out " + decl + " gl_out[]", stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
						doAddVariableDeclStatement( "out " + decl, stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eGeometryInput:
						doAddVariableDeclStatement( "in " + decl + " gl_in[]", stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eGeometryOutput:
						doAddVariableDeclStatement( "out " + decl, stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eMeshOutput:
						doAddVariableDeclStatement( "out " + decl + " gl_MeshVerticesNV[]", stmt );
						break;
					}
				}
			}

			void visitReturnStmt( ast::stmt::Return * stmt )override
			{
				std::string text = "return";

				if ( stmt->getExpr() )
				{
					text += " " + doSubmit( stmt->getExpr() );
				}

				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override
			{
				auto type = stmt->getVariable()->getType();

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					type = std::static_pointer_cast< ast::type::Array >( type )->getType();
				}

				assert( type->getKind() == ast::type::Kind::eSampledImage );
				auto sampledImage = std::static_pointer_cast< ast::type::SampledImage >( type );
				std::string text;

				if ( helpers::hasExtension( m_config, ARB_shading_language_420pack ) )
				{
					text += "layout(";
					doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
					text += ") ";
				}

				text += "uniform " + helpers::getQualifiedName( ast::type::Kind::eSampledImage, sampledImage->getConfig() ) + " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )override
			{
				auto type = stmt->getVariable()->getType();

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					type = std::static_pointer_cast< ast::type::Array >( type )->getType();
				}

				assert( type->getKind() == ast::type::Kind::eCombinedImage );
				auto sampledImage = std::static_pointer_cast< ast::type::CombinedImage >( type );
				std::string text;

				if ( helpers::hasExtension( m_config, ARB_shading_language_420pack ) )
				{
					text += "layout(";
					doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
					text += ") ";
				}

				text += "uniform " + helpers::getQualifiedName( ast::type::Kind::eCombinedImage, sampledImage->getConfig(), sampledImage->isComparison() ) + " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override
			{
				std::string text = "layout(";
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
				text += ") uniform sampler";

				if ( static_cast< ast::type::Sampler const & >( *getNonArrayType( stmt->getVariable()->getType() ) ).isComparison() )
				{
					text += "Shadow";
				}

				text += " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override
			{
				doAddStatement( "struct " + stmt->getSsboName() + "Block", StatementType::eStructureDecl, stmt );
				doParseScope( stmt
					, StatementType::eStructureScopeBegin
					, StatementType::eStructureMemberDecl
					, StatementType::eStructureScopeEnd );
				std::string text = "layout(";
				text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				text += ") buffer " + stmt->getSsboName() + "Block " + stmt->getSsboName();
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override
			{
				doAddStatement( "struct " + stmt->getSsboName(), StatementType::eStructureDecl, stmt );
				doBeginScope( stmt, StatementType::eStructureScopeBegin, StatementType::eStructureMemberDecl );
				auto data = stmt->getData();
				auto arrayType = std::static_pointer_cast< ast::type::Array >( data->getType() );
				std::string text = getTypeName( arrayType->getType() ) + " " + data->getName();
				text += helpers::getTypeArraySize( arrayType ) + "";
				doAddSimpleStatement( std::move( text ), stmt );
				doEndScope( stmt, StatementType::eStructureScopeEnd );

				text = "layout(";
				text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				text += ") buffer " + stmt->getSsboName() + " " + stmt->getSsboInstance()->getName();
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitSimpleStmt( ast::stmt::Simple * stmt )override
			{
				if ( stmt->getExpr()->getKind() == ast::expr::Kind::eAlias )
				{
					doSubmit( stmt->getExpr() );
				}
				else if ( stmt->getExpr()->getKind() != ast::expr::Kind::eIdentifier )
				{
					auto result = doSubmit( stmt->getExpr() );

					if ( !result.empty() )
					{
						doAddSimpleStatement( doSubmit( stmt->getExpr() ), stmt );
					}
				}
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override
			{
				doParseStruct( stmt, *stmt->getType() );
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override
			{
				if ( stmt->getCaseExpr() )
				{
					doAddStatement( "case " + doSubmit( stmt->getCaseExpr() ) + ":", StatementType::eControlBegin, stmt );
				}
				else
				{
					doAddStatement( "default:", StatementType::eControlBegin, stmt );
				}

				doParseScope( stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
			}

			void visitSwitchStmt( ast::stmt::Switch * stmt )override
			{
				doAddStatement( "switch (" + doSubmit( stmt->getTestExpr() ) + ")", StatementType::eControlBegin, stmt );
				doParseScope( stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )override
			{
				doAddSimpleStatement( "terminateRayEXT", stmt );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override
			{
				if ( !stmt->getVariable()->isBuiltin() )
				{
					auto var = stmt->getVariable();

					if ( var->isPerTaskNV() )
					{
						auto structType = getStructType( var->getType() );

						if ( structType && !structType->empty() )
						{
							doParseStruct( stmt, *structType );
							std::string text = "taskNV";
							helpers::join( text, helpers::getDirectionName( *var ), " " );
							text += " ";
							text += structType->getName();
							helpers::join( text, var->getName(), " " );
							doAddVariableDeclStatement( std::move( text ), stmt );
						}
					}
					else if ( var->isPerTask() )
					{
						auto structType = getStructType( var->getType() );

						if ( structType && !structType->empty() )
						{
							doParseStruct( stmt, *structType );
						}

						if ( !structType || !structType->empty() )
						{
							std::string text = "taskPayloadSharedEXT";
							helpers::join( text, getTypeName( var->getType() ), " " );
							helpers::join( text, var->getName(), " " );
							doAddVariableDeclStatement( std::move( text ), stmt );
						}
					}
					else
					{
						std::string text;
						helpers::join( text, helpers::getDirectionName( *var ), " " );
						helpers::join( text, helpers::getInterpolationQualifier( *var ), " " );
						helpers::join( text, getTypeName( var->getType() ), " " );
						helpers::join( text, var->getName(), " " );
						text += helpers::getTypeArraySize( var->getType() );
						doAddVariableDeclStatement( std::move( text ), stmt );
					}
				}
			}

			void visitWhileStmt( ast::stmt::While * stmt )override
			{
				AST_Failure( "Unexpected While statement." );
			}

			void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override
			{
				AST_Failure( "Unexpected PreprocDefine statement." );
			}

			void visitPreprocElif( ast::stmt::PreprocElif * preproc )override
			{
				AST_Failure( "Unexpected PreprocElif statement." );
			}

			void visitPreprocElse( ast::stmt::PreprocElse * preproc )override
			{
				AST_Failure( "Unexpected PreprocElse statement." );
			}

			void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override
			{
				AST_Failure( "Unexpected PreprocEndif statement." );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override
			{
				doAddStatement( "#extension " + preproc->getName() + ": " + helpers::getStatusName( preproc->getStatus() ), StatementType::eScopeLine, preproc );
			}

			void visitPreprocIf( ast::stmt::PreprocIf * preproc )override
			{
				AST_Failure( "Unexpected PreprocIf statement." );
			}

			void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override
			{
				AST_Failure( "Unexpected PreprocIfDef statement." );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override
			{
				doAddStatement( "#version " + preproc->getName(), StatementType::eScopeLine, preproc );
			}

			void doWriteBinding( uint32_t binding
				, uint32_t set
				, std::string sep
				, std::string & result )
			{
				if ( binding != helpers::InvalidIndex
					&& helpers::hasExtension( m_config, ARB_shading_language_420pack ) )
				{
					result += sep + "binding=" + writeValue( binding );

					if ( set != helpers::InvalidIndex
						&& m_config.wantedVersion >= v4_6 )
					{
						result += sep + "set=" + writeValue( set );
					}
				}
			}

		private:
			StmtConfig const & m_config;
			std::map< ast::var::VariablePtr, ast::expr::Expr * > & m_aliases;
			ast::ShaderStage m_shaderStage;
			std::vector< std::string > m_indents{ std::string{} };
			Statements & m_result;
			std::vector< ast::stmt::Stmt * > m_scopes{ nullptr };
			uint32_t m_currentLine{ 1u };
			std::string m_currentText;
			std::vector< StatementType > m_scopeLines{ StatementType::eScopeLine };
			StatementType m_lastStmtType{ StatementType::eScopeLine };
		};

		//*****************************************************************************************
	}

	Statements generateGlslStatements( StmtConfig const & config
		, ast::stmt::Container * stmt )
	{
		std::map< ast::var::VariablePtr, ast::expr::Expr * > aliases;
		return generateGlslStatements( config, aliases, stmt );
	}

	Statements generateGlslStatements( StmtConfig const & config
		, std::map< ast::var::VariablePtr, ast::expr::Expr * > & aliases
		, ast::stmt::Container * stmt )
	{
		return gstvis::StmtVisitor::submit( config, aliases, stmt );
	}
}
