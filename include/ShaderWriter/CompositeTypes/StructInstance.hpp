/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StructInstance_H___
#define ___SDW_StructInstance_H___

#include "ShaderWriter/Value.hpp"

#include <ShaderAST/Type/TypeStruct.hpp>

namespace sdw
{
	class StructInstance
		: public Value
	{
	public:
		SDW_API StructInstance( Shader * shader
			, expr::ExprPtr expr );
		SDW_API StructInstance & operator=( StructInstance const & rhs );

		template< typename T >
		inline T getMember( std::string const & name );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name );

	private:
		type::StructPtr m_type;
	};
}

#include "StructInstance.inl"

#endif
