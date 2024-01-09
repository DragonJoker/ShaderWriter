/*
See LICENSE file in root folder
*/
#include "HlslIntrinsicFunctions.hpp"
#include "HlslCombinedImageAccessFunctions.hpp"

#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtComment.hpp>

namespace hlsl
{
	namespace details
	{
		void writeProjectTexCoords2( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float SDW_projectTexCoords2(float2 texCoords)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn texCoords.x / texCoords.y;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		void writeProjectTexCoords3( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_projectTexCoords3(float3 texCoords)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn texCoords.xy / texCoords.z;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		void writeProjectTexCoords4To1( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float SDW_projectTexCoords4to1(float4 texCoords)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn texCoords.x / texCoords.w;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		void writeProjectTexCoords4To2( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_projectTexCoords4To2(float4 texCoords)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn texCoords.xy / texCoords.w;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		void writeProjectTexCoords4( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float3 SDW_projectTexCoords4(float4 texCoords)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn texCoords.xyz / texCoords.w;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
	}

	void compileHlslTextureAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
		if ( config.requiresProjectTexCoords2 )
		{
			details::writeProjectTexCoords2( container );
		}
		if ( config.requiresProjectTexCoords3 )
		{
			details::writeProjectTexCoords3( container );
		}
		if ( config.requiresProjectTexCoords4To1 )
		{
			details::writeProjectTexCoords4To1( container );
		}
		if ( config.requiresProjectTexCoords4To2 )
		{
			details::writeProjectTexCoords4To2( container );
		}
		if ( config.requiresProjectTexCoords4 )
		{
			details::writeProjectTexCoords4( container );
		}
	}
}
