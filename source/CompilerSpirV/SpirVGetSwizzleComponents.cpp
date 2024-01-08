/*
See LICENSE file in root folder
*/
#include "SpirVGetSwizzleComponents.hpp"

#include <algorithm>
#include <numeric>

namespace spirv
{
	namespace swzcmp
	{
		static UInt32List getSwizzle2Components( ast::ShaderAllocatorBlock * allocator
			, ast::expr::SwizzleKind swizzle )
		{
			switch ( swizzle.getValue() )
			{
			case ast::expr::SwizzleKind::e01:
				return UInt32List{ { 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e10:
				return UInt32List{ { 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			default:
				AST_Failure( "Impossible LHS swizzle kind for 2 components vector" );
				return UInt32List{ ast::StlAllocatorT< uint32_t >( allocator ) };
			}
		}

		static UInt32List getSwizzle3Components( ast::ShaderAllocatorBlock * allocator
			, ast::expr::SwizzleKind swizzle )
		{
			switch ( swizzle.getValue() )
			{
			case ast::expr::SwizzleKind::e012:
				return UInt32List{ { 0, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e021:
				return UInt32List{ { 0, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e102:
				return UInt32List{ { 1, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e120:
				return UInt32List{ { 1, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e201:
				return UInt32List{ { 2, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e210:
				return UInt32List{ { 2, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			default:
				AST_Failure( "Impossible LHS swizzle kind for 3 components vector" );
				return UInt32List{ ast::StlAllocatorT< uint32_t >( allocator ) };
			}
		}

		static UInt32List getSwizzle4Components( ast::ShaderAllocatorBlock * allocator
			, ast::expr::SwizzleKind swizzle )
		{
			switch ( swizzle.getValue() )
			{
			case ast::expr::SwizzleKind::e0123:
				return UInt32List{ { 0, 1, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e0132:
				return UInt32List{ { 0, 1, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e0213:
				return UInt32List{ { 0, 2, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e0231:
				return UInt32List{ { 0, 2, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e0312:
				return UInt32List{ { 0, 3, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e0321:
				return UInt32List{ { 0, 3, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e1023:
				return UInt32List{ { 1, 0, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e1032:
				return UInt32List{ { 1, 0, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e1230:
				return UInt32List{ { 1, 2, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e1302:
				return UInt32List{ { 1, 3, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e1320:
				return UInt32List{ { 1, 3, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e2013:
				return UInt32List{ { 2, 0, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e2031:
				return UInt32List{ { 2, 0, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e2103:
				return UInt32List{ { 2, 1, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e2130:
				return UInt32List{ { 2, 1, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e2301:
				return UInt32List{ { 2, 3, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e2310:
				return UInt32List{ { 2, 3, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e3012:
				return UInt32List{ { 3, 0, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e3021:
				return UInt32List{ { 3, 0, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e3102:
				return UInt32List{ { 3, 1, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e3120:
				return UInt32List{ { 3, 1, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e3201:
				return UInt32List{ { 3, 2, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			case ast::expr::SwizzleKind::e3210:
				return UInt32List{ { 3, 2, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
			default:
				AST_Failure( "Impossible LHS swizzle kind for 3 components vector" );
				return UInt32List{ ast::StlAllocatorT< uint32_t >( allocator ) };
			}
		}

		static IdList fillVec2Swizzle( ast::ShaderAllocatorBlock * allocator
			, ast::expr::SwizzleKind lhsSwizzle
			, ast::expr::SwizzleKind rhsSwizzle )
		{
			UInt32List result{ allocator };
			auto rhs = getSwizzleComponents( allocator, rhsSwizzle );
			std::transform( rhs.begin()
				, rhs.end()
				, rhs.begin()
				, []( uint32_t v )
				{
					return v + 2u;
				} );
			assert( !rhs.empty() );

			if ( rhs.size() == 1u )
			{
				switch ( lhsSwizzle.getValue() )
				{
				case ast::expr::SwizzleKind::e0:
					//! lhs.x = rhs.c => lhs = vec2(rhs.c, lhs.y)
					result = { rhs[0u], 1u };
					break;
				case ast::expr::SwizzleKind::e1:
					//! lhs.y = rhs.c => lhs = vec2(lhs.x, rhs.c)
					result = { 0u, rhs[0u] };
					break;
				default:
					AST_Failure( "Impossible LHS swizzle kind" );
					break;
				}
			}
			else if ( rhs.size() == 2u )
			{
				auto lhs = getSwizzle2Components( allocator, lhsSwizzle );
				assert( lhs.size() == rhs.size() );
				result = { rhs[lhs[0u]], rhs[lhs[1u]] };
			}

			assert( result.size() == 2u );
			return result;
		}

		static IdList fillVec3Swizzle( ast::ShaderAllocatorBlock * allocator
			, ast::expr::SwizzleKind lhsSwizzle
			, ast::expr::SwizzleKind rhsSwizzle )
		{
			UInt32List result{ allocator };
			auto rhs = getSwizzleComponents( allocator, rhsSwizzle );
			std::transform( rhs.begin()
				, rhs.end()
				, rhs.begin()
				, []( uint32_t v )
				{
					return v + 3u;
				} );
			assert( !rhs.empty() );

			if ( rhs.size() == 1u )
			{
				switch ( lhsSwizzle.getValue() )
				{
				case ast::expr::SwizzleKind::e0:
					//! lhs.x = rhs.c => lhs = vec3(rhs.c, lhs.y, lhs.z)
					result = { rhs[0u], 1u, 2u };
					break;
				case ast::expr::SwizzleKind::e1:
					//! lhs.y = rhs.c => lhs = vec3(lhs.x, rhs.c, lhs.z)
					result = { 0u, rhs[0u], 2u };
					break;
				case ast::expr::SwizzleKind::e2:
					//! lhs.z = rhs.c => lhs = vec3(lhs.x, lhs.y, rhs.c)
					result = { 0u, 1u, rhs[0u] };
					break;
				default:
					AST_Failure( "Impossible LHS swizzle kind" );
					break;
				}
			}
			else if ( rhs.size() == 2u )
			{
				switch ( lhsSwizzle.getValue() )
				{
				case ast::expr::SwizzleKind::e01:
					//! lhs.xy = rhs.cMcN => lhs = vec3(rhs.cM, rhs.cN, lhs.z)
					result = { rhs[0u], rhs[1u], 2u };
					break;
				case ast::expr::SwizzleKind::e02:
					//! lhs.xz = rhs.cMcN => lhs = vec3(rhs.cM, lhs.y, rhs.cN)
					result = { rhs[0u], 1u, rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e10:
					//! lhs.yx = rhs.cMcN => lhs = vec3(rhs.cN, rhs.cM, lhs.z)
					result = { rhs[1u], rhs[0u], 2u };
					break;
				case ast::expr::SwizzleKind::e12:
					//! lhs.yz = rhs.cMcN => lhs = vec3(lhs.x, rhs.cM, rhs.cN)
					result = { 0u, rhs[0u], rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e20:
					//! lhs.zx = rhs.cMcN => lhs = vec3(rhs.cN, lhs.y, rhs.cM)
					result = { rhs[1u], 1u, rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e21:
					//! lhs.zy = rhs.cMcN => lhs = vec3(lhs.x, rhs.cN, rhs.cM)
					result = { 0u, rhs[1u], rhs[0u] };
					break;
				default:
					AST_Failure( "Impossible LHS swizzle kind" );
					break;
				}
			}
			else if ( rhs.size() == 3u )
			{
				auto lhs = getSwizzle3Components( allocator, lhsSwizzle );
				assert( lhs.size() == rhs.size() );
				result = { rhs[lhs[0u]], rhs[lhs[1u]], rhs[lhs[2u]] };
			}

			assert( result.size() == 3u );
			return result;
		}

		static IdList fillVec4Swizzle( ast::ShaderAllocatorBlock * allocator
			, ast::expr::SwizzleKind lhsSwizzle
			, ast::expr::SwizzleKind rhsSwizzle )
		{
			UInt32List result{ allocator };
			auto rhs = getSwizzleComponents( allocator, rhsSwizzle );
			std::transform( rhs.begin()
				, rhs.end()
				, rhs.begin()
				, []( uint32_t v )
				{
					return v + 4u;
				} );
			assert( !rhs.empty() );

			if ( rhs.size() == 1u )
			{
				switch ( lhsSwizzle.getValue() )
				{
				case ast::expr::SwizzleKind::e0:
					//! lhs.x = rhs.c => lhs = vec4(rhs.c, lhs.y, lhs.z, lhs.w)
					result = { rhs[0u], 1u, 2u, 3u };
					break;
				case ast::expr::SwizzleKind::e1:
					//! lhs.y = rhs.c => lhs = vec4(lhs.x, rhs.c, lhs.z, lhs.w)
					result = { 0u, rhs[0u], 2u, 3u };
					break;
				case ast::expr::SwizzleKind::e2:
					//! lhs.z = rhs.c => lhs = vec4(lhs.x, lhs.y, rhs.c, lhs.w)
					result = { 0u, 1u, rhs[0u], 3u };
					break;
				case ast::expr::SwizzleKind::e3:
					//! lhs.w = rhs.c => lhs = vec4(lhs.x, lhs.y, lhs.z, rhs.c)
					result = { 0u, 1u, 2u, rhs[0u] };
					break;
				default:
					AST_Failure( "Impossible LHS swizzle kind" );
					break;
				}
			}
			else if ( rhs.size() == 2u )
			{
				switch ( lhsSwizzle.getValue() )
				{
				case ast::expr::SwizzleKind::e01:
					//! lhs.xy = rhs.cMcN => lhs = vec4(rhs.cM, rhs.cN, lhs.z, lhs.w)
					result = { rhs[0u], rhs[1u], 2u, 3u };
					break;
				case ast::expr::SwizzleKind::e02:
					//! lhs.xz = rhs.cMcN => lhs = vec4(rhs.cM, lhs.y, rhs.cN, lhs.w)
					result = { rhs[0u], 1u, rhs[1u], 3u };
					break;
				case ast::expr::SwizzleKind::e03:
					//! lhs.xw = rhs.cMcN => lhs = vec4(rhs.cM, lhs.y, lhs.z, rhs.cN)
					result = { rhs[0u], 1u, 2u, rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e10:
					//! lhs.yx = rhs.cMcN => lhs = vec4(rhs.cN, rhs.cM, lhs.z, lhs.w)
					result = { rhs[1u], rhs[0u], 2u, 3u };
					break;
				case ast::expr::SwizzleKind::e12:
					//! lhs.yz = rhs.cMcN => lhs = vec4(lhs.x, rhs.cM, rhs.cN, lhs.w)
					result = { 0u, rhs[0u], rhs[1u], 3u };
					break;
				case ast::expr::SwizzleKind::e13:
					//! lhs.yw = rhs.cMcN => lhs = vec4(lhs.x, rhs.cM, lhs.z, rhs.cN)
					result = { 0u, rhs[0u], 2u, rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e20:
					//! lhs.zx = rhs.cMcN => lhs = vec4(rhs.cN, lhs.y, rhs.cM, lhs.w)
					result = { rhs[1u], 1u, rhs[0u], 3u };
					break;
				case ast::expr::SwizzleKind::e21:
					//! lhs.zy = rhs.cMcN => lhs = vec4(lhs.x, rhs.cN, rhs.cM, lhs.w)
					result = { 0u, rhs[1u], rhs[0u], 3u };
					break;
				case ast::expr::SwizzleKind::e23:
					//! lhs.zw = rhs.cMcN => lhs = vec4(lhs.x, lhs.y, rhs.cM, rhs.cN)
					result = { 0u, 1u, rhs[0u], rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e30:
					//! lhs.wx = rhs.cMcN => lhs = vec4(rhs.cN, lhs.y, lhs.z, rhs.cM)
					result = { rhs[1u], 1u, 2u, rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e31:
					//! lhs.wy = rhs.cMcN => lhs = vec4(lhs.x, rhs.cN, lhs.z, rhs.cM)
					result = { 0u, rhs[1u], 2u, rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e32:
					//! lhs.wz = rhs.cMcN => lhs = vec4(lhs.x, lhs.y, rhs.cN, rhs.cM)
					result = { 0u, 1u, rhs[1u], rhs[0u] };
					break;
				default:
					AST_Failure( "Impossible LHS swizzle kind" );
					break;
				}
			}
			else if ( rhs.size() == 3u )
			{
				switch ( lhsSwizzle.getValue() )
				{
				case ast::expr::SwizzleKind::e012:
					//! lhs.xyz = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cN, rhs.cO, lhs.w)
					result = { rhs[0u], rhs[1u], rhs[2u], 3u };
					break;
				case ast::expr::SwizzleKind::e013:
					//! lhs.xyw = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cN, lhs.z, rhs.cO)
					result = { rhs[0u], rhs[1u], 2u, rhs[2u] };
					break;
				case ast::expr::SwizzleKind::e021:
					//! lhs.xzy = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cO, rhs.cN, lhs.w)
					result = { rhs[0u], rhs[2u], rhs[1u], 3u };
					break;
				case ast::expr::SwizzleKind::e023:
					//! lhs.xzw = rhs.cMcNcO => lhs = vec4(rhs.cM, lhs.y, rhs.cN, rhs.cO)
					result = { rhs[0u], rhs[1u], 2u, rhs[2u] };
					break;
				case ast::expr::SwizzleKind::e031:
					//! lhs.xwy = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cO, lhs.z, rhs.cN)
					result = { rhs[0u], rhs[2u], 2u, rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e032:
					//! lhs.xwz = rhs.cMcNcO => lhs = vec4(rhs.cM, lhs.y, rhs.cO, rhs.cN)
					result = { rhs[0u], 1u, rhs[2u], rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e102:
					//! lhs.yxz = rhs.cMcNcO => lhs = vec4(rhs.cN, rhs.cM, rhs.cO, lhs.w)
					result = { rhs[1u], rhs[0u], rhs[2u], 3u };
					break;
				case ast::expr::SwizzleKind::e103:
					//! lhs.yxw = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cN, lhs.z, rhs.cO)
					result = { rhs[1u], rhs[0u], 2u, rhs[2u] };
					break;
				case ast::expr::SwizzleKind::e120:
					//! lhs.yzx = rhs.cMcNcO => lhs = vec4(rhs.cO, rhs.cM, rhs.cN, lhs.w)
					result = { rhs[2u], rhs[0u], rhs[1u], 3u };
					break;
				case ast::expr::SwizzleKind::e123:
					//! lhs.yzw = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cM, rhs.cN, rhs.cO)
					result = { 0u, rhs[0u], rhs[1u], rhs[2u] };
					break;
				case ast::expr::SwizzleKind::e130:
					//! lhs.ywx = rhs.cMcNcO => lhs = vec4(rhs.cM, rhs.cO, lhs.z, rhs.cN)
					result = { rhs[2u], rhs[0u], 2u, rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e132:
					//! lhs.ywz = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cM, rhs.cO, rhs.cN)
					result = { 0u, rhs[0u], rhs[2u], rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e201:
					//! lhs.zxy = rhs.cMcNcO => lhs = vec4(rhs.cN, rhs.cO, rhs.cM, lhs.w)
					result = { rhs[1u], rhs[2u], rhs[0u], 3u };
					break;
				case ast::expr::SwizzleKind::e203:
					//! lhs.zxw = rhs.cMcNcO => lhs = vec4(rhs.cN, lhs.y, rhs.cM, rhs.cO)
					result = { rhs[1u], 1u, rhs[0u], rhs[2u] };
					break;
				case ast::expr::SwizzleKind::e210:
					//! lhs.zyx = rhs.cMcNcO => lhs = vec4(rhs.cO, rhs.cN, rhs.cM, lhs.w)
					result = { rhs[2u], rhs[1u], rhs[0u], 3u };
					break;
				case ast::expr::SwizzleKind::e213:
					//! lhs.zyw = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cN, rhs.cM, rhs.cO)
					result = { 0u, rhs[1u], rhs[0u], rhs[2u] };
					break;
				case ast::expr::SwizzleKind::e230:
					//! lhs.zwx = rhs.cMcNcO => lhs = vec4(rhs.cO, lhs.y, rhs.cM, rhs.cN)
					result = { rhs[2u], 1u, rhs[0u], rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e231:
					//! lhs.zwy = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cO, rhs.cM, rhs.cN)
					result = { 0u, rhs[2u], rhs[0u], rhs[1u] };
					break;
				case ast::expr::SwizzleKind::e301:
					//! lhs.wxy = rhs.cMcNcO => lhs = vec4(rhs.cN, rhs.cO, lhs.z, rhs.cM)
					result = { rhs[1u], rhs[2u], 2u, rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e302:
					//! lhs.wxz = rhs.cMcNcO => lhs = vec4(rhs.cN, lhs.y, rhs.cO, rhs.cM)
					result = { rhs[1u], 1u, rhs[2u], rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e310:
					//! lhs.wyx = rhs.cMcNcO => lhs = vec4(rhs.cO, rhs.cN, lhs.z, rhs.cM)
					result = { rhs[2u], rhs[1u], 2u, rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e312:
					//! lhs.wyz = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cN, rhs.cO, rhs.cM)
					result = { 0u, rhs[1u], rhs[2u], rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e320:
					//! lhs.wzx = rhs.cMcNcO => lhs = vec4(rhs.cO, lhs.y, rhs.cN, rhs.cM)
					result = { rhs[2u], 1u, rhs[1u], rhs[0u] };
					break;
				case ast::expr::SwizzleKind::e321:
					//! lhs.wzy = rhs.cMcNcO => lhs = vec4(lhs.x, rhs.cO, rhs.cN, rhs.cM)
					result = { 0u, rhs[2u], rhs[1u], rhs[0u] };
					break;
				default:
					AST_Failure( "Impossible LHS swizzle kind" );
					break;
				}
			}
			else if ( rhs.size() == 4u )
			{
				auto lhs = getSwizzle4Components( allocator, lhsSwizzle );
				assert( lhs.size() == rhs.size() );
				result = { rhs[lhs[0u]], rhs[lhs[1u]], rhs[lhs[2u]], rhs[lhs[3u]] };
			}

			assert( result.size() == 4u );
			return result;
		}

		static IdList fillSwizzle( ast::ShaderAllocatorBlock * allocator
			, ast::expr::SwizzleKind lhsSwizzle
			, ast::expr::SwizzleKind rhsSwizzle
			, uint32_t count )
		{
			IdList result{ allocator };

			switch ( count )
			{
			case 2:
				result = fillVec2Swizzle( allocator, lhsSwizzle, rhsSwizzle );
				break;
			case 3:
				result = fillVec3Swizzle( allocator, lhsSwizzle, rhsSwizzle );
				break;
			case 4:
				result = fillVec4Swizzle( allocator, lhsSwizzle, rhsSwizzle );
				break;
			default:
				AST_Failure( "Unsupported components count" );
				break;
			}

			return result;
		}
	}

	UInt32List getSwizzleComponents( ast::ShaderAllocatorBlock * allocator
		, ast::expr::SwizzleKind kind )
	{
		switch ( kind.getValue() )
		{
		case ast::expr::SwizzleKind::e0:
			return UInt32List{ { 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1:
			return UInt32List{ { 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2:
			return UInt32List{ { 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3:
			return UInt32List{ { 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e00:
			return UInt32List{ { 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e01:
			return UInt32List{ { 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e02:
			return UInt32List{ { 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e03:
			return UInt32List{ { 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e10:
			return UInt32List{ { 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e11:
			return UInt32List{ { 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e12:
			return UInt32List{ { 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e13:
			return UInt32List{ { 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e20:
			return UInt32List{ { 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e21:
			return UInt32List{ { 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e22:
			return UInt32List{ { 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e23:
			return UInt32List{ { 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e30:
			return UInt32List{ { 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e31:
			return UInt32List{ { 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e32:
			return UInt32List{ { 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e33:
			return UInt32List{ { 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e000:
			return UInt32List{ { 0, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e001:
			return UInt32List{ { 0, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e002:
			return UInt32List{ { 0, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e003:
			return UInt32List{ { 0, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e010:
			return UInt32List{ { 0, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e011:
			return UInt32List{ { 0, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e012:
			return UInt32List{ { 0, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e013:
			return UInt32List{ { 0, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e020:
			return UInt32List{ { 0, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e021:
			return UInt32List{ { 0, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e022:
			return UInt32List{ { 0, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e023:
			return UInt32List{ { 0, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e030:
			return UInt32List{ { 0, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e031:
			return UInt32List{ { 0, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e032:
			return UInt32List{ { 0, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e033:
			return UInt32List{ { 0, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e100:
			return UInt32List{ { 1, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e101:
			return UInt32List{ { 1, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e102:
			return UInt32List{ { 1, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e103:
			return UInt32List{ { 1, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e110:
			return UInt32List{ { 1, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e111:
			return UInt32List{ { 1, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e112:
			return UInt32List{ { 1, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e113:
			return UInt32List{ { 1, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e120:
			return UInt32List{ { 1, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e121:
			return UInt32List{ { 1, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e122:
			return UInt32List{ { 1, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e123:
			return UInt32List{ { 1, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e130:
			return UInt32List{ { 1, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e131:
			return UInt32List{ { 1, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e132:
			return UInt32List{ { 1, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e133:
			return UInt32List{ { 1, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e200:
			return UInt32List{ { 2, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e201:
			return UInt32List{ { 2, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e202:
			return UInt32List{ { 2, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e203:
			return UInt32List{ { 2, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e210:
			return UInt32List{ { 2, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e211:
			return UInt32List{ { 2, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e212:
			return UInt32List{ { 2, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e213:
			return UInt32List{ { 2, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e220:
			return UInt32List{ { 2, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e221:
			return UInt32List{ { 2, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e222:
			return UInt32List{ { 2, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e223:
			return UInt32List{ { 2, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e230:
			return UInt32List{ { 2, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e231:
			return UInt32List{ { 2, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e232:
			return UInt32List{ { 2, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e233:
			return UInt32List{ { 2, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e300:
			return UInt32List{ { 3, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e301:
			return UInt32List{ { 3, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e302:
			return UInt32List{ { 3, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e303:
			return UInt32List{ { 3, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e310:
			return UInt32List{ { 3, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e311:
			return UInt32List{ { 3, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e312:
			return UInt32List{ { 3, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e313:
			return UInt32List{ { 3, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e320:
			return UInt32List{ { 3, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e321:
			return UInt32List{ { 3, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e322:
			return UInt32List{ { 3, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e323:
			return UInt32List{ { 3, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e330:
			return UInt32List{ { 3, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e331:
			return UInt32List{ { 3, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e332:
			return UInt32List{ { 3, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e333:
			return UInt32List{ { 3, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0000:
			return UInt32List{ { 0, 0, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0001:
			return UInt32List{ { 0, 0, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0002:
			return UInt32List{ { 0, 0, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0003:
			return UInt32List{ { 0, 0, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0010:
			return UInt32List{ { 0, 0, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0011:
			return UInt32List{ { 0, 0, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0012:
			return UInt32List{ { 0, 0, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0013:
			return UInt32List{ { 0, 0, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0020:
			return UInt32List{ { 0, 0, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0021:
			return UInt32List{ { 0, 0, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0022:
			return UInt32List{ { 0, 0, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0023:
			return UInt32List{ { 0, 0, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0030:
			return UInt32List{ { 0, 0, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0031:
			return UInt32List{ { 0, 0, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0032:
			return UInt32List{ { 0, 0, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0033:
			return UInt32List{ { 0, 0, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0100:
			return UInt32List{ { 0, 1, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0101:
			return UInt32List{ { 0, 1, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0102:
			return UInt32List{ { 0, 1, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0103:
			return UInt32List{ { 0, 1, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0110:
			return UInt32List{ { 0, 1, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0111:
			return UInt32List{ { 0, 1, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0112:
			return UInt32List{ { 0, 1, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0113:
			return UInt32List{ { 0, 1, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0120:
			return UInt32List{ { 0, 1, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0121:
			return UInt32List{ { 0, 1, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0122:
			return UInt32List{ { 0, 1, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0123:
			return UInt32List{ { 0, 1, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0130:
			return UInt32List{ { 0, 1, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0131:
			return UInt32List{ { 0, 1, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0132:
			return UInt32List{ { 0, 1, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0133:
			return UInt32List{ { 0, 1, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0200:
			return UInt32List{ { 0, 2, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0201:
			return UInt32List{ { 0, 2, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0202:
			return UInt32List{ { 0, 2, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0203:
			return UInt32List{ { 0, 2, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0210:
			return UInt32List{ { 0, 2, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0211:
			return UInt32List{ { 0, 2, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0212:
			return UInt32List{ { 0, 2, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0213:
			return UInt32List{ { 0, 2, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0220:
			return UInt32List{ { 0, 2, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0221:
			return UInt32List{ { 0, 2, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0222:
			return UInt32List{ { 0, 2, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0223:
			return UInt32List{ { 0, 2, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0230:
			return UInt32List{ { 0, 2, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0231:
			return UInt32List{ { 0, 2, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0232:
			return UInt32List{ { 0, 2, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0233:
			return UInt32List{ { 0, 2, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0300:
			return UInt32List{ { 0, 3, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0301:
			return UInt32List{ { 0, 3, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0302:
			return UInt32List{ { 0, 3, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0303:
			return UInt32List{ { 0, 3, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0310:
			return UInt32List{ { 0, 3, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0311:
			return UInt32List{ { 0, 3, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0312:
			return UInt32List{ { 0, 3, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0313:
			return UInt32List{ { 0, 3, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0320:
			return UInt32List{ { 0, 3, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0321:
			return UInt32List{ { 0, 3, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0322:
			return UInt32List{ { 0, 3, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0323:
			return UInt32List{ { 0, 3, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0330:
			return UInt32List{ { 0, 3, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0331:
			return UInt32List{ { 0, 3, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0332:
			return UInt32List{ { 0, 3, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e0333:
			return UInt32List{ { 0, 3, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1000:
			return UInt32List{ { 1, 0, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1001:
			return UInt32List{ { 1, 0, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1002:
			return UInt32List{ { 1, 0, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1003:
			return UInt32List{ { 1, 0, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1010:
			return UInt32List{ { 1, 0, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1011:
			return UInt32List{ { 1, 0, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1012:
			return UInt32List{ { 1, 0, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1013:
			return UInt32List{ { 1, 0, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1020:
			return UInt32List{ { 1, 0, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1021:
			return UInt32List{ { 1, 0, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1022:
			return UInt32List{ { 1, 0, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1023:
			return UInt32List{ { 1, 0, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1030:
			return UInt32List{ { 1, 0, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1031:
			return UInt32List{ { 1, 0, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1032:
			return UInt32List{ { 1, 0, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1033:
			return UInt32List{ { 1, 0, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1100:
			return UInt32List{ { 1, 1, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1101:
			return UInt32List{ { 1, 1, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1102:
			return UInt32List{ { 1, 1, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1103:
			return UInt32List{ { 1, 1, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1110:
			return UInt32List{ { 1, 1, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1111:
			return UInt32List{ { 1, 1, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1112:
			return UInt32List{ { 1, 1, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1113:
			return UInt32List{ { 1, 1, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1120:
			return UInt32List{ { 1, 1, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1121:
			return UInt32List{ { 1, 1, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1122:
			return UInt32List{ { 1, 1, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1123:
			return UInt32List{ { 1, 1, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1130:
			return UInt32List{ { 1, 1, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1131:
			return UInt32List{ { 1, 1, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1132:
			return UInt32List{ { 1, 1, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1133:
			return UInt32List{ { 1, 1, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1200:
			return UInt32List{ { 1, 2, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1201:
			return UInt32List{ { 1, 2, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1202:
			return UInt32List{ { 1, 2, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1203:
			return UInt32List{ { 1, 2, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1210:
			return UInt32List{ { 1, 2, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1211:
			return UInt32List{ { 1, 2, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1212:
			return UInt32List{ { 1, 2, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1213:
			return UInt32List{ { 1, 2, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1220:
			return UInt32List{ { 1, 2, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1221:
			return UInt32List{ { 1, 2, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1222:
			return UInt32List{ { 1, 2, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1223:
			return UInt32List{ { 1, 2, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1230:
			return UInt32List{ { 1, 2, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1231:
			return UInt32List{ { 1, 2, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1232:
			return UInt32List{ { 1, 2, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1233:
			return UInt32List{ { 1, 2, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1300:
			return UInt32List{ { 1, 3, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1301:
			return UInt32List{ { 1, 3, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1302:
			return UInt32List{ { 1, 3, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1303:
			return UInt32List{ { 1, 3, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1310:
			return UInt32List{ { 1, 3, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1311:
			return UInt32List{ { 1, 3, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1312:
			return UInt32List{ { 1, 3, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1313:
			return UInt32List{ { 1, 3, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1320:
			return UInt32List{ { 1, 3, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1321:
			return UInt32List{ { 1, 3, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1322:
			return UInt32List{ { 1, 3, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1323:
			return UInt32List{ { 1, 3, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1330:
			return UInt32List{ { 1, 3, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1331:
			return UInt32List{ { 1, 3, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1332:
			return UInt32List{ { 1, 3, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e1333:
			return UInt32List{ { 1, 3, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2000:
			return UInt32List{ { 2, 0, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2001:
			return UInt32List{ { 2, 0, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2002:
			return UInt32List{ { 2, 0, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2003:
			return UInt32List{ { 2, 0, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2010:
			return UInt32List{ { 2, 0, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2011:
			return UInt32List{ { 2, 0, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2012:
			return UInt32List{ { 2, 0, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2013:
			return UInt32List{ { 2, 0, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2020:
			return UInt32List{ { 2, 0, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2021:
			return UInt32List{ { 2, 0, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2022:
			return UInt32List{ { 2, 0, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2023:
			return UInt32List{ { 2, 0, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2030:
			return UInt32List{ { 2, 0, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2031:
			return UInt32List{ { 2, 0, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2032:
			return UInt32List{ { 2, 0, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2033:
			return UInt32List{ { 2, 0, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2100:
			return UInt32List{ { 2, 1, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2101:
			return UInt32List{ { 2, 1, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2102:
			return UInt32List{ { 2, 1, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2103:
			return UInt32List{ { 2, 1, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2110:
			return UInt32List{ { 2, 1, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2111:
			return UInt32List{ { 2, 1, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2112:
			return UInt32List{ { 2, 1, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2113:
			return UInt32List{ { 2, 1, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2120:
			return UInt32List{ { 2, 1, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2121:
			return UInt32List{ { 2, 1, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2122:
			return UInt32List{ { 2, 1, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2123:
			return UInt32List{ { 2, 1, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2130:
			return UInt32List{ { 2, 1, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2131:
			return UInt32List{ { 2, 1, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2132:
			return UInt32List{ { 2, 1, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2133:
			return UInt32List{ { 2, 1, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2200:
			return UInt32List{ { 2, 2, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2201:
			return UInt32List{ { 2, 2, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2202:
			return UInt32List{ { 2, 2, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2203:
			return UInt32List{ { 2, 2, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2210:
			return UInt32List{ { 2, 2, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2211:
			return UInt32List{ { 2, 2, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2212:
			return UInt32List{ { 2, 2, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2213:
			return UInt32List{ { 2, 2, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2220:
			return UInt32List{ { 2, 2, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2221:
			return UInt32List{ { 2, 2, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2222:
			return UInt32List{ { 2, 2, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2223:
			return UInt32List{ { 2, 2, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2230:
			return UInt32List{ { 2, 2, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2231:
			return UInt32List{ { 2, 2, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2232:
			return UInt32List{ { 2, 2, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2233:
			return UInt32List{ { 2, 2, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2300:
			return UInt32List{ { 2, 3, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2301:
			return UInt32List{ { 2, 3, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2302:
			return UInt32List{ { 2, 3, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2303:
			return UInt32List{ { 2, 3, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2310:
			return UInt32List{ { 2, 3, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2311:
			return UInt32List{ { 2, 3, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2312:
			return UInt32List{ { 2, 3, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2313:
			return UInt32List{ { 2, 3, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2320:
			return UInt32List{ { 2, 3, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2321:
			return UInt32List{ { 2, 3, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2322:
			return UInt32List{ { 2, 3, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2323:
			return UInt32List{ { 2, 3, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2330:
			return UInt32List{ { 2, 3, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2331:
			return UInt32List{ { 2, 3, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2332:
			return UInt32List{ { 2, 3, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e2333:
			return UInt32List{ { 2, 3, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3000:
			return UInt32List{ { 3, 0, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3001:
			return UInt32List{ { 3, 0, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3002:
			return UInt32List{ { 3, 0, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3003:
			return UInt32List{ { 3, 0, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3010:
			return UInt32List{ { 3, 0, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3011:
			return UInt32List{ { 3, 0, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3012:
			return UInt32List{ { 3, 0, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3013:
			return UInt32List{ { 3, 0, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3020:
			return UInt32List{ { 3, 0, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3021:
			return UInt32List{ { 3, 0, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3022:
			return UInt32List{ { 3, 0, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3023:
			return UInt32List{ { 3, 0, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3030:
			return UInt32List{ { 3, 0, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3031:
			return UInt32List{ { 3, 0, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3032:
			return UInt32List{ { 3, 0, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3033:
			return UInt32List{ { 3, 0, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3100:
			return UInt32List{ { 3, 1, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3101:
			return UInt32List{ { 3, 1, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3102:
			return UInt32List{ { 3, 1, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3103:
			return UInt32List{ { 3, 1, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3110:
			return UInt32List{ { 3, 1, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3111:
			return UInt32List{ { 3, 1, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3112:
			return UInt32List{ { 3, 1, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3113:
			return UInt32List{ { 3, 1, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3120:
			return UInt32List{ { 3, 1, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3121:
			return UInt32List{ { 3, 1, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3122:
			return UInt32List{ { 3, 1, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3123:
			return UInt32List{ { 3, 1, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3130:
			return UInt32List{ { 3, 1, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3131:
			return UInt32List{ { 3, 1, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3132:
			return UInt32List{ { 3, 1, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3133:
			return UInt32List{ { 3, 1, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3200:
			return UInt32List{ { 3, 2, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3201:
			return UInt32List{ { 3, 2, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3202:
			return UInt32List{ { 3, 2, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3203:
			return UInt32List{ { 3, 2, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3210:
			return UInt32List{ { 3, 2, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3211:
			return UInt32List{ { 3, 2, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3212:
			return UInt32List{ { 3, 2, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3213:
			return UInt32List{ { 3, 2, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3220:
			return UInt32List{ { 3, 2, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3221:
			return UInt32List{ { 3, 2, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3222:
			return UInt32List{ { 3, 2, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3223:
			return UInt32List{ { 3, 2, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3230:
			return UInt32List{ { 3, 2, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3231:
			return UInt32List{ { 3, 2, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3232:
			return UInt32List{ { 3, 2, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3233:
			return UInt32List{ { 3, 2, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3300:
			return UInt32List{ { 3, 3, 0, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3301:
			return UInt32List{ { 3, 3, 0, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3302:
			return UInt32List{ { 3, 3, 0, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3303:
			return UInt32List{ { 3, 3, 0, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3310:
			return UInt32List{ { 3, 3, 1, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3311:
			return UInt32List{ { 3, 3, 1, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3312:
			return UInt32List{ { 3, 3, 1, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3313:
			return UInt32List{ { 3, 3, 1, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3320:
			return UInt32List{ { 3, 3, 2, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3321:
			return UInt32List{ { 3, 3, 2, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3322:
			return UInt32List{ { 3, 3, 2, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3323:
			return UInt32List{ { 3, 3, 2, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3330:
			return UInt32List{ { 3, 3, 3, 0 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3331:
			return UInt32List{ { 3, 3, 3, 1 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3332:
			return UInt32List{ { 3, 3, 3, 2 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		case ast::expr::SwizzleKind::e3333:
			return UInt32List{ { 3, 3, 3, 3 }, ast::StlAllocatorT< uint32_t >( allocator ) };
		default:
			AST_Failure( "Unsupported SwizzleKind." );
			return UInt32List{ ast::StlAllocatorT< uint32_t >( allocator ) };
		}
	}

	IdList getSwizzleComponents( ast::ShaderAllocatorBlock * allocator
		, ast::expr::SwizzleKind lhsSwizzle
		, ast::expr::SwizzleKind rhsSwizzle
		, uint32_t componentCount )
	{
		return swzcmp::fillSwizzle( allocator, lhsSwizzle, rhsSwizzle, componentCount );
	}

	ast::expr::SwizzleKind getSwizzleComponents( uint32_t count )
	{
		assert( count > 0 && count < 4 );

		switch ( count )
		{
		case 1:
			return ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e0 };
		case 2:
			return ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e01 };
		default:
			return ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e012 };
		}
	}
}
