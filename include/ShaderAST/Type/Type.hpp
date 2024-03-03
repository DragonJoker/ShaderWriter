/*
See LICENSE file in root folder
*/
#ifndef ___AST_Type_H___
#define ___AST_Type_H___
#pragma once

#include "ShaderAST/ShaderASTPrerequisites.hpp"

namespace ast::type
{
	static uint32_t constexpr NotMember = ~0u;
	enum class Kind
		: uint8_t
	{
		eUndefined,
		eVoid,
		eBoolean,
		eInt8,// Submitted to extension enabling
		eInt16,// Submitted to extension enabling
		eInt32,
		eInt64,// Submitted to extension enabling
		eUInt8,// Submitted to extension enabling
		eUInt16,// Submitted to extension enabling
		eUInt32,
		eUInt64,// Submitted to extension enabling
		eHalf,// Submitted to extension enabling
		eFloat,
		eDouble,
		eVec2B,
		eVec3B,
		eVec4B,
		eVec2I8,// Submitted to extension enabling
		eVec3I8,// Submitted to extension enabling
		eVec4I8,// Submitted to extension enabling
		eVec2I16,// Submitted to extension enabling
		eVec3I16,// Submitted to extension enabling
		eVec4I16,// Submitted to extension enabling
		eVec2I32,
		eVec3I32,
		eVec4I32,
		eVec2I64,// Submitted to extension enabling
		eVec3I64,// Submitted to extension enabling
		eVec4I64,// Submitted to extension enabling
		eVec2U8,// Submitted to extension enabling
		eVec3U8,// Submitted to extension enabling
		eVec4U8,// Submitted to extension enabling
		eVec2U16,// Submitted to extension enabling
		eVec3U16,// Submitted to extension enabling
		eVec4U16,// Submitted to extension enabling
		eVec2U32,
		eVec3U32,
		eVec4U32,
		eVec2U64,// Submitted to extension enabling
		eVec3U64,// Submitted to extension enabling
		eVec4U64,// Submitted to extension enabling
		eVec2H,// Submitted to extension enabling
		eVec4H,// Submitted to extension enabling
		eVec2F,
		eVec3F,
		eVec4F,
		eVec2D,
		eVec3D,
		eVec4D,
		eMat2x2F,
		eMat2x3F,
		eMat2x4F,
		eMat3x2F,
		eMat3x3F,
		eMat3x4F,
		eMat4x2F,
		eMat4x3F,
		eMat4x4F,
		eMat2x2D,
		eMat2x3D,
		eMat2x4D,
		eMat3x2D,
		eMat3x3D,
		eMat3x4D,
		eMat4x2D,
		eMat4x3D,
		eMat4x4D,
		eBasicTypesMax = eMat4x4D,
		eArray,
		eFunction,
		eStruct,
		eSampler,
		eImage,
		eCombinedImage,
		eSampledImage,
		eAccelerationStructure,// Submitted to extension enabling
		eRayPayload,// Submitted to extension enabling
		eCallableData,// Submitted to extension enabling
		eHitAttribute,// Submitted to extension enabling
		eRayDesc,// Submitted to extension enabling
		ePointer,
		eGeometryInput,
		eGeometryOutput,
		eTessellationInputPatch,
		eTessellationOutputPatch,
		eTessellationControlInput,
		eTessellationControlOutput,
		eTessellationEvaluationInput,
		eFragmentInput,
		eComputeInput,
		eMeshVertexOutput,
		eMeshPrimitiveOutput,
		eTaskPayloadNV,
		eTaskPayload,
		eTaskPayloadInNV,
		eTaskPayloadIn,
		eCount,
		eInt = eInt32,
		eUInt = eUInt32,
		eVec2I = eVec2I32,
		eVec3I = eVec3I32,
		eVec4I = eVec4I32,
		eVec2U = eVec2U32,
		eVec3U = eVec3U32,
		eVec4U = eVec4U32,
		eMin = eUndefined,
		eMax = eArray,
	};

	enum class Storage
	{
		eUniformConstant = 0,
		eInput = 1,
		eUniform = 2,
		eOutput = 3,
		eWorkgroup = 4,
		eCrossWorkgroup = 5,
		ePrivate = 6,
		eFunction = 7,
		eGeneric = 8,
		ePushConstant = 9,
		eAtomicCounter = 10,
		eImage = 11,
		eStorageBuffer = 12,
		eCallableData = 5328,
		eIncomingCallableData = 5329,
		eRayPayload = 5338,
		eHitAttribute = 5339,
		eIncomingRayPayload = 5342,
		eShaderRecordBuffer = 5343,
		ePhysicalStorageBuffer = 5349,
		eTaskPayloadWorkgroup = 5402,
		eCodeSection = 5605,
		eMax = 0x7fffffff,
	};

	enum class MemorySemanticsMask : uint32_t
	{
		eNone = 0,
		eAcquire = 0x00000002,
		eRelease = 0x00000004,
		eAcquireRelease = 0x00000008,
		eSequentiallyConsistent = 0x00000010,
		eUniformMemory = 0x00000040,
		eSubgroupMemory = 0x00000080,
		eWorkgroupMemory = 0x00000100,
		eCrossWorkgroupMemory = 0x00000200,
		eAtomicCounterMemory = 0x00000400,
		eImageMemory = 0x00000800,
		eOutputMemory = 0x00001000,
		eMakeAvailable = 0x00002000,
		eMakeVisible = 0x00004000,
		eVolatile = 0x00008000,
	};

	enum class Scope : uint32_t
	{
		eCrossDevice = 0,
		eDevice = 1,
		eWorkgroup = 2,
		eSubgroup = 3,
		eInvocation = 4,
		eQueueFamily = 5,
		eShaderCall = 6,
	};

	struct MemorySemantics
	{
		constexpr MemorySemantics()noexcept = default;

		explicit constexpr MemorySemantics( MemorySemanticsMask v )noexcept
			: value{ uint32_t( v ) }
		{
		}

		explicit constexpr MemorySemantics( unsigned int v )noexcept
			: value{ uint32_t( v ) }
		{
		}

		explicit constexpr MemorySemantics( unsigned long v )noexcept
			: value{ uint32_t( v ) }
		{
		}

		explicit constexpr operator uint32_t()const noexcept
		{
			return value;
		}

		uint32_t value{};
	};

	constexpr MemorySemantics operator|( MemorySemanticsMask lhs, MemorySemanticsMask rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) | uint32_t( rhs ) };
	}

	constexpr MemorySemantics operator|( MemorySemanticsMask lhs, MemorySemantics rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) | uint32_t( rhs ) };
	}

	constexpr MemorySemantics operator|( MemorySemantics lhs, MemorySemanticsMask rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) | uint32_t( rhs ) };
	}

	constexpr MemorySemantics operator|( MemorySemantics lhs, MemorySemantics rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) | uint32_t( rhs ) };
	}

	constexpr MemorySemantics operator&( MemorySemanticsMask lhs, MemorySemanticsMask rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) & uint32_t( rhs ) };
	}

	constexpr MemorySemantics operator&( MemorySemanticsMask lhs, MemorySemantics rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) & uint32_t( rhs ) };
	}

	constexpr MemorySemantics operator&( MemorySemantics lhs, MemorySemanticsMask rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) & uint32_t( rhs ) };
	}

	constexpr MemorySemantics operator&( MemorySemantics lhs, MemorySemantics rhs )noexcept
	{
		return MemorySemantics{ uint32_t( lhs ) & uint32_t( rhs ) };
	}

	constexpr bool operator==( MemorySemanticsMask lhs, MemorySemanticsMask rhs )noexcept
	{
		return uint32_t( lhs ) == uint32_t( rhs );
	}

	constexpr bool operator==( MemorySemanticsMask lhs, MemorySemantics rhs )noexcept
	{
		return uint32_t( lhs ) == uint32_t( rhs );
	}

	constexpr bool operator==( MemorySemantics lhs, MemorySemanticsMask rhs )noexcept
	{
		return uint32_t( lhs ) == uint32_t( rhs );
	}

	constexpr bool operator==( MemorySemantics lhs, MemorySemantics rhs )noexcept
	{
		return uint32_t( lhs ) == uint32_t( rhs );
	}

	class Type
	{
	private:
		template< typename TypeT
			, typename CreatorT
			, typename HasherT >
		friend class TypeCache;
		friend class Struct;

	public:
		SDAST_API Type( TypesCache & typesCache
			, Kind kind );
		SDAST_API Type( TypesCache & typesCache
			, Struct * parent
			, uint32_t index
			, Type const & nonMbr );
		SDAST_API Type( TypesCache & typesCache
			, Struct & parent
			, uint32_t index
			, Type const & nonMbr );
		SDAST_API virtual TypePtr getMemberType( Struct & parent, uint32_t index )const;
		SDAST_API Type const * getNonMemberType()const;

		SDAST_API virtual ~Type()noexcept = default;
		SDAST_API Type( Type const & ) = delete;
		SDAST_API Type & operator=( Type const & ) = delete;

		Kind getRawKind()const
		{
			return m_kind;
		}

		virtual Kind getKind()const
		{
			return m_kind;
		}

		bool isMember()const
		{
			return m_index != NotMember;
		}

		uint32_t getIndex()const
		{
			return m_index;
		}

		Struct * getParent()const
		{
			return m_parent;
		}

		TypesCache & getTypesCache()const
		{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnull-dereference"
			assert( m_typesCache );
			return *m_typesCache;
#pragma GCC diagnostic pop
		}

	private:
		TypesCache * m_typesCache;
		Kind m_kind;
		Struct * m_parent;
		uint32_t m_index;
		Type const * m_nonMbr;
	};

	SDAST_API bool operator==( Type const & lhs, Type const & rhs );

	SDAST_API bool isBoolType( Kind kind );
	SDAST_API bool isUnsignedInt8Type( Kind kind );
	SDAST_API bool isSignedInt8Type( Kind kind );
	SDAST_API bool isUnsignedInt16Type( Kind kind );
	SDAST_API bool isSignedInt16Type( Kind kind );
	SDAST_API bool isUnsignedInt32Type( Kind kind );
	SDAST_API bool isSignedInt32Type( Kind kind );
	SDAST_API bool isUnsignedInt64Type( Kind kind );
	SDAST_API bool isSignedInt64Type( Kind kind );
	SDAST_API bool isUnsignedIntType( Kind kind );
	SDAST_API bool isSignedIntType( Kind kind );
	SDAST_API bool isHalfType( Kind kind );
	SDAST_API bool isFloatType( Kind kind );
	SDAST_API bool isDoubleType( Kind kind );
	SDAST_API bool isScalarType( Kind kind );
	SDAST_API bool isScalarType( TypePtr type );
	SDAST_API bool isVectorType( Kind kind );
	SDAST_API bool isVectorType( TypePtr type );
	SDAST_API bool isMatrixType( Kind kind );
	SDAST_API bool isMatrixType( TypePtr type );
	SDAST_API bool isArrayType( Kind kind );
	SDAST_API bool isArrayType( TypePtr type );
	SDAST_API bool isStructType( Kind kind );
	SDAST_API bool isStructType( Type const & type );
	SDAST_API bool isStructType( TypePtr type );
	SDAST_API bool isPointerType( Kind kind );
	SDAST_API bool isPointerType( TypePtr type );
	SDAST_API bool isSamplerType( Kind kind );
	SDAST_API bool isSamplerType( TypePtr type );
	SDAST_API bool isSampledImageType( Kind kind );
	SDAST_API bool isSampledImageType( TypePtr type );
	SDAST_API bool isImageType( Kind kind );
	SDAST_API bool isImageType( TypePtr type );
	SDAST_API bool isTextureType( Kind kind );
	SDAST_API bool isTextureType( TypePtr type );
	SDAST_API bool isAccelerationStructureType( Kind kind );
	SDAST_API bool isAccelerationStructureType( TypePtr type );
	SDAST_API bool isHitAttributeType( Kind kind );
	SDAST_API bool isHitAttributeType( TypePtr type );
	SDAST_API bool isRayPayloadType( Kind kind );
	SDAST_API bool isRayPayloadType( TypePtr type );
	SDAST_API bool isCallableDataType( Kind kind );
	SDAST_API bool isCallableDataType( TypePtr type );
	SDAST_API bool isOpaqueType( Kind kind );
	SDAST_API bool isOpaqueType( TypePtr type );
	/**
	*\remarks
	*	Returns count * arraySize in case of arrays.
	*/
	SDAST_API uint32_t getComponentCount( Kind kind );
	SDAST_API uint32_t getComponentCount( Type const & type );
	SDAST_API uint32_t getComponentCount( TypePtr const & type );
	/**
	*\remarks
	*	Returns \p kind if it is not a matrix or vector type.
	*/
	SDAST_API Kind getComponentType( Kind kind );
	SDAST_API Kind getComponentType( Type const & type );
	SDAST_API Kind getComponentType( TypePtr const & type );
	SDAST_API Kind getScalarType( Kind kind );
	SDAST_API expr::CompositeType getCompositeType( Kind kind );
	SDAST_API Type const & getNonArrayType( Type const & type );
	SDAST_API TypePtr getNonArrayType( TypePtr type );
	SDAST_API Kind getNonArrayKind( Type const & type );
	SDAST_API Kind getNonArrayKind( TypePtr type );
	SDAST_API Type const & getNonArrayTypeRec( Type const & type );
	SDAST_API TypePtr getNonArrayTypeRec( TypePtr type );
	SDAST_API Kind getNonArrayKindRec( Type const & type );
	SDAST_API Kind getNonArrayKindRec( TypePtr type );
	SDAST_API uint32_t getArraySize( Type const & type );
	SDAST_API uint32_t getArraySize( TypePtr type );

	SDAST_API bool isWrapperType( Type const & type );
	SDAST_API bool isWrapperType( TypePtr type );
	SDAST_API Type const & unwrapType( Type const & type );
	SDAST_API TypePtr unwrapType( TypePtr type );

	template< typename T >
	inline size_t hashCombine( size_t & hash
		, T const & rhs )noexcept
	{
		const uint64_t kMul = 0x9ddfea08eb382d69ULL;
		auto seed = hash;

		std::hash< T > hasher;
		uint64_t a = ( hasher( rhs ) ^ seed ) * kMul;
		a ^= ( a >> 47 );

		uint64_t b = ( seed ^ a ) * kMul;
		b ^= ( b >> 47 );

		hash = std::size_t( b * kMul );
		return hash;
	}
}

#endif
