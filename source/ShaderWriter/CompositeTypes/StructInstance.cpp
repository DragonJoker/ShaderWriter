/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

#include "ShaderWriter/BaseTypes/Boolean.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/BaseTypes/Double.hpp"
#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"
#include "ShaderWriter/VecTypes/Vec2.hpp"
#include "ShaderWriter/VecTypes/Vec3.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"
#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

#include <ShaderAST/ShaderBuilder.hpp>

namespace sdw
{
	//*********************************************************************************************

	namespace structinst
	{
		template< typename Func >
		void traverseType( ast::type::TypePtr type
			, ast::expr::ExprPtr & result
			, Func func )
		{
			auto arrayDim = getArraySize( type );

			switch ( type->getRawKind() )
			{
			case ast::type::Kind::eArray:
				if ( arrayDim == ast::type::UnknownArraySize )
				{
					throw ast::Exception{ "Can't provide a default value for given type" };
				}

				if ( arrayDim > 1u )
				{
					ast::expr::ExprList inits;
					auto arrayType = getNonArrayType( type );

					for ( uint32_t i = 0u; i < arrayDim; ++i )
					{
						ast::expr::ExprPtr init;
						traverseType( arrayType, init, func );
						inits.emplace_back( std::move( init ) );
					}

					result = sdw::makeAggrInit( type, std::move( inits ) );
				}
				else
				{
					traverseType( getNonArrayType( type ), result, func );
				}
				break;
			case ast::type::Kind::eStruct:
			case ast::type::Kind::eRayDesc:
				if ( auto structType = getStructType( type ) )
				{
					ast::expr::ExprList inits;

					for ( auto & mbr : *structType )
					{
						ast::expr::ExprPtr init;
						traverseType( mbr.type, init, func );
						inits.emplace_back( std::move( init ) );
					}

					result = sdw::makeAggrInit( type, std::move( inits ) );
				}
				break;
			case ast::type::Kind::eRayPayload:
				traverseType( static_cast< ast::type::RayPayload const & >( *type ).getDataType(), result, func );
				break;
			case ast::type::Kind::eCallableData:
				traverseType( static_cast< ast::type::CallableData const & >( *type ).getDataType(), result, func );
				break;
			case ast::type::Kind::eHitAttribute:
				traverseType( static_cast< ast::type::HitAttribute const & >( *type ).getDataType(), result, func );
				break;
			case ast::type::Kind::ePointer:
				traverseType( static_cast< ast::type::Pointer const & >( *type ).getPointerType(), result, func );
				break;
			case ast::type::Kind::eGeometryInput:
				traverseType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eGeometryOutput:
				traverseType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTessellationInputPatch:
				traverseType( static_cast< ast::type::TessellationInputPatch const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTessellationOutputPatch:
				traverseType( static_cast< ast::type::TessellationOutputPatch const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTessellationControlInput:
				traverseType( static_cast< ast::type::TessellationControlInput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTessellationControlOutput:
				traverseType( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTessellationEvaluationInput:
				traverseType( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eFragmentInput:
				traverseType( static_cast< ast::type::FragmentInput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eComputeInput:
				traverseType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eMeshVertexOutput:
				traverseType( static_cast< ast::type::MeshVertexOutput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eMeshPrimitiveOutput:
				traverseType( static_cast< ast::type::MeshPrimitiveOutput const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTaskPayloadNV:
				traverseType( static_cast< ast::type::TaskPayloadNV const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTaskPayload:
				traverseType( static_cast< ast::type::TaskPayload const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTaskPayloadInNV:
				traverseType( static_cast< ast::type::TaskPayloadInNV const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eTaskPayloadIn:
				traverseType( static_cast< ast::type::TaskPayloadIn const & >( *type ).getType(), result, func );
				break;
			case ast::type::Kind::eVoid:
			case ast::type::Kind::eUndefined:
			case ast::type::Kind::eHalf:
			case ast::type::Kind::eVec2H:
			case ast::type::Kind::eVec4H:
			case ast::type::Kind::eFunction:
			case ast::type::Kind::eSampler:
			case ast::type::Kind::eImage:
			case ast::type::Kind::eCombinedImage:
			case ast::type::Kind::eSampledImage:
			case ast::type::Kind::eAccelerationStructure:
				throw ast::Exception{ "Can't provide a default value for given type" };
				break;
			default:
				result = func( type );
				break;
			}
		}
	}

	//*********************************************************************************************

	ast::expr::ExprPtr getZeroValue( ast::type::TypePtr ptype )
	{
		ast::expr::ExprPtr presult;
		structinst::traverseType( ptype, presult
			, []( ast::type::TypePtr type ) -> ast::expr::ExprPtr
			{
				switch ( type->getRawKind() )
				{
				case ast::type::Kind::eBoolean:
					return makeExpr( 0_b );
				case ast::type::Kind::eInt8:
					return makeExpr( 0_i8 );
				case ast::type::Kind::eInt16:
					return makeExpr( 0_i16 );
				case ast::type::Kind::eInt32:
					return makeExpr( 0_i32 );
				case ast::type::Kind::eInt64:
					return makeExpr( 0_i64 );
				case ast::type::Kind::eUInt8:
					return makeExpr( 0_u8 );
				case ast::type::Kind::eUInt16:
					return makeExpr( 0_u16 );
				case ast::type::Kind::eUInt32:
					return makeExpr( 0_u32 );
				case ast::type::Kind::eUInt64:
					return makeExpr( 0_u64 );
				case ast::type::Kind::eFloat:
					return makeExpr( 0.0_f );
				case ast::type::Kind::eDouble:
					return makeExpr( 0.0_d );
				case ast::type::Kind::eVec2B:
					return makeExpr( bvec2( 0_b ) );
				case ast::type::Kind::eVec3B:
					return makeExpr( bvec3( 0_b ) );
				case ast::type::Kind::eVec4B:
					return makeExpr( bvec4( 0_b ) );
				case ast::type::Kind::eVec2I8:
					return makeExpr( i8vec2( 0_i8 ) );
				case ast::type::Kind::eVec3I8:
					return makeExpr( i8vec3( 0_i8 ) );
				case ast::type::Kind::eVec4I8:
					return makeExpr( i8vec4( 0_i8 ) );
				case ast::type::Kind::eVec2I16:
					return makeExpr( i16vec2( 0_i16 ) );
				case ast::type::Kind::eVec3I16:
					return makeExpr( i16vec3( 0_i16 ) );
				case ast::type::Kind::eVec4I16:
					return makeExpr( i16vec4( 0_i16 ) );
				case ast::type::Kind::eVec2I32:
					return makeExpr( i32vec2( 0_i32 ) );
				case ast::type::Kind::eVec3I32:
					return makeExpr( i32vec3( 0_i32 ) );
				case ast::type::Kind::eVec4I32:
					return makeExpr( i32vec4( 0_i32 ) );
				case ast::type::Kind::eVec2I64:
					return makeExpr( i64vec2( 0_i64 ) );
				case ast::type::Kind::eVec3I64:
					return makeExpr( i64vec3( 0_i64 ) );
				case ast::type::Kind::eVec4I64:
					return makeExpr( i64vec4( 0_i64 ) );
				case ast::type::Kind::eVec2U8:
					return makeExpr( u8vec2( 0_u8 ) );
				case ast::type::Kind::eVec3U8:
					return makeExpr( u8vec3( 0_u8 ) );
				case ast::type::Kind::eVec4U8:
					return makeExpr( u8vec4( 0_u8 ) );
				case ast::type::Kind::eVec2U16:
					return makeExpr( u16vec2( 0_u16 ) );
				case ast::type::Kind::eVec3U16:
					return makeExpr( u16vec3( 0_u16 ) );
				case ast::type::Kind::eVec4U16:
					return makeExpr( u16vec4( 0_u16 ) );
				case ast::type::Kind::eVec2U32:
					return makeExpr( u32vec2( 0_u32 ) );
				case ast::type::Kind::eVec3U32:
					return makeExpr( u32vec3( 0_u32 ) );
				case ast::type::Kind::eVec4U32:
					return makeExpr( u32vec4( 0_u32 ) );
				case ast::type::Kind::eVec2U64:
					return makeExpr( u64vec2( 0_u64 ) );
				case ast::type::Kind::eVec3U64:
					return makeExpr( u64vec3( 0_u64 ) );
				case ast::type::Kind::eVec4U64:
					return makeExpr( u64vec4( 0_u64 ) );
				case ast::type::Kind::eVec2F:
					return makeExpr( vec2( 0.0_f ) );
				case ast::type::Kind::eVec3F:
					return makeExpr( vec3( 0.0_f ) );
				case ast::type::Kind::eVec4F:
					return makeExpr( vec4( 0.0_f ) );
				case ast::type::Kind::eVec2D:
					return makeExpr( dvec2( 0.0_d ) );
				case ast::type::Kind::eVec3D:
					return makeExpr( dvec3( 0.0_d ) );
				case ast::type::Kind::eVec4D:
					return makeExpr( dvec4( 0.0_d ) );
				case ast::type::Kind::eMat2x2F:
					return makeExpr( mat2x2( vec2( 0.0_f ), vec2( 0.0_f ) ) );
				case ast::type::Kind::eMat2x3F:
					return makeExpr( mat2x3( vec2( 0.0_f ), vec2( 0.0_f ), vec2( 0.0_f ) ) );
				case ast::type::Kind::eMat2x4F:
					return makeExpr( mat2x4( vec2( 0.0_f ), vec2( 0.0_f ), vec2( 0.0_f ), vec2( 0.0_f ) ) );
				case ast::type::Kind::eMat3x2F:
					return makeExpr( mat3x2( vec3( 0.0_f ), vec3( 0.0_f ) ) );
				case ast::type::Kind::eMat3x3F:
					return makeExpr( mat3x3( vec3( 0.0_f ), vec3( 0.0_f ), vec3( 0.0_f ) ) );
				case ast::type::Kind::eMat3x4F:
					return makeExpr( mat3x4( vec3( 0.0_f ), vec3( 0.0_f ), vec3( 0.0_f ), vec3( 0.0_f ) ) );
				case ast::type::Kind::eMat4x2F:
					return makeExpr( mat4x2( vec4( 0.0_f ), vec4( 0.0_f ) ) );
				case ast::type::Kind::eMat4x3F:
					return makeExpr( mat4x3( vec4( 0.0_f ), vec4( 0.0_f ), vec4( 0.0_f ) ) );
				case ast::type::Kind::eMat4x4F:
					return makeExpr( mat4x4( vec4( 0.0_f ), vec4( 0.0_f ), vec4( 0.0_f ), vec4( 0.0_f ) ) );
				case ast::type::Kind::eMat2x2D:
					return makeExpr( dmat2x2( dvec2( 0.0_d ), dvec2( 0.0_d ) ) );
				case ast::type::Kind::eMat2x3D:
					return makeExpr( dmat2x3( dvec2( 0.0_d ), dvec2( 0.0_d ), dvec2( 0.0_d ) ) );
				case ast::type::Kind::eMat2x4D:
					return makeExpr( dmat2x4( dvec2( 0.0_d ), dvec2( 0.0_d ), dvec2( 0.0_d ), dvec2( 0.0_d ) ) );
				case ast::type::Kind::eMat3x2D:
					return makeExpr( dmat3x2( dvec3( 0.0_d ), dvec3( 0.0_d ) ) );
				case ast::type::Kind::eMat3x3D:
					return makeExpr( dmat3x3( dvec3( 0.0_d ), dvec3( 0.0_d ), dvec3( 0.0_d ) ) );
				case ast::type::Kind::eMat3x4D:
					return makeExpr( dmat3x4( dvec3( 0.0_d ), dvec3( 0.0_d ), dvec3( 0.0_d ), dvec3( 0.0_d ) ) );
				case ast::type::Kind::eMat4x2D:
					return makeExpr( dmat4x2( dvec4( 0.0_d ), dvec4( 0.0_d ) ) );
				case ast::type::Kind::eMat4x3D:
					return makeExpr( dmat4x3( dvec4( 0.0_d ), dvec4( 0.0_d ), dvec4( 0.0_d ) ) );
				case ast::type::Kind::eMat4x4D:
					return makeExpr( dmat4x4( dvec4( 0.0_d ), dvec4( 0.0_d ), dvec4( 0.0_d ), dvec4( 0.0_d ) ) );
				default:
					return nullptr;
				}
			} );
		return presult;
	}

	Boolean getBoolMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Boolean >( builtin );
	}

	Int8 getInt8Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int8 >( builtin );
	}

	Int16 getInt16Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int16 >( builtin );
	}

	Int32 getInt32Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int32 >( builtin );
	}

	Int64 getInt64Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Int64 >( builtin );
	}

	Int32 getIntMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getInt32Member( instance, builtin );
	}

	UInt8 getUInt8Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt8 >( builtin );
	}

	UInt16 getUInt16Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt16 >( builtin );
	}

	UInt32 getUInt32Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt32 >( builtin );
	}

	UInt64 getUInt64Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< UInt64 >( builtin );
	}

	UInt32 getUIntMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getUInt32Member( instance, builtin );
	}

	Float getFloatMember( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Float >( builtin );
	}

	Vec2 getVec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Vec2 >( builtin );
	}

	Vec3 getVec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Vec3 >( builtin );
	}

	Vec4 getVec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Vec4 >( builtin );
	}

	U8Vec2 getU8Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U8Vec2 >( builtin );
	}

	U8Vec3 getU8Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U8Vec3 >( builtin );
	}

	U8Vec4 getU8Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U8Vec4 >( builtin );
	}

	U16Vec2 getU16Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U16Vec2 >( builtin );
	}

	U16Vec3 getU16Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U16Vec3 >( builtin );
	}

	U16Vec4 getU16Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U16Vec4 >( builtin );
	}

	U32Vec2 getU32Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U32Vec2 >( builtin );
	}

	U32Vec3 getU32Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U32Vec3 >( builtin );
	}

	U32Vec4 getU32Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U32Vec4 >( builtin );
	}

	U64Vec2 getU64Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U64Vec2 >( builtin );
	}

	U64Vec3 getU64Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U64Vec3 >( builtin );
	}

	U64Vec4 getU64Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< U64Vec4 >( builtin );
	}

	U32Vec2 getUVec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getU32Vec2Member( instance, builtin );
	}

	U32Vec3 getUVec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getU32Vec3Member( instance, builtin );
	}

	U32Vec4 getUVec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getU32Vec4Member( instance, builtin );
	}

	I8Vec2 getI8Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I8Vec2 >( builtin );
	}

	I8Vec3 getI8Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I8Vec3 >( builtin );
	}

	I8Vec4 getI8Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I8Vec4 >( builtin );
	}

	I16Vec2 getI16Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I16Vec2 >( builtin );
	}

	I16Vec3 getI16Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I16Vec3 >( builtin );
	}

	I16Vec4 getI16Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I16Vec4 >( builtin );
	}

	I32Vec2 getI32Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I32Vec2 >( builtin );
	}

	I32Vec3 getI32Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I32Vec3 >( builtin );
	}

	I32Vec4 getI32Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I32Vec4 >( builtin );
	}

	I64Vec2 getI64Vec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I64Vec2 >( builtin );
	}

	I64Vec3 getI64Vec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I64Vec3 >( builtin );
	}

	I64Vec4 getI64Vec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< I64Vec4 >( builtin );
	}

	I32Vec2 getIVec2Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getI32Vec2Member( instance, builtin );
	}

	I32Vec3 getIVec3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getI32Vec3Member( instance, builtin );
	}

	I32Vec4 getIVec4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return getI32Vec4Member( instance, builtin );
	}

	Mat4x3 getMat4x3Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Mat4x3 >( builtin );
	}

	Mat3x4 getMat3x4Member( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMember< Mat3x4 >( builtin );
	}

	Array< Int32 > getIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Int32 >( builtin );
	}

	Array< UInt32 > getUIntMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< UInt32 >( builtin );
	}

	Array< Float > getFloatMemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Float >( builtin );
	}

	Array< Vec4 > getVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Vec4 >( builtin );
	}

	Array< I32Vec2 > getIVec2MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< I32Vec2 >( builtin );
	}

	Array< I32Vec3 > getIVec3MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< I32Vec3 >( builtin );
	}

	Array< I32Vec4 > getIVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< I32Vec4 >( builtin );
	}

	Array< U32Vec2 > getUVec2MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< U32Vec2 >( builtin );
	}

	Array< U32Vec3 > getUVec3MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< U32Vec3 >( builtin );
	}

	Array< U32Vec4 > getUVec4MemberArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< U32Vec4 >( builtin );
	}

	Array< Array< Int32 > > getIntMemberArrayArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Array< Int32 > >( builtin );
	}

	Array< Array< Float > > getFloatMemberArrayArray( StructInstance const & instance
		, ast::Builtin builtin )
	{
		return instance.getMemberArray< Array< Float > >( builtin );
	}

	//*********************************************************************************************

	StructInstance::StructInstance( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_type{ getStructType( getType() ) }
	{
		assert( m_type != nullptr && "Non structure type ?" );
	}

	ast::expr::ExprPtr StructInstance::makeInitExpr( ast::type::StructPtr type
		, StructInstance const * rhs )
	{
		if ( !rhs )
		{
			sdw::expr::ExprList initializers;

			for ( size_t index{}; index < type->size(); ++index )
			{
				auto lhsMbr = type->getMember( uint32_t( index ) );
				initializers.emplace_back( getZeroValue( lhsMbr.type ) );
			}

			return sdw::makeAggrInit( type, std::move( initializers ) );
		}

		if ( type == rhs->m_type )
		{
			return sdw::makeExpr( *rhs );
		}

		sdw::expr::ExprList initializers;
		auto rhsType = rhs->m_type;

		for ( size_t index{}; index < type->size(); ++index )
		{
			auto lhsMbr = type->getMember( uint32_t( index ) );
			auto rhsIdx = rhsType->findMember( lhsMbr.name );

			if ( rhsIdx != ast::type::Struct::NotFound )
			{
				initializers.emplace_back( rhs->doGetMember( rhsIdx ) );
			}
			else
			{
				initializers.emplace_back( getZeroValue( lhsMbr.type ) );
			}
		}

		return sdw::makeAggrInit( type, std::move( initializers ) );
	}

	ast::expr::ExprPtr StructInstance::doGetMember( uint32_t mbrIndex )const
	{
		assert( m_type->getKind() == type::Kind::eStruct
			|| m_type->getKind() == type::Kind::eRayDesc );
		auto mbrFlags = m_type->getFlag();

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchOutput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderOutput;
		}

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchInput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderInput;
		}

		auto member = m_type->getMember( mbrIndex );

		if ( mbrFlags )
		{
			auto & shader = getBuilder();

			if ( checkFlag( mbrFlags, ast::var::Flag::eShaderInput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					shader.registerInput( m_type->getEntryPoint()
						, "in::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
			else if ( checkFlag( mbrFlags, ast::var::Flag::eShaderOutput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					shader.registerOutput( m_type->getEntryPoint()
						, "out::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
		}

		auto const & writer = findWriterMandat( *this );
		return sdw::makeMbrSelect( makeExpr( writer, *this )
			, member.type->getIndex()
			, mbrFlags );
	}

	//*********************************************************************************************
}
