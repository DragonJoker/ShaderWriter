/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp"

#include <ASTGenerator/Expr/EnumIntrinsic.hpp>
#include <ASTGenerator/Expr/ExprBitAnd.hpp>
#include <ASTGenerator/Expr/ExprBitOr.hpp>
#include <ASTGenerator/Expr/ExprCast.hpp>
#include <ASTGenerator/Expr/ExprDivide.hpp>
#include <ASTGenerator/Expr/ExprEqual.hpp>
#include <ASTGenerator/Expr/ExprInit.hpp>
#include <ASTGenerator/Expr/ExprIntrinsicCall.hpp>
#include <ASTGenerator/expr/ExprLiteral.hpp>
#include <ASTGenerator/expr/ExprLShift.hpp>
#include <ASTGenerator/expr/ExprLShiftAssign.hpp>
#include <ASTGenerator/expr/ExprMbrSelect.hpp>
#include <ASTGenerator/expr/ExprOrAssign.hpp>
#include <ASTGenerator/expr/ExprRShift.hpp>
#include <ASTGenerator/expr/ExprRShiftAssign.hpp>
#include <ASTGenerator/expr/ExprTimes.hpp>

#include <ASTGenerator/Stmt/StmtFunctionDecl.hpp>
#include <ASTGenerator/Stmt/StmtReturn.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>
#include <ASTGenerator/Stmt/StmtVariableDecl.hpp>

#include <string>

namespace sdw::hlsl
{
	namespace details
	{
		using namespace ast;

		inline void writeRoundEven1F( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_roundEven(float x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0 ) ) * 2.0;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven2F( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_roundEven(float2 x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0.xx ) ) * 2.0.xx;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven3F( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float3 SDW_roundEven(float3 x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0.xxx ) ) * 2.0.xxx;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven4F( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float4 SDW_roundEven(float4 x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0.xxxx ) ) * 2.0.xxxx;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven1D( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "double SDW_roundEven(double x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0 ) ) * 2.0;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven2D( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "double2 SDW_roundEven(double2 x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0.xx ) ) * 2.0.xx;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven3D( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "double3 SDW_roundEven(double3 x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0.xxx ) ) * 2.0.xxx;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven4D( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "double4 SDW_roundEven(double4 x)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return ( round( x / 2.0.xxxx ) ) * 2.0.xxxx;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackDouble2x32( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "double SDW_packDouble2x32(uint2 v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return asdouble(v.x, v.y);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackDouble2x32( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint2 SDW_unpackDouble2x32(double v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint2 res;" ) );
			cont->addStmt( stmt::makeComment( "	asuint(v, res.x, res.y);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackHalf2x16( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_packHalf2x16(float2 v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint2 p = f32tof16(v);" ) );
			cont->addStmt( stmt::makeComment( "	return p.x | (p.y << 16);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackHalf2x16( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_unpackHalf2x16(uint v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return f16tof32(uint2(v & 0xFFFF, v >> 16));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackSnorm2x16( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_packSnorm2x16(float2 v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int2 p = int2(round(clamp(v, -1.0, 1.0) * 32767.0)) & 0xFFFF;" ) );
			cont->addStmt( stmt::makeComment( "	return uint(p.x | (p.y << 16));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackSnorm2x16( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_unpackSnorm2x16(uint v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int s = int(v);" ) );
			cont->addStmt( stmt::makeComment( "	int2 p = int2(s << 16, s) >> 24;" ) );
			cont->addStmt( stmt::makeComment( "	return clamp(p / 32767.0, -1.0, 1.0);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackUnorm2x16( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_packUnorm2x16(float2 v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint2 p = uint2(round(saturate(v) * 65535.0));" ) );
			cont->addStmt( stmt::makeComment( "	return p.x | (p.y << 16);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackUnorm2x16( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2 SDW_unpackUnorm2x16(uint v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint2 p = uint2(v & 0xFFFF, v >> 16);" ) );
			cont->addStmt( stmt::makeComment( "	return float2(p) / 65535.0;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackSnorm4x8( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_packSnorm4x8(float4 v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int4 p = int4(round(clamp(v, -1.0, 1.0) * 127.0)) & 0xFF;" ) );
			cont->addStmt( stmt::makeComment( "	return uint(p.x | (p.y << 8) | (p.z << 16) | (p.w << 24));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackSnorm4x8( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float4 SDW_unpackSnorm4x8(uint v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int s = int(v);" ) );
			cont->addStmt( stmt::makeComment( "	int4 p = int4(s << 24, s << 16, s << 8, s) >> 24;" ) );
			cont->addStmt( stmt::makeComment( "	return clamp(float4(p) / 127.0, -1.0, 1.0);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackUnorm4x8( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_packUnorm4x8(float4 v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint4 p = uint4(round(clamp(v, 0.0, 1.0) * 255.0));" ) );
			cont->addStmt( stmt::makeComment( "	return uint(p.x | (p.y << 8) | (p.z << 16) | (p.w << 24));" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackUnorm4x8( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float4 SDW_unpackUnorm4x8(uint v)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint4 p = uint4(v & 0xFF, (v >> 8) & 0xFF, (v >> 16) & 0xFF, v >> 24);" ) );
			cont->addStmt( stmt::makeComment( "	return float4(p) / 255.0;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse2x2F( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float2x2 SDW_Inverse(float2x2 m)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	float2x2 adj;" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][0] =  m[1][1];" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][1] = -m[0][1];" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][0] = -m[1][0];" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][1] =  m[0][0];" ) );
			cont->addStmt( stmt::makeComment( "	float det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]);" ) );
			cont->addStmt( stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse2x2D( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "double2x2 SDW_Inverse(double2x2 m)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	double2x2 adj;" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][0] =  m[1][1];" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][1] = -m[0][1];" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][0] = -m[1][0];" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][1] =  m[0][0];" ) );
			cont->addStmt( stmt::makeComment( "	double det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]);" ) );
			cont->addStmt( stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse3x3F( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "float SDW_Det2x2(float a1, float a2, float b1, float b2)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			cont->addStmt( stmt::makeComment( "" ) );
			cont->addStmt( stmt::makeComment( "float3x3 SDW_Inverse(float3x3 m)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	float3x3 adj;" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][0] =  SDW_Det2x2(m[1][1], m[1][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][1] = -SDW_Det2x2(m[0][1], m[0][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][2] =  SDW_Det2x2(m[0][1], m[0][2], m[1][1], m[1][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][0] = -SDW_Det2x2(m[1][0], m[1][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][1] =  SDW_Det2x2(m[0][0], m[0][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][2] = -SDW_Det2x2(m[0][0], m[0][2], m[1][0], m[1][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][0] =  SDW_Det2x2(m[1][0], m[1][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][1] = -SDW_Det2x2(m[0][0], m[0][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][2] =  SDW_Det2x2(m[0][0], m[0][1], m[1][0], m[1][1]);" ) );
			cont->addStmt( stmt::makeComment( "	float det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]);" ) );
			cont->addStmt( stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse3x3D( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "double SDW_Det2x2(double a1, double a2, double b1, double b2)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			cont->addStmt( stmt::makeComment( "" ) );
			cont->addStmt( stmt::makeComment( "double3x3 SDW_Inverse(double3x3 m)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	double3x3 adj;" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][0] =  SDW_Det2x2(m[1][1], m[1][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][1] = -SDW_Det2x2(m[0][1], m[0][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][2] =  SDW_Det2x2(m[0][1], m[0][2], m[1][1], m[1][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][0] = -SDW_Det2x2(m[1][0], m[1][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][1] =  SDW_Det2x2(m[0][0], m[0][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][2] = -SDW_Det2x2(m[0][0], m[0][2], m[1][0], m[1][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][0] =  SDW_Det2x2(m[1][0], m[1][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][1] = -SDW_Det2x2(m[0][0], m[0][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][2] =  SDW_Det2x2(m[0][0], m[0][1], m[1][0], m[1][1]);" ) );
			cont->addStmt( stmt::makeComment( "	double det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]);" ) );
			cont->addStmt( stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse4x4F( stmt::Container * container
			, IntrinsicsConfig const & config )
		{
			auto cont = stmt::makeContainer();

			if ( !config.requiresInverse3x3F )
			{
				cont->addStmt( stmt::makeComment( "float SDW_Det2x2(float a1, float a2, float b1, float b2)" ) );
				cont->addStmt( stmt::makeComment( "{" ) );
				cont->addStmt( stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
				cont->addStmt( stmt::makeComment( "}" ) );
				cont->addStmt( stmt::makeComment( "" ) );
			}

			cont->addStmt( stmt::makeComment( "float SDW_Det3x3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return a1 * SDW_Det2x2(b2, b3, c2, c3) - b1 * SDW_Det2x2(a2, a3, c2, c3) + c1 * SDW_Det2x2(a2, a3, b2, b3);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			cont->addStmt( stmt::makeComment( "" ) );
			cont->addStmt( stmt::makeComment( "float4x4 SDW_Inverse(float4x4 m)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	float4x4 adj;" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][0] =  SDW_Det3x3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][1] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][2] =  SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][3] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][0] = -SDW_Det3x3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][1] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][2] = -SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][3] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][0] =  SDW_Det3x3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][1] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][2] =  SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][3] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][0] = -SDW_Det3x3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][1] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][2] = -SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][3] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	float det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]) + (adj[0][3] * m[3][0]);" ) );
			cont->addStmt( stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse4x4D( stmt::Container * container
			, IntrinsicsConfig const & config )
		{
			auto cont = stmt::makeContainer();

			if ( !config.requiresInverse3x3D )
			{
				cont->addStmt( stmt::makeComment( "double SDW_Det2x2(double a1, double a2, double b1, double b2)" ) );
				cont->addStmt( stmt::makeComment( "{" ) );
				cont->addStmt( stmt::makeComment( "	return a1 * b2 - b1 * a2;" ) );
				cont->addStmt( stmt::makeComment( "}" ) );
				cont->addStmt( stmt::makeComment( "" ) );
			}

			cont->addStmt( stmt::makeComment( "double SDW_Det3x3(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	return a1 * SDW_Det2x2(b2, b3, c2, c3) - b1 * SDW_Det2x2(a2, a3, c2, c3) + c1 * SDW_Det2x2(a2, a3, b2, b3);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			cont->addStmt( stmt::makeComment( "" ) );
			cont->addStmt( stmt::makeComment( "double4x4 SDW_Inverse(double4x4 m)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	double4x4 adj;" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][0] =  SDW_Det3x3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][1] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][2] =  SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[0][3] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][0] = -SDW_Det3x3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][1] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][2] = -SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[1][3] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][0] =  SDW_Det3x3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][1] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][2] =  SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[2][3] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][0] = -SDW_Det3x3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][1] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][2] = -SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmt::makeComment( "	adj[3][3] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmt::makeComment( "	double det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]) + (adj[0][3] * m[3][0]);" ) );
			cont->addStmt( stmt::makeComment( "	return (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry1( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_uaddCarry(uint x, uint y, out uint carry)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint r;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r, carry, x, y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint2 SDW_uaddCarry(uint2 x, uint2 y, out uint2 carry)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint2 r;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry3( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint3 SDW_uaddCarry(uint3 x, uint3 y, out uint3 carry)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint3 r;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.z, carry.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry4( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint4 SDW_uaddCarry(uint4 x, uint4 y, out uint4 carry)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint4 r;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.z, carry.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	uaddc r.w, carry.w, x.w, y.w;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow1( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_usubBorrow(uint x, uint y, out uint borrow)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint r;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r, borrow, x, y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint2 SDW_usubBorrow(uint2 x, uint2 y, out uint2 borrow)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint2 r;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow3( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint3 SDW_usubBorrow(uint3 x, uint3 y, out uint3 borrow)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint3 r;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.z, borrow.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow4( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint4 SDW_usubBorrow(uint4 x, uint4 y, out uint4 borrow)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint4 r;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.z, borrow.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	usubb r.w, borrow.w, x.w, y.w;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended1( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_umulExtended(uint x, uint y, out uint msb, out uint lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint r;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb, lsb, x, y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint2 SDW_umulExtended(uint2 x, uint2 y, out uint2 msb, out uint2 lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint2 r;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended3( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint3 SDW_umulExtended(uint3 x, uint3 y, out uint3 msb, out uint3 lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint3 r;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended4( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint4 SDW_umulExtended(uint4 x, uint4 y, out uint4 msb, out uint4 lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint4 r;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	umul msb.w, lsb.w, x.w, y.w;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended1( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imulExtended(int x, int y, out int msb, out int lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int r;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb, lsb, x, y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended2( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int2 SDW_imulExtended(int2 x, int2 y, out int2 msb, out int2 lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int2 r;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended3( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int3 SDW_imulExtended(int3 x, int3 y, out int3 msb, out int3 lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int3 r;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended4( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int4 SDW_imulExtended(int4 x, int4 y, out int4 msb, out int4 lsb)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int4 r;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmt::makeComment( "	imul msb.w, lsb.w, x.w, y.w;" ) );
			cont->addStmt( stmt::makeComment( "	return r;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert1I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_bitfieldInsert(int base, int insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert2I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int2 SDW_bitfieldInsert(int2 base, int2 insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert3I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int3 SDW_bitfieldInsert(int3 base, int3 insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert4I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int4 SDW_bitfieldInsert(int4 base, int4 insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert1U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_bitfieldInsert(uint base, uint insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert2U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint2 SDW_bitfieldInsert(uint2 base, uint2 insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert3U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint3 SDW_bitfieldInsert(uint3 base, uint3 insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert4U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint4 SDW_bitfieldInsert(uint4 base, uint4 insert, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmt::makeComment( "	return (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract1I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_bitfieldExtract(int base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	int masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract2I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int2 SDW_bitfieldExtract(int2 base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	int2 masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract3I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int3 SDW_bitfieldExtract(int3 base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	int3 masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract4I( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int4 SDW_bitfieldExtract(int4 base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int mask = bits == 32 ? -1 : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	int4 masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "	int extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmt::makeComment( "	return (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract1U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_bitfieldExtract(uint base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract2U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint2 SDW_bitfieldExtract(uint2 base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract3U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint3 SDW_bitfieldExtract(uint3 base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract4U( stmt::Container * container )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint4 SDW_bitfieldExtract(uint4 base, int offset, int bits)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint mask = bits == 32 ? 0xFFFFFFFF : ((1 << bits) - 1);" ) );
			cont->addStmt( stmt::makeComment( "	return (base >> offset) & mask;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
	}

	void compileHlslIntrinsicFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
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
	}
}
