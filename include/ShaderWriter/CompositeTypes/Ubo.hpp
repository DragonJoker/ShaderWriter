/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Ubo_H___
#define ___SDW_Ubo_H___
#pragma once

#include "ShaderWriter/CompositeTypes/StructHelper.hpp"
#include "ShaderWriter/Helpers.hpp"

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
		inline Ubo( ShaderWriter & writer
			, std::string name
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
		inline ValueT declMember( std::string name
			, bool enabled = true
			, ParamsT ... params );
		template< typename ValueT, typename ... ParamsT >
		inline Array< ValueT > declMember( std::string name
			, uint32_t dimension
			, bool enabled = true
			, ParamsT ... params );
		template< typename ValueT, typename ... ParamsT >
		inline Array< ValueT > declMemberArray( std::string name
			, bool enabled = true
			, ParamsT ... params );

		template< typename ValueT >
		inline ValueT getMember( std::string_view name
			, bool enabled = true )const;
		template< typename ValueT >
		inline Array< ValueT > getMemberArray( std::string_view name
			, bool enabled = true )const;

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

#if SDW_EnableStructHelper

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
		UboHelperT( ShaderWriter & writer
			, std::string name
			, LocationHelper location )
			: UboHelperT{ writer, std::move( name ), location.binding, location.set }
		{
		}
	};

	template< typename... FieldsT >
	using UboHelperStd140T = UboHelperT< ast::type::MemoryLayout::eStd140, FieldsT... >;
	template< typename... FieldsT >
	using UboHelperStd430T = UboHelperT< ast::type::MemoryLayout::eStd430, FieldsT... >;

#endif
}

#include "Ubo.inl"

#endif
