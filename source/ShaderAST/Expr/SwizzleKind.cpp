#include "ShaderAST/Expr/SwizzleKind.hpp"

#include "ShaderAST/Shader.hpp"

namespace ast::expr
{
	namespace
	{
#if !defined( NDEBUG )
		bool isValid( SwizzleKind::Value value )
		{
			return value == SwizzleKind::e0
				|| value == SwizzleKind::e1
				|| value == SwizzleKind::e2
				|| value == SwizzleKind::e3;
		}

		bool isValid( SwizzleKind const & value )
		{
			auto count = value.getComponentsCount();
			return isValid( value.getFirstValue() )
				&& ( count < 2u || isValid( value.getSecondValue() ) )
				&& ( count < 3u || isValid( value.getThirdValue() ) )
				&& ( count < 4u || isValid( value.getFourthValue() ) );
		}
#endif

		SwizzleKind::Value operator|( SwizzleKind::Value lhs, SwizzleKind::Value rhs )
		{
			return SwizzleKind::Value( uint16_t( lhs ) | uint16_t( rhs ) );
		}

		SwizzleKind::Value operator&( SwizzleKind::Value lhs, SwizzleKind::Value rhs )
		{
			return SwizzleKind::Value( uint16_t( lhs ) & uint16_t( rhs ) );
		}

		SwizzleKind::Value operator<<( SwizzleKind::Value lhs, uint32_t rhs )
		{
			return SwizzleKind::Value( uint16_t( lhs ) << rhs );
		}
	}

	SwizzleKind::SwizzleKind( SwizzleKind::Value value )
		: m_value{ value }
	{
		assert( m_value == eUndefined
			|| isValid( *this ) );
	}

	SwizzleKind SwizzleKind::fromOffset( uint32_t offset )
	{
		assert( offset < 4u );
		return SwizzleKind( Value( ( 0x01 << offset ) << eShiftFourthComponentToFirst ) );
	}

	uint32_t SwizzleKind::getComponentsCount()const
	{
		return ( m_value & eMaskOneComponent ) == m_value
			? 1u
			: ( ( m_value & eMaskTwoComponents ) == m_value
				? 2u
				: ( ( m_value & eMaskThreeComponents ) == m_value
					? 3u
					: 4u ) );
	}

	bool SwizzleKind::isOneComponent()const
	{
		return getComponentsCount() == 1u;
	}

	uint32_t SwizzleKind::toIndex()const
	{
		assert( isOneComponent()
			 && "Can't get index of non single component" );

		return ( m_value & e0 ) == m_value
			? 0u
			: ( ( m_value & e1 ) == m_value
				? 1u
				: ( ( m_value & e2 ) == m_value
					? 2u
					: 3u ) );
	}

	bool SwizzleKind::isTwoComponents()const
	{
		return getComponentsCount() == 2u;
	}

	bool SwizzleKind::isThreeComponents()const
	{
		return getComponentsCount() == 3u;
	}

	bool SwizzleKind::isFourComponents()const
	{
		return getComponentsCount() == 4u;
	}

	SwizzleKind::Value SwizzleKind::getFirstValue()const
	{
		return m_value & eMaskFirstComponent;
	}

	SwizzleKind::Value SwizzleKind::getSecondValue()const
	{
		assert( !isOneComponent()
			&& "Invalid swizzle for second component search" );

		return ( m_value & eMaskSecondComponent )
			<< uint32_t( eShiftSecondComponentToFirst );
	}

	SwizzleKind::Value SwizzleKind::getThirdValue()const
	{
		assert( !isOneComponent()
			&& !isTwoComponents()
			&& "Invalid swizzle for third component search" );

		return ( m_value & eMaskThirdComponent )
			<< uint32_t( eShiftThirdComponentToFirst );
	}

	SwizzleKind::Value SwizzleKind::getFourthValue()const
	{
		assert( !isOneComponent()
			&& !isTwoComponents()
			&& !isThreeComponents()
			&& "Invalid swizzle for fourth component search" );

		return ( m_value & eMaskFourthComponent )
			<< uint32_t( eShiftFourthComponentToFirst );
	}

	SwizzleKind SwizzleKind::operator[]( uint32_t index )const
	{
		assert( index < getComponentsCount()
			&& "Out of bounds array access to swizzle" );

		return SwizzleKind{ ( m_value << ( index * 4u ) ) & eMaskFirstComponent };
	}

	SwizzleKind & SwizzleKind::operator|=( SwizzleKind const & rhs )
	{
		m_value = m_value | rhs.m_value;
		assert( isValid( *this ) );
		return *this;
	}

	std::string getName( SwizzleKind kind )
	{
		std::string result;

		switch ( kind.getValue() )
		{
		case expr::SwizzleKind::e0:
			result = "x";
			break;
		case expr::SwizzleKind::e1:
			result = "y";
			break;
		case expr::SwizzleKind::e2:
			result = "z";
			break;
		case expr::SwizzleKind::e3:
			result = "w";
			break;
		case expr::SwizzleKind::e00:
			result = "xx";
			break;
		case expr::SwizzleKind::e01:
			result = "xy";
			break;
		case expr::SwizzleKind::e02:
			result = "xz";
			break;
		case expr::SwizzleKind::e03:
			result = "xw";
			break;
		case expr::SwizzleKind::e10:
			result = "yx";
			break;
		case expr::SwizzleKind::e11:
			result = "yy";
			break;
		case expr::SwizzleKind::e12:
			result = "yz";
			break;
		case expr::SwizzleKind::e13:
			result = "yw";
			break;
		case expr::SwizzleKind::e20:
			result = "zx";
			break;
		case expr::SwizzleKind::e21:
			result = "zy";
			break;
		case expr::SwizzleKind::e22:
			result = "zz";
			break;
		case expr::SwizzleKind::e23:
			result = "zw";
			break;
		case expr::SwizzleKind::e30:
			result = "wx";
			break;
		case expr::SwizzleKind::e31:
			result = "wy";
			break;
		case expr::SwizzleKind::e32:
			result = "wz";
			break;
		case expr::SwizzleKind::e33:
			result = "ww";
			break;
		case expr::SwizzleKind::e000:
			result = "xxx";
			break;
		case expr::SwizzleKind::e001:
			result = "xxy";
			break;
		case expr::SwizzleKind::e002:
			result = "xxz";
			break;
		case expr::SwizzleKind::e003:
			result = "xxw";
			break;
		case expr::SwizzleKind::e010:
			result = "xyx";
			break;
		case expr::SwizzleKind::e011:
			result = "xyy";
			break;
		case expr::SwizzleKind::e012:
			result = "xyz";
			break;
		case expr::SwizzleKind::e013:
			result = "xyw";
			break;
		case expr::SwizzleKind::e020:
			result = "xzx";
			break;
		case expr::SwizzleKind::e021:
			result = "xzy";
			break;
		case expr::SwizzleKind::e022:
			result = "xzz";
			break;
		case expr::SwizzleKind::e023:
			result = "xzw";
			break;
		case expr::SwizzleKind::e030:
			result = "xwx";
			break;
		case expr::SwizzleKind::e031:
			result = "xwy";
			break;
		case expr::SwizzleKind::e032:
			result = "xwz";
			break;
		case expr::SwizzleKind::e033:
			result = "xww";
			break;
		case expr::SwizzleKind::e100:
			result = "yxx";
			break;
		case expr::SwizzleKind::e101:
			result = "yxy";
			break;
		case expr::SwizzleKind::e102:
			result = "yxz";
			break;
		case expr::SwizzleKind::e103:
			result = "yxw";
			break;
		case expr::SwizzleKind::e110:
			result = "yyx";
			break;
		case expr::SwizzleKind::e111:
			result = "yyy";
			break;
		case expr::SwizzleKind::e112:
			result = "yyz";
			break;
		case expr::SwizzleKind::e113:
			result = "yyw";
			break;
		case expr::SwizzleKind::e120:
			result = "yzx";
			break;
		case expr::SwizzleKind::e121:
			result = "yzy";
			break;
		case expr::SwizzleKind::e122:
			result = "yzz";
			break;
		case expr::SwizzleKind::e123:
			result = "yzw";
			break;
		case expr::SwizzleKind::e130:
			result = "ywx";
			break;
		case expr::SwizzleKind::e131:
			result = "ywy";
			break;
		case expr::SwizzleKind::e132:
			result = "ywz";
			break;
		case expr::SwizzleKind::e133:
			result = "yww";
			break;
		case expr::SwizzleKind::e200:
			result = "zxx";
			break;
		case expr::SwizzleKind::e201:
			result = "zxy";
			break;
		case expr::SwizzleKind::e202:
			result = "zxz";
			break;
		case expr::SwizzleKind::e203:
			result = "zxw";
			break;
		case expr::SwizzleKind::e210:
			result = "zyx";
			break;
		case expr::SwizzleKind::e211:
			result = "zyy";
			break;
		case expr::SwizzleKind::e212:
			result = "zyz";
			break;
		case expr::SwizzleKind::e213:
			result = "zyw";
			break;
		case expr::SwizzleKind::e220:
			result = "zzx";
			break;
		case expr::SwizzleKind::e221:
			result = "zzy";
			break;
		case expr::SwizzleKind::e222:
			result = "zzz";
			break;
		case expr::SwizzleKind::e223:
			result = "zzw";
			break;
		case expr::SwizzleKind::e230:
			result = "zwx";
			break;
		case expr::SwizzleKind::e231:
			result = "zwy";
			break;
		case expr::SwizzleKind::e232:
			result = "zwz";
			break;
		case expr::SwizzleKind::e233:
			result = "zww";
			break;
		case expr::SwizzleKind::e300:
			result = "wxx";
			break;
		case expr::SwizzleKind::e301:
			result = "wxy";
			break;
		case expr::SwizzleKind::e302:
			result = "wxz";
			break;
		case expr::SwizzleKind::e303:
			result = "wxw";
			break;
		case expr::SwizzleKind::e310:
			result = "wyx";
			break;
		case expr::SwizzleKind::e311:
			result = "wyy";
			break;
		case expr::SwizzleKind::e312:
			result = "wyz";
			break;
		case expr::SwizzleKind::e313:
			result = "wyw";
			break;
		case expr::SwizzleKind::e320:
			result = "wzx";
			break;
		case expr::SwizzleKind::e321:
			result = "wzy";
			break;
		case expr::SwizzleKind::e322:
			result = "wzz";
			break;
		case expr::SwizzleKind::e323:
			result = "wzw";
			break;
		case expr::SwizzleKind::e330:
			result = "wwx";
			break;
		case expr::SwizzleKind::e331:
			result = "wwy";
			break;
		case expr::SwizzleKind::e332:
			result = "wwz";
			break;
		case expr::SwizzleKind::e333:
			result = "www";
			break;
		case expr::SwizzleKind::e0000:
			result = "xxxx";
			break;
		case expr::SwizzleKind::e0001:
			result = "xxxy";
			break;
		case expr::SwizzleKind::e0002:
			result = "xxxz";
			break;
		case expr::SwizzleKind::e0003:
			result = "xxxw";
			break;
		case expr::SwizzleKind::e0010:
			result = "xxyx";
			break;
		case expr::SwizzleKind::e0011:
			result = "xxyy";
			break;
		case expr::SwizzleKind::e0012:
			result = "xxyz";
			break;
		case expr::SwizzleKind::e0013:
			result = "xxyw";
			break;
		case expr::SwizzleKind::e0020:
			result = "xxzx";
			break;
		case expr::SwizzleKind::e0021:
			result = "xxzy";
			break;
		case expr::SwizzleKind::e0022:
			result = "xxzz";
			break;
		case expr::SwizzleKind::e0023:
			result = "xxzw";
			break;
		case expr::SwizzleKind::e0030:
			result = "xxwx";
			break;
		case expr::SwizzleKind::e0031:
			result = "xxwy";
			break;
		case expr::SwizzleKind::e0032:
			result = "xxwz";
			break;
		case expr::SwizzleKind::e0033:
			result = "xxww";
			break;
		case expr::SwizzleKind::e0100:
			result = "xyxx";
			break;
		case expr::SwizzleKind::e0101:
			result = "xyxy";
			break;
		case expr::SwizzleKind::e0102:
			result = "xyxz";
			break;
		case expr::SwizzleKind::e0103:
			result = "xyxw";
			break;
		case expr::SwizzleKind::e0110:
			result = "xyyx";
			break;
		case expr::SwizzleKind::e0111:
			result = "xyyy";
			break;
		case expr::SwizzleKind::e0112:
			result = "xyyz";
			break;
		case expr::SwizzleKind::e0113:
			result = "xyyw";
			break;
		case expr::SwizzleKind::e0120:
			result = "xyzx";
			break;
		case expr::SwizzleKind::e0121:
			result = "xyzy";
			break;
		case expr::SwizzleKind::e0122:
			result = "xyzz";
			break;
		case expr::SwizzleKind::e0123:
			result = "xyzw";
			break;
		case expr::SwizzleKind::e0130:
			result = "xywx";
			break;
		case expr::SwizzleKind::e0131:
			result = "xywy";
			break;
		case expr::SwizzleKind::e0132:
			result = "xywz";
			break;
		case expr::SwizzleKind::e0133:
			result = "xyww";
			break;
		case expr::SwizzleKind::e0200:
			result = "xzxx";
			break;
		case expr::SwizzleKind::e0201:
			result = "xzxy";
			break;
		case expr::SwizzleKind::e0202:
			result = "xzxz";
			break;
		case expr::SwizzleKind::e0203:
			result = "xzxw";
			break;
		case expr::SwizzleKind::e0210:
			result = "xzyx";
			break;
		case expr::SwizzleKind::e0211:
			result = "xzyy";
			break;
		case expr::SwizzleKind::e0212:
			result = "xzyz";
			break;
		case expr::SwizzleKind::e0213:
			result = "xzyw";
			break;
		case expr::SwizzleKind::e0220:
			result = "xzzx";
			break;
		case expr::SwizzleKind::e0221:
			result = "xzzy";
			break;
		case expr::SwizzleKind::e0222:
			result = "xzzz";
			break;
		case expr::SwizzleKind::e0223:
			result = "xzzw";
			break;
		case expr::SwizzleKind::e0230:
			result = "xzwx";
			break;
		case expr::SwizzleKind::e0231:
			result = "xzwy";
			break;
		case expr::SwizzleKind::e0232:
			result = "xzwz";
			break;
		case expr::SwizzleKind::e0233:
			result = "xzww";
			break;
		case expr::SwizzleKind::e0300:
			result = "xwxx";
			break;
		case expr::SwizzleKind::e0301:
			result = "xwxy";
			break;
		case expr::SwizzleKind::e0302:
			result = "xwxz";
			break;
		case expr::SwizzleKind::e0303:
			result = "xwxw";
			break;
		case expr::SwizzleKind::e0310:
			result = "xwyx";
			break;
		case expr::SwizzleKind::e0311:
			result = "xwyy";
			break;
		case expr::SwizzleKind::e0312:
			result = "xwyz";
			break;
		case expr::SwizzleKind::e0313:
			result = "xwyw";
			break;
		case expr::SwizzleKind::e0320:
			result = "xwzx";
			break;
		case expr::SwizzleKind::e0321:
			result = "xwzy";
			break;
		case expr::SwizzleKind::e0322:
			result = "xwzz";
			break;
		case expr::SwizzleKind::e0323:
			result = "xwzw";
			break;
		case expr::SwizzleKind::e0330:
			result = "xwwx";
			break;
		case expr::SwizzleKind::e0331:
			result = "xwwy";
			break;
		case expr::SwizzleKind::e0332:
			result = "xwwz";
			break;
		case expr::SwizzleKind::e0333:
			result = "xwww";
			break;
		case expr::SwizzleKind::e1000:
			result = "yxxx";
			break;
		case expr::SwizzleKind::e1001:
			result = "yxxy";
			break;
		case expr::SwizzleKind::e1002:
			result = "yxxz";
			break;
		case expr::SwizzleKind::e1003:
			result = "yxxw";
			break;
		case expr::SwizzleKind::e1010:
			result = "yxyx";
			break;
		case expr::SwizzleKind::e1011:
			result = "yxyy";
			break;
		case expr::SwizzleKind::e1012:
			result = "yxyz";
			break;
		case expr::SwizzleKind::e1013:
			result = "yxyw";
			break;
		case expr::SwizzleKind::e1020:
			result = "yxzx";
			break;
		case expr::SwizzleKind::e1021:
			result = "yxzy";
			break;
		case expr::SwizzleKind::e1022:
			result = "yxzz";
			break;
		case expr::SwizzleKind::e1023:
			result = "yxzw";
			break;
		case expr::SwizzleKind::e1030:
			result = "yxwx";
			break;
		case expr::SwizzleKind::e1031:
			result = "yxwy";
			break;
		case expr::SwizzleKind::e1032:
			result = "yxwz";
			break;
		case expr::SwizzleKind::e1033:
			result = "yxww";
			break;
		case expr::SwizzleKind::e1100:
			result = "yyxx";
			break;
		case expr::SwizzleKind::e1101:
			result = "yyxy";
			break;
		case expr::SwizzleKind::e1102:
			result = "yyxz";
			break;
		case expr::SwizzleKind::e1103:
			result = "yyxw";
			break;
		case expr::SwizzleKind::e1110:
			result = "yyyx";
			break;
		case expr::SwizzleKind::e1111:
			result = "yyyy";
			break;
		case expr::SwizzleKind::e1112:
			result = "yyyz";
			break;
		case expr::SwizzleKind::e1113:
			result = "yyyw";
			break;
		case expr::SwizzleKind::e1120:
			result = "yyzx";
			break;
		case expr::SwizzleKind::e1121:
			result = "yyzy";
			break;
		case expr::SwizzleKind::e1122:
			result = "yyzz";
			break;
		case expr::SwizzleKind::e1123:
			result = "yyzw";
			break;
		case expr::SwizzleKind::e1130:
			result = "yywx";
			break;
		case expr::SwizzleKind::e1131:
			result = "yywy";
			break;
		case expr::SwizzleKind::e1132:
			result = "yywz";
			break;
		case expr::SwizzleKind::e1133:
			result = "yyww";
			break;
		case expr::SwizzleKind::e1200:
			result = "yzxx";
			break;
		case expr::SwizzleKind::e1201:
			result = "yzxy";
			break;
		case expr::SwizzleKind::e1202:
			result = "yzxz";
			break;
		case expr::SwizzleKind::e1203:
			result = "yzxw";
			break;
		case expr::SwizzleKind::e1210:
			result = "yzyx";
			break;
		case expr::SwizzleKind::e1211:
			result = "yzyy";
			break;
		case expr::SwizzleKind::e1212:
			result = "yzyz";
			break;
		case expr::SwizzleKind::e1213:
			result = "yzyw";
			break;
		case expr::SwizzleKind::e1220:
			result = "yzzx";
			break;
		case expr::SwizzleKind::e1221:
			result = "yzzy";
			break;
		case expr::SwizzleKind::e1222:
			result = "yzzz";
			break;
		case expr::SwizzleKind::e1223:
			result = "yzzw";
			break;
		case expr::SwizzleKind::e1230:
			result = "yzwx";
			break;
		case expr::SwizzleKind::e1231:
			result = "yzwy";
			break;
		case expr::SwizzleKind::e1232:
			result = "yzwz";
			break;
		case expr::SwizzleKind::e1233:
			result = "yzww";
			break;
		case expr::SwizzleKind::e1300:
			result = "ywxx";
			break;
		case expr::SwizzleKind::e1301:
			result = "ywxy";
			break;
		case expr::SwizzleKind::e1302:
			result = "ywxz";
			break;
		case expr::SwizzleKind::e1303:
			result = "ywxw";
			break;
		case expr::SwizzleKind::e1310:
			result = "ywyx";
			break;
		case expr::SwizzleKind::e1311:
			result = "ywyy";
			break;
		case expr::SwizzleKind::e1312:
			result = "ywyz";
			break;
		case expr::SwizzleKind::e1313:
			result = "ywyw";
			break;
		case expr::SwizzleKind::e1320:
			result = "ywzx";
			break;
		case expr::SwizzleKind::e1321:
			result = "ywzy";
			break;
		case expr::SwizzleKind::e1322:
			result = "ywzz";
			break;
		case expr::SwizzleKind::e1323:
			result = "ywzw";
			break;
		case expr::SwizzleKind::e1330:
			result = "ywwx";
			break;
		case expr::SwizzleKind::e1331:
			result = "ywwy";
			break;
		case expr::SwizzleKind::e1332:
			result = "ywwz";
			break;
		case expr::SwizzleKind::e1333:
			result = "ywww";
			break;
		case expr::SwizzleKind::e2000:
			result = "zxxx";
			break;
		case expr::SwizzleKind::e2001:
			result = "zxxy";
			break;
		case expr::SwizzleKind::e2002:
			result = "zxxz";
			break;
		case expr::SwizzleKind::e2003:
			result = "zxxw";
			break;
		case expr::SwizzleKind::e2010:
			result = "zxyx";
			break;
		case expr::SwizzleKind::e2011:
			result = "zxyy";
			break;
		case expr::SwizzleKind::e2012:
			result = "zxyz";
			break;
		case expr::SwizzleKind::e2013:
			result = "zxyw";
			break;
		case expr::SwizzleKind::e2020:
			result = "zxzx";
			break;
		case expr::SwizzleKind::e2021:
			result = "zxzy";
			break;
		case expr::SwizzleKind::e2022:
			result = "zxzz";
			break;
		case expr::SwizzleKind::e2023:
			result = "zxzw";
			break;
		case expr::SwizzleKind::e2030:
			result = "zxwx";
			break;
		case expr::SwizzleKind::e2031:
			result = "zxwy";
			break;
		case expr::SwizzleKind::e2032:
			result = "zxwz";
			break;
		case expr::SwizzleKind::e2033:
			result = "zxww";
			break;
		case expr::SwizzleKind::e2100:
			result = "zyxx";
			break;
		case expr::SwizzleKind::e2101:
			result = "zyxy";
			break;
		case expr::SwizzleKind::e2102:
			result = "zyxz";
			break;
		case expr::SwizzleKind::e2103:
			result = "zyxw";
			break;
		case expr::SwizzleKind::e2110:
			result = "zyyx";
			break;
		case expr::SwizzleKind::e2111:
			result = "zyyy";
			break;
		case expr::SwizzleKind::e2112:
			result = "zyyz";
			break;
		case expr::SwizzleKind::e2113:
			result = "zyyw";
			break;
		case expr::SwizzleKind::e2120:
			result = "zyzx";
			break;
		case expr::SwizzleKind::e2121:
			result = "zyzy";
			break;
		case expr::SwizzleKind::e2122:
			result = "zyzz";
			break;
		case expr::SwizzleKind::e2123:
			result = "zyzw";
			break;
		case expr::SwizzleKind::e2130:
			result = "zywx";
			break;
		case expr::SwizzleKind::e2131:
			result = "zywy";
			break;
		case expr::SwizzleKind::e2132:
			result = "zywz";
			break;
		case expr::SwizzleKind::e2133:
			result = "zyww";
			break;
		case expr::SwizzleKind::e2200:
			result = "zzxx";
			break;
		case expr::SwizzleKind::e2201:
			result = "zzxy";
			break;
		case expr::SwizzleKind::e2202:
			result = "zzxz";
			break;
		case expr::SwizzleKind::e2203:
			result = "zzxw";
			break;
		case expr::SwizzleKind::e2210:
			result = "zzyx";
			break;
		case expr::SwizzleKind::e2211:
			result = "zzyy";
			break;
		case expr::SwizzleKind::e2212:
			result = "zzyz";
			break;
		case expr::SwizzleKind::e2213:
			result = "zzyw";
			break;
		case expr::SwizzleKind::e2220:
			result = "zzzx";
			break;
		case expr::SwizzleKind::e2221:
			result = "zzzy";
			break;
		case expr::SwizzleKind::e2222:
			result = "zzzz";
			break;
		case expr::SwizzleKind::e2223:
			result = "zzzw";
			break;
		case expr::SwizzleKind::e2230:
			result = "zzwx";
			break;
		case expr::SwizzleKind::e2231:
			result = "zzwy";
			break;
		case expr::SwizzleKind::e2232:
			result = "zzwz";
			break;
		case expr::SwizzleKind::e2233:
			result = "zzww";
			break;
		case expr::SwizzleKind::e2300:
			result = "zwxx";
			break;
		case expr::SwizzleKind::e2301:
			result = "zwxy";
			break;
		case expr::SwizzleKind::e2302:
			result = "zwxz";
			break;
		case expr::SwizzleKind::e2303:
			result = "zwxw";
			break;
		case expr::SwizzleKind::e2310:
			result = "zwyx";
			break;
		case expr::SwizzleKind::e2311:
			result = "zwyy";
			break;
		case expr::SwizzleKind::e2312:
			result = "zwyz";
			break;
		case expr::SwizzleKind::e2313:
			result = "zwyw";
			break;
		case expr::SwizzleKind::e2320:
			result = "zwzx";
			break;
		case expr::SwizzleKind::e2321:
			result = "zwzy";
			break;
		case expr::SwizzleKind::e2322:
			result = "zwzz";
			break;
		case expr::SwizzleKind::e2323:
			result = "zwzw";
			break;
		case expr::SwizzleKind::e2330:
			result = "zwwx";
			break;
		case expr::SwizzleKind::e2331:
			result = "zwwy";
			break;
		case expr::SwizzleKind::e2332:
			result = "zwwz";
			break;
		case expr::SwizzleKind::e2333:
			result = "zwww";
			break;
		case expr::SwizzleKind::e3000:
			result = "wxxx";
			break;
		case expr::SwizzleKind::e3001:
			result = "wxxy";
			break;
		case expr::SwizzleKind::e3002:
			result = "wxxz";
			break;
		case expr::SwizzleKind::e3003:
			result = "wxxw";
			break;
		case expr::SwizzleKind::e3010:
			result = "wxyx";
			break;
		case expr::SwizzleKind::e3011:
			result = "wxyy";
			break;
		case expr::SwizzleKind::e3012:
			result = "wxyz";
			break;
		case expr::SwizzleKind::e3013:
			result = "wxyw";
			break;
		case expr::SwizzleKind::e3020:
			result = "wxzx";
			break;
		case expr::SwizzleKind::e3021:
			result = "wxzy";
			break;
		case expr::SwizzleKind::e3022:
			result = "wxzz";
			break;
		case expr::SwizzleKind::e3023:
			result = "wxzw";
			break;
		case expr::SwizzleKind::e3030:
			result = "wxwx";
			break;
		case expr::SwizzleKind::e3031:
			result = "wxwy";
			break;
		case expr::SwizzleKind::e3032:
			result = "wxwz";
			break;
		case expr::SwizzleKind::e3033:
			result = "wxww";
			break;
		case expr::SwizzleKind::e3100:
			result = "wyxx";
			break;
		case expr::SwizzleKind::e3101:
			result = "wyxy";
			break;
		case expr::SwizzleKind::e3102:
			result = "wyxz";
			break;
		case expr::SwizzleKind::e3103:
			result = "wyxw";
			break;
		case expr::SwizzleKind::e3110:
			result = "wyyx";
			break;
		case expr::SwizzleKind::e3111:
			result = "wyyy";
			break;
		case expr::SwizzleKind::e3112:
			result = "wyyz";
			break;
		case expr::SwizzleKind::e3113:
			result = "wyyw";
			break;
		case expr::SwizzleKind::e3120:
			result = "wyzx";
			break;
		case expr::SwizzleKind::e3121:
			result = "wyzy";
			break;
		case expr::SwizzleKind::e3122:
			result = "wyzz";
			break;
		case expr::SwizzleKind::e3123:
			result = "wyzw";
			break;
		case expr::SwizzleKind::e3130:
			result = "wywx";
			break;
		case expr::SwizzleKind::e3131:
			result = "wywy";
			break;
		case expr::SwizzleKind::e3132:
			result = "wywz";
			break;
		case expr::SwizzleKind::e3133:
			result = "wyww";
			break;
		case expr::SwizzleKind::e3200:
			result = "wzxx";
			break;
		case expr::SwizzleKind::e3201:
			result = "wzxy";
			break;
		case expr::SwizzleKind::e3202:
			result = "wzxz";
			break;
		case expr::SwizzleKind::e3203:
			result = "wzxw";
			break;
		case expr::SwizzleKind::e3210:
			result = "wzyx";
			break;
		case expr::SwizzleKind::e3211:
			result = "wzyy";
			break;
		case expr::SwizzleKind::e3212:
			result = "wzyz";
			break;
		case expr::SwizzleKind::e3213:
			result = "wzyw";
			break;
		case expr::SwizzleKind::e3220:
			result = "wzzx";
			break;
		case expr::SwizzleKind::e3221:
			result = "wzzy";
			break;
		case expr::SwizzleKind::e3222:
			result = "wzzz";
			break;
		case expr::SwizzleKind::e3223:
			result = "wzzw";
			break;
		case expr::SwizzleKind::e3230:
			result = "wzwx";
			break;
		case expr::SwizzleKind::e3231:
			result = "wzwy";
			break;
		case expr::SwizzleKind::e3232:
			result = "wzwz";
			break;
		case expr::SwizzleKind::e3233:
			result = "wzww";
			break;
		case expr::SwizzleKind::e3300:
			result = "wwxx";
			break;
		case expr::SwizzleKind::e3301:
			result = "wwxy";
			break;
		case expr::SwizzleKind::e3302:
			result = "wwxz";
			break;
		case expr::SwizzleKind::e3303:
			result = "wwxw";
			break;
		case expr::SwizzleKind::e3310:
			result = "wwyx";
			break;
		case expr::SwizzleKind::e3311:
			result = "wwyy";
			break;
		case expr::SwizzleKind::e3312:
			result = "wwyz";
			break;
		case expr::SwizzleKind::e3313:
			result = "wwyw";
			break;
		case expr::SwizzleKind::e3320:
			result = "wwzx";
			break;
		case expr::SwizzleKind::e3321:
			result = "wwzy";
			break;
		case expr::SwizzleKind::e3322:
			result = "wwzz";
			break;
		case expr::SwizzleKind::e3323:
			result = "wwzw";
			break;
		case expr::SwizzleKind::e3330:
			result = "wwwx";
			break;
		case expr::SwizzleKind::e3331:
			result = "wwwy";
			break;
		case expr::SwizzleKind::e3332:
			result = "wwwz";
			break;
		case expr::SwizzleKind::e3333:
			result = "wwww";
			break;
		default:
			break;
		}

		return result;
	}
}
