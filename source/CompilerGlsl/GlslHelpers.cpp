/*
See LICENSE file in root folder
*/
#include "GlslHelpers.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

#include <stdexcept>

namespace glsl
{
	std::string getTypeName( ast::type::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case ast::type::Kind::eUndefined:
			result = "undefined";
			break;
		case ast::type::Kind::eVoid:
			result = "void";
			break;
		case ast::type::Kind::eStruct:
			result = "struct";
			break;
		case ast::type::Kind::eFunction:
			result = "function";
			break;
		case ast::type::Kind::eBoolean:
			result = "bool";
			break;
		case ast::type::Kind::eInt:
			result = "int";
			break;
		case ast::type::Kind::eUInt:
			result = "uint";
			break;
		case ast::type::Kind::eFloat:
			result = "float";
			break;
		case ast::type::Kind::eDouble:
			result = "double";
			break;
		case ast::type::Kind::eVec2B:
			result = "bvec2";
			break;
		case ast::type::Kind::eVec3B:
			result = "bvec3";
			break;
		case ast::type::Kind::eVec4B:
			result = "bvec4";
			break;
		case ast::type::Kind::eVec2I:
			result = "ivec2";
			break;
		case ast::type::Kind::eVec3I:
			result = "ivec3";
			break;
		case ast::type::Kind::eVec4I:
			result = "ivec4";
			break;
		case ast::type::Kind::eVec2U:
			result = "uvec2";
			break;
		case ast::type::Kind::eVec3U:
			result = "uvec3";
			break;
		case ast::type::Kind::eVec4U:
			result = "uvec4";
			break;
		case ast::type::Kind::eVec2F:
			result = "vec2";
			break;
		case ast::type::Kind::eVec3F:
			result = "vec3";
			break;
		case ast::type::Kind::eVec4F:
			result = "vec4";
			break;
		case ast::type::Kind::eVec2D:
			result = "dvec2";
			break;
		case ast::type::Kind::eVec3D:
			result = "dvec3";
			break;
		case ast::type::Kind::eVec4D:
			result = "dvec4";
			break;
		case ast::type::Kind::eMat2x2F:
			result = "mat2";
			break;
		case ast::type::Kind::eMat2x3F:
			result = "mat2x3";
			break;
		case ast::type::Kind::eMat2x4F:
			result = "mat2x4";
			break;
		case ast::type::Kind::eMat3x3F:
			result = "mat3";
			break;
		case ast::type::Kind::eMat3x2F:
			result = "mat3x2";
			break;
		case ast::type::Kind::eMat3x4F:
			result = "mat3x4";
			break;
		case ast::type::Kind::eMat4x4F:
			result = "mat4";
			break;
		case ast::type::Kind::eMat4x2F:
			result = "mat4x2";
			break;
		case ast::type::Kind::eMat4x3F:
			result = "mat4x3";
			break;
		case ast::type::Kind::eMat2x2D:
			result = "dmat2";
			break;
		case ast::type::Kind::eMat2x3D:
			result = "dmat2x3";
			break;
		case ast::type::Kind::eMat2x4D:
			result = "dmat2x4";
			break;
		case ast::type::Kind::eMat3x3D:
			result = "dmat3";
			break;
		case ast::type::Kind::eMat3x2D:
			result = "dmat3x2";
			break;
		case ast::type::Kind::eMat3x4D:
			result = "dmat3x4";
			break;
		case ast::type::Kind::eMat4x4D:
			result = "dmat4";
			break;
		case ast::type::Kind::eMat4x2D:
			result = "dmat4x2";
			break;
		case ast::type::Kind::eMat4x3D:
			result = "dmat4x3";
			break;
		case ast::type::Kind::eImage:
			result = "image";
			break;
		case ast::type::Kind::eSampler:
			result = "sampler";
			break;
		case ast::type::Kind::eSampledImage:
			result = "sampledImage";
			break;
		default:
			assert( false && "Unsupported type::Kind" );
			break;
		}

		return result;
	}

	std::string getName( ast::type::ImageDim value )
	{
		std::string result;

		switch ( value )
		{
		case ast::type::ImageDim::e1D:
			result = "1D";
			break;
		case ast::type::ImageDim::e2D:
			result = "2D";
			break;
		case ast::type::ImageDim::e3D:
			result = "3D";
			break;
		case ast::type::ImageDim::eCube:
			result = "Cube";
			break;
		case ast::type::ImageDim::eRect:
			result = "2DRect";
			break;
		case ast::type::ImageDim::eBuffer:
			result = "Buffer";
			break;
		default:
			assert( false && "Unsupported ast::type::ImageDim" );
			result = "Undefined";
			break;
		}

		return result;
	}

	std::string getTypeName( ast::type::ImagePtr type )
	{
		std::string result;
		auto & config = type->getConfig();
		result += "image";
		result += getName( config.dimension );

		if ( config.isArrayed )
		{
			result += "Array";
		}

		if ( config.isDepth == ast::type::Trinary::eTrue )
		{
			assert( config.isSampled == ast::type::Trinary::eTrue );
			result += "Shadow";
		}

		return result;
	}

	std::string getTypeName( ast::type::SampledImagePtr type )
	{
		std::string result;
		auto config = type->getConfig();
		result += "sampler";
		result += getName( config.dimension );

		if ( config.isArrayed )
		{
			result += "Array";
		}

		if ( config.isDepth == ast::type::Trinary::eTrue )
		{
			assert( config.isSampled == ast::type::Trinary::eTrue );
			result += "Shadow";
		}

		return result;
	}

	std::string getTypeName( ast::type::TypePtr type )
	{
		std::string result;

		switch ( type->getKind() )
		{
		case ast::type::Kind::eStruct:
			result = static_cast< ast::type::Struct const & >( *type ).getName();
			break;
		case ast::type::Kind::eImage:
			result = getTypeName( std::static_pointer_cast< ast::type::Image >( type ) );
			break;
		case ast::type::Kind::eSampledImage:
			result = getTypeName( std::static_pointer_cast< ast::type::SampledImage >( type ) );
			break;
		case ast::type::Kind::eArray:
			result = getTypeName( std::static_pointer_cast< ast::type::Array >( type )->getType() );
			break;
		default:
			result = getTypeName( type->getKind() );
			break;
		}

		return result;
	}

	std::string getTypeArraySize( ast::type::TypePtr type );

	std::string getTypeArraySize( ast::type::ArrayPtr type )
	{
		std::string result;
		auto arraySize = getArraySize( type );

		if ( arraySize != ast::type::NotArray )
		{
			if ( arraySize == ast::type::UnknownArraySize )
			{
				result += "[]";
			}
			else
			{
				result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		return getTypeArraySize( type->getType() ) + result;
	}

	std::string getTypeArraySize( ast::type::TypePtr type )
	{
		std::string result;

		if ( type->getKind() == ast::type::Kind::eArray )
		{
			result = getTypeArraySize( std::static_pointer_cast< ast::type::Array >( type ) );
		}

		return result;
	}

	std::string getFlatnessName( ast::var::Variable const & var )
	{
		std::string result;

		if ( var.isFlat() )
		{
			result = "flat ";
		}

		return result;
	}

	std::string getLocationName( ast::var::Variable const & var )
	{
		std::string result;

		if ( var.isShaderConstant() )
		{
			result = "constant_id";
		}
		else if ( var.isShaderInput()
			|| var.isShaderOutput() )
		{
			result = "location";
		}

		return result;
	}

	std::string getDirectionName( ast::var::Variable const & var )
	{
		std::string result;

		if ( var.isInputParam()
			&& var.isOutputParam() )
		{
			result = "inout";
		}
		else if ( var.isInputParam()
			|| var.isShaderInput() )
		{
			result = "in";
		}
		else if ( var.isOutputParam()
			|| var.isShaderOutput() )
		{
			result = "out";
		}
		else if ( var.isShaderConstant() )
		{
			result = "const";
		}

		return result;
	}

	std::string getStatusName( ast::stmt::PreprocExtension::Status status )
	{
		std::string result;

		switch ( status )
		{
		case ast::stmt::PreprocExtension::Status::eDisabled:
			result = "disable";
			break;

		case ast::stmt::PreprocExtension::Status::eEnabled:
			result = "enable";
			break;

		case ast::stmt::PreprocExtension::Status::eRequired:
			result = "require";
			break;

		}

		return result;
	}

	std::string getOperatorName( ast::expr::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case ast::expr::Kind::eAdd:
			result = "+";
			break;
		case ast::expr::Kind::eMinus:
			result = "-";
			break;
		case ast::expr::Kind::eTimes:
			result = "*";
			break;
		case ast::expr::Kind::eDivide:
			result = "/";
			break;
		case ast::expr::Kind::eModulo:
			result = "%";
			break;
		case ast::expr::Kind::eLShift:
			result = "<<";
			break;
		case ast::expr::Kind::eRShift:
			result = ">>";
			break;
		case ast::expr::Kind::eBitAnd:
			result = "&";
			break;
		case ast::expr::Kind::eBitNot:
			result = "~";
			break;
		case ast::expr::Kind::eBitOr:
			result = "|";
			break;
		case ast::expr::Kind::eBitXor:
			result = "^";
			break;
		case ast::expr::Kind::eLogAnd:
			result = "&&";
			break;
		case ast::expr::Kind::eLogNot:
			result = "!";
			break;
		case ast::expr::Kind::eLogOr:
			result = "||";
			break;
		case ast::expr::Kind::eCast:
			result = "cast";
			break;
		case ast::expr::Kind::eEqual:
			result = "==";
			break;
		case ast::expr::Kind::eGreater:
			result = ">";
			break;
		case ast::expr::Kind::eGreaterEqual:
			result = ">=";
			break;
		case ast::expr::Kind::eLess:
			result = "<";
			break;
		case ast::expr::Kind::eLessEqual:
			result = "<=";
			break;
		case ast::expr::Kind::eNotEqual:
			result = "!=";
			break;
		case ast::expr::Kind::eComma:
			result = ",";
			break;
		case ast::expr::Kind::eMbrSelect:
			result = ".";
			break;
		case ast::expr::Kind::ePreIncrement:
			result = "++";
			break;
		case ast::expr::Kind::ePreDecrement:
			result = "--";
			break;
		case ast::expr::Kind::ePostIncrement:
			result = "++";
			break;
		case ast::expr::Kind::ePostDecrement:
			result = "--";
			break;
		case ast::expr::Kind::eUnaryMinus:
			result = "-";
			break;
		case ast::expr::Kind::eUnaryPlus:
			result = "+";
			break;
		case ast::expr::Kind::eAssign:
			result = "=";
			break;
		case ast::expr::Kind::eAddAssign:
			result = "+=";
			break;
		case ast::expr::Kind::eMinusAssign:
			result = "-=";
			break;
		case ast::expr::Kind::eTimesAssign:
			result = "*=";
			break;
		case ast::expr::Kind::eDivideAssign:
			result = "/=";
			break;
		case ast::expr::Kind::eModuloAssign:
			result = "%=";
			break;
		case ast::expr::Kind::eLShiftAssign:
			result = "<<=";
			break;
		case ast::expr::Kind::eRShiftAssign:
			result = ">>=";
			break;
		case ast::expr::Kind::eAndAssign:
			result = "&=";
			break;
		case ast::expr::Kind::eNotAssign:
			result = "!=";
			break;
		case ast::expr::Kind::eOrAssign:
			result = "|=";
			break;
		case ast::expr::Kind::eXorAssign:
			result = "^=";
			break;
		default:
			throw std::runtime_error{ "Non operation expression" };
		}

		return result;
	}

	std::string getLayoutName( ast::stmt::InputLayout layout )
	{
		std::string result;

		switch ( layout )
		{
		case ast::stmt::InputLayout::ePointList:
			result = "points";
			break;
		case ast::stmt::InputLayout::eLineList:
			result = "lines";
			break;
		case ast::stmt::InputLayout::eLineStrip:
			result = "lines";
			break;
		case ast::stmt::InputLayout::eTriangleList:
			result = "triangles";
			break;
		case ast::stmt::InputLayout::eTriangleStrip:
			result = "triangles";
			break;
		case ast::stmt::InputLayout::eTriangleFan:
			result = "triangles";
			break;
		case ast::stmt::InputLayout::eLineListWithAdjacency:
			result = "lines_adjacency";
			break;
		case ast::stmt::InputLayout::eLineStripWithAdjacency:
			result = "lines_adjacency";
			break;
		case ast::stmt::InputLayout::eTriangleListWithAdjacency:
			result = "triangles_adjacency";
			break;
		case ast::stmt::InputLayout::eTriangleStripWithAdjacency:
			result = "triangles_adjacency";
			break;
		default:
			throw std::runtime_error{ "Unsupported input layout." };
		}

		return result;
	}

	std::string getLayoutName( ast::stmt::OutputLayout layout )
	{
		std::string result;

		switch ( layout )
		{
		case ast::stmt::OutputLayout::ePointList:
			result = "points";
			break;
		case ast::stmt::OutputLayout::eLineStrip:
			result = "line_strip";
			break;
		case ast::stmt::OutputLayout::eTriangleStrip:
			result = "triangle_strip";
			break;
		default:
			throw std::runtime_error{ "Unsupported output layout." };
		}

		return result;
	}

	std::string getCtorName( ast::expr::CompositeType composite
		, ast::type::Kind component )
	{
		std::string result;

		switch ( composite )
		{
		case ast::expr::CompositeType::eVec2:
			switch ( component )
			{
			case ast::type::Kind::eBoolean:
				result = "bvec2";
				break;
			case ast::type::Kind::eInt:
				result = "ivec2";
				break;
			case ast::type::Kind::eUInt:
				result = "uvec2";
				break;
			case ast::type::Kind::eFloat:
				result = "vec2";
				break;
			case ast::type::Kind::eDouble:
				result = "dvec2";
				break;
			case ast::type::Kind::eHalf:
				result = "hvec2";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eVec3:
			switch ( component )
			{
			case ast::type::Kind::eBoolean:
				result = "bvec3";
				break;
			case ast::type::Kind::eInt:
				result = "ivec3";
				break;
			case ast::type::Kind::eUInt:
				result = "uvec3";
				break;
			case ast::type::Kind::eFloat:
				result = "vec3";
				break;
			case ast::type::Kind::eDouble:
				result = "dvec3";
				break;
			case ast::type::Kind::eHalf:
				result = "hvec3";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eVec4:
			switch ( component )
			{
			case ast::type::Kind::eBoolean:
				result = "bvec4";
				break;
			case ast::type::Kind::eInt:
				result = "ivec4";
				break;
			case ast::type::Kind::eUInt:
				result = "uvec4";
				break;
			case ast::type::Kind::eFloat:
				result = "vec4";
				break;
			case ast::type::Kind::eDouble:
				result = "dvec4";
				break;
			case ast::type::Kind::eHalf:
				result = "hvec4";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat2x2:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat2";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat2";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat2x3:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat2x3";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat2x3";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat2x4:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat2x4";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat2x4";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat3x2:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat3x2";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat3x2";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat3x3:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat3";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat3";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat3x4:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat3x4";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat3x4";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat4x2:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat4x2";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat4x2";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat4x3:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat4x3";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat4x3";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		case ast::expr::CompositeType::eMat4x4:
			switch ( component )
			{
			case ast::type::Kind::eFloat:
				result = "mat4";
				break;
			case ast::type::Kind::eDouble:
				result = "dmat4";
				break;
			default:
				assert( false && "Unsupported type::Kind" );
				break;
			}
			break;
		default:
			assert( false && "Unsupported expr::CompositeType" );
			break;
		}

		return result;
	}

	bool isUnaryPre( ast::expr::Kind kind )
	{
		bool result;

		switch ( kind )
		{
		case ast::expr::Kind::eMbrSelect:
		case ast::expr::Kind::ePostIncrement:
		case ast::expr::Kind::ePostDecrement:
			result = false;
			break;
		case ast::expr::Kind::eBitNot:
		case ast::expr::Kind::eLogNot:
		case ast::expr::Kind::eCast:
		case ast::expr::Kind::ePreIncrement:
		case ast::expr::Kind::ePreDecrement:
		case ast::expr::Kind::eUnaryMinus:
		case ast::expr::Kind::eUnaryPlus:
			result = true;
			break;
		default:
			throw std::runtime_error{ "Non unary expression" };
		}

		return result;
	}
}
