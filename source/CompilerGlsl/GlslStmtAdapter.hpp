/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslStmtAdapter_H___
#define ___SDW_GlslStmtAdapter_H___
#pragma once

#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslHelpers.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

#include <unordered_set>

namespace glsl
{
	struct IOVars
	{
	private:
		ast::var::VariablePtr m_var{};
		ast::var::VariablePtr m_patch{};

	public:
		void setMainVar( ast::var::VariablePtr const & rhs )
		{
			if ( rhs->isPatch()
				|| rhs->isPerPrimitive() )
			{
				m_patch = rhs;
			}
			else
			{
				m_var = rhs;
			}
		}

		bool isMainVar( ast::var::VariablePtr const & rhs )
		{
			return rhs == m_var || rhs == m_patch;
		}

		std::map< ast::type::StructPtr, ast::var::VariableList > vars{};
		ast::var::VariablePtr perVertex{};
		ast::var::VariablePtr perPrimitive{};
		std::map< ast::Builtin, ast::expr::ExprPtr > perVertexMbrs;
		std::map< ast::Builtin, ast::expr::ExprPtr > perPrimitiveMbrs;
		std::map< ast::type::StructPtr, std::pair< ast::type::StructPtr, uint32_t > > builtinsStructs;
		std::map< ast::type::StructPtr, ast::var::VariablePtr > othersStructs;
	};

	struct AdaptationData
	{
		ast::ShaderStage stage;
		GlslConfig & writerConfig;
		IntrinsicsConfig intrinsicsConfig;
		uint32_t nextVarId;
		IOVars inputs{};
		IOVars outputs{};
		std::map< ast::var::VariablePtr, ast::var::VariablePtr > aliases{};
	};

	class StmtAdapter
		: public ast::StmtCloner
	{
	public:
		static ast::stmt::ContainerPtr submit( ast::stmt::StmtCache & stmtCache
			,  ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, ast::stmt::Container * container
			, AdaptationData & adaptationData );

	private:
		StmtAdapter( ast::stmt::StmtCache & stmtCache
			, ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, AdaptationData & adaptationData
			, ast::stmt::Container * globalsCont
			, ast::stmt::ContainerPtr & result );

		using ast::StmtCloner::doSubmit;
		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;

		void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override;
		void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override;
		void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )override;
		void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )override;
		void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override;
		void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override;
		void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override;
		void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override;
		void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )override;
		void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override;
		void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override;
		void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override;
		void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override;
		void declareType( ast::type::TypePtr type );

	private:
		void doProcess( ast::var::VariablePtr var
			, ast::type::FragmentInput const & fragType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::GeometryOutput const & geomType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::GeometryInput const & geomType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TessellationInputPatch const & patchType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TessellationControlInput const & tesscType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TessellationControlOutput const & tesscType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TessellationEvaluationInput const & tesseType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::MeshVertexOutput const & meshType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::MeshPrimitiveOutput const & meshType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TaskPayloadNV const & taskType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TaskPayload const & taskType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TaskPayloadInNV const & taskType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::TaskPayloadIn const & taskType );
		void doProcess( ast::var::VariablePtr var
			, ast::type::ComputeInput const & compType );
		void doProcessOutput( ast::var::VariablePtr var
			, ast::type::IOStructPtr structType
			, uint32_t arraySize
			, bool declVar );
		void doProcessInput( ast::var::VariablePtr var
			, ast::type::IOStructPtr structType
			, uint32_t arraySize
			, bool declVar );
		void doProcessIO( ast::var::VariablePtr var
			, ast::type::IOStructPtr structType
			, uint32_t arraySize
			, bool declVar
			, bool isInput
			, IOVars & io );
		void doProcessEntryPoint( ast::stmt::FunctionDecl * stmt );
		void doProcessPatchRoutine( ast::stmt::FunctionDecl * stmt );
		ast::type::TypePtr doDeclarePerVertex( bool isInput
			, IOVars & io );
		ast::type::TypePtr doDeclarePerPrimitive( bool isInput
			, IOVars & io );
		void doProcessMeshOutputs();

	private:
		ast::type::TypesCache & m_typesCache;
		AdaptationData & m_adaptationData;
		ast::stmt::ContainerPtr m_entryPointFinish;
		ast::stmt::Container * m_globalsCont;
		std::unordered_set< std::string > m_declaredStructs;
		uint32_t m_maxPoint{};
		uint32_t m_maxPrimitives{};
		ast::type::InputLayout m_inputLayout;
		ast::type::TypePtr m_inPerVertex;
		ast::type::TypePtr m_outPerVertex;
		ast::type::TypePtr m_inPerPrimitive;
		ast::type::TypePtr m_outPerPrimitive;
		ast::var::VariablePtr m_meshVtxVar{};
		ast::type::MeshVertexOutput const * m_meshVtxType{};
		ast::var::VariablePtr m_meshPrimVar{};
		ast::type::MeshPrimitiveOutput const * m_meshPrimType{};
		bool m_inPCB{};
	};
}

#endif
