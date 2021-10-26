/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TessellationControlWriter_H___
#define ___SDW_TessellationControlWriter_H___

#include "ShaderWriter/Writer.hpp"
namespace sdw
{
	SDW_API uint32_t getOuterArraySize( ast::type::OutputDomain domain );
	SDW_API uint32_t getInnerArraySize( ast::type::OutputDomain domain );
	SDW_API bool hasInnerLevel( ast::type::OutputDomain domain );
	/**
	*name
	*	Tessellation Control.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	struct TessControlInT
		: Array< InputT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		TessControlInT( ShaderWriter & writer
			, bool fromEntryPoint );
		TessControlInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PatchVerticesIn;
		Int patchVerticesIn;
		//in int gl_PrimitiveID;
		Int primitiveID;
		//in int gl_InvocationID;
		Int invocationID;
		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		PerVertex vtx;

		static constexpr uint32_t MaxPoints = MaxPointsT;
	};

	using TessControlIn = TessControlInT< VoidT, 0u >;

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	struct TessControlOutT
		: Array< OutputT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		TessControlOutT( ShaderWriter & writer
			, ast::type::OutputPartitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::OutputVertexOrder vertexOrder
			, uint32_t outputVertices );
		TessControlOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//patch out float gl_TessLevelOuter[];
		Array< Float > tessLevelOuter;
		//patch out float gl_TessLevelInner[];
		Array< Float > tessLevelInner;
		//out gl_PerVertex gl_out[];
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using IsolinesTessControlOutT = TessControlOutT< DataT, ast::type::OutputDomain::eIsolines >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesTessControlOutT = TessControlOutT< DataT, ast::type::OutputDomain::eTriangles >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using QuadsTessControlOutT = TessControlOutT< DataT, ast::type::OutputDomain::eQuads >;

	using IsolinesTessControlOut = IsolinesTessControlOutT< VoidT >;
	using TrianglesTessControlOut = TrianglesTessControlOutT< VoidT >;
	using QuadsTessControlOut = QuadsTessControlOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	struct TessPatchOutT
		: PatchOutT< DataT >
	{
		static constexpr ast::var::Flag FlagT = PatchOutT< DataT >::FlagT;

		TessPatchOutT( ShaderWriter & writer
			, uint32_t patchLocation );
		TessPatchOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using IsolinesTessPatchOutT = TessPatchOutT< DataT, ast::type::OutputDomain::eIsolines >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesTessPatchOutT = TessPatchOutT< DataT, ast::type::OutputDomain::eTriangles >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using QuadsTessPatchOutT = TessPatchOutT< DataT, ast::type::OutputDomain::eQuads >;

	using IsolinesTessPatchOut = IsolinesTessPatchOutT< VoidT >;
	using TrianglesTessPatchOut = TrianglesTessPatchOutT< VoidT >;
	using QuadsTessPatchOut = QuadsTessPatchOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT
		, ast::type::OutputDomain DomainT >
	using TessControlPatchRoutineT = std::function< void( TessControlInT< InT, MaxPointsT >
		, TessPatchOutT< OutT, DomainT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using IsolinesTessControlPatchRoutineT = std::function< void( TessControlInT< InT, MaxPointsT >
		, IsolinesTessControlOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using TrianglesTessControlPatchRoutineT = std::function< void( TessControlInT< InT, MaxPointsT >
		, TrianglesTessControlOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using QuadsTessControlPatchRoutineT = std::function< void( TessControlInT< InT, MaxPointsT >
		, QuadsTessControlOutT< OutT > ) >;

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::OutputDomain DomainT >
	using TessControlMainFuncT = std::function< void( TessControlInT< InT, MaxPointsT >
		, TessPatchOutT< PatchT, DomainT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using IsolinesTessControlMainFuncT = std::function< void( TessControlInT< InT, MaxPointsT >
		, IsolinesTessPatchOutT< PatchT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using TrianglesTessControlMainFuncT = std::function< void( TessControlInT< InT, MaxPointsT >
		, TrianglesTessPatchOutT< PatchT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using QuadsTessControlMainFuncT = std::function< void( TessControlInT< InT, MaxPointsT >
		, QuadsTessPatchOutT< PatchT > ) >;

	class TessellationControlWriter
		: public ShaderWriter
	{
	public:
		struct Config
		{
		};

		SDW_API TessellationControlWriter();

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::OutputDomain DomainT >
		inline void implementPatchRoutineT( ast::type::OutputPartitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::OutputVertexOrder vertexOrder
			, uint32_t outputVertices
			, TessControlPatchRoutineT< InT, MaxPointsT, PatchT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( ast::type::OutputPartitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::OutputVertexOrder vertexOrder
			, uint32_t outputVertices
			, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( ast::type::OutputPartitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::OutputVertexOrder vertexOrder
			, uint32_t outputVertices
			, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( ast::type::OutputPartitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::OutputVertexOrder vertexOrder
			, uint32_t outputVertices
			, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::OutputDomain DomainT >
		inline void implementMainT( uint32_t patchLocation
			, TessControlMainFuncT< InT, MaxPointsT, PatchT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( uint32_t patchLocation
			, IsolinesTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( uint32_t patchLocation
			, TrianglesTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( uint32_t patchLocation
			, QuadsTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function );
	};
	/**@}*/
}

#include "TessellationControlWriter.inl"

#endif
