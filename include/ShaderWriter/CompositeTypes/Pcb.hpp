/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Pcb_H___
#define ___SDW_Pcb_H___
#pragma once

#include "ShaderWriter/CompositeTypes/StructHelper.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtPushConstantsBufferDecl.hpp>

namespace sdw
{
	class Pcb
	{
	public:
		SDW_API Pcb( ShaderWriter & writer
			, std::string name
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
		stmt::PushConstantsBufferDeclPtr m_stmt;
		std::string m_name;
		ast::PcbInfo m_info;
		var::VariablePtr m_var;
		bool m_enabled;
	};

	template< ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class PcbHelperT
		: public StructHelperT< Pcb, LayoutT, FieldsT... >
	{
	public:
		PcbHelperT( ShaderWriter & writer, const std::string & name )
			: StructHelperT< Pcb, LayoutT, FieldsT... >{ writer, name, LayoutT }
		{
		}
	};

	template< typename... FieldsT >
	using PcbHelperStd140T = PcbHelperT< ast::type::MemoryLayout::eStd140, FieldsT... >;
	template< typename... FieldsT >
	using PcbHelperStd430T = PcbHelperT< ast::type::MemoryLayout::eStd430, FieldsT... >;
	template< typename... FieldsT >
	using PcbHelperScalarT = PcbHelperT< ast::type::MemoryLayout::eScalar, FieldsT... >;
	template< typename... FieldsT >
	using PcbHelperCT = PcbHelperT< ast::type::MemoryLayout::eC, FieldsT... >;
}

#include "Pcb.inl"

#endif
