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
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba32f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec4F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eVec2F;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16f >
	{
		static Kind constexpr SampledBaseType = Kind::eFloat;
		static Kind constexpr SampledType = Kind::eFloat;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec4I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec4I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec4I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec2I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec2I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eVec2I;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8i >
	{
		static Kind constexpr SampledBaseType = Kind::eInt;
		static Kind constexpr SampledType = Kind::eInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec4U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec4U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRgba8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec4U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec2U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec2U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eRg8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eVec2U;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR32u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eUInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR16u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eUInt;
	};

	template<>
	struct ImageFormatTraits< ImageFormat::eR8u >
	{
		static Kind constexpr SampledBaseType = Kind::eUInt;
		static Kind constexpr SampledType = Kind::eUInt;
	};

	template< ImageFormat FormatT
		, ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ImageConfiguration makeConfig( bool sampled
		, bool readOnly )
	{
		return ImageConfiguration
		{
			sampledBaseType< FormatT >,
			DimT,
			FormatT,
			DepthT ? Trinary::eTrue : Trinary::eFalse,
			sampled ? Trinary::eTrue : Trinary::eFalse,
			ArrayedT,
			MsT,
			readOnly ? AccessKind::eRead : AccessKind::eReadWrite
		};
	}

	template< typename T >
	inline size_t hashCombine( size_t & hash
		, T const & rhs )
	{
		const uint64_t kMul = 0x9ddfea08eb382d69ULL;
		auto seed = hash;

		std::hash< T > hasher;
		uint64_t a = ( hasher( rhs ) ^ seed ) * kMul;
		a ^= ( a >> 47 );

		uint64_t b = ( seed ^ a ) * kMul;
		b ^= ( b >> 47 );

		hash = static_cast< std::size_t >( b * kMul );
		return hash;
	}}
