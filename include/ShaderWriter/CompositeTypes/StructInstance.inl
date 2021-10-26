/*
See LICENSE file in root folder
*/
namespace sdw
{
	template< typename T >
	inline T StructInstance::getMember( std::string const & name )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto member = m_type->getMember( name );
		auto & writer = findWriterMandat( *this );
		return T{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, m_type->getFlag() )
			, true};
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( std::string const & name )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto member = m_type->getMember( name );
		auto & writer = findWriterMandat( *this );
		return Array< T >{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, m_type->getFlag() )
			, true };
	}

	template< typename T >
	inline T StructInstance::getMember( ast::Builtin builtin )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto member = m_type->getMember( builtin );
		auto & writer = findWriterMandat( *this );
		return T{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, m_type->getFlag() | ast::var::Flag::eBuiltin )
			, true};
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( ast::Builtin builtin )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto member = m_type->getMember( builtin );
		auto & writer = findWriterMandat( *this );
		return Array< T >{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, m_type->getFlag() | ast::var::Flag::eBuiltin )
			, true };
	}
}
