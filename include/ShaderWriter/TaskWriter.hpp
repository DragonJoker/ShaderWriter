/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskWriter_H___
#define ___SDW_TaskWriter_H___

#include "ShaderWriterPrerequisites.hpp"

#if !defined( SDW_PreferredMeshShadingExtension )
#	error "You must define SDW_PreferredMeshShadingExtension to either SDW_MeshShadingEXT or SDW_MeshShadingNV"
#endif

#if SDW_PreferredMeshShadingExtension == SDW_MeshShadingEXT
#	include "ShaderWriter/TaskWriterEXT.hpp"
#else
#	include "ShaderWriter/TaskWriterNV.hpp"
#endif

namespace sdw
{
#if SDW_PreferredMeshShadingExtension == SDW_MeshShadingEXT
#	define SDW_TaskLocalSize( x, y, z ) x, y, z
#	define SDW_TaskDispatch( x, y, z ) x, y, z

	using TaskWriter = sdw::TaskWriterEXT;

	template< template< ast::var::Flag FlagT > typename DataT >
	using TaskPayloadOutT = sdw::TaskPayloadOutEXTT< DataT >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TaskPayloadInT = sdw::TaskPayloadInEXTT< DataT >;

	using TaskPayloadOut = TaskPayloadOutEXT;
	using TaskPayloadIn = TaskPayloadInEXT;

	using TaskIn = TaskInEXT;
	using TaskSubgroupIn = TaskSubgroupInEXT;

	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskMainFuncT = TaskEXTMainFuncT< PayloadT >;
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskSubgroupMainFuncT = TaskEXTSubgroupMainFuncT< PayloadT >;

	using TaskMainFunc = TaskEXTMainFunc;
	using TaskSubgroupMainFunc = TaskEXTSubgroupMainFunc;

	template< template< ast::var::Flag FlagT > typename DataT >
	void dispatchMesh( TaskPayloadOutT< DataT > const & payload
		, sdw::UInt const & numTasks )
	{
		payload.dispatchMesh( numTasks, 1_u, 1_u );
	}
#else
#	define SDW_TaskLocalSize( x, y, z ) x * y * z
#	define SDW_TaskDispatch( x, y, z ) x * y * z

	using TaskWriter = sdw::TaskWriterNV;

	template< template< ast::var::Flag FlagT > typename DataT >
	using TaskPayloadOutT = sdw::TaskPayloadOutNVT< DataT >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TaskPayloadInT = sdw::TaskPayloadInNVT< DataT >;

	using TaskPayloadOut = TaskPayloadOutNV;
	using TaskPayloadIn = TaskPayloadInNV;

	using TaskIn = TaskInNV;
	using TaskSubgroupIn = TaskSubgroupInNV;

	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskMainFuncT = TaskNVMainFuncT< PayloadT >;
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskSubgroupMainFuncT = TaskNVSubgroupMainFuncT< PayloadT >;

	using TaskMainFunc = TaskNVMainFunc;
	using TaskSubgroupMainFunc = TaskNVSubgroupMainFunc;

	template< template< ast::var::Flag FlagT > typename DataT >
	void dispatchMesh( TaskPayloadOutT< DataT > const & payload
		, sdw::UInt const & numTasks )
	{
		payload.dispatchMesh( numTasks );
	}

#endif
}

#endif
