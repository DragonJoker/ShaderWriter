#pragma once

#include <ShaderAST/Expr/ExprCache.hpp>
#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/ImageConfiguration.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 4068 )
#pragma warning( disable: 5262 )
#pragma warning( disable: 5264 )
#pragma clang diagnostic ignored "-Wextra-semi-stmt"
#pragma GCC diagnostic ignored "-Wrestrict"
#include <atomic>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#pragma warning( pop )

template< typename ValueT >
inline std::string toString( ValueT const & v )
{
	return std::to_string( v );
}

inline std::string toString( ast::expr::LiteralType const & v )
{
	switch ( v )
	{
	case ast::expr::LiteralType::eBool:
		return "Bool";
	case ast::expr::LiteralType::eInt8:
		return "Int8";
	case ast::expr::LiteralType::eInt16:
		return "Int16";
	case ast::expr::LiteralType::eInt32:
		return "Int32";
	case ast::expr::LiteralType::eInt64:
		return "Int64";
	case ast::expr::LiteralType::eUInt8:
		return "UInt8";
	case ast::expr::LiteralType::eUInt16:
		return "UInt16";
	case ast::expr::LiteralType::eUInt32:
		return "UInt32";
	case ast::expr::LiteralType::eUInt64:
		return "UInt64";
	case ast::expr::LiteralType::eFloat:
		return "Float";
	case ast::expr::LiteralType::eDouble:
		return "Double";
	default:
		return "Unknown";
	}
}

inline std::string toString( ast::type::Kind const & v )
{
	switch ( v )
	{
	case ast::type::Kind::eUndefined:
		return "Undefined";
	case ast::type::Kind::eVoid:
		return "Void";
	case ast::type::Kind::eBoolean:
		return "Boolean";
	case ast::type::Kind::eInt8:
		return "Int8";
	case ast::type::Kind::eInt16:
		return "Int16";
	case ast::type::Kind::eInt32:
		return "Int32";
	case ast::type::Kind::eInt64:
		return "Int64";
	case ast::type::Kind::eUInt8:
		return "UInt8";
	case ast::type::Kind::eUInt16:
		return "UInt16";
	case ast::type::Kind::eUInt32:
		return "UInt32";
	case ast::type::Kind::eUInt64:
		return "UInt64";
	case ast::type::Kind::eHalf:
		return "Half";
	case ast::type::Kind::eFloat:
		return "Float";
	case ast::type::Kind::eDouble:
		return "Double";
	case ast::type::Kind::eVec2B:
		return "Vec2B";
	case ast::type::Kind::eVec3B:
		return "Vec3B";
	case ast::type::Kind::eVec4B:
		return "Vec4B";
	case ast::type::Kind::eVec2I8:
		return "Vec2I8";
	case ast::type::Kind::eVec3I8:
		return "Vec3I8";
	case ast::type::Kind::eVec4I8:
		return "Vec4I8";
	case ast::type::Kind::eVec2I16:
		return "Vec2I16";
	case ast::type::Kind::eVec3I16:
		return "Vec3I16";
	case ast::type::Kind::eVec4I16:
		return "Vec4I16";
	case ast::type::Kind::eVec2I32:
		return "Vec2I32";
	case ast::type::Kind::eVec3I32:
		return "Vec3I32";
	case ast::type::Kind::eVec4I32:
		return "Vec4I32";
	case ast::type::Kind::eVec2I64:
		return "Vec2I64";
	case ast::type::Kind::eVec3I64:
		return "Vec3I64";
	case ast::type::Kind::eVec4I64:
		return "Vec4I64";
	case ast::type::Kind::eVec2U8:
		return "Vec2U8";
	case ast::type::Kind::eVec3U8:
		return "Vec3U8";
	case ast::type::Kind::eVec4U8:
		return "Vec4U8";
	case ast::type::Kind::eVec2U16:
		return "Vec2U16";
	case ast::type::Kind::eVec3U16:
		return "Vec3U16";
	case ast::type::Kind::eVec4U16:
		return "Vec4U16";
	case ast::type::Kind::eVec2U32:
		return "Vec2U32";
	case ast::type::Kind::eVec3U32:
		return "Vec3U32";
	case ast::type::Kind::eVec4U32:
		return "Vec4U32";
	case ast::type::Kind::eVec2U64:
		return "Vec2U64";
	case ast::type::Kind::eVec3U64:
		return "Vec3U64";
	case ast::type::Kind::eVec4U64:
		return "Vec4U64";
	case ast::type::Kind::eVec2H:
		return "Vec2H";
	case ast::type::Kind::eVec4H:
		return "Vec4H";
	case ast::type::Kind::eVec2F:
		return "Vec2F";
	case ast::type::Kind::eVec3F:
		return "Vec3F";
	case ast::type::Kind::eVec4F:
		return "Vec4F";
	case ast::type::Kind::eVec2D:
		return "Vec2D";
	case ast::type::Kind::eVec3D:
		return "Vec3D";
	case ast::type::Kind::eVec4D:
		return "Vec4D";
	case ast::type::Kind::eMat2x2F:
		return "Mat2x2F";
	case ast::type::Kind::eMat2x3F:
		return "Mat2x3F";
	case ast::type::Kind::eMat2x4F:
		return "Mat2x4F";
	case ast::type::Kind::eMat3x2F:
		return "Mat3x2F";
	case ast::type::Kind::eMat3x3F:
		return "Mat3x3F";
	case ast::type::Kind::eMat3x4F:
		return "Mat3x4F";
	case ast::type::Kind::eMat4x2F:
		return "Mat4x2F";
	case ast::type::Kind::eMat4x3F:
		return "Mat4x3F";
	case ast::type::Kind::eMat4x4F:
		return "Mat4x4F";
	case ast::type::Kind::eMat2x2D:
		return "Mat2x2D";
	case ast::type::Kind::eMat2x3D:
		return "Mat2x3D";
	case ast::type::Kind::eMat2x4D:
		return "Mat2x4D";
	case ast::type::Kind::eMat3x2D:
		return "Mat3x2D";
	case ast::type::Kind::eMat3x3D:
		return "Mat3x3D";
	case ast::type::Kind::eMat3x4D:
		return "Mat3x4D";
	case ast::type::Kind::eMat4x2D:
		return "Mat4x2D";
	case ast::type::Kind::eMat4x3D:
		return "Mat4x3D";
	case ast::type::Kind::eMat4x4D:
		return "Mat4x4D";
	case ast::type::Kind::eArray:
		return "Array";
	case ast::type::Kind::eFunction:
		return "Function";
	case ast::type::Kind::eStruct:
		return "Struct";
	case ast::type::Kind::eSampler:
		return "Sampler";
	case ast::type::Kind::eImage:
		return "Image";
	case ast::type::Kind::eCombinedImage:
		return "CombinedImage";
	case ast::type::Kind::eSampledImage:
		return "SampledImage";
	case ast::type::Kind::eAccelerationStructure:
		return "AccelerationStructure";
	case ast::type::Kind::eRayPayload:
		return "RayPayload";
	case ast::type::Kind::eCallableData:
		return "CallableData";
	case ast::type::Kind::eHitAttribute:
		return "HitAttribute";
	case ast::type::Kind::eRayDesc:
		return "RayDesc";
	case ast::type::Kind::ePointer:
		return "Pointer";
	case ast::type::Kind::eGeometryInput:
		return "GeometryInput";
	case ast::type::Kind::eGeometryOutput:
		return "GeometryOutput";
	case ast::type::Kind::eTessellationInputPatch:
		return "TessellationInputPatch";
	case ast::type::Kind::eTessellationOutputPatch:
		return "TessellationOutputPatch";
	case ast::type::Kind::eTessellationControlInput:
		return "TessellationControlInput";
	case ast::type::Kind::eTessellationControlOutput:
		return "TessellationControlOutput";
	case ast::type::Kind::eTessellationEvaluationInput:
		return "TessellationEvaluationInput";
	case ast::type::Kind::eFragmentInput:
		return "FragmentInput";
	case ast::type::Kind::eComputeInput:
		return "ComputeInput";
	case ast::type::Kind::eMeshVertexOutput:
		return "MeshVertexOutput";
	case ast::type::Kind::eMeshPrimitiveOutput:
		return "MeshPrimitiveOutput";
	case ast::type::Kind::eTaskPayloadNV:
		return "TaskPayloadNV";
	case ast::type::Kind::eTaskPayload:
		return "TaskPayload";
	case ast::type::Kind::eTaskPayloadInNV:
		return "TaskPayloadInNV";
	case ast::type::Kind::eTaskPayloadIn:
		return "TaskPayloadIn";
	default:
		return "Unknown";
	}
}

inline std::string toString( ast::expr::Kind const & v )
{
	switch ( v )
	{
	case ast::expr::Kind::eCopy:
		return "Copy";
	case ast::expr::Kind::eAdd:
		return "Add";
	case ast::expr::Kind::eMinus:
		return "Minus";
	case ast::expr::Kind::eTimes:
		return "Times";
	case ast::expr::Kind::eDivide:
		return "Divide";
	case ast::expr::Kind::eModulo:
		return "Modulo";
	case ast::expr::Kind::eLShift:
		return "LShift";
	case ast::expr::Kind::eRShift:
		return "RShift";
	case ast::expr::Kind::eBitAnd:
		return "BitAnd";
	case ast::expr::Kind::eBitNot:
		return "BitNot";
	case ast::expr::Kind::eBitOr:
		return "BitOr";
	case ast::expr::Kind::eBitXor:
		return "BitXor";
	case ast::expr::Kind::eLogAnd:
		return "LogAnd";
	case ast::expr::Kind::eLogNot:
		return "LogNot";
	case ast::expr::Kind::eLogOr:
		return "LogOr";
	case ast::expr::Kind::eCast:
		return "Cast";
	case ast::expr::Kind::eInit:
		return "Init";
	case ast::expr::Kind::eAggrInit:
		return "AggrInit";
	case ast::expr::Kind::eFnCall:
		return "FnCall";
	case ast::expr::Kind::eCompositeConstruct:
		return "CompositeConstruct";
	case ast::expr::Kind::eIntrinsicCall:
		return "IntrinsicCall";
	case ast::expr::Kind::eCombinedImageAccessCall:
		return "CombinedImageAccessCall";
	case ast::expr::Kind::eImageAccessCall:
		return "ImageAccessCall";
	case ast::expr::Kind::eEqual:
		return "Equal";
	case ast::expr::Kind::eGreater:
		return "Greater";
	case ast::expr::Kind::eGreaterEqual:
		return "GreaterEqual";
	case ast::expr::Kind::eLess:
		return "Less";
	case ast::expr::Kind::eLessEqual:
		return "LessEqual";
	case ast::expr::Kind::eNotEqual:
		return "NotEqual";
	case ast::expr::Kind::eComma:
		return "Comma";
	case ast::expr::Kind::eIdentifier:
		return "Identifier";
	case ast::expr::Kind::eLiteral:
		return "Literal";
	case ast::expr::Kind::eMbrSelect:
		return "MbrSelect";
	case ast::expr::Kind::eSwizzle:
		return "Swizzle";
	case ast::expr::Kind::eSwitchTest:
		return "SwitchTest";
	case ast::expr::Kind::eSwitchCase:
		return "SwitchCase";
	case ast::expr::Kind::eQuestion:
		return "Question";
	case ast::expr::Kind::ePreIncrement:
		return "PreIncrement";
	case ast::expr::Kind::ePreDecrement:
		return "PreDecrement";
	case ast::expr::Kind::ePostIncrement:
		return "PostIncrement";
	case ast::expr::Kind::ePostDecrement:
		return "PostDecrement";
	case ast::expr::Kind::eUnaryMinus:
		return "UnaryMinus";
	case ast::expr::Kind::eUnaryPlus:
		return "UnaryPlus";
	case ast::expr::Kind::eAssign:
		return "Assign";
	case ast::expr::Kind::eAddAssign:
		return "AddAssign";
	case ast::expr::Kind::eMinusAssign:
		return "MinusAssign";
	case ast::expr::Kind::eTimesAssign:
		return "TimesAssign";
	case ast::expr::Kind::eDivideAssign:
		return "DivideAssign";
	case ast::expr::Kind::eModuloAssign:
		return "ModuloAssign";
	case ast::expr::Kind::eLShiftAssign:
		return "LShiftAssign";
	case ast::expr::Kind::eRShiftAssign:
		return "RShiftAssign";
	case ast::expr::Kind::eAndAssign:
		return "AndAssign";
	case ast::expr::Kind::eOrAssign:
		return "OrAssign";
	case ast::expr::Kind::eXorAssign:
		return "XorAssign";
	case ast::expr::Kind::eArrayAccess:
		return "ArrayAccess";
	case ast::expr::Kind::eAlias:
		return "Alias";
	case ast::expr::Kind::eStreamAppend:
		return "StreamAppend";
	default:
		return "Unknown";
	}
}

inline std::string toString( ast::stmt::Kind const & v )
{
	switch ( v )
	{
	case ast::stmt::Kind::eSimple:
		return "Simple";
	case ast::stmt::Kind::eContainer:
		return "Container";
	case ast::stmt::Kind::eCompound:
		return "Compound";
	case ast::stmt::Kind::eComment:
		return "Comment";
	case ast::stmt::Kind::eVariableDecl:
		return "VariableDecl";
	case ast::stmt::Kind::ePerPrimitiveDecl:
		return "PerPrimitiveDecl";
	case ast::stmt::Kind::ePerVertexDecl:
		return "PerVertexDecl";
	case ast::stmt::Kind::eInOutVariableDecl:
		return "InOutVariableDecl";
	case ast::stmt::Kind::eSpecialisationConstantDecl:
		return "SpecialisationConstantDecl";
	case ast::stmt::Kind::eConstantBufferDecl:
		return "ConstantBufferDecl";
	case ast::stmt::Kind::ePushConstantsBufferDecl:
		return "PushConstantsBufferDecl";
	case ast::stmt::Kind::eShaderBufferDecl:
		return "ShaderBufferDecl";
	case ast::stmt::Kind::eShaderStructBufferDecl:
		return "ShaderStructBufferDecl";
	case ast::stmt::Kind::eSamplerDecl:
		return "SamplerDecl";
	case ast::stmt::Kind::eImageDecl:
		return "ImageDecl";
	case ast::stmt::Kind::eSampledImageDecl:
		return "SampledImageDecl";
	case ast::stmt::Kind::eCombinedImageDecl:
		return "CombinedImageDecl";
	case ast::stmt::Kind::eFunctionDecl:
		return "FunctionDecl";
	case ast::stmt::Kind::eStructureDecl:
		return "StructureDecl";
	case ast::stmt::Kind::eIf:
		return "If";
	case ast::stmt::Kind::eElse:
		return "Else";
	case ast::stmt::Kind::eElseIf:
		return "ElseIf";
	case ast::stmt::Kind::eWhile:
		return "While";
	case ast::stmt::Kind::eFor:
		return "For";
	case ast::stmt::Kind::eDoWhile:
		return "DoWhile";
	case ast::stmt::Kind::eSwitch:
		return "Switch";
	case ast::stmt::Kind::eSwitchCase:
		return "SwitchCase";
	case ast::stmt::Kind::eReturn:
		return "Return";
	case ast::stmt::Kind::eBreak:
		return "Break";
	case ast::stmt::Kind::eContinue:
		return "Continue";
	case ast::stmt::Kind::eDemote:
		return "Demote";
	case ast::stmt::Kind::eTerminateInvocation:
		return "TerminateInvocation";
	case ast::stmt::Kind::eInputGeometryLayout:
		return "InputGeometryLayout";
	case ast::stmt::Kind::eOutputGeometryLayout:
		return "OutputGeometryLayout";
	case ast::stmt::Kind::eInputComputeLayout:
		return "InputComputeLayout";
	case ast::stmt::Kind::eOutputMeshLayout:
		return "OutputMeshLayout";
	case ast::stmt::Kind::eFragmentLayout:
		return "FragmentLayout";
	case ast::stmt::Kind::eOutputTessellationControlLayout:
		return "OutputTessellationControlLayout";
	case ast::stmt::Kind::eInputTessellationEvaluationLayout:
		return "InputTessellationEvaluationLayout";
	case ast::stmt::Kind::eAccelerationStructureDecl:
		return "AccelerationStructureDecl";
	case ast::stmt::Kind::eInOutRayPayloadVariableDecl:
		return "InOutRayPayloadVariableDecl";
	case ast::stmt::Kind::eHitAttributeVariableDecl:
		return "HitAttributeVariableDecl";
	case ast::stmt::Kind::eInOutCallableDataVariableDecl:
		return "InOutCallableDataVariableDecl";
	case ast::stmt::Kind::eBufferReferenceDecl:
		return "BufferReferenceDecl";
	case ast::stmt::Kind::eTerminateRay:
		return "TerminateRay";
	case ast::stmt::Kind::eIgnoreIntersection:
		return "IgnoreIntersection";
	case ast::stmt::Kind::eDispatchMesh:
		return "DispatchMesh";
	case ast::stmt::Kind::ePreprocExtension:
		return "PreprocExtension";
	case ast::stmt::Kind::ePreprocVersion:
		return "PreprocVersion";
	default:
		return "Unknown";
	}
}

namespace test
{
	void printCDBConsole( std::string const & toLog
		, bool newLine );
	uint32_t getCoreCount();
	std::string getExecutableDirectory();

	struct TestCounts;
	struct TestSuite;

	class Exception
		: public std::runtime_error
	{
		using std::runtime_error::runtime_error;

	public:
		std::string getText()const
		{
			return what();
		}
	};

	struct TestStringStreams
	{
		TestStringStreams( std::string & sout );

		std::stringstream cout;
		std::unique_ptr< std::streambuf > tcout;
	};

	struct TestResults
	{
		uint32_t totalCount{ 0u };
		uint32_t errorCount{ 0u };
	};

	struct TestCounts
	{
		TestCounts( TestSuite & suite );
		virtual ~TestCounts()noexcept;

		void initialise();
		TestResults cleanup();

		uint32_t getTotalCount()
		{
			return result.totalCount;
		}

		void incTest();
		void incErr();

		std::string testName;
		uint32_t curTestErrors{ 0u };
		std::string sout;
		TestStringStreams streams;
		uint32_t nextVarId{};
		ast::ShaderAllocator allocator;
		ast::ShaderAllocatorBlockPtr allocatorBlock;

		void incIndent()
		{
			indent += 2;
		}

		void decIndent()
		{
			if ( indent >= 2 )
			{
				indent -= 2;
			}
			else
			{
				indent = 0;
			}
		}

		uint32_t getNextVarId()
		{
			++nextVarId;
			return nextVarId;
		}

	private:
		virtual void doInitialise(){}
		virtual void doCleanup(){}

		void print( std::string const & text )
		{
			std::stringstream stream{ text };
			std::string sep;

			for ( std::string line; std::getline( stream, line ); )
			{
				if ( line.empty() )
				{
					streams.cout << std::endl;
					newLine = true;
				}
				else
				{
					if ( newLine )
					{
						streams.cout << getIndent();
					}

					streams.cout << sep << line;
					newLine = false;
				}

				sep = "\n" + getIndent();
			}
		}

		std::string getIndent()const
		{
			return std::string( size_t( indent ), ' ' );
		}

	private:
		template< typename T >
		friend TestCounts & operator<<( TestCounts & counts, T const & rhs );

		uint32_t indent{};
		bool newLine{ true };
		TestSuite & suite;
		TestResults result{};
		std::atomic_bool m_initialised{ false };
		std::atomic_bool m_cleaned{ true };
	};

	static std::string_view endl{ "\n" };

	template< typename T >
	TestCounts & operator<<( TestCounts & counts, T const & rhs )
	{
		std::stringstream stream;
		stream.imbue( std::locale{ "C" } );
		stream << rhs;
		counts.print( stream.str() );
		return counts;
	}

	using TestCountsPtr = std::unique_ptr< TestCounts >;

	struct TestSuite
	{
		using TestCountsType = test::TestCounts;
		using TestSuiteLaunch = TestResults( * )( test::TestSuite &, test::TestCounts & );

		TestSuite( std::string name );
		~TestSuite()noexcept;

		void registerTests( std::string name
			, TestSuiteLaunch launch
			, TestCountsPtr testCounts );
		int run();

		template< typename TestSuiteT >
		void registerTests( std::string name
			, TestSuiteLaunch launch )
		{
			return registerTests( std::move( name )
				, std::move( launch )
				, std::make_unique< typename TestSuiteT::TestCountsType >( *this ) );
		}

		template< typename TestSuiteT
			, typename TestCountsT >
		void registerTests( std::string name
			, TestResults( *launch )( TestSuiteT &, TestCountsT & ) )
		{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
			return registerTests( std::move( name )
				, reinterpret_cast< TestSuiteLaunch >( launch )
				, std::make_unique< typename TestSuiteT::TestCountsType >( *this ) );
#pragma GCC diagnostic pop
		}

		std::atomic_uint32_t totalCount{ 0u };
		std::atomic_uint32_t errorCount{ 0u };
		std::atomic_uint32_t totalMemory{ 0u };

	private:
		struct TestSuiteRun
		{
			TestSuiteRun( TestSuiteLaunch plaunch
				, std::string pname
				, TestCountsPtr ptestCount )
				: launch{ std::move( plaunch ) }
				, name{ std::move( pname ) }
				, testCount{ std::move( ptestCount ) }
			{
			}

			TestSuiteLaunch launch;
			std::string name;
			TestCountsPtr testCount;
		};
		using TestSuiteRunPtr = std::unique_ptr< TestSuiteRun >;

		std::string suiteName;
		std::vector< TestSuiteRunPtr > tests;
		std::unique_ptr< std::streambuf > tcout;
	};

	void beginTest( TestCounts & testCounts
		, std::string name );
	void endTest( TestCounts & testCounts );
	void reportFailure( char const * const error
		, char const * const function
		, int line
		, TestCounts & testCounts );
	void reportFailure( char const * const error
		, char const * const callerFunction
		, int callerLine
		, char const * const calleeFunction
		, int calleeLine
		, TestCounts & testCounts );

	inline void reportFailure( std::string_view error
		, char const * const function
		, int line
		, TestCounts & testCounts )
	{
		reportFailure( error.data(), function, line, testCounts );
	}

	inline void reportFailure( std::string_view error
		, char const * const callerFunction
		, int callerLine
		, char const * const calleeFunction
		, int calleeLine
		, TestCounts & testCounts )
	{
		reportFailure( error.data(), callerFunction, callerLine, calleeFunction, calleeLine, testCounts );
	}

	inline void reportFailure( std::string_view error
		, std::string const & callerFunction
		, int callerLine
		, char const * const calleeFunction
		, int calleeLine
		, TestCounts & testCounts )
	{
		reportFailure( error.data(), callerFunction.c_str(), callerLine, calleeFunction, calleeLine, testCounts );
	}

#	define testSuiteMain( testName )\
	static test::TestResults launch##testName( test::TestSuite & suite, test::TestCounts & testCounts )

#if defined( _MSC_VER )
#	define testEval( V ) V

#	define testConcat2( lhs, rhs )\
	testEval( lhs ) ## testEval( rhs )

#	define testConcat3( lhs, mid, rhs )\
	testConcat2( lhs, mid ) ## testEval( rhs )

#	define testConcat( lhs, rhs )\
	testConcat3( lhs, _, rhs )
#else
#	define testConcat2( lhs, rhs )\
	lhs ## rhs

#	define testConcat( lhs, rhs )\
	lhs ## _ ## rhs
#endif

#if defined( SDW_COMPILE_TESTS )
#	define testSuiteLaunchEx( testName, suiteType )\
	int main( int argv, char ** argc )\
	{\
		suiteType suite{ #testName };\
		suite.registerTests< suiteType >( #testName, testConcat2( launch, testName ) );\
		return suite.run();\
	}
#else
#	define testSuiteLaunchEx( testName, suiteType )
#endif

#define testSuiteLaunch( name )\
	testSuiteLaunchEx( name, test::TestSuite )

#define testStringify( x )\
	#x

#define testConcatStr2( x, y )\
	testStringify( x ) testStringify( y )

#define testConcatStr3( x, y, z )\
	testConcatStr2( x, y ) testStringify( z )

#define testConcatStr4( x, y, z, w )\
	testConcatStr3( x, y, z ) testStringify( w )

#define testSuiteBeginEx( testCounts )\
	testCounts.initialise();\
	try\
	{\

#define testSuiteEnd()\
	}\
	catch ( ast::Exception & exc )\
	{\
		test::reportFailure( std::string{ "Test failed, Unhandled exception: " } + exc.what(), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( "Test failed, Unhandled exception: Unknown", __FUNCTION__, __LINE__, testCounts );\
	}\
	return testCounts.cleanup();

#define testSuiteBegin()\
	testSuiteBeginEx( testCounts )

#define testBegin( name )\
	test::beginTest( testCounts, name );\
	try\
	{\
		auto testName = testCounts.testName

#define testEnd()\
	}\
	catch ( ast::Exception & exc )\
	{\
		test::reportFailure( std::string{ "Test failed, Unhandled exception: " } + exc.what(), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( "Test failed, Unhandled exception: Unknown", __FUNCTION__, __LINE__, testCounts );\
	}\
	test::endTest( testCounts );

#define success()\
	testCounts.incTest()

#define failure( x )\
	success();\
	test::reportFailure( x " failed.", __FUNCTION__, __LINE__, testCounts )\

#define require( x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			throw test::Exception{ "\n    Value: " + toString( x ) };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		test::reportFailure( testConcatStr2( x, " failed:" ) + exc.getText(), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define beginRequire( x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			throw test::Exception{ "\n    Value: " + toString( x ) };\
		}

#define endRequire\
	}\
	catch ( test::Exception & exc )\
	{\
		test::reportFailure( testConcatStr2( x, " failed:" ) + exc.getText(), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define check( x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			test::reportFailure( testConcatStr2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
		}\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr2( x, " failed: Unhandled exception." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define checkEqual( x, y )\
	try\
	{\
		testCounts.incTest();\
		if ( ( x ) != ( y ) )\
		{\
			throw test::Exception{ "\n    LHS: " + toString( x ) + "\n    RHS: " + toString( y ) };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		test::reportFailure( testConcatStr4( x, " == ", y, " failed:" ) + exc.getText(), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr4( x, " == ", y, " failed: Unhandled exception." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define checkNotEqual( x, y )\
	try\
	{\
		testCounts.incTest();\
		if ( ( x ) == ( y ) )\
		{\
			throw test::Exception{ "\n    LHS: " + toString( x ) + "\n    RHS: " + toString( y ) };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		test::reportFailure( testConcatStr4( x, " != ", y, " failed:" ) + exc.getText(), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr4( x, " != ", y, " failed: Unhandled exception." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define checkThrow( x )\
	try\
	{\
		testCounts.incTest();\
		( x ); \
		test::reportFailure( testConcatStr2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ast::Exception & exc )\
	{\
		testCounts << testCounts.testName << " Success: Expected exception - " << exc.what() << test::endl;\
	}\
	catch ( ... )\
	{\
		testCounts << testCounts.testName << " Failure: Unexpected exception type." << test::endl;\
	}

#define checkNoThrow( x )\
	try\
	{\
		testCounts.incTest();\
		( x ); \
	}\
	catch ( ast::Exception & exc )\
	{\
		test::reportFailure( exc.what(), __FUNCTION__, __LINE__, testCounts );\
		test::reportFailure( testConcatStr2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr2( x, " failed." ), __FUNCTION__, __LINE__, testCounts );\
	}

#define subRequire( f, l, x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			throw test::Exception{ "\n    Value: " + toString( x ) };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		test::reportFailure( testConcatStr2( x, " failed:" ) + exc.getText(), f, l, __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr2( x, " failed." ), f, l, __FUNCTION__, __LINE__, testCounts );\
	}

#define subCheck( f, l, x )\
	try\
	{\
		testCounts.incTest();\
		if ( !( x ) )\
		{\
			test::reportFailure( testConcatStr2( x, " failed." ), f, l, __FUNCTION__, __LINE__, testCounts );\
		}\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr2( x, " failed: Unhandled exception." ), f, l, __FUNCTION__, __LINE__, testCounts );\
	}

#define subCheckEqual( f, l, x, y )\
	try\
	{\
		testCounts.incTest();\
		if ( ( x ) != ( y ) )\
		{\
			throw test::Exception{ "\n    LHS: " + toString( x ) + "\n    RHS: " + toString( y ) };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		test::reportFailure( testConcatStr4( x, " == ", y, " failed:" ) + exc.getText(), f, l, __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr4( x, " == ", y, " failed: Unhandled exception." ), f, l, __FUNCTION__, __LINE__, testCounts );\
	}

#define subCheckNotEqual( f, l, x, y )\
	try\
	{\
		testCounts.incTest();\
		if ( ( x ) == ( y ) )\
		{\
			throw test::Exception{ "\n    LHS: " + toString( x ) + "\n    RHS: " + toString( y ) };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		test::reportFailure( testConcatStr4( x, " != ", y, " failed:" ) + exc.getText(), f, l, __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr4( x, " != ", y, " failed: Unhandled exception." ), f, l, __FUNCTION__, __LINE__, testCounts );\
	}

#define subCheckThrow( f, l, x )\
	try\
	{\
		testCounts.incTest();\
		( x ); \
		test::reportFailure( testConcatStr2( x, " failed." ), f, l, __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ast::Exception & exc )\
	{\
		testCounts << testCounts.testName << " Success: Expected exception - " << exc.what() << test::endl;\
	}\
	catch ( ... )\
	{\
		testCounts << testCounts.testName << " Failure: Unexpected exception type." << test::endl;\
	}

#define subCheckNoThrow( f, l, x )\
	try\
	{\
		testCounts.incTest();\
		( x ); \
	}\
	catch ( ast::Exception & exc )\
	{\
		test::reportFailure( exc.what(), f, l, __FUNCTION__, __LINE__, testCounts );\
		test::reportFailure( testConcatStr2( x, " failed." ), f, l, __FUNCTION__, __LINE__, testCounts );\
	}\
	catch ( ... )\
	{\
		test::reportFailure( testConcatStr2( x, " failed." ), f, l, __FUNCTION__, __LINE__, testCounts );\
	}
}
