/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLiteral.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Literal::Literal( bool value )
		: Expr{ std::move( type::getBool() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eBool }
	{
		m_value.boolv = value;
	}

	Literal::Literal( int32_t value )
		: Expr{ std::move( type::getInt() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eInt }
	{
		m_value.intv = value;
	}

	Literal::Literal( uint32_t value )
		: Expr{ std::move( type::getUInt() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eUInt }
	{
		m_value.uintv = value;
	}

	Literal::Literal( float value )
		: Expr{ std::move( type::getFloat() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eFloat }
	{
		m_value.floatv = value;
	}

	Literal::Literal( double value )
		: Expr{ std::move( type::getDouble() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eDouble }
	{
		m_value.doublev = value;
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
			return makeLiteral( !operand.getValue< LiteralType::eBool >() );
		case LiteralType::eInt:
			return makeLiteral( ~operand.getValue< LiteralType::eInt >() );
		case LiteralType::eUInt:
			return makeLiteral( ~operand.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eBool >() | rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( int32_t( lhs.getValue< LiteralType::eBool >() ) | rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( uint32_t( lhs.getValue< LiteralType::eBool >() ) | rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() | int32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() | rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() | rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() | uint32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() | rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() | rhs.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eBool >() & rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( int32_t( lhs.getValue< LiteralType::eBool >() ) & rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( uint32_t( lhs.getValue< LiteralType::eBool >() ) & rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() & int32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() & rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() & rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() & uint32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() & rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() & rhs.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eBool >() ^ rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( int32_t( lhs.getValue< LiteralType::eBool >() ) ^ rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( uint32_t( lhs.getValue< LiteralType::eBool >() ) ^ rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() ^ int32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() ^ rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() ^ rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() ^ uint32_t( rhs.getValue< LiteralType::eBool >() ) );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() ^ rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() ^ rhs.getValue< LiteralType::eUInt >() );
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
			return makeLiteral( !operand.getValue< LiteralType::eBool >() );
		case LiteralType::eInt:
			return makeLiteral( !operand.getValue< LiteralType::eInt >() );
		case LiteralType::eUInt:
			return makeLiteral( !operand.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eBool >() || rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() || rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() || rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() || rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() || rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() || rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() || rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() || rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() || rhs.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eBool >() && rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() && rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() && rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() && rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() && rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() && rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() && rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() && rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() && rhs.getValue< LiteralType::eUInt >() );
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
			return makeLiteral( !operand.getValue< LiteralType::eBool >() );
		case LiteralType::eInt:
			return makeLiteral( -operand.getValue< LiteralType::eInt >() );
		case LiteralType::eFloat:
			return makeLiteral( -operand.getValue< LiteralType::eFloat >() );
		case LiteralType::eDouble:
			return makeLiteral( -operand.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() + rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() + rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() + rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() + rhs.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() - rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() - rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() - rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() - rhs.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() * rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() * rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() * rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() * rhs.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() / rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() / rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() / rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() / rhs.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() % rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() % rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() % rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() % rhs.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() << rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() << rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() << rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() << rhs.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() >> rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() >> rhs.getValue< LiteralType::eUInt >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() >> rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() >> rhs.getValue< LiteralType::eUInt >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eBool >() == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eInt >() ) );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eFloat >() ) );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() == bool( rhs.getValue< LiteralType::eDouble >() ) );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eInt >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() == rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eUInt >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() == rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eFloat >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() == rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eDouble >() ) == rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() == rhs.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eBool >() != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eInt >() ) );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eFloat >() ) );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eBool >() != bool( rhs.getValue< LiteralType::eDouble >() ) );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eInt >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() != rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eUInt >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() != rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eFloat >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() != rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eBool:
				return makeLiteral( bool( lhs.getValue< LiteralType::eDouble >() ) != rhs.getValue< LiteralType::eBool >() );
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() != rhs.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() < int64_t( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() < rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( int64_t( lhs.getValue< LiteralType::eUInt >() ) < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() < rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() < rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() < rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() < rhs.getValue< LiteralType::eDouble >() );
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
				return makeLiteral( lhs.getValue< LiteralType::eInt >() > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() > int64_t( rhs.getValue< LiteralType::eUInt >() ) );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eInt >() > rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eUInt:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( int64_t( lhs.getValue< LiteralType::eUInt >() ) > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() > rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eUInt >() > rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eFloat:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eFloat >() > rhs.getValue< LiteralType::eDouble >() );
			default:
				assert( false && "Unexpected operand for bit negate" );
				return nullptr;
			}
		case LiteralType::eDouble:
			switch ( rhs.getLiteralType() )
			{
			case LiteralType::eInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eInt >() );
			case LiteralType::eUInt:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eUInt >() );
			case LiteralType::eFloat:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eFloat >() );
			case LiteralType::eDouble:
				return makeLiteral( lhs.getValue< LiteralType::eDouble >() > rhs.getValue< LiteralType::eDouble >() );
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
