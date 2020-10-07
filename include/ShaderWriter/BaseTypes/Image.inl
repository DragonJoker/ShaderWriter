/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eUnknown >
	{
		using SampleType = Vec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba32f >
	{
		using SampleType = Vec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba16f >
	{
		using SampleType = HVec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg32f >
	{
		using SampleType = Vec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg16f >
	{
		using SampleType = HVec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR32f >
	{
		using SampleType = Float;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR16f >
	{
		using SampleType = Half;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba32i >
	{
		using SampleType = IVec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba16i >
	{
		using SampleType = IVec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba8i >
	{
		using SampleType = IVec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg32i >
	{
		using SampleType = IVec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg16i >
	{
		using SampleType = IVec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg8i >
	{
		using SampleType = IVec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR32i >
	{
		using SampleType = Int;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR16i >
	{
		using SampleType = Int;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR8i >
	{
		using SampleType = Int;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba32u >
	{
		using SampleType = UVec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba16u >
	{
		using SampleType = UVec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRgba8u >
	{
		using SampleType = UVec4;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg32u >
	{
		using SampleType = UVec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg16u >
	{
		using SampleType = UVec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eRg8u >
	{
		using SampleType = UVec2;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR32u >
	{
		using SampleType = UInt;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR16u >
	{
		using SampleType = UInt;
	};

	template<>
	struct ImageSampleGetter< ast::type::ImageFormat::eR8u >
	{
		using SampleType = UInt;
	};

	//*****************************************************************************************

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e1D, false >
	{
		using CoordsType = sdw::Int;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e2D, false >
	{
		using CoordsType = sdw::IVec2;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e3D, false >
	{
		using CoordsType = sdw::IVec3;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::eCube, false >
	{
		using CoordsType = sdw::IVec3;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::eBuffer, false >
	{
		using CoordsType = sdw::Int;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e1D, true >
	{
		using CoordsType = sdw::IVec2;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e2D, true >
	{
		using CoordsType = sdw::IVec3;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::eCube, true >
	{
		using CoordsType = sdw::IVec3;
	};

	//*****************************************************************************************

	template< typename T >
	Image & Image::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = *findShader( *this, rhs );
		addStmt( shader
			, sdw::makeSimple( sdw::makeAssign( getExpr()->getType()
				, makeExpr( shader, getExpr() )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::ImageT( Shader * shader
		, expr::ExprPtr expr )
		: Image{ FormatT, shader, std::move( expr ) }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::ImageT( ImageT const & rhs )
		: Image{ rhs }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > & ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = *findShader( *this, rhs );
		addStmt( shader
			, sdw::makeSimple( sdw::makeAssign( getExpr()->getType()
				, makeExpr( shader, getExpr() )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::operator uint32_t()
	{
		return 0u;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >( false );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ast::type::TypePtr ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getImage( makeConfig() );
	}

	//*****************************************************************************************
}
