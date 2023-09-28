/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Struct.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	//************************************************************************************************

	Struct::Struct( ShaderWriter & writer
		, std::string name
		, type::MemoryLayout layout )
		: m_writer{ &writer }
		, m_shader{ &m_writer->getShader() }
		, m_type{ writer.getTypesCache().getStruct( layout, std::move( name ) ) }
	{
	}

	Struct::Struct( ShaderWriter & writer
		, ast::type::BaseStructPtr type )
		: m_writer{ &writer }
		, m_shader{ &m_writer->getShader() }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_writer, makeStructureDecl( getStmtCache( m_writer ), m_type ) );
	}

	void Struct::end()
	{
		addStmt( *m_writer, makeStructureDecl( getStmtCache( m_writer ), m_type ) );
	}

	bool Struct::hasMember( std::string name )const
	{
		return m_type->hasMember( name );
	}

	void Struct::declMember( std::string name
		, Struct const & type )
	{
		m_type->declMember( name
			, std::static_pointer_cast< type::Struct >( type.getType() ) );
	}

	//************************************************************************************************
}
