/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Pcb_H___
#define ___Writer_Pcb_H___
#pragma once

#include "BoInfo.hpp"

namespace sdw
{
	class Pcb
	{
	public:
		enum class Layout
		{
			eStd430,
		};

		Pcb( Shader & shader
			, std::string const & name
			, std::string const & instance );
		void end();

		template< typename T >
		inline T declMember( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Array< T > declMember( std::string const & name
			, uint32_t dimension
			, uint32_t location );
		template< typename T >
		inline Array< T > declMemberArray( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< T > declMember( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declMember( std::string const & name
			, uint32_t dimension
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declMemberArray( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline T getMember( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Array< T > getMember( std::string const & name
			, uint32_t location
			, uint32_t dimension );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< T > getMember( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > getMember( std::string const & name
			, uint32_t dimension
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > getMemberArray( std::string const & name
			, uint32_t location
			, bool enabled );

	private:
		Shader & m_shader;
		std::string m_name;
		std::string m_instance;
		uint32_t m_count{ 0u };
	};
}

#include "Pcb.inl"

#endif
