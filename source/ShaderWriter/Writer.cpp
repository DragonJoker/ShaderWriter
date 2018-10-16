#if 0
#include "ShaderWriter/Writer.hpp"

#include "ShaderWriter/Vec.hpp"
#include "ShaderWriter/Intrinsics.hpp"

namespace sdw
{
	GlslWriter::GlslWriter( GlslWriterConfig const & config )
		: m_keywords( sdw::KeywordsBase::get( config ) )
		, m_uniform( cuT( "uniform " ) )
		, m_config( config )
	{
		m_stream.imbue( Expr::getLocale() );
		*this << sdw::Version() << endl;

#if !defined( NDEBUG )
		*this << "#pragma optimize(off)" << endl;
		*this << "#pragma debug(on)" << endl;
#endif

		if ( m_config.m_shaderLanguageVersion < 430 )
		{
			*this << "#extension GL_ARB_explicit_attrib_location : enable" << endl;
			*this << "#extension GL_ARB_explicit_uniform_location : enable" << endl;
			*this << "#extension GL_ARB_separate_shader_objects : enable" << endl;
			*this << "#extension GL_ARB_shading_language_420pack : enable" << endl;
			*this << "#extension GL_ARB_texture_cube_map_array : enable" << endl;
		}
	}

	void GlslWriter::inlineComment( std::string const & comment )
	{
		m_stream << cuT( "// " ) << comment << std::endl;
	}

	void GlslWriter::multilineComment( std::string const & comment )
	{
		m_stream << cuT( "/*" ) << comment << "*/" << std::endl;
	}

	void GlslWriter::enableExtension( std::string const & name, uint32_t inCoreVersion )
	{
		if ( getShaderLanguageVersion() < inCoreVersion
			|| !inCoreVersion )
		{
			m_stream << "#extension " << name << ": enable" << std::endl;
		}
	}

	std::string GlslWriter::getInstanceID()
	{
		if ( m_config.m_hasInstanceIndex )
		{
			return cuT( "gl_InstanceIndex" );
		}
		else
		{
			return cuT( "gl_InstanceID" );
		}
	}

	std::string GlslWriter::getVertexID()
	{
		if ( m_config.m_hasVertexIndex )
		{
			return cuT( "gl_VertexIndex" );
		}
		else
		{
			return cuT( "gl_VertexID" );
		}
	}

	Vec2 GlslWriter::ashesBottomUpToTopDown( Vec2 const & texCoord )
	{
		return writeFunctionCall< Vec2 >( this
			, cuT( "ashesBottomUpToTopDown" )
			, texCoord );
	}

	Vec2 GlslWriter::ashesTopDownToBottomUp( Vec2 const & texCoord )
	{
		return writeFunctionCall< Vec2 >( this
			, cuT( "ashesTopDownToBottomUp" )
			, texCoord );
	}

	Vec3 GlslWriter::ashesBottomUpToTopDown( Vec3 const & texCoord )
	{
		return writeFunctionCall< Vec3 >( this
			, cuT( "ashesBottomUpToTopDown" )
			, texCoord );
	}

	Vec3 GlslWriter::ashesTopDownToBottomUp( Vec3 const & texCoord )
	{
		return writeFunctionCall< Vec3 >( this
			, cuT( "ashesTopDownToBottomUp" )
			, texCoord );
	}

	void GlslWriter::forStmt( Type && init, Expr const & cond, Expr const & incr, std::function< void() > function )
	{
		m_stream << std::endl;
		m_stream << cuT( "for ( " ) << std::string( init ) << cuT( "; " ) << cond.m_value.rdbuf() << cuT( "; " ) << incr.m_value.rdbuf() << cuT( " )" ) << std::endl;
		{
			IndentBlock block( *this );
			function();
		}
		m_stream << std::endl;
	}

	void GlslWriter::whileStmt( Expr const & cond, std::function< void() > function )
	{
		m_stream << std::endl;
		m_stream << cuT( "while ( " ) << cond.m_value.rdbuf() << cuT( " )" ) << std::endl;
		{
			IndentBlock block( *this );
			function();
		}
		m_stream << std::endl;
	}

	GlslWriter & GlslWriter::ifStmt( Expr const & cond, std::function< void() > function )
	{
		m_stream << std::endl;
		m_stream << cuT( "if ( " ) << cond.m_value.rdbuf() << cuT( " )" ) << std::endl;
		{
			IndentBlock block( *this );
			function();
		}
		m_stream << std::endl;
		return *this;
	}

	GlslWriter & GlslWriter::elseIfStmt( Expr const & cond, std::function< void() > function )
	{
		m_stream << cuT( "else if ( " ) << cond.m_value.rdbuf() << cuT( " )" ) << std::endl;
		{
			IndentBlock block( *this );
			function();
		}
		m_stream << std::endl;
		return *this;
	}

	void GlslWriter::elseStmt( std::function< void() > function )
	{
		m_stream << cuT( "else" ) << std::endl;
		{
			IndentBlock block( *this );
			function();
		}
		m_stream << std::endl;
	}

	void GlslWriter::emitVertex()
	{
		m_stream << cuT( "emitVertex();" ) << std::endl;
	}

	void GlslWriter::endPrimitive()
	{
		m_stream << cuT( "endPrimitive();" ) << std::endl;
	}

	void GlslWriter::discard()
	{
		m_stream << cuT( "discard;" ) << std::endl;
	}

	void GlslWriter::inputGeometryLayout( std::string const & layout )
	{
		m_stream << cuT( "layout( " ) << layout << cuT( " ) in;" ) << std::endl;
	}

	void GlslWriter::outputGeometryLayout( std::string const & layout )
	{
		m_stream << cuT( "layout( " ) << layout << cuT( " ) out;" ) << std::endl;
	}

	void GlslWriter::outputGeometryLayout( std::string const & layout, uint32_t count )
	{
		m_stream << cuT( "layout( " ) << layout << cuT( ", max_vertices = " ) << count << cuT( " ) out;" ) << std::endl;
	}

	void GlslWriter::outputVertexCount( uint32_t count )
	{
		m_stream << cuT( "layout( max_vertices = " ) << count << cuT( " ) out;" ) << std::endl;
	}

	GlslWriter & GlslWriter::operator<<( Version const & rhs )
	{
		m_stream << m_keywords->getVersion();
		return *this;
	}

	GlslWriter & GlslWriter::operator<<( InputLayout const & rhs )
	{
		static std::map< InputLayout::Kind, std::string > const Names
		{
			{ InputLayout::Kind::ePoints, cuT( "points" ) },
			{ InputLayout::Kind::eLines, cuT( "lines" ) },
			{ InputLayout::Kind::eLinesAdjacency, cuT( "lines_adjacency" ) },
			{ InputLayout::Kind::eTriangles, cuT( "triangles" ) },
			{ InputLayout::Kind::eTrianglesAdjacency, cuT( "triangles_adjacency" ) },
		};
		REQUIRE( rhs.m_kind >= InputLayout::Kind::ePoints && rhs.m_kind <= InputLayout::Kind::eTrianglesAdjacency );
		m_stream << cuT( "layout( " ) << Names.at( rhs.m_kind ) << cuT( " ) in;" ) << std::endl;
		return *this;
	}

	GlslWriter & GlslWriter::operator<<( OutputLayout const & rhs )
	{
		static std::map< OutputLayout::Kind, std::string > const Names
		{
			{ OutputLayout::Kind::ePoints, cuT( "points" ) },
			{ OutputLayout::Kind::eLineStrip, cuT( "line_strip" ) },
			{ OutputLayout::Kind::eTriangleStrip, cuT( "triangle_strip" ) },
		};
		REQUIRE( rhs.m_kind >= OutputLayout::Kind::ePoints && rhs.m_kind <= OutputLayout::Kind::eTriangleStrip );
		m_stream << cuT( "layout( " ) << Names.at( rhs.m_kind ) << cuT( ", max_vertices = " ) << rhs.m_count << cuT( " ) out;" ) << std::endl;
		return *this;
	}
}
#endif
