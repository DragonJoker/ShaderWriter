/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e1D, false >
	{
		using Type = sdw::Int;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e2D, false >
	{
		using Type = sdw::IVec2;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e3D, false >
	{
		using Type = sdw::IVec3;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::eRect, false >
	{
		using Type = sdw::IVec2;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::eCube, false >
	{
		using Type = sdw::IVec3;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::eBuffer, false >
	{
		using Type = sdw::Int;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e1D, true >
	{
		using Type = sdw::IVec2;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::e2D, true >
	{
		using Type = sdw::IVec3;
	};

	template<>
	struct ImageCoordsGetter< ast::type::ImageDim::eCube, true >
	{
		using Type = sdw::IVec3;
	};

	//*****************************************************************************************

	template< typename T >
	Image & Image::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::ImageT( Shader * shader
		, expr::ExprPtr expr )
		: Image{ shader, std::move( expr ) }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::ImageT( ImageT const & rhs )
		: Image{ rhs }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > & ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::operator uint32_t()
	{
		return 0u;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, DimT, ArrayedT, DepthT, MsT >( false, false );
	}

	//*****************************************************************************************
}