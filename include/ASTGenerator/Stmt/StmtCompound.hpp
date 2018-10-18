/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtCompound_H___
#define ___AST_StmtCompound_H___
#pragma once

#include "StmtContainer.hpp"

namespace ast::stmt
{
	class Compound
		: public Container
	{
	protected:
		Compound( Kind kind );

	public:
		Compound();

		void accept( VisitorPtr vis )override;
	};
	using CompoundPtr = std::unique_ptr< Compound >;

	inline std::unique_ptr< Compound > makeCompound()
	{
		return std::make_unique< Compound >();
	}
}

#endif
