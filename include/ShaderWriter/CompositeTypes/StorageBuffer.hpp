/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StorageBuffer_H___
#define ___SDW_StorageBuffer_H___
#pragma once

#include "ShaderWriter/CompositeTypes/StructHelper.hpp"
#include "ShaderWriter/Helpers.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	class StorageBuffer
	{
	public:
		SDW_API StorageBuffer( ShaderWriter & writer
			, std::string const & blockName
			, std::string variableName
			, uint32_t bind
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		StorageBuffer( ShaderWriter & writer
			, std::string const & name
			, uint32_t bind
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		StorageBuffer( ShaderWriter & writer
			, std::string const & blockName
			, std::string variableName
			, LocationHelper location
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		StorageBuffer( ShaderWriter & writer
			, std::string const & name
			, LocationHelper location
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
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
		std::string m_name;
		ast::InterfaceBlock m_interface;
		ast::SsboInfo m_info;
		bool m_redeclare;
		var::VariablePtr m_var;
		stmt::ShaderBufferDeclPtr m_stmt;
		bool m_enabled;
	};

#if SDW_EnableStructHelper

	template< ast::type::MemoryLayout LayoutT
		, typename ... FieldsT >
	class StorageBufferHelperT
		: public StructHelperT< StorageBuffer, LayoutT, FieldsT... >
	{
	public:
		StorageBufferHelperT( ShaderWriter & writer, const std::string & name, uint32_t bind, uint32_t set )
			: StructHelperT< StorageBuffer, LayoutT, FieldsT... >{ writer, name, bind, set, LayoutT }
		{
		}
		StorageBufferHelperT( ShaderWriter & writer, const std::string & name, LocationHelper location )
			: StorageBufferHelperT{ writer, name, location.binding, location.set }
		{
		}
	};

	template< typename... FieldsT >
	using StorageBufferHelperStd140T = StorageBufferHelperT< ast::type::MemoryLayout::eStd140, FieldsT... >;
	template< typename... FieldsT >
	using StorageBufferHelperStd430T = StorageBufferHelperT< ast::type::MemoryLayout::eStd430, FieldsT... >;
	template< typename... FieldsT >
	using StorageBufferHelperScalarT = StorageBufferHelperT< ast::type::MemoryLayout::eScalar, FieldsT... >;

#endif
}

#include "StorageBuffer.inl"

#endif
