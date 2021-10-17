/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/compileSpirV.hpp"

#include "SpirvCountActions.hpp"
#include "SpirvStmtAdapter.hpp"
#include "SpirvStmtConfigFiller.hpp"
#include "SpirvStmtVisitor.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Visitors/StmtSimplifier.hpp>
#include <ShaderAST/Visitors/TransformSSA.hpp>

#include <iostream>

namespace spirv
{
	namespace
	{
		spirv::Module compileSpirV( ast::Shader const & shader
			, SpirVConfig config )
		{
			ast::SSAData ssaData;
			ssaData.nextVarId = shader.getData().nextVarId;
			auto ssaStatements = ast::transformSSA( shader.getTypesCache()
				, shader.getStatements()
				, ssaData );
			auto simplified = ast::StmtSimplifier::submit( shader.getTypesCache()
				, ssaStatements.get() );
			ModuleConfig moduleConfig = spirv::StmtConfigFiller::submit( simplified.get() );
			moduleConfig.aliasId = ssaData.aliasId;
			moduleConfig.nextVarId = ssaData.nextVarId;
			spirv::PreprocContext context{};
			AdaptationData adaptationData{ context, moduleConfig };
			auto spirvStatements = spirv::StmtAdapter::submit( simplified.get(), adaptationData );
			auto actions = listActions( simplified.get() );
			return spirv::StmtVisitor::submit( shader.getTypesCache()
				, spirvStatements.get()
				, shader.getType()
				, moduleConfig
				, std::move( context )
				, config
				, std::move( actions ) );
		}
	}

	std::string writeSpirv( ast::Shader const & shader
		, SpirVConfig config
		, bool writeHeader )
	{
		std::string result;

		try
		{
			auto module = compileSpirV( shader, std::move( config ) );
			result = Module::write( module, writeHeader );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}

	std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, SpirVConfig config )
	{
		std::vector< uint32_t > result;

		try
		{
			auto module = compileSpirV( shader, std::move( config ) );
			result = Module::serialize( module );
		}
		catch ( std::exception & exc )
		{
			std::cerr << exc.what() << std::endl;
		}

		return result;
	}
}
