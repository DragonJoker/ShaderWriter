/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayClosestHitWriter_H___
#define ___SDW_RayClosestHitWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"
#include "ShaderWriter/BaseTypes/HitAttribute.hpp"
#include "ShaderWriter/BaseTypes/RayPayload.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"

namespace sdw
{
	/**
	*name
	*	RayClosestHit.
	*/
	/**@{*/
	/**
	*	Holds input data for a ray closest hit shader.
	*/
	struct RayClosestHitIn
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit RayClosestHitIn( ShaderWriter & writer );
		SDW_API RayClosestHitIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		// Work dimensions
		//in uvec3 gl_LaunchIDEXT;
		U32Vec3 launchID;
		//in uvec3 gl_LaunchSizeEXT;
		U32Vec3 launchSize;

		// Geometry instance ids
		//in int gl_PrimitiveID;
		Int32 primitiveID;
		//in int gl_InstanceID;
		Int32 instanceID;
		//in int gl_InstanceCustomIndexEXT;
		Int32 instanceCustomIndex;
		//in int gl_GeometryIndexEXT;
		Int32 geometryIndex;

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
		UInt32 incomingRayFlags;

		// Ray hit info
		//in uint gl_HitKindEXT;
		UInt32 hitKind;

		// Transform matrices
		//in mat4x3 gl_ObjectToWorldEXT;
		Mat4x3 objectToWorld;
		//in mat4x3 gl_WorldToObjectEXT;
		Mat4x3 worldToObject;

		Float hitT;
	};

	template< typename PayloadT, typename AttrT >
	using RayClosestHitMainFuncT = std::function< void( RayClosestHitIn, RayPayloadInT< PayloadT >, HitAttributeT< AttrT > ) >;

	class RayClosestHitWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit RayClosestHitWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit RayClosestHitWriter( ShaderBuilder & builder );

		template< typename PayloadT, typename AttrT >
		void implementMainT( uint32_t payloadLocation
			, RayClosestHitMainFuncT< PayloadT, AttrT > const & function );
		template< typename PayloadT, typename AttrT >
		void implementMainT( RayPayloadInT< PayloadT > payload
			, HitAttributeT< AttrT > attribute
			, RayClosestHitMainFuncT< PayloadT, AttrT > const & function );
	};
	/**@}*/
}

#include "RayClosestHitWriter.inl"

#endif
