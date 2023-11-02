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
			addStmt( *m_writer, makeVariableDecl( getStmtCache( m_writer ), var ) );
		}

		return InstanceT{ *m_writer
			, makeExpr( *m_writer, var )
			, enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline void Struct::declMember( std::string name
		, ParamsT && ... params )
	{
		static_assert( typeEnumV< ValueT > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, ValueT::makeType( getTypesCache( *m_writer )
				, std::forward< ParamsT >( params )... ) );
	}

	template< typename ValueT, typename ... ParamsT >
	inline void Struct::declMember( std::string name
		, uint32_t dimension
		, ParamsT && ... params )
	{
		static_assert( typeEnumV< ValueT > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, ValueT::makeType( getTypesCache( *m_writer )
				, std::forward< ParamsT >( params )... )
			, dimension );
	}

	//*********************************************************************************************

	template< var::Flag FlagT >
	IOStructT< FlagT >::IOStructT( ShaderWriter & writer
		, ast::EntryPoint entryPoint
		, std::string name )
		: m_writer{ &writer }
		, m_builder{ &sdw::getBuilder( *m_writer ) }
		, m_type{ getTypesCache( *m_writer ).getIOStruct( std::move( name ), entryPoint, FlagT ) }
	{
	}

	template< var::Flag FlagT >
	IOStructT< FlagT >::IOStructT( ShaderWriter & writer
		, ast::type::IOStructPtr type )
		: m_writer{ &writer }
		, m_builder{ &sdw::getBuilder( *m_writer ) }
		, m_type{ std::move( type ) }
	{
		addStmt( *m_writer, makeStructureDecl( getStmtCache( m_writer ), m_type ) );
	}

	template< var::Flag FlagT >
	void IOStructT< FlagT >::end()
	{
		addStmt( *m_writer, makeStructureDecl( getStmtCache( m_writer ), m_type ) );
	}

	template< var::Flag FlagT >
	template< typename ValueT, typename ... ParamsT >
	inline void IOStructT< FlagT >::declMember( std::string name
		, uint32_t location
		, ParamsT && ... params )
	{
		static_assert( typeEnumV< ValueT > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, ValueT::makeType( getTypesCache( *m_writer )
				, std::forward< ParamsT >( params )... )
			, location );
	}

	template< var::Flag FlagT >
	template< typename ValueT, typename ... ParamsT >
	inline void IOStructT< FlagT >::declMember( std::string name
		, uint32_t dimension
		, uint32_t location
		, ParamsT && ... params )
	{
		static_assert( typeEnumV< ValueT > != type::Kind::eBoolean
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec2B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec3B
			, "Can't put a boolean type inside a structure" );
		static_assert( typeEnumV< ValueT > != type::Kind::eVec4B
			, "Can't put a boolean type inside a structure" );
		m_type->declMember( std::move( name )
			, ValueT::makeType( getTypesCache( *m_writer )
				, std::forward< ParamsT >( params )... )
			, dimension
			, location );
	}

	//*********************************************************************************************
}
