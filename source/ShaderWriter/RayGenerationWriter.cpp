/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayGenerationWriter.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	//*************************************************************************

	RayGenerationIn::RayGenerationIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, launchID{ getU32Vec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getU32Vec3Member( *this, ast::Builtin::eLaunchSize ) }
	{
	}

	RayGenerationIn::RayGenerationIn( ShaderWriter & writer )
		: RayGenerationIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "rayGenIn"
					, makeType( getTypesCache( writer ) )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr RayGenerationIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eRayGeneration
			, FlagT );

		if ( !result->hasMember( ast::Builtin::eLaunchID ) )
		{
			result->declMember( ast::Builtin::eLaunchID
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLaunchSize
				, type::Kind::eVec3U32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	RayGenerationWriter::RayGenerationWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eRayGeneration, allocator }
	{
	}

	RayGenerationWriter::RayGenerationWriter( ShaderBuilder & builder )
		: EntryPointWriter{ builder }
	{
	}

	void RayGenerationWriter::implementMain( RayGenerationMainFunc const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eRayGenerationEntryPoint
			, function
			, makeInParam( RayGenerationIn{ *this } ) );
	}
}
