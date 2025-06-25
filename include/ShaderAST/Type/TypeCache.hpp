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
		, typename ... BaseParamsT >
	class TypeCache
	{
	private:
		using TypeTPtr = std::unique_ptr< TypeT >;
		using TypeRPtr = TypeT *;
		using CreatorT = std::function< TypeTPtr( BaseParamsT ... ) >;
		using HasherT = std::function< size_t( BaseParamsT ... ) >;

	public:
		inline TypeCache( CreatorT creator
			, HasherT hasher )
			: m_creator{ std::move( creator ) }
			, m_hasher{ std::move( hasher ) }
		{
		}

		inline TypeRPtr getType( BaseParamsT ... params )
		{
			auto key = m_hasher( params... );
			auto [it, inserted] = m_cache.try_emplace( key, nullptr );
			if ( inserted )
				it->second = m_creator( params... );
			return it->second.get();
		}

		template< typename ... ParamsT >
		inline TypeRPtr registerType( BaseParamsT ... params
			, ParamsT && ... ctorParams )
		{
			auto key = m_hasher( params... );
			auto [it, inserted] = m_cache.try_emplace( key, nullptr );
			if ( inserted )
				it->second = std::make_unique< TypeT >( ctorParams... );
			return it->second.get();
		}

		template< typename TypeU, typename ... ParamsT >
		inline TypeRPtr registerTypeT( BaseParamsT ... params
			, ParamsT && ... ctorParams )
		{
			auto key = m_hasher( params... );
			auto [it, inserted] = m_cache.try_emplace( key, nullptr );
			if ( inserted )
				it->second = std::make_unique< TypeU >( ctorParams... );
			return it->second.get();
		}

		template< typename ... ParamsT >
		inline TypeRPtr tryAddType( BaseParamsT ... params
			, TypeTPtr && type )
		{
			auto key = m_hasher( params... );
			auto [it, inserted] = m_cache.try_emplace( key, nullptr );
			if ( inserted )
				it->second = std::move( type );
			return it->second.get();
		}

	private:
		CreatorT m_creator;
		HasherT m_hasher;
		std::map< size_t, TypeTPtr > m_cache;
	};

	class TypesCache final
	{
	public:
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
		SDAST_API TypePtr getMat2x2F( bool explicitLayout = false );
		SDAST_API TypePtr getMat2x3F( bool explicitLayout = false );
		SDAST_API TypePtr getMat2x4F( bool explicitLayout = false );
		SDAST_API TypePtr getMat3x2F( bool explicitLayout = false );
		SDAST_API TypePtr getMat3x3F( bool explicitLayout = false );
		SDAST_API TypePtr getMat3x4F( bool explicitLayout = false );
		SDAST_API TypePtr getMat4x2F( bool explicitLayout = false );
		SDAST_API TypePtr getMat4x3F( bool explicitLayout = false );
		SDAST_API TypePtr getMat4x4F( bool explicitLayout = false );
		SDAST_API TypePtr getMat2x2D( bool explicitLayout = false );
		SDAST_API TypePtr getMat2x3D( bool explicitLayout = false );
		SDAST_API TypePtr getMat2x4D( bool explicitLayout = false );
		SDAST_API TypePtr getMat3x2D( bool explicitLayout = false );
		SDAST_API TypePtr getMat3x3D( bool explicitLayout = false );
		SDAST_API TypePtr getMat3x4D( bool explicitLayout = false );
		SDAST_API TypePtr getMat4x2D( bool explicitLayout = false );
		SDAST_API TypePtr getMat4x3D( bool explicitLayout = false );
		SDAST_API TypePtr getMat4x4D( bool explicitLayout = false );
		SDAST_API TypePtr getBasicType( Kind kind, bool explicitLayout = false );
		SDAST_API TypePtr getVec2Type( Kind kind );
		SDAST_API TypePtr getVec3Type( Kind kind );
		SDAST_API TypePtr getVec4Type( Kind kind );
		SDAST_API Kind getVec2Kind( Kind kind )const;
		SDAST_API Kind getVec3Kind( Kind kind )const;
		SDAST_API Kind getVec4Kind( Kind kind )const;
		SDAST_API Kind getMat2Kind( Kind kind )const;
		SDAST_API Kind getMat3Kind( Kind kind )const;
		SDAST_API Kind getMat4Kind( Kind kind )const;
		SDAST_API TypePtr getVector( Kind kind, uint32_t count );

		SDAST_API ComputeInputPtr getComputeInput( TypePtr type, uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ );
		SDAST_API FragmentInputPtr getFragmentInput( TypePtr type, FragmentOrigin origin, FragmentCenter center, InvocationOrdering ordering );
		SDAST_API GeometryInputPtr getGeometryInput( TypePtr type, InputLayout layout );
		SDAST_API GeometryOutputPtr getGeometryOutput( TypePtr type, OutputLayout layout, uint32_t count );
		SDAST_API TessellationOutputPatchPtr getTessellationOutputPatch( TypePtr type, uint32_t location );
		SDAST_API TessellationControlInputPtr getTessellationControlInput( TypePtr type, uint32_t inputVertices );
		SDAST_API TessellationControlOutputPtr getTessellationControlOutput( TypePtr type, PatchDomain domain, Partitioning partitioning, OutputTopology topology, PrimitiveOrdering order, uint32_t outputVertices );
		SDAST_API TessellationInputPatchPtr getTessellationInputPatch( TypePtr type, PatchDomain domain, uint32_t location );
		SDAST_API TessellationEvaluationInputPtr getTessellationEvaluationInput( TypePtr type, PatchDomain domain, Partitioning partitioning, PrimitiveOrdering order, uint32_t inputVertices );
		SDAST_API MeshPrimitiveOutputPtr getMeshPrimitiveOutput( TypePtr type, OutputTopology topology, uint32_t maxPrimitives );
		SDAST_API MeshVertexOutputPtr getMeshVertexOutput( TypePtr type, uint32_t maxVertices );
		SDAST_API TaskPayloadInPtr getTaskPayloadIn( TypePtr type );
		SDAST_API TaskPayloadInNVPtr getTaskPayloadInNV( TypePtr type );
		SDAST_API TaskPayloadPtr getTaskPayload( TypePtr type );
		SDAST_API TaskPayloadNVPtr getTaskPayloadNV( TypePtr type );

		SDAST_API AccelerationStructurePtr getAccelerationStructure();
		SDAST_API HitAttributePtr getHitAttribute( TypePtr dataType );
		SDAST_API RayPayloadPtr getRayPayload( TypePtr dataType, uint32_t location );
		SDAST_API CallableDataPtr getCallableData( TypePtr dataType, uint32_t location );
		SDAST_API RayDescPtr getRayDesc();
		SDAST_API ImagePtr getImage( ImageConfiguration const & func );
		SDAST_API SampledImagePtr getSampledImage( ImageConfiguration const & func, Trinary comparison = Trinary::eDontCare );
		SDAST_API CombinedImagePtr getCombinedImage( ImageConfiguration const & func, bool isComparison = false );
		SDAST_API SamplerPtr getSampler( bool comparison = false );
		SDAST_API TypePtr getSampledType( ImageFormat format );
		SDAST_API TypePtr getTexelType( ImageFormat format );
		SDAST_API FunctionPtr getFunction( TypePtr returnType, var::VariableList parameters );
		SDAST_API BaseStructPtr getStruct( MemoryLayout layout, std::string const & name, bool explicitLayout = false );
		SDAST_API IOStructPtr getIOStruct( std::string const & name, ast::EntryPoint entryPoint, var::Flag flag );
		SDAST_API IOStructPtr getIOStruct( std::string const & name, ast::EntryPoint entryPoint, ast::type::MemoryLayout layout, var::Flag flag, bool explicitLayout = false );
		SDAST_API ArrayPtr getArray( TypePtr type, uint32_t arraySize = UnknownArraySize, bool explicitLayout = false );

		SDAST_API TypePtr getMemberType( TypePtr type, Struct & parent, uint32_t memberIndex );
		SDAST_API ArrayPtr getMemberType( ArrayPtr type, Struct & parent, uint32_t memberIndex );
		SDAST_API StructPtr getMemberType( StructPtr type, Struct & parent, uint32_t memberIndex );
		SDAST_API Type const * getNonMemberType( TypePtr type )const;

		SDAST_API TypePtr getExplicitLayoutType( TypePtr type );
		SDAST_API ArrayPtr getExplicitLayoutType( ArrayPtr type );
		SDAST_API BaseStructPtr getExplicitLayoutType( BaseStructPtr type );
		SDAST_API IOStructPtr getExplicitLayoutType( IOStructPtr type );

		SDAST_API TypePtr getNonExplicitLayoutType( TypePtr type );
		SDAST_API ArrayPtr getNonExplicitLayoutType( ArrayPtr type );
		SDAST_API BaseStructPtr getNonExplicitLayoutType( BaseStructPtr type );
		SDAST_API IOStructPtr getNonExplicitLayoutType( IOStructPtr type );

		SDAST_API TypePtr getPointerType( TypePtr pointerType, Storage storage );
		SDAST_API TypePtr getForwardPointerType( TypePtr pointerType, Storage storage );

	private:
		TypeCache< Type, ast::type::Kind, bool > m_basic{ [this]( ast::type::Kind kind, bool explicitLayout )
			{
				return std::make_unique< Type >( *this, kind, explicitLayout );
			}
			, []( ast::type::Kind kind, bool explicitLayout )noexcept
			{
				return ast::type::getHash( kind, explicitLayout );
			} };
		TypeCache< Type, TypePtr, StructPtr, uint32_t > m_member{ [this]( TypePtr type, StructPtr parent, uint32_t mbrIndex )
			{
				return std::make_unique< Type >( *this, parent, mbrIndex, type );
			}
			, []( TypePtr type, StructPtr parent, uint32_t mbrIndex )noexcept
			{
				return ast::type::getHash( type, parent, mbrIndex );
			} };
		TypeCache< Image, ImageConfiguration const & > m_image{ [this]( ImageConfiguration const & config )
			{
				return std::make_unique< Image >( *this, config );
			}
			, []( ImageConfiguration const & config )noexcept
			{
				return ast::type::getHash( config );
			} };
		TypeCache< CombinedImage, ImageConfiguration const &, bool > m_combinedImage{ [this]( ImageConfiguration const & config, bool isComparison )
			{
				return std::make_unique< CombinedImage >( *this, config, isComparison );
			}
			, []( ImageConfiguration const & config, bool isComparison )noexcept
			{
				return ast::type::getHash( config, isComparison );
			} };
		TypeCache< SampledImage, ImageConfiguration const &, Trinary > m_sampledImage{ [this]( ImageConfiguration const & config, Trinary comparison )
			{
				return std::make_unique< SampledImage >( *this, config, comparison );
			}
			, []( ImageConfiguration const & config, Trinary )noexcept
			{
				return ast::type::getHash( config );
			} };
		TypeCache< Sampler, bool > m_sampler{ [this]( bool comparison )
			{
				return std::make_unique< Sampler >( *this, comparison );
			}
			, []( bool comparison )noexcept
			{
				return comparison ? 1u : 0u;
			} };
		TypeCache< Function, TypePtr, var::VariableList > m_function{ []( TypePtr returnType
				, var::VariableList parameters )
			{
				return std::make_unique< Function >( returnType
					, std::move( parameters ) );
			}
			, []( TypePtr returnType
				, var::VariableList const & parameters )noexcept
			{
				return ast::type::getHash( returnType, parameters );
			} };
		TypeCache< BaseStruct, MemoryLayout, std::string const &, bool > m_struct{ [this]( MemoryLayout layout
				, std::string name
				, bool explicitLayout )
			{
				return std::make_unique< BaseStruct >( *this
					, layout
					, std::move( name )
					, explicitLayout );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( layout, name, explicitLayout );
			} };
		TypeCache< IOStruct, MemoryLayout, std::string const &, EntryPoint, var::Flag, bool > m_inputStruct{ [this]( MemoryLayout layout
				, std::string name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )
			{
				return std::make_unique< IOStruct >( *this
					, layout
					, std::move( name )
					, entryPoint
					, flag
					, explicitLayout );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( layout, name, entryPoint, flag, explicitLayout );
			} };
		TypeCache< IOStruct, MemoryLayout, std::string const &, EntryPoint, var::Flag, bool > m_outputStruct{ [this]( MemoryLayout layout
				, std::string name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )
			{
				return std::make_unique< IOStruct >( *this
					, layout
					, std::move( name )
					, entryPoint
					, flag
					, explicitLayout );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( layout, name, entryPoint, flag, explicitLayout );
			} };
		TypeCache< Array, TypePtr, uint32_t, bool > m_array{ []( TypePtr type
				, uint32_t arraySize
				, bool explicitLayout )
			{
				return std::make_unique< Array >( std::move( type )
					, arraySize
					, explicitLayout );
			}
			, []( TypePtr type
				, uint32_t arraySize
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( type, arraySize, explicitLayout );
			} };
		TypeCache< Pointer, TypePtr, Storage, bool > m_pointer{ []( TypePtr pointerType
				, Storage storage
				, bool isForward )
			{
				return std::make_unique< Pointer >( std::move( pointerType )
					, storage
					, isForward );
			}
			, []( TypePtr pointerType
				, Storage storage
				, bool isForward )noexcept
			{
				return ast::type::getHash( pointerType, storage, isForward );
			} };
		TypeCache< RayPayload, TypePtr, uint32_t > m_rayPayload{ []( TypePtr type
				, uint32_t location )
			{
				return std::make_unique< RayPayload >( std::move( type )
					, location );
			}
			, []( TypePtr type
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location, false );
			} };
		TypeCache< CallableData, TypePtr, uint32_t > m_callableData{ []( TypePtr type
				, uint32_t location )
			{
				return std::make_unique< CallableData >( std::move( type )
					, location );
			}
			, []( TypePtr type
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location, false );
			} };
		TypeCache< HitAttribute, TypePtr > m_hitAttribute{ []( TypePtr type )
			{
				return std::make_unique< HitAttribute >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} };
		TypeCache< MeshVertexOutput, TypePtr, uint32_t > m_meshVertexOutput{ []( TypePtr type
				, uint32_t maxVertices )
			{
				return std::make_unique< MeshVertexOutput >( type, maxVertices );
			}
			, []( TypePtr type
				, uint32_t maxVertices )noexcept
			{
				return getHash( type, maxVertices, false );
			} };
		TypeCache< MeshPrimitiveOutput, TypePtr, OutputTopology, uint32_t > m_meshPrimitiveOutput{ []( TypePtr type
				, OutputTopology topology
				, uint32_t maxPrimitives )
			{
				return std::make_unique< MeshPrimitiveOutput >( type, topology, maxPrimitives );
			}
			, []( TypePtr type
				, OutputTopology topology
				, uint32_t maxPrimitives )noexcept
			{
				return getHash( type, topology, maxPrimitives );
			} };
		TypeCache< TaskPayloadNV, TypePtr > m_taskPayloadNV{ []( TypePtr type )
			{
				return std::make_unique< TaskPayloadNV >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} };
		TypeCache< TaskPayloadInNV, TypePtr > m_taskPayloadInNV{ []( TypePtr type )
			{
				return std::make_unique< TaskPayloadInNV >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} };
		TypeCache< TaskPayload, TypePtr > m_taskPayload{ []( TypePtr type )
			{
				return std::make_unique< TaskPayload >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} };
		TypeCache< TaskPayloadIn, TypePtr > m_taskPayloadIn{ []( TypePtr type )
			{
				return std::make_unique< TaskPayloadIn >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} };
		TypeCache< ComputeInput, TypePtr, uint32_t, uint32_t, uint32_t > m_compute{ []( TypePtr type
				, uint32_t localSizeX
				, uint32_t localSizeY
				, uint32_t localSizeZ )
			{
				return std::make_unique< ComputeInput >( type, localSizeX, localSizeY, localSizeZ );
			}
			, []( TypePtr type
				, uint32_t localSizeX
				, uint32_t localSizeY
				, uint32_t localSizeZ )noexcept
			{
				return getHash( type, localSizeX, localSizeY, localSizeZ );
			} };
		TypeCache< FragmentInput, TypePtr, FragmentOrigin, FragmentCenter, InvocationOrdering > m_fragment{ []( TypePtr type
				, FragmentOrigin origin
				, FragmentCenter center
				, InvocationOrdering ordering )
			{
				return std::make_unique< FragmentInput >( type, origin, center, ordering );
			}
			, []( TypePtr type
				, FragmentOrigin origin
				, FragmentCenter center
				, InvocationOrdering ordering )noexcept
			{
				return getHash( type, origin, center, ordering );
			} };
		TypeCache< GeometryInput, TypePtr, InputLayout > m_geometryInput{ []( TypePtr type
				, InputLayout layout )
			{
				return std::make_unique< GeometryInput >( type, layout );
			}
			, []( TypePtr type
					, InputLayout layout )noexcept
			{
				return getHash( type, layout );
			} };
		TypeCache< GeometryOutput, TypePtr, OutputLayout, uint32_t > m_geometryOutput{ []( TypePtr type
				, OutputLayout layout
				, uint32_t count )
			{
				return std::make_unique< GeometryOutput >( type, layout, count );
			}
			, []( TypePtr type
				, OutputLayout layout
				, uint32_t count )noexcept
			{
				return getHash( type, layout, count );
			} };
		TypeCache< TessellationOutputPatch, TypePtr, uint32_t > m_tessellationOutputPatch{ []( TypePtr type
				, uint32_t location )
			{
				return std::make_unique< TessellationOutputPatch >( type, location );
			}
			, []( TypePtr type
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location, false );
			} };
		TypeCache< TessellationControlInput, TypePtr, uint32_t > m_tessellationControlInput{ []( TypePtr type
				, uint32_t inputVertices )
			{
				return std::make_unique< TessellationControlInput >( type, inputVertices );
			}
			, []( TypePtr type
				, uint32_t inputVertices )noexcept
			{
				return ast::type::getHash( type, inputVertices, false );
			} };
		TypeCache< TessellationControlOutput, TypePtr, PatchDomain, Partitioning, OutputTopology, PrimitiveOrdering, uint32_t > m_tessellationControlOutput{ []( TypePtr type
				, PatchDomain domain
				, Partitioning partitioning
				, OutputTopology topology
				, PrimitiveOrdering order
				, uint32_t outputVertices )
			{
				return std::make_unique< TessellationControlOutput >( type, domain, partitioning, topology, order, outputVertices );
			}
			, []( TypePtr type
				, PatchDomain domain
				, Partitioning partitioning
				, OutputTopology topology
				, PrimitiveOrdering order
				, uint32_t outputVertices )noexcept
			{
				return getHash( type, domain, partitioning, topology, order, outputVertices );
			} };
		TypeCache< TessellationInputPatch, TypePtr, PatchDomain, uint32_t > m_tessellationInputPatch{ []( TypePtr type
				, PatchDomain domain
				, uint32_t location )
			{
				return std::make_unique< TessellationInputPatch >( type, domain, location );
			}
			, []( TypePtr type
				, PatchDomain domain
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, domain, location );
			} };
		TypeCache< TessellationEvaluationInput, TypePtr, PatchDomain, Partitioning, PrimitiveOrdering, uint32_t > m_tessellationEvaluationInput{ []( TypePtr type
				, PatchDomain domain
				, Partitioning partitioning
				, PrimitiveOrdering order
				, uint32_t outputVertices )
			{
				return std::make_unique< TessellationEvaluationInput >( type, domain, partitioning, order, outputVertices );
			}
			, []( TypePtr type
				, PatchDomain domain
				, Partitioning partitioning
				, PrimitiveOrdering order
				, uint32_t outputVertices )noexcept
			{
				return getHash( type, domain, partitioning, order, outputVertices );
			} };
		std::unique_ptr< AccelerationStructure > m_accelerationStructure{ std::make_unique< AccelerationStructure >( *this ) };
		std::unique_ptr< RayDesc > m_rayDesc{ std::make_unique< RayDesc >( *this ) };
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
