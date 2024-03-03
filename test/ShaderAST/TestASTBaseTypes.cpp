#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	void testBase( test::TestCounts & testCounts )
	{
		testBegin( "testBase" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getUndefined();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUndefined )
			check( type->getIndex() == ast::type::NotMember )
			check( type->getParent() == nullptr )
			check( !isWrapperType( *type ) )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isScalarType( type ) )
			check( !isVectorType( type->getKind() ) )
			check( !isVectorType( type ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isMatrixType( type ) )
			check( !isArrayType( type->getKind() ) )
			check( !isArrayType( type ) )
			check( !isPointerType( type->getKind() ) )
			check( !isPointerType( type ) )
			check( !isStructType( type->getKind() ) )
			check( !isStructType( type ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSamplerType( type ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isSampledImageType( type ) )
			check( !isImageType( type->getKind() ) )
			check( !isImageType( type ) )
			check( !isTextureType( type->getKind() ) )
			check( !isTextureType( type ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isAccelerationStructureType( type ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isHitAttributeType( type ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isRayPayloadType( type ) )
			check( !isCallableDataType( type->getKind() ) )
			check( !isCallableDataType( type ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentCount( type ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
			check( getComponentType( type ) == type->getKind() )
			check( unwrapType( type ) == type )
			check( &unwrapType( *type ) == type.get() )
		}
		{
			auto type = typesCache.getVoid();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVoid )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getBool();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eBoolean )
			check( isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
			check( getScalarType( type->getKind() ) == type->getKind() )
		}
		testEnd()
	}

	void testSIntBase( test::TestCounts & testCounts )
	{
		testBegin( "testSIntBase" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getInt8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt8 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getInt16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getInt32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getInt64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		testEnd()
	}

	void testUIntBase( test::TestCounts & testCounts )
	{
		testBegin( "testUIntBase" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getUInt8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt8 )
			check( !isBoolType( type->getKind() ) )
			check( isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getUInt16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getUInt32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getUInt64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		testEnd()
	}

	void testFloatBase( test::TestCounts & testCounts )
	{
		testBegin( "testFloatBase" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getHalf();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eHalf )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getFloat();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eFloat )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getDouble();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eDouble )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 1u )
			check( getComponentType( type->getKind() ) == type->getKind() )
		}
		testEnd()
	}

	void testBaseVecSInt( test::TestCounts & testCounts )
	{
		testBegin( "testBaseVecSInt" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getVec2B();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2B )
			check( isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eBoolean )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eVec2 )
		}
		{
			auto type = typesCache.getVec3B();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3B )
			check( isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eBoolean )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eVec3 )
		}
		{
			auto type = typesCache.getVec4B();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4B )
			check( isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eBoolean )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eVec4 )
		}
		{
			auto type = typesCache.getVec2I8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I8 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec3I8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3I8 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec4I8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I8 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec2I16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec3I16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3I16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec4I16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec2I32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec3I32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3I32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec4I32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec2I64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt64 )
		}
		{
			auto type = typesCache.getVec3I64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3I64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt64 )
		}
		{
			auto type = typesCache.getVec4I64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eInt64 )
		}
		testEnd()
	}

	void testBaseVecUInt( test::TestCounts & testCounts )
	{
		testBegin( "testBaseVecUInt" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getVec2U8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U8 )
			check( !isBoolType( type->getKind() ) )
			check( isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec3U8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3U8 )
			check( !isBoolType( type->getKind() ) )
			check( isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec4U8();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U8 )
			check( !isBoolType( type->getKind() ) )
			check( isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec2U16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec3U16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3U16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec4U16();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U16 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec2U32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec3U32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3U32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec4U32();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U32 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec2U64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt64 )
		}
		{
			auto type = typesCache.getVec3U64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3U64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt64 )
		}
		{
			auto type = typesCache.getVec4U64();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U64 )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eUInt64 )
		}
		testEnd()
	}

	void testBaseVecFloat( test::TestCounts & testCounts )
	{
		testBegin( "testBaseVecH" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getVec2H();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2H )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eHalf )
		}
		{
			auto type = typesCache.getVec4H();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4H )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eHalf )
		}
		{
			auto type = typesCache.getVec2F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec3F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec4F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec2D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVec3D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec3D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVec4D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( isVectorType( type->getKind() ) )
			check( !isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eDouble )
		}
		testEnd()
	}

	void testBaseMatrixFloat( test::TestCounts & testCounts )
	{
		testBegin( "testBaseMatrixFloat" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getMat2x2F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat2x2F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec2F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat2x2 )
		}
		{
			auto type = typesCache.getMat2x3F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat2x3F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec3F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat2x3 )
		}
		{
			auto type = typesCache.getMat2x4F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat2x4F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec4F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat2x4 )
		}
		{
			auto type = typesCache.getMat3x2F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat3x2F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec2F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat3x2 )
		}
		{
			auto type = typesCache.getMat3x3F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat3x3F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec3F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat3x3 )
		}
		{
			auto type = typesCache.getMat3x4F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat3x4F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec4F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat3x4 )
		}
		{
			auto type = typesCache.getMat4x2F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat4x2F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec2F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat4x2 )
		}
		{
			auto type = typesCache.getMat4x3F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat4x3F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec3F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat4x3 )
		}
		{
			auto type = typesCache.getMat4x4F();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat4x4F )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( isFloatType( type->getKind() ) )
			check( !isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec4F )
			check( getCompositeType( type->getKind() ) == ast::expr::CompositeType::eMat4x4 )
		}
		testEnd()
	}

	void testBaseMatrixDouble( test::TestCounts & testCounts )
	{
		testBegin( "testBaseMatrixDouble" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getMat2x2D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat2x2D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec2D )
			check( getScalarType( type->getKind() ) == ast::type::Kind::eDouble )
		}
		{
			auto type = typesCache.getMat2x3D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat2x3D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec3D )
		}
		{
			auto type = typesCache.getMat2x4D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat2x4D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 2u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec4D )
		}
		{
			auto type = typesCache.getMat3x2D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat3x2D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec2D )
		}
		{
			auto type = typesCache.getMat3x3D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat3x3D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec3D )
		}
		{
			auto type = typesCache.getMat3x4D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat3x4D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 3u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec4D )
		}
		{
			auto type = typesCache.getMat4x2D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat4x2D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec2D )
		}
		{
			auto type = typesCache.getMat4x3D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat4x3D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec3D )
		}
		{
			auto type = typesCache.getMat4x4D();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eMat4x4D )
			check( !isBoolType( type->getKind() ) )
			check( !isUnsignedInt8Type( type->getKind() ) )
			check( !isSignedInt8Type( type->getKind() ) )
			check( !isUnsignedInt16Type( type->getKind() ) )
			check( !isSignedInt16Type( type->getKind() ) )
			check( !isUnsignedInt32Type( type->getKind() ) )
			check( !isSignedInt32Type( type->getKind() ) )
			check( !isUnsignedInt64Type( type->getKind() ) )
			check( !isSignedInt64Type( type->getKind() ) )
			check( !isUnsignedIntType( type->getKind() ) )
			check( !isSignedIntType( type->getKind() ) )
			check( !isHalfType( type->getKind() ) )
			check( !isFloatType( type->getKind() ) )
			check( isDoubleType( type->getKind() ) )
			check( !isScalarType( type->getKind() ) )
			check( !isVectorType( type->getKind() ) )
			check( isMatrixType( type->getKind() ) )
			check( !isArrayType( type->getKind() ) )
			check( !isPointerType( type->getKind() ) )
			check( !isStructType( type->getKind() ) )
			check( !isSamplerType( type->getKind() ) )
			check( !isSampledImageType( type->getKind() ) )
			check( !isImageType( type->getKind() ) )
			check( !isTextureType( type->getKind() ) )
			check( !isAccelerationStructureType( type->getKind() ) )
			check( !isHitAttributeType( type->getKind() ) )
			check( !isRayPayloadType( type->getKind() ) )
			check( !isCallableDataType( type->getKind() ) )
			check( getComponentCount( type->getKind() ) == 4u )
			check( getComponentType( type->getKind() ) == ast::type::Kind::eVec4D )
		}
		testEnd()
	}

	void testGetSampledType( test::TestCounts & testCounts )
	{
		testBegin( "testGetSampledType" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eUnknown );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba32f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba16f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg32f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2F )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg16f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2F )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR32f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR16f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba32i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba16i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba8i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg32i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg16i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg8i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR32i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR16i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR8i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba32u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba16u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba8u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg32u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg16u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg8u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR32u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR16u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR8u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		testEnd()
	}

	void testGetTexelType( test::TestCounts & testCounts )
	{
		testBegin( "testGetTexelType" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eUnknown );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba32f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba16f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4H )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg32f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2F )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg16f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2H )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR32f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR16f );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eHalf )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba32i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba16i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba8i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg32i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg16i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg8i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR32i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR16i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR8i );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba32u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba16u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba8u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg32u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg16u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg8u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR32u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR16u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR8u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		testEnd()
	}

	void testBasicFunctions( test::TestCounts & testCounts )
	{
		testBegin( "testBasicFunctions" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eBoolean );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eBoolean )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eBoolean );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eBoolean ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eBoolean );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eBoolean ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eBoolean );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eBoolean ) )
		}
		{
			auto type = typesCache.getRayDesc();
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eRayDesc )
			check( type->getMemoryLayout() == ast::type::MemoryLayout::eC )
			check( type->getName() == "RayDesc" )
			check( type->getFlag() == 0u )
			check( type->size() == 4u )
			check( type->getMember( "Origin" ).type->getKind() == ast::type::Kind::eVec3F )
			check( type->getMember( "TMin" ).type->getKind() == ast::type::Kind::eFloat )
			check( type->getMember( "Direction" ).type->getKind() == ast::type::Kind::eVec3F )
			check( type->getMember( "TMax" ).type->getKind() == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getNonMemberType( typesCache.getInt32() );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		testEnd()
	}

	void testBasicFunctionsSInt( test::TestCounts & testCounts )
	{
		testBegin( "testBasicFunctionsSInt" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt8 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt8 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt8 ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt16 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt16 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt16 ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt32 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt32 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt32 ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eInt64 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt64 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt64 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt64 ) )
		}
		testEnd()
	}

	void testBasicFunctionsUInt( test::TestCounts & testCounts )
	{
		testBegin( "testBasicFunctionsUInt" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt8 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt8 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt8 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt8 ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt16 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt16 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt16 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt16 ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt32 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt32 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt32 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt32 ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eUInt64 )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt64 ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt64 ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt64 );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt64 ) )
		}
		testEnd()
	}

	void testBasicFunctionsFloat( test::TestCounts & testCounts )
	{
		testBegin( "testBasicFunctionsFloat" );
		ast::type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eHalf );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eHalf )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eHalf );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eHalf ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eHalf );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eHalf ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eFloat );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eFloat );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eFloat ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eFloat );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eFloat ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eFloat );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eFloat ) )
		}
		{
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec2F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec2F ) )
		}
		{
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec3F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec3F ) )
		}
		{
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec4F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec4F ) )
		}
		{
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec2F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec2F ) )
		}
		{
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec3F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec3F ) )
		}
		{
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec4F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec4F ) )
		}
		{
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec2F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec2F ) )
		}
		{
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec3F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec3F ) )
		}
		{
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec4F );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec4F ) )
		}
		{
			auto type = typesCache.getBasicType( ast::type::Kind::eDouble );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVec2Type( ast::type::Kind::eDouble );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVec3Type( ast::type::Kind::eDouble );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVec4Type( ast::type::Kind::eDouble );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec2D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec2D ) )
		}
		{
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec3D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec3D ) )
		}
		{
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec4D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec4D ) )
		}
		{
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec2D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec2D ) )
		}
		{
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec3D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec3D ) )
		}
		{
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec4D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec4D ) )
		}
		{
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec2D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec2D ) )
		}
		{
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec3D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec3D ) )
		}
		{
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec4D );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec4D ) )
		}
		{
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 1u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == ast::type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 2u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 3u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 4u );
			testCounts << "Type: " << ast::debug::getTypeName( type ) << test::endl;
			testCounts << "Kind: " << ast::debug::getTypeName( type->getKind() ) << test::endl;
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eDouble ) )
		}
		testEnd()
	}
}

testSuiteMain( TestASTBaseTypes )
{
	testSuiteBegin()
	testBase( testCounts );
	testSIntBase( testCounts );
	testUIntBase( testCounts );
	testFloatBase( testCounts );
	testBaseVecSInt( testCounts );
	testBaseVecUInt( testCounts );
	testBaseVecFloat( testCounts );
	testBaseMatrixFloat( testCounts );
	testBaseMatrixDouble( testCounts );
	testGetSampledType( testCounts );
	testGetTexelType( testCounts );
	testBasicFunctions( testCounts );
	testBasicFunctionsSInt( testCounts );
	testBasicFunctionsUInt( testCounts );
	testBasicFunctionsFloat( testCounts );
	testSuiteEnd()
}

testSuiteLaunch( TestASTBaseTypes )
