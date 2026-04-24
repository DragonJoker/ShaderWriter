/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/UniformBuffer.hpp"

#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"
#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>

namespace sdw
{
	UniformBuffer::UniformBuffer( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_builder{ writer.getBuilder() }
		, m_buffer{ static_cast< type::UniformBuffer * >( getNonArrayType( m_expr->getType() ) ) }
	{
	}

	StructInstance UniformBuffer::declStructMember( std::string name
		, Struct const & s
		, bool enabled )
	{
		auto & writer = findWriterMandat( *this );
		auto [type, added, mbrIndex] = m_buffer->registerMember( name, s.getType() );
		return StructInstance{ writer
			, makeMbrSelect( mbrIndex )
			, isEnabled() && enabled };
	}

	Array< StructInstance > UniformBuffer::declStructMember( std::string name
		, Struct const & s
		, uint32_t dimension
		, bool enabled )
	{
		auto & writer = findWriterMandat( *this );
		auto [type, added, mbrIndex] = m_buffer->registerMember( name, s.getType(), dimension );
		return Array< StructInstance >{ writer
			, makeMbrSelect( mbrIndex )
			, isEnabled() && enabled };
	}

	expr::ExprPtr UniformBuffer::makeMbrSelect( uint32_t mbrIndex )const
	{
		auto & writer = findWriterMandat( *this );
		auto ident = findIdentifier( *m_expr );
		auto mbrType = m_buffer->getDataType()->getMember( mbrIndex );
		auto mbrVar = registerMember( writer, ident->getVariable(), mbrType.name, mbrType.type );
		return makeExpr( writer, mbrVar );
	}

	expr::ExprPtr UniformBuffer::makeMbrSelect( std::string_view name )const
	{
		auto & writer = findWriterMandat( *this );
		auto ident = findIdentifier( *m_expr );
		auto mbrVar = getMemberVariable( writer, ident->getVariable(), name );
		return makeExpr( writer, mbrVar );
	}

	ast::type::UniformBufferPtr UniformBuffer::makeType( ast::type::TypesCache & cache
		, std::string const & name
		, ast::type::MemoryLayout layout )
	{
		return cache.getUniformBuffer( name, layout );
	}
}
