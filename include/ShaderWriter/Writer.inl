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
#pragma region Type registration
	/**
	*name
	*	Type registration
	*/
	/**@{*/
	template< typename TypeT >
	inline type::StructPtr ShaderWriter::declType()
	{
		auto result = TypeT::makeType( getTypesCache() );
		addGlobalStmt( sdw::makeStructDecl( result ) );
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
		return implementFunction< ReturnT >( name
			, ast::stmt::FunctionFlag::eNone
			, function
			, std::forward< ParamsT >( params )... );
	}

	template< typename ReturnT, typename ... ParamsT >
	inline Function< ReturnT, ParamsT... > ShaderWriter::implementFunction( std::string const & name
		, ast::stmt::FunctionFlag flag
		, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
		, ParamsT && ... params )
	{
		ast::var::VariableList args;
		auto decl = getFunctionHeader< ReturnT >( *this, args, name, flag, params... );
		doPushScope( decl.get(), args );
		details::doUpdateParams( decl->getType(), params... );
		function( params... );
		doPopScope();
		auto functionType = decl->getType();
		addGlobalStmt( std::move( decl ) );
		return Function< ReturnT, ParamsT... >{ *this, functionType, name };
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
			, std::enable_if_t< isSameComponentCountV< DstT, SrcT > && !IsSameV< DstT, SrcT > > >
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
				, std::move( right ) )
			, areOptionalEnabled( condition, left, right ) };
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
	inline T ShaderWriter::declConstant( std::string const & name
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

		return T{ *this
			, makeConstExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declConstantArray( std::string const & name
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

		return Array< T >{ *this
			, makeConstExpr( *this, var )
			, enabled };
	}

	template< ast::type::Kind KindT >
	inline IntegerValue< KindT > ShaderWriter::declConstant( std::string const & name
		, ReturnWrapperT< IntegerValue< KindT > > rhs
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

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
		inline T ShaderWriter::declSampledImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled )
	{
		return declSampledImage < T::Format
			, T::Dim
			, T::Arrayed
			, T::Depth
			, T::Ms > ( name
				, binding
				, set
				, enabled );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		inline Array< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > ShaderWriter::declSampledImageArray( std::string const & name
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

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
		inline Array< T > ShaderWriter::declSampledImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled )
	{
		return declSampledImageArray < T::Format
			, T::Dim
			, T::Arrayed
			, T::Depth
			, T::Ms > ( name
				, binding
				, set
				, dimension
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
		, bool DepthT
		, bool MsT >
		inline ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > ShaderWriter::declImage( std::string const & name
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

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
		inline T ShaderWriter::declImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled )
	{
		return declImage < T::Format
			, T::Access
			, T::Dim
			, T::Arrayed
			, T::Depth
			, T::Ms > ( name
				, binding
				, set
				, enabled );
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

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
		inline Array< T > ShaderWriter::declImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled )
	{
		return declImageArray < T::Format
			, T::Access
			, T::Dim
			, T::Arrayed
			, T::Depth
			, T::Ms > ( name
				, binding
				, set
				, dimension
				, enabled );
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
		, uint32_t location
		, bool enabled )
	{
		return declInput< T >( name
			, location
			, 0u
			, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declInput( std::string const & name
		, uint32_t location
		, uint64_t attributes
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

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
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
	inline Array< T > ShaderWriter::declInputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, uint64_t attributes
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

		return Array< T >{ *this
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
		, uint64_t attributes
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
			, makeExpr( *this, var )
			, true };
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
		, uint64_t attributes
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
			, makeExpr( *this, var )
			, true };
	}
	/**@}*/
#pragma endregion
#pragma region Ray payload declaration
	/**
	*name
	*	Ray payload declaration.
	*/
	/**@{*/
	template< typename T >
	inline RayPayloadT< T > ShaderWriter::declRayPayload( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = RayPayloadT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( sdw::makeStructDecl( structType ) );
		}

		auto var = registerName( name
			, type
			, uint64_t( ast::var::Flag::eRayPayload ) );

		if ( enabled )
		{
			addStmt( sdw::makeInOutRayPayloadVariableDecl( var
				, location ) );
		}

		return RayPayloadT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline RayPayloadInT< T > ShaderWriter::declIncomingRayPayload( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = RayPayloadInT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( sdw::makeStructDecl( structType ) );
		}

		auto var = registerInOut( name
			, uint64_t( ast::var::Flag::eIncomingRayPayload )
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutRayPayloadVariableDecl( var
				, location ) );
		}

		return RayPayloadInT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline CallableDataT< T > ShaderWriter::declCallableData( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = CallableDataT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( sdw::makeStructDecl( structType ) );
		}

		auto var = registerName( name
			, type
			, uint64_t( ast::var::Flag::eCallableData ) );

		if ( enabled )
		{
			addStmt( sdw::makeInOutCallableDataVariableDecl( var
				, location ) );
		}

		return CallableDataT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline CallableDataInT< T > ShaderWriter::declIncomingCallableData( std::string const & name
		, uint32_t location
		, bool enabled )
	{
		auto type = CallableDataInT< T >::makeType( getTypesCache(), location );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( sdw::makeStructDecl( structType ) );
		}

		auto var = registerInOut( name
			, uint64_t( ast::var::Flag::eIncomingCallableData )
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeInOutCallableDataVariableDecl( var
				, location ) );
		}

		return CallableDataInT< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline HitAttributeT< T > ShaderWriter::declHitAttribute( std::string const & name
		, bool enabled )
	{
		auto type = T::makeType( getTypesCache() );

		if ( auto structType = getStructType( type ) )
		{
			addGlobalStmt( sdw::makeStructDecl( structType ) );
		}

		auto var = registerInOut( name
			, uint64_t( ast::var::Flag::eHitAttribute )
			, type );

		if ( enabled )
		{
			addGlobalStmt( sdw::makeHitAttributeVariableDecl( var ) );
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
	template< typename T >
	inline T ShaderWriter::declUniformBuffer( std::string const & name
		, uint32_t binding
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled )
	{
		return T{ *this, name, binding, set, layout, enabled };
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
		, ast::type::MemoryLayout layout
		, bool enabled )
	{
		return T{ *this, name, binding, set, layout, enabled };
	}

	template< typename T >
	inline ArraySsboT< T > ShaderWriter::declArrayShaderStorageBuffer( std::string const & name
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		return ArraySsboT< T >{ *this, name, binding, set, enabled };
	}
	/**@}*/
#pragma endregion
#pragma region Buffer reference declaration
	/**
	*name
	*	Buffer reference declaration.
	*/
	/**@{*/
	template< typename BufferT >
	inline BufferReferenceT< BufferT > ShaderWriter::declBufferReference( std::string const & name
		, ast::type::MemoryLayout layout
		, ast::type::Storage storage
		, bool enabled )
	{
		return BufferReferenceT< BufferT >{ *this, name, layout, storage, enabled };
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
		, ast::type::MemoryLayout layout
		, bool enabled )
	{
		return T{ *this, name, layout, enabled };
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
		, uint32_t location
		, bool enabled )
	{
		return declOutput< T >( name
			, location
			, 0u
			, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declOutput( std::string const & name
		, uint32_t location
		, uint64_t attributes
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

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declOutputArray( std::string const & name
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
	inline Array< T > ShaderWriter::declOutputArray( std::string const & name
		, uint32_t location
		, uint32_t dimension
		, uint64_t attributes
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

		return Array< T >{ *this
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
		, Struct const & type
		, bool enabled )
	{
		return type.getInstance< InstanceT >( name, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, bool enabled )
	{
		auto type = T::makeType( getTypesCache() );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, T const & rhs )
	{
		return declLocale( name, rhs, rhs.isEnabled() );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
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

		return T{ *this
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
			, makeExpr( *this, var )
			, true };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
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

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocaleArray( std::string const & name
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

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocale( std::string const & name
		, Array< T > const & rhs )
	{
		return declLocale( name, rhs, rhs.isEnabled() );
	}

	template< typename T >
	inline Array< T > ShaderWriter::declLocale( std::string const & name
		, Array< T > const & rhs
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

		return Array< T >{ *this
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
			, makeExpr( *this, var )
			, true };
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, ReturnWrapperT< T > rhs
		, bool enabled )
	{
		return declLocale( name, T{ std::move( rhs ) }, enabled );
	}

	template< typename T >
	inline T ShaderWriter::declLocale( std::string const & name
		, bool enabled
		, ReturnWrapperT< T > defaultValue )
	{
		return declLocale( name, enabled, T{ std::move( defaultValue ) } );
	}

	template< typename BaseT, typename DerivedT >
	inline std::unique_ptr< BaseT > ShaderWriter::declDerivedLocale( std::string const & name
		, bool enabled )
	{
		auto type = DerivedT::makeType( getTypesCache() );
		auto var = registerLocale( name
			, type );

		if ( enabled )
		{
			addStmt( sdw::makeVariableDecl( var ) );
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
	inline T ShaderWriter::getVariable( std::string const & name
		, bool enabled )
	{
		auto var = getVar( name );
		T result{ *this
			, makeExpr( *this, var )
			, enabled };
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}

	template< typename T >
	inline Array< T > ShaderWriter::getVariableArray( std::string const & name
		, bool enabled )
	{
		auto var = getVar( name );
		Array< T > result{ *this
			, makeExpr( *this, var )
			, enabled };
		details::checkTypes( var->getType(), result.getType() );
		return result;
	}
	/**@}*/
#pragma endregion
}
