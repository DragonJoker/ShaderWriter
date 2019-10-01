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
	inline expr::ExprPtr makeConstExpr( Shader const & shader
		, T const & value
		, bool force )
	{
		expr::ExprPtr result = makeExpr( shader, value, force );

		if ( result )
		{
			result->updateFlag( ast::expr::Flag::eConstant );
		}

		return result;
	}

	template< typename T >
	expr::ExprList makeExpr( Shader const & shader
		, std::vector< T > const & values
		, bool force )
	{
		expr::ExprList result;

		for ( auto & value : values )
		{
			result.emplace_back( makeExpr( shader, value, force ) );
		}

		return result;
	}

	template< typename T >
	inline expr::ExprList makeConstExpr( Shader const & shader
		, std::vector< T > const & values
		, bool force )
	{
		expr::ExprList result;

		for ( auto & value : values )
		{
			result.emplace_back( makeExpr( shader, value, force ) );
			result.back()->updateFlag( ast::expr::Flag::eConstant );
		}

		return result;
	}

	template< typename ValueT >
	ast::type::TypePtr makeType( ast::type::TypesCache & cache )
	{
		auto kind = typeEnum< ValueT >;

		switch ( kind )
		{
		case ast::type::Kind::eStruct:
			assert( false );
			return nullptr;
		case ast::type::Kind::eImage:
			return cache.getImage( makeConfig< ValueT >() );
		case ast::type::Kind::eSampledImage:
			return cache.getSampledImage( makeConfig< ValueT >() );
		default:
			return cache.getBasicType( kind );
		}
	}

	template< typename ValueT >
	expr::ExprPtr makeCondition( ValueT const & value )
	{
		return value.makeCondition();
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
