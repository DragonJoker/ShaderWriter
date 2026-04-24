#include "Common.hpp"

#include <ShaderAST/BoInfo.hpp>
#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma GCC diagnostic ignored "-Wdisabled-optimization"
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

	template< type::Kind MbrKindT >
	void testInterfaceBlockT( test::TestCounts & testCounts, type::MemoryLayout layout )
	{
		type::TypesCache typesCache;
		type::InterfaceBlock block{ typesCache, layout, "test" };
		uint32_t count{};
		std::string name{ "mbr0" };
		if constexpr ( MbrKindT != type::Kind::eBoolean
			&& MbrKindT != type::Kind::eVec2B
			&& MbrKindT != type::Kind::eVec3B
			&& MbrKindT != type::Kind::eVec4B )
		{
			if ( astOn( "Non array basic kind member declaration" ) )
			{
				astCheck( std::get< 1 >( block.registerMember< MbrKindT >( name, type::NotArray ) ) )
				astCheck( !std::get< 1 >( block.registerMember< MbrKindT >( name, type::NotArray ) ) )
				astCheck( block.hasMember( name ) )
				astCheck( block.findMember( name ) != type::Struct::NotFound )
				astCheckNoThrow( block.getMember( name ) )
				astCheck( block.getType()->size() == updateCount( count, name ) )
			}
		}
		if ( astOn( "Non array basic type member declaration" ) )
		{
			astCheck( std::get< 1 >( block.registerMember( name, typesCache.getBasicType( MbrKindT ), type::NotArray ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, typesCache.getBasicType( MbrKindT ), type::NotArray ) ) )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Non array basic array member declaration" ) )
		{
			astCheck( std::get< 1 >( block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), type::NotArray ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), type::NotArray ) ) )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Non array base struct member declaration" ) )
		{
			auto structType = typesCache.getStruct( layout, "mbr" );
			structType->declMember( "mbmbr", MbrKindT );
			astCheck( std::get< 1 >( block.registerMember( name, structType, type::NotArray ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, structType, type::NotArray ) ) )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Non array I/O struct member declaration" ) )
		{
			auto structType = typesCache.getIOStruct( "iombr", EntryPoint::eCompute, var::Flag::eShaderInput );
			structType->declMember( "mbmbr", MbrKindT, 1u );
			astCheck( std::get< 1 >( block.registerMember( name, structType, type::NotArray ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, structType, type::NotArray ) ) )
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
				astCheck( std::get< 1 >( block.registerMember< MbrKindT >( name, 4u ) ) )
				astCheck( !std::get< 1 >( block.registerMember< MbrKindT >( name, 4u ) ) )
				astCheck( block.hasMember( name ) )
				astCheck( block.findMember( name ) != type::Struct::NotFound )
				astCheckNoThrow( block.getMember( name ) )
				astCheck( block.getType()->size() == updateCount( count, name ) )
			}
		}
		if ( astOn( "Static array basic type member declaration" ) )
		{
			astCheck( std::get< 1 >( block.registerMember( name, typesCache.getBasicType( MbrKindT ), 4u ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, typesCache.getBasicType( MbrKindT ), 4u ) ) )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Static array basic array member declaration" ) )
		{
			astCheck( std::get< 1 >( block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ) ) )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
		if ( astOn( "Static array struct member declaration" ) )
		{
			astCheck( std::get< 1 >( block.registerMember( name, typesCache.getStruct( layout, "mbr" ), 4u ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, typesCache.getStruct( layout, "mbr" ), 4u ) ) )
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
				astCheck( std::get< 1 >( block.registerMember< MbrKindT >( name, type::UnknownArraySize ) ) )
				astCheck( !std::get< 1 >( block.registerMember< MbrKindT >( name, type::UnknownArraySize ) ) )
				astCheck( block.hasMember( name ) )
				astCheck( block.findMember( name ) != type::Struct::NotFound )
				astCheckNoThrow( block.getMember( name ) )
				astCheck( block.getType()->size() == updateCount( count, name ) )
			}
		}
		if ( astOn( "Dynamic array member array declaration" ) )
		{
			astCheck( std::get< 1 >( block.registerMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ), type::UnknownArraySize ) ) )
			astCheck( !std::get< 1 >( block.registerMember( name, typesCache.getArray( typesCache.getArray( typesCache.getBasicType( MbrKindT ), 4u ), 4u ), type::UnknownArraySize ) ) )
			astCheck( block.hasMember( name ) )
			astCheck( block.findMember( name ) != type::Struct::NotFound )
			astCheckNoThrow( block.getMember( name ) )
			astCheck( block.getType()->size() == updateCount( count, name ) )
		}
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

	struct TestInterfaceBlock
	{
		type::Kind member;
		type::MemoryLayout layout;

		TestInterfaceBlock & operator+( int i )
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
		friend bool operator<( TestInterfaceBlock const & lhs, TestInterfaceBlock const & rhs )
		{
			return ( uint8_t( lhs.member ) < uint8_t( rhs.member )
				|| ( lhs.member == rhs.member
					&& ( uint8_t( lhs.layout ) < uint8_t( rhs.layout ) ) ) );
		}
	};

	static constexpr TestInterfaceBlock minInterfaceBlock{ type::Kind::eBoolean
		, type::MemoryLayout::eStd140 };

	static constexpr TestInterfaceBlock maxInterfaceBlock{ type::Kind::eBasicTypesMax
		, type::MemoryLayout::eShaderRecord };

	std::string getInterfaceBlockName( TestInterfaceBlock const & v )
	{
		return getName( v.layout ) + debug::getTypeName( v.member );
	}

	using InterfaceBlocks = testing::TestWithParam< TestInterfaceBlock >;

	TEST_P( InterfaceBlocks, TestInterfaceBlock )
	{
		auto param = GetParam();
		astTestBegin( "testInterfaceBlock" + getInterfaceBlockName( param ) );
		testInterfaceBlock( testCounts, param.layout, param.member );
		astTestEnd()
	}
}

INSTANTIATE_TEST_SUITE_P( TestASTInterfaceBlocks, InterfaceBlocks
	, testing::Range( minInterfaceBlock, maxInterfaceBlock )
	, astTestNameP( TestInterfaceBlock, getInterfaceBlockName ) );

astTestSuiteMain()
