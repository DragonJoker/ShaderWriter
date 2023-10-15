/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IOStructInstanceHelper_H___
#define ___SDW_IOStructInstanceHelper_H___
#pragma once

#if SDW_EnableStructHelper

#include "StructInstance.hpp"

namespace sdw
{
	template< ast::var::Flag FlagT
		, StringLiteralT StructNameT
		, typename... FieldsT >
	class IOStructInstanceHelperT
		: public StructInstance
	{
		static_assert( sizeof...( FieldsT ) > 0
			, "A structure must have at least one field" );

	public:
		~IOStructInstanceHelperT() override = default;
		IOStructInstanceHelperT( IOStructInstanceHelperT const & ) = default;
		IOStructInstanceHelperT( IOStructInstanceHelperT && ) = default;

		IOStructInstanceHelperT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true )
			: StructInstance{ writer, std::move( expr ), enabled }
		{
		}

		IOStructInstanceHelperT & operator=( IOStructInstanceHelperT const & rhs )
		{
			StructInstance::operator=( rhs );
			return *this;
		}

		IOStructInstanceHelperT & operator=( IOStructInstanceHelperT && rhs )
		{
			StructInstance::operator=( std::move( rhs ) );
			return *this;
		}

		template< sdw::StringLiteralT FieldNameT >
		constexpr static auto getFieldByName()
		{
			return doGetFieldByName< FieldNameT, FieldsT... >();
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

		static type::IOStructPtr makeIOType( type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
				, std::string( StructNameT.value ) + ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Out" }
					: std::string{ "In" } )
				, FlagT );

			if ( result->empty() )
			{
				( result->declMember( std::string( FieldsT::Name )
					, FieldsT::TypeT::makeType( cache )
					, FieldsT::ArraySize
					, FieldsT::Location )
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
