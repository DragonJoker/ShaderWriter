/*
See LICENSE file in root folder
*/
#include "PipelineWriter.hpp"

namespace sdw
{
#pragma region Input declaration
	/**
	*name
	*	Input declaration.
	*/
	/**@{*/
	template< typename T >
	inline T PipelineWriter::declInput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, bool enabled )
	{
		return declInput< T >( std::move( name )
			, entryPoint
			, location
			, 0u
			, enabled );
	}

	template< typename T >
	inline T PipelineWriter::declInput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint64_t attributes
		, bool enabled )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerInput( std::move( name )
			, entryPoint
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( makeInOutVariableDecl( getStmtCache(), var
				, location ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > PipelineWriter::declInputArray( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		return declInputArray< T >( std::move( name )
			, entryPoint
			, location
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > PipelineWriter::declInputArray( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint32_t dimension
		, uint64_t attributes
		, bool enabled )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerInput( std::move( name )
			, entryPoint
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( makeInOutVariableDecl( getStmtCache(), var
				, location ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T PipelineWriter::declInput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, bool enabled
		, T const & defaultValue )
	{
		return declInput< T >( std::move( name )
			, entryPoint
			, location
			, 0u
			, enabled
			, defaultValue );
	}

	template< typename T >
	inline T PipelineWriter::declInput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint64_t attributes
		, bool enabled
		, T const & defaultValue )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = T::makeType( getTypesCache() );
		var::VariablePtr var;

		if ( enabled )
		{
			var = registerInput( std::move( name )
				, entryPoint
				, location
				, attributes
				, type );
			addStmt( makeInOutVariableDecl( getStmtCache(), var
				, location ) );
		}
		else
		{
			var = registerStaticConstant( std::move( name )
				, type );
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, true };
	}

	template< typename T >
	inline Array< T > PipelineWriter::declInputArray( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint32_t dimension
		, bool enabled
		, std::vector< T > const & defaultValue )
	{
		return declInputArray< T >( std::move( name )
			, entryPoint
			, location
			, dimension
			, 0u
			, enabled
			, defaultValue );
	}

	template< typename T >
	inline Array< T > PipelineWriter::declInputArray( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint32_t dimension
		, uint64_t attributes
		, bool enabled
		, std::vector< T > const & defaultValue )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		var::VariablePtr var;

		if ( enabled )
		{
			var = registerInput( std::move( name )
				, entryPoint
				, location
				, attributes
				, type );
			addStmt( makeInOutVariableDecl( getStmtCache(), var
				, location ) );
		}
		else
		{
			var = registerStaticConstant( std::move( name )
				, type );
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeAggrInit( var
					, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, true };
	}
	/**@}*/
#pragma endregion
#pragma region Output declaration
	/**
	*name
	*	Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T PipelineWriter::declOutput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, bool enabled )
	{
		return declOutput< T >( std::move( name )
			, entryPoint
			, location
			, 0u
			, enabled );
	}

	template< typename T >
	inline T PipelineWriter::declOutput( std::string name
		, EntryPoint entryPoint
		, uint32_t location
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
			, entryPoint
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( makeInOutVariableDecl( getStmtCache(), var
				, location ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > PipelineWriter::declOutputArray( std::string name
		, EntryPoint entryPoint
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		return declOutputArray< T >( std::move( name )
			, entryPoint
			, location
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > PipelineWriter::declOutputArray( std::string name
		, EntryPoint entryPoint
		, uint32_t location
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
			, entryPoint
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( makeInOutVariableDecl( getStmtCache(), var
				, location ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
#pragma endregion
}
