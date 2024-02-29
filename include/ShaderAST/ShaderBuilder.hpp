/*
See LICENSE file in root folder
*/
#ifndef ___AST_ShaderBuilder_H___
#define ___AST_ShaderBuilder_H___
#pragma once

#include "Shader.hpp"

namespace ast
{
	class ShaderBuilder
	{
	public:
		SDAST_API explicit ShaderBuilder( ast::ShaderStage type
			, ShaderAllocator * allocator = nullptr );
		SDAST_API void push( stmt::Container * container
			, var::VariableList const & vars );
		SDAST_API void pop();
		SDAST_API void saveNextExpr();
		SDAST_API expr::ExprPtr loadExpr( expr::ExprPtr expr );
		SDAST_API void beginIf( expr::ExprPtr condition );
		SDAST_API void beginElseIf( expr::ExprPtr condition );
		SDAST_API void beginElse();
		SDAST_API void endIf();
		SDAST_API void beginSwitch( expr::ExprPtr value );
		SDAST_API void beginCase( expr::LiteralPtr literal );
		SDAST_API void beginDefault();
		SDAST_API void endSwitch();
		SDAST_API void pushScope( ast::stmt::ContainerPtr container );
		SDAST_API void popScope();
		/**
		*name
		*	Functions registration.
		*/
		/**@{*/
		SDAST_API bool hasFunction( std::string_view name
			, ast::stmt::FunctionFlag flag )const;
		SDAST_API bool hasFunction( std::string_view name
			, uint32_t flags )const;
		SDAST_API var::VariablePtr getFunction( std::string const & name
			, ast::stmt::FunctionFlag flag );
		SDAST_API var::VariablePtr getFunction( std::string const & name
			, uint32_t flags );
		SDAST_API var::VariablePtr registerFunction( std::string name
			, type::FunctionPtr type
			, ast::stmt::FunctionFlag flag );
		SDAST_API var::VariablePtr registerFunction( std::string name
			, type::FunctionPtr type
			, uint32_t flags );
		/**@}*/
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		SDAST_API uint32_t getNextVarId();
		SDAST_API bool hasGlobalVariable( std::string_view name )const;
		SDAST_API bool hasVariable( std::string_view name
			, bool isLocale )const;
		SDAST_API var::VariablePtr getVariable( std::string_view name
			, bool isLocale )const;
		SDAST_API bool hasMemberVariable( var::VariablePtr outer
			, std::string_view name )const;
		SDAST_API var::VariablePtr getMemberVariable( var::VariablePtr outer
			, std::string_view name )const;
		SDAST_API void registerVariable( var::VariablePtr var );
		SDAST_API var::VariablePtr registerName( std::string name
			, type::TypePtr type
			, uint64_t flags );
		SDAST_API var::VariablePtr registerName( std::string name
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerName( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string name
			, type::TypePtr type
			, uint64_t flags );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string name
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerMember( var::VariablePtr outer
			, std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerStaticConstant( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerSpecConstant( std::string name
			, uint32_t location
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerAccelerationStructure( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerSampler( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerSampledImage( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerTexture( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerImage( std::string name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDAST_API var::VariablePtr registerInput( EntryPoint entryPoint
			, std::string name
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerOutput( EntryPoint entryPoint
			, std::string name
			, uint32_t location
			, uint64_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInOut( std::string name
			, uint64_t attributes
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerBuiltin( Builtin builtin
			, type::TypePtr type
			, var::Flag flag );
		SDAST_API var::VariablePtr registerBlockVariable( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerLocale( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerLoopVar( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerParam( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInParam( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerOutParam( std::string name
			, type::TypePtr type );
		SDAST_API var::VariablePtr registerInOutParam( std::string name
			, type::TypePtr type );
		SDAST_API void addStmt( stmt::StmtPtr stmt );
		SDAST_API void addGlobalStmt( stmt::StmtPtr stmt );
		SDAST_API void registerSsbo( std::string name
			, SsboInfo const & info );
		SDAST_API void registerUbo( std::string name
			, UboInfo const & info );
		SDAST_API void registerPcb( std::string name
			, InterfaceBlock const & info );
		SDAST_API void registerShaderRecord( std::string name
			, ShaderRecordInfo const & info );
		SDAST_API expr::ExprPtr getDummyExpr( type::TypePtr type )const;
		/**@}*/

		ast::Shader & getShader()const
		{
			return *m_shader;
		}

		ast::ShaderPtr releaseShader()
		{
			return std::move( m_shader );
		}

		stmt::Container * getContainer()const
		{
			return m_blocks.back().container;
		}

		stmt::Container * getGlobalContainer()const
		{
			return m_blocks.front().container;
		}

		ShaderStage getType()const
		{
			return m_shader->getType();
		}

		type::TypesCache & getTypesCache()const
		{
			return m_shader->getTypesCache();
		}

		expr::ExprCache & getExprCache()const
		{
			return m_shader->getExprCache();
		}

		stmt::StmtCache & getStmtCache()const
		{
			return m_shader->getStmtCache();
		}

		ShaderAllocatorBlock & getAllocator()const
		{
			return m_shader->getAllocator();
		}

		ShaderData const & getData()const
		{
			return m_shader->getData();
		}

	public:
		struct Block
		{
			std::set< var::VariablePtr > registered;
			stmt::Container * container;
		};

	private:
		void doPushScope( ast::stmt::ContainerPtr container
			, ast::var::VariableList const & vars );

		ShaderData & getData()
		{
			return m_shader->getData();
		}

	private:
		ShaderPtr m_shader;
		std::vector< Block > m_blocks;
		bool m_ignore{ false };
		stmt::StmtPtr m_savedStmt;
		std::vector< stmt::If * > m_ifStmt;
		std::vector< stmt::Switch * > m_switchStmt;
		std::vector< ast::stmt::ContainerPtr > m_currentStmts;
		struct Function
		{
			var::VariablePtr variable;
			uint32_t flags;

			Function( var::VariablePtr v
				, uint32_t f )
				: variable{ std::move( v ) }
				, flags{ f }
			{
			}

			Function( var::VariablePtr v
				, ast::stmt::FunctionFlag f )
				: Function{ std::move( v ), uint32_t( f ) }
			{
			}
		};
		std::vector< Function > m_functions;
	};
}

#endif
