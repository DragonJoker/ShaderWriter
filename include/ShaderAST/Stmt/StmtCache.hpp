/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtCache_H___
#define ___AST_StmtCache_H___
#pragma once

#include "ShaderAST/ShaderAllocator.hpp"
#include "ShaderAST/Expr/ExprCache.hpp"
#include "ShaderAST/Stmt/PreprocExtension.hpp"
#include "ShaderAST/Stmt/StmtFunctionDecl.hpp"
#include "ShaderAST/Stmt/StmtPerVertexDecl.hpp"
#include "ShaderAST/Type/TypeGeometryIO.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"
#include "ShaderAST/Type/TypeTessellationControlIO.hpp"

namespace ast::stmt
{
	class StmtCache
	{
	public:
		SDAST_API explicit StmtCache( ShaderAllocatorBlock & allocator );
		SDAST_API ~StmtCache() = default;

		SDAST_API PreprocExtensionPtr makePreprocExtension( std::string name, PreprocExtension::ExtStatus status );
		SDAST_API PreprocVersionPtr makePreprocVersion( std::string name );
		SDAST_API AccelerationStructureDeclPtr makeAccelerationStructureDecl( var::VariablePtr variable, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API BreakPtr makeBreak( bool switchCaseBreak );
		SDAST_API BufferReferenceDeclPtr makeBufferReferenceDecl( type::TypePtr type );
		SDAST_API CombinedImageDeclPtr makeCombinedImageDecl( var::VariablePtr variable, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API CommentPtr makeComment( std::string text );
		SDAST_API CompoundPtr makeCompound();
		SDAST_API ConstantBufferDeclPtr makeConstantBufferDecl( std::string name, type::MemoryLayout layout, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API ContainerPtr makeContainer();
		SDAST_API ContinuePtr makeContinue();
		SDAST_API DemotePtr makeDemote();
		SDAST_API DispatchMeshPtr makeDispatchMesh( expr::ExprPtr numGroupsX, expr::ExprPtr numGroupsY, expr::ExprPtr numGroupsZ, expr::ExprPtr payload );
		SDAST_API DoWhilePtr makeDoWhile( expr::ExprPtr ctrlExpr );
		SDAST_API ElseIfPtr makeElseIf( expr::ExprPtr ctrlExpr );
		SDAST_API ElsePtr makeElse();
		SDAST_API ForPtr makeFor( expr::ExprPtr initExpr, expr::ExprPtr ctrlExpr, expr::ExprPtr incrExpr );
		SDAST_API FragmentLayoutPtr makeFragmentLayout( type::TypePtr type, FragmentOrigin origin, FragmentCenter center );
		SDAST_API FunctionDeclPtr makeFunctionDecl( var::VariablePtr funcVar, FunctionFlag flag = {} );
		SDAST_API FunctionDeclPtr makeFunctionDecl( var::VariablePtr funcVar, uint32_t flags );
		SDAST_API HitAttributeVariableDeclPtr makeHitAttributeVariableDecl( var::VariablePtr variable );
		SDAST_API IfPtr makeIf( expr::ExprPtr ctrlExpr );
		SDAST_API IgnoreIntersectionPtr makeIgnoreIntersection();
		SDAST_API ImageDeclPtr makeImageDecl( var::VariablePtr variable, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API InOutCallableDataVariableDeclPtr makeInOutCallableDataVariableDecl( var::VariablePtr variable, uint32_t location );
		SDAST_API InOutRayPayloadVariableDeclPtr makeInOutRayPayloadVariableDecl( var::VariablePtr variable, uint32_t location );
		SDAST_API InOutVariableDeclPtr makeInOutVariableDecl( var::VariablePtr variable, uint32_t location );
		SDAST_API InOutVariableDeclPtr makeInOutVariableDecl( var::VariablePtr variable, uint32_t location, uint32_t streamIndex, uint32_t blendIndex );
		SDAST_API InOutVariableDeclPtr makeInOutStreamVariableDecl( var::VariablePtr variable, uint32_t location, uint32_t streamIndex = 0u );
		SDAST_API InOutVariableDeclPtr makeInOutBlendVariableDecl( var::VariablePtr variable, uint32_t location, uint32_t blendIndex = 0u );
		SDAST_API InputComputeLayoutPtr makeInputComputeLayout( type::TypePtr type, uint32_t workGroupsX, uint32_t workGroupsY, uint32_t workGroupsZ );
		SDAST_API InputGeometryLayoutPtr makeInputGeometryLayout( type::TypePtr type, type::InputLayout layout );
		SDAST_API InputTessellationEvaluationLayoutPtr makeInputTessellationEvaluationLayout( type::TypePtr type, type::PatchDomain domain, type::Partitioning partitioning, type::PrimitiveOrdering order );
		SDAST_API OutputGeometryLayoutPtr makeOutputGeometryLayout( type::TypePtr type, type::OutputLayout layout, uint32_t primCount );
		SDAST_API OutputMeshLayoutPtr makeOutputMeshLayout( type::TypePtr type, type::OutputTopology topology, uint32_t maxVertices, uint32_t maxPrimitives );
		SDAST_API OutputTessellationControlLayoutPtr makeOutputTessellationControlLayout( type::TypePtr type, type::PatchDomain domain, type::Partitioning partitioning, type::OutputTopology topology, type::PrimitiveOrdering order, uint32_t outputVertices );
		SDAST_API PerPrimitiveDeclPtr makePerPrimitiveDecl( type::TypePtr type );
		SDAST_API PerVertexDeclPtr makePerVertexDecl( PerVertexDecl::Source source, type::TypePtr type );
		SDAST_API PushConstantsBufferDeclPtr makePushConstantsBufferDecl( std::string name, type::MemoryLayout layout );
		SDAST_API ReturnPtr makeReturn();
		SDAST_API ReturnPtr makeReturn( expr::ExprPtr expr );
		SDAST_API SampledImageDeclPtr makeSampledImageDecl( var::VariablePtr variable, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API SamplerDeclPtr makeSamplerDecl( var::VariablePtr variable, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API ShaderBufferDeclPtr makeShaderBufferDecl( type::TypesCache & typesCache, std::string const & ssboName, type::MemoryLayout layout, uint32_t bindingPoint, uint32_t bindingSet, uint32_t nextVarId );
		SDAST_API ShaderBufferDeclPtr makeShaderBufferDecl( var::VariablePtr var, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API ShaderStructBufferDeclPtr makeShaderStructBufferDecl( std::string ssboName, var::VariablePtr ssboInstance, var::VariablePtr data, uint32_t bindingPoint, uint32_t bindingSet );
		SDAST_API SimplePtr makeSimple( expr::ExprPtr expr );
		SDAST_API SpecialisationConstantDeclPtr makeSpecialisationConstantDecl( var::VariablePtr variable, uint32_t location, expr::LiteralPtr value );
		SDAST_API StructureDeclPtr makeStructureDecl( type::StructPtr type );
		SDAST_API SwitchPtr makeSwitch( expr::SwitchTestPtr testExpr );
		SDAST_API SwitchCasePtr makeSwitchCase( expr::SwitchCasePtr label );
		SDAST_API SwitchCasePtr makeSwitchDefault();
		SDAST_API TerminateInvocationPtr makeTerminateInvocation();
		SDAST_API TerminateRayPtr makeTerminateRay();
		SDAST_API VariableDeclPtr makeVariableDecl( var::VariablePtr variable );
		SDAST_API WhilePtr makeWhile( expr::ExprPtr ctrlExpr );

		template< typename StmtT, typename ... ParamsT >
		std::unique_ptr< StmtT, DeleteStmt > makeStmt( ParamsT && ... params )
		{
			auto mem = m_allocator.allocate( sizeof( StmtT ) );
			return std::unique_ptr< StmtT, DeleteStmt >{ new ( mem )StmtT{ *this, std::forward< ParamsT >( params )... } };
		}

		ShaderAllocatorBlock & getAllocator()const
		{
			return m_allocator;
		}

	private:
		friend struct DeleteStmt;

		void freeStmt( Stmt * stmt )noexcept;

	private:
		ShaderAllocatorBlock & m_allocator;
	};
}

#endif
