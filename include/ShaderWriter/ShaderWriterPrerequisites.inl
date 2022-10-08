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
		using OperandType = void;
		using LargestType = void;
		using ComponentType = Void;
	};
	
	template<>
	struct TypeTraits< bool >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eBoolean;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 1;
		static size_t constexpr ComponentCount = 1;
		using CppType = bool;
		using OperandType = Boolean;
		using LargestType = Boolean;
		using ComponentType = Boolean;
	};

	template<>
	struct TypeTraits< int8_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 1;
		static size_t constexpr ComponentCount = 1;
		using CppType = int8_t;
		using OperandType = Int8;
		using LargestType = Int64;
		using ComponentType = Int8;
	};

	template<>
	struct TypeTraits< int16_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 2;
		static size_t constexpr ComponentCount = 1;
		using CppType = int16_t;
		using OperandType = Int16;
		using LargestType = Int64;
		using ComponentType = Int16;
	};

	template<>
	struct TypeTraits< int32_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 1;
		using CppType = int32_t;
		using OperandType = Int32;
		using LargestType = Int64;
		using ComponentType = Int32;
	};

	template<>
	struct TypeTraits< int64_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 1;
		using CppType = int64_t;
		using OperandType = Int64;
		using LargestType = Int64;
		using ComponentType = Int64;
	};

	template<>
	struct TypeTraits< uint8_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 1;
		static size_t constexpr ComponentCount = 1;
		using CppType = uint8_t;
		using OperandType = UInt8;
		using LargestType = UInt64;
		using ComponentType = UInt8;
	};

	template<>
	struct TypeTraits< uint16_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 2;
		static size_t constexpr ComponentCount = 1;
		using CppType = uint16_t;
		using OperandType = UInt16;
		using LargestType = UInt64;
		using ComponentType = UInt16;
	};

	template<>
	struct TypeTraits< uint32_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 1;
		using CppType = uint32_t;
		using OperandType = UInt32;
		using LargestType = UInt64;
		using ComponentType = UInt32;
	};

	template<>
	struct TypeTraits< uint64_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 1;
		using CppType = uint64_t;
		using OperandType = UInt64;
		using LargestType = UInt64;
		using ComponentType = UInt64;
	};

	template<>
	struct TypeTraits< float >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eFloat;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 1;
		using CppType = float;
		using OperandType = Float;
		using LargestType = Double;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< double >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eDouble;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 1;
		using CppType = double;
		using OperandType = Double;
		using LargestType = Double;
		using ComponentType = Double;
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
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eInt8 > > : TypeTraits< int8_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eInt16 > > : TypeTraits< int16_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eInt32 > > : TypeTraits< int32_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eInt64 > > : TypeTraits< int64_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eUInt8 > > : TypeTraits< uint8_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eUInt16 > > : TypeTraits< uint16_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eUInt32 > > : TypeTraits< uint32_t >
	{
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eUInt64 > > : TypeTraits< uint64_t >
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
		using OperandType = Half;
		using LargestType = Double;
		using ComponentType = Half;
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eDouble > > : TypeTraits< double >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eInt8 > > : TypeTraits< int8_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eInt16 > > : TypeTraits< int16_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eInt32 > > : TypeTraits< int32_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eInt64 > > : TypeTraits< int64_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eUInt8 > > : TypeTraits< uint8_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eUInt16 > > : TypeTraits< uint16_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eUInt32 > > : TypeTraits< uint32_t >
	{
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eUInt64 > > : TypeTraits< uint64_t >
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
		using OperandType = BVec2;
		using LargestType = BVec2;
		using ComponentType = Boolean;
	};

	template<>
	struct TypeTraits< BVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3B;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 3;
		static size_t constexpr ComponentCount = 3;
		using CppType = bool;
		using OperandType = BVec3;
		using LargestType = BVec3;
		using ComponentType = Boolean;
	};

	template<>
	struct TypeTraits< BVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4B;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 1;
		static size_t constexpr ComponentCount = 4;
		using CppType = bool;
		using OperandType = BVec4;
		using LargestType = BVec4;
		using ComponentType = Boolean;
	};

	template<>
	struct TypeTraits< I8Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2I8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 2;
		static size_t constexpr ComponentCount = 2;
		using CppType = int8_t;
		using OperandType = I8Vec2;
		using LargestType = I64Vec2;
		using ComponentType = Int8;
	};

	template<>
	struct TypeTraits< I8Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3I8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 3;
		static size_t constexpr ComponentCount = 3;
		using CppType = int8_t;
		using OperandType = I8Vec3;
		using LargestType = I64Vec3;
		using ComponentType = Int8;
	};

	template<>
	struct TypeTraits< I8Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4I8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 4;
		using CppType = int8_t;
		using OperandType = I8Vec4;
		using LargestType = I64Vec4;
		using ComponentType = Int8;
	};

	template<>
	struct TypeTraits< I16Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2I16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 2;
		using CppType = int16_t;
		using OperandType = I16Vec2;
		using LargestType = I64Vec2;
		using ComponentType = Int16;
	};

	template<>
	struct TypeTraits< I16Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3I16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 6;
		static size_t constexpr ComponentCount = 3;
		using CppType = int16_t;
		using OperandType = I16Vec3;
		using LargestType = I64Vec3;
		using ComponentType = Int16;
	};

	template<>
	struct TypeTraits< I16Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4I16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 4;
		using CppType = int16_t;
		using OperandType = I16Vec4;
		using LargestType = I64Vec3;
		using ComponentType = Int16;
	};

	template<>
	struct TypeTraits< I32Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2I32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 2;
		using CppType = int32_t;
		using OperandType = I32Vec2;
		using LargestType = I64Vec2;
		using ComponentType = Int32;
	};

	template<>
	struct TypeTraits< I32Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3I32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 12;
		static size_t constexpr ComponentCount = 3;
		using CppType = int32_t;
		using OperandType = I32Vec3;
		using LargestType = I64Vec3;
		using ComponentType = Int32;
	};

	template<>
	struct TypeTraits< I32Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4I32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = int32_t;
		using OperandType = I32Vec4;
		using LargestType = I64Vec4;
		using ComponentType = Int32;
	};

	template<>
	struct TypeTraits< I64Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2I64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 2;
		using CppType = int64_t;
		using OperandType = I64Vec2;
		using LargestType = I64Vec2;
		using ComponentType = Int64;
	};

	template<>
	struct TypeTraits< I64Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3I64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 3;
		using CppType = int64_t;
		using OperandType = I64Vec3;
		using LargestType = I64Vec3;
		using ComponentType = Int64;
	};

	template<>
	struct TypeTraits< I64Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4I64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 4;
		using CppType = int64_t;
		using OperandType = I64Vec4;
		using LargestType = I64Vec4;
		using ComponentType = Int64;
	};

	template<>
	struct TypeTraits< U8Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2U8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 2;
		static size_t constexpr ComponentCount = 2;
		using CppType = uint8_t;
		using OperandType = U8Vec2;
		using LargestType = U64Vec2;
		using ComponentType = UInt8;
	};

	template<>
	struct TypeTraits< U8Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3U8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 3;
		static size_t constexpr ComponentCount = 3;
		using CppType = uint8_t;
		using OperandType = U8Vec3;
		using LargestType = U64Vec3;
		using ComponentType = UInt8;
	};

	template<>
	struct TypeTraits< U8Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4U8;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 4;
		using CppType = uint8_t;
		using OperandType = U8Vec4;
		using LargestType = U64Vec4;
		using ComponentType = UInt8;
	};

	template<>
	struct TypeTraits< U16Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2U16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 2;
		using CppType = uint16_t;
		using OperandType = U16Vec2;
		using LargestType = U64Vec2;
		using ComponentType = UInt16;
	};

	template<>
	struct TypeTraits< U16Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3U16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 6;
		static size_t constexpr ComponentCount = 3;
		using CppType = uint16_t;
		using OperandType = U16Vec3;
		using LargestType = U64Vec3;
		using ComponentType = UInt16;
	};

	template<>
	struct TypeTraits< U16Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4U16;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 4;
		using CppType = uint16_t;
		using OperandType = U16Vec4;
		using LargestType = U64Vec4;
		using ComponentType = UInt16;
	};

	template<>
	struct TypeTraits< U32Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2U32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 2;
		using CppType = uint32_t;
		using OperandType = U32Vec2;
		using LargestType = U64Vec2;
		using ComponentType = UInt32;
	};

	template<>
	struct TypeTraits< U32Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3U32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 12;
		static size_t constexpr ComponentCount = 3;
		using CppType = uint32_t;
		using OperandType = U32Vec3;
		using LargestType = U64Vec3;
		using ComponentType = UInt32;
	};

	template<>
	struct TypeTraits< U32Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4U32;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = uint32_t;
		using OperandType = U32Vec4;
		using LargestType = U64Vec4;
		using ComponentType = UInt32;
	};

	template<>
	struct TypeTraits< U64Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2U64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 2;
		using CppType = uint64_t;
		using OperandType = U64Vec2;
		using LargestType = U64Vec2;
		using ComponentType = UInt64;
	};

	template<>
	struct TypeTraits< U64Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3U64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 3;
		using CppType = uint64_t;
		using OperandType = U64Vec3;
		using LargestType = U64Vec3;
		using ComponentType = UInt64;
	};

	template<>
	struct TypeTraits< U64Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4U64;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 4;
		using CppType = uint64_t;
		using OperandType = U64Vec4;
		using LargestType = U64Vec4;
		using ComponentType = UInt64;
	};

	template<>
	struct TypeTraits< Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 2;
		using CppType = float;
		using OperandType = Vec2;
		using LargestType = DVec2;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 12;
		static size_t constexpr ComponentCount = 3;
		using CppType = float;
		using OperandType = Vec3;
		using LargestType = DVec3;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = float;
		using OperandType = Vec4;
		using LargestType = DVec4;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< HVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2H;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 4;
		static size_t constexpr ComponentCount = 2;
		using CppType = float;
		using OperandType = HVec2;
		using LargestType = DVec2;
		using ComponentType = Half;
	};

	template<>
	struct TypeTraits< HVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4H;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 8;
		static size_t constexpr ComponentCount = 4;
		using CppType = float;
		using OperandType = HVec4;
		using LargestType = DVec4;
		using ComponentType = Half;
	};

	template<>
	struct TypeTraits< DVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 2;
		using CppType = double;
		using OperandType = DVec2;
		using LargestType = DVec2;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 3;
		using CppType = double;
		using OperandType = DVec3;
		using LargestType = DVec3;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 4;
		using CppType = double;
		using OperandType = DVec4;
		using LargestType = DVec4;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< Mat2x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x2F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 16;
		static size_t constexpr ComponentCount = 4;
		using CppType = float;
		using OperandType = Mat2x2;
		using LargestType = DMat2x2;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat2x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x3F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 6;
		using CppType = float;
		using OperandType = Mat2x3;
		using LargestType = DMat2x3;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat2x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x4F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 8;
		using CppType = float;
		using OperandType = Mat2x4;
		using LargestType = DMat2x4;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat3x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x2F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 24;
		static size_t constexpr ComponentCount = 6;
		using CppType = float;
		using OperandType = Mat3x2;
		using LargestType = DMat3x2;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat3x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x3F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 36;
		static size_t constexpr ComponentCount = 9;
		using CppType = float;
		using OperandType = Mat3x3;
		using LargestType = DMat3x3;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat3x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x4F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 12;
		using CppType = float;
		using OperandType = Mat3x4;
		using LargestType = DMat3x4;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat4x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x2F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 8;
		using CppType = float;
		using OperandType = Mat4x2;
		using LargestType = DMat4x2;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat4x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x3F;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 12;
		using CppType = float;
		using OperandType = Mat4x3;
		using LargestType = DMat4x3;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< Mat4x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x4F;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 64;
		static size_t constexpr ComponentCount = 16;
		using CppType = float;
		using OperandType = Mat4x4;
		using LargestType = DMat4x4;
		using ComponentType = Float;
	};

	template<>
	struct TypeTraits< DMat2x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x2D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 32;
		static size_t constexpr ComponentCount = 4;
		using CppType = double;
		using OperandType = DMat2x2;
		using LargestType = DMat2x2;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat2x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x3D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 6;
		using CppType = double;
		using OperandType = DMat2x3;
		using LargestType = DMat2x3;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat2x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x4D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 64;
		static size_t constexpr ComponentCount = 8;
		using CppType = double;
		using OperandType = DMat2x4;
		using LargestType = DMat2x4;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat3x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x2D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 48;
		static size_t constexpr ComponentCount = 6;
		using CppType = double;
		using OperandType = DMat3x2;
		using LargestType = DMat3x2;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat3x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x3D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 72;
		static size_t constexpr ComponentCount = 9;
		using CppType = double;
		using OperandType = DMat3x3;
		using LargestType = DMat3x3;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat3x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x4D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 96;
		static size_t constexpr ComponentCount = 12;
		using CppType = double;
		using OperandType = DMat3x4;
		using LargestType = DMat3x4;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat4x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x2D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 64;
		static size_t constexpr ComponentCount = 8;
		using CppType = double;
		using OperandType = DMat4x2;
		using LargestType = DMat4x2;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat4x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x3D;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 96;
		static size_t constexpr ComponentCount = 12;
		using CppType = double;
		using OperandType = DMat4x3;
		using LargestType = DMat4x3;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< DMat4x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x4D;
		static bool constexpr HasArithmeticOperators = true;
		static size_t constexpr Size = 128;
		static size_t constexpr ComponentCount = 16;
		using CppType = double;
		using OperandType = DMat4x4;
		using LargestType = DMat4x4;
		using ComponentType = Double;
	};

	template<>
	struct TypeTraits< StructInstance >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eStruct;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
		using OperandType = Void;
		using LargestType = Void;
		using ComponentType = Void;
	};

	template<>
	struct TypeTraits< RayDesc >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eRayDesc;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
		using OperandType = Void;
		using LargestType = Void;
		using ComponentType = Void;
	};

	template<>
	struct TypeTraits< CombinedImage >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eCombinedImage;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
		using OperandType = Void;
		using LargestType = Void;
		using ComponentType = Void;
	};

	template<>
	struct TypeTraits< Sampler >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eSampler;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
		using OperandType = Void;
		using LargestType = Void;
		using ComponentType = Void;
	};

	template<>
	struct TypeTraits< SampledImage >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eSampledImage;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
		using OperandType = Void;
		using LargestType = Void;
		using ComponentType = Void;
	};

	template<>
	struct TypeTraits< StorageImage >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eImage;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
		using OperandType = Void;
		using LargestType = Void;
		using ComponentType = Void;
	};

	template<>
	struct TypeTraits< AccelerationStructure >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eAccelerationStructure;
		static bool constexpr HasArithmeticOperators = false;
		static size_t constexpr Size = 0;
		static size_t constexpr ComponentCount = 1;
		using CppType = void;
		using OperandType = Void;
		using LargestType = Void;
		using ComponentType = Void;
	};

	template< typename TypeT >
	struct TypeTraits< NonUniformT< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
	};

	template< typename TypeT >
	struct TypeTraits< Array< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
	};

	template< typename TypeT >
	struct TypeTraits< InParam< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
	};

	template< typename TypeT >
	struct TypeTraits< OutParam< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
	};

	template< typename TypeT >
	struct TypeTraits< InOutParam< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
	};

	template< typename TypeT >
	struct TypeTraits< ReturnWrapperT< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
		using Type = TypeT;
	};

	template< typename TypeT >
	struct TypeTraits< DefaultedT< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
		using Type = TypeT;
	};

	template< ast::var::Flag FlagT, typename TypeT >
	struct TypeTraits< RayPayloadBaseT< FlagT, TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
		using Type = TypeT;
	};

	template< ast::var::Flag FlagT, typename TypeT >
	struct TypeTraits< CallableDataBaseT< FlagT, TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
		using Type = TypeT;
	};

	template< typename TypeT >
	struct TypeTraits< HitAttributeT< TypeT > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< TypeT >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;
		using CppType = typename TypeTraits< TypeT >::CppType;
		using OperandType = typename TypeTraits< TypeT >::OperandType;
		using LargestType = typename TypeTraits< TypeT >::LargestType;
		using ComponentType = typename TypeTraits< TypeT >::ComponentType;
		static size_t constexpr Size = TypeTraits< TypeT >::Size;
		static size_t constexpr ComponentCount = TypeTraits< TypeT >::ComponentCount;
		using Type = TypeT;
	};

	//***********************************************************************************************

	template<>
	struct TypeKindTraits< ast::type::Kind::eBoolean >
	{
		using Type = Boolean;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eInt8 >
	{
		using Type = Int8;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eInt16 >
	{
		using Type = Int16;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eInt32 >
	{
		using Type = Int32;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eInt64 >
	{
		using Type = Int64;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eUInt8 >
	{
		using Type = UInt8;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eUInt16 >
	{
		using Type = UInt16;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eUInt32 >
	{
		using Type = UInt32;
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
	struct TypeKindTraits< ast::type::Kind::eVec2I8 >
	{
		using Type = I8Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3I8 >
	{
		using Type = I8Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4I8 >
	{
		using Type = I8Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2I16 >
	{
		using Type = I16Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3I16 >
	{
		using Type = I16Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4I16 >
	{
		using Type = I16Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2I32 >
	{
		using Type = I32Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3I32 >
	{
		using Type = I32Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4I32 >
	{
		using Type = I32Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2I64 >
	{
		using Type = I64Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3I64 >
	{
		using Type = I64Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4I64 >
	{
		using Type = I64Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2U8 >
	{
		using Type = U8Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3U8 >
	{
		using Type = U8Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4U8 >
	{
		using Type = U8Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2U16 >
	{
		using Type = U16Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3U16 >
	{
		using Type = U16Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4U16 >
	{
		using Type = U16Vec4;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec2U32 >
	{
		using Type = U32Vec2;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec3U32 >
	{
		using Type = U32Vec3;
	};

	template<>
	struct TypeKindTraits< ast::type::Kind::eVec4U32 >
	{
		using Type = U32Vec4;
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

	template< typename TypeT >
	struct RealTypeGetter
	{
		using Type = TypeT;
	};

	template< typename TypeT >
	struct RealTypeGetter< InParam< TypeT > >
	{
		using Type = TypeT;
	};

	template< typename TypeT >
	struct RealTypeGetter< OutParam< TypeT > >
	{
		using Type = TypeT;
	};

	template< typename TypeT >
	struct RealTypeGetter< InOutParam< TypeT > >
	{
		using Type = TypeT;
	};

	template< typename TypeT >
	struct RealTypeGetter< ReturnWrapperT< TypeT > >
	{
		using Type = TypeT;
	};

	//***********************************************************************************************
}
