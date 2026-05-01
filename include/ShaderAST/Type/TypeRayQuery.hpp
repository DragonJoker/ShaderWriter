/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeRayQuery_H___
#define ___AST_TypeRayQuery_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	enum class CommittedStatus : uint32_t
	{
		eNone,
		eTriangle,
		eProceduralPrimitive,
	};

	enum class CandidateType : uint32_t
	{
		eNonOpaqueTriangle,
		eProceduralPrimitive,
	};

	enum class RayFlag : uint32_t
	{
		eNone = 0x00,
		eForceOpaque = 0x01,
		eForceNonOpaque = 0x02,
		eAcceptFirstHitAndEndSearch = 0x04,
		eSkipClosestHitShader = 0x08,
		eCullBackFacingTriangles = 0x10,
		eCullFrontFacingTriangles = 0x20,
		eCullOpaque = 0x40,
		eCullNonOpaque = 0x80,
		eSkipTriangles = 0x100,
		eSkipProceduralPrimitives = 0x200
	};

	SDAST_API uint32_t operator|( RayFlag lhs, RayFlag rhs );
	SDAST_API uint32_t operator|( uint32_t lhs, RayFlag rhs );
	SDAST_API uint32_t operator|( RayFlag lhs, uint32_t rhs );
	SDAST_API RayFlag operator&( uint32_t lhs, RayFlag rhs );

	class RayQuery
		: public Type
	{
	public:
		SDAST_API explicit RayQuery( TypesCache & typesCache
			, uint32_t baseFlags );// combination of ast::type::RayFlag

		uint32_t getBaseFlags()const noexcept
		{
			return m_baseFlags;
		}

	private:
		uint32_t m_baseFlags;
	};

	using RayQueryPtr = RayQuery *;
}

#endif
