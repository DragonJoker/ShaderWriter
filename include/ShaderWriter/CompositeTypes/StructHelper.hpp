/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructHelper_H___
#define ___SDW_StructHelper_H___

#include "ShaderWriter/BaseTypes/Void.hpp"

namespace sdw
{
	template< size_t N >
	struct StringLiteralT
	{
		constexpr StringLiteralT( const char( &str )[N] )
		{
			std::copy_n( str, N, value );
		}

		char value[N];
	};
	// Help CTAD
	template< size_t N >
	StringLiteralT( const char( &str )[N] )->StringLiteralT< N >;

	template< typename FieldTypeT
		, StringLiteralT FieldNameT >
	struct StructFieldT
	{
		using TypeT = FieldTypeT;
		static constexpr std::string_view Name = FieldNameT.value;
		static constexpr uint32_t ArraySize = sdw::type::NotArray;

		template< typename HolderT >
		static void decl( HolderT & h )
		{
			h.template declMember< TypeT >( std::string( Name ) );
		}

		template< typename HolderT >
		static auto get( HolderT & h )
		{
			return h.template getMember< TypeT >( Name );
		}
	};

	template< typename FieldTypeT
		, StringLiteralT FieldNameT
		, uint32_t ArraySizeT >
	struct StructFieldArrayT
	{
		using TypeT = FieldTypeT;
		static constexpr std::string_view Name = FieldNameT.value;
		static constexpr uint32_t ArraySize = ArraySizeT;

		template< typename HolderT >
		static void decl( HolderT & h )
		{
			h.template declMember< TypeT >( std::string( Name ), ArraySize );
		}

		template< typename HolderT >
		static auto get( HolderT & h )
		{
			return h.template getMemberArray< TypeT >( Name );
		}
	};

	template< typename StructT
		, ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class StructHelperT : public StructT
	{
		static_assert( sizeof...( FieldsT ) > 0
			, "A structure must have at least one field" );

		struct EndType {};

		using StructT::declMember;
		using StructT::declStructMember;
		using StructT::end;
		using StructT::getMember;
		using StructT::getMemberArray;

	public:
		template< sdw::StringLiteralT FieldNameT >
		constexpr static auto getFieldByName()
		{
			return doGetFieldByName< FieldNameT, FieldsT..., EndType >();
		}

		template< sdw::StringLiteralT FieldNameT >
		using Field = decltype( getFieldByName< FieldNameT >() );

		template< sdw::StringLiteralT FieldNameT >
		auto getMember()
		{
			return Field< FieldNameT >::template get< StructT >( *this );
		}

	protected:
		template< typename ... ParamsT >
		StructHelperT( ParamsT && ... params )
			: StructT{ std::forward< ParamsT >( params )... }
		{
			( FieldsT::template decl< StructT >( *this ), ... );
			end();
		}

	private:
		template< sdw::StringLiteralT FieldNameT, typename FieldU, typename... FieldsU >
		constexpr static auto doGetFieldByName()
		{
			static_assert( not std::is_same_v<FieldU, EndType>, "That field does not exist in this structure" );

			if constexpr ( std::string_view( FieldNameT.value ) == FieldU::Name )
			{
				return FieldU{};
			}
			else
			{
				return doGetFieldByName< FieldNameT, FieldsU... >();
			}
		}
	};
}

#endif
