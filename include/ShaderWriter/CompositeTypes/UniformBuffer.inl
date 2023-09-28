/*
See LICENSE file in root folder
*/
namespace sdw
{
	inline UniformBuffer::UniformBuffer( ShaderWriter & writer
		, std::string name
		, uint32_t binding
		, uint32_t set
		, ast::type::MemoryLayout layout
		, bool enabled )
		: UniformBuffer{ writer
			, name + "Block"
			, name
			, binding
			, set
			, layout
			, enabled }
	{
	}

	inline UniformBuffer::UniformBuffer( ShaderWriter & writer
		, std::string blockName
		, std::string variableName
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled )
		: UniformBuffer{ writer
			, std::move( blockName )
			, std::move( variableName )
			, location.binding
			, location.set
			, layout
			, enabled }
	{
	}

	inline UniformBuffer::UniformBuffer( ShaderWriter & writer
		, std::string name
		, LocationHelper location
		, ast::type::MemoryLayout layout
		, bool enabled )
		: UniformBuffer{ writer
			, name + "Block"
			, name
			, location.binding
			, location.set
			, layout
			, enabled }
	{
	}

	template< typename ValueT, typename ... ParamsT >
	inline ValueT UniformBuffer::declMember( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto type = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer )
				, std::forward< ParamsT >( params )... ) );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( getStmtCache( m_writer ).makeVariableDecl( var ) );
		}

		return ValueT{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > UniformBuffer::declMember( std::string name
		, uint32_t dimension
		, bool enabled
		, ParamsT && ... params )
	{
		auto type = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer )
				, std::forward< ParamsT >( params )... )
			, dimension );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( getStmtCache( m_writer ).makeVariableDecl( var ) );
		}

		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > UniformBuffer::declMemberArray( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto type = m_interface.registerMember( name
			, ValueT::makeType( getTypesCache( m_writer )
				, std::forward< ParamsT >( params )... )
			, type::UnknownArraySize );
		auto var = registerMember( m_writer, m_var, std::move( name ), type );

		if ( isEnabled() && enabled )
		{
			m_stmt->add( getStmtCache( m_writer ).makeVariableDecl( var ) );
		}

		return Array< ValueT >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline T UniformBuffer::getMember( std::string_view name
		, bool enabled )const
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return T{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline Array< T > UniformBuffer::getMemberArray( std::string_view name
		, bool enabled )const
	{
		auto var = getMemberVar( m_writer, m_var, name );
		return Array< T >{ m_writer
			, makeExpr( m_writer, var )
			, isEnabled() && enabled };
	}
}
