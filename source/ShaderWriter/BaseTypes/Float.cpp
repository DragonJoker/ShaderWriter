/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Float.hpp"

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

namespace
{
	void compileFloat()
	{
		bool ignore;
		auto a = 0.0_f;
		auto b = 1.0_f;
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
		a += 1.0f;
		a -= 1.0f;
		a *= 1.0f;
		a /= 1.0f;
		ignore = a == 1.0f;
		ignore = a != 1.0f;
		ignore = a <= 1.0f;
		ignore = a >= 1.0f;
		ignore = a < 1.0f;
		ignore = a > 1.0f;
		a + 1.0f;
		a - 1.0f;
		a * 1.0f;
		a / 1.0f;
		ignore = 1.0f == a;
		ignore = 1.0f != a;
		ignore = 1.0f <= a;
		ignore = 1.0f >= a;
		ignore = 1.0f < a;
		ignore = 1.0f > a;
		1.0f + a;
		1.0f - a;
		1.0f * a;
		1.0f / a;
	}
}
