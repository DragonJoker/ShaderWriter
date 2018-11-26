/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Ssbo_H___
#define ___SDW_Ssbo_H___

#include "BoInfo.hpp"

#include <ShaderAST/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	class Ssbo
	{
	public:
		using Info = BoInfo;

		Ssbo( ShaderWriter & writer
			, std::string const & name
			, uint32_t bind
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430 );
		void end();

		StructInstance declMember( std::string const & name, Struct const & s );
		template< typename T >
		inline T declMember( std::string const & name );
		template< typename T >
		inline Array< T > declMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declMemberArray( std::string const & name );
		template< typename T >
		inline T getMember( std::string const & name );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name );

	private:
		Shader & m_shader;
		std::string m_name;
		Info m_info;
		var::VariablePtr m_var;
		stmt::ShaderBufferDeclPtr m_stmt;
	};
}

#include "Ssbo.inl"

#endif
