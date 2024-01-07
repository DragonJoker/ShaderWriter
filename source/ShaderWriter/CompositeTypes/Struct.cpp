/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Struct.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	//************************************************************************************************

	Struct::Struct( ShaderWriter & writer
		, std::string const & name
		, type::MemoryLayout layout )
		: m_writer{ &writer }
		, m_builder{ &m_writer->getBuilder() }
		, m_type{ writer.getTypesCache().getStruct( layout, name ) }
	{
	}

	Struct::Struct( ShaderWriter & writer
		, ast::type::BaseStructPtr type )
		: m_writer{ &writer }
		, m_builder{ &m_writer->getBuilder() }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_builder, makeStructureDecl( getStmtCache( *m_builder ), m_type ) );
	}

	void Struct::end()
	{
		addStmt( *m_builder, makeStructureDecl( getStmtCache( *m_builder ), m_type ) );
	}

	bool Struct::hasMember( std::string const & name )const
	{
		return m_type->hasMember( name );
	}

	void Struct::declMember( std::string name
		, Struct const & type )
	{
		m_type->declMember( std::move( name )
			, std::static_pointer_cast< type::Struct >( type.getType() ) );
	}

	//************************************************************************************************
}
