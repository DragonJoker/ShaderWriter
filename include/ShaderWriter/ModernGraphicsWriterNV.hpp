/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ModernGraphicsWriterNV_H___
#define ___SDW_ModernGraphicsWriterNV_H___

#include "ShaderWriter/GraphicsPipelineWriter.hpp"
#include "ShaderWriter/MeshWriterNV.hpp"
#include "ShaderWriter/TaskWriterNV.hpp"

namespace sdw
{
	class ModernGraphicsWriterNV
		: public GraphicsPipelineWriter
	{
	public:
		SDW_API explicit ModernGraphicsWriterNV( ShaderAllocator * allocator = nullptr );
		SDW_API explicit ModernGraphicsWriterNV( ShaderBuilder & builder );
		using GraphicsPipelineWriter::implementEntryPoint;
		using GraphicsPipelineWriter::implementEntryPointT;
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
		void implementEntryPointT( uint32_t taskCount
			, TaskPayloadOutNVT< PayloadT > payload
			, TaskNVMainFuncT< PayloadT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementEntryPointT( uint32_t taskCount
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
		void implementEntryPointT( uint32_t numGroups
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
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
		void implementEntryPointT( uint32_t numGroups
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
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
		void implementEntryPointT( uint32_t numGroups
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t numGroups
			, TaskPayloadInNVT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
#pragma endregion
		/**@}*/
#pragma endregion
	};
}

#include "ModernGraphicsWriterNV.inl"

#endif
