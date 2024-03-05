#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;

	void testBase( test::TestCounts & testCounts )
	{
		astTestBegin( "testBase" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getUndefined();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUndefined )
			astCheck( type->getIndex() == type::NotMember )
			astCheck( type->getParent() == nullptr )
			astCheck( !isWrapperType( *type ) )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isScalarType( type ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isVectorType( type ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isMatrixType( type ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isArrayType( type ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isPointerType( type ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isStructType( type ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSamplerType( type ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isSampledImageType( type ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isImageType( type ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isTextureType( type ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isHitAttributeType( type ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isRayPayloadType( type ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( !isCallableDataType( type ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentCount( type ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
			astCheck( getComponentType( type ) == type->getKind() )
			astCheck( unwrapType( type ) == type )
			astCheck( &unwrapType( *type ) == type.get() )
		}
		{
			auto type = typesCache.getVoid();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVoid )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getBool();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eBoolean )
			astCheck( isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
			astCheck( getScalarType( type->getKind() ) == type->getKind() )
		}
		astTestEnd()
	}

	void testSIntBase( test::TestCounts & testCounts )
	{
		astTestBegin( "testSIntBase" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getInt8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getInt16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getInt32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getInt64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		astTestEnd()
	}

	void testUIntBase( test::TestCounts & testCounts )
	{
		astTestBegin( "testUIntBase" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getUInt8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getUInt16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getUInt32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getUInt64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		astTestEnd()
	}

	void testFloatBase( test::TestCounts & testCounts )
	{
		astTestBegin( "testFloatBase" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getHalf();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eHalf )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getFloat();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eFloat )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		{
			auto type = typesCache.getDouble();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eDouble )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 1u )
			astCheck( getComponentType( type->getKind() ) == type->getKind() )
		}
		astTestEnd()
	}

	void testBaseVecSInt( test::TestCounts & testCounts )
	{
		astTestBegin( "testBaseVecSInt" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getVec2B();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2B )
			astCheck( isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eBoolean )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eVec2 )
		}
		{
			auto type = typesCache.getVec3B();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3B )
			astCheck( isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eBoolean )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eVec3 )
		}
		{
			auto type = typesCache.getVec4B();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4B )
			astCheck( isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eBoolean )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eVec4 )
		}
		{
			auto type = typesCache.getVec2I8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec3I8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3I8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec4I8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec2I16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec3I16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3I16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec4I16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec2I32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec3I32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3I32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec4I32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec2I64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt64 )
		}
		{
			auto type = typesCache.getVec3I64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3I64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt64 )
		}
		{
			auto type = typesCache.getVec4I64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eInt64 )
		}
		astTestEnd()
	}

	void testBaseVecUInt( test::TestCounts & testCounts )
	{
		astTestBegin( "testBaseVecUInt" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getVec2U8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec3U8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3U8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec4U8();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U8 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec2U16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec3U16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3U16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec4U16();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U16 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec2U32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec3U32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3U32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec4U32();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U32 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec2U64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt64 )
		}
		{
			auto type = typesCache.getVec3U64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3U64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt64 )
		}
		{
			auto type = typesCache.getVec4U64();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U64 )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eUInt64 )
		}
		astTestEnd()
	}

	void testBaseVecFloat( test::TestCounts & testCounts )
	{
		astTestBegin( "testBaseVecH" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getVec2H();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2H )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eHalf )
		}
		{
			auto type = typesCache.getVec4H();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4H )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eHalf )
		}
		{
			auto type = typesCache.getVec2F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec3F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec4F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec2D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVec3D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec3D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVec4D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( isVectorType( type->getKind() ) )
			astCheck( !isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eDouble )
		}
		astTestEnd()
	}

	void testBaseMatrixFloat( test::TestCounts & testCounts )
	{
		astTestBegin( "testBaseMatrixFloat" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getMat2x2F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat2x2F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec2F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat2x2 )
		}
		{
			auto type = typesCache.getMat2x3F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat2x3F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec3F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat2x3 )
		}
		{
			auto type = typesCache.getMat2x4F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat2x4F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec4F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat2x4 )
		}
		{
			auto type = typesCache.getMat3x2F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat3x2F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec2F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat3x2 )
		}
		{
			auto type = typesCache.getMat3x3F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat3x3F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec3F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat3x3 )
		}
		{
			auto type = typesCache.getMat3x4F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat3x4F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec4F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat3x4 )
		}
		{
			auto type = typesCache.getMat4x2F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat4x2F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec2F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat4x2 )
		}
		{
			auto type = typesCache.getMat4x3F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat4x3F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec3F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat4x3 )
		}
		{
			auto type = typesCache.getMat4x4F();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat4x4F )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( isFloatType( type->getKind() ) )
			astCheck( !isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec4F )
			astCheck( getCompositeType( type->getKind() ) == expr::CompositeType::eMat4x4 )
		}
		astTestEnd()
	}

	void testBaseMatrixDouble( test::TestCounts & testCounts )
	{
		astTestBegin( "testBaseMatrixDouble" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getMat2x2D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat2x2D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec2D )
			astCheck( getScalarType( type->getKind() ) == type::Kind::eDouble )
		}
		{
			auto type = typesCache.getMat2x3D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat2x3D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec3D )
		}
		{
			auto type = typesCache.getMat2x4D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat2x4D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 2u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec4D )
		}
		{
			auto type = typesCache.getMat3x2D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat3x2D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec2D )
		}
		{
			auto type = typesCache.getMat3x3D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat3x3D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec3D )
		}
		{
			auto type = typesCache.getMat3x4D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat3x4D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 3u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec4D )
		}
		{
			auto type = typesCache.getMat4x2D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat4x2D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec2D )
		}
		{
			auto type = typesCache.getMat4x3D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat4x3D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec3D )
		}
		{
			auto type = typesCache.getMat4x4D();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eMat4x4D )
			astCheck( !isBoolType( type->getKind() ) )
			astCheck( !isUnsignedInt8Type( type->getKind() ) )
			astCheck( !isSignedInt8Type( type->getKind() ) )
			astCheck( !isUnsignedInt16Type( type->getKind() ) )
			astCheck( !isSignedInt16Type( type->getKind() ) )
			astCheck( !isUnsignedInt32Type( type->getKind() ) )
			astCheck( !isSignedInt32Type( type->getKind() ) )
			astCheck( !isUnsignedInt64Type( type->getKind() ) )
			astCheck( !isSignedInt64Type( type->getKind() ) )
			astCheck( !isUnsignedIntType( type->getKind() ) )
			astCheck( !isSignedIntType( type->getKind() ) )
			astCheck( !isHalfType( type->getKind() ) )
			astCheck( !isFloatType( type->getKind() ) )
			astCheck( isDoubleType( type->getKind() ) )
			astCheck( !isScalarType( type->getKind() ) )
			astCheck( !isVectorType( type->getKind() ) )
			astCheck( isMatrixType( type->getKind() ) )
			astCheck( !isArrayType( type->getKind() ) )
			astCheck( !isPointerType( type->getKind() ) )
			astCheck( !isStructType( type->getKind() ) )
			astCheck( !isSamplerType( type->getKind() ) )
			astCheck( !isSampledImageType( type->getKind() ) )
			astCheck( !isImageType( type->getKind() ) )
			astCheck( !isTextureType( type->getKind() ) )
			astCheck( !isAccelerationStructureType( type->getKind() ) )
			astCheck( !isHitAttributeType( type->getKind() ) )
			astCheck( !isRayPayloadType( type->getKind() ) )
			astCheck( !isCallableDataType( type->getKind() ) )
			astCheck( getComponentCount( type->getKind() ) == 4u )
			astCheck( getComponentType( type->getKind() ) == type::Kind::eVec4D )
		}
		astTestEnd()
	}

	void testGetSampledType( test::TestCounts & testCounts )
	{
		astTestBegin( "testGetSampledType" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eUnknown );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba32f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba16f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg32f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2F )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg16f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2F )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR32f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR16f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba32i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba16i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba8i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg32i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg16i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg8i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR32i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR16i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR8i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba32u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba16u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRgba8u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg32u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg16u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eRg8u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR32u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR16u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getSampledType( type::ImageFormat::eR8u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
		}
		astTestEnd()
	}

	void testGetTexelType( test::TestCounts & testCounts )
	{
		astTestBegin( "testGetTexelType" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eUnknown );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba32f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4F )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba16f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4H )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg32f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2F )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg16f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2H )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR32f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR16f );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eHalf )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba32i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba16i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba8i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4I32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg32i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg16i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg8i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2I32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR32i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR16i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR8i );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba32u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba16u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRgba8u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec4U32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg32u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg16u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eRg8u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eVec2U32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR32u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR16u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getTexelType( type::ImageFormat::eR8u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
		}
		astTestEnd()
	}

	void testBasicFunctions( test::TestCounts & testCounts )
	{
		astTestBegin( "testBasicFunctions" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( type::Kind::eBoolean );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eBoolean )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eBoolean );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eBoolean ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eBoolean );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eBoolean ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eBoolean );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eBoolean ) )
		}
		{
			auto type = typesCache.getRayDesc();
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eRayDesc )
			astCheck( type->getMemoryLayout() == type::MemoryLayout::eC )
			astCheck( type->getName() == "RayDesc" )
			astCheck( type->getFlag() == 0u )
			astCheck( type->size() == 4u )
			astCheck( type->getMember( "Origin" ).type->getKind() == type::Kind::eVec3F )
			astCheck( type->getMember( "TMin" ).type->getKind() == type::Kind::eFloat )
			astCheck( type->getMember( "Direction" ).type->getKind() == type::Kind::eVec3F )
			astCheck( type->getMember( "TMax" ).type->getKind() == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getNonMemberType( typesCache.getInt32() );
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		astTestEnd()
	}

	void testBasicFunctionsSInt( test::TestCounts & testCounts )
	{
		astTestBegin( "testBasicFunctionsSInt" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( type::Kind::eInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt8 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eInt8 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eInt8 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eInt8 ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt16 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eInt16 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eInt16 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eInt16 ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt32 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eInt32 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eInt32 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eInt32 ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eInt64 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eInt64 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eInt64 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eInt64 ) )
		}
		astTestEnd()
	}

	void testBasicFunctionsUInt( test::TestCounts & testCounts )
	{
		astTestBegin( "testBasicFunctionsUInt" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( type::Kind::eUInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt8 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eUInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eUInt8 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eUInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eUInt8 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eUInt8 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eUInt8 ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eUInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt16 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eUInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eUInt16 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eUInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eUInt16 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eUInt16 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eUInt16 ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eUInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt32 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eUInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eUInt32 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eUInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eUInt32 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eUInt32 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eUInt32 ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eUInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eUInt64 )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eUInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eUInt64 ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eUInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eUInt64 ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eUInt64 );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eUInt64 ) )
		}
		astTestEnd()
	}

	void testBasicFunctionsFloat( test::TestCounts & testCounts )
	{
		astTestBegin( "testBasicFunctionsFloat" );
		type::TypesCache typesCache;
		{
			auto type = typesCache.getBasicType( type::Kind::eHalf );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eHalf )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eHalf );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eHalf ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eHalf );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eHalf ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eFloat );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eFloat )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eFloat );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eFloat ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eFloat );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eFloat ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eFloat );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eFloat ) )
		}
		{
			auto type = typesCache.getMat2Type( type::Kind::eVec2F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat2Kind( type::Kind::eVec2F ) )
		}
		{
			auto type = typesCache.getMat2Type( type::Kind::eVec3F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat2Kind( type::Kind::eVec3F ) )
		}
		{
			auto type = typesCache.getMat2Type( type::Kind::eVec4F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat2Kind( type::Kind::eVec4F ) )
		}
		{
			auto type = typesCache.getMat3Type( type::Kind::eVec2F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat3Kind( type::Kind::eVec2F ) )
		}
		{
			auto type = typesCache.getMat3Type( type::Kind::eVec3F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat3Kind( type::Kind::eVec3F ) )
		}
		{
			auto type = typesCache.getMat3Type( type::Kind::eVec4F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat3Kind( type::Kind::eVec4F ) )
		}
		{
			auto type = typesCache.getMat4Type( type::Kind::eVec2F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat4Kind( type::Kind::eVec2F ) )
		}
		{
			auto type = typesCache.getMat4Type( type::Kind::eVec3F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat4Kind( type::Kind::eVec3F ) )
		}
		{
			auto type = typesCache.getMat4Type( type::Kind::eVec4F );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat4Kind( type::Kind::eVec4F ) )
		}
		{
			auto type = typesCache.getBasicType( type::Kind::eDouble );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVec2Type( type::Kind::eDouble );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVec3Type( type::Kind::eDouble );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVec4Type( type::Kind::eDouble );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getMat2Type( type::Kind::eVec2D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat2Kind( type::Kind::eVec2D ) )
		}
		{
			auto type = typesCache.getMat2Type( type::Kind::eVec3D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat2Kind( type::Kind::eVec3D ) )
		}
		{
			auto type = typesCache.getMat2Type( type::Kind::eVec4D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat2Kind( type::Kind::eVec4D ) )
		}
		{
			auto type = typesCache.getMat3Type( type::Kind::eVec2D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat3Kind( type::Kind::eVec2D ) )
		}
		{
			auto type = typesCache.getMat3Type( type::Kind::eVec3D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat3Kind( type::Kind::eVec3D ) )
		}
		{
			auto type = typesCache.getMat3Type( type::Kind::eVec4D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat3Kind( type::Kind::eVec4D ) )
		}
		{
			auto type = typesCache.getMat4Type( type::Kind::eVec2D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat4Kind( type::Kind::eVec2D ) )
		}
		{
			auto type = typesCache.getMat4Type( type::Kind::eVec3D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat4Kind( type::Kind::eVec3D ) )
		}
		{
			auto type = typesCache.getMat4Type( type::Kind::eVec4D );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getMat4Kind( type::Kind::eVec4D ) )
		}
		{
			auto type = typesCache.getVector( type::Kind::eDouble, 1u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == type::Kind::eDouble )
		}
		{
			auto type = typesCache.getVector( type::Kind::eDouble, 2u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec2Kind( type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVector( type::Kind::eDouble, 3u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec3Kind( type::Kind::eDouble ) )
		}
		{
			auto type = typesCache.getVector( type::Kind::eDouble, 4u );
			astCheckNoThrow( debug::getTypeName( type ) )
			astCheckNoThrow( debug::getTypeName( type->getKind() ) )
			astCheck( type->getKind() == typesCache.getVec4Kind( type::Kind::eDouble ) )
		}
		astTestEnd()
	}
}

astTestSuiteMain( TestASTBaseTypes )
{
	astTestSuiteBegin()
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
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTBaseTypes )
