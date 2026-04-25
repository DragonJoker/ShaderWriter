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

	template< typename InstanceT >
	expr::ExprPtr makeExpr( ArrayStorageBufferT< InstanceT > const & value );

	template< typename InstanceT >
	struct Array< ArrayStorageBufferT< InstanceT > >
		: public Value
	{
		using ValueT = ArrayStorageBufferT< InstanceT >;
		SDW_DeclValue( , Array );

		Array( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< ast::type::Kind KindT >
		ValueT operator[]( IntegerValue< KindT > const & offset )const;
		ValueT operator[]( int32_t offset )const;
		ValueT operator[]( uint32_t offset )const;
	};
}

#include "ArrayStorageBuffer.inl"

#endif
