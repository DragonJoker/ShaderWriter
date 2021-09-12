/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	StructInstance::StructInstance( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_type{ std::static_pointer_cast< type::Struct >( getType() ) }
	{
	}

	StructInstance & StructInstance::operator=( StructInstance const & rhs )
	{
		if ( getContainer() )
		{
			if ( isEnabled() )
			{
				auto & writer = findWriterMandat( *this, rhs );
				addStmt( writer
					, sdw::makeSimple( sdw::makeAssign( getType()
						, makeExpr( writer, *this )
						, makeExpr( writer, rhs ) ) ) );
			}
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}
}
