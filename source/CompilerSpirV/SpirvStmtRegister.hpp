/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvStmtRegister_H___
#define ___SDW_SpirvStmtRegister_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

namespace spirv
{
	enum class BlockType
	{
		eGlobal,
		eFunction,
		eMax,
	};

	struct Variable
	{
		Variable( ast::var::VariablePtr var
			, IdList decorations )
			: var{ std::move( var ) }
			, decorations{ std::move( decorations ) }
		{
		}

		ast::var::VariablePtr var;
		IdList decorations;
	};

	using VariablePtr = std::shared_ptr< Variable >;
	using VariableArray = std::vector< VariablePtr >;

	struct VarUsage
	{
		VariableArray use;
		VariablePtr set;
	};

	using VarUsageArray = std::vector< VarUsage >;
	using UsedVars = std::set< VariablePtr >;

	struct BlockStruct
	{
		BlockType type;
		VariableArray * allVars;
		VarUsageArray usages;
		VariableArray ownVars;
	};

	using BlockStructMap = std::map< uint32_t, BlockStruct >;

	using TypeMap = std::map< uint32_t, ast::type::TypePtr >;

	struct ModuleStruct
	{
		TypeMap types;
		BlockStruct globalScope{ BlockType::eGlobal };
		BlockStructMap functionScopes;
	};

	using IdSet = std::set< spv::Id >;
	class ExprRegister;

	class StmtRegister
		: public ast::StmtCloner
	{
	public:
		static ast::stmt::ContainerPtr submit( ast::stmt::Container * cont
			, uint32_t & currentId
			, ast::type::TypesCache & cache
			, ModuleStruct & moduleStruct );

	private:
		class ModuleStructBuilder
		{
		public:
			ModuleStructBuilder( ast::stmt::ContainerPtr & result
				, ModuleStruct & moduleStruct
				, ast::type::TypesCache & cache
				, uint32_t & currentId );

			uint32_t getNextId();

			void beginBlock( BlockType type = BlockType::eFunction );
			void endBlock();

			void beginFunction( ast::type::FunctionPtr funcType );
			bool makeAlias( ast::stmt::Container * container
				, ast::expr::ExprPtr expr
				, bool param
				, ast::expr::ExprPtr & aliasExpr
				, VariablePtr & alias );
			void endFunction( ast::stmt::Container * container
				, ast::type::FunctionPtr funcType );

			void registerType( ast::type::TypePtr type );
			void registerVar( VariablePtr var );
			void registerUsage( VarUsage usage );
			void registerUsages( VarUsageArray usages );
			void registerBlockStruct( VarUsageArray blockVars );

			inline bool isGlobalScopeEmpty()const
			{
				return m_moduleStruct.types.empty()
					&& m_globalVars.empty();
			}

		private:
			void doRegisterVar( VariablePtr var );
			void doRegisterUse( VariablePtr var );
			void doUpdateVars( VariableArray * vars );

		private:
			ast::stmt::ContainerPtr & m_result;
			ModuleStruct & m_moduleStruct;
			ast::type::TypesCache & m_cache;
			IdSet m_intermediates;
			IdSet m_freeIntermediates;
			BlockStruct m_currentBlock;
			VariableArray * m_allVars;
			VariableArray m_globalVars;
			UsedVars m_usedVars;
			uint32_t scopeCurrentLevel{ 0u };
			uint32_t * m_currentId;
		};

		friend class ExprRegister;

	private:
		StmtRegister( ast::stmt::ContainerPtr & result
			, ModuleStructBuilder & builder
			, ast::type::TypesCache & cache
			, uint32_t & currentId );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr );

		void visitContainerStmt( ast::stmt::Container * stmt )override;
		void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override;
		void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override;
		void visitCompoundStmt( ast::stmt::Compound * stmt )override;
		void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override;
		void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override;
		void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override;
		void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override;
		void visitReturnStmt( ast::stmt::Return * stmt )override;
		void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override;
		void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override;
		void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override;
		void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override;
		void visitSimpleStmt( ast::stmt::Simple * stmt )override;
		void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override;
		void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override;
		void visitSwitchStmt( ast::stmt::Switch * stmt )override;
		void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override;
		void visitWhileStmt( ast::stmt::While * stmt )override;
		void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override;
		void visitPreprocElif( ast::stmt::PreprocElif * preproc )override;
		void visitPreprocElse( ast::stmt::PreprocElse * preproc )override;
		void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override;
		void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override;
		void visitPreprocIf( ast::stmt::PreprocIf * preproc )override;
		void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override;
		void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override;

	private:
		using TypeIdMap = std::map< spv::Id, ast::type::TypePtr >;

		ModuleStructBuilder & m_builder;
		ast::type::TypesCache & m_cache;
		uint32_t * m_currentId;
	};
}

#endif
