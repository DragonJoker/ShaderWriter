/*
See LICENSE file in root folder
*/
#ifndef ___SDW_PushConstantBuffer_H___
#define ___SDW_PushConstantBuffer_H___
#pragma once

#include "ShaderWriter/CompositeTypes/StructHelper.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtPushConstantsBufferDecl.hpp>

namespace sdw
{
	class PushConstantBuffer
	{
	public:
		SDW_API PushConstantBuffer( ShaderWriter & writer
			, std::string const & blockName
			, std::string variableName
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eC
			, bool enabled = true );
		SDW_API PushConstantBuffer( ShaderWriter & writer
			, std::string const & name
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eC
			, bool enabled = true );
		SDW_API void end();

		SDW_API StructInstance declStructMember( std::string name
			, Struct const & s
			, bool enabled = true );
		SDW_API Array< StructInstance > declStructMember( std::string name
			, Struct const & s
			, uint32_t dimension
			, bool enabled = true );

		template< typename ValueT, typename ... ParamsT >
		ValueT declMember( std::string name
			, bool enabled = true
			, ParamsT && ... params );
		template< typename ValueT, typename ... ParamsT >
		Array< ValueT > declMember( std::string name
			, uint32_t dimension
			, bool enabled = true
			, ParamsT && ... params );
		template< typename ValueT, typename ... ParamsT >
		Array< ValueT > declMemberArray( std::string name
			, bool enabled = true
			, ParamsT && ... params );

		template< typename ValueT >
		ValueT getMember( std::string_view name
			, bool enabled = true )const;
		template< typename ValueT >
		Array< ValueT > getMemberArray( std::string_view name
			, bool enabled = true )const;

		bool isEnabled()const
		{
			return m_enabled;
		}

	private:
		ShaderWriter & m_writer;
		ast::ShaderBuilder & m_builder;
		stmt::PushConstantsBufferDeclPtr m_stmt;
		std::string m_name;
		ast::PcbInfo m_info;
		var::VariablePtr m_var;
		bool m_enabled;
	};

#if SDW_EnableStructHelper

	template< ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class PushConstantBufferHelperT
		: public StructHelperT< PushConstantBuffer, LayoutT, FieldsT... >
	{
	public:
		PushConstantBufferHelperT( ShaderWriter & writer, const std::string & name )
			: StructHelperT< PushConstantBuffer, LayoutT, FieldsT... >{ writer, name, LayoutT }
		{
		}
	};

	template< typename... FieldsT >
	using PushConstantBufferHelperStd140T = PushConstantBufferHelperT< ast::type::MemoryLayout::eStd140, FieldsT... >;
	template< typename... FieldsT >
	using PushConstantBufferHelperStd430T = PushConstantBufferHelperT< ast::type::MemoryLayout::eStd430, FieldsT... >;
	template< typename... FieldsT >
	using PushConstantBufferHelperScalarT = PushConstantBufferHelperT< ast::type::MemoryLayout::eScalar, FieldsT... >;
	template< typename... FieldsT >
	using PushConstantBufferHelperCT = PushConstantBufferHelperT< ast::type::MemoryLayout::eC, FieldsT... >;

#endif
}

#include "PushConstantBuffer.inl"

#endif
