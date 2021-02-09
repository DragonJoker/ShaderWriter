/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeCache_H___
#define ___AST_TypeCache_H___
#pragma once

#include "Type.hpp"
#include "TypeArray.hpp"
#include "TypeFunction.hpp"
#include "TypeImage.hpp"
#include "TypeSampledImage.hpp"
#include "TypeSampler.hpp"
#include "TypeStruct.hpp"

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
		inline TypeTPtr getType( ParamsT ... params )
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

	class TypesCache
	{
	public:
		SDAST_API TypesCache();
		SDAST_API ~TypesCache();
		SDAST_API TypePtr getUndefined();
		SDAST_API TypePtr getVoid();
		SDAST_API TypePtr getBool();
		SDAST_API TypePtr getInt();
		SDAST_API TypePtr getUInt();
		SDAST_API TypePtr getHalf();
		SDAST_API TypePtr getFloat();
		SDAST_API TypePtr getDouble();
		SDAST_API TypePtr getVec2B();
		SDAST_API TypePtr getVec3B();
		SDAST_API TypePtr getVec4B();
		SDAST_API TypePtr getVec2I();
		SDAST_API TypePtr getVec3I();
		SDAST_API TypePtr getVec4I();
		SDAST_API TypePtr getVec2U();
		SDAST_API TypePtr getVec3U();
		SDAST_API TypePtr getVec4U();
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
		SDAST_API TypePtr getVector( Kind kind, uint32_t count );

		SDAST_API ImagePtr getImage( ImageConfiguration const & config );
		SDAST_API SampledImagePtr getSampledImage( ImageConfiguration const & config );
		SDAST_API SamplerPtr getSampler( bool comparison = false );
		SDAST_API TypePtr getSampledType( ImageFormat format );
		SDAST_API TypePtr getTexelType( ImageFormat format );
		SDAST_API FunctionPtr getFunction( TypePtr returnType, var::VariableList parameters );
		SDAST_API StructPtr getStruct( MemoryLayout layout, std::string const & name );
		SDAST_API ArrayPtr getArray( TypePtr type, uint32_t arraySize = UnknownArraySize );

		SDAST_API TypePtr getMemberType( TypePtr type, Struct & parent, uint32_t memberIndex );
		SDAST_API Type const * getNonMemberType( TypePtr type );

	private:
		std::array< TypePtr, size_t( Kind::eMax ) > m_basicTypes;
		TypeCache< Image, std::function< ImagePtr( ImageConfiguration ) >, std::function< size_t( ImageConfiguration const & ) > > m_image;
		TypeCache< SampledImage, std::function< SampledImagePtr( ImageConfiguration ) >, std::function< size_t( ImageConfiguration const & ) > > m_sampledImage;
		TypeCache< Sampler, std::function< SamplerPtr( bool ) >, std::function< size_t( bool ) > > m_sampler;
		TypeCache< Function, std::function< FunctionPtr( TypePtr, var::VariableList ) >, std::function< size_t( TypePtr, var::VariableList ) > > m_function;
		TypeCache< Struct, std::function< StructPtr( MemoryLayout, std::string ) >, std::function< size_t( MemoryLayout, std::string const & ) > > m_struct;
		TypeCache< Array, std::function< ArrayPtr( TypePtr, uint32_t ) >, std::function< size_t( TypePtr, uint32_t ) > > m_array;
		struct MemberTypeInfo
		{
			TypePtr nonMemberType;
			TypePtr parent;
			uint32_t memberIndex;
		};
		std::map< TypePtr, MemberTypeInfo > m_memberTypes;
	};
}

#endif
