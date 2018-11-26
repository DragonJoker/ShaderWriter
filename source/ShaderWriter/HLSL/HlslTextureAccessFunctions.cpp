/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp"

#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtComment.hpp>

namespace sdw::hlsl
{
	namespace details
	{
		using namespace ast;

		inline void writeProjectTexCoords2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_projectTexCoords2(float2 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.x / texCoords.y;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords3( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_projectTexCoords3(float3 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.xy / texCoords.z;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords4To1( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_projectTexCoords4to1(float4 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.x / texCoords.w;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords4To2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_projectTexCoords4To2(float4 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.xy / texCoords.w;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeProjectTexCoords4( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float3 SDW_projectTexCoords4(float4 texCoords)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return texCoords.xyz / texCoords.w;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
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
