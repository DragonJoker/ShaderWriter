/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslHelpers.hpp"

#include "ASTGenerator/Type/TypeImage.hpp"

namespace sdw::glsl
{
	std::string getTypeName( type::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case type::Kind::eUndefined:
			result = "undefined";
			break;
		case type::Kind::eVoid:
			result = "void";
			break;
		case type::Kind::eStruct:
			result = "struct";
			break;
		case type::Kind::eFunction:
			result = "function";
			break;
		case type::Kind::eBoolean:
			result = "bool";
			break;
		case type::Kind::eInt:
			result = "int";
			break;
		case type::Kind::eUInt:
			result = "uint";
			break;
		case type::Kind::eFloat:
			result = "float";
			break;
		case type::Kind::eDouble:
			result = "double";
			break;
		case type::Kind::eVec2B:
			result = "bvec2";
			break;
		case type::Kind::eVec3B:
			result = "bvec3";
			break;
		case type::Kind::eVec4B:
			result = "bvec4";
			break;
		case type::Kind::eVec2I:
			result = "ivec2";
			break;
		case type::Kind::eVec3I:
			result = "ivec3";
			break;
		case type::Kind::eVec4I:
			result = "ivec4";
			break;
		case type::Kind::eVec2U:
			result = "uvec2";
			break;
		case type::Kind::eVec3U:
			result = "uvec3";
			break;
		case type::Kind::eVec4U:
			result = "uvec4";
			break;
		case type::Kind::eVec2F:
			result = "vec2";
			break;
		case type::Kind::eVec3F:
			result = "vec3";
			break;
		case type::Kind::eVec4F:
			result = "vec4";
			break;
		case type::Kind::eVec2D:
			result = "dvec2";
			break;
		case type::Kind::eVec3D:
			result = "dvec3";
			break;
		case type::Kind::eVec4D:
			result = "dvec4";
			break;
		case type::Kind::eMat2x2F:
			result = "mat2";
			break;
		case type::Kind::eMat2x3F:
			result = "mat2x3";
			break;
		case type::Kind::eMat2x4F:
			result = "mat2x4";
			break;
		case type::Kind::eMat3x3F:
			result = "mat3";
			break;
		case type::Kind::eMat3x2F:
			result = "mat3x2";
			break;
		case type::Kind::eMat3x4F:
			result = "mat3x4";
			break;
		case type::Kind::eMat4x4F:
			result = "mat4";
			break;
		case type::Kind::eMat4x2F:
			result = "mat4x2";
			break;
		case type::Kind::eMat4x3F:
			result = "mat4x3";
			break;
		case type::Kind::eMat2x2D:
			result = "dmat2";
			break;
		case type::Kind::eMat2x3D:
			result = "dmat2x3";
			break;
		case type::Kind::eMat2x4D:
			result = "dmat2x4";
			break;
		case type::Kind::eMat3x3D:
			result = "dmat3";
			break;
		case type::Kind::eMat3x2D:
			result = "dmat3x2";
			break;
		case type::Kind::eMat3x4D:
			result = "dmat3x4";
			break;
		case type::Kind::eMat4x4D:
			result = "dmat4";
			break;
		case type::Kind::eMat4x2D:
			result = "dmat4x2";
			break;
		case type::Kind::eMat4x3D:
			result = "dmat4x3";
			break;
		case type::Kind::eConstantsBuffer:
			result = "uniform";
			break;
		case type::Kind::eShaderBuffer:
			result = "buffer";
			break;
		case type::Kind::eImage:
			result = "image";
			break;
		case type::Kind::eSampler:
			result = "sampler";
			break;
		case type::Kind::eSampledImage:
			result = "sampledImage";
			break;
		}

		return result;
	}

	std::string getName( type::ImageDim value )
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
			assert( false && "Unsupported type::ImageDim" );
			result = "Undefined";
			break;
		}

		return result;
	}

	std::string getTypeName( type::ImagePtr type )
	{
		std::string result;
		auto & config = type->getConfig();

		if ( config.isSampled == type::Trinary::eTrue )
		{
			result += "sampler";
		}
		else
		{
			result += "image";
		}

		result += getName( config.dimension );

		if ( config.isArrayed )
		{
			result += "Array";
		}

		if ( config.isDepth == type::Trinary::eTrue )
		{
			assert( config.isSampled == type::Trinary::eTrue );
			result += "Shadow";
		}

		return result;
	}

	std::string getTypeName( type::TypePtr type )
	{
		std::string result;

		switch ( type->getKind() )
		{
		case type::Kind::eStruct:
			result = static_cast< type::Struct const & >( *type ).getName();
			break;
		case type::Kind::eImage:
			result = getTypeName( std::static_pointer_cast< type::Image >( type ) );
			break;
		default:
			result = getTypeName( type->getKind() );
			break;
		}

		return result;
	}

	std::string getLocationName( var::Variable const & var )
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

	std::string getDirectionName( var::Variable const & var )
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

	std::string getStatusName( stmt::PreprocExtension::Status status )
	{
		std::string result;

		switch ( status )
		{
		case stmt::PreprocExtension::Status::eDisabled:
			result = "disable";
			break;

		case stmt::PreprocExtension::Status::eEnabled:
			result = "enable";
			break;

		case stmt::PreprocExtension::Status::eRequired:
			result = "required";
			break;

		}

		return result;
	}

	std::string getOperatorName( expr::Kind kind )
	{
		std::string result;

		switch ( kind )
		{
		case expr::Kind::eAdd:
			result = "+";
			break;
		case expr::Kind::eMinus:
			result = "-";
			break;
		case expr::Kind::eTimes:
			result = "*";
			break;
		case expr::Kind::eDivide:
			result = "/";
			break;
		case expr::Kind::eModulo:
			result = "%";
			break;
		case expr::Kind::eLShift:
			result = "<<";
			break;
		case expr::Kind::eRShift:
			result = ">>";
			break;
		case expr::Kind::eBitAnd:
			result = "&";
			break;
		case expr::Kind::eBitNot:
			result = "~";
			break;
		case expr::Kind::eBitOr:
			result = "|";
			break;
		case expr::Kind::eBitXor:
			result = "^";
			break;
		case expr::Kind::eLogAnd:
			result = "&&";
			break;
		case expr::Kind::eLogNot:
			result = "!";
			break;
		case expr::Kind::eLogOr:
			result = "||";
			break;
		case expr::Kind::eCast:
			result = "cast";
			break;
		case expr::Kind::eEqual:
			result = "==";
			break;
		case expr::Kind::eGreater:
			result = ">";
			break;
		case expr::Kind::eGreaterEqual:
			result = ">=";
			break;
		case expr::Kind::eLess:
			result = "<";
			break;
		case expr::Kind::eLessEqual:
			result = "<=";
			break;
		case expr::Kind::eNotEqual:
			result = "!=";
			break;
		case expr::Kind::eComma:
			result = ",";
			break;
		case expr::Kind::eMbrSelect:
			result = ".";
			break;
		case expr::Kind::ePreIncrement:
			result = "++";
			break;
		case expr::Kind::ePreDecrement:
			result = "--";
			break;
		case expr::Kind::ePostIncrement:
			result = "++";
			break;
		case expr::Kind::ePostDecrement:
			result = "--";
			break;
		case expr::Kind::eUnaryMinus:
			result = "-";
			break;
		case expr::Kind::eUnaryPlus:
			result = "+";
			break;
		case expr::Kind::eAssign:
			result = "=";
			break;
		case expr::Kind::eAddAssign:
			result = "+=";
			break;
		case expr::Kind::eMinusAssign:
			result = "-=";
			break;
		case expr::Kind::eTimesAssign:
			result = "*=";
			break;
		case expr::Kind::eDivideAssign:
			result = "/=";
			break;
		case expr::Kind::eModuloAssign:
			result = "%=";
			break;
		case expr::Kind::eLShiftAssign:
			result = "<<=";
			break;
		case expr::Kind::eRShiftAssign:
			result = ">>=";
			break;
		case expr::Kind::eAndAssign:
			result = "&=";
			break;
		case expr::Kind::eNotAssign:
			result = "!=";
			break;
		case expr::Kind::eOrAssign:
			result = "|=";
			break;
		case expr::Kind::eXorAssign:
			result = "^=";
			break;
		default:
			throw std::runtime_error{ "Non operation expression" };
		}

		return result;
	}

	std::string getLayoutName( stmt::InputLayout layout )
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

	std::string getLayoutName( stmt::OutputLayout layout )
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

	bool isUnaryPre( expr::Kind kind )
	{
		bool result;

		switch ( kind )
		{
		case expr::Kind::eMbrSelect:
		case expr::Kind::ePostIncrement:
		case expr::Kind::ePostDecrement:
			result = false;
			break;
		case expr::Kind::eBitNot:
		case expr::Kind::eLogNot:
		case expr::Kind::eCast:
		case expr::Kind::ePreIncrement:
		case expr::Kind::ePreDecrement:
		case expr::Kind::eUnaryMinus:
		case expr::Kind::eUnaryPlus:
			result = true;
			break;
		default:
			throw std::runtime_error{ "Non unary expression" };
		}

		return result;
	}
}
