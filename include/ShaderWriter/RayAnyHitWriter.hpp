/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayAnyHitWriter_H___
#define ___SDW_RayAnyHitWriter_H___

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"

namespace sdw
{
	/**
	*name
	*	RayAnyHit.
	*/
	/**@{*/
	/**
	*	Holds input data for a ray any hit shader.
	*/
	struct RayAnyHitIn
		: public VoidT< ast::var::Flag::eShaderInput >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API RayAnyHitIn( ShaderWriter & writer );
		SDW_API RayAnyHitIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache );

		// Work dimensions
		//in uvec3 gl_LaunchIDEXT;
		UVec3 launchID;
		//in uvec3 gl_LaunchSizeEXT;
		UVec3 launchSize;

		// Geometry instance ids
		//in int gl_PrimitiveID;
		Int primitiveID;
		//in int gl_InstanceID;
		Int instanceID;
		//in int gl_InstanceCustomIndexEXT;
		Int instanceCustomIndex;
		//in int gl_GeometryIndexEXT;
		Int geometryIndex;

		// World space parameters
		//in vec3 gl_WorldRayOriginEXT;
		Vec3 worldRayOrigin;
		//in vec3 gl_WorldRayDirectionEXT;
		Vec3 worldRayDirection;
		//in vec3 gl_ObjectRayOriginEXT;
		Vec3 objectRayOrigin;
		//in vec3 gl_ObjectRayDirectionEXT;
		Vec3 objectRayDirection;

		// Ray parameters
		//in float gl_RayTminEXT;
		Float rayTmin;
		//in float gl_RayTmaxEXT;
		Float rayTmax;
		//in uint gl_IncomingRayFlagsEXT;
		UInt incomingRayFlags;

		// Ray hit info
		//in uint gl_HitKindEXT;
		UInt hitKind;

		// Transform matrices
		//in mat4x3 gl_ObjectToWorldEXT;
		Mat4x3 objectToWorld;
		//in mat4x3 gl_WorldToObjectEXT;
		Mat4x3 worldToObject;

		Float hitT;
	};

	using RayAnyHitMainFunc = std::function< void( RayAnyHitIn ) >;

	class RayAnyHitWriter
		: public ShaderWriter
	{
	public:
		SDW_API RayAnyHitWriter();

		SDW_API void ignoreIntersection();
		SDW_API void terminateRay();

		SDW_API void implementMain( RayAnyHitMainFunc const & function );
	};
	/**@}*/
}

#endif
