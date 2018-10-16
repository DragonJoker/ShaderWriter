/*
See LICENSE file in root folder
*/
#include "Shader.hpp"

#include <ASTGenerator/Expr/ExprAggrInit.hpp>
#include <ASTGenerator/Expr/ExprCast.hpp>
#include <ASTGenerator/Expr/ExprInit.hpp>
#include <ASTGenerator/Expr/ExprQuestion.hpp>
#include <ASTGenerator/Stmt/PreprocDefine.hpp>
#include <ASTGenerator/Stmt/StmtInOutVariableDecl.hpp>
#include <ASTGenerator/Stmt/StmtReturn.hpp>
#include <ASTGenerator/Stmt/StmtSamplerDecl.hpp>
#include <ASTGenerator/Stmt/StmtVariableDecl.hpp>

namespace sdw
{
	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... > Shader::implementFunction( std::string const & name
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		auto decl = getFunctionHeader< ReturnT >( name, params... );
		m_blocks.push( { {}, decl.get() } );
		function( std::forward< ParamsT && >( params )... );
		m_blocks.pop();
		m_container.addStmt( std::move( decl ) );
		return Function< ReturnT, ParamsT... >{ this, name };
	}

	template< typename RetType >
	void Shader::returnStmt( RetType const & value )
	{
		getContainer()->addStmt( stmt::makeReturn( makeExpr( value ) ) );
	}

	template< typename ExprType >
	ExprType Shader::ternary( expr::ExprPtr condition
		, expr::ExprPtr left
		, expr::ExprPtr right )
	{
		return ExprType{ this
			, expr::makeQuestion( left->getType()
				, std::move( condition )
				, std::move( left )
				, std::move( right ) ) };
	}

	template< typename DestT >
	inline DestT Shader::cast( Value const & from )
	{
		return DestT{ this
			, expr::makeCast( makeType( typeEnum< DestT > )
				, makeExpr( from ) ) };
	}

	template< typename ValueT >
	inline ValueT Shader::paren( ValueT const & content )
	{
		return ValueT{ this
			, makeExpr( content ) };
	}

#pragma region Constant declaration
	/**
	*name
	*	Constant declaration.
	*/
	/**@{*/
	template< typename T >
	inline T Shader::declConstant( std::string const & name
		, T const & rhs )
	{
		registerConstant( name
			, typeEnum< T > );
		addStmt( stmt::makePreprocDefine( name
			, makeExpr( rhs ) ) );
		auto type = type::makeType( typeEnum< T > );
		return T{ this
			, makeExpr( var::makeVariable( type, name ) ) };
	}

	template< typename T >
	inline Optional< T > Shader::declConstant( std::string const & name
		, T const & rhs
		, bool enabled )
	{
		registerConstant( name
			, typeEnum< T > );

		if ( enabled )
		{
			addStmt( stmt::makePreprocDefine( name
				, makeExpr( rhs ) ) );
		}

		auto type = type::makeType( typeEnum< T > );
		return Optional< T >{ this
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
	inline T Shader::declSpecConstant( std::string const & name
		, uint32_t location
		, T const & rhs )
	{
		registerConstant( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderConstant );
		addStmt( stmt::makeInOutVariableDecl( var
			, location ) );
		return T{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Shader::declSpecConstant( std::string const & name
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
			addStmt( stmt::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ this
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
	inline typename SamplerTypeTraits< SamplerT >::Type Shader::declSampler( std::string const & name
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
		addStmt( stmt::makeSamplerDecl( var
			, binding
			, set ) );
		return T{ this
			, makeExpr( var ) };
	}

	template< SamplerType SamplerT >
	inline Optional< typename SamplerTypeTraits< SamplerT >::Type > Shader::declSampler( std::string const & name
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
			addStmt( stmt::makeSamplerDecl( var
				, binding
				, set ) );
		}

		return Optional< T >{ this
			, makeExpr( var )
			, enabled };
	}

	template< SamplerType SamplerT >
	inline Array< typename SamplerTypeTraits< SamplerT >::Type > Shader::declSamplerArray( std::string const & name
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
		addStmt( stmt::makeSamplerDecl( var
			, binding
			, set ) );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< SamplerType SamplerT >
	inline Optional< Array< typename SamplerTypeTraits< SamplerT >::Type > > Shader::declSamplerArray( std::string const & name
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
			addStmt( stmt::makeSamplerDecl( var
				, binding
				, set ) );
		}

		return Optional< Array< T > >{ this
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
	inline T Shader::declInput( std::string const & name
		, uint32_t location )
	{
		registerInput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderInput );
		addStmt( stmt::makeInOutVariableDecl( var
			, location ) );
		return T{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Shader::declInput( std::string const & name
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
			addStmt( stmt::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > Shader::declInputArray( std::string const & name
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
		addStmt( stmt::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Shader::declInputArray( std::string const & name
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
		addStmt( stmt::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declInputArray( std::string const & name
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
			addStmt( stmt::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declInputArray( std::string const & name
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
			addStmt( stmt::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ this
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
	inline T Shader::declOutput( std::string const & name
		, uint32_t location )
	{
		registerOutput( name
			, location
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eShaderOutput );
		addStmt( stmt::makeInOutVariableDecl( var
			, location ) );
		return T{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Shader::declOutput( std::string const & name
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
			addStmt( stmt::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > Shader::declOutputArray( std::string const & name
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
		addStmt( stmt::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Shader::declOutputArray( std::string const & name
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
		addStmt( stmt::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declOutputArray( std::string const & name
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
			addStmt( stmt::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declOutputArray( std::string const & name
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
			addStmt( stmt::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ this
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
	inline T Shader::declLocale( std::string const & name )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );
		addStmt( stmt::makeVariableDecl( var ) );
		return T{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline T Shader::declLocale( std::string const & name
		, T const & rhs )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );
		addStmt( stmt::makeSimple( expr::makeInit( expr::makeIdentifier( var )
			, makeExpr( rhs ) ) ) );
		return T{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Shader::declLocale( std::string const & name
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
			addStmt( stmt::makeVariableDecl( var ) );
		}

		return Optional< T >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< T > Shader::declLocale( std::string const & name
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
			addStmt( stmt::makeSimple( expr::makeInit( expr::makeIdentifier( var )
				, makeExpr( rhs ) ) ) );
		}

		return Optional< T >{ this
			, makeExpr( var )
			, rhs.isEnabled() };
	}

	template< typename T >
	inline Optional< T > Shader::declLocale( std::string const & name
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
			addStmt( stmt::makeSimple( expr::makeInit( expr::makeIdentifier( var )
				, makeExpr( rhs ) ) ) );
		}

		return Optional< T >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > Shader::declLocaleArray( std::string const & name
		, uint32_t dimension )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eLocale );
		addStmt( stmt::makeVariableDecl( var ) );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Shader::declLocaleArray( std::string const & name
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
		addStmt( stmt::makeSimple( expr::makeAggrInit( expr::makeIdentifier( var )
			, makeExpr( rhs ) ) ) );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declLocaleArray( std::string const & name
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
			addStmt( stmt::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declLocaleArray( std::string const & name
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
			addStmt( stmt::makeSimple( expr::makeAggrInit( expr::makeIdentifier( var )
				, makeExpr( rhs ) ) ) );
		}

		return Optional< Array< T > >{ this
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
	inline T Shader::declBuiltin( std::string const & name )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return T{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Shader::declBuiltin( std::string const & name
		, bool enabled )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< T >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > Shader::declBuiltinArray( std::string const & name
		, uint32_t dimension )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Array< T > Shader::declBuiltinArray( std::string const & name )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declBuiltinArray( std::string const & name
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
		return Optional< Array< T > >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::declBuiltinArray( std::string const & name
		, bool enabled )
	{
		registerName( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< Array< T > >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline T Shader::getBuiltin( std::string const & name )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return T{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< T > Shader::getBuiltin( std::string const & name
		, bool enabled )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T > );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< T >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > Shader::getBuiltinArray( std::string const & name )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::getBuiltinArray( std::string const & name
		, bool enabled )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, type::UnknownArraySize );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Optional< Array< T > >{ this
			, makeExpr( var )
			, enabled };
	}

	template< typename T >
	inline Array< T > Shader::getBuiltinArray( std::string const & name
		, uint32_t dimension )
	{
		checkNameExists( name
			, typeEnum< T > );
		auto type = type::makeType( typeEnum< T >
			, dimension );
		auto var = var::makeVariable( type
			, name
			, var::Flag::eBuiltin );
		return Array< T >{ this
			, makeExpr( var ) };
	}

	template< typename T >
	inline Optional< Array< T > > Shader::getBuiltinArray( std::string const & name
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
		return Optional< Array< T > >{ this
			, makeExpr( var )
			, enabled };
	}
	/**@}*/
#pragma endregion
}
