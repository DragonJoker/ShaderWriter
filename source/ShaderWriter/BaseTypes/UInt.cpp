/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/UInt.hpp"

namespace
{
	void compileUInt()
	{
		bool ignore;
		auto a = 0_u;
		auto b = 1_u;
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
