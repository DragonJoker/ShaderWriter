#include "Common.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;

	std::string getName( type::MemoryLayout layout )
	{
		switch ( layout )
		{
		case type::MemoryLayout::eStd140:
			return "Std140";
		case type::MemoryLayout::eStd430:
			return "Std430";
		case type::MemoryLayout::eC:
			return "C";
		case type::MemoryLayout::eScalar:
			return "Scalar";
		case type::MemoryLayout::eShaderRecord:
			return "ShaderRecord";
		default:
			return "Unknown";
		}
	}

	uint32_t updateCount( uint32_t & count, std::string & name )
	{
		++count;
		name = "mbr" + std::to_string( count );
		return count;
	}

	void testStruct( test::TestCounts & testCounts, type::MemoryLayout layout, type::Kind mbrKind )
	{
		{
			type::TypesCache typesCache;
			auto type = typesCache.getStruct( layout, "test" );
			astCheck( type->getRawKind() == type::Kind::eStruct )
			astCheck( type->getKind() == type::Kind::eStruct )
			astCheck( type->getMemoryLayout() == layout )
			astCheck( type->getName() == "test" )
			astCheck( type->getFlag() == 0u )
			astCheck( !type->isShaderInput() )
			astCheck( !type->isShaderOutput() )
			astCheck( !type->isPatchInput() )
			astCheck( !type->isPatchOutput() )
			astCheck( !type->isPerTaskNV() )
			astCheck( !type->isPerTask() )
			astCheck( type->getEntryPoint() == EntryPoint::eNone )
			astCheck( type->size() == 0u )
			astCheck( type->empty() )
			astCheck( type->begin() == type->end() )
			astCheck( !type->hasMember( "mbr" ) )
			astCheck( !type->hasMember( Builtin::eBaseVertex ) )
			astCheck( type->findMember( "mbr" ) == type::Struct::NotFound )
			astCheck( type->findMember( Builtin::eBaseVertex ) == type::Struct::NotFound )
			astCheck( !hasRuntimeArray( type ) )
			astCheckThrow( type->getMember( "mbr" ) )
			astCheckThrow( type->getMember( Builtin::eBaseVertex ) )
			uint32_t count{};
			std::string name{};
			if ( astOn( "Non array builtin member declaration, undefined index" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( Builtin::eBaseVertex, mbrKind, type::NotArray, type::Struct::UndefinedIndex, false ).second )
					astCheck( !type->hasMember( Builtin::eBaseVertex ) )
					astCheck( type->findMember( Builtin::eBaseVertex ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eBaseVertex ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( Builtin::eBaseVertex, mbrKind, type::NotArray, type::Struct::UndefinedIndex, true ).second )
					astCheck( !type->declMember( Builtin::eBaseVertex, mbrKind, type::NotArray, type::Struct::UndefinedIndex, true ).second )
					astCheck( type->hasMember( Builtin::eBaseVertex ) )
					astCheck( type->findMember( Builtin::eBaseVertex ) != type::Struct::NotFound )
					astCheckNoThrow( type->getMember( Builtin::eBaseVertex ) )
					astCheck( !hasRuntimeArray( type ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Array builtin member declaration, undefined index" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( Builtin::eBaseInstance, mbrKind, 4u, type::Struct::UndefinedIndex, false ).second )
					astCheck( !type->hasMember( Builtin::eBaseInstance ) )
					astCheck( type->findMember( Builtin::eBaseInstance ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eBaseInstance ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( Builtin::eBaseInstance, mbrKind, 4u, type::Struct::UndefinedIndex, true ).second )
					astCheck( !type->declMember( Builtin::eBaseInstance, mbrKind, 4u, type::Struct::UndefinedIndex, true ).second )
					astCheck( type->hasMember( Builtin::eBaseInstance ) )
					astCheck( type->findMember( Builtin::eBaseInstance ) != type::Struct::NotFound )
					astCheckNoThrow( type->getMember( Builtin::eBaseInstance ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Non array builtin member declaration, defined index" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( Builtin::eDrawIndex, mbrKind, type::NotArray, 7u, false ).second )
					astCheck( !type->hasMember( Builtin::eDrawIndex ) )
					astCheck( type->findMember( Builtin::eDrawIndex ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eDrawIndex ) )
					astCheck( !type->hasMember( Builtin::eDrawIndex, 7u ) )
					astCheck( type->findMember( Builtin::eDrawIndex, 7u ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eDrawIndex, 7u ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( Builtin::eDrawIndex, mbrKind, type::NotArray, 7u, true ).second )
					astCheck( !type->declMember( Builtin::eDrawIndex, mbrKind, type::NotArray, 7u, true ).second )
					astCheck( !type->hasMember( Builtin::eDrawIndex ) )
					astCheck( type->findMember( Builtin::eDrawIndex ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eDrawIndex ) )
					astCheck( type->hasMember( Builtin::eDrawIndex, 7u ) )
					astCheck( type->findMember( Builtin::eDrawIndex, 7u ) != type::Struct::NotFound )
					astCheckNoThrow( type->getMember( Builtin::eDrawIndex, 7u ) )
					astCheck( !hasRuntimeArray( type ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Array builtin member declaration, defined index" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( Builtin::eDeviceIndex, mbrKind, 4u, 8u, false ).second )
					astCheck( !type->hasMember( Builtin::eDeviceIndex ) )
					astCheck( type->findMember( Builtin::eDeviceIndex ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eDeviceIndex ) )
					astCheck( !type->hasMember( Builtin::eDeviceIndex, 8u ) )
					astCheck( type->findMember( Builtin::eDeviceIndex, 8u ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eDeviceIndex, 8u ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( Builtin::eDeviceIndex, mbrKind, 4u, 8u, true ).second )
					astCheck( !type->declMember( Builtin::eDeviceIndex, mbrKind, 4u, 8u, true ).second )
					astCheck( !type->hasMember( Builtin::eDeviceIndex ) )
					astCheck( type->findMember( Builtin::eDeviceIndex ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( Builtin::eDeviceIndex ) )
					astCheck( type->hasMember( Builtin::eDeviceIndex, 8u ) )
					astCheck( type->findMember( Builtin::eDeviceIndex, 8u ) != type::Struct::NotFound )
					astCheckNoThrow( type->getMember( Builtin::eDeviceIndex, 8u ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Non array basic kind member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, mbrKind, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, mbrKind, type::NotArray, true ).second )
					astCheck( !type->declMember( name, mbrKind, type::NotArray, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Non array basic type member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getBasicType( mbrKind ), type::NotArray, true ).second )
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), type::NotArray, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Non array basic array member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), type::NotArray, true ).second )
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), type::NotArray, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Non array base struct member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getStruct( layout, "mbr" ), false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					auto structType = typesCache.getStruct( layout, "mbr" );
					structType->declMember( "mbmbr", mbrKind );
					astCheck( type->declMember( name, structType, type::NotArray, true ).second )
					astCheck( !type->declMember( name, structType, type::NotArray, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Non array I/O struct member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getIOStruct( "iombr", EntryPoint::eCompute, var::Flag::eShaderInput ), false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					auto structType = typesCache.getIOStruct( "iombr", EntryPoint::eCompute, var::Flag::eShaderInput );
					structType->declMember( "mbmbr", mbrKind, 1u );
					astCheck( type->declMember( name, structType, type::NotArray, true ).second )
					astCheck( !type->declMember( name, structType, type::NotArray, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Static array basic kind member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, mbrKind, 4u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, mbrKind, 4u, true ).second )
					astCheck( !type->declMember( name, mbrKind, 4u, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Static array basic type member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), 4u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getBasicType( mbrKind ), 4u, true ).second )
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), 4u, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Static array basic array member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, true ).second )
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Static array struct member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getStruct( layout, "mbr" ), 4u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getStruct( layout, "mbr" ), 4u, true ).second )
					astCheck( !type->declMember( name, typesCache.getStruct( layout, "mbr" ), 4u, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( !hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Dynamic array member declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, mbrKind, type::UnknownArraySize, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, mbrKind, type::UnknownArraySize, true ).second )
					astCheck( !type->declMember( name, mbrKind, type::UnknownArraySize, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			if ( astOn( "Dynamic array member array declaration" ) )
			{
				if ( astWhen( "Non enabled" ) )
				{
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u ), type::UnknownArraySize, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u ), type::UnknownArraySize, true ).second )
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u ), type::UnknownArraySize, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			{
				auto mbrType = typesCache.getMemberType( typesCache.getBasicType( mbrKind ), *type, 0u );
				astCheck( mbrType != typesCache.getBasicType( mbrKind ) )
				astCheck( mbrType->getNonMemberType() == typesCache.getBasicType( mbrKind ) )
			}
			{
				auto type2 = typesCache.getStruct( layout, "test" );
				astCheck( type == type2 )
				astCheck( *type == *type2 )
			}
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
		}
		{
			type::TypesCache typesCache;
			astCheckThrow( typesCache.getIOStruct( "test", EntryPoint::eNone, var::Flag::eNone ) )
		}
	}

	struct StructType
	{
		type::Kind member;
		type::MemoryLayout layout;

		StructType & operator+( int i )
		{
			if ( layout != type::MemoryLayout::eShaderRecord )
			{
				layout = type::MemoryLayout( uint8_t( layout ) + 1 );
				return *this;
			}
			layout = type::MemoryLayout::eStd140;

			if ( member != type::Kind::eBasicTypesMax )
			{
				member = type::Kind( uint8_t( member ) + 1 );
				return *this;
			}
			member = type::Kind::eBoolean;

			return *this;
		}

	private:
		friend bool operator<( StructType const & lhs, StructType const & rhs )
		{
			return ( uint8_t( lhs.member ) < uint8_t( rhs.member )
				|| ( lhs.member == rhs.member
					&& ( uint8_t( lhs.layout ) < uint8_t( rhs.layout ) ) ) );
		}
	};

	static constexpr StructType minStructType{ type::Kind::eBoolean
		, type::MemoryLayout::eStd140 };

	static constexpr StructType maxStructType{ type::Kind::eBasicTypesMax
		, type::MemoryLayout::eShaderRecord };

	std::string getStructTypeName( StructType const & v )
	{
		return getName( v.layout ) + debug::getTypeName( v.member );
	}

	using StructTypes = testing::TestWithParam< StructType >;

	TEST_P( StructTypes, Struct )
	{
		auto param = GetParam();
		astTestBegin( "testStruct" + getStructTypeName( param ) );
		testStruct( testCounts, param.layout, param.member );
		astTestEnd()
	}
}

INSTANTIATE_TEST_SUITE_P( TestASTStructTypes, StructTypes
	, testing::Range( minStructType, maxStructType )
	, astTestNameP( StructType, getStructTypeName ) );
