/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslStmtAdapter_H___
#define ___SDW_GlslStmtAdapter_H___
#pragma once

#include "CompilerGlsl/compileGlsl.hpp"

#include "GlslHelpers.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

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
		void doProcessOutput( ast::var::VariablePtr var
			, ast::type::IOStruct const & ioType );
		void doProcessInput( ast::var::VariablePtr var
			, ast::type::IOStruct const & ioType
			, uint32_t arraySize );

	private:
		ast::type::TypesCache & m_cache;
		AdaptationData & m_adaptationData;
	};
}

#endif
