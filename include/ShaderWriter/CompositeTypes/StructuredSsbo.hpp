/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructuredSsbo_H___
#define ___SDW_StructuredSsbo_H___

#include "BoInfo.hpp"

#include <ASTGenerator/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	class StructuredSsbo
	{
	public:
		using Info = BoInfo;

		StructuredSsbo( ShaderWriter & writer
			, std::string const & name
			, Struct const & dataType
			, uint32_t bind
			, uint32_t set );

		StructInstance operator[]( uint32_t index );
		StructInstance operator[]( UInt index );

	private:
		Shader & m_shader;
		std::string m_name;
		Info m_info;
		type::StructPtr m_ssboType;
		var::VariablePtr m_dataVar;
		var::VariablePtr m_ssboVar;
	};
}

#include "StructuredSsbo.inl"

#endif
