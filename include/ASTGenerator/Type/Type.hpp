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
		eVec2B,
		eVec3B,
		eVec4B,
		eVec2I,
		eVec3I,
		eVec4I,
		eVec2UI,
		eVec3UI,
		eVec4UI,
		eVec2F,
		eVec3F,
		eVec4F,
		eMat2x2B,
		eMat3x3B,
		eMat4x4B,
		eMat2x2I,
		eMat3x3I,
		eMat4x4I,
		eMat2x2UI,
		eMat3x3UI,
		eMat4x4UI,
		eMat2x2F,
		eMat3x3F,
		eMat4x4F,
		eConstantsBuffer,
		eShaderBuffer,
		eSamplerBuffer,
		eSampler1D,
		eSampler2D,
		eSampler3D,
		eSamplerCube,
		eSampler2DRect,
		eSampler1DArray,
		eSampler2DArray,
		eSamplerCubeArray,
		eSampler1DShadow,
		eSampler2DShadow,
		eSamplerCubeShadow,
		eSampler2DRectShadow,
		eSampler1DArrayShadow,
		eSampler2DArrayShadow,
		eSamplerCubeArrayShadow,
		eCount,
		eMin = eUndefined,
		eMax = eSamplerCubeArrayShadow,
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

	inline TypePtr getVec2UI()
	{
		static TypePtr const result = makeType( Kind::eVec2UI );
		return result;
	}

	inline TypePtr getVec3UI()
	{
		static TypePtr const result = makeType( Kind::eVec3UI );
		return result;
	}

	inline TypePtr getVec4UI()
	{
		static TypePtr const result = makeType( Kind::eVec4UI );
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

	inline TypePtr getMat2x2B()
	{
		static TypePtr const result = makeType( Kind::eMat2x2B );
		return result;
	}

	inline TypePtr getMat3x3B()
	{
		static TypePtr const result = makeType( Kind::eMat3x3B );
		return result;
	}

	inline TypePtr getMat4x4B()
	{
		static TypePtr const result = makeType( Kind::eMat4x4B );
		return result;
	}

	inline TypePtr getMat2x2I()
	{
		static TypePtr const result = makeType( Kind::eMat2x2I );
		return result;
	}

	inline TypePtr getMat3x3I()
	{
		static TypePtr const result = makeType( Kind::eMat3x3I );
		return result;
	}

	inline TypePtr getMat4x4I()
	{
		static TypePtr const result = makeType( Kind::eMat4x4I );
		return result;
	}

	inline TypePtr getMat2x2UI()
	{
		static TypePtr const result = makeType( Kind::eMat2x2UI );
		return result;
	}

	inline TypePtr getMat3x3UI()
	{
		static TypePtr const result = makeType( Kind::eMat3x3UI );
		return result;
	}

	inline TypePtr getMat4x4UI()
	{
		static TypePtr const result = makeType( Kind::eMat4x4UI );
		return result;
	}

	inline TypePtr getMat2x2F()
	{
		static TypePtr const result = makeType( Kind::eMat2x2F );
		return result;
	}

	inline TypePtr getMat3x3F()
	{
		static TypePtr const result = makeType( Kind::eMat3x3F );
		return result;
	}

	inline TypePtr getMat4x4F()
	{
		static TypePtr const result = makeType( Kind::eMat4x4F );
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

	inline TypePtr getSamplerBuffer()
	{
		static TypePtr const result = makeType( Kind::eSamplerBuffer );
		return result;
	}

	inline TypePtr getSampler1D()
	{
		static TypePtr const result = makeType( Kind::eSampler1D );
		return result;
	}

	inline TypePtr getSampler2D()
	{
		static TypePtr const result = makeType( Kind::eSampler2D );
		return result;
	}

	inline TypePtr getSampler3D()
	{
		static TypePtr const result = makeType( Kind::eSampler3D );
		return result;
	}

	inline TypePtr getSamplerCube()
	{
		static TypePtr const result = makeType( Kind::eSamplerCube );
		return result;
	}

	inline TypePtr getSampler2DRect()
	{
		static TypePtr const result = makeType( Kind::eSampler2DRect );
		return result;
	}

	inline TypePtr getSampler1DArray()
	{
		static TypePtr const result = makeType( Kind::eSampler1DArray );
		return result;
	}

	inline TypePtr getSampler2DArray()
	{
		static TypePtr const result = makeType( Kind::eSampler2DArray );
		return result;
	}

	inline TypePtr getSamplerCubeArray()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeArray );
		return result;
	}

	inline TypePtr getSampler1DShadow()
	{
		static TypePtr const result = makeType( Kind::eSampler1DShadow );
		return result;
	}

	inline TypePtr getSampler2DShadow()
	{
		static TypePtr const result = makeType( Kind::eSampler2DShadow );
		return result;
	}

	inline TypePtr getSamplerCubeShadow()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeShadow );
		return result;
	}

	inline TypePtr getSampler2DRectShadow()
	{
		static TypePtr const result = makeType( Kind::eSampler2DRectShadow );
		return result;
	}

	inline TypePtr getSampler1DArrayShadow()
	{
		static TypePtr const result = makeType( Kind::eSampler1DArrayShadow );
		return result;
	}

	inline TypePtr getSampler2DArrayShadow()
	{
		static TypePtr const result = makeType( Kind::eSampler2DArrayShadow );
		return result;
	}

	inline TypePtr getSamplerCubeArrayShadow()
	{
		static TypePtr const result = makeType( Kind::eSamplerCubeArrayShadow );
		return result;
	}
}

#endif
