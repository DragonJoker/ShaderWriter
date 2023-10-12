/*
See LICENSE file in root folder
*/
#include "SpirVDebugNames.hpp"

namespace spirv::debug
{
	DebugNames::DebugNames( ast::ShaderAllocatorBlock * allocator )
		: m_stringsDeclarations{ allocator }
		, m_namesDeclarations{ allocator }
		, m_nameCache{ allocator }
	{
	}

	void DebugNames::registerSource( spv::SourceLanguage language, uint32_t version )
	{
		m_namesDeclarations.push_back( makeInstruction< SourceInstruction >( m_nameCache
			, ValueId{ spv::Id( language ) }
			, ValueId{ version } ) );
	}

	void DebugNames::registerName( DebugId id, std::string name )
	{
		m_namesDeclarations.push_back( makeInstruction< NameInstruction >( m_nameCache
			, id.id
			, std::move( name ) ) );
	}

	void DebugNames::registerMemberName( DebugId outerId, uint32_t index, std::string name )
	{
		m_namesDeclarations.push_back( makeInstruction< MemberNameInstruction >( m_nameCache
			, outerId.id
			, ValueId{ index }
			, std::move( name ) ) );
	}

	void DebugNames::registerString( ValueId id, std::string text )
	{
		m_stringsDeclarations.push_back( makeInstruction< StringInstruction >( m_nameCache
			, id
			, std::move( text ) ) );
	}
}
