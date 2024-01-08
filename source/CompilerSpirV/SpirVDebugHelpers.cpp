/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/SpirVDebugHelpers.hpp"

#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeCache.hpp>

namespace spirv::debug
{
	ValueIdList convert( DebugIdList const & in )
	{
		ValueIdList result{ in.get_allocator() };
		result.reserve( in.size() );

		for ( auto & v : in )
		{
			result.push_back( v.debug );
		}

		return result;
	}

	uint32_t getSize( ast::type::Kind kind )
	{
		if ( kind == ast::type::Kind::eVoid )
		{
			return 0u;
		}

		uint32_t mult = 1u;

		while ( !isScalarType( kind ) )
		{
			mult *= getComponentCount( kind );
			kind = getComponentType( kind );
		}

		switch ( kind )
		{
		case ast::type::Kind::eDouble:
		case ast::type::Kind::eInt64:
		case ast::type::Kind::eUInt64:
			return mult * 64u;
		case ast::type::Kind::eFloat:
		case ast::type::Kind::eInt32:
		case ast::type::Kind::eUInt32:
			return mult * 32u;
		case ast::type::Kind::eInt16:
		case ast::type::Kind::eUInt16:
		case ast::type::Kind::eHalf:
			return mult * 16u;
		case ast::type::Kind::eBoolean:
		case ast::type::Kind::eInt8:
		case ast::type::Kind::eUInt8:
			return mult * 8u;
		default:
			AST_Failure( "Unsupported type::Kind" );
			return 0u;
		}
	}

	uint32_t getEncoding( ast::type::Kind kind )
	{
		if ( kind == ast::type::Kind::eVoid )
		{
			return uint32_t( spv::NonSemanticShaderDebugInfo100DebugBaseTypeAttributeEncoding::Unspecified );
		}

		while ( !isScalarType( kind ) )
		{
			kind = getComponentType( kind );
		}

		switch ( kind )
		{
		case ast::type::Kind::eHalf:
		case ast::type::Kind::eFloat:
		case ast::type::Kind::eDouble:
			return uint32_t( spv::NonSemanticShaderDebugInfo100DebugBaseTypeAttributeEncoding::Float );
		case ast::type::Kind::eUInt8:
		case ast::type::Kind::eInt16:
		case ast::type::Kind::eInt32:
		case ast::type::Kind::eInt64:
			return uint32_t( spv::NonSemanticShaderDebugInfo100DebugBaseTypeAttributeEncoding::Signed );
		case ast::type::Kind::eInt8:
		case ast::type::Kind::eUInt16:
		case ast::type::Kind::eUInt32:
		case ast::type::Kind::eUInt64:
			return uint32_t( spv::NonSemanticShaderDebugInfo100DebugBaseTypeAttributeEncoding::Unsigned );
		case ast::type::Kind::eBoolean:
			return uint32_t( spv::NonSemanticShaderDebugInfo100DebugBaseTypeAttributeEncoding::Boolean );
		default:
			AST_Failure( "Unsupported type::Kind" );
			return uint32_t( spv::NonSemanticShaderDebugInfo100DebugBaseTypeAttributeEncoding::Unspecified );
		}
	}

	uint32_t getFlags( uint64_t varFlags )
	{
		uint32_t result{};

		if ( varFlags & uint64_t( ast::var::Flag::eLocale ) )
		{
			result |= uint32_t( spv::NonSemanticShaderDebugInfo100DebugInfoFlags::IsLocal );
		}

		return result;
	}
}
