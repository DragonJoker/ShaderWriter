/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeCache_H___
#define ___AST_TypeCache_H___
#pragma once

#include "Type.hpp"

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
		inline TypeCache( CreatorT creator, HasherT hasher )
			: m_creator{ std::move( creator ) }
			, m_hasher{ std::move( hasher ) }
		{
		}

		template< typename ... ParamsT >
		inline TypeTPtr getType( ParamsT ... params )
		{
			auto key = m_hasher( std::forward< ParamsT >( params )... );
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

	template< typename TypeT
		, typename CreatorT
		, typename HasherT >
		inline TypeCache< TypeT, CreatorT, HasherT > makeTypeCache( CreatorT creator, HasherT hasher )
	{
		return TypeCache< TypeT, CreatorT, HasherT >{ std::move( creator ), std::move( hasher ) };
	}
}

#endif
