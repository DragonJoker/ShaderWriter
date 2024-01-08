/*
See LICENSE file in root folder
*/
#ifndef ___SDWVK_ArrayHolder_H___
#define ___SDWVK_ArrayHolder_H___

#include "ShaderDataPtr.hpp"

#include <array>
#include <optional>
#include <variant>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

namespace ast::vk
{
	template< typename ValueT >
	struct FixedSizeArrayT
		: private std::vector< ValueT >
	{
		using VecT = std::vector< ValueT >;

		FixedSizeArrayT()
			: VecT{}
		{
		}

		FixedSizeArrayT( ValueT const * pbegin
			, ValueT const * pend )
			: VecT{ pbegin, pend }
		{
		}

		FixedSizeArrayT( size_t count
			, ValueT const & value )
			: VecT{}
		{
			VecT::resize( count, value );
		}

		explicit FixedSizeArrayT( ValueT const & value )
			: FixedSizeArrayT{ 1u, value }
		{
		}

		using VecT::empty;
		using VecT::data;
		using VecT::size;
		using VecT::begin;
		using VecT::end;
		using VecT::cbegin;
		using VecT::cend;
		using VecT::operator[];
		using VecT::at;
	};

	template< typename DataT
		, typename ValueT
		, typename CountT
		, size_t DataOffsetT
		, size_t CountOffsetT
		, size_t DivisorT >
	struct ArrayHolder
	{
		using VecT = FixedSizeArrayT< ValueT >;

		ArrayHolder()
		{
			updateData( nullptr, 0u );
		}

		explicit ArrayHolder( DataT pdata )
			: values{ ( ( *getCount( pdata ) && *getPtr( pdata ) )
				? VecT{ *getPtr( pdata ), *getPtr( pdata ) + ( *getCount( pdata ) / DivisorT ) }
				: ( *getCount( pdata )
					? [&pdata]()
						{
							VecT res{ size_t( *getCount( pdata ) / DivisorT ), ValueT{} };
							return res;
						}()
					: VecT{} ) ) }
			, data{ std::move( pdata ) }
		{
			updateData();
		}

		ArrayHolder( ValueT const * begin
			, ValueT const * end )
			: values{ begin, end }
		{
			updateData();
		}

		ArrayHolder( ArrayHolder const & rhs )
			: values{ rhs.values }
			, data{ rhs.data }
		{
			updateData();
		}

		ArrayHolder( ArrayHolder && rhs )noexcept
			: values{ std::move( rhs.values ) }
			, data{ std::move( rhs.data ) }
		{
			rhs.data = {};
			updateData();
		}

		ArrayHolder & operator=( ArrayHolder const & rhs )
		{
			values = rhs.values;
			data = rhs.data;
			updateData();
			return *this;
		}

		ArrayHolder & operator=( ArrayHolder && rhs )noexcept
		{
			values = std::move( rhs.values );
			data = std::move( rhs.data );
			rhs.data = {};
			updateData();
			return *this;
		}

		ArrayHolder( ValueT const * pvalues
			, size_t size )
			: ArrayHolder{ pvalues, pvalues + size }
		{
		}

		explicit ArrayHolder( FixedSizeArrayT< ValueT > const & rhs )
			: ArrayHolder{ rhs.data(), rhs.size() }
		{
		}

		explicit ArrayHolder( std::vector< ValueT > const & rhs )
			: ArrayHolder{ rhs.data(), rhs.size() }
		{
		}

		template< size_t SizeT >
		explicit ArrayHolder( std::array< ValueT, SizeT > const & rhs )
			: ArrayHolder{ rhs.data(), SizeT }
		{
		}

		template< size_t SizeT >
		explicit ArrayHolder( ValueT const ( &rhs )[SizeT] )
			: ArrayHolder{ rhs, SizeT }
		{
		}

		~ArrayHolder() = default;

		VecT values{};
		DataT data{};

	private:
		void updateData( ValueT * ptr
			, CountT size )
		{
			*getPtr( data ) = ptr;
			*getCount( data ) = size * DivisorT;
		}

		void updateData()
		{
			updateData( values.data()
				, CountT( values.size() ) );
		}

		static ValueT ** getPtr( DataT & data )
		{
			auto buffer = reinterpret_cast< std::byte * >( &data );
			buffer += DataOffsetT;
			return reinterpret_cast< ValueT ** >( buffer );
		}

		static CountT * getCount( DataT & data )
		{
			auto buffer = reinterpret_cast<std::byte* >( &data );
			buffer += CountOffsetT;
			return reinterpret_cast< CountT * >( buffer );
		}
	};
}

#pragma GCC diagnostic pop

#endif
