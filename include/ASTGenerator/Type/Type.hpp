/*
See LICENSE file in root folder
*/
#ifndef ___AST_Type_H___
#define ___AST_Type_H___
#pragma once

#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

namespace ast::type
{
	static uint32_t constexpr NotArray = 0u;
	static uint32_t constexpr UnknownArraySize = ~( 0u );
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
		template< typename TypeT, typename CreatorT >
		friend class TypeCache;
		friend class Struct;

	protected:
		Type( Kind kind
			, uint32_t arraySize = NotArray );
		Type( Struct * parent
			, uint32_t index
			, Kind kind
			, uint32_t arraySize = NotArray );

	public:
		virtual ~Type();

		inline Kind getKind()const
		{
			return m_kind;
		}

		inline uint32_t getArraySize()const
		{
			return m_arraySize;
		}

		inline bool isMember()const
		{
			return m_index != ~( 0u );
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
		uint32_t m_arraySize;
		Struct * m_parent;
		uint32_t m_index;
	};

	TypePtr getUndefined( uint32_t arraySize = NotArray );
	TypePtr getVoid( uint32_t arraySize = NotArray );
	TypePtr getFunction( uint32_t arraySize = NotArray );
	TypePtr getBool( uint32_t arraySize = NotArray );
	TypePtr getInt( uint32_t arraySize = NotArray );
	TypePtr getUInt( uint32_t arraySize = NotArray );
	TypePtr getFloat( uint32_t arraySize = NotArray );
	TypePtr getDouble( uint32_t arraySize = NotArray );
	TypePtr getVec2Type( Kind kind, uint32_t arraySize = NotArray );
	TypePtr getVec3Type( Kind kind, uint32_t arraySize = NotArray );
	TypePtr getVec4Type( Kind kind, uint32_t arraySize = NotArray );
	TypePtr getVec2B( uint32_t arraySize = NotArray );
	TypePtr getVec3B( uint32_t arraySize = NotArray );
	TypePtr getVec4B( uint32_t arraySize = NotArray );
	TypePtr getVec2I( uint32_t arraySize = NotArray );
	TypePtr getVec3I( uint32_t arraySize = NotArray );
	TypePtr getVec4I( uint32_t arraySize = NotArray );
	TypePtr getVec2U( uint32_t arraySize = NotArray );
	TypePtr getVec3U( uint32_t arraySize = NotArray );
	TypePtr getVec4U( uint32_t arraySize = NotArray );
	TypePtr getVec2F( uint32_t arraySize = NotArray );
	TypePtr getVec3F( uint32_t arraySize = NotArray );
	TypePtr getVec4F( uint32_t arraySize = NotArray );
	TypePtr getVec2D( uint32_t arraySize = NotArray );
	TypePtr getVec3D( uint32_t arraySize = NotArray );
	TypePtr getVec4D( uint32_t arraySize = NotArray );
	TypePtr getMat2x2F( uint32_t arraySize = NotArray );
	TypePtr getMat2x3F( uint32_t arraySize = NotArray );
	TypePtr getMat2x4F( uint32_t arraySize = NotArray );
	TypePtr getMat3x2F( uint32_t arraySize = NotArray );
	TypePtr getMat3x3F( uint32_t arraySize = NotArray );
	TypePtr getMat3x4F( uint32_t arraySize = NotArray );
	TypePtr getMat4x2F( uint32_t arraySize = NotArray );
	TypePtr getMat4x3F( uint32_t arraySize = NotArray );
	TypePtr getMat4x4F( uint32_t arraySize = NotArray );
	TypePtr getMat2x2D( uint32_t arraySize = NotArray );
	TypePtr getMat2x3D( uint32_t arraySize = NotArray );
	TypePtr getMat2x4D( uint32_t arraySize = NotArray );
	TypePtr getMat3x2D( uint32_t arraySize = NotArray );
	TypePtr getMat3x3D( uint32_t arraySize = NotArray );
	TypePtr getMat3x4D( uint32_t arraySize = NotArray );
	TypePtr getMat4x2D( uint32_t arraySize = NotArray );
	TypePtr getMat4x3D( uint32_t arraySize = NotArray );
	TypePtr getMat4x4D( uint32_t arraySize = NotArray );
	TypePtr getConstantsBuffer( uint32_t arraySize = NotArray );
	TypePtr getShaderBuffer( uint32_t arraySize = NotArray );
	TypePtr getSampler( uint32_t arraySize = NotArray );

	TypePtr getImage( ImageConfiguration config
		, uint32_t arraySize = NotArray );
	TypePtr getSampledImage( ImageConfiguration config
		, uint32_t arraySize = NotArray );

	TypePtr makeType( Kind kind
		, uint32_t arraySize = NotArray );

	bool isScalarType( Kind kind );
	bool isVectorType( Kind kind );
	bool isMatrixType( Kind kind );
	bool isSamplerType( Kind kind );
	bool isImageType( Kind kind );
	bool isSampledImageType( Kind kind );
	uint32_t getComponentCount( Kind kind );
	Kind getComponentType( Kind kind );
}

#endif
