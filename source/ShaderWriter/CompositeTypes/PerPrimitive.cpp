/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/PerPrimitive.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	PerPrimitive::PerPrimitive( StructInstance const & instance )
		: primitiveID{ instance.getMember< Int32 >( ast::Builtin::ePrimitiveID ) }
		, layer{ instance.getMember< Int32 >( ast::Builtin::eLayer ) }
		, viewportIndex{ instance.getMember< Int32 >( ast::Builtin::eViewportIndex ) }
		, viewportMask{ instance.getMemberArray< Int32 >( ast::Builtin::eViewportMaskNV ) }
	{
	}

	void PerPrimitive::fillType( ast::type::IOStruct & structType )
	{
		if ( !structType.hasMember( ast::Builtin::ePosition ) )
		{
			structType.declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt32
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::eLayer
				, type::Kind::eInt32
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::eViewportIndex
				, type::Kind::eInt32
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::eViewportMaskNV
				, type::Kind::eInt32
				, 1u );
		}
	}
}
