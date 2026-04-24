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
	struct ArrayStorageBufferT
		: public Value
	{
	public:
		SDW_DeclValue( , ArrayStorageBufferT );

		ArrayStorageBufferT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		ReturnWrapperT< InstanceT > operator[]( uint32_t index )const;
		ReturnWrapperT< InstanceT > operator[]( UInt32 const & index )const;

		template< typename ... ParamsT >
		static type::StorageBufferPtr makeType( type::TypesCache & cache
			, std::string const & name
			, type::MemoryLayout layout
			, ParamsT && ... params );

	private:
		expr::ExprPtr makeMbrSelect( std::string_view name )const;

	private:
		ShaderBuilder & m_builder;
		type::StorageBuffer * m_buffer;
		type::TypePtr m_dataType;
		var::VariablePtr m_var;
	};

	SDW_API var::VariablePtr registerStorageBuffer( ShaderWriter & writer
		, std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, var::Flag flag = var::Flag::eStorageBuffer
		, bool enabled = true );
	SDW_API type::StorageBufferPtr makeArrayStorageBufferType( type::TypesCache & cache
		, std::string const & name
		, type::MemoryLayout layout
		, Struct const & dataType );
	SDW_API type::StorageBufferPtr makeArrayStorageBufferType( type::TypesCache & cache
		, std::string const & name
		, type::MemoryLayout layout
		, type::TypePtr dataType );
}

#include "ArrayStorageBuffer.inl"

#endif
