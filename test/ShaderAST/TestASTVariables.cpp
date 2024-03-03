#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	std::string printVariable( ast::var::Variable const & var )
	{
		std::string result;
		result += ast::debug::getTypeName( var.getType() ) + " " + var.getName();
		return result;
	}

	void testVariable( ast::type::Kind kind
		, uint32_t arraySize
		, test::TestCounts & testCounts )
	{
		ast::type::TypesCache cache;
		ast::type::TypePtr type;

		switch ( kind )
		{
		case ast::type::Kind::eStruct:
			type = cache.getStruct( ast::type::MemoryLayout::eStd140, "Dummy" );
			break;
		case ast::type::Kind::eImage:
			type = cache.getImage( ast::type::ImageConfiguration{} );
			break;
		case ast::type::Kind::eCombinedImage:
			type = cache.getCombinedImage( ast::type::ImageConfiguration{}, false );
			break;
		case ast::type::Kind::eSampledImage:
			type = cache.getSampledImage( ast::type::ImageConfiguration{} );
			break;
		case ast::type::Kind::eSampler:
			type = cache.getSampler();
			break;
		default:
			type = cache.getBasicType( kind );
			break;
		}

		if ( arraySize != ast::type::NotArray )
		{
			type = cache.getArray( type, arraySize );
		}

		auto dummyVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "dummyVar" }, type );
		check( dummyVar->getId() == testCounts.nextVarId )
		check( dummyVar->getBuiltin() == ast::Builtin::eNone )
		check( !dummyVar->isMemberVar() )
		check( !dummyVar->getOuter() )
		{
			ast::var::Variable coinVar{ ast::EntityName{ testCounts.getNextVarId(), "coinVar" }, type };
			check( coinVar.getId() == testCounts.nextVarId )
			check( !coinVar.isMemberVar() )
			check( !coinVar.getOuter() )
		}
		{
			ast::var::Variable innerCoinVar{ ast::EntityName{ testCounts.getNextVarId(), "innerCoinVar" }, dummyVar, type };
			check( innerCoinVar.getId() == testCounts.nextVarId )
			check( innerCoinVar.getOuter() == dummyVar )
			check( innerCoinVar.getOutermost() == dummyVar )
			check( innerCoinVar.isMemberVar() )
		}
		{
			ast::var::Variable builtinVar{ testCounts.getNextVarId(), ast::Builtin::eBaseInstance, type, uint64_t( ast::var::Flag::eShaderInput ) };
			check( builtinVar.getId() == testCounts.nextVarId )
			check( builtinVar.isBuiltin() )
			check( builtinVar.getBuiltin() == ast::Builtin::eBaseInstance )
			check( !builtinVar.isMemberVar() )
			check( !builtinVar.getOuter() )
		}
		{
			auto functionVar = ast::var::makeFunction( testCounts.getNextVarId()
				, cache.getFunction( type, {} )
				, "func" );
			check( functionVar->getId() == testCounts.nextVarId )
			check( !functionVar->isBuiltin() )
			check( !functionVar->isMemberVar() )
			check( !functionVar->getOuter() )
		}
		{
			auto functionVar = ast::var::makeFunction( testCounts.getNextVarId()
				, cache.getFunction( type, {} )
				, "func"
				, uint64_t( ast::var::Flag::eConstant ) );
			check( functionVar->getId() == testCounts.nextVarId )
			check( !functionVar->isBuiltin() )
			check( !functionVar->isMemberVar() )
			check( !functionVar->getOuter() )
		}
		{
			auto builtinVar = ast::var::makeBuiltin( testCounts.getNextVarId(), ast::Builtin::eBaseInstance, type, ast::var::Flag::eShaderInput );
			check( builtinVar->getId() == testCounts.nextVarId )
			check( builtinVar->isBuiltin() )
			check( builtinVar->getBuiltin() == ast::Builtin::eBaseInstance )
			check( !builtinVar->isMemberVar() )
			check( !builtinVar->getOuter() )
		}
		{
			auto builtinVar = ast::var::makeBuiltin( testCounts.getNextVarId(), ast::Builtin::eBaseInstance, type, uint64_t( ast::var::Flag::eShaderInput ) );
			check( builtinVar->getId() == testCounts.nextVarId )
			check( builtinVar->isBuiltin() )
			check( builtinVar->getBuiltin() == ast::Builtin::eBaseInstance )
			check( !builtinVar->isMemberVar() )
			check( !builtinVar->getOuter() )
		}
		{
			auto coinVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "coinVar" }, type );
			check( coinVar->getId() == testCounts.nextVarId )
			check( !coinVar->isMemberVar() )
			check( !coinVar->getOuter() )
		}
		{
			auto coinVar = ast::var::makeVariable( testCounts.getNextVarId(), type, "coinVar" );
			check( coinVar->getId() == testCounts.nextVarId )
			check( !coinVar->isMemberVar() )
			check( !coinVar->getOuter() )
		}
		{
			auto coinVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "coinVar" }, type, ast::var::Flag::eAlias );
			check( coinVar->getId() == testCounts.nextVarId )
			check( !coinVar->isMemberVar() )
			check( !coinVar->getOuter() )
			check( coinVar->isAlias() )
		}
		{
			auto coinVar = ast::var::makeVariable( testCounts.getNextVarId(), type, "coinVar", ast::var::Flag::eAlias );
			check( coinVar->getId() == testCounts.nextVarId )
			check( !coinVar->isMemberVar() )
			check( !coinVar->getOuter() )
			check( coinVar->isAlias() )
		}
		{
			auto coinVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "coinVar" }, type, uint64_t( ast::var::Flag::eAlias ) );
			check( coinVar->getId() == testCounts.nextVarId )
			check( !coinVar->isMemberVar() )
			check( !coinVar->getOuter() )
			check( coinVar->isAlias() )
		}
		{
			auto coinVar = ast::var::makeVariable( testCounts.getNextVarId(), type, "coinVar", uint64_t( ast::var::Flag::eAlias ) );
			check( coinVar->getId() == testCounts.nextVarId )
			check( !coinVar->isMemberVar() )
			check( !coinVar->getOuter() )
			check( coinVar->isAlias() )
		}
		{
			auto innerVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "innerVar" }, dummyVar, type );
			check( innerVar->getId() == testCounts.nextVarId )
			check( innerVar->getOuter() == dummyVar )
			check( innerVar->getOutermost() == dummyVar )
			check( innerVar->isMemberVar() )
			{
				ast::var::Variable innerTempVar{ ast::EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type, ast::var::Flag::eTemp };
				check( innerTempVar.getId() == testCounts.nextVarId )
				check( innerTempVar.getOuter() == innerVar )
				check( innerTempVar.getOutermost() == dummyVar )
				check( innerTempVar.isMemberVar() )
				check( innerTempVar.isTempVar() )
			}
			{
				auto innerTempVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type );
				check( innerTempVar->getId() == testCounts.nextVarId )
				check( innerTempVar->getOuter() == innerVar )
				check( innerTempVar->getOutermost() == dummyVar )
				check( innerTempVar->isMemberVar() )
				check( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = ast::var::makeVariable( testCounts.getNextVarId(), innerVar, type, "innerTempVar" );
				check( innerTempVar->getId() == testCounts.nextVarId )
				check( innerTempVar->getOuter() == innerVar )
				check( innerTempVar->getOutermost() == dummyVar )
				check( innerTempVar->isMemberVar() )
				check( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type, ast::var::Flag::eTemp );
				check( innerTempVar->getId() == testCounts.nextVarId )
				check( innerTempVar->getOuter() == innerVar )
				check( innerTempVar->getOutermost() == dummyVar )
				check( innerTempVar->isMemberVar() )
				check( innerTempVar->isTempVar() )
				check( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = ast::var::makeVariable( testCounts.getNextVarId(), innerVar, type, "innerTempVar", ast::var::Flag::eTemp );
				check( innerTempVar->getId() == testCounts.nextVarId )
				check( innerTempVar->getOuter() == innerVar )
				check( innerTempVar->getOutermost() == dummyVar )
				check( innerTempVar->isMemberVar() )
				check( innerTempVar->isTempVar() )
				check( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = ast::var::makeVariable( ast::EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type, uint64_t( ast::var::Flag::eTemp ) );
				check( innerTempVar->getId() == testCounts.nextVarId )
				check( innerTempVar->getOuter() == innerVar )
				check( innerTempVar->getOutermost() == dummyVar )
				check( innerTempVar->isMemberVar() )
				check( innerTempVar->isTempVar() )
				check( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = ast::var::makeVariable( testCounts.getNextVarId(), innerVar, type, "innerTempVar", uint64_t( ast::var::Flag::eTemp ) );
				check( innerTempVar->getId() == testCounts.nextVarId )
				check( innerTempVar->getOuter() == innerVar )
				check( innerTempVar->getOutermost() == dummyVar )
				check( innerTempVar->isMemberVar() )
				check( innerTempVar->isTempVar() )
				check( getOutermost( innerTempVar ) == dummyVar )
			}
		}
		testCounts << printVariable( *dummyVar ) << test::endl;
		check( getNonArrayKind( dummyVar->getType() ) == kind )
		check( getArraySize( dummyVar->getType() ) == arraySize )
		check( dummyVar->getName() == "dummyVar" )
		{
			check( !dummyVar->isShaderOutput() )
			dummyVar->updateFlag( ast::var::Flag::eShaderOutput );
			check( dummyVar->isShaderOutput() )
			check( !dummyVar->isShaderInput() )
			dummyVar->updateFlag( ast::var::Flag::eShaderInput );
			check( dummyVar->isShaderInput() )
			check( !dummyVar->isLocale() )
			dummyVar->updateFlag( ast::var::Flag::eLocale );
			check( dummyVar->isLocale() )
			check( !dummyVar->isUniform() )
			dummyVar->updateFlag( ast::var::Flag::eUniform );
			check( dummyVar->isUniform() )
			check( !dummyVar->isImplicit() )
			dummyVar->updateFlag( ast::var::Flag::eImplicit );
			check( dummyVar->isImplicit() )
			check( !dummyVar->isFlat() )
			dummyVar->updateFlag( ast::var::Flag::eFlat );
			check( dummyVar->isFlat() )
			check( !dummyVar->isLoopVar() )
			dummyVar->updateFlag( ast::var::Flag::eLoopVar );
			check( dummyVar->isLoopVar() )
			check( !dummyVar->isMember() )
			dummyVar->updateFlag( ast::var::Flag::eMember );
			check( dummyVar->isMember() )
			check( !dummyVar->isNoPerspective() )
			dummyVar->updateFlag( ast::var::Flag::eNoPerspective );
			check( dummyVar->isNoPerspective() )
			check( !dummyVar->isPatch() )
			check( !dummyVar->isPatchInput() )
			dummyVar->updateFlag( ast::var::Flag::ePatchInput );
			check( dummyVar->isPatchInput() )
			check( !dummyVar->isPatchOutput() )
			dummyVar->updateFlag( ast::var::Flag::ePatchOutput );
			check( dummyVar->isPatchOutput() )
			check( dummyVar->isPatch() )
			check( !dummyVar->isCentroid() )
			dummyVar->updateFlag( ast::var::Flag::eCentroid );
			check( dummyVar->isCentroid() )
			check( !dummyVar->isPerSample() )
			dummyVar->updateFlag( ast::var::Flag::ePerSample );
			check( dummyVar->isPerSample() )
			check( !dummyVar->isGeometryStream() )
			dummyVar->updateFlag( ast::var::Flag::eGeometryStream );
			check( dummyVar->isGeometryStream() )
			check( !dummyVar->isBlendIndex() )
			dummyVar->updateFlag( ast::var::Flag::eBlendIndex );
			check( dummyVar->isBlendIndex() )
			check( !dummyVar->isTempVar() )
			dummyVar->updateFlag( ast::var::Flag::eTemp );
			check( dummyVar->isTempVar() )
			check( !dummyVar->isAlias() )
			dummyVar->updateFlag( ast::var::Flag::eAlias );
			check( dummyVar->isAlias() )
			check( !dummyVar->isStorageBuffer() )
			dummyVar->updateFlag( ast::var::Flag::eStorageBuffer );
			check( dummyVar->isStorageBuffer() )
			check( !dummyVar->isIncomingRayPayload() )
			dummyVar->updateFlag( ast::var::Flag::eIncomingRayPayload );
			check( dummyVar->isIncomingRayPayload() )
			check( !dummyVar->isRayPayload() )
			dummyVar->updateFlag( ast::var::Flag::eRayPayload );
			check( dummyVar->isRayPayload() )
			check( !dummyVar->isIncomingCallableData() )
			dummyVar->updateFlag( ast::var::Flag::eIncomingCallableData );
			check( dummyVar->isIncomingCallableData() )
			check( !dummyVar->isCallableData() )
			dummyVar->updateFlag( ast::var::Flag::eCallableData );
			check( dummyVar->isCallableData() )
			check( !dummyVar->isHitAttribute() )
			dummyVar->updateFlag( ast::var::Flag::eHitAttribute );
			check( dummyVar->isHitAttribute() )
			check( !dummyVar->isBufferReference() )
			dummyVar->updateFlag( ast::var::Flag::eBufferReference );
			check( dummyVar->isBufferReference() )
			check( !dummyVar->isPerPrimitive() )
			dummyVar->updateFlag( ast::var::Flag::ePerPrimitive );
			check( dummyVar->isPerPrimitive() )
			check( !dummyVar->isPerView() )
			dummyVar->updateFlag( ast::var::Flag::ePerView );
			check( dummyVar->isPerView() )
			check( !dummyVar->isPerTaskNV() )
			dummyVar->updateFlag( ast::var::Flag::ePerTaskNV );
			check( dummyVar->isPerTaskNV() )
			check( !dummyVar->isPerTask() )
			dummyVar->updateFlag( ast::var::Flag::ePerTask );
			check( dummyVar->isPerTask() )
			check( !dummyVar->isShared() )
			dummyVar->updateFlag( ast::var::Flag::eShared );
			check( dummyVar->isShared() )
			dummyVar->updateFlag( ast::var::Flag::eShared, false );
			check( !dummyVar->isShared() )
		}
		{
			uint64_t flags{};
			flags = flags | ast::var::Flag::eShared;
			check( checkFlag( flags, ast::var::Flag::eShared ) )
			flags = ast::var::Flag::ePerTask | flags;
			check( checkFlag( flags, ast::var::Flag::ePerTask ) )
		}
	}

	void testVariable( test::TestCounts & testCounts )
	{
		testBegin( "testVariable" );
		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eArray ); ++i )
		{
			testVariable( ast::type::Kind( i ), ast::type::NotArray, testCounts );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eArray ); ++i )
		{
			testVariable( ast::type::Kind( i ), ast::type::UnknownArraySize, testCounts );
		}

		for ( uint8_t i = uint8_t( ast::type::Kind::eMin ); i < uint8_t( ast::type::Kind::eArray ); ++i )
		{
			testVariable( ast::type::Kind( i ), 3u, testCounts );
		}
		testEnd();
	}
}

testSuiteMain( TestASTVariables )
{
	testSuiteBegin();
	testVariable( testCounts );
	testSuiteEnd();
}

testSuiteLaunch( TestASTVariables )
