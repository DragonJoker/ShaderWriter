/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeCache_H___
#define ___AST_TypeCache_H___
#pragma once

#include "Type.hpp"
#include "TypeAccelerationStructure.hpp"
#include "TypeArray.hpp"
#include "TypeCallableData.hpp"
#include "TypeCombinedImage.hpp"
#include "TypeComputeIO.hpp"
#include "TypeFragmentIO.hpp"
#include "TypeFunction.hpp"
#include "TypeGeometryIO.hpp"
#include "TypeHitAttribute.hpp"
#include "TypeImage.hpp"
#include "TypeMeshIO.hpp"
#include "TypePointer.hpp"
#include "TypeRayPayload.hpp"
#include "TypeSampledImage.hpp"
#include "TypeSampler.hpp"
#include "TypeStruct.hpp"
#include "TypeTaskIO.hpp"
#include "TypeTessellationControlIO.hpp"
#include "TypeTessellationEvaluationIO.hpp"

#include <array>
#include <functional>
#include <map>

namespace ast::type
{
	template< typename TypeT
		, typename CreatorT
		, typename HasherT >
	class TypeCache
	{
	private:
		using TypeTPtr = std::shared_ptr< TypeT >;

	public:
		inline TypeCache( CreatorT creator
			, HasherT hasher )
			: m_creator{ std::move( creator ) }
			, m_hasher{ std::move( hasher ) }
		{
		}

		template< typename ... ParamsT >
		inline TypeTPtr getType( ParamsT && ... params )
		{
			auto key = m_hasher( params... );
			auto it = m_cache.find( key );

			if ( it == m_cache.end() )
			{
				it = m_cache.emplace( key, m_creator( std::forward< ParamsT >( params )... ) ).first;
			}

			return it->second;
		}

	private:
		CreatorT m_creator;
		HasherT m_hasher;
		std::map< size_t, TypeTPtr > m_cache;
	};

	class TypesCache final
	{
	public:
		SDAST_API TypesCache();
		SDAST_API ~TypesCache() = default;
		SDAST_API TypePtr getUndefined();
		SDAST_API TypePtr getVoid();
		SDAST_API TypePtr getBool();
		SDAST_API TypePtr getBoolean();
		SDAST_API TypePtr getInt8();
		SDAST_API TypePtr getInt16();
		SDAST_API TypePtr getInt32();
		SDAST_API TypePtr getInt64();
		SDAST_API TypePtr getUInt8();
		SDAST_API TypePtr getUInt16();
		SDAST_API TypePtr getUInt32();
		SDAST_API TypePtr getUInt64();
		SDAST_API TypePtr getHalf();
		SDAST_API TypePtr getFloat();
		SDAST_API TypePtr getDouble();
		SDAST_API TypePtr getVec2B();
		SDAST_API TypePtr getVec3B();
		SDAST_API TypePtr getVec4B();
		SDAST_API TypePtr getVec2I8();
		SDAST_API TypePtr getVec3I8();
		SDAST_API TypePtr getVec4I8();
		SDAST_API TypePtr getVec2I16();
		SDAST_API TypePtr getVec3I16();
		SDAST_API TypePtr getVec4I16();
		SDAST_API TypePtr getVec2I32();
		SDAST_API TypePtr getVec3I32();
		SDAST_API TypePtr getVec4I32();
		SDAST_API TypePtr getVec2I64();
		SDAST_API TypePtr getVec3I64();
		SDAST_API TypePtr getVec4I64();
		SDAST_API TypePtr getVec2U8();
		SDAST_API TypePtr getVec3U8();
		SDAST_API TypePtr getVec4U8();
		SDAST_API TypePtr getVec2U16();
		SDAST_API TypePtr getVec3U16();
		SDAST_API TypePtr getVec4U16();
		SDAST_API TypePtr getVec2U32();
		SDAST_API TypePtr getVec3U32();
		SDAST_API TypePtr getVec4U32();
		SDAST_API TypePtr getVec2U64();
		SDAST_API TypePtr getVec3U64();
		SDAST_API TypePtr getVec4U64();
		SDAST_API TypePtr getVec2H();
		SDAST_API TypePtr getVec4H();
		SDAST_API TypePtr getVec2F();
		SDAST_API TypePtr getVec3F();
		SDAST_API TypePtr getVec4F();
		SDAST_API TypePtr getVec2D();
		SDAST_API TypePtr getVec3D();
		SDAST_API TypePtr getVec4D();
		SDAST_API TypePtr getMat2x2F();
		SDAST_API TypePtr getMat2x3F();
		SDAST_API TypePtr getMat2x4F();
		SDAST_API TypePtr getMat3x2F();
		SDAST_API TypePtr getMat3x3F();
		SDAST_API TypePtr getMat3x4F();
		SDAST_API TypePtr getMat4x2F();
		SDAST_API TypePtr getMat4x3F();
		SDAST_API TypePtr getMat4x4F();
		SDAST_API TypePtr getMat2x2D();
		SDAST_API TypePtr getMat2x3D();
		SDAST_API TypePtr getMat2x4D();
		SDAST_API TypePtr getMat3x2D();
		SDAST_API TypePtr getMat3x3D();
		SDAST_API TypePtr getMat3x4D();
		SDAST_API TypePtr getMat4x2D();
		SDAST_API TypePtr getMat4x3D();
		SDAST_API TypePtr getMat4x4D();
		SDAST_API TypePtr getBasicType( Kind kind );
		SDAST_API TypePtr getVec2Type( Kind kind );
		SDAST_API TypePtr getVec3Type( Kind kind );
		SDAST_API TypePtr getVec4Type( Kind kind );
		SDAST_API TypePtr getMat2Type( Kind kind );
		SDAST_API TypePtr getMat3Type( Kind kind );
		SDAST_API TypePtr getMat4Type( Kind kind );
		SDAST_API Kind getVec2Kind( Kind kind )const;
		SDAST_API Kind getVec3Kind( Kind kind )const;
		SDAST_API Kind getVec4Kind( Kind kind )const;
		SDAST_API Kind getMat2Kind( Kind kind )const;
		SDAST_API Kind getMat3Kind( Kind kind )const;
		SDAST_API Kind getMat4Kind( Kind kind )const;
		SDAST_API TypePtr getVector( Kind kind, uint32_t count );

		SDAST_API AccelerationStructurePtr getAccelerationStructure();
		SDAST_API HitAttributePtr getHitAttribute( TypePtr dataType );
		SDAST_API RayPayloadPtr getRayPayload( TypePtr dataType, uint32_t location );
		SDAST_API CallableDataPtr getCallableData( TypePtr dataType, uint32_t location );
		SDAST_API RayDescPtr getRayDesc();
		SDAST_API MeshVertexOutputPtr getMeshVertexOutput( TypePtr type, uint32_t maxVertices );
		SDAST_API MeshPrimitiveOutputPtr getMeshPrimitiveOutput( TypePtr type, OutputTopology topology, uint32_t maxPrimitives );
		SDAST_API TaskPayloadNVPtr getTaskPayloadNV( TypePtr type );
		SDAST_API TaskPayloadInNVPtr getTaskPayloadInNV( TypePtr type );
		SDAST_API TaskPayloadPtr getTaskPayload( TypePtr type );
		SDAST_API TaskPayloadInPtr getTaskPayloadIn( TypePtr type );
		SDAST_API ImagePtr getImage( ImageConfiguration func );
		SDAST_API SampledImagePtr getSampledImage( ImageConfiguration func, Trinary comparison = Trinary::eDontCare );
		SDAST_API CombinedImagePtr getCombinedImage( ImageConfiguration func, bool isComparison = false );
		SDAST_API SamplerPtr getSampler( bool comparison = false );
		SDAST_API TypePtr getSampledType( ImageFormat format );
		SDAST_API TypePtr getTexelType( ImageFormat format );
		SDAST_API FunctionPtr getFunction( TypePtr returnType, var::VariableList parameters );
		SDAST_API BaseStructPtr getStruct( MemoryLayout layout, std::string const & name );
		SDAST_API IOStructPtr getIOStruct( std::string name, ast::EntryPoint entryPoint, var::Flag flag );
		SDAST_API ArrayPtr getArray( TypePtr type, uint32_t arraySize = UnknownArraySize );

		SDAST_API TypePtr getMemberType( TypePtr type, Struct & parent, uint32_t memberIndex )const;
		SDAST_API Type const * getNonMemberType( TypePtr type )const;

		SDAST_API TypePtr getPointerType( TypePtr pointerType, Storage storage );
		SDAST_API TypePtr getForwardPointerType( TypePtr pointerType, Storage storage );

	private:
		std::array< TypePtr, size_t( Kind::eMax ) > m_basicTypes;
		AccelerationStructurePtr m_accelerationStructure;
		RayDescPtr m_rayDesc;
		TypeCache< Image, std::function< ImagePtr( ImageConfiguration ) >, std::function< size_t( ImageConfiguration const & ) > > m_image;
		TypeCache< CombinedImage, std::function< CombinedImagePtr( ImageConfiguration, bool ) >, std::function< size_t( ImageConfiguration const &, bool ) > > m_texture;
		TypeCache< SampledImage, std::function< SampledImagePtr( ImageConfiguration, Trinary ) >, std::function< size_t( ImageConfiguration const &, Trinary ) > > m_sampledImage;
		TypeCache< Sampler, std::function< SamplerPtr( bool ) >, std::function< size_t( bool ) > > m_sampler;
		TypeCache< Function, std::function< FunctionPtr( TypePtr, var::VariableList ) >, std::function< size_t( TypePtr, var::VariableList ) > > m_function;
		TypeCache< BaseStruct, std::function< BaseStructPtr( MemoryLayout, std::string ) >, std::function< size_t( MemoryLayout, std::string const & ) > > m_struct;
		TypeCache< IOStruct, std::function< IOStructPtr( MemoryLayout, std::string, EntryPoint, var::Flag ) >, std::function< size_t( MemoryLayout, std::string const &, EntryPoint, var::Flag ) > > m_inputStruct;
		TypeCache< IOStruct, std::function< IOStructPtr( MemoryLayout, std::string, EntryPoint, var::Flag ) >, std::function< size_t( MemoryLayout, std::string const &, EntryPoint, var::Flag ) > > m_outputStruct;
		TypeCache< Array, std::function< ArrayPtr( TypePtr, uint32_t ) >, std::function< size_t( TypePtr, uint32_t ) > > m_array;
		TypeCache< Pointer, std::function< PointerPtr( TypePtr, Storage, bool ) >, std::function< size_t( TypePtr, Storage, bool ) > > m_pointer;
		TypeCache< RayPayload, std::function< RayPayloadPtr( TypePtr, uint32_t ) >, std::function< size_t( TypePtr, uint32_t ) > > m_rayPayload;
		TypeCache< CallableData, std::function< CallableDataPtr( TypePtr, uint32_t ) >, std::function< size_t( TypePtr, uint32_t ) > > m_callableData;
		TypeCache< HitAttribute, std::function< HitAttributePtr( TypePtr ) >, std::function< size_t( TypePtr ) > > m_hitAttribute;
		TypeCache< MeshVertexOutput, std::function< MeshVertexOutputPtr( TypePtr, uint32_t ) >, std::function< size_t( TypePtr, uint32_t ) > > m_meshVertexOutput;
		TypeCache< MeshPrimitiveOutput, std::function< MeshPrimitiveOutputPtr( TypePtr, OutputTopology, uint32_t ) >, std::function< size_t( TypePtr, OutputTopology, uint32_t ) > > m_meshPrimitiveOutput;
		TypeCache< TaskPayloadNV, std::function< TaskPayloadNVPtr( TypePtr ) >, std::function< size_t( TypePtr ) > > m_taskPayloadNV;
		TypeCache< TaskPayloadInNV, std::function< TaskPayloadInNVPtr( TypePtr ) >, std::function< size_t( TypePtr ) > > m_taskPayloadInNV;
		TypeCache< TaskPayload, std::function< TaskPayloadPtr( TypePtr ) >, std::function< size_t( TypePtr ) > > m_taskPayload;
		TypeCache< TaskPayloadIn, std::function< TaskPayloadInPtr( TypePtr ) >, std::function< size_t( TypePtr ) > > m_taskPayloadIn;
		struct MemberTypeInfo
		{
			TypePtr nonMemberType;
			TypePtr parent;
			uint32_t memberIndex;
		};
		std::map< TypePtr, MemberTypeInfo > m_memberTypes;
	};

	template< typename Func >
	void traverseType( ast::type::TypePtr type
		, uint32_t arrayDim
		, Func func )
	{
		switch ( type->getRawKind() )
		{
		case ast::type::Kind::eArray:
			traverseType( getNonArrayType( type )
				, getArraySize( type ) * ( ( arrayDim == NotArray || arrayDim == UnknownArraySize )
					? 1u
					: arrayDim )
				, func );
			break;
		case ast::type::Kind::eFunction:
			{
				auto & funcType = static_cast< Function const & >( *type );
				traverseType( funcType.getReturnType(), arrayDim, func );

				for ( auto & arg : funcType )
				{
					traverseType( arg->getType(), arrayDim, func );
				}
			}
			break;
		case ast::type::Kind::eStruct:
		case ast::type::Kind::eRayDesc:
			if ( auto structType = getStructType( type ) )
			{
				for ( auto & mbr : *structType )
				{
					traverseType( mbr.type, arrayDim, func );
				}
			}
			break;
		case ast::type::Kind::eRayPayload:
			traverseType( static_cast< ast::type::RayPayload const & >( *type ).getDataType(), arrayDim, func );
			break;
		case ast::type::Kind::eCallableData:
			traverseType( static_cast< ast::type::CallableData const & >( *type ).getDataType(), arrayDim, func );
			break;
		case ast::type::Kind::eHitAttribute:
			traverseType( static_cast< ast::type::HitAttribute const & >( *type ).getDataType(), arrayDim, func );
			break;
		case ast::type::Kind::ePointer:
			traverseType( static_cast< ast::type::Pointer const & >( *type ).getPointerType(), arrayDim, func );
			break;
		case ast::type::Kind::eGeometryInput:
			traverseType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eGeometryOutput:
			traverseType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTessellationInputPatch:
			traverseType( static_cast< ast::type::TessellationInputPatch const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTessellationOutputPatch:
			traverseType( static_cast< ast::type::TessellationOutputPatch const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTessellationControlInput:
			traverseType( static_cast< ast::type::TessellationControlInput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTessellationControlOutput:
			traverseType( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTessellationEvaluationInput:
			traverseType( static_cast< ast::type::TessellationControlOutput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eFragmentInput:
			traverseType( static_cast< ast::type::FragmentInput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eComputeInput:
			traverseType( static_cast< ast::type::ComputeInput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eMeshVertexOutput:
			traverseType( static_cast< ast::type::MeshVertexOutput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eMeshPrimitiveOutput:
			traverseType( static_cast< ast::type::MeshPrimitiveOutput const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTaskPayloadNV:
			traverseType( static_cast< ast::type::TaskPayloadNV const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTaskPayload:
			traverseType( static_cast< ast::type::TaskPayload const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTaskPayloadInNV:
			traverseType( static_cast< ast::type::TaskPayloadInNV const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eTaskPayloadIn:
			traverseType( static_cast< ast::type::TaskPayloadIn const & >( *type ).getType(), arrayDim, func );
			break;
		case ast::type::Kind::eVoid:
		case ast::type::Kind::eUndefined:
			break;
		default:
			func( type, arrayDim );
			break;
		}
	}
}

#endif
