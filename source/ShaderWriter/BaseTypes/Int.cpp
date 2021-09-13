/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

namespace
{
	void compileInt()
	{
		bool ignore;
		auto a = 0_i;
		auto b = 1_i;
		a += b;
		a -= b;
		a *= b;
		a /= b;
		a %= b;
		a <<= b;
		a >>= b;
		a &= b;
		a |= b;
		a ^= b;
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
		a % b;
		a << b;
		a >> b;
		a & b;
		a | b;
		a ^ b;
		a += 1;
		a -= 1;
		a *= 1;
		a /= 1;
		a %= 1;
		a <<= 1;
		a >>= 1;
		a &= 1;
		a |= 1;
		a ^= 1;
		ignore = a == 1;
		ignore = a != 1;
		ignore = a <= 1;
		ignore = a >= 1;
		ignore = a < 1;
		ignore = a > 1;
		a + 1;
		a - 1;
		a * 1;
		a / 1;
		a % 1;
		a << 1;
		a >> 1;
		a & 1;
		a | 1;
		a ^ 1;
		ignore = 1 == a;
		ignore = 1 != a;
		ignore = 1 <= a;
		ignore = 1 >= a;
		ignore = 1 < a;
		ignore = 1 > a;
		1 + a;
		1 - a;
		1 * a;
		1 / a;
		1 % a;
		1 << a;
		1 >> a;
		1 & a;
		1 | a;
		1 ^ a;
	}
}
