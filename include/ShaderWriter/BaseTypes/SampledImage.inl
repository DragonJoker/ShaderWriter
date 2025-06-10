/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/Sampler.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	SampledImageT< FormatT, DimT, ArrayedT, MsT >::SampledImageT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: SampledImage{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	template< typename T >
	ReturnWrapperT< SampledImageT< FormatT, DimT, ArrayedT, MsT > > SampledImageT< FormatT, DimT, ArrayedT, MsT >::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		return writeAssignOperator< SampledImageT >( *this, rhs, sdw::makeAssign );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	ast::type::ImageConfiguration SampledImageT< FormatT, DimT, ArrayedT, MsT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, ast::type::AccessKind::eRead, DimT, ArrayedT, MsT >( true );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline ast::type::TypePtr SampledImageT< FormatT, DimT, ArrayedT, MsT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getSampledImage( makeConfig() );
	}
}
