/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtAccelerationStructureDecl_H___
#define ___AST_StmtAccelerationStructureDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class AccelerationStructureDecl
		: public Stmt
	{
	public:
		SDAST_API AccelerationStructureDecl( var::VariablePtr variable
			, uint32_t bindingPoint
			, uint32_t bindingSet );

		SDAST_API void accept( VisitorPtr vis )override;

		var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		uint32_t getDescriptorSet()const
		{
			return m_bindingSet;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using AccelerationStructureDeclPtr = std::unique_ptr< AccelerationStructureDecl >;

	inline AccelerationStructureDeclPtr makeAccelerationStructureDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< AccelerationStructureDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}
}

#endif
