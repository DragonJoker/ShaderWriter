/*
See LICENSE file in root folder
*/
#include "TessellationEvaluationWriter.hpp"

#include "BaseTypes/Float.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalDataInT< DataT >::TessEvalDataInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< EntryPoint::eTessellationEvaluation, DataT >{ writer, std::move( expr ), enabled }
		, vtx{ *this }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TessEvalDataInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = InputT< EntryPoint::eTessellationEvaluation, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t InputVerticesT >
	TessEvalListInT< DataT, InputVerticesT >::TessEvalListInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
		: Array< TessEvalDataInT< DataT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t InputVerticesT >
	template< typename ... ParamsT >
	TessEvalListInT< DataT, InputVerticesT >::TessEvalListInT( ShaderWriter & writer
		, ast::type::PatchDomain domain
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, ParamsT && ... params )
		: TessEvalListInT{ writer
		, makeExpr( writer
			, getBuilder( writer ).registerName( "tesseListIn"
				, ast::type::makeTessellationEvaluationInputType( makeType( getTypesCache( writer )
						, std::forward< ParamsT >( params )... )
					, domain
					, partitioning
					, ordering
					, InputVerticesT )
				, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t InputVerticesT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TessEvalListInT< DataT, InputVerticesT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return TessEvalDataInT< DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}
	
	//*************************************************************************
	
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	TessPatchInT< DataT, DomainT >::TessPatchInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PatchInT< DataT >{ writer, std::move( expr ), enabled }
		, tessLevelOuter{ getFloatMemberArray( *this, ast::Builtin::eTessLevelOuter ) }
		, tessLevelInner{ getFloatMemberArray( *this, ast::Builtin::eTessLevelInner ) }
		, tessCoord{ getVec3Member( *this, ast::Builtin::eTessCoord ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	template< typename ... ParamsT >
	TessPatchInT< DataT, DomainT >::TessPatchInT( ShaderWriter & writer
		, uint32_t patchLocation
		, ParamsT && ... params )
		: TessPatchInT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "tessePatch"
					, ast::type::makeTessellationInputPatchType( makeType( getTypesCache( writer )
							, std::forward< ParamsT >( params )... )
						, DomainT
						, patchLocation )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	template< typename ... ParamsT >
	ast::type::TypePtr TessPatchInT< DataT, DomainT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		auto result = PatchInT< DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::eTessLevelOuter ) )
		{
			result->declMember( ast::Builtin::eTessLevelOuter
				, type::Kind::eFloat
				, getOuterArraySize( DomainT ) );
			result->declMember( ast::Builtin::eTessLevelInner
				, type::Kind::eFloat
				, getInnerArraySize( DomainT ) );
			result->declMember( ast::Builtin::eTessCoord
				, type::Kind::eVec3F
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalDataOutT< DataT >::TessEvalDataOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< EntryPoint::eTessellationEvaluation, DataT >{ writer, std::move( expr ), enabled }
		, vtx{ *this }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	TessEvalDataOutT< DataT >::TessEvalDataOutT( ShaderWriter & writer
		, ParamsT && ... params )
		: TessEvalDataOutT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "tesseOut"
					, makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TessEvalDataOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = OutputT< EntryPoint::eTessellationEvaluation, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::PatchDomain DomainT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, TessEvalMainFuncT< InT, MaxPointsT, PatchT, DomainT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( TessEvalListInT< InT, MaxPointsT >{ *this, DomainT, partitioning, ordering } )
			, makeInParam( TessPatchInT< PatchT, DomainT >{ *this, patchLocation } )
			, makeOutParam( TessEvalDataOutT< OutT >{ *this } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		this->implementMainT( TessEvalListInT< InT, MaxPointsT >{ *this, ast::type::PatchDomain::eIsolines, partitioning, ordering }
			, IsolinesTessPatchInT< PatchT >{ *this, patchLocation }
			, TessEvalDataOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		this->implementMainT( TessEvalListInT< InT, MaxPointsT >{ *this, ast::type::PatchDomain::eTriangles, partitioning, ordering }
			, TrianglesTessPatchInT< PatchT >{ *this, patchLocation }
			, TessEvalDataOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		this->implementMainT( TessEvalListInT< InT, MaxPointsT >{ *this, ast::type::PatchDomain::eQuads, partitioning, ordering }
			, QuadsTessPatchInT< PatchT >{ *this, patchLocation }
			, TessEvalDataOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( TessEvalListInT< InT, MaxPointsT > listIn
		, IsolinesTessPatchInT< PatchT > patchIn
		, TessEvalDataOutT< OutT > out
		, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( std::move( listIn ) )
			, makeInParam( std::move( patchIn ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( TessEvalListInT< InT, MaxPointsT > listIn
		, TrianglesTessPatchInT< PatchT > patchIn
		, TessEvalDataOutT< OutT > out
		, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( std::move( listIn ) )
			, makeInParam( std::move( patchIn ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( TessEvalListInT< InT, MaxPointsT > listIn
		, QuadsTessPatchInT< PatchT > patchIn
		, TessEvalDataOutT< OutT > out
		, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( std::move( listIn ) )
			, makeInParam( std::move( patchIn ) )
			, makeOutParam( std::move( out ) ) );
	}

	//*************************************************************************
}
