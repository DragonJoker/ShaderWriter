/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	namespace details
	{
		inline void getFunctionCallParamsRec( ShaderWriter & writer
			, expr::ExprList & args
			, bool & isEnabled )
		{
		}

		template< typename Param >
		inline void getFunctionCallParamsRec( ShaderWriter & writer
			, expr::ExprList & args
			, bool & isEnabled
			, Param const & last )
		{
			isEnabled = isEnabled && isOptionalEnabled( last );
			auto lastArgs = makeFnArg( writer, last );

			for ( auto & expr : lastArgs )
			{
				args.emplace_back( std::move( expr ) );
			}
		}

		template< typename Param, typename ... Params >
		inline void getFunctionCallParamsRec( ShaderWriter & writer
			, expr::ExprList & args
			, bool & isEnabled
			, Param const & current
			, Params const & ... params )
		{
			isEnabled = isEnabled && isOptionalEnabled( current );
			auto currentArgs = makeFnArg( writer, current );

			for ( auto & expr : currentArgs )
			{
				args.emplace_back( std::move( expr ) );
			}

			getFunctionCallParamsRec( writer, args, isEnabled, params... );
		}
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename LhsT
			, typename RhsT
			, typename Enable = void >
		struct AreCompatible
		{
			static constexpr bool value = false;
		};
		template< typename LhsT
			, typename RhsT >
		struct AreCompatible< LhsT
			, RhsT
			, std::enable_if_t< std::is_same_v< CppTypeT< LhsT >, CppTypeT< RhsT > > > >
		{
			static constexpr bool value = true;
		};

		template< typename LhsT, typename RhsT >
		constexpr bool AreCompatibleV = AreCompatible< LhsT, RhsT >::value;

		template< typename OutputT, size_t CountT, typename InputT >
		inline Value ctorCast( InputT input )
		{
			if constexpr ( std::is_same_v< InputT, Value > )
			{
				return sdw::Value::ctorCast< OutputT, CountT >( std::move( input ) );
			}
			else if constexpr ( std::is_same_v< InputT, CppTypeT< InputT > > )
			{
				return OutputT{ CppTypeT< OutputT >( std::move( input ) ) };
			}
			else if constexpr ( AreCompatibleV< OutputT, InputT > )
			{
				return Value{ std::move( input ) };
			}
			else
			{
				return Value{ std::move( input ) };
			}
		}

		template< typename ParamT, size_t CountT >
		inline void getCtorCallParamsRec( ShaderWriter & writer
			, expr::ExprList & args
			, bool & isEnabled )
		{
		}

		template< typename ParamT, size_t CountT, typename Param >
		inline void getCtorCallParamsRec( ShaderWriter & writer
			, expr::ExprList & args
			, bool & isEnabled
			, Param const & last )
		{
			isEnabled = isEnabled && isOptionalEnabled( last );
			auto lastArgs = makeFnArg( writer, details::ctorCast< ParamT, CountT >( last ) );

			for ( auto & expr : lastArgs )
			{
				args.emplace_back( std::move( expr ) );
			}
		}

		template< typename ParamT, size_t CountT, typename Param, typename ... Params >
		inline void getCtorCallParamsRec( ShaderWriter & writer
			, expr::ExprList & args
			, bool & isEnabled
			, Param const & current
			, Params const & ... params )
		{
			isEnabled = isEnabled && isOptionalEnabled( current );
			auto currentArgs = makeFnArg( writer, details::ctorCast< ParamT, CountT >( current ) );

			for ( auto & expr : currentArgs )
			{
				args.emplace_back( std::move( expr ) );
			}

			getCtorCallParamsRec< ParamT, CountT >( writer, args, isEnabled, params... );
		}

		template< typename ReturnT, typename ParamT, size_t CountT >
		struct CtorCallGetter
		{
			template< typename ... ParamsT >
			static inline ReturnT submit( ShaderWriter & writer
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getCtorCallParamsRec< ParamT, CountT >( writer, args, isEnabled, params... );
				return ReturnT{ writer
					, sdw::makeCompositeCtor( getCompositeType( typeEnum< ReturnT > )
						, type::getScalarType( typeEnum< ReturnT > )
						, std::move( args ) )
					, isEnabled };
			}
		};

		template< typename ConstructT >
		struct CtorTraits
		{
			using type = ConstructT;
			static size_t constexpr count = 1u;
		};
		template< typename ComponentT >
		struct CtorTraits< Vec2T< ComponentT > >
		{
			using type = ComponentT;
			static size_t constexpr count = 2u;
		};
		template< typename ComponentT >
		struct CtorTraits< Vec3T< ComponentT > >
		{
			using type = ComponentT;
			static size_t constexpr count = 3u;
		};
		template< typename ComponentT >
		struct CtorTraits< Vec4T< ComponentT > >
		{
			using type = ComponentT;
			static size_t constexpr count = 4u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat2T< ComponentT > >
		{
			using type = Vec2T< ComponentT >;
			static size_t constexpr count = 2u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat2x3T< ComponentT > >
		{
			using type = Vec3T< ComponentT >;
			static size_t constexpr count = 2u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat2x4T< ComponentT > >
		{
			using type = Vec4T< ComponentT >;
			static size_t constexpr count = 2u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat3x2T< ComponentT > >
		{
			using type = Vec2T< ComponentT >;
			static size_t constexpr count = 3u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat3T< ComponentT > >
		{
			using type = Vec3T< ComponentT >;
			static size_t constexpr count = 3u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat3x4T< ComponentT > >
		{
			using type = Vec4T< ComponentT >;
			static size_t constexpr count = 3u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat4x2T< ComponentT > >
		{
			using type = Vec2T< ComponentT >;
			static size_t constexpr count = 4u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat4x3T< ComponentT > >
		{
			using type = Vec3T< ComponentT >;
			static size_t constexpr count = 4u;
		};
		template< typename ComponentT >
		struct CtorTraits< Mat4T< ComponentT > >
		{
			using type = Vec4T< ComponentT >;
			static size_t constexpr count = 4u;
		};
		template< typename ConstructT >
		using ParamsT = typename CtorTraits< ConstructT >::type;
		template< typename ConstructT >
		inline size_t constexpr CountV = CtorTraits< ConstructT >::count;
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT getCtorCall( ShaderWriter & writer
		, ParamsT const & ... params )
	{
		return details::CtorCallGetter< ReturnT, details::ParamsT< ReturnT >, details::CountV< ReturnT > >::submit( writer, params... );
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename ReturnT >
		struct FunctionCallGetter
		{
			template< typename ... ParamsT >
			static inline ReturnT submit( ShaderWriter & writer
				, ast::type::FunctionPtr type
				, std::string const & name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( writer, args, isEnabled, params... );
				auto & cache = getTypesCache( writer );
				return ReturnT{ writer
					, sdw::makeFnCall( ReturnT::makeType( cache )
						, sdw::makeIdent( cache, var::makeFunction( type, name ) )
						, std::move( args ) )
					, isEnabled };
			}
		};
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT getFunctionCall( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string const & name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< ReturnT >::submit( writer
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
	inline stmt::FunctionDeclPtr getFunctionHeader( ShaderWriter & writer
		, ast::var::VariableList & args
		, std::string const & name
		, ParamsT && ... params )
	{
		auto & cache = getTypesCache( writer );
		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
		return stmt::makeFunctionDecl( cache.getFunction( ReturnT::makeType( cache ), args )
			, name );
	}

	template<>
	inline stmt::FunctionDeclPtr getFunctionHeader< void >( ShaderWriter & writer
		, ast::var::VariableList & args
		, std::string const & name )
	{
		auto & cache = getTypesCache( writer );
		return stmt::makeFunctionDecl( cache.getFunction( cache.getVoid(), args )
			, name );
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename ReturnT >
		struct StmtAdder
		{
			static inline void submit( ShaderWriter & writer, ReturnT const & result )
			{
			}
		};

		template<>
		struct StmtAdder< Void >
		{
			static inline void submit( ShaderWriter & writer, Void const & result )
			{
				sdw::addStmt( writer, sdw::makeSimple( sdw::makeExpr( writer, result ) ) );
			}
		};
	}

	//***********************************************************************************************

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... >::Function( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string const & name )
		: m_writer{ &writer }
		, m_shader{ &getShader( *m_writer ) }
		, m_type{ type }
		, m_name{ name }
	{
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnT Function< ReturnT, ParamsT... >::operator()( ParamsT && ... params )const
	{
		assert( !m_name.empty() );
		return getFunctionCall< ReturnT >( *m_writer
			, m_type
			, m_name
			, std::forward< ParamsT >( params )... );
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... >::operator bool()const
	{
		return !m_name.empty();
	}

	//***********************************************************************************************
}
