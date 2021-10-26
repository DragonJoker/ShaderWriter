/*
See LICENSE file in root folder
*/
#include "FragmentWriter.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentInT< DataT >::FragmentInT( ShaderWriter & writer )
		: FragmentInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "fragIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentInT< DataT >::FragmentInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, fragCoord{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eFragCoord
					, getTypesCache( writer ).getVec4F()
					, FlagT ) )
			, true }
		, frontFacing{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eFrontFacing
					, getTypesCache( writer ).getBool()
					, FlagT ) )
			, true }
		, pointCoord{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::ePointCoord
					, getTypesCache( writer ).getVec2F()
					, FlagT ) )
			, true }
		, sampleID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eSampleID
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, samplePosition{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eSamplePosition
					, getTypesCache( writer ).getVec2F()
					, FlagT ) )
			, true }
		, sampleMaskIn{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eSampleMask
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getInt() )
					, FlagT ) )
			, true }
		, clipDistance{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eClipDistance
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat() )
					, FlagT ) )
			, true }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::ePrimitiveID
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, layer{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eLayer
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, viewportIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eViewportIndex
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr FragmentInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentOutT< DataT >::FragmentOutT( ShaderWriter & writer )
		: FragmentOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "fragOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	FragmentOutT< DataT >::FragmentOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, fragDepth{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eFragDepth
					, getTypesCache( writer ).getFloat()
					, FlagT ) )
			, true }
		, sampleMask{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eSampleMask
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getInt() )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr FragmentOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	/**
	*name
	*	I/O layout declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void FragmentWriter::implementMainT( FragmentMainFuncT< InT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( FragmentInT< InT >{ *this } )
			, makeOutParam( FragmentOutT< OutT >{ *this } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void FragmentWriter::implementMainT( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< InT, OutT > const & function )
	{
		addStmt( stmt::makeFragmentLayout( origin, center ) );
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( FragmentInT< InT >{ *this } )
			, makeOutParam( FragmentOutT< OutT >{ *this } ) );
	}
	/**@}*/
	/**
	*name
	*	Blend Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T FragmentWriter::declBlendOutput( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, bool enabled )
	{
		return declBlendOutput< T >( name
			, location
			, blendIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline T FragmentWriter::declBlendOutput( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
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
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutBlendVariableDecl( var
				, location
				, blendIndex ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > FragmentWriter::declBlendOutputArray( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declBlendOutputArray< T >( name
			, location
			, blendIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > FragmentWriter::declBlendOutputArray( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
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
			, blendIndex
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutBlendVariableDecl( var
				, location
				, blendIndex ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/

	//*************************************************************************
}
