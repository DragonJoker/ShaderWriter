/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayIntersectionWriter_H___
#define ___SDW_RayIntersectionWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"

namespace sdw
{
	/**
	*name
	*	RayIntersection.
	*/
	/**@{*/
	/**
	*	Holds input data for a ray intersection shader.
	*/
	struct RayIntersectionIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit RayIntersectionIn( ShaderWriter & writer );
		SDW_API RayIntersectionIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		// Work dimensions
		// in uvec3 gl_LaunchIDEXT;
		U32Vec3 launchID;
		// in uvec3 gl_LaunchSizeEXT;
		U32Vec3 launchSize;

		// Geometry instance ids
		// in int gl_PrimitiveID;
		Int32 primitiveID;
		// in int gl_InstanceID;
		Int32 instanceID;
		// in int gl_InstanceCustomIndexEXT;
		Int32 instanceCustomIndex;
		// in int gl_GeometryIndexEXT;
		Int32 geometryIndex;

		// World space parameters
		// in vec3 gl_WorldRayOriginEXT;
		Vec3 worldRayOrigin;
		// in vec3 gl_WorldRayDirectionEXT;
		Vec3 worldRayDirection;
		// in vec3 gl_ObjectRayOriginEXT;
		Vec3 objectRayOrigin;
		// in vec3 gl_ObjectRayDirectionEXT;
		Vec3 objectRayDirection;

		// Ray parameters
		// in float gl_RayTminEXT;
		Float rayTmin;
		// in volatile float gl_RayTmaxEXT;
		Float rayTmax;
		// in uint gl_IncomingRayFlagsEXT;
		UInt32 incomingRayFlags;

		// Transform matrices
		// in mat4x3 gl_ObjectToWorldEXT;
		Mat4x3 objectToWorld;
		// in mat4x3 gl_WorldToObjectEXT;
		Mat4x3 worldToObject;

		Float hitT;
	};

	using RayIntersectionMainFunc = std::function< void( RayIntersectionIn ) >;

	class RayIntersectionWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit RayIntersectionWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit RayIntersectionWriter( ShaderBuilder & builder );

		SDW_API void implementMain( RayIntersectionMainFunc const & function );
	};
	/**@}*/
}

#endif
