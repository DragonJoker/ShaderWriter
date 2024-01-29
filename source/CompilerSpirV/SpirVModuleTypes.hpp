/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModuleTypes_H___
#define ___SDW_SpirvModuleTypes_H___
#pragma once

#include "CompilerSpirV/SpirVFunction.hpp"

#include <GlslCommon/GlslStatementsHelpers.hpp>

#include <ShaderAST/Type/TypeAccelerationStructure.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeSampler.hpp>

#include <map>

namespace spirv
{
	struct NameCache;

	namespace debug
	{
		class DebugNames;
		class NonSemanticDebug;
	}

	class ModuleTypes
	{
		friend class debug::NonSemanticDebug;

	public:
		ModuleTypes( ast::ShaderAllocatorBlock * allocator
			, Module & shaderModule
			, ast::type::TypesCache * typesCache
			, InstructionList & constantsTypes );

		TypeId registerType( ast::type::TypePtr type
			, glsl::Statement const * debugStatement );
		TypeId registerType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId const & parentId
			, glsl::Statement const * debugStatement );
		TypeId registerImageType( ast::type::ImagePtr image
			, bool isComparison );
		TypeId registerPointerType( TypeId type
			, spv::StorageClass storage
			, bool isForward = false );
		TypeId registerFunctionType( TypeIdList const & funcTypes );
		DebugId mergeSamplerImage( DebugId const & image
			, DebugId const & sampler
			, Block & currentBlock );

		ast::type::TypePtr getType( DebugId const & typeId )const;

		void deserialize( spv::Op opCode
			, Instruction const & instruction
			, NameCache const & names );

		ast::type::TypesCache & getTypesCache()const noexcept
		{
			return *m_typesCache;
		}

	private:
		TypeId doRegisterNonArrayType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId const & parentId
			, glsl::Statement const * debugStatement );
		TypeId doRegisterTypeRec( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId const & parentId
			, uint32_t arrayStride
			, glsl::Statement const * debugStatement );
		TypeId & doRegisterBaseType( spv::Id id
			, ast::type::TypePtr type );
		TypeId & doRegisterBaseType( spv::Id id
			, ast::type::Kind kind );
		TypeId doRegisterBaseType( ast::type::Kind kind
			, glsl::Statement const * debugStatement );
		TypeId doRegisterBaseType( ast::type::StructPtr type
			, uint32_t mbrIndex
			, TypeId const & parentId
			, glsl::Statement const * debugStatement );
		TypeId doRegisterBaseType( ast::type::SamplerPtr type );
		TypeId doRegisterBaseType( ast::type::CombinedImagePtr type );
		void doRegisterBaseType( spv::Id id
			, ast::type::ImagePtr type
			, ast::type::Trinary isComparison );
		TypeId doRegisterBaseType( ast::type::ImagePtr type
			, ast::type::Trinary isComparison );
		TypeId doRegisterBaseType( ast::type::ImagePtr type );
		TypeId doRegisterBaseType( ast::type::SampledImagePtr type );
		TypeId doRegisterBaseType( ast::type::AccelerationStructurePtr type );
		TypeId doRegisterBaseType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId const & parentId
			, glsl::Statement const * debugStatement );
		bool doAddMbrBuiltin( ast::Builtin pbuiltin
			, DebugId const & outer
			, uint32_t mbrIndex );

	private:
		ast::ShaderAllocatorBlock * m_allocator;
		Module & m_module;
		debug::DebugNames & m_debugNames;
		debug::NonSemanticDebug & m_nonSemanticDebug;
		InstructionList & m_declarations;
		ast::type::TypesCache * m_typesCache;
		ast::UnorderedMap< size_t, TypeId > m_registeredTypes;
		ast::UnorderedMap< DebugId, ast::UnorderedMap< DebugId, DebugId, DebugIdHasher >, DebugIdHasher > m_registeredSamplerImages;
		ast::UnorderedMap< size_t, TypeId > m_registeredImageTypes;
		ast::Map< uint64_t, TypeId > m_registeredPointerTypes;
		ast::Map< uint64_t, TypeId > m_registeredForwardPointerTypes;
		ast::UnorderedMap< TypeIdList, TypeId, TypeIdListHasher > m_registeredFunctionTypes;
	};
}

#endif
