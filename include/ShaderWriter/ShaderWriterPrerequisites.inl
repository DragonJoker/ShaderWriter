namespace sdw
{
	//***********************************************************************************************

	template<>
	struct SamplerTypeTraits< SamplerType::eBuffer >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerBuffer;
		using Type = SamplerBuffer;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1D >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1D;
		using Type = Sampler1D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2D >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2D;
		using Type = Sampler2D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e3D >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler3D;
		using Type = Sampler3D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCube >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCube;
		using Type = SamplerCube;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRect >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DRect;
		using Type = Sampler2DRect;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1DShadow;
		using Type = Sampler1DShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DShadow;
		using Type = Sampler2DShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCubeShadow;
		using Type = SamplerCubeShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRectShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DRectShadow;
		using Type = Sampler2DRectShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArray >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1DArray;
		using Type = Sampler1DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArray >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DArray;
		using Type = Sampler2DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArray >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCubeArray;
		using Type = SamplerCubeArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArrayShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1DArrayShadow;
		using Type = Sampler1DArrayShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArrayShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DArrayShadow;
		using Type = Sampler2DArrayShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArrayShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCubeArrayShadow;
		using Type = SamplerCubeArrayShadow;
	};

	//***********************************************************************************************

	template<>
	struct TypeTraits< Boolean >
	{
		static type::Kind const TypeEnum = type::Kind::eBoolean;
	};

	template<>
	struct TypeTraits< Int >
	{
		static type::Kind const TypeEnum = type::Kind::eInt;
	};

	template<>
	struct TypeTraits< UInt >
	{
		static type::Kind const TypeEnum = type::Kind::eUInt;
	};

	template<>
	struct TypeTraits< Float >
	{
		static type::Kind const TypeEnum = type::Kind::eFloat;
	};

	template<>
	struct TypeTraits< BVec2 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec2B;
	};

	template<>
	struct TypeTraits< BVec3 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec3B;
	};

	template<>
	struct TypeTraits< BVec4 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec4B;
	};

	template<>
	struct TypeTraits< IVec2 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec2I;
	};

	template<>
	struct TypeTraits< IVec3 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec3I;
	};

	template<>
	struct TypeTraits< IVec4 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec4I;
	};

	template<>
	struct TypeTraits< UVec2 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec2UI;
	};

	template<>
	struct TypeTraits< UVec3 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec3UI;
	};

	template<>
	struct TypeTraits< UVec4 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec4UI;
	};

	template<>
	struct TypeTraits< Vec2 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec2F;
	};

	template<>
	struct TypeTraits< Vec3 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec3F;
	};

	template<>
	struct TypeTraits< Vec4 >
	{
		static type::Kind const TypeEnum = type::Kind::eVec4F;
	};

	template<>
	struct TypeTraits< BMat2 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat2x2B;
	};

	template<>
	struct TypeTraits< BMat3 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat3x3B;
	};

	template<>
	struct TypeTraits< BMat4 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat4x4B;
	};

	template<>
	struct TypeTraits< IMat2 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat2x2I;
	};

	template<>
	struct TypeTraits< IMat3 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat3x3I;
	};

	template<>
	struct TypeTraits< IMat4 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat4x4I;
	};

	template<>
	struct TypeTraits< UMat2 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat2x2UI;
	};

	template<>
	struct TypeTraits< UMat3 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat3x3UI;
	};

	template<>
	struct TypeTraits< UMat4 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat4x4UI;
	};

	template<>
	struct TypeTraits< Mat2 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat2x2F;
	};

	template<>
	struct TypeTraits< Mat3 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat3x3F;
	};

	template<>
	struct TypeTraits< Mat4 >
	{
		static type::Kind const TypeEnum = type::Kind::eMat4x4F;
	};

	template<>
	struct TypeTraits< SamplerBuffer >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerBuffer;
	};

	template<>
	struct TypeTraits< Sampler1D >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1D;
	};

	template<>
	struct TypeTraits< Sampler2D >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2D;
	};

	template<>
	struct TypeTraits< Sampler3D >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler3D;
	};

	template<>
	struct TypeTraits< SamplerCube >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCube;
	};

	template<>
	struct TypeTraits< Sampler2DRect >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DRect;
	};

	template<>
	struct TypeTraits< Sampler1DArray >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1DArray;
	};

	template<>
	struct TypeTraits< Sampler2DArray >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DArray;
	};

	template<>
	struct TypeTraits< SamplerCubeArray >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCubeArray;
	};

	template<>
	struct TypeTraits< Sampler1DShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1DShadow;
	};

	template<>
	struct TypeTraits< Sampler2DShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DShadow;
	};

	template<>
	struct TypeTraits< SamplerCubeShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCubeShadow;
	};

	template<>
	struct TypeTraits< Sampler2DRectShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DRectShadow;
	};

	template<>
	struct TypeTraits< Sampler1DArrayShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler1DArrayShadow;
	};

	template<>
	struct TypeTraits< Sampler2DArrayShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSampler2DArrayShadow;
	};

	template<>
	struct TypeTraits< SamplerCubeArrayShadow >
	{
		static type::Kind const TypeEnum = type::Kind::eSamplerCubeArrayShadow;
	};

	template< typename T >
	struct TypeTraits< InParam< T > >
	{
		static type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< Optional< T > >
	{
		static type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< OutParam< T > >
	{
		static type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< InOutParam< T > >
	{
		static type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	//***********************************************************************************************

	template< typename T >
	struct TypeOf< Optional< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct TypeOf< InParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct TypeOf< OutParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct TypeOf< InOutParam< T > >
	{
		using Type = T;
	};

	//***********************************************************************************************

	template< typename T >
	expr::ExprList makeExpr( std::vector< T > const & values )
	{
		expr::ExprList result;

		for ( auto & value : values )
		{
			result.emplace_back( makeExpr( value.m_expr ) );
		}

		return result;
	}

	//***********************************************************************************************
}
