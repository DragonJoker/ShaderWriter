/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	template< typename Param
		, typename ... Params >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled
		, Param const & current
		, Params const & ... params );

	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled )
	{
	}

	template< typename Param >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled
		, Param const & last )
	{
		isEnabled = isEnabled && isOptionalEnabled( last );
		auto lastArgs = makeFnArg( last );

		for ( auto & expr : lastArgs )
		{
			args.emplace_back( std::move( expr ) );
		}
	}

	template< typename Param
		, typename ... Params >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled
		, Param const & current
		, Params const & ... params )
	{
		isEnabled = isEnabled && isOptionalEnabled( current );
		auto currentArgs = makeFnArg( current );

		for ( auto & expr : currentArgs )
		{
			args.emplace_back( std::move( expr ) );
		}

		getFunctionCallParamsRec( args, isEnabled, params... );
	}

	namespace details
	{
		template< typename ReturnT >
		struct CtorCallGetter
		{
			template< typename ... ParamsT >
			static ReturnT submit( ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( args, isEnabled, params... );
				return ReturnT{ findShader( params... )
					, sdw::makeCompositeCtor( getCompositeType( typeEnum< ReturnT > )
						, type::getScalarType( typeEnum< ReturnT > )
						, std::move( args ) ) };
			}
		};

		template< typename ReturnT >
		struct CtorCallGetter< Optional< ReturnT > >
		{
			template< typename ... ParamsT >
			static Optional< ReturnT > submit( ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( args, isEnabled, params... );
				return Optional< ReturnT >{ findShader( params... )
					, sdw::makeCompositeCtor( getCompositeType( typeEnum< ReturnT > )
						, type::getScalarType( typeEnum< ReturnT > )
						, std::move( args ) )
					, isEnabled };
			}
		};

		template< typename ReturnT >
		struct FunctionCallGetter
		{
			template< typename ... ParamsT >
			static ReturnT submit( std::string const & name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( args, isEnabled, params... );
				return ReturnT{ findShader( params... )
					, sdw::makeFnCall( ReturnT::makeType()
						, sdw::makeIdent( var::makeFunction( name ) )
						, std::move( args ) ) };
			}
		};

		template< typename ReturnT >
		struct FunctionCallGetter< Optional< ReturnT > >
		{
			template< typename ... ParamsT >
			static Optional< ReturnT > submit( std::string const & name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( args, isEnabled, params... );
				return Optional< ReturnT >{ findShader( params... )
					, sdw::makeFnCall( ReturnT::makeType()
						, sdw::makeIdent( var::makeFunction( name ) )
						, std::move( args ) )
					, isEnabled };
			}
		};
	}

	template< typename ReturnT
		, typename ... ParamsT >
	inline ReturnT getCtorCall( ParamsT const & ... params )
	{
		return details::CtorCallGetter< ReturnT >::submit( params... );
	}

	template< typename ReturnT
		, typename ... ParamsT >
	inline Optional< ReturnT > getOptCtorCall( ParamsT const & ... params )
	{
		return details::CtorCallGetter< Optional< ReturnT > >::submit( params... );
	}

	template< typename ReturnT
		, typename ... ParamsT >
	inline ReturnT getFunctionCall( std::string const & name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< ReturnT >::submit( name, params... );
	}

	template< typename ReturnT
		, typename ... ParamsT >
	inline Optional< ReturnT > getOptFunctionCall( std::string const & name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< Optional< ReturnT > >::submit( name, params... );
	}

	//***********************************************************************************************

	template< typename ParamT
		, typename ... ParamsT >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, ParamT && current
		, ParamsT && ... params );

	inline void getFunctionHeaderArgsRec( var::VariableList & args )
	{
	}

	template< typename ParamT >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, ParamT && last )
	{
		auto idents = listIdentifiers( last.getExpr() );
		assert( !idents.empty() );

		for ( auto & ident : idents )
		{
			args.emplace_back( ident->getVariable() );
		}
	}

	template< typename ParamT
		, typename ... ParamsT >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, ParamT && current
		, ParamsT && ... params )
	{
		auto idents = listIdentifiers( current.getExpr() );
		assert( !idents.empty() );

		for ( auto & ident : idents )
		{
			args.emplace_back( ident->getVariable() );
		}

		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
	}

	template< typename ReturnT
		, typename ... ParamsT >
	inline stmt::FunctionDeclPtr getFunctionHeader( std::string const & name
		, ParamsT && ... params )
	{
		var::VariableList args;
		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
		return stmt::makeFunctionDecl( ReturnT::makeType()
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

	namespace details
	{
		template< typename ReturnT >
		struct StmtAdder
		{
			static void submit( Shader & shader, ReturnT const & result )
			{
			}
		};

		template<>
		struct StmtAdder< Void >
		{
			static void submit( Shader & shader, Void const & result )
			{
				sdw::addStmt( shader, sdw::makeSimple( sdw::makeExpr( result ) ) );
			}
		};
	}

	//***********************************************************************************************

	template< typename ReturnT
		, typename ... ParamsT >
	Function< ReturnT, ParamsT... >::Function( Shader * shader
		, std::string const & name )
		: m_shader{ shader }
		, m_name{ name }
	{
	}

	template< typename ReturnT
		, typename ... ParamsT >
	ReturnT Function< ReturnT, ParamsT... >::operator()( ParamsT && ... params )const
	{
		assert( !m_name.empty() );
		auto result = getFunctionCall< ReturnT >( m_name
			, std::forward< ParamsT >( params )... );
		details::StmtAdder< ReturnT >::submit( *m_shader, result );
		return result;
	}

	//***********************************************************************************************
}
