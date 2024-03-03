#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	std::string getName( ast::type::MemoryLayout layout )
	{
		switch ( layout )
		{
		case ast::type::MemoryLayout::eStd140:
			return "Std140";
		case ast::type::MemoryLayout::eStd430:
			return "Std430";
		case ast::type::MemoryLayout::eC:
			return "C";
		case ast::type::MemoryLayout::eScalar:
			return "Scalar";
		case ast::type::MemoryLayout::eShaderRecord:
			return "ShaderRecord";
		default:
			return "Unknown";
		}
	}

	std::string getName( ast::EntryPoint entryPoint, ast::var::Flag flag )
	{
		auto result = getName( entryPoint );
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

	void testStruct( test::TestCounts & testCounts, ast::type::MemoryLayout layout, ast::type::Kind mbrKind )
	{
		testBegin( "testStruct" + getName( layout ) + ast::debug::getTypeName( mbrKind ) );
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getStruct( layout, "test" );
			check( type->getRawKind() == ast::type::Kind::eStruct )
			check( type->getKind() == ast::type::Kind::eStruct )
			check( type->getMemoryLayout() == layout )
			check( type->getName() == "test" )
			check( type->getFlag() == 0u )
			check( !type->isShaderInput() )
			check( !type->isShaderOutput() )
			check( !type->isPatchInput() )
			check( !type->isPatchOutput() )
			check( !type->isPerTaskNV() )
			check( !type->isPerTask() )
			check( type->getEntryPoint() == ast::EntryPoint::eNone )
			check( type->size() == 0u )
			check( type->empty() )
			check( type->begin() == type->end() )
			check( !type->hasMember( "mbr" ) )
			check( !type->hasMember( ast::Builtin::eBaseVertex ) )
			check( type->findMember( "mbr" ) == ast::type::Struct::NotFound )
			check( type->findMember( ast::Builtin::eBaseVertex ) == ast::type::Struct::NotFound )
			checkThrow( type->getMember( "mbr" ) )
			checkThrow( type->getMember( ast::Builtin::eBaseVertex ) )
			{
				check( !type->declMember( ast::Builtin::eBaseVertex, mbrKind, ast::type::NotArray, ast::type::Struct::InvalidLocation, false ).second )
				check( !type->hasMember( ast::Builtin::eBaseVertex ) )
				check( type->findMember( ast::Builtin::eBaseVertex ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( ast::Builtin::eBaseVertex ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "mbr1", mbrKind, ast::type::NotArray, false ).second )
				check( !type->hasMember( "mbr1" ) )
				check( type->findMember( "mbr1" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "mbr1" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "mbr2", typesCache.getBasicType( mbrKind ), ast::type::NotArray, false ).second )
				check( !type->hasMember( "mbr2" ) )
				check( type->findMember( "mbr2" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "mbr2" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "mbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), ast::type::NotArray, false ).second )
				check( !type->hasMember( "mbr3" ) )
				check( type->findMember( "mbr3" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "mbr3" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "mbr4", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), false ).second )
				check( !type->hasMember( "mbr4" ) )
				check( type->findMember( "mbr4" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "mbr4" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "mbr5", typesCache.getStruct( layout, "mbr" ), ast::type::NotArray, false ).second )
				check( !type->hasMember( "mbr5" ) )
				check( type->findMember( "mbr5" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "mbr5" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "mbr6", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), ast::type::NotArray, false ).second )
				check( !type->hasMember( "mbr6" ) )
				check( type->findMember( "mbr6" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "mbr6" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "mbr7", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), false ).second )
				check( !type->hasMember( "mbr7" ) )
				check( type->findMember( "mbr7" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "mbr7" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( ast::Builtin::eBaseInstance, mbrKind, 4u, ast::type::Struct::InvalidLocation, false ).second )
				check( !type->hasMember( ast::Builtin::eBaseInstance ) )
				check( type->findMember( ast::Builtin::eBaseInstance ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( ast::Builtin::eBaseInstance ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "arrmbr1", mbrKind, 4u, false ).second )
				check( !type->hasMember( "arrmbr1" ) )
				check( type->findMember( "arrmbr1" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "arrmbr1" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "arrmbr2", typesCache.getBasicType( mbrKind ), 4u, false ).second )
				check( !type->hasMember( "arrmbr2" ) )
				check( type->findMember( "arrmbr2" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "arrmbr2" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "arrmbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, false ).second )
				check( !type->hasMember( "arrmbr3" ) )
				check( type->findMember( "arrmbr3" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "arrmbr3" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "arrmbr5", typesCache.getStruct( layout, "mbr" ), 4u, false ).second )
				check( !type->hasMember( "arrmbr5" ) )
				check( type->findMember( "arrmbr5" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "arrmbr5" ) )
				check( type->empty() )
			}
			{
				check( !type->declMember( "arrmbr6", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), 4u, false ).second )
				check( !type->hasMember( "arrmbr6" ) )
				check( type->findMember( "arrmbr6" ) == ast::type::Struct::NotFound )
				checkThrow( type->getMember( "arrmbr6" ) )
				check( type->empty() )
			}
			{
				check( type->declMember( ast::Builtin::eBaseVertex, mbrKind, ast::type::NotArray, ast::type::Struct::InvalidLocation, true ).second )
				check( type->hasMember( ast::Builtin::eBaseVertex ) )
				check( type->findMember( ast::Builtin::eBaseVertex ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( ast::Builtin::eBaseVertex ) )
				check( type->size() == 1 )
			}
			{
				check( type->declMember( "mbr1", mbrKind, ast::type::NotArray, true ).second )
				check( type->hasMember( "mbr1" ) )
				check( type->findMember( "mbr1" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "mbr1" ) )
				check( type->size() == 2 )
			}
			{
				check( type->declMember( "mbr2", typesCache.getBasicType( mbrKind ), ast::type::NotArray, true ).second )
				check( type->hasMember( "mbr2" ) )
				check( type->findMember( "mbr2" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "mbr2" ) )
				check( type->size() == 3 )
			}
			{
				check( type->declMember( "mbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), ast::type::NotArray, true ).second )
				check( type->hasMember( "mbr3" ) )
				check( type->findMember( "mbr3" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "mbr3" ) )
				check( type->size() == 4 )
			}
			{
				check( type->declMember( "mbr4", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), true ).second )
				check( type->hasMember( "mbr4" ) )
				check( type->findMember( "mbr4" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "mbr4" ) )
				check( type->size() == 5 )
			}
			{
				auto structType = typesCache.getStruct( layout, "mbr" );
				structType->declMember( "mbmbr", mbrKind );
				check( type->declMember( "mbr5", structType, ast::type::NotArray, true ).second )
				check( type->hasMember( "mbr5" ) )
				check( type->findMember( "mbr5" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "mbr5" ) )
				check( type->size() == 6 )
			}
			{
				auto structType = typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput );
				structType->declMember( "mbmbr", mbrKind, ast::type::NotArray, 1u );
				check( type->declMember( "mbr6", structType, ast::type::NotArray, true ).second )
				check( type->hasMember( "mbr6" ) )
				check( type->findMember( "mbr6" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "mbr6" ) )
				check( type->size() == 7 )
			}
			{
				auto structType = typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput );
				check( type->declMember( "mbr7", structType, true ).second )
				check( type->hasMember( "mbr7" ) )
				check( type->findMember( "mbr7" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "mbr7" ) )
				check( type->size() == 8 )
			}
			{
				check( type->declMember( ast::Builtin::eBaseInstance, mbrKind, 4u, ast::type::Struct::InvalidLocation, true ).second )
				check( type->hasMember( ast::Builtin::eBaseInstance ) )
				check( type->findMember( ast::Builtin::eBaseInstance ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( ast::Builtin::eBaseInstance ) )
				check( type->size() == 9 )
			}
			{
				check( type->declMember( "arrmbr1", mbrKind, 4u, true ).second )
				check( type->hasMember( "arrmbr1" ) )
				check( type->findMember( "arrmbr1" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "arrmbr1" ) )
				check( type->size() == 10 )
			}
			{
				check( type->declMember( "arrmbr2", typesCache.getBasicType( mbrKind ), 4u, true ).second )
				check( type->hasMember( "arrmbr2" ) )
				check( type->findMember( "arrmbr2" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "arrmbr2" ) )
				check( type->size() == 11 )
			}
			{
				check( type->declMember( "arrmbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, true ).second )
				check( type->hasMember( "arrmbr3" ) )
				check( type->findMember( "arrmbr3" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "arrmbr3" ) )
				check( type->size() == 12 )
			}
			{
				check( type->declMember( "arrmbr5", typesCache.getStruct( layout, "mbr" ), 4u, true ).second )
				check( type->hasMember( "arrmbr5" ) )
				check( type->findMember( "arrmbr5" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "arrmbr5" ) )
				check( type->size() == 13 )
			}
			{
				check( type->declMember( "arrmbr6", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), 4u, true ).second )
				check( type->hasMember( "arrmbr6" ) )
				check( type->findMember( "arrmbr6" ) != ast::type::Struct::NotFound )
				checkNoThrow( type->getMember( "arrmbr6" ) )
				check( type->size() == 14 )
			}
			{
				auto mbrType = typesCache.getBasicType( mbrKind )->getMemberType( *type, 0u );
				check( mbrType != typesCache.getBasicType( mbrKind ) )
				check( mbrType->getNonMemberType() == typesCache.getBasicType( mbrKind ).get() )
			}
			{
				auto type2 = typesCache.getStruct( layout, "test" );
				check( type == type2 )
			}
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		}
		{
			ast::type::TypesCache typesCache;
			checkThrow( typesCache.getIOStruct( "test", ast::EntryPoint::eNone, ast::var::Flag::eNone ) )
		}
		testEnd()
	}

	void testIOStruct( test::TestCounts & testCounts, ast::EntryPoint entryPoint, ast::var::Flag flag )
	{
		testBegin( "testIOStruct" + getName( entryPoint, flag ) );
		{
			ast::type::TypesCache typesCache;
			std::string name = "test" + getName( entryPoint, flag );
			auto type = typesCache.getIOStruct( "test", entryPoint, flag );
			check( type->getRawKind() == ast::type::Kind::eStruct )
			check( type->getKind() == ast::type::Kind::eStruct )
			check( type->getName() == name )
			check( type->getFlag() == uint64_t( flag ) )
			check( type->getEntryPoint() == entryPoint )
			{
				auto type2 = typesCache.getIOStruct( "test", entryPoint, flag );
				check( type == type2 )
			}
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		}
		testEnd()
	}
}

testSuiteMain( TestASTStructTypes )
{
	testSuiteBegin()
	for ( uint32_t i = uint32_t( ast::type::Kind::eBoolean ); i < uint32_t( ast::type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, ast::type::MemoryLayout::eStd140, ast::type::Kind( i ) );
	}

	for ( uint32_t i = uint32_t( ast::type::Kind::eBoolean ); i < uint32_t( ast::type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, ast::type::MemoryLayout::eStd430, ast::type::Kind( i ) );
	}

	for ( uint32_t i = uint32_t( ast::type::Kind::eBoolean ); i < uint32_t( ast::type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, ast::type::MemoryLayout::eScalar, ast::type::Kind( i ) );
	}

	for ( uint32_t i = uint32_t( ast::type::Kind::eBoolean ); i < uint32_t( ast::type::Kind::eBasicTypesMax ); ++i )
	{
		testStruct( testCounts, ast::type::MemoryLayout::eC, ast::type::Kind( i ) );
	}

	testIOStruct( testCounts, ast::EntryPoint::eVertex, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationControl, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationEvaluation, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eGeometry, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eMeshNV, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eTaskNV, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eMesh, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eTask, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eFragment, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayGeneration, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayAnyHit, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayClosestHit, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayMiss, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayIntersection, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eCallable, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput );
	testIOStruct( testCounts, ast::EntryPoint::eVertex, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationControl, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationEvaluation, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eGeometry, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eMeshNV, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTaskNV, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eMesh, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTask, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eFragment, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayGeneration, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayAnyHit, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayClosestHit, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayMiss, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayIntersection, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eCallable, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eCompute, ast::var::Flag::eShaderOutput );
	testIOStruct( testCounts, ast::EntryPoint::eVertex, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationControl, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationEvaluation, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eGeometry, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eMeshNV, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTaskNV, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eMesh, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eTask, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eFragment, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayGeneration, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayAnyHit, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayClosestHit, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayMiss, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eRayIntersection, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eCallable, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eCompute, ast::var::Flag::ePatchOutput );
	testIOStruct( testCounts, ast::EntryPoint::eVertex, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationControl, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationEvaluation, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eGeometry, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eMeshNV, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eTaskNV, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eMesh, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eTask, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eFragment, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayGeneration, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayAnyHit, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayClosestHit, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayMiss, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eRayIntersection, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eCallable, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eCompute, ast::var::Flag::ePatchInput );
	testIOStruct( testCounts, ast::EntryPoint::eVertex, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationControl, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eTessellationEvaluation, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eGeometry, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eMeshNV, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eTaskNV, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eMesh, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eTask, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eFragment, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eRayGeneration, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eRayAnyHit, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eRayClosestHit, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eRayMiss, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eRayIntersection, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eCallable, ast::var::Flag::ePerTask );
	testIOStruct( testCounts, ast::EntryPoint::eCompute, ast::var::Flag::ePerTask );
	testSuiteEnd()
}

testSuiteLaunch( TestASTStructTypes )
