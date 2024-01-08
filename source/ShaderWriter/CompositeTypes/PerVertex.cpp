/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/PerVertex.hpp"

#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Expr/ExprArrayAccess.hpp>
#include <ShaderAST/Expr/ExprIdentifier.hpp>

namespace sdw
{
	PerVertex::PerVertex( StructInstance const & instance )
		: position{ instance.getMember< Vec4 >( ast::Builtin::ePosition ) }
		, pointSize{ instance.getMember< Float >( ast::Builtin::ePointSize ) }
		, clipDistance{ instance.getMemberArray< Float >( ast::Builtin::eClipDistance ) }
		, cullDistance{ instance.getMemberArray< Float >( ast::Builtin::eCullDistance ) }
	{
	}

	void PerVertex::fillType( ast::type::IOStruct & structType )
	{
		if ( !structType.hasMember( ast::Builtin::ePosition ) )
		{
			structType.declMember( ast::Builtin::ePosition
				, type::Kind::eVec4F
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::ePointSize
				, type::Kind::eFloat
				, ast::type::NotArray );
			structType.declMember( ast::Builtin::eClipDistance
				, type::Kind::eFloat
				, 8u );
			structType.declMember( ast::Builtin::eCullDistance
				, type::Kind::eFloat
				, 8u );
		}
	}
}
