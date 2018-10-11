/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Var/Variable.hpp"

namespace ast::var
{
	Variable::Variable( type::TypePtr type
		, std::string name )
		: m_type{ type }
		, m_name{ std::move( name ) }
		, m_flags{ 0u }
	{
	}

	Variable::Variable( type::TypePtr type
		, std::string name
		, uint32_t flags )
		: m_type{ type }
		, m_name{ std::move( name ) }
		, m_flags{ flags }
	{
	}
	
	Variable::Variable( type::TypePtr type
		, std::string name
		, Flag flag )
		: m_type{ type }
		, m_name{ std::move( name ) }
		, m_flags{ uint32_t( flag ) }
	{
	}

	Variable::~Variable()
	{
	}
}
