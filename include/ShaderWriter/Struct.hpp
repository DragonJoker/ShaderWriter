/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Struct_H___
#define ___Writer_Struct_H___

#include "StructInstance.hpp"

#include <ASTGenerator/Stmt/StmtStructureDecl.hpp>

namespace sdw
{
	class Struct
	{
	public:
		Struct( Shader & shader
			, std::string name );
		void end();
		StructInstance getInstance( std::string const & name );

		template< typename T >
		inline void declMember( std::string const & name );
		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline void declMemberArray( std::string const & name );

	private:
		Shader * m_shader;
		type::StructPtr m_type;
	};
}

#include "Struct.inl"

#endif
