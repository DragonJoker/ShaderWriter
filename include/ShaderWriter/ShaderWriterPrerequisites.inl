/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Type/Type.hpp>

namespace sdw
{
	//***********************************************************************************************

	template<>
	struct SamplerTypeTraits< SamplerType::eBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBuffer;
		using Type = SamplerBuffer;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1D;
		using Type = Sampler1D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2D;
		using Type = Sampler2D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3D;
		using Type = Sampler3D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCube;
		using Type = SamplerCube;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRect;
		using Type = Sampler2DRect;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DShadow;
		using Type = Sampler1DShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DShadow;
		using Type = Sampler2DShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeShadow;
		using Type = SamplerCubeShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRectShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectShadow;
		using Type = Sampler2DRectShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArray;
		using Type = Sampler1DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArray;
		using Type = Sampler2DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArray;
		using Type = SamplerCubeArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayShadow;
		using Type = Sampler1DArrayShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayShadow;
		using Type = Sampler2DArrayShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayShadow;
		using Type = SamplerCubeArrayShadow;
	};

	template< SamplerType ST >
	using SamplerTypeT = typename SamplerTypeTraits< ST >::Type;

	//***********************************************************************************************

	template<>
	struct TypeTraits< Boolean >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eBoolean;
	};

	template<>
	struct TypeTraits< Int >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eInt;
	};

	template<>
	struct TypeTraits< UInt >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eUInt;
	};

	template<>
	struct TypeTraits< Float >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eFloat;
	};

	template<>
	struct TypeTraits< BVec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2B;
	};

	template<>
	struct TypeTraits< BVec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3B;
	};

	template<>
	struct TypeTraits< BVec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4B;
	};

	template<>
	struct TypeTraits< IVec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2I;
	};

	template<>
	struct TypeTraits< IVec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3I;
	};

	template<>
	struct TypeTraits< IVec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4I;
	};

	template<>
	struct TypeTraits< UVec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2UI;
	};

	template<>
	struct TypeTraits< UVec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3UI;
	};

	template<>
	struct TypeTraits< UVec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4UI;
	};

	template<>
	struct TypeTraits< Vec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2F;
	};

	template<>
	struct TypeTraits< Vec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3F;
	};

	template<>
	struct TypeTraits< Vec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4F;
	};

	template<>
	struct TypeTraits< BMat2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x2B;
	};

	template<>
	struct TypeTraits< BMat3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x3B;
	};

	template<>
	struct TypeTraits< BMat4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x4B;
	};

	template<>
	struct TypeTraits< IMat2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x2I;
	};

	template<>
	struct TypeTraits< IMat3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x3I;
	};

	template<>
	struct TypeTraits< IMat4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x4I;
	};

	template<>
	struct TypeTraits< UMat2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x2UI;
	};

	template<>
	struct TypeTraits< UMat3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x3UI;
	};

	template<>
	struct TypeTraits< UMat4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x4UI;
	};

	template<>
	struct TypeTraits< Mat2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x2F;
	};

	template<>
	struct TypeTraits< Mat3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x3F;
	};

	template<>
	struct TypeTraits< Mat4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x4F;
	};

	template<>
	struct TypeTraits< SamplerBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBuffer;
	};

	template<>
	struct TypeTraits< Sampler1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1D;
	};

	template<>
	struct TypeTraits< Sampler2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2D;
	};

	template<>
	struct TypeTraits< Sampler3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3D;
	};

	template<>
	struct TypeTraits< SamplerCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCube;
	};

	template<>
	struct TypeTraits< Sampler2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRect;
	};

	template<>
	struct TypeTraits< Sampler1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArray;
	};

	template<>
	struct TypeTraits< Sampler2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArray;
	};

	template<>
	struct TypeTraits< SamplerCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArray;
	};

	template<>
	struct TypeTraits< Sampler1DShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DShadow;
	};

	template<>
	struct TypeTraits< Sampler2DShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DShadow;
	};

	template<>
	struct TypeTraits< SamplerCubeShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeShadow;
	};

	template<>
	struct TypeTraits< Sampler2DRectShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectShadow;
	};

	template<>
	struct TypeTraits< Sampler1DArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayShadow;
	};

	template<>
	struct TypeTraits< Sampler2DArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayShadow;
	};

	template<>
	struct TypeTraits< SamplerCubeArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayShadow;
	};

	template< typename T >
	struct TypeTraits< InParam< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< Optional< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< OutParam< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< InOutParam< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	static ast::type::Kind constexpr typeEnum = TypeTraits< T >::TypeEnum;

	//***********************************************************************************************
}
