/*
See LICENSE file in root folder
*/
#ifndef ___SDW_IOStructHelper_H___
#define ___SDW_IOStructHelper_H___

#include "ShaderWriter/CompositeTypes/MixedStructHelper.hpp"

#if SDW_EnableStructHelper

namespace sdw
{
	template< typename StructT
		, typename... FieldsT >
	class IOStructHelperT
		: public MixedStructHelperT< StructT
			, ast::type::MemoryLayout::eC
			, FieldsT... >
	{
		using MyHelper = MixedStructHelperT< StructT
			, ast::type::MemoryLayout::eC
			, FieldsT... >;

		using MyHelper::declMember;
		using MyHelper::declStructMember;
		using MyHelper::end;
		using MyHelper::getMember;
		using MyHelper::getMemberArray;
		using MyHelper::getFieldByName;

	protected:
		template< typename ... ParamsT >
		explicit IOStructHelperT( ParamsT && ... params )
			: MyHelper{ std::forward< ParamsT >( params )... }
		{
		}
	};
}

#endif

#endif
