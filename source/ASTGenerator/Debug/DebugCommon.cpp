/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Debug/DebugCommon.hpp"

#include "ASTGenerator/Expr/Expr.hpp"
#include "ASTGenerator/Stmt/PreprocExtension.hpp"
#include "ASTGenerator/Stmt/StmtInOutVariableDecl.hpp"
#include "ASTGenerator/Type/TypeArray.hpp"
#include "ASTGenerator/Type/TypeImage.hpp"
#include "ASTGenerator/Type/TypeSampledImage.hpp"
#include "ASTGenerator/Type/TypeStruct.hpp"
#include "ASTGenerator/Var/Variable.hpp"

#include <sstream>

namespace ast::debug
{
	namespace
	{
		std::string getName( type::ImageDim value )
		{
			switch ( value )
			{
			case type::ImageDim::e1D:
				return "1D";
			case type::ImageDim::e2D:
				return "2D";
			case type::ImageDim::e3D:
				return "3D";
			case type::ImageDim::eCube:
				return "CUBE";
			case type::ImageDim::eRect:
				return "RECT";
			case type::ImageDim::eBuffer:
				return "BUFFER";
			default:
				assert( false && "Unsupported type::ImageDim" );
				return "Undefined";
			}
		}

		std::string getName( type::Trinary value
			, std::string const & trueTxt = "TRUE"
			, std::string const & falseTxt = "FALSE"
			, std::string const & dontCareTxt = "DONTCARE" )
		{
			switch ( value )
			{
			case type::Trinary::eTrue:
				return trueTxt;
			case type::Trinary::eFalse:
				return falseTxt;
			default:
				return dontCareTxt;
			}
		}

		std::string getName( type::AccessKind value )
		{
			switch ( value )
			{
			case type::AccessKind::eRead:
				return "R";
			case type::AccessKind::eWrite:
				return "W";
			default:
				return "RW";
			}
		}

		std::string getName( bool value
			, std::string const & trueTxt = "TRUE"
			, std::string const & falseTxt = "FALSE" )
		{
			return value
				? trueTxt
				: falseTxt;
		}

		std::string getName( type::ImageConfiguration const & config )
		{
			std::string result;
			result += getName( config.dimension );
			result += "," + debug::getName( config.format );
			result += "," + getName( config.isDepth );
			result += "," + getName( config.isSampled );
			result += "," + getName( config.isArrayed );
			result += "," + getName( config.isMS );
			result += "," + getName( config.accessKind );
			return result;
		}

		std::string getName( type::MemoryLayout value )
		{
			switch ( value )
			{
			case type::MemoryLayout::eStd140:
				return "STD140";
				break;
			case type::MemoryLayout::eStd430:
				return "STD430";
				break;
			default:
				assert( false && "Unsupported type::MemoryLayout" );
				return "Undefined";
			}
		}
	}

	std::string getName( type::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case type::Kind::eUndefined:
			result = "UNDEF";
			break;
		case type::Kind::eVoid:
			result = "VOID";
			break;
		case type::Kind::eStruct:
			result = "STRUCT";
			break;
		case type::Kind::eFunction:
			result = "FUNC";
			break;
		case type::Kind::eBoolean:
			result = "BOOL";
			break;
		case type::Kind::eInt:
			result = "INT";
			break;
		case type::Kind::eUInt:
			result = "UINT";
			break;
		case type::Kind::eFloat:
			result = "FLOAT";
			break;
		case type::Kind::eDouble:
			result = "DOUBLE";
			break;
		case type::Kind::eVec2B:
			result = "BVEC2";
			break;
		case type::Kind::eVec3B:
			result = "BVEC3";
			break;
		case type::Kind::eVec4B:
			result = "BVEC4";
			break;
		case type::Kind::eVec2I:
			result = "IVEC2";
			break;
		case type::Kind::eVec3I:
			result = "IVEC3";
			break;
		case type::Kind::eVec4I:
			result = "IVEC4";
			break;
		case type::Kind::eVec2U:
			result = "UVEC2";
			break;
		case type::Kind::eVec3U:
			result = "UVEC3";
			break;
		case type::Kind::eVec4U:
			result = "UVEC4";
			break;
		case type::Kind::eVec2F:
			result = "FVEC2";
			break;
		case type::Kind::eVec3F:
			result = "FVEC3";
			break;
		case type::Kind::eVec4F:
			result = "FVEC4";
			break;
		case type::Kind::eVec2D:
			result = "DVEC2";
			break;
		case type::Kind::eVec3D:
			result = "DVEC3";
			break;
		case type::Kind::eVec4D:
			result = "DVEC4";
			break;
		case type::Kind::eMat2x2F:
			result = "FMAT2x2";
			break;
		case type::Kind::eMat2x3F:
			result = "FMAT2X3";
			break;
		case type::Kind::eMat2x4F:
			result = "FMAT2X4";
			break;
		case type::Kind::eMat3x2F:
			result = "FMAT3X2";
			break;
		case type::Kind::eMat3x3F:
			result = "FMAT3X3";
			break;
		case type::Kind::eMat3x4F:
			result = "FMAT3X4";
			break;
		case type::Kind::eMat4x2F:
			result = "FMAT4X2";
			break;
		case type::Kind::eMat4x3F:
			result = "FMAT4X3";
			break;
		case type::Kind::eMat4x4F:
			result = "FMAT4X4";
			break;
		case type::Kind::eMat2x2D:
			result = "DMAT2x2";
			break;
		case type::Kind::eMat2x3D:
			result = "DMAT2X3";
			break;
		case type::Kind::eMat2x4D:
			result = "DMAT2X4";
			break;
		case type::Kind::eMat3x2D:
			result = "DMAT3X2";
			break;
		case type::Kind::eMat3x3D:
			result = "DMAT3X3";
			break;
		case type::Kind::eMat3x4D:
			result = "DMAT3X4";
			break;
		case type::Kind::eMat4x2D:
			result = "DMAT4X2";
			break;
		case type::Kind::eMat4x3D:
			result = "DMAT4X3";
			break;
		case type::Kind::eMat4x4D:
			result = "DMAT4X4";
			break;
		case type::Kind::eConstantsBuffer:
			result = "CBUFF";
			break;
		case type::Kind::eShaderBuffer:
			result = "SBUFF";
			break;
		case type::Kind::eImage:
			result = "IMAGE";
			break;
		case type::Kind::eSampler:
			result = "SAMPLER";
			break;
		case type::Kind::eSampledImage:
			result = "SAMPLEDIMG";
			break;
		}

		return result;
	}

	std::string getName( type::TypePtr type )
	{
		return getName( *type );
	}

	std::string computeArray( uint32_t arraySize )
	{
		std::string result;

		if ( arraySize != type::NotArray )
		{
			result += "[";

			if ( arraySize != type::UnknownArraySize )
			{
				result += std::to_string( arraySize );
			}

			result += "]";
		}

		return result;
	}

	std::string getName( type::Kind kind
		, uint32_t arraySize )
	{
		return getName( kind ) + computeArray( arraySize );
	}

	std::string getName( type::ImageFormat value )
	{
		switch ( value )
		{
		case ast::type::ImageFormat::eUnknown:
			return "UNKNOWN";
		case ast::type::ImageFormat::eRgba32f:
			return "RGBA32F";
		case ast::type::ImageFormat::eRgba16f:
			return "RGBA16F";
		case ast::type::ImageFormat::eRg32f:
			return "RG32F";
		case ast::type::ImageFormat::eRg16f:
			return "RG16F";
		case ast::type::ImageFormat::eR32f:
			return "R32F";
		case ast::type::ImageFormat::eR16f:
			return "R16F";
		case ast::type::ImageFormat::eRgba32i:
			return "RGBA32I";
		case ast::type::ImageFormat::eRgba16i:
			return "RGBA16I";
		case ast::type::ImageFormat::eRgba8i:
			return "RGBA8I";
		case ast::type::ImageFormat::eRg32i:
			return "RG32I";
		case ast::type::ImageFormat::eRg16i:
			return "RG16I";
		case ast::type::ImageFormat::eRg8i:
			return "RG8I";
		case ast::type::ImageFormat::eR32i:
			return "R32I";
		case ast::type::ImageFormat::eR16i:
			return "R16I";
		case ast::type::ImageFormat::eR8i:
			return "R8I";
		case ast::type::ImageFormat::eRgba32u:
			return "RGBA32U";
		case ast::type::ImageFormat::eRgba16u:
			return "RGBA16U";
		case ast::type::ImageFormat::eRgba8u:
			return "RGBA8U";
		case ast::type::ImageFormat::eRg32u:
			return "RG32U";
		case ast::type::ImageFormat::eRg16u:
			return "RG16U";
		case ast::type::ImageFormat::eRg8u:
			return "RG8U";
		case ast::type::ImageFormat::eR32u:
			return "R32U";
		case ast::type::ImageFormat::eR16u:
			return "R16U";
		case ast::type::ImageFormat::eR8u:
			return "R8U";
		default:
			assert( false && "Unsupported type::ImageFormat" );
			return "Undefined";
		}
	}

	std::string getName( ast::type::ImageFormat format
		, ast::type::ImageDim dim
		, bool arrayed
		, bool depth
		, bool ms )
	{
		return getName( dim )
			+ getName( format )
			+ getName( arrayed, "Array", "" )
			+ getName( depth, "Shadow", "" )
			+ getName( ms, "MS", "" );
	}

	std::string getName( type::Struct const & type )
	{
		return type.getName()
			+ "," + getName( type.getMemoryLayout() );
	}

	std::string getName( type::Type const & type )
	{
		std::string result;

		switch ( type.getKind() )
		{
		case type::Kind::eArray:
			result = getName( *static_cast< type::Array const & >( type ).getType() );
			result += computeArray( static_cast< type::Array const & >( type ).getArraySize() );
			break;
		case type::Kind::eStruct:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::Struct const & >( type ) ) + ")";
			break;
		case type::Kind::eImage:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::Image const & >( type ).getConfig() ) + ")";
			break;
		case type::Kind::eSampledImage:
			result = getName( getNonArrayKind( type ) );
			result += "(" + getName( static_cast< type::SampledImage const & >( type ).getConfig() ) + ")";
			break;
		default:
			break;
		}

		return result;
	}

	std::string displayVar( ast::var::Variable const & var )
	{
		std::string result = "VAR(";
		std::string sep;

		if ( var.isInputParam() )
		{
			result += sep + "IN";
			sep = ",";
		}

		if ( var.isOutputParam() )
		{
			result += sep + "OUT";
			sep = ",";
		}

		if ( var.isShaderInput() )
		{
			result += sep + "INATTR";
			sep = ",";
		}

		if ( var.isShaderOutput() )
		{
			result += sep + "OUTATTR";
			sep = ",";
		}

		if ( var.isShaderConstant() )
		{
			result += sep + "CONST";
			sep = ",";
		}

		if ( var.isPushConstant() )
		{
			result += sep + "PUSH";
			sep = ",";
		}

		if ( var.isUniform() )
		{
			result += sep + "UNIFORM";
			sep = ",";
		}

		if ( var.isBuiltin() )
		{
			result += sep + "BUILTIN";
			sep = ",";
		}

		if ( var.isImplicit() )
		{
			result += sep + "IMPLICIT";
			sep = ",";
		}

		if ( var.isLocale() )
		{
			result += sep + "LOCALE";
			sep = ",";
		}

		if ( var.isMember() )
		{
			result += sep + "MEMBER";
			sep = ",";
		}

		result += sep + getName( *var.getType() );
		result += ") " + var.getName();
		return result;
	}

	std::string displayVar( ast::var::VariablePtr var )
	{
		return displayVar( *var );
	}
}
