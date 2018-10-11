/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Struct_H___
#define ___Writer_Struct_H___

#include "ShaderWriterPrerequisites.hpp"

#include <ASTGenerator/Stmt/StmtStructureDecl.hpp>
#include <ASTGenerator/Type/TypeStruct.hpp>

namespace sdw
{
	class Struct
	{
	public:
		Struct( stmt::Container & m_container
			, std::string name );
		void end();

		template< typename T >
		inline void declMember( std::string const & name );
		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline void declMemberArray( std::string const & name );
		template< typename T >
		inline T getMember( std::string const & name );
		template< typename T >
		inline Array< T > getMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name );

	private:
		stmt::Container & m_container;
		type::StructPtr m_type;
	};
}

#include "Struct.inl"

#endif
