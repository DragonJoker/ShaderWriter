/*
See LICENSE file in root folder
*/
#include "ShaderAST/ShaderAllocator.hpp"

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <iostream>
#pragma warning( pop )

namespace ast
{
	//*********************************************************************************************

	BuddyAllocator::BuddyAllocator( uint32_t numLevels
		, uint32_t minBlockSize )
		: m_memory{ minBlockSize * ( 1u << numLevels ) }
		, m_numLevels{ numLevels }
		, m_minBlockSize{ minBlockSize }
	{
		assert( m_numLevels < 32 );
		m_freeLists.resize( m_numLevels + 1 );
		m_freeLists[0u].push_back( getPointer( 0u ) );
	}

	BuddyAllocator::~BuddyAllocator()
	{
		for ( auto const & [offset, level] : m_allocated )
		{
			std::cout << "Leaked block at " << offset << ", for level " << level << " for " << m_minBlockSize << " block size buddy" << std::endl;
		}
	}

	bool BuddyAllocator::hasAvailable( size_t size )const
	{
		auto level = doGetLevel( size );
		bool result = !size;

		if ( !result && size <= getTotalSize() )
		{
			auto it = m_freeLists.rend() - ( level + 1 );

			while ( it != m_freeLists.rend() && it->empty() )
			{
				++it;
			}

			result = it != m_freeLists.rend();
		}

		return result;
	}

	BuddyAllocator::PointerType BuddyAllocator::allocate( size_t size )
	{
		PointerType result{};

		if ( size <= getTotalSize() )
		{
			auto level = doGetLevel( size );
			result = doAllocate( level );
			auto offset = getOffset( result );
			m_allocated.emplace_back( offset, level );
		}
		else
		{
			throw std::bad_alloc{};
		}

		return result;
	}

	bool BuddyAllocator::deallocate( PointerType pointer )
	{
		auto offset = getOffset( pointer );
		auto it = std::find_if( m_allocated.begin()
			, m_allocated.end()
			, [offset]( PointerLevel const & ptrLevel )
			{
				return ptrLevel.first == offset;
			} );
		bool result = it != m_allocated.end();

		if ( result )
		{
			auto level = it->second;
			auto index = uint32_t( offset / doGetLevelSize( level ) );
			PointerType block{ pointer };
			m_allocated.erase( it );
			doMergeLevel( block, index, level );
		}
		else
		{
			std::cout << "Double delete at " << offset << std::endl;
		}

		return result;
	}

	size_t BuddyAllocator::getTotalSize()const
	{
		return m_memory.size();
	}

	size_t BuddyAllocator::getAlignSize()const
	{
		return m_minBlockSize;
	}

	BuddyAllocator::PointerType BuddyAllocator::getPointer( uint32_t offset )
	{
		return m_memory.data() + offset;
	}

	size_t BuddyAllocator::getOffset( ConstPointerType pointer )const
	{
		return size_t( pointer - m_memory.data() );
	}

	uint32_t BuddyAllocator::doGetLevel( size_t size )const
	{
		auto levelSize = getTotalSize();
		uint32_t level = 0;

		while ( size < levelSize )
		{
			levelSize >>= 1;
			++level;
		}

		if ( size > levelSize )
		{
			--level;
		}

		return std::min( level, m_numLevels );
	}

	size_t BuddyAllocator::doGetLevelSize( uint32_t level )const
	{
		return getTotalSize() / size_t( 1ULL << level );
	}

	BuddyAllocator::PointerType BuddyAllocator::doAllocate( uint32_t level )
	{
		auto & freeList = m_freeLists[level];

		if ( freeList.empty() )
		{
			if ( level == 0 )
			{
				return nullptr;
			}

			auto buddy = doAllocate( level - 1 );

			if ( !buddy )
			{
				return buddy;
			}

			freeList.push_back( PointerType( buddy ) );
			freeList.push_back( PointerType( buddy + doGetLevelSize( level ) ) );
		}

		auto buddy = freeList.front();
		freeList.erase( freeList.begin() );
		return buddy;
	}

	void BuddyAllocator::doMergeLevel( PointerType const & block
		, uint32_t index
		, uint32_t level )
	{
		auto & freeList = m_freeLists[level];
		PointerType lhs;
		ConstPointerType rhs;
		typename FreeList::iterator it;

		if ( index % 2u )
		{
			// RHS block => find LHS in free blocks of same level.
			lhs = PointerType( block - doGetLevelSize( level ) );
			it = std::find_if( freeList.begin()
				, freeList.end()
				, [lhs]( PointerType const & lookUp )
				{
					return lookUp == lhs;
				} );
		}
		else
		{
			// LHS block => find RHS in free blocks of same level.
			lhs = block;
			rhs = PointerType( block + doGetLevelSize( level ) );
			it = std::find_if( freeList.begin()
				, freeList.end()
				, [rhs]( PointerType const & lookUp )
				{
					return lookUp == rhs;
				} );
		}

		if ( it != freeList.end() )
		{
			// remove the other block from the list.
			freeList.erase( it );
			// add lhs to lower level list.
			auto offset = getOffset( lhs );
			auto newIndex = uint32_t( offset / doGetLevelSize( level - 1u ) );
			// merge lower level.
			doMergeLevel( lhs, newIndex, level - 1u );
		}
		else
		{
			freeList.push_back( block );
		}
	}

	//*********************************************************************************************

	ShaderAllocatorBlock::ShaderAllocatorBlock( ShaderAllocator & allocator )noexcept
		: m_allocator{ &allocator }
		, m_savedCursor{ allocator.getCursor() }
	{
	}

	ShaderAllocatorBlock::ShaderAllocatorBlock( ShaderAllocatorBlock && rhs )noexcept
		: m_allocator{ rhs.m_allocator }
		, m_savedCursor{ rhs.m_savedCursor }
	{
		rhs.m_allocator = {};
		rhs.m_savedCursor = {};
	}

	ShaderAllocatorBlock & ShaderAllocatorBlock::operator=( ShaderAllocatorBlock && rhs )noexcept
	{
		m_allocator = rhs.m_allocator;
		m_savedCursor = rhs.m_savedCursor;

		rhs.m_allocator = {};
		rhs.m_savedCursor = {};

		return *this;
	}

	ShaderAllocatorBlock::~ShaderAllocatorBlock()noexcept
	{
		if ( m_allocator )
		{
			m_allocator->flushTo( m_savedCursor );
		}
	}

	void * ShaderAllocatorBlock::allocate( size_t size, size_t count )
	{
		return m_allocator->allocate( size, count );
	}

	void ShaderAllocatorBlock::deallocate( void * mem, size_t size, size_t count )noexcept
	{
		m_allocator->deallocate( mem, size, count );
	}

	size_t ShaderAllocatorBlock::report()const
	{
		return m_allocator->getMemDiff( m_savedCursor );
	}

	//*********************************************************************************************

	ShaderAllocator::ShaderAllocator( AllocationMode allocationMode )
		: m_allocationMode{ allocationMode }
		, m_currentMemory{ &m_memory.emplace_back() }
	{
	}

	void * ShaderAllocator::allocate( size_t size, size_t count )
	{
		auto wholeSize = size * count;

		if ( m_allocationMode == AllocationMode::eNone )
		{
			return malloc( wholeSize );
		}

		if ( m_allocationMode == AllocationMode::eIncremental )
		{
			if ( wholeSize > m_currentMemory->data->size() - m_currentMemory->offset )
			{
				if ( m_pending.empty() )
				{
					m_currentMemory = &m_memory.emplace_back( wholeSize );
				}
				else
				{
					auto it = std::find_if( m_pending.begin()
						, m_pending.end()
						, [wholeSize]( Memory const & lookup )
						{
							return wholeSize <= lookup.data->size() - lookup.offset;
						} );

					if ( it == m_pending.end() )
					{
						m_currentMemory = &m_memory.emplace_back( wholeSize );
					}
					else
					{
						m_currentMemory = &m_memory.emplace_back( std::move( *it ) );
						m_pending.erase( it );
					}
				}
			}

			auto result = m_currentMemory->data->data() + m_currentMemory->offset;
			m_currentMemory->offset += wholeSize;
			m_maxAllocated = std::max( m_maxAllocated
				, std::distance( m_memory.data(), m_currentMemory ) * Memory::BlockAllocSize + m_currentMemory->offset );
			return result;
		}

		auto it = m_buddies.emplace( size, nullptr ).first;

		if ( !it->second )
		{
			it->second = std::make_unique < BuddyAllocator >( 17u, uint32_t( size ) );
		}

		auto & buddy = *it->second;
		auto result = buddy.allocate( wholeSize );
		assert( result != nullptr );
		return result;
	}

	void ShaderAllocator::deallocate( void * mem, size_t size, [[maybe_unused]] size_t count )noexcept
	{
		if ( m_allocationMode == AllocationMode::eNone )
		{
			return free( mem );
		}

		if ( m_allocationMode == AllocationMode::eFragmented )
		{
			auto it = m_buddies.find( size );

			if ( it != m_buddies.end() )
			{
				it->second->deallocate( reinterpret_cast< std::byte * >( mem ) );
			}
		}
	}

	MemoryCursor ShaderAllocator::getCursor()const noexcept
	{
		return { std::distance( m_memory.data(), const_cast< Memory const * >( m_currentMemory ) )
			, m_currentMemory->offset };
	}

	size_t ShaderAllocator::getMemDiff( MemoryCursor const & cursor )const noexcept
	{
		size_t result{ m_memory[size_t( cursor.index )].offset - cursor.offset };

		if ( auto currentIt = std::next( m_memory.begin(), cursor.index + 1 ); currentIt != m_memory.end() )
		{
			for ( auto it = currentIt; it != m_memory.end(); ++it )
			{
				result += it->offset;
			}
		}

		return result;
	}

	size_t ShaderAllocator::report()const
	{
		return m_maxAllocated;
	}

	void ShaderAllocator::flushTo( MemoryCursor const & cursor )noexcept
	{
		if ( m_allocationMode == AllocationMode::eIncremental )
		{
			m_memory[size_t( cursor.index )].offset = cursor.offset;
			auto currentIt = std::next( m_memory.begin(), cursor.index + 1 );

			if ( currentIt != m_memory.end() )
			{
				try
				{
					for ( auto it = currentIt; it != m_memory.end(); ++it )
					{
						it->offset = 0u;
						m_pending.push_back( std::move( *it ) );
					}

					m_memory.erase( currentIt, m_memory.end() );
					m_currentMemory = &m_memory[size_t( cursor.index )];
				}
				catch ( ... )
				{
				}
			}
		}
	}

	//*********************************************************************************************
}
