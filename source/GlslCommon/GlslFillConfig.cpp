/*
See LICENSE file in root folder
*/
#include "GlslFillConfig.hpp"

#include "GlslCombinedImageAccessConfig.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>

#include <stdexcept>

namespace glsl
{
	namespace config
	{
		namespace helpers
		{
			static void checkBuiltin( ast::Builtin builtin
				, IntrinsicsConfig & config )
			{
				switch ( builtin )
				{
				case ast::Builtin::eGlobalInvocationID:
				case ast::Builtin::eLocalInvocationID:
				case ast::Builtin::eLocalInvocationIndex:
				case ast::Builtin::eNumWorkGroups:
				case ast::Builtin::eWorkGroupID:
					if ( config.stage == ast::ShaderStage::eCompute )
					{
						config.requiredExtensions.insert( ARB_compute_shader );
					}
					break;
				case ast::Builtin::eInvocationID:
					if ( config.stage == ast::ShaderStage::eTessellationControl
						|| config.stage == ast::ShaderStage::eTessellationEvaluation )
					{
						config.requiredExtensions.insert( ARB_tessellation_shader );
					}
					else
					{
						config.requiredExtensions.insert( ARB_gpu_shader5 );
					}
					break;
				case ast::Builtin::ePrimitiveIDIn:
					if ( config.stage == ast::ShaderStage::eTessellationControl
						|| config.stage == ast::ShaderStage::eTessellationEvaluation )
					{
						config.requiredExtensions.insert( ARB_tessellation_shader );
					}
					else
					{
						config.requiredExtensions.insert( NV_gpu_shader5 );
					}
					break;
				case ast::Builtin::eTessLevelInner:
				case ast::Builtin::eTessLevelOuter:
				case ast::Builtin::ePatchVerticesIn:
				case ast::Builtin::eTessCoord:
					config.requiredExtensions.insert( ARB_tessellation_shader );
					break;
				case ast::Builtin::eDrawIndex:
				case ast::Builtin::eBaseInstance:
				case ast::Builtin::eBaseVertex:
					config.requiredExtensions.insert( ARB_shader_draw_parameters );
					break;
				case ast::Builtin::eSampleID:
				case ast::Builtin::eSamplePosition:
					config.requiredExtensions.insert( ARB_sample_shading );
					break;
				case ast::Builtin::eViewportIndex:
					config.requiredExtensions.insert( ARB_viewport_array );
					if ( config.stage != ast::ShaderStage::eGeometry )
					{
						config.requiredExtensions.insert( ARB_fragment_layer_viewport );
					}
					break;
				case ast::Builtin::eSubgroupSize:
				case ast::Builtin::eSubgroupMaxSize:
				case ast::Builtin::eNumSubgroups:
				case ast::Builtin::eSubgroupID:
				case ast::Builtin::eSubgroupLocalInvocationID:
					config.requiredExtensions.insert( KHR_shader_subgroup_basic );
					break;
				case ast::Builtin::eSubgroupEqMask:
				case ast::Builtin::eSubgroupGeMask:
				case ast::Builtin::eSubgroupGtMask:
				case ast::Builtin::eSubgroupLeMask:
				case ast::Builtin::eSubgroupLtMask:
					config.requiredExtensions.insert( KHR_shader_subgroup_ballot );
					break;
				default:
					break;
				}
			}

			static void checkBuiltin( ast::var::Variable const & var
				, IntrinsicsConfig & config )
			{
				if ( var.isBuiltin() )
				{
					checkBuiltin( var.getBuiltin(), config );
				}
			}

			static void checkBuiltin( ast::type::Struct const & type
				, uint32_t index
				, IntrinsicsConfig & config )
			{
				auto & mbr = *std::next( type.begin(), ptrdiff_t( index ) );

				if ( mbr.builtin != ast::Builtin::eNone )
				{
					checkBuiltin( mbr.builtin, config );
				}
			}
		}

		class ExprConfigFiller
			: public ast::expr::SimpleVisitor
		{
		public:
			static void submit( ast::expr::Expr const & expr
				, IntrinsicsConfig & config )
			{
				ExprConfigFiller vis{ config };
				expr.accept( &vis );
			}

		private:
			explicit ExprConfigFiller( IntrinsicsConfig & config )
				: m_config{ config }
			{
			}

			void doSubmit( ast::expr::Expr const & expr )
			{
				expr.accept( this );

				if ( expr.isNonUniform() )
				{
					m_config.requiredExtensions.insert( EXT_nonuniform_qualifier );
				}
			}

			void visitUnaryExpr( ast::expr::Unary const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getOperand() );
			}

			void visitBinaryExpr( ast::expr::Binary const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getLHS() );
				doSubmit( *expr->getRHS() );
			}

			void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
			{
				checkType( expr->getType(), m_config );

				if ( expr->hasIdentifier() )
				{
					doSubmit( expr->getIdentifier() );
				}

				for ( auto & init : expr->getInitialisers() )
				{
					doSubmit( *init );
				}
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
			{
				checkType( expr->getType(), m_config );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( *arg );
				}
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
			{
				checkType( expr->getType(), m_config );
				helpers::checkBuiltin( *expr->getOuterType(), expr->getMemberIndex(), m_config );
				doSubmit( *expr->getOuterExpr() );
			}

			void visitFnCallExpr( ast::expr::FnCall const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getFn() );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( *arg );
				}
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
			{
				checkType( expr->getType(), m_config );

				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eSubgroupElect )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_basic );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupAll
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupAllEqual4D )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_vote );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupBroadcast1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupBallotFindMSB )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_ballot );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupShuffle1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupShuffleXor4D )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_shuffle );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupShuffleUp1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupShuffleDown4D )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_shuffle_relative );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupAdd1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupExclusiveXor4B )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_arithmetic );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupClusterAdd1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupClusterXor4B )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_arithmetic );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_clustered );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eSubgroupQuadBroadcast1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( KHR_shader_subgroup );
					m_config.requiredExtensions.insert( KHR_shader_subgroup_quad );
				}
				else if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eReadInvocation1F
					&& expr->getIntrinsic() <= ast::expr::Intrinsic::eReadFirstInvocation4D )
				{
					m_config.requiredExtensions.insert( KHR_vulkan_glsl );
					m_config.requiredExtensions.insert( ARB_shader_ballot );
				}
				else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier
					|| expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
				{
					ast::type::Scope memory;
					ast::type::MemorySemantics semantics;

					if ( bool isControlBarrier = ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );
						isControlBarrier )
					{
						if ( expr->getArgList().size() < 3u )
						{
							throw ast::Exception{ "Wrong number of parameters for a control barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[1] ) );
						semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[2] ) );
					}
					else
					{
						if ( expr->getArgList().size() < 2u )
						{
							throw ast::Exception{ "Wrong number of parameters for a memory barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[0] ) );
						semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( *expr->getArgList()[1] ) );
					}

					if ( memory == ast::type::Scope::eSubgroup )
					{
						m_config.requiredExtensions.insert( KHR_vulkan_glsl );
						m_config.requiredExtensions.insert( KHR_shader_subgroup_basic );
					}
					else
					{
						m_config.requiredExtensions.insert( ARB_compute_shader );
					}
				}

				switch ( expr->getIntrinsic() )
				{
				case ast::expr::Intrinsic::eFma1F:
					m_config.requiresFma1F = true;
					break;
				case ast::expr::Intrinsic::eFma2F:
					m_config.requiresFma2F = true;
					break;
				case ast::expr::Intrinsic::eFma3F:
					m_config.requiresFma3F = true;
					break;
				case ast::expr::Intrinsic::eFma4F:
					m_config.requiresFma4F = true;
					break;
				case ast::expr::Intrinsic::eFma1D:
					m_config.requiresFma1D = true;
					break;
				case ast::expr::Intrinsic::eFma2D:
					m_config.requiresFma2D = true;
					break;
				case ast::expr::Intrinsic::eFma3D:
					m_config.requiresFma3D = true;
					break;
				case ast::expr::Intrinsic::eFma4D:
					m_config.requiresFma4D = true;
					break;
				case ast::expr::Intrinsic::eDFdxCoarse1:
				case ast::expr::Intrinsic::eDFdxCoarse2:
				case ast::expr::Intrinsic::eDFdxCoarse3:
				case ast::expr::Intrinsic::eDFdxCoarse4:
				case ast::expr::Intrinsic::eDFdxFine1:
				case ast::expr::Intrinsic::eDFdxFine2:
				case ast::expr::Intrinsic::eDFdxFine3:
				case ast::expr::Intrinsic::eDFdxFine4:
				case ast::expr::Intrinsic::eDFdyCoarse1:
				case ast::expr::Intrinsic::eDFdyCoarse2:
				case ast::expr::Intrinsic::eDFdyCoarse3:
				case ast::expr::Intrinsic::eDFdyCoarse4:
				case ast::expr::Intrinsic::eDFdyFine1:
				case ast::expr::Intrinsic::eDFdyFine2:
				case ast::expr::Intrinsic::eDFdyFine3:
				case ast::expr::Intrinsic::eDFdyFine4:
					m_config.requiredExtensions.insert( ARB_derivative_control );
					break;
				case ast::expr::Intrinsic::eUaddCarry1:
				case ast::expr::Intrinsic::eUaddCarry2:
				case ast::expr::Intrinsic::eUaddCarry3:
				case ast::expr::Intrinsic::eUaddCarry4:
				case ast::expr::Intrinsic::eUsubBorrow1:
				case ast::expr::Intrinsic::eUsubBorrow2:
				case ast::expr::Intrinsic::eUsubBorrow3:
				case ast::expr::Intrinsic::eUsubBorrow4:
				case ast::expr::Intrinsic::eUmulExtended1:
				case ast::expr::Intrinsic::eUmulExtended2:
				case ast::expr::Intrinsic::eUmulExtended3:
				case ast::expr::Intrinsic::eUmulExtended4:
				case ast::expr::Intrinsic::eImulExtended1:
				case ast::expr::Intrinsic::eImulExtended2:
				case ast::expr::Intrinsic::eImulExtended3:
				case ast::expr::Intrinsic::eImulExtended4:
				case ast::expr::Intrinsic::eBitfieldExtract1I:
				case ast::expr::Intrinsic::eBitfieldExtract2I:
				case ast::expr::Intrinsic::eBitfieldExtract3I:
				case ast::expr::Intrinsic::eBitfieldExtract4I:
				case ast::expr::Intrinsic::eBitfieldExtract1U:
				case ast::expr::Intrinsic::eBitfieldExtract2U:
				case ast::expr::Intrinsic::eBitfieldExtract3U:
				case ast::expr::Intrinsic::eBitfieldExtract4U:
				case ast::expr::Intrinsic::eBitfieldInsert1I:
				case ast::expr::Intrinsic::eBitfieldInsert2I:
				case ast::expr::Intrinsic::eBitfieldInsert3I:
				case ast::expr::Intrinsic::eBitfieldInsert4I:
				case ast::expr::Intrinsic::eBitfieldInsert1U:
				case ast::expr::Intrinsic::eBitfieldInsert2U:
				case ast::expr::Intrinsic::eBitfieldInsert3U:
				case ast::expr::Intrinsic::eBitfieldInsert4U:
				case ast::expr::Intrinsic::eBitfieldReverse1I:
				case ast::expr::Intrinsic::eBitfieldReverse2I:
				case ast::expr::Intrinsic::eBitfieldReverse3I:
				case ast::expr::Intrinsic::eBitfieldReverse4I:
				case ast::expr::Intrinsic::eBitfieldReverse1U:
				case ast::expr::Intrinsic::eBitfieldReverse2U:
				case ast::expr::Intrinsic::eBitfieldReverse3U:
				case ast::expr::Intrinsic::eBitfieldReverse4U:
				case ast::expr::Intrinsic::eBitCount1I:
				case ast::expr::Intrinsic::eBitCount2I:
				case ast::expr::Intrinsic::eBitCount3I:
				case ast::expr::Intrinsic::eBitCount4I:
				case ast::expr::Intrinsic::eBitCount1U:
				case ast::expr::Intrinsic::eBitCount2U:
				case ast::expr::Intrinsic::eBitCount3U:
				case ast::expr::Intrinsic::eBitCount4U:
				case ast::expr::Intrinsic::eFindLSB1I:
				case ast::expr::Intrinsic::eFindLSB2I:
				case ast::expr::Intrinsic::eFindLSB3I:
				case ast::expr::Intrinsic::eFindLSB4I:
				case ast::expr::Intrinsic::eFindLSB1U:
				case ast::expr::Intrinsic::eFindLSB2U:
				case ast::expr::Intrinsic::eFindLSB3U:
				case ast::expr::Intrinsic::eFindLSB4U:
				case ast::expr::Intrinsic::eFindMSB1I:
				case ast::expr::Intrinsic::eFindMSB2I:
				case ast::expr::Intrinsic::eFindMSB3I:
				case ast::expr::Intrinsic::eFindMSB4I:
				case ast::expr::Intrinsic::eFindMSB1U:
				case ast::expr::Intrinsic::eFindMSB2U:
				case ast::expr::Intrinsic::eFindMSB3U:
				case ast::expr::Intrinsic::eFindMSB4U:
				case ast::expr::Intrinsic::eFrexp1F:
				case ast::expr::Intrinsic::eFrexp2F:
				case ast::expr::Intrinsic::eFrexp3F:
				case ast::expr::Intrinsic::eFrexp4F:
				case ast::expr::Intrinsic::eFrexp1D:
				case ast::expr::Intrinsic::eFrexp2D:
				case ast::expr::Intrinsic::eFrexp3D:
				case ast::expr::Intrinsic::eFrexp4D:
				case ast::expr::Intrinsic::eLdexp1F:
				case ast::expr::Intrinsic::eLdexp2F:
				case ast::expr::Intrinsic::eLdexp3F:
				case ast::expr::Intrinsic::eLdexp4F:
				case ast::expr::Intrinsic::eLdexp1D:
				case ast::expr::Intrinsic::eLdexp2D:
				case ast::expr::Intrinsic::eLdexp3D:
				case ast::expr::Intrinsic::eLdexp4D:
				case ast::expr::Intrinsic::ePackUnorm2x16:
				case ast::expr::Intrinsic::ePackSnorm4x8:
				case ast::expr::Intrinsic::ePackUnorm4x8:
				case ast::expr::Intrinsic::eUnpackUnorm2x16:
				case ast::expr::Intrinsic::eUnpackSnorm4x8:
				case ast::expr::Intrinsic::eUnpackUnorm4x8:
				case ast::expr::Intrinsic::eInterpolateAtCentroid1:
				case ast::expr::Intrinsic::eInterpolateAtCentroid2:
				case ast::expr::Intrinsic::eInterpolateAtCentroid3:
				case ast::expr::Intrinsic::eInterpolateAtCentroid4:
				case ast::expr::Intrinsic::eInterpolateAtSample1:
				case ast::expr::Intrinsic::eInterpolateAtSample2:
				case ast::expr::Intrinsic::eInterpolateAtSample3:
				case ast::expr::Intrinsic::eInterpolateAtSample4:
				case ast::expr::Intrinsic::eInterpolateAtOffset1:
				case ast::expr::Intrinsic::eInterpolateAtOffset2:
				case ast::expr::Intrinsic::eInterpolateAtOffset3:
				case ast::expr::Intrinsic::eInterpolateAtOffset4:
					m_config.requiredExtensions.insert( ARB_gpu_shader5 );
					break;
				case ast::expr::Intrinsic::ePackHalf2x16:
				case ast::expr::Intrinsic::ePackSnorm2x16:
				case ast::expr::Intrinsic::eUnpackHalf2x16:
				case ast::expr::Intrinsic::eUnpackSnorm2x16:
					m_config.requiredExtensions.insert( ARB_shading_language_packing );
					break;
				case ast::expr::Intrinsic::eAtomicAdd2H:
				case ast::expr::Intrinsic::eAtomicAdd4H:
				case ast::expr::Intrinsic::eAtomicExchange2H:
				case ast::expr::Intrinsic::eAtomicExchange4H:
					m_config.requiredExtensions.insert( NV_shader_atomic_fp16_vector );
					[[fallthrough]];
				case ast::expr::Intrinsic::eAtomicAddF:
				case ast::expr::Intrinsic::eAtomicExchangeF:
					m_config.requiredExtensions.insert( NV_shader_atomic_float );
					break;
				case ast::expr::Intrinsic::eTraceRay:
					m_config.requiresRayDescDecl = true;
					break;
				case ast::expr::Intrinsic::eHelperInvocation:
					break;
				default:
					break;
				}

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( *arg );
				}
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )override
			{
				checkType( expr->getType(), m_config );
				getGlslConfig( expr->getCombinedImageAccess(), m_config );

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( *arg );
				}
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )override
			{
				checkType( expr->getType(), m_config );

				if ( ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAdd1DF
					&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF )
					|| ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicExchange1DF
						&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF ) )
				{
					m_config.requiredExtensions.insert( NV_shader_atomic_float );

					for ( auto & arg : expr->getArgList() )
					{
						if ( ast::type::getComponentType( arg->getType() ) == ast::type::Kind::eHalf )
						{
							m_config.requiredExtensions.insert( NV_shader_atomic_fp16_vector );
						}
					}
				}
				else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageSize1DF
					&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageSize2DMSArrayU )
				{
					m_config.requiredExtensions.insert( ARB_shader_image_size );
				}

				for ( auto & arg : expr->getArgList() )
				{
					doSubmit( *arg );
				}
			}

			void visitIdentifierExpr( ast::expr::Identifier const * expr )override
			{
				checkType( expr->getType(), m_config );
				helpers::checkBuiltin( *expr->getVariable(), m_config );
			}

			void visitInitExpr( ast::expr::Init const * expr )override
			{
				checkType( expr->getType(), m_config );

				if ( expr->hasIdentifier() )
				{
					doSubmit( expr->getIdentifier() );
				}

				doSubmit( *expr->getInitialiser() );
			}

			void visitLiteralExpr( ast::expr::Literal const * expr )override
			{
				checkType( expr->getType(), m_config );
			}

			void visitQuestionExpr( ast::expr::Question const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getCtrlExpr() );
				doSubmit( *expr->getTrueExpr() );
				doSubmit( *expr->getFalseExpr() );
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getOperand() );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getLabel() );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getValue() );
			}

			void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
			{
				checkType( expr->getType(), m_config );
				doSubmit( *expr->getOuterExpr() );
			}

		private:
			IntrinsicsConfig & m_config;
		};

		class StmtConfigFiller
			: public ast::stmt::Visitor
		{
		public:
			static IntrinsicsConfig submit( ast::ShaderStage stage
				, ast::stmt::Container const & container )
			{
				IntrinsicsConfig result{ stage };

				if ( isRayTraceStage( stage ) )
				{
					result.requiredExtensions.insert( EXT_ray_tracing );
				}

				if ( isMeshNVStage( stage ) )
				{
					result.requiredExtensions.insert( NV_mesh_shader );
				}
				else if ( isMeshStage( stage ) )
				{
					result.requiredExtensions.insert( EXT_mesh_shader );
				}

				StmtConfigFiller vis{ result };
				container.accept( &vis );
				return result;
			}

		private:
			explicit StmtConfigFiller( IntrinsicsConfig & result )
				: m_result{ result }
			{
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl const * stmt )override
			{
				checkType( stmt->getType(), m_result );
				m_result.requiredExtensions.insert( EXT_buffer_reference2 );
				m_result.requiredExtensions.insert( EXT_scalar_block_layout );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitContainerStmt( ast::stmt::Container const * cont )override
			{
				for ( auto & stmt : *cont )
				{
					stmt->accept( this );
				}
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitCompoundStmt( ast::stmt::Compound const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile const * stmt )override
			{
				ExprConfigFiller::submit( *stmt->getCtrlExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				ExprConfigFiller::submit( *stmt->getCtrlExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitForStmt( ast::stmt::For const * stmt )override
			{
				ExprConfigFiller::submit( *stmt->getInitExpr(), m_result );
				ExprConfigFiller::submit( *stmt->getCtrlExpr(), m_result );
				ExprConfigFiller::submit( *stmt->getIncrExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );

				if ( stmt->getBlendIndex() )
				{
					m_result.requiresBlendIndex = true;
				}
			}

			void visitIfStmt( ast::stmt::If const * stmt )override
			{
				ExprConfigFiller::submit( *stmt->getCtrlExpr(), m_result );
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

			void visitImageDeclStmt( ast::stmt::ImageDecl const * stmt )override
			{
				m_result.requiredExtensions.insert( ARB_shader_image_load_store );
				auto image = std::static_pointer_cast< ast::type::Image >( stmt->getVariable()->getType() );
				doParseImageConfig( image->getConfig() );
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitReturnStmt( ast::stmt::Return const * stmt )override
			{
				if ( auto expr = stmt->getExpr() )
				{
					ExprConfigFiller::submit( *expr, m_result );
				}
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl const * stmt )override
			{
				auto image = std::static_pointer_cast< ast::type::CombinedImage >( ast::type::getNonArrayTypeRec( stmt->getVariable()->getType() ) );
				doParseImageConfig( image->getConfig() );
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl const * stmt )override
			{
				m_result.requiredExtensions.insert( KHR_vulkan_glsl );
				m_result.requiresSeparateSamplers = true;
				auto image = std::static_pointer_cast< ast::type::SampledImage >( ast::type::getNonArrayTypeRec( stmt->getVariable()->getType() ) );
				doParseImageConfig( image->getConfig() );
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl const * stmt )override
			{
				m_result.requiredExtensions.insert( KHR_vulkan_glsl );
				m_result.requiresSeparateSamplers = true;
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl const * stmt )override
			{
				m_result.requiredExtensions.insert( ARB_shader_storage_buffer_object );

				if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eScalar )
				{
					m_result.requiredExtensions.insert( EXT_scalar_block_layout );
				}

				visitContainerStmt( stmt );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl const * stmt )override
			{
				if ( stmt->getMemoryLayout() == ast::type::MemoryLayout::eScalar )
				{
					m_result.requiredExtensions.insert( EXT_scalar_block_layout );
				}

				m_result.requiredExtensions.insert( ARB_shader_storage_buffer_object );

				for ( auto & type : static_cast< ast::type::Struct const & >( *stmt->getSsboInstance()->getType() ) )
				{
					checkType( type.type, m_result );
				}
			}

			void visitSimpleStmt( ast::stmt::Simple const * stmt )override
			{
				ExprConfigFiller::submit( *stmt->getExpr(), m_result );
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl const * stmt )override
			{
				for ( auto & type : *stmt->getType() )
				{
					checkType( type.type, m_result );
				}
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase const * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitSwitchStmt( ast::stmt::Switch const * stmt )override
			{
				ExprConfigFiller::submit( *stmt->getTestExpr()->getValue(), m_result );
				visitContainerStmt( stmt );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl const * stmt )override
			{
				checkType( stmt->getVariable()->getType(), m_result );
			}

			void visitWhileStmt( ast::stmt::While const * stmt )override
			{
				ExprConfigFiller::submit( *stmt->getCtrlExpr(), m_result );
				visitContainerStmt( stmt );
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl const * stmt )override
			{
			}

			void visitBreakStmt( ast::stmt::Break const * stmt )override
			{
			}

			void visitContinueStmt( ast::stmt::Continue const * stmt )override
			{
			}

			void visitDemoteStmt( ast::stmt::Demote const * stmt )override
			{
				m_result.requiredExtensions.insert( EXT_demote_to_helper_invocation );
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh const * stmt )override
			{
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation const * stmt )override
			{
			}

			void visitCommentStmt( ast::stmt::Comment const * stmt )override
			{
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout const * stmt )override
			{
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection const * stmt )override
			{
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout const * stmt )override
			{
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout const * stmt )override
			{
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout const * stmt )override
			{
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout const * stmt )override
			{
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout const * stmt )override
			{
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout const * stmt )override
			{
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl const * stmt )override
			{
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl const * stmt )override
			{
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay const * stmt )override
			{
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension const * preproc )override
			{
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion const * preproc )override
			{
			}

			void doParseImageConfig( ast::type::ImageConfiguration const & config )
			{
				if ( config.dimension == ast::type::ImageDim::eCube
					&& config.isArrayed )
				{
					m_result.requiredExtensions.insert( ARB_texture_cube_map_array );
				}
			}

		private:
			IntrinsicsConfig & m_result;
		};
	}

	IntrinsicsConfig fillConfig( ast::ShaderStage stage
		, ast::stmt::Container const & container )
	{
		return config::StmtConfigFiller::submit( stage, container );
	}

	void checkConfig( StmtConfig & writerConfig
		, IntrinsicsConfig & intrinsicsConfig )
	{
		if ( writerConfig.wantedVersion >= v4_6 )
		{
			writerConfig.availableExtensions.insert( KHR_vulkan_glsl );
			intrinsicsConfig.requiredExtensions.insert( KHR_vulkan_glsl );
		}

		if ( intrinsicsConfig.requiresSeparateSamplers )
		{
			if ( ( !writerConfig.vulkanGlsl )
				|| !writerConfig.availableExtensions.contains( KHR_vulkan_glsl ) )
			{
				throw ast::Exception{ "Separate Samplers are only supported with extension [" + KHR_vulkan_glsl.name + "] which is not available" };
			}

			writerConfig.requiredExtensions.insert( EXT_separate_samplers );
			writerConfig.availableExtensions.insert( EXT_separate_samplers );
		}

		if ( writerConfig.shaderStage == ast::ShaderStage::eTessellationControl
			|| writerConfig.shaderStage == ast::ShaderStage::eTessellationEvaluation )
		{
			intrinsicsConfig.requiredExtensions.insert( ARB_tessellation_shader );
		}

		if ( writerConfig.wantedVersion >= ARB_explicit_attrib_location.specVersion )
		{
			writerConfig.availableExtensions.insert( ARB_explicit_attrib_location );
			intrinsicsConfig.requiredExtensions.insert( ARB_explicit_attrib_location );
		}

		if ( writerConfig.wantedVersion >= ARB_explicit_uniform_location.specVersion )
		{
			writerConfig.availableExtensions.insert( ARB_explicit_uniform_location );
			intrinsicsConfig.requiredExtensions.insert( ARB_explicit_uniform_location );
		}

		if ( writerConfig.wantedVersion >= ARB_separate_shader_objects.specVersion )
		{
			writerConfig.availableExtensions.insert( ARB_separate_shader_objects );
			intrinsicsConfig.requiredExtensions.insert( ARB_separate_shader_objects );
		}

		if ( intrinsicsConfig.requiresBlendIndex
			&& ( writerConfig.wantedVersion < v4_3
				|| ( !writerConfig.availableExtensions.contains( ARB_explicit_attrib_location )
					&& !writerConfig.availableExtensions.contains( ARB_separate_shader_objects ) ) ) )
		{
			throw ast::Exception{ "GLSL specification version (" + writeValue( writerConfig.wantedVersion )
				+ ") doesn't support blend index attributes (required version: " + writeValue( v4_3 ) +
				+" or extension [" + ARB_explicit_attrib_location.name + "])" };
		}

		if ( writerConfig.wantedVersion >= ARB_shading_language_420pack.coreVersion )
		{
			writerConfig.availableExtensions.insert( ARB_shading_language_420pack );
		}

		if ( writerConfig.wantedVersion >= KHR_vulkan_glsl.specVersion
			&& writerConfig.vulkanGlsl )
		{
			writerConfig.availableExtensions.insert( KHR_vulkan_glsl );
			intrinsicsConfig.requiredExtensions.insert( KHR_vulkan_glsl );
		}

		if ( intrinsicsConfig.requiresInt8 )
		{
			if ( writerConfig.availableExtensions.contains( NV_gpu_shader5 ) )
			{
				intrinsicsConfig.requiredExtensions.insert( NV_gpu_shader5 );
			}
			else if ( writerConfig.availableExtensions.contains( EXT_shader_explicit_arithmetic_types_int8 ) )
			{
				intrinsicsConfig.requiredExtensions.insert( EXT_shader_explicit_arithmetic_types_int8 );
			}
			else
			{
				throw ast::Exception{ "int8_t and uint8_t need either of [" + EXT_shader_explicit_arithmetic_types_int8.name
					+ "] or [" + NV_gpu_shader5.name + "]" };
			}
		}

		if ( intrinsicsConfig.requiresInt16 )
		{
			if ( writerConfig.availableExtensions.contains( NV_gpu_shader5 ) )
			{
				intrinsicsConfig.requiredExtensions.insert( NV_gpu_shader5 );
			}
			else if ( writerConfig.availableExtensions.contains( EXT_shader_explicit_arithmetic_types_int16 ) )
			{
				intrinsicsConfig.requiredExtensions.insert( EXT_shader_explicit_arithmetic_types_int16 );
			}
			else
			{
				throw ast::Exception{ "int16_t and uint16_t need either of [" + EXT_shader_explicit_arithmetic_types_int16.name
					+ "] or [" + NV_gpu_shader5.name + "]" };
			}
		}

		if ( intrinsicsConfig.requiresInt64 )
		{
			if ( writerConfig.availableExtensions.contains( ARB_gpu_shader_int64 ) )
			{
				intrinsicsConfig.requiredExtensions.insert( ARB_gpu_shader_int64 );
			}
			else if ( writerConfig.availableExtensions.contains( NV_gpu_shader5 ) )
			{
				intrinsicsConfig.requiredExtensions.insert( NV_gpu_shader5 );
			}
			else if ( writerConfig.availableExtensions.contains( EXT_shader_explicit_arithmetic_types_int64 ) )
			{
				intrinsicsConfig.requiredExtensions.insert( EXT_shader_explicit_arithmetic_types_int64 );
			}
			else
			{
				throw ast::Exception{ "int64_t and uint64_t need either of [" + EXT_shader_explicit_arithmetic_types_int16.name
					+ "] or [" + ARB_gpu_shader_int64.name + "]"
					+ "] or [" + NV_gpu_shader5.name + "]" };
			}
		}

		for ( auto & extension : intrinsicsConfig.requiredExtensions )
		{
			if ( extension.reqVersion > writerConfig.wantedVersion )
			{
				throw ast::Exception{ "GLSL specification version (" + writeValue( writerConfig.wantedVersion )
					+ ") doesn't support extension [" + extension.name
					+ "] (required version: " + writeValue( extension.reqVersion ) + ")" };
			}
		}
	}
}
