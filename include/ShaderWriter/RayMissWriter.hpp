/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayMissWriter_H___
#define ___SDW_RayMissWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"
#include "ShaderWriter/BaseTypes/RayPayload.hpp"
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
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit RayMissIn( ShaderWriter & writer );
		SDW_API RayMissIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		// Work dimensions
		//in uvec3 gl_LaunchIDEXT;
		U32Vec3 launchID;
		//in uvec3 gl_LaunchSizeEXT;
		U32Vec3 launchSize;

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
		UInt32 incomingRayFlags;

		Float hitT;
	};

	template< typename PayloadT >
	using RayMissMainFuncT = std::function< void( RayMissIn, RayPayloadInT< PayloadT > ) >;

	class RayMissWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit RayMissWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit RayMissWriter( ShaderBuilder & builder );

		template< typename PayloadT >
		void implementMainT( uint32_t payloadLocation
			, RayMissMainFuncT< PayloadT > const & function );
		template< typename PayloadT >
		void implementMainT( RayPayloadInT< PayloadT > payload
			, RayMissMainFuncT< PayloadT > const & function );
	};
	/**@}*/
}

#include "RayMissWriter.inl"

#endif
