/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TessellationControlWriter_H___
#define ___SDW_TessellationControlWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"
#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

namespace sdw
{
	/**
	*name
	*	Tessellation Control.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessControlDataInT
		: InputT< EntryPoint::eTessellationControl, DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< EntryPoint::eTessellationControl, DataT >::FlagT;

		TessControlDataInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	struct TessControlListInT
		: Array< TessControlDataInT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = TessControlDataInT< DataT >::FlagT;

		template< typename ... ParamsT >
		TessControlListInT( ShaderWriter & writer
			, bool fromEntryPoint
			, ParamsT && ... params );
		TessControlListInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		static constexpr uint32_t MaxPoints = MaxPointsT;
	};

	using TessControlListIn = TessControlListInT< VoidT, 0u >;

	struct TessControlPatchRoutineIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit TessControlPatchRoutineIn( ShaderWriter & writer );
		SDW_API TessControlPatchRoutineIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PrimitiveID / SV_PrimitiveID;
		Int32 primitiveID;
	};

	struct TessControlMainIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit TessControlMainIn( ShaderWriter & writer );
		SDW_API TessControlMainIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PrimitiveID / SV_PrimitiveID;
		Int32 primitiveID;
		//in int gl_InvocationID / SV_OutputControlPointID;
		Int32 invocationID;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	struct TessControlListOutT
		: OutputT< EntryPoint::eTessellationControl, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eTessellationControl, DataT >::FlagT;

		template< typename ... ParamsT >
		TessControlListOutT( ShaderWriter & writer
			, ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, ParamsT && ... params );
		TessControlListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//out gl_PerVertex gl_out[];
		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using IsolinesTessControlListOutT = TessControlListOutT< DataT, ast::type::PatchDomain::eIsolines >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesTessControlListOutT = TessControlListOutT< DataT, ast::type::PatchDomain::eTriangles >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using QuadsTessControlListOutT = TessControlListOutT< DataT, ast::type::PatchDomain::eQuads >;

	using IsolinesTessControlListOut = IsolinesTessControlListOutT< VoidT >;
	using TrianglesTessControlListOut = TrianglesTessControlListOutT< VoidT >;
	using QuadsTessControlListOut = QuadsTessControlListOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	struct TessPatchOutT
		: PatchOutT< DataT >
	{
		static constexpr ast::var::Flag FlagT = PatchOutT< DataT >::FlagT;

		template< typename ... ParamsT >
		TessPatchOutT( ShaderWriter & writer
			, uint32_t patchLocation
			, ParamsT && ... params );
		TessPatchOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! patch out float gl_TessLevelOuter[] /SV_TessFactor;
		Array< Float > tessLevelOuter;
		//! patch out float gl_TessLevelInner[] / SV_InsideTessFactor;
		Array< Float > tessLevelInner;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using IsolinesTessPatchOutT = TessPatchOutT< DataT, ast::type::PatchDomain::eIsolines >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesTessPatchOutT = TessPatchOutT< DataT, ast::type::PatchDomain::eTriangles >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using QuadsTessPatchOutT = TessPatchOutT< DataT, ast::type::PatchDomain::eQuads >;

	using IsolinesTessPatchOut = IsolinesTessPatchOutT< VoidT >;
	using TrianglesTessPatchOut = TrianglesTessPatchOutT< VoidT >;
	using QuadsTessPatchOut = QuadsTessPatchOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::PatchDomain DomainT >
	using TessControlPatchRoutineT = std::function< void( TessControlPatchRoutineIn
		, TessControlListInT< InT, MaxPointsT >
		, TessPatchOutT< PatchT, DomainT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using IsolinesTessControlPatchRoutineT = std::function< void( TessControlPatchRoutineIn
		, TessControlListInT< InT, MaxPointsT >
		, IsolinesTessPatchOutT< PatchT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using TrianglesTessControlPatchRoutineT = std::function< void( TessControlPatchRoutineIn
		, TessControlListInT< InT, MaxPointsT >
		, TrianglesTessPatchOutT< PatchT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using QuadsTessControlPatchRoutineT = std::function< void( TessControlPatchRoutineIn
		, TessControlListInT< InT, MaxPointsT >
		, QuadsTessPatchOutT< PatchT > ) >;

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT
		, ast::type::PatchDomain DomainT >
	using TessControlMainFuncT = std::function< void( TessControlMainIn
		, TessControlListInT< InT, MaxPointsT >
		, TessControlListOutT< OutT, DomainT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using IsolinesTessControlMainFuncT = std::function< void( TessControlMainIn
		, TessControlListInT< InT, MaxPointsT >
		, IsolinesTessControlListOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using TrianglesTessControlMainFuncT = std::function< void( TessControlMainIn
		, TessControlListInT< InT, MaxPointsT >
		, TrianglesTessControlListOutT< OutT > ) >;
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	using QuadsTessControlMainFuncT = std::function< void( TessControlMainIn
		, TessControlListInT< InT, MaxPointsT >
		, QuadsTessControlListOutT< OutT > ) >;

	class TessellationControlWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit TessellationControlWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit TessellationControlWriter( ShaderBuilder & builder );
		/**
		*name
		*	Patch routine declaration.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::PatchDomain DomainT >
		void implementPatchRoutineT( uint32_t patchLocation
			, TessControlPatchRoutineT< InT, MaxPointsT, PatchT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		void implementPatchRoutineT( uint32_t patchLocation
			, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		void implementPatchRoutineT( uint32_t patchLocation
			, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		void implementPatchRoutineT( uint32_t patchLocation
			, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		void implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
			, IsolinesTessPatchOutT< PatchT > out
			, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		void implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
			, TrianglesTessPatchOutT< PatchT > out
			, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		void implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
			, QuadsTessPatchOutT< PatchT > out
			, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
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
		void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, TessControlMainFuncT< InT, MaxPointsT, OutT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( TessControlListInT< InT, MaxPointsT > in
			, IsolinesTessControlListOutT< OutT > out
			, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( TessControlListInT< InT, MaxPointsT > in
			, TrianglesTessControlListOutT< OutT > out
			, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( TessControlListInT< InT, MaxPointsT > in
			, QuadsTessControlListOutT< OutT > out
			, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		/**@}*/

		void barrier()
		{
			sdw::barrier( *this );
		}
	};
	/**@}*/
}

#include "TessellationControlWriter.inl"

#endif
