/*
See LICENSE file in root folder
*/
#include "GeometryWriter.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	GeometryInT< DataT, LayoutT >::GeometryInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< InputT< DataT > >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_in"
					, PerVertex::getArrayType( getTypesCache( writer ), getArraySize( LayoutT ) )
					, FlagT ) )
			, true }
		, primitiveIDIn{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_PrimitiveIDIn"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, invocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_InvocationID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	GeometryInT< DataT, LayoutT >::GeometryInT( ShaderWriter & writer )
		: GeometryInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomIn"
					, ast::type::makeGeometryInputType( makeType( getTypesCache( writer ) )
						, LayoutT )
					, FlagT ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryInput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	ast::type::TypePtr GeometryInT< DataT, LayoutT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	GeometryOutT< DataT, LayoutT >::GeometryOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ""
					, PerVertex::getBaseType( getTypesCache( writer ) )
					, FlagT ) ) }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_PrimitiveID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, layer{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_Layer"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, viewportIndex{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_ViewportIndex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	GeometryOutT< DataT, LayoutT >::GeometryOutT( ShaderWriter & writer
		, uint32_t count )
		: GeometryOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomOut"
					, ast::type::makeGeometryOutputType( makeType( getTypesCache( writer ) )
						, LayoutT
						, count )
					, FlagT ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	void GeometryOutT< DataT, LayoutT >::append()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( ast::expr::makeStreamAppend( sdw::makeExpr( *this ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	void GeometryOutT< DataT, LayoutT >::restartStrip()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( ast::expr::makeEndPrimitive( getTypesCache( writer ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	ast::type::TypePtr GeometryOutT< DataT, LayoutT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	/**
	*name
	*	I/O layout declaration.
	*/
	/**@{*/
	template< uint32_t MaxPrimCountT, typename InputArrT, typename OutStreamT >
	inline void GeometryWriter::implementMainT( std::function< void( InputArrT, OutStreamT ) > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( InputArrT{ *this } )
			, makeInOutParam( OutStreamT{ *this, MaxPrimCountT } ) );
	}
	/**@}*/
	/**
	*name
	*	Stream Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T GeometryWriter::declStreamOutput( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, bool enabled )
	{
		return declStreamOutput< T >( name
			, location
			, streamIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline T GeometryWriter::declStreamOutput( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutStreamVariableDecl( var
				, location
				, streamIndex ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > GeometryWriter::declStreamOutputArray( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declStreamOutputArray< T >( name
			, location
			, streamIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > GeometryWriter::declStreamOutputArray( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location
				, streamIndex ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/

	//*************************************************************************
}
