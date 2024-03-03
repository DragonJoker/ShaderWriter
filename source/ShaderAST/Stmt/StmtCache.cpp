/*
See LICENSE file in root folder
*/
#include "ShaderAST/Stmt/StmtCache.hpp"

#include "ShaderAST/Stmt/PreprocExtension.hpp"
#include "ShaderAST/Stmt/PreprocVersion.hpp"
#include "ShaderAST/Stmt/StmtAccelerationStructureDecl.hpp"
#include "ShaderAST/Stmt/StmtBreak.hpp"
#include "ShaderAST/Stmt/StmtBufferReferenceDecl.hpp"
#include "ShaderAST/Stmt/StmtComment.hpp"
#include "ShaderAST/Stmt/StmtCompound.hpp"
#include "ShaderAST/Stmt/StmtContainer.hpp"
#include "ShaderAST/Stmt/StmtContinue.hpp"
#include "ShaderAST/Stmt/StmtConstantBufferDecl.hpp"
#include "ShaderAST/Stmt/StmtDemote.hpp"
#include "ShaderAST/Stmt/StmtDispatchMesh.hpp"
#include "ShaderAST/Stmt/StmtDoWhile.hpp"
#include "ShaderAST/Stmt/StmtElse.hpp"
#include "ShaderAST/Stmt/StmtElseIf.hpp"
#include "ShaderAST/Stmt/StmtFor.hpp"
#include "ShaderAST/Stmt/StmtFragmentLayout.hpp"
#include "ShaderAST/Stmt/StmtFunctionDecl.hpp"
#include "ShaderAST/Stmt/StmtHitAttributeVariableDecl.hpp"
#include "ShaderAST/Stmt/StmtIf.hpp"
#include "ShaderAST/Stmt/StmtImageDecl.hpp"
#include "ShaderAST/Stmt/StmtIgnoreIntersection.hpp"
#include "ShaderAST/Stmt/StmtInOutCallableDataVariableDecl.hpp"
#include "ShaderAST/Stmt/StmtInOutRayPayloadVariableDecl.hpp"
#include "ShaderAST/Stmt/StmtInOutVariableDecl.hpp"
#include "ShaderAST/Stmt/StmtInputComputeLayout.hpp"
#include "ShaderAST/Stmt/StmtInputGeometryLayout.hpp"
#include "ShaderAST/Stmt/StmtInputTessellationEvaluationLayout.hpp"
#include "ShaderAST/Stmt/StmtOutputGeometryLayout.hpp"
#include "ShaderAST/Stmt/StmtOutputMeshLayout.hpp"
#include "ShaderAST/Stmt/StmtOutputTessellationControlLayout.hpp"
#include "ShaderAST/Stmt/StmtPerPrimitiveDecl.hpp"
#include "ShaderAST/Stmt/StmtPerVertexDecl.hpp"
#include "ShaderAST/Stmt/StmtPushConstantsBufferDecl.hpp"
#include "ShaderAST/Stmt/StmtReturn.hpp"
#include "ShaderAST/Stmt/StmtSampledImageDecl.hpp"
#include "ShaderAST/Stmt/StmtCombinedImageDecl.hpp"
#include "ShaderAST/Stmt/StmtSamplerDecl.hpp"
#include "ShaderAST/Stmt/StmtShaderBufferDecl.hpp"
#include "ShaderAST/Stmt/StmtShaderStructBufferDecl.hpp"
#include "ShaderAST/Stmt/StmtSimple.hpp"
#include "ShaderAST/Stmt/StmtSpecialisationConstantDecl.hpp"
#include "ShaderAST/Stmt/StmtStructureDecl.hpp"
#include "ShaderAST/Stmt/StmtSwitchCase.hpp"
#include "ShaderAST/Stmt/StmtSwitch.hpp"
#include "ShaderAST/Stmt/StmtTerminateInvocation.hpp"
#include "ShaderAST/Stmt/StmtTerminateRay.hpp"
#include "ShaderAST/Stmt/StmtVariableDecl.hpp"
#include "ShaderAST/Stmt/StmtWhile.hpp"

namespace ast::stmt
{
	//*********************************************************************************************

	void DeleteStmt::operator()( Stmt * stmt )const noexcept
	{
		if ( stmt )
		{
			stmt->getStmtCache().freeStmt( stmt );
		}
	}

	//*********************************************************************************************

	StmtCache::StmtCache( ShaderAllocatorBlock & allocator )
		: m_allocator{ allocator }
	{
	}

	PreprocExtensionPtr StmtCache::makePreprocExtension( std::string name
		, PreprocExtension::ExtStatus status )
	{
		return makeStmt< PreprocExtension >( std::move( name )
			, status );
	}

	PreprocVersionPtr StmtCache::makePreprocVersion( std::string name )
	{
		return makeStmt< PreprocVersion >( std::move( name ) );
	}

	AccelerationStructureDeclPtr StmtCache::makeAccelerationStructureDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< AccelerationStructureDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}

	BreakPtr StmtCache::makeBreak( bool switchCaseBreak )
	{
		return makeStmt< Break >( switchCaseBreak );
	}

	BufferReferenceDeclPtr StmtCache::makeBufferReferenceDecl( type::TypePtr type )
	{
		return makeStmt< BufferReferenceDecl >( std::move( type ) );
	}

	CombinedImageDeclPtr StmtCache::makeCombinedImageDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< CombinedImageDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}

	CommentPtr StmtCache::makeComment( std::string text )
	{
		return makeStmt< Comment >( std::move( text ) );
	}

	CompoundPtr StmtCache::makeCompound()
	{
		return makeStmt< Compound >();
	}

	ConstantBufferDeclPtr StmtCache::makeConstantBufferDecl( std::string name
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< ConstantBufferDecl >( std::move( name )
			, layout
			, bindingPoint
			, bindingSet );
	}

	ContainerPtr StmtCache::makeContainer()
	{
		return makeStmt< Container >();
	}

	ContinuePtr StmtCache::makeContinue()
	{
		return makeStmt< Continue >();
	}

	DemotePtr StmtCache::makeDemote()
	{
		return makeStmt< Demote >();
	}

	DispatchMeshPtr StmtCache::makeDispatchMesh( expr::ExprPtr numGroupsX
		, expr::ExprPtr numGroupsY
		, expr::ExprPtr numGroupsZ
		, expr::ExprPtr payload )
	{
		return makeStmt< DispatchMesh >( std::move( numGroupsX )
			, std::move( numGroupsY )
			, std::move( numGroupsZ )
			, std::move( payload ) );
	}

	DoWhilePtr StmtCache::makeDoWhile( expr::ExprPtr ctrlExpr )
	{
		return makeStmt< DoWhile >( std::move( ctrlExpr ) );
	}

	ElseIfPtr StmtCache::makeElseIf( expr::ExprPtr ctrlExpr )
	{
		return makeStmt< ElseIf >( std::move( ctrlExpr ) );
	}

	ElsePtr StmtCache::makeElse()
	{
		return makeStmt< Else >();
	}

	ForPtr StmtCache::makeFor( expr::ExprPtr initExpr
		, expr::ExprPtr ctrlExpr
		, expr::ExprPtr incrExpr )
	{
		return makeStmt< For >( std::move( initExpr )
			, std::move( ctrlExpr )
			, std::move( incrExpr ) );
	}

	FragmentLayoutPtr StmtCache::makeFragmentLayout( type::TypePtr type
		, FragmentOrigin origin
		, FragmentCenter center )
	{
		return makeStmt< FragmentLayout >( type
			, origin
			, center );
	}

	FunctionDeclPtr StmtCache::makeFunctionDecl( var::VariablePtr funcVar
		, FunctionFlag flag )
	{
		return makeFunctionDecl( std::move( funcVar )
			, uint32_t( flag ) );
	}

	FunctionDeclPtr StmtCache::makeFunctionDecl( var::VariablePtr funcVar
		, uint32_t flags )
	{
		return makeStmt< FunctionDecl >( std::move( funcVar )
			, flags );
	}

	HitAttributeVariableDeclPtr StmtCache::makeHitAttributeVariableDecl( var::VariablePtr variable )
	{
		return makeStmt< HitAttributeVariableDecl >( std::move( variable ) );
	}

	IfPtr StmtCache::makeIf( expr::ExprPtr ctrlExpr )
	{
		return makeStmt< If >( std::move( ctrlExpr ) );
	}

	IgnoreIntersectionPtr StmtCache::makeIgnoreIntersection()
	{
		return makeStmt< IgnoreIntersection >();
	}

	ImageDeclPtr StmtCache::makeImageDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< ImageDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}

	InOutCallableDataVariableDeclPtr StmtCache::makeInOutCallableDataVariableDecl( var::VariablePtr variable
		, uint32_t location )
	{
		return makeStmt< InOutCallableDataVariableDecl >( std::move( variable )
			, location );
	}

	InOutRayPayloadVariableDeclPtr StmtCache::makeInOutRayPayloadVariableDecl( var::VariablePtr variable
		, uint32_t location )
	{
		return makeStmt< InOutRayPayloadVariableDecl >( std::move( variable )
			, location );
	}

	InOutVariableDeclPtr StmtCache::makeInOutVariableDecl( var::VariablePtr variable
		, uint32_t location )
	{
		return makeInOutVariableDecl( std::move( variable )
			, location
			, 0u
			, 0u );
	}

	InOutVariableDeclPtr StmtCache::makeInOutVariableDecl( var::VariablePtr variable
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t blendIndex )
	{
		return makeStmt< InOutVariableDecl >( std::move( variable )
			, location
			, streamIndex
			, blendIndex );
	}

	InOutVariableDeclPtr StmtCache::makeInOutStreamVariableDecl( var::VariablePtr variable
		, uint32_t location
		, uint32_t streamIndex )
	{
		return makeStmt< InOutVariableDecl >( std::move( variable )
			, location
			, streamIndex
			, 0u );
	}

	InOutVariableDeclPtr StmtCache::makeInOutBlendVariableDecl( var::VariablePtr variable
		, uint32_t location
		, uint32_t blendIndex )
	{
		return makeStmt< InOutVariableDecl >( std::move( variable )
			, location
			, 0u
			, blendIndex );
	}

	InputComputeLayoutPtr StmtCache::makeInputComputeLayout( type::TypePtr type
		, uint32_t workGroupsX
		, uint32_t workGroupsY
		, uint32_t workGroupsZ )
	{
		return makeStmt< InputComputeLayout >( type
			, workGroupsX
			, workGroupsY
			, workGroupsZ );
	}

	InputGeometryLayoutPtr StmtCache::makeInputGeometryLayout( type::TypePtr type
		, type::InputLayout layout )
	{
		return makeStmt< InputGeometryLayout >( std::move( type )
			, layout );
	}

	InputTessellationEvaluationLayoutPtr StmtCache::makeInputTessellationEvaluationLayout( type::TypePtr type
		, type::PatchDomain domain
		, type::Partitioning partitioning
		, type::PrimitiveOrdering order )
	{
		return makeStmt< InputTessellationEvaluationLayout >( std::move( type )
			, domain
			, partitioning
			, order );
	}

	OutputGeometryLayoutPtr StmtCache::makeOutputGeometryLayout( type::TypePtr type
		, type::OutputLayout layout
		, uint32_t primCount )
	{
		return makeStmt< OutputGeometryLayout >( std::move( type )
			, layout
			, primCount );
	}

	OutputMeshLayoutPtr StmtCache::makeOutputMeshLayout( type::TypePtr type
		, type::OutputTopology topology
		, uint32_t maxVertices
		, uint32_t maxPrimitives )
	{
		return makeStmt< OutputMeshLayout >( std::move( type )
			, topology
			, maxVertices
			, maxPrimitives );
	}

	OutputTessellationControlLayoutPtr StmtCache::makeOutputTessellationControlLayout( type::TypePtr type
		, type::PatchDomain domain
		, type::Partitioning partitioning
		, type::OutputTopology topology
		, type::PrimitiveOrdering order
		, uint32_t outputVertices )
	{
		return makeStmt< OutputTessellationControlLayout >( std::move( type )
			, domain
			, partitioning
			, topology
			, order
			, outputVertices );
	}

	PerPrimitiveDeclPtr StmtCache::makePerPrimitiveDecl( type::TypePtr type )
	{
		return makeStmt< PerPrimitiveDecl >( std::move( type ) );
	}

	PerVertexDeclPtr StmtCache::makePerVertexDecl( PerVertexDecl::Source source
		, type::TypePtr type )
	{
		return makeStmt< PerVertexDecl >( source
			, std::move( type ) );
	}

	PushConstantsBufferDeclPtr StmtCache::makePushConstantsBufferDecl( std::string name
		, type::MemoryLayout layout )
	{
		return makeStmt< PushConstantsBufferDecl >( std::move( name )
			, layout );
	}

	ReturnPtr StmtCache::makeReturn()
	{
		return makeStmt< Return >( nullptr );
	}

	ReturnPtr StmtCache::makeReturn( expr::ExprPtr expr )
	{
		return makeStmt< Return >( std::move( expr ) );
	}

	SampledImageDeclPtr StmtCache::makeSampledImageDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< SampledImageDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}

	SamplerDeclPtr StmtCache::makeSamplerDecl( var::VariablePtr variable
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< SamplerDecl >( std::move( variable )
			, bindingPoint
			, bindingSet );
	}

	ShaderBufferDeclPtr StmtCache::makeShaderBufferDecl( type::TypesCache & typesCache
		, std::string const & ssboName
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet
		, uint32_t nextVarId )
	{
		auto type = typesCache.getStruct( layout, ssboName );
		assert( type != nullptr );
		return makeShaderBufferDecl( var::makeVariable( nextVarId, type, ssboName + "_data" )
			, bindingPoint
			, bindingSet );
	}

	ShaderBufferDeclPtr StmtCache::makeShaderBufferDecl( var::VariablePtr var
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< ShaderBufferDecl >( var
			, bindingPoint
			, bindingSet );
	}

	ShaderStructBufferDeclPtr StmtCache::makeShaderStructBufferDecl( std::string ssboName
		, var::VariablePtr ssboInstance
		, var::VariablePtr data
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return makeStmt< ShaderStructBufferDecl >( std::move( ssboName )
			, std::move( ssboInstance )
			, std::move( data )
			, bindingPoint
			, bindingSet );
	}

	SimplePtr StmtCache::makeSimple( expr::ExprPtr expr )
	{
		return makeStmt< Simple >( std::move( expr ) );
	}

	SpecialisationConstantDeclPtr StmtCache::makeSpecialisationConstantDecl( var::VariablePtr variable
		, uint32_t location
		, expr::LiteralPtr value )
	{
		return makeStmt< SpecialisationConstantDecl >( std::move( variable )
			, location
			, std::move( value ) );
	}

	StructureDeclPtr StmtCache::makeStructureDecl( type::StructPtr type )
	{
		return makeStmt< StructureDecl >( std::move( type ) );
	}

	SwitchPtr StmtCache::makeSwitch( expr::SwitchTestPtr testExpr )
	{
		return makeStmt< Switch >( std::move( testExpr ) );
	}

	SwitchCasePtr StmtCache::makeSwitchCase( expr::SwitchCasePtr label )
	{
		return makeStmt< SwitchCase >( std::move( label ) );
	}

	SwitchCasePtr StmtCache::makeSwitchDefault()
	{
		return makeStmt< SwitchCase >();
	}

	TerminateInvocationPtr StmtCache::makeTerminateInvocation()
	{
		return makeStmt< TerminateInvocation >();
	}

	TerminateRayPtr StmtCache::makeTerminateRay()
	{
		return makeStmt< TerminateRay >();
	}

	VariableDeclPtr StmtCache::makeVariableDecl( var::VariablePtr variable )
	{
		return makeStmt< VariableDecl >( std::move( variable ) );
	}

	WhilePtr StmtCache::makeWhile( expr::ExprPtr ctrlExpr )
	{
		return makeStmt< While >( std::move( ctrlExpr ) );
	}

	void StmtCache::freeStmt( Stmt * stmt )noexcept
	{
		stmt->~Stmt();
		m_allocator.deallocate( stmt, stmt->getSize() );
	}
}
