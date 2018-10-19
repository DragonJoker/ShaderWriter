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
		eMin = eUndefined,
		eMax = eImageCubeArrayU,
	};

	class Type
	{
	public:

	public:
		Type( Kind kind
			, uint32_t arraySize = NotArray );
		virtual ~Type();

		inline Kind getKind()const
		{
			return m_kind;
		}

		inline uint32_t getArraySize()const
		{
			return m_arraySize;
		}

	private:
		Kind m_kind;
		uint32_t m_arraySize;
	};

	inline TypePtr makeType( Kind kind
		, uint32_t arraySize = NotArray )
	{
		return std::make_shared< Type >( kind, arraySize );
	}

	inline TypePtr getUndefined()
	{
		static TypePtr const result = makeType( Kind::eUndefined );
		return result;
	}

	inline TypePtr getVoid()
	{
		static TypePtr const result = makeType( Kind::eVoid );
		return result;
	}

	inline TypePtr getFunction()
	{
		static TypePtr const result = makeType( Kind::eFunction );
		return result;
	}

	inline TypePtr getBool()
	{
		static TypePtr const result = makeType( Kind::eBoolean );
		return result;
	}

	inline TypePtr getInt()
	{
		static TypePtr const result = makeType( Kind::eInt );
		return result;
	}

	inline TypePtr getUInt()
	{
		static TypePtr const result = makeType( Kind::eUInt );
		return result;
	}

	inline TypePtr getFloat()
	{
		static TypePtr const result = makeType( Kind::eFloat );
		return result;
	}

	inline TypePtr getDouble()
	{
		static TypePtr const result = makeType( Kind::eDouble );
		return result;
	}

	inline TypePtr getVec2B()
	{
		static TypePtr const result = makeType( Kind::eVec2B );
		return result;
	}

	inline TypePtr getVec3B()
	{
		static TypePtr const result = makeType( Kind::eVec3B );
		return result;
	}

	inline TypePtr getVec4B()
	{
		static TypePtr const result = makeType( Kind::eVec4B );
		return result;
	}

	inline TypePtr getVec2I()
	{
		static TypePtr const result = makeType( Kind::eVec2I );
		return result;
	}

	inline TypePtr getVec3I()
	{
		static TypePtr const result = makeType( Kind::eVec3I );
		return result;
	}

	inline TypePtr getVec4I()
	{
		static TypePtr const result = makeType( Kind::eVec4I );
		return result;
	}

	inline TypePtr getVec2U()
	{
		static TypePtr const result = makeType( Kind::eVec2U );
		return result;
	}

	inline TypePtr getVec3U()
	{
		static TypePtr const result = makeType( Kind::eVec3U );
		return result;
	}

	inline TypePtr getVec4U()
	{
		static TypePtr const result = makeType( Kind::eVec4U );
		return result;
	}

	inline TypePtr getVec2F()
	{
		static TypePtr const result = makeType( Kind::eVec2F );
		return result;
	}

	inline TypePtr getVec3F()
	{
		static TypePtr const result = makeType( Kind::eVec3F );
		return result;
	}

	inline TypePtr getVec4F()
	{
		static TypePtr const result = makeType( Kind::eVec4F );
		return result;
	}

	inline TypePtr getVec2D()
	{
		static TypePtr const result = makeType( Kind::eVec2D );
		return result;
	}

	inline TypePtr getVec3D()
	{
		static TypePtr const result = makeType( Kind::eVec3D );
		return result;
	}

	inline TypePtr getVec4D()
	{
		static TypePtr const result = makeType( Kind::eVec4D );
		return result;
	}

	inline TypePtr getMat2x2F()
	{
		static TypePtr const result = makeType( Kind::eMat2x2F );
		return result;
	}

	inline TypePtr getMat2x3F()
	{
		static TypePtr const result = makeType( Kind::eMat2x3F );
		return result;
	}

	inline TypePtr getMat2x4F()
	{
		static TypePtr const result = makeType( Kind::eMat2x4F );
		return result;
	}

	inline TypePtr getMat3x2F()
	{
		static TypePtr const result = makeType( Kind::eMat3x2F );
		return result;
	}

	inline TypePtr getMat3x3F()
	{
		static TypePtr const result = makeType( Kind::eMat3x3F );
		return result;
	}

	inline TypePtr getMat3x4F()
	{
		static TypePtr const result = makeType( Kind::eMat3x4F );
		return result;
	}

	inline TypePtr getMat4x2F()
	{
		static TypePtr const result = makeType( Kind::eMat4x2F );
		return result;
	}

	inline TypePtr getMat4x3F()
	{
		static TypePtr const result = makeType( Kind::eMat4x3F );
		return result;
	}

	inline TypePtr getMat4x4F()
	{
		static TypePtr const result = makeType( Kind::eMat4x4F );
		return result;
	}

	inline TypePtr getMat2x2D()
	{
		static TypePtr const result = makeType( Kind::eMat2x2D );
		return result;
	}

	inline TypePtr getMat2x3D()
	{
		static TypePtr const result = makeType( Kind::eMat2x3D );
		return result;
	}

	inline TypePtr getMat2x4D()
	{
		static TypePtr const result = makeType( Kind::eMat2x4D );
		return result;
	}

	inline TypePtr getMat3x2D()
	{
		static TypePtr const result = makeType( Kind::eMat3x2D );
		return result;
	}

	inline TypePtr getMat3x3D()
	{
		static TypePtr const result = makeType( Kind::eMat3x3D );
		return result;
	}

	inline TypePtr getMat3x4D()
	{
		static TypePtr const result = makeType( Kind::eMat3x4D );
		return result;
	}

	inline TypePtr getMat4x2D()
	{
		static TypePtr const result = makeType( Kind::eMat4x2D );
		return result;
	}

	inline TypePtr getMat4x3D()
	{
		static TypePtr const result = makeType( Kind::eMat4x3D );
		return result;
	}

	inline TypePtr getMat4x4D()
	{
		static TypePtr const result = makeType( Kind::eMat4x4D );
		return result;
	}

	inline TypePtr getConstantsBuffer()
	{
		static TypePtr const result = makeType( Kind::eConstantsBuffer );
		return result;
	}

	inline TypePtr getShaderBuffer()
	{
		static TypePtr const result = makeType( Kind::eShaderBuffer );
		return result;
	}

	inline TypePtr getSamplerBufferF()
	{
		static TypePtr const result = makeType( Kind::eSamplerBufferF );
		return result;
	}

	inline TypePtr getSampler1DF()
	{
		static TypePtr const result = makeType( Kind::eSampler1DF );
		return result;
	}

	inline TypePtr getSampler2DF()
	{
		static TypePtr const result = makeType( Kind::eSampler2DF );
		return result;
	}

	inline TypePtr getSampler3DF()
	{
		static TypePtr const result = makeType( Kind::eSampler3DF );
		return result;
	}

	inline TypePtr getSamplerCubeF()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeF );
		return result;
	}

	inline TypePtr getSampler2DRectF()
	{
		static TypePtr const result = makeType( Kind::eSampler2DRectF );
		return result;
	}

	inline TypePtr getSampler1DArrayF()
	{
		static TypePtr const result = makeType( Kind::eSampler1DArrayF );
		return result;
	}

	inline TypePtr getSampler2DArrayF()
	{
		static TypePtr const result = makeType( Kind::eSampler2DArrayF );
		return result;
	}

	inline TypePtr getSamplerCubeArrayF()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeArrayF );
		return result;
	}

	inline TypePtr getSampler1DShadowF()
	{
		static TypePtr const result = makeType( Kind::eSampler1DShadowF );
		return result;
	}

	inline TypePtr getSampler2DShadowF()
	{
		static TypePtr const result = makeType( Kind::eSampler2DShadowF );
		return result;
	}

	inline TypePtr getSamplerCubeShadowF()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeShadowF );
		return result;
	}

	inline TypePtr getSampler2DRectShadowF()
	{
		static TypePtr const result = makeType( Kind::eSampler2DRectShadowF );
		return result;
	}

	inline TypePtr getSampler1DArrayShadowF()
	{
		static TypePtr const result = makeType( Kind::eSampler1DArrayShadowF );
		return result;
	}

	inline TypePtr getSampler2DArrayShadowF()
	{
		static TypePtr const result = makeType( Kind::eSampler2DArrayShadowF );
		return result;
	}

	inline TypePtr getSamplerCubeArrayShadowF()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeArrayShadowF );
		return result;
	}

	inline TypePtr getSamplerBufferI()
	{
		static TypePtr const result = makeType( Kind::eSamplerBufferI );
		return result;
	}

	inline TypePtr getSampler1DI()
	{
		static TypePtr const result = makeType( Kind::eSampler1DI );
		return result;
	}

	inline TypePtr getSampler2DI()
	{
		static TypePtr const result = makeType( Kind::eSampler2DI );
		return result;
	}

	inline TypePtr getSampler3DI()
	{
		static TypePtr const result = makeType( Kind::eSampler3DI );
		return result;
	}

	inline TypePtr getSamplerCubeI()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeI );
		return result;
	}

	inline TypePtr getSampler2DRectI()
	{
		static TypePtr const result = makeType( Kind::eSampler2DRectI );
		return result;
	}

	inline TypePtr getSampler1DArrayI()
	{
		static TypePtr const result = makeType( Kind::eSampler1DArrayI );
		return result;
	}

	inline TypePtr getSampler2DArrayI()
	{
		static TypePtr const result = makeType( Kind::eSampler2DArrayI );
		return result;
	}

	inline TypePtr getSamplerCubeArrayI()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeArrayI );
		return result;
	}

	inline TypePtr getSamplerBufferU()
	{
		static TypePtr const result = makeType( Kind::eSamplerBufferU );
		return result;
	}

	inline TypePtr getSampler1DU()
	{
		static TypePtr const result = makeType( Kind::eSampler1DU );
		return result;
	}

	inline TypePtr getSampler2DU()
	{
		static TypePtr const result = makeType( Kind::eSampler2DU );
		return result;
	}

	inline TypePtr getSampler3DU()
	{
		static TypePtr const result = makeType( Kind::eSampler3DU );
		return result;
	}

	inline TypePtr getSamplerCubeU()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeU );
		return result;
	}

	inline TypePtr getSampler2DRectU()
	{
		static TypePtr const result = makeType( Kind::eSampler2DRectU );
		return result;
	}

	inline TypePtr getSampler1DArrayU()
	{
		static TypePtr const result = makeType( Kind::eSampler1DArrayU );
		return result;
	}

	inline TypePtr getSampler2DArrayU()
	{
		static TypePtr const result = makeType( Kind::eSampler2DArrayU );
		return result;
	}

	inline TypePtr getSamplerCubeArrayU()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeArrayU );
		return result;
	}

	inline TypePtr getImageBufferF()
	{
		static TypePtr const result = makeType( Kind::eImageBufferF );
		return result;
	}

	inline TypePtr getImage1DF()
	{
		static TypePtr const result = makeType( Kind::eImage1DF );
		return result;
	}

	inline TypePtr getImage2DF()
	{
		static TypePtr const result = makeType( Kind::eImage2DF );
		return result;
	}

	inline TypePtr getImage3DF()
	{
		static TypePtr const result = makeType( Kind::eImage3DF );
		return result;
	}

	inline TypePtr getImageCubeF()
	{
		static TypePtr const result = makeType( Kind::eImageCubeF );
		return result;
	}

	inline TypePtr getImage2DRectF()
	{
		static TypePtr const result = makeType( Kind::eImage2DRectF );
		return result;
	}

	inline TypePtr getImage1DArrayF()
	{
		static TypePtr const result = makeType( Kind::eImage1DArrayF );
		return result;
	}

	inline TypePtr getImage2DArrayF()
	{
		static TypePtr const result = makeType( Kind::eImage2DArrayF );
		return result;
	}

	inline TypePtr getImageCubeArrayF()
	{
		static TypePtr const result = makeType( Kind::eImageCubeArrayF );
		return result;
	}

	inline TypePtr getImage2DMSF()
	{
		static TypePtr const result = makeType( Kind::eImage2DMSF );
		return result;
	}

	inline TypePtr getImage2DMSArrayF()
	{
		static TypePtr const result = makeType( Kind::eImage2DMSArrayF );
		return result;
	}

	inline TypePtr getImageBufferI()
	{
		static TypePtr const result = makeType( Kind::eImageBufferI );
		return result;
	}

	inline TypePtr getImage1DI()
	{
		static TypePtr const result = makeType( Kind::eImage1DI );
		return result;
	}

	inline TypePtr getImage2DI()
	{
		static TypePtr const result = makeType( Kind::eImage2DI );
		return result;
	}

	inline TypePtr getImage3DI()
	{
		static TypePtr const result = makeType( Kind::eImage3DI );
		return result;
	}

	inline TypePtr getImageCubeI()
	{
		static TypePtr const result = makeType( Kind::eImageCubeI );
		return result;
	}

	inline TypePtr getImage2DRectI()
	{
		static TypePtr const result = makeType( Kind::eImage2DRectI );
		return result;
	}

	inline TypePtr getImage1DArrayI()
	{
		static TypePtr const result = makeType( Kind::eImage1DArrayI );
		return result;
	}

	inline TypePtr getImage2DArrayI()
	{
		static TypePtr const result = makeType( Kind::eImage2DArrayI );
		return result;
	}

	inline TypePtr getImageCubeArrayI()
	{
		static TypePtr const result = makeType( Kind::eImageCubeArrayI );
		return result;
	}

	inline TypePtr getImage2DMSI()
	{
		static TypePtr const result = makeType( Kind::eImage2DMSI );
		return result;
	}

	inline TypePtr getImage2DMSArrayI()
	{
		static TypePtr const result = makeType( Kind::eImage2DMSArrayI );
		return result;
	}

	inline TypePtr getImageBufferU()
	{
		static TypePtr const result = makeType( Kind::eImageBufferU );
		return result;
	}

	inline TypePtr getImage1DU()
	{
		static TypePtr const result = makeType( Kind::eImage1DU );
		return result;
	}

	inline TypePtr getImage2DU()
	{
		static TypePtr const result = makeType( Kind::eImage2DU );
		return result;
	}

	inline TypePtr getImage3DU()
	{
		static TypePtr const result = makeType( Kind::eImage3DU );
		return result;
	}

	inline TypePtr getImageCubeU()
	{
		static TypePtr const result = makeType( Kind::eImageCubeU );
		return result;
	}

	inline TypePtr getImage2DRectU()
	{
		static TypePtr const result = makeType( Kind::eImage2DRectU );
		return result;
	}

	inline TypePtr getImage1DArrayU()
	{
		static TypePtr const result = makeType( Kind::eImage1DArrayU );
		return result;
	}

	inline TypePtr getImage2DArrayU()
	{
		static TypePtr const result = makeType( Kind::eImage2DArrayU );
		return result;
	}

	inline TypePtr getImageCubeArrayU()
	{
		static TypePtr const result = makeType( Kind::eImageCubeArrayU );
		return result;
	}

	inline TypePtr getImage2DMSU()
	{
		static TypePtr const result = makeType( Kind::eImage2DMSU );
		return result;
	}

	inline TypePtr getImage2DMSArrayU()
	{
		static TypePtr const result = makeType( Kind::eImage2DMSArrayU );
		return result;
	}
}

#endif
