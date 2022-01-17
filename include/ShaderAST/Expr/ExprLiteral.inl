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
			return lit.uint32v;
		}

		template<>
		inline uint64_t valueGetter< LiteralType::eUInt64 >( LiteralValue const & lit )
		{
			return lit.uint64v;
		}

		template<>
		inline float valueGetter< LiteralType::eFloat >( LiteralValue const & lit )
		{
			return lit.floatv;
		}

		template<>
		inline double valueGetter< LiteralType::eDouble >( LiteralValue const & lit )
		{
			return lit.doublev;
		}
	}

	template< LiteralType T >
	inline LiteralValueType< T > Literal::getValue()const
	{
		assert( m_valueType == T );
		return details::valueGetter< T >( m_value );
	}
}
