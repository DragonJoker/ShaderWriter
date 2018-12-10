/*
See LICENSE file in root folder
*/
#include "SpirvExprVisitor.hpp"

#include "SpirvHelpers.hpp"
#include "SpirvImageAccessConfig.hpp"
#include "SpirvImageAccessNames.hpp"
#include "SpirvIntrinsicConfig.hpp"
#include "SpirvIntrinsicNames.hpp"
#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

#include <numeric>
#include <sstream>

namespace spirv
{
	namespace
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

		spv::Id loadVariable( spv::Id varId
			, ast::type::TypePtr type
			, Module & module
			, Block & currentBlock
			, LoadedVariableArray & loadedVariables )
		{
			auto it = std::find_if( loadedVariables.begin()
				, loadedVariables.end()
				, [varId]( LoadedVariable const & lookup )
				{
					return lookup.varId == varId;
				} );

			if ( loadedVariables.end() == it )
			{
				auto loadedRhsId = module.loadVariable( varId
					, type
					, currentBlock );
				loadedVariables.push_back( { varId, loadedRhsId } );
				it = loadedVariables.begin() + loadedVariables.size() - 1u;
			}

			return it->loadedId;
		}

		spv::Id writeShuffle( Module & module
			, Block & currentBlock
			, spv::Id pointerTypeId
			, spv::Id rawTypeId
			, spv::Id outerId
			, ast::expr::SwizzleKind swizzle
			, bool & needsLoad )
		{
			spv::Id result;
			auto swizzleComponents = getSwizzleComponents( swizzle );
			spirv::IdList shuffle;

			if ( swizzleComponents.size() == 1u )
			{
				shuffle.push_back( outerId );
				shuffle.push_back( swizzleComponents.front() );
				auto it = currentBlock.vectorShuffles.find( shuffle );

				if ( it == currentBlock.vectorShuffles.end() )
				{
					auto intermediateId = module.getIntermediateResult();
					currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( rawTypeId
						, intermediateId
						, shuffle ) );
					it = currentBlock.vectorShuffles.emplace( shuffle, intermediateId ).first;
				}

				needsLoad = false;
				result = it->second;
			}
			else
			{
				shuffle.push_back( outerId );
				shuffle.push_back( outerId );
				//shuffle.push_back( spv::Id( spv::Op::OpUndef ) );
				shuffle.insert( shuffle.end(), swizzleComponents.begin(), swizzleComponents.end() );
				auto it = currentBlock.vectorShuffles.find( shuffle );

				if ( it == currentBlock.vectorShuffles.end() )
				{
					auto intermediateId = module.getIntermediateResult();
					currentBlock.instructions.emplace_back( makeInstruction< VectorShuffleInstruction >( rawTypeId
						, intermediateId
						, shuffle ) );
					it = currentBlock.vectorShuffles.emplace( shuffle, intermediateId ).first;
				}

				needsLoad = true;
				result = it->second;
			}

			return result;
		}

		bool isAccessChain( ast::expr::Expr * expr )
		{
			return expr->getKind() == ast::expr::Kind::eArrayAccess
				|| expr->getKind() == ast::expr::Kind::eMbrSelect
				|| ( expr->getKind() == ast::expr::Kind::eSwizzle
					&& !isScalarType( expr->getType()->getKind() ) )
				|| ( expr->getKind() == ast::expr::Kind::eIdentifier
					&& static_cast< ast::expr::Identifier const & >( *expr ).getVariable()->isMember() );
		}

		spv::Id makeAccessChain( ast::expr::Expr * expr
			, Module & module
			, Block & currentBlock
			, LoadedVariableArray & loadedVariables );

		class AccessChainLineariser
			: public ast::expr::SimpleVisitor
		{
		public:
			static std::vector< ast::expr::Expr * > submit( ast::expr::Expr * expr
				, ast::expr::ExprList & idents )
			{
				std::vector< ast::expr::Expr * > result;
				AccessChainLineariser vis{ result, idents };
				expr->accept( &vis );
				return result;
			}

		private:
			AccessChainLineariser( std::vector< ast::expr::Expr * > & result
				, ast::expr::ExprList & idents )
				: m_result{ result }
				, m_idents{ idents }
			{
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				assert( false && "Unexpected ast::expr::Unary ?" );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				assert( false && "Unexpected ast::expr::Binary ?" );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				auto outer = submit( expr->getOuterExpr(), m_idents );
				auto inner = submit( expr->getOperand(), m_idents );
				m_result = outer;
				m_result.insert( m_result.end(), inner.begin(), inner.end() );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				auto lhs = submit( expr->getLHS(), m_idents );
				m_result = lhs;
				m_result.push_back( expr->getRHS() );
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				if ( expr->getVariable()->isMember()
					&& expr->getType()->isMember() )
				{
					m_idents.emplace_back( sdw::makeIdent( expr->getVariable()->getOuter() ) );
					auto ident = m_idents.back().get();
					m_result = submit( ident, m_idents );
				}

				m_result.push_back( expr );
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				m_result.push_back( expr );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				m_result.push_back( expr );
			}
			
			void visitAggrInitExpr( ast::expr::AggrInit * )override
			{
				assert( false && "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				assert( false && "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall * )override
			{
				assert( false && "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::ImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init * )override
			{
				assert( false && "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * )override
			{
				assert( false && "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question * )override
			{
				assert( false && "Unexpected ast::expr::Question ?" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * )override
			{
				assert( false && "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * )override
			{
				assert( false && "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::TextureAccessCall ?" );
			}

		private:
			std::vector< ast::expr::Expr * > & m_result;
			ast::expr::ExprList & m_idents;
		};

		class AccessChainCreator
			: public ast::expr::SimpleVisitor
		{
		public:
			static IdList submit( std::vector< ast::expr::Expr * > const & exprs
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables )
			{
				IdList result;
				assert( exprs.size() >= 2u );
				VariableInfo info;
				result.push_back( submit( exprs[0]
					, module
					, currentBlock
					, loadedVariables ) );

				for ( size_t i = 1u; i < exprs.size(); ++i )
				{
					auto & expr = exprs[i];
					result.push_back( submit( result.back()
						, exprs[i - 1u]
						, expr
						, module
						, currentBlock
						, loadedVariables
						, info ) );
				}

				return result;
			}

		private:
			AccessChainCreator( spv::Id & result
				, ast::expr::Expr * parentExpr
				, spv::Id parentId
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables
				, VariableInfo & info )
				: m_result{ result }
				, m_module{ module }
				, m_currentBlock{ currentBlock }
				, m_loadedVariables{ loadedVariables }
				, m_parentId{ parentId }
				, m_info{ info }
			{
			}

			static spv::Id submit( ast::expr::Expr * expr
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables )
			{
				spv::Id result;
				VariableInfo info;
				AccessChainCreator vis{ result, nullptr, 0u, module, currentBlock, loadedVariables, info };
				expr->accept( &vis );
				return result;
			}

			static spv::Id submit( spv::Id parentId
				, ast::expr::Expr * parentExpr
				, ast::expr::Expr * expr
				, Module & module
				, Block & currentBlock
				, LoadedVariableArray & loadedVariables
				, VariableInfo & info )
			{
				spv::Id result;
				AccessChainCreator vis{ result, parentExpr, parentId, module, currentBlock, loadedVariables, info };
				expr->accept( &vis );
				return result;
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				assert( false && "Unexpected ast::expr::Unary ?" );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				assert( false && "Unexpected ast::expr::Binary ?" );
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				assert( m_parentId != 0u );
				m_result = submit( expr->getOperand(), m_module, m_currentBlock, m_loadedVariables );
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				assert( m_parentId != 0u );

				if ( isAccessChain( expr->getRHS() ) )
				{
					m_result = makeAccessChain( expr->getRHS(), m_module, m_currentBlock, m_loadedVariables );
				}
				else
				{
					m_result = submit( expr->getRHS(), m_module, m_currentBlock, m_loadedVariables );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				auto var = expr->getVariable();

				if ( m_parentId != 0u )
				{
					// Leaf or Intermediate identifier :
					// Store member only (parent has already be added).
					m_result = m_module.registerMemberVariableIndex( expr->getType() );
				}
				else
				{
					// Head identifier
					m_result = m_module.registerVariable( var->getName()
						, getStorageClass( var )
						, expr->getType()
						, m_info ).id;
				}
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				assert( m_parentId != 0u );

				switch ( expr->getLiteralType() )
				{
				case ast::expr::LiteralType::eBool:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eBool >() );
					break;
				case ast::expr::LiteralType::eInt:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eInt >() );
					break;
				case ast::expr::LiteralType::eUInt:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt >() );
					break;
				case ast::expr::LiteralType::eFloat:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eFloat >() );
					break;
				case ast::expr::LiteralType::eDouble:
					m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eDouble >() );
					break;
				default:
					assert( false && "Unsupported literal type" );
					break;
				}
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				assert( m_parentId != 0u );
				spv::Id parentId;

				if ( isAccessChain( expr->getOuterExpr() ) )
				{
					parentId = makeAccessChain( expr->getOuterExpr()
						, m_module
						, m_currentBlock
						, m_loadedVariables );
				}
				else
				{
					parentId = ExprVisitor::submit( expr->getOuterExpr()
						, m_currentBlock
						, m_module );
				}

				auto rawTypeId = m_module.registerType( expr->getType() );
				auto pointerTypeId = m_module.registerPointerType( rawTypeId, spv::StorageClassFunction );
				bool needsLoad = false;
				auto shuffleId = writeShuffle( m_module, m_currentBlock, pointerTypeId, rawTypeId, parentId, expr->getSwizzle(), needsLoad );
				//m_result = loadVariable( shuffleId
				//	, expr->getType()
				//	, m_module
				//	, m_currentBlock
				//	, m_loadedVariables );
				m_result = shuffleId;
			}

			void visitAggrInitExpr( ast::expr::AggrInit * )override
			{
				assert( false && "Unexpected ast::expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				assert( false && "Unexpected ast::expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( ast::expr::FnCall * )override
			{
				assert( false && "Unexpected ast::expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( ast::expr::ImageAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::ImageAccessCall ?" );
			}

			void visitInitExpr( ast::expr::Init * )override
			{
				assert( false && "Unexpected ast::expr::Init ?" );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * )override
			{
				assert( false && "Unexpected ast::expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( ast::expr::Question * )override
			{
				assert( false && "Unexpected ast::expr::Question ?" );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * )override
			{
				assert( false && "Unexpected ast::expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * )override
			{
				assert( false && "Unexpected ast::expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * )override
			{
				assert( false && "Unexpected ast::expr::TextureAccessCall ?" );
			}

		private:
			spv::Id & m_result;
			Module & m_module;
			Block & m_currentBlock;
			LoadedVariableArray & m_loadedVariables;
			spv::Id m_parentId;
			ast::expr::Expr * m_parentExpr;
			VariableInfo & m_info;
		};

		spv::Id writeAccessChain( Block & currentBlock
			, IdList const & accessChain
			, ast::expr::Expr * expr
			, Module & module
			, LoadedVariableArray & loadedVariables )
		{
			auto it = currentBlock.accessChains.find( accessChain );

			if ( it == currentBlock.accessChains.end() )
			{
			// Reserve the ID for the result.
				auto resultId = module.getIntermediateResult();
				// Register the type pointed to.
				auto rawTypeId = module.registerType( expr->getType() );
				// Register the pointer to the type.
				auto pointerTypeId = module.registerPointerType( rawTypeId
					, getStorageClass( ast::findIdentifier( expr )->getVariable() ) );
				// Write access chain => resultId = pointerTypeId( outer.members + index ).
				currentBlock.instructions.emplace_back( makeInstruction< AccessChainInstruction >( pointerTypeId
					, resultId
					, accessChain ) );
				it = currentBlock.accessChains.emplace( accessChain, resultId ).first;
			}

			return it->second;
		}

		spv::Id makeAccessChain( ast::expr::Expr * expr
			, Module & module
			, Block & currentBlock
			, LoadedVariableArray & loadedVariables )
		{
			// Create Access Chain.
			ast::expr::ExprList idents;
			auto accessChainExprs = AccessChainLineariser::submit( expr, idents );
			auto accessChain = AccessChainCreator::submit( accessChainExprs
				, module
				, currentBlock
				, loadedVariables );
			return writeAccessChain( currentBlock
				, accessChain
				, expr
				, module
				, loadedVariables );
		}

		inline spv::Op getCastOp( ast::type::Kind src, ast::type::Kind dst )
		{
			spv::Op result = spv::Op::OpNop;

			if ( isDoubleType( src ) )
			{
				if ( isFloatType( dst ) )
				{
					result = spv::Op::OpFConvert;
				}
				else if ( isSignedIntType( dst ) )
				{
					result = spv::Op::OpConvertFToS;
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::Op::OpConvertFToU;
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else if ( isFloatType( src ) )
			{
				if ( isDoubleType( dst ) )
				{
					result = spv::Op::OpFConvert;
				}
				else if ( isSignedIntType( dst ) )
				{
					result = spv::Op::OpConvertFToS;
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::Op::OpConvertFToU;
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else if ( isSignedIntType( src ) )
			{
				if ( isDoubleType( dst )
					|| isFloatType( dst ) )
				{
					result = spv::Op::OpConvertSToF;
				}
				else if ( isSignedIntType( dst ) )
				{
				}
				else if ( isUnsignedIntType( dst ) )
				{
					result = spv::Op::OpBitcast;
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else if ( isUnsignedIntType( src ) )
			{
				if ( isDoubleType( dst )
					|| isFloatType( dst ) )
				{
					result = spv::Op::OpConvertUToF;
				}
				else if ( isSignedIntType( dst ) )
				{
					result = spv::Op::OpBitcast;
				}
				else if ( isUnsignedIntType( dst ) )
				{
				}
				else
				{
					assert( false && "Unsupported cast expression" );
				}
			}
			else
			{
				assert( false && "Unsupported cast expression" );
			}

			return result;
		}
	}

	spv::StorageClass getStorageClass( ast::var::VariablePtr var )
	{
		var = getOutermost( var );
		spv::StorageClass result = spv::StorageClassFunction;

		if ( var->isUniform() )
		{
			if ( var->isConstant() )
			{
				result = spv::StorageClassUniformConstant;
			}
			else
			{
				result = spv::StorageClassUniform;
			}
		}
		else if ( var->isBuiltin() )
		{
			if ( var->isShaderInput() )
			{
				result = spv::StorageClassInput;
			}
			else if ( var->isShaderOutput() )
			{
				result = spv::StorageClassOutput;
			}
			else
			{
				assert( false && "Unsupported built-in variable storage." );
			}
		}
		else if ( var->isShaderInput() )
		{
			result = spv::StorageClassInput;
		}
		else if ( var->isShaderOutput() )
		{
			result = spv::StorageClassOutput;
		}
		else if ( var->isShaderConstant() )
		{
			result = spv::StorageClassInput;
		}
		else if ( var->isSpecialisationConstant() )
		{
			assert( false && "Specialisation constants shouldn't be processed as variables" );
		}
		else if ( var->isPushConstant() )
		{
			result = spv::StorageClassPushConstant;
		}

		return result;
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool loadVariable )
	{
		bool allLiterals{ false };
		LoadedVariableArray loadedVariables;
		return submit( expr
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables );
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		bool allLiterals{ false };
		return submit( expr
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables );
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool loadVariable )
	{
		LoadedVariableArray loadedVariables;
		return submit( expr
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables );
	}

	spv::Id ExprVisitor::submit( ast::expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		spv::Id result{ 0u };
		ExprVisitor vis{ result
			, currentBlock
			, module
			, allLiterals
			, loadVariable
			, loadedVariables };
		expr->accept( &vis );
		return result;
	}

	ExprVisitor::ExprVisitor( spv::Id & result
		, Block & currentBlock
		, Module & module
		, bool & allLiterals
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
		: m_result{ result }
		, m_currentBlock{ currentBlock }
		, m_module{ module }
		, m_allLiterals{ allLiterals }
		, m_loadVariable{ loadVariable }
		, m_loadedVariables{ loadedVariables }
	{
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr )
	{
		return submit( expr, m_currentBlock, m_module, m_loadVariable, m_loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, LoadedVariableArray & loadedVariables )
	{
		return submit( expr, m_currentBlock, m_module, m_loadVariable, loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool loadVariable )
	{
		return submit( expr, m_currentBlock, m_module, loadVariable, m_loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		return submit( expr, m_currentBlock, m_module, loadVariable, loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool & allLiterals
		, bool loadVariable )
	{
		return submit( expr, m_currentBlock, m_module, allLiterals, loadVariable, m_loadedVariables );
	}

	spv::Id ExprVisitor::doSubmit( ast::expr::Expr * expr
		, bool & allLiterals
		, bool loadVariable
		, LoadedVariableArray & loadedVariables )
	{
		return submit( expr, m_currentBlock, m_module, allLiterals, loadVariable, loadedVariables );
	}

	void ExprVisitor::visitAssignmentExpr( ast::expr::Assign * expr )
	{
		m_allLiterals = false;
		auto typeId = m_module.registerType( expr->getType() );
		// No load to retrieve the variable ID.
		auto lhsId = getVariableIdNoLoad( expr->getLHS() );
		// Ask for the needed variables to be loaded.
		auto rhsId = doSubmit( expr->getRHS(), true, m_loadedVariables );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( lhsId, rhsId ) );
		m_result = lhsId;
	}

	void ExprVisitor::visitOpAssignmentExpr( ast::expr::Assign * expr )
	{
		m_allLiterals = false;
		auto typeId = m_module.registerType( expr->getType() );
		// No load to retrieve the variable ID.
		auto lhsId = getVariableIdNoLoad( expr->getLHS() );
		// Load the variable manually.
		auto loadedLhsId = loadVariable( lhsId
			, expr->getType() );
		// Ask for the needed variables to be loaded.
		auto rhsId = doSubmit( expr->getRHS()
			, true );
		auto intermediateId = writeBinOpExpr( expr->getKind()
			, expr->getLHS()->getType()->getKind()
			, expr->getRHS()->getType()->getKind()
			, typeId
			, loadedLhsId
			, rhsId
			, expr->getLHS()->isSpecialisationConstant() );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( lhsId, intermediateId ) );
		m_module.putIntermediateResult( intermediateId );
		m_module.putIntermediateResult( loadedLhsId );
		m_result = lhsId;
	}

	void ExprVisitor::visitUnaryExpr( ast::expr::Unary * expr )
	{
		m_allLiterals = false;
		auto operandId = doSubmit( expr->getOperand() );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();

		if ( expr->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( typeId
				, m_result
				, makeOperands( spv::Id( getUnOpCode( expr->getKind(), expr->getType()->getKind() ) )
					, operandId ) ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeUnInstruction( typeId
				, m_result
				, expr->getKind()
				, expr->getType()->getKind()
				, operandId ) );
		}
	}

	void ExprVisitor::visitBinaryExpr( ast::expr::Binary * expr )
	{
		m_allLiterals = false;
		auto lhsId = doSubmit( expr->getLHS() );
		auto loadedLhsId = lhsId;
		auto rhsId = doSubmit( expr->getRHS() );
		auto loadedRhsId = rhsId;
		auto typeId = m_module.registerType( expr->getType() );
		m_result = writeBinOpExpr( expr->getKind()
			, expr->getLHS()->getType()->getKind()
			, expr->getRHS()->getType()->getKind()
			, typeId
			, loadedLhsId
			, loadedRhsId
			, expr->isSpecialisationConstant() );
	}

	void ExprVisitor::visitCastExpr( ast::expr::Cast * expr )
	{
		m_allLiterals = false;
		auto operandId = doSubmit( expr->getOperand() );
		auto dstTypeId = m_module.registerType( expr->getType() );
		auto op = getCastOp( expr->getOperand()->getType()->getKind()
			, expr->getType()->getKind() );

		if ( op == spv::Op::OpNop )
		{
			m_result = operandId;
		}
		else
		{
			m_result = m_module.getIntermediateResult();

			if ( expr->isSpecialisationConstant() )
			{
				m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( dstTypeId
					, m_result
					, makeOperands( spv::Id( op )
						, operandId ) ) );
			}
			else
			{
				m_currentBlock.instructions.emplace_back( makeCastInstruction( dstTypeId
					, m_result
					, op
					, operandId ) );
			}
		}
	}

	void ExprVisitor::visitPreDecrementExpr( ast::expr::PreDecrement * expr )
	{
		m_allLiterals = false;
		auto literal = m_module.registerLiteral( 1 );
		auto operandId = doSubmit( expr->getOperand(), true );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eMinus
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal ) );
		operandId = m_module.getNonIntermediate( operandId );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( operandId, m_result ) );
	}

	void ExprVisitor::visitPreIncrementExpr( ast::expr::PreIncrement * expr )
	{
		m_allLiterals = false;
		auto literal = m_module.registerLiteral( 1 );
		auto operandId = doSubmit( expr->getOperand(), true );
		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal ) );
		operandId = m_module.getNonIntermediate( operandId );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( operandId, m_result ) );
	}

	void ExprVisitor::visitPostDecrementExpr( ast::expr::PostDecrement * expr )
	{
		m_allLiterals = false;
		auto literal1 = m_module.registerLiteral( 1 );
		auto literal0 = m_module.registerLiteral( 0 );
		auto operandId = doSubmit( expr->getOperand() );
		auto originId = operandId;
		operandId = loadVariable( operandId
			, expr->getType() );

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal0 ) );
		auto operand2 = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, operand2
			, ast::expr::Kind::eMinus
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal1 ) );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( originId, operand2 ) );
	}

	void ExprVisitor::visitPostIncrementExpr( ast::expr::PostIncrement * expr )
	{
		m_allLiterals = false;
		auto literal1 = m_module.registerLiteral( 1 );
		auto literal0 = m_module.registerLiteral( 0 );
		auto operandId = doSubmit( expr->getOperand() );
		auto originId = operandId;
		operandId = loadVariable( operandId
			, expr->getType() );

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, m_result
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal0 ) );
		auto operand2 = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
			, operand2
			, ast::expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, ast::type::Kind::eInt
			, operandId
			, literal1 ) );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( originId, operand2 ) );
	}

	void ExprVisitor::visitUnaryPlusExpr( ast::expr::UnaryPlus * expr )
	{
		m_result = doSubmit( expr );
	}

	void ExprVisitor::visitAddAssignExpr( ast::expr::AddAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAndAssignExpr( ast::expr::AndAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAssignExpr( ast::expr::Assign * expr )
	{
		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitDivideAssignExpr( ast::expr::DivideAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitMinusAssignExpr( ast::expr::MinusAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitModuloAssignExpr( ast::expr::ModuloAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitOrAssignExpr( ast::expr::OrAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitTimesAssignExpr( ast::expr::TimesAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitXorAssignExpr( ast::expr::XorAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAggrInitExpr( ast::expr::AggrInit * expr )
	{
		auto typeId = m_module.registerType( expr->getType() );
		IdList initialisers;
		bool allLiterals = true;

		for ( auto & init : expr->getInitialisers() )
		{
			initialisers.push_back( doSubmit( init.get(), allLiterals, true ) );
		}

		spv::Id init;

		if ( allLiterals )
		{
			init = m_module.registerLiteral( initialisers, expr->getType() );
		}
		else
		{
			init = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( typeId
				, init
				, initialisers ) );
		}

		if ( expr->getIdentifier() )
		{
			m_result = doSubmit( expr->getIdentifier(), false );
			m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( m_result, init ) );
			m_module.putIntermediateResult( init );
		}
		else
		{
			assert( allLiterals );
			m_result = init;
		}

		m_allLiterals = false;
	}

	void ExprVisitor::visitArrayAccessExpr( ast::expr::ArrayAccess * expr )
	{
		m_allLiterals = false;
		m_result = makeAccessChain( expr, m_module, m_currentBlock, m_loadedVariables );

		if ( m_loadVariable )
		{
			auto result = loadVariable( m_result
				, expr->getType() );
			m_module.putIntermediateResult( m_result );
			m_result = result;
		}
	}

	void ExprVisitor::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		m_allLiterals = false;
		m_result = makeAccessChain( expr, m_module, m_currentBlock, m_loadedVariables );

		if ( m_loadVariable )
		{
			auto result = loadVariable( m_result
				, expr->getType() );
			m_module.putIntermediateResult( m_result );
			m_result = result;
		}
	}

	void ExprVisitor::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		IdList params;
		bool allLiterals = true;
		auto paramsCount = 0u;

		for ( auto & arg : expr->getArgList() )
		{
			bool allLitsInit = true;
			auto id = doSubmit( arg.get(), allLitsInit, m_loadVariable );
			params.push_back( id );
			allLiterals = allLiterals && allLitsInit;
			paramsCount += ast::type::getComponentCount( arg->getType()->getKind() );
		}

		auto retCount = ast::type::getComponentCount( expr->getType()->getKind() )
			* ast::type::getComponentCount( ast::type::getComponentType( expr->getType()->getKind() ) );
		auto typeId = m_module.registerType( expr->getType() );

		if ( paramsCount == 1u && retCount != 1u )
		{
			params.resize( retCount, params.back() );
			paramsCount = retCount;
		}

		if ( allLiterals )
		{
			assert( paramsCount == retCount );
			m_result = m_module.registerLiteral( params, expr->getType() );
		}
		else
		{
			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< CompositeConstructInstruction >( typeId
				, m_result
				, params ) );
		}

		m_allLiterals = m_allLiterals && allLiterals;
	}

	void ExprVisitor::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		IdList params;
		bool allLiterals = true;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = doSubmit( arg.get() );
			allLiterals = allLiterals
				&& ( arg->getKind() == ast::expr::Kind::eLiteral );

			if ( isImageType( arg->getType()->getKind() )
				|| isSampledImageType( arg->getType()->getKind() ) )
			{
				VariableInfo info;
				info.rvalue = true;
				id = m_module.registerVariable( "temp_" + static_cast< ast::expr::Identifier const & >( *arg ).getVariable()->getName()
					, spv::StorageClassFunction
					, arg->getType()
					, info ).id;
				auto loadedImageId = m_module.loadVariable( id, arg->getType(), m_currentBlock );
				m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( id, loadedImageId ) );
			}

			params.push_back( id );
		}

		auto typeId = m_module.registerType( expr->getType() );
		auto fnId = doSubmit( expr->getFn() );
		params.insert( params.begin(), fnId );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< FunctionCallInstruction >( typeId
			, m_result
			, params ) );

		m_allLiterals = m_allLiterals && allLiterals;
	}

	void ExprVisitor::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		m_allLiterals = false;
		auto var = expr->getVariable();

		if ( var->isMember() )
		{
			m_result = makeAccessChain( expr
				, m_module
				, m_currentBlock
				, m_loadedVariables );

			if ( m_loadVariable )
			{
				auto result = loadVariable( m_result
					, expr->getType() );
				m_module.putIntermediateResult( m_result );
				m_result = result;
			}
		}
		else
		{
			if ( var->isSpecialisationConstant() )
			{
				m_result = m_module.registerVariable( var->getName()
					, spv::StorageClassInput
					, expr->getType()
					, m_info ).id;
			}
			else
			{
				m_result = m_module.registerVariable( var->getName()
					, getStorageClass( var )
					, expr->getType()
					, m_info ).id;
			}

			if ( m_loadVariable
				&& ( var->isLocale() || var->isShaderInput() || var->isShaderOutput() ) )
			{
				m_result = loadVariable( m_result
					, expr->getType() );
			}
		}
	}

	void ExprVisitor::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		m_allLiterals = false;
		auto paramType = expr->getArgList()[0]->getType();
		assert( paramType->getKind() == ast::type::Kind::eImage );
		auto imageType = std::static_pointer_cast< ast::type::Image >( paramType );
		auto imageVarId = doSubmit( expr->getArgList()[0].get() );
		auto intermediateId = loadVariable( imageVarId, imageType );
		IdList params;
		params.push_back( intermediateId );

		for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
		{
			auto & arg = ( *it );
			auto id = doSubmit( arg.get() );
			params.push_back( id );
		}

		IntrinsicConfig config;
		getSpirVConfig( expr->getImageAccess(), config );
		auto op = getSpirVName( expr->getImageAccess() );
		auto typeId = m_module.registerType( expr->getType() );

		if ( config.needsTexelPointer )
		{
			IdList texelPointerParams;
			uint32_t index = 0u;
			texelPointerParams.push_back( params[index++] );
			texelPointerParams.push_back( params[index++] );

			if ( imageType->getConfig().isMS )
			{
				texelPointerParams.push_back( params[index++] );
			}
			else
			{
				texelPointerParams.push_back( m_module.registerLiteral( 0u ) );
			}

			assert( expr->getArgList()[0]->getKind() == ast::expr::Kind::eIdentifier );
			auto imgParam = static_cast< ast::expr::Identifier const & >( *expr->getArgList()[0] ).getType();
			assert( imgParam->getKind() == ast::type::Kind::eImage );
			auto image = std::static_pointer_cast< ast::type::Image >( imgParam );
			auto sampledId = m_module.registerType( image->getCache().makeType( image->getConfig().sampledType ) );
			auto pointerTypeId = m_module.registerPointerType( sampledId
				, spv::StorageClassImage );
			auto pointerId = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< ImageTexelPointerInstruction >( pointerTypeId
				, pointerId
				, texelPointerParams ) );

			auto scopeId = m_module.registerLiteral( uint32_t( spv::ScopeDevice ) );
			IdList accessParams;
			accessParams.push_back( pointerId );
			accessParams.push_back( scopeId );

			if ( op == spv::Op::OpAtomicCompareExchange )
			{
				auto equalMemorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
				auto unequalMemorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
				accessParams.push_back( equalMemorySemanticsId );
				accessParams.push_back( unequalMemorySemanticsId );
			}
			else
			{
				auto memorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsImageMemoryMask ) );
				accessParams.push_back( memorySemanticsId );
			}

			if ( params.size() > index )
			{
				accessParams.insert( accessParams.end()
					, params.begin() + index
					, params.end() );
			}

			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( typeId
				, m_result
				, op
				, accessParams ) );
			m_module.putIntermediateResult( pointerId );
		}
		else
		{
			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeImageAccessInstruction( typeId
				, m_result
				, op
				, params ) );
		}
	}

	void ExprVisitor::visitInitExpr( ast::expr::Init * expr )
	{
		m_allLiterals = false;
		m_module.registerType( expr->getType() );
		auto init = doSubmit( expr->getInitialiser() );
		m_info.lvalue = true;
		m_result = m_module.registerVariable( expr->getIdentifier()->getVariable()->getName()
			, ( ( expr->getIdentifier()->getVariable()->isLocale() || expr->getIdentifier()->getVariable()->isParam() )
				? spv::StorageClassFunction
				: spv::StorageClassUniformConstant )
			, expr->getType()
			, m_info ).id;
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( m_result, init ) );
	}

	void ExprVisitor::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		m_allLiterals = false;
		IntrinsicConfig config;
		getSpirVConfig( expr->getIntrinsic(), config );
		auto opCodeId = getSpirVName( expr->getIntrinsic() );

		if ( !config.isExtension )
		{
			auto opCode = spv::Op( opCodeId );

			if ( config.isAtomic )
			{
				handleAtomicIntrinsicCallExpr( opCode, expr );
			}
			else if ( opCode == spv::Op::OpIAddCarry
				|| opCode == spv::Op::OpISubBorrow )
			{
				handleCarryBorrowIntrinsicCallExpr( opCode, expr );
			}
			else if ( opCode == spv::Op::OpUMulExtended
				|| opCode == spv::Op::OpSMulExtended )
			{
				handleMulExtendedIntrinsicCallExpr( opCode, expr );
			}
			else
			{
				handleOtherIntrinsicCallExpr( opCode, expr );
			}
		}
		else
		{
			handleExtensionIntrinsicCallExpr( opCodeId, expr );
		}
	}

	void ExprVisitor::visitLiteralExpr( ast::expr::Literal * expr )
	{
		switch ( expr->getLiteralType() )
		{
		case ast::expr::LiteralType::eBool:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eBool >() );
			break;
		case ast::expr::LiteralType::eInt:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eInt >() );
			break;
		case ast::expr::LiteralType::eUInt:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eUInt >() );
			break;
		case ast::expr::LiteralType::eFloat:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eFloat >() );
			break;
		case ast::expr::LiteralType::eDouble:
			m_result = m_module.registerLiteral( expr->getValue< ast::expr::LiteralType::eDouble >() );
			break;
		default:
			assert( false && "Unsupported literal type" );
			break;
		}
	}

	void ExprVisitor::visitQuestionExpr( ast::expr::Question * expr )
	{
		m_allLiterals = false;
		auto ctrlId = doSubmit( expr->getCtrlExpr() );
		auto trueId = doSubmit( expr->getTrueExpr() );
		auto falseId = doSubmit( expr->getFalseExpr() );
		auto type = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		auto branches = makeOperands( ctrlId, trueId, falseId );

		if ( expr->getCtrlExpr()->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( type
				, m_result
				, makeOperands( spv::Id( spv::Op::OpSelect ), branches ) ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SelectInstruction >( type
				, m_result
				, branches ) );
		}
	}

	void ExprVisitor::visitSwitchCaseExpr( ast::expr::SwitchCase * expr )
	{
		m_result = doSubmit( expr->getLabel() );
	}

	void ExprVisitor::visitSwitchTestExpr( ast::expr::SwitchTest * expr )
	{
		m_result = doSubmit( expr->getValue() );
	}

	void ExprVisitor::visitSwizzleExpr( ast::expr::Swizzle * expr )
	{
		m_allLiterals = false;
		auto outerId = doSubmit( expr->getOuterExpr() );
		auto rawTypeId = m_module.registerType( expr->getType() );
		auto pointerTypeId = m_module.registerPointerType( rawTypeId, spv::StorageClassFunction );
		bool needsLoad = false;
		m_result = writeShuffle( m_module, m_currentBlock, pointerTypeId, rawTypeId, outerId, expr->getSwizzle(), needsLoad );
	}

	void ExprVisitor::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		m_allLiterals = false;
		IdList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		auto typeId = m_module.registerType( expr->getType() );
		auto kind = expr->getTextureAccess();
		IntrinsicConfig config;
		getSpirVConfig( kind, config );
		auto op = getSpirVName( kind );

		// Load the sampled image variable
		auto sampledImageType = expr->getArgList()[0]->getType();
		assert( sampledImageType->getKind() == ast::type::Kind::eSampledImage );
		auto sampleImageId = args[0];
		auto loadedSampleImageId = loadVariable( sampleImageId, sampledImageType );
		args[0] = loadedSampleImageId;

		if ( config.needsImage )
		{
			// We need to extract the image from the sampled image, to give it to the final instruction.
			auto imageType = std::static_pointer_cast< ast::type::SampledImage >( sampledImageType )->getImageType();
			auto imageTypeId = m_module.registerType( imageType );
			auto imageId = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction< ImageInstruction >( imageTypeId
				, imageId
				, loadedSampleImageId ) );
			args[0] = imageId;
		}

		if ( config.imageOperandsIndex )
		{
			assert( args.size() >= config.imageOperandsIndex );
			auto mask = getMask( kind );
			args.insert( args.begin() + config.imageOperandsIndex, spv::Id( mask ) );
		}

		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeTextureAccessInstruction( typeId
			, m_result
			, op
			, args ) );
	}

	void ExprVisitor::handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is carry or borrow.
		assert( expr->getArgList().size() == 3u );
		IdList params;
		params.push_back( doSubmit( expr->getArgList()[0].get() ) );
		params.push_back( doSubmit( expr->getArgList()[1].get() ) );

		auto resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( expr->getType()->getKind() )
			? getComponentCount( expr->getType()->getKind() )
			: 1 );
		auto resultCarryBorrowId = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( resultStructTypeId
			, resultCarryBorrowId
			, opCode
			, params ) );

		auto & carryBorrowArg = *expr->getArgList()[2];
		auto carryBorrowTypeId = m_module.registerType( carryBorrowArg.getType() );
		auto intermediateId = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( carryBorrowTypeId
			, intermediateId
			, IdList{ resultCarryBorrowId, 1u } ) );
		auto carryBorrowId = getVariableIdNoLoad( &carryBorrowArg );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( carryBorrowId, intermediateId ) );

		auto resultTypeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( resultTypeId
			, m_result
			, IdList{ resultCarryBorrowId, 0u } ) );

		m_module.putIntermediateResult( intermediateId );
	}

	void ExprVisitor::handleMulExtendedIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is msb.
		// Arg 4 is lsb.
		assert( expr->getArgList().size() == 4u );
		IdList params;
		params.push_back( doSubmit( expr->getArgList()[0].get() ) );
		params.push_back( doSubmit( expr->getArgList()[1].get() ) );
		spv::Id resultStructTypeId;
		auto paramType = expr->getArgList()[0]->getType()->getKind();

		if ( isSignedIntType( paramType ) )
		{
			resultStructTypeId = getSignedExtendedResultTypeId( isVectorType( paramType )
				? getComponentCount( paramType )
				: 1 );
		}
		else
		{
			resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( paramType )
				? getComponentCount( paramType )
				: 1 );
		}

		auto resultMulExtendedId = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( resultStructTypeId
			, resultMulExtendedId
			, opCode
			, params ) );

		auto & msbArg = *expr->getArgList()[2];
		auto msbTypeId = m_module.registerType( msbArg.getType() );
		auto intermediateMsb = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( msbTypeId
			, intermediateMsb
			, IdList{ resultMulExtendedId, 1u } ) );
		auto msbId = getVariableIdNoLoad( &msbArg );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( msbId, intermediateMsb ) );

		auto & lsbArg = *expr->getArgList()[3];
		auto lsbTypeId = m_module.registerType( lsbArg.getType() );
		auto intermediateLsb = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< CompositeExtractInstruction >( lsbTypeId
			, intermediateLsb
			, IdList{ resultMulExtendedId, 0u } ) );
		auto lsbId = getVariableIdNoLoad( &lsbArg );
		m_currentBlock.instructions.emplace_back( makeInstruction< StoreInstruction >( lsbId, intermediateLsb ) );

		m_module.putIntermediateResult( intermediateMsb );
		m_module.putIntermediateResult( intermediateLsb );
		m_module.putIntermediateResult( resultMulExtendedId );
	}

	void ExprVisitor::handleAtomicIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = doSubmit( arg.get() );
			params.push_back( id );
		}

		auto typeId = m_module.registerType( expr->getType() );
		auto scopeId = m_module.registerLiteral( uint32_t( spv::ScopeDevice ) );
		auto memorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsAcquireReleaseMask ) );
		uint32_t index{ 1u };
		params.insert( params.begin() + ( index++ ), scopeId );
		params.insert( params.begin() + ( index++ ), memorySemanticsId );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( typeId
			, m_result
			, opCode
			, params ) );
	}

	void ExprVisitor::handleExtensionIntrinsicCallExpr( spv::Id opCode, ast::expr::IntrinsicCall * expr )
	{
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = doSubmit( arg.get() );
			params.push_back( id );
		}

		auto typeId = m_module.registerType( expr->getType() );
		params.insert( params.begin(), opCode );
		params.insert( params.begin(), 1u );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction< ExtInstInstruction >( typeId
			, m_result
			, params ) );
	}

	void ExprVisitor::handleOtherIntrinsicCallExpr( spv::Op opCode, ast::expr::IntrinsicCall * expr )
	{
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = doSubmit( arg.get() );
			params.push_back( id );
		}

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeIntrinsicInstruction( typeId
			, m_result
			, opCode
			, params ) );
	}

	spv::Id ExprVisitor::getUnsignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_unsignedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeU" + std::to_string( count + 1u );
			m_unsignedExtendedTypes[count] = m_module.getCache().getStruct( ast::type::MemoryLayout::eStd430, name );
			auto type = count == 3
				? m_module.getCache().getVec4U()
				: ( count == 2
					? m_module.getCache().getVec3U()
					: ( count == 1
						? m_module.getCache().getVec2U()
						: ( m_module.getCache().getUInt() ) ) );

			if ( m_unsignedExtendedTypes[count]->empty() )
			{
				m_unsignedExtendedTypes[count]->declMember( "result", type );
				m_unsignedExtendedTypes[count]->declMember( "extended", type );
			}
		}

		return m_module.registerType( m_unsignedExtendedTypes[count] );
	}

	spv::Id ExprVisitor::getSignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_signedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeS" + std::to_string( count + 1u );
			m_signedExtendedTypes[count] = m_module.getCache().getStruct( ast::type::MemoryLayout::eStd430, name );
			auto type = count == 3
				? m_module.getCache().getVec4I()
				: ( count == 2
					? m_module.getCache().getVec3I()
					: ( count == 1
						? m_module.getCache().getVec2I()
						: ( m_module.getCache().getInt() ) ) );

			if ( m_signedExtendedTypes[count]->empty() )
			{
				m_signedExtendedTypes[count]->declMember( "result", type );
				m_signedExtendedTypes[count]->declMember( "extended", type );
			}
		}

		return m_module.registerType( m_signedExtendedTypes[count] );
	}

	spv::Id ExprVisitor::getVariableIdNoLoad( ast::expr::Expr * expr )
	{
		spv::Id result;

		if ( isAccessChain( expr ) )
		{
			auto save = m_loadVariable;
			m_loadVariable = false;
			result = doSubmit( expr );
			m_loadVariable = save;
		}
		else
		{
			auto ident = sdw::findIdentifier( expr );

			if ( ident )
			{
				auto var = ident->getVariable();

				if ( var->isSpecialisationConstant() )
				{
					m_info.lvalue = false;
					m_info.rvalue = true;
					result = m_module.registerVariable( var->getName()
						, spv::StorageClassInput
						, expr->getType()
						, m_info ).id;
				}
				else
				{
					result = m_module.registerVariable( var->getName()
						, getStorageClass( var )
						, expr->getType()
						, m_info ).id;
				}
			}
			else
			{
				result = doSubmit( expr );
			}
		}

		return result;
	}

	spv::Id ExprVisitor::writeBinOpExpr( ast::expr::Kind exprKind
		, ast::type::Kind lhsTypeKind
		, ast::type::Kind rhsTypeKind
		, spv::Id typeId
		, spv::Id lhsId
		, spv::Id rhsId
		, bool isLhsSpecConstant )
	{
		auto result = m_module.getIntermediateResult();

		if ( isLhsSpecConstant )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction< SpecConstantOpInstruction >( typeId
				, result
				, makeBinOpOperands( exprKind
					, lhsTypeKind
					, rhsTypeKind
					, lhsId
					, rhsId ) ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeBinInstruction( typeId
				, result
				, exprKind
				, lhsTypeKind
				, rhsTypeKind
				, lhsId
				, rhsId ) );
		}

		return result;
	}

	spv::Id ExprVisitor::loadVariable( spv::Id varId
		, ast::type::TypePtr type )
	{
		return spirv::loadVariable( varId
			, type
			, m_module
			, m_currentBlock
			, m_loadedVariables );
	}
}
