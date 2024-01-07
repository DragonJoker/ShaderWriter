/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"

#pragma warning( disable: 4619 )
#pragma warning( disable: 5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

namespace
{
	void compileInt()
	{
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
		auto ignore = a == b;
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
