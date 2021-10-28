/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GeometryWriter.hpp"

namespace sdw
{
	//*************************************************************************

		GeometryIn::GeometryIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, primitiveID{ this->getMember< Int >( ast::Builtin::ePrimitiveIDIn ) }
		, invocationID{ this->getMember< Int >( ast::Builtin::eInvocationID ) }
	{
	}

	GeometryIn::GeometryIn( ShaderWriter & writer )
		: GeometryIn{ writer
		, makeExpr( writer
			, sdw::getShader( writer ).registerName( "geomGlobIn"
				, makeType( getTypesCache( writer ) )
				, FlagT ) ) }
	{
	}

	ast::type::StructPtr GeometryIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
			, "GeometryIn"
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePrimitiveIDIn ) )
		{
			result->declMember( ast::Builtin::ePrimitiveIDIn
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInvocationID
				, type::Kind::eInt
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	GeometryWriter::GeometryWriter()
		: ShaderWriter{ ast::ShaderStage::eGeometry }
	{
	}

	//*************************************************************************
}
