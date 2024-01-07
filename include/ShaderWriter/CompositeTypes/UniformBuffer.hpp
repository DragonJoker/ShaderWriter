/*
See LICENSE file in root folder
*/
#ifndef ___SDW_UniformBuffer_H___
#define ___SDW_UniformBuffer_H___
#pragma once

#include "ShaderWriter/CompositeTypes/StructHelper.hpp"
#include "ShaderWriter/Helpers.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtConstantBufferDecl.hpp>

namespace sdw
{
	class UniformBuffer
	{
	public:
		SDW_API UniformBuffer( ShaderWriter & writer
			, std::string const & blockName
			, std::string variableName
			, uint32_t bind
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140
			, bool enabled = true );
		UniformBuffer( ShaderWriter & writer
			, std::string const & name
			, uint32_t bind
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140
			, bool enabled = true );
		UniformBuffer( ShaderWriter & writer
			, std::string const & blockName
			, std::string variableName
			, LocationHelper location
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140
			, bool enabled = true );
		UniformBuffer( ShaderWriter & writer
			, std::string const & name
			, LocationHelper location
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140
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
		stmt::ConstantBufferDeclPtr m_stmt;
		std::string m_name;
		ast::InterfaceBlock m_interface;
		ast::UboInfo m_info;
		var::VariablePtr m_var;
		bool m_enabled;
	};

#if SDW_EnableStructHelper

	template< ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class UniformBufferHelperT
		: public StructHelperT< UniformBuffer, LayoutT, FieldsT... >
	{
	public:
		UniformBufferHelperT( ShaderWriter & writer
			, std::string name
			, uint32_t bind
			, uint32_t set )
			: StructHelperT< UniformBuffer, LayoutT, FieldsT... >{ writer, std::move( name ), bind, set, LayoutT }
		{
		}
		UniformBufferHelperT( ShaderWriter & writer
			, std::string name
			, LocationHelper location )
			: UniformBufferHelperT{ writer, std::move( name ), location.binding, location.set }
		{
		}
	};

	template< typename... FieldsT >
	using UniformBufferHelperStd140T = UniformBufferHelperT< ast::type::MemoryLayout::eStd140, FieldsT... >;
	template< typename... FieldsT >
	using UniformBufferHelperStd430T = UniformBufferHelperT< ast::type::MemoryLayout::eStd430, FieldsT... >;

#endif
}

#include "UniformBuffer.inl"

#endif
