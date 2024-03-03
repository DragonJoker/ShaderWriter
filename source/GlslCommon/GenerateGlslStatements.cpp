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
#include <ShaderAST/Visitors/SimplifyStatements.hpp>

#include <cmath>
#include <cstring>
#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
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
			static uint32_t constexpr InvalidIndex = ~0u;

			static bool isContainer( ast::stmt::Stmt const & stmt )
			{
				switch ( stmt.getKind() )
				{
				case ast::stmt::Kind::eContainer:
				case ast::stmt::Kind::eCompound:
				case ast::stmt::Kind::eConstantBufferDecl:
				case ast::stmt::Kind::ePushConstantsBufferDecl:
				case ast::stmt::Kind::eShaderBufferDecl:
				case ast::stmt::Kind::eIf:
				case ast::stmt::Kind::eElse:
				case ast::stmt::Kind::eElseIf:
				case ast::stmt::Kind::eWhile:
				case ast::stmt::Kind::eFor:
				case ast::stmt::Kind::eDoWhile:
				case ast::stmt::Kind::eSwitch:
				case ast::stmt::Kind::eSwitchCase:
					return true;
				case ast::stmt::Kind::eSimple:
				case ast::stmt::Kind::eComment:
				case ast::stmt::Kind::eVariableDecl:
				case ast::stmt::Kind::ePerPrimitiveDecl:
				case ast::stmt::Kind::ePerVertexDecl:
				case ast::stmt::Kind::eInOutVariableDecl:
				case ast::stmt::Kind::eSpecialisationConstantDecl:
				case ast::stmt::Kind::eShaderStructBufferDecl:
				case ast::stmt::Kind::eSamplerDecl:
				case ast::stmt::Kind::eImageDecl:
				case ast::stmt::Kind::eSampledImageDecl:
				case ast::stmt::Kind::eCombinedImageDecl:
				case ast::stmt::Kind::eFunctionDecl:
				case ast::stmt::Kind::eStructureDecl:
				case ast::stmt::Kind::eReturn:
				case ast::stmt::Kind::eBreak:
				case ast::stmt::Kind::eContinue:
				case ast::stmt::Kind::eDemote:
				case ast::stmt::Kind::eTerminateInvocation:
				case ast::stmt::Kind::eInputGeometryLayout:
				case ast::stmt::Kind::eOutputGeometryLayout:
				case ast::stmt::Kind::eInputComputeLayout:
				case ast::stmt::Kind::eOutputMeshLayout:
				case ast::stmt::Kind::eFragmentLayout:
				case ast::stmt::Kind::eOutputTessellationControlLayout:
				case ast::stmt::Kind::eInputTessellationEvaluationLayout:
				case ast::stmt::Kind::eAccelerationStructureDecl:
				case ast::stmt::Kind::eInOutRayPayloadVariableDecl:
				case ast::stmt::Kind::eHitAttributeVariableDecl:
				case ast::stmt::Kind::eInOutCallableDataVariableDecl:
				case ast::stmt::Kind::eBufferReferenceDecl:
				case ast::stmt::Kind::eTerminateRay:
				case ast::stmt::Kind::eIgnoreIntersection:
				case ast::stmt::Kind::eDispatchMesh:
				case ast::stmt::Kind::ePreprocExtension:
				case ast::stmt::Kind::ePreprocVersion:
					return false;
				default:
					AST_Failure( "Unsupported stmt kind." );
					return false;
				}
			}

			static std::string adaptName( std::string const & name
				, StmtConfig const & writerConfig )
			{
				if ( writerConfig.vulkanGlsl )
				{
					static std::map< std::string, std::string, std::less<> > const toVkNames
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
					static std::map< std::string, std::string, std::less<> > const toGlNames
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

				if ( auto arraySize = getArraySize( type );
					arraySize != ast::type::NotArray )
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

			static std::string getType( ast::type::Kind kind )
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

			static std::string getTypeArraySize( ast::type::TypePtr type )
			{
				std::string result;

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					result = getTypeArraySize( std::static_pointer_cast< ast::type::Array >( type ) );
				}

				return result;
			}

			static std::string getCtorArray( ast::type::TypePtr type )
			{
				std::string result;

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					result = "[]";
				}

				return result;
			}

			static std::string getInterpolationQualifier( ast::var::Variable const & var
				, ast::ShaderStage shaderStage )
			{
				std::string result;

				if ( var.isFlat()
					&& ( shaderStage != ast::ShaderStage::eFragment || !var.isShaderOutput() ) )
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
				return config.availableExtensions.contains( extension );
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
					throw ast::Exception{ "Unsupported input layout." };
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
					throw ast::Exception{ "Unsupported output layout." };
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
					throw ast::Exception{ "Unsupported ast::type::PatchDomain." };
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
					throw ast::Exception{ "Unsupported ast::type::PatchDomain." };
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
					throw ast::Exception{ "Unsupported ast::type::Partitioning." };
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
					throw ast::Exception{ "Unsupported ast::type::OutputTopology." };
				}
			}

			static std::string getQualifiedName( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config )
			{
				return getPrefix( config.sampledType )
					+ getType( kind )
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
					throw ast::Exception{ "Non unary expression" };
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
						+ getType( ast::type::Kind::eSampler )
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
				case glsl::StatementType::eVariableBlockDecl:
				case glsl::StatementType::eBuiltinVariableDecl:
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
				case glsl::StatementType::eVariableBlockDecl:
				case glsl::StatementType::eBuiltinVariableDecl:
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
				case glsl::StatementType::eVariableBlockDecl:
				case glsl::StatementType::eBuiltinVariableDecl:
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

			static void doAddStatement( std::string text
				, Statements & result
				, uint32_t & line )
			{
				result.source += std::move( text ) + "\n";
				++line;
			}

			static void enableExtension( Statements & result
				, GlslExtension const & extension
				, uint32_t shaderVersion
				, uint32_t & line )
			{
				if ( extension.coreVersion > shaderVersion )
				{
					doAddStatement( "#extension " + extension.name + ": enable", result, line );
				}
			}
		}

		//*****************************************************************************************

		class ExprVisitor
			: public ast::expr::SimpleVisitor
		{
		public:
			static std::string submit( ast::expr::Expr const & expr
				, StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
				, bool withExprColumns
				, uint32_t currentColumn
				, ExprsColumns & exprs )
			{
				std::string result;
				ExprVisitor vis{ result, config, aliases, withExprColumns, currentColumn, exprs };
				expr.accept( &vis );
				return result;
			}

		private:
			ExprVisitor( std::string & result
				, StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
				, bool withExprColumns
				, uint32_t currentColumn
				, ExprsColumns & exprs )
				: m_result{ result }
				, m_config{ config }
				, m_aliases{ aliases }
				, m_withExprColumns{ withExprColumns }
				, m_currentColumn{ currentColumn }
				, m_exprsColumns{ exprs }
			{
			}

			std::string doSubmit( ast::expr::Expr const & expr, uint32_t currentColumn )const
			{
				return submit( expr, m_config, m_aliases, m_withExprColumns, currentColumn, m_exprsColumns );
			}

			uint32_t doGetColumn( std::string const & text )const
			{
				return uint32_t( m_currentColumn + text.size() );
			}

			struct Wrapped
			{
				ast::expr::Expr const * expr;
				bool maybeNonUniform;
			};

			std::string doJoinWrap( ast::expr::Expr const & expr, bool maybeNonUniform );
			std::string doJoinWrap( ast::expr::Expr const & expr, bool maybeNonUniform, uint32_t currentColumn );

			ast::expr::Expr const & doResolveAlias( ast::expr::Expr const & expr )const
			{
				if ( expr.getKind() == ast::expr::Kind::eIdentifier )
				{
					auto it = m_aliases.find( static_cast< ast::expr::Identifier const & >( expr ).getVariable() );

					if ( it != m_aliases.end() )
					{
						return *it->second;
					}
				}

				return expr;
			}

			void doParse( char const * const value
				, std::string & result )const
			{
				result += value;
			}

			void doParse( std::string const & value
				, std::string & result )const
			{
				result += value;
			}

			void doParse( ast::expr::Expr const & value
				, std::string & result )const
			{
				result += doSubmit( value, 0u );
			}

			void doParse( [[maybe_unused]] uint32_t value
				, [[maybe_unused]] std::string const & result )const
			{
			}

			void doParse( Wrapped const & value
				, std::string & result )
			{
				result += doJoinWrap( *value.expr, value.maybeNonUniform );
			}

			void doParse( std::pair< ast::expr::Expr const *, std::string > const & value
				, std::string & result )const
			{
				result += value.second;
			}

			uint32_t doParse( std::string const & value
				, uint32_t curColumn
				, std::string & result )const
			{
				result += value;
				return uint32_t( curColumn + value.size() );
			}

			template< size_t N >
			uint32_t doParse( char const value[N]
				, uint32_t curColumn
				, std::string & result )const
			{
				result += value;
				return uint32_t( curColumn + N );
			}

			uint32_t doParse( ast::expr::Expr const & value
				, uint32_t curColumn
				, std::string & result )const
			{
				auto & val = doResolveAlias( value );
				auto it = m_exprsColumns.emplace( &val, RangeInfo{} ).first;
				it->second.start = curColumn;
				auto text = doSubmit( val, curColumn );
				result += text;

				if ( it->second.end == 1 )
				{
					it->second.end = uint32_t( curColumn + text.size() );
				}

				return uint32_t( curColumn + text.size() );
			}

			uint32_t doParse( uint32_t value
				, uint32_t curColumn
				, [[maybe_unused]] std::string & result )const
			{
				return curColumn + value;
			}

			uint32_t doParse( Wrapped const & value
				, uint32_t curColumn
				, std::string & result )
			{
				auto & expr = doResolveAlias( *value.expr );
				auto it = m_exprsColumns.emplace( &expr, RangeInfo{} ).first;
				it->second.start = curColumn;
				auto text = doJoinWrap( expr, value.maybeNonUniform, curColumn );
				result += text;

				if ( it->second.end == 1 )
				{
					it->second.end = uint32_t( curColumn + text.size() );
				}

				return uint32_t( curColumn + text.size() );
			}

			uint32_t doParse( std::pair< ast::expr::Expr const *, std::string > const & value
				, uint32_t curColumn
				, std::string & result )const
			{
				auto & expr = doResolveAlias( *value.first );
				auto it = m_exprsColumns.emplace( &expr, RangeInfo{} ).first;
				it->second.start = curColumn;
				result += value.second;
				it->second.end = uint32_t( curColumn + value.second.size() );
				return it->second.end;
			}

			uint32_t doParse( ast::expr::Expr const * value
				, uint32_t curColumn
				, std::string & result )const
			{
				return doParse( *value, curColumn, result );
			}

			void doJoinRec( [[maybe_unused]] std::string & result )const
			{
			}

			template< typename ParamT, typename ... ParamsT >
			void doJoinRec( std::string & result
				, ParamT const & param
				, ParamsT && ... params )
			{
				doParse( param, result );
				doJoinRec( result, std::forward< ParamsT >( params )... );
			}

			void doJoinExprRec( [[maybe_unused]] std::string & result
				, [[maybe_unused]] uint32_t curColumn )const
			{
			}

			template< typename ParamT, typename ... ParamsT >
			void doJoinExprRec( std::string & result
				, uint32_t curColumn
				, ParamT const & param
				, ParamsT && ... params )
			{
				curColumn = doParse( param, curColumn, result );
				doJoinExprRec( result, curColumn, std::forward< ParamsT >( params )... );
			}

			template< typename ... ParamsT >
			std::string doJoin( ParamsT && ... params )
			{
				std::string text;

				if ( m_withExprColumns )
				{
					doJoinExprRec( text, m_currentColumn, std::forward< ParamsT >( params )... );
				}
				else
				{
					doJoinRec( text, std::forward< ParamsT >( params )... );
				}

				return text;
			}

			void doAppend( std::string const & text )
			{
				m_result += text;
				m_currentColumn += uint32_t( text.size() );
			}

			Wrapped wrap( ast::expr::Expr const & expr )const
			{
				return Wrapped{ &expr, false };
			}

			Wrapped wrapMaybeNonUniform( ast::expr::Expr const & expr )const
			{
				return Wrapped{ &expr, true };
			}

			void visitAssignmentExpr( ast::expr::Binary const * expr )
			{
				doAppend( doJoin( wrap( *expr->getLHS() )
					, " ", std::make_pair( expr, helpers::getOperatorName( expr->getKind() ) ), " "
					, *expr->getRHS() ) );
			}

			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				if ( expr->isNonUniform()
					&& !expr->getOperand()->isNonUniform() )
				{
					doAppend( "nonuniformEXT(" );
				}

				if ( helpers::isUnaryPre( expr->getKind() ) )
				{
					doAppend( doJoin( std::make_pair( expr, helpers::getOperatorName( expr->getKind() ) )
						, wrap( *expr->getOperand() ) ) );
				}
				else
				{
					doAppend( doJoin( wrap( *expr->getOperand() )
						, std::make_pair( expr, helpers::getOperatorName( expr->getKind() ) ) ) );
				}

				if ( expr->isNonUniform()
					&& !expr->getOperand()->isNonUniform() )
				{
					doAppend( ")" );
				}
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				if ( ( expr->getKind() == ast::expr::Kind::eEqual
					|| expr->getKind() == ast::expr::Kind::eNotEqual )
					&& ast::type::isVectorType( expr->getType() ) )
				{
					if ( expr->getKind() == ast::expr::Kind::eNotEqual )
					{
						doAppend( "!" );
					}

					doAppend( doJoin( std::make_pair( expr, "equal(" ), *expr->getLHS(), ", ", *expr->getRHS(), ")" ) );
				}
				else
				{
					doAppend( doJoin( wrap( *expr->getLHS() )
						, " ", std::make_pair( expr, helpers::getOperatorName( expr->getKind() ) ), " "
						, wrap( *expr->getRHS() ) ) );
				}
			}

			void visitAddAssignExpr( ast::expr::AddAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAndAssignExpr( ast::expr::AndAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAssignExpr( ast::expr::Assign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitDivideAssignExpr( ast::expr::DivideAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitLShiftAssignExpr( ast::expr::LShiftAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitMinusAssignExpr( ast::expr::MinusAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitModuloAssignExpr( ast::expr::ModuloAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitOrAssignExpr( ast::expr::OrAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitRShiftAssignExpr( ast::expr::RShiftAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitTimesAssignExpr( ast::expr::TimesAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitXorAssignExpr( ast::expr::XorAssign const * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					if ( expr->isConstant() )
					{
						doAppend( "const " );
					}

					doAppend( doJoin( getTypeName( expr->getType() ) + " "
						, expr->getIdentifier()
						, helpers::getTypeArraySize( expr->getType() )
						, " = " ) );
				}

				doAppend( doJoin( std::make_pair( expr, getTypeName( expr->getType() ) + helpers::getCtorArray( expr->getType() ) + "(" ) ) );
				std::string sep;

				for ( auto & init : expr->getInitialisers() )
				{
					doAppend( doJoin( sep, *init ) );
					sep = ", ";
				}

				doAppend( ")" );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )override
			{
				doAppend( doJoin( wrap( *expr->getLHS() )
					, doJoin( std::make_pair( expr, "[" ) )
					, wrapMaybeNonUniform( *expr->getRHS() )
					, "]" ) );
			}

			void visitCastExpr( ast::expr::Cast const * expr )override
			{
				doAppend( doJoin( doJoin( std::make_pair( expr, getTypeName( expr->getType() ) + "(" ) )
					, *expr->getOperand()
					, ")" ) );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
			{
				if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
				{
					doAppend( doJoin( std::make_pair( expr, helpers::getCtorName( *expr->getArgList()[0]
						, *expr->getArgList()[1] ) ) ) );
				}
				else
				{
					doAppend( doJoin( std::make_pair( expr, helpers::getCtorName( expr->getComposite()
						, getScalarType( expr->getComponent() ) ) ) ) );
				}

				doAppend( "(" );
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					doAppend( doJoin( sep, *arg ) );
					sep = ", ";
				}

				doAppend( ")" );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				doAppend( doJoin( wrap( *expr->getOuterExpr() ) ) );

				if ( !m_result.empty() )
				{
					doAppend( doJoin( std::make_pair( expr, "." ) ) );
				}

				auto mbr = expr->getOuterType()->getMember( expr->getMemberIndex() );

				if ( mbr.builtin != ast::Builtin::eNone )
				{
					doAppend( "gl_" + getName( mbr.builtin ) );
				}
				else
				{
					doAppend( mbr.name );
				}
			}

			void visitFnCallExpr( ast::expr::FnCall const * expr )override
			{
				if ( expr->isMember() )
				{
					doAppend( doJoin( wrap( *expr->getInstance() ), "." ) );
				}

				doAppend( doJoin( std::make_pair( expr, doJoin( *expr->getFn(), "(" ) ) ) );
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					doAppend( doJoin( sep, *arg ) );
					sep = ", ";
				}

				doAppend( ")" );
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				auto it = m_aliases.find( expr->getVariable() );

				if ( it != m_aliases.end() )
				{
					doAppend( doJoin( wrap( *it->second ) ) );
				}
				else
				{
					doAppend( doJoin( std::make_pair( expr, visitVariable( expr->getVariable() ) ) ) );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
			{
				doAppend( doJoin( std::make_pair( expr, getGlslName( expr->getImageAccess() ) + "(" ) ) );
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					doAppend( doJoin( sep, *arg ) );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitInitExpr( ast::expr::Init const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					if ( expr->isConstant() )
					{
						m_result += "const ";
					}

					doAppend( doJoin( getTypeName( expr->getType() ), " "
						, expr->getIdentifier()
						, helpers::getTypeArraySize( expr->getIdentifier().getType() )
						, doJoin( std::make_pair( expr, " = " ) )
						, *expr->getInitialiser() ) );
				}
				else
				{
					doAppend( doJoin( *expr->getInitialiser() ) );
				}
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
			{
				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier
					|| expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
				{
					doProcessMemoryBarrier( *expr );
				}
				else
				{
					doAppend( doJoin( std::make_pair( expr, getGlslName( expr->getIntrinsic() ) + "(" ) ) );
					std::string sep;

					for ( auto & arg : expr->getArgList() )
					{
						doAppend( doJoin( sep, *arg ) );
						sep = ", ";
					}

					doAppend( ")" );
				}
			}

			void visitLiteralExpr( ast::expr::Literal const * expr )override
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

				doAppend( stream.str() );
			}

			void visitQuestionExpr( ast::expr::Question const * expr )override
			{
				if ( ast::type::isVectorType( expr->getType() )
					&& ast::type::isVectorType( expr->getCtrlExpr()->getType() ) )
				{
					auto & exprCache = expr->getExprCache();
					auto & typesCache = expr->getTypesCache();
					auto componentCount = ast::type::getComponentCount( expr->getCtrlExpr()->getType() );
					auto componentType = typesCache.getBasicType( ast::type::getComponentType( expr->getType() ) );
					ast::expr::ExprList perComponent;

					for ( uint32_t i = 0u; i < componentCount; ++i )
					{
						auto swizzle = ast::expr::SwizzleKind::fromOffset( i );
						perComponent.push_back( exprCache.makeQuestion( componentType
							, ast::simplify( exprCache, typesCache, *exprCache.makeSwizzle( expr->getCtrlExpr()->clone(), swizzle ) )
							, ast::simplify( exprCache, typesCache, *exprCache.makeSwizzle( expr->getTrueExpr()->clone(), swizzle ) )
							, ast::simplify( exprCache, typesCache, *exprCache.makeSwizzle( expr->getFalseExpr()->clone(), swizzle ) ) ) );
					}

					auto compositeCtor = exprCache.makeCompositeConstruct( ast::expr::CompositeType( componentCount - 1u )
						, componentType->getKind()
						, std::move( perComponent ) );
					doAppend( doJoin( std::make_pair( expr, doJoin( *compositeCtor ) ) ) );
				}
				else
				{
					doAppend( doJoin( std::make_pair( expr, doJoin( "("
						, wrap( *expr->getCtrlExpr() )
						, " ? "
						, wrap( *expr->getTrueExpr() )
						, " : "
						, wrap( *expr->getFalseExpr() )
						, ")" ) ) ) );
				}
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend expression." );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
			{
				doAppend( doJoin( std::make_pair( expr, doJoin( *expr->getLabel() ) ) ) );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
			{
				doAppend( doJoin( std::make_pair( expr, doJoin( *expr->getValue() ) ) ) );
			}

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				doAppend( doJoin( std::make_pair( expr, doJoin( wrap( *expr->getOuterExpr() ) ) )
					, ".", getName( expr->getSwizzle() ) ) );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
			{
				doAppend( doJoin( std::make_pair( expr, getGlslName( expr->getCombinedImageAccess() ) + "(" ) ) );
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					doAppend( doJoin( sep, *arg ) );
					sep = ", ";
				}

				doAppend( ")" );
			}

			void visitAliasExpr( ast::expr::Alias const * expr )override
			{
				if ( expr->hasIdentifier() )
				{
					m_aliases.try_emplace( expr->getIdentifier().getVariable(), expr->getAliasedExpr() );
				}
				else
				{
					doAppend( doJoin( *expr->getAliasedExpr() ) );
				}
			}

		private:
			std::string visitVariable( ast::var::VariablePtr var )
			{
				return ( var->getOuter()
					? visitVariable( var->getOuter() ) + "." + var->getName()
					: ( ( var->isBuiltin() && var->getBuiltin() != ast::Builtin::eNone )
						? helpers::adaptName( helpers::getBuiltinName( var->getBuiltin() ), m_config )
						: helpers::adaptName( var->getName(), m_config ) ) );
			}

			void doProcessGlobalMemoryBarrier( ast::type::MemorySemantics semantics )
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

			void doProcessWorkgroupMemoryBarrier( ast::type::MemorySemantics semantics )
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

			void doProcessSubgroupMemoryBarrier( ast::type::MemorySemantics semantics
				, bool isControlBarrier )
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

			void doProcessMemoryBarrier( ast::expr::IntrinsicCall const & expr )
			{
				ast::type::Scope memory;
				ast::type::MemorySemantics semantics;
				bool isControlBarrier = ( expr.getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );

				if ( isControlBarrier )
				{
					if ( expr.getArgList().size() < 3u )
					{
						throw ast::Exception{ "Wrong number of parameters for a control barrier" };
					}

					memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[1] ) );
					semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[2] ) );
				}
				else
				{
					if ( expr.getArgList().size() < 2u )
					{
						throw ast::Exception{ "Wrong number of parameters for a memory barrier" };
					}

					memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[0] ) );
					semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr.getArgList()[1] ) );
				}

				if ( memory == ast::type::Scope::eWorkgroup )
				{
					doProcessWorkgroupMemoryBarrier( semantics );
				}
				else if ( memory == ast::type::Scope::eSubgroup )
				{
					doProcessSubgroupMemoryBarrier( semantics, isControlBarrier );
				}
				else
				{
					doProcessGlobalMemoryBarrier( semantics );
				}
			}

		private:
			std::string & m_result;
			StmtConfig const & m_config;
			std::map< ast::var::VariablePtr, ast::expr::Expr const * > & m_aliases;
			bool m_withExprColumns;
			uint32_t m_currentColumn;
			ExprsColumns & m_exprsColumns;
		};

		std::string ExprVisitor::doJoinWrap( ast::expr::Expr const & expr, bool maybeNonUniform )
		{
			bool noParen = expr.getKind() == ast::expr::Kind::eFnCall
				|| expr.getKind() == ast::expr::Kind::eIdentifier
				|| expr.getKind() == ast::expr::Kind::eLiteral
				|| expr.getKind() == ast::expr::Kind::eMbrSelect
				|| expr.getKind() == ast::expr::Kind::eCast
				|| expr.getKind() == ast::expr::Kind::eSwizzle
				|| expr.getKind() == ast::expr::Kind::eArrayAccess
				|| expr.getKind() == ast::expr::Kind::eIntrinsicCall
				|| expr.getKind() == ast::expr::Kind::eCombinedImageAccessCall
				|| expr.getKind() == ast::expr::Kind::eImageAccessCall
				|| expr.getKind() == ast::expr::Kind::eUnaryMinus
				|| expr.getKind() == ast::expr::Kind::eUnaryPlus
				|| expr.getKind() == ast::expr::Kind::eCopy;
			std::string result;

			if ( maybeNonUniform && expr.isNonUniform() )
			{
				result += doJoin( "nonuniformEXT(", expr, ")" );
			}
			else if ( noParen )
			{
				result += doJoin( expr );
			}
			else
			{
				result += doJoin( "(", expr, ")" );
			}

			return result;
		}

		std::string ExprVisitor::doJoinWrap( ast::expr::Expr const & expr, bool maybeNonUniform, uint32_t currentColumn )
		{
			auto save = m_currentColumn;
			m_currentColumn = currentColumn;
			auto result = doJoinWrap( expr, maybeNonUniform );
			m_currentColumn = save;
			return result;
		}

		//*****************************************************************************************

		class StmtVisitor
			: public ast::stmt::Visitor
		{
		public:
			static Statements submit( StmtConfig const & config
				, IntrinsicsConfig const & intrinsics
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
				, ast::stmt::Stmt const & stmt
				, bool withExprColumns )
			{
				Statements result{ std::string{}, StatementsList{} };
				uint32_t line{ 1u };

				if ( withExprColumns && helpers::isContainer( stmt ) )
				{
					auto & container = static_cast< ast::stmt::Container const & >( stmt );
					auto it = std::find_if( container.begin()
						, container.end()
						, []( ast::stmt::StmtPtr const & lookup )
						{
							return lookup->getKind() == ast::stmt::Kind::ePreprocVersion;
						} );

					if ( it == container.end() )
					{
						helpers::doAddStatement( "#version " + writeValue( config.wantedVersion ), result, line );

						for ( auto & extension : intrinsics.requiredExtensions )
						{
							if ( extension.name != KHR_vulkan_glsl.name )
							{
								helpers::enableExtension( result, extension, config.wantedVersion, line );
							}
						}
					}
				}

				StmtVisitor vis{ config, aliases, withExprColumns, result, line };
				stmt.accept( &vis );
				return result;
			}

		private:
			StmtVisitor( StmtConfig const & config
				, std::map< ast::var::VariablePtr, ast::expr::Expr const * > & aliases
				, bool withExprColumns
				, Statements & result
				, uint32_t line )
				: m_config{ config }
				, m_aliases{ aliases }
				, m_withExprColumns{ withExprColumns }
				, m_result{ result }
				, m_currentLine{ line }
			{
			}

			uint32_t doGetStartColumn()const noexcept
			{
				return m_indents.empty()
					? 0u
					: uint32_t( m_indents.back().size() );
			}

			std::string doSubmit( ast::expr::Expr const & expr, ExprsColumns & exprs )const
			{
				return ExprVisitor::submit( expr, m_config, m_aliases, m_withExprColumns, doGetStartColumn(), exprs );
			}

			std::pair< std::string, ExprsColumns > doSubmit( ast::expr::Expr const & expr )const
			{
				ExprsColumns exprs;
				auto text = doSubmit( expr, exprs );
				return { text, exprs };
			}

			ast::stmt::Stmt const * getCurrentScope()const
			{
				return m_scopes.back();
			}

			uint32_t doGetColumn( std::string const & text )const
			{
				return m_withExprColumns
					? uint32_t( doGetStartColumn() + text.size() )
					: 0u;
			}

			void doAddStatement( std::string text
				, ExprsColumns exprs
				, StatementType type
				, ast::stmt::Stmt const & stmt
				, ast::stmt::Stmt const * scope = nullptr )
			{
				if ( ( helpers::isScopeEndStatement( m_lastStmtType )
						&& !helpers::isScopeEndStatement( type ) )
					|| ( helpers::isScopeDeclStatement( type )
						&& !helpers::isScopeBeginStatement( m_lastStmtType ) ) )
				{
					++m_currentLine;
					m_result.source += "\n";
				}

				Statement current;
				current.type = type;
				current.stmt = &stmt;
				auto length = uint32_t( text.size() );
				m_result.source += m_indents.back() + std::move( text ) + "\n";
				current.source.lines.start = m_currentLine;
				current.source.columns.start = uint32_t( m_indents.back().size() );
				current.source.columns.end = current.source.columns.start + length;
				current.source.scope = scope ? scope : getCurrentScope();
				current.exprs = std::move( exprs );
				m_result.statements.push_back( std::move( current ) );

				++m_currentLine;
				m_lastStmtType = type;
			}

			void doAddSimpleStatement( std::string const & text
				, ExprsColumns exprs
				, ast::stmt::Stmt const & stmt )
			{
				doAddStatement( text + ";", std::move( exprs ), m_scopeLines.back(), stmt );
			}

			void doAddInterruptStatement( std::string const & text
				, ast::stmt::Stmt const & stmt )
			{
				doAddSimpleStatement( text, ExprsColumns{}, stmt );
			}

			void doAddBuiltinVarDeclStatement( ast::stmt::Stmt const & stmt )
			{
				Statement current;
				current.type = StatementType::eBuiltinVariableDecl;
				current.stmt = &stmt;
				current.source.lines.start = m_currentLine;
				current.source.columns.start = 1u;
				current.source.columns.end = 2u;
				current.source.scope = getCurrentScope();
				m_result.statements.push_back( std::move( current ) );
			}

			void doAddVariableDeclStatement( std::string text
				, ast::stmt::Stmt const & stmt )
			{
				text += ";";
				doAddStatement( std::move( text ), ExprsColumns{}, StatementType::eVariableDecl, stmt );
			}

			void doAddBlockVariableDeclStatement( std::string text
				, ast::stmt::Stmt const & stmt )
			{
				doAddStatement( std::move( text ), ExprsColumns{}, StatementType::eVariableBlockDecl, stmt );
			}

			void doBeginScope( ast::stmt::Stmt const & stmt
				, StatementType scopeBegin
				, StatementType scopeLine )
			{
				m_scopes.push_back( &stmt );
				doAddStatement( "{", ExprsColumns{}, scopeBegin, stmt, &stmt );
				m_scopeLines.push_back( scopeLine );
				m_indents.push_back( m_indents.back() + "    " );
			}

			void doEndScope( ast::stmt::Stmt const & stmt
				, StatementType scopeEnd
				, std::string const & scopeEndText = std::string{} )
			{
				m_indents.pop_back();
				m_scopeLines.pop_back();

				if ( scopeEnd == StatementType::eStructureDecl
					|| scopeEnd == StatementType::eStructureScopeEnd )
				{
					doAddStatement( "}" + scopeEndText + ";", ExprsColumns{}, scopeEnd, stmt, &stmt );
				}
				else
				{
					doAddStatement( "}" + scopeEndText, ExprsColumns{}, scopeEnd, stmt, &stmt );
				}

				m_scopes.pop_back();
			}

			void doParseScope( ast::stmt::Compound const & stmt
				, StatementType scopeBegin
				, StatementType scopeLine
				, StatementType scopeEnd
				, std::string const & preEndLine = {}
				, std::string const & scopeEndText = {} )
			{
				doBeginScope( stmt, scopeBegin, scopeLine );
				visitContainerStmt( &stmt );

				if ( !preEndLine.empty() )
				{
					doAddSimpleStatement( preEndLine, ExprsColumns{}, stmt );
				}

				doEndScope( stmt, scopeEnd, scopeEndText );
			}

			void doParseStructBlock( ast::stmt::Stmt const & stmt
				, ast::type::Struct const & structType )
			{
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
					doAddSimpleStatement( text, ExprsColumns{}, stmt );
				}

				doEndScope( stmt, StatementType::eStructureScopeEnd );
			}
			
			bool doHasRuntimeArray( ast::type::Struct const & type )const
			{
				return type.end() != std::find_if( type.begin()
					, type.end()
					, []( ast::type::Struct::Member const & lookup )
					{
						return lookup.type->getKind() == ast::type::Kind::eArray
							&& getArraySize( lookup.type ) == ast::type::UnknownArraySize;
					} );
			}

			void doParseStruct( ast::stmt::Stmt const & stmt
				, ast::type::Struct const & structType )
			{
				if ( structType.empty()/* || doHasRuntimeArray( structType ) */)
				{
					return;
				}

				doAddStatement( "struct " + structType.getName(), ExprsColumns{}, StatementType::eStructureDecl, stmt );
				doParseStructBlock( stmt, structType );
			}

			void doParse( char const * const text
				, std::string & result )const
			{
				result += text;
			}

			void doParse( ast::expr::Expr const & expr
				, std::string & result )const
			{
				result += doSubmit( expr ).first;
			}

			uint32_t doParse( char const * const text
				, [[maybe_unused]] ExprsColumns const & exprs
				, [[maybe_unused]] uint32_t curColumn
				, std::string & result )const
			{
				doParse( text, result );
				return doGetColumn( result );
			}

			uint32_t doParse( ast::expr::Expr const & expr
				, ExprsColumns & exprs
				, uint32_t curColumn
				, std::string & result )const
			{
				auto it = exprs.emplace( &expr, RangeInfo{} ).first;
				it->second.start = curColumn;
				result += doSubmit( expr, exprs );
				it->second.end = doGetColumn( result );
				return it->second.end;
			}

			void doJoinExprRec( [[maybe_unused]] std::string & result
				, [[maybe_unused]] ExprsColumns & exprs
				, [[maybe_unused]] uint32_t curColumn )const
			{
			}

			template< typename ParamT, typename ... ParamsT >
			void doJoinExprRec( std::string & result
				, ExprsColumns & exprs
				, uint32_t curColumn
				, ParamT const & param
				, ParamsT && ... params )const
			{
				curColumn = doParse( param, exprs, curColumn, result );
				doJoinExprRec( result, exprs, curColumn, std::forward< ParamsT >( params )... );
			}

			void doJoinRec( std::string & )const
			{
			}

			template< typename ParamT, typename ... ParamsT >
			void doJoinRec( std::string & result
				, ParamT const & param
				, ParamsT && ... params )const
			{
				doParse( param, result );
				doJoinRec( result, std::forward< ParamsT >( params )... );
			}

			template< typename ... ParamsT >
			std::pair< std::string, ExprsColumns > doJoin( ParamsT && ... params )const
			{
				ExprsColumns exprs;
				std::string text;

				if ( m_withExprColumns )
				{
					doJoinExprRec( text, exprs, 0u, std::forward< ParamsT >( params )... );
				}
				else
				{
					doJoinRec( text, std::forward< ParamsT >( params )... );
				}

				return { text, exprs };
			}

			void visitContainerStmt( ast::stmt::Container const * stmt )override
			{
				for ( auto & curStmt : *stmt )
				{
					curStmt->accept( this );
				}
			}

			void visitBreakStmt( ast::stmt::Break const * stmt )override
			{
				doAddInterruptStatement( "break", *stmt );
			}

			void visitContinueStmt( ast::stmt::Continue const * stmt )override
			{
				doAddInterruptStatement( "continue", *stmt );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl const * stmt )override
			{
				if ( !stmt->empty() )
				{
					std::string text = "layout(";
					text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
					doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
					text += ") uniform " + stmt->getName() + "Block";
					doAddBlockVariableDeclStatement( std::move( text ), *stmt );
					doParseScope( *stmt
						, StatementType::eStructureScopeBegin
						, StatementType::eStructureMemberDecl
						, StatementType::eStructureScopeEnd
						, std::string{}
						, stmt->getName() );
				}
			}

			void visitDemoteStmt( ast::stmt::Demote const * stmt )override
			{
				if ( m_config.vulkanGlsl )
				{
					doAddInterruptStatement( "demote", *stmt );
				}
				else
				{
					doAddInterruptStatement( "discard", *stmt );
				}
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh const * stmt )override
			{
				auto [text, exprs] = doJoin( "EmitMeshTasksEXT"
					, "(", *stmt->getNumGroupsX()
					, ", ", *stmt->getNumGroupsY()
					, ", ", *stmt->getNumGroupsZ()
					, ")" );
				doAddSimpleStatement( text, exprs, *stmt );
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation const * stmt )override
			{
				doAddInterruptStatement( "discard", *stmt );
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl const * stmt )override
			{
				if ( !stmt->empty() )
				{
					std::string text = "layout(push_constant) ";
					text += "uniform " + stmt->getName() + "Block";
					doAddBlockVariableDeclStatement( std::move( text ), *stmt );
					doParseScope( *stmt
						, StatementType::eStructureScopeBegin
						, StatementType::eStructureMemberDecl
						, StatementType::eStructureScopeEnd
						, std::string{}
						, " " + stmt->getName() );
				}
			}

			void visitCommentStmt( ast::stmt::Comment const * stmt )override
			{
			}

			void visitCompoundStmt( ast::stmt::Compound const * stmt )override
			{
				doParseScope( *stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile const * stmt )override
			{
				doAddStatement( "do", ExprsColumns{}, StatementType::eControlBegin, *stmt, stmt );
				doParseScope( *stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );

				if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
				{
					auto [text, exprs] = doJoin( "while (bool(", *stmt->getCtrlExpr(), "));" );
					doAddStatement( std::move( text ), std::move( exprs ), StatementType::eControlEnd, *stmt, stmt );
				}
				else
				{
					auto [text, exprs] = doJoin( "while (", *stmt->getCtrlExpr(), ");" );
					doAddStatement( std::move( text ), std::move( exprs ), StatementType::eControlEnd, *stmt, stmt );
				}
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				doAddStatement( "else", ExprsColumns{}, StatementType::eControlBegin, *stmt, stmt );
				doParseScope( *stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
			}

			void visitForStmt( ast::stmt::For const * stmt )override
			{
				AST_Failure( "Unexpected For statement." );
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout const * stmt )override
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
					doAddVariableDeclStatement( std::move( text ), *stmt );
				}
				else
				{
					doAddSimpleStatement( std::string{}, ExprsColumns{}, *stmt );
				}
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
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

				doAddStatement( std::move( text ), ExprsColumns{}, StatementType::eFunctionDecl, *stmt );
				doParseScope( *stmt
					, StatementType::eFunctionScopeBegin
					, StatementType::eScopeLine
					, StatementType::eFunctionScopeEnd
					, preEndText );
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
				std::string text = "hitAttributeEXT";
				helpers::join( text, getTypeName( stmt->getVariable()->getType() ), " " );
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitIfStmt( ast::stmt::If const * stmt )override
			{
				if ( stmt->getCtrlExpr()->getType()->getKind() != ast::type::Kind::eBoolean )
				{
					auto [text, exprs] = doJoin( "if (bool(", *stmt->getCtrlExpr(), "))" );
					doAddStatement( std::move( text ), std::move( exprs ), StatementType::eControlBegin, *stmt, stmt );
				}
				else
				{
					auto [text, exprs] = doJoin( "if (", *stmt->getCtrlExpr(), ")" );
					doAddStatement( std::move( text ), std::move( exprs ), StatementType::eControlBegin, *stmt, stmt );
				}

				doParseScope( *stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );

				if ( stmt->getElse() )
				{
					stmt->getElse()->accept( this );
				}
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl const * stmt )override
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
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection const * stmt )override
			{
				doAddInterruptStatement( "ignoreIntersectionEXT", *stmt );
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl const * stmt )override
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

				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl const * stmt )override
			{
				std::string text = "layout(";
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
				text += ") uniform accelerationStructureEXT";
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
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
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
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
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
			{
				if ( stmt->getVariable()->isBuiltin() )
				{
					doAddBuiltinVarDeclStatement( *stmt );
				}
				else
				{
					std::string text = helpers::getInOutLayout( m_config, *stmt );
					helpers::join( text, helpers::getInterpolationQualifier( *stmt->getVariable(), m_config.shaderStage ), " " );
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

					doAddVariableDeclStatement( std::move( text ), *stmt );
				}
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl const * stmt )override
			{
				doAddVariableDeclStatement( "layout(constant_id=" + std::to_string( stmt->getLocation() )
					+ ") const " + getTypeName( stmt->getVariable()->getType() )
					+ " " + stmt->getVariable()->getName(), *stmt );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout const * stmt )override
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

				doAddSimpleStatement( text, ExprsColumns{}, *stmt );
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout const * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getLayout() ) + ") in", ExprsColumns{}, *stmt );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout const * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getLayout() ) + ", max_vertices = " + writeValue( stmt->getPrimCount() ) + ") out", ExprsColumns{}, *stmt );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout const * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getTopology() ) + ") out", ExprsColumns{}, *stmt );
				doAddSimpleStatement( "layout(max_vertices = " + writeValue( stmt->getMaxVertices() ) + ", max_primitives = " + writeValue( stmt->getMaxPrimitives() ) + ") out", ExprsColumns{}, *stmt );
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout const * stmt )override
			{
				doAddSimpleStatement( "layout(vertices=" + writeValue( stmt->getOutputVertices() ) + ") out", ExprsColumns{}, *stmt );
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout const * stmt )override
			{
				std::string text = "layout(" + helpers::getLayoutName( stmt->getDomain() );
				text += ", " + helpers::getLayoutName( stmt->getPartitioning() );
				text += ", " + helpers::getLayoutName( stmt->getPrimitiveOrdering() );
				text += ") in";
				doAddSimpleStatement( text, ExprsColumns{}, *stmt );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl const * stmt )override
			{
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl const * stmt )override
			{
				if ( stmt->getSource() != ast::stmt::PerVertexDecl::Source::eMeshOutput )
				{
					std::string decl;
					decl += m_indents.back() + "gl_PerVertex\n";
					decl += m_indents.back() + "{\n";
					decl += m_indents.back() + "\tvec4 gl_Position;\n";
					decl += m_indents.back() + "\tfloat gl_PointSize;\n";
					decl += m_indents.back() + "\tfloat gl_ClipDistance[];\n";
					decl += m_indents.back() + "\tfloat gl_CullDistance[];\n";
					decl += m_indents.back() + "}";

					switch ( stmt->getSource() )
					{
					case ast::stmt::PerVertexDecl::Source::eVertexOutput:
						doAddVariableDeclStatement( "out " + decl, *stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eTessellationControlInput:
					case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationInput:
						doAddVariableDeclStatement( "in " + decl + " gl_in[gl_MaxPatchVertices]", *stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eTessellationControlOutput:
						doAddVariableDeclStatement( "out " + decl + " gl_out[]", *stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eTessellationEvaluationOutput:
						doAddVariableDeclStatement( "out " + decl, *stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eGeometryInput:
						doAddVariableDeclStatement( "in " + decl + " gl_in[]", *stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eGeometryOutput:
						doAddVariableDeclStatement( "out " + decl, *stmt );
						break;
					case ast::stmt::PerVertexDecl::Source::eMeshOutput:
						doAddVariableDeclStatement( "out " + decl + " gl_MeshVerticesNV[]", *stmt );
						break;
					}
				}
			}

			void visitReturnStmt( ast::stmt::Return const * stmt )override
			{
				if ( auto expr = stmt->getExpr() )
				{
					auto [text, exprs] = doJoin( "return ", *expr );
					doAddSimpleStatement( text, std::move( exprs ), *stmt );
				}
				else
				{
					doAddInterruptStatement( "return", *stmt );
				}
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl const * stmt )override
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
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
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
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl const * stmt )override
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
				doAddVariableDeclStatement( std::move( text ), *stmt );
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
				std::string text = "layout(";
				text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				text += ") buffer " + stmt->getSsboName() + "Buffer";
				doAddBlockVariableDeclStatement( std::move( text ), *stmt );
				doParseScope( *stmt
					, StatementType::eStructureScopeBegin
					, StatementType::eStructureMemberDecl
					, StatementType::eStructureScopeEnd
					, std::string{}
					, stmt->getSsboName() );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
				std::string text = "layout(";
				text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				text += ") buffer " + stmt->getSsboName();
				doAddBlockVariableDeclStatement( std::move( text ), *stmt );
				doBeginScope( *stmt, StatementType::eStructureScopeBegin, StatementType::eStructureMemberDecl );
				auto data = stmt->getData();
				auto arrayType = std::static_pointer_cast< ast::type::Array >( data->getType() );
				text = getTypeName( arrayType->getType() ) + " " + data->getName();
				text += helpers::getTypeArraySize( arrayType );
				doAddSimpleStatement( text, ExprsColumns{}, *stmt );
				doEndScope( *stmt, StatementType::eStructureScopeEnd, " " + stmt->getSsboInstance()->getName() );
			}

			void visitSimpleStmt( ast::stmt::Simple const * stmt )override
			{
				if ( stmt->getExpr()->getKind() == ast::expr::Kind::eAlias )
				{
					doSubmit( *stmt->getExpr() );
				}
				else if ( stmt->getExpr()->getKind() != ast::expr::Kind::eIdentifier )
				{
					auto [text, exprs] = doSubmit( *stmt->getExpr() );

					if ( !text.empty() )
					{
						doAddSimpleStatement( text, std::move( exprs ), *stmt );
					}
				}
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
				if ( !stmt->getType()->isShaderInput()
					&& !stmt->getType()->isShaderOutput() )
				{
					doParseStruct( *stmt, *stmt->getType() );
				}
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase const * stmt )override
			{
				if ( stmt->getCaseExpr() )
				{
					auto [text, exprs] = doSubmit( *stmt->getCaseExpr() );
					doAddStatement( "case " + text + ":", exprs, StatementType::eControlBegin, *stmt );
				}
				else
				{
					doAddStatement( "default:", ExprsColumns{}, StatementType::eControlBegin, *stmt );
				}

				doParseScope( *stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
			}

			void visitSwitchStmt( ast::stmt::Switch const * stmt )override
			{
				auto [text, exprs] = doSubmit( *stmt->getTestExpr() );
				doAddStatement( "switch (" + text + ")", exprs, StatementType::eControlBegin, *stmt );
				doParseScope( *stmt
					, StatementType::eLexicalScopeBegin
					, StatementType::eScopeLine
					, StatementType::eLexicalScopeEnd );
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay const * stmt )override
			{
				doAddInterruptStatement( "terminateRayEXT", *stmt );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
				if ( !stmt->getVariable()->isBuiltin() )
				{
					auto var = stmt->getVariable();

					if ( var->isPerTaskNV() )
					{
						auto structType = getStructType( var->getType() );

						if ( structType && !structType->empty() )
						{
							doParseStruct( *stmt, *structType );
							std::string text = "taskNV";
							helpers::join( text, helpers::getDirectionName( *var ), " " );
							text += " ";
							text += var->getName() + "Task";
							doAddBlockVariableDeclStatement( std::move( text ), *stmt );
							doBeginScope( *stmt, StatementType::eStructureScopeBegin, StatementType::eStructureMemberDecl );
							doAddSimpleStatement( structType->getName() + " " + var->getName(), ExprsColumns{}, *stmt );
							doEndScope( *stmt, StatementType::eStructureScopeEnd );
						}
					}
					else if ( var->isPerTask() )
					{
						auto structType = getStructType( var->getType() );

						if ( structType && !structType->empty() )
						{
							doParseStruct( *stmt, *structType );
						}

						if ( !structType || !structType->empty() )
						{
							std::string text = "taskPayloadSharedEXT";
							helpers::join( text, getTypeName( var->getType() ), " " );
							helpers::join( text, var->getName(), " " );
							doAddVariableDeclStatement( std::move( text ), *stmt );
						}
					}
					else
					{
						std::string text;
						helpers::join( text, helpers::getDirectionName( *var ), " " );
						helpers::join( text, helpers::getInterpolationQualifier( *var, m_config.shaderStage ), " " );
						helpers::join( text, getTypeName( var->getType() ), " " );
						helpers::join( text, var->getName(), " " );
						text += helpers::getTypeArraySize( var->getType() );
						doAddVariableDeclStatement( std::move( text ), *stmt );
					}
				}
			}

			void visitWhileStmt( ast::stmt::While const * stmt )override
			{
				AST_Failure( "Unexpected While statement." );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension const * preproc )override
			{
				doAddStatement( "#extension " + preproc->getName() + ": " + helpers::getStatusName( preproc->getStatus() ), ExprsColumns{}, StatementType::eScopeLine, *preproc );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
				doAddStatement( "#version " + preproc->getName(), ExprsColumns{}, StatementType::eScopeLine, *preproc );
			}

			void doWriteBinding( uint32_t binding
				, uint32_t set
				, std::string const & sep
				, std::string & result )const
			{
				if ( binding != helpers::InvalidIndex
					&& helpers::hasExtension( m_config, ARB_shading_language_420pack ) )
				{
					result += sep + "binding=" + writeValue( binding );

					if ( set != helpers::InvalidIndex
						&& m_config.wantedVersion >= v4_6 )
					{
						result += ", set=" + writeValue( set );
					}
				}
			}

		private:
			StmtConfig const & m_config;
			std::map< ast::var::VariablePtr, ast::expr::Expr const * > & m_aliases;
			std::vector< std::string > m_indents{ std::string{} };
			bool m_withExprColumns;
			Statements & m_result;
			std::vector< ast::stmt::Stmt const * > m_scopes{ nullptr };
			uint32_t m_currentLine{ 1u };
			std::vector< StatementType > m_scopeLines{ StatementType::eScopeLine };
			StatementType m_lastStmtType{ StatementType::eScopeLine };
		};

		//*****************************************************************************************
	}

	Statements generateGlslStatements( StmtConfig const & config
		, IntrinsicsConfig const & intrinsics
		, ast::stmt::Container const & stmt
		, bool withExprColumns )
	{
		std::map< ast::var::VariablePtr, ast::expr::Expr const * > aliases;
		return gstvis::StmtVisitor::submit( config, intrinsics, aliases, stmt, withExprColumns );
	}

	std::string getExprName( StmtConfig const & config
		, ast::expr::Expr const & expr )
	{
		std::map< ast::var::VariablePtr, ast::expr::Expr const * > aliases;
		ExprsColumns exprs;
		return gstvis::ExprVisitor::submit( expr, config, aliases, false, 0u, exprs );
	}
}
