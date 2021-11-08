/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TessellationEvaluationWriter_H___
#define ___SDW_TessellationEvaluationWriter_H___

#include "ShaderWriter/Writer.hpp"
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
		: InputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		TessEvalDataInT( ShaderWriter & writer );
		TessEvalDataInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		// patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessEvalListInT
		: Array< TessEvalDataInT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = TessEvalDataInT< DataT >::FlagT;

		TessEvalListInT( ShaderWriter & writer
			, ast::type::PatchDomain domain
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, uint32_t inputVertices );
		TessEvalListInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );
	};

	struct TessEvalMainIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API TessEvalMainIn( ShaderWriter & writer );
		SDW_API TessEvalMainIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PatchVerticesIn;
		Int patchVerticesIn;
		//in int gl_PrimitiveID;
		Int primitiveID;
		//in vec3 gl_TessCoord;
		Vec3 tessCoord;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	struct TessPatchInT
		: PatchInT< DataT >
	{
		static constexpr ast::var::Flag FlagT = PatchInT< DataT >::FlagT;

		TessPatchInT( ShaderWriter & writer
			, uint32_t patchLocation );
		TessPatchInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		//patch out float gl_TessLevelOuter[];
		Array< Float > tessLevelOuter;
		//patch out float gl_TessLevelInner[];
		Array< Float > tessLevelInner;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using IsolinesTessPatchInT = TessPatchInT< DataT, ast::type::PatchDomain::eIsolines >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesTessPatchInT = TessPatchInT< DataT, ast::type::PatchDomain::eTriangles >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using QuadsTessPatchInT = TessPatchInT< DataT, ast::type::PatchDomain::eQuads >;

	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessEvalDataOutT
		: OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		TessEvalDataOutT( ShaderWriter & writer );
		TessEvalDataOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//out gl_PerVertex;
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::PatchDomain DomainT
		, template< ast::var::Flag FlagT > typename OutT >
	using TessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT >
		, TessPatchInT< PatchT, DomainT >
		, TessEvalDataOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	using IsolinesTessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT >
		, IsolinesTessPatchInT< PatchT >
		, TessEvalDataOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	using TrianglesTessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT >
		, TrianglesTessPatchInT< PatchT >
		, TessEvalDataOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	using QuadsTessEvalMainFuncT = std::function< void( TessEvalMainIn
		, TessEvalListInT< InT >
		, QuadsTessPatchInT< PatchT >
		, TessEvalDataOutT< OutT > ) >;

	class TessellationEvaluationWriter
		: public ShaderWriter
	{
	public:
		SDW_API TessellationEvaluationWriter();
		
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::PatchDomain DomainT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, TessEvalMainFuncT< InT, MaxPointsT, PatchT, DomainT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );

	};
	/**@}*/
}

#include "TessellationEvaluationWriter.inl"

#endif
