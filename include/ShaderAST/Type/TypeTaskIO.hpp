/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeTaskIO_H___
#define ___AST_TypeTaskIO_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	class TaskPayloadNV
		: public Type
	{
	public:
		SDAST_API explicit TaskPayloadNV( TypePtr type );

		type::TypePtr getType()const
		{
			return m_type;
		}

	private:
		TypePtr m_type;
	};
	using TaskPayloadNVPtr = std::shared_ptr< TaskPayloadNV >;

	inline TaskPayloadNVPtr makeTaskPayloadNVType( TypePtr type )
	{
		return std::make_shared< TaskPayloadNV >( type );
	}

	class TaskPayload
		: public Type
	{
	public:
		SDAST_API explicit TaskPayload( TypePtr type );

		type::TypePtr getType()const
		{
			return m_type;
		}

	private:
		TypePtr m_type;
	};
	using TaskPayloadPtr = std::shared_ptr< TaskPayload >;

	inline TaskPayloadPtr makeTaskPayloadType( TypePtr type )
	{
		return std::make_shared< TaskPayload >( type );
	}
}

#endif
