/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeComputeIO_H___
#define ___AST_TypeComputeIO_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	struct ComputeInput
		: public Type
	{
		SDAST_API ComputeInput( TypePtr type
			, uint32_t localSizeX
			, uint32_t localSizeY
			, uint32_t localSizeZ );

		type::TypePtr getType()const
		{
			return m_type;
		}

		uint32_t getLocalSizeX()const
		{
			return m_localSizeX;
		}

		uint32_t getLocalSizeY()const
		{
			return m_localSizeY;
		}

		uint32_t getLocalSizeZ()const
		{
			return m_localSizeZ;
		}

	private:
		TypePtr m_type;
		uint32_t m_localSizeX;
		uint32_t m_localSizeY;
		uint32_t m_localSizeZ;
	};
	using ComputeInputPtr = std::shared_ptr< ComputeInput >;

	inline ComputeInputPtr makeComputeInputType( TypePtr type
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
	{
		return std::make_shared< ComputeInput >( type
			, localSizeX
			, localSizeY
			, localSizeZ );
	}
}

#endif
