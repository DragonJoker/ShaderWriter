/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslAdaptStatements_H___
#define ___SDW_GlslAdaptStatements_H___
#pragma once

#include "CompilerGlsl/compileGlsl.hpp"

#include <ShaderAST/Visitors/CloneStmt.hpp>

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

	ast::stmt::ContainerPtr adaptStatements( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::stmt::Container const & container
		, AdaptationData & adaptationData );
}

#endif
