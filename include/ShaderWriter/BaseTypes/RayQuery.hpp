/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayQuery_H___
#define ___SDW_RayQuery_H___
#pragma once

#include "ShaderWriter/Value.hpp"
#include "ShaderWriter/BaseTypes/IntegerValue.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"
#include "ShaderWriter/VecTypes/Vec3.hpp"

namespace sdw
{
	struct RayQuery
		: public Value
	{
		SDW_DeclValueBase( SDW_API, RayQuery );

		SDW_API RayQuery( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::TypePtr makeType( ast::type::TypesCache & cache, uint32_t baseFlags );

		SDW_API ReturnWrapperT< Boolean > isCommittedStatusNone()const;
		SDW_API ReturnWrapperT< Boolean > isCommittedStatusTriangle()const;
		SDW_API ReturnWrapperT< Boolean > isCommittedStatusProceduralPrimitive()const;
		SDW_API ReturnWrapperT< Boolean > isCandidateTypeNonOpaqueTriangle()const;
		SDW_API ReturnWrapperT< Boolean > isCandidateTypeProceduralPrimitive()const;

		SDW_API void traceRay( AccelerationStructure const & topLevel, uint32_t rayFlags, UInt32 const & cullMask, RayDesc const & rayDesc )const;
		SDW_API ReturnWrapperT< Boolean > proceed()const;
		SDW_API void abort()const;
		SDW_API ReturnWrapperT< UInt32 > candidateType()const;
		SDW_API ReturnWrapperT< Boolean > candidateProceduralPrimitiveNonOpaque()const;
		SDW_API void commitNonOpaqueTriangleHit()const;
		SDW_API void commitProceduralPrimitiveHit( Float const & t )const;
		SDW_API ReturnWrapperT< UInt32 > committedStatus()const;
		// Ray system values
		SDW_API ReturnWrapperT< UInt32 > getRayFlags()const;
		SDW_API ReturnWrapperT< Vec3 > getWorldRayOrigin()const;
		SDW_API ReturnWrapperT< Vec3 > getWorldRayDirection()const;
		SDW_API ReturnWrapperT< Float > getRayTMin()const;
		SDW_API ReturnWrapperT< Float > candidateTriangleRayT()const;
		SDW_API ReturnWrapperT< Float > committedRayT()const;
		// Primitive/object space system values
		SDW_API ReturnWrapperT< UInt > candidateInstanceIndex()const;
		SDW_API ReturnWrapperT< UInt > candidateInstanceID()const;
		SDW_API ReturnWrapperT< UInt > candidateInstanceContributionToHitGroupIndex()const;
		SDW_API ReturnWrapperT< UInt > candidateGeometryIndex()const;
		SDW_API ReturnWrapperT< UInt > candidatePrimitiveIndex()const;
		SDW_API ReturnWrapperT< Vec3 > candidateObjectRayOrigin()const;
		SDW_API ReturnWrapperT< Vec3 > candidateObjectRayDirection()const;
		SDW_API ReturnWrapperT< Mat4x3 > candidateObjectToWorld()const;
		SDW_API ReturnWrapperT< Mat4x3 > candidateWorldToObject()const;
		SDW_API ReturnWrapperT< UInt > committedInstanceIndex()const;
		SDW_API ReturnWrapperT< UInt > committedInstanceID()const;
		SDW_API ReturnWrapperT< UInt > committedInstanceContributionToHitGroupIndex()const;
		SDW_API ReturnWrapperT< UInt > committedGeometryIndex()const;
		SDW_API ReturnWrapperT< UInt > committedPrimitiveIndex()const;
		SDW_API ReturnWrapperT< Vec3 > committedObjectRayOrigin()const;
		SDW_API ReturnWrapperT< Vec3 > committedObjectRayDirection()const;
		SDW_API ReturnWrapperT< Mat4x3 > committedObjectToWorld()const;
		SDW_API ReturnWrapperT< Mat4x3 > committedWorldToObject()const;
		// Hit specific system values
		SDW_API ReturnWrapperT< Vec2 > candidateTriangleBarycentrics()const;
		SDW_API ReturnWrapperT< Boolean > candidateTriangleFrontFace()const;
		SDW_API ReturnWrapperT< Vec2 > committedTriangleBarycentrics()const;
		SDW_API ReturnWrapperT< Boolean > committedTriangleFrontFace()const;
	};
}

#endif
