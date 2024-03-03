/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/Type.hpp"

#include "ShaderAST/Type/ImageConfiguration.hpp"
#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

#include <algorithm>

namespace ast::type
{
	//*************************************************************************

	Type::Type( TypesCache & typesCache
		, Kind kind )
		: m_typesCache{ &typesCache }
		, m_kind{ kind }
		, m_parent{ nullptr }
		, m_index{ NotMember }
		, m_nonMbr{ nullptr }
	{
	}

	Type::Type( TypesCache & typesCache
		, Struct * parent
		, uint32_t index
		, Type const & nonMbr )
		: m_typesCache{ &typesCache }
		, m_kind{ nonMbr.getKind() }
		, m_parent{ parent }
		, m_index{ index }
		, m_nonMbr{ &nonMbr }
	{
	}

	Type::Type( TypesCache & typesCache
		, Struct & parent
		, uint32_t index
		, Type const & nonMbr )
		: Type{ typesCache, &parent, index, nonMbr }
	{
	}

	TypePtr Type::getMemberType( Struct & parent, uint32_t index )const
	{
		return std::make_shared< Type >( *m_typesCache, parent, index, *this );
	}

	Type const * Type::getNonMemberType()const
	{
		if ( isMember() )
		{
			assert( m_nonMbr );
			return m_nonMbr;
		}

		return this;
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

	bool isUnsignedInt8Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eUInt8:
		case Kind::eVec2U8:
		case Kind::eVec3U8:
		case Kind::eVec4U8:
			return true;

		default:
			return false;
		}
	}

	bool isSignedInt8Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eInt8:
		case Kind::eVec2I8:
		case Kind::eVec3I8:
		case Kind::eVec4I8:
			return true;

		default:
			return false;
		}
	}

	bool isUnsignedInt16Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eUInt16:
		case Kind::eVec2U16:
		case Kind::eVec3U16:
		case Kind::eVec4U16:
			return true;

		default:
			return false;
		}
	}

	bool isSignedInt16Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eInt16:
		case Kind::eVec2I16:
		case Kind::eVec3I16:
		case Kind::eVec4I16:
			return true;

		default:
			return false;
		}
	}

	bool isUnsignedInt32Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eUInt32:
		case Kind::eVec2U32:
		case Kind::eVec3U32:
		case Kind::eVec4U32:
			return true;

		default:
			return false;
		}
	}

	bool isSignedInt32Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eInt32:
		case Kind::eVec2I32:
		case Kind::eVec3I32:
		case Kind::eVec4I32:
			return true;

		default:
			return false;
		}
	}

	bool isUnsignedInt64Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eUInt64:
		case Kind::eVec2U64:
		case Kind::eVec3U64:
		case Kind::eVec4U64:
			return true;

		default:
			return false;
		}
	}

	bool isSignedInt64Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eInt64:
		case Kind::eVec2I64:
		case Kind::eVec3I64:
		case Kind::eVec4I64:
			return true;

		default:
			return false;
		}
	}

	bool isUnsignedIntType( Kind kind )
	{
		return isUnsignedInt8Type( kind )
			|| isUnsignedInt16Type( kind )
			|| isUnsignedInt32Type( kind )
			|| isUnsignedInt64Type( kind );
	}

	bool isSignedIntType( Kind kind )
	{
		return isSignedInt8Type( kind )
			|| isSignedInt16Type( kind )
			|| isSignedInt32Type( kind )
			|| isSignedInt64Type( kind );
	}

	bool isHalfType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eHalf:
		case Kind::eVec2H:
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
		case Kind::eInt8:
		case Kind::eInt16:
		case Kind::eInt32:
		case Kind::eInt64:
		case Kind::eUInt8:
		case Kind::eUInt16:
		case Kind::eUInt32:
		case Kind::eUInt64:
		case Kind::eFloat:
		case Kind::eDouble:
		case Kind::eHalf:
			return true;

		default:
			return false;
		}
	}

	bool isScalarType( TypePtr type )
	{
		return isScalarType( type->getKind() );
	}

	bool isVectorType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
		case Kind::eVec2I8:
		case Kind::eVec3I8:
		case Kind::eVec4I8:
		case Kind::eVec2I16:
		case Kind::eVec3I16:
		case Kind::eVec4I16:
		case Kind::eVec2I32:
		case Kind::eVec3I32:
		case Kind::eVec4I32:
		case Kind::eVec2I64:
		case Kind::eVec3I64:
		case Kind::eVec4I64:
		case Kind::eVec2U8:
		case Kind::eVec3U8:
		case Kind::eVec4U8:
		case Kind::eVec2U16:
		case Kind::eVec3U16:
		case Kind::eVec4U16:
		case Kind::eVec2U32:
		case Kind::eVec3U32:
		case Kind::eVec4U32:
		case Kind::eVec2U64:
		case Kind::eVec3U64:
		case Kind::eVec4U64:
		case Kind::eVec2F:
		case Kind::eVec3F:
		case Kind::eVec4F:
		case Kind::eVec2D:
		case Kind::eVec3D:
		case Kind::eVec4D:
		case Kind::eVec2H:
		case Kind::eVec4H:
			return true;

		default:
			return false;
		}
	}

	bool isVectorType( TypePtr type )
	{
		return isVectorType( type->getKind() );
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

	bool isMatrixType( TypePtr type )
	{
		return isMatrixType( type->getKind() );
	}

	bool isArrayType( Kind kind )
	{
		return kind == Kind::eArray;
	}

	bool isArrayType( TypePtr type )
	{
		return isArrayType( type->getKind() );
	}

	bool isPointerType( Kind kind )
	{
		return kind == Kind::ePointer;
	}

	bool isPointerType( TypePtr type )
	{
		return isPointerType( type->getKind() );
	}

	bool isStructType( Kind kind )
	{
		return kind == Kind::eStruct;
	}

	bool isStructType( type::Type const & ptype )
	{
		auto type = &ptype;

		while ( type->getRawKind() != type::Kind::eStruct
			&& type->getRawKind() != type::Kind::eRayDesc )
		{
			if ( type->getRawKind() == type::Kind::ePointer )
			{
				type = static_cast< type::Pointer const & >( *type ).getPointerType().get();
			}
			else if ( type->getRawKind() == type::Kind::eRayPayload )
			{
				type = static_cast< type::RayPayload const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eCallableData )
			{
				type = static_cast< type::CallableData const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eHitAttribute )
			{
				type = static_cast< type::HitAttribute const & >( *type ).getDataType().get();
			}
			else if ( type->getRawKind() == type::Kind::eFragmentInput )
			{
				type = static_cast< type::FragmentInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eGeometryInput )
			{
				type = static_cast< type::GeometryInput const & >( *type ).getType().get();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return isStructType( static_cast< type::Array const & >( *type ).getType() );
				}
			}
			else if ( type->getRawKind() == type::Kind::eGeometryOutput )
			{
				type = static_cast< type::GeometryOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eComputeInput )
			{
				type = static_cast< type::ComputeInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationInputPatch )
			{
				type = static_cast< type::TessellationInputPatch const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationOutputPatch )
			{
				type = static_cast< type::TessellationOutputPatch const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlInput )
			{
				type = static_cast< type::TessellationControlInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTessellationControlOutput )
			{
				type = static_cast< type::TessellationControlOutput const & >( *type ).getType().get();

				if ( type->getRawKind() == type::Kind::eArray )
				{
					return isStructType( static_cast< type::Array const & >( *type ).getType() );
				}
			}
			else if ( type->getRawKind() == type::Kind::eTessellationEvaluationInput )
			{
				type = static_cast< type::TessellationEvaluationInput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eMeshVertexOutput )
			{
				type = static_cast< type::MeshVertexOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eMeshPrimitiveOutput )
			{
				type = static_cast< type::MeshPrimitiveOutput const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadNV )
			{
				type = static_cast< type::TaskPayloadNV const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayload )
			{
				type = static_cast< type::TaskPayload const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadInNV )
			{
				type = static_cast< type::TaskPayloadInNV const & >( *type ).getType().get();
			}
			else if ( type->getRawKind() == type::Kind::eTaskPayloadIn )
			{
				type = static_cast< type::TaskPayloadIn const & >( *type ).getType().get();
			}
			else
			{
				break;
			}
		}

		if ( type->getRawKind() == type::Kind::eStruct
			|| type->getRawKind() == type::Kind::eRayDesc )
		{
			return true;
		}

		return false;
	}

	bool isStructType( type::TypePtr type )
	{
		return isStructType( *type );
	}


	bool isSamplerType( Kind kind )
	{
		return kind == Kind::eSampler;
	}

	bool isSamplerType( TypePtr type )
	{
		return isSamplerType( type->getKind() );
	}

	bool isSampledImageType( Kind kind )
	{
		return kind == Kind::eSampledImage;
	}

	bool isSampledImageType( TypePtr type )
	{
		return isSampledImageType( type->getKind() );
	}

	bool isImageType( Kind kind )
	{
		return kind == Kind::eImage;
	}

	bool isImageType( TypePtr type )
	{
		return isImageType( type->getKind() );
	}

	bool isTextureType( Kind kind )
	{
		return kind == Kind::eCombinedImage;
	}

	bool isTextureType( TypePtr type )
	{
		return isTextureType( type->getKind() );
	}

	bool isAccelerationStructureType( Kind kind )
	{
		return kind == Kind::eAccelerationStructure;
	}

	bool isAccelerationStructureType( TypePtr type )
	{
		return isAccelerationStructureType( type->getKind() );
	}

	bool isHitAttributeType( Kind kind )
	{
		return kind == Kind::eRayPayload;
	}

	bool isHitAttributeType( TypePtr type )
	{
		return isHitAttributeType( type->getKind() );
	}

	bool isRayPayloadType( Kind kind )
	{
		return kind == Kind::eRayPayload;
	}

	bool isRayPayloadType( TypePtr type )
	{
		return isRayPayloadType( type->getKind() );
	}

	bool isCallableDataType( Kind kind )
	{
		return kind == Kind::eCallableData;
	}

	bool isCallableDataType( TypePtr type )
	{
		return isCallableDataType( type->getKind() );
	}

	bool isOpaqueType( TypePtr type )
	{
		if ( isArrayType( type->getKind() ) )
		{
			return isOpaqueType( static_cast< Array const & >( *type ).getType() );
		}

		if ( isPointerType( type->getKind() ) )
		{
			return isOpaqueType( static_cast< Pointer const & >( *type ).getPointerType() );
		}

		return isOpaqueType( type->getKind() );
	}

	bool isOpaqueType( Kind kind )
	{
		return isImageType( kind )
			|| isTextureType( kind )
			|| isSamplerType( kind )
			|| isAccelerationStructureType( kind );
	}

	uint32_t getComponentCount( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec2I8:
		case Kind::eVec2I16:
		case Kind::eVec2I32:
		case Kind::eVec2I64:
		case Kind::eVec2U8:
		case Kind::eVec2U16:
		case Kind::eVec2U32:
		case Kind::eVec2U64:
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
		case Kind::eVec3I8:
		case Kind::eVec3I16:
		case Kind::eVec3I32:
		case Kind::eVec3I64:
		case Kind::eVec3U8:
		case Kind::eVec3U16:
		case Kind::eVec3U32:
		case Kind::eVec3U64:
		case Kind::eVec3F:
		case Kind::eVec3D:
		case Kind::eMat3x2F:
		case Kind::eMat3x3F:
		case Kind::eMat3x4F:
		case Kind::eMat3x2D:
		case Kind::eMat3x3D:
		case Kind::eMat3x4D:
			return 3u;

		case Kind::eVec4B:
		case Kind::eVec4I8:
		case Kind::eVec4I16:
		case Kind::eVec4I32:
		case Kind::eVec4I64:
		case Kind::eVec4U8:
		case Kind::eVec4U16:
		case Kind::eVec4U32:
		case Kind::eVec4U64:
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

	uint32_t getComponentCount( Type const & type )
	{
		auto arraySize = getArraySize( type );
		return getComponentCount( getNonArrayKind( type ) )
			* ( arraySize ? arraySize : 1u );
	}

	uint32_t getComponentCount( TypePtr const & type )
	{
		return getComponentCount( *type );
	}

	Kind getComponentType( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec3B:
		case Kind::eVec4B:
			return Kind::eBoolean;

		case Kind::eVec2I8:
		case Kind::eVec3I8:
		case Kind::eVec4I8:
			return Kind::eInt8;

		case Kind::eVec2I16:
		case Kind::eVec3I16:
		case Kind::eVec4I16:
			return Kind::eInt16;

		case Kind::eVec2I32:
		case Kind::eVec3I32:
		case Kind::eVec4I32:
			return Kind::eInt32;

		case Kind::eVec2I64:
		case Kind::eVec3I64:
		case Kind::eVec4I64:
			return Kind::eInt64;

		case Kind::eVec2U8:
		case Kind::eVec3U8:
		case Kind::eVec4U8:
			return Kind::eUInt8;

		case Kind::eVec2U16:
		case Kind::eVec3U16:
		case Kind::eVec4U16:
			return Kind::eUInt16;

		case Kind::eVec2U32:
		case Kind::eVec3U32:
		case Kind::eVec4U32:
			return Kind::eUInt32;

		case Kind::eVec2U64:
		case Kind::eVec3U64:
		case Kind::eVec4U64:
			return Kind::eUInt64;

		case Kind::eVec2H:
		case Kind::eVec4H:
			return Kind::eHalf;

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

		default:
			return kind;
		}
	}

	Kind getComponentType( Type const & type )
	{
		return getComponentType( getNonArrayKind( type ) );
	}

	Kind getComponentType( TypePtr const & type )
	{
		return getComponentType( *type );
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
		expr::CompositeType result{ expr::CompositeType::eVec4 };

		switch ( kind )
		{
		case Kind::eVec2B:
		case Kind::eVec2I8:
		case Kind::eVec2I16:
		case Kind::eVec2I32:
		case Kind::eVec2I64:
		case Kind::eVec2U8:
		case Kind::eVec2U16:
		case Kind::eVec2U32:
		case Kind::eVec2U64:
		case Kind::eVec2F:
		case Kind::eVec2D:
		case Kind::eVec2H:
			result = expr::CompositeType::eVec2;
			break;
		case Kind::eVec3B:
		case Kind::eVec3I8:
		case Kind::eVec3I16:
		case Kind::eVec3I32:
		case Kind::eVec3I64:
		case Kind::eVec3U8:
		case Kind::eVec3U16:
		case Kind::eVec3U32:
		case Kind::eVec3U64:
		case Kind::eVec3F:
		case Kind::eVec3D:
			result = expr::CompositeType::eVec3;
			break;
		case Kind::eVec4B:
		case Kind::eVec4I8:
		case Kind::eVec4I16:
		case Kind::eVec4I32:
		case Kind::eVec4I64:
		case Kind::eVec4U8:
		case Kind::eVec4U16:
		case Kind::eVec4U32:
		case Kind::eVec4U64:
		case Kind::eVec4F:
		case Kind::eVec4D:
		case Kind::eVec4H:
			result = expr::CompositeType::eVec4;
			break;
		case Kind::eMat2x2F:
		case Kind::eMat2x2D:
			result = expr::CompositeType::eMat2x2;
			break;
		case Kind::eMat2x3F:
		case Kind::eMat2x3D:
			result = expr::CompositeType::eMat2x3;
			break;
		case Kind::eMat2x4F:
		case Kind::eMat2x4D:
			result = expr::CompositeType::eMat2x4;
			break;
		case Kind::eMat3x2F:
		case Kind::eMat3x2D:
			result = expr::CompositeType::eMat3x2;
			break;
		case Kind::eMat3x3F:
		case Kind::eMat3x3D:
			result = expr::CompositeType::eMat3x3;
			break;
		case Kind::eMat3x4F:
		case Kind::eMat3x4D:
			result = expr::CompositeType::eMat3x4;
			break;
		case Kind::eMat4x2F:
		case Kind::eMat4x2D:
			result = expr::CompositeType::eMat4x2;
			break;
		case Kind::eMat4x3F:
		case Kind::eMat4x3D:
			result = expr::CompositeType::eMat4x3;
			break;
		case Kind::eMat4x4F:
		case Kind::eMat4x4D:
			result = expr::CompositeType::eMat4x4;
			break;
		default:
			break;
		}

		return result;
	}

	Type const & getNonArrayType( Type const & type )
	{
		Type const * result{};

		switch ( type.getKind() )
		{
		case Kind::eArray:
			result = static_cast< Array const & >( type ).getType().get();
			break;
		default:
			result = &type;
			break;
		}

		return *result;
	}

	TypePtr getNonArrayType( TypePtr type )
	{
		TypePtr result;
		switch ( type->getKind() )
		{
		case Kind::eArray:
			result = std::static_pointer_cast< Array >( type )->getType();
			break;
		default:
			result = type;
			break;
		}

		return result;
	}

	Kind getNonArrayKind( Type const & type )
	{
		return getNonArrayType( type ).getKind();
	}

	Kind getNonArrayKind( TypePtr type )
	{
		return getNonArrayKind( *type );
	}

	Type const & getNonArrayTypeRec( Type const & type )
	{
		auto * tmp = &type;

		while ( tmp->getKind() == type::Kind::eArray )
		{
			tmp = static_cast< Array const & >( *tmp ).getType().get();
		}

		return *tmp;
	}

	TypePtr getNonArrayTypeRec( TypePtr type )
	{
		auto tmp = type;

		while ( tmp->getKind() == type::Kind::eArray )
		{
			tmp = static_cast< Array const & >( *tmp ).getType();
		}

		return tmp;
	}

	Kind getNonArrayKindRec( Type const & type )
	{
		return getNonArrayTypeRec( type ).getKind();
	}

	Kind getNonArrayKindRec( TypePtr type )
	{
		return getNonArrayKindRec( *type );
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

	bool isWrapperType( Type const & type )
	{
		switch ( type.getRawKind() )
		{
		case Kind::eRayPayload:
		case Kind::eCallableData:
		case Kind::eHitAttribute:
			return true;
		default:
			return false;
		}
	}

	bool isWrapperType( TypePtr type )
	{
		return isWrapperType( *type );
	}

	Type const & unwrapType( Type const & type )
	{
		Type const * result{};

		switch ( type.getRawKind() )
		{
		case Kind::eRayPayload:
			result = static_cast< RayPayload const & >( type ).getDataType().get();
			break;
		case Kind::eCallableData:
			result = static_cast< CallableData const & >( type ).getDataType().get();
			break;
		case Kind::eHitAttribute:
			result = static_cast< HitAttribute const & >( type ).getDataType().get();
			break;
		default:
			result = &type;
			break;
		}

		return *result;
	}

	TypePtr unwrapType( TypePtr type )
	{
		TypePtr result;

		switch ( type->getRawKind() )
		{
		case Kind::eRayPayload:
			result = static_cast< RayPayload const & >( *type ).getDataType();
			break;
		case Kind::eCallableData:
			result = static_cast< CallableData const & >( *type ).getDataType();
			break;
		case Kind::eHitAttribute:
			result = static_cast< HitAttribute const & >( *type ).getDataType();
			break;
		default:
			result = type;
			break;
		}

		return result;
	}

	//*************************************************************************
}
