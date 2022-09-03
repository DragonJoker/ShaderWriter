/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <array>

namespace sdw
{
	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eUnknown >
	{
		using SampleType = Vec4;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba32f >
	{
		using SampleType = Vec4;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba16f >
	{
		using SampleType = Vec4;
		using FetchType = Vec4;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg32f >
	{
		using SampleType = Vec2;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg16f >
	{
		using SampleType = Vec2;
		using FetchType = Vec2;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR32f >
	{
		using SampleType = Float;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR16f >
	{
		using SampleType = Float;
		using FetchType = Float;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba32i >
	{
		using SampleType = I32Vec4;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba16i >
	{
		using SampleType = I32Vec4;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba8i >
	{
		using SampleType = I32Vec4;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg32i >
	{
		using SampleType = I32Vec2;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg16i >
	{
		using SampleType = I32Vec2;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg8i >
	{
		using SampleType = I32Vec2;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR32i >
	{
		using SampleType = Int32;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR16i >
	{
		using SampleType = Int32;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR8i >
	{
		using SampleType = Int32;
		using FetchType = SampleType;
		using GatherType = I32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 8u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba32u >
	{
		using SampleType = U32Vec4;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba16u >
	{
		using SampleType = U32Vec4;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRgba8u >
	{
		using SampleType = U32Vec4;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg32u >
	{
		using SampleType = U32Vec2;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg16u >
	{
		using SampleType = U32Vec2;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eRg8u >
	{
		using SampleType = U32Vec2;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR32u >
	{
		using SampleType = UInt32;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR16u >
	{
		using SampleType = UInt32;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< type::ImageFormat::eR8u >
	{
		using SampleType = UInt32;
		using FetchType = SampleType;
		using GatherType = U32Vec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 8u;
	};
}
