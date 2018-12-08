/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeCache_H___
#define ___AST_TypeCache_H___
#pragma once

#include "Type.hpp"
#include "TypeArray.hpp"
#include "TypeImage.hpp"
#include "TypeSampledImage.hpp"
#include "TypeSampler.hpp"
#include "TypeStruct.hpp"

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
		inline TypeCache( TypesCache * parent
			, CreatorT creator
			, HasherT hasher )
			: m_parent{ parent }
			, m_creator{ std::move( creator ) }
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
				it = m_cache.emplace( key, m_creator( m_parent, std::forward< ParamsT >( params )... ) ).first;
			}

			return it->second;
		}

	private:
		TypesCache * m_parent;
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
		TypePtr getFunction();
		TypePtr getBool();
		TypePtr getInt();
		TypePtr getUInt();
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
		TypePtr getConstantsBuffer();
		TypePtr getShaderBuffer();
		ImagePtr getImage( ImageConfiguration const & config );
		SampledImagePtr getSampledImage( ImageConfiguration const & config );
		SamplerPtr getSampler( bool comparison = false );
		TypePtr getSampledType( ImageFormat format );
		StructPtr getStruct( MemoryLayout layout, std::string const & name );
		ArrayPtr getArray( TypePtr type, uint32_t arraySize = UnknownArraySize );
		TypePtr getMemberType( TypePtr type, Struct & parent, uint32_t memberIndex );

		TypePtr getVec2Type( Kind kind );
		TypePtr getVec3Type( Kind kind );
		TypePtr getVec4Type( Kind kind );
		TypePtr getVector( Kind kind, uint32_t count );

		TypePtr makeType( Kind kind );

		static inline TypesCache * get()
		{
			return m_instance;
		}

	private:
		static TypesCache * m_instance;
		TypePtr m_undefined = std::make_shared< Type >( Kind::eUndefined );
		TypePtr m_void = std::make_shared< Type >( Kind::eVoid );
		TypePtr m_function = std::make_shared< Type >( Kind::eFunction );
		TypePtr m_boolean = std::make_shared< Type >( Kind::eBoolean );
		TypePtr m_int = std::make_shared< Type >( Kind::eInt );
		TypePtr m_uint = std::make_shared< Type >( Kind::eUInt );
		TypePtr m_float = std::make_shared< Type >( Kind::eFloat );
		TypePtr m_double = std::make_shared< Type >( Kind::eDouble );
		TypePtr m_vec2B = std::make_shared< Type >( Kind::eVec2B );
		TypePtr m_vec3B = std::make_shared< Type >( Kind::eVec3B );
		TypePtr m_vec4B = std::make_shared< Type >( Kind::eVec4B );
		TypePtr m_vec2I = std::make_shared< Type >( Kind::eVec2I );
		TypePtr m_vec3I = std::make_shared< Type >( Kind::eVec3I );
		TypePtr m_vec4I = std::make_shared< Type >( Kind::eVec4I );
		TypePtr m_vec2U = std::make_shared< Type >( Kind::eVec2U );
		TypePtr m_vec3U = std::make_shared< Type >( Kind::eVec3U );
		TypePtr m_vec4U = std::make_shared< Type >( Kind::eVec4U );
		TypePtr m_vec2F = std::make_shared< Type >( Kind::eVec2F );
		TypePtr m_vec3F = std::make_shared< Type >( Kind::eVec3F );
		TypePtr m_vec4F = std::make_shared< Type >( Kind::eVec4F );
		TypePtr m_vec2D = std::make_shared< Type >( Kind::eVec2D );
		TypePtr m_vec3D = std::make_shared< Type >( Kind::eVec3D );
		TypePtr m_vec4D = std::make_shared< Type >( Kind::eVec4D );
		TypePtr m_mat2x2F = std::make_shared< Type >( Kind::eMat2x2F );
		TypePtr m_mat2x3F = std::make_shared< Type >( Kind::eMat2x3F );
		TypePtr m_mat2x4F = std::make_shared< Type >( Kind::eMat2x4F );
		TypePtr m_mat3x2F = std::make_shared< Type >( Kind::eMat3x2F );
		TypePtr m_mat3x3F = std::make_shared< Type >( Kind::eMat3x3F );
		TypePtr m_mat3x4F = std::make_shared< Type >( Kind::eMat3x4F );
		TypePtr m_mat4x2F = std::make_shared< Type >( Kind::eMat4x2F );
		TypePtr m_mat4x3F = std::make_shared< Type >( Kind::eMat4x3F );
		TypePtr m_mat4x4F = std::make_shared< Type >( Kind::eMat4x4F );
		TypePtr m_mat2x2D = std::make_shared< Type >( Kind::eMat2x2D );
		TypePtr m_mat2x3D = std::make_shared< Type >( Kind::eMat2x3D );
		TypePtr m_mat2x4D = std::make_shared< Type >( Kind::eMat2x4D );
		TypePtr m_mat3x2D = std::make_shared< Type >( Kind::eMat3x2D );
		TypePtr m_mat3x3D = std::make_shared< Type >( Kind::eMat3x3D );
		TypePtr m_mat3x4D = std::make_shared< Type >( Kind::eMat3x4D );
		TypePtr m_mat4x2D = std::make_shared< Type >( Kind::eMat4x2D );
		TypePtr m_mat4x3D = std::make_shared< Type >( Kind::eMat4x3D );
		TypePtr m_mat4x4D = std::make_shared< Type >( Kind::eMat4x4D );
		TypePtr m_ubo = std::make_shared< Type >( Kind::eConstantsBuffer );
		TypePtr m_ssbo = std::make_shared< Type >( Kind::eShaderBuffer );
		TypeCache< Image, std::function< ImagePtr( TypesCache *, ImageConfiguration ) >, std::function< size_t( ImageConfiguration const & ) > > m_image;
		TypeCache< SampledImage, std::function< SampledImagePtr( TypesCache *, ImageConfiguration ) >, std::function< size_t( ImageConfiguration const & ) > > m_sampledImage;
		TypeCache< Sampler, std::function< SamplerPtr( TypesCache *, bool ) >, std::function< size_t( bool ) > > m_sampler;
		TypeCache< Struct, std::function< StructPtr( TypesCache *, MemoryLayout, std::string ) >, std::function< size_t( MemoryLayout, std::string const & ) > > m_struct;
		TypeCache< Array, std::function< ArrayPtr( TypesCache *, TypePtr, uint32_t ) >, std::function< size_t( TypePtr, uint32_t ) > > m_array;
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
