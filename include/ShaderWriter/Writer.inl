/*
See LICENSE file in root folder
*/
#include "Writer.hpp"

namespace sdw
{
	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... > ShaderWriter::implementFunction( std::string const & name
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		auto decl = getFunctionHeader< ReturnT >( name, params... );
		m_shader.push( decl.get() );
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
		registerConstant( name
			, typeEnum< T > );
		addStmt( sdw::makePreprocDefine( name
			, makeExpr( rhs ) ) );
		auto type = type::makeType( typeEnum< T > );
		return T{ &m_shader
			, makeExpr( var::makeVariable( type, name ) ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declConstant( std::string const & name
		, T const & rhs
		, bool enabled )
	{
		registerConstant( name
			, typeEnum< T > );

		if ( enabled )
		{
			addStmt( sdw::makePreprocDefine( name
				, makeExpr( rhs ) ) );
		}

		auto type = type::makeType( typeEnum< T > );
		return Optional< T >{ &m_shader
			, makeExpr( var::makeVariable( type, name ) )
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
		registerConstant( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderConstant );
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
		registerConstant( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderConstant );

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
#pragma region Sampler declaration
	/**
	*name
	*	Sampler declaration.
	*/
	/**@{*/
	template< SamplerType SamplerT >
	inline typename SamplerTypeTraits< SamplerT >::Type ShaderWriter::declSampler( std::string const & name
		, uint32_t binding
		, uint32_t set )
	{
		using T = typename SamplerTypeTraits< SamplerT >::Type;
		registerSampler( name
			, typeEnum< T >
			, binding
			, set
			, type::NotArray );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eSampler );
		addStmt( sdw::makeSamplerDecl( var
			, binding
			, set ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< SamplerType SamplerT >
	inline Optional< typename SamplerTypeTraits< SamplerT >::Type > ShaderWriter::declSampler( std::string const & name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		using T = typename SamplerTypeTraits< SamplerT >::Type;
		registerSampler( name
			, typeEnum< T >
			, binding
			, set
			, type::NotArray
			, enabled );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eSampler );

		if ( enabled )
		{
			addStmt( sdw::makeSamplerDecl( var
				, binding
				, set ) );
		}

		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< SamplerType SamplerT >
	inline Array< typename SamplerTypeTraits< SamplerT >::Type > ShaderWriter::declSamplerArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension )
	{
		using T = typename SamplerTypeTraits< SamplerT >::Type;
		registerSampler( name
			, typeEnum< T >
			, binding
			, set
			, dimension );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eSampler );
		addStmt( sdw::makeSamplerDecl( var
			, binding
			, set ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< SamplerType SamplerT >
	inline Optional< Array< typename SamplerTypeTraits< SamplerT >::Type > > ShaderWriter::declSamplerArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		using T = typename SamplerTypeTraits< SamplerT >::Type;
		registerSampler( name
			, typeEnum< T >
			, binding
			, set
			, dimension
			, enabled );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eSampler );

		if ( enabled )
		{
			addStmt( sdw::makeSamplerDecl( var
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
		registerInput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderInput );
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
		registerInput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderInput );

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
		registerInput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderInput );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location )
	{
		registerInput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderInput );
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
		registerInput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderInput );

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
		registerInput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderInput );

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
		registerOutput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderOutput );
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
		registerOutput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderOutput );

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
		registerOutput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderOutput );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location )
	{
		registerOutput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderOutput );
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
		registerOutput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderOutput );

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
		registerOutput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderOutput );

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
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );
		addStmt( sdw::makeVariableDecl( var ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, T const & rhs )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );
		addStmt( sdw::makeSimple( sdw::makeInit( var
			, makeExpr( rhs ) ) ) );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declLocale( std::string const & name
		, bool enabled )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );

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
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );

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
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );

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
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );
		addStmt( sdw::makeVariableDecl( var ) );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, std::vector< T > const & rhs )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );
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
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );

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
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );

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
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declBuiltin( std::string const & name
		, bool enabled )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declBuiltinArray( std::string const & name
		, uint32_t dimension )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declBuiltinArray( std::string const & name )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declBuiltinArray( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declBuiltinArray( std::string const & name
		, bool enabled )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::getBuiltin( std::string const & name )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return T{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::getBuiltin( std::string const & name
		, bool enabled )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< T >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::getBuiltinArray( std::string const & name )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::getBuiltinArray( std::string const & name
		, bool enabled )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::getBuiltinArray( std::string const & name
		, uint32_t dimension )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ &m_shader
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::getBuiltinArray( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< Array< T > >{ &m_shader
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
}
