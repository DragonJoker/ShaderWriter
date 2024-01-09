/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvHelpers_H___
#define ___SDW_SpirvHelpers_H___
#pragma once

#include "SpirVOpHelpers.hpp"

#include <ShaderAST/ShaderStlTypes.hpp>
#include <ShaderAST/Expr/ExprList.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtFunctionDecl.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>

#include <set>
#include <string>
#include <vector>

namespace spirv
{
	static constexpr uint32_t InvalidComponentCount = ~0u;

	struct ModuleConfig;
	class ExprAdapter;

	struct PendingResult
	{
		ast::var::VariablePtr var{};
	};

	struct PendingIO
	{
		ast::var::VariablePtr var{};
		uint32_t location{};
		uint32_t arraySize{};
		uint64_t flags{};
		PendingResult result{};
	};

	struct PendingMbrIO
	{
		uint32_t mbrIndex{};
		uint32_t location{};
		uint32_t arraySize{};
		uint64_t flags{};
		PendingResult result{};
	};

	void checkBuiltin( ast::Builtin builtin
		, ast::ShaderStage stage
		, ModuleConfig & config );

	struct IOMapping
	{
		IOMapping( ast::ShaderAllocatorBlock * alloc
			, ast::type::TypesCache & typesCache
			, ast::ShaderStage stage
			, bool isInput
			, uint32_t & nextVarId );

		ast::type::TypesCache & typesCache;
		ast::ShaderStage stage;
		bool isInput;
		uint32_t * nextVarId;
		using VarMbrsIndex = std::pair< ast::var::VariablePtr, uint32_t >;
		ast::Map< ast::var::VariablePtr, VarMbrsIndex > splitVarsBuiltins;
		ast::Map< ast::var::VariablePtr, VarMbrsIndex > splitVarsOthers;

		void addPatch( ast::var::VariablePtr patchVar );
		ast::var::VariablePtr getPatch( ast::var::VariablePtr patchVar );
		void add( ast::var::VariablePtr var );
		void addPending( ast::var::VariablePtr pendingVar
			, uint32_t location );
		void addPendingMbr( ast::var::VariablePtr outerVar
			, uint32_t mbrIndex
			, uint64_t flags
			, uint32_t location
			, uint32_t arraySize );
		void addPendingMbr( ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location
			, uint32_t arraySize );
		ast::expr::ExprPtr processPending( ast::expr::ExprCache & exprCache
			, ast::EntityName const & name
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPending( ast::expr::ExprCache & exprCache
			, ast::Builtin builtin
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPending( ast::expr::ExprCache & exprCache
			, ast::var::VariablePtr var
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPendingMbr( ast::expr::ExprCache & exprCache
			, ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont );
		bool isValid( ast::Builtin builtin )const;

		ast::var::VariableList const & getVars()const
		{
			return m_processed;
		}

	private:
		PendingResult processPendingType( ast::type::TypePtr type
			, std::string const & name
			, ast::Builtin builtin
			, uint64_t flags
			, uint32_t location
			, uint32_t arraySize
			, ast::stmt::Container * cont );
		PendingResult processPendingType( ast::type::Struct const & structType
			, uint32_t mbrIndex
			, uint64_t mbrFlags
			, uint32_t mbrLocation
			, uint32_t mbrArraySize
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPendingMbr( ast::expr::ExprCache & exprCache
			, ast::var::VariablePtr outerVar
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ast::stmt::Container * cont );

	private:
		struct MapComp
		{
			bool operator()( ast::EntityName const & lhs
				, ast::EntityName const & rhs )const noexcept
			{
				return lhs.id < rhs.id;
			}
		};
		ast::Map< ast::EntityName, PendingIO, MapComp > m_pending;
		struct PendingMbrIO
		{
			PendingMbrIO( ast::var::VariablePtr pouter
				, uint32_t pindex
				, PendingIO pio )
				: outer{ std::move( pouter ) }
				, index{ pindex }
				, io{ std::move( pio ) }
			{
			}

			ast::var::VariablePtr outer;
			uint32_t index;
			PendingIO io;
		};
		ast::Vector< PendingMbrIO > m_pendingMbr;
		ast::Map< ast::Builtin, ast::var::VariablePtr > m_processedBuiltins;
		ast::Map< std::string, ast::var::VariablePtr > m_processedIOs;
		ast::var::VariableList m_processed;
	};

	class Module;

	struct ModuleConfig
	{
		ModuleConfig( ast::ShaderAllocatorBlock * alloc
			, SpirVConfig & pspirvConfig
			, ast::type::TypesCache & typesCache
			, ast::ShaderStage pstage
			, uint32_t pnextVarId
			, uint32_t paliasId );

		uint32_t nextVarId;
		uint32_t aliasId;
		ast::ShaderStage stage;
		spv::AddressingModel addressingModel{ spv::AddressingModelLogical };
		ast::Set< spv::ExecutionMode > executionModes;

		void registerCapability( spv::Capability capability );
		bool registerExtension( SpirVExtension extension
			, bool optional = false );
		bool hasExtension( SpirVExtension const & extension )const;
		void fillModule( Module & shaderModule )const;

		void initialise( ast::stmt::FunctionDecl const & stmt );
		ast::stmt::ContainerPtr declare( ast::stmt::StmtCache & stmtCache )const;
		void addInputVar( ast::var::VariablePtr var
			, uint32_t location );
		void addOutputVar( ast::var::VariablePtr var
			, uint32_t location );
		ast::expr::ExprPtr processPending( ast::expr::ExprCache & exprCache
			, ast::Builtin builtin
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPending( ast::expr::ExprCache & exprCache
			, ast::var::VariablePtr var
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPendingMbr( ast::expr::ExprCache & exprCache
			, ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont );
		bool isInput( ast::Builtin builtin )const;
		bool isOutput( ast::Builtin builtin )const;
		void addMbrBuiltin( ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location
			, uint32_t arraySize );

		ast::var::VariableList const & getInputs()const
		{
			return inputs.getVars();
		}

		void addInput( ast::var::VariablePtr var )
		{
			inputs.add( var );
		}

		void addPendingInput( ast::var::VariablePtr var
			, uint32_t location )
		{
			inputs.addPending( var, location );
		}

		void addPendingMbrInput( ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location
			, uint32_t arraySize )
		{
			inputs.addPendingMbr( outer
				, mbrIndex
				, flags
				, location
				, arraySize );
		}

		ast::expr::ExprPtr processPendingInput( ast::expr::ExprCache & exprCache
			, ast::EntityName const & name
			, ast::stmt::Container * cont )
		{
			return inputs.processPending( exprCache
				, name
				, cont );
		}

		ast::expr::ExprPtr processPendingInput( ast::expr::ExprCache & exprCache
			, ast::var::VariablePtr var
			, ast::stmt::Container * cont )
		{
			if ( var->isBuiltin() )
			{
				checkBuiltin( var->getBuiltin(), stage, *this );
			}

			return inputs.processPending( exprCache
				, var
				, cont );
		}

		ast::expr::ExprPtr processPendingMbrInput( ast::expr::ExprCache & exprCache
			, ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont )
		{
			if ( isStructType( outer.getType() ) )
			{
				auto mbr = getStructType( outer.getType() )->getMember( mbrIndex );

				if ( mbr.builtin != ast::Builtin::eNone )
				{
					checkBuiltin( mbr.builtin, stage, *this );
				}
			}

			return inputs.processPendingMbr( exprCache
				, outer
				, mbrIndex
				, flags
				, adapter
				, cont );
		}

		ast::var::VariableList const & getOutputs()const
		{
			return outputs.getVars();
		}

		void addOutput( ast::var::VariablePtr var )
		{
			outputs.add( var );
		}

		void addPendingOutput( ast::var::VariablePtr var
			, uint32_t location )
		{
			outputs.addPending( var, location );
		}

		void addPendingMbrOutput( ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location
			, uint32_t arraySize )
		{
			outputs.addPendingMbr( outer
				, mbrIndex
				, flags
				, location
				, arraySize );
		}

		ast::expr::ExprPtr processPendingOutput( ast::expr::ExprCache & exprCache
			, ast::EntityName const & name
			, ast::stmt::Container * cont )
		{
			return outputs.processPending( exprCache
				, name
				, cont );
		}

		ast::expr::ExprPtr processPendingOutput( ast::expr::ExprCache & exprCache
			, ast::var::VariablePtr var
			, ast::stmt::Container * cont )
		{
			if ( var->isBuiltin() )
			{
				checkBuiltin( var->getBuiltin(), stage, *this );
			}

			return outputs.processPending( exprCache
				, var
				, cont );
		}

		ast::expr::ExprPtr processPendingMbrOutput( ast::expr::ExprCache & exprCache
			, ast::expr::Expr const & outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont )
		{
			if ( isStructType( outer.getType() ) )
			{
				auto mbr = getStructType( outer.getType() )->getMember( mbrIndex );

				if ( mbr.builtin != ast::Builtin::eNone )
				{
					checkBuiltin( mbr.builtin, stage, *this );
				}
			}

			return outputs.processPendingMbr( exprCache
				, outer
				, mbrIndex
				, flags
				, adapter
				, cont );
		}

		ast::var::VariablePtr getOutputPatch( ast::var::VariablePtr patchVar )
		{
			return outputs.getPatch( patchVar );
		}

		ast::var::VariablePtr getInputPatch( ast::var::VariablePtr patchVar )
		{
			return inputs.getPatch( patchVar );
		}

	private:
		void registerParam( ast::var::VariablePtr var
			, ast::type::ComputeInput const & compType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::FragmentInput const & fragType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::GeometryInput const & geomType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::GeometryOutput const & geomType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationInputPatch const & patchType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationControlInput const & tessType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationControlOutput const & tessType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TessellationEvaluationInput const & tessType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::MeshVertexOutput const & meshType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::MeshPrimitiveOutput const & meshType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TaskPayloadNV const & taskType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TaskPayload const & taskType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TaskPayloadInNV const & taskType );
		void registerParam( ast::var::VariablePtr var
			, ast::type::TaskPayloadIn const & taskType );
		void registerInput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, uint32_t arraySize );
		void registerOutput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, uint32_t arraySize );

	private:
		SpirVConfig & spirvConfig;
		IOMapping inputs;
		IOMapping outputs;
		ast::Set< spv::Capability > requiredCapabilities;
		SpirVExtensionSet requiredExtensions{};
	};

	struct IntrinsicConfig
	{
		// Intrinsic
		bool isExtension{ false };
		bool isAtomic{ false };
		// Image
		bool needsTexelPointer{ false };
		// Texture
		uint32_t imageOperandsIndex{ 0u };
		bool needsImage{ false };
		spv::ImageOperandsMask mask{ spv::ImageOperandsMaskNone };
		uint32_t returnComponentsCount{ 0u };
		uint32_t offsetIndex{ 0u };
	};

	struct ConstExprIdentifier
	{
		uint32_t scopeId;
		std::string name;
		ast::type::TypePtr type;
	};

	struct ConstExprIdentifierHasher
	{
		size_t operator()( ConstExprIdentifier const & obj )const;
	};

	struct PreprocContext
	{
		ValueId workGroupSizeExpr;
	};

	void checkType( ast::type::TypePtr type
		, ModuleConfig & config );
	spv::BuiltIn getBuiltin( ast::Builtin builtin
		, spv::ExecutionModel executionModel
		, ast::Vector< spv::Decoration > & additionalDecorations );
	spv::MemoryModel getMemoryModel();
	spv::ExecutionModel getExecutionModel( ast::ShaderStage kind );
	std::string getTypeName( spv::Op op );
	std::string getOperatorName( spv::Op op );
	std::string getName( spv::Capability value );
	ast::type::ImageFormat getImageFormat( spv::ImageFormat value );
	ValueIdList makeBinOpOperands( ast::ShaderAllocatorBlock * alloc
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs );
	InstructionPtr makeImageTypeInstruction( NamesCache & nameCache
		, ast::type::ImageConfiguration const & config
		, ast::type::Trinary isComparison
		, ValueId resultId
		, ValueId sampledTypeId );
	InstructionPtr makeAccelerationStructureTypeInstruction( NamesCache & nameCache
		, ValueId resultId );
	InstructionPtr makeBaseTypeInstruction( NamesCache & nameCache
		, ast::type::Kind kind
		, ValueId id );
	InstructionPtr makeIntrinsicInstruction( NamesCache & nameCache
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeIntrinsicInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeSampledImageAccessInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeTextureAccessInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeImageAccessInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeCastInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueId operandId );
	InstructionPtr makeUnInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind typeKind
		, ValueId operand );
	InstructionPtr makeBinInstruction( NamesCache & nameCache
		, ValueId returnTypeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs );
	InstructionPtr makeVariableInstruction( NamesCache & nameCache
		, ValueId typeId
		, ValueId varId
		, ValueId initialiser = ValueId{} );
	ast::expr::ExprPtr makeZero( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeOne( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeToBoolCast( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::expr::ExprPtr expr );
	ast::expr::ExprPtr makeFromBoolCast( ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::expr::ExprPtr expr
		, ast::type::Kind dstScalarType );
	bool isPointerParam( ast::type::TypePtr type
		, bool isOutputParam );
	bool isPointerParam( ast::var::Variable const & param );
	void insertCapability( NamesCache & nameCache
		, InstructionList & capabilities
		, spv::Capability capa );
	void decorateVar( ast::var::Variable const & var
		, DebugId const & varId
		, Module & shaderModule );
	spv::StorageClass getStorageClass( uint32_t version
		, ast::var::VariablePtr var
		, spv::StorageClass fallback = spv::StorageClassFunction );
}

#endif
