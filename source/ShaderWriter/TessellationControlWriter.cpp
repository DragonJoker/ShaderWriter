/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TessellationControlWriter.hpp"

namespace sdw
{
	//*************************************************************************

	uint32_t getOuterArraySize( ast::type::PatchDomain domain )
	{
		switch ( domain )
		{
		case ast::type::PatchDomain::eIsolines:
			return 2u;
		case ast::type::PatchDomain::eTriangles:
			return 3u;
		case ast::type::PatchDomain::eQuads:
			return 4u;
		default:
			return 1u;
		}
	}

	uint32_t getInnerArraySize( ast::type::PatchDomain domain )
	{
		switch ( domain )
		{
		case ast::type::PatchDomain::eIsolines:
			return 0u;
		case ast::type::PatchDomain::eTriangles:
			return 1u;
		case ast::type::PatchDomain::eQuads:
			return 2u;
		default:
			return 0u;
		}
	}

	bool hasInnerLevel( ast::type::PatchDomain domain )
	{
		return domain != ast::type::PatchDomain::eIsolines;
	}

	//*************************************************************************

	TessControlPatchRoutineIn::TessControlPatchRoutineIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, primitiveID{ getMember< Int32 >( ast::Builtin::ePrimitiveID ) }
	{
	}

	TessControlPatchRoutineIn::TessControlPatchRoutineIn( ShaderWriter & writer )
		: TessControlPatchRoutineIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "tesscPatchIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	ast::type::StructPtr TessControlPatchRoutineIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_PatchRoutine"
			, ast::EntryPoint::eNone
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePatchVerticesIn ) )
		{
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TessControlMainIn::TessControlMainIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, primitiveID{ getMember< Int32 >( ast::Builtin::ePrimitiveID ) }
		, invocationID{ getMember< Int32 >( ast::Builtin::eInvocationID ) }
	{
	}

	TessControlMainIn::TessControlMainIn( ShaderWriter & writer )
		: TessControlMainIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "tesscGlobIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	ast::type::StructPtr TessControlMainIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eTessellationControl
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
		{
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInvocationID
				, type::Kind::eInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TessellationControlWriter::TessellationControlWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eTessellationControl, allocator }
	{
	}

	TessellationControlWriter::TessellationControlWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eTessellationControl, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eTessellationControl
			&& builder.getType() != ast::ShaderStage::eTraditionalGraphics )
		{
			throw ast::Exception{ "Can't create a TessellationControlWriter from this kind of builder." };
		}
	}

	//*************************************************************************
}
