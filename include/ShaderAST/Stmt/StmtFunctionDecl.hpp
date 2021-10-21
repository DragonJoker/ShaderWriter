/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFunctionDecl_H___
#define ___AST_StmtFunctionDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "ShaderAST/Var/VariableList.hpp"

namespace ast::stmt
{
	enum class FunctionFlag : uint32_t
	{
		eNone = 0,
		eEntryPoint = 0x0001 << 0,
		ePatchRoutine = 0x0001 << 1,
	};

	class FunctionDecl
		: public Compound
	{
	public:
		SDAST_API FunctionDecl( type::FunctionPtr type
			, std::string name
			, uint32_t flags );

		SDAST_API void accept( VisitorPtr vis )override;

		type::FunctionPtr getType()const
		{
			return m_type;
		}

		std::string const & getName()const
		{
			return m_name;
		}

		uint32_t getFlags()const
		{
			return m_flags;
		}

		bool isEntryPoint()const
		{
			return hasFlag( FunctionFlag::eEntryPoint );
		}

		bool isPatchRoutine()const
		{
			return hasFlag( FunctionFlag::ePatchRoutine );
		}

	private:
		bool hasFlag( FunctionFlag flag )const
		{
			return flag == FunctionFlag::eNone
				? false
				: FunctionFlag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		type::FunctionPtr m_type;
		std::string m_name;
		uint32_t m_flags;
	};
	using FunctionDeclPtr = std::unique_ptr< FunctionDecl >;

	inline FunctionDeclPtr makeFunctionDecl( type::FunctionPtr type
		, std::string name
		, FunctionFlag flag = {} )
	{
		return std::make_unique< FunctionDecl >( std::move( type )
			, std::move( name )
			, uint32_t( flag ) );
	}

	inline FunctionDeclPtr makeFunctionDecl( type::FunctionPtr type
		, std::string name
		, uint32_t flags )
	{
		return std::make_unique< FunctionDecl >( std::move( type )
			, std::move( name )
			, flags );
	}

	inline uint32_t operator|( FunctionFlag const lhs
		, FunctionFlag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( FunctionFlag const lhs
		, uint32_t const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( uint32_t const lhs
		, FunctionFlag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}
}

#endif
