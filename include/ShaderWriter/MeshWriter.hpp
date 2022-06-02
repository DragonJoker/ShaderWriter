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
			, uint32_t localSizeX );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//const uvec3 gl_WorkGroupSize;
		UInt const workGroupSize;
		//in uvec3 gl_WorkGroupID;
		UInt const workGroupID;
		//in uvec3 gl_LocalInvocationID;
		UInt const localInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		UInt const globalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		UInt const localInvocationIndex;
		//in uint  gl_MeshViewCountNV;
		UInt const meshViewCount;
		//in uint  gl_MeshViewIndicesNV[];
		Array< UInt > const meshViewIndices;
		//in uint  gl_DrawID;
		Int const drawID;
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
		using Type = UInt;
		static constexpr ast::type::Kind Kind = ast::type::Kind::eUInt;
		using FnType = std::function< Type( StructInstance const &, ast::Builtin ) >;
		SDW_API static FnType const getMember;
	};
	template<>
	struct PrimitiveIndexT< ast::type::OutputTopology::eLine >
	{
		using Type = UVec2;
		static constexpr ast::type::Kind Kind = ast::type::Kind::eVec2U;
		using FnType = std::function< Type( StructInstance const &, ast::Builtin ) >;
		SDW_API static FnType const getMember;
	};
	template<>
	struct PrimitiveIndexT< ast::type::OutputTopology::eTriangle >
	{
		using Type = UVec3;
		static constexpr ast::type::Kind Kind = ast::type::Kind::eVec3U;
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
		Int primitiveID;
		// int gl_Layer;
		Int layer;
		// int gl_ViewportIndex;
		Int viewportIndex;
		// int gl_ViewportMask[];          // NV_viewport_array2
		Array< Int > viewportMask;
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

		void setMeshOutputCounts( UInt const & numVertices
			, UInt const & numPrimitives );

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
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Lines
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
		/**
		*	Triangles
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementMainT( uint32_t localSizeX
			, TaskPayloadInT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
	};
	/**@}*/
}

#include "MeshWriter.inl"

#endif
