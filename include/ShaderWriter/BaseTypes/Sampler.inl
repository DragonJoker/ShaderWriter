/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*************************************************************************

	template< typename T >
	Sampler & Sampler::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = findWriterMandat( *this, rhs );

		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( shader
				, sdw::makeSimple( getStmtCache( m_writer )
					, sdw::makeAssign( getExpr()->getType()
						, makeExpr( shader, getExpr() )
						, makeExpr( shader, rhs ) ) ) );
		}

		return *this;
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
	SamplerT< ComparisonT > & SamplerT< ComparisonT >::operator=( T const & rhs )
	{
		Sampler::operator=( rhs );
		return *this;
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
