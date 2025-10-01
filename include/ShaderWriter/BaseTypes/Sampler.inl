/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename T >
	ReturnWrapperT< Sampler > Sampler::operator=( T const & rhs )
	{
		return writeAssignOperator< Sampler >( *this, rhs, sdw::makeAssign );
	}

	//*************************************************************************

	template< bool ComparisonT >
	SamplerT< ComparisonT >::SamplerT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Sampler{ writer, std::move( expr ), enabled }
	{
	}

	template< bool ComparisonT >
	template< typename T >
	ReturnWrapperT< SamplerT< ComparisonT > > SamplerT< ComparisonT >::operator=( T const & rhs )
	{
		return writeAssignOperator< SamplerT >( *this, rhs, sdw::makeAssign );
	}

	template< bool ComparisonT >
	bool SamplerT< ComparisonT >::makeConfig()
	{
		return ComparisonT;
	}

	template< bool ComparisonT >
	inline ast::type::TypePtr SamplerT< ComparisonT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getSampler( makeConfig() );
	}

	//*************************************************************************
}
