/*
See LICENSE file in root folder
*/
#include "SpirVDebugNames.hpp"

namespace spirv::debug
{
	DebugNames::DebugNames( ast::ShaderAllocatorBlock * allocator
		, SpirVConfig const * config )
		: m_allocator{ allocator }
		, m_stringsDeclarations{ m_allocator }
		, m_namesDeclarations{ m_allocator }
		, m_nameCache{ m_allocator }
		, m_config{ config }
	{
	}

	void DebugNames::registerSource( spv::SourceLanguage language, uint32_t version )
	{
		if ( !m_config || m_config->debugLevel == DebugLevel::eNone )
		{
			return;
		}

		m_namesDeclarations.push_back( makeInstruction< SourceInstruction >( m_nameCache
			, ValueId{ spv::Id( language ) }
			, ValueId{ version } ) );
	}

	void DebugNames::registerName( DebugId id, std::string name )
	{
		if ( !m_config || m_config->debugLevel == DebugLevel::eNone )
		{
			return;
		}

		m_namesDeclarations.push_back( makeInstruction< NameInstruction >( m_nameCache
			, id.id
			, std::move( name ) ) );
	}

	void DebugNames::registerMemberName( DebugId outerId, uint32_t index, std::string name )
	{
		if ( !m_config || m_config->debugLevel == DebugLevel::eNone )
		{
			return;
		}

		m_namesDeclarations.push_back( makeInstruction< MemberNameInstruction >( m_nameCache
			, outerId.id
			, ValueId{ index }
			, std::move( name ) ) );
	}

	void DebugNames::registerString( ValueId id, std::string text )
	{
		if ( !m_config || m_config->debugLevel != DebugLevel::eDebugInfo )
		{
			return;
		}

		m_stringsDeclarations.push_back( makeInstruction< StringInstruction >( m_nameCache
			, id
			, std::move( text ) ) );
	}
}
