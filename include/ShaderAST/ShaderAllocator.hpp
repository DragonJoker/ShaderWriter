/*
See LICENSE file in root folder
*/
#ifndef ___AST_ShaderAllocator_H___
#define ___AST_ShaderAllocator_H___
#pragma once

#include "ShaderASTPrerequisites.hpp"

#include <list>
#include <memory>
#include <unordered_map>
#include <vector>

namespace ast
{
	class BuddyAllocator
	{
	private:
		using PointerType = std::byte *;
		using ConstPointerType = std::byte const *;

		BuddyAllocator( BuddyAllocator const & ) = delete;
		BuddyAllocator & operator=( BuddyAllocator const & ) = delete;
		BuddyAllocator( BuddyAllocator && )noexcept = delete;
		BuddyAllocator & operator=( BuddyAllocator && )noexcept = delete;

	public:
		/**
		*	Constructor.
		*\param[in]	numLevels
		*	The allocator maximum tree size.
		*\param[in]	minBlockSize
		*	The minimum size for a block.
		*/
		BuddyAllocator( uint32_t numLevels
			, uint32_t minBlockSize );
		/**
		*	Reports memory leaks.
		*/
		~BuddyAllocator();
		/**
		*\param[in]	size
		*	The requested memory size.
		*\return
		*	\p true if there is enough remaining memory for given size.
		*/
		bool hasAvailable( size_t size )const;
		/**
		*	Allocates memory.
		*\param[in]	size
		*	The requested memory size.
		*\return
		*	The memory chunk.
		*/
		PointerType allocate( size_t size );
		/**
		*	Deallocates memory.
		*\param[in]	pointer
		*	The memory chunk.
		*/
		bool deallocate( PointerType pointer );
		/**
		*\return
		*	The pool total size.
		*/
		size_t getTotalSize()const;

		size_t getAlignSize()const;
		PointerType getPointer( uint32_t offset );
		size_t getOffset( ConstPointerType pointer )const;

	private:
		uint32_t doGetLevel( size_t size )const;
		size_t doGetLevelSize( uint32_t level )const;
		PointerType doAllocate( uint32_t level );
		void doMergeLevel( PointerType const & block
			, uint32_t index
			, uint32_t level );

	private:
		using FreeList = std::list< PointerType >;
		using PointerLevel = std::pair< size_t, uint32_t >;

	private:
		std::vector< std::byte > m_memory;
		uint32_t m_numLevels;
		uint32_t m_minBlockSize;
		std::vector< FreeList > m_freeLists;
		std::vector< PointerLevel > m_allocated;
	};

	class ShaderAllocator;

	enum class AllocationMode
	{
		eNone,
		eIncremental,
		eFragmented
	};

	struct MemoryCursor
	{
		ptrdiff_t index{};
		size_t offset{};
	};

	class ShaderAllocatorBlock
	{
	public:
		SDAST_API explicit ShaderAllocatorBlock( ShaderAllocator & allocator )noexcept;
		SDAST_API ShaderAllocatorBlock( ShaderAllocatorBlock const & rhs ) = delete;
		SDAST_API ShaderAllocatorBlock & operator=( ShaderAllocatorBlock const & rhs ) = delete;
		SDAST_API ShaderAllocatorBlock( ShaderAllocatorBlock && rhs )noexcept;
		SDAST_API ShaderAllocatorBlock & operator=( ShaderAllocatorBlock && rhs )noexcept;
		SDAST_API ~ShaderAllocatorBlock()noexcept;

		SDAST_API void * allocate( size_t size, size_t count = 1u );
		SDAST_API void deallocate( void * mem, size_t size, size_t count = 1u )noexcept;

		SDAST_API size_t report()const;

	private:
		ShaderAllocator * m_allocator;
		MemoryCursor m_savedCursor{};
	};

	class ShaderAllocator
	{
		friend class ShaderAllocatorBlock;

	public:
		SDAST_API explicit ShaderAllocator( AllocationMode allocationMode = AllocationMode::eFragmented );
		SDAST_API ~ShaderAllocator() = default;

		SDAST_API void * allocate( size_t size, size_t count = 1u );
		SDAST_API void deallocate( void * mem, size_t size, size_t count = 1u )noexcept;

		SDAST_API MemoryCursor getCursor()const noexcept;
		SDAST_API size_t getMemDiff( MemoryCursor const & cursor )const noexcept;
		SDAST_API size_t report()const;

		SDAST_API ShaderAllocatorBlockPtr getBlock()
		{
			return std::make_unique< ShaderAllocatorBlock >( *this );
		}

	private:
		struct Memory
		{
			static size_t constexpr BlockAllocSize = 1024 * 1024;

			explicit Memory( size_t size = BlockAllocSize )
				: data{ std::make_unique< std::vector< std::byte > >( std::max( size, BlockAllocSize ) ) }
			{
			}

			std::unique_ptr< std::vector< std::byte > > data;
			size_t offset{};
		};

	private:
		void flushTo( MemoryCursor const & cursor )noexcept;

	private:
		AllocationMode m_allocationMode{};
		std::unordered_map< size_t, std::unique_ptr< BuddyAllocator > > m_buddies;
		std::vector< Memory > m_memory;
		std::vector< Memory > m_pending;
		Memory * m_currentMemory{};
		size_t m_maxAllocated{};
	};
}

#endif
