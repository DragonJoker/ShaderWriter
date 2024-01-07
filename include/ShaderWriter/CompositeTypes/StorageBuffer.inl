/*
See LICENSE file in root folder
*/
namespace sdw
{
	inline StorageBuffer::StorageBuffer( ShaderWriter & writer
		, std::string const & name
		, uint32_t bind
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled )
		: StorageBuffer{ writer
			, name + "Block"
			, name
			, bind
			, set
			, layout
			, enabled }
	{
	}

	inline StorageBuffer::StorageBuffer( ShaderWriter & writer
		, std::string const & blockName
		, std::string variableName
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled )
		: StorageBuffer{ writer
			, blockName
			, std::move( variableName )
			, location.binding
			, location.set
			, layout
			, enabled }
	{
	}

	inline StorageBuffer::StorageBuffer( ShaderWriter & writer
		, std::string const & name
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled )
		: StorageBuffer( writer
			, name + "Block"
			, name
			, location.binding
			, location.set
			, layout
			, enabled )
	{
	}

	template< typename ValueT, typename ... ParamsT >
	inline ValueT StorageBuffer::declMember( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto [type, added] = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer ), std::forward< ParamsT >( params )... ) );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled && m_stmt && added )
		{
			m_stmt->add( makeVariableDecl( getStmtCache( m_writer ), var ) );
		}

		return ValueT{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > StorageBuffer::declMember( std::string name
		, uint32_t dimension
		, bool enabled
		, ParamsT && ... params )
	{
		auto [type, added] = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer ), std::forward< ParamsT >( params )... )
			, dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled && m_stmt && added )
		{
			m_stmt->add( makeVariableDecl( getStmtCache( m_writer ), var ) );
		}

		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > StorageBuffer::declMemberArray( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto [type, added] = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer ), std::forward< ParamsT >( params )... )
			, type::UnknownArraySize );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled && m_stmt && added )
		{
			m_stmt->add( makeVariableDecl( getStmtCache( m_writer ), var ) );
		}

		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT >
	inline ValueT StorageBuffer::getMember( std::string_view name
		, bool enabled )const
	{
		auto var = getMemberVariable( m_writer, m_var, name );
		return ValueT{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT >
	inline Array< ValueT > StorageBuffer::getMemberArray( std::string_view name
		, bool enabled )const
	{
		auto var = getMemberVariable( m_writer, m_var, name );
		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
