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
		struct CtorTraits< Mat2x2T< ComponentT > >
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
		struct CtorTraits< Mat3x3T< ComponentT > >
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
		struct CtorTraits< Mat4x4T< ComponentT > >
		{
			using type = Vec4T< ComponentT >;
			static size_t constexpr count = 4u;
		};
		template< typename ConstructT >
		using CtorComponentTypeT = typename CtorTraits< ConstructT >::type;
		template< typename ConstructT >
		inline size_t constexpr ctorComponentCountV = CtorTraits< ConstructT >::count;

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
			, Param last )
		{
			isEnabled = isEnabled && isOptionalEnabled( last );
			auto lastArgs = makeFnArg( writer, details::ctorCast< ParamT, CountT >( std::move( last ) ) );

			for ( auto & expr : lastArgs )
			{
				args.emplace_back( std::move( expr ) );
			}
		}

		template< typename ParamT, size_t CountT, typename Param, typename ... Params >
		inline void getCtorCallParamsRec( ShaderWriter & writer
			, expr::ExprList & args
			, bool & isEnabled
			, Param current
			, Params ... params )
		{
			isEnabled = isEnabled && isOptionalEnabled( current );
			auto currentArgs = makeFnArg( writer, details::ctorCast< ParamT, CountT >( std::move( current ) ) );

			for ( auto & expr : currentArgs )
			{
				args.emplace_back( std::move( expr ) );
			}

			getCtorCallParamsRec< ParamT, CountT >( writer
				, args
				, isEnabled
				, std::forward< Params >( params )... );
		}

		template< typename ReturnT >
		struct CtorCallGetter
		{
			using ComponentTypeT = details::CtorComponentTypeT< ReturnT >;
			static constexpr size_t count = details::ctorComponentCountV< ReturnT >;

			template< typename ... ParamsT >
			static inline ReturnWrapperT< ReturnT > submit( ShaderWriter & writer
				, ParamsT && ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getCtorCallParamsRec< ComponentTypeT, count >( writer
					, args
					, isEnabled
					, std::forward< ParamsT >( params )... );
				return ReturnWrapperT< ReturnT >{ writer
					, sdw::makeCompositeCtor( getCompositeType( typeEnumV< ReturnT > )
						, typeEnumV< ComponentTypeT >
						, std::move( args ) )
					, isEnabled };
			}
		};
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnWrapperT< ReturnT > getCtorCall( ShaderWriter & writer
		, ParamsT && ... params )
	{
		return details::CtorCallGetter< ReturnT >::submit( writer
			, std::forward< ParamsT >( params )... );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > getCombineCall( ShaderWriter & writer
		, SampledImageT< FormatT, DimT, ArrayedT, MsT > const & image
		, SamplerT< DepthT > const & sampler )
	{
		return CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT >{ writer
			, sdw::makeCompositeCtor( std::move( makeFnArg( writer, image ).front() )
				, std::move( makeFnArg( writer, sampler ).front() ) )
			, sdw::areOptionalEnabled( image, sampler ) };
	}

	//***********************************************************************************************

	namespace details
	{
		template< typename ReturnT >
		struct FunctionCallGetter
		{
			template< typename ... ParamsT >
			static inline ReturnWrapperT< ReturnT > submit( ShaderWriter & writer
				, ast::type::FunctionPtr type
				, std::string name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( writer, args, isEnabled, params... );
				auto & cache = getTypesCache( writer );
				return ReturnWrapperT< ReturnT >{ writer
					, sdw::makeFnCall( ReturnT::makeType( cache )
						, sdw::makeIdent( cache, var::makeFunction( getNextVarId( writer ), type, std::move( name ) ) )
						, std::move( args ) )
					, isEnabled };
			}
		};
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnWrapperT< ReturnT > getFunctionCall( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< ReturnT >::submit( writer
			, type
			, std::move( name )
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
		, std::string name
		, stmt::FunctionFlag flag
		, ParamsT && ... params )
	{
		auto & cache = getTypesCache( writer );
		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
		return stmt::makeFunctionDecl( cache.getFunction( ReturnT::makeType( cache ), args )
			, std::move( name )
			, flag );
	}

	template<>
	inline stmt::FunctionDeclPtr getFunctionHeader< void >( ShaderWriter & writer
		, ast::var::VariableList & args
		, std::string name
		, stmt::FunctionFlag flag )
	{
		auto & cache = getTypesCache( writer );
		return stmt::makeFunctionDecl( cache.getFunction( cache.getVoid(), args )
			, std::move( name )
			, flag );
	}

	//***********************************************************************************************

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... >::Function( ShaderWriter & writer
		, ast::type::FunctionPtr type
		, std::string name )
		: m_writer{ &writer }
		, m_shader{ &getShader( *m_writer ) }
		, m_type{ type }
		, m_name{ std::move( name ) }
	{
	}

	template< typename ReturnT, typename ... ParamsT >
	inline ReturnWrapperT< ReturnT > Function< ReturnT, ParamsT... >::operator()( ParamsT && ... params )const
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
