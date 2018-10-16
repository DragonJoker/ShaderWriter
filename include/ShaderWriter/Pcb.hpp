/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Pcb_H___
#define ___Writer_Pcb_H___
#pragma once

#include "BoInfo.hpp"

#include <ASTGenerator/Stmt/StmtPushConstantsBufferDecl.hpp>

namespace sdw
{
	class Pcb
	{
	public:
		using Info = BoInfo;

		Pcb( Shader & shader
			, std::string const & name );
		void end();

		template< typename T >
		inline T declMember( std::string const & name );
		template< typename T >
		inline Array< T > declMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declMemberArray( std::string const & name );
		template< typename T >
		inline Optional< T > declMember( std::string const & name
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declMember( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declMemberArray( std::string const & name
			, bool enabled );
		template< typename T >
		inline T getMember( std::string const & name );
		template< typename T >
		inline Array< T > getMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name );
		template< typename T >
		inline Optional< T > getMember( std::string const & name
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > getMember( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > getMemberArray( std::string const & name
			, bool enabled );

	private:
		Shader & m_shader;
		stmt::PushConstantsBufferDeclPtr m_stmt;
		std::string m_name;
		Info m_info;
	};
}

#include "Pcb.inl"

#endif
