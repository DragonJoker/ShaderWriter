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
		testBegin( "testMemorySemantics" );
		{
			ast::type::MemorySemantics semantics{};
			check( uint32_t( semantics ) == 0u )
			semantics = semantics | ast::type::MemorySemanticsMask::eAcquire;
			check( semantics == ast::type::MemorySemanticsMask::eAcquire )
			semantics = semantics & ast::type::MemorySemanticsMask( ~uint32_t( ast::type::MemorySemanticsMask::eAcquire ) );
			check( uint32_t( semantics ) == 0u )
			semantics = ast::type::MemorySemanticsMask::eAcquire | semantics;
			check( semantics == ast::type::MemorySemanticsMask::eAcquire )
			semantics = ast::type::MemorySemanticsMask::eAcquire & semantics;
			check( ast::type::MemorySemanticsMask::eAcquire == semantics )
			check( ast::type::MemorySemanticsMask::eAcquire == ast::type::MemorySemanticsMask::eAcquire )
			auto rhs = semantics;
			check( semantics == rhs )
		}
		{
			ast::type::MemorySemantics semantics{ ast::type::MemorySemanticsMask::eAcquire };
			check( uint32_t( semantics ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
		}
		{
			ast::type::MemorySemantics semantics{ uint32_t( ast::type::MemorySemanticsMask::eAcquire ) };
			check( uint32_t( semantics ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
		}
		{
			auto semantics{ ast::type::MemorySemanticsMask::eAcquire | ast::type::MemorySemanticsMask::eAcquireRelease };
			check( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquire ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
			check( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) )
			semantics = ast::type::MemorySemanticsMask::eAcquire & ast::type::MemorySemanticsMask::eAcquireRelease;
			check( uint32_t( semantics ) == 0u )
		}
		{
			ast::type::MemorySemantics lhs{ ast::type::MemorySemanticsMask::eAcquire };
			ast::type::MemorySemantics rhs{ ast::type::MemorySemanticsMask::eAcquireRelease };
			auto semantics{ lhs | rhs };
			check( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquire ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquire ) )
			check( ( uint32_t( semantics ) & uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) ) == uint32_t( ast::type::MemorySemanticsMask::eAcquireRelease ) )
			semantics = lhs & rhs;
			check( uint32_t( semantics ) == 0u )
		}
		testEnd()
	}

	void testAccelerationStructure( test::TestCounts & testCounts )
	{
		testBegin( "testAccelerationStructure" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getAccelerationStructure();
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getKind() == ast::type::Kind::eAccelerationStructure )
		check( !isStructType( type ) )

		auto type2 = typesCache.getAccelerationStructure();
		check( type2 == type )
		testEnd()
	}

	void testArray( test::TestCounts & testCounts )
	{
		testBegin( "testArray" );
		{
			ast::type::TypesCache typesCache;
			checkThrow( typesCache.getArray( typesCache.getInt32(), ast::type::NotArray ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getArray( typesCache.getInt32(), ast::type::UnknownArraySize );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eArray )
			check( type->getKind() == ast::type::Kind::eArray )
			check( type->getType() == typesCache.getInt32() )
			check( type->getArraySize() == ast::type::UnknownArraySize )
			check( !isStructType( type ) )
			check( isArrayType( type->getKind() ) )
			check( getNonArrayKindRec( type ) == ast::type::Kind::eInt32 )
			check( getNonArrayTypeRec( type ) == typesCache.getInt32() )
			check( &getNonArrayTypeRec( *type ) == typesCache.getInt32().get() )

			auto type2 = typesCache.getArray( typesCache.getInt32(), ast::type::UnknownArraySize );
			check( type2 == type )
			check( *type2 == *type )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getArray( typesCache.getInt32(), 18 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eArray )
			check( type->getKind() == ast::type::Kind::eArray )
			check( type->getType() == typesCache.getInt32() )
			check( type->getArraySize() == 18 )
			check( !isStructType( type ) )
			check( isArrayType( type->getKind() ) )

			auto type2 = typesCache.getArray( typesCache.getInt32(), 18 );
			check( type2 == type )
			check( *type2 == *type )
		}
		testEnd()
	}

	void testCallableData( test::TestCounts & testCounts )
	{
		testBegin( "testCallableData" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getCallableData( typesCache.getInt32(), 17u );
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getRawKind() == ast::type::Kind::eCallableData )
		check( type->getKind() == ast::type::Kind::eInt32 )
		check( type->getDataType() == typesCache.getInt32() )
		check( type->getLocation() == 17u )
		check( !isStructType( type ) )
		check( isWrapperType( type ) )
		check( unwrapType( type ) == typesCache.getInt32() )
		check( &unwrapType( *type ) == typesCache.getInt32().get() )

		auto type2 = typesCache.getCallableData( typesCache.getInt32(), 17u );
		check( type2 == type )
		testEnd()
	}

	void testComputeIO( test::TestCounts & testCounts )
	{
		testBegin( "testComputeIO" );
		ast::type::TypesCache typesCache;
		auto type = ast::type::makeComputeInputType( typesCache.getInt32(), 17u, 18u, 19u );
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getRawKind() == ast::type::Kind::eComputeInput )
		check( type->getKind() == ast::type::Kind::eComputeInput )
		check( type->getType() == typesCache.getInt32() )
		check( type->getLocalSizeX() == 17u )
		check( type->getLocalSizeY() == 18u )
		check( type->getLocalSizeZ() == 19u )
		check( !isStructType( type ) )
		testEnd()
	}

	void testFragmentIO( test::TestCounts & testCounts )
	{
		testBegin( "testFragmentIO" );
		for ( uint32_t origin = 0u; origin < 2u; ++origin )
		{
			for ( uint32_t center = 0u; center < 2u; ++center )
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeFragmentInputType( typesCache.getInt32()
					, ast::FragmentOrigin( origin )
					, ast::FragmentCenter( center ) );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( type->getRawKind() == ast::type::Kind::eFragmentInput )
				check( type->getKind() == ast::type::Kind::eFragmentInput )
				check( type->getType() == typesCache.getInt32() )
				check( type->getOrigin() == ast::FragmentOrigin( origin ) )
				check( type->getCenter() == ast::FragmentCenter( center ) )
				check( !isStructType( type ) )
			}
		}
		testEnd()
	}

	void testFunction( test::TestCounts & testCounts )
	{
		testBegin( "testFunction" );
		{
			ast::type::TypesCache typesCache;
			auto type1 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{} );
			testCounts << "Type: " << ast::debug::getTypeName( type1 ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type1->getKind() ) << test::endl;
			check( type1->getRawKind() == ast::type::Kind::eFunction )
			check( type1->getKind() == ast::type::Kind::eFunction )
			check( type1->getReturnType() == typesCache.getVoid() )
			check( type1->size() == 0u )
			check( type1->empty() )
			check( type1->begin() == type1->end() )

			auto p0 = ast::var::makeVariable( 0u, typesCache.getInt32(), "p0" );
			auto type2 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0 } );
			testCounts << "Type: " << ast::debug::getTypeName( type2 ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type2->getKind() ) << test::endl;
			check( type2->getRawKind() == ast::type::Kind::eFunction )
			check( type2->getKind() == ast::type::Kind::eFunction )
			check( type2->getReturnType() == typesCache.getVoid() )
			check( type2->size() == 1u )
			check( !type2->empty() )
			check( type2->begin() != type2->end() )
			check( *type2->begin() == type2->front() )
			check( type2->back() == type2->front() )
			check( type2->front() == p0 )

			check( *type1 != *type2 )

			auto type3 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{} );
			check( type1 == type3 )
			auto type4 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0 } );
			check( type2 == type4 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{} );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eFunction )
			check( type->getKind() == ast::type::Kind::eFunction )
			check( type->getReturnType() == typesCache.getInt32() )
			check( type->size() == 0u )
			check( type->empty() )
			check( type->begin() == type->end() )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{} );
			check( type2 == type )
			check( *type == *type2 )
		}
		{
			ast::type::TypesCache typesCache;
			auto p0 = ast::var::makeVariable( 0u, typesCache.getInt32(), "p0" );
			auto type = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eFunction )
			check( type->getKind() == ast::type::Kind::eFunction )
			check( type->getReturnType() == typesCache.getInt32() )
			check( type->size() == 1u )
			check( !type->empty() )
			check( type->begin() != type->end() )
			check( *type->begin() == type->front() )
			check( type->back() == type->front() )
			check( type->front() == p0 )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			check( type2 == type )
			check( *type == *type2 )
		}
		{
			ast::type::TypesCache typesCache;
			auto structType = typesCache.getStruct( ast::type::MemoryLayout::eC, "Str" );
			structType->declMember( "mbr", ast::type::Kind::eInt32, ast::type::NotArray );
			auto p0 = ast::var::makeVariable( 0u, structType, "p0" );
			auto type = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eFunction )
			check( type->getKind() == ast::type::Kind::eFunction )
			check( type->getReturnType() == typesCache.getInt32() )
			check( type->size() == 1u )
			check( !type->empty() )
			check( type->begin() != type->end() )
			check( *type->begin() == type->front() )
			check( type->back() == type->front() )
			check( type->front() == p0 )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0 } );
			check( type2 == type )
			check( *type == *type2 )
		}
		{
			ast::type::TypesCache typesCache;
			auto p0 = ast::var::makeVariable( 0u, typesCache.getInt32(), "p0" );
			auto p1 = ast::var::makeVariable( 1u, typesCache.getFloat(), "p1" );
			auto type1 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0, p1 } );
			testCounts << "Type: " << ast::debug::getTypeName( type1 ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type1->getKind() ) << test::endl;
			check( type1->getRawKind() == ast::type::Kind::eFunction )
			check( type1->getKind() == ast::type::Kind::eFunction )
			check( type1->getReturnType() == typesCache.getVoid() )
			check( type1->size() == 2u )
			check( !type1->empty() )
			check( type1->begin() != type1->end() )
			check( *type1->begin() == type1->front() )
			check( type1->front() == p0 )
			check( type1->back() == p1 )

			auto type2 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0, p1 } );
			testCounts << "Type: " << ast::debug::getTypeName( type2 ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type2->getKind() ) << test::endl;
			check( type2->getRawKind() == ast::type::Kind::eFunction )
			check( type2->getKind() == ast::type::Kind::eFunction )
			check( type2->getReturnType() == typesCache.getInt32() )
			check( type2->size() == 2u )
			check( !type2->empty() )
			check( type2->begin() != type2->end() )
			check( *type2->begin() == type2->front() )
			check( type2->front() == p0 )
			check( type2->back() == p1 )

			check( *type1 != *type2 )

			auto type3 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0, p1 } );
			check( type1 == type3 )
			auto type4 = typesCache.getFunction( typesCache.getInt32(), ast::var::VariableList{ p0, p1 } );
			check( type2 == type4 )
		}
		testEnd()
	}

	void testGeometryIO( test::TestCounts & testCounts )
	{
		testBegin( "testGeometryIO" );
		for ( uint32_t layout = 0u; layout <= uint32_t( ast::type::InputLayout::eTriangleStripWithAdjacency ); ++layout )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeGeometryInputType( typesCache.getInt32()
					, ast::type::InputLayout( layout ) );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( type->getRawKind() == ast::type::Kind::eGeometryInput )
				check( type->getKind() == ast::type::Kind::eGeometryInput )
				check( type->getType() == typesCache.getInt32() )
				check( type->getLayout() == ast::type::InputLayout( layout ) )
				check( !isStructType( type ) )
			}
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeGeometryInputType( typesCache.getArray( typesCache.getInt32(), 4u )
					, ast::type::InputLayout( layout ) );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( type->getRawKind() == ast::type::Kind::eGeometryInput )
				check( type->getKind() == ast::type::Kind::eGeometryInput )
				check( type->getType() == typesCache.getArray( typesCache.getInt32(), 4u ) )
				check( type->getLayout() == ast::type::InputLayout( layout ) )
				check( !isStructType( type ) )
			}
		}
		for ( uint32_t layout = 0u; layout <= uint32_t( ast::type::OutputLayout::eTriangleStrip ); ++layout )
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeGeometryOutputType( typesCache.getInt32()
				, ast::type::OutputLayout( layout )
				, 15u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eGeometryOutput )
			check( type->getKind() == ast::type::Kind::eGeometryOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getLayout() == ast::type::OutputLayout( layout ) )
			check( type->getCount() == 15u )
			check( !isStructType( type ) )
		}
		testEnd()
	}

	void testHitAttribute( test::TestCounts & testCounts )
	{
		testBegin( "testHitAttribute" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getHitAttribute( typesCache.getInt32() );
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getRawKind() == ast::type::Kind::eHitAttribute )
		check( type->getKind() == ast::type::Kind::eInt32 )
		check( type->getDataType() == typesCache.getInt32() )
		check( !isStructType( type ) )
		check( isWrapperType( type ) )
		check( unwrapType( type ) == typesCache.getInt32() )
		check( &unwrapType( *type ) == typesCache.getInt32().get() )

		auto type2 = typesCache.getHitAttribute( typesCache.getInt32() );
		check( type2 == type )
		testEnd()
	}

	void testMeshIO( test::TestCounts & testCounts )
	{
		testBegin( "testMeshIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadInNVType( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadInNV( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadInType( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadIn( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeMeshVertexOutputType( typesCache.getInt32(), 17u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getMaxVertices() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMeshVertexOutput( typesCache.getInt32(), 17u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getMaxVertices() == 17u )
			check( !isStructType( type ) )
		}
		for ( uint32_t topology = 0u; topology <= uint32_t( ast::type::OutputTopology::eQuad ); ++topology )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeMeshPrimitiveOutputType( typesCache.getInt32(), ast::type::OutputTopology( topology ), 17u );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
				check( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
				check( type->getType() == typesCache.getInt32() )
				check( type->getTopology() == ast::type::OutputTopology( topology ) )
				check( type->getMaxPrimitives() == 17u )
				check( !isStructType( type ) )
			}
			{
				ast::type::TypesCache typesCache;
				auto type = typesCache.getMeshPrimitiveOutput( typesCache.getInt32(), ast::type::OutputTopology( topology ), 17u );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
				check( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
				check( type->getType() == typesCache.getInt32() )
				check( type->getTopology() == ast::type::OutputTopology( topology ) )
				check( type->getMaxPrimitives() == 17u )
				check( !isStructType( type ) )
			}
		}
		testEnd()
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
		testBegin( "testPointer" );
		for ( auto storage : storages )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = typesCache.getPointerType( typesCache.getInt32(), ast::type::Storage( storage ) );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( !isOpaqueType( type ) )
				auto & pointer = static_cast< ast::type::Pointer const & >( *type );
				check( pointer.getRawKind() == ast::type::Kind::ePointer )
				check( pointer.getKind() == ast::type::Kind::ePointer )
				check( pointer.getPointerType() == typesCache.getInt32() )
				check( pointer.getStorage() == ast::type::Storage( storage ) )
				check( !pointer.isForward() )
				check( !isStructType( pointer ) )
				check( getPointerLevel( type ) == 1u )

				auto & type2 = static_cast< ast::type::Pointer const & >( *typesCache.getPointerType( typesCache.getInt32(), ast::type::Storage( storage ) ) );
				check( &type2 == &pointer )
				check( type2 == pointer )
			}
			{
				ast::type::TypesCache typesCache;
				auto type = typesCache.getForwardPointerType( typesCache.getInt32(), ast::type::Storage( storage ) );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( !isOpaqueType( type ) )
				auto & pointer = static_cast< ast::type::Pointer const & >( *type );
				check( pointer.getRawKind() == ast::type::Kind::ePointer )
				check( pointer.getKind() == ast::type::Kind::ePointer )
				check( pointer.getPointerType() == typesCache.getInt32() )
				check( pointer.getStorage() == ast::type::Storage( storage ) )
				check( pointer.isForward() )
				check( !isStructType( pointer ) )
				check( getPointerLevel( type ) == 1u )

				auto & type2 = static_cast< ast::type::Pointer const & >( *typesCache.getForwardPointerType( typesCache.getInt32(), ast::type::Storage( storage ) ) );
				check( &type2 == &pointer )
				check( type2 == pointer )
			}
		}
		testEnd()
	}

	void testRayPayload( test::TestCounts & testCounts )
	{
		testBegin( "testRayPayload" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getRayPayload( typesCache.getInt32(), 17u );
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getRawKind() == ast::type::Kind::eRayPayload )
		check( type->getKind() == ast::type::Kind::eInt32 )
		check( type->getDataType() == typesCache.getInt32() )
		check( type->getLocation() == 17u )
		check( !isStructType( type ) )
		check( isWrapperType( type ) )
		check( unwrapType( type ) == typesCache.getInt32() )
		check( &unwrapType( *type ) == typesCache.getInt32().get() )

		auto type2 = typesCache.getRayPayload( typesCache.getInt32(), 17u );
		check( type2 == type )
		testEnd()
	}

	void testSampler( test::TestCounts & testCounts )
	{
		testBegin( "testSampler" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getSampler( true );
		testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
		testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
		check( type->getRawKind() == ast::type::Kind::eSampler )
		check( type->getKind() == ast::type::Kind::eSampler )
		check( type->isComparison() )

		auto type2 = typesCache.getSampler( true );
		check( type2 == type )
		testEnd()
	}

	void testTaskIO( test::TestCounts & testCounts )
	{
		testBegin( "testTaskIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadNVType( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadNV( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadType( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayload )
			check( type->getKind() == ast::type::Kind::eTaskPayload )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayload( typesCache.getInt32() );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTaskPayload )
			check( type->getKind() == ast::type::Kind::eTaskPayload )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		testEnd()
	}

	void testTessellationControlIO( test::TestCounts & testCounts )
	{
		testBegin( "testTessellationControlIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationOutputPatchType( typesCache.getInt32(), 17u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTessellationOutputPatch )
			check( type->getKind() == ast::type::Kind::eTessellationOutputPatch )
			check( type->getType() == typesCache.getInt32() )
			check( type->getLocation() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationControlInputType( typesCache.getInt32(), 17u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getRawKind() == ast::type::Kind::eTessellationControlInput )
			check( type->getKind() == ast::type::Kind::eTessellationControlInput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getInputVertices() == 17u )
			check( !isStructType( type ) )
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
							testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
							testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
							check( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
							check( type->getKind() == ast::type::Kind::eTessellationControlOutput )
							check( type->getType() == typesCache.getInt32() )
							check( type->getDomain() == ast::type::PatchDomain( domain ) )
							check( type->getPartitioning() == ast::type::Partitioning( partitioning ) )
							check( type->getTopology() == ast::type::OutputTopology( topology ) )
							check( type->getOrder() == ast::type::PrimitiveOrdering( ordering ) )
							check( type->getOutputVertices() == 17u )
							check( !isStructType( type ) )
						}
						{
							ast::type::TypesCache typesCache;
							auto type = ast::type::makeTessellationControlOutputType( typesCache.getArray( typesCache.getInt32(), 4u )
								, ast::type::PatchDomain( domain )
								, ast::type::Partitioning( partitioning )
								, ast::type::OutputTopology( topology )
								, ast::type::PrimitiveOrdering( ordering )
								, 17u );
							testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
							testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
							check( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
							check( type->getKind() == ast::type::Kind::eTessellationControlOutput )
							check( type->getType() == typesCache.getArray( typesCache.getInt32(), 4u ) )
							check( type->getDomain() == ast::type::PatchDomain( domain ) )
							check( type->getPartitioning() == ast::type::Partitioning( partitioning ) )
							check( type->getTopology() == ast::type::OutputTopology( topology ) )
							check( type->getOrder() == ast::type::PrimitiveOrdering( ordering ) )
							check( type->getOutputVertices() == 17u )
							check( !isStructType( type ) )
						}
					}
				}
			}
		}
		testEnd()
	}

	void testTessellationEvaluationIO( test::TestCounts & testCounts )
	{
		testBegin( "testTessellationEvaluationIO" );
		for ( uint32_t domain = 0u; domain <= uint32_t( ast::type::PatchDomain::eQuads ); ++domain )
		{
			{
				ast::type::TypesCache typesCache;
				auto type = ast::type::makeTessellationInputPatchType( typesCache.getInt32()
					, ast::type::PatchDomain( domain )
					, 17u );
				testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
				testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
				check( type->getRawKind() == ast::type::Kind::eTessellationInputPatch )
				check( type->getKind() == ast::type::Kind::eTessellationInputPatch )
				check( type->getType() == typesCache.getInt32() )
				check( type->getDomain() == ast::type::PatchDomain( domain ) )
				check( type->getLocation() == 17u )
				check( !isStructType( type ) )
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
					testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
					testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
					check( type->getRawKind() == ast::type::Kind::eTessellationEvaluationInput )
					check( type->getKind() == ast::type::Kind::eTessellationEvaluationInput )
					check( type->getType() == typesCache.getInt32() )
					check( type->getDomain() == ast::type::PatchDomain( domain ) )
					check( type->getPartitioning() == ast::type::Partitioning( partitioning ) )
					check( type->getPrimitiveOrdering() == ast::type::PrimitiveOrdering( ordering ) )
					check( type->getInputVertices() == 17u )
					check( !isStructType( type ) )
				}
			}
		}
		testEnd()
	}
}

testSuiteMain( TestASTOtherTypes )
{
	testSuiteBegin()
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
	testSuiteEnd()
}

testSuiteLaunch( TestASTOtherTypes )
