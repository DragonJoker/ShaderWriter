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
		astTestBegin( "testStruct" + getName( layout ) + ast::debug::getTypeName( mbrKind ) );
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getStruct( layout, "test" );
			astCheck( type->getRawKind() == ast::type::Kind::eStruct )
			astCheck( type->getKind() == ast::type::Kind::eStruct )
			astCheck( type->getMemoryLayout() == layout )
			astCheck( type->getName() == "test" )
			astCheck( type->getFlag() == 0u )
			astCheck( !type->isShaderInput() )
			astCheck( !type->isShaderOutput() )
			astCheck( !type->isPatchInput() )
			astCheck( !type->isPatchOutput() )
			astCheck( !type->isPerTaskNV() )
			astCheck( !type->isPerTask() )
			astCheck( type->getEntryPoint() == ast::EntryPoint::eNone )
			astCheck( type->size() == 0u )
			astCheck( type->empty() )
			astCheck( type->begin() == type->end() )
			astCheck( !type->hasMember( "mbr" ) )
			astCheck( !type->hasMember( ast::Builtin::eBaseVertex ) )
			astCheck( type->findMember( "mbr" ) == ast::type::Struct::NotFound )
			astCheck( type->findMember( ast::Builtin::eBaseVertex ) == ast::type::Struct::NotFound )
			astCheckThrow( type->getMember( "mbr" ) )
			astCheckThrow( type->getMember( ast::Builtin::eBaseVertex ) )
			{
				astCheck( !type->declMember( ast::Builtin::eBaseVertex, mbrKind, ast::type::NotArray, ast::type::Struct::InvalidLocation, false ).second )
				astCheck( !type->hasMember( ast::Builtin::eBaseVertex ) )
				astCheck( type->findMember( ast::Builtin::eBaseVertex ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( ast::Builtin::eBaseVertex ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "mbr1", mbrKind, ast::type::NotArray, false ).second )
				astCheck( !type->hasMember( "mbr1" ) )
				astCheck( type->findMember( "mbr1" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "mbr1" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "mbr2", typesCache.getBasicType( mbrKind ), ast::type::NotArray, false ).second )
				astCheck( !type->hasMember( "mbr2" ) )
				astCheck( type->findMember( "mbr2" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "mbr2" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "mbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), ast::type::NotArray, false ).second )
				astCheck( !type->hasMember( "mbr3" ) )
				astCheck( type->findMember( "mbr3" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "mbr3" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "mbr4", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), false ).second )
				astCheck( !type->hasMember( "mbr4" ) )
				astCheck( type->findMember( "mbr4" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "mbr4" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "mbr5", typesCache.getStruct( layout, "mbr" ), ast::type::NotArray, false ).second )
				astCheck( !type->hasMember( "mbr5" ) )
				astCheck( type->findMember( "mbr5" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "mbr5" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "mbr6", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), ast::type::NotArray, false ).second )
				astCheck( !type->hasMember( "mbr6" ) )
				astCheck( type->findMember( "mbr6" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "mbr6" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "mbr7", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), false ).second )
				astCheck( !type->hasMember( "mbr7" ) )
				astCheck( type->findMember( "mbr7" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "mbr7" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( ast::Builtin::eBaseInstance, mbrKind, 4u, ast::type::Struct::InvalidLocation, false ).second )
				astCheck( !type->hasMember( ast::Builtin::eBaseInstance ) )
				astCheck( type->findMember( ast::Builtin::eBaseInstance ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( ast::Builtin::eBaseInstance ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "arrmbr1", mbrKind, 4u, false ).second )
				astCheck( !type->hasMember( "arrmbr1" ) )
				astCheck( type->findMember( "arrmbr1" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "arrmbr1" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "arrmbr2", typesCache.getBasicType( mbrKind ), 4u, false ).second )
				astCheck( !type->hasMember( "arrmbr2" ) )
				astCheck( type->findMember( "arrmbr2" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "arrmbr2" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "arrmbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, false ).second )
				astCheck( !type->hasMember( "arrmbr3" ) )
				astCheck( type->findMember( "arrmbr3" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "arrmbr3" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "arrmbr5", typesCache.getStruct( layout, "mbr" ), 4u, false ).second )
				astCheck( !type->hasMember( "arrmbr5" ) )
				astCheck( type->findMember( "arrmbr5" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "arrmbr5" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( !type->declMember( "arrmbr6", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), 4u, false ).second )
				astCheck( !type->hasMember( "arrmbr6" ) )
				astCheck( type->findMember( "arrmbr6" ) == ast::type::Struct::NotFound )
				astCheckThrow( type->getMember( "arrmbr6" ) )
				astCheck( type->empty() )
			}
			{
				astCheck( type->declMember( ast::Builtin::eBaseVertex, mbrKind, ast::type::NotArray, ast::type::Struct::InvalidLocation, true ).second )
				astCheck( type->hasMember( ast::Builtin::eBaseVertex ) )
				astCheck( type->findMember( ast::Builtin::eBaseVertex ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( ast::Builtin::eBaseVertex ) )
				astCheck( type->size() == 1 )
			}
			{
				astCheck( type->declMember( "mbr1", mbrKind, ast::type::NotArray, true ).second )
				astCheck( type->hasMember( "mbr1" ) )
				astCheck( type->findMember( "mbr1" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "mbr1" ) )
				astCheck( type->size() == 2 )
			}
			{
				astCheck( type->declMember( "mbr2", typesCache.getBasicType( mbrKind ), ast::type::NotArray, true ).second )
				astCheck( type->hasMember( "mbr2" ) )
				astCheck( type->findMember( "mbr2" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "mbr2" ) )
				astCheck( type->size() == 3 )
			}
			{
				astCheck( type->declMember( "mbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), ast::type::NotArray, true ).second )
				astCheck( type->hasMember( "mbr3" ) )
				astCheck( type->findMember( "mbr3" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "mbr3" ) )
				astCheck( type->size() == 4 )
			}
			{
				astCheck( type->declMember( "mbr4", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), true ).second )
				astCheck( type->hasMember( "mbr4" ) )
				astCheck( type->findMember( "mbr4" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "mbr4" ) )
				astCheck( type->size() == 5 )
			}
			{
				auto structType = typesCache.getStruct( layout, "mbr" );
				structType->declMember( "mbmbr", mbrKind );
				astCheck( type->declMember( "mbr5", structType, ast::type::NotArray, true ).second )
				astCheck( type->hasMember( "mbr5" ) )
				astCheck( type->findMember( "mbr5" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "mbr5" ) )
				astCheck( type->size() == 6 )
			}
			{
				auto structType = typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput );
				structType->declMember( "mbmbr", mbrKind, ast::type::NotArray, 1u );
				astCheck( type->declMember( "mbr6", structType, ast::type::NotArray, true ).second )
				astCheck( type->hasMember( "mbr6" ) )
				astCheck( type->findMember( "mbr6" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "mbr6" ) )
				astCheck( type->size() == 7 )
			}
			{
				auto structType = typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput );
				astCheck( type->declMember( "mbr7", structType, true ).second )
				astCheck( type->hasMember( "mbr7" ) )
				astCheck( type->findMember( "mbr7" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "mbr7" ) )
				astCheck( type->size() == 8 )
			}
			{
				astCheck( type->declMember( ast::Builtin::eBaseInstance, mbrKind, 4u, ast::type::Struct::InvalidLocation, true ).second )
				astCheck( type->hasMember( ast::Builtin::eBaseInstance ) )
				astCheck( type->findMember( ast::Builtin::eBaseInstance ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( ast::Builtin::eBaseInstance ) )
				astCheck( type->size() == 9 )
			}
			{
				astCheck( type->declMember( "arrmbr1", mbrKind, 4u, true ).second )
				astCheck( type->hasMember( "arrmbr1" ) )
				astCheck( type->findMember( "arrmbr1" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "arrmbr1" ) )
				astCheck( type->size() == 10 )
			}
			{
				astCheck( type->declMember( "arrmbr2", typesCache.getBasicType( mbrKind ), 4u, true ).second )
				astCheck( type->hasMember( "arrmbr2" ) )
				astCheck( type->findMember( "arrmbr2" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "arrmbr2" ) )
				astCheck( type->size() == 11 )
			}
			{
				astCheck( type->declMember( "arrmbr3", typesCache.getArray( typesCache.getBasicType( mbrKind ), 4u ), 4u, true ).second )
				astCheck( type->hasMember( "arrmbr3" ) )
				astCheck( type->findMember( "arrmbr3" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "arrmbr3" ) )
				astCheck( type->size() == 12 )
			}
			{
				astCheck( type->declMember( "arrmbr5", typesCache.getStruct( layout, "mbr" ), 4u, true ).second )
				astCheck( type->hasMember( "arrmbr5" ) )
				astCheck( type->findMember( "arrmbr5" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "arrmbr5" ) )
				astCheck( type->size() == 13 )
			}
			{
				astCheck( type->declMember( "arrmbr6", typesCache.getIOStruct( "iombr", ast::EntryPoint::eCompute, ast::var::Flag::eShaderInput ), 4u, true ).second )
				astCheck( type->hasMember( "arrmbr6" ) )
				astCheck( type->findMember( "arrmbr6" ) != ast::type::Struct::NotFound )
				astCheckNoThrow( type->getMember( "arrmbr6" ) )
				astCheck( type->size() == 14 )
			}
			{
				auto mbrType = typesCache.getBasicType( mbrKind )->getMemberType( *type, 0u );
				astCheck( mbrType != typesCache.getBasicType( mbrKind ) )
				astCheck( mbrType->getNonMemberType() == typesCache.getBasicType( mbrKind ).get() )
			}
			{
				auto type2 = typesCache.getStruct( layout, "test" );
				astCheck( type == type2 )
			}
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		}
		{
			ast::type::TypesCache typesCache;
			astCheckThrow( typesCache.getIOStruct( "test", ast::EntryPoint::eNone, ast::var::Flag::eNone ) )
		}
		astTestEnd()
	}

	void testIOStruct( test::TestCounts & testCounts, ast::EntryPoint entryPoint, ast::var::Flag flag )
	{
		astTestBegin( "testIOStruct" + getName( entryPoint, flag ) );
		{
			ast::type::TypesCache typesCache;
			std::string name = "test" + getName( entryPoint, flag );
			auto type = typesCache.getIOStruct( "test", entryPoint, flag );
			astCheck( type->getRawKind() == ast::type::Kind::eStruct )
			astCheck( type->getKind() == ast::type::Kind::eStruct )
			astCheck( type->getName() == name )
			astCheck( type->getFlag() == uint64_t( flag ) )
			astCheck( type->getEntryPoint() == entryPoint )
			{
				auto type2 = typesCache.getIOStruct( "test", entryPoint, flag );
				astCheck( type == type2 )
			}
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		}
		astTestEnd()
	}
}

astTestSuiteMain( TestASTStructTypes )
{
	astTestSuiteBegin()
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
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTStructTypes )
