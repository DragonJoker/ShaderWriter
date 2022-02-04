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
	struct ImageFormatTraits< ImageFormat::eRgba32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec4I;
		static Kind constexpr TexelType = Kind::eVec4I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec4I;
		static Kind constexpr TexelType = Kind::eVec4I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec4I;
		static Kind constexpr TexelType = Kind::eVec4I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec2I;
		static Kind constexpr TexelType = Kind::eVec2I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec2I;
		static Kind constexpr TexelType = Kind::eVec2I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec2I;
		static Kind constexpr TexelType = Kind::eVec2I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eInt;
		static Kind constexpr TexelType = Kind::eInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eInt;
		static Kind constexpr TexelType = Kind::eInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eInt;
		static Kind constexpr TexelType = Kind::eInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec4U;
		static Kind constexpr TexelType = Kind::eVec4U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec4U;
		static Kind constexpr TexelType = Kind::eVec4U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec4U;
		static Kind constexpr TexelType = Kind::eVec4U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec2U;
		static Kind constexpr TexelType = Kind::eVec2U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec2U;
		static Kind constexpr TexelType = Kind::eVec2U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec2U;
		static Kind constexpr TexelType = Kind::eVec2U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eUInt;
		static Kind constexpr TexelType = Kind::eUInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eUInt;
		static Kind constexpr TexelType = Kind::eUInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eUInt;
		static Kind constexpr TexelType = Kind::eUInt;
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
