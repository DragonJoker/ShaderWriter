/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Ubo_H___
#define ___SDW_Ubo_H___
#pragma once

#include "ShaderWriter/CompositeTypes/StructHelper.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtConstantBufferDecl.hpp>

namespace sdw
{
	class Ubo
	{
	public:
		SDW_API Ubo( ShaderWriter & writer
			, std::string name
			, uint32_t bind
			, uint32_t set
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
		stmt::ConstantBufferDeclPtr m_stmt;
		std::string m_name;
		ast::InterfaceBlock m_interface;
		ast::UboInfo m_info;
		var::VariablePtr m_var;
		bool m_enabled;
	};

	template< ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class UboHelperT
		: public StructHelperT< Ubo, LayoutT, FieldsT... >
	{
	public:
		UboHelperT( ShaderWriter & writer
			, std::string name
			, uint32_t bind
			, uint32_t set )
			: StructHelperT< Ubo, LayoutT, FieldsT... >{ writer, std::move( name ), bind, set, LayoutT }
		{
		}
	};

	template< typename... FieldsT >
	using UboHelperStd140T = UboHelperT< ast::type::MemoryLayout::eStd140, FieldsT... >;
	template< typename... FieldsT >
	using UboHelperStd430T = UboHelperT< ast::type::MemoryLayout::eStd430, FieldsT... >;
}

#include "Ubo.inl"

#endif
