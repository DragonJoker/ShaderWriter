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

#if !defined( NDEBUG )
		*this << "#pragma optimize(off)" << endl;
		*this << "#pragma debug(on)" << endl;
#endif
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
