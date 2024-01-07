/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/UInt.hpp"

#pragma warning( disable: 4619 )
#pragma warning( disable: 5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

namespace
{
	void compileUInt()
	{
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
		a += 1u;
		a -= 1u;
		a *= 1u;
		a /= 1u;
		a %= 1u;
		a <<= 1u;
		a >>= 1u;
		a &= 1u;
		a |= 1u;
		a ^= 1u;
		ignore = a == 1u;
		ignore = a != 1u;
		ignore = a <= 1u;
		ignore = a >= 1u;
		ignore = a < 1u;
		ignore = a > 1u;
		a + 1u;
		a - 1u;
		a * 1u;
		a / 1u;
		a % 1u;
		a << 1u;
		a >> 1u;
		a & 1u;
		a | 1u;
		a ^ 1u;
		ignore = 1u == a;
		ignore = 1u != a;
		ignore = 1u <= a;
		ignore = 1u >= a;
		ignore = 1u < a;
		ignore = 1u > a;
		1u + a;
		1u - a;
		1u * a;
		1u / a;
		1u % a;
		1u << a;
		1u >> a;
		1u & a;
		1u | a;
		1u ^ a;
	}
}
