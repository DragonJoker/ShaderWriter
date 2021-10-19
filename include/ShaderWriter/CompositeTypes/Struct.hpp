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
		SDW_API Struct( ShaderWriter & writer
			, std::string name
			, type::MemoryLayout layout = type::MemoryLayout::eC );
		SDW_API Struct( ShaderWriter & writer
			, ast::type::StructPtr type );
		SDW_API void end();
		template< typename InstanceT = StructInstance >
		InstanceT getInstance( std::string const & name
			, bool enabled )const;

		type::StructPtr getType()const
		{
			return m_type;
		}

		template< typename T >
		inline void declMember( std::string const & name );
		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t dimension );
		SDW_API void declMember( std::string name
			, Struct const & type );

	private:
		ShaderWriter * m_writer;
		Shader * m_shader;
		type::StructPtr m_type;
	};

	class InputStruct
	{
	private:
		SDW_API InputStruct( ShaderWriter & writer
			, std::string name );
		SDW_API InputStruct( ShaderWriter & writer
			, ast::type::StructPtr type );
		SDW_API void end();

		type::StructPtr getType()const
		{
			return m_type;
		}

		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t location );
		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t dimension
			, uint32_t location );

	private:
		ShaderWriter * m_writer;
		Shader * m_shader;
		type::StructPtr m_type;
	};

	class OutputStruct
	{
	private:
		SDW_API OutputStruct( ShaderWriter & writer
			, std::string name );
		SDW_API OutputStruct( ShaderWriter & writer
			, ast::type::StructPtr type );
		SDW_API void end();

		type::StructPtr getType()const
		{
			return m_type;
		}

		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t location );
		template< typename T >
		inline void declMember( std::string const & name
			, uint32_t dimension
			, uint32_t location );

	private:
		ShaderWriter * m_writer;
		Shader * m_shader;
		type::StructPtr m_type;
	};
}

#include "Struct.inl"

#endif
