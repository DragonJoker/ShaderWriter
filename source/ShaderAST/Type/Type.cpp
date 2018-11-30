/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/Type.hpp"

#include "ShaderAST/Type/ImageConfiguration.hpp"
#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeImage.hpp"
#include "ShaderAST/Type/TypeSampledImage.hpp"
#include "ShaderAST/Type/TypeSampler.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

#include <algorithm>

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

	Type::Type( Struct * parent
		, uint32_t index
		, Kind kind )
		: m_kind{ kind }
		, m_parent{ parent }
		, m_index{ index }
	{
	}

	Type::Type( Kind kind )
		: Type{ nullptr, NotMember, kind }
	{
	}

	Type::~Type()
	{
	}

	//*************************************************************************

	bool operator==( Type const & lhs, Type const & rhs )
	{
		auto result = lhs.getKind() == rhs.getKind()
			&& getArraySize( lhs ) == getArraySize( rhs );

		if ( result )
		{
			result = getSize( lhs, MemoryLayout::eStd430 ) == getSize( rhs, MemoryLayout::eStd430 );
		}

		return result;
	}

	//*************************************************************************

	TypePtr getUndefined()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eUndefined );
		return cache;
	}

	TypePtr getVoid()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVoid );
		return cache;
	}

	TypePtr getFunction()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eFunction );
		return cache;
	}

	TypePtr getBool()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eBoolean );
		return cache;
	}

	TypePtr getInt()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eInt );
		return cache;
	}

	TypePtr getUInt()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eUInt );
		return cache;
	}

	TypePtr getFloat()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eFloat );
		return cache;
	}

	TypePtr getDouble()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eDouble );
		return cache;
	}

	TypePtr getVec2Type( Kind kind )
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

	TypePtr getVec3Type( Kind kind )
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

	TypePtr getVec4Type( Kind kind )
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

	TypePtr getVec2B()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec2B );
		return cache;
	}

	TypePtr getVec3B()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec3B );
		return cache;
	}

	TypePtr getVec4B()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec4B );
		return cache;
	}

	TypePtr getVec2I()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec2I );
		return cache;
	}

	TypePtr getVec3I()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec3I );
		return cache;
	}

	TypePtr getVec4I()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec4I );
		return cache;
	}

	TypePtr getVec2U()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec2U );
		return cache;
	}

	TypePtr getVec3U()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec3U );
		return cache;
	}

	TypePtr getVec4U()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec4U );
		return cache;
	}

	TypePtr getVec2F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec2F );
		return cache;
	}

	TypePtr getVec3F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec3F );
		return cache;
	}

	TypePtr getVec4F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec4F );
		return cache;
	}

	TypePtr getVec2D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec2D );
		return cache;
	}

	TypePtr getVec3D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec3D );
		return cache;
	}

	TypePtr getVec4D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eVec4D );
		return cache;
	}

	TypePtr getMat2x2F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat2x2F );
		return cache;
	}

	TypePtr getMat2x3F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat2x3F );
		return cache;
	}

	TypePtr getMat2x4F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat2x4F );
		return cache;
	}

	TypePtr getMat3x2F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat3x2F );
		return cache;
	}

	TypePtr getMat3x3F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat3x3F );
		return cache;
	}

	TypePtr getMat3x4F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat3x4F );
		return cache;
	}

	TypePtr getMat4x2F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat4x2F );
		return cache;
	}

	TypePtr getMat4x3F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat4x3F );
		return cache;
	}

	TypePtr getMat4x4F()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat4x4F );
		return cache;
	}

	TypePtr getMat2x2D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat2x2D );
		return cache;
	}

	TypePtr getMat2x3D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat2x3D );
		return cache;
	}

	TypePtr getMat2x4D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat2x4D );
		return cache;
	}

	TypePtr getMat3x2D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat3x2D );
		return cache;
	}

	TypePtr getMat3x3D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat3x3D );
		return cache;
	}

	TypePtr getMat3x4D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat3x4D );
		return cache;
	}

	TypePtr getMat4x2D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat4x2D );
		return cache;
	}

	TypePtr getMat4x3D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat4x3D );
		return cache;
	}

	TypePtr getMat4x4D()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eMat4x4D );
		return cache;
	}

	TypePtr getConstantsBuffer()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eConstantsBuffer );
		return cache;
	}

	TypePtr getShaderBuffer()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eShaderBuffer );
		return cache;
	}

	TypePtr getSampler()
	{
		static TypePtr cache = std::make_shared< Type >( Kind::eSampler );
		return cache;
	}

	TypePtr getImage( ImageConfiguration config )
	{
		static auto cache{ makeTypeCache< Image >( makeImageType
			, []( ImageConfiguration const & config )
			{
				return getHash( config );
			} ) };
		return cache.getType( config );
	}

	TypePtr getSampledImage( ImageConfiguration config )
	{
		static auto cache{ makeTypeCache< SampledImage >( makeSampledImageType
			, []( ImageConfiguration const & config )
			{
				return getHash( config );
			} ) };
		return cache.getType( config );
	}

	TypePtr getSampler( bool comparison )
	{
		static auto cache{ makeTypeCache< Sampler >( makeSamplerType
			, []( bool comparison )
			{
				return comparison ? 1u : 0u;
			} ) };
		return cache.getType( comparison );
	}

	//*************************************************************************

	TypePtr makeType( Kind kind )
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

	bool isBoolType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
			return true;

		default:
			return false;
		}
	}

	bool isUnsignedIntType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eUInt:
		case Kind::eVec2U:
		case Kind::eVec3U:
		case Kind::eVec4U:
			return true;

		default:
			return false;
		}
	}

	bool isSignedIntType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eInt:
		case Kind::eVec2I:
		case Kind::eVec3I:
		case Kind::eVec4I:
			return true;

		default:
			return false;
		}
	}

	bool isHalfType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eHalf:
		case Kind::eVec2H:
		case Kind::eVec3H:
		case Kind::eVec4H:
			return true;

		default:
			return false;
		}
	}

	bool isFloatType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eFloat:
		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
		case Kind::eMat2x2F:
		case Kind::eMat2x3F:
		case Kind::eMat2x4F:
		case Kind::eMat3x2F:
		case Kind::eMat3x3F:
		case Kind::eMat3x4F:
		case Kind::eMat4x2F:
		case Kind::eMat4x3F:
		case Kind::eMat4x4F:
			return true;

		default:
			return false;
		}
	}

	bool isDoubleType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eDouble:
		case Kind::eVec2D:
		case Kind::eVec3D:
		case Kind::eVec4D:
		case Kind::eMat2x2D:
		case Kind::eMat2x3D:
		case Kind::eMat2x4D:
		case Kind::eMat3x2D:
		case Kind::eMat3x3D:
		case Kind::eMat3x4D:
		case Kind::eMat4x2D:
		case Kind::eMat4x3D:
		case Kind::eMat4x4D:
			return true;

		default:
			return false;
		}
	}

	bool isScalarType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
		case Kind::eInt:
		case Kind::eUInt:
		case Kind::eFloat:
		case Kind::eDouble:
		case Kind::eHalf:
			return true;

		default:
			return false;
		}
	}

	bool isVectorType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
		case Kind::eVec2I:
		case Kind::eVec3I:
		case Kind::eVec4I:
		case Kind::eVec2U:
		case Kind::eVec3U:
		case Kind::eVec4U:
		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
		case Kind::eVec2D:
		case Kind::eVec3D:
		case Kind::eVec4D:
		case Kind::eVec2H:
		case Kind::eVec3H:
		case Kind::eVec4H:
			return true;

		default:
			return false;
		}
	}

	bool isMatrixType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eMat2x2F:
		case Kind::eMat2x3F:
		case Kind::eMat2x4F:
		case Kind::eMat3x2F:
		case Kind::eMat3x3F:
		case Kind::eMat3x4F:
		case Kind::eMat4x2F:
		case Kind::eMat4x3F:
		case Kind::eMat4x4F:
		case Kind::eMat2x2D:
		case Kind::eMat2x3D:
		case Kind::eMat2x4D:
		case Kind::eMat3x2D:
		case Kind::eMat3x3D:
		case Kind::eMat3x4D:
		case Kind::eMat4x2D:
		case Kind::eMat4x3D:
		case Kind::eMat4x4D:
			return true;

		default:
			return false;
		}
	}

	bool isSamplerType( Kind kind )
	{
		return kind == Kind::eSampler;
	}

	bool isImageType( Kind kind )
	{
		return kind == Kind::eImage;
	}

	bool isSampledImageType( Kind kind )
	{
		return kind == Kind::eSampledImage;
	}

	uint32_t getComponentCount( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec2I:
		case Kind::eVec2U:
		case Kind::eVec2F:
		case Kind::eVec2D:
		case Kind::eVec2H:
		case Kind::eMat2x2F:
		case Kind::eMat2x3F:
		case Kind::eMat2x4F:
		case Kind::eMat2x2D:
		case Kind::eMat2x3D:
		case Kind::eMat2x4D:
			return 2u;

		case Kind::eVec3B:
		case Kind::eVec3I:
		case Kind::eVec3U:
		case Kind::eVec3F:
		case Kind::eVec3D:
		case Kind::eVec3H:
		case Kind::eMat3x2F:
		case Kind::eMat3x3F:
		case Kind::eMat3x4F:
		case Kind::eMat3x2D:
		case Kind::eMat3x3D:
		case Kind::eMat3x4D:
			return 3u;

		case Kind::eVec4B:
		case Kind::eVec4I:
		case Kind::eVec4U:
		case Kind::eVec4F:
		case Kind::eVec4D:
		case Kind::eVec4H:
		case Kind::eMat4x2F:
		case Kind::eMat4x3F:
		case Kind::eMat4x4F:
		case Kind::eMat4x2D:
		case Kind::eMat4x3D:
		case Kind::eMat4x4D:
			return 4u;

		default:
			return 1u;
		}
	}

	Kind getComponentType( Kind kind )
	{
		assert( isMatrixType( kind )
			|| isVectorType( kind ) );

		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
			return Kind::eBoolean;

		case Kind::eVec2I:
		case Kind::eVec3I:
		case Kind::eVec4I:
			return Kind::eInt;

		case Kind::eVec2U:
		case Kind::eVec3U:
		case Kind::eVec4U:
			return Kind::eUInt;

		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
			return Kind::eFloat;

		case Kind::eMat2x2F:
		case Kind::eMat3x2F:
		case Kind::eMat4x2F:
			return Kind::eVec2F;

		case Kind::eMat2x3F:
		case Kind::eMat3x3F:
		case Kind::eMat4x3F:
			return Kind::eVec3F;

		case Kind::eMat2x4F:
		case Kind::eMat3x4F:
		case Kind::eMat4x4F:
			return Kind::eVec4F;

		case Kind::eVec2D:
		case Kind::eVec3D:
		case Kind::eVec4D:
			return Kind::eDouble;

		case Kind::eMat2x2D:
		case Kind::eMat3x2D:
		case Kind::eMat4x2D:
			return Kind::eVec2D;

		case Kind::eMat2x3D:
		case Kind::eMat3x3D:
		case Kind::eMat4x3D:
			return Kind::eVec3D;

		case Kind::eMat2x4D:
		case Kind::eMat3x4D:
		case Kind::eMat4x4D:
			return Kind::eVec4D;

		case Kind::eVec2H:
		case Kind::eVec3H:
		case Kind::eVec4H:
			return Kind::eHalf;

		default:
			assert( "Unsupported type::Kind" );
			return Kind::eUndefined;
		}
	}

	Kind getScalarType( Kind kind )
	{
		if ( isScalarType( kind ) )
		{
			return kind;
		}

		auto parent = getComponentType( kind );

		if ( isVectorType( kind ) )
		{
			return parent;
		}

		return getComponentType( parent );
	}

	expr::CompositeType getCompositeType( Kind kind )
	{
		assert( isVectorType( kind )
			|| isMatrixType( kind ) );

		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec2I:
		case Kind::eVec2U:
		case Kind::eVec2F:
		case Kind::eVec2D:
		case Kind::eVec2H:
			return expr::CompositeType::eVec2;

		case Kind::eVec3B:
		case Kind::eVec3I:
		case Kind::eVec3U:
		case Kind::eVec3F:
		case Kind::eVec3D:
		case Kind::eVec3H:
			return expr::CompositeType::eVec3;

		case Kind::eVec4B:
		case Kind::eVec4I:
		case Kind::eVec4U:
		case Kind::eVec4F:
		case Kind::eVec4D:
		case Kind::eVec4H:
			return expr::CompositeType::eVec4;

		case Kind::eMat2x2F:
		case Kind::eMat2x2D:
			return expr::CompositeType::eMat2x2;

		case Kind::eMat2x3F:
		case Kind::eMat2x3D:
			return expr::CompositeType::eMat2x3;

		case Kind::eMat2x4F:
		case Kind::eMat2x4D:
			return expr::CompositeType::eMat2x4;

		case Kind::eMat3x2F:
		case Kind::eMat3x2D:
			return expr::CompositeType::eMat3x2;

		case Kind::eMat3x3F:
		case Kind::eMat3x3D:
			return expr::CompositeType::eMat3x3;

		case Kind::eMat3x4F:
		case Kind::eMat3x4D:
			return expr::CompositeType::eMat3x4;

		case Kind::eMat4x2F:
		case Kind::eMat4x2D:
			return expr::CompositeType::eMat4x2;

		case Kind::eMat4x3F:
		case Kind::eMat4x3D:
			return expr::CompositeType::eMat4x3;

		case Kind::eMat4x4F:
		case Kind::eMat4x4D:
			return expr::CompositeType::eMat4x4;

		default:
			assert( "Unsupported type::Kind" );
			return expr::CompositeType::eVec4;
		}
	}

	Kind getNonArrayKindRec( Type const & type )
	{
		auto result = type.getKind();
		auto * tmp = &type;

		while ( tmp->getKind() == type::Kind::eArray )
		{
			tmp = static_cast< Array const & >( *tmp ).getType().get();
		}

		return tmp->getKind();
	}

	Kind getNonArrayKindRec( TypePtr type )
	{
		return getNonArrayKindRec( *type );
	}

	Kind getNonArrayKind( Type const & type )
	{
		return type.getKind() == type::Kind::eArray
			? static_cast< Array const & >( type ).getType()->getKind()
			: type.getKind();
	}

	Kind getNonArrayKind( TypePtr type )
	{
		return getNonArrayKind( *type );
	}

	uint32_t getArraySize( Type const & type )
	{
		return type.getKind() == type::Kind::eArray
			? static_cast< type::Array const & >( type ).getArraySize()
			: NotArray;
	}

	uint32_t getArraySize( TypePtr type )
	{
		return getArraySize( *type );
	}

	//*************************************************************************
}
