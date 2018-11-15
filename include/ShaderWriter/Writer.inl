/*
See LICENSE file in root folder
*/
#include "Writer.hpp"

#include <ASTGenerator/Type/TypeImage.hpp>
#include <ASTGenerator/Type/TypeSampledImage.hpp>

namespace sdw
{
	namespace details
	{
#pragma region Cast
		/**
		*name
		*	Cast.
		*/
		/**@{*/
		template< typename DstT
			, typename SrcT
			, typename Enable = void >
			struct Cast;

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< std::is_same_v< DstT, SrcT > > >
		{
			static inline DstT cast( Shader & shader
				, DstT const & from )
			{
				return from;
			}
		};

		template< typename DstT, typename SrcT >
			struct Cast< DstT, SrcT
				, std::enable_if_t< !std::is_same_v< DstT, SrcT > && !isOptional< DstT > && !isOptional< SrcT > > >
		{
			static inline DstT cast( Shader & shader
				, SrcT const & from )
			{
				auto dstType = makeType( typeEnum< DstT > );
				auto expr = makeExpr( from );
				auto srcType = expr->getType();

				if ( dstType != srcType )
				{
					return DstT{ &shader
						, sdw::makeCast( dstType
							, std::move( expr ) ) };
				}

				return DstT{ &shader
					, std::move( expr ) };
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< !std::is_same_v< DstT, SrcT > && !isOptional< DstT > && isOptional< SrcT > > >
		{
			static inline Optional< DstT > cast( Shader & shader
				, SrcT const & from )
			{
				auto dstType = makeType( typeEnum< DstT > );
				auto expr = makeExpr( from );
				auto srcType = from.getType();

				if ( dstType != srcType )
				{
					return Optional< DstT >{ &shader
						, sdw::makeCast( dstType
							, std::move( expr ) )
						, isOptionalEnabled( from ) };
				}

				return Optional< DstT >{ &shader
					, std::move( expr )
					, isOptionalEnabled( from ) };
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< !std::is_same_v< DstT, SrcT > && isOptional< DstT > && !isOptional< SrcT > > >
		{
			static inline DstT cast( Shader & shader
				, SrcT const & from )
			{
				auto dstType = makeType( typeEnum< DstT > );
				auto expr = makeExpr( from );
				auto srcType = expr->getType();

				if ( dstType != srcType )
				{
					return DstT{ &shader
						, sdw::makeCast( dstType
							, std::move( expr ) )
						, true };
				}

				return DstT{ &shader
					, std::move( expr )
					, true };
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< !std::is_same_v< DstT, SrcT > && isOptional< DstT > && isOptional< SrcT > > >
		{
			static inline DstT cast( Shader & shader
				, SrcT const & from )
			{
				auto dstType = makeType( typeEnum< DstT > );
				auto expr = makeExpr( from );
				auto srcType = from.getType();

				if ( dstType != srcType )
				{
					return DstT{ &shader
						, sdw::makeCast( dstType
							, std::move( expr ) )
						, isOptionalEnabled( from ) };
				}

				return DstT{ &shader
					, std::move( expr )
					, isOptionalEnabled( from ) };
			}
		};
	/**@}*/
#pragma endregion
	}

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

	template< typename ValueT >
	inline ValueT ShaderWriter::paren( ValueT const & content )
	{
		return ValueT{ &m_shader
			, makeExpr( content ) };
	}
#pragma region Cast
		/**
		*name
		*	Cast.
		*/
		/**@{*/
	template< typename DestT >
	inline DestT ShaderWriter::cast( Value const & from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, Value >::cast( m_shader, from );
	}

	template< typename DestT, typename SrcT >
	inline Optional< DestT > ShaderWriter::cast( Optional< SrcT > const & from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< Optional< DestT >, Optional< SrcT > >::cast( m_shader, from );
	}
	template< typename DestT >
	inline DestT ShaderWriter::cast( int32_t from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, int32_t >::cast( m_shader, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( uint32_t from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, uint32_t >::cast( m_shader, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( float from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, float >::cast( m_shader, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( double from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, double >::cast( m_shader, from );
	}
	/**@}*/
#pragma endregion
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
			, makeInit( var, makeExpr( rhs ) ) };
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
			, makeInit( var, makeExpr( rhs ) )
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
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > ShaderWriter::declSampledImage( std::string const & name
		, uint32_t binding
		, uint32_t set )
	{
		using T = SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig() );
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

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declSampledImage( std::string const & name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		using T = SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig() );
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

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Array< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declSampledImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension )
	{
		using T = SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig()
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

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< Array< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > > ShaderWriter::declSampledImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		using T = SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeSampledImageType( T::makeConfig()
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
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > ShaderWriter::declImage( std::string const & name
		, uint32_t binding
		, uint32_t set )
	{
		using T = ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig() );
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

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declImage( std::string const & name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		using T = ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig() );
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

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Array< ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension )
	{
		using T = ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig()
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

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline Optional< Array< ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > > ShaderWriter::declImageArray( std::string const & name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		using T = ImageT< FormatT, DimT, ArrayedT, DepthT, MsT >;
		auto type = type::makeImageType( T::makeConfig()
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
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as input type" );
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
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as input type" );
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
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as input type" );
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
	inline Optional< Array< T > > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as input type" );
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
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as output type" );
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
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as output type" );
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
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as output type" );
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
	inline Optional< Array< T > > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		static_assert( !std::is_same_v< T, Boolean >, "Boolean is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !std::is_same_v< T, Double >, "Double is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !std::is_same_v< T, DVec4 >, "DVec4 is not supported as output type" );
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
