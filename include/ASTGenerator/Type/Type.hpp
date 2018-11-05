/*
See LICENSE file in root folder
*/
#ifndef ___AST_Type_H___
#define ___AST_Type_H___
#pragma once

#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

#include <map>

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
		eSamplerBufferF,
		eSampler1DF,
		eSampler2DF,
		eSampler3DF,
		eSamplerCubeF,
		eSampler2DRectF,
		eSampler1DArrayF,
		eSampler2DArrayF,
		eSamplerCubeArrayF,
		eSampler1DShadowF,
		eSampler2DShadowF,
		eSamplerCubeShadowF,
		eSampler2DRectShadowF,
		eSampler1DArrayShadowF,
		eSampler2DArrayShadowF,
		eSamplerCubeArrayShadowF,
		eSamplerBufferI,
		eSampler1DI,
		eSampler2DI,
		eSampler3DI,
		eSamplerCubeI,
		eSampler2DRectI,
		eSampler1DArrayI,
		eSampler2DArrayI,
		eSamplerCubeArrayI,
		eSamplerBufferU,
		eSampler1DU,
		eSampler2DU,
		eSampler3DU,
		eSamplerCubeU,
		eSampler2DRectU,
		eSampler1DArrayU,
		eSampler2DArrayU,
		eSamplerCubeArrayU,
		eImageBufferF,
		eImage1DF,
		eImage2DF,
		eImage3DF,
		eImageCubeF,
		eImage2DRectF,
		eImage1DArrayF,
		eImage2DArrayF,
		eImageCubeArrayF,
		eImage2DMSF,
		eImage2DMSArrayF,
		eImageBufferI,
		eImage1DI,
		eImage2DI,
		eImage3DI,
		eImageCubeI,
		eImage2DRectI,
		eImage1DArrayI,
		eImage2DArrayI,
		eImageCubeArrayI,
		eImage2DMSI,
		eImage2DMSArrayI,
		eImageBufferU,
		eImage1DU,
		eImage2DU,
		eImage3DU,
		eImageCubeU,
		eImage2DRectU,
		eImage1DArrayU,
		eImage2DArrayU,
		eImageCubeArrayU,
		eImage2DMSU,
		eImage2DMSArrayU,
		eCount,
		eHalf,// Internal only, never use this !!!
		eVec2H,// Internal only, never use this !!!
		eVec3H,// Internal only, never use this !!!
		eVec4H,// Internal only, never use this !!!
		eMin = eUndefined,
		eMax = eImage2DMSArrayU,
	};

	class TypeCache;

	class Type
	{
	private:
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
	TypePtr getSamplerBufferF( uint32_t arraySize = NotArray );
	TypePtr getSampler1DF( uint32_t arraySize = NotArray );
	TypePtr getSampler2DF( uint32_t arraySize = NotArray );
	TypePtr getSampler3DF( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeF( uint32_t arraySize = NotArray );
	TypePtr getSampler2DRectF( uint32_t arraySize = NotArray );
	TypePtr getSampler1DArrayF( uint32_t arraySize = NotArray );
	TypePtr getSampler2DArrayF( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeArrayF( uint32_t arraySize = NotArray );
	TypePtr getSampler1DShadowF( uint32_t arraySize = NotArray );
	TypePtr getSampler2DShadowF( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeShadowF( uint32_t arraySize = NotArray );
	TypePtr getSampler2DRectShadowF( uint32_t arraySize = NotArray );
	TypePtr getSampler1DArrayShadowF( uint32_t arraySize = NotArray );
	TypePtr getSampler2DArrayShadowF( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeArrayShadowF( uint32_t arraySize = NotArray );
	TypePtr getSamplerBufferI( uint32_t arraySize = NotArray );
	TypePtr getSampler1DI( uint32_t arraySize = NotArray );
	TypePtr getSampler2DI( uint32_t arraySize = NotArray );
	TypePtr getSampler3DI( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeI( uint32_t arraySize = NotArray );
	TypePtr getSampler2DRectI( uint32_t arraySize = NotArray );
	TypePtr getSampler1DArrayI( uint32_t arraySize = NotArray );
	TypePtr getSampler2DArrayI( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeArrayI( uint32_t arraySize = NotArray );
	TypePtr getSamplerBufferU( uint32_t arraySize = NotArray );
	TypePtr getSampler1DU( uint32_t arraySize = NotArray );
	TypePtr getSampler2DU( uint32_t arraySize = NotArray );
	TypePtr getSampler3DU( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeU( uint32_t arraySize = NotArray );
	TypePtr getSampler2DRectU( uint32_t arraySize = NotArray );
	TypePtr getSampler1DArrayU( uint32_t arraySize = NotArray );
	TypePtr getSampler2DArrayU( uint32_t arraySize = NotArray );
	TypePtr getSamplerCubeArrayU( uint32_t arraySize = NotArray );
	TypePtr getImageBufferF( uint32_t arraySize = NotArray );
	TypePtr getImage1DF( uint32_t arraySize = NotArray );
	TypePtr getImage2DF( uint32_t arraySize = NotArray );
	TypePtr getImage3DF( uint32_t arraySize = NotArray );
	TypePtr getImageCubeF( uint32_t arraySize = NotArray );
	TypePtr getImage2DRectF( uint32_t arraySize = NotArray );
	TypePtr getImage1DArrayF( uint32_t arraySize = NotArray );
	TypePtr getImage2DArrayF( uint32_t arraySize = NotArray );
	TypePtr getImageCubeArrayF( uint32_t arraySize = NotArray );
	TypePtr getImage2DMSF( uint32_t arraySize = NotArray );
	TypePtr getImage2DMSArrayF( uint32_t arraySize = NotArray );
	TypePtr getImageBufferI( uint32_t arraySize = NotArray );
	TypePtr getImage1DI( uint32_t arraySize = NotArray );
	TypePtr getImage2DI( uint32_t arraySize = NotArray );
	TypePtr getImage3DI( uint32_t arraySize = NotArray );
	TypePtr getImageCubeI( uint32_t arraySize = NotArray );
	TypePtr getImage2DRectI( uint32_t arraySize = NotArray );
	TypePtr getImage1DArrayI( uint32_t arraySize = NotArray );
	TypePtr getImage2DArrayI( uint32_t arraySize = NotArray );
	TypePtr getImageCubeArrayI( uint32_t arraySize = NotArray );
	TypePtr getImage2DMSI( uint32_t arraySize = NotArray );
	TypePtr getImage2DMSArrayI( uint32_t arraySize = NotArray );
	TypePtr getImageBufferU( uint32_t arraySize = NotArray );
	TypePtr getImage1DU( uint32_t arraySize = NotArray );
	TypePtr getImage2DU( uint32_t arraySize = NotArray );
	TypePtr getImage3DU( uint32_t arraySize = NotArray );
	TypePtr getImageCubeU( uint32_t arraySize = NotArray );
	TypePtr getImage2DRectU( uint32_t arraySize = NotArray );
	TypePtr getImage1DArrayU( uint32_t arraySize = NotArray );
	TypePtr getImage2DArrayU( uint32_t arraySize = NotArray );
	TypePtr getImageCubeArrayU( uint32_t arraySize = NotArray );
	TypePtr getImage2DMSU( uint32_t arraySize = NotArray );
	TypePtr getImage2DMSArrayU( uint32_t arraySize = NotArray );

	TypePtr makeType( Kind kind, uint32_t arraySize = NotArray );

	bool isScalarType( Kind kind );
	bool isVectorType( Kind kind );
	bool isMatrixType( Kind kind );
	bool isSamplerType( Kind kind );
	bool isImageType( Kind kind );
	uint32_t getComponentCount( Kind kind );
	Kind getComponentType( Kind kind );
	Kind getVectorType( Kind kind );

	enum class Ternary
	{
		eTrue,
		eFalse,
		eDontCare,
	};

	enum class AccessKind
	{
		eRead,
		eWrite,
		eReadWrite,
	};

	enum class ImageDim
	{
		e1D,
		e2D,
		e3D,
		eCube,
		eRect,
		eBuffer,
	};

	struct ImageConfig
	{
		ImageDim dimension;
		Ternary isDepth;
		Ternary isSampled;
		bool isArrayed;
		bool isMS;
		uint32_t componentCount;
		Kind componentType;
		AccessKind accessKind;
	};

	ImageConfig getImageConfig( Kind kind );
}

#endif
