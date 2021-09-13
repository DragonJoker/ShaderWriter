/*
See LICENSE file in root folder
*/
#include "GlslExprAdapter.hpp"

#include "GlslHelpers.hpp"
#include "GlslTextureAccessConfig.hpp"

#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

namespace glsl
{
	namespace
	{
		ast::expr::ExprPtr swizzleConvert( ast::type::TypePtr dst
			, ast::type::TypePtr src
			, ast::expr::ExprPtr expr )
		{
			ast::expr::SwizzleKind swizzle;
			auto srcCount = getComponentCount( src->getKind() );
			auto dstCount = getComponentCount( dst->getKind() );

			switch ( srcCount )
			{
			case 1:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e00;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e000;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0000;
					break;
				}
				break;
			case 2:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e011;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0111;
					break;
				}
				break;
			case 3:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0122;
					break;
				}
				break;
			case 4:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0123;
					break;
				}
				break;
			}

			return std::make_unique< ast::expr::Swizzle >( std::move( expr )
				, swizzle );
		}
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::Expr * expr
		, GlslConfig const & writerConfig
		, IntrinsicsConfig const & intrinsicsConfig )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis
		{
			cache,
			writerConfig,
			intrinsicsConfig,
			result,
		};
		expr->accept( &vis );
		return result;
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::ExprPtr const & expr
		, GlslConfig const & writerConfig
		, IntrinsicsConfig const & intrinsicsConfig )
	{
		return submit( cache
			, expr.get()
			, writerConfig
			, intrinsicsConfig );
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, GlslConfig const & writerConfig
		, IntrinsicsConfig const & intrinsicsConfig
		, ast::expr::ExprPtr & result )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_writerConfig{ writerConfig }
		, m_intrinsicsConfig{ intrinsicsConfig }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis
		{
			m_cache,
			m_writerConfig,
			m_intrinsicsConfig,
			result,
		};
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageLoad1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageLoad2DMSArrayU )
		{
			doProcessImageLoad( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageStore1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageStore2DMSArrayU )
		{
			doProcessImageStore( expr );
		}
		else
		{
			doProcessImageAccessCall( expr );
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eFma1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eFma4D
			&& m_writerConfig.shaderLanguageVersion < 430 )
		{
			assert( expr->getArgList().size() == 3u );
			m_result = ast::expr::makeAdd( expr->getType()
				, ast::expr::makeTimes( expr->getType()
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) )
				, doSubmit( expr->getArgList()[2].get() ) );
		}
		else
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = ast::expr::makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTexture1DShadowF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF )
		{
			doProcessTextureShadow( expr );
		}
		else if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTexture1DF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4 )
		{
			doProcessTextureSample( expr );
		}
		else if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureGather2DF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp )
		{
			doProcessTextureGather( expr );
		}
		else
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = ast::expr::makeTextureAccessCall( expr->getType()
				, expr->getTextureAccess()
				, std::move( args ) );
		}
	}

	void ExprAdapter::doProcessImageLoad( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = m_cache.getSampledType( config.format );
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		auto glslRetType = m_cache.getVec4Type( getScalarType( callRetType->getKind() ) );
		m_result = ast::expr::makeImageAccessCall( glslRetType
			, expr->getImageAccess()
			, std::move( args ) );

		if ( callRetType != glslRetType )
		{
			m_result = swizzleConvert( callRetType, glslRetType, std::move( m_result ) );
		}

		if ( callRetType != expr->getType() )
		{
			m_result = ast::expr::makeCast( expr->getType(), std::move( m_result ) );
		}
	}

	void ExprAdapter::doProcessImageStore( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto sampledType = m_cache.getSampledType( config.format );
		auto glslType = m_cache.getVec4Type( getScalarType( sampledType->getKind() ) );
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			if ( arg != expr->getArgList().back() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}
			else
			{
				// Convert last parameter to appropriate gvec4 type.
				auto result = doSubmit( arg.get() );

				if ( sampledType != glslType )
				{
					result = ( ( getComponentCount( *sampledType ) == 1u )
						? [&glslType, &result]()
						{
							ast::expr::ExprList list;
							list.emplace_back( std::move( result ) );
							return ast::expr::makeCompositeConstruct( getCompositeType( glslType->getKind() )
								, getComponentType( *glslType )
								, std::move( list ) );
						}()
						: swizzleConvert( glslType, sampledType, std::move( result ) ) );
				}

				args.emplace_back( std::move( result ) );
			}
		}

		m_result = ast::expr::makeImageAccessCall( expr->getType()
			, expr->getImageAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessImageAccessCall( ast::expr::ImageAccessCall * expr )
	{
		// imageSize.
		// imageSamples.
		// imageAtomics except imageAtomicAdd.
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeImageAccessCall( expr->getType()
			, expr->getImageAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureShadow( ast::expr::TextureAccessCall * expr )
	{
		ast::expr::ExprList args;
		// First parameter is the sampled image
		args.emplace_back( doSubmit( expr->getArgList()[0].get() ) );
		// For texture shadow functions, dref value is put inside the coords parameter, instead of being aside.
		assert( expr->getArgList().size() >= 3u );
		
		if ( expr->getTextureAccess() == ast::expr::TextureAccess::eTexture1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexture1DShadowFBias
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProj1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProj1DShadowFBias
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureLod1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureOffset1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureOffset1DShadowFBias
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProjOffset1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureLodOffset1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProjLod1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureGrad1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureGradOffset1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProjGrad1DShadowF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF )
		{
			ast::expr::ExprList merged;

			switch ( expr->getArgList()[1]->getType()->getKind() )
			{
			case ast::type::Kind::eFloat:
				// Texture1DShadow accesses.
				// Merge second and third parameters to the appropriate vector type (float=>vec2, vec2=>vec3, vec3=>vec4).
				merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				merged.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec3
					, ast::type::Kind::eFloat
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec2F:
				{
					// TextureProj1DShadow accesses.
					merged.emplace_back( ast::expr::makeSwizzle( doSubmit( expr->getArgList()[1].get() ), ast::expr::SwizzleKind::e0 ) );
					merged.emplace_back( ast::expr::makeSwizzle( doSubmit( expr->getArgList()[1].get() ), ast::expr::SwizzleKind::e0 ) );
					merged.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
					merged.emplace_back( ast::expr::makeSwizzle( doSubmit( expr->getArgList()[1].get() ), ast::expr::SwizzleKind::e1 ) );
					args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec4
						, ast::type::Kind::eFloat
						, std::move( merged ) ) );
				}
				break;
			case ast::type::Kind::eVec3F:
				merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				merged.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec4
					, ast::type::Kind::eFloat
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec4F:
				// If the first type was a vec4, forget about merging
				args.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				args.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
				break;
			default:
				break;
			}
		}
		else
		{
			// Merge second and third parameters to the appropriate vector type (float=>vec2, vec2=>vec3, vec3=>vec4).
			ast::expr::ExprList merged;
			merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
			merged.emplace_back( doSubmit( expr->getArgList()[2].get() ) );

			switch ( merged[0]->getType()->getKind() )
			{
			case ast::type::Kind::eFloat:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec2
					, ast::type::Kind::eFloat
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec2F:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec3
					, ast::type::Kind::eFloat
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec3F:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec4
					, ast::type::Kind::eFloat
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec4F:
				// If the first type was a vec4, forget about merging
				args.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				args.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
				break;
			default:
				break;
			}
		}

		// Other parameters remain unchanged.
		for ( size_t i = 3u; i < expr->getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( expr->getArgList()[i].get() ) );
		}

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureSample( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = m_cache.getSampledType( config.format );
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );

		auto glslRetType = m_cache.getVec4Type( getScalarType( callRetType->getKind() ) );

		if ( callRetType != glslRetType )
		{
			m_result = swizzleConvert( callRetType, glslRetType, std::move( m_result ) );
		}
	}

	void ExprAdapter::doProcessTextureGather( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}
}
