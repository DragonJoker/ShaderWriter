/*
See LICENSE file in root folder
*/
namespace sdw
{
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
}
