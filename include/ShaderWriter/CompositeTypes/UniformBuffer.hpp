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
	struct UniformBuffer
		: public Value
	{
		SDW_DeclValue( SDW_INL_API, UniformBuffer );

		SDW_API UniformBuffer( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		SDW_INL_API void end()
		{
		}

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

		SDW_API static ast::type::UniformBufferPtr makeType( ast::type::TypesCache & cache
			, std::string const & name
			, ast::type::MemoryLayout layout );

	private:
		SDW_API expr::ExprPtr makeMbrSelect( uint32_t mbrIndex )const;
		SDW_API expr::ExprPtr makeMbrSelect( std::string_view name )const;

	private:
		ast::ShaderBuilder & m_builder;
		ast::type::UniformBufferPtr m_buffer;
	};

#if SDW_EnableStructHelper

	template< ast::type::MemoryLayout LayoutT
		, typename... FieldsT >
	class UniformBufferHelperT
		: public StructHelperT< UniformBuffer, LayoutT, FieldsT... >
	{
	public:
		UniformBufferHelperT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true )
			: StructHelperT< UniformBuffer, LayoutT, FieldsT... >{ writer, std::move( expr ), enabled }
		{
		}

		static ast::type::UniformBufferPtr makeType( ast::type::TypesCache & cache
			, std::string const & name )
		{
			return UniformBuffer::makeType( cache, name, LayoutT );
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
