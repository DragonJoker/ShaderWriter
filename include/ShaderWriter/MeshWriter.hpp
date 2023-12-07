/*
See LICENSE file in root folder
*/
#ifndef ___SDW_MeshWriter_H___
#define ___SDW_MeshWriter_H___

#if !defined( SDW_PreferredMeshShadingExtension )
#	error "You must define SDW_PreferredMeshShadingExtension to either SDW_MeshShadingEXT or SDW_MeshShadingNV"
#endif

#if SDW_PreferredMeshShadingExtension == SDW_MeshShadingEXT
#	include "ShaderWriter/MeshWriterEXT.hpp"
#else
#	include "ShaderWriter/MeshWriterNV.hpp"
#endif

namespace sdw
{
#if SDW_PreferredMeshShadingExtension == SDW_MeshShadingEXT
#	define SDW_MeshLocalSize( x, y, z ) x, y, z

	using MeshWriter = MeshWriterEXT;

	using MeshIn = sdw::MeshInEXT;
	using MeshSubgroupIn = sdw::MeshSubgroupInEXT;

	template< template< ast::var::Flag FlagT > typename DataT >
	using PointsMeshPrimitiveListOutT = PointsMeshEXTPrimitiveListOutT< DataT >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LinesMeshPrimitiveListOutT = LinesMeshEXTPrimitiveListOutT< DataT >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesMeshPrimitiveListOutT = TrianglesMeshEXTPrimitiveListOutT< DataT >;

	using PointsMeshPrimitiveListOut = PointsMeshEXTPrimitiveListOut;
	using LinesMeshPrimitiveListOut = LinesMeshEXTPrimitiveListOut;
	using TrianglesMeshPrimitiveListOut = TrianglesMeshEXTPrimitiveListOut;

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshMainFuncT = PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshMainFuncT = LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshMainFuncT = TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshSubgroupMainFuncT = PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshSubgroupMainFuncT = LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshSubgroupMainFuncT = TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT >;
#else
#	define SDW_MeshLocalSize( x, y, z ) x * y * z

	using MeshWriter = sdw::MeshWriterNV;

	using MeshIn = sdw::MeshInNV;
	using MeshSubgroupIn = sdw::MeshSubgroupInNV;

	template< template< ast::var::Flag FlagT > typename DataT >
	using PointsMeshPrimitiveListOutT = PointsMeshNVPrimitiveListOutT< DataT >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LinesMeshPrimitiveListOutT = LinesMeshNVPrimitiveListOutT< DataT >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TrianglesMeshPrimitiveListOutT = TrianglesMeshNVPrimitiveListOutT< DataT >;

	using PointsMeshPrimitiveListOut = PointsMeshNVPrimitiveListOut;
	using LinesMeshPrimitiveListOut = LinesMeshNVPrimitiveListOut;
	using TrianglesMeshPrimitiveListOut = TrianglesMeshNVPrimitiveListOut;

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshMainFuncT = PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshMainFuncT = LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshMainFuncT = TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using PointsMeshSubgroupMainFuncT = PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using LinesMeshSubgroupMainFuncT = LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT >;
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	using TrianglesMeshSubgroupMainFuncT = TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT >;
#endif
}

#endif
