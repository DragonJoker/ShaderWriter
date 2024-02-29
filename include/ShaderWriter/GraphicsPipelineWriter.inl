/*
See LICENSE file in root folder
*/
#include "GraphicsPipelineWriter.hpp"

namespace sdw
{
	/**
	*name
	*	Fragment Shader.
	*/
	/**@{*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void GraphicsPipelineWriter::implementEntryPointT( FragmentMainFuncT< InT, OutT > const & function )
	{
		this->implementEntryPointT( ast::FragmentOrigin::eUpperLeft
			, ast::FragmentCenter::eHalfPixel
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void GraphicsPipelineWriter::implementEntryPointT( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< InT, OutT > const & function )
	{
		this->implementEntryPointT( FragmentInT< InT >{ *this, origin, center }
			, FragmentOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void GraphicsPipelineWriter::implementEntryPointT( FragmentInT< InT > in
		, FragmentOutT< OutT > out
		, FragmentMainFuncT< InT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainFragment"
			, getEntryPointFlags( ast::EntryPoint::eFragment ) | uint32_t( ast::stmt::FunctionFlag::eFragmentEntryPoint )
			, function
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**
	*name
	*	Blend Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T GraphicsPipelineWriter::declBlendOutput( std::string name
		, uint32_t location
		, uint32_t blendIndex
		, bool enabled )
	{
		return declBlendOutput< T >( std::move( name )
			, location
			, blendIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline T GraphicsPipelineWriter::declBlendOutput( std::string name
		, uint32_t location
		, uint32_t blendIndex
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
			, EntryPoint::eFragment
			, location
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( makeInOutBlendVariableDecl( getStmtCache()
				, var
				, location
				, blendIndex ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > GraphicsPipelineWriter::declBlendOutputArray( std::string name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declBlendOutputArray< T >( std::move( name )
			, location
			, blendIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > GraphicsPipelineWriter::declBlendOutputArray( std::string name
		, uint32_t location
		, uint32_t blendIndex
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
			, EntryPoint::eFragment
			, location
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( makeInOutBlendVariableDecl( getStmtCache()
				, var
				, location
				, blendIndex ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
	/**@}*/
}
