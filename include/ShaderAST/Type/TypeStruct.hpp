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
		eScalar,
		eShaderRecord,
	};

	SDAST_API std::string getRealName( Builtin builtin
		, uint32_t index );

	class Struct
		: public Type
	{
	public:
		static constexpr uint32_t NotFound = ~0u;
		static constexpr uint32_t InvalidLocation = ~0u;

		struct Member
		{
			Member() = default;
			Member( TypePtr ptype
				, Builtin pbuiltin
				, uint32_t pbuiltinIndex = InvalidLocation )
				: type{ std::move( ptype ) }
				, builtin{ pbuiltin }
				, name{ getRealName( pbuiltin, pbuiltinIndex ) }
				, builtinIndex{ pbuiltinIndex }
			{
			}

			Member( TypePtr ptype
				, std::string pname
				, uint32_t poffset
				, uint32_t psize
				, uint32_t parrayStride )
				: type{ std::move( ptype ) }
				, name{ std::move( pname ) }
				, offset{ poffset }
				, size{ psize }
				, arrayStride{ parrayStride }
			{
			}

			Member( TypePtr ptype
				, std::string pname
				, uint32_t poffset
				, uint32_t psize
				, uint32_t parrayStride
				, uint32_t plocation )
				: type{ std::move( ptype ) }
				, name{ std::move( pname ) }
				, offset{ poffset }
				, size{ psize }
				, arrayStride{ parrayStride }
				, location{ plocation }
			{
			}

			TypePtr type{};
			Builtin builtin{};
			std::string name{};
			uint32_t offset{};
			uint32_t size{};
			uint32_t arrayStride{};
			uint32_t location{ InvalidLocation };
			uint32_t builtinIndex{ InvalidLocation };
		};

	private:
		SDAST_API Struct( TypesCache & typesCache
			, Struct const & rhs );
		SDAST_API Struct( TypesCache & typesCache
			, Struct * parent
			, uint32_t index
			, Struct const & copy );
		SDAST_API Struct( TypesCache & typesCache
			, Struct & parent
			, uint32_t index
			, Struct const & copy );

	protected:
		SDAST_API Struct( TypesCache & typesCache
			, MemoryLayout layout
			, std::string name
			, var::Flag flag
			, Kind kind = Kind::eStruct
			, EntryPoint entryPoint = EntryPoint::eNone );

	public:
		SDAST_API Member getMember( uint32_t index )const;
		SDAST_API Member getMember( std::string_view name )const;
		SDAST_API uint32_t findMember( std::string_view name )const;
		SDAST_API Member getMember( Builtin builtin
			, uint32_t index = InvalidLocation )const;
		SDAST_API uint32_t findMember( Builtin builtin
			, uint32_t index = InvalidLocation )const;
		SDAST_API TypePtr getMemberType( Struct & parent, uint32_t index )const override;

		bool hasMember( std::string_view name )const
		{
			return findMember( name ) != NotFound;
		}

		bool hasMember( Builtin builtin
			, uint32_t index = InvalidLocation )const
		{
			return findMember( builtin, index ) != NotFound;
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

		uint64_t getFlag()const
		{
			return uint64_t( m_flag );
		}

		bool isShaderInput()const
		{
			return hasFlag( getFlag(), var::Flag::eShaderInput );
		}

		bool isShaderOutput()const
		{
			return hasFlag( getFlag(), var::Flag::eShaderOutput );
		}

		bool isPatchInput()const
		{
			return hasFlag( getFlag(), var::Flag::ePatchInput );
		}

		bool isPatchOutput()const
		{
			return hasFlag( getFlag(), var::Flag::ePatchOutput );
		}

		bool isPerTaskNV()const
		{
			return hasFlag( getFlag(), var::Flag::ePerTaskNV );
		}

		bool isPerTask()const
		{
			return hasFlag( getFlag(), var::Flag::ePerTask );
		}

		EntryPoint getEntryPoint()const noexcept
		{
			return m_entryPoint;
		}

	protected:
		std::tuple< uint32_t, uint32_t, bool > doLookupMember( std::string_view name
			, TypePtr type );
		void doAddMember( Member const & member );

	private:
		void doCopyMembers( Struct const & rhs );
		void doUpdateOffsets();

	private:
		std::string m_name;
		std::vector< Member > m_members;
		MemoryLayout m_layout;
		var::Flag m_flag{};
		EntryPoint m_entryPoint;
	};

	class BaseStruct
		: public Struct
	{
	protected:
		SDAST_API BaseStruct( TypesCache & typesCache
			, MemoryLayout layout
			, std::string name
			, Kind kind );

	public:
		SDAST_API BaseStruct( TypesCache & typesCache
			, MemoryLayout layout
			, std::string name );

		SDAST_API std::pair< Member, bool > declMember( Builtin builtin
			, Kind kind
			, uint32_t arraySize
			, uint32_t index = InvalidLocation
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, Kind kind
			, uint32_t arraySize = NotArray
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, TypePtr type
			, uint32_t arraySize = NotArray
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, ArrayPtr type
			, uint32_t arraySize
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, ArrayPtr type
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, BaseStructPtr type
			, uint32_t arraySize
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, BaseStructPtr type
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, IOStructPtr type
			, uint32_t arraySize
			, bool enabled = true );
		SDAST_API std::pair< Member, bool > declMember( std::string name
			, IOStructPtr type
			, bool enabled = true );

	private:
		std::pair< Member, bool > doCreateMember( TypePtr type
			, std::string name );
		std::pair< Member, bool > doCreateMember( TypePtr type
			, Builtin builtin
			, uint32_t index = InvalidLocation );
	};

	class IOStruct
		: public Struct
	{
	public:
		SDAST_API IOStruct( TypesCache & typesCache
			, MemoryLayout layout
			, std::string name
			, EntryPoint entryPoint
			, var::Flag flag );

		SDAST_API bool declMember( Builtin builtin
			, Kind kind
			, uint32_t arraySize
			, uint32_t index = InvalidLocation );
		SDAST_API bool declMember( Builtin builtin
			, ArrayPtr type
			, uint32_t arraySize
			, uint32_t index = InvalidLocation );
		SDAST_API bool declMember( std::string name
			, Kind kind
			, uint32_t arraySize
			, uint32_t location
			, bool enabled = true );
		SDAST_API bool declMember( std::string name
			, TypePtr type
			, uint32_t arraySize
			, uint32_t location
			, bool enabled = true );
		SDAST_API bool declMember( std::string name
			, TypePtr type
			, uint32_t location
			, bool enabled = true );
		SDAST_API bool declMember( std::string name
			, ArrayPtr type
			, uint32_t arraySize
			, uint32_t location
			, bool enabled = true );
		SDAST_API bool declMember( std::string name
			, ArrayPtr type
			, uint32_t location
			, bool enabled = true );
		SDAST_API bool declMember( std::string name
			, StructPtr type
			, uint32_t arraySize
			, bool enabled = true );
		SDAST_API bool declMember( std::string name
			, StructPtr type
			, bool enabled = true );

	private:
		std::pair< Member, bool > doCreateMember( TypePtr type
			, std::string name
			, uint32_t location );
		std::pair< Member, bool > doCreateMember( TypePtr type
			, Builtin builtin
			, uint32_t index = InvalidLocation );
	};

	struct RayDesc
		: public BaseStruct
	{
		SDAST_API explicit RayDesc( TypesCache & typesCache );
	};

	using RayDescPtr = std::shared_ptr< RayDesc >;

	SDAST_API type::Struct const * getStructType( type::Type const & type );
	SDAST_API type::StructPtr getStructType( type::TypePtr type );

	SDAST_API size_t getHash( MemoryLayout layout
		, std::string const & name );
	SDAST_API size_t getHash( MemoryLayout layout
		, std::string const & name
		, EntryPoint entryPoint
		, var::Flag flag );

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
	SDAST_API bool hasRuntimeArray( TypePtr type );
}

#endif
