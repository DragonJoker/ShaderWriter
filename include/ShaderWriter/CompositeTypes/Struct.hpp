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
			, std::string const & name
			, type::MemoryLayout layout = type::MemoryLayout::eStd140 );
		SDW_API Struct( ShaderWriter & writer
			, ast::type::BaseStructPtr type );
		SDW_API void end();
		template< typename InstanceT = StructInstance >
		InstanceT getInstance( std::string name
			, bool enabled )const;

		type::BaseStructPtr getType()const
		{
			return m_type;
		}

		SDW_API bool hasMember( std::string const & name )const;
		template< typename ValueT, typename ... ParamsT >
		void declMember( std::string name
			, ParamsT && ... params );
		template< typename ValueT, typename ... ParamsT >
		void declMember( std::string name
			, uint32_t dimension
			, ParamsT && ... params );
		SDW_API void declMember( std::string name
			, Struct const & type );

	private:
		ShaderWriter * m_writer;
		ShaderBuilder * m_builder;
		type::BaseStructPtr m_type;
	};

	template< var::Flag FlagT >
	class IOStructT
	{
	private:
		IOStructT( ShaderWriter & writer
			, ast::EntryPoint entryPoint
			, std::string name );
		IOStructT( ShaderWriter & writer
			, ast::type::IOStructPtr type );
		void end();

		type::IOStructPtr getType()const
		{
			return m_type;
		}

		template< typename ValueT, typename ... ParamsT >
		void declMember( std::string name
			, uint32_t location
			, ParamsT && ... params );
		template< typename ValueT, typename ... ParamsT >
		void declMember( std::string name
			, uint32_t dimension
			, uint32_t location
			, ParamsT && ... params );

	private:
		ShaderWriter * m_writer;
		ShaderBuilder * m_builder;
		type::IOStructPtr m_type;
	};

	using InputStruct = IOStructT< var::Flag::eShaderInput >;
	using OutputStruct = IOStructT< var::Flag::eShaderOutput >;
}

#include "Struct.inl"

#endif
