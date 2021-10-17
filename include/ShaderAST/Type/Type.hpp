/*
See LICENSE file in root folder
*/
#ifndef ___AST_Type_H___
#define ___AST_Type_H___
#pragma once

#include "ShaderAST/ShaderASTPrerequisites.hpp"

namespace ast::type
{
	static uint32_t constexpr NotMember = ~( 0u );
	enum class Kind
		: uint8_t
	{
		eUndefined,
		eVoid,
		eBoolean,
		eInt,
		eUInt,
		eHalf,// Submitted to extension enabling
		eFloat,
		eDouble,
		eVec2B,
		eVec3B,
		eVec4B,
		eVec2I,
		eVec3I,
		eVec4I,
		eVec2U,
		eVec3U,
		eVec4U,
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
		eSampledImage,
		ePointer,
		eGeometryInput,
		eGeometryOutput,
		eCount,
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
		eCodeSection = 5605,
		eMax = 0x7fffffff,
	};

	class Type
	{
	private:
		template< typename TypeT
			, typename CreatorT
			, typename HasherT >
		friend class TypeCache;
		friend class Struct;

	public:
		SDAST_API Type( TypesCache & cache
			, Kind kind );
		SDAST_API Type( TypesCache & cache
			, Struct * parent
			, uint32_t index
			, Type const & nonMbr );
		SDAST_API Type( TypesCache & cache
			, Struct & parent
			, uint32_t index
			, Type const & nonMbr );
		SDAST_API virtual TypePtr getMemberType( Struct & parent, uint32_t index )const;
		SDAST_API Type const * getNonMemberType()const;

		SDAST_API virtual ~Type()noexcept = default;

		inline Kind getKind()const
		{
			return m_kind;
		}

		inline bool isMember()const
		{
			return m_index != NotMember;
		}

		inline uint32_t getIndex()const
		{
			return m_index;
		}

		inline Struct * getParent()const
		{
			return m_parent;
		}

		inline TypesCache & getCache()const
		{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnull-dereference"
			assert( m_cache );
			return *m_cache;
#pragma GCC diagnostic pop
		}

	private:
		TypesCache * m_cache;
		Kind m_kind;
		Struct * m_parent;
		uint32_t m_index;
		Type const * m_nonMbr;
	};

	SDAST_API bool operator==( Type const & lhs, Type const & rhs );

	SDAST_API bool isBoolType( Kind kind );
	SDAST_API bool isUnsignedIntType( Kind kind );
	SDAST_API bool isSignedIntType( Kind kind );
	SDAST_API bool isHalfType( Kind kind );
	SDAST_API bool isFloatType( Kind kind );
	SDAST_API bool isDoubleType( Kind kind );
	SDAST_API bool isScalarType( Kind kind );
	SDAST_API bool isVectorType( Kind kind );
	SDAST_API bool isMatrixType( Kind kind );
	SDAST_API bool isArrayType( Kind kind );
	SDAST_API bool isStructType( Kind kind );
	SDAST_API bool isPointerType( Kind kind );
	SDAST_API bool isSamplerType( Kind kind );
	SDAST_API bool isImageType( Kind kind );
	SDAST_API bool isSampledImageType( Kind kind );
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
}

#endif
