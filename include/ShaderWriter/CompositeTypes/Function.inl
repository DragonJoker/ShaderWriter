/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
		inline void getFunctionCallParamsRec( Shader & shader
			, expr::ExprList & args
			, bool isEnabled )
		{
		}

		template< typename Param >
		inline void getFunctionCallParamsRec( Shader & shader
			, expr::ExprList & args
			, bool isEnabled
			, Param const & last )
		{
			isEnabled = isEnabled && isOptionalEnabled( last );
			auto lastArgs = makeFnArg( shader, last );

			for ( auto & expr : lastArgs )
			{
				args.emplace_back( std::move( expr ) );
			}
		}

		template< typename Param, typename ... Params >
		inline void getFunctionCallParamsRec( Shader & shader
			, expr::ExprList & args
			, bool isEnabled
			, Param const & current
			, Params const & ... params )
		{
			isEnabled = isEnabled && isOptionalEnabled( current );
			auto currentArgs = makeFnArg( shader, current );

			for ( auto & expr : currentArgs )
			{
				args.emplace_back( std::move( expr ) );
			}

			getFunctionCallParamsRec( shader, args, isEnabled, params... );
		}
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename ReturnT >
		struct CtorCallGetter
		{
			template< typename ... ParamsT >
			static inline ReturnT submit( Shader & shader
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( shader, args, isEnabled, params... );
				return ReturnT{ &shader
					, sdw::makeCompositeCtor( getCompositeType( typeEnum< ReturnT > )
						, type::getScalarType( typeEnum< ReturnT > )
						, std::move( args ) ) };
			}
		};

		template< typename ReturnT >
		struct CtorCallGetter< Optional< ReturnT > >
		{
			template< typename ... ParamsT >
			static inline Optional< ReturnT > submit( Shader & shader
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( shader, args, isEnabled, params... );
				return Optional< ReturnT >{ &shader
					, sdw::makeCompositeCtor( getCompositeType( typeEnum< ReturnT > )
						, type::getScalarType( typeEnum< ReturnT > )
						, std::move( args ) )
					, isEnabled };
			}
		};
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT getCtorCall( Shader & shader
		, ParamsT const & ... params )
	{
		return details::CtorCallGetter< ReturnT >::submit( shader, params... );
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Optional< ReturnT > getOptCtorCall( Shader & shader
		, ParamsT const & ... params )
	{
		return details::CtorCallGetter< Optional< ReturnT > >::submit( shader, params... );
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename ReturnT >
		struct FunctionCallGetter
		{
			template< typename ... ParamsT >
			static inline ReturnT submit( Shader & shader
				, ast::type::FunctionPtr type
				, std::string const & name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( shader, args, isEnabled, params... );
				auto & cache = getTypesCache( shader );
				return ReturnT{ &shader
					, sdw::makeFnCall( ReturnT::makeType( cache )
						, sdw::makeIdent( cache, var::makeFunction( type, name ) )
						, std::move( args ) ) };
			}
		};

		template< typename ReturnT >
		struct FunctionCallGetter< Optional< ReturnT > >
		{
			template< typename ... ParamsT >
			static inline Optional< ReturnT > submit( Shader & shader
				, ast::type::FunctionPtr type
				, std::string const & name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( shader, args, isEnabled, params... );
				auto & cache = getTypesCache( shader );
				return Optional< ReturnT >{ &shader
					, sdw::makeFnCall( ReturnT::makeType( cache )
						, sdw::makeIdent( cache, var::makeFunction( type, name ) )
						, std::move( args ) )
					, isEnabled };
			}
		};
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT getFunctionCall( Shader & shader
		, ast::type::FunctionPtr type
		, std::string const & name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< ReturnT >::submit( shader
			, type
			, name
			, params... );
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Optional< ReturnT > getOptFunctionCall( Shader & shader
		, ast::type::FunctionPtr type
		, std::string const & name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< Optional< ReturnT > >::submit( shader
			, type
			, name
			, params... );
	}

	//***********************************************************************************************

	template< typename ParamT, typename ... ParamsT >
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
		auto idents = listCommaIdentifiers( last.getExpr() );
		assert( !idents.empty() );

		for ( auto & ident : idents )
		{
			args.emplace_back( ident->getVariable() );
		}
	}

	template< typename ParamT, typename ... ParamsT >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, ParamT && current
		, ParamsT && ... params )
	{
		auto idents = listCommaIdentifiers( current.getExpr() );
		assert( !idents.empty() );

		for ( auto & ident : idents )
		{
			args.emplace_back( ident->getVariable() );
		}

		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
	}

	template< typename ReturnT, typename ... ParamsT >
	inline stmt::FunctionDeclPtr getFunctionHeader( Shader & shader
		, ast::var::VariableList & args
		, std::string const & name
		, ParamsT && ... params )
	{
		auto & cache = getTypesCache( shader );
		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
		return stmt::makeFunctionDecl( cache.getFunction( ReturnT::makeType( cache ), args )
			, name );
	}

	template<>
	inline stmt::FunctionDeclPtr getFunctionHeader< void >( Shader & shader
		, ast::var::VariableList & args
		, std::string const & name )
	{
		auto & cache = getTypesCache( shader );
		return stmt::makeFunctionDecl( cache.getFunction( cache.getVoid(), args )
			, name );
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename ReturnT >
		struct StmtAdder
		{
			static inline void submit( Shader & shader, ReturnT const & result )
			{
			}
		};

		template<>
		struct StmtAdder< Void >
		{
			static inline void submit( Shader & shader, Void const & result )
			{
				sdw::addStmt( shader, sdw::makeSimple( sdw::makeExpr( shader, result ) ) );
			}
		};
	}

	//***********************************************************************************************

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... >::Function( Shader * shader
		, ast::type::FunctionPtr type
		, std::string const & name )
		: m_shader{ shader }
		, m_type{ type }
		, m_name{ name }
	{
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT Function< ReturnT, ParamsT... >::operator()( ParamsT && ... params )const
	{
		assert( !m_name.empty() );
		auto result = getFunctionCall< ReturnT >( *m_shader
			, m_type
			, m_name
			, std::forward< ParamsT >( params )... );
		details::StmtAdder< ReturnT >::submit( *m_shader, result );
		return result;
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... >::operator bool()const
	{
		return !m_name.empty();
	}

	//***********************************************************************************************
}
