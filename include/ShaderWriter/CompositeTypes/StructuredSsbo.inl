/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename InstanceT >
	inline InstanceT StructuredSsbo::at( uint32_t index )
	{
		return InstanceT{ &m_shader
			, sdw::makeArrayAccess( m_info.getType()
				, sdw::makeMbrSelect( makeIdent( m_ssboVar )
					, 0u
					, makeIdent( m_dataVar ) )
				, makeExpr( index ) ) };
	}

	template< typename InstanceT >
	inline InstanceT StructuredSsbo::at( UInt const & index )
	{
		return InstanceT{ &m_shader
			, sdw::makeArrayAccess( m_info.getType()
				, sdw::makeMbrSelect( makeIdent( m_ssboVar )
					, 0u
					, makeIdent( m_dataVar ) )
				, makeExpr( index ) ) };
	}
}
