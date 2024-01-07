/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ModernGraphicsWriterEXT_H___
#define ___SDW_ModernGraphicsWriterEXT_H___

#include "ShaderWriter/GraphicsPipelineWriter.hpp"
#include "ShaderWriter/MeshWriterEXT.hpp"
#include "ShaderWriter/TaskWriterEXT.hpp"

namespace sdw
{
	class ModernGraphicsWriterEXT
		: public GraphicsPipelineWriter
	{
	public:
		SDW_API explicit ModernGraphicsWriterEXT( ShaderAllocator * allocator = nullptr );
		SDW_API explicit ModernGraphicsWriterEXT( ShaderBuilder & builder );
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
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadOutEXTT< PayloadT > payload
			, TaskEXTMainFuncT< PayloadT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadOutEXTT< PayloadT > payload
			, TaskEXTSubgroupMainFuncT< PayloadT > const & function );
		/**@}*/
#pragma endregion
		template< template< ast::var::Flag FlagT > typename PayloadT >
		void dispatchMesh( UInt numGroupsX
			, UInt numGroupsY
			, UInt numGroupsZ
			, TaskPayloadOutEXTT< PayloadT > const & payload );
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
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
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
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
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
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, uint32_t maxVertices
			, uint32_t maxPrimitives
			, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		template< template< ast::var::Flag FlagT > typename PayloadT
			, template< ast::var::Flag FlagT > typename VertexT
			, template< ast::var::Flag FlagT > typename PrimitiveT >
		void implementEntryPointT( uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ
			, TaskPayloadInEXTT< PayloadT > payloadIn
			, MeshVertexListOutT< VertexT > verticesOut
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
			, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function );
		/**@}*/
#pragma endregion
		/**@}*/
#pragma endregion
	};
}

#include "ModernGraphicsWriterEXT.inl"

#endif
