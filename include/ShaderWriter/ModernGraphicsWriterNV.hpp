/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ModernGraphicsWriterNV_H___
#define ___SDW_ModernGraphicsWriterNV_H___

#include "ShaderWriter/FragmentWriter.hpp"
#include "ShaderWriter/MeshWriterNV.hpp"
#include "ShaderWriter/PipelineWriter.hpp"
#include "ShaderWriter/TaskWriterNV.hpp"

namespace sdw
{
	class ModernGraphicsWriterNV
		: public PipelineWriter
	{
	public:
		SDW_API explicit ModernGraphicsWriterNV( ShaderAllocator * allocator = nullptr );
		SDW_API explicit ModernGraphicsWriterNV( ShaderBuilder & builder );
#pragma region Task Shader
		/**
		*name
		*	Task Shader.
		*/
		/**@{*/
#pragma region Entry point declaration
		/**
		*name
		*	Entry point declaration.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadOutNVT< PayloadT > payload
			, TaskNVMainFuncT< PayloadT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadOutNVT< PayloadT > payload
			, TaskNVSubgroupMainFuncT< PayloadT > const & function );
		/**@}*/
#pragma endregion
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void dispatchMesh( UInt numGroups
			, TaskPayloadOutNVT< PayloadT > const & payload );
		/**@}*/
#pragma endregion
#pragma region Mesh Shader
		/**
		*name
		*	Mesh Shader.
		*/
		/**@{*/
#pragma region Points
		/**
		*	Points
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
#pragma endregion
#pragma region Lines
		/**
		*	Lines
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
#pragma endregion
#pragma region Triangles
		/**
		*	Triangles
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		inline void implementEntryPointT( uint32_t localSizeX
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
#pragma endregion
		/**@}*/
#pragma endregion
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
		inline void implementEntryPointT( FragmentMainFuncT< InT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( ast::FragmentOrigin origin
			, ast::FragmentCenter center
			, FragmentMainFuncT< InT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( FragmentInT< InT > in
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
		inline T declBlendOutput( std::string name
			, uint32_t location
			, uint32_t blendIndex
			, bool enabled = true );
		template< typename T >
		inline T declBlendOutput( std::string name
			, uint32_t location
			, uint32_t blendIndex
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declBlendOutputArray( std::string name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declBlendOutputArray( std::string name
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
}

#include "ModernGraphicsWriterNV.inl"

#endif
