/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TaskWriterNV_H___
#define ___SDW_TaskWriterNV_H___

#include "ShaderWriter/TaskWriter.hpp"
#include "ShaderWriter/BaseTypes/TaskPayloadNV.hpp"

namespace sdw
{
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
	using TaskNVMainFuncT = std::function< void( TaskIn
		, TaskPayloadOutNVT< PayloadT > ) >;
	template< template< ast::var::Flag FlagT > typename PayloadT >
	using TaskNVSubgroupMainFuncT = std::function< void( TaskSubgroupIn
		, TaskPayloadOutNVT< PayloadT > ) >;
	using TaskNVMainFunc = TaskNVMainFuncT< VoidT >;
	using TaskNVSubgroupMainFunc = TaskNVSubgroupMainFuncT< VoidT >;
	/**@}*/

	class TaskWriterNV
		: public ShaderWriter
	{
	public:
		SDW_API TaskWriterNV();

		SDW_API void implementMain( uint32_t localSizeX
			, TaskNVMainFunc const & function );
		SDW_API void implementMain( uint32_t localSizeX
			, TaskNVSubgroupMainFunc const & function );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadOutNVT< PayloadT > payload
			, TaskNVMainFuncT< PayloadT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementMainT( uint32_t localSizeX
			, TaskPayloadOutNVT< PayloadT > payload
			, TaskNVSubgroupMainFuncT< PayloadT > const & function );
	};
	/**@}*/
}

#include "TaskWriterNV.inl"

#endif
