/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructInstanceHelper_H___
#define ___SDW_StructInstanceHelper_H___
#pragma once

#if SDW_EnableStructHelper

#include "StructInstance.hpp"

namespace sdw
{
	template< StringLiteralT StructNameT
		, ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class StructInstanceHelperT
		: public StructInstance
	{
		static_assert( sizeof...( FieldsT ) > 0
			, "A structure must have at least one field" );

	public:
		~StructInstanceHelperT() override = default;
		StructInstanceHelperT( StructInstanceHelperT const & ) = default;
		StructInstanceHelperT( StructInstanceHelperT && ) = default;

		StructInstanceHelperT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true )
			: StructInstance{ writer, std::move( expr ), enabled }
		{
		}

		StructInstanceHelperT & operator=( StructInstanceHelperT const & rhs )
		{
			StructInstance::operator=( rhs );
			return *this;
		}

		StructInstanceHelperT & operator=( StructInstanceHelperT && rhs )
		{
			StructInstance::operator=( std::move( rhs ) );
			return *this;
		}

		template< sdw::StringLiteralT FieldNameT >
		constexpr static auto getFieldByName()
		{
			return doGetFieldByName<FieldNameT, FieldsT...>();
		}

		template< sdw::StringLiteralT FieldNameT >
		constexpr static bool hasFieldByName()
		{
			return ( ... || ( std::string_view( FieldNameT.value ) == FieldsT::Name ) );
		}

		template< sdw::StringLiteralT FieldNameT >
		auto getMember()const
		{
			static_assert( hasFieldByName< FieldNameT >() );
			using FieldT = decltype( getFieldByName< FieldNameT >() );
			return FieldT::template get( *this );
		}

		static type::BaseStructPtr makeType( type::TypesCache & cache )
		{
			auto result = cache.getStruct( LayoutT
				, std::string( StructNameT.value ) );

			if ( result->empty() )
			{
				( result->declMember( std::string( FieldsT::Name )
					, typeEnum< typename FieldsT::TypeT >
					, FieldsT::ArraySize )
					, ... );
			}

			return result;
		}

		using StructInstance::getMember;
		using StructInstance::getMemberArray;

	private:
		template< sdw::StringLiteralT FieldNameT >
		constexpr static auto doGetFieldByName()
		{
			return sdw::Void{};
		}

		template< sdw::StringLiteralT FieldNameT, typename FieldU, typename... FieldsU >
		constexpr static auto doGetFieldByName()
		{
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

#endif
