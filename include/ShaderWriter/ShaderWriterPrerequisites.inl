/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	template<>
	struct TypeTraits< void >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVoid;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 0;
		using CppType = void;
	};
	
	template<>
	struct TypeTraits< bool >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eBoolean;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 1;
		static size_t constexpr ComponentCount = 1;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< int32_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 1;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< uint32_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 1;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< uint64_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 1;
		using CppType = uint64_t;
	};

	template<>
	struct TypeTraits< float >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eFloat;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 1;
		using CppType = float;
	};

	template<>
	struct TypeTraits< double >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eDouble;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 1;
		using CppType = double;
	};

	template<>
	struct TypeTraits< Void > : TypeTraits< void >
	{
	};

	template<>
	struct TypeTraits< Boolean > : TypeTraits< bool >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eInt > > : TypeTraits< int32_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eUInt > > : TypeTraits< uint32_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eUInt64 > > : TypeTraits< uint64_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eInt > > : TypeTraits< int32_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eUInt > > : TypeTraits< uint32_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eUInt64 > > : TypeTraits< uint64_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eFloat > > : TypeTraits< float >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eHalf > >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eHalf;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 2;
		static size_t constexpr ComponentCount = 1;
		using CppType = float;
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eDouble > > : TypeTraits< double >
	{
	};

	template<>
	struct TypeTraits< BVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2B;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 2;
		static size_t constexpr ComponentCount = 2;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< BVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3B;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 3;
		static size_t constexpr ComponentCount = 3;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< BVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4B;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 4;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< IVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2I;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 2;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< IVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3I;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 12;
		static size_t constexpr ComponentCount = 3;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< IVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4I;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< UVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2U;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 2;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< UVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3U;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 12;
		static size_t constexpr ComponentCount = 3;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< UVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4U;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< U64Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2U64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 2;
		using CppType = uint64_t;
	};

	template<>
	struct TypeTraits< U64Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3U64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 3;
		using CppType = uint64_t;
	};

	template<>
	struct TypeTraits< U64Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4U64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 4;
		using CppType = uint64_t;
	};

	template<>
	struct TypeTraits< Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 2;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 12;
		static size_t constexpr ComponentCount = 3;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = float;
	};

	template<>
	struct TypeTraits< HVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2H;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 2;
		using CppType = float;
	};

	template<>
	struct TypeTraits< HVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4H;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 4;
		using CppType = float;
	};

	template<>
	struct TypeTraits< DVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 2;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 3;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 4;
		using CppType = double;
	};

	template<>
	struct TypeTraits< Mat2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x2F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat2x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x3F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 6;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat2x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x4F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 8;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x3F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 36;
		static size_t constexpr ComponentCount = 9;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat3x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x2F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 6;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat3x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x4F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 12;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x4F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 64;
		static size_t constexpr ComponentCount = 16;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat4x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x2F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 8;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat4x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x3F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 12;
		using CppType = float;
	};

	template<>
	struct TypeTraits< DMat2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x2D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 4;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat2x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x3D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 6;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat2x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x4D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 64;
		static size_t constexpr ComponentCount = 8;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x3D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 72;
		static size_t constexpr ComponentCount = 9;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat3x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x2D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 6;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat3x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x4D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 96;
		static size_t constexpr ComponentCount = 12;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x4D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 128;
		static size_t constexpr ComponentCount = 16;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat4x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x2D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 64;
		static size_t constexpr ComponentCount = 8;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat4x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x3D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 96;
		static size_t constexpr ComponentCount = 12;
		using CppType = double;
	};

	template<>
	struct TypeTraits< StructInstance >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eStruct;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
	};

	template<>
	struct TypeTraits< RayDesc >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eRayDesc;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
	};

	template<>
	struct TypeTraits< Texture >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eTexture;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
	};

	template<>
	struct TypeTraits< Sampler >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eSampler;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
	};

	template<>
	struct TypeTraits< SampledImage >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eSampledImage;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
	};

	template<>
	struct TypeTraits< Image >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eImage;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
	};

	template<>
	struct TypeTraits< AccelerationStructure >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eAccelerationStructure;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
	};

	template< typename T >
	struct TypeTraits< NonUniformT< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = typename TypeTraits< T >::CppType;
		static size_t constexpr Size = TypeTraits< T >::Size;
		static size_t constexpr ComponentCount = TypeTraits< T >::ComponentCount;
	};

	template< typename T >
	struct TypeTraits< Array< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = typename TypeTraits< T >::CppType;
		static size_t constexpr Size = TypeTraits< T >::Size;
		static size_t constexpr ComponentCount = TypeTraits< T >::ComponentCount;
	};

	template< typename T >
	struct TypeTraits< InParam< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
		static size_t constexpr Size = TypeTraits< T >::Size;
		static size_t constexpr ComponentCount = TypeTraits< T >::ComponentCount;
	};

	template< typename T >
	struct TypeTraits< OutParam< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
		static size_t constexpr Size = TypeTraits< T >::Size;
		static size_t constexpr ComponentCount = TypeTraits< T >::ComponentCount;
	};

	template< typename T >
	struct TypeTraits< InOutParam< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
		static size_t constexpr Size = TypeTraits< T >::Size;
		static size_t constexpr ComponentCount = TypeTraits< T >::ComponentCount;
	};

	template< typename ValueT >
	struct TypeTraits< ReturnWrapperT< ValueT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< ValueT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< ValueT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< ValueT >::CppType;
		static size_t constexpr Size = TypeTraits< ValueT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< ValueT >::ComponentCount;
		using Type = ValueT;
	};

	//***********************************************************************************************

	template<>
	struct TypeKindTraits< ast::type::Kind::eBoolean >
	{
		using Type = Boolean;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eInt >
	{
		using Type = Int;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eUInt >
	{
		using Type = UInt;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eUInt64 >
	{
		using Type = UInt64;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eHalf >
	{
		using Type = Half;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eFloat >
	{
		using Type = Float;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eDouble >
	{
		using Type = Double;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2H >
	{
		using Type = HVec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4H >
	{
		using Type = HVec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2F >
	{
		using Type = Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3F >
	{
		using Type = Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4F >
	{
		using Type = Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2D >
	{
		using Type = DVec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3D >
	{
		using Type = DVec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4D >
	{
		using Type = DVec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2I >
	{
		using Type = IVec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3I >
	{
		using Type = IVec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4I >
	{
		using Type = IVec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2U >
	{
		using Type = UVec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3U >
	{
		using Type = UVec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4U >
	{
		using Type = UVec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2U64 >
	{
		using Type = U64Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3U64 >
	{
		using Type = U64Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4U64 >
	{
		using Type = U64Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat2x2F >
	{
		using Type = Mat2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat2x3F >
	{
		using Type = Mat2x3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat2x4F >
	{
		using Type = Mat2x4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat3x2F >
	{
		using Type = Mat3x2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat3x3F >
	{
		using Type = Mat3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat3x4F >
	{
		using Type = Mat3x4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat4x2F >
	{
		using Type = Mat4x2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat4x3F >
	{
		using Type = Mat4x3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eMat4x4F >
	{
		using Type = Mat4;
	};

	//***********************************************************************************************

	template< typename OpT >
	struct AreCompatibleT< OpT, ReturnWrapperT< OpT > >
		: std::true_type
	{
	};

	template< typename OpT >
	struct AreCompatibleT< ReturnWrapperT< OpT >, OpT >
		: std::true_type
	{
	};

	template< typename OpT >
	struct AreCompatibleT< OpT, OpT >
		: std::true_type
	{
	};

	template< typename OpT >
	struct AreCompatibleT< OpT, CppTypeT< OpT > >
		: std::true_type
	{
	};

	template< typename OpT >
	struct AreCompatibleT< CppTypeT< OpT >, OpT >
		: std::true_type
	{
	};

	//***********************************************************************************************

#define Writer_Image( Prefix, TypeName, Format, Value )\
	template<>\
	struct TypeTraits< R##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	};\
	template<>\
	struct TypeTraits< W##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	};\
	template<>\
	struct TypeTraits< RW##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	}

#define Writer_Texture( Prefix, TypeName, Format, Value )\
	template<>\
	struct TypeTraits< Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	}

	Writer_Image( , ImageBuffer, Rgba32, eImage );
	Writer_Image( , Image1D, Rgba32, eImage );
	Writer_Image( , Image2D, Rgba32, eImage );
	Writer_Image( , Image3D, Rgba32, eImage );
	Writer_Image( , ImageCube, Rgba32, eImage );
	Writer_Image( , Image1DArray, Rgba32, eImage );
	Writer_Image( , Image2DArray, Rgba32, eImage );
	Writer_Image( , ImageCubeArray, Rgba32, eImage );
	Writer_Image( , Image2DMS, Rgba32, eImage );
	Writer_Image( , Image2DMSArray, Rgba32, eImage );
	Writer_Texture( , TextureBuffer, Rgba32, eTexture );
	Writer_Texture( , Texture1D, Rgba32, eTexture );
	Writer_Texture( , Texture2D, Rgba32, eTexture );
	Writer_Texture( , Texture3D, Rgba32, eTexture );
	Writer_Texture( , TextureCube, Rgba32, eTexture );
	Writer_Texture( , Texture1DArray, Rgba32, eTexture );
	Writer_Texture( , Texture2DArray, Rgba32, eTexture );
	Writer_Texture( , TextureCubeArray, Rgba32, eTexture );
	Writer_Texture( , Texture2DMS, Rgba32, eTexture );
	Writer_Texture( , Texture2DMSArray, Rgba32, eTexture );
	Writer_Image( , ImageBuffer, Rgba16, eImage );
	Writer_Image( , Image1D, Rgba16, eImage );
	Writer_Image( , Image2D, Rgba16, eImage );
	Writer_Image( , Image3D, Rgba16, eImage );
	Writer_Image( , ImageCube, Rgba16, eImage );
	Writer_Image( , Image1DArray, Rgba16, eImage );
	Writer_Image( , Image2DArray, Rgba16, eImage );
	Writer_Image( , ImageCubeArray, Rgba16, eImage );
	Writer_Image( , Image2DMS, Rgba16, eImage );
	Writer_Image( , Image2DMSArray, Rgba16, eImage );
	Writer_Texture( , TextureBuffer, Rgba16, eTexture );
	Writer_Texture( , Texture1D, Rgba16, eTexture );
	Writer_Texture( , Texture2D, Rgba16, eTexture );
	Writer_Texture( , Texture3D, Rgba16, eTexture );
	Writer_Texture( , TextureCube, Rgba16, eTexture );
	Writer_Texture( , Texture1DArray, Rgba16, eTexture );
	Writer_Texture( , Texture2DArray, Rgba16, eTexture );
	Writer_Texture( , TextureCubeArray, Rgba16, eTexture );
	Writer_Texture( , Texture2DMS, Rgba16, eTexture );
	Writer_Texture( , Texture2DMSArray, Rgba16, eTexture );
	Writer_Image( , ImageBuffer, Rg32, eImage );
	Writer_Image( , Image1D, Rg32, eImage );
	Writer_Image( , Image2D, Rg32, eImage );
	Writer_Image( , Image3D, Rg32, eImage );
	Writer_Image( , ImageCube, Rg32, eImage );
	Writer_Image( , Image1DArray, Rg32, eImage );
	Writer_Image( , Image2DArray, Rg32, eImage );
	Writer_Image( , ImageCubeArray, Rg32, eImage );
	Writer_Image( , Image2DMS, Rg32, eImage );
	Writer_Image( , Image2DMSArray, Rg32, eImage );
	Writer_Texture( , TextureBuffer, Rg32, eTexture );
	Writer_Texture( , Texture1D, Rg32, eTexture );
	Writer_Texture( , Texture2D, Rg32, eTexture );
	Writer_Texture( , Texture3D, Rg32, eTexture );
	Writer_Texture( , TextureCube, Rg32, eTexture );
	Writer_Texture( , Texture1DArray, Rg32, eTexture );
	Writer_Texture( , Texture2DArray, Rg32, eTexture );
	Writer_Texture( , TextureCubeArray, Rg32, eTexture );
	Writer_Texture( , Texture2DMS, Rg32, eTexture );
	Writer_Texture( , Texture2DMSArray, Rg32, eTexture );
	Writer_Image( , ImageBuffer, Rg16, eImage );
	Writer_Image( , Image1D, Rg16, eImage );
	Writer_Image( , Image2D, Rg16, eImage );
	Writer_Image( , Image3D, Rg16, eImage );
	Writer_Image( , ImageCube, Rg16, eImage );
	Writer_Image( , Image1DArray, Rg16, eImage );
	Writer_Image( , Image2DArray, Rg16, eImage );
	Writer_Image( , ImageCubeArray, Rg16, eImage );
	Writer_Image( , Image2DMS, Rg16, eImage );
	Writer_Image( , Image2DMSArray, Rg16, eImage );
	Writer_Texture( , TextureBuffer, Rg16, eTexture );
	Writer_Texture( , Texture1D, Rg16, eTexture );
	Writer_Texture( , Texture2D, Rg16, eTexture );
	Writer_Texture( , Texture3D, Rg16, eTexture );
	Writer_Texture( , TextureCube, Rg16, eTexture );
	Writer_Texture( , Texture1DArray, Rg16, eTexture );
	Writer_Texture( , Texture2DArray, Rg16, eTexture );
	Writer_Texture( , TextureCubeArray, Rg16, eTexture );
	Writer_Texture( , Texture2DMS, Rg16, eTexture );
	Writer_Texture( , Texture2DMSArray, Rg16, eTexture );
	Writer_Image( , ImageBuffer, R32, eImage );
	Writer_Image( , Image1D, R32, eImage );
	Writer_Image( , Image2D, R32, eImage );
	Writer_Image( , Image3D, R32, eImage );
	Writer_Image( , ImageCube, R32, eImage );
	Writer_Image( , Image1DArray, R32, eImage );
	Writer_Image( , Image2DArray, R32, eImage );
	Writer_Image( , ImageCubeArray, R32, eImage );
	Writer_Image( , Image2DMS, R32, eImage );
	Writer_Image( , Image2DMSArray, R32, eImage );
	Writer_Texture( , TextureBuffer, R32, eTexture );
	Writer_Texture( , Texture1D, R32, eTexture );
	Writer_Texture( , Texture2D, R32, eTexture );
	Writer_Texture( , Texture3D, R32, eTexture );
	Writer_Texture( , TextureCube, R32, eTexture );
	Writer_Texture( , Texture1DArray, R32, eTexture );
	Writer_Texture( , Texture2DArray, R32, eTexture );
	Writer_Texture( , TextureCubeArray, R32, eTexture );
	Writer_Texture( , Texture2DMS, R32, eTexture );
	Writer_Texture( , Texture2DMSArray, R32, eTexture );
	Writer_Image( , ImageBuffer, R16, eImage );
	Writer_Image( , Image1D, R16, eImage );
	Writer_Image( , Image2D, R16, eImage );
	Writer_Image( , Image3D, R16, eImage );
	Writer_Image( , ImageCube, R16, eImage );
	Writer_Image( , Image1DArray, R16, eImage );
	Writer_Image( , Image2DArray, R16, eImage );
	Writer_Image( , ImageCubeArray, R16, eImage );
	Writer_Image( , Image2DMS, R16, eImage );
	Writer_Image( , Image2DMSArray, R16, eImage );
	Writer_Texture( , TextureBuffer, R16, eTexture );
	Writer_Texture( , Texture1D, R16, eTexture );
	Writer_Texture( , Texture2D, R16, eTexture );
	Writer_Texture( , Texture3D, R16, eTexture );
	Writer_Texture( , TextureCube, R16, eTexture );
	Writer_Texture( , Texture1DArray, R16, eTexture );
	Writer_Texture( , Texture2DArray, R16, eTexture );
	Writer_Texture( , TextureCubeArray, R16, eTexture );
	Writer_Texture( , Texture2DMS, R16, eTexture );
	Writer_Texture( , Texture2DMSArray, R16, eTexture );
	Writer_Texture( , Texture1DShadow, R32, eTexture );
	Writer_Texture( , Texture2DShadow, R32, eTexture );
	Writer_Texture( , TextureCubeShadow, R32, eTexture );
	Writer_Texture( , Texture1DArrayShadow, R32, eTexture );
	Writer_Texture( , Texture2DArrayShadow, R32, eTexture );
	Writer_Texture( , TextureCubeArrayShadow, R32, eTexture );
	Writer_Texture( , Texture1DShadow, R16, eTexture );
	Writer_Texture( , Texture2DShadow, R16, eTexture );
	Writer_Texture( , TextureCubeShadow, R16, eTexture );
	Writer_Texture( , Texture1DArrayShadow, R16, eTexture );
	Writer_Texture( , Texture2DArrayShadow, R16, eTexture );
	Writer_Texture( , TextureCubeArrayShadow, R16, eTexture );
	Writer_Image( I, ImageBuffer, Rgba32, eImage );
	Writer_Image( I, Image1D, Rgba32, eImage );
	Writer_Image( I, Image2D, Rgba32, eImage );
	Writer_Image( I, Image3D, Rgba32, eImage );
	Writer_Image( I, ImageCube, Rgba32, eImage );
	Writer_Image( I, Image1DArray, Rgba32, eImage );
	Writer_Image( I, Image2DArray, Rgba32, eImage );
	Writer_Image( I, ImageCubeArray, Rgba32, eImage );
	Writer_Image( I, Image2DMS, Rgba32, eImage );
	Writer_Image( I, Image2DMSArray, Rgba32, eImage );
	Writer_Texture( I, TextureBuffer, Rgba32, eTexture );
	Writer_Texture( I, Texture1D, Rgba32, eTexture );
	Writer_Texture( I, Texture2D, Rgba32, eTexture );
	Writer_Texture( I, Texture3D, Rgba32, eTexture );
	Writer_Texture( I, TextureCube, Rgba32, eTexture );
	Writer_Texture( I, Texture1DArray, Rgba32, eTexture );
	Writer_Texture( I, Texture2DArray, Rgba32, eTexture );
	Writer_Texture( I, TextureCubeArray, Rgba32, eTexture );
	Writer_Texture( I, Texture2DMS, Rgba32, eTexture );
	Writer_Texture( I, Texture2DMSArray, Rgba32, eTexture );
	Writer_Image( I, ImageBuffer, Rgba16, eImage );
	Writer_Image( I, Image1D, Rgba16, eImage );
	Writer_Image( I, Image2D, Rgba16, eImage );
	Writer_Image( I, Image3D, Rgba16, eImage );
	Writer_Image( I, ImageCube, Rgba16, eImage );
	Writer_Image( I, Image1DArray, Rgba16, eImage );
	Writer_Image( I, Image2DArray, Rgba16, eImage );
	Writer_Image( I, ImageCubeArray, Rgba16, eImage );
	Writer_Image( I, Image2DMS, Rgba16, eImage );
	Writer_Image( I, Image2DMSArray, Rgba16, eImage );
	Writer_Texture( I, TextureBuffer, Rgba16, eTexture );
	Writer_Texture( I, Texture1D, Rgba16, eTexture );
	Writer_Texture( I, Texture2D, Rgba16, eTexture );
	Writer_Texture( I, Texture3D, Rgba16, eTexture );
	Writer_Texture( I, TextureCube, Rgba16, eTexture );
	Writer_Texture( I, Texture1DArray, Rgba16, eTexture );
	Writer_Texture( I, Texture2DArray, Rgba16, eTexture );
	Writer_Texture( I, TextureCubeArray, Rgba16, eTexture );
	Writer_Texture( I, Texture2DMS, Rgba16, eTexture );
	Writer_Texture( I, Texture2DMSArray, Rgba16, eTexture );
	Writer_Image( I, ImageBuffer, Rgba8, eImage );
	Writer_Image( I, Image1D, Rgba8, eImage );
	Writer_Image( I, Image2D, Rgba8, eImage );
	Writer_Image( I, Image3D, Rgba8, eImage );
	Writer_Image( I, ImageCube, Rgba8, eImage );
	Writer_Image( I, Image1DArray, Rgba8, eImage );
	Writer_Image( I, Image2DArray, Rgba8, eImage );
	Writer_Image( I, ImageCubeArray, Rgba8, eImage );
	Writer_Image( I, Image2DMS, Rgba8, eImage );
	Writer_Image( I, Image2DMSArray, Rgba8, eImage );
	Writer_Texture( I, TextureBuffer, Rgba8, eTexture );
	Writer_Texture( I, Texture1D, Rgba8, eTexture );
	Writer_Texture( I, Texture2D, Rgba8, eTexture );
	Writer_Texture( I, Texture3D, Rgba8, eTexture );
	Writer_Texture( I, TextureCube, Rgba8, eTexture );
	Writer_Texture( I, Texture1DArray, Rgba8, eTexture );
	Writer_Texture( I, Texture2DArray, Rgba8, eTexture );
	Writer_Texture( I, TextureCubeArray, Rgba8, eTexture );
	Writer_Texture( I, Texture2DMS, Rgba8, eTexture );
	Writer_Texture( I, Texture2DMSArray, Rgba8, eTexture );
	Writer_Image( I, ImageBuffer, Rg32, eImage );
	Writer_Image( I, Image1D, Rg32, eImage );
	Writer_Image( I, Image2D, Rg32, eImage );
	Writer_Image( I, Image3D, Rg32, eImage );
	Writer_Image( I, ImageCube, Rg32, eImage );
	Writer_Image( I, Image1DArray, Rg32, eImage );
	Writer_Image( I, Image2DArray, Rg32, eImage );
	Writer_Image( I, ImageCubeArray, Rg32, eImage );
	Writer_Image( I, Image2DMS, Rg32, eImage );
	Writer_Image( I, Image2DMSArray, Rg32, eImage );
	Writer_Texture( I, TextureBuffer, Rg32, eTexture );
	Writer_Texture( I, Texture1D, Rg32, eTexture );
	Writer_Texture( I, Texture2D, Rg32, eTexture );
	Writer_Texture( I, Texture3D, Rg32, eTexture );
	Writer_Texture( I, TextureCube, Rg32, eTexture );
	Writer_Texture( I, Texture1DArray, Rg32, eTexture );
	Writer_Texture( I, Texture2DArray, Rg32, eTexture );
	Writer_Texture( I, TextureCubeArray, Rg32, eTexture );
	Writer_Texture( I, Texture2DMS, Rg32, eTexture );
	Writer_Texture( I, Texture2DMSArray, Rg32, eTexture );
	Writer_Image( I, ImageBuffer, Rg16, eImage );
	Writer_Image( I, Image1D, Rg16, eImage );
	Writer_Image( I, Image2D, Rg16, eImage );
	Writer_Image( I, Image3D, Rg16, eImage );
	Writer_Image( I, ImageCube, Rg16, eImage );
	Writer_Image( I, Image1DArray, Rg16, eImage );
	Writer_Image( I, Image2DArray, Rg16, eImage );
	Writer_Image( I, ImageCubeArray, Rg16, eImage );
	Writer_Image( I, Image2DMS, Rg16, eImage );
	Writer_Image( I, Image2DMSArray, Rg16, eImage );
	Writer_Texture( I, TextureBuffer, Rg16, eTexture );
	Writer_Texture( I, Texture1D, Rg16, eTexture );
	Writer_Texture( I, Texture2D, Rg16, eTexture );
	Writer_Texture( I, Texture3D, Rg16, eTexture );
	Writer_Texture( I, TextureCube, Rg16, eTexture );
	Writer_Texture( I, Texture1DArray, Rg16, eTexture );
	Writer_Texture( I, Texture2DArray, Rg16, eTexture );
	Writer_Texture( I, TextureCubeArray, Rg16, eTexture );
	Writer_Texture( I, Texture2DMS, Rg16, eTexture );
	Writer_Texture( I, Texture2DMSArray, Rg16, eTexture );
	Writer_Image( I, ImageBuffer, Rg8, eImage );
	Writer_Image( I, Image1D, Rg8, eImage );
	Writer_Image( I, Image2D, Rg8, eImage );
	Writer_Image( I, Image3D, Rg8, eImage );
	Writer_Image( I, ImageCube, Rg8, eImage );
	Writer_Image( I, Image1DArray, Rg8, eImage );
	Writer_Image( I, Image2DArray, Rg8, eImage );
	Writer_Image( I, ImageCubeArray, Rg8, eImage );
	Writer_Image( I, Image2DMS, Rg8, eImage );
	Writer_Image( I, Image2DMSArray, Rg8, eImage );
	Writer_Texture( I, TextureBuffer, Rg8, eTexture );
	Writer_Texture( I, Texture1D, Rg8, eTexture );
	Writer_Texture( I, Texture2D, Rg8, eTexture );
	Writer_Texture( I, Texture3D, Rg8, eTexture );
	Writer_Texture( I, TextureCube, Rg8, eTexture );
	Writer_Texture( I, Texture1DArray, Rg8, eTexture );
	Writer_Texture( I, Texture2DArray, Rg8, eTexture );
	Writer_Texture( I, TextureCubeArray, Rg8, eTexture );
	Writer_Texture( I, Texture2DMS, Rg8, eTexture );
	Writer_Texture( I, Texture2DMSArray, Rg8, eTexture );
	Writer_Image( I, ImageBuffer, R32, eImage );
	Writer_Image( I, Image1D, R32, eImage );
	Writer_Image( I, Image2D, R32, eImage );
	Writer_Image( I, Image3D, R32, eImage );
	Writer_Image( I, ImageCube, R32, eImage );
	Writer_Image( I, Image1DArray, R32, eImage );
	Writer_Image( I, Image2DArray, R32, eImage );
	Writer_Image( I, ImageCubeArray, R32, eImage );
	Writer_Image( I, Image2DMS, R32, eImage );
	Writer_Image( I, Image2DMSArray, R32, eImage );
	Writer_Texture( I, TextureBuffer, R32, eTexture );
	Writer_Texture( I, Texture1D, R32, eTexture );
	Writer_Texture( I, Texture2D, R32, eTexture );
	Writer_Texture( I, Texture3D, R32, eTexture );
	Writer_Texture( I, TextureCube, R32, eTexture );
	Writer_Texture( I, Texture1DArray, R32, eTexture );
	Writer_Texture( I, Texture2DArray, R32, eTexture );
	Writer_Texture( I, TextureCubeArray, R32, eTexture );
	Writer_Texture( I, Texture2DMS, R32, eTexture );
	Writer_Texture( I, Texture2DMSArray, R32, eTexture );
	Writer_Image( I, ImageBuffer, R16, eImage );
	Writer_Image( I, Image1D, R16, eImage );
	Writer_Image( I, Image2D, R16, eImage );
	Writer_Image( I, Image3D, R16, eImage );
	Writer_Image( I, ImageCube, R16, eImage );
	Writer_Image( I, Image1DArray, R16, eImage );
	Writer_Image( I, Image2DArray, R16, eImage );
	Writer_Image( I, ImageCubeArray, R16, eImage );
	Writer_Image( I, Image2DMS, R16, eImage );
	Writer_Image( I, Image2DMSArray, R16, eImage );
	Writer_Texture( I, TextureBuffer, R16, eTexture );
	Writer_Texture( I, Texture1D, R16, eTexture );
	Writer_Texture( I, Texture2D, R16, eTexture );
	Writer_Texture( I, Texture3D, R16, eTexture );
	Writer_Texture( I, TextureCube, R16, eTexture );
	Writer_Texture( I, Texture1DArray, R16, eTexture );
	Writer_Texture( I, Texture2DArray, R16, eTexture );
	Writer_Texture( I, TextureCubeArray, R16, eTexture );
	Writer_Texture( I, Texture2DMS, R16, eTexture );
	Writer_Texture( I, Texture2DMSArray, R16, eTexture );
	Writer_Image( I, ImageBuffer, R8, eImage );
	Writer_Image( I, Image1D, R8, eImage );
	Writer_Image( I, Image2D, R8, eImage );
	Writer_Image( I, Image3D, R8, eImage );
	Writer_Image( I, ImageCube, R8, eImage );
	Writer_Image( I, Image1DArray, R8, eImage );
	Writer_Image( I, Image2DArray, R8, eImage );
	Writer_Image( I, ImageCubeArray, R8, eImage );
	Writer_Image( I, Image2DMS, R8, eImage );
	Writer_Image( I, Image2DMSArray, R8, eImage );
	Writer_Texture( I, TextureBuffer, R8, eTexture );
	Writer_Texture( I, Texture1D, R8, eTexture );
	Writer_Texture( I, Texture2D, R8, eTexture );
	Writer_Texture( I, Texture3D, R8, eTexture );
	Writer_Texture( I, TextureCube, R8, eTexture );
	Writer_Texture( I, Texture1DArray, R8, eTexture );
	Writer_Texture( I, Texture2DArray, R8, eTexture );
	Writer_Texture( I, TextureCubeArray, R8, eTexture );
	Writer_Texture( I, Texture2DMS, R8, eTexture );
	Writer_Texture( I, Texture2DMSArray, R8, eTexture );
	Writer_Image( U, ImageBuffer, Rgba32, eImage );
	Writer_Image( U, Image1D, Rgba32, eImage );
	Writer_Image( U, Image2D, Rgba32, eImage );
	Writer_Image( U, Image3D, Rgba32, eImage );
	Writer_Image( U, ImageCube, Rgba32, eImage );
	Writer_Image( U, Image1DArray, Rgba32, eImage );
	Writer_Image( U, Image2DArray, Rgba32, eImage );
	Writer_Image( U, ImageCubeArray, Rgba32, eImage );
	Writer_Image( U, Image2DMS, Rgba32, eImage );
	Writer_Image( U, Image2DMSArray, Rgba32, eImage );
	Writer_Texture( U, TextureBuffer, Rgba32, eTexture );
	Writer_Texture( U, Texture1D, Rgba32, eTexture );
	Writer_Texture( U, Texture2D, Rgba32, eTexture );
	Writer_Texture( U, Texture3D, Rgba32, eTexture );
	Writer_Texture( U, TextureCube, Rgba32, eTexture );
	Writer_Texture( U, Texture1DArray, Rgba32, eTexture );
	Writer_Texture( U, Texture2DArray, Rgba32, eTexture );
	Writer_Texture( U, TextureCubeArray, Rgba32, eTexture );
	Writer_Texture( U, Texture2DMS, Rgba32, eTexture );
	Writer_Texture( U, Texture2DMSArray, Rgba32, eTexture );
	Writer_Image( U, ImageBuffer, Rgba16, eImage );
	Writer_Image( U, Image1D, Rgba16, eImage );
	Writer_Image( U, Image2D, Rgba16, eImage );
	Writer_Image( U, Image3D, Rgba16, eImage );
	Writer_Image( U, ImageCube, Rgba16, eImage );
	Writer_Image( U, Image1DArray, Rgba16, eImage );
	Writer_Image( U, Image2DArray, Rgba16, eImage );
	Writer_Image( U, ImageCubeArray, Rgba16, eImage );
	Writer_Image( U, Image2DMS, Rgba16, eImage );
	Writer_Image( U, Image2DMSArray, Rgba16, eImage );
	Writer_Texture( U, TextureBuffer, Rgba16, eTexture );
	Writer_Texture( U, Texture1D, Rgba16, eTexture );
	Writer_Texture( U, Texture2D, Rgba16, eTexture );
	Writer_Texture( U, Texture3D, Rgba16, eTexture );
	Writer_Texture( U, TextureCube, Rgba16, eTexture );
	Writer_Texture( U, Texture1DArray, Rgba16, eTexture );
	Writer_Texture( U, Texture2DArray, Rgba16, eTexture );
	Writer_Texture( U, TextureCubeArray, Rgba16, eTexture );
	Writer_Texture( U, Texture2DMS, Rgba16, eTexture );
	Writer_Texture( U, Texture2DMSArray, Rgba16, eTexture );
	Writer_Image( U, ImageBuffer, Rgba8, eImage );
	Writer_Image( U, Image1D, Rgba8, eImage );
	Writer_Image( U, Image2D, Rgba8, eImage );
	Writer_Image( U, Image3D, Rgba8, eImage );
	Writer_Image( U, ImageCube, Rgba8, eImage );
	Writer_Image( U, Image1DArray, Rgba8, eImage );
	Writer_Image( U, Image2DArray, Rgba8, eImage );
	Writer_Image( U, ImageCubeArray, Rgba8, eImage );
	Writer_Image( U, Image2DMS, Rgba8, eImage );
	Writer_Image( U, Image2DMSArray, Rgba8, eImage );
	Writer_Texture( U, TextureBuffer, Rgba8, eTexture );
	Writer_Texture( U, Texture1D, Rgba8, eTexture );
	Writer_Texture( U, Texture2D, Rgba8, eTexture );
	Writer_Texture( U, Texture3D, Rgba8, eTexture );
	Writer_Texture( U, TextureCube, Rgba8, eTexture );
	Writer_Texture( U, Texture1DArray, Rgba8, eTexture );
	Writer_Texture( U, Texture2DArray, Rgba8, eTexture );
	Writer_Texture( U, TextureCubeArray, Rgba8, eTexture );
	Writer_Texture( U, Texture2DMS, Rgba8, eTexture );
	Writer_Texture( U, Texture2DMSArray, Rgba8, eTexture );
	Writer_Image( U, ImageBuffer, Rg32, eImage );
	Writer_Image( U, Image1D, Rg32, eImage );
	Writer_Image( U, Image2D, Rg32, eImage );
	Writer_Image( U, Image3D, Rg32, eImage );
	Writer_Image( U, ImageCube, Rg32, eImage );
	Writer_Image( U, Image1DArray, Rg32, eImage );
	Writer_Image( U, Image2DArray, Rg32, eImage );
	Writer_Image( U, ImageCubeArray, Rg32, eImage );
	Writer_Image( U, Image2DMS, Rg32, eImage );
	Writer_Image( U, Image2DMSArray, Rg32, eImage );
	Writer_Texture( U, TextureBuffer, Rg32, eTexture );
	Writer_Texture( U, Texture1D, Rg32, eTexture );
	Writer_Texture( U, Texture2D, Rg32, eTexture );
	Writer_Texture( U, Texture3D, Rg32, eTexture );
	Writer_Texture( U, TextureCube, Rg32, eTexture );
	Writer_Texture( U, Texture1DArray, Rg32, eTexture );
	Writer_Texture( U, Texture2DArray, Rg32, eTexture );
	Writer_Texture( U, TextureCubeArray, Rg32, eTexture );
	Writer_Texture( U, Texture2DMS, Rg32, eTexture );
	Writer_Texture( U, Texture2DMSArray, Rg32, eTexture );
	Writer_Image( U, ImageBuffer, Rg16, eImage );
	Writer_Image( U, Image1D, Rg16, eImage );
	Writer_Image( U, Image2D, Rg16, eImage );
	Writer_Image( U, Image3D, Rg16, eImage );
	Writer_Image( U, ImageCube, Rg16, eImage );
	Writer_Image( U, Image1DArray, Rg16, eImage );
	Writer_Image( U, Image2DArray, Rg16, eImage );
	Writer_Image( U, ImageCubeArray, Rg16, eImage );
	Writer_Image( U, Image2DMS, Rg16, eImage );
	Writer_Image( U, Image2DMSArray, Rg16, eImage );
	Writer_Texture( U, TextureBuffer, Rg16, eTexture );
	Writer_Texture( U, Texture1D, Rg16, eTexture );
	Writer_Texture( U, Texture2D, Rg16, eTexture );
	Writer_Texture( U, Texture3D, Rg16, eTexture );
	Writer_Texture( U, TextureCube, Rg16, eTexture );
	Writer_Texture( U, Texture1DArray, Rg16, eTexture );
	Writer_Texture( U, Texture2DArray, Rg16, eTexture );
	Writer_Texture( U, TextureCubeArray, Rg16, eTexture );
	Writer_Texture( U, Texture2DMS, Rg16, eTexture );
	Writer_Texture( U, Texture2DMSArray, Rg16, eTexture );
	Writer_Image( U, ImageBuffer, Rg8, eImage );
	Writer_Image( U, Image1D, Rg8, eImage );
	Writer_Image( U, Image2D, Rg8, eImage );
	Writer_Image( U, Image3D, Rg8, eImage );
	Writer_Image( U, ImageCube, Rg8, eImage );
	Writer_Image( U, Image1DArray, Rg8, eImage );
	Writer_Image( U, Image2DArray, Rg8, eImage );
	Writer_Image( U, ImageCubeArray, Rg8, eImage );
	Writer_Image( U, Image2DMS, Rg8, eImage );
	Writer_Image( U, Image2DMSArray, Rg8, eImage );
	Writer_Texture( U, TextureBuffer, Rg8, eTexture );
	Writer_Texture( U, Texture1D, Rg8, eTexture );
	Writer_Texture( U, Texture2D, Rg8, eTexture );
	Writer_Texture( U, Texture3D, Rg8, eTexture );
	Writer_Texture( U, TextureCube, Rg8, eTexture );
	Writer_Texture( U, Texture1DArray, Rg8, eTexture );
	Writer_Texture( U, Texture2DArray, Rg8, eTexture );
	Writer_Texture( U, TextureCubeArray, Rg8, eTexture );
	Writer_Texture( U, Texture2DMS, Rg8, eTexture );
	Writer_Texture( U, Texture2DMSArray, Rg8, eTexture );
	Writer_Image( U, ImageBuffer, R32, eImage );
	Writer_Image( U, Image1D, R32, eImage );
	Writer_Image( U, Image2D, R32, eImage );
	Writer_Image( U, Image3D, R32, eImage );
	Writer_Image( U, ImageCube, R32, eImage );
	Writer_Image( U, Image1DArray, R32, eImage );
	Writer_Image( U, Image2DArray, R32, eImage );
	Writer_Image( U, ImageCubeArray, R32, eImage );
	Writer_Image( U, Image2DMS, R32, eImage );
	Writer_Image( U, Image2DMSArray, R32, eImage );
	Writer_Texture( U, TextureBuffer, R32, eTexture );
	Writer_Texture( U, Texture1D, R32, eTexture );
	Writer_Texture( U, Texture2D, R32, eTexture );
	Writer_Texture( U, Texture3D, R32, eTexture );
	Writer_Texture( U, TextureCube, R32, eTexture );
	Writer_Texture( U, Texture1DArray, R32, eTexture );
	Writer_Texture( U, Texture2DArray, R32, eTexture );
	Writer_Texture( U, TextureCubeArray, R32, eTexture );
	Writer_Texture( U, Texture2DMS, R32, eTexture );
	Writer_Texture( U, Texture2DMSArray, R32, eTexture );
	Writer_Image( U, ImageBuffer, R16, eImage );
	Writer_Image( U, Image1D, R16, eImage );
	Writer_Image( U, Image2D, R16, eImage );
	Writer_Image( U, Image3D, R16, eImage );
	Writer_Image( U, ImageCube, R16, eImage );
	Writer_Image( U, Image1DArray, R16, eImage );
	Writer_Image( U, Image2DArray, R16, eImage );
	Writer_Image( U, ImageCubeArray, R16, eImage );
	Writer_Image( U, Image2DMS, R16, eImage );
	Writer_Image( U, Image2DMSArray, R16, eImage );
	Writer_Texture( U, TextureBuffer, R16, eTexture );
	Writer_Texture( U, Texture1D, R16, eTexture );
	Writer_Texture( U, Texture2D, R16, eTexture );
	Writer_Texture( U, Texture3D, R16, eTexture );
	Writer_Texture( U, TextureCube, R16, eTexture );
	Writer_Texture( U, Texture1DArray, R16, eTexture );
	Writer_Texture( U, Texture2DArray, R16, eTexture );
	Writer_Texture( U, TextureCubeArray, R16, eTexture );
	Writer_Texture( U, Texture2DMS, R16, eTexture );
	Writer_Texture( U, Texture2DMSArray, R16, eTexture );
	Writer_Image( U, ImageBuffer, R8, eImage );
	Writer_Image( U, Image1D, R8, eImage );
	Writer_Image( U, Image2D, R8, eImage );
	Writer_Image( U, Image3D, R8, eImage );
	Writer_Image( U, ImageCube, R8, eImage );
	Writer_Image( U, Image1DArray, R8, eImage );
	Writer_Image( U, Image2DArray, R8, eImage );
	Writer_Image( U, ImageCubeArray, R8, eImage );
	Writer_Image( U, Image2DMS, R8, eImage );
	Writer_Image( U, Image2DMSArray, R8, eImage );
	Writer_Texture( U, TextureBuffer, R8, eTexture );
	Writer_Texture( U, Texture1D, R8, eTexture );
	Writer_Texture( U, Texture2D, R8, eTexture );
	Writer_Texture( U, Texture3D, R8, eTexture );
	Writer_Texture( U, TextureCube, R8, eTexture );
	Writer_Texture( U, Texture1DArray, R8, eTexture );
	Writer_Texture( U, Texture2DArray, R8, eTexture );
	Writer_Texture( U, TextureCubeArray, R8, eTexture );
	Writer_Texture( U, Texture2DMS, R8, eTexture );
	Writer_Texture( U, Texture2DMSArray, R8, eTexture );

#undef Writer_Texture
#undef Writer_Image

	//***********************************************************************************************

	template< typename T >
	struct RealTypeGetter
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeGetter< InParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeGetter< OutParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeGetter< InOutParam< T > >
	{
		using Type = T;
	};

	//***********************************************************************************************
}
