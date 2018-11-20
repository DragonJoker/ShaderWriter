/*
See LICENSE file in root folder
*/
#ifndef ___AST_Type_H___
#define ___AST_Type_H___
#pragma once

#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

namespace ast::type
{
	static uint32_t constexpr NotMember = ~( 0u );
	enum class Kind
		: uint8_t
	{
		eUndefined,
		eVoid,
		eFunction,
		eStruct,
		eBoolean,
		eInt,
		eUInt,
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
		eConstantsBuffer,
		eShaderBuffer,
		eSampler,
		eImage,
		eSampledImage,
		eArray,
		eCount,
		eHalf,// Internal only, never use this !!!
		eVec2H,// Internal only, never use this !!!
		eVec3H,// Internal only, never use this !!!
		eVec4H,// Internal only, never use this !!!
		eMin = eUndefined,
		eMax = eSampledImage,
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
		Type( Kind kind );
		Type( Struct * parent
			, uint32_t index
			, Kind kind );

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

	private:
		Kind m_kind;
		Struct * m_parent;
		uint32_t m_index;
	};

	bool operator==( Type const & lhs, Type const & rhs );

	TypePtr getUndefined();
	TypePtr getVoid();
	TypePtr getFunction();
	TypePtr getBool();
	TypePtr getInt();
	TypePtr getUInt();
	TypePtr getFloat();
	TypePtr getDouble();
	TypePtr getVec2Type( Kind kind );
	TypePtr getVec3Type( Kind kind );
	TypePtr getVec4Type( Kind kind );
	TypePtr getVec2B();
	TypePtr getVec3B();
	TypePtr getVec4B();
	TypePtr getVec2I();
	TypePtr getVec3I();
	TypePtr getVec4I();
	TypePtr getVec2U();
	TypePtr getVec3U();
	TypePtr getVec4U();
	TypePtr getVec2F();
	TypePtr getVec3F();
	TypePtr getVec4F();
	TypePtr getVec2D();
	TypePtr getVec3D();
	TypePtr getVec4D();
	TypePtr getMat2x2F();
	TypePtr getMat2x3F();
	TypePtr getMat2x4F();
	TypePtr getMat3x2F();
	TypePtr getMat3x3F();
	TypePtr getMat3x4F();
	TypePtr getMat4x2F();
	TypePtr getMat4x3F();
	TypePtr getMat4x4F();
	TypePtr getMat2x2D();
	TypePtr getMat2x3D();
	TypePtr getMat2x4D();
	TypePtr getMat3x2D();
	TypePtr getMat3x3D();
	TypePtr getMat3x4D();
	TypePtr getMat4x2D();
	TypePtr getMat4x3D();
	TypePtr getMat4x4D();
	TypePtr getConstantsBuffer();
	TypePtr getShaderBuffer();
	TypePtr getSampler();

	TypePtr getImage( ImageConfiguration config );
	TypePtr getSampledImage( ImageConfiguration config );
	TypePtr getSampler( bool comparison );

	TypePtr makeType( Kind kind );

	bool isBoolType( Kind kind );
	bool isUnsignedIntType( Kind kind );
	bool isSignedIntType( Kind kind );
	bool isHalfType( Kind kind );
	bool isFloatType( Kind kind );
	bool isDoubleType( Kind kind );
	bool isScalarType( Kind kind );
	bool isVectorType( Kind kind );
	bool isMatrixType( Kind kind );
	bool isSamplerType( Kind kind );
	bool isImageType( Kind kind );
	bool isSampledImageType( Kind kind );
	uint32_t getComponentCount( Kind kind );
	Kind getComponentType( Kind kind );
	Kind getScalarType( Kind kind );
	expr::CompositeType getCompositeType( Kind kind );
	Kind getNonArrayKindRec( Type const & type );
	Kind getNonArrayKindRec( TypePtr type );
	Kind getNonArrayKind( Type const & type );
	Kind getNonArrayKind( TypePtr type );
	uint32_t getArraySize( Type const & type );
	uint32_t getArraySize( TypePtr type );
}

#endif
