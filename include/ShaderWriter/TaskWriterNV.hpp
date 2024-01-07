/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskWriterNV_H___
#define ___SDW_TaskWriterNV_H___

#include "ShaderWriter/TaskWriterEXT.hpp"
#include "ShaderWriter/BaseTypes/TaskPayloadNV.hpp"

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
	struct TaskInNV
		: public StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API TaskInNV( ShaderWriter & writer
			, uint32_t taskCount );
		SDW_API TaskInNV( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

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
	*	Holds input data for a task subgroup shader.
	*/
	struct TaskSubgroupInNV
		: private TaskInNV
	{
		SDW_API TaskSubgroupInNV( ShaderWriter & writer
			, uint32_t taskCount );
		SDW_API TaskSubgroupInNV( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		using TaskInNV::updateContainer;
		using TaskInNV::getContainer;
		using TaskInNV::updateExpr;
		using TaskInNV::getType;
		using TaskInNV::getExpr;
		using TaskInNV::getWriter;
		using TaskInNV::getBuilder;
		using TaskInNV::isEnabled;

		//! in uint  gl_DrawID;
		using TaskInNV::drawID;
		//! in uvec3 gl_WorkGroupSize;
		using TaskInNV::workGroupSize;
		//! in uvec3 gl_WorkGroupID / SV_GroupID;
		using TaskInNV::workGroupID;
		//! in uvec3 gl_LocalInvocationID / SV_GroupThreadID;
		using TaskInNV::localInvocationID;
		//! in uvec3 gl_GlobalInvocationID / SV_DispatchThreadID;
		using TaskInNV::globalInvocationID;
		//! in uint  gl_LocalInvocationIndex / SV_GroupIndex;
		using TaskInNV::localInvocationIndex;

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
	*	Task.
	*/
	/**@{*/
	/**
	*	Entry point type
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskNVMainFuncT = std::function< void( TaskInNV
		, TaskPayloadOutNVT< PayloadT > ) >;
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskNVSubgroupMainFuncT = std::function< void( TaskSubgroupInNV
		, TaskPayloadOutNVT< PayloadT > ) >;
	using TaskNVMainFunc = TaskNVMainFuncT< VoidT >;
	using TaskNVSubgroupMainFunc = TaskNVSubgroupMainFuncT< VoidT >;
	/**@}*/

	class TaskWriterNV
		: public EntryPointWriter
	{
	public:
		SDW_API explicit TaskWriterNV( ShaderAllocator * allocator = nullptr );
		SDW_API explicit TaskWriterNV( ShaderBuilder & builder );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void dispatchMesh( UInt numGroups
			, TaskPayloadOutNVT< PayloadT > const & payload );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t taskCount
			, TaskPayloadOutNVT< PayloadT > payload
			, TaskNVMainFuncT< PayloadT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t taskCount
			, TaskPayloadOutNVT< PayloadT > payload
			, TaskNVSubgroupMainFuncT< PayloadT > const & function );
	};
	/**@}*/
}

#include "TaskWriterNV.inl"

#endif
