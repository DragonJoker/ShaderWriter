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
		, patchVerticesIn{ getMember< Int >( ast::Builtin::ePatchVerticesIn ) }
		, primitiveID{ getMember< Int >( ast::Builtin::ePrimitiveID ) }
		, tessCoord{ getMember< Vec3 >( ast::Builtin::eTessCoord ) }
	{
	}

	TessEvalMainIn::TessEvalMainIn( ShaderWriter & writer )
		: TessEvalMainIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "tesseGlobIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	ast::type::StructPtr TessEvalMainIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
			, "TessEvalMainIn"
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
		{
			result->declMember( ast::Builtin::ePatchVerticesIn
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eTessCoord
				, type::Kind::eVec3F
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TessellationEvaluationWriter::TessellationEvaluationWriter()
		: ShaderWriter{ ast::ShaderStage::eTessellationEvaluation }
	{
	}

	//*************************************************************************
}
