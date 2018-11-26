/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslStmtAdapter_H___
#define ___SDW_HlslStmtAdapter_H___
#pragma once

#include <ShaderAST/Visitors/CloneStmt.hpp>
#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/HLSL/HlslShader.hpp"

namespace sdw::hlsl
{
	class StmtAdapter
		: public StmtCloner
	{
	public:
		static stmt::ContainerPtr submit( Shader const & shader
			, IntrinsicsConfig const & config );

	private:
		StmtAdapter( Shader const & shader
			, IntrinsicsConfig const & config
			, stmt::ContainerPtr & result );

		expr::ExprPtr doSubmit( expr::Expr * expr )override;

		void linkVars( var::VariablePtr textureSampler
			, var::VariablePtr texture
			, var::VariablePtr sampler );

		void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override;
		void visitInOutVariableDeclStmt( stmt::InOutVariableDecl * stmt )override;
		void visitInputComputeLayoutStmt( stmt::InputComputeLayout * stmt )override;
		void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override;
		void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override;
		void visitPerVertexDeclStmt( stmt::PerVertexDecl * stmt )override;
		void visitSampledImageDeclStmt( stmt::SampledImageDecl * stmt )override;
		void visitShaderBufferDeclStmt( stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( stmt::ShaderStructBufferDecl * stmt )override;
		void visitVariableDeclStmt( stmt::VariableDecl * stmt )override;
		void visitPreprocDefine( stmt::PreprocDefine * preproc )override;
		void visitPreprocEndif( stmt::PreprocEndif * preproc )override;
		void visitPreprocExtension( stmt::PreprocExtension * preproc )override;
		void visitPreprocVersion( stmt::PreprocVersion * preproc )override;

	private:
		void rewriteShaderIOVars();
		stmt::FunctionDeclPtr rewriteMainHeader( stmt::FunctionDecl * stmt );
		stmt::FunctionDeclPtr rewriteFuncHeader( stmt::FunctionDecl * stmt );
		void rewriteMainFooter( stmt::FunctionDecl * stmt );

	private:
		IntrinsicsConfig const & m_config;
		HlslShader m_shader;
		stmt::Container * m_intrinsics;
		AdaptationData m_adaptationData;
		stmt::InputComputeLayout * m_inputComputeLayout{ nullptr };
		stmt::InputGeometryLayout * m_inputGeometryLayout{ nullptr };
		stmt::OutputGeometryLayout * m_outputGeometryLayout{ nullptr };
	};
}

#endif
