/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename T >
	SampledImage & SampledImage::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	SampledImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::SampledImageT( Shader * shader
		, expr::ExprPtr expr )
		: SampledImage{ shader, std::move( expr ) }
	{
	}

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	SampledImageT< DimT, FormatT, ArrayedT, DepthT, MsT > & SampledImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	SampledImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::operator uint32_t()
	{
		return 0u;
	}

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration SampledImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return sdw::makeConfig< DimT, FormatT, ArrayedT, DepthT, MsT >( true, true );
	}

	//*************************************************************************
}
