#include "ShaderWriter/PerVertex.hpp"

#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprMbrSelect.hpp>
#include <ASTGenerator/Stmt/StmtInOutVariableDecl.hpp>
#include <ASTGenerator/Type/TypeStruct.hpp>

namespace sdw
{
	namespace
	{
		type::TypePtr doGetType()
		{
			auto result = type::makeStructType( "gl_PerVertex" );
			result->addMember( type::getVec4F(), "gl_Position" );
			result->addMember( type::getFloat(), "gl_PointSize" );
			result->addMember( type::makeType( type::Kind::eFloat, type::UnknownArraySize ), "gl_ClipDistance" );
			return result;
		}
	}

	gl_PerVertex::gl_PerVertex()
		: Value{ nullptr, expr::makeIdentifier( var::makeVariable( doGetType(), "" ) ) }
		, m_source{ stmt::PerVertexDecl::Source::eVertexOutput }
	{
	}

	gl_PerVertex::gl_PerVertex( Shader & shader, stmt::PerVertexDecl::Source source )
		: Value{ &shader, expr::makeIdentifier( var::makeVariable( doGetType(), "" ) ) }
		, m_source{ source }
	{
		addStmt( *findContainer( *this )
			, stmt::makePerVertexDecl( source ) );
	}

	Vec4 gl_PerVertex::gl_Position()const
	{
		return Vec4{ findShader( *this )
			, expr::makeIdentifier( var::makeVariable( type::getVec4F(), "gl_Position" ) ) };
	}

	Float gl_PerVertex::gl_PointSize()const
	{
		return Float{ findShader( *this )
			, expr::makeIdentifier( var::makeVariable( type::getFloat(), "gl_PointSize" ) ) };
	}

	Float gl_PerVertex::gl_ClipDistance()const
	{
		return Float{ findShader( *this )
			, expr::makeIdentifier( var::makeVariable( type::makeType( type::Kind::eFloat, type::UnknownArraySize ), "gl_ClipDistance" ) ) };
	}
}
