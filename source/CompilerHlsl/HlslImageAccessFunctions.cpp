/*
See LICENSE file in root folder
*/
#include "HlslIntrinsicFunctions.hpp"
#include "HlslImageAccessFunctions.hpp"
#include "HlslExprAdapter.hpp"

#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtComment.hpp>

namespace hlsl
{
	namespace details
	{
		inline void writeImageSamples2DMS( ast::stmt::Container * container, std::string const & type )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int SDW_imageSamples(" + type + " image)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint dumpX;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint dumpY;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint res;" ) );
			cont->addStmt( ast::stmt::makeComment( "	image.GetDimensions(dumpX, dumpY, res);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageSamples2DMSArray( ast::stmt::Container * container, std::string const & type )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int SDW_imageSamples(" + type + " image)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint dumpX;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint dumpY;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint dumpZ;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint res;" ) );
			cont->addStmt( ast::stmt::makeComment( "	image.GetDimensions(dumpX, dumpY, dumpZ, res);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
	}

	void compileHlslImageAccessFunctions( ast::stmt::Container * /*container*/
		, IntrinsicsConfig const & /*config*/ )
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
