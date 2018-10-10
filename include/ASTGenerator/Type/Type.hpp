/*
See LICENSE file in root folder
*/
#ifndef ___AST_Type_H___
#define ___AST_Type_H___
#pragma once

#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

namespace ast
{
	class Type
	{
	public:
		static uint32_t constexpr NotArray = 0u;
		static uint32_t constexpr UnknownArraySize = ~( 0u );
		enum class Kind
			: uint8_t
		{
			eUndefined,
			eFunction,
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

	inline TypePtr makeType( Type::Kind kind
		, uint32_t arraySize = Type::NotArray )
	{
		return std::make_shared< Type >( kind, arraySize );
	}

	inline TypePtr getUndefinedType()
	{
		static TypePtr const result = makeType( Type::Kind::eUndefined );
		return result;
	}

	inline TypePtr getFunctionType()
	{
		static TypePtr const result = makeType( Type::Kind::eFunction );
		return result;
	}

	inline TypePtr getBoolType()
	{
		static TypePtr const result = makeType( Type::Kind::eBoolean );
		return result;
	}

	inline TypePtr getIntType()
	{
		static TypePtr const result = makeType( Type::Kind::eInt );
		return result;
	}

	inline TypePtr getUIntType()
	{
		static TypePtr const result = makeType( Type::Kind::eUInt );
		return result;
	}

	inline TypePtr getFloatType()
	{
		static TypePtr const result = makeType( Type::Kind::eFloat );
		return result;
	}

	inline TypePtr getVec2BType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec2B );
		return result;
	}

	inline TypePtr getVec3BType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec3B );
		return result;
	}

	inline TypePtr getVec4BType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec4B );
		return result;
	}

	inline TypePtr getVec2IType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec2I );
		return result;
	}

	inline TypePtr getVec3IType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec3I );
		return result;
	}

	inline TypePtr getVec4IType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec4I );
		return result;
	}

	inline TypePtr getVec2UIType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec2UI );
		return result;
	}

	inline TypePtr getVec3UIType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec3UI );
		return result;
	}

	inline TypePtr getVec4UIType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec4UI );
		return result;
	}

	inline TypePtr getVec2FType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec2F );
		return result;
	}

	inline TypePtr getVec3FType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec3F );
		return result;
	}

	inline TypePtr getVec4FType()
	{
		static TypePtr const result = makeType( Type::Kind::eVec4F );
		return result;
	}

	inline TypePtr getMat2x2BType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat2x2B );
		return result;
	}

	inline TypePtr getMat3x3BType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat3x3B );
		return result;
	}

	inline TypePtr getMat4x4BType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat4x4B );
		return result;
	}

	inline TypePtr getMat2x2IType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat2x2I );
		return result;
	}

	inline TypePtr getMat3x3IType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat3x3I );
		return result;
	}

	inline TypePtr getMat4x4IType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat4x4I );
		return result;
	}

	inline TypePtr getMat2x2UIType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat2x2UI );
		return result;
	}

	inline TypePtr getMat3x3UIType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat3x3UI );
		return result;
	}

	inline TypePtr getMat4x4UIType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat4x4UI );
		return result;
	}

	inline TypePtr getMat2x2FType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat2x2F );
		return result;
	}

	inline TypePtr getMat3x3FType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat3x3F );
		return result;
	}

	inline TypePtr getMat4x4FType()
	{
		static TypePtr const result = makeType( Type::Kind::eMat4x4F );
		return result;
	}

	inline TypePtr getConstantsBufferType()
	{
		static TypePtr const result = makeType( Type::Kind::eConstantsBuffer );
		return result;
	}

	inline TypePtr getShaderBufferType()
	{
		static TypePtr const result = makeType( Type::Kind::eShaderBuffer );
		return result;
	}

	inline TypePtr getSamplerBufferType()
	{
		static TypePtr const result = makeType( Type::Kind::eSamplerBuffer );
		return result;
	}

	inline TypePtr getSampler1DType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler1D );
		return result;
	}

	inline TypePtr getSampler2DType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler2D );
		return result;
	}

	inline TypePtr getSampler3DType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler3D );
		return result;
	}

	inline TypePtr getSamplerCubeType()
	{
		static TypePtr const result = makeType( Type::Kind::eSamplerCube );
		return result;
	}

	inline TypePtr getSampler2DRectType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler2DRect );
		return result;
	}

	inline TypePtr getSampler1DArrayType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler1DArray );
		return result;
	}

	inline TypePtr getSampler2DArrayType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler2DArray );
		return result;
	}

	inline TypePtr getSamplerCubeArrayType()
	{
		static TypePtr const result = makeType( Type::Kind::eSamplerCubeArray );
		return result;
	}

	inline TypePtr getSampler1DShadowType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler1DShadow );
		return result;
	}

	inline TypePtr getSampler2DShadowType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler2DShadow );
		return result;
	}

	inline TypePtr getSamplerCubeShadowType()
	{
		static TypePtr const result = makeType( Type::Kind::eSamplerCubeShadow );
		return result;
	}

	inline TypePtr getSampler2DRectShadowType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler2DRectShadow );
		return result;
	}

	inline TypePtr getSampler1DArrayShadowType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler1DArrayShadow );
		return result;
	}

	inline TypePtr getSampler2DArrayShadowType()
	{
		static TypePtr const result = makeType( Type::Kind::eSampler2DArrayShadow );
		return result;
	}

	inline TypePtr getSamplerCubeArrayShadowType()
	{
		static TypePtr const result = makeType( Type::Kind::eSamplerCubeArrayShadow );
		return result;
	}
}

#endif
