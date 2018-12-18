/*
See LICENSE file in root folder
*/
#include "HlslIntrinsicFunctions.hpp"

#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtComment.hpp>

namespace hlsl
{
	namespace details
	{
		inline void writeACosh1F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_acosh(float x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x - 1.0 ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeACosh2F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_acosh(float2 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x - 1.0.xx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeACosh3F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_acosh(float3 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x - 1.0.xxx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeACosh4F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_acosh(float4 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x - 1.0.xxxx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
		
		inline void writeASinh1F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_asinh(float x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x + 1.0 ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeASinh2F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_asinh(float2 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x + 1.0.xx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeASinh3F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_asinh(float3 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x + 1.0.xxx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeASinh4F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_asinh(float4 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return log( x + sqrt( x * x + 1.0.xxxx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh1F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_atanh(float x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return 0.5 * log( ( x + 1.0 ) / ( x - 1.0 ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh2F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_atanh(float2 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return 0.5.xx * log( ( x + 1.0.xx ) / ( x - 1.0.xx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh3F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_atanh(float3 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return 0.5.xxx * log( ( x + 1.0.xxx ) / ( x - 1.0.xxx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh4F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_atanh(float4 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return 0.5.xxxx * log( ( x + 1.0.xxxx ) / ( x - 1.0.xxxx ) );" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven1F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_roundEven(float x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0 ) ) * 2.0;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven2F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float2 SDW_roundEven(float2 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0.xx ) ) * 2.0.xx;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven3F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float3 SDW_roundEven(float3 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0.xxx ) ) * 2.0.xxx;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven4F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float4 SDW_roundEven(float4 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0.xxxx ) ) * 2.0.xxxx;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven1D( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "double SDW_roundEven(double x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0 ) ) * 2.0;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven2D( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "double2 SDW_roundEven(double2 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0.xx ) ) * 2.0.xx;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven3D( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "double3 SDW_roundEven(double3 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0.xxx ) ) * 2.0.xxx;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven4D( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "double4 SDW_roundEven(double4 x)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return ( round( x / 2.0.xxxx ) ) * 2.0.xxxx;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackDouble2x32( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "double SDW_packDouble2x32(uint2 v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return asdouble(v.x, v.y);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackDouble2x32( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint2 SDW_unpackDouble2x32(double v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 res;" ) );
			cont->addStmt( ast::stmt::makeComment( "	asuint(v, res.x, res.y);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return res;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackHalf2x16( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_packHalf2x16(float2 v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 p = f32tof16(v);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return p.x | (p.y << 16);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackHalf2x16( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float2 SDW_unpackHalf2x16(uint v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return f16tof32(uint2(v & 0xFFFF, v >> 16));" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackSnorm2x16( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_packSnorm2x16(float2 v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int2 p = int2(round(clamp(v, -1.0, 1.0) * 32767.0)) & 0xFFFF;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return uint(p.x | (p.y << 16));" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackSnorm2x16( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float2 SDW_unpackSnorm2x16(uint v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int s = int(v);" ) );
			cont->addStmt( ast::stmt::makeComment( "	int2 p = int2(s << 16, s) >> 24;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return clamp(p / 32767.0, -1.0, 1.0);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackUnorm2x16( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_packUnorm2x16(float2 v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 p = uint2(round(saturate(v) * 65535.0));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return p.x | (p.y << 16);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackUnorm2x16( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float2 SDW_unpackUnorm2x16(uint v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 p = uint2(v & 0xFFFF, v >> 16);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return float2(p) / 65535.0;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackSnorm4x8( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_packSnorm4x8(float4 v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int4 p = int4(round(clamp(v, -1.0, 1.0) * 127.0)) & 0xFF;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return uint(p.x | (p.y << 8) | (p.z << 16) | (p.w << 24));" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackSnorm4x8( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float4 SDW_unpackSnorm4x8(uint v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int s = int(v);" ) );
			cont->addStmt( ast::stmt::makeComment( "	int4 p = int4(s << 24, s << 16, s << 8, s) >> 24;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return clamp(float4(p) / 127.0, -1.0, 1.0);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackUnorm4x8( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_packUnorm4x8(float4 v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint4 p = uint4(round(clamp(v, 0.0, 1.0) * 255.0));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return uint(p.x | (p.y << 8) | (p.z << 16) | (p.w << 24));" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackUnorm4x8( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float4 SDW_unpackUnorm4x8(uint v)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint4 p = uint4(v & 0xFF, (v >> 8) & 0xFF, (v >> 16) & 0xFF, v >> 24);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return float4(p) / 255.0;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse2x2F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float2x2 SDW_Inverse(float2x2 m)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	float2x2 adj;" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][0] =  m[1][1];" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][1] = -m[0][1];" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][0] = -m[1][0];" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][1] =  m[0][0];" ) );
			cont->addStmt( ast::stmt::makeComment( "	float det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse2x2D( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "double2x2 SDW_Inverse(double2x2 m)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	double2x2 adj;" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][0] =  m[1][1];" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][1] = -m[0][1];" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][0] = -m[1][0];" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][1] =  m[0][0];" ) );
			cont->addStmt( ast::stmt::makeComment( "	double det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse3x3F( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "float SDW_Det2x2(float a1, float a2, float b1, float b2)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			cont->addStmt( ast::stmt::makeComment( "" ) );
			cont->addStmt( ast::stmt::makeComment( "float3x3 SDW_Inverse(float3x3 m)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	float3x3 adj;" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][0] =  SDW_Det2x2(m[1][1], m[1][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][1] = -SDW_Det2x2(m[0][1], m[0][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][2] =  SDW_Det2x2(m[0][1], m[0][2], m[1][1], m[1][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][0] = -SDW_Det2x2(m[1][0], m[1][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][1] =  SDW_Det2x2(m[0][0], m[0][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][2] = -SDW_Det2x2(m[0][0], m[0][2], m[1][0], m[1][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][0] =  SDW_Det2x2(m[1][0], m[1][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][1] = -SDW_Det2x2(m[0][0], m[0][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][2] =  SDW_Det2x2(m[0][0], m[0][1], m[1][0], m[1][1]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	float det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse3x3D( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "double SDW_Det2x2(double a1, double a2, double b1, double b2)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			cont->addStmt( ast::stmt::makeComment( "" ) );
			cont->addStmt( ast::stmt::makeComment( "double3x3 SDW_Inverse(double3x3 m)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	double3x3 adj;" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][0] =  SDW_Det2x2(m[1][1], m[1][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][1] = -SDW_Det2x2(m[0][1], m[0][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][2] =  SDW_Det2x2(m[0][1], m[0][2], m[1][1], m[1][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][0] = -SDW_Det2x2(m[1][0], m[1][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][1] =  SDW_Det2x2(m[0][0], m[0][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][2] = -SDW_Det2x2(m[0][0], m[0][2], m[1][0], m[1][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][0] =  SDW_Det2x2(m[1][0], m[1][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][1] = -SDW_Det2x2(m[0][0], m[0][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][2] =  SDW_Det2x2(m[0][0], m[0][1], m[1][0], m[1][1]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	double det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse4x4F( ast::stmt::Container * container
			, IntrinsicsConfig const & config )
		{
			auto cont = ast::stmt::makeContainer();

			if ( !config.requiresInverse3x3F )
			{
				cont->addStmt( ast::stmt::makeComment( "float SDW_Det2x2(float a1, float a2, float b1, float b2)" ) );
				cont->addStmt( ast::stmt::makeComment( "{" ) );
				cont->addStmt( ast::stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
				cont->addStmt( ast::stmt::makeComment( "}" ) );
				cont->addStmt( ast::stmt::makeComment( "" ) );
			}

			cont->addStmt( ast::stmt::makeComment( "float SDW_Det3x3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return a1 * SDW_Det2x2(b2, b3, c2, c3) - b1 * SDW_Det2x2(a2, a3, c2, c3) + c1 * SDW_Det2x2(a2, a3, b2, b3);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			cont->addStmt( ast::stmt::makeComment( "" ) );
			cont->addStmt( ast::stmt::makeComment( "float4x4 SDW_Inverse(float4x4 m)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	float4x4 adj;" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][0] =  SDW_Det3x3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][1] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][2] =  SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][3] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][0] = -SDW_Det3x3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][1] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][2] = -SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][3] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][0] =  SDW_Det3x3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][1] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][2] =  SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][3] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][0] = -SDW_Det3x3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][1] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][2] = -SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][3] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	float det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]) + (adj[0][3] * m[3][0]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse4x4D( ast::stmt::Container * container
			, IntrinsicsConfig const & config )
		{
			auto cont = ast::stmt::makeContainer();

			if ( !config.requiresInverse3x3D )
			{
				cont->addStmt( ast::stmt::makeComment( "double SDW_Det2x2(double a1, double a2, double b1, double b2)" ) );
				cont->addStmt( ast::stmt::makeComment( "{" ) );
				cont->addStmt( ast::stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
				cont->addStmt( ast::stmt::makeComment( "}" ) );
				cont->addStmt( ast::stmt::makeComment( "" ) );
			}

			cont->addStmt( ast::stmt::makeComment( "double SDW_Det3x3(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	return a1 * SDW_Det2x2(b2, b3, c2, c3) - b1 * SDW_Det2x2(a2, a3, c2, c3) + c1 * SDW_Det2x2(a2, a3, b2, b3);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			cont->addStmt( ast::stmt::makeComment( "" ) );
			cont->addStmt( ast::stmt::makeComment( "double4x4 SDW_Inverse(double4x4 m)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	double4x4 adj;" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][0] =  SDW_Det3x3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][1] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][2] =  SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[0][3] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][0] = -SDW_Det3x3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][1] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][2] = -SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[1][3] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][0] =  SDW_Det3x3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][1] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][2] =  SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[2][3] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][0] = -SDW_Det3x3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][1] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][2] = -SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	adj[3][3] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	double det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]) + (adj[0][3] * m[3][0]);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry1( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_uaddCarry(uint x, uint y, out uint carry)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r, carry, x, y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry2( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint2 SDW_uaddCarry(uint2 x, uint2 y, out uint2 carry)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry3( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint3 SDW_uaddCarry(uint3 x, uint3 y, out uint3 carry)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint3 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.z, carry.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry4( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint4 SDW_uaddCarry(uint4 x, uint4 y, out uint4 carry)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint4 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.z, carry.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	uaddc r.w, carry.w, x.w, y.w;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow1( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_usubBorrow(uint x, uint y, out uint borrow)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r, borrow, x, y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow2( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint2 SDW_usubBorrow(uint2 x, uint2 y, out uint2 borrow)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow3( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint3 SDW_usubBorrow(uint3 x, uint3 y, out uint3 borrow)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint3 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.z, borrow.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow4( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint4 SDW_usubBorrow(uint4 x, uint4 y, out uint4 borrow)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint4 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.z, borrow.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	usubb r.w, borrow.w, x.w, y.w;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended1( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_umulExtended(uint x, uint y, out uint msb, out uint lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb, lsb, x, y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended2( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint2 SDW_umulExtended(uint2 x, uint2 y, out uint2 msb, out uint2 lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended3( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint3 SDW_umulExtended(uint3 x, uint3 y, out uint3 msb, out uint3 lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint3 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended4( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint4 SDW_umulExtended(uint4 x, uint4 y, out uint4 msb, out uint4 lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint4 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	umul msb.w, lsb.w, x.w, y.w;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended1( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int SDW_imulExtended(int x, int y, out int msb, out int lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb, lsb, x, y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended2( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int2 SDW_imulExtended(int2 x, int2 y, out int2 msb, out int2 lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int2 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended3( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int3 SDW_imulExtended(int3 x, int3 y, out int3 msb, out int3 lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int3 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended4( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int4 SDW_imulExtended(int4 x, int4 y, out int4 msb, out int4 lsb)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int4 r;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( ast::stmt::makeComment( "	imul msb.w, lsb.w, x.w, y.w;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return r;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert1I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int SDW_bitfieldInsert(int base, int insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert2I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int2 SDW_bitfieldInsert(int2 base, int2 insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert3I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int3 SDW_bitfieldInsert(int3 base, int3 insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert4I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int4 SDW_bitfieldInsert(int4 base, int4 insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert1U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_bitfieldInsert(uint base, uint insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert2U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint2 SDW_bitfieldInsert(uint2 base, uint2 insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert3U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint3 SDW_bitfieldInsert(uint3 base, uint3 insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert4U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint4 SDW_bitfieldInsert(uint4 base, uint4 insert, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract1I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int SDW_bitfieldExtract(int base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	int masked = (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract2I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int2 SDW_bitfieldExtract(int2 base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	int2 masked = (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract3I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int3 SDW_bitfieldExtract(int3 base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	int3 masked = (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract4I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int4 SDW_bitfieldExtract(int4 base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	int4 masked = (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract1U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint SDW_bitfieldExtract(uint base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract2U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint2 SDW_bitfieldExtract(uint2 base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract3U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint3 SDW_bitfieldExtract(uint3 base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract4U( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "uint4 SDW_bitfieldExtract(uint4 base, int offset, int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( ast::stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse1I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int SDW_reverseBits(int bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint tmp = reversebits(uint(bits));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return int(tmp);" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse2I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int2 SDW_reverseBits(int2 bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint2 tmp = reversebits(uint2(uint(bits.x), uint(bits.y)));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return int2(int(tmp.x), int(tmp.y));" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse3I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int3 SDW_reverseBits(int3 bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint3 tmp = reversebits(uint3(uint(bits.x), uint(bits.y), uint(bits.z)));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return int3(int(tmp.x), int(tmp.y), int(tmp.z));" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse4I( ast::stmt::Container * container )
		{
			auto cont = ast::stmt::makeContainer();
			cont->addStmt( ast::stmt::makeComment( "int4 SDW_reverseBits(int4 bits)" ) );
			cont->addStmt( ast::stmt::makeComment( "{" ) );
			cont->addStmt( ast::stmt::makeComment( "	uint4 tmp = reversebits(uint4(uint(bits.x), uint(bits.y), uint(bits.z), uint(bits.w)));" ) );
			cont->addStmt( ast::stmt::makeComment( "	return int4(int(tmp.x), int(tmp.y), int(tmp.z), int(tmp.w));" ) );
			cont->addStmt( ast::stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
	}

	void compileHlslIntrinsicFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
		if ( config.requiresACosh1F )
		{
			details::writeACosh1F( container );
		}
		if ( config.requiresACosh2F )
		{
			details::writeACosh2F( container );
		}
		if ( config.requiresACosh3F )
		{
			details::writeACosh3F( container );
		}
		if ( config.requiresACosh4F )
		{
			details::writeACosh4F( container );
		}
		if ( config.requiresASinh1F )
		{
			details::writeASinh1F( container );
		}
		if ( config.requiresASinh2F )
		{
			details::writeASinh2F( container );
		}
		if ( config.requiresASinh3F )
		{
			details::writeASinh3F( container );
		}
		if ( config.requiresASinh4F )
		{
			details::writeASinh4F( container );
		}
		if ( config.requiresATanh1F )
		{
			details::writeATanh1F( container );
		}
		if ( config.requiresATanh2F )
		{
			details::writeATanh2F( container );
		}
		if ( config.requiresATanh3F )
		{
			details::writeATanh3F( container );
		}
		if ( config.requiresATanh4F )
		{
			details::writeATanh4F( container );
		}
		if ( config.requiresRoundEven1F )
		{
			details::writeRoundEven1F( container );
		}
		if ( config.requiresRoundEven2F )
		{
			details::writeRoundEven2F( container );
		}
		if ( config.requiresRoundEven3F )
		{
			details::writeRoundEven3F( container );
		}
		if ( config.requiresRoundEven4F )
		{
			details::writeRoundEven4F( container );
		}
		if ( config.requiresRoundEven1D )
		{
			details::writeRoundEven1D( container );
		}
		if ( config.requiresRoundEven2D )
		{
			details::writeRoundEven2D( container );
		}
		if ( config.requiresRoundEven3D )
		{
			details::writeRoundEven3D( container );
		}
		if ( config.requiresRoundEven4D )
		{
			details::writeRoundEven4D( container );
		}
		if ( config.requiresPackDouble2x32 )
		{
			details::writePackDouble2x32( container );
		}
		if ( config.requiresPackHalf2x16 )
		{
			details::writePackHalf2x16( container );
		}
		if ( config.requiresPackSnorm2x16 )
		{
			details::writePackSnorm2x16( container );
		}
		if ( config.requiresPackUnorm2x16 )
		{
			details::writePackUnorm2x16( container );
		}
		if ( config.requiresPackSnorm4x8 )
		{
			details::writePackSnorm4x8( container );
		}
		if ( config.requiresPackUnorm4x8 )
		{
			details::writePackUnorm4x8( container );
		}
		if ( config.requiresUnpackDouble2x32 )
		{
			details::writeUnpackDouble2x32( container );
		}
		if ( config.requiresUnpackHalf2x16 )
		{
			details::writeUnpackHalf2x16( container );
		}
		if ( config.requiresUnpackSnorm2x16 )
		{
			details::writeUnpackSnorm2x16( container );
		}
		if ( config.requiresUnpackUnorm2x16 )
		{
			details::writeUnpackUnorm2x16( container );
		}
		if ( config.requiresUnpackSnorm4x8 )
		{
			details::writeUnpackSnorm4x8( container );
		}
		if ( config.requiresUnpackUnorm4x8 )
		{
			details::writeUnpackUnorm4x8( container );
		}
		if ( config.requiresInverse2x2F )
		{
			details::writeInverse2x2F( container );
		}
		if ( config.requiresInverse2x2D )
		{
			details::writeInverse2x2D( container );
		}
		if ( config.requiresInverse3x3F )
		{
			details::writeInverse3x3F( container );
		}
		if ( config.requiresInverse3x3D )
		{
			details::writeInverse3x3D( container );
		}
		if ( config.requiresInverse4x4F )
		{
			details::writeInverse4x4F( container, config );
		}
		if ( config.requiresInverse4x4D )
		{
			details::writeInverse4x4D( container, config );
		}
		if ( config.requiresUaddCarry1 )
		{
			details::writeUaddCarry1( container );
		}
		if ( config.requiresUaddCarry2 )
		{
			details::writeUaddCarry2( container );
		}
		if ( config.requiresUaddCarry3 )
		{
			details::writeUaddCarry3( container );
		}
		if ( config.requiresUaddCarry4 )
		{
			details::writeUaddCarry4( container );
		}
		if ( config.requiresUsubBorrow1 )
		{
			details::writeUsubBorrow1( container );
		}
		if ( config.requiresUsubBorrow2 )
		{
			details::writeUsubBorrow2( container );
		}
		if ( config.requiresUsubBorrow3 )
		{
			details::writeUsubBorrow3( container );
		}
		if ( config.requiresUsubBorrow4 )
		{
			details::writeUsubBorrow4( container );
		}
		if ( config.requiresUmulExtended1 )
		{
			details::writeUmulExtended1( container );
		}
		if ( config.requiresUmulExtended2 )
		{
			details::writeUmulExtended2( container );
		}
		if ( config.requiresUmulExtended3 )
		{
			details::writeUmulExtended3( container );
		}
		if ( config.requiresUmulExtended4 )
		{
			details::writeUmulExtended4( container );
		}
		if ( config.requiresImulExtended1 )
		{
			details::writeImulExtended1( container );
		}
		if ( config.requiresImulExtended2 )
		{
			details::writeImulExtended2( container );
		}
		if ( config.requiresImulExtended3 )
		{
			details::writeImulExtended3( container );
		}
		if ( config.requiresImulExtended4 )
		{
			details::writeImulExtended4( container );
		}
		if ( config.requiresBitfieldInsert1I )
		{
			details::writeBitfieldInsert1I( container );
		}
		if ( config.requiresBitfieldInsert2I )
		{
			details::writeBitfieldInsert2I( container );
		}
		if ( config.requiresBitfieldInsert3I )
		{
			details::writeBitfieldInsert3I( container );
		}
		if ( config.requiresBitfieldInsert4I )
		{
			details::writeBitfieldInsert4I( container );
		}
		if ( config.requiresBitfieldInsert1U )
		{
			details::writeBitfieldInsert1U( container );
		}
		if ( config.requiresBitfieldInsert2U )
		{
			details::writeBitfieldInsert2U( container );
		}
		if ( config.requiresBitfieldInsert3U )
		{
			details::writeBitfieldInsert3U( container );
		}
		if ( config.requiresBitfieldInsert4U )
		{
			details::writeBitfieldInsert4U( container );
		}
		if ( config.requiresBitfieldExtract1I )
		{
			details::writeBitfieldExtract1I( container );
		}
		if ( config.requiresBitfieldExtract2I )
		{
			details::writeBitfieldExtract2I( container );
		}
		if ( config.requiresBitfieldExtract3I )
		{
			details::writeBitfieldExtract3I( container );
		}
		if ( config.requiresBitfieldExtract4I )
		{
			details::writeBitfieldExtract4I( container );
		}
		if ( config.requiresBitfieldExtract1U )
		{
			details::writeBitfieldExtract1U( container );
		}
		if ( config.requiresBitfieldExtract2U )
		{
			details::writeBitfieldExtract2U( container );
		}
		if ( config.requiresBitfieldExtract3U )
		{
			details::writeBitfieldExtract3U( container );
		}
		if ( config.requiresBitfieldExtract4U )
		{
			details::writeBitfieldExtract4U( container );
		}
		if ( config.requiresBitfieldReverse1I )
		{
			details::writeBitfieldReverse1I( container );
		}
		if ( config.requiresBitfieldReverse2I )
		{
			details::writeBitfieldReverse2I( container );
		}
		if ( config.requiresBitfieldReverse3I )
		{
			details::writeBitfieldReverse3I( container );
		}
		if ( config.requiresBitfieldReverse4I )
		{
			details::writeBitfieldReverse4I( container );
		}
	}
}
