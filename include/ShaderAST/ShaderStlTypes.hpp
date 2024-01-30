/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ShaderStlTypes_H___
#define ___SDW_ShaderStlTypes_H___

#include "ShaderAST/ShaderAllocator.hpp"

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace ast
{
	struct StringHash
	{
		using is_transparent = void;

		std::size_t operator()( std::string_view v )const
		{
			return std::hash<std::string_view>{}( v );
		}
	};

	template< typename TypeT >
	class StlAllocatorT
	{
	public:
		using value_type = TypeT;
		using size_type = std::size_t;

		template< typename TypeU >
		friend class StlAllocatorT;

		StlAllocatorT( ast::ShaderAllocatorBlock * allocator )noexcept
			: m_allocator{ allocator }
		{
		}

		template< typename TypeU >
		StlAllocatorT( const StlAllocatorT< TypeU > & rhs )noexcept
			: m_allocator{ rhs.m_allocator }
		{
		}

		value_type * allocate( size_type const count )
		{
			return reinterpret_cast< value_type * >( m_allocator->allocate( sizeof( value_type ), count ) );
		}

		void deallocate( value_type * value, size_type const count )
		{
			m_allocator->deallocate( value, sizeof( value_type ), count );
		}

		ast::ShaderAllocatorBlock * getAllocator()const
		{
			return m_allocator;
		}

	private:
		ast::ShaderAllocatorBlock * m_allocator;
	};

	template< typename TypeT >
	inline bool operator==( const StlAllocatorT< TypeT > &, const StlAllocatorT< TypeT > & )
	{
		return true;
	}

	template< typename TypeT >
	inline bool operator!=( const StlAllocatorT< TypeT > &, const StlAllocatorT< TypeT > & )
	{
		return false;
	}

	template< typename FirstT, typename SecondT >
	using StlPairAllocatorT = StlAllocatorT< std::pair< FirstT, SecondT > >;

	template< typename KeyT, typename ValueT >
	using StlMapAllocatorT = StlPairAllocatorT< KeyT const, ValueT >;

	template< typename ValueT >
	using Vector = std::vector< ValueT, StlAllocatorT< ValueT > >;

	template< typename ValueT, typename CompareT = std::less< ValueT > >
	using Set = std::set< ValueT, CompareT, StlAllocatorT< ValueT > >;

	template< typename ValueT, typename HashT = std::hash< ValueT >, typename KeyEqualT = std::equal_to< ValueT > >
	using UnorderedSet = std::unordered_set< ValueT, HashT, KeyEqualT, StlAllocatorT< ValueT > >;

	template< typename KeyT, typename ValueT, typename CompareT = std::less< KeyT > >
	using Map = std::map< KeyT, ValueT, CompareT, StlMapAllocatorT< KeyT, ValueT > >;

	template< typename KeyT, typename ValueT, typename HashT = std::hash< KeyT >, typename KeyEqualT = std::equal_to< KeyT > >
	using UnorderedMap = std::unordered_map< KeyT, ValueT, HashT, KeyEqualT, StlMapAllocatorT< KeyT, ValueT > >;

	using UnorderedStringSet = std::unordered_set< std::string, StringHash, std::equal_to<> >;
}

#endif
