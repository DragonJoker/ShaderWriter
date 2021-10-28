/*
See LICENSE file in root folder
*/
#ifndef ___SDW_FragmentWriter_H___
#define ___SDW_FragmentWriter_H___

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	/**
	*name
	*	Fragment.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct FragmentInT
		: public InputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		FragmentInT( ShaderWriter & writer );
		FragmentInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//in vec4 gl_FragCoord;
		Vec4 const fragCoord;
		//in bool gl_FrontFacing;
		Boolean const frontFacing;
		//in vec2 gl_PointCoord;
		Vec2 const pointCoord;
		//in int gl_SampleID;
		Int const sampleID;
		//in vec2 gl_SamplePosition;
		Vec2 const samplePosition;
		//in int gl_SampleMaskIn[];
		Array< Int > const sampleMask;
		//in float gl_ClipDistance[];
		Array < Float > const clipDistance;
		//in int gl_PrimitiveID;
		Int const primitiveID;
		//in int gl_Layer;
		Int const layer;
		//in int gl_ViewportIndex;
		Int const viewportIndex;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct FragmentOutT
		: public OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		FragmentOutT( ShaderWriter & writer );
		FragmentOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//out float gl_FragDepth;
		Float fragDepth;
		//out int gl_SampleMask[];
		Array< Int > sampleMask;
	};

	using FragmentIn = FragmentInT< VoidT >;
	using FragmentOut = FragmentOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	using FragmentMainFuncT = std::function< void( FragmentInT< InT >, FragmentOutT< OutT > ) >;

	class FragmentWriter
		: public ShaderWriter
	{
	public:
		SDW_API FragmentWriter();
		/**
		*name
		*	I/O layout declaration.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( FragmentMainFuncT< InT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( ast::FragmentOrigin origin
			, ast::FragmentCenter center
			, FragmentMainFuncT< InT, OutT > const & function );
		/**@}*/
		/**
		*name
		*	Blend Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declBlendOutput( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, bool enabled = true );
		template< typename T >
		inline T declBlendOutput( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declBlendOutputArray( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declBlendOutputArray( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t dimension
			, uint32_t attributes
			, bool enabled = true );
		/**@}*/
	};
	/**@}*/
}

#include "FragmentWriter.inl"

#endif
