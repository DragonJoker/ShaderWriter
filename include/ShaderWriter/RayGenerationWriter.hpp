/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayGenerationWriter_H___
#define ___SDW_RayGenerationWriter_H___

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	/**
	*name
	*	RayGeneration.
	*/
	/**@{*/
	/**
	*	Holds input data for a ray generation shader.
	*/
	struct RayGenerationIn
		: public VoidT< ast::var::Flag::eShaderInput >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API RayGenerationIn( ShaderWriter & writer );
		SDW_API RayGenerationIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		//in uvec3 gl_LaunchIDEXT;
		UVec3 const launchID;
		//in uvec3 gl_LaunchSizeEXT;
		UVec3 const launchSize;
	};

	using RayGenerationMainFunc = std::function< void( RayGenerationIn ) >;

	class RayGenerationWriter
		: public ShaderWriter
	{
	public:
		SDW_API RayGenerationWriter();

		SDW_API void traceRay( AccelerationStructure const & topLevel
			, UInt const & rayFlags
			, UInt const & cullMask
			, UInt const & sbtRecordOffset
			, UInt const & sbtRecordStride
			, UInt const & missIndex
			, Vec3 const & origin
			, Float const & Tmin
			, Vec3 const & direction
			, Float const & Tmax
			, Int const & payload );

		SDW_API void implementMain( RayGenerationMainFunc const & function );
	};
	/**@}*/
}

#endif
