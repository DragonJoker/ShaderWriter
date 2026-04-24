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
		friend class TypesCache;

	public:
		static constexpr uint32_t NotFound = ~0u;
		static constexpr uint32_t InvalidLocation = ~0u;
		static constexpr uint32_t UndefinedIndex = ~0u;

		struct Member
		{
			Member() = default;
			Member( TypePtr ptype
				, Builtin pbuiltin
				, uint32_t pbuiltinIndex = UndefinedIndex )
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
			uint32_t builtinIndex{ UndefinedIndex };
		};

	private:
		SDAST_API Struct( TypesCache & typesCache
			, Struct * parent
			, uint32_t index
			, StructPtr copy );
		SDAST_API Struct( TypesCache & typesCache
			, Struct & parent
			, uint32_t index
			, StructPtr copy );

	protected:
		SDAST_API Struct( TypesCache & typesCache
			, MemoryLayout layout
			, std::string name
			, var::Flag flag
			, Kind kind = Kind::eStruct
			, EntryPoint entryPoint = EntryPoint::eNone
			, bool explicitLayout = false );

	public:
		SDAST_API Member getMember( uint32_t index )const;
		SDAST_API Member getMember( std::string_view name )const;
		SDAST_API uint32_t findMember( std::string_view name )const;
		SDAST_API Member getMember( Builtin builtin
			, uint32_t index = UndefinedIndex )const;
		SDAST_API uint32_t findMember( Builtin builtin
			, uint32_t index = UndefinedIndex )const;

		bool hasMember( std::string_view name )const
		{
			return findMember( name ) != NotFound;
		}

		bool hasMember( Builtin builtin
			, uint32_t index = UndefinedIndex )const
		{
			return findMember( builtin, index ) != NotFound;
		}

		std::string const & getName()const noexcept
		{
			return m_name;
		}

		size_t size()const noexcept
		{
			return m_members.size();
		}

		bool empty()const noexcept
		{
			return m_members.empty();
		}

		auto begin()const noexcept
		{
			return m_members.begin();
		}

		auto end()const noexcept
		{
			return m_members.end();
		}

		auto front()const noexcept
		{
			return m_members.front();
		}

		auto back()const noexcept
		{
			return m_members.back();
		}

		MemoryLayout getMemoryLayout()const noexcept
		{
			return m_layout;
		}

		uint64_t getFlag()const noexcept
		{
			return uint64_t( m_flag );
		}

		bool isShaderInput()const noexcept
		{
			return hasFlag( getFlag(), var::Flag::eShaderInput );
		}

		bool isShaderOutput()const noexcept
		{
			return hasFlag( getFlag(), var::Flag::eShaderOutput );
		}

		bool isPatchInput()const noexcept
		{
			return hasFlag( getFlag(), var::Flag::ePatchInput );
		}

		bool isPatchOutput()const noexcept
		{
			return hasFlag( getFlag(), var::Flag::ePatchOutput );
		}

		bool isInput()const noexcept
		{
			return isShaderInput() || isPatchInput();
		}

		bool isOutput()const noexcept
		{
			return isShaderOutput() || isPatchOutput();
		}

		bool isPerTaskNV()const noexcept
		{
			return hasFlag( getFlag(), var::Flag::ePerTaskNV );
		}

		bool isPerTask()const noexcept
		{
			return hasFlag( getFlag(), var::Flag::ePerTask );
		}

		EntryPoint getEntryPoint()const noexcept
		{
			return m_entryPoint;
		}

		virtual bool isIOStruct()const noexcept
		{
			return false;
		}

	protected:
		std::tuple< uint32_t, uint32_t, bool, uint32_t > doLookupMember( std::string_view name
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
			, Kind kind
			, bool explicitLayout );

	public:
		SDAST_API BaseStruct( TypesCache & typesCache
			, MemoryLayout layout
			, std::string name
			, bool explicitLayout );

		SDAST_API std::tuple< Member, bool, uint32_t > declMember( Builtin builtin
			, TypePtr type
			, uint32_t arraySize
			, uint32_t index = UndefinedIndex
			, bool enabled = true );
		SDAST_API std::tuple< Member, bool, uint32_t > declMember( std::string name
			, TypePtr type
			, uint32_t arraySize
			, bool enabled = true );
		SDAST_API std::tuple< Member, bool, uint32_t > declMember( Builtin builtin
			, Kind kind
			, uint32_t arraySize
			, uint32_t index = UndefinedIndex
			, bool enabled = true );
		SDAST_API std::tuple< Member, bool, uint32_t > declMember( std::string name
			, Kind kind
			, uint32_t arraySize
			, bool enabled = true );

		SDAST_API IOStructPtr getIOStruct( EntryPoint entryPoint, var::Flag flag, uint32_t baseLocation )const;

		std::tuple< Member, bool, uint32_t > declMember( std::string name
			, TypePtr type
			, bool enabled = true )
		{
			return declMember( std::move( name )
				, std::move( type )
				, NotArray
				, enabled );
		}

		std::tuple< Member, bool, uint32_t > declMember( std::string name
			, Kind kind
			, bool enabled = true )
		{
			return declMember( std::move( name )
				, kind
				, NotArray
				, enabled );
		}

	private:
		std::tuple< Member, bool, uint32_t > doCreateMember( TypePtr type
			, std::string name );
		std::tuple< Member, bool, uint32_t > doCreateMember( TypePtr type
			, Builtin builtin
			, uint32_t index );
	};

	class IOStruct
		: public Struct
	{
	public:
		SDAST_API IOStruct( TypesCache & typesCache
			, MemoryLayout layout
			, std::string name
			, EntryPoint entryPoint
			, var::Flag flag
			, bool explicitLayout = false );

		SDAST_API std::tuple< Member, bool, uint32_t > declMember( Builtin builtin
			, TypePtr type
			, uint32_t arraySize
			, uint32_t index = UndefinedIndex
			, bool enabled = true );
		SDAST_API std::tuple< Member, bool, uint32_t > declMember( std::string name
			, TypePtr type
			, uint32_t arraySize
			, uint32_t location
			, bool enabled = true );
		SDAST_API std::tuple< Member, bool, uint32_t > declMember( Builtin builtin
			, Kind kind
			, uint32_t arraySize
			, uint32_t index = UndefinedIndex
			, bool enabled = true );
		SDAST_API std::tuple< Member, bool, uint32_t > declMember( std::string name
			, Kind kind
			, uint32_t arraySize
			, uint32_t location
			, bool enabled = true );

		SDAST_API BaseStructPtr getBaseStruct( MemoryLayout layout )const;

		SDAST_API static std::string getNameSuffix( ast::EntryPoint entryPoint
			, var::Flag flag );

		std::tuple< Member, bool, uint32_t > declMember( std::string name
			, TypePtr type
			, uint32_t location
			, bool enabled = true )
		{
			return declMember( std::move( name )
				, std::move( type )
				, NotArray
				, location
				, enabled );
		}

		std::tuple< Member, bool, uint32_t > declMember( std::string name
			, Kind kind
			, uint32_t location
			, bool enabled = true )
		{
			return declMember( std::move( name )
				, kind
				, NotArray
				, location
				, enabled );
		}

		bool isIOStruct()const noexcept override
		{
			return true;
		}

	private:
		std::tuple< Member, bool, uint32_t > doCreateMember( TypePtr type
			, std::string name
			, uint32_t location );
		std::tuple< Member, bool, uint32_t > doCreateMember( TypePtr type
			, Builtin builtin
			, uint32_t index );

	private:
		std::string m_baseName;
	};

	struct RayDesc
		: public BaseStruct
	{
		SDAST_API explicit RayDesc( TypesCache & typesCache );
	};

	using RayDescPtr = RayDesc *;

	SDAST_API type::Struct const * getStructType( type::Type const & type );
	SDAST_API type::StructPtr getStructType( type::TypePtr type );

	SDAST_API size_t getHash( MemoryLayout layout
		, std::string const & name
		, bool explicitLayout );
	SDAST_API size_t getHash( MemoryLayout layout
		, std::string const & name
		, EntryPoint entryPoint
		, var::Flag flag
		, bool explicitLayout );
	SDAST_API size_t getHash( TypePtr type
		, StructPtr parent
		, uint32_t mbrIndex );

	SDAST_API bool operator==( Struct const & lhs, Struct const & rhs );

	SDAST_API uint32_t getSize( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getSize( TypePtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getAlignment( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getAlignment( TypePtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( TypePtr type
		, MemoryLayout layout );
	SDAST_API bool hasRuntimeArray( TypePtr type );
	SDAST_API TypePtr getExplicitLayoutType( TypesCache & typesCache, TypePtr type );
	SDAST_API TypePtr getBasicType( TypesCache & typesCache, Kind kind, bool explicitLayout );
	SDAST_API BaseStructPtr getStruct( TypesCache & typesCache, MemoryLayout layout, std::string const & name, bool explicitLayout );

	struct InterfaceBlock
	{
		InterfaceBlock( TypesCache & typesCache
			, MemoryLayout layout
			, std::string const & name )
			: m_type{ getType( typesCache, layout, name ) }
		{
		}

		explicit InterfaceBlock( BaseStructPtr dataType )
			: m_type{ std::move( dataType ) }
		{
		}

		std::string const & getName()const noexcept
		{
			return m_type->getName();
		}

		template< Kind Kind >
		std::tuple< TypePtr, bool, uint32_t > registerMember( std::string name
			, uint32_t arraySize = ast::type::NotArray )
		{
			static_assert( Kind != Kind::eBoolean, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != Kind::eVec2B, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != Kind::eVec3B, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != Kind::eVec4B, "Can't put a boolean type inside an interface block" );
			return registerMember( std::move( name )
				, getBasicType( m_type->getTypesCache(), Kind, true )
				, arraySize );
		}

		std::tuple< TypePtr, bool, uint32_t > registerMember( std::string name
			, TypePtr type
			, uint32_t arraySize = ast::type::NotArray )
		{
			auto [mbr, added, index] = m_type->declMember( std::move( name )
				, getExplicitLayoutType( m_type->getTypesCache(), type )
				, arraySize );
			return { mbr.type, added, index };
		}

		uint32_t findMember( std::string_view name )const
		{
			return m_type->findMember( name );
		}

		bool hasMember( std::string_view name )const
		{
			return m_type->hasMember( name );
		}

		TypePtr getMember( std::string_view name )const
		{
			return m_type->getMember( name ).type;
		}

		TypePtr getMember( uint32_t index )const
		{
			return m_type->getMember( index ).type;
		}

		BaseStructPtr getType()const noexcept
		{
			return m_type;
		}

		static BaseStructPtr getType( TypesCache & typesCache
			, MemoryLayout layout
			, std::string const & name )
		{
			return getStruct( typesCache, layout, name, true );
		}

	private:
		BaseStructPtr m_type{};
	};
}

#endif
