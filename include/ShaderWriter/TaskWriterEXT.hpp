/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskWriterEXT_H___
#define ___SDW_TaskWriterEXT_H___

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
	*	Task.
	*/
	/**@{*/
	/**
	*	Holds input data for a task shader.
	*/
	struct TaskInEXT
		: public StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API TaskInEXT( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );
		SDW_API TaskInEXT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

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
	*	Holds input data for a task subgroup shader.
	*/
	struct TaskSubgroupInEXT
		: private TaskInEXT
	{
		SDW_API TaskSubgroupInEXT( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );
		SDW_API TaskSubgroupInEXT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		using TaskInEXT::updateContainer;
		using TaskInEXT::getContainer;
		using TaskInEXT::updateExpr;
		using TaskInEXT::getType;
		using TaskInEXT::getExpr;
		using TaskInEXT::getWriter;
		using TaskInEXT::getBuilder;
		using TaskInEXT::isEnabled;

		//! in uint  gl_DrawID;
		using TaskInEXT::drawID;
		//! in uvec3 gl_WorkGroupSize;
		using TaskInEXT::workGroupSize;
		//! in uvec3 gl_WorkGroupID / SV_GroupID;
		using TaskInEXT::workGroupID;
		//! in uvec3 gl_LocalInvocationID / SV_GroupThreadID;
		using TaskInEXT::localInvocationID;
		//! in uvec3 gl_GlobalInvocationID / SV_DispatchThreadID;
		using TaskInEXT::globalInvocationID;
		//! in uint  gl_LocalInvocationIndex / SV_GroupIndex;
		using TaskInEXT::localInvocationIndex;

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
	*	Entry point type
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskEXTMainFuncT = std::function< void( TaskInEXT
		, TaskPayloadOutEXTT< PayloadT > ) >;
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskEXTSubgroupMainFuncT = std::function< void( TaskSubgroupInEXT
		, TaskPayloadOutEXTT< PayloadT > ) >;
	using TaskEXTMainFunc = TaskEXTMainFuncT< VoidT >;
	using TaskEXTSubgroupMainFunc = TaskEXTSubgroupMainFuncT< VoidT >;
	/**@}*/

	class TaskWriterEXT
		: public EntryPointWriter
	{
	public:
		SDW_API explicit TaskWriterEXT( ShaderAllocator * allocator = nullptr );
		SDW_API explicit TaskWriterEXT( ShaderBuilder & builder );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void dispatchMesh( UInt numGroupsX
			, UInt numGroupsY
			, UInt numGroupsZ
			, TaskPayloadOutEXTT< PayloadT > const & payload );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadOutEXTT< PayloadT > payload
			, TaskEXTMainFuncT< PayloadT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadOutEXTT< PayloadT > payload
			, TaskEXTSubgroupMainFuncT< PayloadT > const & function );
	};
	/**@}*/
}

#include "TaskWriterEXT.inl"

#endif
