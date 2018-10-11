/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprFnCall.hpp>
#include <ASTGenerator/Expr/ExprList.hpp>

namespace sdw
{
	//***********************************************************************************************

	template< typename Param
		, typename ... Params >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, Param const & current
		, Params const & ... params );

	inline void getFunctionCallParamsRec( expr::ExprList & args )
	{
	}

	template< typename Param >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, Param const & last )
	{
		args.emplace_back( make( last ) );
	}

	template< typename Param
		, typename ... Params >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, Param const & current
		, Params const & ... params )
	{
		args.emplace_back( make( last ) );
		getFunctionCallParamsRec( args, params... );
	}

	template< typename Return
		, typename ... Params >
	inline expr::ExprPtr getFunctionCall( std::string const & name
		, Params const & ... params )
	{
		expr::ExprList args;
		getFunctionCallParamsRec( args, params... );
		return expr::makeFnCall( makeType( TypeTraits< Return >::TypeEnum )
			, expr::makeIdentifier( var::makeVariable( getFunction(), name ) )
			, args );
	}

	template< typename Return
		, typename OptType
		, typename ... Params >
	inline expr::ExprPtr getFunctionCall( std::string const & name
		, Optional< OptType > const & param
		, Params const & ... params )
	{
		if ( param.isEnabled() )
		{
			return getFunctionCall< Return >( name
				, static_cast< OptType const & >( param )
				, params... );
		}

		return nullptr;
	}

	//***********************************************************************************************

	template< typename Param
		, typename ... Params >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, Param && current
		, Params && ... params );

	inline void getFunctionHeaderArgsRec( var::VariableList & args )
	{
	}

	template< typename Param >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, Param && last )
	{
		args.emplace_back( makeVarDecl( last ) );
	}

	template< typename Param
		, typename ... Params >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, Param && current
		, Params && ... params )
	{
		args.emplace_back( makeVarDecl( current ) );
		getFunctionHeaderArgsRec( args, std::forward< Params >( params )... );
	}

	template< typename Return
		, typename ... Params >
	inline void getFunctionHeader( std::string const & name
		, Params && ... params )
	{
		var::VariableList args;
		getFunctionHeaderArgsRec( args, std::forward< Params >( params )... );
		return makeFunctionDecl( makeType( TypeTraits< Return >::TypeEnum )
			, name
			, args );
	}

	template<>
	inline stmt::FunctionDeclPtr getFunctionHeader< void >( std::string const & name )
	{
		var::VariableList args;
		return stmt::makeFunctionDecl( type::getVoid()
			, name
			, args );
	}

	//***********************************************************************************************

	template< typename RetT, typename ... ParamsT >
	Function< RetT, ParamsT... >::Function( stmt::Container * container
		, std::string const & name )
		: m_container{ writer }
		, m_name{ name }
	{
	}

	template< typename RetT, typename ... ParamsT >
	expr::ExprPtr Function< RetT, ParamsT... >::operator()( ParamsT && ... params )const
	{
		assert( !m_name.empty() );
		return getFunctionCall< RetT >( m_name, std::forward< ParamsT >( params )... );
	}

	//***********************************************************************************************
}
