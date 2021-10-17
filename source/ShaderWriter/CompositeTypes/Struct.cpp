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
		, ast::type::StructPtr type )
		: m_writer{ &writer }
		, m_shader{ &m_writer->getShader() }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	void Struct::end()
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	void Struct::declMember( std::string name
		, Struct const & type )
	{
		m_type->declMember( name, type.getType() );
	}

	//************************************************************************************************

	InputStruct::InputStruct( ShaderWriter & writer
		, std::string name )
		: m_writer{ &writer }
		, m_shader{ &m_writer->getShader() }
		, m_type{ writer.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, std::move( name ) ) }
	{
	}

	InputStruct::InputStruct( ShaderWriter & writer
		, ast::type::StructPtr type )
		: m_writer{ &writer }
		, m_shader{ &m_writer->getShader() }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	void InputStruct::end()
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	//************************************************************************************************

	OutputStruct::OutputStruct( ShaderWriter & writer
		, std::string name )
		: m_writer{ &writer }
		, m_shader{ &m_writer->getShader() }
		, m_type{ writer.getTypesCache().getStruct( ast::type::MemoryLayout::eStd430, std::move( name ) ) }
	{
	}

	OutputStruct::OutputStruct( ShaderWriter & writer
		, ast::type::StructPtr type )
		: m_writer{ &writer }
		, m_shader{ &m_writer->getShader() }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	void OutputStruct::end()
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	//************************************************************************************************
}
