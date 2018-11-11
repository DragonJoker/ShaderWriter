/*
See LICENSE file in root folder
*/
#include "Writer.hpp"

#include <ASTGenerator/Type/TypeImage.hpp>
#include <ASTGenerator/Type/TypeSampledImage.hpp>

namespace sdw
{
	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... > ShaderWriter::implementFunction( std::string const & name
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		auto decl = getFunctionHeader< ReturnT >( name, params... );
		m_shader.push( decl.get() );

		for ( auto & var : decl->getParameters() )
		{
			m_shader.registerVariable( var );
		}

		function( std::forward< ParamsT && >( params )... );
		m_shader.pop();
		addStmt( std::move( decl ) );
		return Function< ReturnT, ParamsT... >{ &m_shader, name };
	}

	template< typename RetType >
	void ShaderWriter::returnStmt( RetType const & value )
	{
		addStmt( sdw::makeReturn( makeExpr( value ) ) );
	}

	template< typename ExprType >
	ExprType ShaderWriter::ternary( expr::ExprPtr condition
		, expr::ExprPtr left
		, expr::ExprPtr right )
	{
		return ExprType{ &m_shader
			, sdw::makeQuestion( left->getType()
				, std::move( condition )
				, std::move( left )
				, std::move( right ) ) };
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( Value const & from )
	{
		return DestT{ &m_shader
			, sdw::makeCast( makeType( typeEnum< DestT > )
				, makeExpr( from ) ) };
	}

	template< typename ValueT >
	inline ValueT ShaderWriter::paren( ValueT const & content )
	{
		return ValueT{ &m_shader
			, makeExpr( content ) };
	}

#pragma region Constant declaration
	/**
	*name
	*	Constant declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declConstant( std::string const & name
		, T const & rhs )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerConstant( name
			, type );
		addStmt( sdw::makePreprocDefine( name
			, makeExpr( rhs ) ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declConstant( std::string const & name
		, T const & rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerConstant( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makePreprocDefine( name
				, makeExpr( rhs ) ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declConstantArray( std::string const & name
		, std::vector< T > const & rhs )
	{
		auto type = type::makeType( typeEnum< T >
			, uint32_t( rhs.size() ) );
		auto var = registerConstant( name
			, type );
		addStmt( sdw::makePreprocDefine( name
			, sdw::makeAggrInit( var->getType()
				, makeExpr( rhs ) ) ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declConstantArray( std::string const & name
		, std::vector< T > const & rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, uint32_t( rhs.size() ) );
		auto var = registerConstant( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makePreprocDefine( name
				, sdw::makeAggrInit( var->getType()
					, makeExpr( rhs ) ) ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Specialisation constant declaration
	/**
	*name
	*	Specialisation constant declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, T const & rhs )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerSpecConstant( name
			, location
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declSpecConstant( std::string const & name
		, uint32_t location
		, T const & rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerSpecConstant( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Sampled Image declaration
	/**
	*name
	*	Sampled Image declaration.
	*/
	/**@{*/
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT > ShaderWriter::declSampledImage( std::string const & name
		, uint32_t binding
		, uint32_t set
		, ast::type::ImageFormat format )
	{
		using T = SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig( format ) );
		auto var = registerSampledImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeSampledImgDecl( var
			, binding
			, set ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declSampledImage( std::string const & name
		, uint32_t binding
		, uint32_t set
		, bool enabled
		, ast::type::ImageFormat format )
	{
		using T = SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig( format ) );
		auto var = registerSampledImage( name
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( sdw::makeSampledImgDecl( var
				, binding
				, set ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Array< SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declSampledImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, ast::type::ImageFormat format )
	{
		using T = SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig( format )
			, dimension );
		auto var = registerSampledImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeSampledImgDecl( var
			, binding
			, set ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< Array< SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT > > > ShaderWriter::declSampledImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled
		, ast::type::ImageFormat format )
	{
		using T = SampledImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig( format )
			, dimension );
		auto var = registerSampledImage( name
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( sdw::makeSampledImgDecl( var
				, binding
				, set ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Image declaration
	/**
	*name
	*	Image declaration.
	*/
	/**@{*/
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ImageT< SampledT, DimT, ArrayedT, DepthT, MsT > ShaderWriter::declImage( std::string const & name
		, uint32_t binding
		, uint32_t set
		, ast::type::ImageFormat format )
	{
		using T = ImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig( format ) );
		auto var = registerImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeImageDecl( var
			, binding
			, set ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< ImageT< SampledT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declImage( std::string const & name
		, uint32_t binding
		, uint32_t set
		, bool enabled
		, ast::type::ImageFormat format )
	{
		using T = ImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig( format ) );
		auto var = registerImage( name
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( sdw::makeImageDecl( var
				, binding
				, set ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Array< ImageT< SampledT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, ast::type::ImageFormat format )
	{
		using T = ImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig( format )
			, dimension );
		auto var = registerImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeImageDecl( var
			, binding
			, set ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< Array< ImageT< SampledT, DimT, ArrayedT, DepthT, MsT > > > ShaderWriter::declImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled
		, ast::type::ImageFormat format )
	{
		using T = ImageT< SampledT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig( format )
			, dimension );
		auto var = registerImage( name
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( sdw::makeImageDecl( var
				, binding
				, set ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Input declaration
	/**
	*name
	*	Input declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declInput( std::string const & name
		, uint32_t location )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerInput( name
			, location
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declInput( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerInput( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerInput( name
			, location
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location )
	{
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = registerInput( name
			, location
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerInput( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = registerInput( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Output declaration
	/**
	*name
	*	Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declOutput( std::string const & name
		, uint32_t location )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerOutput( name
			, location
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declOutput( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerOutput( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerOutput( name
			, location
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location )
	{
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = registerOutput( name
			, location
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerOutput( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = registerOutput( name
			, location
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Locale declaration
	/**
	*name
	*	Locale declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeVariableDecl( var ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, T const & rhs )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeSimple( sdw::makeInit( var
			, makeExpr( rhs ) ) ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declLocale( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declLocale( std::string const & name
		, Optional< T > const & rhs )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerLocale( name
			, type );

		if ( rhs.isEnabled() )
		{
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeExpr( rhs ) ) ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, rhs.isEnabled() };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declLocale( std::string const & name
		, T const & rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeExpr( rhs ) ) ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, std::vector< T > const & rhs )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeSimple( sdw::makeAggrInit( var
			, makeExpr( rhs ) ) ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, std::vector< T > const & rhs
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( sdw::makeAggrInit( var
				, makeExpr( rhs ) ) ) );
		}

		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Built-in declaration
	/**
	*name
	*	Built-in variable declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declBuiltin( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerBuiltin( name
			, type );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declBuiltin( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T > );
		auto var = registerBuiltin( name
			, type );
		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declBuiltinArray( std::string const & name
		, uint32_t dimension )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerBuiltin( name
			, type );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declBuiltinArray( std::string const & name )
	{
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = registerBuiltin( name
			, type );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declBuiltinArray( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = registerBuiltin( name
			, type );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declBuiltinArray( std::string const & name
		, bool enabled )
	{
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = registerBuiltin( name
			, type );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Already declared variable getters
	/**
	*name
	*	Already declared variable getters.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::getVariable( std::string const & name )
	{
		auto var = getVar( name );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::getVariable( std::string const & name
		, bool enabled )
	{
		auto var = getVar( name );
		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::getVariableArray( std::string const & name )
	{
		auto var = getVar( name );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::getVariableArray( std::string const & name
		, bool enabled )
	{
		auto var = getVar( name );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
}
