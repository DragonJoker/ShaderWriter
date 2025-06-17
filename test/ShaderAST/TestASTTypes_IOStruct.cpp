#include "Common.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;

	std::string getName( ast::EntryPoint entryPoint
		, var::Flag flag )
	{
		std::string result{ "Unknown" };

		switch ( entryPoint )
		{
		case EntryPoint::eNone:
			result = std::string{};
			break;
		case EntryPoint::eVertex:
			result = "Vert";
			break;
		case EntryPoint::eTessellationControl:
			result = "Tesc";
			break;
		case EntryPoint::eTessellationEvaluation:
			result = "Tese";
			break;
		case EntryPoint::eGeometry:
			result = "Geom";
			break;
		case EntryPoint::eMeshNV:
			result = "MeshNV";
			break;
		case EntryPoint::eMesh:
			result = "Mesh";
			break;
		case EntryPoint::eTaskNV:
			result = "TaskNV";
			break;
		case EntryPoint::eTask:
			result = "Task";
			break;
		case EntryPoint::eFragment:
			result = "Frag";
			break;
		case EntryPoint::eRayGeneration:
			result = "Rgen";
			break;
		case EntryPoint::eRayAnyHit:
			result = "Rany";
			break;
		case EntryPoint::eRayClosestHit:
			result = "Rcls";
			break;
		case EntryPoint::eRayMiss:
			result = "Rmis";
			break;
		case EntryPoint::eRayIntersection:
			result = "Rint";
			break;
		case EntryPoint::eCallable:
			result = "Call";
			break;
		case EntryPoint::eCompute:
			result = "Comp";
			break;
		default:
			AST_Failure( "Unsupported EntryPoint" );
		}

		result += ( ( hasFlag( uint64_t( flag ), ast::var::Flag::ePatchInput ) || hasFlag( uint64_t( flag ), ast::var::Flag::ePatchOutput ) )
			? std::string{ "Patch" }
		: std::string{} );
		result += ( ( hasFlag( uint64_t( flag ), ast::var::Flag::eShaderOutput ) || hasFlag( uint64_t( flag ), ast::var::Flag::ePatchOutput ) )
			? std::string{ "Output" }
			: ( ( hasFlag( uint64_t( flag ), ast::var::Flag::eShaderInput ) || hasFlag( uint64_t( flag ), ast::var::Flag::ePatchInput ) )
				? std::string{ "Input" }
		: std::string{} ) );
		return result;
	}

	uint32_t updateCount( uint32_t & count, std::string & name )
	{
		++count;
		name = "mbr" + std::to_string( count );
		return count;
	}

	void testIOStruct( test::TestCounts & testCounts, EntryPoint entryPoint, var::Flag flag, type::Kind mbrKind )
	{
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
				auto mbrType = typesCache.getMemberType( typesCache.getBasicType( mbrKind ), *type, 0u );
				astCheck( mbrType != typesCache.getBasicType( mbrKind ) )
				astCheck( mbrType->getNonMemberType() == typesCache.getBasicType( mbrKind ) )
			}
			{
				auto type2 = typesCache.getIOStruct( "test", entryPoint, flag );
				astCheck( type == type2 )
				astCheck( *type == *type2 )
			}
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
		}
	}

	static constexpr std::array< var::Flag, 5U > supportedFlags{ var::Flag::eShaderInput
		, var::Flag::eShaderOutput
		, var::Flag::ePatchInput
		, var::Flag::ePatchOutput
		, var::Flag::ePerTask };

	struct IOStructType
	{
		type::Kind member;
		EntryPoint entryPoint;
		size_t flagIndex;

		IOStructType & operator+( int i )
		{
			if ( flagIndex < supportedFlags.size() - 1u )
			{
				++flagIndex;
				return *this;
			}
			flagIndex = 0u;

			if ( entryPoint != EntryPoint::eCompute )
			{
				entryPoint = EntryPoint( uint8_t( entryPoint ) + 1 );
				return *this;
			}
			entryPoint = EntryPoint::eVertex;

			if ( member != type::Kind::eBasicTypesMax )
			{
				member = type::Kind( uint8_t( member ) + 1 );
				return *this;
			}
			member = type::Kind::eBoolean;

			return *this;
		}

	private:
		friend bool operator<( IOStructType const & lhs, IOStructType const & rhs )
		{
			return ( uint8_t( lhs.member ) < uint8_t( rhs.member )
				|| ( lhs.member == rhs.member
					&& ( uint8_t( lhs.entryPoint ) < uint8_t( rhs.entryPoint )
						|| ( lhs.entryPoint == rhs.entryPoint
							&& ( uint8_t( lhs.flagIndex ) < uint8_t( rhs.flagIndex ) ) ) ) ) );
		}
	};

	static constexpr IOStructType minIOStructType{ type::Kind::eBoolean
		, EntryPoint::eVertex
		, 0u };

	static constexpr IOStructType maxIOStructType{ type::Kind::eBasicTypesMax
		, EntryPoint::eCompute
		, supportedFlags.size() - 1u };

	std::string getIOStructTypeName( IOStructType const & v )
	{
		return getName( v.entryPoint, supportedFlags[v.flagIndex] ) + debug::getTypeName( v.member );
	}

	using IOStructTypes = testing::TestWithParam< IOStructType >;

	TEST_P( IOStructTypes, IOStruct )
	{
		auto param = GetParam();
		astTestBegin( "testIOStruct" + getIOStructTypeName( param ) );
		testIOStruct( testCounts, param.entryPoint, supportedFlags[param.flagIndex], param.member );
		astTestEnd()
	}
}

INSTANTIATE_TEST_SUITE_P( TestASTIOStructTypes, IOStructTypes
	, testing::Range( minIOStructType, maxIOStructType )
	, astTestNameP( IOStructType, getIOStructTypeName ) );
