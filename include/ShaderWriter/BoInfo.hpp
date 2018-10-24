/*
See LICENSE file in root folder
*/
#ifndef ___SDW_BoInfo_H___
#define ___SDW_BoInfo_H___
#pragma once

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	struct BoInfo
	{
		BoInfo( uint32_t bind
			, uint32_t set )
			: m_bind{ bind }
			, m_set{ set }
		{
		}

		inline void registerMember( std::string const & name, type::TypePtr type )
		{
			m_members.emplace( name, type );
		}
		
		inline type::TypePtr getMember( std::string const & name )const
		{
			return m_members.at( name );
		}

		inline uint32_t getBindingPoint()const
		{
			return m_bind;
		}

		inline uint32_t getSetPoint()const
		{
			return m_set;
		}

	private:
		uint32_t m_bind;
		uint32_t m_set;
		std::map< std::string, type::TypePtr > m_members;
	};
}

#endif
