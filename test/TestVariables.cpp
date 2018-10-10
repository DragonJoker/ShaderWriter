#include "Common.hpp"

#include <ASTGenerator/Var/Variable.hpp>

namespace
{
	std::string getTypeName( ast::TypePtr type )
	{
		std::string result;

		switch ( type->getKind() )
		{
		case ast::Type::Kind::eUndefined:
			result = "undefined";
			break;
		case ast::Type::Kind::eFunction:
			result = "function";
			break;
		case ast::Type::Kind::eBoolean:
			result = "bool";
			break;
		case ast::Type::Kind::eInt:
			result = "int";
			break;
		case ast::Type::Kind::eUInt:
			result = "uint";
			break;
		case ast::Type::Kind::eFloat:
			result = "float";
			break;
		case ast::Type::Kind::eVec2B:
			result = "bvec2";
			break;
		case ast::Type::Kind::eVec3B:
			result = "bvec3";
			break;
		case ast::Type::Kind::eVec4B:
			result = "bvec4";
			break;
		case ast::Type::Kind::eVec2I:
			result = "ivec2";
			break;
		case ast::Type::Kind::eVec3I:
			result = "ivec3";
			break;
		case ast::Type::Kind::eVec4I:
			result = "ivec4";
			break;
		case ast::Type::Kind::eVec2UI:
			result = "uivec2";
			break;
		case ast::Type::Kind::eVec3UI:
			result = "uivec3";
			break;
		case ast::Type::Kind::eVec4UI:
			result = "uivec4";
			break;
		case ast::Type::Kind::eVec2F:
			result = "vec2";
			break;
		case ast::Type::Kind::eVec3F:
			result = "vec3";
			break;
		case ast::Type::Kind::eVec4F:
			result = "vec4";
			break;
		case ast::Type::Kind::eMat2x2B:
			result = "bmat2";
			break;
		case ast::Type::Kind::eMat3x3B:
			result = "bmat3";
			break;
		case ast::Type::Kind::eMat4x4B:
			result = "bmat4";
			break;
		case ast::Type::Kind::eMat2x2I:
			result = "imat2";
			break;
		case ast::Type::Kind::eMat3x3I:
			result = "imat3";
			break;
		case ast::Type::Kind::eMat4x4I:
			result = "imat4";
			break;
		case ast::Type::Kind::eMat2x2UI:
			result = "uimat2";
			break;
		case ast::Type::Kind::eMat3x3UI:
			result = "uimat3";
			break;
		case ast::Type::Kind::eMat4x4UI:
			result = "uimat4";
			break;
		case ast::Type::Kind::eMat2x2F:
			result = "mat2";
			break;
		case ast::Type::Kind::eMat3x3F:
			result = "mat3";
			break;
		case ast::Type::Kind::eMat4x4F:
			result = "mat4";
			break;
		case ast::Type::Kind::eConstantsBuffer:
			result = "uniform";
			break;
		case ast::Type::Kind::eShaderBuffer:
			result = "buffer";
			break;
		case ast::Type::Kind::eSamplerBuffer:
			result = "samplerBuffer";
			break;
		case ast::Type::Kind::eSampler1D:
			result = "sampler1D";
			break;
		case ast::Type::Kind::eSampler2D:
			result = "sampler2D";
			break;
		case ast::Type::Kind::eSampler3D:
			result = "sampler3D";
			break;
		case ast::Type::Kind::eSamplerCube:
			result = "samplerCube";
			break;
		case ast::Type::Kind::eSampler2DRect:
			result = "sampler2DRect";
			break;
		case ast::Type::Kind::eSampler1DArray:
			result = "sampler1DArray";
			break;
		case ast::Type::Kind::eSampler2DArray:
			result = "sampler2DArray";
			break;
		case ast::Type::Kind::eSamplerCubeArray:
			result = "samplerCubeArray";
			break;
		case ast::Type::Kind::eSampler1DShadow:
			result = "sampler1DShadow";
			break;
		case ast::Type::Kind::eSampler2DShadow:
			result = "sampler2DShadow";
			break;
		case ast::Type::Kind::eSamplerCubeShadow:
			result = "samplerCubeShadow";
			break;
		case ast::Type::Kind::eSampler2DRectShadow:
			result = "sampler2DRectArrayShadow";
			break;
		case ast::Type::Kind::eSampler1DArrayShadow:
			result = "sampler1DArrayShadow";
			break;
		case ast::Type::Kind::eSampler2DArrayShadow:
			result = "sampler2DArrayShadow";
			break;
		case ast::Type::Kind::eSamplerCubeArrayShadow:
			result = "samplerCubeArrayShadow";
			break;
		}

		return result;
	}

	std::string printVariable( ast::Variable const & var )
	{
		std::string result;
		result += getTypeName( var.getType() ) + " " + var.getName();
		auto arraySize = var.getType()->getArraySize();

		if ( arraySize != ast::Type::NotArray )
		{
			if ( arraySize == ast::Type::UnknownArraySize )
			{
				result += "[]";
			}
			else
			{
				result += "[" + std::to_string( arraySize ) + "]";
			}
		}

		return result;
	}

	void testVariable()
	{
		testBegin( "testVariable" );
		for ( uint8_t i = uint8_t( ast::Type::Kind::eMin ); i < uint8_t( ast::Type::Kind::eCount ); ++i )
		{
			ast::Variable dummyVar{ ast::makeType( ast::Type::Kind( i ) ), "dummyVar" };
			std::cout << printVariable( dummyVar ) << std::endl;
			check( dummyVar.getType()->getKind() == ast::Type::Kind( i ) );
			check( dummyVar.getType()->getArraySize() == ast::Type::NotArray );
			check( dummyVar.getName() == "dummyVar" );
		}

		for ( uint8_t i = uint8_t( ast::Type::Kind::eMin ); i < uint8_t( ast::Type::Kind::eCount ); ++i )
		{
			ast::Variable dummyVar{ ast::makeType( ast::Type::Kind( i ), ast::Type::UnknownArraySize ), "dummyVar" };
			std::cout << printVariable( dummyVar ) << std::endl;
			check( dummyVar.getType()->getKind() == ast::Type::Kind( i ) );
			check( dummyVar.getType()->getArraySize() == ast::Type::UnknownArraySize );
			check( dummyVar.getName() == "dummyVar" );
		}

		for ( uint8_t i = uint8_t( ast::Type::Kind::eMin ); i < uint8_t( ast::Type::Kind::eCount ); ++i )
		{
			ast::Variable dummyVar{ ast::makeType( ast::Type::Kind( i ), 3u ), "dummyVar" };
			std::cout << printVariable( dummyVar ) << std::endl;
			check( dummyVar.getType()->getKind() == ast::Type::Kind( i ) );
			check( dummyVar.getType()->getArraySize() == 3u );
			check( dummyVar.getName() == "dummyVar" );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestVariables" );
	testVariable();
	testSuiteEnd();
}
