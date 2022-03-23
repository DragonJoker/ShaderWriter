/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructuredSsbo_H___
#define ___SDW_StructuredSsbo_H___

#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/Helpers.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	template< typename InstanceT >
	class ArraySsboT
	{
	public:
		ArraySsboT( ShaderWriter & writer
			, std::string instanceName
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout
			, uint32_t bind
			, uint32_t set
			, bool enabled );

		ArraySsboT( ShaderWriter & writer
			, std::string instanceName
			, ast::type::BaseStructPtr dataType
			, uint32_t bind
			, uint32_t set
			, bool enabled );

		ArraySsboT( ShaderWriter & writer
			, std::string instanceName
			, uint32_t bind
			, uint32_t set
			, bool enabled );

		// From a buffer reference
		ArraySsboT( ShaderWriter & writer
			, std::string instanceName
			, ast::expr::ExprPtr addressExpr
			, bool enabled );

		ArraySsboT(ShaderWriter& writer
			, std::string instanceName
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout
			, LocationHelper location
			, bool enabled);

		ArraySsboT(ShaderWriter& writer
			, std::string instanceName
			, ast::type::BaseStructPtr dataType
			, LocationHelper location
			, bool enabled);

		ArraySsboT(ShaderWriter& writer
			, std::string instanceName
			, LocationHelper location
			, bool enabled);

		InstanceT operator[]( uint32_t index );
		InstanceT operator[]( UInt const & index );

		bool isEnabled()const
		{
			return m_enabled;
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache
			, std::string const & name
			, ast::type::MemoryLayout layout
			, bool enabled );

	private:
		ShaderWriter & m_writer;
		ast::Shader & m_shader;
		std::string m_name;
		ast::InterfaceBlock m_interface;
		ast::SsboInfo m_info;
		type::BaseStructPtr m_ssboType;
		var::VariablePtr m_dataVar;
		var::VariablePtr m_ssboVar;
		bool m_enabled;
	};

	SDW_API void registerSsbo( ShaderWriter & writer
		, std::string name
		, SsboInfo const & info );
}

#include "ArraySsbo.inl"

#endif
