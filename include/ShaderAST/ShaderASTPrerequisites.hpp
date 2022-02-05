/*
See LICENSE file in root folder
*/
#ifndef ___AST_Prerequisites_H___
#define ___AST_Prerequisites_H___
#pragma once

#include <cassert>
#include <cstdint>

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <functional>
#include <memory>
#include <string>
#include <vector>
#pragma warning( pop )

#if defined( ShaderAST_Static )
#	define SDAST_API
#elif defined( _WIN32 )
#	if defined( ShaderAST_Exports )
#		define SDAST_API __declspec( dllexport )
#	else
#		define SDAST_API __declspec( dllimport )
#	endif
#else
#	define SDAST_API
#endif

#define AST_Failure( msg )\
	assert( false && msg )

namespace ast
{
	enum class ShaderStage
	{
		eVertex,
		eTessellationControl,
		eTessellationEvaluation,
		eGeometry,
		eFragment,
		eCompute,
		eTask,
		eMesh,
		eRayGeneration,
		eRayAnyHit,
		eRayClosestHit,
		eRayMiss,
		eRayIntersection,
		eCallable,
	};
	SDAST_API bool isRasterizerStage( ShaderStage stage );
	SDAST_API bool isComputeStage( ShaderStage stage );
	SDAST_API bool isRayTraceStage( ShaderStage stage );
	SDAST_API bool isMeshStage( ShaderStage stage );

	enum class FragmentOrigin
	{
		eLowerLeft,
		eUpperLeft,
	};

	enum class FragmentCenter
	{
		eHalfPixel,
		eCenterInteger,
	};

	enum class RayFlag
	{
		eNone = 0u,
		eOpaque = 1u,
		eNoOpaque = 2u,
		eTerminateOnFirstHit = 4u,
		eSkipClosestHitShader = 8u,
		eCullBackFacingTriangles = 16u,
		eCullFrontFacingTriangles = 32u,
		eCullOpaque = 64u,
		eCullNoOpaque = 128u,
	};

	enum class RayHitKind
	{
		eFrontFacingTriangle = 0xFEu,
		eBackFacingTriangle = 0xFFu,
	};

	enum class Builtin
	{
		eNone,
		ePosition,
		ePointSize,
		eClipDistance,
		eCullDistance,
		ePrimitiveID,
		ePrimitiveIDIn,
		eInvocationID,
		eLayer,
		eViewportIndex,
		eTessLevelOuter,
		eTessLevelInner,
		eTessCoord,
		ePatchVertices,
		ePatchVerticesIn,
		eFragCoord,
		ePointCoord,
		eFrontFacing,
		eSampleID,
		eSamplePosition,
		eSampleMask,
		eSampleMaskIn,
		eFragDepth,
		eHelperInvocation,
		eNumWorkGroups,
		eWorkGroupSize,
		eWorkGroupID,
		eLocalInvocationID,
		eGlobalInvocationID,
		eLocalInvocationIndex,
		eWorkDim,
		eGlobalSize,
		eEnqueuedWorkgroupSize,
		eGlobalLinearID,
		eSubgroupSize,
		eSubgroupMaxSize,
		eNumSubgroups,
		eNumEnqueuedSubgroups,
		eSubgroupID,
		eSubgroupLocalInvocationID,
		eVertexIndex,
		eInstanceIndex,
		eInstanceID,
		eSubgroupEqMaskKHR,
		eSubgroupGeMaskKHR,
		eSubgroupGtMaskKHR,
		eSubgroupLeMaskKHR,
		eSubgroupLtMaskKHR,
		eBaseVertex,
		eBaseInstance,
		eDrawIndex,
		eDeviceIndex,
		eViewIndex,
		eBaryCoordNoPerspAMD,
		eBaryCoordNoPerspCentroidAMD,
		eBaryCoordNoPerspSampleAMD,
		eBaryCoordSmoothAMD,
		eBaryCoordSmoothCentroidAMD,
		eBaryCoordSmoothSampleAMD,
		eBaryCoordPullModelAMD,
		eFragStencilRefEXT,
		eViewportMaskNV,
		eSecondaryPositionNV,
		eSecondaryViewportMaskNV,
		ePositionPerViewNV,
		eViewportMaskPerViewNV,
		ePrimitiveIndicesNV,
		ePrimitiveCountNV,
		eTaskCountNV,
		eClipDistancePerViewNV,
		eCullDistancePerViewNV,
		eLayerPerViewNV,
		eMeshViewCountNV,
		eMeshViewIndicesNV,
		eLaunchID,
		eLaunchSize,
		eInstanceCustomIndex,
		eGeometryIndex,
		eWorldRayOrigin,
		eWorldRayDirection,
		eObjectRayOrigin,
		eObjectRayDirection,
		eRayTmin,
		eRayTmax,
		eIncomingRayFlags,
		eHitKind,
		eObjectToWorld,
		eWorldToObject,
	};
	SDAST_API std::string getName( Builtin value );
	SDAST_API bool isPerVertex( Builtin value
		, ShaderStage stage );
	SDAST_API bool isPerPrimitive( Builtin value
		, ShaderStage stage );

	struct EntityName
	{
		uint32_t id;
		std::string name;
	};

	namespace expr
	{
		class Expr;
		class Visitor;
		using ExprPtr = std::unique_ptr< Expr >;
		using VisitorPtr = Visitor * ;

		enum class CompositeType
		{
			eScalar,
			eVec2,
			eVec3,
			eVec4,
			eMat2x2,
			eMat2x3,
			eMat2x4,
			eMat3x2,
			eMat3x3,
			eMat3x4,
			eMat4x2,
			eMat4x3,
			eMat4x4,
			eCombine,
		};
	}

	namespace stmt
	{
		class Stmt;
		class Visitor;
		using StmtPtr = std::unique_ptr< Stmt >;
		using VisitorPtr = Visitor * ;
	}
	namespace var
	{
		class Variable;
		using VariablePtr = std::shared_ptr< Variable >;
	}
	namespace type
	{
		class TypesCache;
		class Type;
		using TypePtr = std::shared_ptr< Type >;

		template< typename TypeT
			, typename CreatorT
			, typename HasherT >
		class TypeCache;
		class Function;
		using FunctionPtr = std::shared_ptr< Function >;
		class Struct;
		using StructPtr = std::shared_ptr< Struct >;
		class BaseStruct;
		using BaseStructPtr = std::shared_ptr< BaseStruct >;
		class IOStruct;
		using IOStructPtr = std::shared_ptr< IOStruct >;
		class Array;
		using ArrayPtr = std::shared_ptr< Array >;
		struct ImageConfiguration;
		class Sampler;
		using SamplerPtr = std::shared_ptr< Sampler >;
		class Image;
		using ImagePtr = std::shared_ptr< Image >;
		class CombinedImage;
		using CombinedImagePtr = std::shared_ptr< CombinedImage >;
		class Sampler;
		using SamplerPtr = std::shared_ptr< Sampler >;
	}

	struct AttributeInfo
	{
		type::TypePtr type;
		uint32_t location;
	};

	inline bool operator<( AttributeInfo const & lhs
		, AttributeInfo const & rhs )
	{
		return lhs.location < rhs.location;
	}

	inline bool operator==( AttributeInfo const & lhs
		, AttributeInfo const & rhs )
	{
		return lhs.location == rhs.location
			&& lhs.type == rhs.type;
	}

	struct SpecConstantInfo
		: AttributeInfo
	{
	};

	struct InputInfo
		: AttributeInfo
	{
	};

	struct OutputInfo
		: AttributeInfo
	{
	};

	struct InOutInfo
	{
		type::TypePtr type;
	};

	inline bool operator<( ast::InOutInfo const & lhs
		, ast::InOutInfo const & rhs )
	{
		return lhs.type < rhs.type;
	}

	inline bool operator==( ast::InOutInfo const & lhs
		, ast::InOutInfo const & rhs )
	{
		return lhs.type == rhs.type;
	}

	struct SpecConstantData
	{
		SpecConstantInfo info;
		std::vector< uint8_t > data;
	};

	struct SpecialisationInfo
	{
		std::vector< SpecConstantData > data;
	};

	struct DescriptorBinding
	{
		uint32_t binding;
		uint32_t set;
	};

	inline bool operator<( DescriptorBinding const & lhs
		, DescriptorBinding const & rhs )
	{
		return lhs.set < rhs.set
			|| ( lhs.set == rhs.set
				&& lhs.binding < rhs.binding );
	}

	inline bool operator==( DescriptorBinding const & lhs
		, DescriptorBinding const & rhs )
	{
		return lhs.set == rhs.set
			&& lhs.binding == rhs.binding;
	}

	template< typename TypeT = ast::type::Type >
	struct DescriptorInfoT
	{
		std::shared_ptr< TypeT > type;
		DescriptorBinding binding;
	};

	using DescriptorInfo = DescriptorInfoT<>;

	struct SamplerInfo
		: DescriptorInfo
	{
	};

	struct TextureInfo
		: DescriptorInfo
	{
	};

	struct ImageInfo
		: DescriptorInfo
	{
	};

	class Shader;
	using ShaderRef = std::reference_wrapper< Shader const >;
	using ShaderArray = std::vector< Shader >;
	using ShaderRefArray = std::vector< ShaderRef >;
}

#endif
