/*
See LICENSE file in root folder
*/
#ifndef ___SDW_ArrayStorageBuffer_H___
#define ___SDW_ArrayStorageBuffer_H___

#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/Helpers.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	template< typename InstanceT >
	class ArrayStorageBufferT
	{
	public:
		ArrayStorageBufferT( ShaderWriter & writer
			, std::string instanceName
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout
			, uint32_t bind
			, uint32_t set
			, bool enabled );

		ArrayStorageBufferT( ShaderWriter & writer
			, std::string instanceName
			, ast::type::BaseStructPtr dataType
			, uint32_t bind
			, uint32_t set
			, bool enabled );

		template< typename ... ParamsT >
		ArrayStorageBufferT( ShaderWriter & writer
			, std::string instanceName
			, uint32_t bind
			, uint32_t set
			, bool enabled
			, ParamsT && ... params );

		// From a buffer reference
		ArrayStorageBufferT( ShaderWriter & writer
			, std::string instanceName
			, ast::expr::ExprPtr addressExpr
			, bool enabled );

		ArrayStorageBufferT(ShaderWriter& writer
			, std::string instanceName
			, ast::type::TypePtr dataType
			, ast::type::MemoryLayout layout
			, LocationHelper location
			, bool enabled );

		ArrayStorageBufferT(ShaderWriter& writer
			, std::string instanceName
			, ast::type::BaseStructPtr dataType
			, LocationHelper location
			, bool enabled );

		template< typename ... ParamsT >
		ArrayStorageBufferT(ShaderWriter& writer
			, std::string instanceName
			, LocationHelper location
			, bool enabled
			, ParamsT && ... params );

		InstanceT operator[]( uint32_t index )const;
		InstanceT operator[]( UInt32 const & index )const;

		bool isEnabled()const
		{
			return m_enabled;
		}

		template< typename ... ParamsT >
		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache
			, std::string const & name
			, ast::type::MemoryLayout layout
			, bool enabled
			, ParamsT && ... params );

	private:
		ShaderWriter & m_writer;
		ast::ShaderBuilder & m_builder;
		std::string m_name;
		bool m_redeclare;
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

#include "ArrayStorageBuffer.inl"

#endif
