/*
See LICENSE file in root folder
*/
#include "GlslHelpers.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>

#include <stdexcept>

#pragma GCC diagnostic ignored "-Wrestrict"

namespace glsl
{
	void checkType( ast::type::TypePtr ptype
		, IntrinsicsConfig & config )
	{
		ast::type::traverseType( ptype, 1u
			, [&config]( ast::type::TypePtr type
				, uint32_t arraySize )
			{
				switch ( type->getRawKind() )
				{
				case ast::type::Kind::eImage:
				case ast::type::Kind::eCombinedImage:
				case ast::type::Kind::eAccelerationStructure:
					return;
				case ast::type::Kind::eSampler:
				case ast::type::Kind::eSampledImage:
					config.requiresSeparateSamplers = true;
					return;
				default:
					break;
				}

				auto component = getComponentType( type );

				while ( !isScalarType( component ) )
				{
					component = getComponentType( component );
				}

				if ( component == ast::type::Kind::eHalf )
				{
					config.requiredExtensions.insert( NV_gpu_shader5 );
				}

				if ( component == ast::type::Kind::eDouble )
				{
					config.requiredExtensions.insert( ARB_gpu_shader_fp64 );
				}

				if ( component == ast::type::Kind::eInt8
					|| component == ast::type::Kind::eUInt8 )
				{
					config.requiresInt8 = true;
				}

				if ( component == ast::type::Kind::eUInt16
					|| component == ast::type::Kind::eInt16 )
				{
					config.requiresInt16 = true;
				}

				if ( component == ast::type::Kind::eUInt64
					|| component == ast::type::Kind::eInt64 )
				{
					config.requiresInt64 = true;
				}
			} );
	}
}
