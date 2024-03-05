#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#include <set>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	void testMemorySemantics( test::TestCounts & testCounts )
	{
		astTestBegin( "testMemorySemantics" );
		{
			ast::type::MemorySemantics semantics{};
			astCheck( uint32_t( semantics ) == 0u )
			semantics = semantics | ast::type::MemorySemanticsMask::eAcquire;
			astCheck( semantics == ast::type::MemorySemanticsMask::eAcquire )
			semantics = semantics & ast::type::MemorySemanticsMask( ~uint32_t( ast::type::MemorySemanticsMask::eAcquire ) );
			astCheck( uint32_t( semantics ) == 0u )
			semantics = ast::type::MemorySemanticsMask::eAcquire | semantics;
			astCheck( semantics == ast::type::MemorySemanticsMask::eAcquire )
			semantics = ast::type::MemorySemanticsMask::eAcquire & semantics;
			astCheck( ast::type::MemorySemanticsMask::eAcquire == semantics )
			astCheck( ast::type::MemorySemanticsMask::eAcquire == ast::type::MemorySemanticsMask::eAcquire )
			auto rhs = semantics;
			astCheck( semantics == rhs )
		}
		{
			ast::type::MemorySemantics semantics{ ast::type::MemorySemanticsMask::eAcquire };
			astCheck( uint32_t( semantics ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
		}
		{
			ast::type::MemorySemantics semantics{ uint32_t( ast::type::MemorySemanticsMask::eAcquire ) };
			astCheck( uint32_t( semantics ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
		}
		{
			auto semantics{ ast::type::MemorySemanticsMask::eAcquire | ast::type::MemorySemanticsMask::eAcquireRelease };
			astCheck( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquire ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
			astCheck( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) )
			semantics = ast::type::MemorySemanticsMask::eAcquire & ast::type::MemorySemanticsMask::eAcquireRelease;
			astCheck( uint32_t( semantics ) == 0u )
		}
		{
			ast::type::MemorySemantics lhs{ ast::type::MemorySemanticsMask::eAcquire };
			ast::type::MemorySemantics rhs{ ast::type::MemorySemanticsMask::eAcquireRelease };
			auto semantics{ lhs | rhs };
			astCheck( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquire ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
			astCheck( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) )
			semantics = lhs & rhs;
			astCheck( uint32_t( semantics ) == 0u )
		}
		astTestEnd()
	}

	void testAccelerationStructure( test::TestCounts & testCounts )
	{
		astTestBegin( "testAccelerationStructure" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getAccelerationStructure();
		astCheckNoThrow( ast::debug::getTypeName( type ) )
		astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		astCheck( type->getKind() == ast::type::Kind::eAccelerationStructure )
		astCheck( !isStructType( type ) )

		auto type2 = typesCache.getAccelerationStructure();
		astCheck( type2 == type )
		astTestEnd()
	}

	void testArray( test::TestCounts & testCounts )
	{
		astTestBegin( "testArray" );
		{
			ast::type::TypesCache typesCache;
			astCheckThrow( typesCache.getArray( typesCache.getInt32(), ast::type::NotArray ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getArray( typesCache.getInt32(), ast::type::UnknownArraySize );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eArray )
			astCheck( type->getKind() == ast::type::Kind::eArray )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( type->getArraySize() == ast::type::UnknownArraySize )
			astCheck( !isStructType( type ) )
			astCheck( isArrayType( type->getKind() ) )
			astCheck( getNonArrayKindRec( type ) == ast::type::Kind::eInt32 )
			astCheck( getNonArrayTypeRec( type ) == typesCache.getInt32() )
			astCheck( &getNonArrayTypeRec( *type ) == typesCache.getInt32().get() )

			auto type2 = typesCache.getArray( typesCache.getInt32(), ast::type::UnknownArraySize );
			astCheck( type2 == type )
			astCheck( *type2 == *type )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getArray( typesCache.getInt32(), 18 );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eArray )
			astCheck( type->getKind() == ast::type::Kind::eArray )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( type->getArraySize() == 18 )
			astCheck( !isStructType( type ) )
			astCheck( isArrayType( type->getKind() ) )

			auto type2 = typesCache.getArray( typesCache.getInt32(), 18 );
			astCheck( type2 == type )
			astCheck( *type2 == *type )
		}
		astTestEnd()
	}

	void testCallableData( test::TestCounts & testCounts )
	{
		astTestBegin( "testCallableData" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getCallableData( typesCache.getInt32(), 17u );
		astCheckNoThrow( ast::debug::getTypeName( type ) )
		astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		astCheck( type->getRawKind() == ast::type::Kind::eCallableData )
		astCheck( type->getKind() == ast::type::Kind::eInt32 )
		astCheck( type->getDataType() == typesCache.getInt32() )
		astCheck( type->getLocation() == 17u )
		astCheck( !isStructType( type ) )
		astCheck( isWrapperType( type ) )
		astCheck( unwrapType( type ) == typesCache.getInt32() )
		astCheck( &unwrapType( *type ) == typesCache.getInt32().get() )

		auto type2 = typesCache.getCallableData( typesCache.getInt32(), 17u );
		astCheck( type2 == type )
		astTestEnd()
	}

	void testComputeIO( test::TestCounts & testCounts )
	{
		astTestBegin( "testComputeIO" );
		ast::type::TypesCache typesCache;
		auto type = ast::type::makeComputeInputType( typesCache.getInt32(), 17u, 18u, 19u );
		astCheckNoThrow( ast::debug::getTypeName( type ) )
		astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		astCheck( type->getRawKind() == ast::type::Kind::eComputeInput )
		astCheck( type->getKind() == ast::type::Kind::eComputeInput )
		astCheck( type->getType() == typesCache.getInt32() )
		astCheck( type->getLocalSizeX() == 17u )
		astCheck( type->getLocalSizeY() == 18u )
		astCheck( type->getLocalSizeZ() == 19u )
		astCheck( !isStructType( type ) )
		astTestEnd()
	}

	void testFragmentIO( test::TestCounts & testCounts )
	{
		astTestBegin( "testFragmentIO" );
		for ( uint32_t origin = 0u; origin < 2u; ++origin )
		{
			for ( uint32_t center = 0u; center < 2u; ++center )
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeFragmentInputType( typesCache.getInt32()
					, ast::FragmentOrigin( origin )
					, ast::FragmentCenter( center ) );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( type->getRawKind() == ast::type::Kind::eFragmentInput )
				astCheck( type->getKind() == ast::type::Kind::eFragmentInput )
				astCheck( type->getType() == typesCache.getInt32() )
				astCheck( type->getOrigin() == ast::FragmentOrigin( origin ) )
				astCheck( type->getCenter() == ast::FragmentCenter( center ) )
				astCheck( !isStructType( type ) )
			}
		}
		astTestEnd()
	}

	void testFunction( test::TestCounts & testCounts )
	{
		astTestBegin( "testFunction" );
		{
			ast::type::TypesCache typesCache;
			auto type1 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{} );
			astCheckNoThrow( ast::debug::getTypeName( type1 ) )
			astCheckNoThrow( ast::debug::getTypeName( type1->getKind() ) )
			astCheck( type1->getRawKind() == ast::type::Kind::eFunction )
			astCheck( type1->getKind() == ast::type::Kind::eFunction )
			astCheck( type1->getReturnType() == typesCache.getVoid() )
			astCheck( type1->size() == 0u )
			astCheck( type1->empty() )
			astCheck( type1->begin() == type1->end() )

			auto p0 = ast::var::makeVariable( 0u, typesCache.getInt32(), "p0" );
			auto type2 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0 } );
			astCheckNoThrow( ast::debug::getTypeName( type2 ) )
			astCheckNoThrow( ast::debug::getTypeName( type2->getKind() ) )
			astCheck( type2->getRawKind() == ast::type::Kind::eFunction )
			astCheck( type2->getKind() == ast::type::Kind::eFunction )
			astCheck( type2->getReturnType() == typesCache.getVoid() )
			astCheck( type2->size() == 1u )
			astCheck( !type2->empty() )
			astCheck( type2->begin() != type2->end() )
			astCheck( *type2->begin() == type2->front() )
			astCheck( type2->back() == type2->front() )
			astCheck( type2->front() == p0 )

			astCheck( *type1 != *type2 )

			auto type3 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{} );
			astCheck( type1 == type3 )
			auto type4 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0 } );
			astCheck( type2 == type4 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{} );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eFunction )
			astCheck( type->getKind() == ast::type::Kind::eFunction )
			astCheck( type->getReturnType() == typesCache.getInt32() )
			astCheck( type->size() == 0u )
			astCheck( type->empty() )
			astCheck( type->begin() == type->end() )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{} );
			astCheck( type2 == type )
			astCheck( *type == *type2 )
		}
		{
			ast::type::TypesCache typesCache;
			auto p0 = ast::var::makeVariable( 0u, typesCache.getInt32(), "p0" );
			auto type = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eFunction )
			astCheck( type->getKind() == ast::type::Kind::eFunction )
			astCheck( type->getReturnType() == typesCache.getInt32() )
			astCheck( type->size() == 1u )
			astCheck( !type->empty() )
			astCheck( type->begin() != type->end() )
			astCheck( *type->begin() == type->front() )
			astCheck( type->back() == type->front() )
			astCheck( type->front() == p0 )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			astCheck( type2 == type )
			astCheck( *type == *type2 )
		}
		{
			ast::type::TypesCache typesCache;
			auto structType = typesCache.getStruct( ast::type::MemoryLayout::eC, "Str" );
			structType->declMember( "mbr", ast::type::Kind::eInt32, ast::type::NotArray );
			auto p0 = ast::var::makeVariable( 0u, structType, "p0" );
			auto type = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eFunction )
			astCheck( type->getKind() == ast::type::Kind::eFunction )
			astCheck( type->getReturnType() == typesCache.getInt32() )
			astCheck( type->size() == 1u )
			astCheck( !type->empty() )
			astCheck( type->begin() != type->end() )
			astCheck( *type->begin() == type->front() )
			astCheck( type->back() == type->front() )
			astCheck( type->front() == p0 )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			astCheck( type2 == type )
			astCheck( *type == *type2 )
		}
		{
			ast::type::TypesCache typesCache;
			auto p0 = ast::var::makeVariable( 0u, typesCache.getInt32(), "p0" );
			auto p1 = ast::var::makeVariable( 1u, typesCache.getFloat(), "p1" );
			auto type1 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0, p1 } );
			astCheckNoThrow( ast::debug::getTypeName( type1 ) )
			astCheckNoThrow( ast::debug::getTypeName( type1->getKind() ) )
			astCheck( type1->getRawKind() == ast::type::Kind::eFunction )
			astCheck( type1->getKind() == ast::type::Kind::eFunction )
			astCheck( type1->getReturnType() == typesCache.getVoid() )
			astCheck( type1->size() == 2u )
			astCheck( !type1->empty() )
			astCheck( type1->begin() != type1->end() )
			astCheck( *type1->begin() == type1->front() )
			astCheck( type1->front() == p0 )
			astCheck( type1->back() == p1 )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0, p1 } );
			astCheckNoThrow( ast::debug::getTypeName( type2 ) )
			astCheckNoThrow( ast::debug::getTypeName( type2->getKind() ) )
			astCheck( type2->getRawKind() == ast::type::Kind::eFunction )
			astCheck( type2->getKind() == ast::type::Kind::eFunction )
			astCheck( type2->getReturnType() == typesCache.getInt32() )
			astCheck( type2->size() == 2u )
			astCheck( !type2->empty() )
			astCheck( type2->begin() != type2->end() )
			astCheck( *type2->begin() == type2->front() )
			astCheck( type2->front() == p0 )
			astCheck( type2->back() == p1 )

			astCheck( *type1 != *type2 )

			auto type3 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0, p1 } );
			astCheck( type1 == type3 )
			auto type4 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0, p1 } );
			astCheck( type2 == type4 )
		}
		astTestEnd()
	}

	void testGeometryIO( test::TestCounts & testCounts )
	{
		astTestBegin( "testGeometryIO" );
		for ( uint32_t layout = 0u; layout <= uint32_t( ast::type::InputLayout::eTriangleStripWithAdjacency ); ++layout )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeGeometryInputType( typesCache.getInt32()
					, ast::type::InputLayout( layout ) );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( type->getRawKind() == ast::type::Kind::eGeometryInput )
				astCheck( type->getKind() == ast::type::Kind::eGeometryInput )
				astCheck( type->getType() == typesCache.getInt32() )
				astCheck( type->getLayout() == ast::type::InputLayout( layout ) )
				astCheck( !isStructType( type ) )
			}
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeGeometryInputType( typesCache.getArray( typesCache.getInt32(), 4u )
					, ast::type::InputLayout( layout ) );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( type->getRawKind() == ast::type::Kind::eGeometryInput )
				astCheck( type->getKind() == ast::type::Kind::eGeometryInput )
				astCheck( type->getType() == typesCache.getArray( typesCache.getInt32(), 4u ) )
				astCheck( type->getLayout() == ast::type::InputLayout( layout ) )
				astCheck( !isStructType( type ) )
			}
		}
		for ( uint32_t layout = 0u; layout <= uint32_t( ast::type::OutputLayout::eTriangleStrip ); ++layout )
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeGeometryOutputType( typesCache.getInt32()
				, ast::type::OutputLayout( layout )
				, 15u );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eGeometryOutput )
			astCheck( type->getKind() == ast::type::Kind::eGeometryOutput )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( type->getLayout() == ast::type::OutputLayout( layout ) )
			astCheck( type->getCount() == 15u )
			astCheck( !isStructType( type ) )
		}
		astTestEnd()
	}

	void testHitAttribute( test::TestCounts & testCounts )
	{
		astTestBegin( "testHitAttribute" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getHitAttribute( typesCache.getInt32() );
		astCheckNoThrow( ast::debug::getTypeName( type ) )
		astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		astCheck( type->getRawKind() == ast::type::Kind::eHitAttribute )
		astCheck( type->getKind() == ast::type::Kind::eInt32 )
		astCheck( type->getDataType() == typesCache.getInt32() )
		astCheck( !isStructType( type ) )
		astCheck( isWrapperType( type ) )
		astCheck( unwrapType( type ) == typesCache.getInt32() )
		astCheck( &unwrapType( *type ) == typesCache.getInt32().get() )

		auto type2 = typesCache.getHitAttribute( typesCache.getInt32() );
		astCheck( type2 == type )
		astTestEnd()
	}

	void testMeshIO( test::TestCounts & testCounts )
	{
		astTestBegin( "testMeshIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadInNVType( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayloadInNV )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadInNV( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayloadInNV )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadInType( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayloadIn )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadIn( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayloadIn )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeMeshVertexOutputType( typesCache.getInt32(), 17u );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
			astCheck( type->getKind() == ast::type::Kind::eMeshVertexOutput )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( type->getMaxVertices() == 17u )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMeshVertexOutput( typesCache.getInt32(), 17u );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
			astCheck( type->getKind() == ast::type::Kind::eMeshVertexOutput )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( type->getMaxVertices() == 17u )
			astCheck( !isStructType( type ) )
		}
		for ( uint32_t topology = 0u; topology <= uint32_t( ast::type::OutputTopology::eQuad ); ++topology )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeMeshPrimitiveOutputType( typesCache.getInt32(), ast::type::OutputTopology( topology ), 17u );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
				astCheck( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
				astCheck( type->getType() == typesCache.getInt32() )
				astCheck( type->getTopology() == ast::type::OutputTopology( topology ) )
				astCheck( type->getMaxPrimitives() == 17u )
				astCheck( !isStructType( type ) )
			}
			{
				ast::type::TypesCache typesCache;
				auto type = typesCache.getMeshPrimitiveOutput( typesCache.getInt32(), ast::type::OutputTopology( topology ), 17u );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
				astCheck( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
				astCheck( type->getType() == typesCache.getInt32() )
				astCheck( type->getTopology() == ast::type::OutputTopology( topology ) )
				astCheck( type->getMaxPrimitives() == 17u )
				astCheck( !isStructType( type ) )
			}
		}
		astTestEnd()
	}

	void testPointer( test::TestCounts & testCounts )
	{
		std::set< uint32_t > storages
		{
			uint32_t( ast::type::Storage::eUniformConstant ),
			uint32_t( ast::type::Storage::eInput ),
			uint32_t( ast::type::Storage::eUniform ),
			uint32_t( ast::type::Storage::eOutput ),
			uint32_t( ast::type::Storage::eWorkgroup ),
			uint32_t( ast::type::Storage::eCrossWorkgroup ),
			uint32_t( ast::type::Storage::ePrivate ),
			uint32_t( ast::type::Storage::eFunction ),
			uint32_t( ast::type::Storage::eGeneric ),
			uint32_t( ast::type::Storage::ePushConstant ),
			uint32_t( ast::type::Storage::eAtomicCounter ),
			uint32_t( ast::type::Storage::eImage ),
			uint32_t( ast::type::Storage::eStorageBuffer ),
			uint32_t( ast::type::Storage::eCallableData ),
			uint32_t( ast::type::Storage::eIncomingCallableData ),
			uint32_t( ast::type::Storage::eRayPayload ),
			uint32_t( ast::type::Storage::eHitAttribute ),
			uint32_t( ast::type::Storage::eIncomingRayPayload ),
			uint32_t( ast::type::Storage::eShaderRecordBuffer ),
			uint32_t( ast::type::Storage::ePhysicalStorageBuffer ),
			uint32_t( ast::type::Storage::eTaskPayloadWorkgroup ),
			uint32_t( ast::type::Storage::eCodeSection ),
		};
		astTestBegin( "testPointer" );
		for ( auto storage : storages )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = typesCache.getPointerType( typesCache.getInt32(), ast::type::Storage( storage ) );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( !isOpaqueType( type ) )
				auto & pointer = static_cast< ast::type::Pointer const & >( *type );
				astCheck( pointer.getRawKind() == ast::type::Kind::ePointer )
				astCheck( pointer.getKind() == ast::type::Kind::ePointer )
				astCheck( pointer.getPointerType() == typesCache.getInt32() )
				astCheck( pointer.getStorage() == ast::type::Storage( storage ) )
				astCheck( !pointer.isForward() )
				astCheck( !isStructType( pointer ) )
				astCheck( getPointerLevel( type ) == 1u )

				auto & type2 = static_cast< ast::type::Pointer const & >( *typesCache.getPointerType( typesCache.getInt32(), ast::type::Storage( storage ) ) );
				astCheck( &type2 == &pointer )
				astCheck( type2 == pointer )
			}
			{
				ast::type::TypesCache typesCache;
				auto type = typesCache.getForwardPointerType( typesCache.getInt32(), ast::type::Storage( storage ) );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( !isOpaqueType( type ) )
				auto & pointer = static_cast< ast::type::Pointer const & >( *type );
				astCheck( pointer.getRawKind() == ast::type::Kind::ePointer )
				astCheck( pointer.getKind() == ast::type::Kind::ePointer )
				astCheck( pointer.getPointerType() == typesCache.getInt32() )
				astCheck( pointer.getStorage() == ast::type::Storage( storage ) )
				astCheck( pointer.isForward() )
				astCheck( !isStructType( pointer ) )
				astCheck( getPointerLevel( type ) == 1u )

				auto & type2 = static_cast< ast::type::Pointer const & >( *typesCache.getForwardPointerType( typesCache.getInt32(), ast::type::Storage( storage ) ) );
				astCheck( &type2 == &pointer )
				astCheck( type2 == pointer )
			}
		}
		astTestEnd()
	}

	void testRayPayload( test::TestCounts & testCounts )
	{
		astTestBegin( "testRayPayload" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getRayPayload( typesCache.getInt32(), 17u );
		astCheckNoThrow( ast::debug::getTypeName( type ) )
		astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		astCheck( type->getRawKind() == ast::type::Kind::eRayPayload )
		astCheck( type->getKind() == ast::type::Kind::eInt32 )
		astCheck( type->getDataType() == typesCache.getInt32() )
		astCheck( type->getLocation() == 17u )
		astCheck( !isStructType( type ) )
		astCheck( isWrapperType( type ) )
		astCheck( unwrapType( type ) == typesCache.getInt32() )
		astCheck( &unwrapType( *type ) == typesCache.getInt32().get() )

		auto type2 = typesCache.getRayPayload( typesCache.getInt32(), 17u );
		astCheck( type2 == type )
		astTestEnd()
	}

	void testSampler( test::TestCounts & testCounts )
	{
		astTestBegin( "testSampler" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getSampler( true );
		astCheckNoThrow( ast::debug::getTypeName( type ) )
		astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
		astCheck( type->getRawKind() == ast::type::Kind::eSampler )
		astCheck( type->getKind() == ast::type::Kind::eSampler )
		astCheck( type->isComparison() )

		auto type2 = typesCache.getSampler( true );
		astCheck( type2 == type )
		astTestEnd()
	}

	void testTaskIO( test::TestCounts & testCounts )
	{
		astTestBegin( "testTaskIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadNVType( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayloadNV )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadNV( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayloadNV )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadType( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayload )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayload )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayload( typesCache.getInt32() );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTaskPayload )
			astCheck( type->getKind() == ast::type::Kind::eTaskPayload )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( !isStructType( type ) )
		}
		astTestEnd()
	}

	void testTessellationControlIO( test::TestCounts & testCounts )
	{
		astTestBegin( "testTessellationControlIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationOutputPatchType( typesCache.getInt32(), 17u );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTessellationOutputPatch )
			astCheck( type->getKind() == ast::type::Kind::eTessellationOutputPatch )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( type->getLocation() == 17u )
			astCheck( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationControlInputType( typesCache.getInt32(), 17u );
			astCheckNoThrow( ast::debug::getTypeName( type ) )
			astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
			astCheck( type->getRawKind() == ast::type::Kind::eTessellationControlInput )
			astCheck( type->getKind() == ast::type::Kind::eTessellationControlInput )
			astCheck( type->getType() == typesCache.getInt32() )
			astCheck( type->getInputVertices() == 17u )
			astCheck( !isStructType( type ) )
		}
		for ( uint32_t domain = 0u; domain <= uint32_t( ast::type::PatchDomain::eQuads ); ++domain )
		{
			for ( uint32_t partitioning = 0u; partitioning <= uint32_t( ast::type::Partitioning::eFractionalOdd ); ++partitioning )
			{
				for ( uint32_t topology = 0u; topology <= uint32_t( ast::type::OutputTopology::eQuad ); ++topology )
				{
					for ( uint32_t ordering = 0u; ordering <= uint32_t( ast::type::PrimitiveOrdering::eCCW ); ++ordering )
					{
						{
							ast::type::TypesCache typesCache;
							auto type = ast::type::makeTessellationControlOutputType( typesCache.getInt32()
								, ast::type::PatchDomain( domain )
								, ast::type::Partitioning( partitioning )
								, ast::type::OutputTopology( topology )
								, ast::type::PrimitiveOrdering( ordering )
								, 17u );
							astCheckNoThrow( ast::debug::getTypeName( type ) )
							astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
							astCheck( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
							astCheck( type->getKind() == ast::type::Kind::eTessellationControlOutput )
							astCheck( type->getType() == typesCache.getInt32() )
							astCheck( type->getDomain() == ast::type::PatchDomain( domain ) )
							astCheck( type->getPartitioning() == ast::type::Partitioning( partitioning ) )
							astCheck( type->getTopology() == ast::type::OutputTopology( topology ) )
							astCheck( type->getOrder() == ast::type::PrimitiveOrdering( ordering ) )
							astCheck( type->getOutputVertices() == 17u )
							astCheck( !isStructType( type ) )
						}
						{
							ast::type::TypesCache typesCache;
							auto type = ast::type::makeTessellationControlOutputType( typesCache.getArray( typesCache.getInt32(), 4u )
								, ast::type::PatchDomain( domain )
								, ast::type::Partitioning( partitioning )
								, ast::type::OutputTopology( topology )
								, ast::type::PrimitiveOrdering( ordering )
								, 17u );
							astCheckNoThrow( ast::debug::getTypeName( type ) )
							astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
							astCheck( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
							astCheck( type->getKind() == ast::type::Kind::eTessellationControlOutput )
							astCheck( type->getType() == typesCache.getArray( typesCache.getInt32(), 4u ) )
							astCheck( type->getDomain() == ast::type::PatchDomain( domain ) )
							astCheck( type->getPartitioning() == ast::type::Partitioning( partitioning ) )
							astCheck( type->getTopology() == ast::type::OutputTopology( topology ) )
							astCheck( type->getOrder() == ast::type::PrimitiveOrdering( ordering ) )
							astCheck( type->getOutputVertices() == 17u )
							astCheck( !isStructType( type ) )
						}
					}
				}
			}
		}
		astTestEnd()
	}

	void testTessellationEvaluationIO( test::TestCounts & testCounts )
	{
		astTestBegin( "testTessellationEvaluationIO" );
		for ( uint32_t domain = 0u; domain <= uint32_t( ast::type::PatchDomain::eQuads ); ++domain )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeTessellationInputPatchType( typesCache.getInt32()
					, ast::type::PatchDomain( domain )
					, 17u );
				astCheckNoThrow( ast::debug::getTypeName( type ) )
				astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
				astCheck( type->getRawKind() == ast::type::Kind::eTessellationInputPatch )
				astCheck( type->getKind() == ast::type::Kind::eTessellationInputPatch )
				astCheck( type->getType() == typesCache.getInt32() )
				astCheck( type->getDomain() == ast::type::PatchDomain( domain ) )
				astCheck( type->getLocation() == 17u )
				astCheck( !isStructType( type ) )
			}
			for ( uint32_t partitioning = 0u; partitioning <= uint32_t( ast::type::Partitioning::eFractionalOdd ); ++partitioning )
			{
				for ( uint32_t ordering = 0u; ordering <= uint32_t( ast::type::PrimitiveOrdering::eCCW ); ++ordering )
				{
					ast::type::TypesCache typesCache;
					auto type = ast::type::makeTessellationEvaluationInputType( typesCache.getInt32()
						, ast::type::PatchDomain( domain )
						, ast::type::Partitioning( partitioning )
						, ast::type::PrimitiveOrdering( ordering )
						, 17u );
					astCheckNoThrow( ast::debug::getTypeName( type ) )
					astCheckNoThrow( ast::debug::getTypeName( type->getKind() ) )
					astCheck( type->getRawKind() == ast::type::Kind::eTessellationEvaluationInput )
					astCheck( type->getKind() == ast::type::Kind::eTessellationEvaluationInput )
					astCheck( type->getType() == typesCache.getInt32() )
					astCheck( type->getDomain() == ast::type::PatchDomain( domain ) )
					astCheck( type->getPartitioning() == ast::type::Partitioning( partitioning ) )
					astCheck( type->getPrimitiveOrdering() == ast::type::PrimitiveOrdering( ordering ) )
					astCheck( type->getInputVertices() == 17u )
					astCheck( !isStructType( type ) )
				}
			}
		}
		astTestEnd()
	}
}

astTestSuiteMain( TestASTOtherTypes )
{
	astTestSuiteBegin()
	testMemorySemantics( testCounts );
	testAccelerationStructure( testCounts );
	testArray( testCounts );
	testCallableData( testCounts );
	testComputeIO( testCounts );
	testFragmentIO( testCounts );
	testFunction( testCounts );
	testGeometryIO( testCounts );
	testHitAttribute( testCounts );
	testMeshIO( testCounts );
	testPointer( testCounts );
	testRayPayload( testCounts );
	testSampler( testCounts );
	testTaskIO( testCounts );
	testTessellationControlIO( testCounts );
	testTessellationEvaluationIO( testCounts );
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTOtherTypes )
