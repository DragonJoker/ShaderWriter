/*
See LICENSE file in root folder
*/
#include "TessellationControlWriter.hpp"

#include "BaseTypes/Float.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlDataInT< DataT >::TessControlDataInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< EntryPoint::eTessellationControl, DataT >{ writer, std::move( expr ), enabled }
		, vtx{ *this }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TessControlDataInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = InputT< EntryPoint::eTessellationControl, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	TessControlListInT< DataT, MaxPointsT >::TessControlListInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< TessControlDataInT< DataT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	template< typename ... ParamsT >
	TessControlListInT< DataT, MaxPointsT >::TessControlListInT( ShaderWriter & writer
		, bool fromEntryPoint
		, ParamsT && ... params )
		: TessControlListInT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "tesscIn"
					, ast::type::makeTessellationControlInputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... ), MaxPointsT )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TessControlListInT< DataT, MaxPointsT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return TessControlDataInT< DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	TessControlListOutT< DataT, DomainT >::TessControlListOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< EntryPoint::eTessellationControl, DataT >{ writer, std::move( expr ), enabled }
		, vtx{ *this }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	template< typename ... ParamsT >
	TessControlListOutT< DataT, DomainT >::TessControlListOutT( ShaderWriter & writer
		, ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertex
		, ParamsT && ... params )
		: TessControlListOutT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "tesscOut"
					, ast::type::makeTessellationControlOutputType( makeType( getTypesCache( writer )
							, std::forward< ParamsT >( params )... )
						, DomainT
						, partitioning
						, topology
						, vertexOrder
						, outputVertex )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TessControlListOutT< DataT, DomainT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = OutputT< EntryPoint::eTessellationControl, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	TessPatchOutT< DataT, DomainT >::TessPatchOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PatchOutT< DataT >{ writer, std::move( expr ), enabled }
		, tessLevelOuter{ getFloatMemberArray( *this, ast::Builtin::eTessLevelOuter ) }
		, tessLevelInner{ getFloatMemberArray( *this, ast::Builtin::eTessLevelInner ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	template< typename ... ParamsT >
	TessPatchOutT< DataT, DomainT >::TessPatchOutT( ShaderWriter & writer
		, uint32_t patchLocation
		, ParamsT && ... params )
		: TessPatchOutT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "tesscPatch"
					, ast::type::makeTessellationOutputPatchType( makeType( getTypesCache( writer )
							, std::forward< ParamsT >( params )... )
						, patchLocation )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	template< typename ... ParamsT >
	ast::type::TypePtr TessPatchOutT< DataT, DomainT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		auto result = PatchOutT< DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::eTessLevelOuter ) )
		{
			result->declMember( ast::Builtin::eTessLevelOuter
				, type::Kind::eFloat
				, getOuterArraySize( DomainT ) );
			result->declMember( ast::Builtin::eTessLevelInner
				, type::Kind::eFloat
				, getInnerArraySize( DomainT ) );
		}

		return result;
	}

	//*************************************************************************

	/**
	*name
	*	Patch routine declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::PatchDomain DomainT >
	void TessellationControlWriter::implementPatchRoutineT( uint32_t patchLocation
		, TessControlPatchRoutineT< InT, MaxPointsT, PatchT, DomainT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( TessPatchOutT< PatchT, DomainT >{ *this, patchLocation } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementPatchRoutineT( uint32_t patchLocation
		, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		this->implementPatchRoutineT( TessControlListInT< InT, MaxPointsT >{ *this, true }
			, IsolinesTessPatchOutT< PatchT >{ *this, patchLocation }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementPatchRoutineT( uint32_t patchLocation
		, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		this->implementPatchRoutineT( TessControlListInT< InT, MaxPointsT >{ *this, true }
			, TrianglesTessPatchOutT< PatchT >{ *this, patchLocation }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementPatchRoutineT( uint32_t patchLocation
		, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		this->implementPatchRoutineT( TessControlListInT< InT, MaxPointsT >{ *this, true }
			, QuadsTessPatchOutT< PatchT >{ *this, patchLocation }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
		, IsolinesTessPatchOutT< PatchT > out
		, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
		, TrianglesTessPatchOutT< PatchT > out
		, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
		, QuadsTessPatchOutT< PatchT > out
		, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT
		, ast::type::PatchDomain DomainT >
	void TessellationControlWriter::implementMainT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, TessControlMainFuncT< InT, MaxPointsT, OutT, DomainT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( TessControlListOutT< OutT, DomainT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementMainT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		this->implementMainT( TessControlListInT< InT, MaxPointsT >{ *this, false }
			, IsolinesTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementMainT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		this->implementMainT( TessControlListInT< InT, MaxPointsT >{ *this, false }
			, TrianglesTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementMainT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		this->implementMainT( TessControlListInT< InT, MaxPointsT >{ *this, false }
			, QuadsTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementMainT( TessControlListInT< InT, MaxPointsT > in
		, IsolinesTessControlListOutT< OutT > out
		, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementMainT( TessControlListInT< InT, MaxPointsT > in
		, TrianglesTessControlListOutT< OutT > out
		, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementMainT( TessControlListInT< InT, MaxPointsT > in
		, QuadsTessControlListOutT< OutT > out
		, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/

	//*************************************************************************
}
