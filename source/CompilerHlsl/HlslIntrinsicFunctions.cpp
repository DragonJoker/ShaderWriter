/*
See LICENSE file in root folder
*/
#include "HlslIntrinsicFunctions.hpp"

#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtContainer.hpp>
#include <ShaderAST/Stmt/StmtComment.hpp>

namespace hlsl
{
	namespace details
	{
		inline void writeACosh1F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float SDW_acosh(float x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x - 1.0 ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeACosh2F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_acosh(float2 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x - 1.0.xx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeACosh3F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float3 SDW_acosh(float3 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x - 1.0.xxx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeACosh4F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float4 SDW_acosh(float4 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x - 1.0.xxxx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
		
		inline void writeASinh1F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float SDW_asinh(float x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x + 1.0 ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeASinh2F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_asinh(float2 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x + 1.0.xx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeASinh3F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float3 SDW_asinh(float3 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x + 1.0.xxx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeASinh4F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float4 SDW_asinh(float4 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn log( x + sqrt( x * x + 1.0.xxxx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh1F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float SDW_atanh(float x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn 0.5 * log( ( x + 1.0 ) / ( x - 1.0 ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh2F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_atanh(float2 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn 0.5.xx * log( ( x + 1.0.xx ) / ( x - 1.0.xx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh3F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float3 SDW_atanh(float3 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn 0.5.xxx * log( ( x + 1.0.xxx ) / ( x - 1.0.xxx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeATanh4F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float4 SDW_atanh(float4 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn 0.5.xxxx * log( ( x + 1.0.xxxx ) / ( x - 1.0.xxxx ) );" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven1F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float SDW_roundEven(float x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( x / 2.0 ) ) * 2.0;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven2F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_roundEven(float2 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( x / 2.0.xx ) ) * 2.0.xx;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven3F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float3 SDW_roundEven(float3 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( x / 2.0.xxx ) ) * 2.0.xxx;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven4F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float4 SDW_roundEven(float4 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( x / 2.0.xxxx ) ) * 2.0.xxxx;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven1D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double SDW_roundEven(double x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( float( x / 2.0 ) ) ) * 2.0;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven2D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double2 SDW_roundEven(double2 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( float2( x / 2.0.xx ) ) ) * 2.0.xx;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven3D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double3 SDW_roundEven(double3 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( float3( x / 2.0.xxx ) ) ) * 2.0.xxx;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeRoundEven4D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double4 SDW_roundEven(double4 x)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn ( round( float4( x / 2.0.xxxx ) ) ) * 2.0.xxxx;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackDouble2x32( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double SDW_packDouble2x32(uint2 v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn asdouble(v.x, v.y);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackDouble2x32( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint2 SDW_unpackDouble2x32(double v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 res;" ) );
			cont->addStmt( stmtCache.makeComment( "\tasuint(v, res.x, res.y);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn res;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackHalf2x16( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_packHalf2x16(float2 v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 p = f32tof16(v);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn p.x | (p.y << 16);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackHalf2x16( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_unpackHalf2x16(uint v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn f16tof32(uint2(v & 0xFFFF, v >> 16));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackSnorm2x16( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_packSnorm2x16(float2 v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint2 p = int2(round(clamp(v, -1.0, 1.0) * 32767.0)) & 0xFFFF;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn uint(p.x | (p.y << 16));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackSnorm2x16( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_unpackSnorm2x16(uint v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint s = int(v);" ) );
			cont->addStmt( stmtCache.makeComment( "\tint2 p = int2(s << 16, s) >> 24;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn clamp(p / 32767.0, -1.0, 1.0);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackUnorm2x16( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_packUnorm2x16(float2 v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 p = uint2(round(saturate(v) * 65535.0));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn p.x | (p.y << 16);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackUnorm2x16( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2 SDW_unpackUnorm2x16(uint v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 p = uint2(v & 0xFFFF, v >> 16);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn float2(p) / 65535.0;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackSnorm4x8( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_packSnorm4x8(float4 v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint4 p = int4(round(clamp(v, -1.0, 1.0) * 127.0)) & 0xFF;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn uint(p.x | (p.y << 8) | (p.z << 16) | (p.w << 24));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackSnorm4x8( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float4 SDW_unpackSnorm4x8(uint v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint s = int(v);" ) );
			cont->addStmt( stmtCache.makeComment( "\tint4 p = int4(s << 24, s << 16, s << 8, s) >> 24;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn clamp(float4(p) / 127.0, -1.0, 1.0);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writePackUnorm4x8( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_packUnorm4x8(float4 v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 p = uint4(round(clamp(v, 0.0, 1.0) * 255.0));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn uint(p.x | (p.y << 8) | (p.z << 16) | (p.w << 24));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUnpackUnorm4x8( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float4 SDW_unpackUnorm4x8(uint v)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 p = uint4(v & 0xFF, (v >> 8) & 0xFF, (v >> 16) & 0xFF, v >> 24);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn float4(p) / 255.0;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse2x2F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float2x2 SDW_Inverse(float2x2 m)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat2x2 adj;" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][0] =  m[1][1];" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][1] = -m[0][1];" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][0] = -m[1][0];" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][1] =  m[0][0];" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse2x2D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double2x2 SDW_Inverse(double2x2 m)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tdouble2x2 adj;" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][0] =  m[1][1];" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][1] = -m[0][1];" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][0] = -m[1][0];" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][1] =  m[0][0];" ) );
			cont->addStmt( stmtCache.makeComment( "\tdouble det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse3x3F( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "float SDW_Det2x2(float a1, float a2, float b1, float b2)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn a1 * b2 - b1 * a2;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			cont->addStmt( stmtCache.makeComment( "" ) );
			cont->addStmt( stmtCache.makeComment( "float3x3 SDW_Inverse(float3x3 m)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat3x3 adj;" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][0] =  SDW_Det2x2(m[1][1], m[1][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][1] = -SDW_Det2x2(m[0][1], m[0][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][2] =  SDW_Det2x2(m[0][1], m[0][2], m[1][1], m[1][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][0] = -SDW_Det2x2(m[1][0], m[1][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][1] =  SDW_Det2x2(m[0][0], m[0][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][2] = -SDW_Det2x2(m[0][0], m[0][2], m[1][0], m[1][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][0] =  SDW_Det2x2(m[1][0], m[1][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][1] = -SDW_Det2x2(m[0][0], m[0][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][2] =  SDW_Det2x2(m[0][0], m[0][1], m[1][0], m[1][1]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse3x3D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double SDW_Det2x2(double a1, double a2, double b1, double b2)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn a1 * b2 - b1 * a2;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			cont->addStmt( stmtCache.makeComment( "" ) );
			cont->addStmt( stmtCache.makeComment( "double3x3 SDW_Inverse(double3x3 m)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tdouble3x3 adj;" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][0] =  SDW_Det2x2(m[1][1], m[1][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][1] = -SDW_Det2x2(m[0][1], m[0][2], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][2] =  SDW_Det2x2(m[0][1], m[0][2], m[1][1], m[1][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][0] = -SDW_Det2x2(m[1][0], m[1][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][1] =  SDW_Det2x2(m[0][0], m[0][2], m[2][0], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][2] = -SDW_Det2x2(m[0][0], m[0][2], m[1][0], m[1][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][0] =  SDW_Det2x2(m[1][0], m[1][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][1] = -SDW_Det2x2(m[0][0], m[0][1], m[2][0], m[2][1]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][2] =  SDW_Det2x2(m[0][0], m[0][1], m[1][0], m[1][1]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tdouble det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse4x4F( ast::stmt::Container * container
			, IntrinsicsConfig const & config )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();

			if ( !config.requiresInverse3x3F )
			{
				cont->addStmt( stmtCache.makeComment( "float SDW_Det2x2(float a1, float a2, float b1, float b2)" ) );
				cont->addStmt( stmtCache.makeComment( "{" ) );
				cont->addStmt( stmtCache.makeComment( "\treturn a1 * b2 - b1 * a2;" ) );
				cont->addStmt( stmtCache.makeComment( "}" ) );
				cont->addStmt( stmtCache.makeComment( "" ) );
			}

			cont->addStmt( stmtCache.makeComment( "float SDW_Det3x3(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn a1 * SDW_Det2x2(b2, b3, c2, c3) - b1 * SDW_Det2x2(a2, a3, c2, c3) + c1 * SDW_Det2x2(a2, a3, b2, b3);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			cont->addStmt( stmtCache.makeComment( "" ) );
			cont->addStmt( stmtCache.makeComment( "float4x4 SDW_Inverse(float4x4 m)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat4x4 adj;" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][0] =  SDW_Det3x3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][1] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][2] =  SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][3] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][0] = -SDW_Det3x3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][1] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][2] = -SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][3] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][0] =  SDW_Det3x3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][1] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][2] =  SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][3] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][0] = -SDW_Det3x3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][1] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][2] = -SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][3] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]) + (adj[0][3] * m[3][0]);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeInverse4x4D( ast::stmt::Container * container
			, IntrinsicsConfig const & config )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();

			if ( !config.requiresInverse3x3D )
			{
				cont->addStmt( stmtCache.makeComment( "double SDW_Det2x2(double a1, double a2, double b1, double b2)" ) );
				cont->addStmt( stmtCache.makeComment( "{" ) );
				cont->addStmt( stmtCache.makeComment( "\treturn a1 * b2 - b1 * a2;" ) );
				cont->addStmt( stmtCache.makeComment( "}" ) );
				cont->addStmt( stmtCache.makeComment( "" ) );
			}

			cont->addStmt( stmtCache.makeComment( "double SDW_Det3x3(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn a1 * SDW_Det2x2(b2, b3, c2, c3) - b1 * SDW_Det2x2(a2, a3, c2, c3) + c1 * SDW_Det2x2(a2, a3, b2, b3);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			cont->addStmt( stmtCache.makeComment( "" ) );
			cont->addStmt( stmtCache.makeComment( "double4x4 SDW_Inverse(double4x4 m)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tdouble4x4 adj;" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][0] =  SDW_Det3x3(m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][1] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[2][1], m[2][2], m[2][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][2] =  SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[3][1], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[0][3] = -SDW_Det3x3(m[0][1], m[0][2], m[0][3], m[1][1], m[1][2], m[1][3], m[2][1], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][0] = -SDW_Det3x3(m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][1] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[2][0], m[2][2], m[2][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][2] = -SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[3][0], m[3][2], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[1][3] =  SDW_Det3x3(m[0][0], m[0][2], m[0][3], m[1][0], m[1][2], m[1][3], m[2][0], m[2][2], m[2][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][0] =  SDW_Det3x3(m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][1] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[2][0], m[2][1], m[2][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][2] =  SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[3][0], m[3][1], m[3][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[2][3] = -SDW_Det3x3(m[0][0], m[0][1], m[0][3], m[1][0], m[1][1], m[1][3], m[2][0], m[2][1], m[2][3]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][0] = -SDW_Det3x3(m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][1] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[2][0], m[2][1], m[2][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][2] = -SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[3][0], m[3][1], m[3][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tadj[3][3] =  SDW_Det3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);" ) );
			cont->addStmt( stmtCache.makeComment( "\tdouble det = (adj[0][0] * m[0][0]) + (adj[0][1] * m[1][0]) + (adj[0][2] * m[2][0]) + (adj[0][3] * m[3][0]);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (det != 0.0f) ? (adj * (1.0f / det)) : m;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry1( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_uaddCarry(uint x, uint y, out uint carry)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r, carry, x, y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry2( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint2 SDW_uaddCarry(uint2 x, uint2 y, out uint2 carry)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry3( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint3 SDW_uaddCarry(uint3 x, uint3 y, out uint3 carry)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.z, carry.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUaddCarry4( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint4 SDW_uaddCarry(uint4 x, uint4 y, out uint4 carry)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.x, carry.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.y, carry.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.z, carry.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\tuaddc r.w, carry.w, x.w, y.w;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow1( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_usubBorrow(uint x, uint y, out uint borrow)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r, borrow, x, y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow2( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint2 SDW_usubBorrow(uint2 x, uint2 y, out uint2 borrow)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow3( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint3 SDW_usubBorrow(uint3 x, uint3 y, out uint3 borrow)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.z, borrow.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUsubBorrow4( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint4 SDW_usubBorrow(uint4 x, uint4 y, out uint4 borrow)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.x, borrow.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.y, borrow.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.z, borrow.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\tusubb r.w, borrow.w, x.w, y.w;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended1( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_umulExtended(uint x, uint y, out uint msb, out uint lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb, lsb, x, y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended2( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint2 SDW_umulExtended(uint2 x, uint2 y, out uint2 msb, out uint2 lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended3( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint3 SDW_umulExtended(uint3 x, uint3 y, out uint3 msb, out uint3 lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeUmulExtended4( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint4 SDW_umulExtended(uint4 x, uint4 y, out uint4 msb, out uint4 lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\tumul msb.w, lsb.w, x.w, y.w;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended1( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int SDW_imulExtended(int x, int y, out int msb, out int lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint r;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb, lsb, x, y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended2( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int2 SDW_imulExtended(int2 x, int2 y, out int2 msb, out int2 lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint2 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended3( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int3 SDW_imulExtended(int3 x, int3 y, out int3 msb, out int3 lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint3 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImulExtended4( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int4 SDW_imulExtended(int4 x, int4 y, out int4 msb, out int4 lsb)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint4 r;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.x, lsb.x, x.x, y.x;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.y, lsb.y, x.y, y.y;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.z, lsb.z, x.z, y.z;" ) );
			cont->addStmt( stmtCache.makeComment( "\timul msb.w, lsb.w, x.w, y.w;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn r;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert1I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int SDW_bitfieldInsert(int base, int insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert2I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int2 SDW_bitfieldInsert(int2 base, int2 insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert3I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int3 SDW_bitfieldInsert(int3 base, int3 insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert4I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int4 SDW_bitfieldInsert(int4 base, int4 insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert1U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_bitfieldInsert(uint base, uint insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert2U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint2 SDW_bitfieldInsert(uint2 base, uint2 insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert3U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint3 SDW_bitfieldInsert(uint3 base, uint3 insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldInsert4U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint4 SDW_bitfieldInsert(uint4 base, uint4 insert, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = (bits == 32) ? 0xffffffff : (((1u << bits) - 1) << (offset & 31));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base & ~mask) | ((insert << offset) & mask);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract1I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int SDW_bitfieldExtract(int base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint mask = bits == 32 ? -1 : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\tint masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "\tint extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract2I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int2 SDW_bitfieldExtract(int2 base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint mask = bits == 32 ? -1 : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\tint2 masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "\tint extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract3I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int3 SDW_bitfieldExtract(int3 base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint mask = bits == 32 ? -1 : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\tint3 masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "\tint extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract4I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int4 SDW_bitfieldExtract(int4 base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tint mask = bits == 32 ? -1 : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\tint4 masked = (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "\tint extendShift = (32 - bits) & 31;" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (masked << extendShift) >> extendShift;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract1U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint SDW_bitfieldExtract(uint base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = bits == 32 ? 0xFFFFFFFF : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract2U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint2 SDW_bitfieldExtract(uint2 base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = bits == 32 ? 0xFFFFFFFF : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract3U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint3 SDW_bitfieldExtract(uint3 base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = bits == 32 ? 0xFFFFFFFF : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldExtract4U( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "uint4 SDW_bitfieldExtract(uint4 base, int offset, int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint mask = bits == 32 ? 0xFFFFFFFF : ((1L << bits) - 1);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn (base >> offset) & mask;" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse1I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int SDW_reverseBits(int bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint tmp = reversebits(uint(bits));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int(tmp);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse2I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int2 SDW_reverseBits(int2 bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 tmp = reversebits(uint2(uint(bits.x), uint(bits.y)));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int2(int(tmp.x), int(tmp.y));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse3I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int3 SDW_reverseBits(int3 bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 tmp = reversebits(uint3(uint(bits.x), uint(bits.y), uint(bits.z)));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int3(int(tmp.x), int(tmp.y), int(tmp.z));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeBitfieldReverse4I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int4 SDW_reverseBits(int4 bits)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 tmp = reversebits(uint4(uint(bits.x), uint(bits.y), uint(bits.z), uint(bits.w)));" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int4(int(tmp.x), int(tmp.y), int(tmp.z), int(tmp.w));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeModf1D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double SDW_modf(double x, out double ip)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat fip;" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat ret = modf(float(x), fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\tip = double(fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn double(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeModf2D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double2 SDW_modf(double2 x, out double2 ip)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat2 fip;" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat2 ret = modf(float2(x), fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\tip = double2(fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn double2(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeModf3D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double3 SDW_modf(double3 x, out double3 ip)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat3 fip;" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat3 ret = modf(float3(x), fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\tip = double3(fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn double3(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeModf4D( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "double4 SDW_modf(double4 x, out double4 ip)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat4 fip;" ) );
			cont->addStmt( stmtCache.makeComment( "\tfloat4 ret = modf(float4(x), fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\tip = double4(fip);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn double4(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd1I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int SDW_subgroupAnd(int id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint uid = uint(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd2I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int2 SDW_subgroupAnd(int2 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 uid = uint2(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int2(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd3I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int3 SDW_subgroupAnd(int3 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 uid = uint3(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int3(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd4I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int4 SDW_subgroupAnd(int4 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 uid = uint4(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int4(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd1B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool SDW_subgroupAnd(bool id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint uid = uint(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd2B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool2 SDW_subgroupAnd(bool2 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 uid = uint2(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool2(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd3B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool3 SDW_subgroupAnd(bool3 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 uid = uint3(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool3(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAnd4B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool4 SDW_subgroupAnd(bool4 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 uid = uint4(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 ret = WaveActiveBitAnd(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool4(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr1I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int SDW_subgroupOr(int id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint uid = uint(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr2I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int2 SDW_subgroupOr(int2 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 uid = uint2(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int2(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr3I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int3 SDW_subgroupOr(int3 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 uid = uint3(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int3(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr4I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int4 SDW_subgroupOr(int4 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 uid = uint4(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int4(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr1B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool SDW_subgroupOr(bool id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint uid = uint(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr2B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool2 SDW_subgroupOr(bool2 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 uid = uint2(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool2(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr3B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool3 SDW_subgroupOr(bool3 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 uid = uint3(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool3(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupOr4B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool4 SDW_subgroupOr(bool4 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 uid = uint4(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 ret = WaveActiveBitOr(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool4(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor1I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int SDW_subgroupXor(int id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint uid = uint(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor2I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int2 SDW_subgroupXor(int2 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 uid = uint2(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int2(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor3I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int3 SDW_subgroupXor(int3 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 uid = uint3(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int3(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor4I( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "int4 SDW_subgroupXor(int4 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 uid = uint4(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn int4(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor1B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool SDW_subgroupXor(bool id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint uid = uint(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor2B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool2 SDW_subgroupXor(bool2 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 uid = uint2(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint2 ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool2(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor3B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool3 SDW_subgroupXor(bool3 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 uid = uint3(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint3 ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool3(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupXor4B( ast::stmt::Container * container )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool4 SDW_subgroupXor(bool4 id)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 uid = uint4(id);" ) );
			cont->addStmt( stmtCache.makeComment( "\tuint4 ret = WaveActiveBitXor(uid);" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn bool4(ret);" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAllEqual( ast::stmt::Container * container
			, std::string const & type )
		{
			auto & stmtCache = container->getStmtCache();
			auto cont = stmtCache.makeContainer();
			cont->addStmt( stmtCache.makeComment( "bool SDW_subgroupAllEqual(" + type + " value)" ) );
			cont->addStmt( stmtCache.makeComment( "{" ) );
			cont->addStmt( stmtCache.makeComment( "\treturn all(WaveActiveAllEqual(value));" ) );
			cont->addStmt( stmtCache.makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeSubgroupAllEqual2F( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "float2" );
		}

		inline void writeSubgroupAllEqual3F( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "float3" );
		}

		inline void writeSubgroupAllEqual4F( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "float4" );
		}

		inline void writeSubgroupAllEqual2I( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "int2" );
		}

		inline void writeSubgroupAllEqual3I( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "int3" );
		}

		inline void writeSubgroupAllEqual4I( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "int4" );
		}

		inline void writeSubgroupAllEqual2U( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "uint2" );
		}

		inline void writeSubgroupAllEqual3U( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "uint3" );
		}

		inline void writeSubgroupAllEqual4U( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "uint4" );
		}

		inline void writeSubgroupAllEqual2D( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "double2" );
		}

		inline void writeSubgroupAllEqual3D( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "double3" );
		}

		inline void writeSubgroupAllEqual4D( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "double4" );
		}

		inline void writeSubgroupAllEqual2B( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "bool2" );
		}

		inline void writeSubgroupAllEqual3B( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "bool3" );
		}

		inline void writeSubgroupAllEqual4B( ast::stmt::Container * container )
		{
			writeSubgroupAllEqual( container, "bool4" );
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
		if ( config.requiresModf1D )
		{
			details::writeModf1D( container );
		}
		if ( config.requiresModf2D )
		{
			details::writeModf2D( container );
		}
		if ( config.requiresModf3D )
		{
			details::writeModf3D( container );
		}
		if ( config.requiresModf4D )
		{
			details::writeModf4D( container );
		}
		if ( config.requiresSubgroupAnd1I )
		{
			details::writeSubgroupAnd1I( container );
		}
		if ( config.requiresSubgroupAnd2I )
		{
			details::writeSubgroupAnd2I( container );
		}
		if ( config.requiresSubgroupAnd3I )
		{
			details::writeSubgroupAnd3I( container );
		}
		if ( config.requiresSubgroupAnd4I )
		{
			details::writeSubgroupAnd4I( container );
		}
		if ( config.requiresSubgroupAnd1B )
		{
			details::writeSubgroupAnd1B( container );
		}
		if ( config.requiresSubgroupAnd2B )
		{
			details::writeSubgroupAnd2B( container );
		}
		if ( config.requiresSubgroupAnd3B )
		{
			details::writeSubgroupAnd3B( container );
		}
		if ( config.requiresSubgroupAnd4B )
		{
			details::writeSubgroupAnd4B( container );
		}
		if ( config.requiresSubgroupOr1I )
		{
			details::writeSubgroupOr1I( container );
		}
		if ( config.requiresSubgroupOr2I )
		{
			details::writeSubgroupOr2I( container );
		}
		if ( config.requiresSubgroupOr3I )
		{
			details::writeSubgroupOr3I( container );
		}
		if ( config.requiresSubgroupOr4I )
		{
			details::writeSubgroupOr4I( container );
		}
		if ( config.requiresSubgroupOr1B )
		{
			details::writeSubgroupOr1B( container );
		}
		if ( config.requiresSubgroupOr2B )
		{
			details::writeSubgroupOr2B( container );
		}
		if ( config.requiresSubgroupOr3B )
		{
			details::writeSubgroupOr3B( container );
		}
		if ( config.requiresSubgroupOr4B )
		{
			details::writeSubgroupOr4B( container );
		}
		if ( config.requiresSubgroupXor1I )
		{
			details::writeSubgroupXor1I( container );
		}
		if ( config.requiresSubgroupXor2I )
		{
			details::writeSubgroupXor2I( container );
		}
		if ( config.requiresSubgroupXor3I )
		{
			details::writeSubgroupXor3I( container );
		}
		if ( config.requiresSubgroupXor4I )
		{
			details::writeSubgroupXor4I( container );
		}
		if ( config.requiresSubgroupXor1B )
		{
			details::writeSubgroupXor1B( container );
		}
		if ( config.requiresSubgroupXor2B )
		{
			details::writeSubgroupXor2B( container );
		}
		if ( config.requiresSubgroupXor3B )
		{
			details::writeSubgroupXor3B( container );
		}
		if ( config.requiresSubgroupXor4B )
		{
			details::writeSubgroupXor4B( container );
		}
		if ( config.requiresSubgroupAllEqual2F )
		{
			details::writeSubgroupAllEqual2F( container );
		}
		if ( config.requiresSubgroupAllEqual3F )
		{
			details::writeSubgroupAllEqual3F( container );
		}
		if ( config.requiresSubgroupAllEqual4F )
		{
			details::writeSubgroupAllEqual4F( container );
		}
		if ( config.requiresSubgroupAllEqual2I )
		{
			details::writeSubgroupAllEqual2I( container );
		}
		if ( config.requiresSubgroupAllEqual3I )
		{
			details::writeSubgroupAllEqual3I( container );
		}
		if ( config.requiresSubgroupAllEqual4I )
		{
			details::writeSubgroupAllEqual4I( container );
		}
		if ( config.requiresSubgroupAllEqual2U )
		{
			details::writeSubgroupAllEqual2U( container );
		}
		if ( config.requiresSubgroupAllEqual3U )
		{
			details::writeSubgroupAllEqual3U( container );
		}
		if ( config.requiresSubgroupAllEqual4U )
		{
			details::writeSubgroupAllEqual4U( container );
		}
		if ( config.requiresSubgroupAllEqual2B )
		{
			details::writeSubgroupAllEqual2B( container );
		}
		if ( config.requiresSubgroupAllEqual3B )
		{
			details::writeSubgroupAllEqual3B( container );
		}
		if ( config.requiresSubgroupAllEqual4B )
		{
			details::writeSubgroupAllEqual4B( container );
		}
		if ( config.requiresSubgroupAllEqual2D )
		{
			details::writeSubgroupAllEqual2D( container );
		}
		if ( config.requiresSubgroupAllEqual3D )
		{
			details::writeSubgroupAllEqual3D( container );
		}
		if ( config.requiresSubgroupAllEqual4D )
		{
			details::writeSubgroupAllEqual4D( container );
		}
	}
}
