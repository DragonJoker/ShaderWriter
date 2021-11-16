/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ComputeWriter_H___
#define ___SDW_ComputeWriter_H___

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	/**
	*name
	*	Compute.
	*/
	/**@{*/
	SDW_API UVec3 getWorkGroupSize( ast::type::TypePtr type );

	template< template< ast::var::Flag FlagT > typename DataT >
	struct ComputeInT
		: public InputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		template< typename ... ParamsT >
		ComputeInT( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, ParamsT ... params );
		ComputeInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );

		//in uvec3 gl_NumWorkGroups;
		UVec3 const numWorkGroups;
		//in uvec3 gl_WorkGroupID;
		UVec3 const workGroupID;
		//in uvec3 gl_LocalInvocationID;
		UVec3 const localInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		UVec3 const globalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		UInt const localInvocationIndex;
		//const uvec3 gl_WorkGroupSize;
		UVec3 const workGroupSize;
	};

	using ComputeIn = ComputeInT< VoidT >;

	template< template< ast::var::Flag FlagT > typename DataT >
	using ComputeMainFuncT = std::function< void( ComputeInT< DataT > ) >;

	class ComputeWriter
		: public ShaderWriter
	{
	public:
		SDW_API ComputeWriter();

		SDW_API void implementMain( uint32_t localSizeX
			, ComputeMainFuncT< VoidT > const & function );
		SDW_API void implementMain( uint32_t localSizeX
			, uint32_t localSizeY
			, ComputeMainFuncT< VoidT > const & function );
		SDW_API void implementMain( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, ComputeMainFuncT< VoidT > const & function );

		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( uint32_t localSizeX
			, ComputeMainFuncT< DataT > const & function );
		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, ComputeMainFuncT< DataT > const & function );
		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, ComputeMainFuncT< DataT > const & function );

		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( ComputeInT< DataT > in
			, ComputeMainFuncT< DataT > const & function );
	};
	/**@}*/
}

#include "ComputeWriter.inl"

#endif
