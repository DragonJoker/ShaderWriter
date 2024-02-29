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

	std::string getName( ast::type::ImageDim dimension )
	{
		switch ( dimension )
		{
		case ast::type::ImageDim::e1D:
			return "1D";
		case ast::type::ImageDim::e2D:
			return "2D";
		case ast::type::ImageDim::e3D:
			return "3D";
		case ast::type::ImageDim::eCube:
			return "Cube";
		case ast::type::ImageDim::eRect:
			return "Rect";
		case ast::type::ImageDim::eBuffer:
			return "Buffer";
		default:
			return "Invalid";
		}
	}

	std::string getName( ast::type::ImageFormat format )
	{
		switch ( format )
		{
		case ast::type::ImageFormat::eUnknown:
			return "Unknown";
		case ast::type::ImageFormat::eRgba32f:
			return "Rgba32f";
		case ast::type::ImageFormat::eRgba16f:
			return "Rgba16f";
		case ast::type::ImageFormat::eRg32f:
			return "Rg32f";
		case ast::type::ImageFormat::eRg16f:
			return "Rg16f";
		case ast::type::ImageFormat::eR32f:
			return "R32f";
		case ast::type::ImageFormat::eR16f:
			return "R16f";
		case ast::type::ImageFormat::eRgba32i:
			return "Rgba32i";
		case ast::type::ImageFormat::eRgba16i:
			return "Rgba16i";
		case ast::type::ImageFormat::eRgba8i:
			return "Rgba8i";
		case ast::type::ImageFormat::eRg32i:
			return "Rg32i";
		case ast::type::ImageFormat::eRg16i:
			return "Rg16i";
		case ast::type::ImageFormat::eRg8i:
			return "Rg8i";
		case ast::type::ImageFormat::eR32i:
			return "R32i";
		case ast::type::ImageFormat::eR16i:
			return "R16i";
		case ast::type::ImageFormat::eR8i:
			return "R8i";
		case ast::type::ImageFormat::eRgba32u:
			return "Rgba32u";
		case ast::type::ImageFormat::eRgba16u:
			return "Rgba16u";
		case ast::type::ImageFormat::eRgba8u:
			return "Rgba8u";
		case ast::type::ImageFormat::eRg32u:
			return "Rg32u";
		case ast::type::ImageFormat::eRg16u:
			return "Rg16u";
		case ast::type::ImageFormat::eRg8u:
			return "Rg8u";
		case ast::type::ImageFormat::eR32u:
			return "R32u";
		case ast::type::ImageFormat::eR16u:
			return "R16u";
		case ast::type::ImageFormat::eR8u:
			return "R8u";
		default:
			return "Invalid";
		}
	}

	std::string getName( ast::type::Trinary isSampled )
	{
		switch ( isSampled )
		{
		case ast::type::Trinary::eFalse:
			return "NSpl";
		case ast::type::Trinary::eTrue:
			return "Spl";
		case ast::type::Trinary::eDontCare:
			return "";
		default:
			return "InvSpl";
		}
	}

	std::string getName( ast::type::AccessKind accessKind )
	{
		switch ( accessKind )
		{
		case ast::type::AccessKind::eRead:
			return "R";
		case ast::type::AccessKind::eWrite:
			return "W";
		case ast::type::AccessKind::eReadWrite:
			return "RW";
		default:
			return "Inv";
		}
	}

	std::string getName( ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		std::string result;
		result += getName( accessKind );
		result += getName( dimension );
		result += getName( format );
		result += getName( isSampled );

		if ( isMS )
			result += "MS";

		if ( isArrayed )
			result += "Array";

		return result;
	}

	ast::type::ImageConfiguration makeConfig( ast::type::TypesCache & typesCache
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		return ast::type::ImageConfiguration{ typesCache.getSampledType( format )->getKind()
			, dimension
			, format
			, isSampled
			, isArrayed
			, isMS
			, accessKind };
	}

	bool operator==( ast::type::ImageConfiguration const & lhs
		, ast::type::ImageConfiguration const & rhs )noexcept
	{
		return lhs.sampledType == rhs.sampledType
			&& lhs.dimension == rhs.dimension
			&& lhs.format == rhs.format
			&& lhs.isSampled == rhs.isSampled
			&& lhs.isArrayed == rhs.isArrayed
			&& lhs.isMS == rhs.isMS
			&& lhs.accessKind == rhs.accessKind;
	}

	void testBase( test::TestCounts & testCounts )
	{
		testBegin( "testBase" );
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getUndefined();
			check( type->getKind() == ast::type::Kind::eUndefined )
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVoid();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBool();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getInt8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getInt16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getInt32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getInt64();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getUInt8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getUInt16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getUInt32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getUInt64();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getHalf();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getFloat();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getDouble();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2B();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3B();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4B();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2I8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3I8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4I8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2I16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3I16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4I16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2I32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3I32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4I32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2I64();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3I64();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4I64();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2U8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3U8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4U8();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2U16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3U16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4U16();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2U32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3U32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4U32();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2U64();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3U64();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4U64();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2H();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4H();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4D();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2x2F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2x3F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2x4F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3x2F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3x3F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3x4F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4x2F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4x3F();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4x4F();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2x2D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2x3D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2x4D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3x2D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3x3D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3x4D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4x2D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4x3D();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4x4D();
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
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eBoolean );
			check( type->getKind() == ast::type::Kind::eBoolean )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eBoolean );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eBoolean ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eBoolean );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eBoolean ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eBoolean );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eBoolean ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eInt8 );
			check( type->getKind() == ast::type::Kind::eInt8 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt8 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt8 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt8 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt8 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt8 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt8 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eInt16 );
			check( type->getKind() == ast::type::Kind::eInt16 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt16 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt16 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt16 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt16 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt16 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt16 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eInt32 );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt32 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt32 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt32 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt32 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt32 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt32 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eInt64 );
			check( type->getKind() == ast::type::Kind::eInt64 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eInt64 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eInt64 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eInt64 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eInt64 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eInt64 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eInt64 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt8 );
			check( type->getKind() == ast::type::Kind::eUInt8 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt8 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt8 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt8 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt8 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt8 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt8 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt16 );
			check( type->getKind() == ast::type::Kind::eUInt16 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt16 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt16 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt16 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt16 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt16 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt16 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt32 );
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt32 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt32 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt32 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt32 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt32 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt32 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eUInt64 );
			check( type->getKind() == ast::type::Kind::eUInt64 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eUInt64 );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eUInt64 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eUInt64 );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eUInt64 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eUInt64 );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eUInt64 ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eHalf );
			check( type->getKind() == ast::type::Kind::eHalf )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eHalf );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eHalf ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eHalf );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eHalf ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eFloat );
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eFloat );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eFloat ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eFloat );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eFloat ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eFloat );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eFloat ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec2F );
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec2F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec3F );
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec3F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec4F );
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec4F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec2F );
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec2F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec3F );
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec3F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec4F );
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec4F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec2F );
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec2F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec3F );
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec3F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec4F );
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec4F ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getBasicType( ast::type::Kind::eDouble );
			check( type->getKind() == ast::type::Kind::eDouble )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec2Type( ast::type::Kind::eDouble );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eDouble ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec3Type( ast::type::Kind::eDouble );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eDouble ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVec4Type( ast::type::Kind::eDouble );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eDouble ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec2D );
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec2D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec3D );
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec3D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat2Type( ast::type::Kind::eVec4D );
			check( type->getKind() == typesCache.getMat2Kind( ast::type::Kind::eVec4D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec2D );
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec2D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec3D );
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec3D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat3Type( ast::type::Kind::eVec4D );
			check( type->getKind() == typesCache.getMat3Kind( ast::type::Kind::eVec4D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec2D );
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec2D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec3D );
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec3D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMat4Type( ast::type::Kind::eVec4D );
			check( type->getKind() == typesCache.getMat4Kind( ast::type::Kind::eVec4D ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 1u );
			check( type->getKind() == ast::type::Kind::eDouble )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 2u );
			check( type->getKind() == typesCache.getVec2Kind( ast::type::Kind::eDouble ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 3u );
			check( type->getKind() == typesCache.getVec3Kind( ast::type::Kind::eDouble ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getVector( ast::type::Kind::eDouble, 4u );
			check( type->getKind() == typesCache.getVec4Kind( ast::type::Kind::eDouble ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getRayDesc();
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
			ast::type::TypesCache typesCache;
			auto type = typesCache.getNonMemberType( typesCache.getInt32() );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eUnknown );
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba32f );
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba16f );
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg32f );
			check( type->getKind() == ast::type::Kind::eVec2F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg16f );
			check( type->getKind() == ast::type::Kind::eVec2F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR32f );
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR16f );
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba32i );
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba16i );
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba8i );
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg32i );
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg16i );
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg8i );
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR32i );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR16i );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR8i );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba32u );
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba16u );
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRgba8u );
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg32u );
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg16u );
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eRg8u );
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR32u );
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR16u );
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getSampledType( ast::type::ImageFormat::eR8u );
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eUnknown );
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba32f );
			check( type->getKind() == ast::type::Kind::eVec4F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba16f );
			check( type->getKind() == ast::type::Kind::eVec4H )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg32f );
			check( type->getKind() == ast::type::Kind::eVec2F )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg16f );
			check( type->getKind() == ast::type::Kind::eVec2H )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR32f );
			check( type->getKind() == ast::type::Kind::eFloat )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR16f );
			check( type->getKind() == ast::type::Kind::eHalf )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba32i );
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba16i );
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba8i );
			check( type->getKind() == ast::type::Kind::eVec4I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg32i );
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg16i );
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg8i );
			check( type->getKind() == ast::type::Kind::eVec2I32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR32i );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR16i );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR8i );
			check( type->getKind() == ast::type::Kind::eInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba32u );
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba16u );
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRgba8u );
			check( type->getKind() == ast::type::Kind::eVec4U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg32u );
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg16u );
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eRg8u );
			check( type->getKind() == ast::type::Kind::eVec2U32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR32u );
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR16u );
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTexelType( ast::type::ImageFormat::eR8u );
			check( type->getKind() == ast::type::Kind::eUInt32 )
		}
		testEnd()
	}

	void testAccelerationStructure( test::TestCounts & testCounts )
	{
		testBegin( "testAccelerationStructure" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getAccelerationStructure();
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
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getArray( typesCache.getInt32(), 18 );
			check( type->getRawKind() == ast::type::Kind::eArray )
			check( type->getKind() == ast::type::Kind::eArray )
			check( type->getType() == typesCache.getInt32() )
			check( type->getArraySize() == 18 )
			check( !isStructType( type ) )
			check( isArrayType( type->getKind() ) )

			auto type2 = typesCache.getArray( typesCache.getInt32(), 18 );
			check( type2 == type )
		}
		testEnd()
	}

	void testCallableData( test::TestCounts & testCounts )
	{
		testBegin( "testCallableData" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getCallableData( typesCache.getInt32(), 17u );
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

	void testImage( test::TestCounts & testCounts
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		testBegin( "testImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS ) );
		ast::type::TypesCache typesCache;
		auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
		auto type = typesCache.getImage( config );
		check( type->getRawKind() == ast::type::Kind::eImage )
		check( type->getKind() == ast::type::Kind::eImage )
		check( type->getConfig() == config )

		auto type2 = typesCache.getImage( config );
		check( type2 == type )
		testEnd()
	}

	void testSampledImage( test::TestCounts & testCounts
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		testBegin( "testSampledImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS ) );
		ast::type::TypesCache typesCache;
		auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
		auto type = typesCache.getSampledImage( config, ast::type::Trinary::eTrue );
		check( type->getRawKind() == ast::type::Kind::eSampledImage )
		check( type->getKind() == ast::type::Kind::eSampledImage )
		check( type->getDepth() == ast::type::Trinary::eTrue )
		check( type->getImageType() == typesCache.getImage( config ) )
		check( type->getConfig() == config )

		auto type2 = typesCache.getSampledImage( config, ast::type::Trinary::eTrue );
		check( type2 == type )
		testEnd()
	}

	void testCombinedImage( test::TestCounts & testCounts
		, ast::type::ImageDim dimension
		, ast::type::ImageFormat format
		, ast::type::Trinary isSampled
		, ast::type::AccessKind accessKind
		, bool isArrayed
		, bool isMS )
	{
		testBegin( "testCombinedImage" + getName( dimension, format, isSampled, accessKind, isArrayed, isMS ) );
		{
			ast::type::TypesCache typesCache;
			auto config = makeConfig( typesCache, dimension, format, isSampled, accessKind, isArrayed, isMS );
			bool isCompare = false;
			auto type = typesCache.getCombinedImage( config, isCompare );
			check( type->getRawKind() == ast::type::Kind::eCombinedImage )
			check( type->getKind() == ast::type::Kind::eCombinedImage )
			check( type->getImageType() == typesCache.getImage( config ) )
			check( type->getSamplerType() == typesCache.getSampler( isCompare ) )
			check( type->getConfig() == config )
			check( type->isComparison() == isCompare )

			auto type2 = typesCache.getCombinedImage( config, isCompare );
			check( type2 == type )
		}
		{
			ast::type::TypesCache typesCache;
			ast::type::ImageConfiguration config{};
			bool isCompare = true;
			auto type = typesCache.getCombinedImage( config, isCompare );
			check( type->getRawKind() == ast::type::Kind::eCombinedImage )
			check( type->getKind() == ast::type::Kind::eCombinedImage )
			check( type->getImageType() == typesCache.getImage( config ) )
			check( type->getSamplerType() == typesCache.getSampler( isCompare ) )
			check( type->getConfig() == config )
			check( type->isComparison() == isCompare )

			auto type2 = typesCache.getCombinedImage( config, isCompare );
			check( type2 == type )
		}
		testEnd()
	}

	void testComputeIO( test::TestCounts & testCounts )
	{
		testBegin( "testComputeIO" );
		ast::type::TypesCache typesCache;
		auto type = ast::type::makeComputeInputType( typesCache.getInt32(), 17u, 18u, 19u );
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
		ast::type::TypesCache typesCache;
		auto type = ast::type::makeFragmentInputType( typesCache.getInt32()
			, ast::FragmentOrigin::eUpperLeft
			, ast::FragmentCenter::eCenterInteger );
		check( type->getRawKind() == ast::type::Kind::eFragmentInput )
		check( type->getKind() == ast::type::Kind::eFragmentInput )
		check( type->getType() == typesCache.getInt32() )
		check( type->getOrigin() == ast::FragmentOrigin::eUpperLeft )
		check( type->getCenter() == ast::FragmentCenter::eCenterInteger )
		check( !isStructType( type ) )
		testEnd()
	}

	void testFunction( test::TestCounts & testCounts )
	{
		testBegin( "testFunction" );
		{
			ast::type::TypesCache typesCache;
			auto type1 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{} );
			check( type1->getRawKind() == ast::type::Kind::eFunction )
			check( type1->getKind() == ast::type::Kind::eFunction )
			check( type1->getReturnType() == typesCache.getVoid() )
			check( type1->size() == 0u )
			check( type1->empty() )
			check( type1->begin() == type1->end() )

			auto p0 = ast::var::makeVariable( 0u, typesCache.getInt32(), "p0" );
			auto type2 = typesCache.getFunction( typesCache.getVoid(), ast::var::VariableList{ p0 } );
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
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeGeometryInputType( typesCache.getInt32()
				, ast::type::InputLayout::eTriangleFan );
			check( type->getRawKind() == ast::type::Kind::eGeometryInput )
			check( type->getKind() == ast::type::Kind::eGeometryInput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getLayout() == ast::type::InputLayout::eTriangleFan )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeGeometryInputType( typesCache.getArray( typesCache.getInt32(), 4u )
				, ast::type::InputLayout::eTriangleFan );
			check( type->getRawKind() == ast::type::Kind::eGeometryInput )
			check( type->getKind() == ast::type::Kind::eGeometryInput )
			check( type->getType() == typesCache.getArray( typesCache.getInt32(), 4u ) )
			check( type->getLayout() == ast::type::InputLayout::eTriangleFan )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeGeometryOutputType( typesCache.getInt32()
				, ast::type::OutputLayout::eLineStrip
				, 15u );
			check( type->getRawKind() == ast::type::Kind::eGeometryOutput )
			check( type->getKind() == ast::type::Kind::eGeometryOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getLayout() == ast::type::OutputLayout::eLineStrip )
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
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadInNV( typesCache.getInt32() );
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadInNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadInType( typesCache.getInt32() );
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadIn( typesCache.getInt32() );
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getKind() == ast::type::Kind::eTaskPayloadIn )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeMeshVertexOutputType( typesCache.getInt32(), 17u );
			check( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getMaxVertices() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMeshVertexOutput( typesCache.getInt32(), 17u );
			check( type->getRawKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getKind() == ast::type::Kind::eMeshVertexOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getMaxVertices() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeMeshPrimitiveOutputType( typesCache.getInt32(), ast::type::OutputTopology::eTriangle, 17u );
			check( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
			check( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getTopology() == ast::type::OutputTopology::eTriangle )
			check( type->getMaxPrimitives() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getMeshPrimitiveOutput( typesCache.getInt32(), ast::type::OutputTopology::eTriangle, 17u );
			check( type->getRawKind() == ast::type::Kind::eMeshPrimitiveOutput )
			check( type->getKind() == ast::type::Kind::eMeshPrimitiveOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getTopology() == ast::type::OutputTopology::eTriangle )
			check( type->getMaxPrimitives() == 17u )
			check( !isStructType( type ) )
		}
		testEnd()
	}

	void testPointer( test::TestCounts & testCounts )
	{
		testBegin( "testPointer" );
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getPointerType( typesCache.getInt32(), ast::type::Storage::eFunction );
			check( !isOpaqueType( type ) )
			auto & pointer = static_cast< ast::type::Pointer const & >( *type );
			check( pointer.getRawKind() == ast::type::Kind::ePointer )
			check( pointer.getKind() == ast::type::Kind::ePointer )
			check( pointer.getPointerType() == typesCache.getInt32() )
			check( pointer.getStorage() == ast::type::Storage::eFunction )
			check( !pointer.isForward() )
			check( !isStructType( pointer ) )
			check( getPointerLevel( type ) == 1u )

			auto & type2 = static_cast< ast::type::Pointer const & >( *typesCache.getPointerType( typesCache.getInt32(), ast::type::Storage::eFunction ) );
			check( &type2 == &pointer )
			check( type2 == pointer )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getForwardPointerType( typesCache.getInt32(), ast::type::Storage::eFunction );
			check( !isOpaqueType( type ) )
			auto & pointer = static_cast< ast::type::Pointer const & >( *type );
			check( pointer.getRawKind() == ast::type::Kind::ePointer )
			check( pointer.getKind() == ast::type::Kind::ePointer )
			check( pointer.getPointerType() == typesCache.getInt32() )
			check( pointer.getStorage() == ast::type::Storage::eFunction )
			check( pointer.isForward() )
			check( !isStructType( pointer ) )
			check( getPointerLevel( type ) == 1u )

			auto & type2 = static_cast< ast::type::Pointer const & >( *typesCache.getForwardPointerType( typesCache.getInt32(), ast::type::Storage::eFunction ) );
			check( &type2 == &pointer )
			check( type2 == pointer )
		}
		testEnd()
	}

	void testRayPayload( test::TestCounts & testCounts )
	{
		testBegin( "testRayPayload" );
		ast::type::TypesCache typesCache;
		auto type = typesCache.getRayPayload( typesCache.getInt32(), 17u );
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
		check( type->getRawKind() == ast::type::Kind::eSampler )
		check( type->getKind() == ast::type::Kind::eSampler )
		check( type->isComparison() )

		auto type2 = typesCache.getSampler( true );
		check( type2 == type )
		testEnd()
	}

	void testStruct( test::TestCounts & testCounts, ast::type::MemoryLayout layout )
	{
		testBegin( "testStruct" + getName( layout ) );
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
			check( !type->hasMember( "test" ) )
			check( !type->hasMember( ast::Builtin::eBaseVertex ) )
			check( type->findMember( "test" ) == ast::type::Struct::NotFound )
			check( type->findMember( ast::Builtin::eBaseVertex ) == ast::type::Struct::NotFound )
			checkThrow( type->getMember( "test" ) )
			checkThrow( type->getMember( ast::Builtin::eBaseVertex ) )
			auto mbrType = typesCache.getInt32()->getMemberType( *type, 0u );
			check( mbrType != typesCache.getInt32() )
			check( mbrType->getNonMemberType() == typesCache.getInt32().get() )

			auto type2 = typesCache.getStruct( layout, "test" );
			check( type == type2 )
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

			auto type2 = typesCache.getIOStruct( "test", entryPoint, flag );
			check( type == type2 )
		}
		testEnd()
	}

	void testTaskIO( test::TestCounts & testCounts )
	{
		testBegin( "testTaskIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadNVType( typesCache.getInt32() );
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayloadNV( typesCache.getInt32() );
			check( type->getRawKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getKind() == ast::type::Kind::eTaskPayloadNV )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTaskPayloadType( typesCache.getInt32() );
			check( type->getRawKind() == ast::type::Kind::eTaskPayload )
			check( type->getKind() == ast::type::Kind::eTaskPayload )
			check( type->getType() == typesCache.getInt32() )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = typesCache.getTaskPayload( typesCache.getInt32() );
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
			check( type->getRawKind() == ast::type::Kind::eTessellationOutputPatch )
			check( type->getKind() == ast::type::Kind::eTessellationOutputPatch )
			check( type->getType() == typesCache.getInt32() )
			check( type->getLocation() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationControlInputType( typesCache.getInt32(), 17u );
			check( type->getRawKind() == ast::type::Kind::eTessellationControlInput )
			check( type->getKind() == ast::type::Kind::eTessellationControlInput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getInputVertices() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationControlOutputType( typesCache.getInt32()
				, ast::type::PatchDomain::eTriangles
				, ast::type::Partitioning::eFractionalEven
				, ast::type::OutputTopology::eTriangle
				, ast::type::PrimitiveOrdering::eCCW
				, 17u );
			check( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
			check( type->getKind() == ast::type::Kind::eTessellationControlOutput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getDomain() == ast::type::PatchDomain::eTriangles )
			check( type->getPartitioning() == ast::type::Partitioning::eFractionalEven )
			check( type->getTopology() == ast::type::OutputTopology::eTriangle )
			check( type->getOrder() == ast::type::PrimitiveOrdering::eCCW )
			check( type->getOutputVertices() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationControlOutputType( typesCache.getArray( typesCache.getInt32(), 4u )
				, ast::type::PatchDomain::eTriangles
				, ast::type::Partitioning::eFractionalEven
				, ast::type::OutputTopology::eTriangle
				, ast::type::PrimitiveOrdering::eCCW
				, 17u );
			check( type->getRawKind() == ast::type::Kind::eTessellationControlOutput )
			check( type->getKind() == ast::type::Kind::eTessellationControlOutput )
			check( type->getType() == typesCache.getArray( typesCache.getInt32(), 4u ) )
			check( type->getDomain() == ast::type::PatchDomain::eTriangles )
			check( type->getPartitioning() == ast::type::Partitioning::eFractionalEven )
			check( type->getTopology() == ast::type::OutputTopology::eTriangle )
			check( type->getOrder() == ast::type::PrimitiveOrdering::eCCW )
			check( type->getOutputVertices() == 17u )
			check( !isStructType( type ) )
		}
		testEnd()
	}

	void testTessellationEvaluationIO( test::TestCounts & testCounts )
	{
		testBegin( "testTessellationEvaluationIO" );
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationInputPatchType( typesCache.getInt32()
				, ast::type::PatchDomain::eTriangles
				, 17u );
			check( type->getRawKind() == ast::type::Kind::eTessellationInputPatch )
			check( type->getKind() == ast::type::Kind::eTessellationInputPatch )
			check( type->getType() == typesCache.getInt32() )
			check( type->getDomain() == ast::type::PatchDomain::eTriangles )
			check( type->getLocation() == 17u )
			check( !isStructType( type ) )
		}
		{
			ast::type::TypesCache typesCache;
			auto type = ast::type::makeTessellationEvaluationInputType( typesCache.getInt32()
				, ast::type::PatchDomain::eTriangles
				, ast::type::Partitioning::eFractionalEven
				, ast::type::PrimitiveOrdering::eCCW
				, 17u );
			check( type->getRawKind() == ast::type::Kind::eTessellationEvaluationInput )
			check( type->getKind() == ast::type::Kind::eTessellationEvaluationInput )
			check( type->getType() == typesCache.getInt32() )
			check( type->getDomain() == ast::type::PatchDomain::eTriangles )
			check( type->getPartitioning() == ast::type::Partitioning::eFractionalEven )
			check( type->getPrimitiveOrdering() == ast::type::PrimitiveOrdering::eCCW )
			check( type->getInputVertices() == 17u )
			check( !isStructType( type ) )
		}
		testEnd()
	}
}

testSuiteMain( TestASTTypes )
{
	testSuiteBegin()
	testBase( testCounts );
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
	testStruct( testCounts, ast::type::MemoryLayout::eStd140 );
	testStruct( testCounts, ast::type::MemoryLayout::eStd430 );
	testStruct( testCounts, ast::type::MemoryLayout::eScalar );
	testStruct( testCounts, ast::type::MemoryLayout::eC );
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
	testTaskIO( testCounts );
	testTessellationControlIO( testCounts );
	testTessellationEvaluationIO( testCounts );

	for ( uint8_t dim = uint8_t( ast::type::ImageDim::eMin ); dim < uint8_t( ast::type::ImageDim::eMax ); ++dim )
	{
		for ( uint8_t fmt = uint8_t( ast::type::ImageFormat::eMin ); fmt < uint8_t( ast::type::ImageFormat::eMax ); ++fmt )
		{
			for ( uint8_t spl = uint8_t( ast::type::Trinary::eMin ); spl < uint8_t( ast::type::Trinary::eMax ); ++spl )
			{
				for ( uint8_t acc = uint8_t( ast::type::AccessKind::eMin ); acc < uint8_t( ast::type::AccessKind::eMax ); ++acc )
				{
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, false );
					testSampledImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, false );
					testCombinedImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, false );
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, true );
					testSampledImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, true );
					testCombinedImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), false, true );
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, false );
					testSampledImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, false );
					testCombinedImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, false );
					testImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, true );
					testSampledImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, true );
					testCombinedImage( testCounts, ast::type::ImageDim( dim ), ast::type::ImageFormat( fmt ), ast::type::Trinary( spl ), ast::type::AccessKind( acc ), true, true );
				}
			}
		}
	}
	testSuiteEnd()
}

testSuiteLaunch( TestASTTypes )
