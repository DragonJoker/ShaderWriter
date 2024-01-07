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
		, primitiveID{ this->getMember< Int32 >( ast::Builtin::ePrimitiveIDIn ) }
		, invocationID{ this->getMember< Int32 >( ast::Builtin::eInvocationID ) }
	{
	}

	GeometryIn::GeometryIn( ShaderWriter & writer )
		: GeometryIn{ writer
		, makeExpr( writer
			, sdw::getBuilder( writer ).registerName( "geomGlobIn"
				, makeType( getTypesCache( writer ) )
				, FlagT ) ) }
	{
	}

	ast::type::StructPtr GeometryIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eGeometry
			, FlagT );

		if ( !result->hasMember( ast::Builtin::ePrimitiveIDIn ) )
		{
			result->declMember( ast::Builtin::ePrimitiveIDIn
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInvocationID
				, type::Kind::eInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	GeometryWriter::GeometryWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eGeometry, allocator }
	{
	}

	GeometryWriter::GeometryWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eGeometry, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eGeometry
			&& builder.getType() != ast::ShaderStage::eTraditionalGraphics )
		{
			throw ast::Exception{ "Can't create a GeometryWriter from this kind of builder." };
		}
	}

	//*************************************************************************
}
