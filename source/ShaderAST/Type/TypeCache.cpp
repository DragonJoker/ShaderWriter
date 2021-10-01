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

	TypesCache::TypesCache()
		: m_image{ [this]( ImageConfiguration config )
			{
				return std::make_shared< Image >( *this, std::move( config ) );
			}
			, []( ImageConfiguration const & config )noexcept
			{
				return getHash( config );
			} }
		, m_sampledImage{ [this]( ImageConfiguration config )
			{
				return std::make_shared< SampledImage >( *this, std::move( config ) );
			}
			, []( ImageConfiguration const & config )noexcept
			{
				return getHash( config );
			} }
		, m_sampler{ [this]( bool comparison )
			{
				return std::make_shared< Sampler >( *this, comparison );
			}
			, []( bool comparison )noexcept
			{
				return comparison ? 1u : 0u;
			} }
		, m_function{ []( TypePtr returnType
				, var::VariableList parameters )
			{
				return std::make_shared< Function >( returnType
					, std::move( parameters ) );
			}
			, []( TypePtr returnType
				, var::VariableList const & parameters )noexcept
			{
				return getHash( returnType, parameters );
			} }
		, m_struct{ [this]( MemoryLayout layout
				, std::string name )
			{
				return std::make_shared< Struct >( *this
					, layout
					, std::move( name ) );
			}
			, []( MemoryLayout layout
				, std::string const & name )noexcept
			{
				return getHash( layout, name );
			} }
		, m_array{ []( TypePtr type
				, uint32_t arraySize )
			{
				return std::make_shared< Array >( std::move( type )
					, arraySize );
			}
			, []( TypePtr type
				, uint32_t arraySize )noexcept
			{
				return getHash( type, arraySize );
			} }
		, m_pointer{ []( TypePtr pointerType
				, Storage storage )
			{
				return std::make_shared< Pointer >( std::move( pointerType )
					, storage );
			}
			, []( TypePtr pointerType
				, Storage storage )noexcept
			{
				return getHash( pointerType, storage );
			} }
	{
		for ( uint32_t i = uint32_t( Kind::eUndefined ); i <= uint32_t( Kind::eMat4x4D ); ++i )
		{
			m_basicTypes[i] = std::make_shared< Type >( *this, Kind( i ) );
		}
	}

	TypesCache::~TypesCache()
	{
	}

	TypePtr TypesCache::getUndefined()
	{
		return getBasicType( Kind::eUndefined );
	}

	TypePtr TypesCache::getVoid()
	{
		return getBasicType( Kind::eVoid );
	}

	TypePtr TypesCache::getBool()
	{
		return getBasicType( Kind::eBoolean );
	}

	TypePtr TypesCache::getInt()
	{
		return getBasicType( Kind::eInt );
	}

	TypePtr TypesCache::getUInt()
	{
		return getBasicType( Kind::eUInt );
	}

	TypePtr TypesCache::getHalf()
	{
		return getBasicType( Kind::eHalf );
	}

	TypePtr TypesCache::getFloat()
	{
		return getBasicType( Kind::eFloat );
	}

	TypePtr TypesCache::getDouble()
	{
		return getBasicType( Kind::eDouble );
	}

	TypePtr TypesCache::getVec2B()
	{
		return getBasicType( Kind::eVec2B );
	}

	TypePtr TypesCache::getVec3B()
	{
		return getBasicType( Kind::eVec3B );
	}

	TypePtr TypesCache::getVec4B()
	{
		return getBasicType( Kind::eVec4B );
	}

	TypePtr TypesCache::getVec2I()
	{
		return getBasicType( Kind::eVec2I );
	}

	TypePtr TypesCache::getVec3I()
	{
		return getBasicType( Kind::eVec3I );
	}

	TypePtr TypesCache::getVec4I()
	{
		return getBasicType( Kind::eVec4I );
	}

	TypePtr TypesCache::getVec2U()
	{
		return getBasicType( Kind::eVec2U );
	}

	TypePtr TypesCache::getVec3U()
	{
		return getBasicType( Kind::eVec3U );
	}

	TypePtr TypesCache::getVec4U()
	{
		return getBasicType( Kind::eVec4U );
	}

	TypePtr TypesCache::getVec2H()
	{
		return getBasicType( Kind::eVec2H );
	}

	TypePtr TypesCache::getVec4H()
	{
		return getBasicType( Kind::eVec4H );
	}

	TypePtr TypesCache::getVec2F()
	{
		return getBasicType( Kind::eVec2F );
	}

	TypePtr TypesCache::getVec3F()
	{
		return getBasicType( Kind::eVec3F );
	}

	TypePtr TypesCache::getVec4F()
	{
		return getBasicType( Kind::eVec4F );
	}

	TypePtr TypesCache::getVec2D()
	{
		return getBasicType( Kind::eVec2D );
	}

	TypePtr TypesCache::getVec3D()
	{
		return getBasicType( Kind::eVec3D );
	}

	TypePtr TypesCache::getVec4D()
	{
		return getBasicType( Kind::eVec4D );
	}

	TypePtr TypesCache::getMat2x2F()
	{
		return getBasicType( Kind::eMat2x2F );
	}

	TypePtr TypesCache::getMat2x3F()
	{
		return getBasicType( Kind::eMat2x3F );
	}

	TypePtr TypesCache::getMat2x4F()
	{
		return getBasicType( Kind::eMat2x4F );
	}

	TypePtr TypesCache::getMat3x2F()
	{
		return getBasicType( Kind::eMat3x2F );
	}

	TypePtr TypesCache::getMat3x3F()
	{
		return getBasicType( Kind::eMat3x3F );
	}

	TypePtr TypesCache::getMat3x4F()
	{
		return getBasicType( Kind::eMat3x4F );
	}

	TypePtr TypesCache::getMat4x2F()
	{
		return getBasicType( Kind::eMat4x2F );
	}

	TypePtr TypesCache::getMat4x3F()
	{
		return getBasicType( Kind::eMat4x3F );
	}

	TypePtr TypesCache::getMat4x4F()
	{
		return getBasicType( Kind::eMat4x4F );
	}

	TypePtr TypesCache::getMat2x2D()
	{
		return getBasicType( Kind::eMat2x2D );
	}

	TypePtr TypesCache::getMat2x3D()
	{
		return getBasicType( Kind::eMat2x3D );
	}

	TypePtr TypesCache::getMat2x4D()
	{
		return getBasicType( Kind::eMat2x4D );
	}

	TypePtr TypesCache::getMat3x2D()
	{
		return getBasicType( Kind::eMat3x2D );
	}

	TypePtr TypesCache::getMat3x3D()
	{
		return getBasicType( Kind::eMat3x3D );
	}

	TypePtr TypesCache::getMat3x4D()
	{
		return getBasicType( Kind::eMat3x4D );
	}

	TypePtr TypesCache::getMat4x2D()
	{
		return getBasicType( Kind::eMat4x2D );
	}

	TypePtr TypesCache::getMat4x3D()
	{
		return getBasicType( Kind::eMat4x3D );
	}

	TypePtr TypesCache::getMat4x4D()
	{
		return getBasicType( Kind::eMat4x4D );
	}

	TypePtr TypesCache::getBasicType( Kind kind )
	{
		assert( kind >= Kind::eUndefined
			&& kind <= Kind::eBasicTypesMax );

		switch ( kind )
		{
		case Kind::eUndefined:
			return m_basicTypes[size_t( Kind::eUndefined )];
		case Kind::eVoid:
			return m_basicTypes[size_t( Kind::eVoid )];
		case Kind::eFunction:
			return m_basicTypes[size_t( Kind::eFunction )];
		case Kind::eBoolean:
			return m_basicTypes[size_t( Kind::eBoolean )];
		case Kind::eInt:
			return m_basicTypes[size_t( Kind::eInt )];
		case Kind::eUInt:
			return m_basicTypes[size_t( Kind::eUInt )];
		case Kind::eHalf:
			return m_basicTypes[size_t( Kind::eHalf )];
		case Kind::eFloat:
			return m_basicTypes[size_t( Kind::eFloat )];
		case Kind::eDouble:
			return m_basicTypes[size_t( Kind::eDouble )];
		case Kind::eVec2B:
			return m_basicTypes[size_t( Kind::eVec2B )];
		case Kind::eVec3B:
			return m_basicTypes[size_t( Kind::eVec3B )];
		case Kind::eVec4B:
			return m_basicTypes[size_t( Kind::eVec4B )];
		case Kind::eVec2I:
			return m_basicTypes[size_t( Kind::eVec2I )];
		case Kind::eVec3I:
			return m_basicTypes[size_t( Kind::eVec3I )];
		case Kind::eVec4I:
			return m_basicTypes[size_t( Kind::eVec4I )];
		case Kind::eVec2U:
			return m_basicTypes[size_t( Kind::eVec2U )];
		case Kind::eVec3U:
			return m_basicTypes[size_t( Kind::eVec3U )];
		case Kind::eVec4U:
			return m_basicTypes[size_t( Kind::eVec4U )];
		case Kind::eVec2H:
			return m_basicTypes[size_t( Kind::eVec2H )];
		case Kind::eVec4H:
			return m_basicTypes[size_t( Kind::eVec4H )];
		case Kind::eVec2F:
			return m_basicTypes[size_t( Kind::eVec2F )];
		case Kind::eVec3F:
			return m_basicTypes[size_t( Kind::eVec3F )];
		case Kind::eVec4F:
			return m_basicTypes[size_t( Kind::eVec4F )];
		case Kind::eVec2D:
			return m_basicTypes[size_t( Kind::eVec2D )];
		case Kind::eVec3D:
			return m_basicTypes[size_t( Kind::eVec3D )];
		case Kind::eVec4D:
			return m_basicTypes[size_t( Kind::eVec4D )];
		case Kind::eMat2x2F:
			return m_basicTypes[size_t( Kind::eMat2x2F )];
		case Kind::eMat2x3F:
			return m_basicTypes[size_t( Kind::eMat2x3F )];
		case Kind::eMat2x4F:
			return m_basicTypes[size_t( Kind::eMat2x4F )];
		case Kind::eMat3x2F:
			return m_basicTypes[size_t( Kind::eMat3x2F )];
		case Kind::eMat3x3F:
			return m_basicTypes[size_t( Kind::eMat3x3F )];
		case Kind::eMat3x4F:
			return m_basicTypes[size_t( Kind::eMat3x4F )];
		case Kind::eMat4x2F:
			return m_basicTypes[size_t( Kind::eMat4x2F )];
		case Kind::eMat4x3F:
			return m_basicTypes[size_t( Kind::eMat4x3F )];
		case Kind::eMat4x4F:
			return m_basicTypes[size_t( Kind::eMat4x4F )];
		case Kind::eMat2x2D:
			return m_basicTypes[size_t( Kind::eMat2x2D )];
		case Kind::eMat2x3D:
			return m_basicTypes[size_t( Kind::eMat2x3D )];
		case Kind::eMat2x4D:
			return m_basicTypes[size_t( Kind::eMat2x4D )];
		case Kind::eMat3x2D:
			return m_basicTypes[size_t( Kind::eMat3x2D )];
		case Kind::eMat3x3D:
			return m_basicTypes[size_t( Kind::eMat3x3D )];
		case Kind::eMat3x4D:
			return m_basicTypes[size_t( Kind::eMat3x4D )];
		case Kind::eMat4x2D:
			return m_basicTypes[size_t( Kind::eMat4x2D )];
		case Kind::eMat4x3D:
			return m_basicTypes[size_t( Kind::eMat4x3D )];
		case Kind::eMat4x4D:
			return m_basicTypes[size_t( Kind::eMat4x4D )];
		default:
			AST_Failure( "Unexpected Kind" );
			return nullptr;
		}
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
		case Kind::eHalf:
			return getVec2H();
		case Kind::eFloat:
			return getVec2F();
		case Kind::eDouble:
			return getVec2D();
		default:
			AST_Failure( "Unsupported component type." );
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
			AST_Failure( "Unsupported component type." );
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
		case Kind::eHalf:
			return getVec4H();
		case Kind::eFloat:
			return getVec4F();
		case Kind::eDouble:
			return getVec4D();
		default:
			AST_Failure( "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVector( Kind kind, uint32_t count )
	{
		assert( isScalarType( kind ) );

		switch ( count )
		{
		case 1:
			return getBasicType( kind );
		case 2:
			return getVec2Type( kind );
		case 3:
			return getVec3Type( kind );
		case 4:
			return getVec4Type( kind );
		}

		return nullptr;
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
			return getBasicType( sampledType< ImageFormat::eUnknown > );
		case ImageFormat::eRgba32f:
			return getBasicType( sampledType< ImageFormat::eRgba32f > );
		case ImageFormat::eRgba16f:
			return getBasicType( sampledType< ImageFormat::eRgba16f > );
		case ImageFormat::eRg32f:
			return getBasicType( sampledType< ImageFormat::eRg32f > );
		case ImageFormat::eRg16f:
			return getBasicType( sampledType< ImageFormat::eRg16f > );
		case ImageFormat::eR32f:
			return getBasicType( sampledType< ImageFormat::eR32f > );
		case ImageFormat::eR16f:
			return getBasicType( sampledType< ImageFormat::eR16f > );
		case ImageFormat::eRgba32i:
			return getBasicType( sampledType< ImageFormat::eRgba32i > );
		case ImageFormat::eRgba16i:
			return getBasicType( sampledType< ImageFormat::eRgba16i > );
		case ImageFormat::eRgba8i:
			return getBasicType( sampledType< ImageFormat::eRgba8i > );
		case ImageFormat::eRg32i:
			return getBasicType( sampledType< ImageFormat::eRg32i > );
		case ImageFormat::eRg16i:
			return getBasicType( sampledType< ImageFormat::eRg16i > );
		case ImageFormat::eRg8i:
			return getBasicType( sampledType< ImageFormat::eRg8i > );
		case ImageFormat::eR32i:
			return getBasicType( sampledType< ImageFormat::eR32i > );
		case ImageFormat::eR16i:
			return getBasicType( sampledType< ImageFormat::eR16i > );
		case ImageFormat::eR8i:
			return getBasicType( sampledType< ImageFormat::eR8i > );
		case ImageFormat::eRgba32u:
			return getBasicType( sampledType< ImageFormat::eRgba32u > );
		case ImageFormat::eRgba16u:
			return getBasicType( sampledType< ImageFormat::eRgba16u > );
		case ImageFormat::eRgba8u:
			return getBasicType( sampledType< ImageFormat::eRgba8u > );
		case ImageFormat::eRg32u:
			return getBasicType( sampledType< ImageFormat::eRg32u > );
		case ImageFormat::eRg16u:
			return getBasicType( sampledType< ImageFormat::eRg16u > );
		case ImageFormat::eRg8u:
			return getBasicType( sampledType< ImageFormat::eRg8u > );
		case ImageFormat::eR32u:
			return getBasicType( sampledType< ImageFormat::eR32u > );
		case ImageFormat::eR16u:
			return getBasicType( sampledType< ImageFormat::eR16u > );
		case ImageFormat::eR8u:
			return getBasicType( sampledType< ImageFormat::eR8u > );
		default:
			AST_Failure( "getSampledType: Unsupported ImageFormat" );
			return nullptr;
		}
	}

	TypePtr TypesCache::getTexelType( ImageFormat format )
	{
		switch ( format )
		{
		case ImageFormat::eUnknown:
			return getBasicType( texelType< ImageFormat::eUnknown > );
		case ImageFormat::eRgba32f:
			return getBasicType( texelType< ImageFormat::eRgba32f > );
		case ImageFormat::eRgba16f:
			return getBasicType( texelType< ImageFormat::eRgba16f > );
		case ImageFormat::eRg32f:
			return getBasicType( texelType< ImageFormat::eRg32f > );
		case ImageFormat::eRg16f:
			return getBasicType( texelType< ImageFormat::eRg16f > );
		case ImageFormat::eR32f:
			return getBasicType( texelType< ImageFormat::eR32f > );
		case ImageFormat::eR16f:
			return getBasicType( texelType< ImageFormat::eR16f > );
		case ImageFormat::eRgba32i:
			return getBasicType( texelType< ImageFormat::eRgba32i > );
		case ImageFormat::eRgba16i:
			return getBasicType( texelType< ImageFormat::eRgba16i > );
		case ImageFormat::eRgba8i:
			return getBasicType( texelType< ImageFormat::eRgba8i > );
		case ImageFormat::eRg32i:
			return getBasicType( texelType< ImageFormat::eRg32i > );
		case ImageFormat::eRg16i:
			return getBasicType( texelType< ImageFormat::eRg16i > );
		case ImageFormat::eRg8i:
			return getBasicType( texelType< ImageFormat::eRg8i > );
		case ImageFormat::eR32i:
			return getBasicType( texelType< ImageFormat::eR32i > );
		case ImageFormat::eR16i:
			return getBasicType( texelType< ImageFormat::eR16i > );
		case ImageFormat::eR8i:
			return getBasicType( texelType< ImageFormat::eR8i > );
		case ImageFormat::eRgba32u:
			return getBasicType( texelType< ImageFormat::eRgba32u > );
		case ImageFormat::eRgba16u:
			return getBasicType( texelType< ImageFormat::eRgba16u > );
		case ImageFormat::eRgba8u:
			return getBasicType( texelType< ImageFormat::eRgba8u > );
		case ImageFormat::eRg32u:
			return getBasicType( texelType< ImageFormat::eRg32u > );
		case ImageFormat::eRg16u:
			return getBasicType( texelType< ImageFormat::eRg16u > );
		case ImageFormat::eRg8u:
			return getBasicType( texelType< ImageFormat::eRg8u > );
		case ImageFormat::eR32u:
			return getBasicType( texelType< ImageFormat::eR32u > );
		case ImageFormat::eR16u:
			return getBasicType( texelType< ImageFormat::eR16u > );
		case ImageFormat::eR8u:
			return getBasicType( texelType< ImageFormat::eR8u > );
		default:
			AST_Failure( "getTexelType: Unsupported ImageFormat" );
			return nullptr;
		}
	}

	FunctionPtr TypesCache::getFunction( TypePtr returnType
		, var::VariableList parameters )
	{
		return m_function.getType( std::move( returnType )
			, std::move( parameters ) );
	}

	StructPtr TypesCache::getStruct( MemoryLayout layout
		, std::string const & name )
	{
		return m_struct.getType( layout, name );
	}

	ArrayPtr TypesCache::getArray( TypePtr type
		, uint32_t arraySize )
	{
		return m_array.getType( type, arraySize );
	}

	TypePtr TypesCache::getMemberType( TypePtr type
		, Struct & parent
		, uint32_t memberIndex )
	{
		return type->getMemberType( parent, memberIndex );
	}

	Type const * TypesCache::getNonMemberType( TypePtr type )
	{
		return type->getNonMemberType();
	}

	TypePtr TypesCache::getPointerType( TypePtr pointerType, Storage storage )
	{
		return m_pointer.getType( pointerType, storage );
	}

	//*************************************************************************
}
