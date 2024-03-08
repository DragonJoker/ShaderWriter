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
		astTestBegin( "testStruct" + getName( layout ) + debug::getTypeName( mbrKind ) );
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
				auto mbrType = typesCache.getBasicType( mbrKind )->getMemberType( *type, 0u );
				astCheck( mbrType != typesCache.getBasicType( mbrKind ) )
				astCheck( mbrType->getNonMemberType() == typesCache.getBasicType( mbrKind ).get() )
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
		astTestEnd()
	}

	template< type::Kind MbrKindT >
	void testInterfaceBlockT( test::TestCounts & testCounts, type::MemoryLayout layout )
	{
		astTestBegin( "testInterfaceBlock" + getName( layout ) + debug::getTypeName( MbrKindT ) );
		type::TypesCache typesCache;
		InterfaceBlock block{ typesCache, layout, "test" };
		uint32_t count{};
		std::string name{};
		if constexpr ( MbrKindT != type::Kind::eBoolean
			&& MbrKindT != type::Kind::eVec2B
			&& MbrKindT != type::Kind::eVec3B
			&& MbrKindT != type::Kind::eVec4B )
		{
			if ( astOn( "Non array basic kind member declaration" ) )
			{
				astCheck( block.registerMember< MbrKindT >( name, type::NotArray ).second )
				astCheck( !block.registerMember< MbrKindT >( name, type::NotArray ).second )
				astCheck( block.hasMember( name ) )
				astCheck( block.findMember( name ) != type::Struct::NotFound )
				astCheckNoThrow( block.getMember( name ) )
				astCheck( block.getType()->size() == updateCount( count, name ) )
			}
		}
		if ( astOn( "Non array basic type member declaration" ) )
		{
			astCheck( block.registerMember( name, typesCache.getBasicType( MbrKindT ), type::NotArray ).second )
			astCheck( !block.registerMember( name, typesCache.getBasicType( MbrKindT ), type::NotArray ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Non array basic array member declaration" ) )
		{
			astCheck( block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), type::NotArray ).second )
			astCheck( !block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), type::NotArray ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Non array base struct member declaration" ) )
		{
			auto structType = typesCache.getStruct( layout, "mbr" );
			structType->declMember( "mbmbr", MbrKindT );
			astCheck( block.registerMember( name, structType, type::NotArray ).second )
			astCheck( !block.registerMember( name, structType, type::NotArray ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Non array I/O struct member declaration" ) )
		{
			auto structType = typesCache.getIOStruct( "iombr", EntryPoint::eCompute, var::Flag::eShaderInput );
			structType->declMember( "mbmbr", MbrKindT, 1u );
			astCheck( block.registerMember( name, structType, type::NotArray ).second )
			astCheck( !block.registerMember( name, structType, type::NotArray ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if constexpr ( MbrKindT != type::Kind::eBoolean
			&& MbrKindT != type::Kind::eVec2B
			&& MbrKindT != type::Kind::eVec3B
			&& MbrKindT != type::Kind::eVec4B )
		{
			if ( astOn( "Static array basic kind member declaration" ) )
			{
				astCheck( block.registerMember< MbrKindT >( name, 4u ).second )
				astCheck( !block.registerMember< MbrKindT >( name, 4u ).second )
				astCheck( block.hasMember( name ) )
				astCheck( block.findMember( name ) != type::Struct::NotFound )
				astCheckNoThrow( block.getMember( name ) )
				astCheck( block.getType()->size() == updateCount( count, name ) )
			}
		}
		if ( astOn( "Static array basic type member declaration" ) )
		{
			astCheck( block.registerMember( name, typesCache.getBasicType( MbrKindT ), 4u ).second )
			astCheck( !block.registerMember( name, typesCache.getBasicType( MbrKindT ), 4u ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Static array basic array member declaration" ) )
		{
			astCheck( block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ).second )
			astCheck( !block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Static array struct member declaration" ) )
		{
			astCheck( block.registerMember( name, typesCache.getStruct( layout, "mbr" ), 4u ).second )
			astCheck( !block.registerMember( name, typesCache.getStruct( layout, "mbr" ), 4u ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if constexpr ( MbrKindT != type::Kind::eBoolean
			&& MbrKindT != type::Kind::eVec2B
			&& MbrKindT != type::Kind::eVec3B
			&& MbrKindT != type::Kind::eVec4B )
		{
			if ( astOn( "Dynamic array member declaration" ) )
			{
				astCheck( block.registerMember< MbrKindT >( name, type::UnknownArraySize ).second )
				astCheck( !block.registerMember< MbrKindT >( name, type::UnknownArraySize ).second )
				astCheck( block.hasMember( name ) )
				astCheck( block.findMember( name ) != type::Struct::NotFound )
				astCheckNoThrow( block.getMember( name ) )
				astCheck( block.getType()->size() == updateCount( count, name ) )
			}
		}
		if ( astOn( "Dynamic array member array declaration" ) )
		{
			astCheck( block.registerMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ), type::UnknownArraySize ).second )
			astCheck( !block.registerMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ), type::UnknownArraySize ).second )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		astTestEnd()
	}

	void testInterfaceBlock( test::TestCounts & testCounts, type::MemoryLayout layout, type::Kind mbrKind )
	{
		switch ( mbrKind )
		{
		case type::Kind::eBoolean:
			testInterfaceBlockT< type::Kind::eBoolean >( testCounts, layout );
			break;
		case type::Kind::eInt8:
			testInterfaceBlockT< type::Kind::eInt8 >( testCounts, layout );
			break;
		case type::Kind::eInt16:
			testInterfaceBlockT< type::Kind::eInt16 >( testCounts, layout );
			break;
		case type::Kind::eInt32:
			testInterfaceBlockT< type::Kind::eInt32 >( testCounts, layout );
			break;
		case type::Kind::eInt64:
			testInterfaceBlockT< type::Kind::eInt64 >( testCounts, layout );
			break;
		case type::Kind::eUInt8:
			testInterfaceBlockT< type::Kind::eUInt8 >( testCounts, layout );
			break;
		case type::Kind::eUInt16:
			testInterfaceBlockT< type::Kind::eUInt16 >( testCounts, layout );
			break;
		case type::Kind::eUInt32:
			testInterfaceBlockT< type::Kind::eUInt32 >( testCounts, layout );
			break;
		case type::Kind::eUInt64:
			testInterfaceBlockT< type::Kind::eUInt64 >( testCounts, layout );
			break;
		case type::Kind::eHalf:
			testInterfaceBlockT< type::Kind::eHalf >( testCounts, layout );
			break;
		case type::Kind::eFloat:
			testInterfaceBlockT< type::Kind::eFloat >( testCounts, layout );
			break;
		case type::Kind::eDouble:
			testInterfaceBlockT< type::Kind::eDouble >( testCounts, layout );
			break;
		case type::Kind::eVec2B:
			testInterfaceBlockT< type::Kind::eVec2B >( testCounts, layout );
			break;
		case type::Kind::eVec3B:
			testInterfaceBlockT< type::Kind::eVec3B >( testCounts, layout );
			break;
		case type::Kind::eVec4B:
			testInterfaceBlockT< type::Kind::eVec4B >( testCounts, layout );
			break;
		case type::Kind::eVec2I8:
			testInterfaceBlockT< type::Kind::eVec2I8 >( testCounts, layout );
			break;
		case type::Kind::eVec3I8:
			testInterfaceBlockT< type::Kind::eVec3I8 >( testCounts, layout );
			break;
		case type::Kind::eVec4I8:
			testInterfaceBlockT< type::Kind::eVec4I8 >( testCounts, layout );
			break;
		case type::Kind::eVec2I16:
			testInterfaceBlockT< type::Kind::eVec2I16 >( testCounts, layout );
			break;
		case type::Kind::eVec3I16:
			testInterfaceBlockT< type::Kind::eVec3I16 >( testCounts, layout );
			break;
		case type::Kind::eVec4I16:
			testInterfaceBlockT< type::Kind::eVec4I16 >( testCounts, layout );
			break;
		case type::Kind::eVec2I32:
			testInterfaceBlockT< type::Kind::eVec2I32 >( testCounts, layout );
			break;
		case type::Kind::eVec3I32:
			testInterfaceBlockT< type::Kind::eVec3I32 >( testCounts, layout );
			break;
		case type::Kind::eVec4I32:
			testInterfaceBlockT< type::Kind::eVec4I32 >( testCounts, layout );
			break;
		case type::Kind::eVec2I64:
			testInterfaceBlockT< type::Kind::eVec2I64 >( testCounts, layout );
			break;
		case type::Kind::eVec3I64:
			testInterfaceBlockT< type::Kind::eVec3I64 >( testCounts, layout );
			break;
		case type::Kind::eVec4I64:
			testInterfaceBlockT< type::Kind::eVec4I64 >( testCounts, layout );
			break;
		case type::Kind::eVec2U8:
			testInterfaceBlockT< type::Kind::eVec2U8 >( testCounts, layout );
			break;
		case type::Kind::eVec3U8:
			testInterfaceBlockT< type::Kind::eVec3U8 >( testCounts, layout );
			break;
		case type::Kind::eVec4U8:
			testInterfaceBlockT< type::Kind::eVec4U8 >( testCounts, layout );
			break;
		case type::Kind::eVec2U16:
			testInterfaceBlockT< type::Kind::eVec2U16 >( testCounts, layout );
			break;
		case type::Kind::eVec3U16:
			testInterfaceBlockT< type::Kind::eVec3U16 >( testCounts, layout );
			break;
		case type::Kind::eVec4U16:
			testInterfaceBlockT< type::Kind::eVec4U16 >( testCounts, layout );
			break;
		case type::Kind::eVec2U32:
			testInterfaceBlockT< type::Kind::eVec2U32 >( testCounts, layout );
			break;
		case type::Kind::eVec3U32:
			testInterfaceBlockT< type::Kind::eVec3U32 >( testCounts, layout );
			break;
		case type::Kind::eVec4U32:
			testInterfaceBlockT< type::Kind::eVec4U32 >( testCounts, layout );
			break;
		case type::Kind::eVec2U64:
			testInterfaceBlockT< type::Kind::eVec2U64 >( testCounts, layout );
			break;
		case type::Kind::eVec3U64:
			testInterfaceBlockT< type::Kind::eVec3U64 >( testCounts, layout );
			break;
		case type::Kind::eVec4U64:
			testInterfaceBlockT< type::Kind::eVec4U64 >( testCounts, layout );
			break;
		case type::Kind::eVec2H:
			testInterfaceBlockT< type::Kind::eVec2H >( testCounts, layout );
			break;
		case type::Kind::eVec4H:
			testInterfaceBlockT< type::Kind::eVec4H >( testCounts, layout );
			break;
		case type::Kind::eVec2F:
			testInterfaceBlockT< type::Kind::eVec2F >( testCounts, layout );
			break;
		case type::Kind::eVec3F:
			testInterfaceBlockT< type::Kind::eVec3F >( testCounts, layout );
			break;
		case type::Kind::eVec4F:
			testInterfaceBlockT< type::Kind::eVec4F >( testCounts, layout );
			break;
		case type::Kind::eVec2D:
			testInterfaceBlockT< type::Kind::eVec2D >( testCounts, layout );
			break;
		case type::Kind::eVec3D:
			testInterfaceBlockT< type::Kind::eVec3D >( testCounts, layout );
			break;
		case type::Kind::eVec4D:
			testInterfaceBlockT< type::Kind::eVec4D >( testCounts, layout );
			break;
		case type::Kind::eMat2x2F:
			testInterfaceBlockT< type::Kind::eMat2x2F >( testCounts, layout );
			break;
		case type::Kind::eMat2x3F:
			testInterfaceBlockT< type::Kind::eMat2x3F >( testCounts, layout );
			break;
		case type::Kind::eMat2x4F:
			testInterfaceBlockT< type::Kind::eMat2x4F >( testCounts, layout );
			break;
		case type::Kind::eMat3x2F:
			testInterfaceBlockT< type::Kind::eMat3x2F >( testCounts, layout );
			break;
		case type::Kind::eMat3x3F:
			testInterfaceBlockT< type::Kind::eMat3x3F >( testCounts, layout );
			break;
		case type::Kind::eMat3x4F:
			testInterfaceBlockT< type::Kind::eMat3x4F >( testCounts, layout );
			break;
		case type::Kind::eMat4x2F:
			testInterfaceBlockT< type::Kind::eMat4x2F >( testCounts, layout );
			break;
		case type::Kind::eMat4x3F:
			testInterfaceBlockT< type::Kind::eMat4x3F >( testCounts, layout );
			break;
		case type::Kind::eMat4x4F:
			testInterfaceBlockT< type::Kind::eMat4x4F >( testCounts, layout );
			break;
		case type::Kind::eMat2x2D:
			testInterfaceBlockT< type::Kind::eMat2x2D >( testCounts, layout );
			break;
		case type::Kind::eMat2x3D:
			testInterfaceBlockT< type::Kind::eMat2x3D >( testCounts, layout );
			break;
		case type::Kind::eMat2x4D:
			testInterfaceBlockT< type::Kind::eMat2x4D >( testCounts, layout );
			break;
		case type::Kind::eMat3x2D:
			testInterfaceBlockT< type::Kind::eMat3x2D >( testCounts, layout );
			break;
		case type::Kind::eMat3x3D:
			testInterfaceBlockT< type::Kind::eMat3x3D >( testCounts, layout );
			break;
		case type::Kind::eMat3x4D:
			testInterfaceBlockT< type::Kind::eMat3x4D >( testCounts, layout );
			break;
		case type::Kind::eMat4x2D:
			testInterfaceBlockT< type::Kind::eMat4x2D >( testCounts, layout );
			break;
		case type::Kind::eMat4x3D:
			testInterfaceBlockT< type::Kind::eMat4x3D >( testCounts, layout );
			break;
		case type::Kind::eMat4x4D:
			testInterfaceBlockT< type::Kind::eMat4x4D >( testCounts, layout );
			break;
		default:
			break;
		}
	}

	void testIOStruct( test::TestCounts & testCounts, EntryPoint entryPoint, var::Flag flag, type::Kind mbrKind )
	{
		astTestBegin( "testIOStruct" + type::IOStruct::getNameSuffix( entryPoint, flag ) + debug::getTypeName( mbrKind ) );
		{
			type::TypesCache typesCache;
			std::string structName = "test" + type::IOStruct::getNameSuffix( entryPoint, flag );
			auto type = typesCache.getIOStruct( "test", entryPoint, flag );
			astCheck( type->getRawKind() == type::Kind::eStruct )
			astCheck( type->getKind() == type::Kind::eStruct )
			astCheck( type->getName() == structName )
			astCheck( type->getFlag() == uint64_t( flag ) )
			astCheck( type->getEntryPoint() == entryPoint )
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
					astCheck( !type->declMember( name, mbrKind, 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, mbrKind, type::NotArray, 18u, true ).second )
					astCheck( !type->declMember( name, mbrKind, type::NotArray, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getBasicType( mbrKind ), type::NotArray, 18u, true ).second )
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), type::NotArray, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), type::NotArray, 18u, true ).second )
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), type::NotArray, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getStruct( type::MemoryLayout::eC, "mbr" ), 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					auto structType = typesCache.getStruct( type::MemoryLayout::eC, "mbr" );
					structType->declMember( "mbmbr", mbrKind );
					astCheck( type->declMember( name, structType, type::NotArray, 18u, true ).second )
					astCheck( !type->declMember( name, structType, type::NotArray, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getIOStruct( "iombr", entryPoint, flag ), 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					auto structType = typesCache.getIOStruct( "iombr", entryPoint, flag );
					structType->declMember( "mbmbr", mbrKind, 1u );
					astCheck( type->declMember( name, structType, type::NotArray, 18u, true ).second )
					astCheck( !type->declMember( name, structType, type::NotArray, 18u, true ).second )
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
					astCheck( !type->declMember( name, mbrKind, 4u, 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, mbrKind, 4u, 18u, true ).second )
					astCheck( !type->declMember( name, mbrKind, 4u, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), 4u, 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getBasicType( mbrKind ), 4u, 18u, true ).second )
					astCheck( !type->declMember( name, typesCache.getBasicType( mbrKind ), 4u, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, 18u, true ).second )
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getIOStruct( "iombr", entryPoint, flag ), 4u, 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getIOStruct( "iombr", entryPoint, flag ), 4u, 18u, true ).second )
					astCheck( !type->declMember( name, typesCache.getIOStruct( "iombr", entryPoint, flag ), 4u, 18u, true ).second )
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
					astCheck( !type->declMember( name, mbrKind, type::UnknownArraySize, 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, mbrKind, type::UnknownArraySize, 18u, true ).second )
					astCheck( !type->declMember( name, mbrKind, type::UnknownArraySize, 18u, true ).second )
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
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u ), type::UnknownArraySize, 18u, false ).second )
					astCheck( !type->hasMember( name ) )
					astCheck( type->findMember( name ) == type::Struct::NotFound )
					astCheckThrow( type->getMember( name ) )
					astCheck( type->size() == count )
				}
				if ( astWhen( "Enabled" ) )
				{
					astCheck( type->declMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u ), type::UnknownArraySize, 18u, true ).second )
					astCheck( !type->declMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u ), type::UnknownArraySize, 18u, true ).second )
					astCheck( type->hasMember( name ) )
					astCheck( type->findMember( name ) != type::Struct::NotFound )
					astCheck( hasRuntimeArray( type ) )
					astCheckNoThrow( type->getMember( name ) )
					astCheck( type->size() == updateCount( count, name ) )
				}
			}
			{
				auto mbrType = typesCache.getBasicType( mbrKind )->getMemberType( *type, 0u );
				astCheck( mbrType != typesCache.getBasicType( mbrKind ) )
				astCheck( mbrType->getNonMemberType() == typesCache.getBasicType( mbrKind ).get() )
			}
			{
				auto type2 = typesCache.getIOStruct( "test", entryPoint, flag );
				astCheck( type == type2 )
				astCheck( *type == *type2 )
			}
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
		}
		astTestEnd()
	}
}

astTestSuiteMain( TestASTStructTypes )
{
	astTestSuiteBegin()
	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, type::MemoryLayout::eStd140, type::Kind( i ) );
	}

	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, type::MemoryLayout::eStd430, type::Kind( i ) );
	}

	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, type::MemoryLayout::eScalar, type::Kind( i ) );
	}

	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, type::MemoryLayout::eC, type::Kind( i ) );
	}

	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testInterfaceBlock( testCounts, type::MemoryLayout::eStd140, type::Kind( i ) );
	}

	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testInterfaceBlock( testCounts, type::MemoryLayout::eStd430, type::Kind( i ) );
	}

	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testInterfaceBlock( testCounts, type::MemoryLayout::eScalar, type::Kind( i ) );
	}

	for ( auto i = uint32_t( type::Kind::eBoolean ); i <= uint32_t( type::Kind::eBasicTypesMax ); ++i )
	{
		testInterfaceBlock( testCounts, type::MemoryLayout::eC, type::Kind( i ) );
	}

	for ( auto i = uint32_t( EntryPoint::eVertex ); i <= uint32_t( EntryPoint::eCompute ); ++i )
	{
		for ( auto j = uint32_t( type::Kind::eBoolean ); j <= uint32_t( type::Kind::eBasicTypesMax ); ++j )
		{
			testIOStruct( testCounts, EntryPoint( i ), var::Flag::eShaderInput, type::Kind( j ) );
		}
	}

	for ( auto i = uint32_t( EntryPoint::eVertex ); i <= uint32_t( EntryPoint::eCompute ); ++i )
	{
		for ( auto j = uint32_t( type::Kind::eBoolean ); j <= uint32_t( type::Kind::eBasicTypesMax ); ++j )
		{
			testIOStruct( testCounts, EntryPoint( i ), var::Flag::eShaderOutput, type::Kind( j ) );
		}
	}

	for ( auto i = uint32_t( EntryPoint::eVertex ); i <= uint32_t( EntryPoint::eCompute ); ++i )
	{
		for ( auto j = uint32_t( type::Kind::eBoolean ); j <= uint32_t( type::Kind::eBasicTypesMax ); ++j )
		{
			testIOStruct( testCounts, EntryPoint( i ), var::Flag::ePatchInput, type::Kind( j ) );
		}
	}

	for ( auto i = uint32_t( EntryPoint::eVertex ); i <= uint32_t( EntryPoint::eCompute ); ++i )
	{
		for ( auto j = uint32_t( type::Kind::eBoolean ); j <= uint32_t( type::Kind::eBasicTypesMax ); ++j )
		{
			testIOStruct( testCounts, EntryPoint( i ), var::Flag::ePatchOutput, type::Kind( j ) );
		}
	}

	for ( auto i = uint32_t( EntryPoint::eVertex ); i <= uint32_t( EntryPoint::eCompute ); ++i )
	{
		for ( auto j = uint32_t( type::Kind::eBoolean ); j <= uint32_t( type::Kind::eBasicTypesMax ); ++j )
		{
			testIOStruct( testCounts, EntryPoint( i ), var::Flag::ePerTask, type::Kind( j ) );
		}
	}

	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTStructTypes )
