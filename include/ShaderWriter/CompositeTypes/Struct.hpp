/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Struct_H___
#define ___SDW_Struct_H___

#include "StructInstance.hpp"

#include <ShaderAST/Stmt/StmtStructureDecl.hpp>

namespace sdw
{
	class Struct
	{
	public:
		Struct( ShaderWriter & writer
			, std::string name
			, type::MemoryLayout layout = type::MemoryLayout::eStd140 );
		Struct( ShaderWriter & writer
			, ast::type::StructPtr type );
		void end();
		StructInstance getInstance( std::string const & name )const;

		inline type::StructPtr getType()const
		{
			return m_type;
		}

		template< typename T >
		inline void declMember( std::string const & name );
		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t dimension );
		void declMember( std::string name
			, Struct const & type );

	private:
		Shader * m_shader;
		type::StructPtr m_type;
	};
}

#include "Struct.inl"

#endif
