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
		eCount,
		eMin = eUndefined,
		eMax = eArray,
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
		Type( TypesCache & cache
			, Kind kind );
		Type( TypesCache & cache
			, Struct * parent
			, uint32_t index
			, Kind kind );
		Type( TypesCache & cache
			, Struct & parent
			, uint32_t index
			, Kind kind );
		virtual TypePtr getMemberType( Struct & parent, uint32_t index )const;

		virtual ~Type();

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
			return *m_cache;
		}

	private:
		TypesCache * m_cache;
		Kind m_kind;
		Struct * m_parent;
		uint32_t m_index;
	};

	bool operator==( Type const & lhs, Type const & rhs );

	bool isBoolType( Kind kind );
	bool isUnsignedIntType( Kind kind );
	bool isSignedIntType( Kind kind );
	bool isHalfType( Kind kind );
	bool isFloatType( Kind kind );
	bool isDoubleType( Kind kind );
	bool isScalarType( Kind kind );
	bool isVectorType( Kind kind );
	bool isMatrixType( Kind kind );
	bool isArrayType( Kind kind );
	bool isStructType( Kind kind );
	bool isSamplerType( Kind kind );
	bool isImageType( Kind kind );
	bool isSampledImageType( Kind kind );
	/**
	*\remarks
	*	Returns count * arraySize in case of arrays.
	*/
	uint32_t getComponentCount( Kind kind );
	uint32_t getComponentCount( Type const & type );
	uint32_t getComponentCount( TypePtr const & type );
	/**
	*\remarks
	*	Returns \p kind if it is not a matrix or vector type.
	*/
	Kind getComponentType( Kind kind );
	Kind getComponentType( Type const & type );
	Kind getComponentType( TypePtr const & type );
	Kind getScalarType( Kind kind );
	expr::CompositeType getCompositeType( Kind kind );
	Type const & getNonArrayType( Type const & type );
	TypePtr getNonArrayType( TypePtr type );
	Kind getNonArrayKind( Type const & type );
	Kind getNonArrayKind( TypePtr type );
	Type const & getNonArrayTypeRec( Type const & type );
	TypePtr getNonArrayTypeRec( TypePtr type );
	Kind getNonArrayKindRec( Type const & type );
	Kind getNonArrayKindRec( TypePtr type );
	uint32_t getArraySize( Type const & type );
	uint32_t getArraySize( TypePtr type );
}

#endif
