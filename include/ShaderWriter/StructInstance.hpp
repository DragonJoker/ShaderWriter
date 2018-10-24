/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructInstance_H___
#define ___SDW_StructInstance_H___

#include "Value.hpp"

#include <ASTGenerator/Type/TypeStruct.hpp>

namespace sdw
{
	class StructInstance
		: public Value
	{
	public:
		StructInstance( Shader * shader
			, expr::ExprPtr expr );

		template< typename T >
		inline T getMember( std::string const & name );
		template< typename T >
		inline Array< T > getMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name );

	private:
		type::StructPtr m_type;
	};
}

#include "StructInstance.inl"

#endif
