/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvHelpers_H___
#define ___SDW_SpirvHelpers_H___
#pragma once

#include "SpirvOpHelpers.hpp"

#include <ShaderAST/Expr/ExprList.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtFunctionDecl.hpp>

#include <set>
#include <string>
#include <vector>

namespace spirv
{
	class ExprAdapter;

	struct PendingResult
	{
		ast::var::VariablePtr var;
	};

	struct PendingIO
	{
		ast::var::VariablePtr var;
		uint32_t location;
		uint32_t arraySize;
		uint32_t flags;
		PendingResult result;
	};

	struct PendingMbrIO
	{
		uint32_t mbrIndex;
		uint32_t location;
		uint32_t arraySize;
		uint32_t flags;
		PendingResult result;
	};

	struct IOMapping
	{
		IOMapping( ast::type::TypesCache & pcache
			, ast::ShaderStage pstage
			, bool pisInput
			, uint32_t & pnextVarId );

		ast::type::TypesCache & cache;
		ast::ShaderStage stage;
		bool isInput;
		uint32_t * nextVarId;
		using VarMbrsIndex = std::pair< ast::var::VariablePtr, uint32_t >;
		std::map< ast::var::VariablePtr, VarMbrsIndex > splitVarsBuiltins{};
		std::map< ast::var::VariablePtr, VarMbrsIndex > splitVarsOthers{};

		void declare( ast::stmt::Container & stmt );

		void addOutputPatch( ast::var::VariablePtr patchVar
			, uint32_t location );
		ast::var::VariablePtr getOutputPatch( ast::var::VariablePtr patchVar );
		void addPending( ast::var::VariablePtr pendingVar
			, uint32_t location );
		void addPendingMbr( ast::var::VariablePtr outerVar
			, uint32_t mbrIndex
			, uint32_t flags
			, uint32_t location
			, uint32_t arraySize );
		void addPendingMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location
			, uint32_t arraySize );
		ast::expr::ExprPtr processPending( std::string const & name
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPending( ast::Builtin builtin
			, ExprAdapter & adapter
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPending( ast::var::VariablePtr var
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPendingMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont );
		bool isValid( ast::Builtin builtin );

		ast::var::VariableList const & getVars()const
		{
			return m_processed;
		}

	private:
		PendingResult processPendingType( ast::type::TypePtr type
			, std::string const & name
			, ast::Builtin builtin
			, uint32_t flags
			, uint32_t location
			, uint32_t arraySize
			, ast::stmt::Container * cont );
		PendingResult processPendingType( ast::type::Struct const & structType
			, uint32_t mbrIndex
			, uint32_t mbrFlags
			, uint32_t mbrLocation
			, uint32_t mbrArraySize
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPendingMbr( ast::var::VariablePtr outerVar
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont );

	private:
		std::map< std::string, PendingIO > m_pending;
		struct PendingMbrIO
		{
			ast::var::VariablePtr outer;
			uint32_t index;
			PendingIO io;
		};
		std::vector< PendingMbrIO > m_pendingMbr;
		std::map< ast::Builtin, ast::var::VariablePtr > m_processedBuiltins;
		std::map< std::string, ast::var::VariablePtr > m_processedIOs;
		ast::var::VariableList m_processed;
	};

	struct ModuleConfig
	{
		ModuleConfig( ast::type::TypesCache & cache
			, ast::ShaderStage pstage
			, uint32_t pnextVarId
			, uint32_t paliasId )
			: nextVarId{ pnextVarId }
			, aliasId{ paliasId }
			, stage{ pstage }
			, inputs{ cache, stage, true, nextVarId }
			, outputs{ cache, stage, false, nextVarId }
		{
		}

		uint32_t nextVarId;
		uint32_t aliasId;
		ast::ShaderStage stage;
		std::set< spv::Capability > requiredCapabilities;

		void initialise( ast::stmt::FunctionDecl const & stmt );
		ast::stmt::ContainerPtr declare();
		void addInputVar( ast::var::VariablePtr var
			, uint32_t location );
		void addOutputVar( ast::var::VariablePtr var
			, uint32_t location );
		ast::expr::ExprPtr processPending( ast::Builtin builtin
			, ExprAdapter & adapter
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPending( ast::var::VariablePtr var
			, ast::stmt::Container * cont );
		ast::expr::ExprPtr processPendingMbr( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont );
		bool isInput( ast::Builtin builtin );
		bool isOutput( ast::Builtin builtin );
		void addMbrBuiltin( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, uint32_t location
			, uint32_t arraySize );

		ast::var::VariableList const & getInputs()const
		{
			return inputs.getVars();
		}

		void addPendingInput( ast::var::VariablePtr var
			, uint32_t location )
		{
			return inputs.addPending( var, location );
		}

		void addPendingMbrInput( ast::expr::Expr * outer
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

		ast::expr::ExprPtr processPendingInput( std::string const & name
			, ast::stmt::Container * cont )
		{
			return inputs.processPending( name
				, cont );
		}

		ast::expr::ExprPtr processPendingInput( ast::var::VariablePtr var
			, ast::stmt::Container * cont )
		{
			return inputs.processPending( var
				, cont );
		}

		ast::expr::ExprPtr processPendingMbrInput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont )
		{
			return inputs.processPendingMbr( outer
				, mbrIndex
				, flags
				, adapter
				, cont );
		}

		ast::var::VariableList const & getOutputs()const
		{
			return outputs.getVars();
		}

		void addPendingOutput( ast::var::VariablePtr var
			, uint32_t location )
		{
			return outputs.addPending( var, location );
		}

		void addPendingMbrOutput( ast::expr::Expr * outer
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

		ast::expr::ExprPtr processPendingOutput( std::string const & name
			, ast::stmt::Container * cont )
		{
			return outputs.processPending( name
				, cont );
		}

		ast::expr::ExprPtr processPendingOutput( ast::var::VariablePtr var
			, ast::stmt::Container * cont )
		{
			return outputs.processPending( var
				, cont );
		}

		ast::expr::ExprPtr processPendingMbrOutput( ast::expr::Expr * outer
			, uint32_t mbrIndex
			, ast::var::FlagHolder const & flags
			, ExprAdapter & adapter
			, ast::stmt::Container * cont )
		{
			return outputs.processPendingMbr( outer
				, mbrIndex
				, flags
				, adapter
				, cont );
		}

		ast::var::VariablePtr getOutputPatch( ast::var::VariablePtr patchVar )
		{
			return outputs.getOutputPatch( patchVar );
		}

	private:
		void registerComputeInput( ast::var::VariablePtr var
			, ast::type::ComputeInput const & compType );
		void registerGeometryInput( ast::var::VariablePtr var
			, ast::type::GeometryInput const & geomType );
		void registerGeometryOutput( ast::var::VariablePtr var
			, ast::type::GeometryOutput const & geomType );
		void registerTessellationControlInput( ast::var::VariablePtr var
			, ast::type::TessellationControlInput const & tessType
			, bool isEntryPoint );
		void registerTessellationControlOutput( ast::var::VariablePtr var
			, ast::type::TessellationControlOutput const & tessType
			, bool isEntryPoint );
		void registerInput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, uint32_t arraySize
			, bool isEntryPoint );
		void registerOutput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, uint32_t arraySize
			, bool isEntryPoint );
		void registerOutputPatch( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType
			, bool isEntryPoint );

	private:
		IOMapping inputs;
		IOMapping outputs;
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
		std::map< uint32_t, ast::expr::ExprPtr > constExprs;
		std::map< uint32_t, ast::expr::ExprList > constAggrExprs;
		ValueId workGroupSizeExpr;
	};

	spv::BuiltIn getBuiltin( ast::Builtin builtin
		, std::vector< spv::Decoration > & additionalDecorations );
	spv::MemoryModel getMemoryModel();
	spv::ExecutionModel getExecutionModel( ast::ShaderStage kind );
	std::string getTypeName( spv::Op op );
	std::string getOperatorName( spv::Op op );
	std::string getName( spv::Capability value );
	ValueIdList makeBinOpOperands( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs );
	InstructionPtr makeImageTypeInstruction( ast::type::ImageConfiguration const & config
		, ValueId resultId
		, ValueId sampledTypeId );
	InstructionPtr makeBaseTypeInstruction( ast::type::Kind kind
		, ValueId id );
	InstructionPtr makeIntrinsicInstruction( spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeIntrinsicInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeTextureAccessInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeImageAccessInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueIdList const & operands );
	InstructionPtr makeCastInstruction( ValueId returnTypeId
		, ValueId resultId
		, spv::Op op
		, ValueId operandId );
	InstructionPtr makeUnInstruction( ValueId returnTypeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind typeKind
		, ValueId operand );
	InstructionPtr makeBinInstruction( ValueId returnTypeId
		, ValueId resultId
		, ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, ValueId lhs
		, ValueId rhs );
	InstructionPtr makeVariableInstruction( ValueId typeId
		, ValueId varId
		, ValueId initialiser = {} );
	ast::expr::ExprPtr makeZero( ast::type::TypesCache & cache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeOne( ast::type::TypesCache & cache
		, ast::type::Kind kind );
	ast::expr::ExprPtr makeToBoolCast( ast::type::TypesCache & cache
		, ast::expr::ExprPtr expr );
	ast::expr::ExprPtr makeFromBoolCast( ast::type::TypesCache & cache
		, ast::expr::ExprPtr expr
		, ast::type::Kind dstScalarType );
	bool isPointerParam( ast::type::TypePtr type
		, bool isOutputParam );
	bool isPointerParam( ast::var::Variable const & param );
}

#endif
