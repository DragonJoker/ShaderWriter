/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtAdapter_H___
#define ___SDW_SpirvStmtAdapter_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

#include <unordered_set>

namespace spirv
{
	struct AdaptationData
	{
		AdaptationData( PreprocContext & pcontext
			, ModuleConfig pconfig )
			: context{ pcontext }
			, config{ std::move( pconfig ) }
		{
		}

		PreprocContext & context;
		ModuleConfig config;
	};

	class StmtAdapter
		: public ast::StmtCloner
	{
	public:
		static ast::stmt::ContainerPtr submit( ast::stmt::Container * container
			, AdaptationData & adaptationData );

	private:
		StmtAdapter( ast::stmt::ContainerPtr & result
			, AdaptationData & adaptationData );
		
		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;

		void visitElseIfStmt( ast::stmt::ElseIf * stmt )override;
		void visitElseStmt( ast::stmt::Else * stmt )override;
		void visitIfStmt( ast::stmt::If * stmt )override;
		void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override;
		void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitSimpleStmt( ast::stmt::Simple * stmt )override;
		void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override;
		void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override;
		void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( ast::stmt::PreprocElif * preproc )override;
		void visitPreprocElse( ast::stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override;
		void visitPreprocIf( ast::stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override;

	private:
		void doProcessComputeInput( ast::var::VariablePtr var
			, ast::type::ComputeInput const & compType );
		void doProcessGeometryOutput( ast::var::VariablePtr var
			, ast::type::GeometryOutput const & geomType );
		void doProcessGeometryInput( ast::var::VariablePtr var
			, ast::type::GeometryInput const & geomType );
		void doProcessTessellationControlOutput( ast::var::VariablePtr var
			, ast::type::TessellationControlOutput const & tessType
			, bool isEntryPoint );
		void doProcessTessellationControlInput( ast::var::VariablePtr var
			, ast::type::TessellationControlInput const & tessType
			, bool isEntryPoint );
		void doProcessOutput( ast::var::VariablePtr var
			, ast::type::IOStructPtr ioType
			, bool isEntryPoint );
		void doProcessInput( ast::var::VariablePtr var
			, ast::type::IOStructPtr ioType
			, bool isEntryPoint );
		void doProcessOutputPatch( ast::var::VariablePtr var
			, ast::type::TessellationOutputPatch const & patchType
			, bool isEntryPoint );
		void doProcessInputPatch( ast::var::VariablePtr var
			, ast::type::StructPtr const & structType
			, bool isEntryPoint );
		void doProcessEntryPoint( ast::stmt::FunctionDecl * stmt );
		void doProcessPatchRoutine( ast::stmt::FunctionDecl * stmt );
		void doProcessInOut( ast::type::FunctionPtr funcType
			, bool isEntryPoint );
		void doDeclareStruct( ast::type::StructPtr const & structType );

	private:
		AdaptationData & m_adaptationData;
		std::unordered_set< ast::type::StructPtr > m_declaredStructs;
		struct PendingFunction
		{
			ast::type::FunctionPtr funcType;
			ast::stmt::ContainerPtr statements;
		};
		std::map< std::string, PendingFunction > m_pending;
	};
}

#endif
