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
		: public EntryPointWriter
	{
	public:
		SDW_API explicit TaskWriterNV( ShaderAllocator * allocator = nullptr );

		template< template< ast::var::Flag FlagT > typename PayloadT >
		void dispatchMesh( UInt numGroups
			, TaskPayloadOutNVT< PayloadT > const & payload );

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
