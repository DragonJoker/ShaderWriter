#pragma once

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/SelectEntryPoint.hpp>
#include <ShaderWriter/BaseTypes/Double.hpp>
#include <ShaderWriter/BaseTypes/Float.hpp>
#include <ShaderWriter/BaseTypes/Int.hpp>
#include <ShaderWriter/BaseTypes/Sampler.hpp>
#include <ShaderWriter/BaseTypes/StorageImage.hpp>
#include <ShaderWriter/BaseTypes/UInt.hpp>
#include <ShaderWriter/Intrinsics/Intrinsics.hpp>
#include <ShaderWriter/PipelineWriter.hpp>
#include <ShaderWriter/Writer.hpp>
#include <ShaderWriter/WriterDebug.hpp>
#include <ShaderWriter/Source.hpp>
#include <ShaderWriter/MeshWriterNV.hpp>
#include <ShaderWriter/TaskWriterNV.hpp>

namespace test
{
	using FloatTypes = testing::Types< sdw::Float, sdw::Vec2, sdw::Vec3, sdw::Vec4 >;
	using DoubleTypes = testing::Types< sdw::Double, sdw::DVec2, sdw::DVec3, sdw::DVec4 >;
	using UIntTypes = testing::Types< sdw::UInt, sdw::UVec2, sdw::UVec3, sdw::UVec4 >;
	using IntTypes = testing::Types< sdw::Int, sdw::IVec2, sdw::IVec3, sdw::IVec4 >;

	using FloatDoubleTypes = testing::Types< sdw::Float, sdw::Vec2, sdw::Vec3, sdw::Vec4
		, sdw::Double, sdw::DVec2, sdw::DVec3, sdw::DVec4 >;
	using IntUIntTypes = testing::Types< sdw::Int, sdw::IVec2, sdw::IVec3, sdw::IVec4
		, sdw::UInt, sdw::UVec2, sdw::UVec3, sdw::UVec4 >;
	using IntUIntBoolTypes = testing::Types< sdw::Int, sdw::IVec2, sdw::IVec3, sdw::IVec4
		, sdw::UInt, sdw::UVec2, sdw::UVec3, sdw::UVec4
		, sdw::Boolean, sdw::BVec2, sdw::BVec3, sdw::BVec4 >;
	using FloatDoubleIntTypes = testing::Types< sdw::Float, sdw::Vec2, sdw::Vec3, sdw::Vec4
		, sdw::Double, sdw::DVec2, sdw::DVec3, sdw::DVec4
		, sdw::Int, sdw::IVec2, sdw::IVec3, sdw::IVec4 >;
	using FloatDoubleIntUIntTypes = testing::Types< sdw::Float, sdw::Vec2, sdw::Vec3, sdw::Vec4
		, sdw::Double, sdw::DVec2, sdw::DVec3, sdw::DVec4
		, sdw::Int, sdw::IVec2, sdw::IVec3, sdw::IVec4
		, sdw::UInt, sdw::UVec2, sdw::UVec3, sdw::UVec4 >;
	using FloatDoubleIntUIntBoolTypes = testing::Types< sdw::Float, sdw::Vec2, sdw::Vec3, sdw::Vec4
		, sdw::Double, sdw::DVec2, sdw::DVec3, sdw::DVec4
		, sdw::Int, sdw::IVec2, sdw::IVec3, sdw::IVec4
		, sdw::UInt, sdw::UVec2, sdw::UVec3, sdw::UVec4
		, sdw::Boolean, sdw::BVec2, sdw::BVec3, sdw::BVec4 >;

	using VecBoolTypes = testing::Types< sdw::BVec2, sdw::BVec3, sdw::BVec4 >;
	using VecFloatDoubleTypes = testing::Types< sdw::Vec2, sdw::Vec3, sdw::Vec4
		, sdw::DVec2, sdw::DVec3, sdw::DVec4 >;
	using VecFloatDoubleIntUIntTypes = testing::Types< sdw::Vec2, sdw::Vec3, sdw::Vec4
		, sdw::DVec2, sdw::DVec3, sdw::DVec4
		, sdw::IVec2, sdw::IVec3, sdw::IVec4
		, sdw::UVec2, sdw::UVec3, sdw::UVec4 >;
	using MatFloatDoubleTypes = testing::Types< sdw::Mat2x2, sdw::Mat2x3, sdw::Mat2x4
		, sdw::Mat3x2, sdw::Mat3x3, sdw::Mat3x4
		, sdw::Mat4x2, sdw::Mat4x3, sdw::Mat4x4
		, sdw::DMat2x2, sdw::DMat2x3, sdw::DMat2x4
		, sdw::DMat3x2, sdw::DMat3x3, sdw::DMat3x4
		, sdw::DMat4x2, sdw::DMat4x3, sdw::DMat4x4 >;
	using SqMatFloatDoubleTypes = testing::Types< sdw::Mat2x2, sdw::Mat3x3, sdw::Mat4x4
		, sdw::DMat2x2, sdw::DMat3x3, sdw::DMat4x4 >;
	using Vec3FloatDoubleTypes = testing::Types< sdw::Vec3, sdw::DVec3 >;

	template< typename T >
	inline bool constexpr isInt16Type = std::is_same_v< T, sdw::Int16 >
		|| std::is_same_v< T, sdw::I16Vec2 >
		|| std::is_same_v< T, sdw::I16Vec3 >
		|| std::is_same_v< T, sdw::I16Vec4 >;
	template< typename T >
	inline bool constexpr isUInt16Type = std::is_same_v< T, sdw::UInt16 >
		|| std::is_same_v< T, sdw::U16Vec2 >
		|| std::is_same_v< T, sdw::U16Vec3 >
		|| std::is_same_v< T, sdw::U16Vec4 >;
	template< typename T >
	inline bool constexpr isFloat64Type = std::is_same_v< T, sdw::Double >
		|| std::is_same_v< T, sdw::DVec2 >
		|| std::is_same_v< T, sdw::DVec3 >
		|| std::is_same_v< T, sdw::DVec4 >;

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct CombinedImageTypeT
	{
		static ast::type::ImageDim constexpr Dim = DimT;
		static bool constexpr Arrayed = ArrayedT;
		static bool constexpr Ms = MsT;
		static bool constexpr Depth = DepthT;
	};

	using CombinedImageTypes = testing::Types< CombinedImageTypeT< Img1DBase, false >
		, CombinedImageTypeT< Img2DBase, false >
		, CombinedImageTypeT< Img3DBase, false >
		, CombinedImageTypeT< ImgCubeBase, false >
		, CombinedImageTypeT< ImgBufferBase, false >
		, CombinedImageTypeT< Img1DArrayBase, false >
		, CombinedImageTypeT< Img2DArrayBase, false >
		, CombinedImageTypeT< ImgCubeArrayBase, false >
		, CombinedImageTypeT< Img1DBase, true >
		, CombinedImageTypeT< Img2DBase, true >
		, CombinedImageTypeT< ImgCubeBase, true >
		, CombinedImageTypeT< Img1DArrayBase, true >
		, CombinedImageTypeT< Img2DArrayBase, true >
		, CombinedImageTypeT< ImgCubeArrayBase, true > >;

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageTypeT
	{
		static ast::type::ImageDim constexpr Dim = DimT;
		static bool constexpr Arrayed = ArrayedT;
		static bool constexpr Ms = MsT;
		static bool constexpr Depth = DepthT;
	};

	using SampledImageTypes = testing::Types< SampledImageTypeT< Img1DBase, false >
		, SampledImageTypeT< Img2DBase, false >
		, SampledImageTypeT< Img3DBase, false >
		, SampledImageTypeT< ImgCubeBase, false >
		, SampledImageTypeT< ImgBufferBase, false >
		, SampledImageTypeT< Img1DArrayBase, false >
		, SampledImageTypeT< Img2DArrayBase, false >
		, SampledImageTypeT< ImgCubeArrayBase, false >
		, SampledImageTypeT< Img1DBase, true >
		, SampledImageTypeT< Img2DBase, true >
		, SampledImageTypeT< ImgCubeBase, true >
		, SampledImageTypeT< Img1DArrayBase, true >
		, SampledImageTypeT< Img2DArrayBase, true >
		, SampledImageTypeT< ImgCubeArrayBase, true > >;

	template< ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct StorageImageTypeT
	{
		static ast::type::AccessKind constexpr Access = AccessT;
		static ast::type::ImageDim constexpr Dim = DimT;
		static bool constexpr Arrayed = ArrayedT;
		static bool constexpr Ms = MsT;
	};

#define WriteTypes( Access )\
		StorageImageTypeT< ast::type::AccessKind::Access, Img1DBase >\
		, StorageImageTypeT< ast::type::AccessKind::Access, Img2DBase >\
		, StorageImageTypeT< ast::type::AccessKind::Access, Img3DBase >\
		, StorageImageTypeT< ast::type::AccessKind::Access, ImgCubeBase >\
		, StorageImageTypeT< ast::type::AccessKind::Access, ImgBufferBase >\
		, StorageImageTypeT< ast::type::AccessKind::Access, Img1DArrayBase >\
		, StorageImageTypeT< ast::type::AccessKind::Access, Img2DArrayBase >\
		, StorageImageTypeT< ast::type::AccessKind::Access, ImgCubeArrayBase >

	using StorageImageTypes = testing::Types< WriteTypes( eRead )
		, WriteTypes( eWrite )
		, WriteTypes( eReadWrite ) >;

#undef WriteTypes

	class TypesNames
	{
	public:
		template< typename T >
		static std::string GetName( int )
		{
			if constexpr ( std::is_same_v < T, sdw::Boolean > ) return "Bool";
			else if constexpr ( std::is_same_v < T, sdw::BVec2 > ) return "BVec2";
			else if constexpr ( std::is_same_v < T, sdw::BVec3 > ) return "BVec3";
			else if constexpr ( std::is_same_v < T, sdw::BVec4 > ) return "BVec4";
			else if constexpr ( std::is_same_v < T, sdw::Float > ) return "Float";
			else if constexpr ( std::is_same_v < T, sdw::Vec2 > ) return "Vec2";
			else if constexpr ( std::is_same_v < T, sdw::Vec3 > ) return "Vec3";
			else if constexpr ( std::is_same_v < T, sdw::Vec4 > ) return "Vec4";
			else if constexpr ( std::is_same_v < T, sdw::Half > ) return "Half";
			else if constexpr ( std::is_same_v < T, sdw::HVec2 > ) return "HVec2";
			else if constexpr ( std::is_same_v < T, sdw::HVec4 > ) return "HVec4";
			else if constexpr ( std::is_same_v < T, sdw::Double > ) return "Double";
			else if constexpr ( std::is_same_v < T, sdw::DVec2 > ) return "DVec2";
			else if constexpr ( std::is_same_v < T, sdw::DVec3 > ) return "DVec3";
			else if constexpr ( std::is_same_v < T, sdw::DVec4 > ) return "DVec4";
			else if constexpr ( std::is_same_v < T, sdw::UInt8 > ) return "UInt8";
			else if constexpr ( std::is_same_v < T, sdw::U8Vec2 > ) return "U8Vec2";
			else if constexpr ( std::is_same_v < T, sdw::U8Vec3 > ) return "U8Vec3";
			else if constexpr ( std::is_same_v < T, sdw::U8Vec4 > ) return "U8Vec4";
			else if constexpr ( std::is_same_v < T, sdw::UInt16 > ) return "UInt16";
			else if constexpr ( std::is_same_v < T, sdw::U16Vec2 > ) return "U16Vec2";
			else if constexpr ( std::is_same_v < T, sdw::U16Vec3 > ) return "U16Vec3";
			else if constexpr ( std::is_same_v < T, sdw::U16Vec4 > ) return "U16Vec4";
			else if constexpr ( std::is_same_v < T, sdw::UInt32 > ) return "UInt32";
			else if constexpr ( std::is_same_v < T, sdw::U32Vec2 > ) return "U32Vec2";
			else if constexpr ( std::is_same_v < T, sdw::U32Vec3 > ) return "U32Vec3";
			else if constexpr ( std::is_same_v < T, sdw::U32Vec4 > ) return "U32Vec4";
			else if constexpr ( std::is_same_v < T, sdw::UInt64 > ) return "UInt64";
			else if constexpr ( std::is_same_v < T, sdw::U64Vec2 > ) return "U64Vec2";
			else if constexpr ( std::is_same_v < T, sdw::U64Vec3 > ) return "U64Vec3";
			else if constexpr ( std::is_same_v < T, sdw::U64Vec4 > ) return "U64Vec4";
			else if constexpr ( std::is_same_v < T, sdw::Int8 > ) return "Int8";
			else if constexpr ( std::is_same_v < T, sdw::I8Vec2 > ) return "I8Vec2";
			else if constexpr ( std::is_same_v < T, sdw::I8Vec3 > ) return "I8Vec3";
			else if constexpr ( std::is_same_v < T, sdw::I8Vec4 > ) return "I8Vec4";
			else if constexpr ( std::is_same_v < T, sdw::Int16 > ) return "Int16";
			else if constexpr ( std::is_same_v < T, sdw::I16Vec2 > ) return "I16Vec2";
			else if constexpr ( std::is_same_v < T, sdw::I16Vec3 > ) return "I16Vec3";
			else if constexpr ( std::is_same_v < T, sdw::I16Vec4 > ) return "I16Vec4";
			else if constexpr ( std::is_same_v < T, sdw::Int32 > ) return "Int32";
			else if constexpr ( std::is_same_v < T, sdw::I32Vec2 > ) return "I32Vec2";
			else if constexpr ( std::is_same_v < T, sdw::I32Vec3 > ) return "I32Vec3";
			else if constexpr ( std::is_same_v < T, sdw::I32Vec4 > ) return "I32Vec4";
			else if constexpr ( std::is_same_v < T, sdw::Int64 > ) return "Int64";
			else if constexpr ( std::is_same_v < T, sdw::I64Vec2 > ) return "I64Vec2";
			else if constexpr ( std::is_same_v < T, sdw::I64Vec3 > ) return "I64Vec3";
			else if constexpr ( std::is_same_v < T, sdw::I64Vec4 > ) return "I64Vec4";
			else if constexpr ( std::is_same_v < T, sdw::Mat2x2 > ) return "Mat2x2";
			else if constexpr ( std::is_same_v < T, sdw::Mat2x3 > ) return "Mat2x3";
			else if constexpr ( std::is_same_v < T, sdw::Mat2x4 > ) return "Mat2x4";
			else if constexpr ( std::is_same_v < T, sdw::Mat3x2 > ) return "Mat3x2";
			else if constexpr ( std::is_same_v < T, sdw::Mat3x3 > ) return "Mat3x3";
			else if constexpr ( std::is_same_v < T, sdw::Mat3x4 > ) return "Mat3x4";
			else if constexpr ( std::is_same_v < T, sdw::Mat4x2 > ) return "Mat4x2";
			else if constexpr ( std::is_same_v < T, sdw::Mat4x3 > ) return "Mat4x3";
			else if constexpr ( std::is_same_v < T, sdw::Mat4x4 > ) return "Mat4x4";
			else if constexpr ( std::is_same_v < T, sdw::DMat2x2 > ) return "DMat2x2";
			else if constexpr ( std::is_same_v < T, sdw::DMat2x3 > ) return "DMat2x3";
			else if constexpr ( std::is_same_v < T, sdw::DMat2x4 > ) return "DMat2x4";
			else if constexpr ( std::is_same_v < T, sdw::DMat3x2 > ) return "DMat3x2";
			else if constexpr ( std::is_same_v < T, sdw::DMat3x3 > ) return "DMat3x3";
			else if constexpr ( std::is_same_v < T, sdw::DMat3x4 > ) return "DMat3x4";
			else if constexpr ( std::is_same_v < T, sdw::DMat4x2 > ) return "DMat4x2";
			else if constexpr ( std::is_same_v < T, sdw::DMat4x3 > ) return "DMat4x3";
			else if constexpr ( std::is_same_v < T, sdw::DMat4x4 > ) return "DMat4x4";
		}
	};

	template< ast::type::ImageFormat FormatT >
	class CombinedImageTypesNamesT
	{
	public:
		template< typename TypeParam >
		static std::string GetName( int )
		{
			static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
			static bool constexpr ArrayedT = TypeParam::Arrayed;
			static bool constexpr MsT = TypeParam::Ms;
			static bool constexpr DepthT = TypeParam::Depth;
			return sdw::debug::getTypeName( sdw::typeEnumV< sdw::CombinedImage > )
				+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		}
	};

	template< ast::type::ImageFormat FormatT >
	class SampledImageTypesNamesT
	{
	public:
		template< typename TypeParam >
		static std::string GetName( int )
		{
			static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
			static bool constexpr ArrayedT = TypeParam::Arrayed;
			static bool constexpr MsT = TypeParam::Ms;
			static bool constexpr DepthT = TypeParam::Depth;
			return sdw::debug::getTypeName( sdw::typeEnumV< sdw::SampledImage > )
				+ sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
		}
	};

	template< ast::type::ImageFormat FormatT >
	class StorageImageTypesNamesT
	{
	public:
		template< typename TypeParam >
		static std::string GetName( int )
		{
			static ast::type::AccessKind constexpr AccessT = TypeParam::Access;
			static ast::type::ImageDim constexpr DimT = TypeParam::Dim;
			static bool constexpr ArrayedT = TypeParam::Arrayed;
			static bool constexpr MsT = TypeParam::Ms;
			return sdw::debug::getTypeName( sdw::typeEnumV< sdw::StorageImage > )
				+ sdw::debug::getImageTypeName( FormatT, AccessT, DimT, ArrayedT, MsT );
		}
	};

	template< typename T >
	T getZero( sdw::ShaderWriter & writer );

	template<>
	inline sdw::Boolean getZero< sdw::Boolean >( sdw::ShaderWriter & writer )
	{
		return sdw::Boolean{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), false )
			, true };
	}

	template<>
	inline sdw::Int8 getZero< sdw::Int8 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int8{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int8_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::Int16 getZero< sdw::Int16 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int16{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int16_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::Int32 getZero< sdw::Int32 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int32{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int32_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::Int64 getZero< sdw::Int64 >( sdw::ShaderWriter & writer )
	{
		return sdw::Int64{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int64_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::UInt8 getZero< sdw::UInt8 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt8{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint8_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::UInt16 getZero< sdw::UInt16 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt16{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint16_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::UInt32 getZero< sdw::UInt32 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt32{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint32_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::UInt64 getZero< sdw::UInt64 >( sdw::ShaderWriter & writer )
	{
		return sdw::UInt64{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint64_t( 0 ) )
			, true };
	}

	template<>
	inline sdw::Half getZero< sdw::Half >( sdw::ShaderWriter & writer )
	{
		return sdw::Half{ writer
			, getExprCache( writer ).makeCast( writer.getTypesCache().getHalf()
				, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 0.0f ) )
			, true };
	}

	template<>
	inline sdw::Float getZero< sdw::Float >( sdw::ShaderWriter & writer )
	{
		return sdw::Float{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 0.0f )
			, true };
	}

	template<>
	inline sdw::Double getZero< sdw::Double >( sdw::ShaderWriter & writer )
	{
		return sdw::Double{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 0.0 )
			, true };
	}

	template<>
	inline sdw::Vec2 getZero< sdw::Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::vec2( getZero< sdw::Float >( writer )
			, getZero< sdw::Float >( writer ) );
	}

	template<>
	inline sdw::Vec3 getZero< sdw::Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::vec3( getZero< sdw::Float >( writer )
			, getZero< sdw::Float >( writer )
			, getZero< sdw::Float >( writer ) );
	}

	template<>
	inline sdw::Vec4 getZero< sdw::Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::vec4( getZero< sdw::Float >( writer )
			, getZero< sdw::Float >( writer )
			, getZero< sdw::Float >( writer )
			, getZero< sdw::Float >( writer ) );
	}

	template<>
	inline sdw::DVec2 getZero< sdw::DVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dvec2( getZero< sdw::Double >( writer )
			, getZero< sdw::Double >( writer ) );
	}

	template<>
	inline sdw::DVec3 getZero< sdw::DVec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dvec3( getZero< sdw::Double >( writer )
			, getZero< sdw::Double >( writer )
			, getZero< sdw::Double >( writer ) );
	}

	template<>
	inline sdw::DVec4 getZero< sdw::DVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dvec4( getZero< sdw::Double >( writer )
			, getZero< sdw::Double >( writer )
			, getZero< sdw::Double >( writer )
			, getZero< sdw::Double >( writer ) );
	}

	template<>
	inline sdw::HVec2 getZero< sdw::HVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::f16vec2( getZero< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::HVec4 getZero< sdw::HVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::f16vec4( getZero< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::BVec2 getZero< sdw::BVec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::bvec2( getZero< sdw::Boolean >( writer )
			, getZero< sdw::Boolean >( writer ) );
	}

	template<>
	inline sdw::BVec3 getZero< sdw::BVec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::bvec3( getZero< sdw::Boolean >( writer )
			, getZero< sdw::Boolean >( writer )
			, getZero< sdw::Boolean >( writer ) );
	}

	template<>
	inline sdw::BVec4 getZero< sdw::BVec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::bvec4( getZero< sdw::Boolean >( writer )
			, getZero< sdw::Boolean >( writer )
			, getZero< sdw::Boolean >( writer )
			, getZero< sdw::Boolean >( writer ) );
	}

	template<>
	inline sdw::I8Vec2 getZero< sdw::I8Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::i8vec2( getZero< sdw::Int8 >( writer )
			, getZero< sdw::Int8 >( writer ) );
	}

	template<>
	inline sdw::I8Vec3 getZero< sdw::I8Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::i8vec3( getZero< sdw::Int8 >( writer )
			, getZero< sdw::Int8 >( writer )
			, getZero< sdw::Int8 >( writer ) );
	}

	template<>
	inline sdw::I8Vec4 getZero< sdw::I8Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::i8vec4( getZero< sdw::Int8 >( writer )
			, getZero< sdw::Int8 >( writer )
			, getZero< sdw::Int8 >( writer )
			, getZero< sdw::Int8 >( writer ) );
	}

	template<>
	inline sdw::I16Vec2 getZero< sdw::I16Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::i16vec2( getZero< sdw::Int16 >( writer )
			, getZero< sdw::Int16 >( writer ) );
	}

	template<>
	inline sdw::I16Vec3 getZero< sdw::I16Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::i16vec3( getZero< sdw::Int16 >( writer )
			, getZero< sdw::Int16 >( writer )
			, getZero< sdw::Int16 >( writer ) );
	}

	template<>
	inline sdw::I16Vec4 getZero< sdw::I16Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::i16vec4( getZero< sdw::Int16 >( writer )
			, getZero< sdw::Int16 >( writer )
			, getZero< sdw::Int16 >( writer )
			, getZero< sdw::Int16 >( writer ) );
	}

	template<>
	inline sdw::I32Vec2 getZero< sdw::I32Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec2( getZero< sdw::Int32 >( writer )
			, getZero< sdw::Int32 >( writer ) );
	}

	template<>
	inline sdw::I32Vec3 getZero< sdw::I32Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec3( getZero< sdw::Int32 >( writer )
			, getZero< sdw::Int32 >( writer )
			, getZero< sdw::Int32 >( writer ) );
	}

	template<>
	inline sdw::I32Vec4 getZero< sdw::I32Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::ivec4( getZero< sdw::Int32 >( writer )
			, getZero< sdw::Int32 >( writer )
			, getZero< sdw::Int32 >( writer )
			, getZero< sdw::Int32 >( writer ) );
	}

	template<>
	inline sdw::I64Vec2 getZero< sdw::I64Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::i64vec2( getZero< sdw::Int64 >( writer )
			, getZero< sdw::Int64 >( writer ) );
	}

	template<>
	inline sdw::I64Vec3 getZero< sdw::I64Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::i64vec3( getZero< sdw::Int64 >( writer )
			, getZero< sdw::Int64 >( writer )
			, getZero< sdw::Int64 >( writer ) );
	}

	template<>
	inline sdw::I64Vec4 getZero< sdw::I64Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::i64vec4( getZero< sdw::Int64 >( writer )
			, getZero< sdw::Int64 >( writer )
			, getZero< sdw::Int64 >( writer )
			, getZero< sdw::Int64 >( writer ) );
	}

	template<>
	inline sdw::U8Vec2 getZero< sdw::U8Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::u8vec2( getZero< sdw::UInt8 >( writer )
			, getZero< sdw::UInt8 >( writer ) );
	}

	template<>
	inline sdw::U8Vec3 getZero< sdw::U8Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::u8vec3( getZero< sdw::UInt8 >( writer )
			, getZero< sdw::UInt8 >( writer )
			, getZero< sdw::UInt8 >( writer ) );
	}

	template<>
	inline sdw::U8Vec4 getZero< sdw::U8Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::u8vec4( getZero< sdw::UInt8 >( writer )
			, getZero< sdw::UInt8 >( writer )
			, getZero< sdw::UInt8 >( writer )
			, getZero< sdw::UInt8 >( writer ) );
	}

	template<>
	inline sdw::U16Vec2 getZero< sdw::U16Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::u16vec2( getZero< sdw::UInt16 >( writer )
			, getZero< sdw::UInt16 >( writer ) );
	}

	template<>
	inline sdw::U16Vec3 getZero< sdw::U16Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::u16vec3( getZero< sdw::UInt16 >( writer )
			, getZero< sdw::UInt16 >( writer )
			, getZero< sdw::UInt16 >( writer ) );
	}

	template<>
	inline sdw::U16Vec4 getZero< sdw::U16Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::u16vec4( getZero< sdw::UInt16 >( writer )
			, getZero< sdw::UInt16 >( writer )
			, getZero< sdw::UInt16 >( writer )
			, getZero< sdw::UInt16 >( writer ) );
	}

	template<>
	inline sdw::U32Vec2 getZero< sdw::U32Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec2( getZero< sdw::UInt32 >( writer )
			, getZero< sdw::UInt32 >( writer ) );
	}

	template<>
	inline sdw::U32Vec3 getZero< sdw::U32Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec3( getZero< sdw::UInt32 >( writer )
			, getZero< sdw::UInt32 >( writer )
			, getZero< sdw::UInt32 >( writer ) );
	}

	template<>
	inline sdw::U32Vec4 getZero< sdw::U32Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::uvec4( getZero< sdw::UInt32 >( writer )
			, getZero< sdw::UInt32 >( writer )
			, getZero< sdw::UInt32 >( writer )
			, getZero< sdw::UInt32 >( writer ) );
	}

	template<>
	inline sdw::U64Vec2 getZero< sdw::U64Vec2 >( sdw::ShaderWriter & writer )
	{
		return sdw::u64vec2( getZero< sdw::UInt64 >( writer )
			, getZero< sdw::UInt64 >( writer ) );
	}

	template<>
	inline sdw::U64Vec3 getZero< sdw::U64Vec3 >( sdw::ShaderWriter & writer )
	{
		return sdw::u64vec3( getZero< sdw::UInt64 >( writer )
			, getZero< sdw::UInt64 >( writer )
			, getZero< sdw::UInt64 >( writer ) );
	}

	template<>
	inline sdw::U64Vec4 getZero< sdw::U64Vec4 >( sdw::ShaderWriter & writer )
	{
		return sdw::u64vec4( getZero< sdw::UInt64 >( writer )
			, getZero< sdw::UInt64 >( writer )
			, getZero< sdw::UInt64 >( writer )
			, getZero< sdw::UInt64 >( writer ) );
	}

	template<>
	inline sdw::Mat2 getZero< sdw::Mat2 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat2( getZero< sdw::Vec2 >( writer )
			, getZero< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::Mat2x3 getZero< sdw::Mat2x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat2x3( getZero< sdw::Vec3 >( writer )
			, getZero< sdw::Vec3 >( writer ) );
	}

	template<>
	inline sdw::Mat2x4 getZero< sdw::Mat2x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat2x4( getZero< sdw::Vec4 >( writer )
			, getZero< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::Mat3 getZero< sdw::Mat3 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat3( getZero< sdw::Vec3 >( writer )
			, getZero< sdw::Vec3 >( writer )
			, getZero< sdw::Vec3 >( writer ) );
	}

	template<>
	inline sdw::Mat3x2 getZero< sdw::Mat3x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat3x2( getZero< sdw::Vec2 >( writer )
			, getZero< sdw::Vec2 >( writer )
			, getZero< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::Mat3x4 getZero< sdw::Mat3x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat3x4( getZero< sdw::Vec4 >( writer )
			, getZero< sdw::Vec4 >( writer )
			, getZero< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::Mat4 getZero< sdw::Mat4 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat4( getZero< sdw::Vec4 >( writer )
			, getZero< sdw::Vec4 >( writer )
			, getZero< sdw::Vec4 >( writer )
			, getZero< sdw::Vec4 >( writer ) );
	}

	template<>
	inline sdw::Mat4x2 getZero< sdw::Mat4x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat4x2( getZero< sdw::Vec2 >( writer )
			, getZero< sdw::Vec2 >( writer )
			, getZero< sdw::Vec2 >( writer )
			, getZero< sdw::Vec2 >( writer ) );
	}

	template<>
	inline sdw::Mat4x3 getZero< sdw::Mat4x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::mat4x3( getZero< sdw::Vec3 >( writer )
			, getZero< sdw::Vec3 >( writer )
			, getZero< sdw::Vec3 >( writer )
			, getZero< sdw::Vec3 >( writer ) );
	}

	template<>
	inline sdw::DMat2 getZero< sdw::DMat2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat2( getZero< sdw::DVec2 >( writer )
			, getZero< sdw::DVec2 >( writer ) );
	}

	template<>
	inline sdw::DMat2x3 getZero< sdw::DMat2x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat2x3( getZero< sdw::DVec3 >( writer )
			, getZero< sdw::DVec3 >( writer ) );
	}

	template<>
	inline sdw::DMat2x4 getZero< sdw::DMat2x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat2x4( getZero< sdw::DVec4 >( writer )
			, getZero< sdw::DVec4 >( writer ) );
	}

	template<>
	inline sdw::DMat3 getZero< sdw::DMat3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat3( getZero< sdw::DVec3 >( writer )
			, getZero< sdw::DVec3 >( writer )
			, getZero< sdw::DVec3 >( writer ) );
	}

	template<>
	inline sdw::DMat3x2 getZero< sdw::DMat3x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat3x2( getZero< sdw::DVec2 >( writer )
			, getZero< sdw::DVec2 >( writer )
			, getZero< sdw::DVec2 >( writer ) );
	}

	template<>
	inline sdw::DMat3x4 getZero< sdw::DMat3x4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat3x4( getZero< sdw::DVec4 >( writer )
			, getZero< sdw::DVec4 >( writer )
			, getZero< sdw::DVec4 >( writer ) );
	}

	template<>
	inline sdw::DMat4 getZero< sdw::DMat4 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat4( getZero< sdw::DVec4 >( writer )
			, getZero< sdw::DVec4 >( writer )
			, getZero< sdw::DVec4 >( writer )
			, getZero< sdw::DVec4 >( writer ) );
	}

	template<>
	inline sdw::DMat4x2 getZero< sdw::DMat4x2 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat4x2( getZero< sdw::DVec2 >( writer )
			, getZero< sdw::DVec2 >( writer )
			, getZero< sdw::DVec2 >( writer )
			, getZero< sdw::DVec2 >( writer ) );
	}

	template<>
	inline sdw::DMat4x3 getZero< sdw::DMat4x3 >( sdw::ShaderWriter & writer )
	{
		return sdw::dmat4x3( getZero< sdw::DVec3 >( writer )
			, getZero< sdw::DVec3 >( writer )
			, getZero< sdw::DVec3 >( writer )
			, getZero< sdw::DVec3 >( writer ) );
	}

	template< typename T >
	T getDefault( sdw::ShaderWriter & writer, uint32_t index );

	template<>
	inline sdw::Boolean getDefault< sdw::Boolean >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Boolean{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), index != 0u )
			, true };
	}

	template<>
	inline sdw::Int8 getDefault< sdw::Int8 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Int8{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int8_t( 1 + index ) )
			, true };
	}

	template<>
	inline sdw::Int16 getDefault< sdw::Int16 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Int16{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int16_t( 1 + index ) )
			, true };
	}

	template<>
	inline sdw::Int32 getDefault< sdw::Int32 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Int32{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int32_t( 1 + index ) )
			, true };
	}

	template<>
	inline sdw::Int64 getDefault< sdw::Int64 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Int64{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), int64_t( 1 + index ) )
			, true };
	}

	template<>
	inline sdw::UInt8 getDefault< sdw::UInt8 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::UInt8{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint8_t( 1 + index ) )
			, true };
	}

	template<>
	inline sdw::UInt16 getDefault< sdw::UInt16 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::UInt16{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint16_t( 1 + index ) )
			, true };
	}

	template<>
	inline sdw::UInt32 getDefault< sdw::UInt32 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::UInt32{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint32_t( 1u + index ) )
			, true };
	}

	template<>
	inline sdw::UInt64 getDefault< sdw::UInt64 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::UInt64{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), uint64_t( 1ull + index ) )
			, true };
	}

	template<>
	inline sdw::Half getDefault< sdw::Half >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Half{ writer
			, getExprCache( writer ).makeCast( writer.getTypesCache().getHalf()
				, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 0.2f * float( index + 1 ) ) )
			, true };
	}

	template<>
	inline sdw::Float getDefault< sdw::Float >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Float{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 0.2f * float( index + 1 ) )
			, true };
	}

	template<>
	inline sdw::Double getDefault< sdw::Double >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::Double{ writer
			, getExprCache( writer ).makeLiteral( writer.getTypesCache(), 0.2 * double( index + 1 ) )
			, true };
	}

	template<>
	inline sdw::Vec2 getDefault< sdw::Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::vec2( getDefault< sdw::Float >( writer, index++ )
			, getDefault< sdw::Float >( writer, index++ ) );
	}

	template<>
	inline sdw::Vec3 getDefault< sdw::Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::vec3( getDefault< sdw::Float >( writer, index++ )
			, getDefault< sdw::Float >( writer, index++ )
			, getDefault< sdw::Float >( writer, index++ ) );
	}

	template<>
	inline sdw::Vec4 getDefault< sdw::Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::vec4( getDefault< sdw::Float >( writer, index++ )
			, getDefault< sdw::Float >( writer, index++ )
			, getDefault< sdw::Float >( writer, index++ )
			, getDefault< sdw::Float >( writer, index++ ) );
	}

	template<>
	inline sdw::DVec2 getDefault< sdw::DVec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dvec2( getDefault< sdw::Double >( writer, index++ )
			, getDefault< sdw::Double >( writer, index++ ) );
	}

	template<>
	inline sdw::DVec3 getDefault< sdw::DVec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dvec3( getDefault< sdw::Double >( writer, index++ )
			, getDefault< sdw::Double >( writer, index++ )
			, getDefault< sdw::Double >( writer, index++ ) );
	}

	template<>
	inline sdw::DVec4 getDefault< sdw::DVec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dvec4( getDefault< sdw::Double >( writer, index++ )
			, getDefault< sdw::Double >( writer, index++ )
			, getDefault< sdw::Double >( writer, index++ )
			, getDefault< sdw::Double >( writer, index++ ) );
	}

	template<>
	inline sdw::HVec2 getDefault< sdw::HVec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::f16vec2( getDefault< sdw::Vec2 >( writer, index ) );
	}

	template<>
	inline sdw::HVec4 getDefault< sdw::HVec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::f16vec4( getDefault< sdw::Vec4 >( writer, index ) );
	}

	template<>
	inline sdw::BVec2 getDefault< sdw::BVec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::bvec2( getDefault< sdw::Boolean >( writer, index++ )
			, getDefault< sdw::Boolean >( writer, index++ ) );
	}

	template<>
	inline sdw::BVec3 getDefault< sdw::BVec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::bvec3( getDefault< sdw::Boolean >( writer, index++ )
			, getDefault< sdw::Boolean >( writer, index++ )
			, getDefault< sdw::Boolean >( writer, index++ ) );
	}

	template<>
	inline sdw::BVec4 getDefault< sdw::BVec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::bvec4( getDefault< sdw::Boolean >( writer, index++ )
			, getDefault< sdw::Boolean >( writer, index++ )
			, getDefault< sdw::Boolean >( writer, index++ )
			, getDefault< sdw::Boolean >( writer, index++ ) );
	}

	template<>
	inline sdw::I8Vec2 getDefault< sdw::I8Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i8vec2( getDefault< sdw::Int8 >( writer, index++ )
			, getDefault< sdw::Int8 >( writer, index++ ) );
	}

	template<>
	inline sdw::I8Vec3 getDefault< sdw::I8Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i8vec3( getDefault< sdw::Int8 >( writer, index++ )
			, getDefault< sdw::Int8 >( writer, index++ )
			, getDefault< sdw::Int8 >( writer, index++ ) );
	}

	template<>
	inline sdw::I8Vec4 getDefault< sdw::I8Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i8vec4( getDefault< sdw::Int8 >( writer, index++ )
			, getDefault< sdw::Int8 >( writer, index++ )
			, getDefault< sdw::Int8 >( writer, index++ )
			, getDefault< sdw::Int8 >( writer, index++ ) );
	}

	template<>
	inline sdw::I16Vec2 getDefault< sdw::I16Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i16vec2( getDefault< sdw::Int16 >( writer, index++ )
			, getDefault< sdw::Int16 >( writer, index++ ) );
	}

	template<>
	inline sdw::I16Vec3 getDefault< sdw::I16Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i16vec3( getDefault< sdw::Int16 >( writer, index++ )
			, getDefault< sdw::Int16 >( writer, index++ )
			, getDefault< sdw::Int16 >( writer, index++ ) );
	}

	template<>
	inline sdw::I16Vec4 getDefault< sdw::I16Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i16vec4( getDefault< sdw::Int16 >( writer, index++ )
			, getDefault< sdw::Int16 >( writer, index++ )
			, getDefault< sdw::Int16 >( writer, index++ )
			, getDefault< sdw::Int16 >( writer, index++ ) );
	}

	template<>
	inline sdw::I32Vec2 getDefault< sdw::I32Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::ivec2( getDefault< sdw::Int32 >( writer, index++ )
			, getDefault< sdw::Int32 >( writer, index++ ) );
	}

	template<>
	inline sdw::I32Vec3 getDefault< sdw::I32Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::ivec3( getDefault< sdw::Int32 >( writer, index++ )
			, getDefault< sdw::Int32 >( writer, index++ )
			, getDefault< sdw::Int32 >( writer, index++ ) );
	}

	template<>
	inline sdw::I32Vec4 getDefault< sdw::I32Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::ivec4( getDefault< sdw::Int32 >( writer, index++ )
			, getDefault< sdw::Int32 >( writer, index++ )
			, getDefault< sdw::Int32 >( writer, index++ )
			, getDefault< sdw::Int32 >( writer, index++ ) );
	}

	template<>
	inline sdw::I64Vec2 getDefault< sdw::I64Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i64vec2( getDefault< sdw::Int64 >( writer, index++ )
			, getDefault< sdw::Int64 >( writer, index++ ) );
	}

	template<>
	inline sdw::I64Vec3 getDefault< sdw::I64Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i64vec3( getDefault< sdw::Int64 >( writer, index++ )
			, getDefault< sdw::Int64 >( writer, index++ )
			, getDefault< sdw::Int64 >( writer, index++ ) );
	}

	template<>
	inline sdw::I64Vec4 getDefault< sdw::I64Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::i64vec4( getDefault< sdw::Int64 >( writer, index++ )
			, getDefault< sdw::Int64 >( writer, index++ )
			, getDefault< sdw::Int64 >( writer, index++ )
			, getDefault< sdw::Int64 >( writer, index++ ) );
	}

	template<>
	inline sdw::U8Vec2 getDefault< sdw::U8Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u8vec2( getDefault< sdw::UInt8 >( writer, index++ )
			, getDefault< sdw::UInt8 >( writer, index++ ) );
	}

	template<>
	inline sdw::U8Vec3 getDefault< sdw::U8Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u8vec3( getDefault< sdw::UInt8 >( writer, index++ )
			, getDefault< sdw::UInt8 >( writer, index++ )
			, getDefault< sdw::UInt8 >( writer, index++ ) );
	}

	template<>
	inline sdw::U8Vec4 getDefault< sdw::U8Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u8vec4( getDefault< sdw::UInt8 >( writer, index++ )
			, getDefault< sdw::UInt8 >( writer, index++ )
			, getDefault< sdw::UInt8 >( writer, index++ )
			, getDefault< sdw::UInt8 >( writer, index++ ) );
	}

	template<>
	inline sdw::U16Vec2 getDefault< sdw::U16Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u16vec2( getDefault< sdw::UInt16 >( writer, index++ )
			, getDefault< sdw::UInt16 >( writer, index++ ) );
	}

	template<>
	inline sdw::U16Vec3 getDefault< sdw::U16Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u16vec3( getDefault< sdw::UInt16 >( writer, index++ )
			, getDefault< sdw::UInt16 >( writer, index++ )
			, getDefault< sdw::UInt16 >( writer, index++ ) );
	}

	template<>
	inline sdw::U16Vec4 getDefault< sdw::U16Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u16vec4( getDefault< sdw::UInt16 >( writer, index++ )
			, getDefault< sdw::UInt16 >( writer, index++ )
			, getDefault< sdw::UInt16 >( writer, index++ )
			, getDefault< sdw::UInt16 >( writer, index++ ) );
	}

	template<>
	inline sdw::U32Vec2 getDefault< sdw::U32Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::uvec2( getDefault< sdw::UInt32 >( writer, index++ )
			, getDefault< sdw::UInt32 >( writer, index++ ) );
	}

	template<>
	inline sdw::U32Vec3 getDefault< sdw::U32Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::uvec3( getDefault< sdw::UInt32 >( writer, index++ )
			, getDefault< sdw::UInt32 >( writer, index++ )
			, getDefault< sdw::UInt32 >( writer, index++ ) );
	}

	template<>
	inline sdw::U32Vec4 getDefault< sdw::U32Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::uvec4( getDefault< sdw::UInt32 >( writer, index++ )
			, getDefault< sdw::UInt32 >( writer, index++ )
			, getDefault< sdw::UInt32 >( writer, index++ )
			, getDefault< sdw::UInt32 >( writer, index++ ) );
	}

	template<>
	inline sdw::U64Vec2 getDefault< sdw::U64Vec2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u64vec2( getDefault< sdw::UInt64 >( writer, index++ )
			, getDefault< sdw::UInt64 >( writer, index++ ) );
	}

	template<>
	inline sdw::U64Vec3 getDefault< sdw::U64Vec3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u64vec3( getDefault< sdw::UInt64 >( writer, index++ )
			, getDefault< sdw::UInt64 >( writer, index++ )
			, getDefault< sdw::UInt64 >( writer, index++ ) );
	}

	template<>
	inline sdw::U64Vec4 getDefault< sdw::U64Vec4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::u64vec4( getDefault< sdw::UInt64 >( writer, index++ )
			, getDefault< sdw::UInt64 >( writer, index++ )
			, getDefault< sdw::UInt64 >( writer, index++ )
			, getDefault< sdw::UInt64 >( writer, index++ ) );
	}

	template<>
	inline sdw::Mat2 getDefault< sdw::Mat2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat2( getDefault< sdw::Vec2 >( writer, index + 0 )
			, getDefault< sdw::Vec2 >( writer, index + 2 ) );
	}

	template<>
	inline sdw::Mat2x3 getDefault< sdw::Mat2x3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat2x3( getDefault< sdw::Vec3 >( writer, index + 0 )
			, getDefault< sdw::Vec3 >( writer, index + 3 ) );
	}

	template<>
	inline sdw::Mat2x4 getDefault< sdw::Mat2x4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat2x4( getDefault< sdw::Vec4 >( writer, index + 0 )
			, getDefault< sdw::Vec4 >( writer, index + 4 ) );
	}

	template<>
	inline sdw::Mat3 getDefault< sdw::Mat3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat3( getDefault< sdw::Vec3 >( writer, index + 0 )
			, getDefault< sdw::Vec3 >( writer, index + 3 )
			, getDefault< sdw::Vec3 >( writer, index + 6 ) );
	}

	template<>
	inline sdw::Mat3x2 getDefault< sdw::Mat3x2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat3x2( getDefault< sdw::Vec2 >( writer, index + 0 )
			, getDefault< sdw::Vec2 >( writer, index + 2 )
			, getDefault< sdw::Vec2 >( writer, index + 4 ) );
	}

	template<>
	inline sdw::Mat3x4 getDefault< sdw::Mat3x4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat3x4( getDefault< sdw::Vec4 >( writer, index + 0 )
			, getDefault< sdw::Vec4 >( writer, index + 4 )
			, getDefault< sdw::Vec4 >( writer, index + 8 ) );
	}

	template<>
	inline sdw::Mat4 getDefault< sdw::Mat4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat4( getDefault< sdw::Vec4 >( writer, index + 0 )
			, getDefault< sdw::Vec4 >( writer, index + 4 )
			, getDefault< sdw::Vec4 >( writer, index + 8 )
			, getDefault< sdw::Vec4 >( writer, index + 12 ) );
	}

	template<>
	inline sdw::Mat4x2 getDefault< sdw::Mat4x2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat4x2( getDefault< sdw::Vec2 >( writer, index + 0 )
			, getDefault< sdw::Vec2 >( writer, index + 2 )
			, getDefault< sdw::Vec2 >( writer, index + 4 )
			, getDefault< sdw::Vec2 >( writer, index + 6 ) );
	}

	template<>
	inline sdw::Mat4x3 getDefault< sdw::Mat4x3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::mat4x3( getDefault< sdw::Vec3 >( writer, index + 0 )
			, getDefault< sdw::Vec3 >( writer, index + 3 )
			, getDefault< sdw::Vec3 >( writer, index + 6 )
			, getDefault< sdw::Vec3 >( writer, index + 9 ) );
	}

	template<>
	inline sdw::DMat2 getDefault< sdw::DMat2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat2( getDefault< sdw::DVec2 >( writer, index + 0 )
			, getDefault< sdw::DVec2 >( writer, index + 2 ) );
	}

	template<>
	inline sdw::DMat2x3 getDefault< sdw::DMat2x3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat2x3( getDefault< sdw::DVec3 >( writer, index + 0 )
			, getDefault< sdw::DVec3 >( writer, index + 3 ) );
	}

	template<>
	inline sdw::DMat2x4 getDefault< sdw::DMat2x4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat2x4( getDefault< sdw::DVec4 >( writer, index + 0 )
			, getDefault< sdw::DVec4 >( writer, index + 4 ) );
	}

	template<>
	inline sdw::DMat3 getDefault< sdw::DMat3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat3( getDefault< sdw::DVec3 >( writer, index + 0 )
			, getDefault< sdw::DVec3 >( writer, index + 3 )
			, getDefault< sdw::DVec3 >( writer, index + 6 ) );
	}

	template<>
	inline sdw::DMat3x2 getDefault< sdw::DMat3x2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat3x2( getDefault< sdw::DVec2 >( writer, index + 0 )
			, getDefault< sdw::DVec2 >( writer, index + 2 )
			, getDefault< sdw::DVec2 >( writer, index + 4 ) );
	}

	template<>
	inline sdw::DMat3x4 getDefault< sdw::DMat3x4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat3x4( getDefault< sdw::DVec4 >( writer, index + 0 )
			, getDefault< sdw::DVec4 >( writer, index + 4 )
			, getDefault< sdw::DVec4 >( writer, index + 8 ) );
	}

	template<>
	inline sdw::DMat4 getDefault< sdw::DMat4 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat4( getDefault< sdw::DVec4 >( writer, index + 0 )
			, getDefault< sdw::DVec4 >( writer, index + 4 )
			, getDefault< sdw::DVec4 >( writer, index + 8 )
			, getDefault< sdw::DVec4 >( writer, index + 12 ) );
	}

	template<>
	inline sdw::DMat4x2 getDefault< sdw::DMat4x2 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat4x2( getDefault< sdw::DVec2 >( writer, index + 0 )
			, getDefault< sdw::DVec2 >( writer, index + 2 )
			, getDefault< sdw::DVec2 >( writer, index + 4 )
			, getDefault< sdw::DVec2 >( writer, index + 6 ) );
	}

	template<>
	inline sdw::DMat4x3 getDefault< sdw::DMat4x3 >( sdw::ShaderWriter & writer, uint32_t index )
	{
		return sdw::dmat4x3( getDefault< sdw::DVec3 >( writer, index + 0 )
			, getDefault< sdw::DVec3 >( writer, index + 3 )
			, getDefault< sdw::DVec3 >( writer, index + 6 )
			, getDefault< sdw::DVec3 >( writer, index + 9 ) );
	}

	template< typename T >
	T getDefault( sdw::ShaderWriter & writer )
	{
		return getDefault< T >( writer, 0u );
	}

	template< typename T >
	inline std::vector< T > getDefaultVector( sdw::ShaderWriter & writer
		, uint32_t dimension )
	{
		std::vector< T > result;

		for ( auto i = 0u; i < dimension; ++i )
		{
			result.emplace_back( getDefault< T >( writer, i ) );
		}

		return result;
	}

	template< typename T >
	inline sdw::Array< T > getDefaultArray( sdw::ShaderWriter & writer
		, uint32_t dimension )
	{
		ast::expr::ExprList initialisers;

		for ( auto i = 0u; i < dimension; ++i )
		{
			initialisers.emplace_back( sdw::makeExpr( getDefault< T >( writer ) ) );
		}

		auto type = writer.getTypesCache().getArray( initialisers.front()->getType(), dimension );
		return sdw::Array< T >{ writer
			, getExprCache( writer ).makeAggrInit( std::move( type ), std::move( initialisers ) )
			, true };
	}

}
