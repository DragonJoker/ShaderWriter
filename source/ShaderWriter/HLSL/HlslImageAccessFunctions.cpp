/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp"
#include "ShaderWriter/HLSL/HlslExprAdapter.hpp"

#include <ASTGenerator/Expr/EnumIntrinsic.hpp>
#include <ASTGenerator/Expr/ExprBitAnd.hpp>
#include <ASTGenerator/Expr/ExprBitOr.hpp>
#include <ASTGenerator/Expr/ExprCast.hpp>
#include <ASTGenerator/Expr/ExprDivide.hpp>
#include <ASTGenerator/Expr/ExprEqual.hpp>
#include <ASTGenerator/Expr/ExprInit.hpp>
#include <ASTGenerator/Expr/ExprIntrinsicCall.hpp>
#include <ASTGenerator/expr/ExprLiteral.hpp>
#include <ASTGenerator/expr/ExprLShift.hpp>
#include <ASTGenerator/expr/ExprLShiftAssign.hpp>
#include <ASTGenerator/expr/ExprMbrSelect.hpp>
#include <ASTGenerator/expr/ExprOrAssign.hpp>
#include <ASTGenerator/expr/ExprRShift.hpp>
#include <ASTGenerator/expr/ExprRShiftAssign.hpp>
#include <ASTGenerator/expr/ExprTimes.hpp>

#include <ASTGenerator/Stmt/StmtFunctionDecl.hpp>
#include <ASTGenerator/Stmt/StmtReturn.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>
#include <ASTGenerator/Stmt/StmtVariableDecl.hpp>

#include <ASTGenerator/Type/TypeImage.hpp>

#include <string>

namespace sdw::hlsl
{
		using namespace ast;

		inline void writeImageSamples2DMS( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageSamples(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpY;" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dumpX, dumpY, res);" ) );
			cont->addStmt( stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageSamples2DMSArray( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageSamples(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpZ;" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dumpX, dumpY, dumpZ, res);" ) );
			cont->addStmt( stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

	void compileHlslImageAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
		//if ( config.requiresImageSamples2DMSF )
		//{
		//	details::writeImageSamples2DMS( container, "RWTexture2D<float4>" );
		//}
		//if ( config.requiresImageSamples2DMSI )
		//{
		//	details::writeImageSamples2DMS( container, "RWTexture2D<int4>" );
		//}
		//if ( config.requiresImageSamples2DMSU )
		//{
		//	details::writeImageSamples2DMS( container, "RWTexture2D<uint4>" );
		//}
		//if ( config.requiresImageSamples2DMSArrayF )
		//{
		//	details::writeImageSamples2DMSArray( container, "RWTexture2DArray<float4>" );
		//}
		//if ( config.requiresImageSamples2DMSArrayI )
		//{
		//	details::writeImageSamples2DMSArray( container, "RWTexture2DArray<int4>" );
		//}
		//if ( config.requiresImageSamples2DMSArrayU )
		//{
		//	details::writeImageSamples2DMSArray( container, "RWTexture2DArray<uint4>" );
		//}
	}
}
