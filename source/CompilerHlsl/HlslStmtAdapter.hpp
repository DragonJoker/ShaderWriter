/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslStmtAdapter_H___
#define ___SDW_HlslStmtAdapter_H___
#pragma once

#include <ShaderAST/Visitors/CloneStmt.hpp>
#include "HlslHelpers.hpp"
#include "HlslShader.hpp"

#include <unordered_set>

namespace hlsl
{
	class StmtAdapter
		: public ast::StmtCloner
	{
	public:
		static ast::stmt::ContainerPtr submit( ast::Shader const & shader
			, ast::stmt::Container * container
			, IntrinsicsConfig const & intrinsicsConfig
			, HlslConfig const & writerConfig
			, AdaptationData & adaptationData );

	private:
		StmtAdapter( ast::Shader const & shader
			, IntrinsicsConfig const & intrinsicsConfig
			, HlslConfig const & writerConfig
			, AdaptationData & adaptationData
			, ast::stmt::ContainerPtr & result );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;

		void linkVars( ast::var::VariablePtr textureSampler
			, ast::var::VariablePtr texture
			, ast::var::VariablePtr sampler );

		void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override;
		void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override;
		void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override;
		void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override;
		void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override;
		void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override;
		void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override;
		void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override;

	private:
		void rewriteShaderIOVars();
		void writeMain( ast::stmt::FunctionDecl * stmt );
		ast::stmt::FunctionDeclPtr rewriteFuncHeader( ast::stmt::FunctionDecl * stmt );
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
			, bool isEntryPoint );
		void registerOutput( ast::var::VariablePtr var
			, ast::type::IOStruct const & structType
			, bool isEntryPoint );
		void registerInputPatch( ast::var::VariablePtr var
			, ast::type::StructPtr const & structType
			, bool isEntryPoint );
		void registerOutputPatch( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType
			, bool isEntryPoint );
		void declareStruct( ast::type::StructPtr const & structType );

	private:
		IntrinsicsConfig const & m_intrinsicsConfig;
		HlslConfig const & m_writerConfig;
		AdaptationData & m_adaptationData;
		HlslShader m_shader;
		ast::type::TypesCache & m_cache;
		ast::stmt::Container * m_inOutDeclarations;
		ast::stmt::Container * m_intrinsics;
		ast::stmt::InputComputeLayout * m_inputComputeLayout{ nullptr };
		std::unordered_set< ast::type::StructPtr > m_declaredStructs;
	};
}

#endif
