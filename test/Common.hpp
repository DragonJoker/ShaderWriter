#pragma once

#include <ShaderAST/Expr/ExprCache.hpp>
#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/ImageConfiguration.hpp>
#include <ShaderAST/Type/TypeArray.hpp>

#include <gtest/gtest.h>

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 4068 )
#pragma warning( disable: 5262 )
#pragma warning( disable: 5264 )
#pragma clang diagnostic ignored "-Wextra-semi-stmt"
#pragma GCC diagnostic ignored "-Wrestrict"
#include <atomic>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#pragma warning( pop )

#if defined( _WIN32 ) && !defined( TestASTCommon_STATIC )
#	if defined( TestASTCommon_EXPORTS )
#		define ASTTest_API __declspec( dllexport )
#	else
#		define ASTTest_API __declspec( dllimport )
#	endif
#else
#	define ASTTest_API
#endif

#define astTestStringify( x )\
	#x

#define testConcatStr2( x, y )\
	astTestStringify( x ) astTestStringify( y )

#define astTestConcatStr3( x, y, z )\
	testConcatStr2( x, y ) astTestStringify( z )

#define astTestConcatStr4( x, y, z, w )\
	astTestConcatStr3( x, y, z ) astTestStringify( w )

#if defined( _MSC_VER )
#	define astTestEval( V ) V

#	define astTestConcat2( lhs, rhs )\
	astTestEval( lhs ) ## astTestEval( rhs )

#	define astTestConcat3( lhs, mid, rhs )\
	astTestConcat2( lhs, mid ) ## astTestEval( rhs )

#	define astTestConcat( lhs, rhs )\
	astTestConcat3( lhs, _, rhs )
#else
#	define astTestConcat2( lhs, rhs )\
	lhs ## rhs

#	define astTestConcat( lhs, rhs )\
	lhs ## _ ## rhs
#endif

#define astNameConcat( X, Y ) astNameConcat_( X, Y )
#define astNameConcat_( X, Y ) X ## Y

template< typename ValueT >
inline std::string toString( ValueT const & v )
{
	return std::to_string( v );
}

template< typename ValueT >
inline std::string toString( std::unique_ptr< ValueT > const & v )
{
	std::stringstream stream;
	stream << std::hex << std::setw( 8u ) << std::setfill( '0' ) << uintptr_t( v.get() );
	return stream.str();
}

template< typename ValueT >
inline std::string toString( std::shared_ptr< ValueT > const & v )
{
	std::stringstream stream;
	stream << std::hex << std::setw( 8u ) << std::setfill( '0' ) << uintptr_t( v.get() );
	return stream.str();
}

template< size_t SizeT >
inline std::string toString( char const v[SizeT] )
{
	return std::string( v );
}

inline std::string toString( char const * const v )
{
	return std::string( v );
}

inline std::string const & toString( std::string const & v )
{
	return v;
}

inline std::string toString( ast::Builtin const & v )
{
	return getName( v );
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
	ASTTest_API void printCDBConsole( std::string const & toLog
		, bool newLine );
	ASTTest_API std::string getExecutableDirectory();

	struct TestCounts;
	class TestSuite;

	class Exception
		: public std::runtime_error
	{
	public:
		explicit Exception( char const * const message
			, char const * const function
			, int32_t line )
			: std::runtime_error{ message }
			, m_function{ function }
			, m_line{ line }
		{
		}

		explicit Exception( std::string const & message
			, char const * const function
			, int32_t line )
			: Exception{ message.c_str(), function, line }
		{
		}

		std::string getText()const
		{
			return what();
		}

		std::string getFunction()const
		{
			return m_function;
		}

		int32_t getLine()const
		{
			return m_line;
		}

		std::string m_function;
		int32_t m_line;
	};

	struct TestTrace
	{
		ASTTest_API TestTrace( TestCounts & testCounts, std::string_view file, int line, std::string_view message );
		ASTTest_API ~TestTrace();

		operator bool()const
		{
			return true;
		}

		std::string file;
		int line;
		std::string message;

	private:
		TestCounts & m_testCounts;
		testing::ScopedTrace m_trace;
	};

	struct TestCounts
	{
		friend struct TestBlock;
		friend struct TestTrace;

		ASTTest_API TestCounts();
		ASTTest_API virtual ~TestCounts()noexcept;

		void initialise( std::string const & name )
		{
			testName = name;
			doInitialise();
		}

		void cleanup()
		{
			doCleanup();
			testName.clear();
		}

		ASTTest_API virtual void printBlock( std::string const & text );
		ASTTest_API virtual void printError( std::string const & text );

		std::string testName{};
		uint32_t nextVarId{};
		ast::ShaderAllocator allocator;
		ast::ShaderAllocatorBlockPtr allocatorBlock;

		uint32_t getNextVarId()
		{
			++nextVarId;
			return nextVarId;
		}

	private:
		virtual void doInitialise()
		{
		}

		virtual void doCleanup()
		{
		}

		void doPushTrace( TestTrace const * trace )
		{
			m_traces.push_back( trace );
		}

		void doPopTrace()
		{
			m_traces.pop_back();
		}

	protected:
		std::atomic_bool m_initialised{ false };
		std::atomic_bool m_cleaned{ true };
		std::vector< TestTrace const * > m_traces;

		template< typename T >
		friend TestCounts & operator<<( TestCounts & counts, T const & rhs )
		{
			return counts;
		}
	};

	class TestSuite
		: public ::testing::Environment
	{
	public:
		ASTTest_API TestSuite( std::string const & name );

	private:
		std::unique_ptr< std::streambuf > tcout;
	};

	int testsMain( int argc, char ** argv, std::string_view testSuiteName );
}

#define astTestBegin( name )\
	test::TestCounts testCounts;\
	testCounts.initialise( name );

#define astTestEnd()\
	testCounts.cleanup();

#define astCheck( x )\
	EXPECT_TRUE( x );

#define astCheckEqual( lhs, rhs )\
	EXPECT_EQ( lhs, rhs );

#define astCheckNotEqual( lhs, rhs )\
	EXPECT_NE( lhs, rhs );

#define astCheckThrowEx( x, excType )\
	EXPECT_THROW( x, excType );

#define astCheckNoThrowEx( x, excType )\
	EXPECT_NO_THROW( x );

#define astRequire( x )\
	try\
	{\
		if ( !( x ) )\
		{\
			throw test::Exception{ "\n    Value: " + toString( x ), __FUNCTION__, __LINE__ };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		GTEST_FATAL_FAILURE_( ( std::string{ #x" failed." } + exc.what() ).c_str() );\
	}\
	catch ( ... )\
	{\
		GTEST_FATAL_FAILURE_( "Unknown unhandled exception." );\
	}

#define astBeginRequire( x )\
	try\
	{\
		if ( !( x ) )\
		{\
			throw test::Exception{ testConcatStr2( x, " failed." ), __FUNCTION__, __LINE__ };\
		}

#define astEndRequire\
	}\
	catch ( test::Exception & exc )\
	{\
		GTEST_FATAL_FAILURE_( exc.what() );\
	}\
	catch ( ... )\
	{\
		GTEST_FATAL_FAILURE_( "Unknown unhandled exception." );\
	}

#define astSubRequire( f, l, x )\
	try\
	{\
		if ( !( x ) )\
		{\
			throw test::Exception{ #x" failed.", __FUNCTION__, __LINE__ };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		GTEST_NONFATAL_FAILURE_( ( std::string{ #x" failed." } + exc.what() ).c_str() );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}\
	catch ( ... )\
	{\
		GTEST_NONFATAL_FAILURE_( #x" failed." );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}

#define astSubCheck( f, l, x )\
	try\
	{\
		if ( !( x ) )\
		{\
			GTEST_NONFATAL_FAILURE_( #x" failed: " );\
			GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
			GTEST_FATAL_FAILURE_( "Exiting" );\
		}\
	}\
	catch ( ... )\
	{\
		GTEST_NONFATAL_FAILURE_( #x" failed: Unhandled exception." );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}

#define astSubCheckEqual( f, l, x, y )\
	try\
	{\
		if ( !( ( x ) == ( y ) ) )\
		{\
			throw test::Exception{ "\n    LHS: " + toString( x ) + "\n    RHS: " + toString( y ), __FUNCTION__, __LINE__ };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		GTEST_NONFATAL_FAILURE_( ( std::string{ #x" failed: " } + exc.what() ).c_str() );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}\
	catch ( ... )\
	{\
		GTEST_NONFATAL_FAILURE_( #x" failed: Unhandled exception." );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}

#define astSubCheckNotEqual( f, l, x, y )\
	try\
	{\
		if ( ( x ) == ( y ) )\
		{\
			throw test::Exception{ "\n    LHS: " + toString( x ) + "\n    RHS: " + toString( y ), __FUNCTION__, __LINE__ };\
		}\
	}\
	catch ( test::Exception & exc )\
	{\
		GTEST_NONFATAL_FAILURE_( ( std::string{ #x" failed: " } + exc.what() ).c_str() );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}\
	catch ( ... )\
	{\
		GTEST_MESSAGE_( #x" failed: Unhandled exception." );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}

#define astSubCheckThrowEx( f, l, x, excType )\
	try\
	{\
		( x );\
		GTEST_NONFATAL_FAILURE_( #x" failed: Expected exception not thrown." );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}\
	catch ( excType & )\
	{\
		SUCCEED();\
	}\
	catch ( ... )\
	{\
		GTEST_NONFATAL_FAILURE_( #x" failed: Unexpected exception type." );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}

#define astSubCheckNoThrowEx( f, l, x, excType )\
	try\
	{\
		( x );\
	}\
	catch ( excType & exc )\
	{\
		GTEST_NONFATAL_FAILURE_( ( std::string{ #x" failed: " } + exc.what() ).c_str() );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}\
	catch ( ... )\
	{\
		GTEST_NONFATAL_FAILURE_( #x" failed: Unhandled exception." );\
		GTEST_MESSAGE_AT_( f, l, "Called From: ", ::testing::TestPartResult::kNonFatalFailure );\
		GTEST_FATAL_FAILURE_( "Exiting" );\
	}

#define astTrace( message )\
	const ::test::TestTrace astNameConcat( trace, __LINE__ ){ testCounts, __FILE__, __LINE__, ( message ) }

#define astOn( message )\
	astTrace( std::string{ "On " } + ( message ) )

#define astWhen( message )\
	astTrace( std::string{ "When " } + ( message ) )

#define astAnd( message )\
	astTrace( std::string{ "And " } + ( message ) )

#define astTestNameP( p, f ) \
	[]( testing::TestParamInfo< p > const & i ){ return f( i.param ); }

#define astCheckThrow( x )\
	astCheckThrowEx( x, ast::Exception );

#define astCheckNoThrow( x )\
	astCheckNoThrowEx( x, ast::Exception )

#define astSubCheckThrow( f, l, x )\
	astSubCheckThrowEx( f, l, x, ast::Exception )

#define astSubCheckNoThrow( f, l, x )\
	astSubCheckNoThrowEx( f, l, x, ast::Exception )

#define astTestSuiteMain()\
	int main( int argc, char ** argv )\
	{\
		return test::testsMain( argc, argv, AST_TestSuiteNameString );\
	}
