/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayGenerationWriter_H___
#define ___SDW_RayGenerationWriter_H___

#include "ShaderWriter/EntryPointWriter.hpp"

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
		: StructInstance
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		SDW_API explicit RayGenerationIn( ShaderWriter & writer );
		SDW_API RayGenerationIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		//in uvec3 gl_LaunchIDEXT;
		U32Vec3 const launchID;
		//in uvec3 gl_LaunchSizeEXT;
		U32Vec3 const launchSize;
	};

	using RayGenerationMainFunc = std::function< void( RayGenerationIn ) >;

	class RayGenerationWriter
		: public EntryPointWriter
	{
	public:
		SDW_API explicit RayGenerationWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit RayGenerationWriter( ShaderBuilder & builder );

		SDW_API void implementMain( RayGenerationMainFunc const & function );
	};
	/**@}*/
}

#endif
