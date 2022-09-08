/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MeshWriter_H___
#define ___SDW_MeshWriter_H___

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/BaseTypes/TaskPayload.hpp"
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
	struct MeshIn
		: public StructInstance
	{
		SDW_API MeshIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );
		SDW_API MeshIn( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		UInt32 const meshViewCount;
		//in uint  gl_MeshViewIndicesNV[];
		Array< UInt32 > const meshViewIndices;
		//in uint  gl_DrawID;
		Int32 const drawID;
		//const uvec3 gl_WorkGroupSize;
		UInt32 const workGroupSize;
		//in uvec3 gl_WorkGroupID;
		UInt32 const workGroupID;
		//in uvec3 gl_LocalInvocationID;
		UInt32 const localInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		UInt32 const globalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		UInt32 const localInvocationIndex;
		//in uint  gl_MeshViewCountNV;
	};
	/**
	*	Holds input data for a mesh subgroup shader.
	*/
	struct MeshSubgroupIn
		: private MeshIn
	{
		SDW_API MeshSubgroupIn( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );
		SDW_API MeshSubgroupIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		using MeshIn::updateContainer;
		using MeshIn::getContainer;
		using MeshIn::updateExpr;
		using MeshIn::getType;
		using MeshIn::getExpr;
		using MeshIn::getWriter;
		using MeshIn::getShader;
		using MeshIn::isEnabled;

		using MeshIn::meshViewCount;
		//in uint  gl_MeshViewIndicesNV[];
		using MeshIn::meshViewIndices;
		//in uint  gl_DrawID;
		using MeshIn::drawID;
		//const uvec3 gl_WorkGroupSize;
		using MeshIn::workGroupSize;
		//in uvec3 gl_WorkGroupID;
		using MeshIn::workGroupID;
		//in uvec3 gl_LocalInvocationID;
		using MeshIn::localInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		using MeshIn::globalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		using MeshIn::localInvocationIndex;

		//in uint gl_NumSubgroups;
		UInt32 const numSubgroups;
		//in uint gl_SubgroupID;
		UInt32 const subgroupID;
		//in uint gl_SubgroupSize;
		UInt32 const subgroupSize;
		//in uint gl_SubgroupInvocationID;
		UInt32 const subgroupInvocationID;
		//in uvec4 gl_SubgroupEqMask;
		U32Vec4 const subgroupEqMask;
		//const uvec4 gl_SubgroupGeMask;
		U32Vec4 const subgroupGeMask;
		//const uvec4 gl_SubgroupGtMask;
		U32Vec4 const subgroupGtMask;
		//const uvec4 gl_SubgroupLeMask;
		U32Vec4 const subgroupLeMask;
		//const uvec4 gl_SubgroupLtMask;
		U32Vec4 const subgroupLtMask;
	};
	/**
	*	Holds per vertex data
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct MeshVertexOutT
		: public OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		MeshVertexOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );

		// vec4  gl_Position;
		Vec4 position;
		// float gl_PointSize;
		Float pointSize;
		// float gl_ClipDistance[];
		Array< Float > clipDistance;
		// float gl_CullDistance[];
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
			, ParamsT ... params );
		MeshVertexListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );
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
	struct TopologyOutT
		: public OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		TopologyOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );

		//in uint  gl_PrimitiveIndicesNV[];
		PrimitiveIndexTypeT< TopologyT > primitiveIndex;
	};
	/**
	*	Holds per primitive data
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >// limited to points, lines or triangles
	struct MeshPrimitiveOutT
		: public TopologyOutT< DataT, TopologyT >
	{
		static constexpr ast::var::Flag FlagT = TopologyOutT< DataT, TopologyT >::FlagT;

		MeshPrimitiveOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );

		// int gl_PrimitiveID;
		Int32 primitiveID;
		// int gl_Layer;
		Int32 layer;
		// int gl_ViewportIndex;
		Int32 viewportIndex;
		// int gl_CullPrimitiveEXT;
		Int32 cullPrimitive;
		// int gl_ViewportMask[];          // NV_viewport_array2
		Array< Int32 > viewportMask;
	};
	/**
	*	Holds list of per primitive data
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >// limited to points, lines or triangles
	struct MeshPrimitiveListOutT
		: public Array< MeshPrimitiveOutT< DataT, TopologyT > >
	{
		static constexpr ast::var::Flag FlagT = MeshPrimitiveOutT< DataT, TopologyT >::FlagT;

		template< typename ... ParamsT >
		MeshPrimitiveListOutT( ShaderWriter & writer
			, uint32_t maxPrimitives
			, ParamsT ... params );
		MeshPrimitiveListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		void setMeshOutputCounts( UInt32 const & numVertices
			, UInt32 const & numPrimitives );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using PointsMeshPrimitiveListOutT = MeshPrimitiveListOutT< DataT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LinesMeshPrimitiveListOutT = MeshPrimitiveListOutT< DataT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesMeshPrimitiveListOutT = MeshPrimitiveListOutT< DataT, ast::type::OutputTopology::eTriangle >;

	using PointsMeshPrimitiveListOut = PointsMeshPrimitiveListOutT< VoidT >;
	using LinesMeshPrimitiveListOut = LinesMeshPrimitiveListOutT< VoidT >;
	using TrianglesMeshPrimitiveListOut = TrianglesMeshPrimitiveListOutT< VoidT >;

	/**
	*	Entry point type
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT
		, ast::type::OutputTopology TopologyT >
	using MeshMainFuncT = std::function< void( MeshIn
		, TaskPayloadInT< PayloadT >
		, MeshVertexListOutT< VertexT >
		, MeshPrimitiveListOutT< PrimitiveT, TopologyT > ) >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT
		, ast::type::OutputTopology TopologyT >
	using MeshSubgroupMainFuncT = std::function< void( MeshSubgroupIn
		, TaskPayloadInT< PayloadT >
		, MeshVertexListOutT< VertexT >
		, MeshPrimitiveListOutT< PrimitiveT, TopologyT > ) >;

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshMainFuncT = MeshMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshMainFuncT = MeshMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshMainFuncT = MeshMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eTriangle >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshSubgroupMainFuncT = MeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::ePoint >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshSubgroupMainFuncT = MeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eLine >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshSubgroupMainFuncT = MeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT, ast::type::OutputTopology::eTriangle >;
	/**@}*/

	class MeshWriter
		: public ShaderWriter
	{
	public:
		SDW_API MeshWriter();
		/**
		*	Points
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Lines
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Triangles
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
	};
	/**@}*/
}

#include "MeshWriter.inl"

#endif
