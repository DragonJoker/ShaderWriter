/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Ssbo_H___
#define ___SDW_Ssbo_H___

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	class Ssbo
	{
	public:
		SDW_API Ssbo( ShaderWriter & writer
			, std::string name
			, uint32_t bind
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		SDW_API void end();

		SDW_API StructInstance declStructMember( std::string name
			, Struct const & s
			, bool enabled = true );
		SDW_API Array< StructInstance > declStructMember( std::string name
			, Struct const & s
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline T declStructMember( std::string name
			, bool enabled = true );
		template< typename T >
		inline Array< T > declStructMember( std::string name
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline T declMember( std::string name
			, bool enabled = true );
		template< typename T >
		inline Array< T > declMember( std::string name
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declMemberArray( std::string name
			, bool enabled = true );
		template< typename T >
		inline T getMember( std::string_view name
			, bool enabled = true );
		template< typename T >
		inline Array< T > getMemberArray( std::string_view name
			, bool enabled = true );

		bool isEnabled()const
		{
			return m_enabled;
		}

	private:
		ShaderWriter & m_writer;
		ast::Shader & m_shader;
		std::string m_name;
		ast::InterfaceBlock m_interface;
		ast::SsboInfo m_info;
		var::VariablePtr m_var;
		stmt::ShaderBufferDeclPtr m_stmt;
		bool m_enabled;
	};
}

#include "Ssbo.inl"

#endif
