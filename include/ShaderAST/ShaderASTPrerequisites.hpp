/*
See LICENSE file in root folder
*/
#ifndef ___AST_Prerequisites_H___
#define ___AST_Prerequisites_H___
#pragma once

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <cassert>
#include <cstdint>

#include <functional>
#include <memory>
#include <stdexcept>
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

#define AST_TraceFunc 0

#if AST_TraceFunc
#	include <iostream>
#endif

#if AST_TraceFunc
#	if !defined( NDEBUG )
#		define TraceFunc \
		std::cout << "Function " << __FUNCTION__ << ":" << __LINE__ << std::endl
#	else
#		define TraceFunc
#	endif
#else
#	define TraceFunc
#endif

#define AST_Failure( msg )\
	assert( false && msg )

#define AST_Exception( text )\
	throw ast::Exception{ text }

namespace ast
{
	class ShaderAllocator;
	class ShaderAllocatorBlock;

	using ShaderAllocatorBlockPtr = std::unique_ptr< ShaderAllocatorBlock >;

	enum class ShaderStage
	{
		eVertex,
		eTessellationControl,
		eTessellationEvaluation,
		eGeometry,
		eFragment,
		eCompute,
		eTaskNV,
		eMeshNV,
		eTask,
		eMesh,
		eRayGeneration,
		eRayAnyHit,
		eRayClosestHit,
		eRayMiss,
		eRayIntersection,
		eCallable,
		eTraditionalGraphics,
		eModernGraphicsNV,
		eModernGraphicsEXT,
		eRayTrace,
	};
	SDAST_API bool isRasterizerStage( ShaderStage stage );
	SDAST_API bool isComputeStage( ShaderStage stage );
	SDAST_API bool isRayTraceStage( ShaderStage stage );
	SDAST_API bool isMeshStage( ShaderStage stage );
	SDAST_API bool isMeshNVStage( ShaderStage stage );

	enum class EntryPoint : uint32_t
	{
		eNone = 0,
		eVertex,
		eTessellationControl,
		eTessellationEvaluation,
		eGeometry,
		eMeshNV,
		eTaskNV,
		eMesh,
		eTask,
		eFragment,
		eRayGeneration,
		eRayAnyHit,
		eRayClosestHit,
		eRayMiss,
		eRayIntersection,
		eCallable,
		eCompute,
	};
	SDAST_API std::string getName( EntryPoint entryPoint );
	SDAST_API EntryPoint getEntryPointType( ShaderStage stage );
	SDAST_API ShaderStage getShaderStage( EntryPoint entryPoint );

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
		eSubgroupEqMask,
		eSubgroupGeMask,
		eSubgroupGtMask,
		eSubgroupLeMask,
		eSubgroupLtMask,
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
		ePrimitivePointIndices,
		ePrimitiveLineIndices,
		ePrimitiveTriangleIndices,
		eCullPrimitive,
	};
	SDAST_API std::string getName( Builtin value );
	SDAST_API bool isPerVertex( Builtin value
		, ShaderStage stage );
	SDAST_API bool isPerPrimitive( Builtin value
		, ShaderStage stage );

	class Exception
		: public std::runtime_error
	{
		using std::runtime_error::runtime_error;
	};

	struct EntityName
	{
		uint32_t id;
		std::string name;
	};

	namespace expr
	{
		class Expr;
		class ExprCache;
		class Binary;
		class Unary;
		class Visitor;

		class Add;
		class AddAssign;
		class AggrInit;
		class Alias;
		class AndAssign;
		class ArrayAccess;
		class Assign;
		class BitAnd;
		class BitNot;
		class BitOr;
		class BitXor;
		class Cast;
		class CombinedImageAccessCall;
		class Comma;
		class CompositeConstruct;
		class Copy;
		class Divide;
		class DivideAssign;
		class Equal;
		class FnCall;
		class Greater;
		class GreaterEqual;
		class Identifier;
		class Init;
		class IntrinsicCall;
		class Less;
		class LessEqual;
		class Literal;
		class LogAnd;
		class LogNot;
		class LogOr;
		class LShift;
		class LShiftAssign;
		class MbrSelect;
		class Minus;
		class MinusAssign;
		class Modulo;
		class ModuloAssign;
		class NotEqual;
		class OrAssign;
		class PostDecrement;
		class PostIncrement;
		class PreDecrement;
		class PreIncrement;
		class Question;
		class RShift;
		class RShiftAssign;
		class StorageImageAccessCall;
		class StreamAppend;
		class SwitchCase;
		class SwitchTest;
		class Swizzle;
		class Times;
		class TimesAssign;
		class UnaryMinus;
		class UnaryPlus;
		class XorAssign;

		struct DeleteExpr
		{
			SDAST_API void operator()( Expr * expr )const noexcept;
		};

		template< typename ExprT >
		using ExprPtrT = std::unique_ptr< ExprT, DeleteExpr >;

		using ExprPtr = ExprPtrT< Expr >;
		using AddPtr = ExprPtrT< Add >;
		using AddAssignPtr = ExprPtrT< AddAssign >;
		using AggrInitPtr = ExprPtrT< AggrInit >;
		using AliasPtr = ExprPtrT< Alias >;
		using AndAssignPtr = ExprPtrT< AndAssign >;
		using ArrayAccessPtr = ExprPtrT< ArrayAccess >;
		using AssignPtr = ExprPtrT< Assign >;
		using BitAndPtr = ExprPtrT< BitAnd >;
		using BitNotPtr = ExprPtrT< BitNot >;
		using BitOrPtr = ExprPtrT< BitOr >;
		using BitXorPtr = ExprPtrT< BitXor >;
		using CastPtr = ExprPtrT< Cast >;
		using CombinedImageAccessCallPtr = ExprPtrT< CombinedImageAccessCall >;
		using CommaPtr = ExprPtrT< Comma >;
		using CompositeConstructPtr = ExprPtrT< CompositeConstruct >;
		using CopyPtr = ExprPtrT< Copy >;
		using DividePtr = ExprPtrT< Divide >;
		using DivideAssignPtr = ExprPtrT< DivideAssign >;
		using EqualPtr = ExprPtrT< Equal >;
		using FnCallPtr = ExprPtrT< FnCall >;
		using GreaterPtr = ExprPtrT< Greater >;
		using GreaterEqualPtr = ExprPtrT< GreaterEqual >;
		using IdentifierPtr = ExprPtrT< Identifier >;
		using InitPtr = ExprPtrT< Init >;
		using IntrinsicCallPtr = ExprPtrT< IntrinsicCall >;
		using LessPtr = ExprPtrT< Less >;
		using LessEqualPtr = ExprPtrT< LessEqual >;
		using LiteralPtr = ExprPtrT< Literal >;
		using LogAndPtr = ExprPtrT< LogAnd >;
		using LogNotPtr = ExprPtrT< LogNot >;
		using LogOrPtr = ExprPtrT< LogOr >;
		using LShiftPtr = ExprPtrT< LShift >;
		using LShiftAssignPtr = ExprPtrT< LShiftAssign >;
		using MbrSelectPtr = ExprPtrT< MbrSelect >;
		using MinusPtr = ExprPtrT< Minus >;
		using MinusAssignPtr = ExprPtrT< MinusAssign >;
		using ModuloPtr = ExprPtrT< Modulo >;
		using ModuloAssignPtr = ExprPtrT< ModuloAssign >;
		using NotEqualPtr = ExprPtrT< NotEqual >;
		using OrAssignPtr = ExprPtrT< OrAssign >;
		using PostDecrementPtr = ExprPtrT< PostDecrement >;
		using PostIncrementPtr = ExprPtrT< PostIncrement >;
		using PreDecrementPtr = ExprPtrT< PreDecrement >;
		using PreIncrementPtr = ExprPtrT< PreIncrement >;
		using QuestionPtr = ExprPtrT< Question >;
		using RShiftPtr = ExprPtrT< RShift >;
		using RShiftAssignPtr = ExprPtrT< RShiftAssign >;
		using StorageImageAccessCallPtr = ExprPtrT< StorageImageAccessCall >;
		using StreamAppendPtr = ExprPtrT< StreamAppend >;
		using SwitchCasePtr = ExprPtrT< SwitchCase >;
		using SwitchTestPtr = ExprPtrT< SwitchTest >;
		using SwizzlePtr = ExprPtrT< Swizzle >;
		using TimesPtr = ExprPtrT< Times >;
		using TimesAssignPtr = ExprPtrT< TimesAssign >;
		using UnaryMinusPtr = ExprPtrT< UnaryMinus >;
		using UnaryPlusPtr = ExprPtrT< UnaryPlus >;
		using XorAssignPtr = ExprPtrT< XorAssign >;

		using VisitorPtr = Visitor *;
		using ExprList = std::vector< ExprPtr >;
		using SwitchCaseList = std::vector< SwitchCase * >;

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
		class StmtCache;
		class Visitor;

		class PreprocExtension;
		class PreprocVersion;
		class AccelerationStructureDecl;
		class Break;
		class BufferReferenceDecl;
		class CombinedImageDecl;
		class Comment;
		class Compound;
		class ConstantBufferDecl;
		class Container;
		class Continue;
		class Demote;
		class DispatchMesh;
		class DoWhile;
		class Else;
		class ElseIf;
		class For;
		class FragmentLayout;
		class FunctionDecl;
		class HitAttributeVariableDecl;
		class If;
		class IgnoreIntersection;
		class ImageDecl;
		class InOutCallableDataVariableDecl;
		class InOutRayPayloadVariableDecl;
		class InOutVariableDecl;
		class InputComputeLayout;
		class InputGeometryLayout;
		class InputTessellationEvaluationLayout;
		class OutputGeometryLayout;
		class OutputMeshLayout;
		class OutputTessellationControlLayout;
		class PerPrimitiveDecl;
		class PerVertexDecl;
		class PushConstantsBufferDecl;
		class Return;
		class SampledImageDecl;
		class SamplerDecl;
		class ShaderBufferDecl;
		class ShaderStructBufferDecl;
		class Simple;
		class SpecialisationConstantDecl;
		class StructureDecl;
		class Switch;
		class SwitchCase;
		class TerminateInvocation;
		class TerminateRay;
		class VariableDecl;
		class While;

		struct DeleteStmt
		{
			SDAST_API void operator()( Stmt * stmt )const noexcept;
		};

		template< typename StmtT >
		using StmtPtrT = std::unique_ptr< StmtT, DeleteStmt >;

		using StmtPtr = StmtPtrT< Stmt >;
		using PreprocExtensionPtr = StmtPtrT< PreprocExtension >;
		using PreprocVersionPtr = StmtPtrT< PreprocVersion >;
		using AccelerationStructureDeclPtr = StmtPtrT< AccelerationStructureDecl >;
		using BreakPtr = StmtPtrT< Break >;
		using BufferReferenceDeclPtr = StmtPtrT< BufferReferenceDecl >;
		using CombinedImageDeclPtr = StmtPtrT< CombinedImageDecl >;
		using CommentPtr = StmtPtrT< Comment >;
		using CompoundPtr = StmtPtrT< Compound >;
		using ConstantBufferDeclPtr = StmtPtrT< ConstantBufferDecl >;
		using ContainerPtr = StmtPtrT< Container >;
		using ContinuePtr = StmtPtrT< Continue >;
		using DemotePtr = StmtPtrT< Demote >;
		using DispatchMeshPtr = StmtPtrT< DispatchMesh >;
		using DoWhilePtr = StmtPtrT< DoWhile >;
		using ElsePtr = StmtPtrT< Else >;
		using ElseIfPtr = StmtPtrT< ElseIf >;
		using ForPtr = StmtPtrT< For >;
		using FragmentLayoutPtr = StmtPtrT< FragmentLayout >;
		using FunctionDeclPtr = StmtPtrT< FunctionDecl >;
		using HitAttributeVariableDeclPtr = StmtPtrT< HitAttributeVariableDecl >;
		using IfPtr = StmtPtrT< If >;
		using IgnoreIntersectionPtr = StmtPtrT< IgnoreIntersection >;
		using ImageDeclPtr = StmtPtrT< ImageDecl >;
		using InOutCallableDataVariableDeclPtr = StmtPtrT< InOutCallableDataVariableDecl >;
		using InOutRayPayloadVariableDeclPtr = StmtPtrT< InOutRayPayloadVariableDecl >;
		using InOutVariableDeclPtr = StmtPtrT< InOutVariableDecl >;
		using InputComputeLayoutPtr = StmtPtrT< InputComputeLayout >;
		using InputGeometryLayoutPtr = StmtPtrT< InputGeometryLayout >;
		using InputTessellationEvaluationLayoutPtr = StmtPtrT< InputTessellationEvaluationLayout >;
		using OutputGeometryLayoutPtr = StmtPtrT< OutputGeometryLayout >;
		using OutputMeshLayoutPtr = StmtPtrT< OutputMeshLayout >;
		using OutputTessellationControlLayoutPtr = StmtPtrT< OutputTessellationControlLayout >;
		using PerPrimitiveDeclPtr = StmtPtrT< PerPrimitiveDecl >;
		using PerVertexDeclPtr = StmtPtrT< PerVertexDecl >;
		using PushConstantsBufferDeclPtr = StmtPtrT< PushConstantsBufferDecl >;
		using ReturnPtr = StmtPtrT< Return >;
		using SampledImageDeclPtr = StmtPtrT< SampledImageDecl >;
		using SamplerDeclPtr = StmtPtrT< SamplerDecl >;
		using ShaderBufferDeclPtr = StmtPtrT< ShaderBufferDecl >;
		using ShaderStructBufferDeclPtr = StmtPtrT< ShaderStructBufferDecl >;
		using SimplePtr = StmtPtrT< Simple >;
		using SpecialisationConstantDeclPtr = StmtPtrT< SpecialisationConstantDecl >;
		using StructureDeclPtr = StmtPtrT< StructureDecl >;
		using SwitchPtr = StmtPtrT< Switch >;
		using SwitchCasePtr = StmtPtrT< SwitchCase >;
		using TerminateInvocationPtr = StmtPtrT< TerminateInvocation >;
		using TerminateRayPtr = StmtPtrT< TerminateRay >;
		using VariableDeclPtr = StmtPtrT< VariableDecl >;
		using WhilePtr = StmtPtrT< While >;

		using StmtList = std::vector< StmtPtr >;
		using ElseIfList = std::vector< ElseIfPtr >;

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
	}

	struct AttributeInfo
	{
		type::TypePtr type;
		uint32_t location;

		SDAST_API bool operator==( AttributeInfo const & rhs )const = default;
	};

	inline std::strong_ordering operator<=>( AttributeInfo const & lhs
		, AttributeInfo const & rhs )
	{
		return lhs.location <=> rhs.location;
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

		SDAST_API bool operator==( InOutInfo const & rhs )const = default;
	};

	inline bool operator<( InOutInfo const & lhs
		, InOutInfo const & rhs )
	{
		return lhs.type < rhs.type;
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

		SDAST_API bool operator==( DescriptorBinding const & rhs )const = default;
	};

	inline std::strong_ordering operator<=>( DescriptorBinding const & lhs
		, DescriptorBinding const & rhs )
	{
		if ( auto c = lhs.set <=> rhs.set; c !=std::strong_ordering::equal )
		{
			return c;
		}

		return lhs.binding <=> rhs.binding;
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
	class ShaderBuilder;

	using ShaderPtr = std::unique_ptr< Shader >;
	using ShaderArray = std::vector< Shader >;
	using ShaderPtrArray = std::vector< ShaderPtr >;
}

#endif
