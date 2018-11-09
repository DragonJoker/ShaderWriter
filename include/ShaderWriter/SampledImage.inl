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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >::SampledImageT( Shader * shader
		, expr::ExprPtr expr
		, ast::type::ImageFormat format )
		: SampledImage{ shader, std::move( expr ), format }
	{
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT > & SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( m_expr->getType()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >::operator uint32_t()
	{
		return 0u;
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >::makeConfig( ast::type::ImageFormat format )
	{
		return ast::type::makeConfig< SampledT, DimT, ArrayedT, DepthT, MsT >( format, true, true );
	}

	//*************************************************************************
}
