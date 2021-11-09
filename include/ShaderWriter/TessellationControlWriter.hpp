/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TessellationControlWriter_H___
#define ___SDW_TessellationControlWriter_H___

#include "ShaderWriter/Writer.hpp"
namespace sdw
{
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

	struct TessControlPatchRoutineIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API TessControlPatchRoutineIn( ShaderWriter & writer );
		SDW_API TessControlPatchRoutineIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PrimitiveID;
		Int primitiveID;
	};

	struct TessControlMainIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API TessControlMainIn( ShaderWriter & writer );
		SDW_API TessControlMainIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PrimitiveID;
		Int primitiveID;
		//in int gl_InvocationID;
		Int invocationID;
	};

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::PatchDomain DomainT >
	struct TessControlListOutT
		: OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		TessControlListOutT( ShaderWriter & writer
			, ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices );
		TessControlListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

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

		TessPatchOutT( ShaderWriter & writer
			, uint32_t patchLocation );
		TessPatchOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		//patch out float gl_TessLevelOuter[];
		Array< Float > tessLevelOuter;
		//patch out float gl_TessLevelInner[];
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
			, ast::type::PatchDomain DomainT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, TessControlPatchRoutineT< InT, MaxPointsT, PatchT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::PatchDomain DomainT >
		inline void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, TessControlMainFuncT< InT, MaxPointsT, PatchT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, IsolinesTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, TrianglesTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, QuadsTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function );
	};
	/**@}*/
}

#include "TessellationControlWriter.inl"

#endif
