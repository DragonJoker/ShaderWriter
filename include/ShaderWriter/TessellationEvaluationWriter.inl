/*
See LICENSE file in root folder
*/
#include "TessellationEvaluationWriter.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalDataInT< DataT >::TessEvalDataInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer, *this, FlagT }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalDataInT< DataT >::TessEvalDataInT( ShaderWriter & writer )
		: TessEvalDataInT{ writer
		, makeExpr( writer
			, getShader( writer ).registerName( "tesseIn"
				, makeType( getTypesCache( writer ) )
				, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr TessEvalDataInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		ast::type::IOStructPtr result = InputT< DataT >::makeType( cache );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalListInT< DataT >::TessEvalListInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
		: Array< TessEvalDataInT< DataT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalListInT< DataT >::TessEvalListInT( ShaderWriter & writer
		, uint32_t maxPoints )
		: TessEvalListInT{ writer
		, makeExpr( writer
			, getShader( writer ).registerName( "tesseListIn"
				, ast::type::makeTessellationEvaluationInputType( makeType( getTypesCache( writer ) )
					, maxPoints )
				, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr TessEvalListInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return TessEvalDataInT< DataT >::makeType( cache );
	}
	
	//*************************************************************************
	
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	TessPatchInT< DataT, DomainT >::TessPatchInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PatchInT< DataT >{ writer, std::move( expr ), enabled }
		, tessLevelOuter{ this->getMemberArray< Float >( ast::Builtin::eTessLevelOuter ) }
		, tessLevelInner{ this->getMemberArray< Float >( ast::Builtin::eTessLevelInner ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	TessPatchInT< DataT, DomainT >::TessPatchInT( ShaderWriter & writer
		, uint32_t patchLocation )
		: TessPatchInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tessePatch"
					, ast::type::makeTessellationInputPatchType( makeType( getTypesCache( writer ) )
						, DomainT
						, patchLocation )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	ast::type::TypePtr TessPatchInT< DataT, DomainT >::makeType( ast::type::TypesCache & cache )
	{
		auto result = PatchInT< DataT >::makeType( cache );

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

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalDataOutT< DataT >::TessEvalDataOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer, *this, FlagT }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessEvalDataOutT< DataT >::TessEvalDataOutT( ShaderWriter & writer )
		: TessEvalDataOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesseOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr TessEvalDataOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		ast::type::IOStructPtr result = OutputT< DataT >::makeType( cache );
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
		, TessEvalMainFuncT< InT, MaxPointsT, PatchT, DomainT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( TessEvalListInT< InT >{ *this, MaxPointsT } )
			, makeInParam( TessPatchInT< PatchT, DomainT >{ *this, patchLocation } )
			, makeOutParam( TessEvalDataOutT< OutT >{ *this } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( uint32_t patchLocation
		, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( TessEvalListInT< InT >{ *this, MaxPointsT } )
			, makeInParam( IsolinesTessPatchInT< PatchT >{ *this, patchLocation } )
			, makeOutParam( TessEvalDataOutT< OutT >{ *this } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( uint32_t patchLocation
		, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( TessEvalListInT< InT >{ *this, MaxPointsT } )
			, makeInParam( TrianglesTessPatchInT< PatchT >{ *this, patchLocation } )
			, makeOutParam( TessEvalDataOutT< OutT >{ *this } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationEvaluationWriter::implementMainT( uint32_t patchLocation
		, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( TessEvalListInT< InT >{ *this, MaxPointsT } )
			, makeInParam( QuadsTessPatchInT< PatchT >{ *this, patchLocation } )
			, makeOutParam( TessEvalDataOutT< OutT >{ *this } ) );
	}

	//*************************************************************************
}
