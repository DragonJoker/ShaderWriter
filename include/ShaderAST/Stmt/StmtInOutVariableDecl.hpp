/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtInOutVariableDecl_H___
#define ___AST_StmtInOutVariableDecl_H___
#pragma once

#include "Stmt.hpp"

namespace ast::stmt
{
	class InOutVariableDecl
		: public Stmt
	{
	public:
		SDAST_API InOutVariableDecl( var::VariablePtr variable
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t blendIndex );

		SDAST_API void accept( VisitorPtr vis )override;

		inline var::VariablePtr getVariable()const
		{
			return m_variable;
		}

		inline uint32_t getLocation()const
		{
			return m_location;
		}

		inline uint32_t getStreamIndex()const
		{
			return m_streamIndex;
		}

		inline uint32_t getBlendIndex()const
		{
			return m_blendIndex;
		}

	private:
		var::VariablePtr m_variable;
		uint32_t m_location;
		uint32_t m_streamIndex;
		uint32_t m_blendIndex;
	};
	using InOutVariableDeclPtr = std::unique_ptr< InOutVariableDecl >;

	inline InOutVariableDeclPtr makeInOutVariableDecl( var::VariablePtr variable
		, uint32_t location )
	{
		return std::make_unique< InOutVariableDecl >( std::move( variable )
			, location
			, 0u
			, 0u );
	}

	inline InOutVariableDeclPtr makeInOutVariableDecl( var::VariablePtr variable
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t blendIndex )
	{
		return std::make_unique< InOutVariableDecl >( std::move( variable )
			, location
			, streamIndex
			, blendIndex );
	}

	inline InOutVariableDeclPtr makeInOutStreamVariableDecl( var::VariablePtr variable
		, uint32_t location
		, uint32_t streamIndex = 0u )
	{
		return std::make_unique< InOutVariableDecl >( std::move( variable )
			, location
			, streamIndex
			, 0u );
	}

	inline InOutVariableDeclPtr makeInOutBlendVariableDecl( var::VariablePtr variable
		, uint32_t location
		, uint32_t blendIndex = 0u )
	{
		return std::make_unique< InOutVariableDecl >( std::move( variable )
			, location
			, 0u
			, blendIndex );
	}
}

#endif
