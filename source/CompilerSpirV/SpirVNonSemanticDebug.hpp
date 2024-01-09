/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirVNonSemanticDebug_H___
#define ___SDW_SpirVNonSemanticDebug_H___
#pragma once

#include "CompilerSpirV/SpirVInstruction.hpp"
#include "CompilerSpirV/spirv/NonSemantic.Shader.DebugInfo.100.hpp"

#include <GlslCommon/GlslStatementsHelpers.hpp>

#include <ShaderAST/Expr/Expr.hpp>
#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Type/TypeAccelerationStructure.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Var/VariableList.hpp>

namespace spirv
{
	struct Function;
	class ModuleTypes;
}

namespace spirv::debug
{
	class NonSemanticDebug
	{
	public:
		NonSemanticDebug( ast::ShaderAllocatorBlock * allocator
			, Module & shaderModule
			, glsl::StmtConfig const * config );

		void initialise( InstructionList & imports
			, glsl::Statements const & debugStatements );
		spv::Id getNextId()const;
		bool isExtNonSemanticDebugInfo( spv::Id id )const;
		void setExtID( spv::Id id );
		//
		// Types declarations
		//
		void registerBaseType( ast::type::Kind kind
			, DebugId & resultId );
		void registerArrayType( TypeId const & elementTypeId
			, uint32_t arraySize
			, DebugId & resultId );
		void registerRuntimeArrayType( TypeId const & elementTypeId
			, DebugId & resultId );
		void registerVectorType( TypeId const & componentTypeId
			, uint32_t componentCount
			, DebugId & resultId );
		void registerMatrixType( TypeId const & componentTypeId
			, uint32_t componentCount
			, DebugId & resultId );
		void registerSamplerType( ast::type::SamplerPtr type
			, DebugId & resultId );
		void registerCombinedImageType( ast::type::CombinedImagePtr type
			, DebugId & resultId );
		void registerImageType( ast::type::ImagePtr type
			, DebugId & resultId );
		void registerAccelerationStructureType( DebugId & resultId );
		void registerMemberType( ast::type::Struct::Member const & member
			, DebugId const & subTypeId
			, glsl::Statement const * debugStatement
			, ValueIdList & subTypes );
		void registerStructType( ast::type::StructPtr structType
			, ValueIdList const & subTypes
			, glsl::Statement const * debugStatement
			, DebugId & resultId );
		void registerFunctionType( TypeIdList const & funcTypes
			, DebugId & resultId );
		//
		// Variables declarations
		//
		void declareVariable( InstructionList & instructions
			, std::string const & name
			, ast::type::TypePtr type
			, DebugId variableId
			, DebugId initialiser
			, glsl::Statement const * debugStatement
			, bool isAccessChain = false );
		void declarePointerParam( InstructionList & instructions
			, std::string const & name
			, ast::type::TypePtr type
			, DebugId variableId
			, DebugId initialiser
			, glsl::Statement const * debugStatement );
		void declareAccessChain( InstructionList & instructions
			, ast::expr::Expr const & expr
			, glsl::Statement const * debugStatement
			, DebugId & resultId );
		void declareFunction( Function & function
			, std::string const & name
			, ast::var::VariableList const & params
			, DebugIdList const & funcParams
			, glsl::Statement const * declDebugStatement
			, glsl::Statement const * scopeBeginDebugStatement
			, glsl::Statement const * firstLineStatement );
		//
		// Global Instructions
		//
		void makeEntryPointInstruction( DebugId variableId );
		void makeLexicalBlockInstruction( glsl::Statement const * scopeBeginStatement );
		//
		// Scope Instructions
		//
		void makeValueInstruction( InstructionList & instructions
			, DebugId variableId
			, DebugId valueId );
		void makeScopeInstruction( InstructionList & instructions );
		void makeNoScopeInstruction( InstructionList & instructions );
		void makeLineExtension( InstructionList & instructions
			, glsl::Statement const * debugStatement
			, glsl::RangeInfo const & columns );
		void makeLineExtension( InstructionList & instructions
			, glsl::Statement const * debugStatement
			, ast::expr::Expr const & expr );

		InstructionList const & getDeclarations()const noexcept
		{
			return m_declarations;
		}

		InstructionList & getDeclarations()noexcept
		{
			return m_declarations;
		}

	private:
		ValueId makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
			, InstructionList & instructions
			, ValueIdList operands );
		void makeDebugInstruction( spv::NonSemanticShaderDebugInfo100Instructions instruction
			, InstructionList & instructions
			, ValueId resultId
			, ValueIdList operands );
		void registerOpaqueType( std::string const & name
			, DebugId & resultId );

	private:
		ast::ShaderAllocatorBlock * m_allocator;
		Module & m_module;
		ModuleTypes & m_types;
		glsl::StmtConfig const * m_config;
		InstructionList m_declarations;
		bool m_enabled{};
		ValueId m_extDebugInfo{};
		ValueId m_debugSourceId{};
		ValueId m_globalScopeId{};
		TypeId m_voidType{};
		ValueId m_debugInfoNone{};
		ValueId m_debugExpressionDummy{};
		glsl::Statement const * m_currentFunctionFirstLineStatement{};
		ValueId m_currentScopeId{};
	};
}

#endif
