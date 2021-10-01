/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	namespace
	{
		type::StructPtr getStruct( type::TypePtr type )
		{
			while ( type->getKind() != type::Kind::eStruct )
			{
				if ( type->getKind() == type::Kind::ePointer )
				{
					type = static_cast< type::Pointer const & >( *type ).getPointerType();
				}
				else
				{
					break;
				}
			}

			assert( type->getKind() == type::Kind::eStruct );
			return std::static_pointer_cast< type::Struct >( type );
		}
	}

	StructInstance::StructInstance( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_type{ getStruct( getType() ) }
	{
	}
}
