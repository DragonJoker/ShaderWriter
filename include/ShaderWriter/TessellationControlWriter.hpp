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
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessControlDataInT
		: InputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		TessControlDataInT( ShaderWriter & writer );
		TessControlDataInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	struct TessControlListInT
		: Array< TessControlDataInT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = TessControlDataInT< DataT >::FlagT;

		TessControlListInT( ShaderWriter & writer
			, bool fromEntryPoint );
		TessControlListInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		static constexpr uint32_t MaxPoints = MaxPointsT;
	};

	using TessControlListIn = TessControlListInT< VoidT, 0u >;

	struct TessControlIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API TessControlIn( ShaderWriter & writer );
		SDW_API TessControlIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PatchVerticesIn;
		Int patchVerticesIn;
		//in int gl_PrimitiveID;
		Int primitiveID;
		//in int gl_InvocationID;
		Int invocationID;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessControlDataOutT
		: OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		TessControlDataOutT( ShaderWriter & writer );
		TessControlDataOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//out gl_PerVertex gl_out[];
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	struct TessControlListOutT
		: Array< TessControlDataOutT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = TessControlDataOutT< DataT >::FlagT;

		TessControlListOutT( ShaderWriter & writer
			, ast::type::OutputPartitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::OutputVertexOrder vertexOrder
			, uint32_t outputVertices );
		TessControlListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using IsolinesTessControlListOutT = TessControlListOutT< DataT, ast::type::OutputDomain::eIsolines >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesTessControlListOutT = TessControlListOutT< DataT, ast::type::OutputDomain::eTriangles >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using QuadsTessControlListOutT = TessControlListOutT< DataT, ast::type::OutputDomain::eQuads >;

	using IsolinesTessControlListOut = IsolinesTessControlListOutT< VoidT >;
	using TrianglesTessControlListOut = TrianglesTessControlListOutT< VoidT >;
	using QuadsTessControlListOut = QuadsTessControlListOutT< VoidT >;

	template< ast::type::OutputDomain DomainT >
	struct TessControlOutT
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderOutput;

		TessControlOutT( ShaderWriter & writer );
		TessControlOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//patch out float gl_TessLevelOuter[];
		Array< Float > tessLevelOuter;
		//patch out float gl_TessLevelInner[];
		Array< Float > tessLevelInner;
	};

	using IsolinesTessControlOut = TessControlOutT< ast::type::OutputDomain::eIsolines >;
	using TrianglesTessControlOut = TessControlOutT< ast::type::OutputDomain::eTriangles >;
	using QuadsTessControlOut = TessControlOutT< ast::type::OutputDomain::eQuads >;

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
	using TessControlPatchRoutineT = std::function< void( TessControlIn
		, TessControlListInT< InT, MaxPointsT >
		, TessControlOutT< DomainT >
		, TessControlListOutT< OutT, DomainT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using IsolinesTessControlPatchRoutineT = std::function< void( TessControlIn
		, TessControlListInT< InT, MaxPointsT >
		, IsolinesTessControlOut
		, IsolinesTessControlListOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using TrianglesTessControlPatchRoutineT = std::function< void( TessControlIn
		, TessControlListInT< InT, MaxPointsT >
		, TrianglesTessControlOut
		, TrianglesTessControlListOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using QuadsTessControlPatchRoutineT = std::function< void( TessControlIn
		, TessControlListInT< InT, MaxPointsT >
		, QuadsTessControlOut
		, QuadsTessControlListOutT< OutT > ) >;

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::OutputDomain DomainT >
	using TessControlMainFuncT = std::function< void( TessControlListInT< InT, MaxPointsT >
		, TessPatchOutT< PatchT, DomainT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using IsolinesTessControlMainFuncT = std::function< void( TessControlListInT< InT, MaxPointsT >
		, IsolinesTessPatchOutT< PatchT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using TrianglesTessControlMainFuncT = std::function< void( TessControlListInT< InT, MaxPointsT >
		, TrianglesTessPatchOutT< PatchT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using QuadsTessControlMainFuncT = std::function< void( TessControlListInT< InT, MaxPointsT >
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
