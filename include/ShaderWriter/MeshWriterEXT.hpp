/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MeshWriterEXT_H___
#define ___SDW_MeshWriterEXT_H___

#include "ShaderWriter/EntryPointWriter.hpp"
#include "ShaderWriter/BaseTypes/TaskPayloadEXT.hpp"
#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/CompositeTypes/PerPrimitive.hpp"
#include "ShaderWriter/CompositeTypes/PerVertex.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"
#include "ShaderWriter/VecTypes/Vec3.hpp"

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
	struct MeshInEXT
		: public StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API MeshInEXT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		SDW_API MeshInEXT( ShaderWriter & writer
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
		U32Vec3 const workGroupSize;
		//! in uvec3 gl_WorkGroupID / SV_GroupID;
		U32Vec3 const workGroupID;
		//! in uvec3 gl_LocalInvocationID / SV_GroupThreadID;
		U32Vec3 const localInvocationID;
		//! in uvec3 gl_GlobalInvocationID / SV_DispatchThreadID;
		U32Vec3 const globalInvocationID;
		//! in uint  gl_LocalInvocationIndex / SV_GroupIndex;
		UInt32 const localInvocationIndex;
	};
	/**
	*	Holds input data for a mesh subgroup shader.
	*/
	struct MeshSubgroupInEXT
		: private MeshInEXT
	{
		SDW_API MeshSubgroupInEXT( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );
		SDW_API MeshSubgroupInEXT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		using MeshInEXT::updateContainer;
		using MeshInEXT::getContainer;
		using MeshInEXT::updateExpr;
		using MeshInEXT::getType;
		using MeshInEXT::getExpr;
		using MeshInEXT::getWriter;
		using MeshInEXT::getBuilder;
		using MeshInEXT::isEnabled;

		using MeshInEXT::meshViewCount;
		//! in uint  gl_MeshViewIndicesNV[];
		using MeshInEXT::meshViewIndices;
		//! in uint  gl_DrawID;
		using MeshInEXT::drawID;
		//! const uvec3 gl_WorkGroupSize;
		using MeshInEXT::workGroupSize;
		//! in uvec3 gl_WorkGroupID / SV_GroupID;
		using MeshInEXT::workGroupID;
		//! in uvec3 gl_LocalInvocationID / SV_GroupThreadID;
		using MeshInEXT::localInvocationID;
		//! in uvec3 gl_GlobalInvocationID / SV_DispatchThreadID;
		using MeshInEXT::globalInvocationID;
		//! in uint  gl_LocalInvocationIndex / SV_GroupIndex;
		using MeshInEXT::localInvocationIndex;

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
	*	Holds per vertex data
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct MeshVertexOutT
		: public OutputT< EntryPoint::eMesh, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eMesh, DataT >::FlagT;

		MeshVertexOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! vec4  gl_Position / SV_Position;
		Vec4 position;
		//! float gl_PointSize;
		Float pointSize;
		//! float gl_ClipDistance[] / SV_ClipDistance;
		Array< Float > clipDistance;
		//! float gl_CullDistance[] / SV_CullDistance;
		Array< Float > cullDistance;
	};
	/**
	*	Holds list of per vertex data
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct MeshVertexListOutT
		: public Array< MeshVertexOutT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = MeshVertexOutT< DataT >::FlagT;

		template< typename ... ParamsT >
		MeshVertexListOutT( ShaderWriter & writer
			, uint32_t maxVertices
			, ParamsT && ... params );
		MeshVertexListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};

	using MeshVertexListOut = MeshVertexListOutT< VoidT >;

	template< ast::type::OutputTopology TopologyT >
	struct PrimitiveIndexT;
	template<>
	struct PrimitiveIndexT< ast::type::OutputTopology::ePoint >
	{
		using Type = UInt32;
		static constexpr ast::type::Kind Kind = ast::type::Kind::eUInt32;
		static constexpr ast::Builtin Builtin = ast::Builtin::ePrimitivePointIndices;
		using FnType = std::function< Type( StructInstance const &, ast::Builtin ) >;
		SDW_API static FnType const getMember;
	};
	template<>
	struct PrimitiveIndexT< ast::type::OutputTopology::eLine >
	{
		using Type = U32Vec2;
		static constexpr ast::type::Kind Kind = ast::type::Kind::eVec2U32;
		static constexpr ast::Builtin Builtin = ast::Builtin::ePrimitiveLineIndices;
		using FnType = std::function< Type( StructInstance const &, ast::Builtin ) >;
		SDW_API static FnType const getMember;
	};
	template<>
	struct PrimitiveIndexT< ast::type::OutputTopology::eTriangle >
	{
		using Type = U32Vec3;
		static constexpr ast::type::Kind Kind = ast::type::Kind::eVec3U32;
		static constexpr ast::Builtin Builtin = ast::Builtin::ePrimitiveTriangleIndices;
		using FnType = std::function< Type( StructInstance const &, ast::Builtin ) >;
		SDW_API static FnType const getMember;
	};
	template< ast::type::OutputTopology TopologyT >
	using PrimitiveIndexTypeT = typename PrimitiveIndexT< TopologyT >::Type;
	/**
	*	Prevents per primitive and per vertex outputs to be registered using the same base type
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	struct TopologyEXTOutT
		: public OutputT< EntryPoint::eMesh, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eMesh, DataT >::FlagT;

		TopologyEXTOutT( ShaderWriter & writer
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
		, ast::type::OutputTopology TopologyT >//! limited to points, lines or triangles
	struct MeshEXTPrimitiveOutT
		: public TopologyEXTOutT< DataT, TopologyT >
	{
		static constexpr ast::var::Flag FlagT = TopologyEXTOutT< DataT, TopologyT >::FlagT;

		MeshEXTPrimitiveOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! int gl_PrimitiveID / SV_PrimitiveID;
		Int32 primitiveID;
		//! int gl_Layer / SV_RenderTargetArrayIndex;
		Int32 layer;
		//! int gl_ViewportIndex / SV_ViewportArrayIndex;
		Int32 viewportIndex;
		//! int gl_CullPrimitiveEXT;
		Int32 cullPrimitive;
		//! int gl_ViewportMask[];          //! NV_viewport_array2
		Array< Int32 > viewportMask;
	};
	/**
	*	Holds list of per primitive data
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >//! limited to points, lines or triangles
	struct MeshEXTPrimitiveListOutT
		: public Array< MeshEXTPrimitiveOutT< DataT, TopologyT > >
	{
		static constexpr ast::var::Flag FlagT = MeshEXTPrimitiveOutT< DataT, TopologyT >::FlagT;

		template< typename ... ParamsT >
		MeshEXTPrimitiveListOutT( ShaderWriter & writer
			, uint32_t maxPrimitives
			, ParamsT && ... params );
		MeshEXTPrimitiveListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		void setMeshOutputCounts( UInt32 const & numVertices
			, UInt32 const & numPrimitives );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using PointsMeshEXTPrimitiveListOutT = MeshEXTPrimitiveListOutT< DataT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LinesMeshEXTPrimitiveListOutT = MeshEXTPrimitiveListOutT< DataT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesMeshEXTPrimitiveListOutT = MeshEXTPrimitiveListOutT< DataT, ast::type::OutputTopology::eTriangle >;

	using PointsMeshEXTPrimitiveListOut = PointsMeshEXTPrimitiveListOutT< VoidT >;
	using LinesMeshEXTPrimitiveListOut = LinesMeshEXTPrimitiveListOutT< VoidT >;
	using TrianglesMeshEXTPrimitiveListOut = TrianglesMeshEXTPrimitiveListOutT< VoidT >;

	/**
	*	Entry point type
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT
		, ast::type::OutputTopology TopologyT >
	using MeshEXTMainFuncT = std::function< void( MeshInEXT
		, TaskPayloadInEXTT< PayloadT >
		, MeshVertexListOutT< VertexT >
		, MeshEXTPrimitiveListOutT< PrimitiveT, TopologyT > ) >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT
		, ast::type::OutputTopology TopologyT >
	using MeshEXTSubgroupMainFuncT = std::function< void( MeshSubgroupInEXT
		, TaskPayloadInEXTT< PayloadT >
		, MeshVertexListOutT< VertexT >
		, MeshEXTPrimitiveListOutT< PrimitiveT, TopologyT > ) >;

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshEXTMainFuncT = MeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshEXTMainFuncT = MeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshEXTMainFuncT = MeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eTriangle >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshEXTSubgroupMainFuncT = MeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshEXTSubgroupMainFuncT = MeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshEXTSubgroupMainFuncT = MeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eTriangle >;
	/**@}*/

	class MeshWriterEXT
		: public EntryPointWriter
	{
	public:
		SDW_API explicit MeshWriterEXT( ShaderAllocator * allocator = nullptr );
		SDW_API explicit MeshWriterEXT( ShaderBuilder & builder );
		/**
		*	Points
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Lines
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Triangles
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
	};
	/**@}*/
}

#include "MeshWriterEXT.inl"

#endif
