/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Pcb_H___
#define ___SDW_Pcb_H___
#pragma once

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtPushConstantsBufferDecl.hpp>

namespace sdw
{
	class Pcb
	{
	public:
		SDW_API Pcb( ShaderWriter & writer
			, std::string const & name
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		SDW_API void end();

		SDW_API StructInstance declMember( std::string const & name
			, Struct const & s
			, bool enabled = true );
		template< typename T >
		inline T declMember( std::string const & name
			, bool enabled = true );
		template< typename T >
		inline Array< T > declMember( std::string const & name
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline T getMember( std::string const & name
			, bool enabled = true );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name
			, bool enabled = true );

		bool isEnabled()const
		{
			return m_enabled;
		}

	private:
		ShaderWriter & m_writer;
		ast::Shader & m_shader;
		stmt::PushConstantsBufferDeclPtr m_stmt;
		std::string m_name;
		ast::PcbInfo m_info;
		var::VariablePtr m_var;
		bool m_enabled;
	};
}

#include "Pcb.inl"

#endif
