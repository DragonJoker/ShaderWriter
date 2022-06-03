/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskWriter_H___
#define ___SDW_TaskWriter_H___

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
	*	Task.
	*/
	/**@{*/
	/**
	*	Holds input data for a task shader.
	*/
	struct TaskIn
		: public StructInstance
	{
		SDW_API TaskIn( ShaderWriter & writer
			, uint32_t localSizeX );
		SDW_API TaskIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in uint  gl_DrawID;
		Int const drawID;
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
	};
	/**
	*	Holds input data for a task subgroup shader.
	*/
	struct TaskSubgroupIn
		: private TaskIn
	{
		SDW_API TaskSubgroupIn( ShaderWriter & writer
			, uint32_t localSizeX );
		SDW_API TaskSubgroupIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		using TaskIn::updateContainer;
		using TaskIn::getContainer;
		using TaskIn::updateExpr;
		using TaskIn::getType;
		using TaskIn::getExpr;
		using TaskIn::getWriter;
		using TaskIn::getShader;
		using TaskIn::isEnabled;

		//in uint  gl_DrawID;
		using TaskIn::drawID;
		//in uvec3 gl_WorkGroupSize;
		using TaskIn::workGroupSize;
		//in uvec3 gl_WorkGroupID;
		using TaskIn::workGroupID;
		//in uvec3 gl_LocalInvocationID;
		using TaskIn::localInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		using TaskIn::globalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		using TaskIn::localInvocationIndex;

		//in uint gl_NumSubgroups;
		UInt const numSubgroups;
		//in uint gl_SubgroupID;
		UInt const subgroupID;
		//in uint gl_SubgroupSize;
		UInt const subgroupSize;
		//in uint gl_SubgroupInvocationID;
		UInt const subgroupInvocationID;
		//in uvec4 gl_SubgroupEqMask;
		UVec4 const subgroupEqMask;
		//const uvec4 gl_SubgroupGeMask;
		UVec4 const subgroupGeMask;
		//const uvec4 gl_SubgroupGtMask;
		UVec4 const subgroupGtMask;
		//const uvec4 gl_SubgroupLeMask;
		UVec4 const subgroupLeMask;
		//const uvec4 gl_SubgroupLtMask;
		UVec4 const subgroupLtMask;
	};
	/**
	*	Entry point type
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskMainFuncT = std::function< void( TaskIn
		, TaskPayloadOutT< PayloadT > ) >;
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskSubgroupMainFuncT = std::function< void( TaskSubgroupIn
		, TaskPayloadOutT< PayloadT > ) >;
	using TaskMainFunc = TaskMainFuncT< VoidT >;
	using TaskSubgroupMainFunc = TaskSubgroupMainFuncT< VoidT >;
	/**@}*/

	class TaskWriter
		: public ShaderWriter
	{
	public:
		SDW_API TaskWriter();

		SDW_API void implementMain( uint32_t localSizeX
			, TaskMainFunc const & function );
		SDW_API void implementMain( uint32_t localSizeX
			, TaskSubgroupMainFunc const & function );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadOutT< PayloadT > payload
			, TaskMainFuncT< PayloadT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadOutT< PayloadT > payload
			, TaskSubgroupMainFuncT< PayloadT > const & function );
	};
	/**@}*/
}

#include "TaskWriter.inl"

#endif
