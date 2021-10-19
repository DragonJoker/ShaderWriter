/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeStruct_H___
#define ___AST_TypeStruct_H___
#pragma once

#include "TypeArray.hpp"

#include "ShaderAST/Var/FlagHolder.hpp"

#include <vector>

namespace ast::type
{
	enum class MemoryLayout
	{
		eStd140,
		eStd430,
		eC,
	};

	class Struct
		: public Type
	{
	public:
		static constexpr uint32_t NotFound = ~( 0u );
		static constexpr uint32_t InvalidLocation = ~( 0u );

		struct Member
		{
			Member() = default;
			Member( TypePtr ptype
				, std::string pname
				, uint32_t poffset
				, uint32_t psize
				, uint32_t parrayStride )
				: type{ std::move( ptype ) }
				, name{ std::move( pname ) }
				, offset{ std::move( poffset ) }
				, size{ std::move( psize ) }
				, arrayStride{ std::move( parrayStride ) }
			{
			}

			Member( TypePtr ptype
				, std::string pname
				, uint32_t poffset
				, uint32_t psize
				, uint32_t plocation
				, var::Flag pflag )
				: type{ std::move( ptype ) }
				, name{ std::move( pname ) }
				, offset{ std::move( poffset ) }
				, size{ std::move( psize ) }
				, location{ std::move( plocation ) }
				, flag{ std::move( pflag ) }
			{
			}

			TypePtr type{};
			std::string name{};
			uint32_t offset{};
			uint32_t size{};
			uint32_t arrayStride{};
			uint32_t location{ InvalidLocation };
			var::Flag flag{};
		};

	private:
		SDAST_API Struct( TypesCache & cache
			, Struct const & rhs );
		SDAST_API Struct( TypesCache & cache
			, Struct * parent
			, uint32_t index
			, Struct const & copy );
		SDAST_API Struct( TypesCache & cache
			, Struct & parent
			, uint32_t index
			, Struct const & copy );

	public:
		SDAST_API Struct( TypesCache & cache
			, MemoryLayout layout
			, std::string name );
		SDAST_API Member declMember( std::string name
			, Kind kind
			, uint32_t arraySize = NotArray );
		SDAST_API Member declMember( std::string name
			, Kind kind
			, uint32_t arraySize
			, uint32_t location
			, var::Flag input );
		SDAST_API Member declMember( std::string name
			, TypePtr type );
		SDAST_API Member declMember( std::string name
			, TypePtr type
			, uint32_t location
			, var::Flag input );
		SDAST_API Member declMember( std::string name
			, ArrayPtr type
			, uint32_t arraySize );
		SDAST_API Member declMember( std::string name
			, ArrayPtr type
			, uint32_t arraySize
			, uint32_t location
			, var::Flag input );
		SDAST_API Member declMember( std::string name
			, ArrayPtr type );
		SDAST_API Member declMember( std::string name
			, ArrayPtr type
			, uint32_t location
			, var::Flag input );
		SDAST_API Member declMember( std::string name
			, StructPtr type
			, uint32_t arraySize );
		SDAST_API Member declMember( std::string name
			, StructPtr type );
		SDAST_API Member getMember( uint32_t index );
		SDAST_API Member getMember( std::string const & name );
		SDAST_API uint32_t findMember( std::string const & name );
		SDAST_API TypePtr getMemberType( Struct & parent, uint32_t index )const override;

		bool hasMember( std::string const & name )
		{
			return findMember( name ) != NotFound;
		}

		std::string const & getName()const
		{
			return m_name;
		}

		size_t size()const
		{
			return m_members.size();
		}

		bool empty()const
		{
			return m_members.empty();
		}

		auto begin()const
		{
			return m_members.begin();
		}

		auto end()const
		{
			return m_members.end();
		}

		auto front()const
		{
			return m_members.front();
		}

		auto back()const
		{
			return m_members.back();
		}

		MemoryLayout getMemoryLayout()const
		{
			return m_layout;
		}

	private:
		std::pair< uint32_t, uint32_t > doLookupMember( std::string const & name
			, TypePtr type );
		Member doAddMember( TypePtr type
			, std::string const & name );
		Member doAddIOMember( TypePtr type
			, std::string const & name
			, uint32_t location
			, var::Flag input );
		void doUpdateOffsets();

	private:
		std::string m_name;
		std::vector< Member > m_members;
		MemoryLayout m_layout;
	};
	using StructPtr = std::shared_ptr< Struct >;

	SDAST_API size_t getHash( MemoryLayout layout, std::string const & name );

	SDAST_API bool operator==( Struct const & lhs, Struct const & rhs );

	SDAST_API uint32_t getSize( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getSize( TypePtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getAlignment( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getAlignment( TypePtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( Array const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( ArrayPtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( TypePtr type
		, MemoryLayout layout );
}

#endif
