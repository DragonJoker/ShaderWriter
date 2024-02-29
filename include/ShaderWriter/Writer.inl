/*
See LICENSE file in root folder
*/
#include "Writer.hpp"

#include "ShaderWriter/CompositeTypes/Struct.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <algorithm>
#include <stdexcept>

namespace sdw
{
#pragma region Type registration
	/**
	*name
	*	Type registration
	*/
	/**@{*/
	template< typename TypeT, typename ... ParamsT >
	inline type::StructPtr ShaderWriter::declType( ParamsT && ... params )
	{
		auto result = TypeT::makeType( getTypesCache()
			, std::forward< ParamsT >( params )... );
		addGlobalStmt( makeStructureDecl( getStmtCache(), result ) );
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
		inline void doUpdateParamsRec( var::VariableList::const_iterator )
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
	inline Function< ReturnT, ParamsT... > ShaderWriter::implementFunction( std::string name
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		return implementFunction< ReturnT >( std::move( name )
			, uint32_t( ast::stmt::FunctionFlag::eNone )
			, function
			, std::forward< ParamsT >( params )... );
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... > ShaderWriter::implementFunction( std::string name
		, ast::stmt::FunctionFlag flag
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		return implementFunction< ReturnT >( std::move( name )
			, uint32_t( flag )
			, function
			, std::forward< ParamsT >( params )... );
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... > ShaderWriter::implementFunction( std::string name
		, uint32_t flags
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		ast::var::VariablePtr funcVar;

		if ( m_builder->hasFunction( name, flags ) )
		{
			funcVar = m_builder->getFunction( name, flags );
			auto functionType = funcVar->getType();

			if ( functionType->getKind() != ast::type::Kind::eFunction )
			{
				throw ast::Exception{ "A variable named " + name + " already exists and is not a function." };
			}
		}
		else
		{
			ast::var::VariableList args;
			stmt::FunctionDeclPtr decl = getFunctionHeader< ReturnT >( *this, args, name, flags, params... );
			funcVar = decl->getFuncVar();
			m_builder->push( decl.get(), args );
			details::doUpdateParams( decl->getType(), params... );
			function( params... );
			m_builder->pop();
			addGlobalStmt( std::move( decl ) );
		}

		return Function< ReturnT, ParamsT... >{ *this, std::move( funcVar ) };
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
		template< typename DstT, typename SrcT
			, typename Enable = void >
		struct Cast;

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< isSameV< DstT, SrcT > > >
		{
			static inline DstT cast( ShaderWriter const &
				, DstT const & from )
			{
				return from;
			}
		};

		template< typename DstT, typename SrcT >
		struct Cast< DstT, SrcT
			, std::enable_if_t< isSameComponentCountV< DstT, SrcT > && !isSameV< DstT, SrcT > > >
		{
			static inline DstT cast( ShaderWriter & writer
				, SrcT const & from )
			{
				auto dstType = DstT::makeType( writer.getTypesCache() );
				auto expr = makeExpr( writer, from );

				if ( auto srcType = expr->getType();
					dstType != srcType )
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
	inline DestT ShaderWriter::cast( int32_t from )
	{
		return details::Cast< DestT, int32_t >::cast( *this, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( uint32_t from )
	{
		return details::Cast< DestT, uint32_t >::cast( *this, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( float from )
	{
		return details::Cast< DestT, float >::cast( *this, from );
	}

	template< typename DestT >
	inline DestT ShaderWriter::cast( double from )
	{
		return details::Cast< DestT, double >::cast( *this, from );
	}

	template< typename DestT, typename SourceT >
	inline DestT ShaderWriter::cast( SourceT const & from )
	{
		return details::Cast< DestT, SourceT >::cast( *this, from );
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
		addStmt( makeReturn( getStmtCache(), makeExpr( *this, value ) ) );
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
				, std::move( right ) )
			, true };
	}

	template< typename ExprType >
	ExprType ShaderWriter::ternary( Boolean condition
		, ExprType left
		, ExprType right )
	{
		auto type = left.getType();
		return ExprType{ *this
			, sdw::makeQuestion( type
				, makeExpr( *this, condition )
				, makeExpr( *this, std::move( left ) )
				, makeExpr( *this, std::move( right ) ) )
			, areOptionalEnabled( condition, left, right ) };
	}

	template< typename ExprType >
	ExprType ShaderWriter::ternary( Boolean condition
		, ReturnWrapperT< ExprType > left
		, ExprType right )
	{
		auto type = left.getType();
		return ExprType{ *this
			, sdw::makeQuestion( type
				, makeExpr( *this, condition )
				, makeExpr( *this, std::move( left ) )
				, makeExpr( *this, std::move( right ) ) )
			, areOptionalEnabled( condition, left, right ) };
	}

	template< typename ExprType >
	ExprType ShaderWriter::ternary( Boolean condition
		, ExprType left
		, ReturnWrapperT< ExprType > right )
	{
		auto type = left.getType();
		return ExprType{ *this
			, sdw::makeQuestion( type
				, makeExpr( *this, condition )
				, makeExpr( *this, std::move( left ) )
				, makeExpr( *this, std::move( right ) ) )
			, areOptionalEnabled( condition, left, right ) };
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
	inline T ShaderWriter::declConstant( std::string name
		, T const & rhs
		, bool enabled )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerStaticConstant( std::move( name )
			, type );
		enabled = enabled && isOptionalEnabled( rhs );

		if ( enabled )
		{
			addGlobalStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeConstExpr( *this, rhs ) ) ) );
		}

		return T{ *this
			, makeConstExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declConstantArray( std::string name
		, std::vector< T > const & rhs
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, uint32_t( rhs.size() ) );
		auto var = registerStaticConstant( std::move( name )
			, type );
		enabled = enabled && std::all_of( rhs.begin()
			, rhs.end()
			, []( T const & v )
			{
				return isOptionalEnabled( v );
			} );

		if ( enabled )
		{
			addGlobalStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeAggrInit( var
					, makeConstExpr( *this, rhs ) ) ) );
		}

		return Array< T >{ *this
			, makeConstExpr( *this, var )
			, enabled };
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > ShaderWriter::declConstant( std::string name
		, ReturnWrapperT< IntegerValue< KindT > > rhs
		, bool enabled )
	{
		enabled = enabled && isOptionalEnabled( rhs );
		return declConstant( std::move( name ), IntegerValue< KindT >{ std::move( rhs ) }, enabled );
	}
	/**@}*/
#pragma endregion
#pragma region Sampler declaration
	/**
	*name
	*	Sampler declaration.
	*/
	/**@{*/
	template< bool ComparisonT >
	inline SamplerT< ComparisonT > ShaderWriter::declSampler( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto type = SamplerT< ComparisonT >::makeType( getTypesCache() );
		auto var = registerSampler( std::move( name )
			, type
			, binding
			, set );

		if ( enabled )
		{
			addStmt( makeSamplerDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return SamplerT< ComparisonT >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declSampler( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declSampler< T::Comparison >( std::move( name )
			, binding
			, set
			, enabled );
	}

	template< bool ComparisonT >
	inline Array< SamplerT< ComparisonT > > ShaderWriter::declSamplerArray( std::string name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled )
	{
		using T = SamplerT< ComparisonT >;
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerSampler( std::move( name )
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( makeSamplerDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSamplerArray( std::string name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		return declSamplerArray< T::Comparison >( std::move( name )
			, binding
			, set
			, dimension
			, enabled );
	}

	template< bool ComparisonT >
	inline Array< SamplerT< ComparisonT > > ShaderWriter::declSamplerArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declSamplerArray< SamplerT< ComparisonT > >( std::move( name )
			, binding
			, set
			, ast::type::UnknownArraySize
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSamplerArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declSamplerArray< T::Comparison >( std::move( name )
			, binding
			, set
			, ast::type::UnknownArraySize
			, enabled );
	}

	template< bool ComparisonT >
	inline SamplerT< ComparisonT > ShaderWriter::declSampler(std::string name
		, LocationHelper location
		, bool enabled)
	{
		return declSampler< ComparisonT >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declSampler(std::string name
		, LocationHelper location
		, bool enabled)
	{
		return declSampler< T >( std::move(name)
			, location.binding
			, location.set
			, enabled );
	}

	template< bool ComparisonT >
	inline Array< SamplerT< ComparisonT > > ShaderWriter::declSamplerArray(std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled)
	{
		return declSamplerArray< ComparisonT >( std::move(name)
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSamplerArray(std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled)
	{
		return declSamplerArray< T >( std::move(name)
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< bool ComparisonT >
	inline Array< SamplerT< ComparisonT > > ShaderWriter::declSamplerArray(std::string name
		, LocationHelper location
		, bool enabled)
	{
		return declSamplerArray< ComparisonT >( std::move(name)
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSamplerArray(std::string name
		, LocationHelper location
		, bool enabled)
	{
		return declSamplerArray< T >( std::move(name)
			, location.binding
			, location.set
			, enabled );
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
		, bool MsT >
	inline SampledImageT< FormatT, DimT, ArrayedT, MsT > ShaderWriter::declSampledImg( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		using T = SampledImageT< FormatT, DimT, ArrayedT, MsT >;
		auto type = T::makeType( getTypesCache() );
		auto var = registerSampledImage( std::move( name )
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( makeSampledImageDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declSampledImg( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declSampledImg< T::Format
			, T::Dim
			, T::Arrayed
			, T::Ms >( std::move( name )
				, binding
				, set
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > ShaderWriter::declSampledImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		using T = SampledImageT< FormatT, DimT, ArrayedT, MsT >;
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerSampledImage( std::move( name )
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( makeSampledImageDecl( getStmtCache()
				 ,var
				, binding
				, set ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSampledImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		return declSampledImgArray< T::Format
			, T::Dim
			, T::Arrayed
			, T::Ms >( std::move( name )
				, binding
				, set
				, dimension
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > ShaderWriter::declSampledImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declSampledImgArray< FormatT
			, DimT
			, ArrayedT
			, MsT >( std::move( name )
				, binding
				, set
				, ast::type::UnknownArraySize
				, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSampledImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declSampledImgArray< T::Format
			, T::Dim
			, T::Arrayed
			, T::Ms >( std::move( name )
				, binding
				, set
				, ast::type::UnknownArraySize
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline SampledImageT< FormatT, DimT, ArrayedT, MsT > ShaderWriter::declSampledImg( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declSampledImg< FormatT, DimT, ArrayedT, MsT >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declSampledImg( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declSampledImg< T >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > ShaderWriter::declSampledImgArray( std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled )
	{
		return declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( std::move( name )
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSampledImgArray( std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled )
	{
		return declSampledImgArray< T >( std::move( name )
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< SampledImageT< FormatT, DimT, ArrayedT, MsT > > ShaderWriter::declSampledImgArray( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declSampledImgArray< FormatT, DimT, ArrayedT, MsT >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declSampledImgArray( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declSampledImgArray< T >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}
	/**@}*/
#pragma endregion
#pragma region Combined Sampler and Image declaration
	/**
	*name
	*	Combined Sampler and Image declaration.
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > ShaderWriter::declCombinedImg( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		using T = CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT >;
		auto type = T::makeType( getTypesCache() );
		auto var = registerTexture( std::move( name )
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( makeCombinedImageDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declCombinedImg( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declCombinedImg< T::Format
			, T::Dim
			, T::Arrayed
			, T::Ms
			, T::Depth > ( std::move( name )
				, binding
				, set
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > ShaderWriter::declCombinedImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		using T = CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT >;
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerTexture( std::move( name )
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( makeCombinedImageDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declCombinedImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		return declCombinedImgArray< T::Format
			, T::Dim
			, T::Arrayed
			, T::Ms
			, T::Depth > ( std::move( name )
				, binding
				, set
				, dimension
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > ShaderWriter::declCombinedImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declCombinedImgArray< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT >( std::move( name )
				, binding
				, set
				, ast::type::UnknownArraySize
				, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declCombinedImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declCombinedImgArray< T::Format
			, T::Dim
			, T::Arrayed
			, T::Ms
			, T::Depth >( std::move( name )
				, binding
				, set
				, ast::type::UnknownArraySize
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > ShaderWriter::declCombinedImg( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declCombinedImg( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declCombinedImg< T >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > ShaderWriter::declCombinedImgArray( std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled )
	{
		return declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( std::move( name )
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declCombinedImgArray( std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled )
	{
		return declCombinedImgArray< T >( std::move( name )
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline Array< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > > ShaderWriter::declCombinedImgArray( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declCombinedImgArray< FormatT, DimT, ArrayedT, MsT, DepthT >( std::move( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declCombinedImgArray( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declCombinedImgArray< T >( std::move( name )
			, location.binding
			, location.set
			, enabled );
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
		, bool MsT >
	inline StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > ShaderWriter::declStorageImg( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		using T = StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >;
		auto type = T::makeType( getTypesCache() );
		auto var = registerImage( std::move( name )
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( makeImageDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declStorageImg( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declStorageImg < T::Format
			, T::Access
			, T::Dim
			, T::Arrayed
			, T::Ms > ( std::move( name )
				, binding
				, set
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > ShaderWriter::declStorageImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		using T = StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >;
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerImage( std::move( name )
			, type
			, binding
			, set
			, enabled );

		if ( enabled )
		{
			addStmt( makeImageDecl( getStmtCache()
				, var
				, binding
				, set ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declStorageImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, uint32_t dimension
		, bool enabled )
	{
		return declStorageImgArray < T::Format
			, T::Access
			, T::Dim
			, T::Arrayed
			, T::Ms > ( std::move( name )
				, binding
				, set
				, dimension
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > ShaderWriter::declStorageImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declCombinedImgArray< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT >( std::move( name )
				, binding
				, set
				, ast::type::UnknownArraySize
				, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declStorageImgArray( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return declCombinedImgArray< T::Format
			, T::Access
			, T::Dim
			, T::Arrayed
			, T::Ms >( std::move( name )
				, binding
				, set
				, ast::type::UnknownArraySize
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > ShaderWriter::declStorageImg( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declStorageImg< FormatT, AccessT, DimT, ArrayedT, MsT >( std::move ( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declStorageImg( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declStorageImg< T >( std::move ( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > ShaderWriter::declStorageImgArray( std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled )
	{
		return declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( std::move ( name )
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declStorageImgArray( std::string name
		, LocationHelper location
		, uint32_t dimension
		, bool enabled )
	{
		return declStorageImgArray< T >( std::move ( name )
			, location.binding
			, location.set
			, dimension
			, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline Array< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > > ShaderWriter::declStorageImgArray( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declStorageImgArray< FormatT, AccessT, DimT, ArrayedT, MsT >( std::move ( name )
			, location.binding
			, location.set
			, enabled );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declStorageImgArray( std::string name
		, LocationHelper location
		, bool enabled )
	{
		return declStorageImgArray< T >( std::move ( name )
			, location.binding
			, location.set
			, enabled );
	}
	/**@}*/
#pragma endregion
#pragma region Shared variables declaration
	/**
	*name
	*	Shared variables declaration.
	*/
	/**@{*/
	template< typename T, typename ... ParamsT >
	T ShaderWriter::declSharedVariable( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto type = T::makeType( getTypesCache()
			, std::forward< ParamsT >( params )... );
		auto var = registerName( name
			, type
			, uint64_t( ast::var::Flag::eShared ) );

		if ( enabled )
		{
			addGlobalStmt( makeVariableDecl( getStmtCache(), var ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T, typename ... ParamsT >
	Array< T > ShaderWriter::declSharedVariable( std::string name
		, uint32_t dimension
		, bool enabled
		, ParamsT && ... params )
	{
		auto type = getTypesCache().getArray( T::makeType( getTypesCache()
				, std::forward< ParamsT >( params )... )
			, dimension );
		auto var = registerName( name
			, type
			, uint64_t( ast::var::Flag::eShared ) );

		if ( enabled )
		{
			addGlobalStmt( makeVariableDecl( getStmtCache(), var ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Ray tracing variables declaration
	/**
	*name
	*	Ray tracing variables declaration.
	*/
	/**@{*/
	template< typename T >
	inline RayPayloadT< T > ShaderWriter::declRayPayload( std::string name
		, uint32_t location
		, bool enabled )
	{
		auto type = RayPayloadT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( makeStructureDecl( getStmtCache(), structType ) );
		}

		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eRayPayload ) );

		if ( enabled )
		{
			addStmt( makeInOutRayPayloadVariableDecl( getStmtCache(), var
				, location ) );
		}

		return RayPayloadT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline RayPayloadInT< T > ShaderWriter::declIncomingRayPayload( std::string name
		, uint32_t location
		, bool enabled )
	{
		auto type = RayPayloadInT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( makeStructureDecl( getStmtCache(), structType ) );
		}

		auto var = registerInOut( std::move( name )
			, uint64_t( ast::var::Flag::eIncomingRayPayload )
			, type );

		if ( enabled )
		{
			addStmt( makeInOutRayPayloadVariableDecl( getStmtCache(), var
				, location ) );
		}

		return RayPayloadInT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline CallableDataT< T > ShaderWriter::declCallableData( std::string name
		, uint32_t location
		, bool enabled )
	{
		auto type = CallableDataT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( makeStructureDecl( getStmtCache(), structType ) );
		}

		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eCallableData ) );

		if ( enabled )
		{
			addStmt( makeInOutCallableDataVariableDecl( getStmtCache(), var
				, location ) );
		}

		return CallableDataT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline CallableDataInT< T > ShaderWriter::declIncomingCallableData( std::string name
		, uint32_t location
		, bool enabled )
	{
		auto type = CallableDataInT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( makeStructureDecl( getStmtCache(), structType ) );
		}

		auto var = registerInOut( std::move( name )
			, uint64_t( ast::var::Flag::eIncomingCallableData )
			, type );

		if ( enabled )
		{
			addStmt( makeInOutCallableDataVariableDecl( getStmtCache(), var
				, location ) );
		}

		return CallableDataInT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline HitAttributeT< T > ShaderWriter::declHitAttribute( std::string name
		, bool enabled )
	{
		auto type = HitAttributeT< T >::makeType( getTypesCache() );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( makeStructureDecl( getStmtCache(), structType ) );
		}

		auto var = registerInOut( std::move( name )
			, uint64_t( ast::var::Flag::eHitAttribute )
			, type );

		if ( enabled )
		{
			addStmt( makeHitAttributeVariableDecl( getStmtCache(), var ) );
		}

		return HitAttributeT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Uniform buffer declaration
	/**
	*name
	*	Uniform buffer declaration.
	*/
	/**@{*/
	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declUniformBuffer( std::string name
		, uint32_t binding
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled
		, ParamsT && ... params )
	{
		return T{ *this
			, std::move( name )
			, binding
			, set
			, layout
			, enabled
			, std::forward< ParamsT >( params )... };
	}

	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declUniformBuffer(std::string name
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled
		, ParamsT && ... params )
	{
		return declUniformBuffer< T >( std::move(name)
			, location.binding
			, location.set
			, layout
			, enabled
			, std::forward< ParamsT >( params )... );
	}
	/**@}*/
#pragma endregion
#pragma region Shader storage buffer declaration
	/**
	*name
	*	Shader storage buffer declaration.
	*/
	/**@{*/
	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declStorageBuffer( std::string name
		, uint32_t binding
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled
		, ParamsT && ... params )
	{
		return T{ *this
			, std::move( name )
			, binding
			, set
			, layout
			, enabled
			, std::forward< ParamsT >( params )... };
	}

	template< typename T, typename ... ParamsT >
	inline ArrayStorageBufferT< T > ShaderWriter::declArrayStorageBuffer( std::string name
		, uint32_t binding
		, uint32_t set
		, bool enabled
		, ParamsT && ... params )
	{
		return ArrayStorageBufferT< T >{ *this
			, std::move( name )
			, binding
			, set
			, enabled
			, std::forward< ParamsT >( params )... };
	}

	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declStorageBuffer(std::string name
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled
		, ParamsT && ... params )
	{
		return declStorageBuffer< T >( std::move(name)
			, location.binding
			, location.set
			, layout
			, enabled
			, std::forward< ParamsT >( params )... );
	}

	template< typename T, typename ... ParamsT >
	inline ArrayStorageBufferT< T > ShaderWriter::declArrayStorageBuffer(std::string name
		, LocationHelper location
		, bool enabled
		, ParamsT && ... params )
	{
		return declArrayStorageBuffer< T >( std::move(name)
			, location.binding
			, location.set
			, enabled
			, std::forward< ParamsT >( params )... );
	}
	/**@}*/
#pragma endregion
#pragma region Buffer reference declaration
	/**
	*name
	*	Buffer reference declaration.
	*/
	/**@{*/
	template< typename BufferT, typename ... ParamsT >
	inline BufferReferenceT< BufferT > ShaderWriter::declBufferReference( std::string name
		, ast::type::MemoryLayout layout
		, ast::type::Storage storage
		, bool enabled
		, ParamsT && ... params )
	{
		return BufferReferenceT< BufferT >{ *this
			, std::move( name )
			, layout
			, storage
			, enabled
			, std::forward< ParamsT >( params )... };
	}
	/**@}*/
#pragma endregion
#pragma region Push constants buffer declaration
	/**
	*name
	*	Push constants buffer declaration.
	*/
	/**@{*/
	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declPushConstantsBuffer( std::string name
		, ast::type::MemoryLayout layout
		, bool enabled
		, ParamsT && ... params )
	{
		return T{ *this
			, std::move( name )
			, layout
			, enabled
			, std::forward< ParamsT >( params )... };
	}
	/**@}*/
#pragma endregion
#pragma region Struct declaration
	/**
	*name
	*	Struct declaration.
	*/
	/**@{*/
	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declStruct( std::string name
		, ast::type::MemoryLayout layout
		, ParamsT && ... params )
	{
		return T{ *this
			, std::move( name )
			, layout
			, std::forward< ParamsT >( params )... };
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
	inline InstanceT ShaderWriter::declLocale( std::string name
		, Struct const & type
		, bool enabled )
	{
		return type.getInstance< InstanceT >( std::move( name ), enabled );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string name
		, bool enabled )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerLocale( std::move( name )
			, type );

		if ( enabled )
		{
			addStmt( makeVariableDecl( getStmtCache(), var ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string name
		, T const & rhs )
	{
		return declLocale( std::move( name ), rhs, rhs.isEnabled() );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string name
		, T const & rhs
		, bool enabled )
	{
		auto type = rhs.getType();
		auto var = registerLocale( std::move( name )
			, type );
		enabled = enabled && isOptionalEnabled( rhs );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeExpr( *this, rhs ) ) ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declLocale( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto type = T::makeType( getTypesCache(), std::forward< ParamsT >( params )... );
		auto var = registerLocale( std::move( name )
			, type );

		if ( enabled )
		{
			addStmt( makeVariableDecl( getStmtCache(), var ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string name
		, bool enabled
		, T const & defaultValue )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerLocale( std::move( name )
			, type );

		if ( !enabled )
		{
			addStmt( makeVariableDecl( getStmtCache(), var ) );
		}
		else
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, true };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( std::move( name )
			, type );

		if ( enabled )
		{
			addStmt( makeVariableDecl( getStmtCache(), var ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string name
		, uint32_t dimension
		, std::vector< T > const & rhs
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( std::move( name )
			, type );
		enabled = enabled && std::all_of( rhs.begin()
			, rhs.end()
			, []( T const & v )
			{
				return isOptionalEnabled( v );
			} );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeAggrInit( var
					, makeExpr( *this, rhs ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocale( std::string name
		, Array< T > const & rhs )
	{
		return declLocale( std::move( name ), rhs, rhs.isEnabled() );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocale( std::string name
		, Array< T > const & rhs
		, bool enabled )
	{
		auto type = rhs.getType();
		auto var = registerLocale( std::move( name )
			, type );
		enabled = enabled && isOptionalEnabled( rhs );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeExpr( *this, rhs ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string name
		, uint32_t dimension
		, bool enabled
		, std::vector< T > const & defaultValue )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerLocale( std::move( name )
			, type );

		if ( enabled )
		{
			addStmt( makeVariableDecl( getStmtCache(), var ) );
		}
		else
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeAggrInit( var
					, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, true };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string name
		, ReturnWrapperT< T > rhs
		, bool enabled )
	{
		enabled = enabled && areOptionalEnabled( rhs );
		return declLocale( std::move( name ), T{ std::move( rhs ) }, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string name
		, DefaultedT< T > rhs
		, bool enabled )
	{
		enabled = enabled && areOptionalEnabled( rhs );
		return declLocale( std::move( name ), T{ std::move( rhs ) }, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string name
		, bool enabled
		, ReturnWrapperT< T > defaultValue )
	{
		return declLocale( std::move( name ), enabled, T{ std::move( defaultValue ) } );
	}

	template< typename BaseT, typename DerivedT >
	inline std::unique_ptr< BaseT > ShaderWriter::declDerivedLocale( std::string name
		, bool enabled )
	{
		auto type = DerivedT::makeType( getTypesCache() );
		auto var = registerLocale( std::move( name )
			, type );

		if ( enabled )
		{
			addStmt( makeVariableDecl( getStmtCache(), var ) );
		}

		return std::make_unique< DerivedT >( *this
			, makeExpr( *this, var )
			, enabled );
	}
	/**@}*/
#pragma endregion
#pragma region Global variables declaration
	/**
	*name
	*	Global variables declaration.
	*/
	/**@{*/
	template< typename InstanceT >
	inline InstanceT ShaderWriter::declGlobal( std::string name
		, Struct const & type
		, bool enabled )
	{
		return type.getInstance< InstanceT >( std::move( name ), enabled );
	}

	template< typename T >
	inline T ShaderWriter::declGlobal( std::string name
		, bool enabled )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( getStmtCache(), var ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declGlobal( std::string name
		, T const & rhs )
	{
		return declGlobal( std::move( name ), rhs, rhs.isEnabled() );
	}

	template< typename T >
	inline T ShaderWriter::declGlobal( std::string name
		, T const & rhs
		, bool enabled )
	{
		auto type = rhs.getType();
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );
		enabled = enabled && isOptionalEnabled( rhs );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeExpr( *this, rhs ) ) ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T, typename ... ParamsT >
	inline T ShaderWriter::declGlobal( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto type = T::makeType( getTypesCache(), std::forward< ParamsT >( params )... );
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( getStmtCache(), var ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declGlobal( std::string name
		, bool enabled
		, T const & defaultValue )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );

		if ( !enabled )
		{
			addStmt( sdw::makeVariableDecl( getStmtCache(), var ) );
		}
		else
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, true };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declGlobalArray( std::string name
		, uint32_t dimension
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( getStmtCache(), var ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declGlobalArray( std::string name
		, uint32_t dimension
		, std::vector< T > const & rhs
		, bool enabled )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );
		enabled = enabled && std::all_of( rhs.begin()
			, rhs.end()
			, []( T const & v )
			{
				return isOptionalEnabled( v );
			} );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeAggrInit( var
					, makeExpr( *this, rhs ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declGlobal( std::string name
		, Array< T > const & rhs )
	{
		return declGlobal( std::move( name ), rhs, rhs.isEnabled() );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declGlobal( std::string name
		, Array< T > const & rhs
		, bool enabled )
	{
		auto type = rhs.getType();
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );
		enabled = enabled && isOptionalEnabled( rhs );

		if ( enabled )
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeInit( var
					, makeExpr( *this, rhs ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declGlobalArray( std::string name
		, uint32_t dimension
		, bool enabled
		, std::vector< T > const & defaultValue )
	{
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( getStmtCache(), var ) );
		}
		else
		{
			addStmt( sdw::makeSimple( getStmtCache()
				, sdw::makeAggrInit( var
					, makeConstExpr( *this, defaultValue ) ) ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, true };
	}

	template< typename T >
	inline T ShaderWriter::declGlobal( std::string name
		, ReturnWrapperT< T > rhs
		, bool enabled )
	{
		enabled = enabled && areOptionalEnabled( rhs );
		return declGlobal( std::move( name ), T{ std::move( rhs ) }, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declGlobal( std::string name
		, DefaultedT< T > rhs
		, bool enabled )
	{
		enabled = enabled && areOptionalEnabled( rhs );
		return declGlobal( std::move( name ), T{ std::move( rhs ) }, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declGlobal( std::string name
		, bool enabled
		, ReturnWrapperT< T > defaultValue )
	{
		return declGlobal( std::move( name ), enabled, T{ std::move( defaultValue ) } );
	}

	template< typename BaseT, typename DerivedT >
	inline std::unique_ptr< BaseT > ShaderWriter::declDerivedGlobal( std::string name
		, bool enabled )
	{
		auto type = DerivedT::makeType( getTypesCache() );
		auto var = registerName( std::move( name )
			, type
			, uint64_t( ast::var::Flag::eStatic ) );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( getStmtCache(), var ) );
		}

		return std::make_unique< DerivedT >( *this
			, makeExpr( *this, var )
			, enabled );
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
				text += "Var type [" + debug::getTypeName( varType ) + "] and expected type [" + debug::getTypeName( resultType ) + "] don't match";
				throw ast::Exception{ text };
			}
		}
	}
	/**
	*name
	*	Already declared variable getters.
	*/
	/**@{*/
	template< typename T >
	inline T ShaderWriter::getVariable( std::string_view name
		, bool enabled )
	{
		auto var = hasVariable( name, true )
			? getVariable( name, true )
			: getVariable( name, false );

		T result{ *this
			, makeExpr( *this, var )
			, enabled };
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}

	template< typename T >
	inline Array< T > ShaderWriter::getVariableArray( std::string_view name
		, bool enabled )
	{
		auto var = hasVariable( name, true )
			? getVariable( name, true )
			: getVariable( name, false );

		Array< T > result{ *this
			, makeExpr( *this, var )
			, enabled };
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}
	/**@}*/
#pragma endregion
}
