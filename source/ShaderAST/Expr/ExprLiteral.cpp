/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLiteral.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Literal::Literal( type::TypePtr type, bool value )
		: Expr{ std::move( type ), Kind::eLiteral }
		, m_valueType{ LiteralType::eBool }
	{
		m_value.boolv = value;
	}

	Literal::Literal( type::TypePtr type, int32_t value )
		: Expr{ std::move( type ), Kind::eLiteral }
		, m_valueType{ LiteralType::eInt }
	{
		m_value.intv = value;
	}

	Literal::Literal( type::TypePtr type, uint32_t value )
		: Expr{ std::move( type ), Kind::eLiteral }
		, m_valueType{ LiteralType::eUInt }
	{
		m_value.uintv = value;
	}

	Literal::Literal( type::TypePtr type, float value )
		: Expr{ std::move( type ), Kind::eLiteral }
		, m_valueType{ LiteralType::eFloat }
	{
		m_value.floatv = value;
	}

	Literal::Literal( type::TypePtr type, double value )
		: Expr{ std::move( type ), Kind::eLiteral }
		, m_valueType{ LiteralType::eDouble }
	{
		m_value.doublev = value;
	}

	Literal::Literal( type::TypesCache & cache, bool value )
		: Literal{ std::move( cache.getBool() ), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, int32_t value )
		: Literal{ std::move( cache.getInt() ), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, uint32_t value )
		: Literal{ std::move( cache.getUInt() ), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, float value )
		: Literal{ std::move( cache.getFloat() ), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, double value )
		: Literal{ std::move( cache.getDouble() ), value }
	{
	}

	void Literal::accept( VisitorPtr vis )
	{
		vis->visitLiteralExpr( this );
	}

	LiteralPtr operator~( Literal const & operand )
	{
		switch ( operand.getLiteralType() )
		{
		case LiteralType::eBool:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, !operand.getValue< LiteralType::eBool >() );
		case LiteralType::eInt:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, ~operand.getValue< LiteralType::eInt >() );
		case LiteralType::eUInt:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, ~operand.getValue< LiteralType::eUInt >() );
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator|( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eBool:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() | rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, int32_t( lhs.getValue< LiteralType::eBool >() ) | rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, uint32_t( lhs.getValue< LiteralType::eBool >() ) | rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() | int32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() | rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() | rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() | uint32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() | rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() | rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator&( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eBool:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() & rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, int32_t( lhs.getValue< LiteralType::eBool >() ) & rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, uint32_t( lhs.getValue< LiteralType::eBool >() ) & rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() & int32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() & rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() & rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() & uint32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() & rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() & rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator^( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eBool:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() ^ rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, int32_t( lhs.getValue< LiteralType::eBool >() ) ^ rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( rhs.getType()->getCache()
					, uint32_t( lhs.getValue< LiteralType::eBool >() ) ^ rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() ^ int32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() ^ rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() ^ rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() ^ uint32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() ^ rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() ^ rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator!( Literal const & operand )
	{
		switch ( operand.getLiteralType() )
		{
		case LiteralType::eBool:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, !operand.getValue< LiteralType::eBool >() );
		case LiteralType::eInt:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, !operand.getValue< LiteralType::eInt >() );
		case LiteralType::eUInt:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, !operand.getValue< LiteralType::eUInt >() );
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator||( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eBool:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() || rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() || rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() || rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() || rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() || rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() || rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() || rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() || rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() || rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator&&( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eBool:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() && rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() && rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() && rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() && rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() && rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() && rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() && rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() && rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() && rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator-( Literal const & operand )
	{
		switch ( operand.getLiteralType() )
		{
		case LiteralType::eBool:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, !operand.getValue< LiteralType::eBool >() );
		case LiteralType::eInt:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, -operand.getValue< LiteralType::eInt >() );
		case LiteralType::eFloat:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, -operand.getValue< LiteralType::eFloat >() );
		case LiteralType::eDouble:
			return std::make_unique< Literal >( operand.getType()->getCache()
				, -operand.getValue< LiteralType::eDouble >() );
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator+( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator-( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator*( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator/( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator%( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() % rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() % rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() % rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() % rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator<<( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() << rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() << rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() << rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() << rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator>>( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() >> rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() >> rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() >> rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() >> rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator==( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eBool:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eInt >() ) );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eFloat >() ) );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eDouble >() ) );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eInt >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eUInt >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eFloat >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eDouble >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator!=( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eBool:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eInt >() ) );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eFloat >() ) );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eDouble >() ) );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eInt >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eUInt >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eFloat >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, bool( lhs.getValue< LiteralType::eDouble >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator<( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() < int64_t( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() < rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, int64_t( lhs.getValue< LiteralType::eUInt >() ) < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() < rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() < rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator<=( Literal const & lhs, Literal const & rhs )
	{
		return !( *( lhs > rhs ) );
	}

	LiteralPtr operator>( Literal const & lhs, Literal const & rhs )
	{
		switch ( lhs.getLiteralType() )
		{
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() > int64_t( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eInt >() > rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, int64_t( lhs.getValue< LiteralType::eUInt >() ) > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() > rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eUInt >() > rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return std::make_unique< Literal >( lhs.getType()->getCache()
					, lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		default:
			assert( false && "Unexpected operand for bit negate" );
			return nullptr;
		}
	}

	LiteralPtr operator>=( Literal const & lhs, Literal const & rhs )
	{
		return !( *( lhs < rhs ) );
	}
}
