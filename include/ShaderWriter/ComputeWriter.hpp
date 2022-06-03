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
	/**
	*name
	*	Compute inputs.
	*/
	/**@{*/
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
	struct SubgroupInT
		: private ComputeInT< DataT >
	{
		using ComputeInT< DataT >::FlagT;

		template< typename ... ParamsT >
		SubgroupInT( ShaderWriter & writer
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, ParamsT ... params );
		SubgroupInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT ... params );

		using ComputeInT< DataT >::updateContainer;
		using ComputeInT< DataT >::getContainer;
		using ComputeInT< DataT >::updateExpr;
		using ComputeInT< DataT >::getType;
		using ComputeInT< DataT >::getExpr;
		using ComputeInT< DataT >::getWriter;
		using ComputeInT< DataT >::getShader;
		using ComputeInT< DataT >::isEnabled;

		//in uvec3 gl_NumWorkGroups;
		using ComputeInT< DataT >::numWorkGroups;
		//in uvec3 gl_WorkGroupID;
		using ComputeInT< DataT >::workGroupID;
		//in uvec3 gl_LocalInvocationID;
		using ComputeInT< DataT >::localInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		using ComputeInT< DataT >::globalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		using ComputeInT< DataT >::localInvocationIndex;
		//const uvec3 gl_WorkGroupSize;
		using ComputeInT< DataT >::workGroupSize;

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

	using SubgroupIn = SubgroupInT< VoidT >;
	/**@}*/

	template< template< ast::var::Flag FlagT > typename DataT >
	using ComputeMainFuncT = std::function< void( ComputeInT< DataT > ) >;

	template< template< ast::var::Flag FlagT > typename DataT >
	using SubgroupMainFuncT = std::function< void( SubgroupInT< DataT > ) >;

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

		SDW_API void implementMain( uint32_t localSizeX
			, SubgroupMainFuncT< VoidT > const & function );
		SDW_API void implementMain( uint32_t localSizeX
			, uint32_t localSizeY
			, SubgroupMainFuncT< VoidT > const & function );
		SDW_API void implementMain( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, SubgroupMainFuncT< VoidT > const & function );

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

		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( uint32_t localSizeX
			, SubgroupMainFuncT< DataT > const & function );
		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, SubgroupMainFuncT< DataT > const & function );
		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, SubgroupMainFuncT< DataT > const & function );

		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( SubgroupInT< DataT > in
			, SubgroupMainFuncT< DataT > const & function );
	};
	/**@}*/
}

#include "ComputeWriter.inl"

#endif
