/*
See LICENSE file in root folder
*/
#include "GeometryWriter.hpp"

#include "BaseTypes/Int.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	GeometryDataT< DataT >::GeometryDataT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< EntryPoint::eGeometry, DataT >{ writer, std::move( expr ), enabled }
		, vtx{ *this }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr GeometryDataT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = InputT< EntryPoint::eGeometry, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	GeometryListT< DataT, LayoutT >::GeometryListT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< GeometryDataT< DataT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	template< typename ... ParamsT >
	GeometryListT< DataT, LayoutT >::GeometryListT( ShaderWriter & writer
		, ParamsT && ... params )
		: GeometryListT{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "geomIn"
					, ast::type::makeGeometryInputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, LayoutT )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr GeometryListT< DataT, LayoutT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return GeometryDataT< DataT >::makeType( cache, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	GeometryOutT< DataT, LayoutT >::GeometryOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< EntryPoint::eGeometry, DataT >{ writer, std::move( expr ), enabled }
		, vtx{ *this }
		, primitiveID{ getInt32Member( *this, ast::Builtin::ePrimitiveID ) }
		, layer{ getInt32Member( *this, ast::Builtin::eLayer ) }
		, viewportIndex{ getInt32Member( *this, ast::Builtin::eViewportIndex ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	template< typename ... ParamsT >
	GeometryOutT< DataT, LayoutT >::GeometryOutT( ShaderWriter & writer
		, uint32_t count
		, ParamsT && ... params )
		: GeometryOutT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "geomOut"
					, ast::type::makeGeometryOutputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, LayoutT
						, count )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	void GeometryOutT< DataT, LayoutT >::append()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( getStmtCache( writer )
				, getExprCache( writer ).makeStreamAppend( sdw::makeExpr( *this ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	void GeometryOutT< DataT, LayoutT >::restartStrip()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( getStmtCache( writer )
				, makeEndPrimitive( getExprCache( writer ), getTypesCache( writer ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr GeometryOutT< DataT, LayoutT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		auto result = OutputT< EntryPoint::eGeometry, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
		PerVertex::fillType( *result );

		if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
		{
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLayer
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eViewportIndex
				, type::Kind::eInt
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< uint32_t MaxPrimCountT, typename InputArrT, typename OutStreamT >
	inline void GeometryWriter::implementMainT( GeometryMainFuncT< InputArrT, OutStreamT > const & function )
	{
		this->implementMainT( InputArrT{ *this }
			, OutStreamT{ *this, MaxPrimCountT }
			, function );
	}

	template< typename InputArrT, typename OutStreamT >
	inline void GeometryWriter::implementMainT( InputArrT in
		, OutStreamT out
		, GeometryMainFuncT< InputArrT, OutStreamT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eGeometryEntryPoint )
			, function
			, makeInParam( GeometryIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeInOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**
	*name
	*	Stream Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T GeometryWriter::declStreamOutput( std::string name
		, uint32_t location
		, uint32_t streamIndex
		, bool enabled )
	{
		return declStreamOutput< T >( std::move( name )
			, location
			, streamIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline T GeometryWriter::declStreamOutput( std::string name
		, uint32_t location
		, uint32_t streamIndex
		, uint64_t attributes
		, bool enabled )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( std::move( name )
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( makeInOutStreamVariableDecl( getStmtCache()
				, var
				, location
				, streamIndex ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > GeometryWriter::declStreamOutputArray( std::string name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declStreamOutputArray< T >( std::move( name )
			, location
			, streamIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > GeometryWriter::declStreamOutputArray( std::string name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, uint64_t attributes
		, bool enabled )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( std::move( name )
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( makeInOutVariableDecl( getStmtCache(), var
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
