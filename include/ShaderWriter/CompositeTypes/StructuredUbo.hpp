/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructuredUbo_H___
#define ___SDW_StructuredUbo_H___

#include "ShaderWriter/BaseTypes/UInt.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	template< typename InstanceT >
	class ArrayUboT
	{
	public:
		ArrayUboT( ShaderWriter & writer
			, std::string const & name
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout
			, uint32_t bind
			, uint32_t set );

		ArrayUboT( ShaderWriter & writer
			, std::string const & name
			, ast::type::StructPtr dataType
			, uint32_t bind
			, uint32_t set );

		InstanceT operator[]( uint32_t index );
		InstanceT operator[]( UInt const & index );

	private:
		ast::Shader & m_shader;
		std::string m_name;
		ast::InterfaceBlock m_interface;
		ast::SsboInfo m_info;
		type::StructPtr m_ssboType;
		var::VariablePtr m_dataVar;
		var::VariablePtr m_ssboVar;
	};

	SDW_API void registerUbo( Shader & shader, std::string const & name, SsboInfo const & info );
}

#include "StructuredUbo.inl"

#endif
