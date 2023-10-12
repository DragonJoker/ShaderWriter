/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvDebugNames_H___
#define ___SDW_SpirvDebugNames_H___
#pragma once

#include "CompilerSpirV/SpirvInstruction.hpp"

namespace spirv::debug
{
	class DebugNames
	{
	public:
		DebugNames( ast::ShaderAllocatorBlock * allocator );

		void registerSource( spv::SourceLanguage language, uint32_t version );
		void registerName( DebugId id, std::string name );
		void registerMemberName( DebugId outerId, uint32_t index, std::string name );
		void registerString( ValueId id, std::string text );

		InstructionList const & getStringsDeclarations()const noexcept
		{
			return m_stringsDeclarations;
		}

		InstructionList & getStringsDeclarations()noexcept
		{
			return m_stringsDeclarations;
		}

		InstructionList const & getNamesDeclarations()const noexcept
		{
			return m_namesDeclarations;
		}

		InstructionList & getNamesDeclarations()noexcept
		{
			return m_namesDeclarations;
		}

		Map< std::string, Vector< uint32_t > > & getNameCache()noexcept
		{
			return m_nameCache;
		}

	private:
		InstructionList m_stringsDeclarations;
		InstructionList m_namesDeclarations;
		Map< std::string, Vector< uint32_t > > m_nameCache;
	};
}

#endif
