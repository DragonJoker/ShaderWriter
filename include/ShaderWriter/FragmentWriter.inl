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
		, fragCoord{ this->getMember< Vec4 >( ast::Builtin::eFragCoord ) }
		, frontFacing{ this->getMember< Boolean >( ast::Builtin::eFrontFacing ) }
		, pointCoord{ this->getMember< Vec2 >( ast::Builtin::ePointCoord ) }
		, sampleID{ this->getMember< Int >( ast::Builtin::eSampleID ) }
		, samplePosition{ this->getMember< Vec2 >( ast::Builtin::eSamplePosition ) }
		, sampleMask{ this->getMemberArray< Int >( ast::Builtin::eSampleMaskIn ) }
		, clipDistance{ this->getMemberArray< Float >( ast::Builtin::eClipDistance ) }
		, primitiveID{ this->getMember< Int >( ast::Builtin::ePrimitiveID ) }
		, layer{ this->getMember< Int >( ast::Builtin::eLayer ) }
		, viewportIndex{ this->getMember< Int >( ast::Builtin::eViewportIndex ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr FragmentInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		auto result = InputT< DataT >::makeType( cache );

		if ( !result->hasMember( ast::Builtin::eFragCoord ) )
		{
			result->declMember( ast::Builtin::eFragCoord
				, type::Kind::eVec4F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eFrontFacing
				, type::Kind::eBoolean
				, ast::type::NotArray );
			result->declMember( ast::Builtin::ePointCoord
				, type::Kind::eVec2F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSampleID
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSamplePosition
				, type::Kind::eVec2F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSampleMaskIn
				, type::Kind::eInt
				, 8u );
			result->declMember( ast::Builtin::eClipDistance
				, type::Kind::eFloat
				, 8u );
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
		, fragDepth{ this->getMember< Float >( ast::Builtin::eFragDepth ) }
		, sampleMask{ this->getMemberArray< Int >( ast::Builtin::eSampleMask ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr FragmentOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		auto result = OutputT< DataT >::makeType( cache );

		if ( !result->hasMember( ast::Builtin::eFragDepth ) )
		{
			result->declMember( ast::Builtin::eFragDepth
				, type::Kind::eFloat
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSampleMask
				, type::Kind::eInt
				, 8u );
		}

		return result;
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
