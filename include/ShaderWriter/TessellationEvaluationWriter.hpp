/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TessellationEvaluationWriter_H___
#define ___SDW_TessellationEvaluationWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"
namespace sdw
{
	/**@{*/
	/**
	*name
	*	Tessellation evaluation shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessEvalDataInT
		: InputT< EntryPoint::eTessellationEvaluation, DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< EntryPoint::eTessellationEvaluation, DataT >::FlagT;

		TessEvalDataInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t InputVerticesT >
	struct TessEvalListInT
		: Array< TessEvalDataInT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = TessEvalDataInT< DataT >::FlagT;

		template< typename ... ParamsT >
		TessEvalListInT( ShaderWriter & writer
			, ast::type::PatchDomain domain
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, ParamsT && ... params );
		TessEvalListInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};

	struct TessEvalMainIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit TessEvalMainIn( ShaderWriter & writer );
		SDW_API TessEvalMainIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//! in int gl_PatchVerticesIn;
		Int32 patchVerticesIn;
		//! in int gl_PrimitiveID / SV_PrimitiveID;
		Int32 primitiveID;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	struct TessPatchInT
		: PatchInT< DataT >
	{
		static constexpr ast::var::Flag FlagT = PatchInT< DataT >::FlagT;

		template< typename ... ParamsT >
		TessPatchInT( ShaderWriter & writer
			, uint32_t patchLocation
			, ParamsT && ... params );
		TessPatchInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! patch out float gl_TessLevelOuter[];
		Array< Float > tessLevelOuter;
		//! patch out float gl_TessLevelInner[];
		Array< Float > tessLevelInner;
		//! in vec3 gl_TessCoord;
		Vec3 tessCoord;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using IsolinesTessPatchInT = TessPatchInT< DataT, ast::type::PatchDomain::eIsolines >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesTessPatchInT = TessPatchInT< DataT, ast::type::PatchDomain::eTriangles >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using QuadsTessPatchInT = TessPatchInT< DataT, ast::type::PatchDomain::eQuads >;

	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessEvalDataOutT
		: OutputT< EntryPoint::eTessellationEvaluation, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eTessellationEvaluation, DataT >::FlagT;

		template< typename ... ParamsT >
		explicit TessEvalDataOutT( ShaderWriter & writer
			, ParamsT && ... params );
		TessEvalDataOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! out gl_PerVertex;
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::PatchDomain DomainT
		, template< ast::var::Flag FlagT > typename OutT >
	using TessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT, MaxPointsT >
		, TessPatchInT< PatchT, DomainT >
		, TessEvalDataOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	using IsolinesTessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT, MaxPointsT >
		, IsolinesTessPatchInT< PatchT >
		, TessEvalDataOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	using TrianglesTessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT, MaxPointsT >
		, TrianglesTessPatchInT< PatchT >
		, TessEvalDataOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	using QuadsTessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT, MaxPointsT >
		, QuadsTessPatchInT< PatchT >
		, TessEvalDataOutT< OutT > ) >;

	class TessellationEvaluationWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit TessellationEvaluationWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit TessellationEvaluationWriter( ShaderBuilder & builder );
		
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::PatchDomain DomainT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, TessEvalMainFuncT< InT, MaxPointsT, PatchT, DomainT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( TessEvalListInT< InT, MaxPointsT > listIn
			, IsolinesTessPatchInT< PatchT > patchIn
			, TessEvalDataOutT< OutT > out
			, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( TessEvalListInT< InT, MaxPointsT > listIn
			, TrianglesTessPatchInT< PatchT > patchIn
			, TessEvalDataOutT< OutT > out
			, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( TessEvalListInT< InT, MaxPointsT > listIn
			, QuadsTessPatchInT< PatchT > patchIn
			, TessEvalDataOutT< OutT > out
			, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
	};
	/**@}*/
}

#include "TessellationEvaluationWriter.inl"

#endif
