/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslHelpers_H___
#define ___SDW_HlslHelpers_H___
#pragma once

#include "CompilerHlsl/compileHlsl.hpp"

#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Expr/Expr.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtFunctionDecl.hpp>
#include <ShaderAST/Stmt/StmtInputGeometryLayout.hpp>
#include <ShaderAST/Stmt/StmtOutputGeometryLayout.hpp>

#include <set>
#include <unordered_set>

namespace hlsl
{
	class HlslShader;

	std::string getTypeName( ast::type::Kind kind );
	std::string getTypeName( ast::type::TypePtr type );
	std::string getTypeArraySize( ast::type::TypePtr type );
	std::string getLocationName( ast::var::Variable const & var );
	std::string getDirectionName( ast::var::Variable const & var );
	std::string getOperatorName( ast::expr::Kind kind );
	std::string getLayoutName( ast::type::InputLayout layout );
	std::string getLayoutName( ast::type::OutputLayout layout );
	std::string getCtorName( ast::expr::CompositeType composite
		, ast::type::Kind component );
	std::string getSampledName( ast::type::ImageFormat value );
	std::string getName( ast::type::ImageDim value );
	bool isUnaryPre( ast::expr::Kind kind );
	std::string adaptName( std::string const & name );

	struct Semantic
	{
		std::string name;
		uint32_t index;
	};
	ast::type::Kind getBuiltinHlslKind( ast::Builtin builtin
		, ast::type::Kind input );
	std::string getSemantic( ast::ShaderStage stage
		, ast::Builtin builtin
		, bool isInput
		, uint32_t location
		, ast::type::TypePtr type
		, Semantic & defaultSemantic );

	using LinkedVars = std::map< ast::var::VariablePtr, std::pair< ast::var::VariablePtr, ast::var::VariablePtr > >;
	LinkedVars::iterator updateLinkedVars( ast::var::VariablePtr var
		, LinkedVars & linkedVars
		, uint32_t & nextVarId );

	using VariableExprMap = std::map< ast::var::VariablePtr, ast::expr::ExprPtr >;
	using VariableIdMap = std::map< uint32_t, ast::var::VariablePtr >;

	struct FuncNames
	{
		std::map< std::string, ast::type::FunctionPtr > imageSizeFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicAddFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicMinFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicMaxFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicAndFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicOrFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicXorFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicExchangeFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageAtomicCompSwapFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageLodFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageLevelsFuncs;
		std::map< std::string, ast::type::FunctionPtr > imageStoreFuncs;
	};

	using VarReplacements = std::map< ast::var::VariablePtr, ast::expr::ExprPtr >;
	using VarVarMap = std::map< ast::var::VariablePtr, ast::var::VariablePtr >;

	struct AdaptationData;
	class ExprAdapter;

	struct PendingResult
	{
		uint32_t mbrIndex{ ast::type::Struct::NotFound };
		uint64_t flags{};
		ast::expr::ExprPtr expr{};
	};

	struct PendingIO
	{
		ast::var::VariablePtr var{};
		uint32_t location{ ast::type::Struct::InvalidLocation };
		uint64_t flags{};
		PendingResult result{};
	};

	struct PendingMbrIO
	{
		uint32_t mbrIndex{ ast::type::Struct::NotFound };
		uint32_t location{ ast::type::Struct::InvalidLocation };
		uint64_t flags{};
		PendingResult result{};
	};

	enum class IOMappingMode
	{
		eNoSeparate,
		eNoSeparateDistinctParams,
		eLocalReturn,
		eGlobalSeparateVar,
		eLocalSeparateVar,
	};

	struct IOMapping
	{
		IOMapping( HlslShader & pshader
			, IOMappingMode pmode
			, bool pisInput
			, bool pisPatch
			, std::string const & infix );

		HlslShader * shader;
		ast::ShaderStage stage;
		bool isInput;
		bool isPatch;
		IOMappingMode mode;
		// The final param.
		ast::type::IOStructPtr paramStruct{};
		ast::var::VariablePtr paramVar{};
		// Separate var, if a separate variable (global or local) is needed.
		ast::type::BaseStructPtr separateStruct{};
		ast::var::VariablePtr separateVar{};
		// The effectively written/read var.
		ast::var::VariablePtr mainVar{};
		// The distinct param vars.
		ast::var::VariableList distinctParams{};
		ast::var::VariableList unsupportedBuiltins{};

		void writeGlobals( ast::stmt::Container & stmt
			, std::unordered_set< ast::type::StructPtr > & declaredStructs )const;
		void writeLocalesBegin( ast::stmt::Container & stmt )const;
		void writeLocalesEnd( ast::stmt::Container & stmt )const;
		ast::type::TypePtr fillParameters( ast::var::VariableList & parameters
			, ast::stmt::Container & stmt )const;

		void initialiseMainVar( ast::var::VariablePtr srcVar
			, ast::type::TypePtr type
			, uint64_t flags
			, VarVarMap & paramToEntryPoint );
		void initialisePatchVar( ast::var::VariablePtr srcVar
			, ast::type::TypePtr type
			, uint64_t flags
			, VarVarMap & paramToEntryPoint );

		void addPending( ast::var::VariablePtr pendingVar
			, uint32_t location );
		void addPendingMbr( ast::var::VariablePtr outerVar
			, uint32_t mbrIndex
			, uint64_t flags
			, uint32_t location );
		void addPendingMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location );
		ast::expr::ExprPtr processPending( std::string const & name );
		ast::expr::ExprPtr processPending( ast::var::VariablePtr var );
		ast::expr::ExprPtr processPendingMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter );
		bool isValid( ast::Builtin builtin )const;
		bool hasSeparate()const;

	private:
		struct PendingMbrIO
		{
			ast::var::VariablePtr outer;
			uint32_t index;
			PendingIO io;
		};

		PendingResult processPendingType( ast::type::TypePtr type
			, std::string const & name
			, ast::Builtin builtin
			, uint64_t flags
			, uint32_t location
			, uint32_t arraySize
			, ast::type::IOStruct & structType );
		PendingResult processPendingType( ast::type::TypePtr type
			, std::string const & name
			, ast::Builtin builtin
			, uint64_t flags
			, uint32_t location );
		PendingResult processPendingType( ast::type::Struct const & structType
			, uint32_t mbrIndex
			, uint64_t mbrFlags
			, uint32_t mbrLocation );
		ast::expr::ExprPtr processPendingMbrOuter( ast::var::VariablePtr outerVar
			, uint32_t mbrIndex
			, std::vector< PendingMbrIO >::iterator & it );

	private:
		std::map< std::string, PendingIO > m_pending;
		std::vector< PendingMbrIO > m_pendingMbr;
	};

	struct Routine
	{
		friend struct AdaptationData;

		Routine( HlslShader & pshader
			, AdaptationData * pparent
			, bool pisMain
			, std::string const & name );

		void initialiseHFOutput( ast::var::VariablePtr srcVar
			, ast::type::GeometryOutput const & geomType );
		void initialiseHFOutput( ast::var::VariablePtr var
			, ast::type::TessellationControlOutput const & tessType );
		void initialiseHFOutput( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType );

		HlslShader * shader;
		AdaptationData * parent;
		bool isMain;
		bool needsSeparateFunc;
		VarVarMap paramToEntryPoint{};
		ast::stmt::Container * globalDeclarations{};

		void writeGlobals( ast::stmt::Container & cont
			, std::unordered_set< ast::type::StructPtr > & declaredStructs );
		void writeLocalesBegin( ast::stmt::Container & cont )const;
		void writeLocalesEnd( ast::stmt::Container & cont )const;
		ast::type::TypePtr fillParameters( ast::var::VariableList & parameters
			, ast::stmt::Container & stmt )const;

		ast::expr::ExprPtr processPending( ast::var::VariablePtr var );
		ast::expr::ExprPtr processPendingMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter );
		void addMbrBuiltin( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t index );

		IOMapping & getLFInputs();
		void addInputVar( ast::var::VariablePtr var
			, uint32_t location );
		bool hasSeparateLFInput()const;
		void addPendingInput( ast::var::VariablePtr var
			, uint32_t location );
		void addPendingMbrInput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location );
		ast::expr::ExprPtr processPendingInput( std::string const & name );
		ast::expr::ExprPtr processPendingInput( ast::var::VariablePtr var );
		ast::expr::ExprPtr processPendingMbrInput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter );

		IOMapping & getHFOutputs();
		IOMapping & getLFOutputs();
		bool isOutput( ast::Builtin builtin );
		bool hasSeparateHFOutput()const;
		void addOutputVar( ast::var::VariablePtr var
			, uint32_t location );
		bool hasSeparateLFOutput()const;
		void addPendingOutput( ast::var::VariablePtr var
			, uint32_t location );
		void addPendingMbrOutput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location );
		ast::expr::ExprPtr processPendingOutput( std::string const & name );
		ast::expr::ExprPtr processPendingOutput( ast::var::VariablePtr var );
		ast::expr::ExprPtr processPendingMbrOutput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter );

	private:
		void registerInputMbr( ast::var::VariablePtr var
			, uint64_t outerFlags
			, ast::Builtin mbrBuiltin
			, uint32_t mbrIndex
			, uint32_t mbrLocation );
		void registerOutputMbr( ast::var::VariablePtr var
			, uint64_t outerFlags
			, ast::Builtin mbrBuiltin
			, uint32_t mbrIndex
			, uint32_t mbrLocation );
		IOMapping & getInputMapping();
		IOMapping & getOutputMapping();

		private:
			IOMapping m_highFreqOutputs;
			IOMapping m_lowFreqInputs;
			IOMapping m_lowFreqOutputs;
	};

	using RoutinePtr = std::unique_ptr< Routine >;
	using RoutineMap = std::map< std::string, RoutinePtr >;

	struct AdaptationData
	{
		AdaptationData( HlslShader & shader );

		void addEntryPoint( ast::stmt::FunctionDecl const & stmt );
		void updateCurrentEntryPoint( ast::stmt::FunctionDecl const * stmt );
		bool needsSeparateFunc()const;
		void initialiseEntryPoint( ast::stmt::FunctionDecl const & stmt );

		ast::stmt::ContainerPtr writeGlobals( std::unordered_set< ast::type::StructPtr > & declaredStructs );
		ast::stmt::ContainerPtr writeLocalesBegin();
		ast::stmt::ContainerPtr writeLocalesEnd();
		ast::type::TypePtr fillParameters( ast::var::VariableList & parameters
			, ast::stmt::Container & stmt );
		ast::expr::ExprPtr processPending( ast::var::VariablePtr var );
		ast::expr::ExprPtr processPendingMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter );
		void addMbrBuiltin( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t index );

		IOMapping & getHFInputs();
		IOMapping & getLFInputs();
		void addInputVar( ast::var::VariablePtr var
			, uint32_t location );
		bool isInput( ast::Builtin builtin );
		bool hasSeparateHFInput()const;
		bool hasSeparateLFInput()const;
		void addPendingInput( ast::var::VariablePtr var
			, uint32_t location );
		void addPendingMbrInput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location );
		ast::expr::ExprPtr processPendingInput( std::string const & name );
		ast::expr::ExprPtr processPendingInput( ast::var::VariablePtr var );
		ast::expr::ExprPtr processPendingMbrInput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter );

		IOMapping & getHFOutputs();
		IOMapping & getLFOutputs();
		void addOutputVar( ast::var::VariablePtr var
			, uint32_t location );
		bool isOutput( ast::Builtin builtin );
		bool hasSeparateHFOutput()const;
		bool hasSeparateLFOutput()const;
		void addPendingOutput( ast::var::VariablePtr var
			, uint32_t location );
		void addPendingMbrOutput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location );
		ast::expr::ExprPtr processPendingOutput( std::string const & name );
		ast::expr::ExprPtr processPendingOutput( ast::var::VariablePtr var );
		ast::expr::ExprPtr processPendingMbrOutput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter );

		void setHlslType( ast::type::TypePtr orig
			, ast::type::TypePtr repl )
		{
			m_replacedTypes.emplace( orig, repl );
		}

		bool isHlslType( ast::type::TypePtr type )const
		{
			auto it = std::find_if( m_replacedTypes.begin()
				, m_replacedTypes.end()
				, [&type]( auto const & lookup )
				{
					return lookup.second == type;
				} );
			return it != m_replacedTypes.end();
		}

		ast::type::TypePtr getHlslType( ast::type::TypePtr type )const
		{
			auto it = m_replacedTypes.find( type );

			if ( it == m_replacedTypes.end() )
			{
				return type;
			}

			return it->second;
		}

		RoutineMap const & getRoutines()const
		{
			return m_routines;
		}

	private:
		void declareStruct( ast::type::StructPtr const & structType
			, ast::stmt::Container * stmt );
		void registerParam( ast::var::VariablePtr var
			, ast::type::FragmentInput const & fragType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::ComputeInput const & compType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::GeometryInput const & geomType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::GeometryOutput const & geomType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationInputPatch const & patchType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType
			, bool isEntryPoint );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationControlInput const & tessType
			, bool isEntryPoint );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationControlOutput const & tessType
			, bool isEntryPoint );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationEvaluationInput const & tessType );
		void registerInput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, bool isEntryPoint );
		void registerOutput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, bool isEntryPoint );
		void registerInputMbr( ast::var::VariablePtr var
			, uint64_t outerFlags
			, ast::Builtin mbrBuiltin
			, uint32_t mbrIndex
			, uint32_t mbrLocation );
		void registerOutputMbr( ast::var::VariablePtr var
			, uint64_t outerFlags
			, ast::Builtin mbrBuiltin
			, uint32_t mbrIndex
			, uint32_t mbrLocation );

	private:
		IOMapping m_highFreqInputs;
		std::unique_ptr< IOMapping > m_patchInputs;
		RoutineMap m_routines;
		Routine * m_mainEntryPoint{};
		Routine * m_currentRoutine{};
		std::unordered_set< ast::type::StructPtr > m_declaredStructs;
		std::map< ast::type::TypePtr, ast::type::TypePtr > m_replacedTypes;

	public:
		HlslShader * shader;
		ast::var::VariableList ssboList;
		LinkedVars linkedVars;
		FuncNames funcs;
		VarReplacements replacedVars;

		uint32_t aliasId{ 0u };
		uint32_t nextVarId{ 0u };
	};

	struct IntrinsicsConfig
	{
		bool requiresShadowSampler{ false };

		bool requiresACosh1F{ false };
		bool requiresACosh2F{ false };
		bool requiresACosh3F{ false };
		bool requiresACosh4F{ false };
		bool requiresASinh1F{ false };
		bool requiresASinh2F{ false };
		bool requiresASinh3F{ false };
		bool requiresASinh4F{ false };
		bool requiresATanh1F{ false };
		bool requiresATanh2F{ false };
		bool requiresATanh3F{ false };
		bool requiresATanh4F{ false };
		bool requiresRoundEven1F{ false };
		bool requiresRoundEven2F{ false };
		bool requiresRoundEven3F{ false };
		bool requiresRoundEven4F{ false };
		bool requiresRoundEven1D{ false };
		bool requiresRoundEven2D{ false };
		bool requiresRoundEven3D{ false };
		bool requiresRoundEven4D{ false };
		bool requiresPackDouble2x32{ false };
		bool requiresPackHalf2x16{ false };
		bool requiresPackSnorm2x16{ false };
		bool requiresPackSnorm4x8{ false };
		bool requiresPackUnorm2x16{ false };
		bool requiresPackUnorm4x8{ false };
		bool requiresUnpackDouble2x32{ false };
		bool requiresUnpackHalf2x16{ false };
		bool requiresUnpackSnorm2x16{ false };
		bool requiresUnpackSnorm4x8{ false };
		bool requiresUnpackUnorm2x16{ false };
		bool requiresUnpackUnorm4x8{ false };
		bool requiresInverse2x2F{ false };
		bool requiresInverse3x3F{ false };
		bool requiresInverse4x4F{ false };
		bool requiresInverse2x2D{ false };
		bool requiresInverse3x3D{ false };
		bool requiresInverse4x4D{ false };
		bool requiresUaddCarry1{ false };
		bool requiresUaddCarry2{ false };
		bool requiresUaddCarry3{ false };
		bool requiresUaddCarry4{ false };
		bool requiresUsubBorrow1{ false };
		bool requiresUsubBorrow2{ false };
		bool requiresUsubBorrow3{ false };
		bool requiresUsubBorrow4{ false };
		bool requiresUmulExtended1{ false };
		bool requiresUmulExtended2{ false };
		bool requiresUmulExtended3{ false };
		bool requiresUmulExtended4{ false };
		bool requiresImulExtended1{ false };
		bool requiresImulExtended2{ false };
		bool requiresImulExtended3{ false };
		bool requiresImulExtended4{ false };
		bool requiresBitfieldExtract1I{ false };
		bool requiresBitfieldExtract2I{ false };
		bool requiresBitfieldExtract3I{ false };
		bool requiresBitfieldExtract4I{ false };
		bool requiresBitfieldExtract1U{ false };
		bool requiresBitfieldExtract2U{ false };
		bool requiresBitfieldExtract3U{ false };
		bool requiresBitfieldExtract4U{ false };
		bool requiresBitfieldInsert1I{ false };
		bool requiresBitfieldInsert2I{ false };
		bool requiresBitfieldInsert3I{ false };
		bool requiresBitfieldInsert4I{ false };
		bool requiresBitfieldInsert1U{ false };
		bool requiresBitfieldInsert2U{ false };
		bool requiresBitfieldInsert3U{ false };
		bool requiresBitfieldInsert4U{ false };
		bool requiresBitfieldReverse1I{ false };
		bool requiresBitfieldReverse2I{ false };
		bool requiresBitfieldReverse3I{ false };
		bool requiresBitfieldReverse4I{ false };

		bool requiresTextureSizeBufferF{ false };
		bool requiresTextureSize1DF{ false };
		bool requiresTextureSize2DF{ false };
		bool requiresTextureSize3DF{ false };
		bool requiresTextureSizeCubeF{ false };
		bool requiresTextureSize2DRectF{ false };
		bool requiresTextureSize1DArrayF{ false };
		bool requiresTextureSize2DArrayF{ false };
		bool requiresTextureSizeCubeArrayF{ false };
		bool requiresTextureSize1DShadowF{ false };
		bool requiresTextureSize2DShadowF{ false };
		bool requiresTextureSizeCubeShadowF{ false };
		bool requiresTextureSize2DRectShadowF{ false };
		bool requiresTextureSize1DArrayShadowF{ false };
		bool requiresTextureSize2DArrayShadowF{ false };
		bool requiresTextureSizeCubeArrayShadowF{ false };
		bool requiresTextureSizeBufferI{ false };
		bool requiresTextureSize1DI{ false };
		bool requiresTextureSize2DI{ false };
		bool requiresTextureSize3DI{ false };
		bool requiresTextureSizeCubeI{ false };
		bool requiresTextureSize2DRectI{ false };
		bool requiresTextureSize1DArrayI{ false };
		bool requiresTextureSize2DArrayI{ false };
		bool requiresTextureSizeCubeArrayI{ false };
		bool requiresTextureSizeBufferU{ false };
		bool requiresTextureSize1DU{ false };
		bool requiresTextureSize2DU{ false };
		bool requiresTextureSize3DU{ false };
		bool requiresTextureSizeCubeU{ false };
		bool requiresTextureSize2DRectU{ false };
		bool requiresTextureSize1DArrayU{ false };
		bool requiresTextureSize2DArrayU{ false };
		bool requiresTextureSizeCubeArrayU{ false };
		bool requiresTextureQueryLod1DF{ false };
		bool requiresTextureQueryLod2DF{ false };
		bool requiresTextureQueryLod3DF{ false };
		bool requiresTextureQueryLodCubeF{ false };
		bool requiresTextureQueryLod1DArrayF{ false };
		bool requiresTextureQueryLod2DArrayF{ false };
		bool requiresTextureQueryLodCubeArrayF{ false };
		bool requiresTextureQueryLod1DShadowF{ false };
		bool requiresTextureQueryLod2DShadowF{ false };
		bool requiresTextureQueryLodCubeShadowF{ false };
		bool requiresTextureQueryLod1DArrayShadowF{ false };
		bool requiresTextureQueryLod2DArrayShadowF{ false };
		bool requiresTextureQueryLodCubeArrayShadowF{ false };
		bool requiresTextureQueryLod1DI{ false };
		bool requiresTextureQueryLod2DI{ false };
		bool requiresTextureQueryLod3DI{ false };
		bool requiresTextureQueryLodCubeI{ false };
		bool requiresTextureQueryLod1DArrayI{ false };
		bool requiresTextureQueryLod2DArrayI{ false };
		bool requiresTextureQueryLodCubeArrayI{ false };
		bool requiresTextureQueryLod1DU{ false };
		bool requiresTextureQueryLod2DU{ false };
		bool requiresTextureQueryLod3DU{ false };
		bool requiresTextureQueryLodCubeU{ false };
		bool requiresTextureQueryLod1DArrayU{ false };
		bool requiresTextureQueryLod2DArrayU{ false };
		bool requiresTextureQueryLodCubeArrayU{ false };
		bool requiresTextureQueryLevels1DF{ false };
		bool requiresTextureQueryLevels2DF{ false };
		bool requiresTextureQueryLevels3DF{ false };
		bool requiresTextureQueryLevelsCubeF{ false };
		bool requiresTextureQueryLevels1DArrayF{ false };
		bool requiresTextureQueryLevels2DArrayF{ false };
		bool requiresTextureQueryLevelsCubeArrayF{ false };
		bool requiresTextureQueryLevels1DShadowF{ false };
		bool requiresTextureQueryLevels2DShadowF{ false };
		bool requiresTextureQueryLevelsCubeShadowF{ false };
		bool requiresTextureQueryLevels1DArrayShadowF{ false };
		bool requiresTextureQueryLevels2DArrayShadowF{ false };
		bool requiresTextureQueryLevelsCubeArrayShadowF{ false };
		bool requiresTextureQueryLevels1DI{ false };
		bool requiresTextureQueryLevels2DI{ false };
		bool requiresTextureQueryLevels3DI{ false };
		bool requiresTextureQueryLevelsCubeI{ false };
		bool requiresTextureQueryLevels1DArrayI{ false };
		bool requiresTextureQueryLevels2DArrayI{ false };
		bool requiresTextureQueryLevelsCubeArrayI{ false };
		bool requiresTextureQueryLevels1DU{ false };
		bool requiresTextureQueryLevels2DU{ false };
		bool requiresTextureQueryLevels3DU{ false };
		bool requiresTextureQueryLevelsCubeU{ false };
		bool requiresTextureQueryLevels1DArrayU{ false };
		bool requiresTextureQueryLevels2DArrayU{ false };
		bool requiresTextureQueryLevelsCubeArrayU{ false };
		bool requiresProjectTexCoords2{ false };
		bool requiresProjectTexCoords3{ false };
		bool requiresProjectTexCoords4To1{ false };
		bool requiresProjectTexCoords4To2{ false };
		bool requiresProjectTexCoords4{ false };

		bool requiresImageSizeBufferF{ false };
		bool requiresImageSize1DF{ false };
		bool requiresImageSize2DF{ false };
		bool requiresImageSize3DF{ false };
		bool requiresImageSizeCubeF{ false };
		bool requiresImageSize2DRectF{ false };
		bool requiresImageSize1DArrayF{ false };
		bool requiresImageSize2DArrayF{ false };
		bool requiresImageSizeCubeArrayF{ false };
		bool requiresImageSize2DMSF{ false };
		bool requiresImageSize2DMSArrayF{ false };
		bool requiresImageSizeBufferI{ false };
		bool requiresImageSize1DI{ false };
		bool requiresImageSize2DI{ false };
		bool requiresImageSize3DI{ false };
		bool requiresImageSizeCubeI{ false };
		bool requiresImageSize2DRectI{ false };
		bool requiresImageSize1DArrayI{ false };
		bool requiresImageSize2DArrayI{ false };
		bool requiresImageSizeCubeArrayI{ false };
		bool requiresImageSize2DMSI{ false };
		bool requiresImageSize2DMSArrayI{ false };
		bool requiresImageSizeBufferU{ false };
		bool requiresImageSize1DU{ false };
		bool requiresImageSize2DU{ false };
		bool requiresImageSize3DU{ false };
		bool requiresImageSizeCubeU{ false };
		bool requiresImageSize2DRectU{ false };
		bool requiresImageSize1DArrayU{ false };
		bool requiresImageSize2DArrayU{ false };
		bool requiresImageSizeCubeArrayU{ false };
		bool requiresImageSize2DMSU{ false };
		bool requiresImageSize2DMSArrayU{ false };
		bool requiresImageSamples2DMSF{ false };
		bool requiresImageSamples2DMSArrayF{ false };
		bool requiresImageSamples2DMSI{ false };
		bool requiresImageSamples2DMSArrayI{ false };
		bool requiresImageSamples2DMSU{ false };
		bool requiresImageSamples2DMSArrayU{ false };
		bool requiresImageAtomicAddBufferU{ false };
		bool requiresImageAtomicAdd1DU{ false };
		bool requiresImageAtomicAdd2DU{ false };
		bool requiresImageAtomicAdd3DU{ false };
		bool requiresImageAtomicAddCubeU{ false };
		bool requiresImageAtomicAdd2DRectU{ false };
		bool requiresImageAtomicAdd1DArrayU{ false };
		bool requiresImageAtomicAdd2DArrayU{ false };
		bool requiresImageAtomicAddCubeArrayU{ false };
		bool requiresImageAtomicAdd2DMSU{ false };
		bool requiresImageAtomicAdd2DMSArrayU{ false };
		bool requiresImageAtomicAddBufferI{ false };
		bool requiresImageAtomicAdd1DI{ false };
		bool requiresImageAtomicAdd2DI{ false };
		bool requiresImageAtomicAdd3DI{ false };
		bool requiresImageAtomicAddCubeI{ false };
		bool requiresImageAtomicAdd2DRectI{ false };
		bool requiresImageAtomicAdd1DArrayI{ false };
		bool requiresImageAtomicAdd2DArrayI{ false };
		bool requiresImageAtomicAddCubeArrayI{ false };
		bool requiresImageAtomicAdd2DMSI{ false };
		bool requiresImageAtomicAdd2DMSArrayI{ false };
		bool requiresImageAtomicAddBufferF{ false };
		bool requiresImageAtomicAdd1DF{ false };
		bool requiresImageAtomicAdd2DF{ false };
		bool requiresImageAtomicAdd3DF{ false };
		bool requiresImageAtomicAddCubeF{ false };
		bool requiresImageAtomicAdd2DRectF{ false };
		bool requiresImageAtomicAdd1DArrayF{ false };
		bool requiresImageAtomicAdd2DArrayF{ false };
		bool requiresImageAtomicAddCubeArrayF{ false };
		bool requiresImageAtomicAdd2DMSF{ false };
		bool requiresImageAtomicAdd2DMSArrayF{ false };
		bool requiresImageAtomicMinBufferU{ false };
		bool requiresImageAtomicMin1DU{ false };
		bool requiresImageAtomicMin2DU{ false };
		bool requiresImageAtomicMin3DU{ false };
		bool requiresImageAtomicMinCubeU{ false };
		bool requiresImageAtomicMin2DRectU{ false };
		bool requiresImageAtomicMin1DArrayU{ false };
		bool requiresImageAtomicMin2DArrayU{ false };
		bool requiresImageAtomicMinCubeArrayU{ false };
		bool requiresImageAtomicMin2DMSU{ false };
		bool requiresImageAtomicMin2DMSArrayU{ false };
		bool requiresImageAtomicMinBufferI{ false };
		bool requiresImageAtomicMin1DI{ false };
		bool requiresImageAtomicMin2DI{ false };
		bool requiresImageAtomicMin3DI{ false };
		bool requiresImageAtomicMinCubeI{ false };
		bool requiresImageAtomicMin2DRectI{ false };
		bool requiresImageAtomicMin1DArrayI{ false };
		bool requiresImageAtomicMin2DArrayI{ false };
		bool requiresImageAtomicMinCubeArrayI{ false };
		bool requiresImageAtomicMin2DMSI{ false };
		bool requiresImageAtomicMin2DMSArrayI{ false };
		bool requiresImageAtomicMaxBufferU{ false };
		bool requiresImageAtomicMax1DU{ false };
		bool requiresImageAtomicMax2DU{ false };
		bool requiresImageAtomicMax3DU{ false };
		bool requiresImageAtomicMaxCubeU{ false };
		bool requiresImageAtomicMax2DRectU{ false };
		bool requiresImageAtomicMax1DArrayU{ false };
		bool requiresImageAtomicMax2DArrayU{ false };
		bool requiresImageAtomicMaxCubeArrayU{ false };
		bool requiresImageAtomicMax2DMSU{ false };
		bool requiresImageAtomicMax2DMSArrayU{ false };
		bool requiresImageAtomicMaxBufferI{ false };
		bool requiresImageAtomicMax1DI{ false };
		bool requiresImageAtomicMax2DI{ false };
		bool requiresImageAtomicMax3DI{ false };
		bool requiresImageAtomicMaxCubeI{ false };
		bool requiresImageAtomicMax2DRectI{ false };
		bool requiresImageAtomicMax1DArrayI{ false };
		bool requiresImageAtomicMax2DArrayI{ false };
		bool requiresImageAtomicMaxCubeArrayI{ false };
		bool requiresImageAtomicMax2DMSI{ false };
		bool requiresImageAtomicMax2DMSArrayI{ false };
		bool requiresImageAtomicAndBufferU{ false };
		bool requiresImageAtomicAnd1DU{ false };
		bool requiresImageAtomicAnd2DU{ false };
		bool requiresImageAtomicAnd3DU{ false };
		bool requiresImageAtomicAndCubeU{ false };
		bool requiresImageAtomicAnd2DRectU{ false };
		bool requiresImageAtomicAnd1DArrayU{ false };
		bool requiresImageAtomicAnd2DArrayU{ false };
		bool requiresImageAtomicAndCubeArrayU{ false };
		bool requiresImageAtomicAnd2DMSU{ false };
		bool requiresImageAtomicAnd2DMSArrayU{ false };
		bool requiresImageAtomicAndBufferI{ false };
		bool requiresImageAtomicAnd1DI{ false };
		bool requiresImageAtomicAnd2DI{ false };
		bool requiresImageAtomicAnd3DI{ false };
		bool requiresImageAtomicAndCubeI{ false };
		bool requiresImageAtomicAnd2DRectI{ false };
		bool requiresImageAtomicAnd1DArrayI{ false };
		bool requiresImageAtomicAnd2DArrayI{ false };
		bool requiresImageAtomicAndCubeArrayI{ false };
		bool requiresImageAtomicAnd2DMSI{ false };
		bool requiresImageAtomicAnd2DMSArrayI{ false };
		bool requiresImageAtomicOrBufferU{ false };
		bool requiresImageAtomicOr1DU{ false };
		bool requiresImageAtomicOr2DU{ false };
		bool requiresImageAtomicOr3DU{ false };
		bool requiresImageAtomicOrCubeU{ false };
		bool requiresImageAtomicOr2DRectU{ false };
		bool requiresImageAtomicOr1DArrayU{ false };
		bool requiresImageAtomicOr2DArrayU{ false };
		bool requiresImageAtomicOrCubeArrayU{ false };
		bool requiresImageAtomicOr2DMSU{ false };
		bool requiresImageAtomicOr2DMSArrayU{ false };
		bool requiresImageAtomicOrBufferI{ false };
		bool requiresImageAtomicOr1DI{ false };
		bool requiresImageAtomicOr2DI{ false };
		bool requiresImageAtomicOr3DI{ false };
		bool requiresImageAtomicOrCubeI{ false };
		bool requiresImageAtomicOr2DRectI{ false };
		bool requiresImageAtomicOr1DArrayI{ false };
		bool requiresImageAtomicOr2DArrayI{ false };
		bool requiresImageAtomicOrCubeArrayI{ false };
		bool requiresImageAtomicOr2DMSI{ false };
		bool requiresImageAtomicOr2DMSArrayI{ false };
		bool requiresImageAtomicXorBufferU{ false };
		bool requiresImageAtomicXor1DU{ false };
		bool requiresImageAtomicXor2DU{ false };
		bool requiresImageAtomicXor3DU{ false };
		bool requiresImageAtomicXorCubeU{ false };
		bool requiresImageAtomicXor2DRectU{ false };
		bool requiresImageAtomicXor1DArrayU{ false };
		bool requiresImageAtomicXor2DArrayU{ false };
		bool requiresImageAtomicXorCubeArrayU{ false };
		bool requiresImageAtomicXor2DMSU{ false };
		bool requiresImageAtomicXor2DMSArrayU{ false };
		bool requiresImageAtomicXorBufferI{ false };
		bool requiresImageAtomicXor1DI{ false };
		bool requiresImageAtomicXor2DI{ false };
		bool requiresImageAtomicXor3DI{ false };
		bool requiresImageAtomicXorCubeI{ false };
		bool requiresImageAtomicXor2DRectI{ false };
		bool requiresImageAtomicXor1DArrayI{ false };
		bool requiresImageAtomicXor2DArrayI{ false };
		bool requiresImageAtomicXorCubeArrayI{ false };
		bool requiresImageAtomicXor2DMSI{ false };
		bool requiresImageAtomicXor2DMSArrayI{ false };
		bool requiresImageAtomicExchangeBufferU{ false };
		bool requiresImageAtomicExchange1DU{ false };
		bool requiresImageAtomicExchange2DU{ false };
		bool requiresImageAtomicExchange3DU{ false };
		bool requiresImageAtomicExchangeCubeU{ false };
		bool requiresImageAtomicExchange2DRectU{ false };
		bool requiresImageAtomicExchange1DArrayU{ false };
		bool requiresImageAtomicExchange2DArrayU{ false };
		bool requiresImageAtomicExchangeCubeArrayU{ false };
		bool requiresImageAtomicExchange2DMSU{ false };
		bool requiresImageAtomicExchange2DMSArrayU{ false };
		bool requiresImageAtomicExchangeBufferI{ false };
		bool requiresImageAtomicExchange1DI{ false };
		bool requiresImageAtomicExchange2DI{ false };
		bool requiresImageAtomicExchange3DI{ false };
		bool requiresImageAtomicExchangeCubeI{ false };
		bool requiresImageAtomicExchange2DRectI{ false };
		bool requiresImageAtomicExchange1DArrayI{ false };
		bool requiresImageAtomicExchange2DArrayI{ false };
		bool requiresImageAtomicExchangeCubeArrayI{ false };
		bool requiresImageAtomicExchange2DMSI{ false };
		bool requiresImageAtomicExchange2DMSArrayI{ false };
		bool requiresImageAtomicExchangeBufferF{ false };
		bool requiresImageAtomicExchange1DF{ false };
		bool requiresImageAtomicExchange2DF{ false };
		bool requiresImageAtomicExchange3DF{ false };
		bool requiresImageAtomicExchangeCubeF{ false };
		bool requiresImageAtomicExchange2DRectF{ false };
		bool requiresImageAtomicExchange1DArrayF{ false };
		bool requiresImageAtomicExchange2DArrayF{ false };
		bool requiresImageAtomicExchangeCubeArrayF{ false };
		bool requiresImageAtomicExchange2DMSF{ false };
		bool requiresImageAtomicExchange2DMSArrayF{ false };
		bool requiresImageAtomicCompSwapBufferU{ false };
		bool requiresImageAtomicCompSwap1DU{ false };
		bool requiresImageAtomicCompSwap2DU{ false };
		bool requiresImageAtomicCompSwap3DU{ false };
		bool requiresImageAtomicCompSwapCubeU{ false };
		bool requiresImageAtomicCompSwap2DRectU{ false };
		bool requiresImageAtomicCompSwap1DArrayU{ false };
		bool requiresImageAtomicCompSwap2DArrayU{ false };
		bool requiresImageAtomicCompSwapCubeArrayU{ false };
		bool requiresImageAtomicCompSwap2DMSU{ false };
		bool requiresImageAtomicCompSwap2DMSArrayU{ false };
		bool requiresImageAtomicCompSwapBufferI{ false };
		bool requiresImageAtomicCompSwap1DI{ false };
		bool requiresImageAtomicCompSwap2DI{ false };
		bool requiresImageAtomicCompSwap3DI{ false };
		bool requiresImageAtomicCompSwapCubeI{ false };
		bool requiresImageAtomicCompSwap2DRectI{ false };
		bool requiresImageAtomicCompSwap1DArrayI{ false };
		bool requiresImageAtomicCompSwap2DArrayI{ false };
		bool requiresImageAtomicCompSwapCubeArrayI{ false };
		bool requiresImageAtomicCompSwap2DMSI{ false };
		bool requiresImageAtomicCompSwap2DMSArrayI{ false };
	};
}

#endif
