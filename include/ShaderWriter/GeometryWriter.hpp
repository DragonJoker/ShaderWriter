/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GeometryWriter_H___
#define ___SDW_GeometryWriter_H___

#include "ShaderWriter/Writer.hpp"
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
		: InputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		GeometryDataT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		PerVertex vtx;
	};
	/**
	*	Holds global input data for a geometry shader.
	*/
	struct GeometryIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API GeometryIn( ShaderWriter & writer );
		SDW_API GeometryIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in int gl_PrimitiveIDIn;
		Int const primitiveID;
		//in int gl_InvocationID;
		Int const invocationID;
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

		GeometryListT( ShaderWriter & writer );
		GeometryListT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );
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
		: public OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		GeometryOutT( ShaderWriter & writer
			, uint32_t count );
		GeometryOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		void append();
		void restartStrip();

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		PerVertex vtx;
		//out int gl_PrimitiveID;
		Int primitiveID;
		//out int gl_Layer;
		Int layer;
		//out int gl_ViewportIndex;
		Int viewportIndex;
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
		: public ShaderWriter
	{
	public:
		SDW_API GeometryWriter();
		/**
		*name
		*	I/O layout declaration.
		*/
		/**@{*/
		template< uint32_t MaxPrimCountT, typename InputArrT, typename OutStreamT >
		inline void implementMainT( GeometryMainFuncT< InputArrT, OutStreamT > const & function );
		/**@}*/
		/**
		*name
		*	Stream Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declStreamOutput( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, bool enabled = true );
		template< typename T >
		inline T declStreamOutput( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declStreamOutputArray( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declStreamOutputArray( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, uint32_t attributes
			, bool enabled = true );
		/**@}*/
	};
	/**@}*/
}

#include "GeometryWriter.inl"

#endif
