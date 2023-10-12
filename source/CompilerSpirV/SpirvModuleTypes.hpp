/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModuleTypes_H___
#define ___SDW_SpirvModuleTypes_H___
#pragma once

#include "CompilerSpirV/SpirvFunction.hpp"

#include <GlslCommon/GlslStatementsHelpers.hpp>

#include <ShaderAST/Type/TypeAccelerationStructure.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Type/TypeSampler.hpp>

#include <set>
#include <unordered_set>

namespace spirv
{
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
			, Module & module
			, ast::type::TypesCache * typesCache
			, InstructionList & constantsTypes );

		TypeId registerType( ast::type::TypePtr type
			, glsl::Statement const * debugStatement );
		TypeId registerType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId
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

		ast::type::TypesCache & getTypesCache()const noexcept
		{
			return *m_typesCache;
		}

	private:
		TypeId doRegisterNonArrayType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId
			, glsl::Statement const * debugStatement );
		TypeId doRegisterTypeRec( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId
			, uint32_t arrayStride
			, glsl::Statement const * debugStatement );
		TypeId doRegisterBaseType( ast::type::Kind kind
			, uint32_t mbrIndex
			, TypeId parentId
			, uint32_t arrayStride
			, glsl::Statement const * debugStatement );
		TypeId doRegisterBaseType( ast::type::StructPtr type
			, uint32_t mbrIndex
			, TypeId parentId
			, glsl::Statement const * debugStatement );
		TypeId doRegisterBaseType( ast::type::SamplerPtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::CombinedImagePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::ImagePtr type
			, ast::type::Trinary isComparison );
		TypeId doRegisterBaseType( ast::type::ImagePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::SampledImagePtr type
			, uint32_t mbrIndex
			, TypeId parentId );
		TypeId doRegisterBaseType( ast::type::AccelerationStructurePtr type
			, uint32_t mbrIndex
			, TypeId parentId
			, glsl::Statement const * debugStatement );
		TypeId doRegisterBaseType( ast::type::TypePtr type
			, uint32_t mbrIndex
			, TypeId parentId
			, uint32_t arrayStride
			, glsl::Statement const * debugStatement );
		bool doAddMbrBuiltin( ast::Builtin pbuiltin
			, DebugId outer
			, uint32_t mbrIndex );

	private:
		ast::ShaderAllocatorBlock * m_allocator;
		Module & m_module;
		debug::DebugNames & m_debugNames;
		debug::NonSemanticDebug & m_nonSemanticDebug;
		InstructionList & m_declarations;
		ast::type::TypesCache * m_typesCache;
		Map< ast::type::TypePtr, TypeId > m_registeredTypes;
		Map< ast::type::TypePtr, TypeId > m_registeredMemberTypes;
		UnorderedMap< DebugId, UnorderedMap< DebugId, DebugId, DebugIdHasher >, DebugIdHasher > m_registeredSamplerImages;
		UnorderedMap< size_t, TypeId > m_registeredImageTypes;
		Map< uint64_t, TypeId > m_registeredPointerTypes;
		Map< uint64_t, TypeId > m_registeredForwardPointerTypes;
		UnorderedMap< TypeIdList, TypeId, TypeIdListHasher > m_registeredFunctionTypes;
	};
}

#endif
