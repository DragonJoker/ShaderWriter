/*
See LICENSE file in root folder
*/
#include "ShaderWriter/SPIRV/SpirvExprVisitor.hpp"

#include "ShaderWriter/SPIRV/SpirvHelpers.hpp"
#include "ShaderWriter/SPIRV/SpirvImageAccessNames.hpp"
#include "ShaderWriter/SPIRV/SpirvIntrinsicNames.hpp"
#include "ShaderWriter/SPIRV/SpirvTextureAccessNames.hpp"

#include <ASTGenerator/Type/TypeImage.hpp>
#include <ASTGenerator/Type/TypeSampledImage.hpp>

#include <numeric>
#include <sstream>

namespace sdw::spirv
{
	namespace
	{
		std::vector< uint32_t > getSwizzleComponents( expr::SwizzleKind kind )
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

		spv::Id writeShuffle( Module & module
			, Block & currentBlock
			, spv::Id typeId
			, spv::Id outerId
			, expr::SwizzleKind swizzle )
		{
			auto swizzleComponents = getSwizzleComponents( swizzle );
			IdList shuffle;
			shuffle.push_back( outerId );
			shuffle.insert( shuffle.end(), swizzleComponents.begin(), swizzleComponents.end() );
			auto it = currentBlock.vectorShuffles.find( shuffle );

			if ( it == currentBlock.vectorShuffles.end() )
			{
				auto intermediate = module.getIntermediateResult();
				currentBlock.instructions.emplace_back( makeVectorShuffle( intermediate
					, typeId
					, shuffle ) );
				it = currentBlock.vectorShuffles.emplace( shuffle, intermediate ).first;
			}

			return it->second;
		}

		bool isAccessChain( expr::Expr * expr )
		{
			return expr->getKind() == expr::Kind::eArrayAccess
				|| expr->getKind() == expr::Kind::eMbrSelect
				|| expr->getKind() == expr::Kind::eSwizzle;
		}

		spv::Id makeAccessChain( expr::Expr * expr
			, Module & module
			, Block & currentBlock );

		class AccessChainLineariser
			: public expr::SimpleVisitor
		{
		public:
			static std::vector< expr::Expr * > submit( expr::Expr * expr
				, expr::ExprList & idents )
			{
				std::vector< expr::Expr * > result;
				AccessChainLineariser vis{ result, idents };
				expr->accept( &vis );
				return result;
			}

		private:
			AccessChainLineariser( std::vector< expr::Expr * > & result
				, expr::ExprList & idents )
				: m_result{ result }
				, m_idents{ idents }
			{
			}

			void visitUnaryExpr( expr::Unary * expr )override
			{
				assert( false && "Unexpected expr::Unary ?" );
			}

			void visitBinaryExpr( expr::Binary * expr )override
			{
				assert( false && "Unexpected expr::Binary ?" );
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				auto outer = submit( expr->getOuterExpr(), m_idents );
				auto inner = submit( expr->getOperand(), m_idents );
				m_result = outer;
				m_result.insert( m_result.end(), inner.begin(), inner.end() );
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				auto lhs = submit( expr->getLHS(), m_idents );
				m_result = lhs;
				m_result.push_back( expr->getRHS() );
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				if ( expr->getVariable()->isMember()
					&& expr->getType()->isMember() )
				{
					m_idents.emplace_back( makeIdent( expr->getVariable()->getOuter() ) );
					auto ident = m_idents.back().get();
					m_result = submit( ident, m_idents );
				}

				m_result.push_back( expr );
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				m_result.push_back( expr );
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				m_result.push_back( expr );
			}
			
			void visitAggrInitExpr( expr::AggrInit * )override
			{
				assert( false && "Unexpected expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
			{
				assert( false && "Unexpected expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( expr::FnCall * )override
			{
				assert( false && "Unexpected expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * )override
			{
				assert( false && "Unexpected expr::ImageAccessCall ?" );
			}

			void visitInitExpr( expr::Init * )override
			{
				assert( false && "Unexpected expr::Init ?" );
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall * )override
			{
				assert( false && "Unexpected expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( expr::Question * )override
			{
				assert( false && "Unexpected expr::Question ?" );
			}

			void visitSwitchCaseExpr( expr::SwitchCase * )override
			{
				assert( false && "Unexpected expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( expr::SwitchTest * )override
			{
				assert( false && "Unexpected expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * )override
			{
				assert( false && "Unexpected expr::TextureAccessCall ?" );
			}

		private:
			std::vector< expr::Expr * > & m_result;
			expr::ExprList & m_idents;
		};

		class AccessChainCreator
			: public expr::SimpleVisitor
		{
		public:
			static IdList submit( std::vector< expr::Expr * > const & exprs
				, Module & module
				, Block & currentBlock )
			{
				IdList result;
				assert( exprs.size() >= 2u );
				result.push_back( submit( exprs[0]
					, module
					, currentBlock ) );

				for ( size_t i = 1u; i < exprs.size(); ++i )
				{
					auto & expr = exprs[i];
					result.push_back( submit( result.back()
						, exprs[i - 1u]
						, expr
						, module
						, currentBlock ) );
				}

				return result;
			}

		private:
			AccessChainCreator( spv::Id & result
				, expr::Expr * parentExpr
				, spv::Id parentId
				, Module & module
				, Block & currentBlock )
				: m_result{ result }
				, m_module{ module }
				, m_currentBlock{ currentBlock }
				, m_parentId{ parentId }
			{
			}

			static spv::Id submit( expr::Expr * expr
				, Module & module
				, Block & currentBlock )
			{
				spv::Id result;
				AccessChainCreator vis{ result, nullptr, 0u, module, currentBlock };
				expr->accept( &vis );
				return result;
			}

			static spv::Id submit( spv::Id parentId
				, expr::Expr * parentExpr
				, expr::Expr * expr
				, Module & module
				, Block & currentBlock )
			{
				spv::Id result;
				AccessChainCreator vis{ result, parentExpr, parentId, module, currentBlock };
				expr->accept( &vis );
				return result;
			}

			void visitUnaryExpr( expr::Unary * expr )override
			{
				assert( false && "Unexpected expr::Unary ?" );
			}

			void visitBinaryExpr( expr::Binary * expr )override
			{
				assert( false && "Unexpected expr::Binary ?" );
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				assert( m_parentId != 0u );
				m_result = submit( expr->getOperand(), m_module, m_currentBlock );
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				assert( m_parentId != 0u );

				if ( isAccessChain( expr->getRHS() ) )
				{
					m_result = makeAccessChain( expr->getRHS(), m_module, m_currentBlock );
				}
				else
				{
					m_result = submit( expr->getRHS(), m_module, m_currentBlock );
				}
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
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
						, expr->getType() );
				}
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				assert( m_parentId != 0u );

				switch ( expr->getLiteralType() )
				{
				case expr::LiteralType::eBool:
					m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eBool >() );
					break;
				case expr::LiteralType::eInt:
					m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eInt >() );
					break;
				case expr::LiteralType::eUInt:
					m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eUInt >() );
					break;
				case expr::LiteralType::eFloat:
					m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eFloat >() );
					break;
				case expr::LiteralType::eDouble:
					m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eDouble >() );
					break;
				default:
					assert( false && "Unsupported literal type" );
					break;
				}
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				assert( m_parentId != 0u );
				spv::Id parentId;

				if ( isAccessChain( expr->getOuterExpr() ) )
				{
					parentId = makeAccessChain( expr->getOuterExpr()
						, m_module
						, m_currentBlock );
				}
				else
				{
					parentId = ExprVisitor::submit( expr->getOuterExpr()
						, m_currentBlock
						, m_module );
				}

				auto rawTypeId = m_module.registerType( expr->getType() );
				auto pointerTypeId = m_module.registerPointerType( rawTypeId, spv::StorageClass::Function );
				auto shuffleId = writeShuffle( m_module, m_currentBlock, pointerTypeId, parentId, expr->getSwizzle() );
				m_result = m_module.getIntermediateResult();
				m_currentBlock.instructions.emplace_back( makeLoad( m_result, rawTypeId, shuffleId ) );
			}

			void visitAggrInitExpr( expr::AggrInit * )override
			{
				assert( false && "Unexpected expr::AggrInit ?" );
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
			{
				assert( false && "Unexpected expr::CompositeConstruct ?" );
			}

			void visitFnCallExpr( expr::FnCall * )override
			{
				assert( false && "Unexpected expr::FnCall ?" );
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * )override
			{
				assert( false && "Unexpected expr::ImageAccessCall ?" );
			}

			void visitInitExpr( expr::Init * )override
			{
				assert( false && "Unexpected expr::Init ?" );
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall * )override
			{
				assert( false && "Unexpected expr::IntrinsicCall ?" );
			}

			void visitQuestionExpr( expr::Question * )override
			{
				assert( false && "Unexpected expr::Question ?" );
			}

			void visitSwitchCaseExpr( expr::SwitchCase * )override
			{
				assert( false && "Unexpected expr::SwitchCase ?" );
			}

			void visitSwitchTestExpr( expr::SwitchTest * )override
			{
				assert( false && "Unexpected expr::SwitchTest ?" );
			}

			void visitTextureAccessCallExpr( expr::TextureAccessCall * )override
			{
				assert( false && "Unexpected expr::TextureAccessCall ?" );
			}

		private:
			spv::Id & m_result;
			Module & m_module;
			Block & m_currentBlock;
			spv::Id m_parentId;
			expr::Expr * m_parentExpr;
		};

		spv::Id writeAccessChain( Block & currentBlock
			, IdList const & accessChain
			, expr::Expr * expr
			, Module & module )
		{
			auto it = currentBlock.accessChains.find( accessChain );

			if ( it == currentBlock.accessChains.end() )
			{
			// Reserve the ID for the result.
				auto intermediate = module.getIntermediateResult();
				// Register the type pointed to.
				auto rawType = module.registerType( expr->getType() );
				// Register the pointer to the type.
				auto pointerType = module.registerPointerType( rawType
					, getStorageClass( findIdentifier( expr )->getVariable() ) );
				// Write access chain => resultId = pointerType( outer.members + index ).
				currentBlock.instructions.emplace_back( spirv::makeAccessChain( spv::Op::OpAccessChain
					, intermediate
					, pointerType
					, accessChain ) );
				auto result = module.loadVariable( intermediate
					, expr->getType()
					, currentBlock );
				module.putIntermediateResult( intermediate );
				it = currentBlock.accessChains.emplace( accessChain, result ).first;
			}

			return it->second;
		}

		spv::Id makeAccessChain( expr::Expr * expr
			, Module & module
			, Block & currentBlock )
		{
			// Create Access Chain.
			expr::ExprList idents;
			auto accessChainExprs = AccessChainLineariser::submit( expr, idents );
			auto accessChain = AccessChainCreator::submit( accessChainExprs
				, module
				, currentBlock );
			return writeAccessChain( currentBlock, accessChain, expr, module );
		}
	}

	spv::StorageClass getStorageClass( var::VariablePtr var )
	{
		var = getOutermost( var );
		spv::StorageClass result = spv::StorageClass::Function;

		if ( var->isUniform() )
		{
			if ( var->isConstant() )
			{
				result = spv::StorageClass::UniformConstant;
			}
			else
			{
				result = spv::StorageClass::Uniform;
			}
		}
		else if ( var->isBuiltin() )
		{
			result = spv::StorageClass::Input;
		}
		else if ( var->isShaderInput() )
		{
			result = spv::StorageClass::Input;
		}
		else if ( var->isShaderOutput() )
		{
			result = spv::StorageClass::Output;
		}
		else if ( var->isShaderConstant() )
		{
			result = spv::StorageClass::Input;
		}
		else if ( var->isSpecialisationConstant() )
		{
			assert( false && "Specialisation constants shouldn't be processed as variables" );
		}
		else if ( var->isPushConstant() )
		{
			result = spv::StorageClass::PushConstant;
		}

		return result;
	}

	spv::Id ExprVisitor::submit( expr::Expr * expr
		, Block & currentBlock
		, Module & module )
	{
		bool allLiterals{ false };
		return submit( expr, currentBlock, module, allLiterals );
	}

	spv::Id ExprVisitor::submit( expr::Expr * expr
		, Block & currentBlock
		, Module & module
		, bool & allLiterals )
	{
		spv::Id result{ 0u };
		ExprVisitor vis{ result
			, currentBlock
			, module
			, allLiterals };
		expr->accept( &vis );

		return result;
	}

	ExprVisitor::ExprVisitor( spv::Id & result
		, Block & currentBlock
		, Module & module
		, bool & allLiterals )
		: m_result{ result }
		, m_currentBlock{ currentBlock }
		, m_module{ module }
		, m_allLiterals{ allLiterals }
	{
	}

	void ExprVisitor::visitAssignmentExpr( expr::Assign * expr )
	{
		m_allLiterals = false;
		auto lhs = getVariableIdNoLoad( expr->getLHS() );
		auto rhs = submit( expr->getRHS(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		m_currentBlock.instructions.emplace_back( makeStore( lhs, rhs ) );
		m_result = lhs;
	}

	void ExprVisitor::visitOpAssignmentExpr( expr::Assign * expr )
	{
		m_allLiterals = false;
		auto typeId = m_module.registerType( expr->getType() );
		auto lhsId = submit( expr->getLHS(), m_currentBlock, m_module );
		auto loadedLhsId = m_module.loadVariable( lhsId
			, expr->getType()
			, m_currentBlock );
		auto rhsId = submit( expr->getRHS(), m_currentBlock, m_module );
		auto intermediateId = m_module.getIntermediateResult();

		if ( expr->getLHS()->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeBinSpecConstantInstruction( expr->getKind()
				, expr->getLHS()->getType()->getKind()
				, expr->getRHS()->getType()->getKind()
				, intermediateId
				, typeId
				, loadedLhsId
				, rhsId ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeBinInstruction( expr->getKind()
				, expr->getLHS()->getType()->getKind()
				, expr->getRHS()->getType()->getKind()
				, intermediateId
				, typeId
				, loadedLhsId
				, rhsId ) );
		}

		m_currentBlock.instructions.emplace_back( makeStore( lhsId, intermediateId ) );
		m_module.putIntermediateResult( intermediateId );
		m_module.putIntermediateResult( loadedLhsId );
		m_result = lhsId;
	}

	void ExprVisitor::visitUnaryExpr( expr::Unary * expr )
	{
		m_allLiterals = false;
		auto operand = submit( expr->getOperand(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		auto intermediate = m_module.getIntermediateResult();

		if ( expr->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeUnSpecConstantInstruction( expr->getKind()
				, expr->getType()->getKind()
				, intermediate
				, type
				, operand ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeUnInstruction( expr->getKind()
				, expr->getType()->getKind()
				, intermediate
				, type
				, operand ) );
		}

		m_result = intermediate;
	}

	void ExprVisitor::visitBinaryExpr( expr::Binary * expr )
	{
		m_allLiterals = false;
		auto lhs = submit( expr->getLHS(), m_currentBlock, m_module );
		auto rhs = submit( expr->getRHS(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		auto intermediate = m_module.getIntermediateResult();

		if ( expr->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeBinSpecConstantInstruction( expr->getKind()
				, expr->getLHS()->getType()->getKind()
				, expr->getRHS()->getType()->getKind()
				, intermediate
				, type
				, lhs
				, rhs ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeBinInstruction( expr->getKind()
				, expr->getLHS()->getType()->getKind()
				, expr->getRHS()->getType()->getKind()
				, intermediate
				, type
				, lhs
				, rhs ) );
		}

		m_result = intermediate;
	}

	void ExprVisitor::visitPreDecrementExpr( expr::PreDecrement * expr )
	{
		m_allLiterals = false;
		auto literal = m_module.registerLiteral( 1 );
		auto operand = submit( expr->getOperand(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		auto intermediate = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( expr::Kind::eMinus
			, expr->getOperand()->getType()->getKind()
			, type::Kind::eInt
			, intermediate
			, type
			, operand
			, literal ) );
		m_currentBlock.instructions.emplace_back( makeStore( operand, intermediate ) );
		m_result = intermediate;
	}

	void ExprVisitor::visitPreIncrementExpr( expr::PreIncrement * expr )
	{
		m_allLiterals = false;
		auto literal = m_module.registerLiteral( 1 );
		auto operand = submit( expr->getOperand(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		auto intermediate = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, type::Kind::eInt
			, intermediate
			, type
			, operand
			, literal ) );
		operand = m_module.getNonIntermediate( operand );
		m_currentBlock.instructions.emplace_back( makeStore( operand, intermediate ) );
		m_result = intermediate;
	}

	void ExprVisitor::visitPostDecrementExpr( expr::PostDecrement * expr )
	{
		m_allLiterals = false;
		auto literal1 = m_module.registerLiteral( 1 );
		auto literal0 = m_module.registerLiteral( 0 );
		auto operand = submit( expr->getOperand(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		auto intermediate = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, type::Kind::eInt
			, intermediate
			, type
			, operand
			, literal0 ) );
		m_currentBlock.instructions.emplace_back( makeBinInstruction( expr::Kind::eMinus
			, expr->getOperand()->getType()->getKind()
			, type::Kind::eInt
			, operand
			, type
			, operand
			, literal1 ) );
		m_result = intermediate;
	}

	void ExprVisitor::visitPostIncrementExpr( expr::PostIncrement * expr )
	{
		m_allLiterals = false;
		auto literal1 = m_module.registerLiteral( 1 );
		auto literal0 = m_module.registerLiteral( 0 );
		auto operand = submit( expr->getOperand(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		auto intermediate = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeBinInstruction( expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, type::Kind::eInt
			, intermediate
			, type
			, operand
			, literal0 ) );
		m_currentBlock.instructions.emplace_back( makeBinInstruction( expr::Kind::eAdd
			, expr->getOperand()->getType()->getKind()
			, type::Kind::eInt
			, operand
			, type
			, operand
			, literal1 ) );
		m_result = intermediate;
	}

	void ExprVisitor::visitUnaryPlusExpr( expr::UnaryPlus * expr )
	{
		m_result = submit( expr, m_currentBlock, m_module );
	}

	void ExprVisitor::visitAddAssignExpr( expr::AddAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAndAssignExpr( expr::AndAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAssignExpr( expr::Assign * expr )
	{
		visitAssignmentExpr( expr );
	}

	void ExprVisitor::visitDivideAssignExpr( expr::DivideAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitLShiftAssignExpr( expr::LShiftAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitMinusAssignExpr( expr::MinusAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitModuloAssignExpr( expr::ModuloAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitOrAssignExpr( expr::OrAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitRShiftAssignExpr( expr::RShiftAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitTimesAssignExpr( expr::TimesAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitXorAssignExpr( expr::XorAssign * expr )
	{
		visitOpAssignmentExpr( expr );
	}

	void ExprVisitor::visitAggrInitExpr( expr::AggrInit * expr )
	{
		auto typeId = m_module.registerType( expr->getType() );
		IdList initialisers;
		bool allLiterals = true;

		for ( auto & init : expr->getInitialisers() )
		{
			initialisers.push_back( submit( init.get(), m_currentBlock, m_module, allLiterals ) );
		}

		spv::Id init;

		if ( allLiterals )
		{
			init = m_module.registerLiteral( initialisers, expr->getType() );
		}
		else
		{
			init = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpCompositeConstruct
				, init
				, typeId
				, { initialisers } ) );
		}

		if ( expr->getIdentifier() )
		{
			m_result = submit( expr->getIdentifier(), m_currentBlock, m_module );
			m_currentBlock.instructions.emplace_back( makeStore( m_result, init ) );
			m_module.putIntermediateResult( init );
		}
		else
		{
			assert( allLiterals );
			m_result = init;
		}

		m_allLiterals = false;
	}

	void ExprVisitor::visitArrayAccessExpr( expr::ArrayAccess * expr )
	{
		m_allLiterals = false;
		m_result = makeAccessChain( expr, m_module, m_currentBlock );
	}

	void ExprVisitor::visitMbrSelectExpr( expr::MbrSelect * expr )
	{
		m_allLiterals = false;
		m_result = makeAccessChain( expr, m_module, m_currentBlock );
	}

	void ExprVisitor::visitCompositeConstructExpr( expr::CompositeConstruct * expr )
	{
		IdList params;
		bool allLiterals = true;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = submit( arg.get(), m_currentBlock, m_module );
			params.push_back( id );
			allLiterals = allLiterals
				&& ( arg->getKind() == expr::Kind::eLiteral );
		}

		auto type = m_module.registerType( expr->getType() );
		spv::Id result;

		if ( allLiterals )
		{
			auto paramsCount = std::accumulate( expr->getArgList().begin()
				, expr->getArgList().end()
				, 0u
				, []( uint32_t current, expr::ExprPtr const & lookup )
				{
					return current + type::getComponentCount( lookup->getType()->getKind() );
				} );
			auto retCount = type::getComponentCount( expr->getType()->getKind() );

			if ( paramsCount == 1u && retCount != 1u )
			{
				params.resize( retCount, params.back() );
				result = m_module.registerLiteral( params, expr->getType() );
			}
			else
			{
				assert( paramsCount == retCount );
				result = m_module.registerLiteral( params, expr->getType() );
			}
		}
		else
		{
			result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpCompositeConstruct
				, result
				, type
				, params ) );
		}

		m_allLiterals = m_allLiterals && allLiterals;
		m_result = result;
	}

	void ExprVisitor::visitFnCallExpr( expr::FnCall * expr )
	{
		IdList params;
		bool allLiterals = true;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = submit( arg.get(), m_currentBlock, m_module );
			params.push_back( id );
			allLiterals = allLiterals
				&& ( arg->getKind() == expr::Kind::eLiteral );
		}

		auto type = m_module.registerType( expr->getType() );
		spv::Id result;

		result = m_module.getIntermediateResult();
		auto fnId = submit( expr->getFn(), m_currentBlock, m_module );
		params.insert( params.begin(), fnId );
		m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpFunctionCall
			, result
			, type
			, params ) );

		m_allLiterals = m_allLiterals && allLiterals;
		m_result = result;
	}

	void ExprVisitor::visitIdentifierExpr( expr::Identifier * expr )
	{
		m_allLiterals = false;
		auto var = expr->getVariable();

		if ( var->isMember() )
		{
			m_result = makeAccessChain( expr, m_module, m_currentBlock );
		}
		else
		{
			if ( var->isSpecialisationConstant() )
			{
				m_result = m_module.registerVariable( var->getName()
					, spv::StorageClass::Input
					, expr->getType() );
			}
			else
			{
				m_result = m_module.registerVariable( var->getName()
					, getStorageClass( var )
					, expr->getType() );
			}

			if ( var->isLocale()
				|| var->isShaderInput() )
			{
				m_result = m_module.loadVariable( m_result
					, expr->getType()
					, m_currentBlock );
			}
		}
	}

	void ExprVisitor::visitImageAccessCallExpr( expr::ImageAccessCall * expr )
	{
		m_allLiterals = false;
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = submit( arg.get(), m_currentBlock, m_module );
			params.push_back( id );
		}

		bool needsTexelPointer;
		auto op = getSpirVName( expr->getImageAccess(), needsTexelPointer );
		auto typeId = m_module.registerType( expr->getType() );
		auto paramType = expr->getArgList()[0]->getType();
		assert( paramType->getKind() == type::Kind::eImage );
		auto imageType = std::static_pointer_cast< type::Image >( paramType );

		if ( needsTexelPointer )
		{
			IdList texelPointerParams;
			uint32_t index = 0u;
			texelPointerParams.push_back( params[index++] );
			texelPointerParams.push_back( params[index++] );

			if ( imageType->getConfig().isMS )
			{
				texelPointerParams.push_back( params[index++] );
			}

			assert( expr->getArgList()[0]->getKind() == expr::Kind::eIdentifier );
			auto imgParam = static_cast< expr::Identifier const & >( *expr->getArgList()[0] ).getType();
			assert( imgParam->getKind() == type::Kind::eImage );
			auto image = std::static_pointer_cast< type::Image >( imgParam );
			auto sampledId = m_module.registerType( makeType( image->getConfig().sampledType ) );
			auto pointerTypeId = m_module.registerPointerType( sampledId
				, spv::StorageClass::Image );
			auto pointerId = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpImageTexelPointer
				, pointerId
				, pointerTypeId
				, texelPointerParams ) );

			auto scopeId = m_module.registerLiteral( uint32_t( spv::Scope::Device ) );
			IdList accessParams;
			accessParams.push_back( pointerId );
			accessParams.push_back( scopeId );

			if ( op == spv::Op::OpAtomicCompareExchange )
			{
				auto equalMemorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsMask::ImageMemory ) );
				auto unequalMemorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsMask::ImageMemory ) );
				accessParams.push_back( equalMemorySemanticsId );
				accessParams.push_back( unequalMemorySemanticsId );
			}
			else
			{
				auto memorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsMask::ImageMemory ) );
				accessParams.push_back( memorySemanticsId );
			}

			if ( params.size() > index )
			{
				accessParams.insert( accessParams.end()
					, params.begin() + index
					, params.end() );
			}

			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction( op
				, m_result
				, typeId
				, accessParams ) );
			m_module.putIntermediateResult( pointerId );
		}
		else
		{
			m_result = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction( op
				, m_result
				, typeId
				, params ) );
		}
	}

	void ExprVisitor::visitInitExpr( expr::Init * expr )
	{
		m_allLiterals = false;
		auto result = m_module.registerVariable( expr->getIdentifier()->getVariable()->getName()
			, ( ( expr->getIdentifier()->getVariable()->isLocale() || expr->getIdentifier()->getVariable()->isInputParam() )
				? spv::StorageClass::Function
				: spv::StorageClass::UniformConstant )
			, expr->getType() );
		auto type = m_module.registerType( expr->getType() );
		auto init = submit( expr->getInitialiser(), m_currentBlock, m_module );
		m_currentBlock.instructions.emplace_back( makeStore( result, init ) );
		m_result = result;
	}

	void ExprVisitor::visitIntrinsicCallExpr( expr::IntrinsicCall * expr )
	{
		m_allLiterals = false;
		bool isExtension;
		bool isAtomic;
		auto opCodeId = getSpirVName( expr->getIntrinsic()
			, isExtension
			, isAtomic );

		if ( !isExtension )
		{
			auto opCode = spv::Op( opCodeId );

			if ( isAtomic )
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

	void ExprVisitor::visitLiteralExpr( expr::Literal * expr )
	{
		switch ( expr->getLiteralType() )
		{
		case expr::LiteralType::eBool:
			m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eBool >() );
			break;
		case expr::LiteralType::eInt:
			m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eInt >() );
			break;
		case expr::LiteralType::eUInt:
			m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eUInt >() );
			break;
		case expr::LiteralType::eFloat:
			m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eFloat >() );
			break;
		case expr::LiteralType::eDouble:
			m_result = m_module.registerLiteral( expr->getValue< expr::LiteralType::eDouble >() );
			break;
		default:
			assert( false && "Unsupported literal type" );
			break;
		}
	}

	void ExprVisitor::visitQuestionExpr( expr::Question * expr )
	{
		m_allLiterals = false;
		auto ctrlId = submit( expr->getCtrlExpr(), m_currentBlock, m_module );
		auto trueId = submit( expr->getTrueExpr(), m_currentBlock, m_module );
		auto falseId = submit( expr->getFalseExpr(), m_currentBlock, m_module );
		auto type = m_module.registerType( expr->getType() );
		auto intermediate = m_module.getIntermediateResult();

		if ( expr->getCtrlExpr()->isSpecialisationConstant() )
		{
			m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpSpecConstantOp
				, intermediate
				, type
				, IdList{ spv::Id( spv::Op::OpSelect ), ctrlId, trueId, falseId } ) );
		}
		else
		{
			m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpSelect
				, intermediate
				, type
				, IdList{ ctrlId, trueId, falseId } ) );
		}
		m_result = intermediate;
	}

	void ExprVisitor::visitSwitchCaseExpr( expr::SwitchCase * expr )
	{
		m_result = submit( expr->getLabel(), m_currentBlock, m_module );
	}

	void ExprVisitor::visitSwitchTestExpr( expr::SwitchTest * expr )
	{
		m_result = submit( expr->getValue(), m_currentBlock, m_module );
	}

	void ExprVisitor::visitSwizzleExpr( expr::Swizzle * expr )
	{
		m_allLiterals = false;
		auto outerId = submit( expr->getOuterExpr(), m_currentBlock, m_module );
		auto rawTypeId = m_module.registerType( expr->getType() );
		auto pointerTypeId = m_module.registerPointerType( rawTypeId, spv::StorageClass::Function );
		m_result = writeShuffle( m_module, m_currentBlock, pointerTypeId, outerId, expr->getSwizzle() );
	}

	void ExprVisitor::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		m_allLiterals = false;
		IdList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( submit( arg.get(), m_currentBlock, m_module ) );
		}

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		auto kind = expr->getTextureAccess();
		uint32_t imageOperandsIndex = 0u;
		auto op = getSpirVName( kind, imageOperandsIndex );

		if ( imageOperandsIndex )
		{
			assert( args.size() >= imageOperandsIndex );
			auto mask = getMask( kind );
			args.insert( args.begin() + imageOperandsIndex, spv::Id( mask ) );

			if ( uint32_t( mask ) & uint32_t( spv::ImageOperandsMask::Bias ) )
			{
				// Bias is the last parameter in GLSL, but it has to be the first one after the ImageOperands in SPIR-V.
				args.insert( args.begin() + imageOperandsIndex + 1u, args.back() );
				args.erase( args.begin() + args.size() - 1u );
			}
		}
		else
		{
			// We need to extract the image from the sampled image, to give it to the final instruction.
			auto sampledImageType = expr->getArgList()[0]->getType();
			assert( sampledImageType->getKind() == type::Kind::eSampledImage );
			auto imageTypeId = m_module.registerType( std::static_pointer_cast< type::SampledImage >( sampledImageType )->getImageType() );
			auto imageId = m_module.getIntermediateResult();
			m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpImage
				, imageId
				, imageTypeId
				, IdList{ args[0] } ) );
			args[0] = imageId;
		}

		m_currentBlock.instructions.emplace_back( makeInstruction( op
			, m_result
			, typeId
			, args ) );
	}

	void ExprVisitor::handleCarryBorrowIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is carry or borrow.
		assert( expr->getArgList().size() == 3u );
		IdList params;
		params.push_back( submit( expr->getArgList()[0].get(), m_currentBlock, m_module ) );
		params.push_back( submit( expr->getArgList()[1].get(), m_currentBlock, m_module ) );

		auto resultStructTypeId = getUnsignedExtendedResultTypeId( isVectorType( expr->getType()->getKind() )
			? getComponentCount( expr->getType()->getKind() )
			: 1 );
		auto resultCarryBorrowId = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction( opCode
			, resultCarryBorrowId
			, resultStructTypeId
			, params ) );

		auto & carryBorrowArg = *expr->getArgList()[2];
		auto carryBorrowTypeId = m_module.registerType( carryBorrowArg.getType() );
		auto intermediate = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpCompositeExtract
			, intermediate
			, carryBorrowTypeId
			, IdList{ resultCarryBorrowId, 1u } ) );
		auto carryBorrowId = getVariableIdNoLoad( &carryBorrowArg );
		m_currentBlock.instructions.emplace_back( makeStore( carryBorrowId, intermediate ) );

		auto resultTypeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpCompositeExtract
			, m_result
			, resultTypeId
			, IdList{ resultCarryBorrowId, 0u } ) );

		m_module.putIntermediateResult( intermediate );
	}

	void ExprVisitor::handleMulExtendedIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr )
	{
		// Arg 1 is lhs.
		// Arg 2 is rhs.
		// Arg 3 is msb.
		// Arg 4 is lsb.
		assert( expr->getArgList().size() == 4u );
		IdList params;
		params.push_back( submit( expr->getArgList()[0].get(), m_currentBlock, m_module ) );
		params.push_back( submit( expr->getArgList()[1].get(), m_currentBlock, m_module ) );
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
		m_currentBlock.instructions.emplace_back( makeInstruction( opCode
			, resultMulExtendedId
			, resultStructTypeId
			, params ) );

		auto & msbArg = *expr->getArgList()[2];
		auto msbTypeId = m_module.registerType( msbArg.getType() );
		auto intermediateMsb = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpCompositeExtract
			, intermediateMsb
			, msbTypeId
			, IdList{ resultMulExtendedId, 1u } ) );
		auto msbId = getVariableIdNoLoad( &msbArg );
		m_currentBlock.instructions.emplace_back( makeStore( msbId, intermediateMsb ) );

		auto & lsbArg = *expr->getArgList()[3];
		auto lsbTypeId = m_module.registerType( lsbArg.getType() );
		auto intermediateLsb = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpCompositeExtract
			, intermediateLsb
			, lsbTypeId
			, IdList{ resultMulExtendedId, 0u } ) );
		auto lsbId = getVariableIdNoLoad( &lsbArg );
		m_currentBlock.instructions.emplace_back( makeStore( lsbId, intermediateLsb ) );

		m_module.putIntermediateResult( intermediateMsb );
		m_module.putIntermediateResult( intermediateLsb );
		m_module.putIntermediateResult( resultMulExtendedId );
	}

	void ExprVisitor::handleAtomicIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr )
	{
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = submit( arg.get(), m_currentBlock, m_module );
			params.push_back( id );
		}

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		auto scopeId = m_module.registerLiteral( uint32_t( spv::Scope::Device ) );
		auto memorySemanticsId = m_module.registerLiteral( uint32_t( spv::MemorySemanticsMask::AcquireRelease ) );
		uint32_t index{ 1u };
		params.insert( params.begin() + ( index++ ), scopeId );
		params.insert( params.begin() + ( index++ ), memorySemanticsId );
		m_currentBlock.instructions.emplace_back( makeInstruction( opCode
			, m_result
			, typeId
			, params ) );
	}

	void ExprVisitor::handleExtensionIntrinsicCallExpr( spv::Id opCode, expr::IntrinsicCall * expr )
	{
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = submit( arg.get(), m_currentBlock, m_module );
			params.push_back( id );
		}

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		params.insert( params.begin(), opCode );
		params.insert( params.begin(), 1u );
		m_currentBlock.instructions.emplace_back( makeInstruction( spv::Op::OpExtInst
			, m_result
			, typeId
			, params ) );
	}

	void ExprVisitor::handleOtherIntrinsicCallExpr( spv::Op opCode, expr::IntrinsicCall * expr )
	{
		IdList params;

		for ( auto & arg : expr->getArgList() )
		{
			auto id = submit( arg.get(), m_currentBlock, m_module );
			params.push_back( id );
		}

		auto typeId = m_module.registerType( expr->getType() );
		m_result = m_module.getIntermediateResult();
		m_currentBlock.instructions.emplace_back( makeInstruction( opCode
			, m_result
			, typeId
			, params ) );
	}

	spv::Id ExprVisitor::getUnsignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_unsignedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeU" + std::to_string( count + 1u );
			m_unsignedExtendedTypes[count] = type::makeStructType( type::MemoryLayout::eStd430, name );
			auto type = count == 3
				? type::getVec4U()
				: ( count == 2
					? type::getVec3U()
					: ( count == 1
						? type::getVec2U()
						: ( type::getUInt() ) ) );
			m_unsignedExtendedTypes[count]->declMember( "result", type );
			m_unsignedExtendedTypes[count]->declMember( "extended", type );
		}

		return m_module.registerType( m_unsignedExtendedTypes[count] );
	}

	spv::Id ExprVisitor::getSignedExtendedResultTypeId( uint32_t count )
	{
		--count;

		if ( !m_signedExtendedTypes[count] )
		{
			std::string name = "SDW_ExtendedResultTypeS" + std::to_string( count + 1u );
			m_signedExtendedTypes[count] = type::makeStructType( type::MemoryLayout::eStd430, name );
			auto type = count == 3
				? type::getVec4I()
				: ( count == 2
					? type::getVec3I()
					: ( count == 1
						? type::getVec2I()
						: ( type::getInt() ) ) );
			m_signedExtendedTypes[count]->declMember( "result", type );
			m_signedExtendedTypes[count]->declMember( "extended", type );
		}

		return m_module.registerType( m_signedExtendedTypes[count] );
	}

	spv::Id ExprVisitor::getVariableIdNoLoad( expr::Expr * expr )
	{
		spv::Id result;

		if ( isAccessChain( expr ) )
		{
			result = submit( expr, m_currentBlock, m_module );
		}
		else
		{
			auto ident = sdw::findIdentifier( expr );

			if ( ident )
			{
				auto var = ident->getVariable();
				result = m_module.registerVariable( var->getName()
					, getStorageClass( var )
					, var->getType() );
			}
			else
			{
				result = submit( expr, m_currentBlock, m_module );
			}
		}

		return result;
	}
}
