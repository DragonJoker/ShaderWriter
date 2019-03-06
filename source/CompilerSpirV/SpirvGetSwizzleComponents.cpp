/*
See LICENSE file in root folder
*/
#include "SpirvGetSwizzleComponents.hpp"

#include <algorithm>
#include <numeric>

namespace spirv
{
	std::vector< uint32_t > getSwizzleComponents( ast::expr::SwizzleKind kind )
	{
		switch ( ast::expr::SwizzleKind::Value( kind ) )
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

	std::vector< uint32_t > getSwizzle2Components( ast::expr::SwizzleKind swizzle )
	{
		switch ( ast::expr::SwizzleKind::Value( swizzle ) )
		{
		case ast::expr::SwizzleKind::e01:
			return { 0, 1 };
		case ast::expr::SwizzleKind::e10:
			return { 1, 0 };
		default:
			assert( false && "Impossible LHS swizzle kind for 2 components vector" );
			return {};
		}
	}

	std::vector< uint32_t > getSwizzle3Components( ast::expr::SwizzleKind swizzle )
	{
		switch ( ast::expr::SwizzleKind::Value( swizzle ) )
		{
		case ast::expr::SwizzleKind::e012:
			return { 0, 1, 2 };
		case ast::expr::SwizzleKind::e021:
			return { 0, 2, 1 };
		case ast::expr::SwizzleKind::e102:
			return { 1, 0, 2 };
		case ast::expr::SwizzleKind::e120:
			return { 1, 2, 0 };
		case ast::expr::SwizzleKind::e201:
			return { 2, 0, 1 };
		case ast::expr::SwizzleKind::e210:
			return { 2, 1, 0 };
		default:
			assert( false && "Impossible LHS swizzle kind for 3 components vector" );
			return {};
		}
	}

	std::vector< uint32_t > getSwizzle4Components( ast::expr::SwizzleKind swizzle )
	{
		switch ( ast::expr::SwizzleKind::Value( swizzle ) )
		{
		case ast::expr::SwizzleKind::e0123:
			return { 0, 1, 2, 3 };
		case ast::expr::SwizzleKind::e0132:
			return { 0, 1, 3, 2 };
		case ast::expr::SwizzleKind::e0213:
			return { 0, 2, 1, 3 };
		case ast::expr::SwizzleKind::e0231:
			return { 0, 2, 3, 1 };
		case ast::expr::SwizzleKind::e0312:
			return { 0, 3, 1, 2 };
		case ast::expr::SwizzleKind::e0321:
			return { 0, 3, 2, 1 };
		case ast::expr::SwizzleKind::e1023:
			return { 1, 0, 2, 3 };
		case ast::expr::SwizzleKind::e1032:
			return { 1, 0, 3, 2 };
		case ast::expr::SwizzleKind::e1230:
			return { 1, 2, 3, 0 };
		case ast::expr::SwizzleKind::e1302:
			return { 1, 3, 0, 2 };
		case ast::expr::SwizzleKind::e1320:
			return { 1, 3, 2, 0 };
		case ast::expr::SwizzleKind::e2013:
			return { 2, 0, 1, 3 };
		case ast::expr::SwizzleKind::e2031:
			return { 2, 0, 3, 1 };
		case ast::expr::SwizzleKind::e2103:
			return { 2, 1, 0, 3 };
		case ast::expr::SwizzleKind::e2130:
			return { 2, 1, 3, 0 };
		case ast::expr::SwizzleKind::e2301:
			return { 2, 3, 0, 1 };
		case ast::expr::SwizzleKind::e2310:
			return { 2, 3, 1, 0 };
		case ast::expr::SwizzleKind::e3012:
			return { 3, 0, 1, 2 };
		case ast::expr::SwizzleKind::e3021:
			return { 3, 0, 2, 1 };
		case ast::expr::SwizzleKind::e3102:
			return { 3, 1, 0, 2 };
		case ast::expr::SwizzleKind::e3120:
			return { 3, 1, 2, 0 };
		case ast::expr::SwizzleKind::e3201:
			return { 3, 2, 0, 1 };
		case ast::expr::SwizzleKind::e3210:
			return { 3, 2, 1, 0 };
		default:
			assert( false && "Impossible LHS swizzle kind for 3 components vector" );
			return {};
		}
	}

	IdList fillVec2Swizzle( ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle )
	{
		std::vector< uint32_t > result;
		auto rhs = getSwizzleComponents( rhsSwizzle );
		std::transform( rhs.begin()
			, rhs.end()
			, rhs.begin()
			, []( uint32_t v )
			{
				return v + 2u;
			} );
		assert( !rhs.empty() );

		if ( rhs.size() == 1u )
		{
			switch ( ast::expr::SwizzleKind::Value( lhsSwizzle ) )
			{
			case ast::expr::SwizzleKind::e0:
				// lhs.x = rhs.c => lhs = vec2(rhs.c, lhs.y)
				result = { rhs[0u], 1u };
				break;
			case ast::expr::SwizzleKind::e1:
				// lhs.y = rhs.c => lhs = vec2(lhs.x, rhs.c)
				result = { 0u, rhs[0u] };
				break;
			default:
				assert( false && "Impossible LHS swizzle kind" );
				break;
			}
		}
		else if ( rhs.size() == 2u )
		{
			auto lhs = getSwizzle2Components( lhsSwizzle );
			assert( lhs.size() == rhs.size() );
			result = { rhs[lhs[0u]], rhs[lhs[1u]] };
		}

		assert( result.size() == 2u );
		return result;
	}

	IdList fillVec3Swizzle( ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle )
	{
		std::vector< uint32_t > result;
		auto rhs = getSwizzleComponents( rhsSwizzle );
		std::transform( rhs.begin()
			, rhs.end()
			, rhs.begin()
			, []( uint32_t v )
			{
				return v + 3u;
			} );
		assert( !rhs.empty() );

		if ( rhs.size() == 1u )
		{
			switch ( ast::expr::SwizzleKind::Value( lhsSwizzle ) )
			{
			case ast::expr::SwizzleKind::e0:
				// lhs.x = rhs.c => lhs = vec3(rhs.c, lhs.y, lhs.z)
				result = { rhs[0u], 1u, 2u };
				break;
			case ast::expr::SwizzleKind::e1:
				// lhs.y = rhs.c => lhs = vec3(lhs.x, rhs.c, lhs.z)
				result = { 0u, rhs[0u], 2u };
				break;
			case ast::expr::SwizzleKind::e2:
				// lhs.z = rhs.c => lhs = vec3(lhs.x, lhs.y, rhs.c)
				result = { 0u, 1u, rhs[0u] };
				break;
			default:
				assert( false && "Impossible LHS swizzle kind" );
				break;
			}
		}
		else if ( rhs.size() == 2u )
		{
			switch ( ast::expr::SwizzleKind::Value( lhsSwizzle ) )
			{
			case ast::expr::SwizzleKind::e01:
				// lhs.xy = rhs.cMcN => lhs = vec3(rhs.cM, rhs.cN, lhs.z)
				result = { rhs[0u], rhs[1u], 2u };
				break;
			case ast::expr::SwizzleKind::e02:
				// lhs.xz = rhs.cMcN => lhs = vec3(rhs.cM, lhs.y, rhs.cN)
				result = { rhs[0u], 1u, rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e10:
				// lhs.yx = rhs.cMcN => lhs = vec3(rhs.cN, rhs.cM, lhs.z)
				result = { rhs[1u], rhs[0u], 2u };
				break;
			case ast::expr::SwizzleKind::e12:
				// lhs.yz = rhs.cMcN => lhs = vec3(lhs.x, rhs.cM, rhs.cN)
				result = { 0u, rhs[0u], rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e20:
				// lhs.zx = rhs.cMcN => lhs = vec3(rhs.cN, lhs.y, rhs.cM)
				result = { rhs[1u], 1u, rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e21:
				// lhs.zy = rhs.cMcN => lhs = vec3(lhs.x, rhs.cN, rhs.cM)
				result = { 0u, rhs[1u], rhs[0u] };
				break;
			default:
				assert( false && "Impossible LHS swizzle kind" );
				break;
			}
		}
		else if ( rhs.size() == 3u )
		{
			auto lhs = getSwizzle3Components( lhsSwizzle );
			assert( lhs.size() == rhs.size() );
			result = { rhs[lhs[0u]], rhs[lhs[1u]], rhs[lhs[2u]] };
		}

		assert( result.size() == 3u );
		return result;
	}

	IdList fillVec4Swizzle( ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle )
	{
		std::vector< uint32_t > result;
		auto rhs = getSwizzleComponents( rhsSwizzle );
		std::transform( rhs.begin()
			, rhs.end()
			, rhs.begin()
			, []( uint32_t v )
			{
				return v + 4u;
			} );
		assert( !rhs.empty() );

		if ( rhs.size() == 1u )
		{
			switch ( ast::expr::SwizzleKind::Value( lhsSwizzle ) )
			{
			case ast::expr::SwizzleKind::e0:
				// lhs.x = rhs.c => lhs = vec4(rhs.c, lhs.y, lhs.z, lhs.w)
				result = { rhs[0u], 1u, 2u, 3u };
				break;
			case ast::expr::SwizzleKind::e1:
				// lhs.y = rhs.c => lhs = vec4(lhs.x, rhs.c, lhs.z, lhs.w)
				result = { 0u, rhs[0u], 2u, 3u };
				break;
			case ast::expr::SwizzleKind::e2:
				// lhs.z = rhs.c => lhs = vec4(lhs.x, lhs.y, rhs.c, lhs.w)
				result = { 0u, 1u, rhs[0u], 3u };
				break;
			case ast::expr::SwizzleKind::e3:
				// lhs.w = rhs.c => lhs = vec4(lhs.x, lhs.y, lhs.z, rhs.c)
				result = { 0u, 1u, 2u, rhs[0u] };
				break;
			default:
				assert( false && "Impossible LHS swizzle kind" );
				break;
			}
		}
		else if ( rhs.size() == 2u )
		{
			switch ( ast::expr::SwizzleKind::Value( lhsSwizzle ) )
			{
			case ast::expr::SwizzleKind::e01:
				// lhs.xy = rhs.cMcN => lhs = vec4(rhs.cM, rhs.cN, lhs.z, lhs.w)
				result = { rhs[0u], rhs[1u], 2u, 3u };
				break;
			case ast::expr::SwizzleKind::e02:
				// lhs.xz = rhs.cMcN => lhs = vec4(rhs.cM, lhs.y, rhs.cN, lhs.w)
				result = { rhs[0u], 1u, rhs[1u], 3u };
				break;
			case ast::expr::SwizzleKind::e03:
				// lhs.xw = rhs.cMcN => lhs = vec4(rhs.cM, lhs.y, lhs.z, rhs.cN)
				result = { rhs[0u], 1u, 2u, rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e10:
				// lhs.yx = rhs.cMcN => lhs = vec4(rhs.cN, rhs.cM, lhs.z, lhs.w)
				result = { rhs[1u], rhs[0u], 2u, 3u };
				break;
			case ast::expr::SwizzleKind::e12:
				// lhs.yz = rhs.cMcN => lhs = vec4(lhs.x, rhs.cM, rhs.cN, lhs.w)
				result = { 0u, rhs[0u], rhs[1u], 3u };
				break;
			case ast::expr::SwizzleKind::e13:
				// lhs.yw = rhs.cMcN => lhs = vec4(lhs.x, rhs.cM, lhs.z, rhs.cN)
				result = { 0u, rhs[0u], 2u, rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e20:
				// lhs.zx = rhs.cMcN => lhs = vec4(rhs.cN, lhs.y, rhs.cM, lhs.w)
				result = { rhs[1u], 1u, rhs[0u], 3u };
				break;
			case ast::expr::SwizzleKind::e21:
				// lhs.zy = rhs.cMcN => lhs = vec4(lhs.x, rhs.cN, rhs.cM, lhs.w)
				result = { 0u, rhs[1u], rhs[0u], 3u };
				break;
			case ast::expr::SwizzleKind::e23:
				// lhs.zw = rhs.cMcN => lhs = vec4(lhs.x, lhs.y, rhs.cM, rhs.cN)
				result = { 0u, 1u, rhs[0u], rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e30:
				// lhs.wx = rhs.cMcN => lhs = vec4(rhs.cN, lhs.y, lhs.z, rhs.cM)
				result = { rhs[1u], 1u, 2u, rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e31:
				// lhs.wy = rhs.cMcN => lhs = vec4(lhs.x, rhs.cN, lhs.z, rhs.cM)
				result = { 0u, rhs[1u], 2u, rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e32:
				// lhs.wz = rhs.cMcN => lhs = vec4(lhs.x, lhs.y, rhs.cN, rhs.cM)
				result = { 0u, 1u, rhs[1u], rhs[0u] };
				break;
			default:
				assert( false && "Impossible LHS swizzle kind" );
				break;
			}
		}
		else if ( rhs.size() == 3u )
		{
			switch ( ast::expr::SwizzleKind::Value( lhsSwizzle ) )
			{
			case ast::expr::SwizzleKind::e012:
				// lhs.xyz = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cN, rhs.cO, lhs.w)
				result = { rhs[0u], rhs[1u], rhs[2u], 3u };
				break;
			case ast::expr::SwizzleKind::e013:
				// lhs.xyw = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cN, lhs.z, rhs.cO)
				result = { rhs[0u], rhs[1u], 2u, rhs[2u] };
				break;
			case ast::expr::SwizzleKind::e021:
				// lhs.xzy = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cO, rhs.cN, lhs.w)
				result = { rhs[0u], rhs[2u], rhs[1u], 3u };
				break;
			case ast::expr::SwizzleKind::e023:
				// lhs.xzw = rhs.cMcNcO => lhs = vec4(rhs.cM, lhs.y, rhs.cN, rhs.cO)
				result = { rhs[0u], rhs[1u], 2u, rhs[2u] };
				break;
			case ast::expr::SwizzleKind::e031:
				// lhs.xwy = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cO, lhs.z, rhs.cN)
				result = { rhs[0u], rhs[2u], 2u, rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e032:
				// lhs.xwz = rhs.cMcNcO => lhs = vec4(rhs.cM, lhs.y, rhs.cO, rhs.cN)
				result = { rhs[0u], 1u, rhs[2u], rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e102:
				// lhs.yxz = rhs.cMcNcO => lhs = vec4(rhs.cN, rhs.cM, rhs.cO, lhs.w)
				result = { rhs[1u], rhs[0u], rhs[2u], 3u };
				break;
			case ast::expr::SwizzleKind::e103:
				// lhs.yxw = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cN, lhs.z, rhs.cO)
				result = { rhs[1u], rhs[0u], 2u, rhs[2u] };
				break;
			case ast::expr::SwizzleKind::e120:
				// lhs.yzx = rhs.cMcNcO => lhs = vec4(rhs.cO, rhs.cM, rhs.cN, lhs.w)
				result = { rhs[2u], rhs[0u], rhs[1u], 3u };
				break;
			case ast::expr::SwizzleKind::e123:
				// lhs.yzw = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cM, rhs.cN, rhs.cO)
				result = { 0u, rhs[0u], rhs[1u], rhs[2u] };
				break;
			case ast::expr::SwizzleKind::e130:
				// lhs.ywx = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cO, lhs.z, rhs.cN)
				result = { rhs[2u], rhs[0u], 2u, rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e132:
				// lhs.ywz = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cM, rhs.cO, rhs.cN)
				result = { 0u, rhs[0u], rhs[2u], rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e201:
				// lhs.zxy = rhs.cMcNcO => lhs = vec4(rhs.cN, rhs.cO, rhs.cM, lhs.w)
				result = { rhs[1u], rhs[2u], rhs[0u], 3u };
				break;
			case ast::expr::SwizzleKind::e203:
				// lhs.zxw = rhs.cMcNcO => lhs = vec4(rhs.cN, lhs.y, rhs.cM, rhs.cO)
				result = { rhs[1u], 1u, rhs[0u], rhs[2u] };
				break;
			case ast::expr::SwizzleKind::e210:
				// lhs.zyx = rhs.cMcNcO => lhs = vec4(rhs.cO, rhs.cN, rhs.cM, lhs.w)
				result = { rhs[2u], rhs[1u], rhs[0u], 3u };
				break;
			case ast::expr::SwizzleKind::e213:
				// lhs.zyw = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cN, rhs.cM, rhs.cO)
				result = { 0u, rhs[1u], rhs[0u], rhs[2u] };
				break;
			case ast::expr::SwizzleKind::e230:
				// lhs.zwx = rhs.cMcNcO => lhs = vec4(rhs.cO, lhs.y, rhs.cM, rhs.cN)
				result = { rhs[2u], 1u, rhs[0u], rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e231:
				// lhs.zwy = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cO, rhs.cM, rhs.cN)
				result = { 0u, rhs[2u], rhs[0u], rhs[1u] };
				break;
			case ast::expr::SwizzleKind::e301:
				// lhs.wxy = rhs.cMcNcO => lhs = vec4(rhs.cN, rhs.cO, lhs.z, rhs.cM)
				result = { rhs[1u], rhs[2u], 2u, rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e302:
				// lhs.wxz = rhs.cMcNcO => lhs = vec4(rhs.cN, lhs.y, rhs.cO, rhs.cM)
				result = { rhs[1u], 1u, rhs[2u], rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e310:
				// lhs.wyx = rhs.cMcNcO => lhs = vec4(rhs.cO, rhs.cN, lhs.z, rhs.cM)
				result = { rhs[2u], rhs[1u], 2u, rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e312:
				// lhs.wyz = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cN, rhs.cO, rhs.cM)
				result = { 0u, rhs[1u], rhs[2u], rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e320:
				// lhs.wzx = rhs.cMcNcO => lhs = vec4(rhs.cO, lhs.y, rhs.cN, rhs.cM)
				result = { rhs[2u], 1u, rhs[1u], rhs[0u] };
				break;
			case ast::expr::SwizzleKind::e321:
				// lhs.wzy = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cO, rhs.cN, rhs.cM)
				result = { 0u, rhs[2u], rhs[1u], rhs[0u] };
				break;
			default:
				assert( false && "Impossible LHS swizzle kind" );
				break;
			}
		}
		else if ( rhs.size() == 4u )
		{
			auto lhs = getSwizzle4Components( lhsSwizzle );
			assert( lhs.size() == rhs.size() );
			result = { rhs[lhs[0u]], rhs[lhs[1u]], rhs[lhs[2u]], rhs[lhs[3u]] };
		}

		assert( result.size() == 4u );
		return result;
	}

	IdList fillSwizzle( ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle
		, uint32_t count )
	{
		IdList result;

		switch ( count )
		{
		case 2:
			result = fillVec2Swizzle( lhsSwizzle, rhsSwizzle );
			break;
		case 3:
			result = fillVec3Swizzle( lhsSwizzle, rhsSwizzle );
			break;
		case 4:
			result = fillVec4Swizzle( lhsSwizzle, rhsSwizzle );
			break;
		default:
			assert( false && "Unsupported components count" );
			break;
		}

		return result;
	}

	IdList getSwizzleComponents( ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle
		, uint32_t componentCount )
	{
		return fillSwizzle( lhsSwizzle, rhsSwizzle, componentCount );
	}

	ast::expr::SwizzleKind getSwizzleComponents( uint32_t count )
	{
		assert( count > 0 && count < 4 );

		switch ( count )
		{
		case 1:
			return ast::expr::SwizzleKind::e0;
		case 2:
			return ast::expr::SwizzleKind::e01;
		default:
			return ast::expr::SwizzleKind::e012;
		}
	}
}
