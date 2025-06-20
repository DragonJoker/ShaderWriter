/*
See LICENSE file in root folder
*/
namespace ast::type
{
	template<>
	struct ImageFormatTraits< ImageFormat::eUnknown >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba32f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4H;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
		static Kind constexpr TexelType = Kind::eVec2F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
		static Kind constexpr TexelType = Kind::eVec2H;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
		static Kind constexpr TexelType = Kind::eFloat;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
		static Kind constexpr TexelType = Kind::eHalf;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR11fG11fB10f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec3F;
		static Kind constexpr TexelType = Kind::eVec3F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eVec4I32;
		static Kind constexpr TexelType = Kind::eVec4I32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eVec4I32;
		static Kind constexpr TexelType = Kind::eVec4I32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eVec4I32;
		static Kind constexpr TexelType = Kind::eVec4I32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eVec2I32;
		static Kind constexpr TexelType = Kind::eVec2I32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eVec2I32;
		static Kind constexpr TexelType = Kind::eVec2I32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eVec2I32;
		static Kind constexpr TexelType = Kind::eVec2I32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eInt32;
		static Kind constexpr TexelType = Kind::eInt32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eInt32;
		static Kind constexpr TexelType = Kind::eInt32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt32;
		static Kind constexpr SampledType = Kind::eInt32;
		static Kind constexpr TexelType = Kind::eInt32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eVec4U32;
		static Kind constexpr TexelType = Kind::eVec4U32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eVec4U32;
		static Kind constexpr TexelType = Kind::eVec4U32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eVec4U32;
		static Kind constexpr TexelType = Kind::eVec4U32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eVec2U32;
		static Kind constexpr TexelType = Kind::eVec2U32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eVec2U32;
		static Kind constexpr TexelType = Kind::eVec2U32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eVec2U32;
		static Kind constexpr TexelType = Kind::eVec2U32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eUInt32;
		static Kind constexpr TexelType = Kind::eUInt32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eUInt32;
		static Kind constexpr TexelType = Kind::eUInt32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eUInt32;
		static Kind constexpr TexelType = Kind::eUInt32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgb10A2u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt32;
		static Kind constexpr SampledType = Kind::eVec4U32;
		static Kind constexpr TexelType = Kind::eVec4U32;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16Snorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8Snorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16Snorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
		static Kind constexpr TexelType = Kind::eVec2F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8Snorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
		static Kind constexpr TexelType = Kind::eVec2F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16Snorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
		static Kind constexpr TexelType = Kind::eFloat;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8Snorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
		static Kind constexpr TexelType = Kind::eFloat;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16Unorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8Unorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16Unorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
		static Kind constexpr TexelType = Kind::eVec2F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8Unorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
		static Kind constexpr TexelType = Kind::eVec2F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16Unorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
		static Kind constexpr TexelType = Kind::eFloat;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8Unorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
		static Kind constexpr TexelType = Kind::eFloat;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgb10A2Unorm >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
		static Kind constexpr TexelType = Kind::eVec4F;
	};

	template< ImageFormat FormatT
		, AccessKind AccessT
		, ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline ImageConfiguration makeConfig( bool sampled )noexcept
	{
		return ImageConfiguration
		{
			sampledBaseType< FormatT >,
			DimT,
			FormatT,
			sampled ? Trinary::eTrue : Trinary::eFalse,
			ArrayedT,
			MsT,
			AccessT,
		};
	}
}
