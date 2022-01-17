/*
See LICENSE file in root folder
*/
#include "GlslExprAdapter.hpp"

#include "GlslHelpers.hpp"
#include "GlslTextureAccessConfig.hpp"

#include <ShaderAST/Expr/MakeIntrinsic.hpp>
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

		ast::expr::ExprPtr registerPerVertexBuiltin( ast::type::TypesCache & cache
			, ast::Builtin builtin
			, ast::type::TypePtr type
			, uint64_t flags
			, uint32_t & nextVarId
			, IOVars & io )
		{
			auto ires = io.perVertexMbrs.emplace( builtin, nullptr );

			if ( ires.second )
			{
				ires.first->second = ast::expr::makeIdentifier( cache
					, ast::var::makeVariable( { ++nextVarId, "gl_" + getName( builtin ) }
						, type
						, flags | ast::var::Flag::eBuiltin ) );
			}

			auto it = ires.first;
			return ast::ExprCloner::submit( it->second.get() );
		}
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::Expr * expr
		, AdaptationData & adaptationData )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ cache, adaptationData, result };
		expr->accept( &vis );
		return result;
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::ExprPtr const & expr
		, AdaptationData & adaptationData )
	{
		return submit( cache, expr.get(), adaptationData );
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, AdaptationData & adaptationData
		, ast::expr::ExprPtr & result )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_adaptationData{ adaptationData }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ m_cache, m_adaptationData, result };
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageStore1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageStore2DMSArrayU )
		{
			doProcessImageStore( expr );
		}
		else
		{
			ExprCloner::visitImageAccessCallExpr( expr );
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		if ( expr->getIntrinsic() >= ast::expr::Intrinsic::eFma1F
			&& expr->getIntrinsic() <= ast::expr::Intrinsic::eFma4D
			&& m_adaptationData.writerConfig.shaderLanguageVersion < 430 )
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

	void ExprAdapter::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		m_result = doProcessMbr( expr->getOuterExpr()
			, expr->getMemberIndex()
			, expr->getMemberFlags() );

		if ( !m_result )
		{
			ExprCloner::visitMbrSelectExpr( expr );
		}
	}

	void ExprAdapter::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		m_result = ast::expr::makeEmitVertex( m_cache );
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
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureGatherOffsets2DRectU )
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

		// Component parameter is the last one in GLSL whilst it is the last before
		// optional ones in SPIR-V, hence we move it to the right place.
		// 0->img, 1->coord, 2->component
		auto it = args.begin() + 2u;
		auto compArg = std::move( *it );
		args.erase( it );
		args.emplace_back( std::move( compArg ) );

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	ast::expr::ExprPtr ExprAdapter::doProcessIOMbr( ast::expr::Expr * outer
		, uint32_t mbrIndex
		, uint64_t mbrFlags
		, bool isInput
		, IOVars & io )
	{
		assert( isStructType( outer->getType() ) );
		auto structType = getStructType( outer->getType() );
		auto & mbr = *std::next( structType->begin(), ptrdiff_t( mbrIndex ) );
		auto compType = getComponentType( mbr.type );

		if ( ( m_adaptationData.writerConfig.shaderStage != ast::ShaderStage::eVertex
				|| !isInput )
			&& ( isUnsignedIntType( compType )
				|| isSignedIntType( compType ) ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eFlat;
		}

		ast::expr::ExprPtr result;

		if ( isPerVertex( mbr.builtin, m_adaptationData.writerConfig.shaderStage ) )
		{
			ast::expr::ExprPtr indexExpr{};

			if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
			{
				auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
				outer = arrayAccess.getLHS();

				if ( outer->getKind() == ast::expr::Kind::eIdentifier
					&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
				{
					indexExpr = doSubmit( arrayAccess.getRHS() );
				}
			}

			if ( outer->getKind() == ast::expr::Kind::eIdentifier
				&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
			{
				if ( indexExpr )
				{
					auto type = getNonArrayType( io.perVertex->getType() );
					assert( isStructType( type ) );
					auto perVertexType = getStructType( type );
					mbrIndex = perVertexType->findMember( mbr.builtin );
					assert( mbrIndex != ast::type::Struct::NotFound );
					result = ast::expr::makeArrayAccess( perVertexType
						, ast::expr::makeIdentifier( m_cache, io.perVertex )
						, std::move( indexExpr ) );
					result = ast::expr::makeMbrSelect( std::move( result )
						, mbrIndex
						, mbrFlags | ast::var::Flag::eBuiltin );
				}
				else
				{
					result = registerPerVertexBuiltin( m_cache
						, mbr.builtin
						, mbr.type
						, mbrFlags
						, m_adaptationData.nextVarId
						, io );
				}
			}
		}
		else if ( mbr.builtin != ast::Builtin::eNone )
		{
			auto it = io.vars.find( structType );

			if ( it == io.vars.end() )
			{
				auto structIt = io.builtinsStructs.find( structType );

				if ( structIt != io.builtinsStructs.end() )
				{
					it = io.vars.find( structIt->second.first );
					mbrIndex -= structIt->second.second;
				}
			}

			if ( it != io.vars.end() )
			{
				auto mbrIt = std::find_if( it->second.begin()
					, it->second.end()
					, [&mbr]( ast::var::VariablePtr const & lookup )
					{
						return lookup->getName() == mbr.name
							|| lookup->getName() == "gl_" + mbr.name;
					} );
				assert( mbrIt != it->second.end() );
				result = ast::expr::makeIdentifier( m_cache
					, *mbrIt );
			}
		}
		else
		{
			ast::expr::ExprPtr indexExpr{};

			if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
			{
				auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
				outer = arrayAccess.getLHS();

				if ( outer->getKind() == ast::expr::Kind::eIdentifier
					&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
				{
					indexExpr = doSubmit( arrayAccess.getRHS() );
				}
			}
			else if ( outer->getType()->getKind() == ast::type::Kind::eTessellationControlOutput )
			{
				indexExpr = registerPerVertexBuiltin( m_cache
					, ast::Builtin::eInvocationID
					, m_cache.getUInt32()
					, uint64_t( ast::var::Flag::eShaderInput )
					, m_adaptationData.nextVarId
					, io );
			}

			if ( outer->getKind() == ast::expr::Kind::eIdentifier
				&& io.isMainVar( static_cast< ast::expr::Identifier const & >( *outer ).getVariable() ) )
			{
				auto it = io.vars.find( structType );

				if ( it == io.vars.end() )
				{
					auto structIt = io.othersStructs.find( structType );

					if ( structIt != io.othersStructs.end() )
					{
						return ast::expr::makeMbrSelect( ast::expr::makeIdentifier( m_cache, structIt->second )
							, mbrIndex
							, mbrFlags );
					}
				}

				assert( it != io.vars.end() );
				auto mbrIt = std::find_if( it->second.begin()
					, it->second.end()
					, [&mbr]( ast::var::VariablePtr const & lookup )
					{
						return lookup->getName() == mbr.name
							|| ( !lookup->isBuiltin()
								&& ( lookup->getName() == "sdwIn_" + mbr.name
									|| lookup->getName() == "sdwOut_" + mbr.name ) )
							|| ( lookup->isBuiltin()
								&& lookup->getName() == "gl_" + mbr.name );
					} );
				assert( mbrIt != it->second.end() );
				result = ast::expr::makeIdentifier( m_cache
					, *mbrIt );

				if ( indexExpr )
				{
					result = ast::expr::makeArrayAccess( mbr.type
						, std::move( result )
						, std::move( indexExpr ) );
				}
			}
		}

		return result;
	}

	ast::expr::ExprPtr ExprAdapter::doProcessMbr( ast::expr::Expr * outer
		, uint32_t mbrIndex
		, uint64_t mbrFlags )
	{
		auto result = doProcessIOMbr( outer, mbrIndex, mbrFlags, true, m_adaptationData.inputs );

		if ( !result )
		{
			result = doProcessIOMbr( outer, mbrIndex, mbrFlags, false, m_adaptationData.outputs );
		}

		return result;
	}
}
