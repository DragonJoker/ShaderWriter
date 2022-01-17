/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayMissWriter_H___
#define ___SDW_RayMissWriter_H___

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"

namespace sdw
{
	/**
	*name
	*	RayMiss.
	*/
	/**@{*/
	/**
	*	Holds input data for a ray miss shader.
	*/
	struct RayMissIn
		: public VoidT< ast::var::Flag::eShaderInput >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API RayMissIn( ShaderWriter & writer );
		SDW_API RayMissIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		// Work dimensions
		//in uvec3 gl_LaunchIDEXT;
		UVec3 launchID;
		//in uvec3 gl_LaunchSizeEXT;
		UVec3 launchSize;

		// World space parameters
		//in vec3 gl_WorldRayOriginEXT;
		Vec3 worldRayOrigin;
		//in vec3 gl_WorldRayDirectionEXT;
		Vec3 worldRayDirection;

		// Ray parameters
		//in float gl_RayTminEXT;
		Float rayTmin;
		//in float gl_RayTmaxEXT;
		Float rayTmax;
		//in uint gl_IncomingRayFlagsEXT;
		UInt incomingRayFlags;
	};

	using RayMissMainFunc = std::function< void( RayMissIn ) >;

	class RayMissWriter
		: public ShaderWriter
	{
	public:
		SDW_API RayMissWriter();

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

		SDW_API void implementMain( RayMissMainFunc const & function );
	};
	/**@}*/
}

#endif
