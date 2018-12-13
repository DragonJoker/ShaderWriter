/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructuredSsbo_H___
#define ___SDW_StructuredSsbo_H___

#include "BoInfo.hpp"
#include "ShaderWriter/BaseTypes/UInt.hpp"

#include <ShaderAST/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	template< typename InstanceT >
	class ArraySsboT
	{
	public:
		ArraySsboT( ShaderWriter & writer
			, std::string const & name
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout
			, uint32_t bind
			, uint32_t set );

		ArraySsboT( ShaderWriter & writer
			, std::string const & name
			, ast::type::StructPtr dataType
			, uint32_t bind
			, uint32_t set );

		InstanceT operator[]( uint32_t index );
		InstanceT operator[]( UInt const & index );

	private:
		Shader & m_shader;
		std::string m_name;
		SsboInfo m_info;
		type::StructPtr m_ssboType;
		var::VariablePtr m_dataVar;
		var::VariablePtr m_ssboVar;
	};

	SDW_API void registerSsbo( Shader & shader, std::string const & name, SsboInfo const & info );
}

#include "StructuredSsbo.inl"

#endif
