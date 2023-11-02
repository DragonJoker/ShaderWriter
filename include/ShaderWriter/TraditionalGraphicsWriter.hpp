/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TraditionalGraphicsWriter_H___
#define ___SDW_TraditionalGraphicsWriter_H___

#include "ShaderWriter/FragmentWriter.hpp"
#include "ShaderWriter/GeometryWriter.hpp"
#include "ShaderWriter/PipelineWriter.hpp"
#include "ShaderWriter/TessellationControlWriter.hpp"
#include "ShaderWriter/TessellationEvaluationWriter.hpp"
#include "ShaderWriter/VertexWriter.hpp"

namespace sdw
{
	class TraditionalGraphicsWriter
		: public PipelineWriter
	{
	public:
		SDW_API explicit TraditionalGraphicsWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit TraditionalGraphicsWriter( ShaderBuilder & builder );
#pragma region Vertex Shader
		/**
		*name
		*	Vertex Shader.
		*/
		/**@{*/
		SDW_API void implementEntryPoint( VertexMainFuncT< VoidT, VoidT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( VertexMainFuncT< InT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( VertexInT< InT > in
			, VertexOutT< OutT > out
			, VertexMainFuncT< InT, OutT > const & function );
		/**@}*/
#pragma endregion
#pragma region Geometry Shader
		/**
		*name
		*	Geometry Shader.
		*/
		/**@{*/
#pragma region Entry point declaration
		/**
		*name
		*	Entry point declaration.
		*/
		/**@{*/
		template< uint32_t MaxPrimCountT, typename InputArrT, typename OutStreamT >
		inline void implementEntryPointT( GeometryMainFuncT< InputArrT, OutStreamT > const & function );

		template< typename InputArrT, typename OutStreamT >
		inline void implementEntryPointT( InputArrT in
			, OutStreamT out
			, GeometryMainFuncT< InputArrT, OutStreamT > const & function );
		/**@}*/
#pragma endregion
#pragma region Stream Output declaration
		/**
		*name
		*	Stream Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declStreamOutput( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, bool enabled = true );
		template< typename T >
		inline T declStreamOutput( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declStreamOutputArray( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declStreamOutputArray( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled = true );
		/**@}*/
#pragma endregion
		/**@}*/
#pragma endregion
#pragma region Tessellation Control Shader
		/**
		*name
		*	Tessellation Control Shader.
		*/
		/**@{*/
#pragma region Patch routine declaration
		/**
		*name
		*	Patch routine declaration.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::PatchDomain DomainT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, TessControlPatchRoutineT< InT, MaxPointsT, PatchT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( uint32_t patchLocation
			, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
			, IsolinesTessPatchOutT< PatchT > out
			, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
			, TrianglesTessPatchOutT< PatchT > out
			, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
			, QuadsTessPatchOutT< PatchT > out
			, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		/**@}*/
#pragma endregion
#pragma region Entry point declaration
		/**
		*name
		*	Entry point declaration.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT
			, ast::type::PatchDomain DomainT >
		inline void implementEntryPointT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, TessControlMainFuncT< InT, MaxPointsT, OutT, DomainT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( ast::type::Partitioning partitioning
			, ast::type::OutputTopology topology
			, ast::type::PrimitiveOrdering vertexOrder
			, uint32_t outputVertices
			, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( TessControlListInT< InT, MaxPointsT > in
			, IsolinesTessControlListOutT< OutT > out
			, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( TessControlListInT< InT, MaxPointsT > in
			, TrianglesTessControlListOutT< OutT > out
			, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( TessControlListInT< InT, MaxPointsT > in
			, QuadsTessControlListOutT< OutT > out
			, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function );
		/**@}*/
#pragma endregion
		void barrier()
		{
			sdw::barrier( *this );
		}
		/**@}*/
#pragma endregion
#pragma region Tessellation Evaluation Shader
		/**
		*name
		*	Tessellation Evaluation Shader.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, ast::type::PatchDomain DomainT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, TessEvalMainFuncT< InT, MaxPointsT, PatchT, DomainT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( uint32_t patchLocation
			, ast::type::Partitioning partitioning
			, ast::type::PrimitiveOrdering ordering
			, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( TessEvalListInT< InT, MaxPointsT > listIn
			, IsolinesTessPatchInT< PatchT > patchIn
			, TessEvalDataOutT< OutT > out
			, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( TessEvalListInT< InT, MaxPointsT > listIn
			, TrianglesTessPatchInT< PatchT > patchIn
			, TessEvalDataOutT< OutT > out
			, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementEntryPointT( TessEvalListInT< InT, MaxPointsT > listIn
			, QuadsTessPatchInT< PatchT > patchIn
			, TessEvalDataOutT< OutT > out
			, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function );
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
	/**@}*/
}

#include "TraditionalGraphicsWriter.inl"

#endif
