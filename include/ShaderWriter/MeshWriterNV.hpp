/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MeshWriterNV_H___
#define ___SDW_MeshWriterNV_H___

#include "ShaderWriter/MeshWriterEXT.hpp"
#include "ShaderWriter/BaseTypes/TaskPayloadNV.hpp"

namespace sdw
{
	/**
	*name
	*	Mesh.
	*/
	/**@{*/
	/**
	*	Holds input intrinsics for a mesh shader.
	*/
	struct MeshInNV
		: public StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API MeshInNV( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		SDW_API MeshInNV( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//! in uint  gl_MeshViewCountNV;
		UInt32 const meshViewCount;
		//! in uint  gl_MeshViewIndicesNV[];
		Array< UInt32 > const meshViewIndices;
		//! in uint  gl_DrawID;
		UInt32 const drawID;
		//! const uvec3 gl_WorkGroupSize;
		UInt32 const workGroupSize;
		//! in uvec3 gl_WorkGroupID / SV_GroupID;
		UInt32 const workGroupID;
		//! in uvec3 gl_LocalInvocationID / SV_GroupThreadID;
		UInt32 const localInvocationID;
		//! in uvec3 gl_GlobalInvocationID / SV_DispatchThreadID;
		UInt32 const globalInvocationID;
		//! in uint  gl_LocalInvocationIndex / SV_GroupIndex;
		UInt32 const localInvocationIndex;
	};
	/**
	*	Holds input data for a mesh subgroup shader.
	*/
	struct MeshSubgroupInNV
		: private MeshInNV
	{
		SDW_API MeshSubgroupInNV( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );
		SDW_API MeshSubgroupInNV( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		using MeshInNV::updateContainer;
		using MeshInNV::getContainer;
		using MeshInNV::updateExpr;
		using MeshInNV::getType;
		using MeshInNV::getExpr;
		using MeshInNV::getWriter;
		using MeshInNV::getBuilder;
		using MeshInNV::isEnabled;

		using MeshInNV::meshViewCount;
		//! in uint  gl_MeshViewIndicesNV[];
		using MeshInNV::meshViewIndices;
		//! in uint  gl_DrawID;
		using MeshInNV::drawID;
		//! const uvec3 gl_WorkGroupSize;
		using MeshInNV::workGroupSize;
		//! in uvec3 gl_WorkGroupID / SV_GroupID;
		using MeshInNV::workGroupID;
		//! in uvec3 gl_LocalInvocationID / SV_GroupThreadID;
		using MeshInNV::localInvocationID;
		//! in uvec3 gl_GlobalInvocationID / SV_DispatchThreadID;
		using MeshInNV::globalInvocationID;
		//! in uint  gl_LocalInvocationIndex / SV_GroupIndex;
		using MeshInNV::localInvocationIndex;

		//! in uint gl_NumSubgroups;
		UInt32 const numSubgroups;
		//! in uint gl_SubgroupID;
		UInt32 const subgroupID;
		//! in uint gl_SubgroupSize;
		UInt32 const subgroupSize;
		//! in uint gl_SubgroupInvocationID;
		UInt32 const subgroupInvocationID;
		//! in uvec4 gl_SubgroupEqMask;
		U32Vec4 const subgroupEqMask;
		//! const uvec4 gl_SubgroupGeMask;
		U32Vec4 const subgroupGeMask;
		//! const uvec4 gl_SubgroupGtMask;
		U32Vec4 const subgroupGtMask;
		//! const uvec4 gl_SubgroupLeMask;
		U32Vec4 const subgroupLeMask;
		//! const uvec4 gl_SubgroupLtMask;
		U32Vec4 const subgroupLtMask;
	};
	/**
	*name
	*	Mesh.
	*/
	/**@{*/
	/**
	*	Prevents per primitive and per vertex outputs to be registered using the same base type
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	struct TopologyNVOutT
		: public OutputT< EntryPoint::eMeshNV, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eMeshNV, DataT >::FlagT;

		TopologyNVOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! in uint  gl_PrimitiveIndicesNV[];
		PrimitiveIndexTypeT< TopologyT > primitiveIndex;
	};
	/**
	*	Holds per primitive data
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >//!  limited to points, lines or triangles
	struct MeshNVPrimitiveOutT
		: public TopologyNVOutT< DataT, TopologyT >
	{
		static constexpr ast::var::Flag FlagT = TopologyNVOutT< DataT, TopologyT >::FlagT;

		MeshNVPrimitiveOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//!  int gl_PrimitiveID / SV_PrimitiveID;
		Int32 primitiveID;
		//!  int gl_Layer / SV_RenderTargetArrayIndex;
		Int32 layer;
		//!  int gl_ViewportIndex / SV_ViewportArrayIndex;
		Int32 viewportIndex;
		//!  int gl_ViewportMask[];          //!  NV_viewport_array2
		Array< Int32 > viewportMask;
	};
	/**
	*	Holds list of per primitive data
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >//!  limited to points, lines or triangles
	struct MeshNVPrimitiveListOutT
		: public Array< MeshNVPrimitiveOutT< DataT, TopologyT > >
	{
		static constexpr ast::var::Flag FlagT = MeshNVPrimitiveOutT< DataT, TopologyT >::FlagT;

		template< typename ... ParamsT >
		MeshNVPrimitiveListOutT( ShaderWriter & writer
			, uint32_t maxPrimitives
			, ParamsT && ... params );
		MeshNVPrimitiveListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		void setMeshOutputCounts( UInt32 const & numVertices
			, UInt32 const & numPrimitives );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using PointsMeshNVPrimitiveListOutT = MeshNVPrimitiveListOutT< DataT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LinesMeshNVPrimitiveListOutT = MeshNVPrimitiveListOutT< DataT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesMeshNVPrimitiveListOutT = MeshNVPrimitiveListOutT< DataT, ast::type::OutputTopology::eTriangle >;

	using PointsMeshNVPrimitiveListOut = PointsMeshNVPrimitiveListOutT< VoidT >;
	using LinesMeshNVPrimitiveListOut = LinesMeshNVPrimitiveListOutT< VoidT >;
	using TrianglesMeshNVPrimitiveListOut = TrianglesMeshNVPrimitiveListOutT< VoidT >;
	/**
	*	Entry point type
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT
		, ast::type::OutputTopology TopologyT >
	using MeshNVMainFuncT = std::function< void( MeshInNV
		, TaskPayloadInNVT< PayloadT >
		, MeshVertexListOutT< VertexT >
		, MeshNVPrimitiveListOutT< PrimitiveT, TopologyT > ) >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT
		, ast::type::OutputTopology TopologyT >
	using MeshNVSubgroupMainFuncT = std::function< void( MeshSubgroupInNV
		, TaskPayloadInNVT< PayloadT >
		, MeshVertexListOutT< VertexT >
		, MeshNVPrimitiveListOutT< PrimitiveT, TopologyT > ) >;

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshNVMainFuncT = MeshNVMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshNVMainFuncT = MeshNVMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshNVMainFuncT = MeshNVMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eTriangle >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshNVSubgroupMainFuncT = MeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshNVSubgroupMainFuncT = MeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshNVSubgroupMainFuncT = MeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eTriangle >;
	/**@}*/

	class MeshWriterNV
		: public EntryPointWriter
	{
	public:
		SDW_API explicit MeshWriterNV( ShaderAllocator * allocator = nullptr );
		SDW_API explicit MeshWriterNV( ShaderBuilder & builder );
		/**
		*	Points
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Lines
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Triangles
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
	};
	/**@}*/
}

#include "MeshWriterNV.inl"

#endif
