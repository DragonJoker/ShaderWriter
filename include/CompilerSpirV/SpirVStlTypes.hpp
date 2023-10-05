/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirVStlTypes_H___
#define ___SDW_SpirVStlTypes_H___

#include <ShaderAST/ShaderAllocator.hpp>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#if defined( CompilerSpirV_Static )
#	define SDWSPIRV_API
#elif defined( _WIN32 )
#	if defined( CompilerSpirV_Exports )
#		define SDWSPIRV_API __declspec( dllexport )
#	else
#		define SDWSPIRV_API __declspec( dllimport )
#	endif
#else
#	define SDWSPIRV_API
#endif

namespace spirv
{
	template< typename TypeT >
	class ModuleAllocatorT
	{
	public:
		using value_type = TypeT;
		using size_type = std::size_t;

		template< typename TypeU >
		friend class ModuleAllocatorT;

		ModuleAllocatorT( ModuleAllocatorT const & rhs )noexcept
			: m_allocator{ rhs.m_allocator }
		{
		}

		ModuleAllocatorT( ast::ShaderAllocatorBlock * allocator )noexcept
			: m_allocator{ allocator }
		{
		}

		template< typename TypeU >
		ModuleAllocatorT( const ModuleAllocatorT< TypeU > & rhs )noexcept
			: m_allocator{ rhs.m_allocator }
		{
		}

		SDWSPIRV_API value_type * allocate( size_type const count )
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
	inline bool operator==( const ModuleAllocatorT< TypeT > &, const ModuleAllocatorT< TypeT > & )
	{
		return true;
	}

	template< typename TypeT >
	inline bool operator!=( const ModuleAllocatorT< TypeT > &, const ModuleAllocatorT< TypeT > & )
	{
		return false;
	}

	template< typename KeyT, typename ValueT >
	using ModuleMapAllocatorT = ModuleAllocatorT< std::pair< KeyT const, ValueT > >;

	template< typename ValueT >
	using Vector = std::vector< ValueT, ModuleAllocatorT< ValueT > >;

	template< typename ValueT, typename CompareT = std::less< ValueT > >
	using Set = std::set< ValueT, CompareT, ModuleAllocatorT< ValueT > >;

	template< typename ValueT, typename HashT = std::hash< ValueT >, typename KeyEqualT = std::equal_to< ValueT > >
	using UnorderedSet = std::unordered_set< ValueT, HashT, KeyEqualT, ModuleAllocatorT< ValueT > >;

	template< typename KeyT, typename ValueT, typename CompareT = std::less< KeyT > >
	using Map = std::map< KeyT, ValueT, CompareT, ModuleMapAllocatorT< KeyT, ValueT > >;

	template< typename KeyT, typename ValueT, typename HashT = std::hash< KeyT >, typename KeyEqualT = std::equal_to< KeyT > >
	using UnorderedMap = std::unordered_map< KeyT, ValueT, HashT, KeyEqualT, ModuleMapAllocatorT< KeyT, ValueT > >;
}

#endif
