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
		, typename CreatorT >
	class TypeCache
	{
	private:
		using TypeTPtr = std::shared_ptr< TypeT >;

	public:
		inline TypeCache( Kind kind )
		{
			m_creator = [kind]( uint32_t arraySize )
			{
				return std::shared_ptr< TypeT >( new Type{ kind, arraySize } );
			};
		}
		
		inline TypeCache( CreatorT creator )
			: m_creator{ std::move( creator ) }
		{
		}

		template< typename ... ParamsT >
		inline TypeTPtr getType( uint32_t arraySize, ParamsT ... params )
		{
			auto it = m_cache.find( arraySize );

			if ( it == m_cache.end() )
			{
				it = m_cache.emplace( arraySize
					, m_creator( std::forward< ParamsT >( params )...
						, arraySize ) ).first;
			}

			return it->second;
		}

	private:
		CreatorT m_creator;
		std::map< uint32_t, TypeTPtr > m_cache;
	};

	template< typename TypeT
		, typename CreatorT >
		inline TypeCache< TypeT, CreatorT > makeTypeCache( CreatorT creator )
	{
		return TypeCache< TypeT, CreatorT >{ std::move( creator ) };
	}
}

#endif
