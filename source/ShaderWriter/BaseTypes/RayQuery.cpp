/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Boolean.hpp"
#include "ShaderWriter/BaseTypes/RayQuery.hpp"
#include "ShaderWriter/CompositeTypes/RayDesc.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

#include <ShaderAST/ShaderBuilder.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>

namespace sdw
{
	RayQuery::RayQuery( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
		if ( getType()
			&& getType()->getKind() != type::Kind::eRayQuery )
		{
			throw ast::Exception{ "Wrong type for ray query." };
		}
	}

	ast::type::TypePtr RayQuery::makeType( ast::type::TypesCache & cache, uint32_t baseFlags )
	{
		return cache.getRayQuery( baseFlags );
	}

	ReturnWrapperT< Boolean > RayQuery::isCommittedStatusNone()const
	{
		return committedStatus() == uint32_t( type::CommittedStatus::eNone );
	};

	ReturnWrapperT< Boolean > RayQuery::isCommittedStatusTriangle()const
	{
		return committedStatus() == uint32_t( type::CommittedStatus::eTriangle );
	}

	ReturnWrapperT< Boolean > RayQuery::isCommittedStatusProceduralPrimitive()const
	{
		return committedStatus() == uint32_t( type::CommittedStatus::eProceduralPrimitive );
	}

	ReturnWrapperT< Boolean > RayQuery::isCandidateTypeNonOpaqueTriangle()const
	{
		return candidateType() == uint32_t( type::CandidateType::eNonOpaqueTriangle );
	}

	ReturnWrapperT< Boolean > RayQuery::isCandidateTypeProceduralPrimitive()const
	{
		return candidateType() == uint32_t( type::CandidateType::eProceduralPrimitive );
	}

	void RayQuery::traceRay( AccelerationStructure const & topLevel, uint32_t rayFlags, UInt32 const & cullMask, RayDesc const & rayDesc )const
	{
		rayQueryTraceRay( *this, topLevel, UInt32{ rayFlags }, cullMask, rayDesc );
	}

	ReturnWrapperT< Boolean > RayQuery::proceed()const
	{
		return rayQueryProceed( *this );
	}

	void RayQuery::abort()const
	{
		rayQueryAbort( *this );
	}

	ReturnWrapperT< UInt32 > RayQuery::candidateType()const
	{
		return rayQueryCandidateType( *this );
	}

	ReturnWrapperT< Boolean > RayQuery::candidateProceduralPrimitiveNonOpaque()const
	{
		return rayQueryCandidateProceduralPrimitiveNonOpaque( *this );
	}

	void RayQuery::commitNonOpaqueTriangleHit()const
	{
		rayQueryCommitNonOpaqueTriangleHit( *this );
	}

	void RayQuery::commitProceduralPrimitiveHit( Float const & t )const
	{
		rayQueryCommitProceduralPrimitiveHit( *this, t );
	}

	ReturnWrapperT< UInt32 > RayQuery::committedStatus()const
	{
		return rayQueryCommittedStatus( *this );
	}

	ReturnWrapperT< UInt32 > RayQuery::getRayFlags()const
	{
		return rayQueryGetRayFlags( *this );
	}

	ReturnWrapperT< Vec3 > RayQuery::getWorldRayOrigin()const
	{
		return rayQueryGetWorldRayOrigin( *this );
	}

	ReturnWrapperT< Vec3 > RayQuery::getWorldRayDirection()const
	{
		return rayQueryGetWorldRayDirection( *this );
	}

	ReturnWrapperT< Float > RayQuery::getRayTMin()const
	{
		return rayQueryGetRayTMin( *this );
	}

	ReturnWrapperT< Float > RayQuery::candidateTriangleRayT()const
	{
		return rayQueryCandidateTriangleRayT( *this );
	}

	ReturnWrapperT< Float > RayQuery::committedRayT()const
	{
		return rayQueryCommittedRayT( *this );
	}

	ReturnWrapperT< UInt > RayQuery::candidateInstanceIndex()const
	{
		return rayQueryCandidateInstanceIndex( *this );
	}

	ReturnWrapperT< UInt > RayQuery::candidateInstanceID()const
	{
		return rayQueryCandidateInstanceID( *this );
	}

	ReturnWrapperT< UInt > RayQuery::candidateInstanceContributionToHitGroupIndex()const
	{
		return rayQueryCandidateInstanceContributionToHitGroupIndex( *this );
	}

	ReturnWrapperT< UInt > RayQuery::candidateGeometryIndex()const
	{
		return rayQueryCandidateGeometryIndex( *this );
	}

	ReturnWrapperT< UInt > RayQuery::candidatePrimitiveIndex()const
	{
		return rayQueryCandidatePrimitiveIndex( *this );
	}

	ReturnWrapperT< Vec3 > RayQuery::candidateObjectRayOrigin()const
	{
		return rayQueryCandidateObjectRayOrigin( *this );
	}

	ReturnWrapperT< Vec3 > RayQuery::candidateObjectRayDirection()const
	{
		return rayQueryCandidateObjectRayDirection( *this );
	}

	ReturnWrapperT< Mat4x3 > RayQuery::candidateObjectToWorld()const
	{
		return rayQueryCandidateObjectToWorld( *this );
	}

	ReturnWrapperT< Mat4x3 > RayQuery::candidateWorldToObject()const
	{
		return rayQueryCandidateWorldToObject( *this );
	}

	ReturnWrapperT< UInt > RayQuery::committedInstanceIndex()const
	{
		return rayQueryCommittedInstanceIndex( *this );
	}

	ReturnWrapperT< UInt > RayQuery::committedInstanceID()const
	{
		return rayQueryCommittedInstanceID( *this );
	}

	ReturnWrapperT< UInt > RayQuery::committedInstanceContributionToHitGroupIndex()const
	{
		return rayQueryCommittedInstanceContributionToHitGroupIndex( *this );
	}

	ReturnWrapperT< UInt > RayQuery::committedGeometryIndex()const
	{
		return rayQueryCommittedGeometryIndex( *this );
	}

	ReturnWrapperT< UInt > RayQuery::committedPrimitiveIndex()const
	{
		return rayQueryCommittedPrimitiveIndex( *this );
	}

	ReturnWrapperT< Vec3 > RayQuery::committedObjectRayOrigin()const
	{
		return rayQueryCommittedObjectRayOrigin( *this );
	}

	ReturnWrapperT< Vec3 > RayQuery::committedObjectRayDirection()const
	{
		return rayQueryCommittedObjectRayDirection( *this );
	}

	ReturnWrapperT< Mat4x3 > RayQuery::committedObjectToWorld()const
	{
		return rayQueryCommittedObjectToWorld( *this );
	}

	ReturnWrapperT< Mat4x3 > RayQuery::committedWorldToObject()const
	{
		return rayQueryCommittedWorldToObject( *this );
	}

	ReturnWrapperT< Vec2 > RayQuery::candidateTriangleBarycentrics()const
	{
		return rayQueryCandidateTriangleBarycentrics( *this );
	}

	ReturnWrapperT< Boolean > RayQuery::candidateTriangleFrontFace()const
	{
		return rayQueryCandidateTriangleFrontFace( *this );
	}

	ReturnWrapperT< Vec2 > RayQuery::committedTriangleBarycentrics()const
	{
		return rayQueryCommittedTriangleBarycentrics( *this );
	}

	ReturnWrapperT< Boolean > RayQuery::committedTriangleFrontFace()const
	{
		return rayQueryCommittedTriangleFrontFace( *this );
	}
}
