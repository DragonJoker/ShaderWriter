/*
See LICENSE file in root folder
*/
#ifndef ___SDW_OptionalUbo_H___
#define ___SDW_OptionalUbo_H___

#include "Optional.hpp"
#include "ShaderWriter/CompositeTypes/Ubo.hpp"

namespace sdw
{
	template<>
	struct Optional< Ubo >
		: public Ubo
	{
		Optional( ShaderWriter & writer
			, bool enabled
			, std::string const & name
			, uint32_t bind
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140 )
			: Ubo{ writer, name, bind, set, layout }
			, m_enabled{ enabled }
		{
		}

		inline bool isEnabled()const
		{
			return m_enabled;
		}

		inline void end()
		{
			if ( isEnabled() )
			{
				Ubo::end();
			}
		}

		template< typename T >
		inline Optional< T > declMember( std::string const & name )
		{
			return Ubo::template declMember< T >( name
				, isEnabled() );
		}

		template< typename T >
		inline Optional< T > declMember( std::string const & name
			, bool enabled )
		{
			return Ubo::template declMember< T >( name
				, isEnabled() && enabled );
		}

		template< typename T >
		inline Optional< Array< T > > declMember( std::string const & name
			, uint32_t dimension )
		{
			return Ubo::template declMember< T >( name
				, dimension
				, isEnabled() );
		}

		template< typename T >
		inline Optional< Array< T > > declMember( std::string const & name
			, uint32_t dimension
			, bool enabled )
		{
			return Ubo::template declMember< T >( name
				, dimension
				, isEnabled() && enabled );
		}

		template< typename T >
		inline Optional< T > getMember( std::string const & name )
		{
			return Ubo::template declMember< T >( name
				, isEnabled() );
		}

		template< typename T >
		inline Optional< T > getMember( std::string const & name
			, bool enabled )
		{
			return Ubo::template getMember< T >( name
				, isEnabled() && enabled );
		}

		template< typename T >
		inline Optional< Array< T > > getMemberArray( std::string const & name )
		{
			return Ubo::template getMemberArray< T >( name
				, isEnabled() );
		}

		template< typename T >
		inline Optional< Array< T > > getMemberArray( std::string const & name
			, bool enabled )
		{
			return Ubo::template getMemberArray< T >( name
				, isEnabled() && enabled );
		}

	private:
		bool m_enabled;
	};
}

#endif
