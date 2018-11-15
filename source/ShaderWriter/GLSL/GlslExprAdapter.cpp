/*
See LICENSE file in root folder
*/
#include "ShaderWriter/GLSL/GlslExprAdapter.hpp"

#include "ShaderWriter/GLSL/GlslHelpers.hpp"
#include "ShaderWriter/GLSL/GlslTextureAccessConfig.hpp"

#include "ShaderWriter/Intrinsics.hpp"

#include <ASTGenerator/Type/TypeImage.hpp>
#include <ASTGenerator/Type/TypeSampledImage.hpp>

namespace sdw::glsl
{
	namespace
	{
		expr::ExprPtr swizzleConvert( type::TypePtr dst
			, type::TypePtr src
			, expr::ExprPtr expr )
		{
			expr::SwizzleKind swizzle;
			auto srcCount = getComponentCount( src->getKind() );
			auto dstCount = getComponentCount( dst->getKind() );

			switch ( srcCount )
			{
			case 1:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e00;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e000;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0000;
					break;
				}
				break;
			case 2:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e011;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0111;
					break;
				}
				break;
			case 3:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0122;
					break;
				}
				break;
			case 4:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0123;
					break;
				}
				break;
			}

			return std::make_unique< expr::Swizzle >( std::move( expr )
				, swizzle );
		}
	}
	expr::ExprPtr ExprAdapter::submit( expr::Expr * expr
		, IntrinsicsConfig const & config )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, config };
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr ExprAdapter::submit( expr::ExprPtr const & expr
		, IntrinsicsConfig const & config )
	{
		return submit( expr.get()
			, config );
	}

	ExprAdapter::ExprAdapter( expr::ExprPtr & result
		, IntrinsicsConfig const & config )
		: ExprCloner{ result }
		, m_config{ config }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprAdapter vis{ result, m_config };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitImageAccessCallExpr( expr::ImageAccessCall * expr )
	{
		if ( expr->getImageAccess() >= expr::ImageAccess::eImageLoad1DF
			&& expr->getImageAccess() <= expr::ImageAccess::eImageLoad2DMSArrayU )
		{
			doProcessImageLoad( expr );
		}
		else
		{
			expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = expr::makeImageAccessCall( expr->getType()
				, expr->getImageAccess()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		if ( expr->getTextureAccess() >= expr::TextureAccess::eTexture1DShadowF
			&& expr->getTextureAccess() <= expr::TextureAccess::eTextureProjGradOffset2DRectShadowF )
		{
			doProcessTextureShadow( expr );
		}
		else if ( expr->getTextureAccess() >= expr::TextureAccess::eTexture1DF
			&& expr->getTextureAccess() <= expr::TextureAccess::eTextureProjGradOffset2DRectU4 )
		{
			doProcessTextureSample( expr );
		}
		else if ( expr->getTextureAccess() >= expr::TextureAccess::eTextureGather2DF
			&& expr->getTextureAccess() <= expr::TextureAccess::eTextureGatherOffsets2DRectUComp )
		{
			doProcessTextureGather( expr );
		}
		else
		{
			expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = expr::makeTextureAccessCall( expr->getType()
				, expr->getTextureAccess()
				, std::move( args ) );
		}
	}

	void ExprAdapter::doProcessImageLoad( expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = getType( config.format );
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = expr::makeImageAccessCall( expr->getType()
			, expr->getImageAccess()
			, std::move( args ) );

		auto glslRetType = type::getVec4Type( getScalarType( callRetType->getKind() ) );

		if ( callRetType != glslRetType )
		{
			m_result = swizzleConvert( callRetType, glslRetType, std::move( m_result ) );
		}
	}

	void ExprAdapter::doProcessTextureShadow( expr::TextureAccessCall * expr )
	{
		expr::ExprList args;
		// First parameter is the sampled image
		args.emplace_back( doSubmit( expr->getArgList()[0].get() ) );
		// For texture shadow functions, dref value is put inside the coords parameter, instead of being aside.
		assert( expr->getArgList().size() >= 3u );
		// Merge second and third parameters to the appropriate vector type (float=>vec2, vec2=>vec3, vec3=>vec4).
		expr::ExprList merged;
		merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
		merged.emplace_back( doSubmit( expr->getArgList()[2].get() ) );

		switch ( merged[0]->getType()->getKind() )
		{
		case type::Kind::eFloat:
			args.emplace_back( sdw::makeCompositeCtor( expr::CompositeType::eVec2
				, type::Kind::eFloat
				, std::move( merged ) ) );
			break;
		case type::Kind::eVec2F:
			args.emplace_back( sdw::makeCompositeCtor( expr::CompositeType::eVec3
				, type::Kind::eFloat
				, std::move( merged ) ) );
			break;
		case type::Kind::eVec3F:
			args.emplace_back( sdw::makeCompositeCtor( expr::CompositeType::eVec4
				, type::Kind::eFloat
				, std::move( merged ) ) );
			break;
		case type::Kind::eVec4F:
			// If the first type was a vec4, forget about merging
			args.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
			args.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
			break;
		}

		// Other parameters remain unchanged.
		for ( size_t i = 3u; i < expr->getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( expr->getArgList()[i].get() ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureSample( expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = getType( config.format );
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );

		auto glslRetType = type::getVec4Type( getScalarType( callRetType->getKind() ) );

		if ( callRetType != glslRetType )
		{
			m_result = swizzleConvert( callRetType, glslRetType, std::move( m_result ) );
		}
	}

	void ExprAdapter::doProcessTextureGather( expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			args.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}
}
