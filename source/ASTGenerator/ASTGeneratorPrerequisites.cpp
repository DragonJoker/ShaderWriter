#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

namespace ast::expr
{
	std::string getName( SwizzleKind kind )
	{
		std::string result;

		switch ( kind )
		{
		case expr::SwizzleKind::ex:
			result = "x";
			break;
		case expr::SwizzleKind::ey:
			result = "y";
			break;
		case expr::SwizzleKind::ez:
			result = "z";
			break;
		case expr::SwizzleKind::ew:
			result = "w";
			break;
		case expr::SwizzleKind::exx:
			result = "xx";
			break;
		case expr::SwizzleKind::exy:
			result = "xy";
			break;
		case expr::SwizzleKind::exz:
			result = "xz";
			break;
		case expr::SwizzleKind::exw:
			result = "xw";
			break;
		case expr::SwizzleKind::eyx:
			result = "yx";
			break;
		case expr::SwizzleKind::eyy:
			result = "yy";
			break;
		case expr::SwizzleKind::eyz:
			result = "yz";
			break;
		case expr::SwizzleKind::eyw:
			result = "yw";
			break;
		case expr::SwizzleKind::ezx:
			result = "zx";
			break;
		case expr::SwizzleKind::ezy:
			result = "zy";
			break;
		case expr::SwizzleKind::ezz:
			result = "zz";
			break;
		case expr::SwizzleKind::ezw:
			result = "zw";
			break;
		case expr::SwizzleKind::ewx:
			result = "wx";
			break;
		case expr::SwizzleKind::ewy:
			result = "wy";
			break;
		case expr::SwizzleKind::ewz:
			result = "wz";
			break;
		case expr::SwizzleKind::eww:
			result = "ww";
			break;
		case expr::SwizzleKind::exxx:
			result = "xxx";
			break;
		case expr::SwizzleKind::exxy:
			result = "xxy";
			break;
		case expr::SwizzleKind::exxz:
			result = "xxz";
			break;
		case expr::SwizzleKind::exxw:
			result = "xxw";
			break;
		case expr::SwizzleKind::exyx:
			result = "xyx";
			break;
		case expr::SwizzleKind::exyy:
			result = "xyy";
			break;
		case expr::SwizzleKind::exyz:
			result = "xyz";
			break;
		case expr::SwizzleKind::exyw:
			result = "xyw";
			break;
		case expr::SwizzleKind::exzx:
			result = "xzx";
			break;
		case expr::SwizzleKind::exzy:
			result = "xzy";
			break;
		case expr::SwizzleKind::exzz:
			result = "xzz";
			break;
		case expr::SwizzleKind::exzw:
			result = "xzw";
			break;
		case expr::SwizzleKind::exwx:
			result = "xwx";
			break;
		case expr::SwizzleKind::exwy:
			result = "xwy";
			break;
		case expr::SwizzleKind::exwz:
			result = "xwz";
			break;
		case expr::SwizzleKind::exww:
			result = "xww";
			break;
		case expr::SwizzleKind::eyxx:
			result = "yxx";
			break;
		case expr::SwizzleKind::eyxy:
			result = "yxy";
			break;
		case expr::SwizzleKind::eyxz:
			result = "yxz";
			break;
		case expr::SwizzleKind::eyxw:
			result = "yxw";
			break;
		case expr::SwizzleKind::eyyx:
			result = "yyx";
			break;
		case expr::SwizzleKind::eyyy:
			result = "yyy";
			break;
		case expr::SwizzleKind::eyyz:
			result = "yyz";
			break;
		case expr::SwizzleKind::eyyw:
			result = "yyw";
			break;
		case expr::SwizzleKind::eyzx:
			result = "yzx";
			break;
		case expr::SwizzleKind::eyzy:
			result = "yzy";
			break;
		case expr::SwizzleKind::eyzz:
			result = "yzz";
			break;
		case expr::SwizzleKind::eyzw:
			result = "yzw";
			break;
		case expr::SwizzleKind::eywx:
			result = "ywx";
			break;
		case expr::SwizzleKind::eywy:
			result = "ywy";
			break;
		case expr::SwizzleKind::eywz:
			result = "ywz";
			break;
		case expr::SwizzleKind::eyww:
			result = "yww";
			break;
		case expr::SwizzleKind::ezxx:
			result = "zxx";
			break;
		case expr::SwizzleKind::ezxy:
			result = "zxy";
			break;
		case expr::SwizzleKind::ezxz:
			result = "zxz";
			break;
		case expr::SwizzleKind::ezxw:
			result = "zxw";
			break;
		case expr::SwizzleKind::ezyx:
			result = "zyx";
			break;
		case expr::SwizzleKind::ezyy:
			result = "zyy";
			break;
		case expr::SwizzleKind::ezyz:
			result = "zyz";
			break;
		case expr::SwizzleKind::ezyw:
			result = "zyw";
			break;
		case expr::SwizzleKind::ezzx:
			result = "zzx";
			break;
		case expr::SwizzleKind::ezzy:
			result = "zzy";
			break;
		case expr::SwizzleKind::ezzz:
			result = "zzz";
			break;
		case expr::SwizzleKind::ezzw:
			result = "zzw";
			break;
		case expr::SwizzleKind::ezwx:
			result = "zwx";
			break;
		case expr::SwizzleKind::ezwy:
			result = "zwy";
			break;
		case expr::SwizzleKind::ezwz:
			result = "zwz";
			break;
		case expr::SwizzleKind::ezww:
			result = "zww";
			break;
		case expr::SwizzleKind::ewxx:
			result = "wxx";
			break;
		case expr::SwizzleKind::ewxy:
			result = "wxy";
			break;
		case expr::SwizzleKind::ewxz:
			result = "wxz";
			break;
		case expr::SwizzleKind::ewxw:
			result = "wxw";
			break;
		case expr::SwizzleKind::ewyx:
			result = "wyx";
			break;
		case expr::SwizzleKind::ewyy:
			result = "wyy";
			break;
		case expr::SwizzleKind::ewyz:
			result = "wyz";
			break;
		case expr::SwizzleKind::ewyw:
			result = "wyw";
			break;
		case expr::SwizzleKind::ewzx:
			result = "wzx";
			break;
		case expr::SwizzleKind::ewzy:
			result = "wzy";
			break;
		case expr::SwizzleKind::ewzz:
			result = "wzz";
			break;
		case expr::SwizzleKind::ewzw:
			result = "wzw";
			break;
		case expr::SwizzleKind::ewwx:
			result = "wwx";
			break;
		case expr::SwizzleKind::ewwy:
			result = "wwy";
			break;
		case expr::SwizzleKind::ewwz:
			result = "wwz";
			break;
		case expr::SwizzleKind::ewww:
			result = "www";
			break;
		case expr::SwizzleKind::exxxx:
			result = "xxxx";
			break;
		case expr::SwizzleKind::exxxy:
			result = "xxxy";
			break;
		case expr::SwizzleKind::exxxz:
			result = "xxxz";
			break;
		case expr::SwizzleKind::exxxw:
			result = "xxxw";
			break;
		case expr::SwizzleKind::exxyx:
			result = "xxyx";
			break;
		case expr::SwizzleKind::exxyy:
			result = "xxyy";
			break;
		case expr::SwizzleKind::exxyz:
			result = "xxyz";
			break;
		case expr::SwizzleKind::exxyw:
			result = "xxyw";
			break;
		case expr::SwizzleKind::exxzx:
			result = "xxzx";
			break;
		case expr::SwizzleKind::exxzy:
			result = "xxzy";
			break;
		case expr::SwizzleKind::exxzz:
			result = "xxzz";
			break;
		case expr::SwizzleKind::exxzw:
			result = "xxzw";
			break;
		case expr::SwizzleKind::exxwx:
			result = "xxwx";
			break;
		case expr::SwizzleKind::exxwy:
			result = "xxwy";
			break;
		case expr::SwizzleKind::exxwz:
			result = "xxwz";
			break;
		case expr::SwizzleKind::exxww:
			result = "xxww";
			break;
		case expr::SwizzleKind::exyxx:
			result = "xyxx";
			break;
		case expr::SwizzleKind::exyxy:
			result = "xyxy";
			break;
		case expr::SwizzleKind::exyxz:
			result = "xyxz";
			break;
		case expr::SwizzleKind::exyxw:
			result = "xyxw";
			break;
		case expr::SwizzleKind::exyyx:
			result = "xyyx";
			break;
		case expr::SwizzleKind::exyyy:
			result = "xyyy";
			break;
		case expr::SwizzleKind::exyyz:
			result = "xyyz";
			break;
		case expr::SwizzleKind::exyyw:
			result = "xyyw";
			break;
		case expr::SwizzleKind::exyzx:
			result = "xyzx";
			break;
		case expr::SwizzleKind::exyzy:
			result = "xyzy";
			break;
		case expr::SwizzleKind::exyzz:
			result = "xyzz";
			break;
		case expr::SwizzleKind::exyzw:
			result = "xyzw";
			break;
		case expr::SwizzleKind::exywx:
			result = "xywx";
			break;
		case expr::SwizzleKind::exywy:
			result = "xywy";
			break;
		case expr::SwizzleKind::exywz:
			result = "xywz";
			break;
		case expr::SwizzleKind::exyww:
			result = "xyww";
			break;
		case expr::SwizzleKind::exzxx:
			result = "xzxx";
			break;
		case expr::SwizzleKind::exzxy:
			result = "xzxy";
			break;
		case expr::SwizzleKind::exzxz:
			result = "xzxz";
			break;
		case expr::SwizzleKind::exzxw:
			result = "xzxw";
			break;
		case expr::SwizzleKind::exzyx:
			result = "xzyx";
			break;
		case expr::SwizzleKind::exzyy:
			result = "xzyy";
			break;
		case expr::SwizzleKind::exzyz:
			result = "xzyz";
			break;
		case expr::SwizzleKind::exzyw:
			result = "xzyw";
			break;
		case expr::SwizzleKind::exzzx:
			result = "xzzx";
			break;
		case expr::SwizzleKind::exzzy:
			result = "xzzy";
			break;
		case expr::SwizzleKind::exzzz:
			result = "xzzz";
			break;
		case expr::SwizzleKind::exzzw:
			result = "xzzw";
			break;
		case expr::SwizzleKind::exzwx:
			result = "xzwx";
			break;
		case expr::SwizzleKind::exzwy:
			result = "xzwy";
			break;
		case expr::SwizzleKind::exzwz:
			result = "xzwz";
			break;
		case expr::SwizzleKind::exzww:
			result = "xzww";
			break;
		case expr::SwizzleKind::exwxx:
			result = "xwxx";
			break;
		case expr::SwizzleKind::exwxy:
			result = "xwxy";
			break;
		case expr::SwizzleKind::exwxz:
			result = "xwxz";
			break;
		case expr::SwizzleKind::exwxw:
			result = "xwxw";
			break;
		case expr::SwizzleKind::exwyx:
			result = "xwyx";
			break;
		case expr::SwizzleKind::exwyy:
			result = "xwyy";
			break;
		case expr::SwizzleKind::exwyz:
			result = "xwyz";
			break;
		case expr::SwizzleKind::exwyw:
			result = "xwyw";
			break;
		case expr::SwizzleKind::exwzx:
			result = "xwzx";
			break;
		case expr::SwizzleKind::exwzy:
			result = "xwzy";
			break;
		case expr::SwizzleKind::exwzz:
			result = "xwzz";
			break;
		case expr::SwizzleKind::exwzw:
			result = "xwzw";
			break;
		case expr::SwizzleKind::exwwx:
			result = "xwwx";
			break;
		case expr::SwizzleKind::exwwy:
			result = "xwwy";
			break;
		case expr::SwizzleKind::exwwz:
			result = "xwwz";
			break;
		case expr::SwizzleKind::exwww:
			result = "xwww";
			break;
		case expr::SwizzleKind::eyxxx:
			result = "yxxx";
			break;
		case expr::SwizzleKind::eyxxy:
			result = "yxxy";
			break;
		case expr::SwizzleKind::eyxxz:
			result = "yxxz";
			break;
		case expr::SwizzleKind::eyxxw:
			result = "yxxw";
			break;
		case expr::SwizzleKind::eyxyx:
			result = "yxyx";
			break;
		case expr::SwizzleKind::eyxyy:
			result = "yxyy";
			break;
		case expr::SwizzleKind::eyxyz:
			result = "yxyz";
			break;
		case expr::SwizzleKind::eyxyw:
			result = "yxyw";
			break;
		case expr::SwizzleKind::eyxzx:
			result = "yxzx";
			break;
		case expr::SwizzleKind::eyxzy:
			result = "yxzy";
			break;
		case expr::SwizzleKind::eyxzz:
			result = "yxzz";
			break;
		case expr::SwizzleKind::eyxzw:
			result = "yxzw";
			break;
		case expr::SwizzleKind::eyxwx:
			result = "yxwx";
			break;
		case expr::SwizzleKind::eyxwy:
			result = "yxwy";
			break;
		case expr::SwizzleKind::eyxwz:
			result = "yxwz";
			break;
		case expr::SwizzleKind::eyxww:
			result = "yxww";
			break;
		case expr::SwizzleKind::eyyxx:
			result = "yyxx";
			break;
		case expr::SwizzleKind::eyyxy:
			result = "yyxy";
			break;
		case expr::SwizzleKind::eyyxz:
			result = "yyxz";
			break;
		case expr::SwizzleKind::eyyxw:
			result = "yyxw";
			break;
		case expr::SwizzleKind::eyyyx:
			result = "yyyx";
			break;
		case expr::SwizzleKind::eyyyy:
			result = "yyyy";
			break;
		case expr::SwizzleKind::eyyyz:
			result = "yyyz";
			break;
		case expr::SwizzleKind::eyyyw:
			result = "yyyw";
			break;
		case expr::SwizzleKind::eyyzx:
			result = "yyzx";
			break;
		case expr::SwizzleKind::eyyzy:
			result = "yyzy";
			break;
		case expr::SwizzleKind::eyyzz:
			result = "yyzz";
			break;
		case expr::SwizzleKind::eyyzw:
			result = "yyzw";
			break;
		case expr::SwizzleKind::eyywx:
			result = "yywx";
			break;
		case expr::SwizzleKind::eyywy:
			result = "yywy";
			break;
		case expr::SwizzleKind::eyywz:
			result = "yywz";
			break;
		case expr::SwizzleKind::eyyww:
			result = "yyww";
			break;
		case expr::SwizzleKind::eyzxx:
			result = "yzxx";
			break;
		case expr::SwizzleKind::eyzxy:
			result = "yzxy";
			break;
		case expr::SwizzleKind::eyzxz:
			result = "yzxz";
			break;
		case expr::SwizzleKind::eyzxw:
			result = "yzxw";
			break;
		case expr::SwizzleKind::eyzyx:
			result = "yzyx";
			break;
		case expr::SwizzleKind::eyzyy:
			result = "yzyy";
			break;
		case expr::SwizzleKind::eyzyz:
			result = "yzyz";
			break;
		case expr::SwizzleKind::eyzyw:
			result = "yzyw";
			break;
		case expr::SwizzleKind::eyzzx:
			result = "yzzx";
			break;
		case expr::SwizzleKind::eyzzy:
			result = "yzzy";
			break;
		case expr::SwizzleKind::eyzzz:
			result = "yzzz";
			break;
		case expr::SwizzleKind::eyzzw:
			result = "yzzw";
			break;
		case expr::SwizzleKind::eyzwx:
			result = "yzwx";
			break;
		case expr::SwizzleKind::eyzwy:
			result = "yzwy";
			break;
		case expr::SwizzleKind::eyzwz:
			result = "yzwz";
			break;
		case expr::SwizzleKind::eyzww:
			result = "yzww";
			break;
		case expr::SwizzleKind::eywxx:
			result = "ywxx";
			break;
		case expr::SwizzleKind::eywxy:
			result = "ywxy";
			break;
		case expr::SwizzleKind::eywxz:
			result = "ywxz";
			break;
		case expr::SwizzleKind::eywxw:
			result = "ywxw";
			break;
		case expr::SwizzleKind::eywyx:
			result = "ywyx";
			break;
		case expr::SwizzleKind::eywyy:
			result = "ywyy";
			break;
		case expr::SwizzleKind::eywyz:
			result = "ywyz";
			break;
		case expr::SwizzleKind::eywyw:
			result = "ywyw";
			break;
		case expr::SwizzleKind::eywzx:
			result = "ywzx";
			break;
		case expr::SwizzleKind::eywzy:
			result = "ywzy";
			break;
		case expr::SwizzleKind::eywzz:
			result = "ywzz";
			break;
		case expr::SwizzleKind::eywzw:
			result = "ywzw";
			break;
		case expr::SwizzleKind::eywwx:
			result = "ywwx";
			break;
		case expr::SwizzleKind::eywwy:
			result = "ywwy";
			break;
		case expr::SwizzleKind::eywwz:
			result = "ywwz";
			break;
		case expr::SwizzleKind::eywww:
			result = "ywww";
			break;
		case expr::SwizzleKind::ezxxx:
			result = "zxxx";
			break;
		case expr::SwizzleKind::ezxxy:
			result = "zxxy";
			break;
		case expr::SwizzleKind::ezxxz:
			result = "zxxz";
			break;
		case expr::SwizzleKind::ezxxw:
			result = "zxxw";
			break;
		case expr::SwizzleKind::ezxyx:
			result = "zxyx";
			break;
		case expr::SwizzleKind::ezxyy:
			result = "zxyy";
			break;
		case expr::SwizzleKind::ezxyz:
			result = "zxyz";
			break;
		case expr::SwizzleKind::ezxyw:
			result = "zxyw";
			break;
		case expr::SwizzleKind::ezxzx:
			result = "zxzx";
			break;
		case expr::SwizzleKind::ezxzy:
			result = "zxzy";
			break;
		case expr::SwizzleKind::ezxzz:
			result = "zxzz";
			break;
		case expr::SwizzleKind::ezxzw:
			result = "zxzw";
			break;
		case expr::SwizzleKind::ezxwx:
			result = "zxwx";
			break;
		case expr::SwizzleKind::ezxwy:
			result = "zxwy";
			break;
		case expr::SwizzleKind::ezxwz:
			result = "zxwz";
			break;
		case expr::SwizzleKind::ezxww:
			result = "zxww";
			break;
		case expr::SwizzleKind::ezyxx:
			result = "zyxx";
			break;
		case expr::SwizzleKind::ezyxy:
			result = "zyxy";
			break;
		case expr::SwizzleKind::ezyxz:
			result = "zyxz";
			break;
		case expr::SwizzleKind::ezyxw:
			result = "zyxw";
			break;
		case expr::SwizzleKind::ezyyx:
			result = "zyyx";
			break;
		case expr::SwizzleKind::ezyyy:
			result = "zyyy";
			break;
		case expr::SwizzleKind::ezyyz:
			result = "zyyz";
			break;
		case expr::SwizzleKind::ezyyw:
			result = "zyyw";
			break;
		case expr::SwizzleKind::ezyzx:
			result = "zyzx";
			break;
		case expr::SwizzleKind::ezyzy:
			result = "zyzy";
			break;
		case expr::SwizzleKind::ezyzz:
			result = "zyzz";
			break;
		case expr::SwizzleKind::ezyzw:
			result = "zyzw";
			break;
		case expr::SwizzleKind::ezywx:
			result = "zywx";
			break;
		case expr::SwizzleKind::ezywy:
			result = "zywy";
			break;
		case expr::SwizzleKind::ezywz:
			result = "zywz";
			break;
		case expr::SwizzleKind::ezyww:
			result = "zyww";
			break;
		case expr::SwizzleKind::ezzxx:
			result = "zzxx";
			break;
		case expr::SwizzleKind::ezzxy:
			result = "zzxy";
			break;
		case expr::SwizzleKind::ezzxz:
			result = "zzxz";
			break;
		case expr::SwizzleKind::ezzxw:
			result = "zzxw";
			break;
		case expr::SwizzleKind::ezzyx:
			result = "zzyx";
			break;
		case expr::SwizzleKind::ezzyy:
			result = "zzyy";
			break;
		case expr::SwizzleKind::ezzyz:
			result = "zzyz";
			break;
		case expr::SwizzleKind::ezzyw:
			result = "zzyw";
			break;
		case expr::SwizzleKind::ezzzx:
			result = "zzzx";
			break;
		case expr::SwizzleKind::ezzzy:
			result = "zzzy";
			break;
		case expr::SwizzleKind::ezzzz:
			result = "zzzz";
			break;
		case expr::SwizzleKind::ezzzw:
			result = "zzzw";
			break;
		case expr::SwizzleKind::ezzwx:
			result = "zzwx";
			break;
		case expr::SwizzleKind::ezzwy:
			result = "zzwy";
			break;
		case expr::SwizzleKind::ezzwz:
			result = "zzwz";
			break;
		case expr::SwizzleKind::ezzww:
			result = "zzww";
			break;
		case expr::SwizzleKind::ezwxx:
			result = "zwxx";
			break;
		case expr::SwizzleKind::ezwxy:
			result = "zwxy";
			break;
		case expr::SwizzleKind::ezwxz:
			result = "zwxz";
			break;
		case expr::SwizzleKind::ezwxw:
			result = "zwxw";
			break;
		case expr::SwizzleKind::ezwyx:
			result = "zwyx";
			break;
		case expr::SwizzleKind::ezwyy:
			result = "zwyy";
			break;
		case expr::SwizzleKind::ezwyz:
			result = "zwyz";
			break;
		case expr::SwizzleKind::ezwyw:
			result = "zwyw";
			break;
		case expr::SwizzleKind::ezwzx:
			result = "zwzx";
			break;
		case expr::SwizzleKind::ezwzy:
			result = "zwzy";
			break;
		case expr::SwizzleKind::ezwzz:
			result = "zwzz";
			break;
		case expr::SwizzleKind::ezwzw:
			result = "zwzw";
			break;
		case expr::SwizzleKind::ezwwx:
			result = "zwwx";
			break;
		case expr::SwizzleKind::ezwwy:
			result = "zwwy";
			break;
		case expr::SwizzleKind::ezwwz:
			result = "zwwz";
			break;
		case expr::SwizzleKind::ezwww:
			result = "zwww";
			break;
		case expr::SwizzleKind::ewxxx:
			result = "wxxx";
			break;
		case expr::SwizzleKind::ewxxy:
			result = "wxxy";
			break;
		case expr::SwizzleKind::ewxxz:
			result = "wxxz";
			break;
		case expr::SwizzleKind::ewxxw:
			result = "wxxw";
			break;
		case expr::SwizzleKind::ewxyx:
			result = "wxyx";
			break;
		case expr::SwizzleKind::ewxyy:
			result = "wxyy";
			break;
		case expr::SwizzleKind::ewxyz:
			result = "wxyz";
			break;
		case expr::SwizzleKind::ewxyw:
			result = "wxyw";
			break;
		case expr::SwizzleKind::ewxzx:
			result = "wxzx";
			break;
		case expr::SwizzleKind::ewxzy:
			result = "wxzy";
			break;
		case expr::SwizzleKind::ewxzz:
			result = "wxzz";
			break;
		case expr::SwizzleKind::ewxzw:
			result = "wxzw";
			break;
		case expr::SwizzleKind::ewxwx:
			result = "wxwx";
			break;
		case expr::SwizzleKind::ewxwy:
			result = "wxwy";
			break;
		case expr::SwizzleKind::ewxwz:
			result = "wxwz";
			break;
		case expr::SwizzleKind::ewxww:
			result = "wxww";
			break;
		case expr::SwizzleKind::ewyxx:
			result = "wyxx";
			break;
		case expr::SwizzleKind::ewyxy:
			result = "wyxy";
			break;
		case expr::SwizzleKind::ewyxz:
			result = "wyxz";
			break;
		case expr::SwizzleKind::ewyxw:
			result = "wyxw";
			break;
		case expr::SwizzleKind::ewyyx:
			result = "wyyx";
			break;
		case expr::SwizzleKind::ewyyy:
			result = "wyyy";
			break;
		case expr::SwizzleKind::ewyyz:
			result = "wyyz";
			break;
		case expr::SwizzleKind::ewyyw:
			result = "wyyw";
			break;
		case expr::SwizzleKind::ewyzx:
			result = "wyzx";
			break;
		case expr::SwizzleKind::ewyzy:
			result = "wyzy";
			break;
		case expr::SwizzleKind::ewyzz:
			result = "wyzz";
			break;
		case expr::SwizzleKind::ewyzw:
			result = "wyzw";
			break;
		case expr::SwizzleKind::ewywx:
			result = "wywx";
			break;
		case expr::SwizzleKind::ewywy:
			result = "wywy";
			break;
		case expr::SwizzleKind::ewywz:
			result = "wywz";
			break;
		case expr::SwizzleKind::ewyww:
			result = "wyww";
			break;
		case expr::SwizzleKind::ewzxx:
			result = "wzxx";
			break;
		case expr::SwizzleKind::ewzxy:
			result = "wzxy";
			break;
		case expr::SwizzleKind::ewzxz:
			result = "wzxz";
			break;
		case expr::SwizzleKind::ewzxw:
			result = "wzxw";
			break;
		case expr::SwizzleKind::ewzyx:
			result = "wzyx";
			break;
		case expr::SwizzleKind::ewzyy:
			result = "wzyy";
			break;
		case expr::SwizzleKind::ewzyz:
			result = "wzyz";
			break;
		case expr::SwizzleKind::ewzyw:
			result = "wzyw";
			break;
		case expr::SwizzleKind::ewzzx:
			result = "wzzx";
			break;
		case expr::SwizzleKind::ewzzy:
			result = "wzzy";
			break;
		case expr::SwizzleKind::ewzzz:
			result = "wzzz";
			break;
		case expr::SwizzleKind::ewzzw:
			result = "wzzw";
			break;
		case expr::SwizzleKind::ewzwx:
			result = "wzwx";
			break;
		case expr::SwizzleKind::ewzwy:
			result = "wzwy";
			break;
		case expr::SwizzleKind::ewzwz:
			result = "wzwz";
			break;
		case expr::SwizzleKind::ewzww:
			result = "wzww";
			break;
		case expr::SwizzleKind::ewwxx:
			result = "wwxx";
			break;
		case expr::SwizzleKind::ewwxy:
			result = "wwxy";
			break;
		case expr::SwizzleKind::ewwxz:
			result = "wwxz";
			break;
		case expr::SwizzleKind::ewwxw:
			result = "wwxw";
			break;
		case expr::SwizzleKind::ewwyx:
			result = "wwyx";
			break;
		case expr::SwizzleKind::ewwyy:
			result = "wwyy";
			break;
		case expr::SwizzleKind::ewwyz:
			result = "wwyz";
			break;
		case expr::SwizzleKind::ewwyw:
			result = "wwyw";
			break;
		case expr::SwizzleKind::ewwzx:
			result = "wwzx";
			break;
		case expr::SwizzleKind::ewwzy:
			result = "wwzy";
			break;
		case expr::SwizzleKind::ewwzz:
			result = "wwzz";
			break;
		case expr::SwizzleKind::ewwzw:
			result = "wwzw";
			break;
		case expr::SwizzleKind::ewwwx:
			result = "wwwx";
			break;
		case expr::SwizzleKind::ewwwy:
			result = "wwwy";
			break;
		case expr::SwizzleKind::ewwwz:
			result = "wwwz";
			break;
		case expr::SwizzleKind::ewwww:
			result = "wwww";
			break;
		default:
			throw std::runtime_error{ "Not supported SwizzleKind" };
		}

		return result;
	}
}
