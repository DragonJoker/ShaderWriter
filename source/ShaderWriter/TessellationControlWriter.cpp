/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TessellationControlWriter.hpp"

namespace sdw
{
	//*************************************************************************

	uint32_t getOuterArraySize( ast::type::OutputDomain domain )
	{
		switch ( domain )
		{
		case ast::type::OutputDomain::eIsolines:
			return 2u;
		case ast::type::OutputDomain::eTriangles:
			return 3u;
		case ast::type::OutputDomain::eQuads:
			return 4u;
		default:
			return 1u;
		}
	}

	uint32_t getInnerArraySize( ast::type::OutputDomain domain )
	{
		switch ( domain )
		{
		case ast::type::OutputDomain::eIsolines:
			return 0u;
		case ast::type::OutputDomain::eTriangles:
			return 1u;
		case ast::type::OutputDomain::eQuads:
			return 2u;
		default:
			return 0u;
		}
	}

	bool hasInnerLevel( ast::type::OutputDomain domain )
	{
		return domain != ast::type::OutputDomain::eIsolines;
	}

	//*************************************************************************

	TessControlPatchRoutineIn::TessControlPatchRoutineIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, primitiveID{ getMember< Int >( ast::Builtin::ePrimitiveID ) }
	{
	}

	TessControlPatchRoutineIn::TessControlPatchRoutineIn( ShaderWriter & writer )
		: TessControlPatchRoutineIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "tesscGlobIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	ast::type::StructPtr TessControlPatchRoutineIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
			, "TessControlPatchRoutineIn"
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePatchVerticesIn ) )
		{
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TessControlMainIn::TessControlMainIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, primitiveID{ getMember< Int >( ast::Builtin::ePrimitiveID ) }
		, invocationID{ getMember< Int >( ast::Builtin::eInvocationID ) }
	{
	}

	TessControlMainIn::TessControlMainIn( ShaderWriter & writer )
		: TessControlMainIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "tesscGlobIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	ast::type::StructPtr TessControlMainIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
			, "TessControlMainIn"
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
		{
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInvocationID
				, type::Kind::eInt
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TessellationControlWriter::TessellationControlWriter()
		: ShaderWriter{ ast::ShaderStage::eTessellationControl }
	{
	}
}
