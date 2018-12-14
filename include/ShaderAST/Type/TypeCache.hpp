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
		TypesCache();
		~TypesCache();
		TypePtr getUndefined();
		TypePtr getVoid();
		TypePtr getBool();
		TypePtr getInt();
		TypePtr getUInt();
		TypePtr getHalf();
		TypePtr getFloat();
		TypePtr getDouble();
		TypePtr getVec2B();
		TypePtr getVec3B();
		TypePtr getVec4B();
		TypePtr getVec2I();
		TypePtr getVec3I();
		TypePtr getVec4I();
		TypePtr getVec2U();
		TypePtr getVec3U();
		TypePtr getVec4U();
		TypePtr getVec2H();
		TypePtr getVec3H();
		TypePtr getVec4H();
		TypePtr getVec2F();
		TypePtr getVec3F();
		TypePtr getVec4F();
		TypePtr getVec2D();
		TypePtr getVec3D();
		TypePtr getVec4D();
		TypePtr getMat2x2F();
		TypePtr getMat2x3F();
		TypePtr getMat2x4F();
		TypePtr getMat3x2F();
		TypePtr getMat3x3F();
		TypePtr getMat3x4F();
		TypePtr getMat4x2F();
		TypePtr getMat4x3F();
		TypePtr getMat4x4F();
		TypePtr getMat2x2D();
		TypePtr getMat2x3D();
		TypePtr getMat2x4D();
		TypePtr getMat3x2D();
		TypePtr getMat3x3D();
		TypePtr getMat3x4D();
		TypePtr getMat4x2D();
		TypePtr getMat4x3D();
		TypePtr getMat4x4D();
		TypePtr getBasicType( Kind kind );
		TypePtr getVec2Type( Kind kind );
		TypePtr getVec3Type( Kind kind );
		TypePtr getVec4Type( Kind kind );
		TypePtr getVector( Kind kind, uint32_t count );

		ImagePtr getImage( ImageConfiguration const & config );
		SampledImagePtr getSampledImage( ImageConfiguration const & config );
		SamplerPtr getSampler( bool comparison = false );
		TypePtr getSampledType( ImageFormat format );
		FunctionPtr getFunction( TypePtr returnType, var::VariableList const & parameters );
		StructPtr getStruct( MemoryLayout layout, std::string const & name );
		ArrayPtr getArray( TypePtr type, uint32_t arraySize = UnknownArraySize );

		TypePtr getMemberType( TypePtr type, Struct & parent, uint32_t memberIndex );

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
