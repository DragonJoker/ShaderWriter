/*
See LICENSE file in root folder
*/
#include "GlslCommon/GlslStatementsHelpers.hpp"

#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeCache.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <sstream>
#pragma warning( pop )

#pragma GCC diagnostic ignored "-Wrestrict"

namespace glsl
{
	namespace helpers
	{
		static std::string getImageDimName( ast::type::ImageDim value )
		{
			std::string result;

			switch ( value )
			{
			case ast::type::ImageDim::e1D:
				result = "1D";
				break;
			case ast::type::ImageDim::e2D:
				result = "2D";
				break;
			case ast::type::ImageDim::e3D:
				result = "3D";
				break;
			case ast::type::ImageDim::eCube:
				result = "Cube";
				break;
			case ast::type::ImageDim::eBuffer:
				result = "Buffer";
				break;
			default:
				AST_Failure( "Unsupported ast::type::ImageDim" );
				result = "Undefined";
				break;
			}

			return result;
		}
	}

	std::string getTypeName( ast::type::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case ast::type::Kind::eUndefined:
			result = "undefined";
			break;
		case ast::type::Kind::eVoid:
			result = "void";
			break;
		case ast::type::Kind::eStruct:
		case ast::type::Kind::eRayDesc:
			result = "struct";
			break;
		case ast::type::Kind::eFunction:
			result = "function";
			break;
		case ast::type::Kind::eBoolean:
			result = "bool";
			break;
		case ast::type::Kind::eInt8:
			result = "int8_t";
			break;
		case ast::type::Kind::eInt16:
			result = "int16_t";
			break;
		case ast::type::Kind::eInt32:
			result = "int";
			break;
		case ast::type::Kind::eInt64:
			result = "int64_t";
			break;
		case ast::type::Kind::eUInt8:
			result = "uint8_t";
			break;
		case ast::type::Kind::eUInt16:
			result = "uint16_t";
			break;
		case ast::type::Kind::eUInt32:
			result = "uint";
			break;
		case ast::type::Kind::eUInt64:
			result = "uint64_t";
			break;
		case ast::type::Kind::eHalf:
		case ast::type::Kind::eFloat:
			result = "float";
			break;
		case ast::type::Kind::eDouble:
			result = "double";
			break;
		case ast::type::Kind::eVec2B:
			result = "bvec2";
			break;
		case ast::type::Kind::eVec3B:
			result = "bvec3";
			break;
		case ast::type::Kind::eVec4B:
			result = "bvec4";
			break;
		case ast::type::Kind::eVec2I8:
			result = "i8vec2";
			break;
		case ast::type::Kind::eVec3I8:
			result = "i8vec3";
			break;
		case ast::type::Kind::eVec4I8:
			result = "i8vec4";
			break;
		case ast::type::Kind::eVec2I16:
			result = "i16vec2";
			break;
		case ast::type::Kind::eVec3I16:
			result = "i16vec3";
			break;
		case ast::type::Kind::eVec4I16:
			result = "i16vec4";
			break;
		case ast::type::Kind::eVec2I32:
			result = "ivec2";
			break;
		case ast::type::Kind::eVec3I32:
			result = "ivec3";
			break;
		case ast::type::Kind::eVec4I32:
			result = "ivec4";
			break;
		case ast::type::Kind::eVec2I64:
			result = "i64vec2";
			break;
		case ast::type::Kind::eVec3I64:
			result = "i64vec3";
			break;
		case ast::type::Kind::eVec4I64:
			result = "i64vec4";
			break;
		case ast::type::Kind::eVec2U8:
			result = "u8vec2";
			break;
		case ast::type::Kind::eVec3U8:
			result = "u8vec3";
			break;
		case ast::type::Kind::eVec4U8:
			result = "u8vec4";
			break;
		case ast::type::Kind::eVec2U16:
			result = "u16vec2";
			break;
		case ast::type::Kind::eVec3U16:
			result = "u16vec3";
			break;
		case ast::type::Kind::eVec4U16:
			result = "u16vec4";
			break;
		case ast::type::Kind::eVec2U32:
			result = "uvec2";
			break;
		case ast::type::Kind::eVec3U32:
			result = "uvec3";
			break;
		case ast::type::Kind::eVec4U32:
			result = "uvec4";
			break;
		case ast::type::Kind::eVec2U64:
			result = "u64vec2";
			break;
		case ast::type::Kind::eVec3U64:
			result = "u64vec3";
			break;
		case ast::type::Kind::eVec4U64:
			result = "u64vec4";
			break;
		case ast::type::Kind::eVec2H:
			result = "f16vec2";
			break;
		case ast::type::Kind::eVec4H:
			result = "f16vec4";
			break;
		case ast::type::Kind::eVec2F:
			result = "vec2";
			break;
		case ast::type::Kind::eVec3F:
			result = "vec3";
			break;
		case ast::type::Kind::eVec4F:
			result = "vec4";
			break;
		case ast::type::Kind::eVec2D:
			result = "dvec2";
			break;
		case ast::type::Kind::eVec3D:
			result = "dvec3";
			break;
		case ast::type::Kind::eVec4D:
			result = "dvec4";
			break;
		case ast::type::Kind::eMat2x2F:
			result = "mat2";
			break;
		case ast::type::Kind::eMat2x3F:
			result = "mat2x3";
			break;
		case ast::type::Kind::eMat2x4F:
			result = "mat2x4";
			break;
		case ast::type::Kind::eMat3x3F:
			result = "mat3";
			break;
		case ast::type::Kind::eMat3x2F:
			result = "mat3x2";
			break;
		case ast::type::Kind::eMat3x4F:
			result = "mat3x4";
			break;
		case ast::type::Kind::eMat4x4F:
			result = "mat4";
			break;
		case ast::type::Kind::eMat4x2F:
			result = "mat4x2";
			break;
		case ast::type::Kind::eMat4x3F:
			result = "mat4x3";
			break;
		case ast::type::Kind::eMat2x2D:
			result = "dmat2";
			break;
		case ast::type::Kind::eMat2x3D:
			result = "dmat2x3";
			break;
		case ast::type::Kind::eMat2x4D:
			result = "dmat2x4";
			break;
		case ast::type::Kind::eMat3x3D:
			result = "dmat3";
			break;
		case ast::type::Kind::eMat3x2D:
			result = "dmat3x2";
			break;
		case ast::type::Kind::eMat3x4D:
			result = "dmat3x4";
			break;
		case ast::type::Kind::eMat4x4D:
			result = "dmat4";
			break;
		case ast::type::Kind::eMat4x2D:
			result = "dmat4x2";
			break;
		case ast::type::Kind::eMat4x3D:
			result = "dmat4x3";
			break;
		case ast::type::Kind::eImage:
			result = "image";
			break;
		case ast::type::Kind::eSampler:
			result = "sampler";
			break;
		case ast::type::Kind::eSampledImage:
		case ast::type::Kind::eCombinedImage:
			result = "texture";
			break;
		case ast::type::Kind::ePointer:
			result = "pointer";
			break;
		default:
			AST_Failure( "Unsupported type::Kind" );
			break;
		}

		return result;
	}

	std::string getTypeName( ast::type::ImagePtr type )
	{
		std::string result;
		auto & config = type->getConfig();
		result += "image";
		result += helpers::getImageDimName( config.dimension );

		if ( config.isArrayed )
		{
			result += "Array";
		}

		return result;
	}

	std::string getTypeName( ast::type::SamplerPtr type )
	{
		std::string result;
		result += "sampler";

		if ( type->isComparison() )
		{
			result += "Shadow";
		}

		return result;
	}

	std::string getTypeName( ast::type::CombinedImagePtr type )
	{
		std::string result;
		auto config = type->getConfig();
		result += "sampler";
		result += helpers::getImageDimName( config.dimension );

		if ( config.isArrayed )
		{
			result += "Array";
		}

		if ( type->isComparison() )
		{
			assert( config.isSampled == ast::type::Trinary::eTrue );
			result += "Shadow";
		}

		return result;
	}

	std::string getTypeName( ast::type::SampledImagePtr type )
	{
		std::string result;
		auto config = type->getConfig();
		result += "texture";
		result += helpers::getImageDimName( config.dimension );

		if ( config.isArrayed )
		{
			result += "Array";
		}

		return result;
	}

	std::string getTypeName( ast::type::TypePtr type )
	{
		std::string result;

		switch ( type->getRawKind() )
		{
		case ast::type::Kind::eStruct:
		case ast::type::Kind::eRayDesc:
			result = static_cast< ast::type::Struct const & >( *type ).getName();
			break;
		case ast::type::Kind::eImage:
			result = getTypeName( std::static_pointer_cast< ast::type::Image >( type ) );
			break;
		case ast::type::Kind::eCombinedImage:
			result = getTypeName( std::static_pointer_cast< ast::type::CombinedImage >( type ) );
			break;
		case ast::type::Kind::eSampledImage:
			result = getTypeName( std::static_pointer_cast< ast::type::SampledImage >( type ) );
			break;
		case ast::type::Kind::eArray:
			result = getTypeName( std::static_pointer_cast< ast::type::Array >( type )->getType() );
			break;
		case ast::type::Kind::eRayPayload:
			result = getTypeName( std::static_pointer_cast< ast::type::RayPayload >( type )->getDataType() );
			break;
		case ast::type::Kind::eHitAttribute:
			result = getTypeName( std::static_pointer_cast< ast::type::HitAttribute >( type )->getDataType() );
			break;
		case ast::type::Kind::eCallableData:
			result = getTypeName( std::static_pointer_cast< ast::type::CallableData >( type )->getDataType() );
			break;
		case ast::type::Kind::eTessellationInputPatch:
			result = getTypeName( std::static_pointer_cast< ast::type::TessellationInputPatch >( type )->getType() );
			break;
		case ast::type::Kind::eTessellationOutputPatch:
			result = getTypeName( std::static_pointer_cast< ast::type::TessellationOutputPatch >( type )->getType() );
			break;
		case ast::type::Kind::eTessellationControlInput:
			result = getTypeName( std::static_pointer_cast< ast::type::TessellationControlInput >( type )->getType() );
			break;
		case ast::type::Kind::eTessellationControlOutput:
			result = getTypeName( std::static_pointer_cast< ast::type::TessellationControlOutput >( type )->getType() );
			break;
		case ast::type::Kind::eTessellationEvaluationInput:
			result = getTypeName( std::static_pointer_cast< ast::type::TessellationControlOutput >( type )->getType() );
			break;
		case ast::type::Kind::eTaskPayloadNV:
			result = getTypeName( std::static_pointer_cast< ast::type::TaskPayloadNV >( type )->getType() );
			break;
		case ast::type::Kind::eTaskPayload:
			result = getTypeName( std::static_pointer_cast< ast::type::TaskPayload >( type )->getType() );
			break;
		case ast::type::Kind::eTaskPayloadInNV:
			result = getTypeName( std::static_pointer_cast< ast::type::TaskPayloadInNV >( type )->getType() );
			break;
		case ast::type::Kind::eTaskPayloadIn:
			result = getTypeName( std::static_pointer_cast< ast::type::TaskPayloadIn >( type )->getType() );
			break;
		case ast::type::Kind::ePointer:
			result = getTypeName( std::static_pointer_cast< ast::type::Pointer >( type )->getPointerType() );
			break;
		default:
			result = getTypeName( type->getKind() );
			break;
		}

		return result;
	}

	RangeInfo getColumnData( Statement const * statement
		, ast::expr::Expr const & expr )
	{
		glsl::RangeInfo result;

		if ( statement )
		{
			auto it = statement->exprs.find( &expr );

			if ( it != statement->exprs.end() )
			{
				result = it->second;
			}
			else
			{
				result = statement->source.columns;
			}
		}

		return result;
	}

	RangeInfo getColumnData( Statement const * statement )
	{
		glsl::RangeInfo result;

		if ( statement )
		{
			auto it = statement->exprs.find( nullptr );

			if ( it != statement->exprs.end() )
			{
				result = it->second;
			}
			else
			{
				result = statement->source.columns;
			}
		}

		return result;
	}

	void checkType( ast::type::TypePtr ptype
		, IntrinsicsConfig & config )
	{
		ast::type::traverseType( ptype, 1u
			, [&config]( ast::type::TypePtr type
				, [[maybe_unused]] uint32_t arraySize )
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
	}}
