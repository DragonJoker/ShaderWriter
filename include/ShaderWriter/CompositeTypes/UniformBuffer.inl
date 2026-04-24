/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename ValueT, typename ... ParamsT >
	inline ValueT UniformBuffer::declMember( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto & writer = findWriterMandat( *this );
		auto [type, added, mbrIndex] = m_buffer->registerMember( name
			, ValueT::makeType( getTypesCache( writer )
				, std::forward< ParamsT >( params )... ) );
		return ValueT{ writer
			, makeMbrSelect( mbrIndex )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > UniformBuffer::declMember( std::string name
		, uint32_t dimension
		, bool enabled
		, ParamsT && ... params )
	{
		auto & writer = findWriterMandat( *this );
		auto [type, added, mbrIndex] = m_buffer->registerMember( name
			, ValueT::makeType( getTypesCache( writer )
				, std::forward< ParamsT >( params )... )
			, dimension );
		return Array< ValueT >{ writer
			, makeMbrSelect( mbrIndex )
			, isEnabled() && enabled };
	}

	template< typename ValueT, typename ... ParamsT >
	inline Array< ValueT > UniformBuffer::declMemberArray( std::string name
		, bool enabled
		, ParamsT && ... params )
	{
		auto & writer = findWriterMandat( *this );
		auto [type, added, mbrIndex] = m_buffer->registerMember( name
			, ValueT::makeType( getTypesCache( writer )
				, std::forward< ParamsT >( params )... )
			, type::UnknownArraySize );
		return Array< ValueT >{ writer
			, makeMbrSelect( mbrIndex )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline T UniformBuffer::getMember( std::string_view name
		, bool enabled )const
	{
		auto & writer = findWriterMandat( *this );
		return T{ writer
			, makeMbrSelect( name )
			, isEnabled() && enabled };
	}

	template< typename T >
	inline Array< T > UniformBuffer::getMemberArray( std::string_view name
		, bool enabled )const
	{
		auto & writer = findWriterMandat( *this );
		return Array< T >{ writer
			, makeMbrSelect( name )
			, isEnabled() && enabled };
	}
}
