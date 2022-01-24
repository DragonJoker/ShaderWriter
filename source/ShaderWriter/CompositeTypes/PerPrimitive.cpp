/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/PerPrimitive.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	PerPrimitive::PerPrimitive( ShaderWriter & writer
		, StructInstance & instance
		, ast::var::Flag flag )
		: primitiveID{ instance.getMember< Int >( ast::Builtin::ePrimitiveID ) }
		, layer{ instance.getMember< Int >( ast::Builtin::eLayer ) }
		, viewportIndex{ instance.getMember< Int >( ast::Builtin::eViewportIndex ) }
		, viewportMask{ instance.getMemberArray< Int >( ast::Builtin::eViewportMaskNV ) }
	{
	}

	void PerPrimitive::fillType( ast::type::IOStruct & structType )
	{
		if ( !structType.hasMember( ast::Builtin::ePosition ) )
		{
			structType.declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::eLayer
				, type::Kind::eInt
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::eViewportIndex
				, type::Kind::eInt
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::eViewportMaskNV
				, type::Kind::eInt
				, 1u );
		}
	}
}
