/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/StmtSimplifier.hpp"

#include "ShaderAST/Visitors/CloneExpr.hpp"
#include "ShaderAST/Expr/ExprLiteral.hpp"

namespace ast
{
	namespace simpl
	{
		static expr::LiteralType getLiteralType( type::Type const & type )
		{
			type::Kind kind = type.getKind();

			switch ( kind )
			{
			case type::Kind::eBoolean:
				return expr::LiteralType::eBool;
			case type::Kind::eInt8:
				return expr::LiteralType::eInt8;
			case type::Kind::eInt16:
				return expr::LiteralType::eInt16;
			case type::Kind::eInt32:
				return expr::LiteralType::eInt32;
			case type::Kind::eInt64:
				return expr::LiteralType::eInt64;
			case type::Kind::eUInt8:
				return expr::LiteralType::eUInt8;
			case type::Kind::eUInt16:
				return expr::LiteralType::eUInt16;
			case type::Kind::eUInt32:
				return expr::LiteralType::eUInt32;
			case type::Kind::eUInt64:
				return expr::LiteralType::eUInt64;
			case type::Kind::eFloat:
				return expr::LiteralType::eFloat;
			case type::Kind::eDouble:
				return expr::LiteralType::eDouble;
			default:
				AST_Failure( "Unsupported kind for a literal" );
				return expr::LiteralType::eFloat;
			}
		}

		static std::vector< expr::SwizzleKind > getSwizzleValues( expr::SwizzleKind swizzle )
		{
			auto count = swizzle.getComponentsCount();
			std::vector< expr::SwizzleKind > result;
			result.push_back( swizzle.getFirstValue() );

			if ( count >= 2u )
			{
				result.push_back( swizzle.getSecondValue() );
			}

			if ( count >= 3u )
			{
				result.push_back( swizzle.getThirdValue() );
			}

			if ( count >= 4u )
			{
				result.push_back( swizzle.getFourthValue() );
			}

			return result;
		}

		static uint32_t getSwizzleIndex( expr::SwizzleKind swizzle )
		{
			assert( swizzle.isOneComponent()
				&& "Invalid swizzle for components indexing" );

			return swizzle == expr::SwizzleKind::e0
				? 0u
				: ( swizzle == expr::SwizzleKind::e1
					? 1u
					: ( swizzle == expr::SwizzleKind::e2
						? 2u
						: 3u ) );
		}

		static std::vector< uint32_t > getSwizzleIndices( expr::SwizzleKind swizzle )
		{
			std::vector< uint32_t > result;
			result.push_back( getSwizzleIndex( swizzle.getFirstValue() ) );
			auto count = swizzle.getComponentsCount();

			if ( count >= 2u )
			{
				result.push_back( getSwizzleIndex( swizzle.getSecondValue() ) );
			}

			if ( count >= 3u )
			{
				result.push_back( getSwizzleIndex( swizzle.getThirdValue() ) );
			}

			if ( count >= 4u )
			{
				result.push_back( getSwizzleIndex( swizzle.getFourthValue() ) );
			}

			return result;
		}

		static expr::SwizzleKind getFinalSwizzle( std::vector< expr::SwizzleKind > const & values
			, std::vector< uint32_t > const & indices )
		{
			expr::SwizzleKind result;
			uint32_t shift = 0u;

			for ( auto & index : indices )
			{
				assert( index < values.size() );
				result |= values[index] >> shift;
				shift += 4u;
			}

			return result;
		}

		static uint32_t getComponentsCount( expr::CompositeType type )
		{
			switch ( type )
			{
			case expr::CompositeType::eScalar:
				return 1u;
			case expr::CompositeType::eVec2:
			case expr::CompositeType::eMat2x2:
			case expr::CompositeType::eMat2x3:
			case expr::CompositeType::eMat2x4:
			case expr::CompositeType::eCombine:
				return 2u;
			case expr::CompositeType::eVec3:
			case expr::CompositeType::eMat3x2:
			case expr::CompositeType::eMat3x3:
			case expr::CompositeType::eMat3x4:
				return 3u;
			case expr::CompositeType::eVec4:
			case expr::CompositeType::eMat4x2:
			case expr::CompositeType::eMat4x3:
			case expr::CompositeType::eMat4x4:
				return 4u;
			}

			return 0u;
		}

		class ExprSimplifier
			: public ExprCloner
		{
		public:
			static expr::ExprPtr submit( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, std::map< var::VariablePtr, expr::Literal * > & literalVars
				, expr::Expr * expr )
			{
				bool allLiterals{ false };
				return submit( exprCache
					, typesCache
					, literalVars
					, expr
					, allLiterals );
			}

			static expr::ExprPtr submit( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, std::map< var::VariablePtr, expr::Literal * > & literalVars
				, expr::Expr * expr
				, bool & allLiterals )
			{
				expr::ExprPtr result{};
				ExprSimplifier vis{ exprCache, typesCache, literalVars, allLiterals, result };
				expr->accept( &vis );
				return result;
			}

		private:
			ExprSimplifier( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, std::map< var::VariablePtr, expr::Literal * > & literalVars
				, bool & allLiterals
				, expr::ExprPtr & result )
				: ExprCloner{ exprCache, result }
				, m_typesCache{ typesCache }
				, m_literalVars{ literalVars }
				, m_allLiterals{ allLiterals }
			{
			}

		private:
			expr::ExprPtr doSubmit( expr::Expr * expr
				, bool & allLiterals )
			{
				expr::ExprPtr result{};
				ExprSimplifier vis{ m_exprCache, m_typesCache, m_literalVars, allLiterals, result };
				expr->accept( &vis );

				if ( expr->isNonUniform() )
				{
					result->updateFlag( expr::Flag::eNonUniform );
				}

				return result;
			}

			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				return doSubmit( expr, m_allLiterals );
			}

			expr::ExprPtr doSubmit( expr::ExprPtr expr )
			{
				return doSubmit( expr.get() );
			}

			void visitUnaryExpr( expr::Unary * expr )
			{
				TraceFunc
				auto op = doSubmit( expr->getOperand() );

				if ( op->getKind() == expr::Kind::eLiteral )
				{
					auto & literal = static_cast< expr::Literal const & >( *op );

					switch ( expr->getKind() )
					{
					case expr::Kind::eUnaryMinus:
						m_result = -literal;
						break;
					case expr::Kind::eUnaryPlus:
						m_result = std::move( op );
						break;
					case expr::Kind::eBitNot:
						m_result = ~literal;
						break;
					case expr::Kind::eLogNot:
						m_result = !literal;
						break;
					case expr::Kind::eCast:
						m_result = literal.castTo( getLiteralType( *expr->getType() ) );
						break;
					default:
						AST_Failure( "Unexpected unary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
				else
				{
					m_result = ExprCloner::submit( m_exprCache, expr );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )
			{
				TraceFunc
				auto lhs = doSubmit( expr->getLHS() );
				auto rhs = doSubmit( expr->getRHS() );

				if ( lhs->getKind() == expr::Kind::eLiteral
					&& rhs->getKind() == expr::Kind::eLiteral )
				{
					auto & lhsLiteral = static_cast< expr::Literal const & >( *lhs );
					auto & rhsLiteral = static_cast< expr::Literal const & >( *rhs );

					switch ( expr->getKind() )
					{
					case expr::Kind::eAdd:
						m_result = lhsLiteral + rhsLiteral;
						break;
					case expr::Kind::eBitAnd:
						m_result = lhsLiteral & rhsLiteral;
						break;
					case expr::Kind::eBitOr:
						m_result = lhsLiteral | rhsLiteral;
						break;
					case expr::Kind::eBitXor:
						m_result = lhsLiteral ^ rhsLiteral;
						break;
					case expr::Kind::eDivide:
						m_result = lhsLiteral / rhsLiteral;
						break;
					case expr::Kind::eLShift:
						m_result = lhsLiteral << rhsLiteral;
						break;
					case expr::Kind::eMinus:
						m_result = lhsLiteral - rhsLiteral;
						break;
					case expr::Kind::eModulo:
						m_result = lhsLiteral % rhsLiteral;
						break;
					case expr::Kind::eRShift:
						m_result = lhsLiteral >> rhsLiteral;
						break;
					case expr::Kind::eTimes:
						m_result = lhsLiteral * rhsLiteral;
						break;
					case expr::Kind::eLogAnd:
						m_result = lhsLiteral && rhsLiteral;
						break;
					case expr::Kind::eLogOr:
						m_result = lhsLiteral || rhsLiteral;
						break;
					case expr::Kind::eLess:
						m_result = lhsLiteral < rhsLiteral;
						break;
					case expr::Kind::eLessEqual:
						m_result = lhsLiteral <= rhsLiteral;
						break;
					case expr::Kind::eGreater:
						m_result = lhsLiteral > rhsLiteral;
						break;
					case expr::Kind::eGreaterEqual:
						m_result = lhsLiteral >= rhsLiteral;
						break;
					case expr::Kind::eEqual:
						m_result = lhsLiteral == rhsLiteral;
						break;
					case expr::Kind::eNotEqual:
						m_result = lhsLiteral != rhsLiteral;
						break;
					default:
						AST_Failure( "Unexpected binary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
				else
				{
					switch ( expr->getKind() )
					{
					case expr::Kind::eAdd:
						m_result = m_exprCache.makeAdd( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitAnd:
						m_result = m_exprCache.makeBitAnd( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitOr:
						m_result = m_exprCache.makeBitOr( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eBitXor:
						m_result = m_exprCache.makeBitXor( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eDivide:
						m_result = m_exprCache.makeDivide( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLShift:
						m_result = m_exprCache.makeLShift( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eMinus:
						m_result = m_exprCache.makeMinus( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eModulo:
						m_result = m_exprCache.makeModulo( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eRShift:
						m_result = m_exprCache.makeRShift( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eTimes:
						m_result = m_exprCache.makeTimes( expr->getType(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLogAnd:
						m_result = m_exprCache.makeLogAnd( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLogOr:
						m_result = m_exprCache.makeLogOr( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLess:
						m_result = m_exprCache.makeLess( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eLessEqual:
						m_result = m_exprCache.makeLessEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eGreater:
						m_result = m_exprCache.makeGreater( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eGreaterEqual:
						m_result = m_exprCache.makeGreaterEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eEqual:
						m_result = m_exprCache.makeEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					case expr::Kind::eNotEqual:
						m_result = m_exprCache.makeNotEqual( expr->getTypesCache(), std::move( lhs ), std::move( rhs ) );
						break;
					default:
						AST_Failure( "Unexpected binary expression" );
						m_result = ExprCloner::submit( m_exprCache, expr );
						break;
					}
				}
			}

			void visitCastExpr( expr::Cast * expr )override
			{
				TraceFunc
				auto operand = doSubmit( expr->getOperand() );

				if ( getComponentType( expr->getType() ) != type::Kind::eHalf )
				{
					visitUnaryExpr( expr );
				}
				else
				{
					m_result = ExprCloner::submit( m_exprCache, expr );
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
			{
				TraceFunc
				auto allLiterals = true;
				expr::ExprList args;

				for ( auto & init : expr->getArgList() )
				{
					args.emplace_back( doSubmit( init.get(), allLiterals ) );
				}

				m_allLiterals = m_allLiterals && allLiterals;

				if ( allLiterals )
				{
					// Flatten the composite constructs,
					// to have one initialiser per result component.
					expr::ExprList realArgs;

					for ( auto & arg : args )
					{
						auto kind = arg->getType()->getKind();
						bool processed = false;

						if ( isScalarType( kind ) == isScalarType( expr->getComponent() )
							&& isVectorType( kind ) == isVectorType( expr->getComponent() )
							&& isMatrixType( kind ) == isMatrixType( expr->getComponent() ) )
						{
							if ( args.size() == 1u
								&& getComponentsCount( expr->getComposite() ) > 1u )
							{
								processed = true;
								// Flatten constructs in the form `vec3( 0.0 )` => `vec3( 0.0, 0.0, 0.0 )`
								for ( auto i = 0u; i < getComponentsCount( expr->getComposite() ); ++i )
								{
									realArgs.emplace_back( doSubmit( arg.get() ) );
								}
							}
							else if ( getComponentCount( kind ) == getComponentCount( expr->getComponent() ) )
							{
								processed = true;
								// Same component type as expected by construct
								realArgs.emplace_back( std::move( arg ) );
							}
						}

						if ( !processed )
						{
							// Constructs like `vec4( vec3( 0.0 ), 1.0 )` => `vec4( 0.0, 0.0, 0.0, 0.0 )`
							expr::ExprList work;
							work.emplace_back( std::move( arg ) );

							while ( !work.empty() )
							{
								auto current = std::move( work.front() );
								work.erase( work.begin() );

								expr::ExprList curArgs;
								auto compKind = getComponentType( kind );
								kind = compKind;

								if ( current->getKind() == expr::Kind::eCompositeConstruct )
								{
									// `vec4( vec3( 0.0 ), 1.0 )` => `vec4( 0.0, 0.0, 0.0, 1.0 )`
									for ( auto & param : static_cast< expr::CompositeConstruct & >( *current ).getArgList() )
									{
										if ( isScalarType( compKind ) == isScalarType( expr->getComponent() )
											&& isVectorType( compKind ) == isVectorType( expr->getComponent() )
											&& isMatrixType( compKind ) == isMatrixType( expr->getComponent() )
											&& getComponentCount( compKind ) == getComponentCount( expr->getComponent() ) )
										{
											realArgs.emplace_back( doSubmit( param.get() ) );
										}
										else
										{
											work.emplace_back( doSubmit( param.get() ) );
										}
									}
								}
								else
								{
									realArgs.emplace_back( std::move( current ) );
								}
							}
						}
					}

					m_result = m_exprCache.makeCompositeConstruct( expr->getComposite()
						, expr->getComponent()
						, std::move( realArgs ) );
					
				}
				else
				{
					ExprCloner::visitCompositeConstructExpr( expr );
				}
			}

			void visitAddExpr( expr::Add * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitBitAndExpr( expr::BitAnd * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitBitNotExpr( expr::BitNot * expr )override
			{
				TraceFunc
				visitUnaryExpr( expr );
			}

			void visitBitOrExpr( expr::BitOr * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitBitXorExpr( expr::BitXor * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitDivideExpr( expr::Divide * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitEqualExpr( expr::Equal * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitGreaterExpr( expr::Greater * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitGreaterEqualExpr( expr::GreaterEqual * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				TraceFunc
				bool processed{ false };

				if ( expr->getVariable()->isConstant() )
				{
					auto it = m_literalVars.find( expr->getVariable() );

					if ( it != m_literalVars.end() )
					{
						m_result = doSubmit( it->second );
						processed = true;
					}
				}

				if ( !processed )
				{
					m_allLiterals = false;
					ExprCloner::visitIdentifierExpr( expr );
				}
			}

			void visitInitExpr( expr::Init * expr )override
			{
				TraceFunc
				auto allLiterals = true;
				auto init = doSubmit( expr->getInitialiser(), allLiterals );
				m_allLiterals = m_allLiterals && allLiterals;

				if ( init->getKind() == expr::Kind::eLiteral
					&& expr->getIdentifier()->getVariable()->isConstant() )
				{
					m_literalVars.emplace( expr->getIdentifier()->getVariable()
						, static_cast< expr::Literal * >( init.get() ) );
				}

				m_result = m_exprCache.makeInit( m_exprCache.makeIdentifier( *expr->getIdentifier() )
					, std::move( init ) );
			}

			void visitLessExpr( expr::Less * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLessEqualExpr( expr::LessEqual * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				TraceFunc
				ExprCloner::visitLiteralExpr( expr );
			}

			void visitLogAndExpr( expr::LogAnd * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLogNotExpr( expr::LogNot * expr )override
			{
				TraceFunc
				visitUnaryExpr( expr );
			}

			void visitLogOrExpr( expr::LogOr * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitLShiftExpr( expr::LShift * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitMinusExpr( expr::Minus * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitModuloExpr( expr::Modulo * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitNotEqualExpr( expr::NotEqual * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitRShiftExpr( expr::RShift * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitTimesExpr( expr::Times * expr )override
			{
				TraceFunc
				visitBinaryExpr( expr );
			}

			void visitUnaryMinusExpr( expr::UnaryMinus * expr )override
			{
				TraceFunc
				visitUnaryExpr( expr );
			}

			void visitUnaryPlusExpr( expr::UnaryPlus * expr )override
			{
				TraceFunc
				auto allLiterals = true;
				m_result = doSubmit( expr->getOperand(), allLiterals );
				m_allLiterals = m_allLiterals && allLiterals;
			}

			void visitArrayAccessExpr( expr::ArrayAccess * expr )override
			{
				TraceFunc
				if ( expr->getLHS()->getKind() == expr::Kind::eSwizzle
					&& expr->getRHS()->getKind() == expr::Kind::eLiteral )
				{
					uint32_t index = 0u;
					auto & lit = static_cast< expr::Literal const & >( *expr->getRHS() );
					assert( lit.getLiteralType() == expr::LiteralType::eInt8
						|| lit.getLiteralType() == expr::LiteralType::eInt16
						|| lit.getLiteralType() == expr::LiteralType::eInt32
						|| lit.getLiteralType() == expr::LiteralType::eInt64
						|| lit.getLiteralType() == expr::LiteralType::eUInt8
						|| lit.getLiteralType() == expr::LiteralType::eUInt16
						|| lit.getLiteralType() == expr::LiteralType::eUInt32
						|| lit.getLiteralType() == expr::LiteralType::eUInt64 );

					if ( lit.getLiteralType() == expr::LiteralType::eInt8 )
					{
						index = uint32_t( lit.getValue< expr::LiteralType::eInt8 >() );
					}
					else if ( lit.getLiteralType() == expr::LiteralType::eInt16 )
					{
						index = uint16_t( lit.getValue< expr::LiteralType::eInt16 >() );
					}
					else if ( lit.getLiteralType() == expr::LiteralType::eInt32 )
					{
						index = uint32_t( lit.getValue< expr::LiteralType::eInt32 >() );
					}
					else if ( lit.getLiteralType() == expr::LiteralType::eInt64 )
					{
						index = uint32_t( lit.getValue< expr::LiteralType::eInt64 >() );
					}
					else if ( lit.getLiteralType() == expr::LiteralType::eUInt8 )
					{
						index = lit.getValue< expr::LiteralType::eUInt8 >();
					}
					else if ( lit.getLiteralType() == expr::LiteralType::eUInt16 )
					{
						index = lit.getValue< expr::LiteralType::eUInt16 >();
					}
					else if ( lit.getLiteralType() == expr::LiteralType::eUInt32 )
					{
						index = lit.getValue< expr::LiteralType::eUInt32 >();
					}
					else
					{
						index = uint32_t( lit.getValue< expr::LiteralType::eUInt64 >() );
					}

					auto & outer = static_cast< expr::Swizzle & >( *expr->getLHS() );
					auto newOuter = doSubmit( outer.getOuterExpr() );
					m_result = doSubmit( m_exprCache.makeSwizzle( std::move( newOuter )
							, outer.getSwizzle()[index] ) );
				}
				else
				{
					m_allLiterals = false;
					ExprCloner::visitArrayAccessExpr( expr );
				}
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				TraceFunc
				m_allLiterals = false;

				if ( expr->getOuterExpr()->getKind() == expr::Kind::eSwizzle )
				{
					auto & outer = static_cast< expr::Swizzle const & >( *expr->getOuterExpr() );

					if ( expr::SwizzleKind::Value( expr->getSwizzle() ) == expr::SwizzleKind::Value( outer.getSwizzle() )
						&& expr->getType() == outer.getType() )
					{
						m_result = m_exprCache.makeSwizzle( doSubmit( outer.getOuterExpr() )
							, outer.getSwizzle() );
					}
					else
					{
						auto values = getSwizzleValues( outer.getSwizzle() );
						auto indices = getSwizzleIndices( expr->getSwizzle() );
						m_result = m_exprCache.makeSwizzle( doSubmit( outer.getOuterExpr() )
							, getFinalSwizzle( values, indices ) );
					}
				}

				if ( !m_result )
				{
					auto outer = expr->getOuterExpr();

					if ( outer->getKind() == expr::Kind::eCompositeConstruct
						&& ( expr->getSwizzle() == expr::SwizzleKind::e0
							|| expr->getSwizzle() == expr::SwizzleKind::e1
							|| expr->getSwizzle() == expr::SwizzleKind::e2
							|| expr->getSwizzle() == expr::SwizzleKind::e3 ) )
					{
						auto & compositeConstruct = static_cast< expr::CompositeConstruct const & >( *outer );

						if ( compositeConstruct.getArgList().size() == 1u
							&& type::isScalarType( compositeConstruct.getArgList().front()->getType() ) )
						{
							m_result = doSubmit( compositeConstruct.getArgList().begin()->get() );
						}
						else if ( compositeConstruct.getArgList().size() == type::getComponentCount( compositeConstruct.getType() ) )
						{
							m_result = doSubmit( std::next( compositeConstruct.getArgList().begin()
								, ptrdiff_t( expr->getSwizzle().toIndex() ) )->get() );
						}
					}
				}

				if ( !m_result )
				{
					m_result = m_exprCache.makeSwizzle( doSubmit( expr->getOuterExpr() )
						, expr->getSwizzle() );
				}
			}

		private:
			type::TypesCache & m_typesCache;
			std::map< var::VariablePtr, expr::Literal * > & m_literalVars;
			bool & m_allLiterals;
		};

		class StmtSimplifier
			: public StmtCloner
		{
		public:
			static stmt::ContainerPtr submit( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::Container * stmt )
			{
				std::map< var::VariablePtr, expr::Literal * > literalVars;
				std::vector< stmt::Container * > contStack;
				return submit( exprCache, typesCache, stmt, contStack, literalVars );
			}

		private:
			static stmt::ContainerPtr submit( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::Container * stmt
				, std::vector< stmt::Container * > & contStack
				, std::map< var::VariablePtr, expr::Literal * > & literalVars )
			{
				auto result = stmt::makeContainer();
				StmtSimplifier vis{ exprCache, typesCache, contStack, literalVars, result };
				stmt->accept( &vis );
				return result;
			}

		private:
			StmtSimplifier( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, std::vector< stmt::Container * > & contStack
				, std::map< var::VariablePtr, expr::Literal * > & literalVars
				, stmt::ContainerPtr & result )
				: StmtCloner{ exprCache, result }
				, m_typesCache{ typesCache }
				, m_contStack{ contStack }
				, m_literalVars{ literalVars }
			{
			}

			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				bool allLiterals{ true };
				return doSubmit( expr, allLiterals );
			}

			expr::ExprPtr doSubmit( expr::Expr * expr, bool & allLiterals )
			{
				return ExprSimplifier::submit( m_exprCache, m_typesCache, m_literalVars, expr, allLiterals );
			}

			void processIfStmt( stmt::Container * stmt
				, ast::expr::ExprPtr ctrlExpr
				, bool & first
				, bool & stopped
				, uint32_t & ifs
				, uint32_t & elses )
			{
				TraceFunc
				if ( stopped )
				{
					return;
				}

				auto save = m_current;
				auto cont = stmt::makeContainer();
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;

				if ( cont->empty() )
				{
					auto ifStmt = stmt::makeIf( m_exprCache.makeLogNot( m_typesCache
						, std::move( ctrlExpr ) ) );

					m_ifStmts.push_back( ifStmt.get() );
					m_current->addStmt( std::move( ifStmt ) );
					++ifs;
					first = true;
				}
				else
				{
					auto ifStmt = stmt::makeIf( std::move( ctrlExpr ) );
					m_current = ifStmt.get();
					visitContainerStmt( cont.get() );
					m_current = save;

					m_ifStmts.push_back( ifStmt.get() );
					m_current->addStmt( std::move( ifStmt ) );
					++ifs;
					first = false;
				}
			}

			void processElseIfStmt( stmt::ElseIf * stmt
				, bool & first
				, bool & stopped
				, uint32_t & ifs
				, uint32_t & elses )
			{
				TraceFunc
				if ( stopped )
				{
					return;
				}

				bool allLiterals{ true };
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr(), allLiterals );

				if ( ctrlExpr->getKind() == ast::expr::Kind::eLiteral )
				{
					auto & ctrlValue = static_cast< ast::expr::Literal const & >( *ctrlExpr );

					if ( ctrlValue.getValue< ast::expr::LiteralType::eBool >() )
					{
						processElseStmt( stmt, first, stopped, ifs, elses );
						stopped = true;
					}
				}
				else if ( first )
				{
					processIfStmt( stmt, std::move( ctrlExpr ), first, stopped, ifs, elses );
				}
				else
				{
					auto save = m_current;
					auto cont = stmt::makeContainer();
					m_current = cont.get();
					visitContainerStmt( stmt );
					m_current = save;

					if ( cont->empty() )
					{
						auto elseStmt = m_ifStmts.back()->createElse();
						m_current = elseStmt;
						auto ifStmt = stmt::makeIf( m_exprCache.makeLogNot( m_typesCache
							, std::move( ctrlExpr ) ) );

						m_ifStmts.push_back( ifStmt.get() );
						m_current->addStmt( std::move( ifStmt ) );
						m_contStack.push_back( save );
						++ifs;
						++elses;
						m_current = save;
						first = true;
					}
					else
					{
						auto elseStmt = m_ifStmts.back()->createElseIf( std::move( ctrlExpr ) );
						m_current = elseStmt;
						visitContainerStmt( cont.get() );
						m_current = save;
					}
				}
			}

			void processElseStmt( stmt::Container * stmt
				, bool & first
				, bool & stopped
				, uint32_t & ifs
				, uint32_t & elses )
			{
				TraceFunc
				if ( stopped )
				{
					return;
				}

				if ( first )
				{
					visitContainerStmt( stmt );
					first = false;
				}
				else
				{
					auto save = m_current;
					auto cont = stmt::makeContainer();
					m_current = cont.get();
					visitContainerStmt( stmt );
					m_current = save;

					if ( !cont->empty() )
					{
						auto elseStmt = m_ifStmts.back()->createElse();
						m_current = elseStmt;
						visitContainerStmt( cont.get() );
						m_current = save;
					}
				}
			}

		private:
			void visitIfStmt( stmt::If * stmt )override
			{
				TraceFunc
				bool allLiterals{ true };
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr(), allLiterals );
				bool first = true;
				bool stopped = false;
				uint32_t ifs{};
				uint32_t elses{};

				if ( ctrlExpr->getKind() == ast::expr::Kind::eLiteral )
				{
					auto & ctrlValue = static_cast< ast::expr::Literal const & >( *ctrlExpr );

					if ( ctrlValue.getValue< ast::expr::LiteralType::eBool >() )
					{
						visitContainerStmt( stmt );
						return;
					}

					if ( stmt->getElseIfList().empty() )
					{
						if ( stmt->getElse() )
						{
							visitContainerStmt( stmt->getElse() );
						}

						return;
					}
				}
				else
				{
					processIfStmt( stmt, std::move( ctrlExpr ), first, stopped, ifs, elses );
				}

				for ( auto & elseIf : stmt->getElseIfList() )
				{
					processElseIfStmt( elseIf.get(), first, stopped, ifs, elses );
				}

				if ( stmt->getElse() )
				{
					processElseStmt( stmt->getElse(), first, stopped, ifs, elses );
				}

				while ( ifs-- )
				{
					m_ifStmts.pop_back();
				}

				while ( elses-- )
				{
					m_current = m_contStack.back();
					m_contStack.pop_back();
				}
			}

		private:
			type::TypesCache & m_typesCache;
			std::vector< stmt::Container * > & m_contStack;
			std::map< var::VariablePtr, expr::Literal * > & m_literalVars;
		};
	}

	stmt::ContainerPtr simplify( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container * stmt )
	{
		return simpl::StmtSimplifier::submit( exprCache, typesCache, stmt );
	}
}
