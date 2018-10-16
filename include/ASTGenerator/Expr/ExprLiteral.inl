/*
See LICENSE file in root folder
*/
namespace ast::expr
{
	namespace details
	{
		template< LiteralType T >
		LiteralValueType< T > valueGetter( LiteralValue const & lit );

		template<>
		inline bool valueGetter< LiteralType::eBool >( LiteralValue const & lit )
		{
			return lit.boolv;
		}

		template<>
		inline int32_t valueGetter< LiteralType::eInt >( LiteralValue const & lit )
		{
			return lit.intv;
		}

		template<>
		inline uint32_t valueGetter< LiteralType::eUInt >( LiteralValue const & lit )
		{
			return lit.uintv;
		}

		template<>
		inline float valueGetter< LiteralType::eFloat >( LiteralValue const & lit )
		{
			return lit.floatv;
		}
	}

	template< LiteralType T >
	inline LiteralValueType< T > Literal::getValue()const
	{
		assert( m_valueType == T );
		return details::valueGetter< T >( m_value );
	}
}
