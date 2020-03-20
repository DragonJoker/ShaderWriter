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

namespace ast::vk
{
	template< typename ValueT >
	struct FixedSizeArrayT
		: private std::vector< ValueT >
	{
		using VecT = std::vector< ValueT >;

		inline FixedSizeArrayT()
			: VecT{}
		{
		}

		inline FixedSizeArrayT( ValueT const * begin
			, ValueT const * end )
			: VecT{ begin, end }
		{
		}

		inline FixedSizeArrayT( size_t count
			, ValueT const & value )
			: VecT{}
		{
			VecT::resize( count, value );
		}

		inline FixedSizeArrayT( ValueT const & value )
			: FixedSizeArrayT{ 1u, value }
		{
		}

		inline FixedSizeArrayT( FixedSizeArrayT const & rhs )
			: VecT{ rhs }
		{
		}

		inline FixedSizeArrayT( FixedSizeArrayT && rhs )
			: VecT{ std::move( rhs ) }
		{
		}

		inline FixedSizeArrayT & operator=( FixedSizeArrayT const & rhs )
		{
			VecT::operator=( rhs );
			return *this;
		}

		inline FixedSizeArrayT & operator=( FixedSizeArrayT && rhs )
		{
			VecT::operator=( std::move( rhs ) );
			return *this;
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
		, size_t CountOffsetT >
	struct ArrayHolder
	{
		using VecT = FixedSizeArrayT< ValueT >;

		inline ArrayHolder()
			: values{}
			, data{}
		{
			updateData( nullptr, 0u );
		}

		inline ArrayHolder( DataT data )
			: values{ ( ( *getCount( data ) && *getPtr( data ) )
				? VecT{ *getPtr( data ), *getPtr( data ) + *getCount( data ) }
				: ( *getCount( data )
					? [&data]()
						{
							VecT res{ size_t( *getCount( data ) ), ValueT{} };
							return res;
						}()
					: VecT{} ) ) }
			, data{ std::move( data ) }
		{
			updateData();
		}

		inline ArrayHolder( ValueT const * begin
			, ValueT const * end )
			: values{ values, end }
			, data{}
		{
			updateData();
		}

		inline ArrayHolder( ArrayHolder const & rhs )
			: values{ rhs.values }
			, data{ rhs.data }
		{
			updateData();
		}

		inline ArrayHolder( ArrayHolder && rhs )
			: values{ std::move( rhs.values ) }
			, data{ std::move( rhs.data ) }
		{
			rhs.data = {};
			updateData();
		}

		inline ArrayHolder & operator=( ArrayHolder const & rhs )
		{
			values = rhs.values;
			data = rhs.data;
			updateData();
			return *this;
		}

		inline ArrayHolder & operator=( ArrayHolder && rhs )
		{
			values = std::move( rhs.values );
			data = std::move( rhs.data );
			rhs.data = {};
			updateData();
			return *this;
		}

		inline ArrayHolder( ValueT const * values
			, size_t size )
			: ArrayHolder{ values, values + size }
		{
		}

		inline ArrayHolder( FixedSizeArrayT< ValueT > const & values )
			: ArrayHolder{ values.data(), values.size() }
		{
		}

		inline ArrayHolder( std::vector< ValueT > const & values )
			: ArrayHolder{ values.data(), values.size() }
		{
		}

		template< size_t SizeT >
		inline ArrayHolder( std::array< ValueT, SizeT > const & values )
			: ArrayHolder{ values.data(), SizeT }
		{
		}

		template< size_t SizeT >
		inline ArrayHolder( ValueT const ( &values )[SizeT] )
			: ArrayHolder{ values, SizeT }
		{
		}

		VecT values;
		DataT data;

	private:
		void updateData( ValueT * ptr
			, CountT size )
		{
			*getPtr( data ) = ptr;
			*getCount( data ) = size;
		}

		void updateData()
		{
			updateData( values.data()
				, CountT( values.size() ) );
		}

		static ValueT ** getPtr( DataT & data )
		{
			auto buffer = reinterpret_cast< uint8_t * >( &data );
			buffer += DataOffsetT;
			return reinterpret_cast< ValueT ** >( buffer );
		}

		static CountT * getCount( DataT & data )
		{
			auto buffer = reinterpret_cast< uint8_t * >( &data );
			buffer += CountOffsetT;
			return reinterpret_cast< CountT * >( buffer );
		}
	};
}

#endif
