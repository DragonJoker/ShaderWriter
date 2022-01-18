/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayCallableWriter_H___
#define ___SDW_RayCallableWriter_H___

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	/**
	*name
	*	RayCallable.
	*/
	/**@{*/
	/**
	*	Holds input data for a callable shader.
	*/
	struct RayCallableIn
		: public VoidT< ast::var::Flag::eShaderInput >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API RayCallableIn( ShaderWriter & writer );
		SDW_API RayCallableIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		// Work dimensions
		//in uvec3 gl_LaunchIDEXT;
		UVec3 launchID;
		//in uvec3 gl_LaunchSizeEXT;
		UVec3 launchSize;
	};

	using RayCallableMainFunc = std::function< void( RayCallableIn ) >;

	class RayCallableWriter
		: public ShaderWriter
	{
	public:
		SDW_API RayCallableWriter();

		SDW_API void implementMain( RayCallableMainFunc const & function );
	};
	/**@}*/
}

#endif
