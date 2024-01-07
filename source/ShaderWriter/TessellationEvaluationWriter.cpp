/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TessellationEvaluationWriter.hpp"

namespace sdw
{
	//*************************************************************************

	TessEvalMainIn::TessEvalMainIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, patchVerticesIn{ getMember< Int32 >( ast::Builtin::ePatchVerticesIn ) }
		, primitiveID{ getMember< Int32 >( ast::Builtin::ePrimitiveID ) }
	{
	}

	TessEvalMainIn::TessEvalMainIn( ShaderWriter & writer )
		: TessEvalMainIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "tesseGlobIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	ast::type::StructPtr TessEvalMainIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eTessellationEvaluation
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
		{
			result->declMember( ast::Builtin::ePatchVerticesIn
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TessellationEvaluationWriter::TessellationEvaluationWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eTessellationEvaluation, allocator }
	{
	}

	TessellationEvaluationWriter::TessellationEvaluationWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eTessellationEvaluation, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eTessellationEvaluation
			&& builder.getType() != ast::ShaderStage::eTraditionalGraphics )
		{
			throw ast::Exception{ "Can't create a TessellationEvaluationWriter from this kind of builder." };
		}
	}

	//*************************************************************************
}
