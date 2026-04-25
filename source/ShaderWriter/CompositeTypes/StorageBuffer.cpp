/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/StorageBuffer.hpp"

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	//*********************************************************************************************

	StorageBuffer::StorageBuffer( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, m_buffer{ static_cast< type::StorageBuffer * >( getNonArrayType( m_expr->getType() ) ) }
		, m_var{ findIdentifier( *m_expr )->getVariable() }
	{
	}

	StructInstance StorageBuffer::declStructMember( std::string name
		, Struct const & s
		, bool enabled )
	{
		auto & writer = findWriterMandat( *this );
		auto [type, added, mbrIndex] = m_buffer->registerMember( name, s.getType() );
		return StructInstance{ writer
			, makeMbrSelect( mbrIndex )
			, isEnabled() && enabled };
	}

	Array< StructInstance > StorageBuffer::declStructMember( std::string name
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

	expr::ExprPtr StorageBuffer::makeMbrSelect( uint32_t mbrIndex )const
	{
		return sdw::makeMbrSelect( makeExpr( *this ), 0u, m_var->getFlags() );
	}

	expr::ExprPtr StorageBuffer::makeMbrSelect( std::string_view name )const
	{
		return sdw::makeMbrSelect( makeExpr( *this ), 0u, m_var->getFlags() );
	}

	ast::type::StorageBufferPtr StorageBuffer::makeType( ast::type::TypesCache & cache
		, std::string const & name
		, ast::type::MemoryLayout layout
		, bool isArray )
	{
		return cache.getStorageBuffer( name, layout, isArray );
	}

	ast::type::StorageBufferPtr makeStorageBufferType( ast::type::TypesCache & cache
		, std::string const & name
		, ast::type::MemoryLayout layout
		, bool isArray )
	{
		return StorageBuffer::makeType( cache, name, layout, isArray );
	}

	//*********************************************************************************************
}
