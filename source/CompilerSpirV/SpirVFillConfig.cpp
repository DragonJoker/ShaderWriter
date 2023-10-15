/*
See LICENSE file in root folder
*/
#include "SpirVFillConfig.hpp"

#include "SpirVHelpers.hpp"
#include "SpirVIntrinsicConfig.hpp"
#include "SpirVIntrinsicNames.hpp"
#include "SpirVStorageImageAccessConfig.hpp"
#include "SpirVStorageImageAccessNames.hpp"
#include "SpirVCombinedImageAccessConfig.hpp"
#include "SpirVCombinedImageAccessNames.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>

#include <stdexcept>

namespace spirv
{
	namespace config
	{
		namespace helpers
		{
			static void checkType( ast::expr::Expr * expr
				, ModuleConfig & config )
			{
				checkType( expr->getType()
					, config );
			}

			static void checkType( ast::expr::IntrinsicCall * expr
				, ModuleConfig & config )
			{
				checkType( expr->getType()
					, config );
				auto kind = expr->getIntrinsic();

				if ( ( kind >= ast::expr::Intrinsic::eDFdxCoarse1
					&& kind <= ast::expr::Intrinsic::eDFdxFine4 )
					|| ( kind >= ast::expr::Intrinsic::eDFdyCoarse1
						&& kind <= ast::expr::Intrinsic::eDFdyFine4 ) )
				{
					config.registerCapability( spv::CapabilityDerivativeControl );
				}
				else if ( kind >= ast::expr::Intrinsic::eInterpolateAtCentroid1
					&& kind <= ast::expr::Intrinsic::eInterpolateAtOffset4 )
				{
					config.registerCapability( spv::CapabilityInterpolationFunction );
				}
				else if ( kind == ast::expr::Intrinsic::eAtomicAddF
					|| kind == ast::expr::Intrinsic::eAtomicAdd2H
					|| kind == ast::expr::Intrinsic::eAtomicAdd4H )
				{
					if ( isDoubleType( expr->getType()->getKind() ) )
					{
						config.registerCapability( spv::CapabilityAtomicFloat64AddEXT );
					}
					else
					{
						config.registerCapability( spv::CapabilityAtomicFloat32AddEXT );
					}
				}
				else if ( kind == ast::expr::Intrinsic::eTraceRay
					|| kind == ast::expr::Intrinsic::eReportIntersection
					|| kind == ast::expr::Intrinsic::eExecuteCallable )
				{
					if ( isRayTraceStage( config.stage ) )
					{
						config.registerCapability( spv::CapabilityRayTracingKHR );
					}
					else
					{
						config.registerCapability( spv::CapabilityRayQueryKHR );
					}
				}
				else if ( kind == ast::expr::Intrinsic::eSubgroupElect )
				{
					config.registerCapability( spv::CapabilityGroupNonUniform );
				}
				else if ( kind == ast::expr::Intrinsic::eSubgroupAll
					|| kind == ast::expr::Intrinsic::eSubgroupAny
					|| ( kind >= ast::expr::Intrinsic::eSubgroupAllEqual1F
						&& kind <= ast::expr::Intrinsic::eSubgroupAllEqual4D ) )
				{
					config.registerCapability( spv::CapabilityGroupNonUniformVote );
				}
				else if ( ( kind >= ast::expr::Intrinsic::eSubgroupBallot
					&& kind <= ast::expr::Intrinsic::eSubgroupBallotFindMSB )
					|| ( kind >= ast::expr::Intrinsic::eSubgroupBroadcast1F
						&& kind <= ast::expr::Intrinsic::eSubgroupBroadcast4D )
					|| ( kind >= ast::expr::Intrinsic::eSubgroupBroadcastFirst1F
						&& kind <= ast::expr::Intrinsic::eSubgroupBroadcastFirst4D ) )
				{
					config.registerCapability( spv::CapabilityGroupNonUniformBallot );
				}
				else if ( kind >= ast::expr::Intrinsic::eSubgroupShuffle1F
					&& kind <= ast::expr::Intrinsic::eSubgroupShuffleXor4D )
				{
					config.registerCapability( spv::CapabilityGroupNonUniformShuffle );
				}
				else if ( kind >= ast::expr::Intrinsic::eSubgroupShuffleUp1F
					&& kind <= ast::expr::Intrinsic::eSubgroupShuffleDown4D )
				{
					config.registerCapability( spv::CapabilityGroupNonUniformShuffleRelative );
				}
				else if ( kind >= ast::expr::Intrinsic::eSubgroupAdd1F
					&& kind <= ast::expr::Intrinsic::eSubgroupExclusiveXor4B )
				{
					config.registerCapability( spv::CapabilityGroupNonUniformArithmetic );
				}
				else if ( kind >= ast::expr::Intrinsic::eSubgroupClusterAdd1F
					&& kind <= ast::expr::Intrinsic::eSubgroupClusterXor4B )
				{
					config.registerCapability( spv::CapabilityGroupNonUniformArithmetic );
					config.registerCapability( spv::CapabilityGroupNonUniformClustered );
				}
				else if ( kind >= ast::expr::Intrinsic::eSubgroupQuadBroadcast1F
					&& kind <= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D )
				{
					config.registerCapability( spv::CapabilityGroupNonUniformQuad );
				}
				else if ( kind >= ast::expr::Intrinsic::eReadInvocation1F
					&& kind <= ast::expr::Intrinsic::eReadFirstInvocation4D )
				{
					config.registerCapability( spv::CapabilitySubgroupBallotKHR );
				}
				else if ( kind >= ast::expr::Intrinsic::eControlBarrier
					&& kind <= ast::expr::Intrinsic::eMemoryBarrier )
				{
					ast::type::Scope memory;
					bool isControlBarrier = ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );

					if ( isControlBarrier )
					{
						if ( expr->getArgList().size() < 3u )
						{
							throw std::runtime_error{ "Wrong number of parameters for a control barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
					}
					else
					{
						if ( expr->getArgList().size() < 2u )
						{
							throw std::runtime_error{ "Wrong number of parameters for a memory barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[0] ) );
					}

					if ( memory == ast::type::Scope::eSubgroup )
					{
						config.registerCapability( spv::CapabilitySubgroupBallotKHR );
					}
				}
			}
		}

		class ExprConfigFiller
			: public ast::expr::SimpleVisitor
		{
		public:
			static void submit( ast::expr::Expr * expr
				, ModuleConfig & config )
			{
				ExprConfigFiller vis{ config };
				expr->accept( &vis );

				if ( expr->isNonUniform() )
				{
					config.registerCapability( spv::CapabilityShaderNonUniform );
				}
			}

		private:
			explicit ExprConfigFiller( ModuleConfig & config )
				: ast::expr::SimpleVisitor{}
				, m_config{ config }
			{
			}

			void doSubmit( ast::expr::Expr * expr )
			{
				submit( expr, m_config );
			}

			void doSubmit( ast::expr::ExprPtr const & expr )
			{
				doSubmit( expr.get() );
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				helpers::checkType( expr, m_config );
				doSubmit( expr->getOperand() );
			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				helpers::checkType( expr, m_config );
				doSubmit( expr->getLHS() );
				doSubmit( expr->getRHS() );
			}

			void visitAggrInitExpr( ast::expr::AggrInit * expr )override
			{
				helpers::checkType( expr, m_config );

				if ( expr->getIdentifier() )
				{
					doSubmit( expr->getIdentifier() );
				}

				for ( auto & init : expr->getInitialisers() )
				{
					doSubmit( init );
				}
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				helpers::checkType( expr, m_config );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( arg );
				}
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				helpers::checkType( expr, m_config );
				doSubmit( expr->getOuterExpr() );

				if ( expr->isBuiltin() )
				{
					m_config.addMbrBuiltin( expr->getOuterExpr()
						, expr->getMemberIndex()
						, *expr
						, 0u
						, ast::type::NotArray );
				}
			}

			void visitFnCallExpr( ast::expr::FnCall * expr )override
			{
				helpers::checkType( expr, m_config );
				doSubmit( expr->getFn() );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( arg );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override
			{
				helpers::checkType( expr, m_config );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( arg );
				}

				auto kind = expr->getImageAccess();
				auto & config = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() )->getConfig();

				if ( config.dimension == ast::type::ImageDim::e1D )
				{
					m_config.registerCapability( spv::CapabilityImage1D );
				}
				else if ( config.dimension == ast::type::ImageDim::eRect )
				{
					m_config.registerCapability( spv::CapabilityImageRect );
				}
				else if ( config.dimension == ast::type::ImageDim::eBuffer )
				{
					m_config.registerCapability( spv::CapabilityImageBuffer );
				}

				if ( config.isArrayed )
				{
					if ( config.dimension == ast::type::ImageDim::eCube )
					{
						m_config.registerCapability( spv::CapabilityImageCubeArray );
					}
					else if ( config.isMS )
					{
						m_config.registerCapability( spv::CapabilityImageMSArray );
					}
				}

				if ( ( kind >= ast::expr::StorageImageAccess::eImageSize1DF
					&& kind <= ast::expr::StorageImageAccess::eImageSize2DMSArrayU )
					|| ( kind >= ast::expr::StorageImageAccess::eImageSamples2DMSF
						&& kind <= ast::expr::StorageImageAccess::eImageSamples2DMSArrayU ) )
				{
					m_config.registerCapability( spv::CapabilityImageQuery );
				}
				else if ( ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAdd1DF
					&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF )
					|| ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicExchange1DF
						&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF ) )
				{
					m_config.registerCapability( spv::CapabilityAtomicFloat32AddEXT );
				}
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
			{
				helpers::checkType( expr, m_config );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( arg );
				}

				auto kind = expr->getIntrinsic();

				if ( ( kind >= ast::expr::Intrinsic::eAtomicAddF
					&& kind <= ast::expr::Intrinsic::eAtomicAdd4H )
					|| ( kind >= ast::expr::Intrinsic::eAtomicExchangeF
						&& kind <= ast::expr::Intrinsic::eAtomicExchange4H ) )
				{
					m_config.registerCapability( spv::CapabilityAtomicFloat32AddEXT );
				}
				else if ( kind == ast::expr::Intrinsic::eHelperInvocation )
				{
					m_config.registerCapability( spv::CapabilityDemoteToHelperInvocation );
					// The extension is not optional, when using helperInvocation intrinsic.
					m_config.registerExtension( EXT_demote_to_helper_invocation );
				}
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override
			{
				helpers::checkType( expr, m_config );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( arg );

					if ( arg->isNonUniform() )
					{
						m_config.registerCapability( spv::CapabilitySampledImageArrayNonUniformIndexing );
					}
				}

				auto kind = expr->getCombinedImageAccess();

				if ( ( kind >= ast::expr::CombinedImageAccess::eTextureSize1DF
					&& kind <= ast::expr::CombinedImageAccess::eTextureSizeBufferU )
					|| ( kind >= ast::expr::CombinedImageAccess::eTextureQueryLod1DF
						&& kind <= ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU )
					|| ( kind >= ast::expr::CombinedImageAccess::eTextureQueryLevels1DF
						&& kind <= ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU ) )
				{
					m_config.registerCapability( spv::CapabilityImageQuery );
				}

				if ( ( kind >= ast::expr::CombinedImageAccess::eTextureGather2DShadowF
					&& kind <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectShadowF ) )
				{
					m_config.registerCapability( spv::CapabilityImageGatherExtended );
				}

				if ( getConstOffsets( kind ) == spv::ImageOperandsConstOffsetsMask )
				{
					m_config.registerCapability( spv::CapabilityImageGatherExtended );
				}

				IntrinsicConfig config;
				getSpirVConfig( kind, config );

				if ( config.offsetIndex )
				{
					assert( expr->getArgList().size() >= config.offsetIndex );
					bool constOffset = expr->getArgList()[config.offsetIndex - 1u]->isConstant();

					if ( getOffset( kind, constOffset ) == spv::ImageOperandsOffsetMask )
					{
						m_config.registerCapability( spv::CapabilityImageGatherExtended );
					}
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				helpers::checkType( expr, m_config );
			}

			void visitInitExpr( ast::expr::Init * expr )override
			{
				helpers::checkType( expr, m_config );
				doSubmit( expr->getIdentifier() );
				doSubmit( expr->getInitialiser() );
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				helpers::checkType( expr, m_config );
			}

			void visitQuestionExpr( ast::expr::Question * expr )override
			{
				helpers::checkType( expr, m_config );
				doSubmit( expr->getCtrlExpr() );
				doSubmit( expr->getTrueExpr() );
				doSubmit( expr->getFalseExpr() );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
			{
				doSubmit( expr->getOperand() );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
			{
				doSubmit( expr->getLabel() );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
			{
				doSubmit( expr->getValue() );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				helpers::checkType( expr, m_config );
				doSubmit( expr->getOuterExpr() );
			}

		private:
			ModuleConfig & m_config;
		};

		class StmtConfigFiller
			: public ast::stmt::Visitor
		{
		public:
			static void submit( ast::stmt::Container * cont
				, ModuleConfig & moduleConfig )
			{
				StmtConfigFiller vis{ moduleConfig };
				cont->accept( &vis );
			}

		private:
			explicit StmtConfigFiller( ModuleConfig & result )
				: m_result{ result }
			{
				switch ( m_result.stage )
				{
				case ast::ShaderStage::eVertex:
					m_result.registerCapability( spv::CapabilityShader );
					break;
				case ast::ShaderStage::eTessellationControl:
				case ast::ShaderStage::eTessellationEvaluation:
					m_result.registerCapability( spv::CapabilityShader );
					m_result.registerCapability( spv::CapabilityTessellation );
					break;
				case ast::ShaderStage::eGeometry:
					m_result.registerCapability( spv::CapabilityShader );
					m_result.registerCapability( spv::CapabilityGeometry );
					break;
				case ast::ShaderStage::eFragment:
					m_result.registerCapability( spv::CapabilityShader );
					break;
				case ast::ShaderStage::eCompute:
					m_result.registerCapability( spv::CapabilityShader );
					break;
				case ast::ShaderStage::eTaskNV:
				case ast::ShaderStage::eMeshNV:
					m_result.registerCapability( spv::CapabilityMeshShadingNV );
					break;
				case ast::ShaderStage::eTask:
				case ast::ShaderStage::eMesh:
					m_result.registerCapability( spv::CapabilityMeshShadingEXT );
					break;
				case ast::ShaderStage::eRayGeneration:
				case ast::ShaderStage::eRayClosestHit:
				case ast::ShaderStage::eRayMiss:
				case ast::ShaderStage::eRayIntersection:
				case ast::ShaderStage::eRayAnyHit:
				case ast::ShaderStage::eCallable:
					m_result.registerCapability( spv::CapabilityShader );
					m_result.registerCapability( spv::CapabilityRayTracingKHR );
					break;
				}
			}

			void visitBreakStmt( ast::stmt::Break * cont )override
			{
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitContainerStmt( ast::stmt::Container * cont )override
			{
				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}
			}

			void visitContinueStmt( ast::stmt::Continue * cont )override
			{
			}

			void visitDemoteStmt( ast::stmt::Demote * stmt )override
			{
				m_result.registerCapability( spv::CapabilityDemoteToHelperInvocation );
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh * stmt )override
			{
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )override
			{
				m_result.registerExtension( KHR_terminate_invocation, true );
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitCommentStmt( ast::stmt::Comment * stmt )override
			{
			}

			void visitCompoundStmt( ast::stmt::Compound * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile * stmt )override
			{
				ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitElseIfStmt( ast::stmt::ElseIf * stmt )override
			{
				ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitElseStmt( ast::stmt::Else * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitForStmt( ast::stmt::For * stmt )override
			{
				ExprConfigFiller::submit( stmt->getInitExpr(), m_result );
				ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
				ExprConfigFiller::submit( stmt->getIncrExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )override
			{
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override
			{
				if ( stmt->getFlags() )
				{
					m_result.initialise( *stmt );
				}

				visitContainerStmt( stmt );
			}

			void visitIfStmt( ast::stmt::If * stmt )override
			{
				ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
				visitContainerStmt( stmt );

				for ( auto & elseIf : stmt->getElseIfList() )
				{
					elseIf->accept( this );
				}

				if ( stmt->getElse() )
				{
					stmt->getElse()->accept( this );
				}
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * cont )override
			{
				if ( isRayTraceStage( m_result.stage ) )
				{
					m_result.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					m_result.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )override
			{
				m_result.addressingModel = spv::AddressingModelPhysicalStorageBuffer64;
				m_result.registerCapability( spv::CapabilityPhysicalStorageBufferAddresses );
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )override
			{
				if ( isRayTraceStage( m_result.stage ) )
				{
					m_result.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					m_result.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )override
			{
				if ( isRayTraceStage( m_result.stage ) )
				{
					m_result.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					m_result.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )override
			{
				if ( isRayTraceStage( m_result.stage ) )
				{
					m_result.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					m_result.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override
			{
				auto imgType = std::static_pointer_cast< ast::type::Image >( ast::type::getNonArrayType( stmt->getVariable()->getType() ) );

				if ( imgType->getConfig().dimension == ast::type::ImageDim::e1D )
				{
					m_result.registerCapability( spv::CapabilitySampled1D );
				}

				if ( imgType->getConfig().dimension == ast::type::ImageDim::eRect )
				{
					m_result.registerCapability( spv::CapabilitySampledRect );
				}

				if ( imgType->getConfig().dimension == ast::type::ImageDim::eBuffer )
				{
					m_result.registerCapability( spv::CapabilitySampledBuffer );
				}

				if ( imgType->getConfig().isMS )
				{
					m_result.registerCapability( spv::CapabilityStorageImageMultisample );
				}

				switch ( imgType->getConfig().format )
				{
				case ast::type::ImageFormat::eRg32f:
				case ast::type::ImageFormat::eRg16f:
				case ast::type::ImageFormat::eR32f:
				case ast::type::ImageFormat::eR16f:
				case ast::type::ImageFormat::eRg32i:
				case ast::type::ImageFormat::eRg16i:
				case ast::type::ImageFormat::eRg8i:
				case ast::type::ImageFormat::eR32i:
				case ast::type::ImageFormat::eR16i:
				case ast::type::ImageFormat::eR8i:
				case ast::type::ImageFormat::eRg32u:
				case ast::type::ImageFormat::eRg16u:
				case ast::type::ImageFormat::eRg8u:
				case ast::type::ImageFormat::eR32u:
				case ast::type::ImageFormat::eR16u:
				case ast::type::ImageFormat::eR8u:
					m_result.registerCapability( spv::CapabilityStorageImageExtendedFormats );
					break;
				default:
					break;
				}
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )override
			{
				if ( isRayTraceStage( m_result.stage ) )
				{
					m_result.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					m_result.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override
			{
				auto var = stmt->getVariable();

				if ( !var->isShaderConstant() )
				{
					if ( var->isShaderInput() )
					{
						m_result.addPendingInput( var
							, stmt->getLocation() );
					}

					if ( var->isShaderOutput() )
					{
						m_result.addPendingOutput( var
							, stmt->getLocation() );
					}
				}

				if ( var->isPatch() )
				{
					m_result.registerCapability( spv::CapabilityTessellation );
				}

				if ( var->isPerSample() )
				{
					m_result.registerCapability( spv::CapabilitySampleRateShading );
				}

				if ( var->isGeometryStream() )
				{
					m_result.registerCapability( spv::CapabilityGeometryStreams );
				}

				doTraverseType( var->getType() );
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override
			{
				doTraverseType( stmt->getVariable()->getType() );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override
			{
				doTraverseType( stmt->getType() );
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override
			{
				doTraverseType( stmt->getType() );
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )override
			{
				doTraverseType( stmt->getType() );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override
			{
				doTraverseType( stmt->getType() );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )override
			{
				doTraverseType( stmt->getType() );
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override
			{
				doTraverseType( stmt->getType() );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )override
			{
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override
			{
			}

			void visitReturnStmt( ast::stmt::Return * stmt )override
			{
				if ( stmt->getExpr() )
				{
					ExprConfigFiller::submit( stmt->getExpr(), m_result );
				}
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override
			{
				doTraverseType( stmt->getVariable()->getType() );
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )override
			{
				doTraverseType( stmt->getVariable()->getType() );
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override
			{
				doTraverseType( stmt->getVariable()->getType() );
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override
			{
				doTraverseType( stmt->getSsboInstance()->getType() );
			}

			void visitSimpleStmt( ast::stmt::Simple * stmt )override
			{
				ExprConfigFiller::submit( stmt->getExpr(), m_result );
				doTraverseType( stmt->getExpr()->getType() );
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override
			{
				doTraverseType( stmt->getType() );
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitSwitchStmt( ast::stmt::Switch * stmt )override
			{
				ExprConfigFiller::submit( stmt->getTestExpr()->getValue(), m_result );
				visitContainerStmt( stmt );
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )override
			{
				if ( isRayTraceStage( m_result.stage ) )
				{
					m_result.registerCapability( spv::CapabilityRayTracingKHR );
				}
				else
				{
					m_result.registerCapability( spv::CapabilityRayQueryKHR );
				}
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override
			{
				doTraverseType( stmt->getVariable()->getType() );
				auto var = stmt->getVariable();

				if ( var->isShaderInput() )
				{
					m_result.addInput( var );
				}

				if ( var->isShaderOutput() )
				{
					m_result.addOutput( var );
				}
			}

			void visitWhileStmt( ast::stmt::While * stmt )override
			{
				ExprConfigFiller::submit( stmt->getCtrlExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override
			{
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override
			{
			}

			void doTraverseType( ast::type::TypePtr type )
			{
				checkType( type, m_result );
			}

		private:
			ModuleConfig & m_result;
		};
	}

	void fillConfig( ast::stmt::Container * cont
		, ModuleConfig & moduleConfig )
	{
		return config::StmtConfigFiller::submit( cont, moduleConfig );
	}
}
