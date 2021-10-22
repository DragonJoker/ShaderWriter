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
	struct AdaptationData
	{
		GlslConfig const & writerConfig;
		IntrinsicsConfig intrinsicsConfig;
		uint32_t nextVarId;
		ast::var::VariablePtr output{};
		std::vector< ast::var::VariablePtr > outputs{};
		ast::var::VariablePtr input{};
		std::vector< ast::var::VariablePtr > inputs{};
	};

	class StmtAdapter
		: public ast::StmtCloner
	{
	public:
		static ast::stmt::ContainerPtr submit( ast::type::TypesCache & cache
			, ast::stmt::Container * container
			, AdaptationData & adaptationData );

	private:
		StmtAdapter( ast::type::TypesCache & cache
			, AdaptationData & adaptationData
			, ast::stmt::ContainerPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;

		void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override;
		void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override;

	private:
		void doProcessGeometryOutput( ast::var::VariablePtr var
			, ast::type::GeometryOutput const & geomType );
		void doProcessGeometryInput( ast::var::VariablePtr var
			, ast::type::GeometryInput const & geomType );
		void doProcessTessellationControlInput( ast::var::VariablePtr var
			, ast::type::TessellationControlInput const & geomType );
		void doProcessTessellationControlOutput( ast::var::VariablePtr var
			, ast::type::TessellationControlOutput const & geomType );
		void doProcessOutput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, uint32_t arraySize
			, bool entryPoint );
		void doProcessInput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, uint32_t arraySize
			, bool entryPoint );
		void doProcessOutputPatch( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType
			, bool entryPoint );
		void doProcessInputPatch( ast::var::VariablePtr var
			, ast::type::StructPtr const & structType
			, bool entryPoint );
		void doProcessEntryPoint( ast::stmt::FunctionDecl * stmt );
		void doProcessPatchRoutine( ast::stmt::FunctionDecl * stmt );
		void doDeclareStruct( ast::type::StructPtr const & structType );

	private:
		ast::type::TypesCache & m_cache;
		AdaptationData & m_adaptationData;
		ast::stmt::ContainerPtr m_entryPointFinish;
		std::unordered_set< ast::type::StructPtr > m_declaredStructs;
	};
}

#endif
