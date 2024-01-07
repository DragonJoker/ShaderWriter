/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GeometryWriter_H___
#define ___SDW_GeometryWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"
namespace sdw
{
	/**
	*name
	*	Geometry.
	*/
	/**@{*/
	/**
	*	Holds input data for a geometry shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct GeometryDataT
		: InputT< EntryPoint::eGeometry, DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< EntryPoint::eGeometry, DataT >::FlagT;

		GeometryDataT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		PerVertex vtx;
	};
	/**
	*	Holds global input data for a geometry shader.
	*/
	struct GeometryIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit GeometryIn( ShaderWriter & writer );
		SDW_API GeometryIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//! in int gl_PrimitiveIDIn;
		Int32 const primitiveID;
		//! in int gl_InvocationID / SV_OutputControlPointID;
		Int32 const invocationID;
	};
	/**
	*	Holds vertex input data for a geometry shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	struct GeometryListT
		: Array< GeometryDataT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = GeometryDataT< DataT >::FlagT;

		template< typename ... ParamsT >
		explicit GeometryListT( ShaderWriter & writer
			, ParamsT && ... params );
		GeometryListT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using PointListT = GeometryListT< DataT, ast::type::InputLayout::ePointList >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LineListT = GeometryListT< DataT, ast::type::InputLayout::eLineList >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TriangleListT = GeometryListT< DataT, ast::type::InputLayout::eTriangleList >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LineListWithAdjT = GeometryListT< DataT, ast::type::InputLayout::eLineListWithAdjacency >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TriangleListWithAdjT = GeometryListT< DataT, ast::type::InputLayout::eTriangleListWithAdjacency >;

	using PointList = PointListT< VoidT >;
	using LineList = LineListT< VoidT >;
	using TriangleList = TriangleListT< VoidT >;
	using LineListWithAdj = LineListWithAdjT< VoidT >;
	using TriangleListWithAdj = TriangleListWithAdjT< VoidT >;

	/**
	*	Holds data and functions to append primitives to the stream or restart it.
	*/
	template< template< ast::var::Flag FlagT > typename DataT
		, type::OutputLayout LayoutT >
	struct GeometryOutT
		: public OutputT< EntryPoint::eGeometry, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eGeometry, DataT >::FlagT;

		template< typename ... ParamsT >
		GeometryOutT( ShaderWriter & writer
			, uint32_t count
			, ParamsT && ... params );
		GeometryOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		void append();
		void restartStrip();

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		PerVertex vtx;
		//! out int gl_PrimitiveID / SV_PrimitiveID;
		Int32 primitiveID;
		//! out int gl_Layer / SV_RenderTargetArrayIndex;
		Int32 layer;
		//! out int gl_ViewportIndex / SV_ViewportArrayIndex;
		Int32 viewportIndex;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	using PointStreamT = GeometryOutT< DataT, type::OutputLayout::ePointList >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using LineStreamT = GeometryOutT< DataT, type::OutputLayout::eLineStrip >;
	template< template< ast::var::Flag FlagT > typename DataT >
	using TriangleStreamT = GeometryOutT< DataT, type::OutputLayout::eTriangleStrip >;

	using PointStream = PointStreamT< VoidT >;
	using LineStream = LineStreamT< VoidT >;
	using TriangleStream = TriangleStreamT< VoidT >;

	template< typename InputArrT, typename OutStreamT >
	using GeometryMainFuncT = std::function< void( GeometryIn, InputArrT, OutStreamT ) >;

	class GeometryWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit GeometryWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit GeometryWriter( ShaderBuilder & builder );
		/**
		*name
		*	Entry point declaration.
		*/
		/**@{*/
		template< uint32_t MaxPrimCountT, typename InputArrT, typename OutStreamT >
		void implementMainT( GeometryMainFuncT< InputArrT, OutStreamT > const & function );

		template< typename InputArrT, typename OutStreamT >
		void implementMainT( InputArrT in
			, OutStreamT out
			, GeometryMainFuncT< InputArrT, OutStreamT > const & function );
		/**@}*/
		/**
		*name
		*	Stream Output declaration.
		*/
		/**@{*/
		template< typename T >
		T declStreamOutput( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, bool enabled = true );
		template< typename T >
		T declStreamOutput( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, uint64_t attributes
			, bool enabled = true );
		template< typename T >
		Array< T > declStreamOutputArray( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		Array< T > declStreamOutputArray( std::string name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, uint64_t attributes
			, bool enabled = true );
		/**@}*/
	};
	/**@}*/
}

#include "GeometryWriter.inl"

#endif
