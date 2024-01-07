/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GraphicsPipelineWriter_H___
#define ___SDW_GraphicsPipelineWriter_H___

#include "ShaderWriter/FragmentWriter.hpp"
#include "ShaderWriter/PipelineWriter.hpp"

namespace sdw
{
	class GraphicsPipelineWriter
		: public PipelineWriter
	{
	public:
		SDW_API explicit GraphicsPipelineWriter( ast::ShaderStage type
			, ShaderAllocator * allocator = nullptr );
		SDW_API explicit GraphicsPipelineWriter( ShaderBuilder & builder );
#pragma region Fragment Shader
		/**
		*name
		*	Fragment Shader.
		*/
		/**@{*/
#pragma region Entry point declaration
		/**
		*name
		*	Entry point declaration.
		*/
		/**@{*/
		SDW_API void implementEntryPoint( FragmentMainFuncT< VoidT, VoidT > const & function );
		SDW_API void implementEntryPoint( ast::FragmentOrigin origin
			, ast::FragmentCenter center
			, FragmentMainFuncT< VoidT, VoidT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementEntryPointT( FragmentMainFuncT< InT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementEntryPointT( ast::FragmentOrigin origin
			, ast::FragmentCenter center
			, FragmentMainFuncT< InT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementEntryPointT( FragmentInT< InT > in
			, FragmentOutT< OutT > out
			, FragmentMainFuncT< InT, OutT > const & function );
		/**@}*/
#pragma endregion
#pragma region Blend Output declaration
		/**
		*name
		*	Blend Output declaration.
		*/
		/**@{*/
		template< typename T >
		T declBlendOutput( std::string name
			, uint32_t location
			, uint32_t blendIndex
			, bool enabled = true );
		template< typename T >
		T declBlendOutput( std::string name
			, uint32_t location
			, uint32_t blendIndex
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		Array< T > declBlendOutputArray( std::string name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		Array< T > declBlendOutputArray( std::string name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled = true );
		/**@}*/
#pragma endregion
		/**@}*/
#pragma endregion
	};
	/**@}*/
}

#include "GraphicsPipelineWriter.inl"

#endif
