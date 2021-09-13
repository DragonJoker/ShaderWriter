/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Double.hpp"

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

namespace
{
	void compileDouble()
	{
		bool ignore;
		auto a = 0.0_d;
		auto b = 1.0_d;
		a += b;
		a -= b;
		a *= b;
		a /= b;
		ignore = a == b;
		ignore = a != b;
		ignore = a <= b;
		ignore = a >= b;
		ignore = a < b;
		ignore = a > b;
		a + b;
		a - b;
		a * b;
		a / b;
		a += 1.0;
		a -= 1.0;
		a *= 1.0;
		a /= 1.0;
		ignore = a == 1.0;
		ignore = a != 1.0;
		ignore = a <= 1.0;
		ignore = a >= 1.0;
		ignore = a < 1.0;
		ignore = a > 1.0;
		a + 1.0;
		a - 1.0;
		a * 1.0;
		a / 1.0;
		ignore = 1.0 == a;
		ignore = 1.0 != a;
		ignore = 1.0 <= a;
		ignore = 1.0 >= a;
		ignore = 1.0 < a;
		ignore = 1.0 > a;
		1.0 + a;
		1.0 - a;
		1.0 * a;
		1.0 / a;
	}
}
