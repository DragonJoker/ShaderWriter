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
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct ConfigMaker< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > >
		{
			static ast::type::ImageConfiguration get()
			{
				return StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::makeConfig();
			}
		};
	}

	template< typename T >
	inline expr::ExprPtr makeConstExpr( ShaderWriter const & shader
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
	expr::ExprList makeExpr( ShaderWriter const & shader
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
	inline expr::ExprList makeConstExpr( ShaderWriter const & shader
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
		auto kind = typeEnumV< ValueT >;

		switch ( kind )
		{
		case ast::type::Kind::eStruct:
		case ast::type::Kind::eRayDesc:
		case ast::type::Kind::eSampler:
			assert( false );
			return nullptr;
		case ast::type::Kind::eImage:
			return cache.getImage( makeConfig< ValueT >() );
		case ast::type::Kind::eSampledImage:
			return cache.getSampledImage( makeConfig< ValueT >() );
		case ast::type::Kind::eCombinedImage:
			return cache.getCombinedImage( makeConfig< ValueT >(), false );
		default:
			return cache.getBasicType( kind );
		}
	}

	template< typename ValueT >
	expr::ExprPtr makeCondition( ValueT value )
	{
		return value.makeCondition();
	}

	template< typename ValueT >
	ast::type::ImageConfiguration makeConfig()
	{
		return details::ConfigMaker< ValueT >::get();
	}
}
