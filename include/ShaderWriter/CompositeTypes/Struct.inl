/*
See LICENSE file in root folder
*/
namespace sdw
{
	//*********************************************************************************************

	template< typename InstanceT >
	InstanceT Struct::getInstance( std::string name
		, bool enabled )const
	{
		auto var = registerBlockVariable( *m_writer, std::move( name ), m_type );

		if ( enabled )
		{
			addStmt( *m_writer, sdw::makeVariableDecl( var ) );
		}

		return InstanceT{ *m_writer
			, makeExpr( *m_writer, var )
			, enabled };
	}

	template< typename T >
	inline void Struct::declMember( std::string name )
	{
		static_assert( typeEnum< T > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, T::makeType( getTypesCache( *m_writer ) ) );
	}

	template< typename T >
	inline void Struct::declMember( std::string name
		, uint32_t dimension )
	{
		static_assert( typeEnum< T > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, typeEnum< T >
			, dimension );
	}

	//*********************************************************************************************

	template< var::Flag FlagT >
	IOStructT< FlagT >::IOStructT( ShaderWriter & writer
		, std::string name )
		: m_writer{ &writer }
		, m_shader{ &sdw::getShader( *m_writer ) }
		, m_type{ getTypesCache( *m_writer ).getIOStruct( ast::type::MemoryLayout::eC, std::move( name ), FlagT ) }
	{
	}

	template< var::Flag FlagT >
	IOStructT< FlagT >::IOStructT( ShaderWriter & writer
		, ast::type::IOStructPtr type )
		: m_writer{ &writer }
		, m_shader{ &sdw::getShader( *m_writer ) }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	template< var::Flag FlagT >
	void IOStructT< FlagT >::end()
	{
		addStmt( *m_writer, sdw::makeStructDecl( m_type ) );
	}

	template< var::Flag FlagT >
	template< typename T >
	inline void IOStructT< FlagT >::declMember( std::string name
		, uint32_t location )
	{
		static_assert( typeEnum< T > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, T::makeType( getTypesCache( *m_writer ) )
			, location );
	}

	template< var::Flag FlagT >
	template< typename T >
	inline void IOStructT< FlagT >::declMember( std::string name
		, uint32_t dimension
		, uint32_t location )
	{
		static_assert( typeEnum< T > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnum< T > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, typeEnum< T >
			, dimension
			, location );
	}

	//*********************************************************************************************
}
