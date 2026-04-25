/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Writer_H___
#define ___SDW_Writer_H___

#include "ShaderWriter/BaseTypes/HitAttribute.hpp"
#include "ShaderWriter/BaseTypes/RayPayload.hpp"
#include "ShaderWriter/BaseTypes/SampledImage.hpp"
#include "ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp"
#include "ShaderWriter/CompositeTypes/BufferReference.hpp"
#include "ShaderWriter/CompositeTypes/Builtins.hpp"
#include "ShaderWriter/CompositeTypes/Function.hpp"
#include "ShaderWriter/CompositeTypes/PushConstantBuffer.hpp"
#include "ShaderWriter/CompositeTypes/StorageBuffer.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/UniformBuffer.hpp"
#include "ShaderWriter/CompositeTypes/StorageBuffer.hpp"
#include "ShaderWriter/Helpers.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/ShaderBuilder.hpp>
#include <ShaderAST/Stmt/StmtIf.hpp>
#include <ShaderAST/Stmt/StmtSwitch.hpp>

#include <functional>

#pragma GCC diagnostic ignored "-Wshadow"

#ifdef None
#	undef None
#endif

namespace sdw
{
	struct RayFlags
	{
		static UInt32 None()
		{
			return UInt32{ uint32_t( ast::RayFlag::eNone ) };
		}
		static UInt32 Opaque()
		{
			return UInt32{ uint32_t( ast::RayFlag::eOpaque ) };
		}
		static UInt32 NoOpaque()
		{
			return UInt32{ uint32_t( ast::RayFlag::eNoOpaque ) };
		}
		static UInt32 TerminateOnFirstHit()
		{
			return UInt32{ uint32_t( ast::RayFlag::eTerminateOnFirstHit ) };
		}
		static UInt32 SkipClosestHitShader()
		{
			return UInt32{ uint32_t( ast::RayFlag::eSkipClosestHitShader ) };
		}
		static UInt32 CullBackFacingTriangles()
		{
			return UInt32{ uint32_t( ast::RayFlag::eCullBackFacingTriangles ) };
		}
		static UInt32 CullFrontFacingTriangles()
		{
			return UInt32{ uint32_t( ast::RayFlag::eCullFrontFacingTriangles ) };
		}
		static UInt32 CullOpaque()
		{
			return UInt32{ uint32_t( ast::RayFlag::eCullOpaque ) };
		}
		static UInt32 CullNoOpaque()
		{
			return UInt32{ uint32_t( ast::RayFlag::eCullNoOpaque ) };
		}
	};

	struct RayHitKinds
	{
		static UInt32 FrontFacingTriangle()
		{
			return UInt32{ uint32_t( ast::RayHitKind::eFrontFacingTriangle ) };
		}
		static UInt32 BackFacingTriangle()
		{
			return UInt32{ uint32_t( ast::RayHitKind::eBackFacingTriangle ) };
		}
	};

	class ShaderWriter
	{
	protected:
		SDW_API explicit ShaderWriter( ast::ShaderStage type
			, ShaderAllocator * allocator = nullptr );
		SDW_API explicit ShaderWriter( ShaderBuilder & builder );
		SDW_API ~ShaderWriter()noexcept;

	public:
#pragma region Type registration
		/**
		*\name
		*	Variables registration.
		*/
		/**@{*/
		template< typename TypeT, typename ... ParamsT >
		type::StructPtr declType( ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Variables registration
		/**
		*\name
		*	Variables registration.
		*/
		/**@{*/
		SDW_API bool hasGlobalVariable( std::string_view name )const;
		SDW_API bool hasVariable( std::string_view name
			, bool isLocale )const;
		SDW_API var::VariablePtr getVariable( std::string_view name
			, bool isLocale )const;
		SDW_API var::VariablePtr registerName( std::string name
			, type::TypePtr type
			, uint64_t flags );
		SDW_API var::VariablePtr registerLocale( std::string name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerLoopVar( std::string name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInParam( std::string name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutParam( std::string name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInOutParam( std::string name
			, type::TypePtr type );
		SDW_API void addStmt( stmt::StmtPtr stmt );
		SDW_API void addGlobalStmt( stmt::StmtPtr stmt );
		SDW_API void registerSsbo( std::string name
			, SsboInfo const & info );
		SDW_API void registerUbo( std::string name
			, UboInfo const & info );
		/**@}*/
#pragma endregion
#pragma region Functions
		/**
		*\name
		*	Functions
		*/
		/**@{*/
		template< typename ReturnT, typename ... ParamsT >
		Function< ReturnT, ParamsT... > implementFunction( std::string name
			, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
			, ParamsT && ... params );
		template< typename ReturnT, typename ... ParamsT >
		Function< ReturnT, ParamsT... > implementFunction( std::string name
			, ast::stmt::FunctionFlag flag
			, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
			, ParamsT && ... params );
		template< typename ReturnT, typename ... ParamsT >
		Function< ReturnT, ParamsT... > implementFunction( std::string name
			, uint32_t flags
			, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
			, ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Cast
		/**
		*\name
		*	Cast.
		*/
		/**@{*/
		template< typename DestT >
		DestT cast( int32_t from );
		template< typename DestT >
		DestT cast( uint32_t from );
		template< typename DestT >
		DestT cast( float from );
		template< typename DestT >
		DestT cast( double from );
		template< typename DestT, typename SourceT >
		DestT cast( SourceT const & from );
		/**@}*/
#pragma endregion
#pragma region Control statements
		/**
		*\name
		*	Control statements.
		*/
		/**@{*/
		SDW_API void demote();
		SDW_API void terminate();
		SDW_API void returnStmt();
		template< typename RetType >
		void returnStmt( RetType const & value );
		SDW_API void pushScope();
		SDW_API void popScope();
		SDW_API void saveNextExpr();
		SDW_API ast::expr::ExprPtr loadExpr( Value const & value );
		template< typename ExprType >
		ExprType ternary( expr::ExprPtr condition
			, expr::ExprPtr left
			, expr::ExprPtr right );
		template< typename ExprType >
		ExprType ternary( Boolean condition
			, ExprType left
			, ExprType right );
		template< typename ExprType >
		ExprType ternary( Boolean condition
			, ReturnWrapperT< ExprType > left
			, ExprType right );
		template< typename ExprType >
		ExprType ternary( Boolean condition
			, ExprType left
			, ReturnWrapperT< ExprType > right );
		template< typename InitT, typename CondT, typename IncrT >
		void forStmt( InitT & loopVar
			, InitT const & init
			, CondT const & condition
			, IncrT const & increment
			, std::function< void() > const & function );
		SDW_API void forStmt( expr::ExprPtr init
			, expr::ExprPtr condition
			, expr::ExprPtr increment
			, std::function< void() > const & function );
		SDW_API void doWhileStmt( expr::ExprPtr condition
			, std::function< void() > const & function );
		SDW_API void doWhileStmt( sdw::Boolean const condition
			, std::function< void() > const & function );
		SDW_API void whileStmt( expr::ExprPtr condition
			, std::function< void() > const & function );
		SDW_API void whileStmt( sdw::Boolean const condition
			, std::function< void() > const & function );
		SDW_API ShaderWriter & ifStmt( sdw::Boolean const condition
			, std::function< void() > const & function );
		SDW_API ShaderWriter & ifStmt( expr::ExprPtr condition
			, std::function< void() > const & function );
		SDW_API ShaderWriter & elseIfStmt( sdw::Boolean const condition
			, std::function< void() > const & function );
		SDW_API ShaderWriter & elseIfStmt( expr::ExprPtr condition
			, std::function< void() > const & function );
		SDW_API ShaderWriter & elseStmt( std::function< void() > const & function );
		SDW_API void endIf();
		SDW_API ShaderWriter & switchStmt( expr::ExprPtr value
			, std::function< void() > const & function );
		SDW_API void endSwitch();
		SDW_API void caseStmt( expr::LiteralPtr literal
			, std::function< void() > const & function );
		SDW_API void defaultStmt( std::function< void() > const & function );
		SDW_API void caseBreakStmt();
		SDW_API void loopBreakStmt();
		SDW_API void loopContinueStmt();
		/**@}*/
#pragma endregion
#pragma region Constant declaration
		/**
		*\name
		*	Shader invocation and memory control.
		*/
		/**@{*/
		SDW_API void controlBarrier( type::Scope executionScope
			, type::Scope memoryScope
			, type::MemorySemantics semantics );
		SDW_API void memoryBarrier( type::Scope memoryScope
			, type::MemorySemantics semantics );

		SDW_API void memoryBarrier();
		SDW_API void memoryBarrierBuffer();
		SDW_API void memoryBarrierShared();
		SDW_API void memoryBarrierImage();
		SDW_API void groupMemoryBarrier();

		SDW_API void subgroupBarrier();
		SDW_API void subgroupMemoryBarrier();
		SDW_API void subgroupMemoryBarrierBuffer();
		SDW_API void subgroupMemoryBarrierShared();
		SDW_API void subgroupMemoryBarrierImage();

		/**@}*/
#pragma endregion
#pragma region Constant declaration
		/**
		*\name
		*	Constant declaration (#define name value).
		*/
		/**@{*/
		template< typename T >
		T declConstant( std::string name
			, T const & rhs
			, bool enabled = true );
		template< typename T >
		Array< T > declConstantArray( std::string name
			, std::vector< T > const & rhs
			, bool enabled = true );
		template< typename T >
		T declConstant( std::string name
			, ReturnWrapperT< T > const & rhs
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Specialisation constant declaration
		/**
		*\name
		*	Specialisation constant declaration.
		*/
		/**@{*/
		SDW_API Boolean declSpecConstant( std::string name
			, uint32_t location
			, bool rhs
			, bool enabled = true );
		SDW_API Int8 declSpecConstant( std::string name
			, uint32_t location
			, int8_t rhs
			, bool enabled = true );
		SDW_API Int16 declSpecConstant( std::string name
			, uint32_t location
			, int16_t rhs
			, bool enabled = true );
		SDW_API Int32 declSpecConstant( std::string name
			, uint32_t location
			, int32_t rhs
			, bool enabled = true );
		SDW_API Int64 declSpecConstant( std::string name
			, uint32_t location
			, int64_t rhs
			, bool enabled = true );
		SDW_API UInt8 declSpecConstant( std::string name
			, uint32_t location
			, uint8_t rhs
			, bool enabled = true );
		SDW_API UInt16 declSpecConstant( std::string name
			, uint32_t location
			, uint16_t rhs
			, bool enabled = true );
		SDW_API UInt32 declSpecConstant( std::string name
			, uint32_t location
			, uint32_t rhs
			, bool enabled = true );
		SDW_API UInt64 declSpecConstant( std::string name
			, uint32_t location
			, uint64_t rhs
			, bool enabled = true );
		SDW_API Float declSpecConstant( std::string name
			, uint32_t location
			, float rhs
			, bool enabled = true );
		SDW_API Double declSpecConstant( std::string name
			, uint32_t location
			, double rhs
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Sampler declaration
		/**
		*\name
		*	Sampler declaration.
		*/
		/**@{*/
		template< typename BindingT, typename SetT >
		SamplerT< false > declSampler( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< bool ComparisonT, typename BindingT, typename SetT >
		SamplerT< ComparisonT > declSampler( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		T declSampler( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename BindingT, typename SetT >
		Array< SamplerT< false > > declSamplerArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< bool ComparisonT, typename BindingT, typename SetT >
		Array< SamplerT< ComparisonT > > declSamplerArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declSamplerArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename BindingT, typename SetT >
		Array< SamplerT< false > > declSamplerArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< bool ComparisonT, typename BindingT, typename SetT >
		Array< SamplerT< ComparisonT > > declSamplerArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declSamplerArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< bool ComparisonT = false >
		SamplerT< ComparisonT > declSampler( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< typename T >
		T declSampler( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< bool ComparisonT = false >
		Array< SamplerT< ComparisonT > > declSamplerArray( std::string name
				, LocationHelper location
				, bool enabled = true );
		template< typename T >
		Array< T > declSamplerArray( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< bool ComparisonT = false >
		Array< SamplerT< ComparisonT > > declSamplerArray( std::string name
				, LocationHelper location
				, uint32_t dimension
				, bool enabled = true );
		template< typename T >
		Array< T > declSamplerArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Sampled Image declaration
		/**
		*\name
		*	Combined Sampler and Image declaration.
		*/
		/**@{*/
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		SampledImageT< FormatT, DimT, ArrayedT, MsT > declSampledImg( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		T declSampledImg( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > declSampledImgArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declSampledImgArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > declSampledImgArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declSampledImgArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		SampledImageT< FormatT, DimT, ArrayedT, MsT > declSampledImg( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< typename T >
		T declSampledImg( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > declSampledImgArray( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< typename T >
		Array< T > declSampledImgArray( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > declSampledImgArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		Array< T > declSampledImgArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Combined Sampler and Image declaration
		/**
		*\name
		*	Combined Sampler and Image declaration.
		*/
		/**@{*/
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > declCombinedImg( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT
			, typename BindingT, typename SetT >
		CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > declCombinedImg( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		T declCombinedImg( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > > declCombinedImgArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT
			, typename BindingT, typename SetT >
		Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > declCombinedImgArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declCombinedImgArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > > declCombinedImgArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT
			, typename BindingT, typename SetT >
		Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > declCombinedImgArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declCombinedImgArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT = false >
		CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > declCombinedImg( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< typename T >
		T declCombinedImg( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT = false >
		Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > declCombinedImgArray( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< typename T >
		Array< T > declCombinedImgArray( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT = false >
		Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > declCombinedImgArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		Array< T > declCombinedImgArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Storage Image declaration
		/**
		*\name
		*	Storage Image declaration.
		*/
		/**@{*/
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > declStorageImg( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		T declStorageImg( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > declStorageImgArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declStorageImgArray( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename BindingT, typename SetT >
		Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > declStorageImgArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT >
		Array< T > declStorageImgArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > declStorageImg( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< typename T >
		T declStorageImg( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > declStorageImgArray( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< typename T >
		Array< T > declStorageImgArray( std::string name
			, LocationHelper location
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > declStorageImgArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		Array< T > declStorageImgArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Shared variables declaration
		/**
		*\name
		*	Shared variables declaration.
		*/
		/**@{*/
		template< typename T, typename ... ParamsT >
		T declSharedVariable( std::string name
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename ... ParamsT >
		Array< T > declSharedVariable( std::string name
			, uint32_t dimension
			, bool enabled = true
			, ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Ray tracing variables declaration
		/**
		*\name
		*	Ray tracing variables declaration.
		*/
		/**@{*/
		template< typename T >
		RayPayloadT< T > declRayPayload( std::string name
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		RayPayloadInT< T > declIncomingRayPayload( std::string name
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		CallableDataT< T > declCallableData( std::string name
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		CallableDataInT< T > declIncomingCallableData( std::string name
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		HitAttributeT< T > declHitAttribute( std::string name
			, bool enabled = true );
		template< typename BindingT, typename SetT >
		AccelerationStructure declAccelerationStructure( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Uniform buffer declaration
		/**
		*\name
		*	Uniform buffer declaration.
		*/
		/**@{*/
		template< typename BindingT, typename SetT >
		UniformBuffer declUniformBuffer( std::string name
			, BindingT binding
			, SetT set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT, typename ... ParamsT >
		T declUniformBuffer( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true
			, ParamsT && ... params );
		SDW_INL_API UniformBuffer declUniformBuffer( std::string name
			, LocationHelper location
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140
			, bool enabled = true );
		template< typename T, typename ... ParamsT >
		T declUniformBuffer( std::string name
			, LocationHelper location
			, bool enabled = true
			, ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Shader storage buffer declaration
		/**
		*\name
		*	Shader storage buffer declaration.
		*/
		/**@{*/
		template< typename BindingT, typename SetT >
		StorageBuffer declStorageBuffer( std::string name
			, BindingT binding
			, SetT set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		SDW_INL_API StorageBuffer declStorageBuffer( std::string name
			, LocationHelper location
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT, typename ... ParamsT >
		T declStorageBuffer( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename ... ParamsT >
		T declStorageBuffer( std::string name
			, LocationHelper location
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename BindingT, typename SetT, typename ... ParamsT >
		Array< T > declStorageBufferArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename ... ParamsT >
		Array< T > declStorageBufferArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true
			, ParamsT && ... params );
		template< typename BindingT, typename SetT >
		ArrayStorageBuffer declArrayStorageBuffer( std::string name
			, BindingT binding
			, SetT set
			, Struct const & dataType
			, bool enabled = true );
		SDW_INL_API ArrayStorageBuffer declArrayStorageBuffer( std::string name
			, LocationHelper location
			, Struct const & dataType
			, bool enabled = true );
		template< typename BindingT, typename SetT >
		Array< ArrayStorageBuffer > declArrayStorageBufferArray( std::string name
			, BindingT binding
			, SetT set
			, Struct const & dataType
			, uint32_t dimension
			, bool enabled = true );
		SDW_INL_API Array< ArrayStorageBuffer > declArrayStorageBufferArray( std::string name
			, LocationHelper location
			, Struct const & dataType
			, uint32_t dimension
			, bool enabled = true );
		template< typename BindingT, typename SetT >
		ArrayStorageBuffer declArrayStorageBuffer( std::string name
			, BindingT binding
			, SetT set
			, Struct const & dataType
			, ast::type::MemoryLayout layout
			, bool enabled = true );
		SDW_INL_API ArrayStorageBuffer declArrayStorageBuffer( std::string name
			, LocationHelper location
			, Struct const & dataType
			, ast::type::MemoryLayout layout
			, bool enabled = true );
		template< typename BindingT, typename SetT >
		Array< ArrayStorageBuffer > declArrayStorageBufferArray( std::string name
			, BindingT binding
			, SetT set
			, Struct const & dataType
			, uint32_t dimension
			, ast::type::MemoryLayout layout
			, bool enabled = true );
		SDW_INL_API Array< ArrayStorageBuffer > declArrayStorageBufferArray( std::string name
			, LocationHelper location
			, Struct const & dataType
			, uint32_t dimension
			, ast::type::MemoryLayout layout
			, bool enabled = true );
		template< typename T, typename BindingT, typename SetT, typename ... ParamsT >
		ArrayStorageBufferT< T > declArrayStorageBuffer( std::string name
			, BindingT binding
			, SetT set
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename ... ParamsT >
		ArrayStorageBufferT< T > declArrayStorageBuffer( std::string name
			, LocationHelper location
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename BindingT, typename SetT, typename ... ParamsT >
		Array< ArrayStorageBufferT< T > > declArrayStorageBufferArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename ... ParamsT >
		Array< ArrayStorageBufferT< T > > declArrayStorageBufferArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename BindingT, typename SetT, typename ... ParamsT >
		ArrayStorageBufferT< T > declArrayStorageBuffer( std::string name
			, BindingT binding
			, SetT set
			, ast::type::MemoryLayout layout
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename ... ParamsT >
		ArrayStorageBufferT< T > declArrayStorageBuffer( std::string name
			, LocationHelper location
			, ast::type::MemoryLayout layout
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename BindingT, typename SetT, typename ... ParamsT >
		Array< ArrayStorageBufferT< T > > declArrayStorageBufferArray( std::string name
			, BindingT binding
			, SetT set
			, uint32_t dimension
			, ast::type::MemoryLayout layout
			, bool enabled = true
			, ParamsT && ... params );
		template< typename T, typename ... ParamsT >
		Array< ArrayStorageBufferT< T > > declArrayStorageBufferArray( std::string name
			, LocationHelper location
			, uint32_t dimension
			, ast::type::MemoryLayout layout
			, bool enabled = true
			, ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Buffer reference declaration
		/**
		*\name
		*	Buffer reference declaration.
		*/
		/**@{*/
		template< typename BufferT, typename ... ParamsT >
		BufferReferenceT< BufferT > declBufferReference( std::string name
			, ast::type::MemoryLayout layout
			, ast::type::Storage storage
			, bool enabled = true
			, ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Push constants buffer declaration
		/**
		*\name
		*	Push constants buffer declaration.
		*/
		/**@{*/
		template< typename T = PushConstantBuffer, typename ... ParamsT >
		T declPushConstantsBuffer( std::string name
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eC
			, bool enabled = true
			, ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Struct declaration
		/**
		*\name
		*	Struct declaration.
		*/
		/**@{*/
		template< typename T = Struct, typename ... ParamsT >
		T declStruct( std::string name
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eC
			, ParamsT && ... params );
		/**@}*/
#pragma endregion
#pragma region Locale declaration
		/**
		*\name
		*	Locale variable declaration.
		*/
		/**@{*/
		template< typename InstanceT >
		InstanceT declLocale( std::string name
			, Struct const & type
			, bool enabled = true );
		template< typename T >
		T declLocale( std::string name
			, bool enabled = true );
		template< typename T >
		T declLocale( std::string name
			, T const & rhs );
		template< typename T >
		T declLocale( std::string name
			, T const & rhs
			, bool enabled );
		template< typename T, typename ... ParamsT >
		T declLocale( std::string name
			, bool enabled
			, ParamsT && ... params );
		template< typename T >
		T declLocale( std::string name
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		Array< T > declLocaleArray( std::string name
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		Array< T > declLocaleArray( std::string name
			, uint32_t dimension
			, std::vector< T > const & rhs
			, bool enabled = true );
		template< typename T >
		Array< T > declLocale( std::string name
			, Array< T > const & rhs );
		template< typename T >
		Array< T > declLocale( std::string name
			, Array< T > const & rhs
			, bool enabled );
		template< typename T >
		Array< T > declLocaleArray( std::string name
			, uint32_t dimension
			, bool enabled
			, std::vector< T > const & defaultValue );
		template< typename T >
		T declLocale( std::string name
			, ReturnWrapperT< T > const & rhs
			, bool enabled = true );
		template< typename T >
		T declLocale( std::string name
			, DefaultedT< T > rhs
			, bool enabled = true );
		template< typename T >
		T declLocale( std::string name
			, bool enabled
			, ReturnWrapperT< T > const & defaultValue );
		template< typename BaseT, typename DerivedT >
		std::unique_ptr< BaseT > declDerivedLocale( std::string name
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Global variables declaration
		/**
		*\name
		*	Global variables declaration.
		*/
		/**@{*/
		template< typename InstanceT >
		InstanceT declGlobal( std::string name
			, Struct const & type
			, bool enabled = true );
		template< typename T >
		T declGlobal( std::string name
			, bool enabled = true );
		template< typename T >
		T declGlobal( std::string name
			, T const & rhs );
		template< typename T >
		T declGlobal( std::string name
			, T const & rhs
			, bool enabled );
		template< typename T, typename ... ParamsT >
		T declGlobal( std::string name
			, bool enabled
			, ParamsT && ... params );
		template< typename T >
		T declGlobal( std::string name
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		Array< T > declGlobalArray( std::string name
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		Array< T > declGlobalArray( std::string name
			, uint32_t dimension
			, std::vector< T > const & rhs
			, bool enabled = true );
		template< typename T >
		Array< T > declGlobal( std::string name
			, Array< T > const & rhs );
		template< typename T >
		Array< T > declGlobal( std::string name
			, Array< T > const & rhs
			, bool enabled );
		template< typename T >
		Array< T > declGlobalArray( std::string name
			, uint32_t dimension
			, bool enabled
			, std::vector< T > const & defaultValue );
		template< typename T >
		T declGlobal( std::string name
			, ReturnWrapperT< T > rhs
			, bool enabled = true );
		template< typename T >
		T declGlobal( std::string name
			, DefaultedT< T > rhs
			, bool enabled = true );
		template< typename T >
		T declGlobal( std::string name
			, bool enabled
			, ReturnWrapperT< T > defaultValue );
		template< typename BaseT, typename DerivedT >
		std::unique_ptr< BaseT > declDerivedGlobal( std::string name
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Already declared variable getters
		/**
		*\name
		*	Already declared variable getters.
		*/
		/**@{*/
		template< typename T >
		T getVariable( std::string_view name
			, bool enabled = true );
		template< typename T >
		Array< T > getVariableArray( std::string_view name
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Getters
		/**
		*\name
		*	Getters.
		*/
		/**@{*/
		ast::Shader & getShader()const
		{
			return m_builder->getShader();
		}

		ast::ShaderBuilder & getBuilder()
		{
			return *m_builder;
		}

		ast::ShaderBuilder const & getBuilder()const
		{
			return *m_builder;
		}

		ast::stmt::StmtCache & getStmtCache()const
		{
			return m_builder->getStmtCache();
		}

		ast::expr::ExprCache & getExprCache()const
		{
			return m_builder->getExprCache();
		}

		ast::type::TypesCache & getTypesCache()const
		{
			return m_builder->getTypesCache();
		}
		/**@}*/
#pragma endregion

	protected:
		SDW_API var::VariablePtr registerStaticConstant( std::string name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerSpecConstant( std::string name
			, uint32_t location
			, type::TypePtr type );
		SDW_API var::VariablePtr registerAccelerationStructure( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerSampler( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerSampledImage( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerTexture( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerImage( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerUniformBuffer( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerStorageBuffer( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, var::Flag flag = var::Flag::eStorageBuffer
			, bool enabled = true );
		SDW_API var::VariablePtr registerInOut( std::string name
			, uint64_t attributes
			, type::TypePtr type );
		SDW_API var::VariablePtr registerBuiltin( ast::Builtin builtin
			, type::TypePtr type
			, var::Flag flag );

	private:
		std::unique_ptr< ast::ShaderBuilder > m_ownBuilder;
		ast::ShaderBuilder * m_builder{};
	};

	template< typename WriterT >
	struct WriterScopeT
	{
	private:
		WriterScopeT( WriterScopeT const & rhs ) = delete;
		WriterScopeT & operator=( WriterScopeT const & rhs ) = delete;

	public:
		WriterScopeT( WriterScopeT && rhs )noexcept
			: m_writer{ rhs.m_writer }
		{
			rhs.m_writer = nullptr;
		}

		WriterScopeT & operator=( WriterScopeT && rhs )noexcept
		{
			m_writer = rhs.m_writer;
			rhs.m_writer = nullptr;
			return *this;
		}

		explicit WriterScopeT( WriterT & writer )
			: m_writer{ &writer }
		{
			m_writer->pushScope();
		}

		~WriterScopeT()
		{
			if ( m_writer )
			{
				m_writer->popScope();
			}
		}

		explicit operator bool()const
		{
			return m_writer != nullptr;
		}

		WriterT * operator->()const
		{
			return m_writer;
		}

		WriterT & operator*()const
		{
			return *m_writer;
		}

	private:
		WriterT * m_writer;
	};

	template< typename WriterT >
	WriterScopeT< WriterT > makeScope( WriterT & writer )
	{
		return WriterScopeT< WriterT >{ writer };
	}
}

#if !defined( SDW_DISABLE_CTRL_MACROS )

#define sdwConcat( x, y ) sdwConcatImpl( x, y )
#define sdwConcatImpl( x, y ) x ## y

#define sdwFOR( Writer, Type, Name, Init, Cond, Incr )\
	if ( auto sdwConcat( writerScope, __LINE__ ) = makeScope( Writer ) )\
	{\
		Type Name{ Writer, sdw::makeExpr( Writer, ( Writer ).registerLoopVar( #Name, Type::makeType( ( Writer ).getTypesCache() ) ) ), true };\
		( Writer ).forStmt( Name, Type{ Init }, Cond, Incr\
			, [&]()noexcept

#define sdwROF\
 );\
	}

#define sdwWHILE( Writer, Condition )\
	( Writer ).whileStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define sdwELIHW\
 );

#define sdwDOWHILE( Writer, Condition )\
	( Writer ).doWhileStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define sdwELIHWOD\
 );

#define sdwIF( Writer, Condition )\
	( Writer ).ifStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define sdwELSE\
 ).elseStmt( [&]()noexcept

#define sdwELSEIF( Condition )\
 ).elseIfStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define sdwFI\
 ).endIf();

#define sdwSWITCH( Writer, Value )\
	if ( auto sdwConcat( writerScope, __LINE__ ) = makeScope( Writer ) )\
	{\
		( Writer ).switchStmt( sdw::makeExpr( Writer, Value )\
			, [&]()noexcept

#define sdwCASE( Writer, Literal )\
			( Writer ).caseStmt( sdw::makeLiteral( Writer, Literal )\
				, [&]()noexcept

#define sdwESAC\
 );

#define sdwDEFAULT( Writer )\
			( Writer ).defaultStmt( [&]()noexcept

#define sdwTLUAFED\
 );

#define sdwHCTIWS\
 ).endSwitch();\
	}

#endif

#include "Writer.inl"

#endif
