/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtFunctionDecl_H___
#define ___AST_StmtFunctionDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "ShaderAST/Var/Variable.hpp"

namespace ast::stmt
{
	enum class FunctionFlag : uint32_t
	{
		eNone = 0,
		ePatchRoutine = 0x0001 << 0,
		eVertexEntryPoint = 0x0001 << uint32_t( EntryPoint::eVertex ),
		eTessellationControlEntryPoint = 0x0001 << uint32_t( EntryPoint::eTessellationControl ),
		eTessellationEvaluationEntryPoint = 0x0001 << uint32_t( EntryPoint::eTessellationEvaluation ),
		eGeometryEntryPoint = 0x0001 << uint32_t(EntryPoint::eGeometry),
		eMeshEntryPointNV = 0x0001 << uint32_t( EntryPoint::eMeshNV ),
		eTaskEntryPointNV = 0x0001 << uint32_t( EntryPoint::eTaskNV ),
		eMeshEntryPoint = 0x0001 << uint32_t( EntryPoint::eMesh ),
		eTaskEntryPoint = 0x0001 << uint32_t( EntryPoint::eTask ),
		eFragmentEntryPoint = 0x0001 << uint32_t( EntryPoint::eFragment ),
		eRayGenerationEntryPoint = 0x0001 << uint32_t( EntryPoint::eRayGeneration ),
		eRayAnyHitEntryPoint = 0x0001 << uint32_t( EntryPoint::eRayAnyHit ),
		eRayClosestHitEntryPoint = 0x0001 << uint32_t( EntryPoint::eRayClosestHit ),
		eRayMissEntryPoint = 0x0001 << uint32_t( EntryPoint::eRayMiss ),
		eRayIntersectionEntryPoint = 0x0001 << uint32_t( EntryPoint::eRayIntersection ),
		eCallableEntryPoint = 0x0001 << uint32_t( EntryPoint::eCallable ),
		eComputeEntryPoint = 0x0001 << uint32_t( EntryPoint::eCompute ),
	};

	class FunctionDecl
		: public Compound
	{
	public:
		SDAST_API FunctionDecl( StmtCache & stmtCache
			, var::VariablePtr funcVar
			, uint32_t flags );

		SDAST_API void accept( VisitorPtr vis )const override;

		SDAST_API type::FunctionPtr getType()const;
		SDAST_API std::string const & getName()const;

		var::VariablePtr getFuncVar()const noexcept
		{
			return m_funcVar;
		}

		uint32_t getFlags()const noexcept
		{
			return m_flags;
		}

		bool isComputeEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eComputeEntryPoint );
		}

		bool isVertexEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eVertexEntryPoint );
		}

		bool isGeometryEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eGeometryEntryPoint );
		}

		bool isTessellationControlEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eTessellationControlEntryPoint );
		}

		bool isTessellationEvaluationEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eTessellationEvaluationEntryPoint );
		}

		bool isMeshEntryPointNV()const noexcept
		{
			return hasFlag( FunctionFlag::eMeshEntryPointNV );
		}

		bool isTaskEntryPointNV()const noexcept
		{
			return hasFlag( FunctionFlag::eTaskEntryPointNV );
		}

		bool isMeshEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eMeshEntryPoint );
		}

		bool isTaskEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eTaskEntryPoint );
		}

		bool isFragmentEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eFragmentEntryPoint );
		}

		bool isGraphicsEntryPoint()const noexcept
		{
			return isVertexEntryPoint()
				|| isGeometryEntryPoint()
				|| isTessellationControlEntryPoint()
				|| isTessellationEvaluationEntryPoint()
				|| isMeshEntryPointNV()
				|| isTaskEntryPointNV()
				|| isMeshEntryPoint()
				|| isTaskEntryPoint()
				|| isFragmentEntryPoint();
		}

		bool isCallableEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eCallableEntryPoint );
		}

		bool isRayAnyHitEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eRayAnyHitEntryPoint );
		}

		bool isRayClosestHitEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eRayClosestHitEntryPoint );
		}

		bool isRayGenerationEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eRayGenerationEntryPoint );
		}

		bool isRayIntersectionEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eRayIntersectionEntryPoint );
		}

		bool isRayMissEntryPoint()const noexcept
		{
			return hasFlag( FunctionFlag::eRayMissEntryPoint );
		}

		bool isRayTraceEntryPoint()const noexcept
		{
			return isCallableEntryPoint()
				|| isRayAnyHitEntryPoint()
				|| isRayClosestHitEntryPoint()
				|| isRayGenerationEntryPoint()
				|| isRayIntersectionEntryPoint()
				|| isRayMissEntryPoint();
		}

		bool isEntryPoint()const noexcept
		{
			return isComputeEntryPoint()
				|| isGraphicsEntryPoint()
				|| isRayTraceEntryPoint();
		}

		bool isPatchRoutine()const noexcept
		{
			return hasFlag( FunctionFlag::ePatchRoutine );
		}

	private:
		bool hasFlag( FunctionFlag flag )const noexcept
		{
			return flag == FunctionFlag::eNone
				? false
				: FunctionFlag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		var::VariablePtr m_funcVar;
		uint32_t m_flags;
	};

	inline uint32_t operator|( FunctionFlag const lhs
		, FunctionFlag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( FunctionFlag const lhs
		, uint32_t const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( uint32_t const lhs
		, FunctionFlag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}
}

#endif
