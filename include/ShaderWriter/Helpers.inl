/*
See LICENSE file in root folder
*/
namespace sdw
{
	namespace details
	{
		template< typename ValueT >
		struct ConfigMaker
		{
			static ast::type::ImageConfiguration get()
			{
				return ast::type::ImageConfiguration{};
			}
		};

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ConfigMaker< ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > >
		{
			static ast::type::ImageConfiguration get()
			{
				return ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::makeConfig();
			}
		};

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ConfigMaker< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > >
		{
			static ast::type::ImageConfiguration get()
			{
				return SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::makeConfig();
			}
		};
	}

	template< typename T >
	expr::ExprList makeExpr( std::vector< T > const & values )
	{
		expr::ExprList result;

		for ( auto & value : values )
		{
			result.emplace_back( makeExpr( value ) );
		}

		return result;
	}

	template< typename ValueT >
	ast::type::TypePtr makeType()
	{
		auto kind = typeEnum< ValueT >;

		switch ( kind )
		{
		case ast::type::Kind::eStruct:
			assert( false );
			return nullptr;
		case ast::type::Kind::eImage:
			return type::makeImageType( makeConfig< ValueT >() );
		case ast::type::Kind::eSampledImage:
			return type::makeSampledImageType( makeConfig< ValueT >() );
		default:
			return type::makeType( kind );
		}
	}

	template< typename ValueT >
	ast::type::ImageConfiguration makeConfig()
	{
		auto kind = typeEnum< ValueT >;
		assert( kind == ast::type::Kind::eImage
			|| kind == ast::type::Kind::eSampledImage );
		return details::ConfigMaker< ValueT >::get();
	}
}
