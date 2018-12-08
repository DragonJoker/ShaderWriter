/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeCache.hpp"

#include "ShaderAST/Type/TypeImage.hpp"
#include "ShaderAST/Type/TypeSampledImage.hpp"
#include "ShaderAST/Type/TypeSampler.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::type
{
	//*************************************************************************

	namespace
	{
		template< typename T >
		inline size_t hashCombine( size_t & hash
			, T const & rhs )
		{
			const uint64_t kMul = 0x9ddfea08eb382d69ULL;
			auto seed = hash;

			std::hash< T > hasher;
			uint64_t a = ( hasher( rhs ) ^ seed ) * kMul;
			a ^= ( a >> 47 );

			uint64_t b = ( seed ^ a ) * kMul;
			b ^= ( b >> 47 );

			hash = static_cast< std::size_t >( b * kMul );
			return hash;
		}
	}

	//*************************************************************************

	TypesCache * TypesCache::m_instance{ nullptr };

	TypesCache::TypesCache()
		: m_undefined{ std::make_shared< Type >( this, Kind::eUndefined ) }
		, m_void{ std::make_shared< Type >( this, Kind::eVoid ) }
		, m_function{ std::make_shared< Type >( this, Kind::eFunction ) }
		, m_boolean{ std::make_shared< Type >( this, Kind::eBoolean ) }
		, m_int{ std::make_shared< Type >( this, Kind::eInt ) }
		, m_uint{ std::make_shared< Type >( this, Kind::eUInt ) }
		, m_float{ std::make_shared< Type >( this, Kind::eFloat ) }
		, m_double{ std::make_shared< Type >( this, Kind::eDouble ) }
		, m_vec2B{ std::make_shared< Type >( this, Kind::eVec2B ) }
		, m_vec3B{ std::make_shared< Type >( this, Kind::eVec3B ) }
		, m_vec4B{ std::make_shared< Type >( this, Kind::eVec4B ) }
		, m_vec2I{ std::make_shared< Type >( this, Kind::eVec2I ) }
		, m_vec3I{ std::make_shared< Type >( this, Kind::eVec3I ) }
		, m_vec4I{ std::make_shared< Type >( this, Kind::eVec4I ) }
		, m_vec2U{ std::make_shared< Type >( this, Kind::eVec2U ) }
		, m_vec3U{ std::make_shared< Type >( this, Kind::eVec3U ) }
		, m_vec4U{ std::make_shared< Type >( this, Kind::eVec4U ) }
		, m_vec2F{ std::make_shared< Type >( this, Kind::eVec2F ) }
		, m_vec3F{ std::make_shared< Type >( this, Kind::eVec3F ) }
		, m_vec4F{ std::make_shared< Type >( this, Kind::eVec4F ) }
		, m_vec2D{ std::make_shared< Type >( this, Kind::eVec2D ) }
		, m_vec3D{ std::make_shared< Type >( this, Kind::eVec3D ) }
		, m_vec4D{ std::make_shared< Type >( this, Kind::eVec4D ) }
		, m_mat2x2F{ std::make_shared< Type >( this, Kind::eMat2x2F ) }
		, m_mat2x3F{ std::make_shared< Type >( this, Kind::eMat2x3F ) }
		, m_mat2x4F{ std::make_shared< Type >( this, Kind::eMat2x4F ) }
		, m_mat3x2F{ std::make_shared< Type >( this, Kind::eMat3x2F ) }
		, m_mat3x3F{ std::make_shared< Type >( this, Kind::eMat3x3F ) }
		, m_mat3x4F{ std::make_shared< Type >( this, Kind::eMat3x4F ) }
		, m_mat4x2F{ std::make_shared< Type >( this, Kind::eMat4x2F ) }
		, m_mat4x3F{ std::make_shared< Type >( this, Kind::eMat4x3F ) }
		, m_mat4x4F{ std::make_shared< Type >( this, Kind::eMat4x4F ) }
		, m_mat2x2D{ std::make_shared< Type >( this, Kind::eMat2x2D ) }
		, m_mat2x3D{ std::make_shared< Type >( this, Kind::eMat2x3D ) }
		, m_mat2x4D{ std::make_shared< Type >( this, Kind::eMat2x4D ) }
		, m_mat3x2D{ std::make_shared< Type >( this, Kind::eMat3x2D ) }
		, m_mat3x3D{ std::make_shared< Type >( this, Kind::eMat3x3D ) }
		, m_mat3x4D{ std::make_shared< Type >( this, Kind::eMat3x4D ) }
		, m_mat4x2D{ std::make_shared< Type >( this, Kind::eMat4x2D ) }
		, m_mat4x3D{ std::make_shared< Type >( this, Kind::eMat4x3D ) }
		, m_mat4x4D{ std::make_shared< Type >( this, Kind::eMat4x4D ) }
		, m_ubo{ std::make_shared< Type >( this, Kind::eConstantsBuffer ) }
		, m_ssbo{ std::make_shared< Type >( this, Kind::eShaderBuffer ) }
		, m_image{ this
			, []( TypesCache * cache
				, ImageConfiguration config )
			{
				return std::make_shared< Image >( cache
					, std::move( config ) );
			}
			, []( ImageConfiguration const & config )
			{
				return getHash( config );
			} }
		, m_sampledImage{ this
			, []( TypesCache * cache
				, ImageConfiguration config )
			{
				return std::make_shared< SampledImage >( cache
					, std::move( config ) );
			}
			, []( ImageConfiguration const & config )
			{
				return getHash( config );
			} }
		, m_sampler{ this
			, []( TypesCache * cache
				, bool comparison )
			{
				return std::make_shared< Sampler >( cache
					, comparison );
			}
			, []( bool comparison )
			{
				return comparison ? 1u : 0u;
			} }
		, m_struct{ this
			, []( TypesCache * cache
				, MemoryLayout layout
				, std::string name )
			{
				return std::make_shared< Struct >( cache
					, layout
					, std::move( name ) );
			}
			, []( MemoryLayout layout
				, std::string const & name )
			{
				return getHash( layout, name );
			} }
			, m_array{ this
				, []( TypesCache * cache
				, TypePtr type
				, uint32_t arraySize )
			{
				return std::make_shared< Array >( cache
					, std::move( type )
					, arraySize );
			}
			, []( TypePtr type
				, uint32_t arraySize )
			{
				return getHash( type, arraySize );
			} }
	{
		if ( m_instance )
		{
			throw std::runtime_error{ "Can't have more than one instance of TypeCache" };
		}

		m_instance = this;
	}

	TypesCache::~TypesCache()
	{
		assert( m_instance && "Oops... 0xDDDDDDDD" );
		m_instance = nullptr;
	}

	TypePtr TypesCache::getUndefined()
	{
		return m_undefined;
	}

	TypePtr TypesCache::getVoid()
	{
		return m_void;
	}

	TypePtr TypesCache::getFunction()
	{
		return m_function;
	}

	TypePtr TypesCache::getBool()
	{
		return m_boolean;
	}

	TypePtr TypesCache::getInt()
	{
		return m_int;
	}

	TypePtr TypesCache::getUInt()
	{
		return m_uint;
	}

	TypePtr TypesCache::getFloat()
	{
		return m_float;
	}

	TypePtr TypesCache::getDouble()
	{
		return m_double;
	}

	TypePtr TypesCache::getVec2B()
	{
		return m_vec2B;
	}

	TypePtr TypesCache::getVec3B()
	{
		return m_vec3B;
	}

	TypePtr TypesCache::getVec4B()
	{
		return m_vec4B;
	}

	TypePtr TypesCache::getVec2I()
	{
		return m_vec2I;
	}

	TypePtr TypesCache::getVec3I()
	{
		return m_vec3I;
	}

	TypePtr TypesCache::getVec4I()
	{
		return m_vec4I;
	}

	TypePtr TypesCache::getVec2U()
	{
		return m_vec2U;
	}

	TypePtr TypesCache::getVec3U()
	{
		return m_vec3U;
	}

	TypePtr TypesCache::getVec4U()
	{
		return m_vec4U;
	}

	TypePtr TypesCache::getVec2F()
	{
		return m_vec2F;
	}

	TypePtr TypesCache::getVec3F()
	{
		return m_vec3F;
	}

	TypePtr TypesCache::getVec4F()
	{
		return m_vec4F;
	}

	TypePtr TypesCache::getVec2D()
	{
		return m_vec2D;
	}

	TypePtr TypesCache::getVec3D()
	{
		return m_vec3D;
	}

	TypePtr TypesCache::getVec4D()
	{
		return m_vec4D;
	}

	TypePtr TypesCache::getMat2x2F()
	{
		return m_mat2x2F;
	}

	TypePtr TypesCache::getMat2x3F()
	{
		return m_mat2x3F;
	}

	TypePtr TypesCache::getMat2x4F()
	{
		return m_mat2x4F;
	}

	TypePtr TypesCache::getMat3x2F()
	{
		return m_mat3x2F;
	}

	TypePtr TypesCache::getMat3x3F()
	{
		return m_mat3x3F;
	}

	TypePtr TypesCache::getMat3x4F()
	{
		return m_mat3x4F;
	}

	TypePtr TypesCache::getMat4x2F()
	{
		return m_mat4x2F;
	}

	TypePtr TypesCache::getMat4x3F()
	{
		return m_mat4x3F;
	}

	TypePtr TypesCache::getMat4x4F()
	{
		return m_mat4x4F;
	}

	TypePtr TypesCache::getMat2x2D()
	{
		return m_mat2x2D;
	}

	TypePtr TypesCache::getMat2x3D()
	{
		return m_mat2x3D;
	}

	TypePtr TypesCache::getMat2x4D()
	{
		return m_mat2x4D;
	}

	TypePtr TypesCache::getMat3x2D()
	{
		return m_mat3x2D;
	}

	TypePtr TypesCache::getMat3x3D()
	{
		return m_mat3x3D;
	}

	TypePtr TypesCache::getMat3x4D()
	{
		return m_mat3x4D;
	}

	TypePtr TypesCache::getMat4x2D()
	{
		return m_mat4x2D;
	}

	TypePtr TypesCache::getMat4x3D()
	{
		return m_mat4x3D;
	}

	TypePtr TypesCache::getMat4x4D()
	{
		return m_mat4x4D;
	}

	TypePtr TypesCache::getConstantsBuffer()
	{
		return m_ubo;
	}

	TypePtr TypesCache::getShaderBuffer()
	{
		return m_ssbo;
	}

	ImagePtr TypesCache::getImage( ImageConfiguration const & config )
	{
		return m_image.getType( config );
	}

	SampledImagePtr TypesCache::getSampledImage( ImageConfiguration const & config )
	{
		return m_sampledImage.getType( config );
	}

	SamplerPtr TypesCache::getSampler( bool comparison )
	{
		return m_sampler.getType( comparison );
	}

	TypePtr TypesCache::getSampledType( ImageFormat format )
	{
		switch ( format )
		{
		case ImageFormat::eUnknown:
			return makeType( sampledType< ImageFormat::eUnknown > );
		case ImageFormat::eRgba32f:
			return makeType( sampledType< ImageFormat::eRgba32f > );
		case ImageFormat::eRgba16f:
			return makeType( sampledType< ImageFormat::eRgba16f > );
		case ImageFormat::eRg32f:
			return makeType( sampledType< ImageFormat::eRg32f > );
		case ImageFormat::eRg16f:
			return makeType( sampledType< ImageFormat::eRg16f > );
		case ImageFormat::eR32f:
			return makeType( sampledType< ImageFormat::eR32f > );
		case ImageFormat::eR16f:
			return makeType( sampledType< ImageFormat::eR16f > );
		case ImageFormat::eRgba32i:
			return makeType( sampledType< ImageFormat::eRgba32i > );
		case ImageFormat::eRgba16i:
			return makeType( sampledType< ImageFormat::eRgba16i > );
		case ImageFormat::eRgba8i:
			return makeType( sampledType< ImageFormat::eRgba8i > );
		case ImageFormat::eRg32i:
			return makeType( sampledType< ImageFormat::eRg32i > );
		case ImageFormat::eRg16i:
			return makeType( sampledType< ImageFormat::eRg16i > );
		case ImageFormat::eRg8i:
			return makeType( sampledType< ImageFormat::eRg8i > );
		case ImageFormat::eR32i:
			return makeType( sampledType< ImageFormat::eR32i > );
		case ImageFormat::eR16i:
			return makeType( sampledType< ImageFormat::eR16i > );
		case ImageFormat::eR8i:
			return makeType( sampledType< ImageFormat::eR8i > );
		case ImageFormat::eRgba32u:
			return makeType( sampledType< ImageFormat::eRgba32u > );
		case ImageFormat::eRgba16u:
			return makeType( sampledType< ImageFormat::eRgba16u > );
		case ImageFormat::eRgba8u:
			return makeType( sampledType< ImageFormat::eRgba8u > );
		case ImageFormat::eRg32u:
			return makeType( sampledType< ImageFormat::eRg32u > );
		case ImageFormat::eRg16u:
			return makeType( sampledType< ImageFormat::eRg16u > );
		case ImageFormat::eRg8u:
			return makeType( sampledType< ImageFormat::eRg8u > );
		case ImageFormat::eR32u:
			return makeType( sampledType< ImageFormat::eR32u > );
		case ImageFormat::eR16u:
			return makeType( sampledType< ImageFormat::eR16u > );
		case ImageFormat::eR8u:
			return makeType( sampledType< ImageFormat::eR8u > );
		default:
			assert( false && "hlsl::getType: Unsupported ImageFormat" );
			return nullptr;
		}
	}

	StructPtr TypesCache::getStruct( MemoryLayout layout, std::string const & name )
	{
		return m_struct.getType( layout, name );
	}

	ArrayPtr TypesCache::getArray( TypePtr type, uint32_t arraySize )
	{
		return m_array.getType( type, arraySize );
	}

	TypePtr TypesCache::getMemberType( TypePtr type, Struct & parent, uint32_t memberIndex )
	{
		return type->getMemberType( parent, memberIndex );
	}

	TypePtr TypesCache::getVec2Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec2B();
		case Kind::eInt:
			return getVec2I();
		case Kind::eUInt:
			return getVec2U();
		case Kind::eFloat:
			return getVec2F();
		case Kind::eDouble:
			return getVec2D();
		default:
			assert( false && "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVec3Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec3B();
		case Kind::eInt:
			return getVec3I();
		case Kind::eUInt:
			return getVec3U();
		case Kind::eFloat:
			return getVec3F();
		case Kind::eDouble:
			return getVec3D();
		default:
			assert( false && "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVec4Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec4B();
		case Kind::eInt:
			return getVec4I();
		case Kind::eUInt:
			return getVec4U();
		case Kind::eFloat:
			return getVec4F();
		case Kind::eDouble:
			return getVec4D();
		default:
			assert( false && "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVector( Kind kind, uint32_t count )
	{
		assert( isScalarType( kind ) );

		switch ( count )
		{
		case 1:
			return makeType( kind );
		case 2:
			return getVec2Type( kind );
		case 3:
			return getVec3Type( kind );
		case 4:
			return getVec4Type( kind );
		}

		return nullptr;
	}

	TypePtr TypesCache::makeType( Kind kind )
	{
		assert( kind != Kind::eImage
			&& kind != Kind::eSampledImage
			&& kind != Kind::eSampler );

		switch ( kind )
		{
		case Kind::eUndefined:
			return getUndefined();
		case Kind::eVoid:
			return getVoid();
		case Kind::eFunction:
			return getFunction();
		case Kind::eBoolean:
			return getBool();
		case Kind::eInt:
			return getInt();
		case Kind::eUInt:
			return getUInt();
		case Kind::eFloat:
			return getFloat();
		case Kind::eDouble:
			return getDouble();
		case Kind::eVec2B:
			return getVec2B();
		case Kind::eVec3B:
			return getVec3B();
		case Kind::eVec4B:
			return getVec4B();
		case Kind::eVec2I:
			return getVec2I();
		case Kind::eVec3I:
			return getVec3I();
		case Kind::eVec4I:
			return getVec4I();
		case Kind::eVec2U:
			return getVec2U();
		case Kind::eVec3U:
			return getVec3U();
		case Kind::eVec4U:
			return getVec4U();
		case Kind::eVec2F:
			return getVec2F();
		case Kind::eVec3F:
			return getVec3F();
		case Kind::eVec4F:
			return getVec4F();
		case Kind::eVec2D:
			return getVec2D();
		case Kind::eVec3D:
			return getVec3D();
		case Kind::eVec4D:
			return getVec4D();
		case Kind::eMat2x2F:
			return getMat2x2F();
		case Kind::eMat2x3F:
			return getMat2x3F();
		case Kind::eMat2x4F:
			return getMat2x4F();
		case Kind::eMat3x2F:
			return getMat3x2F();
		case Kind::eMat3x3F:
			return getMat3x3F();
		case Kind::eMat3x4F:
			return getMat3x4F();
		case Kind::eMat4x2F:
			return getMat4x2F();
		case Kind::eMat4x3F:
			return getMat4x3F();
		case Kind::eMat4x4F:
			return getMat4x4F();
		case Kind::eMat2x2D:
			return getMat2x2D();
		case Kind::eMat2x3D:
			return getMat2x3D();
		case Kind::eMat2x4D:
			return getMat2x4D();
		case Kind::eMat3x2D:
			return getMat3x2D();
		case Kind::eMat3x3D:
			return getMat3x3D();
		case Kind::eMat3x4D:
			return getMat3x4D();
		case Kind::eMat4x2D:
			return getMat4x2D();
		case Kind::eMat4x3D:
			return getMat4x3D();
		case Kind::eMat4x4D:
			return getMat4x4D();
		case Kind::eConstantsBuffer:
			return getConstantsBuffer();
		case Kind::eShaderBuffer:
			return getShaderBuffer();
		default:
			assert( false && "Unexpected Kind" );
			return nullptr;
		}
	}

	//*************************************************************************
}
