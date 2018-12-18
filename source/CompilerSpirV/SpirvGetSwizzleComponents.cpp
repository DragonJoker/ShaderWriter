/*
See LICENSE file in root folder
*/
#include "SpirvGetSwizzleComponents.hpp"

#include <numeric>

namespace spirv
{
	std::vector< uint32_t > getSwizzleComponents( ast::expr::SwizzleKind kind )
	{
		switch ( kind )
		{
		case ast::expr::SwizzleKind::e0:
			return { 0 };
		case ast::expr::SwizzleKind::e1:
			return { 1 };
		case ast::expr::SwizzleKind::e2:
			return { 2 };
		case ast::expr::SwizzleKind::e3:
			return { 3 };
		case ast::expr::SwizzleKind::e00:
			return { 0, 0 };
		case ast::expr::SwizzleKind::e01:
			return { 0, 1 };
		case ast::expr::SwizzleKind::e02:
			return { 0, 2 };
		case ast::expr::SwizzleKind::e03:
			return { 0, 3 };
		case ast::expr::SwizzleKind::e10:
			return { 1, 0 };
		case ast::expr::SwizzleKind::e11:
			return { 1, 1 };
		case ast::expr::SwizzleKind::e12:
			return { 1, 2 };
		case ast::expr::SwizzleKind::e13:
			return { 1, 3 };
		case ast::expr::SwizzleKind::e20:
			return { 2, 0 };
		case ast::expr::SwizzleKind::e21:
			return { 2, 1 };
		case ast::expr::SwizzleKind::e22:
			return { 2, 2 };
		case ast::expr::SwizzleKind::e23:
			return { 2, 3 };
		case ast::expr::SwizzleKind::e30:
			return { 3, 0 };
		case ast::expr::SwizzleKind::e31:
			return { 3, 1 };
		case ast::expr::SwizzleKind::e32:
			return { 3, 2 };
		case ast::expr::SwizzleKind::e33:
			return { 3, 3 };
		case ast::expr::SwizzleKind::e000:
			return { 0, 0, 0 };
		case ast::expr::SwizzleKind::e001:
			return { 0, 0, 1 };
		case ast::expr::SwizzleKind::e002:
			return { 0, 0, 2 };
		case ast::expr::SwizzleKind::e003:
			return { 0, 0, 3 };
		case ast::expr::SwizzleKind::e010:
			return { 0, 1, 0 };
		case ast::expr::SwizzleKind::e011:
			return { 0, 1, 1 };
		case ast::expr::SwizzleKind::e012:
			return { 0, 1, 2 };
		case ast::expr::SwizzleKind::e013:
			return { 0, 1, 3 };
		case ast::expr::SwizzleKind::e020:
			return { 0, 2, 0 };
		case ast::expr::SwizzleKind::e021:
			return { 0, 2, 1 };
		case ast::expr::SwizzleKind::e022:
			return { 0, 2, 2 };
		case ast::expr::SwizzleKind::e023:
			return { 0, 2, 3 };
		case ast::expr::SwizzleKind::e030:
			return { 0, 3, 0 };
		case ast::expr::SwizzleKind::e031:
			return { 0, 3, 1 };
		case ast::expr::SwizzleKind::e032:
			return { 0, 3, 2 };
		case ast::expr::SwizzleKind::e033:
			return { 0, 3, 3 };
		case ast::expr::SwizzleKind::e100:
			return { 1, 0, 0 };
		case ast::expr::SwizzleKind::e101:
			return { 1, 0, 1 };
		case ast::expr::SwizzleKind::e102:
			return { 1, 0, 2 };
		case ast::expr::SwizzleKind::e103:
			return { 1, 0, 3 };
		case ast::expr::SwizzleKind::e110:
			return { 1, 1, 0 };
		case ast::expr::SwizzleKind::e111:
			return { 1, 1, 1 };
		case ast::expr::SwizzleKind::e112:
			return { 1, 1, 2 };
		case ast::expr::SwizzleKind::e113:
			return { 1, 1, 3 };
		case ast::expr::SwizzleKind::e120:
			return { 1, 2, 0 };
		case ast::expr::SwizzleKind::e121:
			return { 1, 2, 1 };
		case ast::expr::SwizzleKind::e122:
			return { 1, 2, 2 };
		case ast::expr::SwizzleKind::e123:
			return { 1, 2, 3 };
		case ast::expr::SwizzleKind::e130:
			return { 1, 3, 0 };
		case ast::expr::SwizzleKind::e131:
			return { 1, 3, 1 };
		case ast::expr::SwizzleKind::e132:
			return { 1, 3, 2 };
		case ast::expr::SwizzleKind::e133:
			return { 1, 3, 3 };
		case ast::expr::SwizzleKind::e200:
			return { 2, 0, 0 };
		case ast::expr::SwizzleKind::e201:
			return { 2, 0, 1 };
		case ast::expr::SwizzleKind::e202:
			return { 2, 0, 2 };
		case ast::expr::SwizzleKind::e203:
			return { 2, 0, 3 };
		case ast::expr::SwizzleKind::e210:
			return { 2, 1, 0 };
		case ast::expr::SwizzleKind::e211:
			return { 2, 1, 1 };
		case ast::expr::SwizzleKind::e212:
			return { 2, 1, 2 };
		case ast::expr::SwizzleKind::e213:
			return { 2, 1, 3 };
		case ast::expr::SwizzleKind::e220:
			return { 2, 2, 0 };
		case ast::expr::SwizzleKind::e221:
			return { 2, 2, 1 };
		case ast::expr::SwizzleKind::e222:
			return { 2, 2, 2 };
		case ast::expr::SwizzleKind::e223:
			return { 2, 2, 3 };
		case ast::expr::SwizzleKind::e230:
			return { 2, 3, 0 };
		case ast::expr::SwizzleKind::e231:
			return { 2, 3, 1 };
		case ast::expr::SwizzleKind::e232:
			return { 2, 3, 2 };
		case ast::expr::SwizzleKind::e233:
			return { 2, 3, 3 };
		case ast::expr::SwizzleKind::e300:
			return { 3, 0, 0 };
		case ast::expr::SwizzleKind::e301:
			return { 3, 0, 1 };
		case ast::expr::SwizzleKind::e302:
			return { 3, 0, 2 };
		case ast::expr::SwizzleKind::e303:
			return { 3, 0, 3 };
		case ast::expr::SwizzleKind::e310:
			return { 3, 1, 0 };
		case ast::expr::SwizzleKind::e311:
			return { 3, 1, 1 };
		case ast::expr::SwizzleKind::e312:
			return { 3, 1, 2 };
		case ast::expr::SwizzleKind::e313:
			return { 3, 1, 3 };
		case ast::expr::SwizzleKind::e320:
			return { 3, 2, 0 };
		case ast::expr::SwizzleKind::e321:
			return { 3, 2, 1 };
		case ast::expr::SwizzleKind::e322:
			return { 3, 2, 2 };
		case ast::expr::SwizzleKind::e323:
			return { 3, 2, 3 };
		case ast::expr::SwizzleKind::e330:
			return { 3, 3, 0 };
		case ast::expr::SwizzleKind::e331:
			return { 3, 3, 1 };
		case ast::expr::SwizzleKind::e332:
			return { 3, 3, 2 };
		case ast::expr::SwizzleKind::e333:
			return { 3, 3, 3 };
		case ast::expr::SwizzleKind::e0000:
			return { 0, 0, 0, 0 };
		case ast::expr::SwizzleKind::e0001:
			return { 0, 0, 0, 1 };
		case ast::expr::SwizzleKind::e0002:
			return { 0, 0, 0, 2 };
		case ast::expr::SwizzleKind::e0003:
			return { 0, 0, 0, 3 };
		case ast::expr::SwizzleKind::e0010:
			return { 0, 0, 1, 0 };
		case ast::expr::SwizzleKind::e0011:
			return { 0, 0, 1, 1 };
		case ast::expr::SwizzleKind::e0012:
			return { 0, 0, 1, 2 };
		case ast::expr::SwizzleKind::e0013:
			return { 0, 0, 1, 3 };
		case ast::expr::SwizzleKind::e0020:
			return { 0, 0, 2, 0 };
		case ast::expr::SwizzleKind::e0021:
			return { 0, 0, 2, 1 };
		case ast::expr::SwizzleKind::e0022:
			return { 0, 0, 2, 2 };
		case ast::expr::SwizzleKind::e0023:
			return { 0, 0, 2, 3 };
		case ast::expr::SwizzleKind::e0030:
			return { 0, 0, 3, 0 };
		case ast::expr::SwizzleKind::e0031:
			return { 0, 0, 3, 1 };
		case ast::expr::SwizzleKind::e0032:
			return { 0, 0, 3, 2 };
		case ast::expr::SwizzleKind::e0033:
			return { 0, 0, 3, 3 };
		case ast::expr::SwizzleKind::e0100:
			return { 0, 1, 0, 0 };
		case ast::expr::SwizzleKind::e0101:
			return { 0, 1, 0, 1 };
		case ast::expr::SwizzleKind::e0102:
			return { 0, 1, 0, 2 };
		case ast::expr::SwizzleKind::e0103:
			return { 0, 1, 0, 3 };
		case ast::expr::SwizzleKind::e0110:
			return { 0, 1, 1, 0 };
		case ast::expr::SwizzleKind::e0111:
			return { 0, 1, 1, 1 };
		case ast::expr::SwizzleKind::e0112:
			return { 0, 1, 1, 2 };
		case ast::expr::SwizzleKind::e0113:
			return { 0, 1, 1, 3 };
		case ast::expr::SwizzleKind::e0120:
			return { 0, 1, 2, 0 };
		case ast::expr::SwizzleKind::e0121:
			return { 0, 1, 2, 1 };
		case ast::expr::SwizzleKind::e0122:
			return { 0, 1, 2, 2 };
		case ast::expr::SwizzleKind::e0123:
			return { 0, 1, 2, 3 };
		case ast::expr::SwizzleKind::e0130:
			return { 0, 1, 3, 0 };
		case ast::expr::SwizzleKind::e0131:
			return { 0, 1, 3, 1 };
		case ast::expr::SwizzleKind::e0132:
			return { 0, 1, 3, 2 };
		case ast::expr::SwizzleKind::e0133:
			return { 0, 1, 3, 3 };
		case ast::expr::SwizzleKind::e0200:
			return { 0, 2, 0, 0 };
		case ast::expr::SwizzleKind::e0201:
			return { 0, 2, 0, 1 };
		case ast::expr::SwizzleKind::e0202:
			return { 0, 2, 0, 2 };
		case ast::expr::SwizzleKind::e0203:
			return { 0, 2, 0, 3 };
		case ast::expr::SwizzleKind::e0210:
			return { 0, 2, 1, 0 };
		case ast::expr::SwizzleKind::e0211:
			return { 0, 2, 1, 1 };
		case ast::expr::SwizzleKind::e0212:
			return { 0, 2, 1, 2 };
		case ast::expr::SwizzleKind::e0213:
			return { 0, 2, 1, 3 };
		case ast::expr::SwizzleKind::e0220:
			return { 0, 2, 2, 0 };
		case ast::expr::SwizzleKind::e0221:
			return { 0, 2, 2, 1 };
		case ast::expr::SwizzleKind::e0222:
			return { 0, 2, 2, 2 };
		case ast::expr::SwizzleKind::e0223:
			return { 0, 2, 2, 3 };
		case ast::expr::SwizzleKind::e0230:
			return { 0, 2, 3, 0 };
		case ast::expr::SwizzleKind::e0231:
			return { 0, 2, 3, 1 };
		case ast::expr::SwizzleKind::e0232:
			return { 0, 2, 3, 2 };
		case ast::expr::SwizzleKind::e0233:
			return { 0, 2, 3, 3 };
		case ast::expr::SwizzleKind::e0300:
			return { 0, 3, 0, 0 };
		case ast::expr::SwizzleKind::e0301:
			return { 0, 3, 0, 1 };
		case ast::expr::SwizzleKind::e0302:
			return { 0, 3, 0, 2 };
		case ast::expr::SwizzleKind::e0303:
			return { 0, 3, 0, 3 };
		case ast::expr::SwizzleKind::e0310:
			return { 0, 3, 1, 0 };
		case ast::expr::SwizzleKind::e0311:
			return { 0, 3, 1, 1 };
		case ast::expr::SwizzleKind::e0312:
			return { 0, 3, 1, 2 };
		case ast::expr::SwizzleKind::e0313:
			return { 0, 3, 1, 3 };
		case ast::expr::SwizzleKind::e0320:
			return { 0, 3, 2, 0 };
		case ast::expr::SwizzleKind::e0321:
			return { 0, 3, 2, 1 };
		case ast::expr::SwizzleKind::e0322:
			return { 0, 3, 2, 2 };
		case ast::expr::SwizzleKind::e0323:
			return { 0, 3, 2, 3 };
		case ast::expr::SwizzleKind::e0330:
			return { 0, 3, 3, 0 };
		case ast::expr::SwizzleKind::e0331:
			return { 0, 3, 3, 1 };
		case ast::expr::SwizzleKind::e0332:
			return { 0, 3, 3, 2 };
		case ast::expr::SwizzleKind::e0333:
			return { 0, 3, 3, 3 };
		case ast::expr::SwizzleKind::e1000:
			return { 1, 0, 0, 0 };
		case ast::expr::SwizzleKind::e1001:
			return { 1, 0, 0, 1 };
		case ast::expr::SwizzleKind::e1002:
			return { 1, 0, 0, 2 };
		case ast::expr::SwizzleKind::e1003:
			return { 1, 0, 0, 3 };
		case ast::expr::SwizzleKind::e1010:
			return { 1, 0, 1, 0 };
		case ast::expr::SwizzleKind::e1011:
			return { 1, 0, 1, 1 };
		case ast::expr::SwizzleKind::e1012:
			return { 1, 0, 1, 2 };
		case ast::expr::SwizzleKind::e1013:
			return { 1, 0, 1, 3 };
		case ast::expr::SwizzleKind::e1020:
			return { 1, 0, 2, 0 };
		case ast::expr::SwizzleKind::e1021:
			return { 1, 0, 2, 1 };
		case ast::expr::SwizzleKind::e1022:
			return { 1, 0, 2, 2 };
		case ast::expr::SwizzleKind::e1023:
			return { 1, 0, 2, 3 };
		case ast::expr::SwizzleKind::e1030:
			return { 1, 0, 3, 0 };
		case ast::expr::SwizzleKind::e1031:
			return { 1, 0, 3, 1 };
		case ast::expr::SwizzleKind::e1032:
			return { 1, 0, 3, 2 };
		case ast::expr::SwizzleKind::e1033:
			return { 1, 0, 3, 3 };
		case ast::expr::SwizzleKind::e1100:
			return { 1, 1, 0, 0 };
		case ast::expr::SwizzleKind::e1101:
			return { 1, 1, 0, 1 };
		case ast::expr::SwizzleKind::e1102:
			return { 1, 1, 0, 2 };
		case ast::expr::SwizzleKind::e1103:
			return { 1, 1, 0, 3 };
		case ast::expr::SwizzleKind::e1110:
			return { 1, 1, 1, 0 };
		case ast::expr::SwizzleKind::e1111:
			return { 1, 1, 1, 1 };
		case ast::expr::SwizzleKind::e1112:
			return { 1, 1, 1, 2 };
		case ast::expr::SwizzleKind::e1113:
			return { 1, 1, 1, 3 };
		case ast::expr::SwizzleKind::e1120:
			return { 1, 1, 2, 0 };
		case ast::expr::SwizzleKind::e1121:
			return { 1, 1, 2, 1 };
		case ast::expr::SwizzleKind::e1122:
			return { 1, 1, 2, 2 };
		case ast::expr::SwizzleKind::e1123:
			return { 1, 1, 2, 3 };
		case ast::expr::SwizzleKind::e1130:
			return { 1, 1, 3, 0 };
		case ast::expr::SwizzleKind::e1131:
			return { 1, 1, 3, 1 };
		case ast::expr::SwizzleKind::e1132:
			return { 1, 1, 3, 2 };
		case ast::expr::SwizzleKind::e1133:
			return { 1, 1, 3, 3 };
		case ast::expr::SwizzleKind::e1200:
			return { 1, 2, 0, 0 };
		case ast::expr::SwizzleKind::e1201:
			return { 1, 2, 0, 1 };
		case ast::expr::SwizzleKind::e1202:
			return { 1, 2, 0, 2 };
		case ast::expr::SwizzleKind::e1203:
			return { 1, 2, 0, 3 };
		case ast::expr::SwizzleKind::e1210:
			return { 1, 2, 1, 0 };
		case ast::expr::SwizzleKind::e1211:
			return { 1, 2, 1, 1 };
		case ast::expr::SwizzleKind::e1212:
			return { 1, 2, 1, 2 };
		case ast::expr::SwizzleKind::e1213:
			return { 1, 2, 1, 3 };
		case ast::expr::SwizzleKind::e1220:
			return { 1, 2, 2, 0 };
		case ast::expr::SwizzleKind::e1221:
			return { 1, 2, 2, 1 };
		case ast::expr::SwizzleKind::e1222:
			return { 1, 2, 2, 2 };
		case ast::expr::SwizzleKind::e1223:
			return { 1, 2, 2, 3 };
		case ast::expr::SwizzleKind::e1230:
			return { 1, 2, 3, 0 };
		case ast::expr::SwizzleKind::e1231:
			return { 1, 2, 3, 1 };
		case ast::expr::SwizzleKind::e1232:
			return { 1, 2, 3, 2 };
		case ast::expr::SwizzleKind::e1233:
			return { 1, 2, 3, 3 };
		case ast::expr::SwizzleKind::e1300:
			return { 1, 3, 0, 0 };
		case ast::expr::SwizzleKind::e1301:
			return { 1, 3, 0, 1 };
		case ast::expr::SwizzleKind::e1302:
			return { 1, 3, 0, 2 };
		case ast::expr::SwizzleKind::e1303:
			return { 1, 3, 0, 3 };
		case ast::expr::SwizzleKind::e1310:
			return { 1, 3, 1, 0 };
		case ast::expr::SwizzleKind::e1311:
			return { 1, 3, 1, 1 };
		case ast::expr::SwizzleKind::e1312:
			return { 1, 3, 1, 2 };
		case ast::expr::SwizzleKind::e1313:
			return { 1, 3, 1, 3 };
		case ast::expr::SwizzleKind::e1320:
			return { 1, 3, 2, 0 };
		case ast::expr::SwizzleKind::e1321:
			return { 1, 3, 2, 1 };
		case ast::expr::SwizzleKind::e1322:
			return { 1, 3, 2, 2 };
		case ast::expr::SwizzleKind::e1323:
			return { 1, 3, 2, 3 };
		case ast::expr::SwizzleKind::e1330:
			return { 1, 3, 3, 0 };
		case ast::expr::SwizzleKind::e1331:
			return { 1, 3, 3, 1 };
		case ast::expr::SwizzleKind::e1332:
			return { 1, 3, 3, 2 };
		case ast::expr::SwizzleKind::e1333:
			return { 1, 3, 3, 3 };
		case ast::expr::SwizzleKind::e2000:
			return { 2, 0, 0, 0 };
		case ast::expr::SwizzleKind::e2001:
			return { 2, 0, 0, 1 };
		case ast::expr::SwizzleKind::e2002:
			return { 2, 0, 0, 2 };
		case ast::expr::SwizzleKind::e2003:
			return { 2, 0, 0, 3 };
		case ast::expr::SwizzleKind::e2010:
			return { 2, 0, 1, 0 };
		case ast::expr::SwizzleKind::e2011:
			return { 2, 0, 1, 1 };
		case ast::expr::SwizzleKind::e2012:
			return { 2, 0, 1, 2 };
		case ast::expr::SwizzleKind::e2013:
			return { 2, 0, 1, 3 };
		case ast::expr::SwizzleKind::e2020:
			return { 2, 0, 2, 0 };
		case ast::expr::SwizzleKind::e2021:
			return { 2, 0, 2, 1 };
		case ast::expr::SwizzleKind::e2022:
			return { 2, 0, 2, 2 };
		case ast::expr::SwizzleKind::e2023:
			return { 2, 0, 2, 3 };
		case ast::expr::SwizzleKind::e2030:
			return { 2, 0, 3, 0 };
		case ast::expr::SwizzleKind::e2031:
			return { 2, 0, 3, 1 };
		case ast::expr::SwizzleKind::e2032:
			return { 2, 0, 3, 2 };
		case ast::expr::SwizzleKind::e2033:
			return { 2, 0, 3, 3 };
		case ast::expr::SwizzleKind::e2100:
			return { 2, 1, 0, 0 };
		case ast::expr::SwizzleKind::e2101:
			return { 2, 1, 0, 1 };
		case ast::expr::SwizzleKind::e2102:
			return { 2, 1, 0, 2 };
		case ast::expr::SwizzleKind::e2103:
			return { 2, 1, 0, 3 };
		case ast::expr::SwizzleKind::e2110:
			return { 2, 1, 1, 0 };
		case ast::expr::SwizzleKind::e2111:
			return { 2, 1, 1, 1 };
		case ast::expr::SwizzleKind::e2112:
			return { 2, 1, 1, 2 };
		case ast::expr::SwizzleKind::e2113:
			return { 2, 1, 1, 3 };
		case ast::expr::SwizzleKind::e2120:
			return { 2, 1, 2, 0 };
		case ast::expr::SwizzleKind::e2121:
			return { 2, 1, 2, 1 };
		case ast::expr::SwizzleKind::e2122:
			return { 2, 1, 2, 2 };
		case ast::expr::SwizzleKind::e2123:
			return { 2, 1, 2, 3 };
		case ast::expr::SwizzleKind::e2130:
			return { 2, 1, 3, 0 };
		case ast::expr::SwizzleKind::e2131:
			return { 2, 1, 3, 1 };
		case ast::expr::SwizzleKind::e2132:
			return { 2, 1, 3, 2 };
		case ast::expr::SwizzleKind::e2133:
			return { 2, 1, 3, 3 };
		case ast::expr::SwizzleKind::e2200:
			return { 2, 2, 0, 0 };
		case ast::expr::SwizzleKind::e2201:
			return { 2, 2, 0, 1 };
		case ast::expr::SwizzleKind::e2202:
			return { 2, 2, 0, 2 };
		case ast::expr::SwizzleKind::e2203:
			return { 2, 2, 0, 3 };
		case ast::expr::SwizzleKind::e2210:
			return { 2, 2, 1, 0 };
		case ast::expr::SwizzleKind::e2211:
			return { 2, 2, 1, 1 };
		case ast::expr::SwizzleKind::e2212:
			return { 2, 2, 1, 2 };
		case ast::expr::SwizzleKind::e2213:
			return { 2, 2, 1, 3 };
		case ast::expr::SwizzleKind::e2220:
			return { 2, 2, 2, 0 };
		case ast::expr::SwizzleKind::e2221:
			return { 2, 2, 2, 1 };
		case ast::expr::SwizzleKind::e2222:
			return { 2, 2, 2, 2 };
		case ast::expr::SwizzleKind::e2223:
			return { 2, 2, 2, 3 };
		case ast::expr::SwizzleKind::e2230:
			return { 2, 2, 3, 0 };
		case ast::expr::SwizzleKind::e2231:
			return { 2, 2, 3, 1 };
		case ast::expr::SwizzleKind::e2232:
			return { 2, 2, 3, 2 };
		case ast::expr::SwizzleKind::e2233:
			return { 2, 2, 3, 3 };
		case ast::expr::SwizzleKind::e2300:
			return { 2, 3, 0, 0 };
		case ast::expr::SwizzleKind::e2301:
			return { 2, 3, 0, 1 };
		case ast::expr::SwizzleKind::e2302:
			return { 2, 3, 0, 2 };
		case ast::expr::SwizzleKind::e2303:
			return { 2, 3, 0, 3 };
		case ast::expr::SwizzleKind::e2310:
			return { 2, 3, 1, 0 };
		case ast::expr::SwizzleKind::e2311:
			return { 2, 3, 1, 1 };
		case ast::expr::SwizzleKind::e2312:
			return { 2, 3, 1, 2 };
		case ast::expr::SwizzleKind::e2313:
			return { 2, 3, 1, 3 };
		case ast::expr::SwizzleKind::e2320:
			return { 2, 3, 2, 0 };
		case ast::expr::SwizzleKind::e2321:
			return { 2, 3, 2, 1 };
		case ast::expr::SwizzleKind::e2322:
			return { 2, 3, 2, 2 };
		case ast::expr::SwizzleKind::e2323:
			return { 2, 3, 2, 3 };
		case ast::expr::SwizzleKind::e2330:
			return { 2, 3, 3, 0 };
		case ast::expr::SwizzleKind::e2331:
			return { 2, 3, 3, 1 };
		case ast::expr::SwizzleKind::e2332:
			return { 2, 3, 3, 2 };
		case ast::expr::SwizzleKind::e2333:
			return { 2, 3, 3, 3 };
		case ast::expr::SwizzleKind::e3000:
			return { 3, 0, 0, 0 };
		case ast::expr::SwizzleKind::e3001:
			return { 3, 0, 0, 1 };
		case ast::expr::SwizzleKind::e3002:
			return { 3, 0, 0, 2 };
		case ast::expr::SwizzleKind::e3003:
			return { 3, 0, 0, 3 };
		case ast::expr::SwizzleKind::e3010:
			return { 3, 0, 1, 0 };
		case ast::expr::SwizzleKind::e3011:
			return { 3, 0, 1, 1 };
		case ast::expr::SwizzleKind::e3012:
			return { 3, 0, 1, 2 };
		case ast::expr::SwizzleKind::e3013:
			return { 3, 0, 1, 3 };
		case ast::expr::SwizzleKind::e3020:
			return { 3, 0, 2, 0 };
		case ast::expr::SwizzleKind::e3021:
			return { 3, 0, 2, 1 };
		case ast::expr::SwizzleKind::e3022:
			return { 3, 0, 2, 2 };
		case ast::expr::SwizzleKind::e3023:
			return { 3, 0, 2, 3 };
		case ast::expr::SwizzleKind::e3030:
			return { 3, 0, 3, 0 };
		case ast::expr::SwizzleKind::e3031:
			return { 3, 0, 3, 1 };
		case ast::expr::SwizzleKind::e3032:
			return { 3, 0, 3, 2 };
		case ast::expr::SwizzleKind::e3033:
			return { 3, 0, 3, 3 };
		case ast::expr::SwizzleKind::e3100:
			return { 3, 1, 0, 0 };
		case ast::expr::SwizzleKind::e3101:
			return { 3, 1, 0, 1 };
		case ast::expr::SwizzleKind::e3102:
			return { 3, 1, 0, 2 };
		case ast::expr::SwizzleKind::e3103:
			return { 3, 1, 0, 3 };
		case ast::expr::SwizzleKind::e3110:
			return { 3, 1, 1, 0 };
		case ast::expr::SwizzleKind::e3111:
			return { 3, 1, 1, 1 };
		case ast::expr::SwizzleKind::e3112:
			return { 3, 1, 1, 2 };
		case ast::expr::SwizzleKind::e3113:
			return { 3, 1, 1, 3 };
		case ast::expr::SwizzleKind::e3120:
			return { 3, 1, 2, 0 };
		case ast::expr::SwizzleKind::e3121:
			return { 3, 1, 2, 1 };
		case ast::expr::SwizzleKind::e3122:
			return { 3, 1, 2, 2 };
		case ast::expr::SwizzleKind::e3123:
			return { 3, 1, 2, 3 };
		case ast::expr::SwizzleKind::e3130:
			return { 3, 1, 3, 0 };
		case ast::expr::SwizzleKind::e3131:
			return { 3, 1, 3, 1 };
		case ast::expr::SwizzleKind::e3132:
			return { 3, 1, 3, 2 };
		case ast::expr::SwizzleKind::e3133:
			return { 3, 1, 3, 3 };
		case ast::expr::SwizzleKind::e3200:
			return { 3, 2, 0, 0 };
		case ast::expr::SwizzleKind::e3201:
			return { 3, 2, 0, 1 };
		case ast::expr::SwizzleKind::e3202:
			return { 3, 2, 0, 2 };
		case ast::expr::SwizzleKind::e3203:
			return { 3, 2, 0, 3 };
		case ast::expr::SwizzleKind::e3210:
			return { 3, 2, 1, 0 };
		case ast::expr::SwizzleKind::e3211:
			return { 3, 2, 1, 1 };
		case ast::expr::SwizzleKind::e3212:
			return { 3, 2, 1, 2 };
		case ast::expr::SwizzleKind::e3213:
			return { 3, 2, 1, 3 };
		case ast::expr::SwizzleKind::e3220:
			return { 3, 2, 2, 0 };
		case ast::expr::SwizzleKind::e3221:
			return { 3, 2, 2, 1 };
		case ast::expr::SwizzleKind::e3222:
			return { 3, 2, 2, 2 };
		case ast::expr::SwizzleKind::e3223:
			return { 3, 2, 2, 3 };
		case ast::expr::SwizzleKind::e3230:
			return { 3, 2, 3, 0 };
		case ast::expr::SwizzleKind::e3231:
			return { 3, 2, 3, 1 };
		case ast::expr::SwizzleKind::e3232:
			return { 3, 2, 3, 2 };
		case ast::expr::SwizzleKind::e3233:
			return { 3, 2, 3, 3 };
		case ast::expr::SwizzleKind::e3300:
			return { 3, 3, 0, 0 };
		case ast::expr::SwizzleKind::e3301:
			return { 3, 3, 0, 1 };
		case ast::expr::SwizzleKind::e3302:
			return { 3, 3, 0, 2 };
		case ast::expr::SwizzleKind::e3303:
			return { 3, 3, 0, 3 };
		case ast::expr::SwizzleKind::e3310:
			return { 3, 3, 1, 0 };
		case ast::expr::SwizzleKind::e3311:
			return { 3, 3, 1, 1 };
		case ast::expr::SwizzleKind::e3312:
			return { 3, 3, 1, 2 };
		case ast::expr::SwizzleKind::e3313:
			return { 3, 3, 1, 3 };
		case ast::expr::SwizzleKind::e3320:
			return { 3, 3, 2, 0 };
		case ast::expr::SwizzleKind::e3321:
			return { 3, 3, 2, 1 };
		case ast::expr::SwizzleKind::e3322:
			return { 3, 3, 2, 2 };
		case ast::expr::SwizzleKind::e3323:
			return { 3, 3, 2, 3 };
		case ast::expr::SwizzleKind::e3330:
			return { 3, 3, 3, 0 };
		case ast::expr::SwizzleKind::e3331:
			return { 3, 3, 3, 1 };
		case ast::expr::SwizzleKind::e3332:
			return { 3, 3, 3, 2 };
		case ast::expr::SwizzleKind::e3333:
			return { 3, 3, 3, 3 };
		default:
			assert( false && "Unsupported SwizzleKind." );
			return {};
		}
	}

	IdList getSwizzleComponents( uint32_t totalComponents
		, ast::expr::SwizzleKind swizzle )
	{
		auto result = getSwizzleComponents( swizzle );
		IdList lhsComponents( totalComponents );
		std::iota( lhsComponents.begin(), lhsComponents.end(), 0u );

		for ( auto & comp : result )
		{
			lhsComponents.erase( std::find( lhsComponents.begin(), lhsComponents.end(), comp ) );
			comp += totalComponents;
		}

		result.insert( result.end()
			, lhsComponents.begin()
			, lhsComponents.end() );
		return result;
	}
}
