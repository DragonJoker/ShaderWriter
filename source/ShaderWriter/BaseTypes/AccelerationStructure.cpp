/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/AccelerationStructure.hpp"

#include <ShaderAST/ShaderBuilder.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>

namespace sdw
{
	AccelerationStructure::AccelerationStructure( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool writeStmt )
		: Value{ writer, std::move( expr ), true }
	{
		if ( getType()
			&& getType()->getKind() != type::Kind::eAccelerationStructure )
		{
			throw ast::Exception{ "Wrong type for acceleration structure." };
		}

		if ( writeStmt )
		{
			getBuilder().addStmt( sdw::makeSimple( getStmtCache( m_writer )
				, makeExpr( *this ) ) );
		}
	}

	AccelerationStructure::AccelerationStructure( Value rhs )
		: Value{ std::move( rhs ) }
	{
	}

	ast::type::TypePtr AccelerationStructure::makeType( ast::type::TypesCache & cache )
	{
		return cache.getAccelerationStructure();
	}
}
