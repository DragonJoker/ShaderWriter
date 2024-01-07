/*
See LICENSE file in root folder
*/
#ifndef ___SDW_FragmentWriter_H___
#define ___SDW_FragmentWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"

namespace sdw
{
	/**
	*name
	*	Fragment.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct FragmentInT
		: public InputT< EntryPoint::eFragment, DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< EntryPoint::eFragment, DataT >::FlagT;

		template< typename ... ParamsT >
		FragmentInT( ShaderWriter & writer
			, ast::FragmentOrigin origin
			, ast::FragmentCenter center
			, ParamsT && ... params );
		template< typename ... ParamsT >
		explicit FragmentInT( ShaderWriter & writer
			, ParamsT && ... params );
		FragmentInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! in vec4 gl_FragCoord / SV_Position;
		Vec4 const fragCoord;
		//! in bool gl_FrontFacing / SV_IsFrontFace;
		Boolean const frontFacing;
		//! in vec2 gl_PointCoord;
		Vec2 const pointCoord;
		//! in int gl_SampleID / SV_SampleIndex;
		Int32 const sampleID;
		//! in vec2 gl_SamplePosition;
		Vec2 const samplePosition;
		//! in int gl_SampleMaskIn[] / SV_Coverage;
		Array< Int32 > const sampleMask;
		//! in float gl_ClipDistance[] / SV_ClipDistance;
		Array < Float > const clipDistance;
		//! in int gl_PrimitiveID / SV_PrimitiveID;
		Int32 const primitiveID;
		//! in int gl_Layer / SV_RenderTargetArrayIndex;
		Int32 const layer;
		//! in int gl_ViewportIndex / SV_ViewportArrayIndex;
		Int32 const viewportIndex;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct FragmentOutT
		: public OutputT< EntryPoint::eFragment, DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< EntryPoint::eFragment, DataT >::FlagT;

		template< typename ... ParamsT >
		explicit FragmentOutT( ShaderWriter & writer
			, ParamsT && ... params );
		FragmentOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		template< typename ... ParamsT >
		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache
			, ParamsT && ... params );

		//! out float gl_FragDepth / SV_Depth;
		Float fragDepth;
		//! out int gl_SampleMask[] / SV_Coverage;
		Array< Int32 > sampleMask;
	};

	using FragmentIn = FragmentInT< VoidT >;
	using FragmentOut = FragmentOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	using FragmentMainFuncT = std::function< void( FragmentInT< InT >, FragmentOutT< OutT > ) >;

	class FragmentWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit FragmentWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit FragmentWriter( ShaderBuilder & builder );
		/**
		*name
		*	Entry point declaration.
		*/
		/**@{*/
		SDW_API void implementMain( FragmentMainFuncT< VoidT, VoidT > const & function );
		SDW_API void implementMain( ast::FragmentOrigin origin
			, ast::FragmentCenter center
			, FragmentMainFuncT< VoidT, VoidT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( FragmentMainFuncT< InT, OutT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( ast::FragmentOrigin origin
			, ast::FragmentCenter center
			, FragmentMainFuncT< InT, OutT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		void implementMainT( FragmentInT< InT > in
			, FragmentOutT< OutT > out
			, FragmentMainFuncT< InT, OutT > const & function );
		/**@}*/
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
	};
	/**@}*/
}

#include "FragmentWriter.inl"

#endif
