/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtSamplerDecl_H___
#define ___AST_StmtSamplerDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class SamplerDecl
		: public Stmt
	{
	public:
		SamplerDecl( var::VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		void accept( VisitorPtr vis )override;

		inline var::Variable const & getVariable()const
		{
			return *m_variable;
		}

		inline uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		inline uint32_t getBindingSet()const
		{
			return m_bindingSet;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using SamplerDeclPtr = std::unique_ptr< SamplerDecl >;

	inline SamplerDeclPtr makeSamplerDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< SamplerDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}
}

#endif
