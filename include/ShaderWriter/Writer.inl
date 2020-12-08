/*
See LICENSE file in root folder
*/
#include "Writer.hpp"

#include "ShaderWriter/CompositeTypes/Struct.hpp"

#include <ShaderAST/Debug/DebugCommon.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <stdexcept>

namespace sdw
{
#pragma region Functions
	/**
	*name
	*	Functions
	*/
	/**@{*/
	template< typename TypeT >
	inline type::StructPtr ShaderWriter::declType()
	{
		auto result = TypeT::makeType( getTypesCache() );
		sdw::addStmt( *this, sdw::makeStructDecl( result ) );
		return result;
	}
	/**@}*/
#pragma endregion
#pragma region Functions
	/**
	*name
	*	Functions
	*/
	/**@{*/
	namespace details
	{
		inline void doUpdateParamsRec( var::VariableList::const_iterator it )
		{
		}

		template< typename ParamT >
		inline void doUpdateParamsRec( var::VariableList::const_iterator it
			, ParamT & param )
		{
			param.setVar( it );
		}

		template< typename ParamT, typename ... ParamsT >
		inline void doUpdateParamsRec( var::VariableList::const_iterator it
			, ParamT & param
			, ParamsT & ... params )
		{
			param.setVar( it );
			doUpdateParamsRec( it, params... );
		}

		template< typename ... ParamsT >
		inline void doUpdateParams( ast::type::FunctionPtr type
			, ParamsT && ... params )
		{
			doUpdateParamsRec( type->begin(), params... );
		}
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... > ShaderWriter::implementFunction( std::string const & name
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		ast::var::VariableList args;
		auto decl = getFunctionHeader< ReturnT >( *this, args, name, params... );
		doPushScope( decl.get(), args );
		details::doUpdateParams( decl->getType(), params... );
		function( std::forward< ParamsT && >( params )... );
		doPopScope();
		auto functionType = decl->getType();
		addStmt( std::move( decl ) );
		return Function< ReturnT, ParamsT... >{ *this, functionType, name };
	}

	inline void ShaderWriter::implementMain( std::function< void() > const & function )
	{
		( void )implementFunction< Void >( "main", function );
	}
	/**@}*/
#pragma endregion
#pragma region Cast
	/**
	*name
	*	Cast.
	*/
	/**@{*/
	namespace details
	{
		template< typename DstT
			, typename SrcT
			, typename Enable = void >
			struct Cast;

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< IsSameV< DstT, SrcT > > >
		{
			static inline DstT cast( ShaderWriter & writer
				, DstT const & from )
			{
				return from;
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< !IsSameV< DstT, SrcT > && !isOptional< DstT > && !isOptional< SrcT > > >
		{
			static inline DstT cast( ShaderWriter & writer
				, SrcT const & from )
			{
				auto dstType = DstT::makeType( writer.getTypesCache() );
				auto expr = makeExpr( writer, from );
				auto srcType = expr->getType();

				if ( dstType != srcType )
				{
					return DstT{ writer
						, sdw::makeCast( dstType
							, std::move( expr ) ) };
				}

				return DstT{ writer
					, std::move( expr ) };
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< !IsSameV< DstT, SrcT > && !isOptional< DstT > && isOptional< SrcT > > >
		{
			static inline Optional< DstT > cast( ShaderWriter & writer
				, SrcT const & from )
			{
				auto dstType = DstT::makeType( writer.getTypesCache() );
				auto expr = makeExpr( writer, from );
				auto srcType = from.getType();

				if ( dstType != srcType )
				{
					return Optional< DstT >{ writer
						, sdw::makeCast( dstType
							, std::move( expr ) )
						, isOptionalEnabled( from ) };
				}

				return Optional< DstT >{ writer
					, std::move( expr )
					, isOptionalEnabled( from ) };
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< !IsSameV< DstT, SrcT > && isOptional< DstT > && !isOptional< SrcT > > >
		{
			static inline DstT cast( ShaderWriter & writer
				, SrcT const & from )
			{
				auto dstType = DstT::makeType( writer.getTypesCache() );
				auto expr = makeExpr( writer, from );
				auto srcType = expr->getType();

				if ( dstType != srcType )
				{
					return DstT{ writer
						, sdw::makeCast( dstType
							, std::move( expr ) )
						, true };
				}

				return DstT{ writer
					, std::move( expr )
					, true };
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< !IsSameV< DstT, SrcT > && isOptional< DstT > && isOptional< SrcT > > >
		{
			static inline DstT cast( ShaderWriter & writer
				, SrcT const & from )
			{
				auto dstType = DstT::makeType( writer.getTypesCache() );
				auto expr = makeExpr( writer, from );
				auto srcType = from.getType();

				if ( dstType != srcType )
				{
					return DstT{ writer
						, sdw::makeCast( dstType
							, std::move( expr ) )
						, isOptionalEnabled( from ) };
				}

				return DstT{ writer
					, std::move( expr )
					, isOptionalEnabled( from ) };
			}
		};
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( Value const & from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, Value >::cast( *this, from );
	}

	template< typename DestT, typename SrcT >
	inline Optional< DestT > ShaderWriter::cast( Optional< SrcT > const & from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< Optional< DestT >, Optional< SrcT > >::cast( *this, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( int32_t from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, int32_t >::cast( *this, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( uint32_t from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, uint32_t >::cast( *this, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( float from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, float >::cast( *this, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( double from )
	{
		static_assert( !isOptional< DestT >, "Can't cast to an optional type." );
		return details::Cast< DestT, double >::cast( *this, from );
	}
	/**@}*/
#pragma endregion
#pragma region Control statements
	/**
	*name
	*	Control statements.
	*/
	/**@{*/
	template< typename RetType >
	void ShaderWriter::returnStmt( RetType const & value )
	{
		addStmt( sdw::makeReturn( makeExpr( *this, value ) ) );
	}

	template< typename ExprType >
	ExprType ShaderWriter::ternary( expr::ExprPtr condition
		, expr::ExprPtr left
		, expr::ExprPtr right )
	{
		auto type = left->getType();
		return ExprType{ *this
			, sdw::makeQuestion( type
				, std::move( condition )
				, std::move( left )
				, std::move( right ) ) };
	}

	template< typename ExprType >
	ExprType ShaderWriter::ternary( Boolean condition
		, ExprType left
		, ExprType right )
	{
		auto type = left.getType();
		return ExprType{ *this
			, sdw::makeQuestion( type
				, makeExpr( *this, std::move( condition ) )
				, makeExpr( *this, std::move( left ) )
				, makeExpr( *this, std::move( right ) ) ) };
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
		auto type = T::makeType( getTypesCache() );
		auto var = registerStaticConstant( name
			, type );
		addStmt( sdw::makeSimple( sdw::makeInit( var
			, makeConstExpr( *this, rhs ) ) ) );
		return T{ *this
			, makeConstExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declConstant( std::string const & name
		, T const & rhs
		, bool enabled )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerStaticConstant( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeConstExpr( *this, rhs ) ) ) );
		}

		return Optional< T >{ *this
			, makeConstExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declConstantArray( std::string const & name
		, std::vector< T > const & rhs )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, uint32_t( rhs.size() ) );
		auto var = registerStaticConstant( name
			, type );
		addStmt( sdw::makeSimple( sdw::makeAggrInit( var
				, makeConstExpr( *this, rhs ) ) ) );
		return Array< T >{ *this
			, makeConstExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declConstantArray( std::string const & name
		, std::vector< T > const & rhs
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, uint32_t( rhs.size() ) );
		auto var = registerStaticConstant( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( sdw::makeAggrInit( var
				, makeConstExpr( *this, rhs ) ) ) );
		}

		return Optional< Array< T > >{ *this
			, makeConstExpr( *this, var )
			, enabled };
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > ShaderWriter::declConstant( std::string const & name
		, IncDecWrapperT< KindT > rhs )
	{
		return declConstant( name, IntegerValue< KindT >{ std::move( rhs ) } );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > ShaderWriter::declConstant( std::string const & name
		, IncDecWrapperT< KindT > rhs
		, bool enabled )
	{
		return declConstant( name, IntegerValue< KindT >{ std::move( rhs ) }, enabled );
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
		auto type = T::makeType( getTypesCache() );
		auto var = registerSampledImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeSampledImgDecl( var
			, binding
			, set ) );
		return T{ *this
			, makeExpr( *this, var ) };
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
		auto type = T::makeType( getTypesCache() );
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

		return Optional< T >{ *this
			, makeExpr( *this, var )
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
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerSampledImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeSampledImgDecl( var
			, binding
			, set ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
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
		auto type = Array< T >::makeType( getTypesCache()
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

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
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
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		inline ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > ShaderWriter::declImage( std::string const & name
			, uint32_t binding
			, uint32_t set )
	{
		using T = ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >;
		auto type = T::makeType( getTypesCache() );
		auto var = registerImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeImageDecl( var
			, binding
			, set ) );
		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		inline Optional< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled )
	{
		using T = ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >;
		auto type = T::makeType( getTypesCache() );
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

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		inline Array< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension )
	{
		using T = ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >;
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerImage( name
			, type
			, binding
			, set );
		addStmt( sdw::makeImageDecl( var
			, binding
			, set ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		inline Optional< Array< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > > > ShaderWriter::declImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled )
	{
		using T = ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >;
		auto type = Array< T >::makeType( getTypesCache()
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

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
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
		return declInput< T >( name
			, location
			, 0u );
	}

	template< typename T >
	inline T ShaderWriter::declInput( std::string const & name
		, uint32_t location
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerInput( name
			, location
			, attributes
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension )
	{
		return declInputArray< T >( name
			, location
			, dimension
			, 0u );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerInput( name
			, location
			, attributes
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declInput( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		return declInput< T >( name
			, location
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declInput( std::string const & name
		, uint32_t location
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerInput( name
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		return declInputArray< T >( name
			, location
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerInput( name
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declInput( std::string const & name
		, uint32_t location
		, bool enabled
		, T const & defaultValue )
	{
		return declInput< T >( name
			, location
			, 0u
			, enabled
			, defaultValue );
	}

	template< typename T >
	inline T ShaderWriter::declInput( std::string const & name
		, uint32_t location
		, uint32_t attributes
		, bool enabled
		, T const & defaultValue )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = T::makeType( getTypesCache() );
		var::VariablePtr var;

		if ( enabled )
		{
			var = registerInput( name
				, location
				, attributes
				, type );
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}
		else
		{
			var = registerStaticConstant( name
				, type );
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, bool enabled
		, std::vector< T > const & defaultValue )
	{
		return declInputArray< T >( name
			, location
			, dimension
			, 0u
			, enabled
			, defaultValue );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, uint32_t attributes
		, bool enabled
		, std::vector< T > const & defaultValue )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as input type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as input type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as input type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as input type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as input type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as input type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as input type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as input type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		var::VariablePtr var;

		if ( enabled )
		{
			var = registerInput( name
				, location
				, attributes
				, type );
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}
		else
		{
			var = registerStaticConstant( name
				, type );
			addStmt( sdw::makeSimple( sdw::makeAggrInit( var
				, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}
	/**@}*/
#pragma endregion
#pragma region Uniform buffer declaration
	/**
	*name
	*	Uniform buffer declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declUniformBuffer( std::string const & name
		, uint32_t binding
		, uint32_t set
		, ast::type::MemoryLayout layout )
	{
		return T{ *this, name, binding, set, layout };
	}
	/**@}*/
#pragma endregion
#pragma region Shader storage buffer declaration
	/**
	*name
	*	Shader storage buffer declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declShaderStorageBuffer( std::string const & name
		, uint32_t binding
		, uint32_t set
		, ast::type::MemoryLayout layout )
	{
		return T{ *this, name, binding, set, layout };
	}

	template< typename T >
	inline ArraySsboT< T > ShaderWriter::declArrayShaderStorageBuffer( std::string const & name
		, uint32_t binding
		, uint32_t set )
	{
		return ArraySsboT< T >{ *this, name, binding, set };
	}
	/**@}*/
#pragma endregion
#pragma region Push constants buffer declaration
	/**
	*name
	*	Push constants buffer declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declPushConstantsBuffer( std::string const & name
		, ast::type::MemoryLayout layout )
	{
		return T{ *this, name, layout };
	}
	/**@}*/
#pragma endregion
#pragma region Struct declaration
	/**
	*name
	*	Struct declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::declStruct( std::string const & name
		, ast::type::MemoryLayout layout )
	{
		return T{ *this, name, layout };
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
		return declOutput< T >( name
			, location
			, 0u );
	}

	template< typename T >
	inline T ShaderWriter::declOutput( std::string const & name
		, uint32_t location
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( name
			, location
			, attributes
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension )
	{
		return declOutputArray< T >( name
			, location
			, dimension
			, 0u );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( name
			, location
			, attributes
			, type );
		addStmt( sdw::makeInOutVariableDecl( var
			, location ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declOutput( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		return declOutput< T >( name
			, location
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declOutput( std::string const & name
		, uint32_t location
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( name
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, bool enabled )
	{
		return declOutputArray< T >( name
			, location
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( name
			, location
			, attributes
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location ) );
		}

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
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
	template< typename InstanceT >
	inline InstanceT ShaderWriter::declLocale( std::string const & name
		, Struct const & type )
	{
		return type.getInstance< InstanceT >( name );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeVariableDecl( var ) );
		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, T const & rhs )
	{
		auto type = rhs.getType();
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeSimple( sdw::makeInit( var
			, makeExpr( *this, rhs ) ) ) );
		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline MaybeOptional< T > ShaderWriter::declLocale( std::string const & name
		, MaybeOptional< T > const & rhs )
	{
		auto type = rhs.getType();
		auto var = registerLocale( name
			, type );

		if ( rhs.isEnabled() )
		{
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeExpr( *this, rhs ) ) ) );
		}

		if ( rhs.isOptional() )
		{
			return MaybeOptional< T >{ *this
				, makeExpr( *this, var )
				, rhs.isEnabled() };
		}

		return MaybeOptional< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declLocale( std::string const & name
		, bool enabled )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
		}

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, bool enabled
		, T const & defaultValue )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerLocale( name
			, type );

		if ( !enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
		}
		else
		{
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declLocale( std::string const & name
		, Optional< T > const & rhs )
	{
		auto type = rhs.getType();
		auto var = registerLocale( name
			, type );

		if ( rhs.isEnabled() )
		{
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeExpr( *this, rhs ) ) ) );
		}

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, rhs.isEnabled() };
	}

	template< typename T >
	inline Optional< T > ShaderWriter::declLocale( std::string const & name
		, T const & rhs
		, bool enabled )
	{
		auto type = rhs.getType();
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( sdw::makeInit( var
				, makeExpr( *this, rhs ) ) ) );
		}

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeVariableDecl( var ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, std::vector< T > const & rhs )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( name
			, type );
		addStmt( sdw::makeSimple( sdw::makeAggrInit( var
			, makeExpr( *this, rhs ) ) ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
		}

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, bool enabled
		, std::vector< T > const & defaultValue )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
		}
		else
		{
			addStmt( sdw::makeSimple( sdw::makeAggrInit( var
				, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::declLocaleArray( std::string const & name
		, uint32_t dimension
		, std::vector< T > const & rhs
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( sdw::makeAggrInit( var
				, makeExpr( *this, rhs ) ) ) );
		}

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > ShaderWriter::declLocale( std::string const & name
		, IncDecWrapperT< KindT > rhs )
	{
		using T = IntegerValue< KindT >;
		return declLocale( name, IntegerValue< KindT >{ std::move( rhs ) } );
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > ShaderWriter::declLocale( std::string const & name
		, bool enabled
		, IncDecWrapperT< KindT > defaultValue )
	{
		using T = IntegerValue< KindT >;
		return declLocale( name, enabled, IntegerValue< KindT >{ std::move( defaultValue ) } );
	}

	template< ast::type::Kind KindT >
	inline Optional< IntegerValue< KindT > > ShaderWriter::declLocale( std::string const & name
		, IncDecWrapperT< KindT > rhs
		, bool enabled )
	{
		using T = IntegerValue< KindT >;
		return declLocale( name, IntegerValue< KindT >{ std::move( rhs ) }, enabled );
	}
	/**@}*/
#pragma endregion
#pragma region Already declared variable getters
	namespace details
	{
		inline void checkTypes( type::TypePtr varType, type::TypePtr resultType )
		{
			if ( varType != resultType )
			{
				assert( false
					&& "Var type and expected type don't match" );
				std::string text;
				text += "Var type [" + debug::getName( varType ) + "] and expected type [" + debug::getName( resultType ) + "] don't match";
				throw std::runtime_error{ text };
			}
		}
	}
	/**
	*name
	*	Already declared variable getters.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::getVariable( std::string const & name )
	{
		auto var = getVar( name );
		T result
		{
			*this,
			makeExpr( *this, var ),
		};
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}

	template< typename T >
	inline Optional< T > ShaderWriter::getVariable( std::string const & name
		, bool enabled )
	{
		auto var = getVar( name );
		Optional< T > result
		{
			*this,
			makeExpr( *this, var ),
			enabled,
		};
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}

	template< typename T >
	inline Array< T > ShaderWriter::getVariableArray( std::string const & name )
	{
		auto var = getVar( name );
		Array< T > result
		{
			*this,
			makeExpr( *this, var ),
		};
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}

	template< typename T >
	inline Optional< Array< T > > ShaderWriter::getVariableArray( std::string const & name
		, bool enabled )
	{
		auto var = getVar( name );
		Optional< Array< T > > result
		{
			*this,
			makeExpr( *this, var ),
			enabled
		};
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}
	/**@}*/
#pragma endregion
#pragma region Stream Output declaration
	/**
	*name
	*	Stream Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T GeometryWriter::declStreamOutput( std::string const & name
		, uint32_t location
		, uint32_t streamIndex )
	{
		return declStreamOutput< T >( name
			, location
			, streamIndex
			, 0u );
	}

	template< typename T >
	inline T GeometryWriter::declStreamOutput( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eGeometryStream
			, type );
		addStmt( sdw::makeInOutStreamVariableDecl( var
			, location
			, streamIndex ) );
		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Array< T > GeometryWriter::declStreamOutputArray( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension )
	{
		return declStreamOutputArray< T >( name
			, location
			, streamIndex
			, dimension
			, 0u );
	}

	template< typename T >
	inline Array< T > GeometryWriter::declStreamOutputArray( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eGeometryStream
			, type );
		addStmt( sdw::makeInOutStreamVariableDecl( var
			, location
			, streamIndex ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< T > GeometryWriter::declStreamOutput( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, bool enabled )
	{
		return declStreamOutput< T >( name
			, location
			, streamIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< T > GeometryWriter::declStreamOutput( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutStreamVariableDecl( var
				, location
				, streamIndex ) );
		}

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > GeometryWriter::declStreamOutputArray( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declStreamOutputArray< T >( name
			, location
			, streamIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > GeometryWriter::declStreamOutputArray( std::string const & name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutVariableDecl( var
				, location
				, streamIndex ) );
		}

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Blend Output declaration
	/**
	*name
	*	Blend Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T FragmentWriter::declBlendOutput( std::string const & name
		, uint32_t location
		, uint32_t blendIndex )
	{
		return declBlendOutput< T >( name
			, location
			, blendIndex
			, 0u );
	}

	template< typename T >
	inline T FragmentWriter::declBlendOutput( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eBlendIndex
			, type );
		addStmt( sdw::makeInOutBlendVariableDecl( var
			, location
			, blendIndex ) );
		return T{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Array< T > FragmentWriter::declBlendOutputArray( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension )
	{
		return declBlendOutputArray< T >( name
			, location
			, blendIndex
			, dimension
			, 0u );
	}

	template< typename T >
	inline Array< T > FragmentWriter::declBlendOutputArray( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension
		, uint32_t attributes )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eBlendIndex
			, type );
		addStmt( sdw::makeInOutBlendVariableDecl( var
			, location
			, blendIndex ) );
		return Array< T >{ *this
			, makeExpr( *this, var ) };
	}

	template< typename T >
	inline Optional< T > FragmentWriter::declBlendOutput( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, bool enabled )
	{
		return declBlendOutput< T >( name
			, location
			, blendIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< T > FragmentWriter::declBlendOutput( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( name
			, location
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutBlendVariableDecl( var
				, location
				, blendIndex ) );
		}

		return Optional< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Optional< Array< T > > FragmentWriter::declBlendOutputArray( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declBlendOutputArray< T >( name
			, location
			, blendIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Optional< Array< T > > FragmentWriter::declBlendOutputArray( std::string const & name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension
		, uint32_t attributes
		, bool enabled )
	{
		static_assert( !IsSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !IsSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !IsSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !IsSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !IsSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !IsSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !IsSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !IsSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( name
			, location
			, blendIndex
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutBlendVariableDecl( var
				, location
				, blendIndex ) );
		}

		return Optional< Array< T > >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
#pragma endregion
}
