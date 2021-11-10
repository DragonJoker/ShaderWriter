/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeFragmentIO_H___
#define ___AST_TypeFragmentIO_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	struct FragmentInput
		: public Type
	{
		SDAST_API FragmentInput( TypePtr type
			, ast::FragmentOrigin origin
			, ast::FragmentCenter center );

		TypePtr getType()const
		{
			return m_type;
		}

		FragmentOrigin getOrigin()const
		{
			return m_origin;
		}

		FragmentCenter getCenter()const
		{
			return m_center;
		}

	private:
		TypePtr m_type;
		FragmentOrigin m_origin;
		FragmentCenter m_center;
	};
	using FragmentInputPtr = std::shared_ptr< FragmentInput >;

	inline FragmentInputPtr makeFragmentInputType( TypePtr type
		, ast::FragmentOrigin origin
		, ast::FragmentCenter center )
	{
		return std::make_shared< FragmentInput >( type
			, origin
			, center );
	}
}

#endif
