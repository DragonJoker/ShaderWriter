/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IOStructInstanceHelper_H___
#define ___SDW_IOStructInstanceHelper_H___
#pragma once

#include "MixedStructInstanceHelper.hpp"

#if SDW_EnableStructHelper

namespace sdw
{
	template< ast::var::Flag FlagT
		, StringLiteralT StructNameT
		, typename... FieldsT >
	class IOStructInstanceHelperT
		: public MixedStructInstanceHelperT< FlagT
			, StructNameT
			, ast::type::MemoryLayout::eC
			, FieldsT... >
	{
		using MyHelper = MixedStructInstanceHelperT< FlagT
			, StructNameT
			, ast::type::MemoryLayout::eC
			, FieldsT... >;

	public:
		~IOStructInstanceHelperT()noexcept override = default;
		IOStructInstanceHelperT( IOStructInstanceHelperT const & ) = default;
		IOStructInstanceHelperT( IOStructInstanceHelperT && )noexcept = default;

		IOStructInstanceHelperT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true )
			: MyHelper{ writer, std::move( expr ), enabled }
		{
		}

		IOStructInstanceHelperT & operator=( IOStructInstanceHelperT const & rhs )
		{
			MyHelper::operator=( rhs );
			return *this;
		}

		IOStructInstanceHelperT & operator=( IOStructInstanceHelperT && rhs )noexcept
		{
			MyHelper::operator=( std::move( rhs ) );
			return *this;
		}

		using MyHelper::getMember;
		using MyHelper::getMemberArray;
	};
}
#endif

#endif
