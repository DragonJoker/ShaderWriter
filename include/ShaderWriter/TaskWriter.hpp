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
		//in uint  gl_DrawID;
		Int const drawID;
	};
	/**
	*	Entry point type
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskMainFuncT = std::function< void( TaskIn
		, TaskPayloadOutT< PayloadT > ) >;
	using TaskMainFunc = TaskMainFuncT< VoidT >;
	/**@}*/

	class TaskWriter
		: public ShaderWriter
	{
	public:
		SDW_API TaskWriter();

		SDW_API void implementMain( uint32_t localSizeX
			, TaskMainFunc const & function );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadOutT< PayloadT > payload
			, TaskMainFuncT< PayloadT > const & function );
	};
	/**@}*/
}

#include "TaskWriter.inl"

#endif
