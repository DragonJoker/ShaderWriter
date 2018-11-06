/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*****************************************************************************************

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration makeConfig( bool sampled
		, bool readOnly )
	{
		ast::type::ImageConfiguration result{};
		result.isMS = MsT;
		result.isArrayed = ArrayedT;
		result.isDepth = DepthT ? ast::type::Ternary::eTrue : ast::type::Ternary::eFalse;
		result.format = FormatT;
		result.dimension = DimT;
		result.isSampled = sampled ? ast::type::Ternary::eTrue : ast::type::Ternary::eFalse;
		result.accessKind = readOnly ? ast::type::AccessKind::eRead : ast::type::AccessKind::eReadWrite;
		return result;
	}

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

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::ImageT( Shader * shader
		, expr::ExprPtr expr )
		: Image{ shader, std::move( expr ) }
	{
	}

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::ImageT( ImageT const & rhs )
		: Image{ rhs }
	{
	}

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	ImageT< DimT, FormatT, ArrayedT, DepthT, MsT > & ImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
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
	ImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::operator uint32_t()
	{
		return 0u;
	}

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration ImageT< DimT, FormatT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return sdw::makeConfig< DimT, FormatT, ArrayedT, DepthT, MsT >( false, false );
	}

	//*****************************************************************************************
}
