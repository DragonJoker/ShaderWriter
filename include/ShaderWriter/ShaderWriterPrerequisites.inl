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
	struct TypeTraits< CombinedImage >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eCombinedImage;
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
	struct TypeTraits< StorageImage >
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

#define Writer_StorageImage( Prefix, TypeName, Format )\
	template<>\
	struct TypeTraits< R##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eImage;\
	};\
	template<>\
	struct TypeTraits< W##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eImage;\
	};\
	template<>\
	struct TypeTraits< RW##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eImage;\
	}

#define Writer_UniformImage( Type, Prefix, TypeName, Format, Value )\
	template<>\
	struct TypeTraits< Type##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	}

#	define Writer_CombinedImage( Prefix, TypeName, Format )\
		Writer_UniformImage( Prefix, Combined, TypeName, Format, eCombinedImage )

#	define Writer_SampledImage( Prefix, TypeName, Format )\
		Writer_UniformImage( Prefix, Sampled, TypeName, Format, eSampledImage )

	Writer_StorageImage( , ImageBuffer, Rgba32 );
	Writer_StorageImage( , Image1D, Rgba32 );
	Writer_StorageImage( , Image2D, Rgba32 );
	Writer_StorageImage( , Image3D, Rgba32 );
	Writer_StorageImage( , ImageCube, Rgba32 );
	Writer_StorageImage( , Image1DArray, Rgba32 );
	Writer_StorageImage( , Image2DArray, Rgba32 );
	Writer_StorageImage( , ImageCubeArray, Rgba32 );
	Writer_StorageImage( , Image2DMS, Rgba32 );
	Writer_StorageImage( , Image2DMSArray, Rgba32 );
	Writer_CombinedImage( , ImageBuffer, Rgba32 );
	Writer_CombinedImage( , Image1D, Rgba32 );
	Writer_CombinedImage( , Image2D, Rgba32 );
	Writer_CombinedImage( , Image3D, Rgba32 );
	Writer_CombinedImage( , ImageCube, Rgba32 );
	Writer_CombinedImage( , Image1DArray, Rgba32 );
	Writer_CombinedImage( , Image2DArray, Rgba32 );
	Writer_CombinedImage( , ImageCubeArray, Rgba32 );
	Writer_CombinedImage( , Image2DMS, Rgba32 );
	Writer_CombinedImage( , Image2DMSArray, Rgba32 );
	Writer_SampledImage( , ImageBuffer, Rgba32 );
	Writer_SampledImage( , Image1D, Rgba32 );
	Writer_SampledImage( , Image2D, Rgba32 );
	Writer_SampledImage( , Image3D, Rgba32 );
	Writer_SampledImage( , ImageCube, Rgba32 );
	Writer_SampledImage( , Image1DArray, Rgba32 );
	Writer_SampledImage( , Image2DArray, Rgba32 );
	Writer_SampledImage( , ImageCubeArray, Rgba32 );
	Writer_SampledImage( , Image2DMS, Rgba32 );
	Writer_SampledImage( , Image2DMSArray, Rgba32 );
	Writer_StorageImage( , ImageBuffer, Rgba16 );
	Writer_StorageImage( , Image1D, Rgba16 );
	Writer_StorageImage( , Image2D, Rgba16 );
	Writer_StorageImage( , Image3D, Rgba16 );
	Writer_StorageImage( , ImageCube, Rgba16 );
	Writer_StorageImage( , Image1DArray, Rgba16 );
	Writer_StorageImage( , Image2DArray, Rgba16 );
	Writer_StorageImage( , ImageCubeArray, Rgba16 );
	Writer_StorageImage( , Image2DMS, Rgba16 );
	Writer_StorageImage( , Image2DMSArray, Rgba16 );
	Writer_CombinedImage( , ImageBuffer, Rgba16 );
	Writer_CombinedImage( , Image1D, Rgba16 );
	Writer_CombinedImage( , Image2D, Rgba16 );
	Writer_CombinedImage( , Image3D, Rgba16 );
	Writer_CombinedImage( , ImageCube, Rgba16 );
	Writer_CombinedImage( , Image1DArray, Rgba16 );
	Writer_CombinedImage( , Image2DArray, Rgba16 );
	Writer_CombinedImage( , ImageCubeArray, Rgba16 );
	Writer_CombinedImage( , Image2DMS, Rgba16 );
	Writer_CombinedImage( , Image2DMSArray, Rgba16 );
	Writer_SampledImage( , ImageBuffer, Rgba16 );
	Writer_SampledImage( , Image1D, Rgba16 );
	Writer_SampledImage( , Image2D, Rgba16 );
	Writer_SampledImage( , Image3D, Rgba16 );
	Writer_SampledImage( , ImageCube, Rgba16 );
	Writer_SampledImage( , Image1DArray, Rgba16 );
	Writer_SampledImage( , Image2DArray, Rgba16 );
	Writer_SampledImage( , ImageCubeArray, Rgba16 );
	Writer_SampledImage( , Image2DMS, Rgba16 );
	Writer_SampledImage( , Image2DMSArray, Rgba16 );
	Writer_StorageImage( , ImageBuffer, Rg32 );
	Writer_StorageImage( , Image1D, Rg32 );
	Writer_StorageImage( , Image2D, Rg32 );
	Writer_StorageImage( , Image3D, Rg32 );
	Writer_StorageImage( , ImageCube, Rg32 );
	Writer_StorageImage( , Image1DArray, Rg32 );
	Writer_StorageImage( , Image2DArray, Rg32 );
	Writer_StorageImage( , ImageCubeArray, Rg32 );
	Writer_StorageImage( , Image2DMS, Rg32 );
	Writer_StorageImage( , Image2DMSArray, Rg32 );
	Writer_CombinedImage( , ImageBuffer, Rg32 );
	Writer_CombinedImage( , Image1D, Rg32 );
	Writer_CombinedImage( , Image2D, Rg32 );
	Writer_CombinedImage( , Image3D, Rg32 );
	Writer_CombinedImage( , ImageCube, Rg32 );
	Writer_CombinedImage( , Image1DArray, Rg32 );
	Writer_CombinedImage( , Image2DArray, Rg32 );
	Writer_CombinedImage( , ImageCubeArray, Rg32 );
	Writer_CombinedImage( , Image2DMS, Rg32 );
	Writer_CombinedImage( , Image2DMSArray, Rg32 );
	Writer_SampledImage( , ImageBuffer, Rg32 );
	Writer_SampledImage( , Image1D, Rg32 );
	Writer_SampledImage( , Image2D, Rg32 );
	Writer_SampledImage( , Image3D, Rg32 );
	Writer_SampledImage( , ImageCube, Rg32 );
	Writer_SampledImage( , Image1DArray, Rg32 );
	Writer_SampledImage( , Image2DArray, Rg32 );
	Writer_SampledImage( , ImageCubeArray, Rg32 );
	Writer_SampledImage( , Image2DMS, Rg32 );
	Writer_SampledImage( , Image2DMSArray, Rg32 );
	Writer_StorageImage( , ImageBuffer, Rg16 );
	Writer_StorageImage( , Image1D, Rg16 );
	Writer_StorageImage( , Image2D, Rg16 );
	Writer_StorageImage( , Image3D, Rg16 );
	Writer_StorageImage( , ImageCube, Rg16 );
	Writer_StorageImage( , Image1DArray, Rg16 );
	Writer_StorageImage( , Image2DArray, Rg16 );
	Writer_StorageImage( , ImageCubeArray, Rg16 );
	Writer_StorageImage( , Image2DMS, Rg16 );
	Writer_StorageImage( , Image2DMSArray, Rg16 );
	Writer_CombinedImage( , ImageBuffer, Rg16 );
	Writer_CombinedImage( , Image1D, Rg16 );
	Writer_CombinedImage( , Image2D, Rg16 );
	Writer_CombinedImage( , Image3D, Rg16 );
	Writer_CombinedImage( , ImageCube, Rg16 );
	Writer_CombinedImage( , Image1DArray, Rg16 );
	Writer_CombinedImage( , Image2DArray, Rg16 );
	Writer_CombinedImage( , ImageCubeArray, Rg16 );
	Writer_CombinedImage( , Image2DMS, Rg16 );
	Writer_CombinedImage( , Image2DMSArray, Rg16 );
	Writer_SampledImage( , ImageBuffer, Rg16 );
	Writer_SampledImage( , Image1D, Rg16 );
	Writer_SampledImage( , Image2D, Rg16 );
	Writer_SampledImage( , Image3D, Rg16 );
	Writer_SampledImage( , ImageCube, Rg16 );
	Writer_SampledImage( , Image1DArray, Rg16 );
	Writer_SampledImage( , Image2DArray, Rg16 );
	Writer_SampledImage( , ImageCubeArray, Rg16 );
	Writer_SampledImage( , Image2DMS, Rg16 );
	Writer_SampledImage( , Image2DMSArray, Rg16 );
	Writer_StorageImage( , ImageBuffer, R32 );
	Writer_StorageImage( , Image1D, R32 );
	Writer_StorageImage( , Image2D, R32 );
	Writer_StorageImage( , Image3D, R32 );
	Writer_StorageImage( , ImageCube, R32 );
	Writer_StorageImage( , Image1DArray, R32 );
	Writer_StorageImage( , Image2DArray, R32 );
	Writer_StorageImage( , ImageCubeArray, R32 );
	Writer_StorageImage( , Image2DMS, R32 );
	Writer_StorageImage( , Image2DMSArray, R32 );
	Writer_CombinedImage( , ImageBuffer, R32 );
	Writer_CombinedImage( , Image1D, R32 );
	Writer_CombinedImage( , Image2D, R32 );
	Writer_CombinedImage( , Image3D, R32 );
	Writer_CombinedImage( , ImageCube, R32 );
	Writer_CombinedImage( , Image1DArray, R32 );
	Writer_CombinedImage( , Image2DArray, R32 );
	Writer_CombinedImage( , ImageCubeArray, R32 );
	Writer_CombinedImage( , Image2DMS, R32 );
	Writer_CombinedImage( , Image2DMSArray, R32 );
	Writer_SampledImage( , ImageBuffer, R32 );
	Writer_SampledImage( , Image1D, R32 );
	Writer_SampledImage( , Image2D, R32 );
	Writer_SampledImage( , Image3D, R32 );
	Writer_SampledImage( , ImageCube, R32 );
	Writer_SampledImage( , Image1DArray, R32 );
	Writer_SampledImage( , Image2DArray, R32 );
	Writer_SampledImage( , ImageCubeArray, R32 );
	Writer_SampledImage( , Image2DMS, R32 );
	Writer_SampledImage( , Image2DMSArray, R32 );
	Writer_StorageImage( , ImageBuffer, R16 );
	Writer_StorageImage( , Image1D, R16 );
	Writer_StorageImage( , Image2D, R16 );
	Writer_StorageImage( , Image3D, R16 );
	Writer_StorageImage( , ImageCube, R16 );
	Writer_StorageImage( , Image1DArray, R16 );
	Writer_StorageImage( , Image2DArray, R16 );
	Writer_StorageImage( , ImageCubeArray, R16 );
	Writer_StorageImage( , Image2DMS, R16 );
	Writer_StorageImage( , Image2DMSArray, R16 );
	Writer_CombinedImage( , ImageBuffer, R16 );
	Writer_CombinedImage( , Image1D, R16 );
	Writer_CombinedImage( , Image2D, R16 );
	Writer_CombinedImage( , Image3D, R16 );
	Writer_CombinedImage( , ImageCube, R16 );
	Writer_CombinedImage( , Image1DArray, R16 );
	Writer_CombinedImage( , Image2DArray, R16 );
	Writer_CombinedImage( , ImageCubeArray, R16 );
	Writer_CombinedImage( , Image2DMS, R16 );
	Writer_CombinedImage( , Image2DMSArray, R16 );
	Writer_SampledImage( , ImageBuffer, R16 );
	Writer_SampledImage( , Image1D, R16 );
	Writer_SampledImage( , Image2D, R16 );
	Writer_SampledImage( , Image3D, R16 );
	Writer_SampledImage( , ImageCube, R16 );
	Writer_SampledImage( , Image1DArray, R16 );
	Writer_SampledImage( , Image2DArray, R16 );
	Writer_SampledImage( , ImageCubeArray, R16 );
	Writer_SampledImage( , Image2DMS, R16 );
	Writer_SampledImage( , Image2DMSArray, R16 );
	Writer_CombinedImage( , Image1DShadow, R32 );
	Writer_CombinedImage( , Image2DShadow, R32 );
	Writer_CombinedImage( , ImageCubeShadow, R32 );
	Writer_CombinedImage( , Image1DArrayShadow, R32 );
	Writer_CombinedImage( , Image2DArrayShadow, R32 );
	Writer_CombinedImage( , ImageCubeArrayShadow, R32 );
	Writer_CombinedImage( , Image1DShadow, R16 );
	Writer_CombinedImage( , Image2DShadow, R16 );
	Writer_CombinedImage( , ImageCubeShadow, R16 );
	Writer_CombinedImage( , Image1DArrayShadow, R16 );
	Writer_CombinedImage( , Image2DArrayShadow, R16 );
	Writer_CombinedImage( , ImageCubeArrayShadow, R16 );
	Writer_StorageImage( I, ImageBuffer, Rgba32 );
	Writer_StorageImage( I, Image1D, Rgba32 );
	Writer_StorageImage( I, Image2D, Rgba32 );
	Writer_StorageImage( I, Image3D, Rgba32 );
	Writer_StorageImage( I, ImageCube, Rgba32 );
	Writer_StorageImage( I, Image1DArray, Rgba32 );
	Writer_StorageImage( I, Image2DArray, Rgba32 );
	Writer_StorageImage( I, ImageCubeArray, Rgba32 );
	Writer_StorageImage( I, Image2DMS, Rgba32 );
	Writer_StorageImage( I, Image2DMSArray, Rgba32 );
	Writer_CombinedImage( I, ImageBuffer, Rgba32 );
	Writer_CombinedImage( I, Image1D, Rgba32 );
	Writer_CombinedImage( I, Image2D, Rgba32 );
	Writer_CombinedImage( I, Image3D, Rgba32 );
	Writer_CombinedImage( I, ImageCube, Rgba32 );
	Writer_CombinedImage( I, Image1DArray, Rgba32 );
	Writer_CombinedImage( I, Image2DArray, Rgba32 );
	Writer_CombinedImage( I, ImageCubeArray, Rgba32 );
	Writer_CombinedImage( I, Image2DMS, Rgba32 );
	Writer_CombinedImage( I, Image2DMSArray, Rgba32 );
	Writer_SampledImage( I, ImageBuffer, Rgba32 );
	Writer_SampledImage( I, Image1D, Rgba32 );
	Writer_SampledImage( I, Image2D, Rgba32 );
	Writer_SampledImage( I, Image3D, Rgba32 );
	Writer_SampledImage( I, ImageCube, Rgba32 );
	Writer_SampledImage( I, Image1DArray, Rgba32 );
	Writer_SampledImage( I, Image2DArray, Rgba32 );
	Writer_SampledImage( I, ImageCubeArray, Rgba32 );
	Writer_SampledImage( I, Image2DMS, Rgba32 );
	Writer_SampledImage( I, Image2DMSArray, Rgba32 );
	Writer_StorageImage( I, ImageBuffer, Rgba16 );
	Writer_StorageImage( I, Image1D, Rgba16 );
	Writer_StorageImage( I, Image2D, Rgba16 );
	Writer_StorageImage( I, Image3D, Rgba16 );
	Writer_StorageImage( I, ImageCube, Rgba16 );
	Writer_StorageImage( I, Image1DArray, Rgba16 );
	Writer_StorageImage( I, Image2DArray, Rgba16 );
	Writer_StorageImage( I, ImageCubeArray, Rgba16 );
	Writer_StorageImage( I, Image2DMS, Rgba16 );
	Writer_StorageImage( I, Image2DMSArray, Rgba16 );
	Writer_CombinedImage( I, ImageBuffer, Rgba16 );
	Writer_CombinedImage( I, Image1D, Rgba16 );
	Writer_CombinedImage( I, Image2D, Rgba16 );
	Writer_CombinedImage( I, Image3D, Rgba16 );
	Writer_CombinedImage( I, ImageCube, Rgba16 );
	Writer_CombinedImage( I, Image1DArray, Rgba16 );
	Writer_CombinedImage( I, Image2DArray, Rgba16 );
	Writer_CombinedImage( I, ImageCubeArray, Rgba16 );
	Writer_CombinedImage( I, Image2DMS, Rgba16 );
	Writer_CombinedImage( I, Image2DMSArray, Rgba16 );
	Writer_SampledImage( I, ImageBuffer, Rgba16 );
	Writer_SampledImage( I, Image1D, Rgba16 );
	Writer_SampledImage( I, Image2D, Rgba16 );
	Writer_SampledImage( I, Image3D, Rgba16 );
	Writer_SampledImage( I, ImageCube, Rgba16 );
	Writer_SampledImage( I, Image1DArray, Rgba16 );
	Writer_SampledImage( I, Image2DArray, Rgba16 );
	Writer_SampledImage( I, ImageCubeArray, Rgba16 );
	Writer_SampledImage( I, Image2DMS, Rgba16 );
	Writer_SampledImage( I, Image2DMSArray, Rgba16 );
	Writer_StorageImage( I, ImageBuffer, Rgba8 );
	Writer_StorageImage( I, Image1D, Rgba8 );
	Writer_StorageImage( I, Image2D, Rgba8 );
	Writer_StorageImage( I, Image3D, Rgba8 );
	Writer_StorageImage( I, ImageCube, Rgba8 );
	Writer_StorageImage( I, Image1DArray, Rgba8 );
	Writer_StorageImage( I, Image2DArray, Rgba8 );
	Writer_StorageImage( I, ImageCubeArray, Rgba8 );
	Writer_StorageImage( I, Image2DMS, Rgba8 );
	Writer_StorageImage( I, Image2DMSArray, Rgba8 );
	Writer_CombinedImage( I, ImageBuffer, Rgba8 );
	Writer_CombinedImage( I, Image1D, Rgba8 );
	Writer_CombinedImage( I, Image2D, Rgba8 );
	Writer_CombinedImage( I, Image3D, Rgba8 );
	Writer_CombinedImage( I, ImageCube, Rgba8 );
	Writer_CombinedImage( I, Image1DArray, Rgba8 );
	Writer_CombinedImage( I, Image2DArray, Rgba8 );
	Writer_CombinedImage( I, ImageCubeArray, Rgba8 );
	Writer_CombinedImage( I, Image2DMS, Rgba8 );
	Writer_CombinedImage( I, Image2DMSArray, Rgba8 );
	Writer_SampledImage( I, ImageBuffer, Rgba8 );
	Writer_SampledImage( I, Image1D, Rgba8 );
	Writer_SampledImage( I, Image2D, Rgba8 );
	Writer_SampledImage( I, Image3D, Rgba8 );
	Writer_SampledImage( I, ImageCube, Rgba8 );
	Writer_SampledImage( I, Image1DArray, Rgba8 );
	Writer_SampledImage( I, Image2DArray, Rgba8 );
	Writer_SampledImage( I, ImageCubeArray, Rgba8 );
	Writer_SampledImage( I, Image2DMS, Rgba8 );
	Writer_SampledImage( I, Image2DMSArray, Rgba8 );
	Writer_StorageImage( I, ImageBuffer, Rg32 );
	Writer_StorageImage( I, Image1D, Rg32 );
	Writer_StorageImage( I, Image2D, Rg32 );
	Writer_StorageImage( I, Image3D, Rg32 );
	Writer_StorageImage( I, ImageCube, Rg32 );
	Writer_StorageImage( I, Image1DArray, Rg32 );
	Writer_StorageImage( I, Image2DArray, Rg32 );
	Writer_StorageImage( I, ImageCubeArray, Rg32 );
	Writer_StorageImage( I, Image2DMS, Rg32 );
	Writer_StorageImage( I, Image2DMSArray, Rg32 );
	Writer_CombinedImage( I, ImageBuffer, Rg32 );
	Writer_CombinedImage( I, Image1D, Rg32 );
	Writer_CombinedImage( I, Image2D, Rg32 );
	Writer_CombinedImage( I, Image3D, Rg32 );
	Writer_CombinedImage( I, ImageCube, Rg32 );
	Writer_CombinedImage( I, Image1DArray, Rg32 );
	Writer_CombinedImage( I, Image2DArray, Rg32 );
	Writer_CombinedImage( I, ImageCubeArray, Rg32 );
	Writer_CombinedImage( I, Image2DMS, Rg32 );
	Writer_CombinedImage( I, Image2DMSArray, Rg32 );
	Writer_SampledImage( I, ImageBuffer, Rg32 );
	Writer_SampledImage( I, Image1D, Rg32 );
	Writer_SampledImage( I, Image2D, Rg32 );
	Writer_SampledImage( I, Image3D, Rg32 );
	Writer_SampledImage( I, ImageCube, Rg32 );
	Writer_SampledImage( I, Image1DArray, Rg32 );
	Writer_SampledImage( I, Image2DArray, Rg32 );
	Writer_SampledImage( I, ImageCubeArray, Rg32 );
	Writer_SampledImage( I, Image2DMS, Rg32 );
	Writer_SampledImage( I, Image2DMSArray, Rg32 );
	Writer_StorageImage( I, ImageBuffer, Rg16 );
	Writer_StorageImage( I, Image1D, Rg16 );
	Writer_StorageImage( I, Image2D, Rg16 );
	Writer_StorageImage( I, Image3D, Rg16 );
	Writer_StorageImage( I, ImageCube, Rg16 );
	Writer_StorageImage( I, Image1DArray, Rg16 );
	Writer_StorageImage( I, Image2DArray, Rg16 );
	Writer_StorageImage( I, ImageCubeArray, Rg16 );
	Writer_StorageImage( I, Image2DMS, Rg16 );
	Writer_StorageImage( I, Image2DMSArray, Rg16 );
	Writer_CombinedImage( I, ImageBuffer, Rg16 );
	Writer_CombinedImage( I, Image1D, Rg16 );
	Writer_CombinedImage( I, Image2D, Rg16 );
	Writer_CombinedImage( I, Image3D, Rg16 );
	Writer_CombinedImage( I, ImageCube, Rg16 );
	Writer_CombinedImage( I, Image1DArray, Rg16 );
	Writer_CombinedImage( I, Image2DArray, Rg16 );
	Writer_CombinedImage( I, ImageCubeArray, Rg16 );
	Writer_CombinedImage( I, Image2DMS, Rg16 );
	Writer_CombinedImage( I, Image2DMSArray, Rg16 );
	Writer_SampledImage( I, ImageBuffer, Rg16 );
	Writer_SampledImage( I, Image1D, Rg16 );
	Writer_SampledImage( I, Image2D, Rg16 );
	Writer_SampledImage( I, Image3D, Rg16 );
	Writer_SampledImage( I, ImageCube, Rg16 );
	Writer_SampledImage( I, Image1DArray, Rg16 );
	Writer_SampledImage( I, Image2DArray, Rg16 );
	Writer_SampledImage( I, ImageCubeArray, Rg16 );
	Writer_SampledImage( I, Image2DMS, Rg16 );
	Writer_SampledImage( I, Image2DMSArray, Rg16 );
	Writer_StorageImage( I, ImageBuffer, Rg8 );
	Writer_StorageImage( I, Image1D, Rg8 );
	Writer_StorageImage( I, Image2D, Rg8 );
	Writer_StorageImage( I, Image3D, Rg8 );
	Writer_StorageImage( I, ImageCube, Rg8 );
	Writer_StorageImage( I, Image1DArray, Rg8 );
	Writer_StorageImage( I, Image2DArray, Rg8 );
	Writer_StorageImage( I, ImageCubeArray, Rg8 );
	Writer_StorageImage( I, Image2DMS, Rg8 );
	Writer_StorageImage( I, Image2DMSArray, Rg8 );
	Writer_CombinedImage( I, ImageBuffer, Rg8 );
	Writer_CombinedImage( I, Image1D, Rg8 );
	Writer_CombinedImage( I, Image2D, Rg8 );
	Writer_CombinedImage( I, Image3D, Rg8 );
	Writer_CombinedImage( I, ImageCube, Rg8 );
	Writer_CombinedImage( I, Image1DArray, Rg8 );
	Writer_CombinedImage( I, Image2DArray, Rg8 );
	Writer_CombinedImage( I, ImageCubeArray, Rg8 );
	Writer_CombinedImage( I, Image2DMS, Rg8 );
	Writer_CombinedImage( I, Image2DMSArray, Rg8 );
	Writer_SampledImage( I, ImageBuffer, Rg8 );
	Writer_SampledImage( I, Image1D, Rg8 );
	Writer_SampledImage( I, Image2D, Rg8 );
	Writer_SampledImage( I, Image3D, Rg8 );
	Writer_SampledImage( I, ImageCube, Rg8 );
	Writer_SampledImage( I, Image1DArray, Rg8 );
	Writer_SampledImage( I, Image2DArray, Rg8 );
	Writer_SampledImage( I, ImageCubeArray, Rg8 );
	Writer_SampledImage( I, Image2DMS, Rg8 );
	Writer_SampledImage( I, Image2DMSArray, Rg8 );
	Writer_StorageImage( I, ImageBuffer, R32 );
	Writer_StorageImage( I, Image1D, R32 );
	Writer_StorageImage( I, Image2D, R32 );
	Writer_StorageImage( I, Image3D, R32 );
	Writer_StorageImage( I, ImageCube, R32 );
	Writer_StorageImage( I, Image1DArray, R32 );
	Writer_StorageImage( I, Image2DArray, R32 );
	Writer_StorageImage( I, ImageCubeArray, R32 );
	Writer_StorageImage( I, Image2DMS, R32 );
	Writer_StorageImage( I, Image2DMSArray, R32 );
	Writer_CombinedImage( I, ImageBuffer, R32 );
	Writer_CombinedImage( I, Image1D, R32 );
	Writer_CombinedImage( I, Image2D, R32 );
	Writer_CombinedImage( I, Image3D, R32 );
	Writer_CombinedImage( I, ImageCube, R32 );
	Writer_CombinedImage( I, Image1DArray, R32 );
	Writer_CombinedImage( I, Image2DArray, R32 );
	Writer_CombinedImage( I, ImageCubeArray, R32 );
	Writer_CombinedImage( I, Image2DMS, R32 );
	Writer_CombinedImage( I, Image2DMSArray, R32 );
	Writer_SampledImage( I, ImageBuffer, R32 );
	Writer_SampledImage( I, Image1D, R32 );
	Writer_SampledImage( I, Image2D, R32 );
	Writer_SampledImage( I, Image3D, R32 );
	Writer_SampledImage( I, ImageCube, R32 );
	Writer_SampledImage( I, Image1DArray, R32 );
	Writer_SampledImage( I, Image2DArray, R32 );
	Writer_SampledImage( I, ImageCubeArray, R32 );
	Writer_SampledImage( I, Image2DMS, R32 );
	Writer_SampledImage( I, Image2DMSArray, R32 );
	Writer_StorageImage( I, ImageBuffer, R16 );
	Writer_StorageImage( I, Image1D, R16 );
	Writer_StorageImage( I, Image2D, R16 );
	Writer_StorageImage( I, Image3D, R16 );
	Writer_StorageImage( I, ImageCube, R16 );
	Writer_StorageImage( I, Image1DArray, R16 );
	Writer_StorageImage( I, Image2DArray, R16 );
	Writer_StorageImage( I, ImageCubeArray, R16 );
	Writer_StorageImage( I, Image2DMS, R16 );
	Writer_StorageImage( I, Image2DMSArray, R16 );
	Writer_CombinedImage( I, ImageBuffer, R16 );
	Writer_CombinedImage( I, Image1D, R16 );
	Writer_CombinedImage( I, Image2D, R16 );
	Writer_CombinedImage( I, Image3D, R16 );
	Writer_CombinedImage( I, ImageCube, R16 );
	Writer_CombinedImage( I, Image1DArray, R16 );
	Writer_CombinedImage( I, Image2DArray, R16 );
	Writer_CombinedImage( I, ImageCubeArray, R16 );
	Writer_CombinedImage( I, Image2DMS, R16 );
	Writer_CombinedImage( I, Image2DMSArray, R16 );
	Writer_SampledImage( I, ImageBuffer, R16 );
	Writer_SampledImage( I, Image1D, R16 );
	Writer_SampledImage( I, Image2D, R16 );
	Writer_SampledImage( I, Image3D, R16 );
	Writer_SampledImage( I, ImageCube, R16 );
	Writer_SampledImage( I, Image1DArray, R16 );
	Writer_SampledImage( I, Image2DArray, R16 );
	Writer_SampledImage( I, ImageCubeArray, R16 );
	Writer_SampledImage( I, Image2DMS, R16 );
	Writer_SampledImage( I, Image2DMSArray, R16 );
	Writer_StorageImage( I, ImageBuffer, R8 );
	Writer_StorageImage( I, Image1D, R8 );
	Writer_StorageImage( I, Image2D, R8 );
	Writer_StorageImage( I, Image3D, R8 );
	Writer_StorageImage( I, ImageCube, R8 );
	Writer_StorageImage( I, Image1DArray, R8 );
	Writer_StorageImage( I, Image2DArray, R8 );
	Writer_StorageImage( I, ImageCubeArray, R8 );
	Writer_StorageImage( I, Image2DMS, R8 );
	Writer_StorageImage( I, Image2DMSArray, R8 );
	Writer_CombinedImage( I, ImageBuffer, R8 );
	Writer_CombinedImage( I, Image1D, R8 );
	Writer_CombinedImage( I, Image2D, R8 );
	Writer_CombinedImage( I, Image3D, R8 );
	Writer_CombinedImage( I, ImageCube, R8 );
	Writer_CombinedImage( I, Image1DArray, R8 );
	Writer_CombinedImage( I, Image2DArray, R8 );
	Writer_CombinedImage( I, ImageCubeArray, R8 );
	Writer_CombinedImage( I, Image2DMS, R8 );
	Writer_CombinedImage( I, Image2DMSArray, R8 );
	Writer_SampledImage( I, ImageBuffer, R8 );
	Writer_SampledImage( I, Image1D, R8 );
	Writer_SampledImage( I, Image2D, R8 );
	Writer_SampledImage( I, Image3D, R8 );
	Writer_SampledImage( I, ImageCube, R8 );
	Writer_SampledImage( I, Image1DArray, R8 );
	Writer_SampledImage( I, Image2DArray, R8 );
	Writer_SampledImage( I, ImageCubeArray, R8 );
	Writer_SampledImage( I, Image2DMS, R8 );
	Writer_SampledImage( I, Image2DMSArray, R8 );
	Writer_StorageImage( U, ImageBuffer, Rgba32 );
	Writer_StorageImage( U, Image1D, Rgba32 );
	Writer_StorageImage( U, Image2D, Rgba32 );
	Writer_StorageImage( U, Image3D, Rgba32 );
	Writer_StorageImage( U, ImageCube, Rgba32 );
	Writer_StorageImage( U, Image1DArray, Rgba32 );
	Writer_StorageImage( U, Image2DArray, Rgba32 );
	Writer_StorageImage( U, ImageCubeArray, Rgba32 );
	Writer_StorageImage( U, Image2DMS, Rgba32 );
	Writer_StorageImage( U, Image2DMSArray, Rgba32 );
	Writer_CombinedImage( U, ImageBuffer, Rgba32 );
	Writer_CombinedImage( U, Image1D, Rgba32 );
	Writer_CombinedImage( U, Image2D, Rgba32 );
	Writer_CombinedImage( U, Image3D, Rgba32 );
	Writer_CombinedImage( U, ImageCube, Rgba32 );
	Writer_CombinedImage( U, Image1DArray, Rgba32 );
	Writer_CombinedImage( U, Image2DArray, Rgba32 );
	Writer_CombinedImage( U, ImageCubeArray, Rgba32 );
	Writer_CombinedImage( U, Image2DMS, Rgba32 );
	Writer_CombinedImage( U, Image2DMSArray, Rgba32 );
	Writer_SampledImage( U, ImageBuffer, Rgba32 );
	Writer_SampledImage( U, Image1D, Rgba32 );
	Writer_SampledImage( U, Image2D, Rgba32 );
	Writer_SampledImage( U, Image3D, Rgba32 );
	Writer_SampledImage( U, ImageCube, Rgba32 );
	Writer_SampledImage( U, Image1DArray, Rgba32 );
	Writer_SampledImage( U, Image2DArray, Rgba32 );
	Writer_SampledImage( U, ImageCubeArray, Rgba32 );
	Writer_SampledImage( U, Image2DMS, Rgba32 );
	Writer_SampledImage( U, Image2DMSArray, Rgba32 );
	Writer_StorageImage( U, ImageBuffer, Rgba16 );
	Writer_StorageImage( U, Image1D, Rgba16 );
	Writer_StorageImage( U, Image2D, Rgba16 );
	Writer_StorageImage( U, Image3D, Rgba16 );
	Writer_StorageImage( U, ImageCube, Rgba16 );
	Writer_StorageImage( U, Image1DArray, Rgba16 );
	Writer_StorageImage( U, Image2DArray, Rgba16 );
	Writer_StorageImage( U, ImageCubeArray, Rgba16 );
	Writer_StorageImage( U, Image2DMS, Rgba16 );
	Writer_StorageImage( U, Image2DMSArray, Rgba16 );
	Writer_CombinedImage( U, ImageBuffer, Rgba16 );
	Writer_CombinedImage( U, Image1D, Rgba16 );
	Writer_CombinedImage( U, Image2D, Rgba16 );
	Writer_CombinedImage( U, Image3D, Rgba16 );
	Writer_CombinedImage( U, ImageCube, Rgba16 );
	Writer_CombinedImage( U, Image1DArray, Rgba16 );
	Writer_CombinedImage( U, Image2DArray, Rgba16 );
	Writer_CombinedImage( U, ImageCubeArray, Rgba16 );
	Writer_CombinedImage( U, Image2DMS, Rgba16 );
	Writer_CombinedImage( U, Image2DMSArray, Rgba16 );
	Writer_SampledImage( U, ImageBuffer, Rgba16 );
	Writer_SampledImage( U, Image1D, Rgba16 );
	Writer_SampledImage( U, Image2D, Rgba16 );
	Writer_SampledImage( U, Image3D, Rgba16 );
	Writer_SampledImage( U, ImageCube, Rgba16 );
	Writer_SampledImage( U, Image1DArray, Rgba16 );
	Writer_SampledImage( U, Image2DArray, Rgba16 );
	Writer_SampledImage( U, ImageCubeArray, Rgba16 );
	Writer_SampledImage( U, Image2DMS, Rgba16 );
	Writer_SampledImage( U, Image2DMSArray, Rgba16 );
	Writer_StorageImage( U, ImageBuffer, Rgba8 );
	Writer_StorageImage( U, Image1D, Rgba8 );
	Writer_StorageImage( U, Image2D, Rgba8 );
	Writer_StorageImage( U, Image3D, Rgba8 );
	Writer_StorageImage( U, ImageCube, Rgba8 );
	Writer_StorageImage( U, Image1DArray, Rgba8 );
	Writer_StorageImage( U, Image2DArray, Rgba8 );
	Writer_StorageImage( U, ImageCubeArray, Rgba8 );
	Writer_StorageImage( U, Image2DMS, Rgba8 );
	Writer_StorageImage( U, Image2DMSArray, Rgba8 );
	Writer_CombinedImage( U, ImageBuffer, Rgba8 );
	Writer_CombinedImage( U, Image1D, Rgba8 );
	Writer_CombinedImage( U, Image2D, Rgba8 );
	Writer_CombinedImage( U, Image3D, Rgba8 );
	Writer_CombinedImage( U, ImageCube, Rgba8 );
	Writer_CombinedImage( U, Image1DArray, Rgba8 );
	Writer_CombinedImage( U, Image2DArray, Rgba8 );
	Writer_CombinedImage( U, ImageCubeArray, Rgba8 );
	Writer_CombinedImage( U, Image2DMS, Rgba8 );
	Writer_CombinedImage( U, Image2DMSArray, Rgba8 );
	Writer_SampledImage( U, ImageBuffer, Rgba8 );
	Writer_SampledImage( U, Image1D, Rgba8 );
	Writer_SampledImage( U, Image2D, Rgba8 );
	Writer_SampledImage( U, Image3D, Rgba8 );
	Writer_SampledImage( U, ImageCube, Rgba8 );
	Writer_SampledImage( U, Image1DArray, Rgba8 );
	Writer_SampledImage( U, Image2DArray, Rgba8 );
	Writer_SampledImage( U, ImageCubeArray, Rgba8 );
	Writer_SampledImage( U, Image2DMS, Rgba8 );
	Writer_SampledImage( U, Image2DMSArray, Rgba8 );
	Writer_StorageImage( U, ImageBuffer, Rg32 );
	Writer_StorageImage( U, Image1D, Rg32 );
	Writer_StorageImage( U, Image2D, Rg32 );
	Writer_StorageImage( U, Image3D, Rg32 );
	Writer_StorageImage( U, ImageCube, Rg32 );
	Writer_StorageImage( U, Image1DArray, Rg32 );
	Writer_StorageImage( U, Image2DArray, Rg32 );
	Writer_StorageImage( U, ImageCubeArray, Rg32 );
	Writer_StorageImage( U, Image2DMS, Rg32 );
	Writer_StorageImage( U, Image2DMSArray, Rg32 );
	Writer_CombinedImage( U, ImageBuffer, Rg32 );
	Writer_CombinedImage( U, Image1D, Rg32 );
	Writer_CombinedImage( U, Image2D, Rg32 );
	Writer_CombinedImage( U, Image3D, Rg32 );
	Writer_CombinedImage( U, ImageCube, Rg32 );
	Writer_CombinedImage( U, Image1DArray, Rg32 );
	Writer_CombinedImage( U, Image2DArray, Rg32 );
	Writer_CombinedImage( U, ImageCubeArray, Rg32 );
	Writer_CombinedImage( U, Image2DMS, Rg32 );
	Writer_CombinedImage( U, Image2DMSArray, Rg32 );
	Writer_SampledImage( U, ImageBuffer, Rg32 );
	Writer_SampledImage( U, Image1D, Rg32 );
	Writer_SampledImage( U, Image2D, Rg32 );
	Writer_SampledImage( U, Image3D, Rg32 );
	Writer_SampledImage( U, ImageCube, Rg32 );
	Writer_SampledImage( U, Image1DArray, Rg32 );
	Writer_SampledImage( U, Image2DArray, Rg32 );
	Writer_SampledImage( U, ImageCubeArray, Rg32 );
	Writer_SampledImage( U, Image2DMS, Rg32 );
	Writer_SampledImage( U, Image2DMSArray, Rg32 );
	Writer_StorageImage( U, ImageBuffer, Rg16 );
	Writer_StorageImage( U, Image1D, Rg16 );
	Writer_StorageImage( U, Image2D, Rg16 );
	Writer_StorageImage( U, Image3D, Rg16 );
	Writer_StorageImage( U, ImageCube, Rg16 );
	Writer_StorageImage( U, Image1DArray, Rg16 );
	Writer_StorageImage( U, Image2DArray, Rg16 );
	Writer_StorageImage( U, ImageCubeArray, Rg16 );
	Writer_StorageImage( U, Image2DMS, Rg16 );
	Writer_StorageImage( U, Image2DMSArray, Rg16 );
	Writer_CombinedImage( U, ImageBuffer, Rg16 );
	Writer_CombinedImage( U, Image1D, Rg16 );
	Writer_CombinedImage( U, Image2D, Rg16 );
	Writer_CombinedImage( U, Image3D, Rg16 );
	Writer_CombinedImage( U, ImageCube, Rg16 );
	Writer_CombinedImage( U, Image1DArray, Rg16 );
	Writer_CombinedImage( U, Image2DArray, Rg16 );
	Writer_CombinedImage( U, ImageCubeArray, Rg16 );
	Writer_CombinedImage( U, Image2DMS, Rg16 );
	Writer_CombinedImage( U, Image2DMSArray, Rg16 );
	Writer_SampledImage( U, ImageBuffer, Rg16 );
	Writer_SampledImage( U, Image1D, Rg16 );
	Writer_SampledImage( U, Image2D, Rg16 );
	Writer_SampledImage( U, Image3D, Rg16 );
	Writer_SampledImage( U, ImageCube, Rg16 );
	Writer_SampledImage( U, Image1DArray, Rg16 );
	Writer_SampledImage( U, Image2DArray, Rg16 );
	Writer_SampledImage( U, ImageCubeArray, Rg16 );
	Writer_SampledImage( U, Image2DMS, Rg16 );
	Writer_SampledImage( U, Image2DMSArray, Rg16 );
	Writer_StorageImage( U, ImageBuffer, Rg8 );
	Writer_StorageImage( U, Image1D, Rg8 );
	Writer_StorageImage( U, Image2D, Rg8 );
	Writer_StorageImage( U, Image3D, Rg8 );
	Writer_StorageImage( U, ImageCube, Rg8 );
	Writer_StorageImage( U, Image1DArray, Rg8 );
	Writer_StorageImage( U, Image2DArray, Rg8 );
	Writer_StorageImage( U, ImageCubeArray, Rg8 );
	Writer_StorageImage( U, Image2DMS, Rg8 );
	Writer_StorageImage( U, Image2DMSArray, Rg8 );
	Writer_CombinedImage( U, ImageBuffer, Rg8 );
	Writer_CombinedImage( U, Image1D, Rg8 );
	Writer_CombinedImage( U, Image2D, Rg8 );
	Writer_CombinedImage( U, Image3D, Rg8 );
	Writer_CombinedImage( U, ImageCube, Rg8 );
	Writer_CombinedImage( U, Image1DArray, Rg8 );
	Writer_CombinedImage( U, Image2DArray, Rg8 );
	Writer_CombinedImage( U, ImageCubeArray, Rg8 );
	Writer_CombinedImage( U, Image2DMS, Rg8 );
	Writer_CombinedImage( U, Image2DMSArray, Rg8 );
	Writer_SampledImage( U, ImageBuffer, Rg8 );
	Writer_SampledImage( U, Image1D, Rg8 );
	Writer_SampledImage( U, Image2D, Rg8 );
	Writer_SampledImage( U, Image3D, Rg8 );
	Writer_SampledImage( U, ImageCube, Rg8 );
	Writer_SampledImage( U, Image1DArray, Rg8 );
	Writer_SampledImage( U, Image2DArray, Rg8 );
	Writer_SampledImage( U, ImageCubeArray, Rg8 );
	Writer_SampledImage( U, Image2DMS, Rg8 );
	Writer_SampledImage( U, Image2DMSArray, Rg8 );
	Writer_StorageImage( U, ImageBuffer, R32 );
	Writer_StorageImage( U, Image1D, R32 );
	Writer_StorageImage( U, Image2D, R32 );
	Writer_StorageImage( U, Image3D, R32 );
	Writer_StorageImage( U, ImageCube, R32 );
	Writer_StorageImage( U, Image1DArray, R32 );
	Writer_StorageImage( U, Image2DArray, R32 );
	Writer_StorageImage( U, ImageCubeArray, R32 );
	Writer_StorageImage( U, Image2DMS, R32 );
	Writer_StorageImage( U, Image2DMSArray, R32 );
	Writer_CombinedImage( U, ImageBuffer, R32 );
	Writer_CombinedImage( U, Image1D, R32 );
	Writer_CombinedImage( U, Image2D, R32 );
	Writer_CombinedImage( U, Image3D, R32 );
	Writer_CombinedImage( U, ImageCube, R32 );
	Writer_CombinedImage( U, Image1DArray, R32 );
	Writer_CombinedImage( U, Image2DArray, R32 );
	Writer_CombinedImage( U, ImageCubeArray, R32 );
	Writer_CombinedImage( U, Image2DMS, R32 );
	Writer_CombinedImage( U, Image2DMSArray, R32 );
	Writer_SampledImage( U, ImageBuffer, R32 );
	Writer_SampledImage( U, Image1D, R32 );
	Writer_SampledImage( U, Image2D, R32 );
	Writer_SampledImage( U, Image3D, R32 );
	Writer_SampledImage( U, ImageCube, R32 );
	Writer_SampledImage( U, Image1DArray, R32 );
	Writer_SampledImage( U, Image2DArray, R32 );
	Writer_SampledImage( U, ImageCubeArray, R32 );
	Writer_SampledImage( U, Image2DMS, R32 );
	Writer_SampledImage( U, Image2DMSArray, R32 );
	Writer_StorageImage( U, ImageBuffer, R16 );
	Writer_StorageImage( U, Image1D, R16 );
	Writer_StorageImage( U, Image2D, R16 );
	Writer_StorageImage( U, Image3D, R16 );
	Writer_StorageImage( U, ImageCube, R16 );
	Writer_StorageImage( U, Image1DArray, R16 );
	Writer_StorageImage( U, Image2DArray, R16 );
	Writer_StorageImage( U, ImageCubeArray, R16 );
	Writer_StorageImage( U, Image2DMS, R16 );
	Writer_StorageImage( U, Image2DMSArray, R16 );
	Writer_CombinedImage( U, ImageBuffer, R16 );
	Writer_CombinedImage( U, Image1D, R16 );
	Writer_CombinedImage( U, Image2D, R16 );
	Writer_CombinedImage( U, Image3D, R16 );
	Writer_CombinedImage( U, ImageCube, R16 );
	Writer_CombinedImage( U, Image1DArray, R16 );
	Writer_CombinedImage( U, Image2DArray, R16 );
	Writer_CombinedImage( U, ImageCubeArray, R16 );
	Writer_CombinedImage( U, Image2DMS, R16 );
	Writer_CombinedImage( U, Image2DMSArray, R16 );
	Writer_SampledImage( U, ImageBuffer, R16 );
	Writer_SampledImage( U, Image1D, R16 );
	Writer_SampledImage( U, Image2D, R16 );
	Writer_SampledImage( U, Image3D, R16 );
	Writer_SampledImage( U, ImageCube, R16 );
	Writer_SampledImage( U, Image1DArray, R16 );
	Writer_SampledImage( U, Image2DArray, R16 );
	Writer_SampledImage( U, ImageCubeArray, R16 );
	Writer_SampledImage( U, Image2DMS, R16 );
	Writer_SampledImage( U, Image2DMSArray, R16 );
	Writer_StorageImage( U, ImageBuffer, R8 );
	Writer_StorageImage( U, Image1D, R8 );
	Writer_StorageImage( U, Image2D, R8 );
	Writer_StorageImage( U, Image3D, R8 );
	Writer_StorageImage( U, ImageCube, R8 );
	Writer_StorageImage( U, Image1DArray, R8 );
	Writer_StorageImage( U, Image2DArray, R8 );
	Writer_StorageImage( U, ImageCubeArray, R8 );
	Writer_StorageImage( U, Image2DMS, R8 );
	Writer_StorageImage( U, Image2DMSArray, R8 );
	Writer_CombinedImage( U, ImageBuffer, R8 );
	Writer_CombinedImage( U, Image1D, R8 );
	Writer_CombinedImage( U, Image2D, R8 );
	Writer_CombinedImage( U, Image3D, R8 );
	Writer_CombinedImage( U, ImageCube, R8 );
	Writer_CombinedImage( U, Image1DArray, R8 );
	Writer_CombinedImage( U, Image2DArray, R8 );
	Writer_CombinedImage( U, ImageCubeArray, R8 );
	Writer_CombinedImage( U, Image2DMS, R8 );
	Writer_CombinedImage( U, Image2DMSArray, R8 );
	Writer_SampledImage( U, ImageBuffer, R8 );
	Writer_SampledImage( U, Image1D, R8 );
	Writer_SampledImage( U, Image2D, R8 );
	Writer_SampledImage( U, Image3D, R8 );
	Writer_SampledImage( U, ImageCube, R8 );
	Writer_SampledImage( U, Image1DArray, R8 );
	Writer_SampledImage( U, Image2DArray, R8 );
	Writer_SampledImage( U, ImageCubeArray, R8 );
	Writer_SampledImage( U, Image2DMS, R8 );
	Writer_SampledImage( U, Image2DMSArray, R8 );

#	undef Writer_SampledImage
#	undef Writer_CombinedImage
#	undef Writer_UniformImage
#	undef Writer_StorageImage

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
