/*
See LICENSE file in root folder
*/
#include "SpirvStmtRegister.hpp"

#include "SpirvHelpers.hpp"
#include "SpirvGetSwizzleComponents.hpp"
#include "SpirvTextureAccessConfig.hpp"
#include "SpirvTextureAccessNames.hpp"
#include "SpirvMakeAccessChain.hpp"

#include <ShaderAST/Visitors/CloneExpr.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <sstream>
#include <stdexcept>

namespace spirv
{
	namespace
	{
		IdList getDecorations( uint32_t binding
			, uint32_t set
			, bool isBufferBlock = false )
		{
			IdList result
			{
				spv::Id( spv::DecorationBinding ), binding,
				spv::Id( spv::DecorationDescriptorSet ), set
			};

			if ( isBufferBlock )
			{
				result.push_back( spv::DecorationBufferBlock );
			}

			return result;

		}

		IdList getDecorations( bool isShaderConstant
			, bool isFlat
			, uint32_t location )
		{
			IdList result;

			if ( isShaderConstant )
			{
				result.emplace_back( spv::Id( spv::DecorationSpecId ) );
			}
			else
			{
				result.emplace_back( spv::Id( spv::DecorationLocation ) );
			}

			result.emplace_back( location );

			if ( isFlat )
			{
				result.emplace_back( spv::Id( spv::DecorationFlat ) );
			}

			return result;
		}

		IdList getDecorations( uint32_t location )
		{
			return { spv::Id( spv::DecorationSpecId ), location };
		}

		ast::var::VariablePtr makeVar( ast::type::TypesCache & cache
			, std::string name
			, ast::type::MemoryLayout layout )
		{
			auto type = cache.getStruct( layout, name );
			assert( type != nullptr );
			return ast::var::makeVariable( type, name );
		}

		ast::expr::CompositeType getCompositeType( uint32_t count )
		{
			using ast::expr::CompositeType;
			CompositeType result = CompositeType::eScalar;

			switch ( count )
			{
			case 2:
				result = CompositeType::eVec2;
				break;
			case 3:
				result = CompositeType::eVec3;
				break;
			case 4:
				result = CompositeType::eVec4;
				break;
			}

			return result;
		}
	}

	//*************************************************************************

	StmtRegister::ModuleStructBuilder::ModuleStructBuilder( ast::stmt::ContainerPtr & result
		, ModuleStruct & moduleStruct
		, ast::type::TypesCache & cache
		, uint32_t & currentId )
		: m_moduleStruct{ moduleStruct }
		, m_currentId{ &currentId }
	{
		m_currentBlock = moduleStruct.globalScope.get();
		doUpdateVars( m_currentBlock->allVars );
	}

	uint32_t StmtRegister::ModuleStructBuilder::getNextId()
	{
		auto result = *m_currentId;
		++*m_currentId;
		return result;
	}

	void StmtRegister::ModuleStructBuilder::beginBlock( BlockType type )
	{
		++scopeCurrentLevel;
		auto ires = m_moduleStruct.functionScopes.emplace( getNextId()
			, std::make_unique< BlockStruct >( type ) );
		m_currentBlock = ires.first->second.get();
		doUpdateVars( m_currentBlock->allVars );
		m_allVars = m_currentBlock->allVars;
	}

	void StmtRegister::ModuleStructBuilder::endBlock()
	{
		--scopeCurrentLevel;
	}

	void StmtRegister::ModuleStructBuilder::registerType( ast::type::TypePtr type )
	{
		m_moduleStruct.types.emplace( getNextId()
			, std::move( type ) );
	}

	void StmtRegister::ModuleStructBuilder::registerVar( VariablePtr var )
	{
		auto it = std::find_if( m_allVars->begin()
			, m_allVars->end()
			, [&var]( VariablePtr const & lookup )
			{
				return var->var == lookup->var
					&& var->decorations == lookup->decorations;
			} );

		if ( it == m_allVars->end() )
		{
			m_allVars->push_back( var );
			it = m_allVars->begin() + ptrdiff_t( m_allVars->size() - 1u );

			if ( var->var->isMember() )
			{
				auto outer = var->var->getOuter();
				it = std::find_if( m_allVars->begin()
					, m_allVars->end()
					, [&outer, &var]( VariablePtr const & lookup )
					{
						return outer == lookup->var
							&& var->decorations == lookup->decorations;
					} );

				if ( it == m_allVars->end() )
				{
					registerVar( std::make_shared< Variable >( outer, var->decorations ) );
				}
			}

			doRegisterVar( std::move( var ) );
		}
	}

	void StmtRegister::ModuleStructBuilder::registerUsage( VarUsage usage )
	{
		for ( auto & use : usage.use )
		{
			doRegisterUse( use );
		}

		m_currentBlock->usages.emplace_back( std::move( usage ) );
	}

	void StmtRegister::ModuleStructBuilder::registerUsages( VarUsageArray usages )
	{
		for ( auto usage : usages )
		{
			registerUsage( usage );
		}
	}

	void StmtRegister::ModuleStructBuilder::registerBlockStruct( VarUsageArray blockVars )
	{
	}

	void StmtRegister::ModuleStructBuilder::beginFunction( ast::type::FunctionPtr funcType )
	{
		registerType( funcType );
		beginBlock();
	}

	bool StmtRegister::ModuleStructBuilder::makeAlias( ast::stmt::Container * container
		, ast::expr::ExprPtr expr
		, bool param
		, ast::expr::ExprPtr & aliasExpr
		, VariablePtr & alias )
	{
		ast::var::VariablePtr aliasVar;
		auto result = spirv::makeAlias( container
			, std::move( expr )
			, param
			, aliasExpr
			, aliasVar
			, *m_currentId );

		if ( result )
		{
			alias = std::make_shared< Variable >( aliasVar, IdList{} );
		}

		return result;
	}

	void StmtRegister::ModuleStructBuilder::endFunction( ast::stmt::Container * container
		, ast::type::FunctionPtr funcType )
	{
		endBlock();
	}

	void StmtRegister::ModuleStructBuilder::doRegisterVar( VariablePtr var )
	{
		getNextId();
	}

	void StmtRegister::ModuleStructBuilder::doRegisterUse( VariablePtr var )
	{
		m_usedVars.insert( var );
	}

	void StmtRegister::ModuleStructBuilder::doUpdateVars( VariableArray * vars )
	{
		m_allVars = vars;
	}

	//*************************************************************************

	class ExprRegister
		: public ast::ExprCloner
	{
	public:
		static ast::expr::ExprPtr submit( ast::expr::Expr * expr
			, ast::stmt::Container * container
			, StmtRegister::ModuleStructBuilder & builder
			, ast::type::TypesCache & cache
			, uint32_t & currentId )
		{
			ast::expr::ExprPtr result;
			ExprRegister vis{ result, container, builder, cache, currentId };
			expr->accept( &vis );
			return result;
		}

	private:
		ExprRegister( ast::expr::ExprPtr & result
			, ast::stmt::Container * container
			, StmtRegister::ModuleStructBuilder & builder
			, ast::type::TypesCache & cache
			, uint32_t & currentId )
			: ExprCloner{ result }
			, m_container{ container }
			, m_builder{ builder }
			, m_cache{ cache }
			, m_currentId{ &currentId }
		{
		}

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override
		{
			ast::expr::ExprPtr result;
			ExprRegister vis{ result, m_container, m_builder, m_cache, *m_currentId };
			expr->accept( &vis );
			return result;
		}

		VariablePtr doGetSetVar( ast::expr::Expr * expr )
		{
			auto ident = ast::findIdentifier( expr );
			assert( ident );
			return std::make_shared< Variable >( ident->getVariable()
				, IdList{} );
		}

		VariableArray doGetUsedVars( ast::expr::Expr * expr )
		{
			VariableArray result;

			for ( auto & ident : ast::listIdentifiers( expr ) )
			{
				result.emplace_back( std::make_shared< Variable >( ident->getVariable()
					, IdList{} ) );
			}

			return result;
		}

		void visitAddAssignExpr( ast::expr::AddAssign * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eAdd
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
			m_result = ast::expr::makeAssign( expr->getType()
				, doSubmit( expr->getLHS() )
				, std::move( m_result ) );
		}

		void visitAddExpr( ast::expr::Add * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eAdd
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
		}

		void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eDivide
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
			m_result = ast::expr::makeAssign( expr->getType()
				, doSubmit( expr->getLHS() )
				, std::move( m_result ) );
		}

		void visitDivideExpr( ast::expr::Divide * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eDivide
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
		}

		void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eMinus
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
			m_result = ast::expr::makeAssign( expr->getType()
				, doSubmit( expr->getLHS() )
				, std::move( m_result ) );
		}

		void visitMinusExpr( ast::expr::Minus * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eMinus
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
		}

		void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eTimes
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
			m_result = ast::expr::makeAssign( expr->getType()
				, doSubmit( expr->getLHS() )
				, std::move( m_result ) );
		}

		void visitTimesExpr( ast::expr::Times * expr )override
		{
			m_result = doWriteBinaryOperation( ast::expr::Kind::eTimes
				, expr->getType()
				, expr->getLHS()
				, expr->getRHS() );
		}

		void visitCastExpr( ast::expr::Cast * expr )override
		{
			m_builder.registerType( expr->getType() );
			m_builder.registerType( expr->getOperand()->getType() );
			auto dstScalarType = getScalarType( expr->getType()->getKind() );
			auto srcScalarType = getScalarType( expr->getOperand()->getType()->getKind() );
#if !defined( NDEBUG )
			auto dstComponents = getComponentCount( expr->getType()->getKind() );
			auto srcComponents = getComponentCount( expr->getOperand()->getType()->getKind() );
#endif

			if ( dstScalarType == ast::type::Kind::eBoolean
				&& srcScalarType != ast::type::Kind::eBoolean )
			{
				// Conversion to bool scalar or vector type.
				assert( dstComponents == srcComponents );
				m_result = makeToBoolCast( m_cache
					, doSubmit( expr->getOperand() ) );
			}
			else if ( srcScalarType == ast::type::Kind::eBoolean
				&& dstScalarType != ast::type::Kind::eBoolean )
			{
				// Conversion from bool scalar or vector type.
				assert( dstComponents == srcComponents );
				m_result = makeFromBoolCast( m_cache
					, doSubmit( expr->getOperand() )
					, dstScalarType );
			}
			else
			{
				ExprCloner::visitCastExpr( expr );
			}
		}

		void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
		{
			ast::expr::ExprList args;

			if ( expr->getArgList().size() == 1u
				&& !isScalarType( expr->getArgList().front()->getType()->getKind() ) )
			{
				auto & arg = *expr->getArgList().front();
				auto argType = arg.getType();
				VariablePtr alias;
				ast::expr::ExprPtr argAlias;
				m_builder.makeAlias( m_container, doSubmit( &arg ), false, argAlias, alias );
				m_builder.registerVar( std::make_shared< Variable >( ast::findIdentifier( argAlias )->getVariable(), IdList{} ) );

				if ( isVectorType( argType->getKind() ) )
				{
					doConstructVector( expr
						, argAlias
						, expr->getType()->getKind()
						, args );
				}
				else if ( isMatrixType( argType->getKind() ) )
				{
					doConstructMatrix( expr
						, argAlias
						, expr->getType()->getKind()
						, args );
				}
				else
				{
					// TODO: Struct or array.
				}
			}
			else
			{
				doConstructOther( expr, args );
			}

			m_result = ast::expr::makeCompositeConstruct( expr->getComposite()
				, expr->getComponent()
				, std::move( args ) );
		}

		void visitFnCallExpr( ast::expr::FnCall * expr )override
		{
			ast::expr::ExprList args;

			struct OutputParam
			{
				ast::expr::ExprPtr param;
				VariablePtr alias;
			};
			std::vector< OutputParam > outputParams;
			auto fnType = std::static_pointer_cast< ast::type::Function >( expr->getFn()->getType() );
			auto it = fnType->begin();

			for ( auto & arg : expr->getArgList() )
			{
				auto kind = getNonArrayKind( arg->getType() );
				auto param = *( it++ );

				if ( isSamplerType( kind )
					|| isSampledImageType( kind )
					|| isImageType( kind ) )
				{
					if ( arg->getKind() == ast::expr::Kind::eArrayAccess )
					{
						VariablePtr alias;
						auto tmp = doSubmit( arg.get() );
						ast::expr::ExprPtr aliasExpr;

						if ( m_builder.makeAlias( m_container, std::move( tmp ), true, aliasExpr, alias ) )
						{
							m_builder.registerVar( std::make_shared< Variable >( ast::findIdentifier( aliasExpr )->getVariable(), IdList{} ) );
							auto argIdent = ast::findIdentifier( arg, kind, ast::var::Flag::eUniform );

							if ( argIdent )
							{
								// For samplers and imges, the eUniform flag from the function parameter must be removed,
								// since the alias can't have it.
								param->updateFlag( ast::var::Flag::eUniform, false );
								//// Then the eConstant flag must be added, to match
								//auto aliaIdent
								//( aliasExpr )->getVariable()->updateFlag( ast::var::Flag::eConstant, true );
							}
						}
						else
						{
							m_builder.registerVar( std::make_shared< Variable >( ast::findIdentifier( aliasExpr )->getVariable(), IdList{} ) );
						}

						args.emplace_back( std::move( aliasExpr ) );

						if ( param->isOutputParam()
							&& alias )
						{
							outputParams.push_back( { doSubmit( arg.get() ), alias } );
						}
					}
					else
					{
						// Images/Samplers/SampledImages are uniform constant pointers.
						args.emplace_back( doSubmit( arg.get() ) );
					}
				}
				//else if ( isAccessChain( arg.get() )
				//	&& arg->getKind() != ast::expr::Kind::eSwizzle
				//	&& arg->getKind() != ast::expr::Kind::eLiteral
				//	&& ( arg->getKind() != ast::expr::Kind::eIdentifier
				//		|| !isShaderVariable( *arg ) ) )
				//{
				//	// Access chains are pointers, hence no need for an alias.
				//	args.emplace_back( doSubmit( arg.get() ) );
				//}
				else
				{
					VariablePtr alias;
					ast::expr::ExprPtr tmp;
					m_builder.makeAlias( m_container, doSubmit( arg.get() ), true, tmp, alias );
					args.emplace_back( std::move( tmp ) );

					if ( param->isOutputParam()
						&& alias )
					{
						outputParams.push_back( { doSubmit( arg.get() ), alias } );
					}
				}
			}

			if ( expr->isMember() )
			{
				m_result = ast::expr::makeMemberFnCall( expr->getType()
					, std::make_unique< ast::expr::Identifier >( *expr->getFn() )
					, doSubmit( expr->getInstance() )
					, std::move( args ) );
			}
			else
			{
				m_result = ast::expr::makeFnCall( expr->getType()
					, std::make_unique< ast::expr::Identifier >( *expr->getFn() )
					, std::move( args ) );
			}

			if ( expr->getType()->getKind() != ast::type::Kind::eVoid )
			{
				// Store function result into a return alias, that will be the final result.
				auto var = createTmpVar( expr->getType()
					, *m_currentId );
				m_builder.registerVar( std::make_shared< Variable >( var, IdList{} ) );
				m_container->addStmt( ast::stmt::makeSimple( ast::expr::makeAlias( expr->getType()
					, ast::expr::makeIdentifier( m_cache, var )
					, std::move( m_result ) ) ) );
				m_result = ast::expr::makeIdentifier( m_cache, var );
			}

			for ( auto & var : outputParams )
			{
				m_container->addStmt( ast::stmt::makeSimple( std::move( m_result ) ) );
				m_result = ast::expr::makeAssign( var.alias->var->getType()
					, std::move( var.param )
					, ast::expr::makeIdentifier( m_cache, var.alias->var ) );
			}
		}

		void visitIdentifierExpr( ast::expr::Identifier * expr )override
		{
			m_builder.registerVar( std::make_shared< Variable >( expr->getVariable(), IdList{} ) );
			m_result = ExprCloner::submit( expr );
		}

		void visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )override
		{
			m_builder.registerType( expr->getType() );
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = ast::expr::makeImageAccessCall( expr->getType()
				, expr->getImageAccess()
				, std::move( args ) );
		}

		void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
		{
			m_builder.registerType( expr->getType() );
			auto intrinsic = expr->getIntrinsic();

			if ( intrinsic >= ast::expr::Intrinsic::eMatrixCompMult2x2F
				&& intrinsic <= ast::expr::Intrinsic::eMatrixCompMult4x4D )
			{
				assert( expr->getArgList().size() == 2u );
				m_result = doWriteMatrixBinaryOperation( ast::expr::Kind::eTimes
					, expr->getType()
					, expr->getArgList()[0].get()
					, expr->getArgList()[1].get() );
			}
			else
			{
				ExprCloner::visitIntrinsicCallExpr( expr );
			}
		}

		void visitQuestionExpr( ast::expr::Question * expr )override
		{
			m_builder.registerType( expr->getCtrlExpr()->getType() );
			m_builder.registerType( expr->getTrueExpr()->getType() );
			m_builder.registerType( expr->getFalseExpr()->getType() );
			auto condComponents = getComponentCount( expr->getCtrlExpr()->getType()->getKind() );
			auto opsComponents = getComponentCount( expr->getTrueExpr()->getType()->getKind() );

			if ( condComponents == opsComponents )
			{
				ExprCloner::visitQuestionExpr( expr );
			}
			else
			{
				assert( condComponents == 1u );
				ast::expr::ExprList args;
				VariablePtr alias;
				ast::expr::ExprPtr aliasExpr;
				m_builder.makeAlias( m_container, doSubmit( expr->getCtrlExpr() ), false, aliasExpr, alias );
				m_builder.registerVar( std::make_shared< Variable >( ast::findIdentifier( aliasExpr )->getVariable(), IdList{} ) );
				args.emplace_back( std::move( aliasExpr ) );
				m_result = ast::expr::makeQuestion( expr->getType()
					, doSubmit( ast::expr::makeCompositeConstruct( getCompositeType( opsComponents )
						, expr->getCtrlExpr()->getType()->getKind()
						, std::move( args ) ).get() )
					, doSubmit( expr->getTrueExpr() )
					, doSubmit( expr->getFalseExpr() ) );
			}
		}

		void visitSwizzleExpr( ast::expr::Swizzle * expr )override
		{
			auto outerComponentsCount = getComponentCount( expr->getOuterExpr()->getType()->getKind() );
			auto innerComponentsCount = getComponentCount( expr->getType()->getKind() );

			// Remove unnecessary swizzles
			if ( outerComponentsCount == innerComponentsCount
				&& ( expr->getSwizzle() == ast::expr::SwizzleKind::e0
					|| expr->getSwizzle() == ast::expr::SwizzleKind::e01
					|| expr->getSwizzle() == ast::expr::SwizzleKind::e012
					|| expr->getSwizzle() == ast::expr::SwizzleKind::e0123 ) )
			{
				m_result = doSubmit( expr->getOuterExpr() );
			}
			else
			{
				ExprCloner::visitSwizzleExpr( expr );
			}
		}

		void visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )override
		{
			auto kind = expr->getTextureAccess();
			IntrinsicConfig config;
			getSpirVConfig( kind, config );
			auto returnType = expr->getType();
			auto count = getComponentCount( returnType->getKind() );

			if ( config.returnComponentsCount != ~( 0u ) && config.returnComponentsCount != count )
			{
				assert( config.returnComponentsCount > count );
				returnType = m_cache.getVector( getScalarType( returnType->getKind() ), config.returnComponentsCount );
			}

			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( submit( arg.get(), m_container, m_builder, m_cache, *m_currentId ) );
			}

			m_result = ast::expr::makeTextureAccessCall( returnType
				, kind
				, std::move( args ) );

			if ( config.returnComponentsCount != ~( 0u ) && config.returnComponentsCount != count )
			{
				ast::expr::SwizzleKind swizzleKind;

				switch ( count )
				{
				case 1:
					swizzleKind = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzleKind = ast::expr::SwizzleKind::e01;
					break;
				case 3:
					swizzleKind = ast::expr::SwizzleKind::e012;
					break;
				case 4:
					swizzleKind = ast::expr::SwizzleKind::e0123;
					break;
				}

				m_result = ast::expr::makeSwizzle( std::move( m_result ), swizzleKind );
			}
		}

		ast::type::TypePtr doPromoteScalar( ast::expr::ExprPtr & lhs
			, ast::expr::ExprPtr & rhs )
		{
			auto lhsScalar = isScalarType( lhs->getType()->getKind() );
			auto rhsScalar = isScalarType( rhs->getType()->getKind() );
			auto result = lhs->getType();

			if ( !lhsScalar || !rhsScalar )
			{
				if ( !lhsScalar && !rhsScalar )
				{
					assert( false && "TODO" );
				}
				else if ( lhsScalar )
				{
					result = rhs->getType();
					ast::expr::ExprList args;
					auto count = getComponentCount( result->getKind() );
					VariablePtr aliasVar;
					ast::expr::ExprPtr alias;
					m_builder.makeAlias( m_container
						, doSubmit( lhs.get() )
						, false
						, alias
						, aliasVar );

					for ( auto i = 0u; i < count; ++i )
					{
						args.emplace_back( doSubmit( alias.get() ) );
					}

					lhs = ast::expr::makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
						, args.back()->getType()->getKind()
						, std::move( args ) );
					m_builder.registerType( lhs->getType() );
				}
				else if ( rhsScalar )
				{
					result = lhs->getType();
					ast::expr::ExprList args;
					auto count = getComponentCount( result->getKind() );
					VariablePtr aliasVar;
					ast::expr::ExprPtr alias;
					m_builder.makeAlias( m_container
						, doSubmit( rhs.get() )
						, false
						, alias
						, aliasVar );

					for ( auto i = 0u; i < count; ++i )
					{
						args.emplace_back( doSubmit( alias.get() ) );
					}

					rhs = ast::expr::makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
						, args.back()->getType()->getKind()
						, std::move( args ) );
					m_builder.registerType( rhs->getType() );
				}
			}

			return result;
		}

		ast::expr::ExprPtr doWriteBinaryOperation( ast::expr::Kind operation
			, ast::type::TypePtr resType
			, ast::expr::Expr * lhs
			, ast::expr::Expr * rhs )
		{
			bool needMatchingVectors;
			bool switchParams;
			auto op = getBinOpCode( operation
				, lhs->getType()->getKind()
				, rhs->getType()->getKind()
				, switchParams
				, needMatchingVectors );

			if ( switchParams )
			{
				std::swap( lhs, rhs );
			}

			auto lhsType = lhs->getType();
			auto rhsType = rhs->getType();
			bool lhsMat = isMatrixType( lhsType->getKind() );
			bool rhsMat = isMatrixType( rhsType->getKind() );
			auto lhsExpr = doSubmit( lhs );
			auto rhsExpr = doSubmit( rhs );
			auto type = lhsExpr->getType();
			ast::expr::ExprPtr result;

			if ( lhsMat || rhsMat )
			{
				if ( op == spv::OpMatrixTimesVector )
				{
					type = rhsExpr->getType();
				}

				ast::expr::ExprList args;
				VariablePtr lhsAlias, rhsAlias;
				m_builder.makeAlias( m_container, std::move( lhsExpr ), false, lhsExpr, lhsAlias );
				m_builder.makeAlias( m_container, std::move( rhsExpr ), false, rhsExpr, rhsAlias );

				switch ( operation )
				{
				case ast::expr::Kind::eAdd:
				case ast::expr::Kind::eDivide:
				case ast::expr::Kind::eMinus:
					result = doWriteMatrixBinaryOperation( operation
						, resType
						, lhsExpr.get()
						, rhsExpr.get() );
					break;
				case ast::expr::Kind::eTimes:
					result = ast::expr::makeTimes( type
						, std::move( lhsExpr )
						, std::move( rhsExpr ) );
					break;
				default:
					assert( false && "Unsupported binary operation" );
					break;
				}
			}
			else
			{
				if ( needMatchingVectors )
				{
					type = doPromoteScalar( lhsExpr, rhsExpr );
				}

				ast::expr::ExprList args;

				switch ( operation )
				{
				case ast::expr::Kind::eAdd:
					result = ast::expr::makeAdd( type
						, std::move( lhsExpr )
						, std::move( rhsExpr ) );
					break;
				case ast::expr::Kind::eDivide:
					result = ast::expr::makeDivide( type
						, std::move( lhsExpr )
						, std::move( rhsExpr ) );
					break;
				case ast::expr::Kind::eMinus:
					result = ast::expr::makeMinus( type
						, std::move( lhsExpr )
						, std::move( rhsExpr ) );
					break;
				case ast::expr::Kind::eTimes:
					result = ast::expr::makeTimes( type
						, std::move( lhsExpr )
						, std::move( rhsExpr ) );
					break;
				default:
					assert( false && "Unsupported binary operation" );
					break;
				}
			}

			return result;
		}

		ast::expr::ExprPtr doWriteMatrixBinaryOperation( ast::expr::Kind operation
			, ast::type::TypePtr resType
			, ast::expr::Expr * lhs
			, ast::expr::Expr * rhs )
		{
				// one time set up...
			auto lhsType = lhs->getType();
			auto rhsType = rhs->getType();
			bool lhsMat = isMatrixType( lhsType->getKind() );
			bool rhsMat = isMatrixType( rhsType->getKind() );
			auto lhsColumns = getComponentCount( lhsType->getKind() );
			auto rhsColumns = getComponentCount( rhsType->getKind() );
			auto lhsRows = getComponentCount( getComponentType( lhsType->getKind() ) );
			auto rhsRows = getComponentCount( getComponentType( rhsType->getKind() ) );
			auto numCols = lhsMat ? lhsColumns : rhsColumns;
			auto numRows = lhsMat ? lhsRows : rhsRows;
			auto scalarType = getScalarType( resType->getKind() );
			auto vecType = m_cache.getVector( scalarType, numRows );
			m_builder.registerType( vecType );
			ast::expr::CompositeType composite;

			switch ( numRows )
			{
			case 1:
				composite = ast::expr::CompositeType::eScalar;
				break;
			case 2:
				composite = ast::expr::CompositeType::eVec2;
				break;
			case 3:
				composite = ast::expr::CompositeType::eVec3;
				break;
			default:
				composite = ast::expr::CompositeType::eVec4;
				break;
			}

			ast::expr::ExprPtr smearVec;

			if ( isScalarType( lhsType->getKind() ) )
			{
				if ( composite == ast::expr::CompositeType::eScalar )
				{
					smearVec = doSubmit( lhs );
				}
				else
				{
					ast::expr::ExprList params;
					params.emplace_back( doSubmit( lhs ) );
					smearVec = ast::expr::makeCompositeConstruct( composite
						, lhsType->getKind()
						, std::move( params ) );
				}
			}
			else if ( isScalarType( rhsType->getKind() ) )
			{
				if ( composite == ast::expr::CompositeType::eScalar )
				{
					smearVec = doSubmit( rhs );
				}
				else
				{
					ast::expr::ExprList params;
					params.emplace_back( doSubmit( rhs ) );
					smearVec = ast::expr::makeCompositeConstruct( composite
						, rhsType->getKind()
						, std::move( params ) );
				}
			}

			ast::expr::ExprList args;

			// do each vector op
			for ( unsigned int c = 0; c < numCols; ++c )
			{
				std::vector<unsigned int> indexes;
				indexes.push_back( c );
				auto lhsVec = lhsMat
					? ast::expr::makeArrayAccess( vecType, doSubmit( lhs ), ast::expr::makeLiteral( m_cache, c ) )
					: ast::ExprCloner::submit( smearVec.get() );
				auto rhsVec = rhsMat
					? ast::expr::makeArrayAccess( vecType, doSubmit( rhs ), ast::expr::makeLiteral( m_cache, c ) )
					: ast::ExprCloner::submit( smearVec.get() );

				switch ( operation )
				{
				case ast::expr::Kind::eAdd:
					args.emplace_back( ast::expr::makeAdd( vecType
						, std::move( lhsVec )
						, std::move( rhsVec ) ) );
					break;
				case ast::expr::Kind::eDivide:
					args.emplace_back( ast::expr::makeDivide( vecType
						, std::move( lhsVec )
						, std::move( rhsVec ) ) );
					break;
				case ast::expr::Kind::eMinus:
					args.emplace_back( ast::expr::makeMinus( vecType
						, std::move( lhsVec )
						, std::move( rhsVec ) ) );
					break;
				case ast::expr::Kind::eTimes:
					args.emplace_back( ast::expr::makeTimes( vecType
						, std::move( lhsVec )
						, std::move( rhsVec ) ) );
					break;
				default:
					assert( false && "Unsupported binary operation" );
					break;
				}
			}

			switch ( composite )
			{
			case ast::expr::CompositeType::eScalar:
				switch ( numCols )
				{
				case 1:
					composite = ast::expr::CompositeType::eScalar;
					break;
				case 2:
					composite = ast::expr::CompositeType::eVec2;
					break;
				case 3:
					composite = ast::expr::CompositeType::eVec3;
					break;
				case 4:
					composite = ast::expr::CompositeType::eVec4;
					break;
				}
				break;
			case ast::expr::CompositeType::eVec2:
				switch ( numCols )
				{
				case 1:
					composite = ast::expr::CompositeType::eVec2;
					break;
				case 2:
					composite = ast::expr::CompositeType::eMat2x2;
					break;
				case 3:
					composite = ast::expr::CompositeType::eMat3x2;
					break;
				case 4:
					composite = ast::expr::CompositeType::eMat4x2;
					break;
				}
				break;
			case ast::expr::CompositeType::eVec3:
				switch ( numCols )
				{
				case 1:
					composite = ast::expr::CompositeType::eVec3;
					break;
				case 2:
					composite = ast::expr::CompositeType::eMat2x3;
					break;
				case 3:
					composite = ast::expr::CompositeType::eMat3x3;
					break;
				case 4:
					composite = ast::expr::CompositeType::eMat4x3;
					break;
				}
				break;
			case ast::expr::CompositeType::eVec4:
				switch ( numCols )
				{
				case 1:
					composite = ast::expr::CompositeType::eVec4;
					break;
				case 2:
					composite = ast::expr::CompositeType::eMat2x4;
					break;
				case 3:
					composite = ast::expr::CompositeType::eMat3x4;
					break;
				case 4:
					composite = ast::expr::CompositeType::eMat4x4;
					break;
				}
				break;
			default:
				break;
			}

			// put the pieces together
			if ( composite != ast::expr::CompositeType::eScalar )
			{
				return ast::expr::makeCompositeConstruct( composite
					, scalarType
					, std::move( args ) );
			}

			assert( args.size() == 1u );
			return std::move( args[0] );
		}

		void doConstructVector( ast::expr::CompositeConstruct * expr
			, ast::expr::ExprPtr const & newArg
			, ast::type::Kind destKind
			, ast::expr::ExprList & args )
		{
			auto count = getComponentCount( newArg->getType()->getKind() );

			for ( auto i = 0u; i < count; ++i )
			{
				args.emplace_back( ast::expr::makeSwizzle( doSubmit( newArg.get() )
					, ast::expr::SwizzleKind::fromOffset( i ) ) );
			}

			if ( newArg->getType()->getKind() != expr->getType()->getKind() )
			{
				auto dstType = m_cache.getBasicType( getScalarType( expr->getType()->getKind() ) );

				for ( auto & arg : args )
				{
					arg = doSubmit( ast::expr::makeCast( dstType
						, std::move( arg ) ).get() );
				}
			}
		}

		void doConstructMatrix( ast::expr::CompositeConstruct * expr
			, ast::expr::ExprPtr const & newArg
			, ast::type::Kind destKind
			, ast::expr::ExprList & args )
		{
			auto scalarType = getScalarType( destKind );
			auto srcColumnCount = getComponentCount( newArg->getType()->getKind() );
			auto srcRowCount = getComponentCount( getComponentType( newArg->getType()->getKind() ) );
			auto dstColumnCount = getComponentCount( destKind );
			auto dstRowCount = getComponentCount( getComponentType( destKind ) );
			auto minColumnCount = std::min( srcColumnCount, dstColumnCount );

			for ( auto col = 0u; col < minColumnCount; ++col )
			{
				auto arrayAccess = ast::expr::makeArrayAccess( m_cache.getVector( scalarType, srcRowCount )
					, doSubmit( newArg.get() )
					, ast::expr::makeLiteral( m_cache, col ) );

				if ( dstRowCount < srcRowCount )
				{
					args.emplace_back( ast::expr::makeSwizzle( std::move( arrayAccess )
						, getSwizzleComponents( dstRowCount ) ) );
				}
				else if ( dstRowCount == srcRowCount )
				{
					args.emplace_back( std::move( arrayAccess ) );
				}
				else
				{
					ast::expr::ExprList compositeArgs;
					compositeArgs.emplace_back( std::move( arrayAccess ) );

					for ( auto row = srcRowCount; row < dstRowCount; ++row )
					{
						if ( row == col )
						{
							switch ( scalarType )
							{
							case ast::type::Kind::eInt:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1 ) );
								break;
							case ast::type::Kind::eUInt:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1u ) );
								break;
							case ast::type::Kind::eFloat:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1.0f ) );
								break;
							case ast::type::Kind::eDouble:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 1.0 ) );
								break;
							default:
								break;
							}
						}
						else
						{
							switch ( scalarType )
							{
							case ast::type::Kind::eInt:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0 ) );
								break;
							case ast::type::Kind::eUInt:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0u ) );
								break;
							case ast::type::Kind::eFloat:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0.0f ) );
								break;
							case ast::type::Kind::eDouble:
								compositeArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0.0 ) );
								break;
							default:
								break;
							}
						}
					}

					args.emplace_back( ast::expr::makeCompositeConstruct( getCompositeType( dstRowCount )
						, scalarType
						, std::move( compositeArgs ) ) );
				}
			}

			for ( auto col = minColumnCount; col < dstColumnCount; ++col )
			{
			}
		}

		void doConstructOther( ast::expr::CompositeConstruct * expr
			, ast::expr::ExprList & args )
		{
			auto scalarType = expr->getComponent();

			for ( auto & arg : expr->getArgList() )
			{
				auto newArg = doSubmit( arg.get() );

				if ( isScalarType( newArg->getType()->getKind() ) )
				{
					auto argTypeKind = getScalarType( newArg->getType()->getKind() );

					if ( argTypeKind != scalarType )
					{
						newArg = ast::expr::makeCast( m_cache.getBasicType( scalarType )
							, std::move( newArg ) );
					}
				}

				args.emplace_back( std::move( newArg ) );
			}
		}

	private:
		ast::stmt::Container * m_container;
		StmtRegister::ModuleStructBuilder & m_builder;
		ast::type::TypesCache & m_cache;
		uint32_t * m_currentId;
	};

	//*************************************************************************

	ast::stmt::ContainerPtr StmtRegister::submit( ast::stmt::Container * cont
		, uint32_t & currentId
		, ast::type::TypesCache & cache
		, ModuleStruct & moduleStruct )
	{
		auto result = ast::stmt::makeContainer();
		ModuleStructBuilder builder
		{
			result,
			moduleStruct,
			cache,
			currentId,
		};
		StmtRegister vis
		{
			result,
			builder,
			cache,
			currentId,
		};
		cont->accept( &vis );
		return result;
	}

	StmtRegister::StmtRegister( ast::stmt::ContainerPtr & result
		, ModuleStructBuilder & builder
		, ast::type::TypesCache & cache
		, uint32_t & currentId )
		: StmtCloner{ result }
		, m_builder{ builder }
		, m_cache{ cache }
		, m_currentId{ &currentId }
	{
	}

	ast::expr::ExprPtr StmtRegister::doSubmit( ast::expr::Expr * expr )
	{
		return ExprRegister::submit( expr, m_current, m_builder, m_cache, *m_currentId );
	}

	void StmtRegister::visitContainerStmt( ast::stmt::Container * cont )
	{
		bool empty = m_builder.isGlobalScopeEmpty();

		if ( !empty )
		{
			m_builder.beginBlock();
			StmtCloner::visitContainerStmt( cont );
			m_builder.endBlock();
		}
		else
		{
			StmtCloner::visitContainerStmt( cont );
		}
	}

	void StmtRegister::visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )
	{
		StmtCloner::visitConstantBufferDeclStmt( stmt );
	}

	void StmtRegister::visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )
	{
		StmtCloner::visitPushConstantsBufferDeclStmt( stmt );
	}

	void StmtRegister::visitCompoundStmt( ast::stmt::Compound * stmt )
	{
		StmtCloner::visitCompoundStmt( stmt );
	}

	void StmtRegister::visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )
	{
		m_builder.beginFunction( stmt->getType() );
		StmtCloner::visitFunctionDeclStmt( stmt );
		m_builder.endFunction( m_current, stmt->getType() );
	}

	void StmtRegister::visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )
	{
		StmtCloner::visitInOutVariableDeclStmt( stmt );
		auto var = stmt->getVariable();
		m_builder.registerVar( std::make_shared< Variable >( var
			, getDecorations( var->isShaderConstant()
				, var->isFlat()
				, stmt->getLocation() ) ) );
	}

	void StmtRegister::visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )
	{
		StmtCloner::visitSpecialisationConstantDeclStmt( stmt );
		auto var = stmt->getVariable();
		m_builder.registerVar( std::make_shared< Variable >( var
			, getDecorations( stmt->getLocation() ) ) );
	}

	void StmtRegister::visitReturnStmt( ast::stmt::Return * stmt )
	{
		StmtCloner::visitReturnStmt( stmt );

		if ( stmt->getExpr() )
		{
			ast::expr::ExprPtr aliasExpr;
			spirv::VariablePtr aliasVar;

			if ( m_builder.makeAlias( m_result.get()
				, doSubmit( stmt->getExpr() )
				, false
				, aliasExpr
				, aliasVar ) )
			{
				//m_builder.registerUsages( alias );
			}
		}

		m_builder.endFunction( m_result.get(), nullptr /* TODO */ );
	}

	void StmtRegister::visitImageDeclStmt( ast::stmt::ImageDecl * stmt )
	{
		m_builder.registerVar( std::make_shared< Variable >( stmt->getVariable()
			, getDecorations( stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) ) );
	}

	void StmtRegister::visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )
	{
		m_builder.registerVar( std::make_shared< Variable >( stmt->getVariable()
			, getDecorations( stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) ) );
	}

	void StmtRegister::visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )
	{
		m_builder.registerVar( std::make_shared< Variable >( stmt->getVariable()
			, getDecorations( stmt->getBindingPoint()
				, stmt->getDescriptorSet() ) ) );
	}

	void StmtRegister::visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )
	{
		m_builder.registerVar( std::make_shared< Variable >( makeVar( m_cache
				, stmt->getSsboName()
				, stmt->getMemoryLayout() )
			, getDecorations( stmt->getBindingPoint()
				, stmt->getDescriptorSet()
				, true ) ) );
		visitContainerStmt( stmt );
	}

	void StmtRegister::visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )
	{
		m_builder.registerVar( std::make_shared< Variable >( stmt->getSsboInstance()
			, getDecorations( stmt->getBindingPoint()
				, stmt->getDescriptorSet()
				, true ) ) );
	}

	void StmtRegister::visitSimpleStmt( ast::stmt::Simple * stmt )
	{
		doSubmit( stmt->getExpr() );
	}

	void StmtRegister::visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )
	{
		m_builder.registerType( stmt->getType() );
	}

	void StmtRegister::visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )
	{
		visitContainerStmt( stmt );
	}

	void StmtRegister::visitSwitchStmt( ast::stmt::Switch * stmt )
	{
		doSubmit( stmt->getTestExpr() );
		m_builder.beginBlock();

		for ( auto & it : *stmt )
		{
			assert( it->getKind() == ast::stmt::Kind::eSwitchCase );
			auto & caseStmt = static_cast< ast::stmt::SwitchCase & >( *it );

			if ( caseStmt.getCaseExpr() )
			{
				doSubmit( caseStmt.getCaseExpr() );
				visitSwitchCaseStmt( &caseStmt );
			}
			else
			{
				// Default
				visitSwitchCaseStmt( &caseStmt );
			}
		}

		m_builder.endBlock();
	}

	void StmtRegister::visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )
	{
		m_builder.registerVar(
			{
				stmt->getVariable(),
				{}
			} );
	}

	void StmtRegister::visitWhileStmt( ast::stmt::While * stmt )
	{
		doSubmit( stmt->getCtrlExpr() );
		visitContainerStmt( stmt );
	}

	void StmtRegister::visitPreprocDefine( ast::stmt::PreprocDefine * preproc )
	{
	}

	void StmtRegister::visitPreprocElif( ast::stmt::PreprocElif * preproc )
	{
	}

	void StmtRegister::visitPreprocElse( ast::stmt::PreprocElse * preproc )
	{
	}

	void StmtRegister::visitPreprocEndif( ast::stmt::PreprocEndif * preproc )
	{
	}

	void StmtRegister::visitPreprocExtension( ast::stmt::PreprocExtension * preproc )
	{
	}

	void StmtRegister::visitPreprocIf( ast::stmt::PreprocIf * preproc )
	{
	}

	void StmtRegister::visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )
	{
	}

	void StmtRegister::visitPreprocVersion( ast::stmt::PreprocVersion * preproc )
	{
	}
}
