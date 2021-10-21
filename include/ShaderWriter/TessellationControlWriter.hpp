/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TessellationControlWriter_H___
#define ___SDW_TessellationControlWriter_H___

#include "ShaderWriter/Writer.hpp"
namespace sdw
{
	/**
	*name
	*	Tessellation Control.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
		struct TessControlInT
		: Array< InputT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		TessControlInT( ShaderWriter & writer
			, bool fromEntryPoint );
		TessControlInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		//in int gl_PatchVerticesIn;
		Int patchVerticesIn;
		//in int gl_PrimitiveID;
		Int primitiveID;
		//in int gl_InvocationID;
		Int invocationID;
		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		Array< PerVertex > vtx;

		static constexpr uint32_t MaxPoints = MaxPointsT;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessControlOutT
		: OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		TessControlOutT( ShaderWriter & writer );
		TessControlOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		//patch out float gl_TessLevelOuter[4];
		Array< Float > tessLevelOuter;
		//patch out float gl_TessLevelInner[2];
		Array< Float > tessLevelInner;
		//out gl_PerVertex gl_out[];
		Array< PerVertex > vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct TessPatchOutT
		: PatchOutT< DataT >
	{
		static constexpr ast::var::Flag FlagT = PatchOutT< DataT >::FlagT;

		TessPatchOutT( ShaderWriter & writer );
		TessPatchOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};

	using TessControlIn = TessControlInT< VoidT, 0u >;
	using TessControlOut = TessControlOutT< VoidT >;

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	using TessControlPatchRoutineT = std::function< void( TessControlInT< InT, MaxPointsT >
		, TessPatchOutT< PatchT > ) >;

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT
		, template< ast::var::Flag FlagT > typename PatchT >
	using TessControlMainFuncT = std::function< void( TessControlInT< InT, MaxPointsT >
		, TessControlOutT< OutT >
		, TessPatchOutT< PatchT > ) >;

	class TessellationControlWriter
		: public ShaderWriter
	{
	public:
		struct Config
		{
		};

		SDW_API TessellationControlWriter();

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( TessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );

		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( uint32_t outputVertices
			, TessControlMainFuncT< InT, MaxPointsT, OutT, PatchT > const & function );
	};
	/**@}*/
}

#include "TessellationControlWriter.inl"

#endif
