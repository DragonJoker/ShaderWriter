#include "Common.hpp"

#include <ShaderAST/Var/Variable.hpp>
#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	using namespace ast;

	std::string getArraySizeName( uint32_t arraySize )
	{
		std::string result;

		if ( arraySize != type::NotArray )
		{
			result += "[";

			if ( arraySize != type::UnknownArraySize )
			{
				result += std::to_string( arraySize );
			}

			result += "]";
		}

		return result;
	}

	void testVariable( type::Kind kind
		, uint32_t arraySize
		, test::TestCounts & testCounts )
	{
		astTestBegin( "testVariable" + debug::getTypeName( kind ) + getArraySizeName( arraySize ) );
		type::TypesCache cache;
		type::TypePtr type;

		switch ( kind )
		{
		case type::Kind::eStruct:
			type = cache.getStruct( type::MemoryLayout::eStd140, "Dummy" );
			break;
		case type::Kind::eImage:
			type = cache.getImage( type::ImageConfiguration{} );
			break;
		case type::Kind::eCombinedImage:
			type = cache.getCombinedImage( type::ImageConfiguration{}, false );
			break;
		case type::Kind::eSampledImage:
			type = cache.getSampledImage( type::ImageConfiguration{} );
			break;
		case type::Kind::eSampler:
			type = cache.getSampler();
			break;
		default:
			type = cache.getBasicType( kind );
			break;
		}

		if ( arraySize != type::NotArray )
		{
			type = cache.getArray( type, arraySize );
		}

		auto dummyVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "dummyVar" }, type );
		astCheck( dummyVar->getId() == testCounts.nextVarId )
		astCheck( dummyVar->getBuiltin() == Builtin::eNone )
		astCheck( !dummyVar->isMemberVar() )
		astCheck( !dummyVar->getOuter() )
		{
			var::Variable coinVar{ EntityName{ testCounts.getNextVarId(), "coinVar" }, type };
			astCheck( coinVar.getId() == testCounts.nextVarId )
			astCheck( !coinVar.isMemberVar() )
			astCheck( !coinVar.getOuter() )
		}
		{
			var::Variable innerCoinVar{ EntityName{ testCounts.getNextVarId(), "innerCoinVar" }, dummyVar, type };
			astCheck( innerCoinVar.getId() == testCounts.nextVarId )
			astCheck( innerCoinVar.getOuter() == dummyVar )
			astCheck( innerCoinVar.getOutermost() == dummyVar )
			astCheck( innerCoinVar.isMemberVar() )
		}
		{
			var::Variable builtinVar{ testCounts.getNextVarId(), Builtin::eBaseInstance, type, uint64_t( var::Flag::eShaderInput ) };
			astCheck( builtinVar.getId() == testCounts.nextVarId )
			astCheck( builtinVar.isBuiltin() )
			astCheck( builtinVar.getBuiltin() == Builtin::eBaseInstance )
			astCheck( !builtinVar.isMemberVar() )
			astCheck( !builtinVar.getOuter() )
		}
		{
			auto functionVar = var::makeFunction( testCounts.getNextVarId()
				, cache.getFunction( type, {} )
				, "func" );
			astCheck( functionVar->getId() == testCounts.nextVarId )
			astCheck( !functionVar->isBuiltin() )
			astCheck( !functionVar->isMemberVar() )
			astCheck( !functionVar->getOuter() )
		}
		{
			auto functionVar = var::makeFunction( testCounts.getNextVarId()
				, cache.getFunction( type, {} )
				, "func"
				, uint64_t( var::Flag::eConstant ) );
			astCheck( functionVar->getId() == testCounts.nextVarId )
			astCheck( !functionVar->isBuiltin() )
			astCheck( !functionVar->isMemberVar() )
			astCheck( !functionVar->getOuter() )
		}
		{
			auto builtinVar = var::makeBuiltin( testCounts.getNextVarId(), Builtin::eBaseInstance, type, var::Flag::eShaderInput );
			astCheck( builtinVar->getId() == testCounts.nextVarId )
			astCheck( builtinVar->isBuiltin() )
			astCheck( builtinVar->getBuiltin() == Builtin::eBaseInstance )
			astCheck( !builtinVar->isMemberVar() )
			astCheck( !builtinVar->getOuter() )
		}
		{
			auto builtinVar = var::makeBuiltin( testCounts.getNextVarId(), Builtin::eBaseInstance, type, uint64_t( var::Flag::eShaderInput ) );
			astCheck( builtinVar->getId() == testCounts.nextVarId )
			astCheck( builtinVar->isBuiltin() )
			astCheck( builtinVar->getBuiltin() == Builtin::eBaseInstance )
			astCheck( !builtinVar->isMemberVar() )
			astCheck( !builtinVar->getOuter() )
		}
		{
			auto coinVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "coinVar" }, type );
			astCheck( coinVar->getId() == testCounts.nextVarId )
			astCheck( !coinVar->isMemberVar() )
			astCheck( !coinVar->getOuter() )
		}
		{
			auto coinVar = var::makeVariable( testCounts.getNextVarId(), type, "coinVar" );
			astCheck( coinVar->getId() == testCounts.nextVarId )
			astCheck( !coinVar->isMemberVar() )
			astCheck( !coinVar->getOuter() )
		}
		{
			auto coinVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "coinVar" }, type, var::Flag::eAlias );
			astCheck( coinVar->getId() == testCounts.nextVarId )
			astCheck( !coinVar->isMemberVar() )
			astCheck( !coinVar->getOuter() )
			astCheck( coinVar->isAlias() )
		}
		{
			auto coinVar = var::makeVariable( testCounts.getNextVarId(), type, "coinVar", var::Flag::eAlias );
			astCheck( coinVar->getId() == testCounts.nextVarId )
			astCheck( !coinVar->isMemberVar() )
			astCheck( !coinVar->getOuter() )
			astCheck( coinVar->isAlias() )
		}
		{
			auto coinVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "coinVar" }, type, uint64_t( var::Flag::eAlias ) );
			astCheck( coinVar->getId() == testCounts.nextVarId )
			astCheck( !coinVar->isMemberVar() )
			astCheck( !coinVar->getOuter() )
			astCheck( coinVar->isAlias() )
		}
		{
			auto coinVar = var::makeVariable( testCounts.getNextVarId(), type, "coinVar", uint64_t( var::Flag::eAlias ) );
			astCheck( coinVar->getId() == testCounts.nextVarId )
			astCheck( !coinVar->isMemberVar() )
			astCheck( !coinVar->getOuter() )
			astCheck( coinVar->isAlias() )
		}
		{
			auto innerVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "innerVar" }, dummyVar, type );
			astCheck( innerVar->getId() == testCounts.nextVarId )
			astCheck( innerVar->getOuter() == dummyVar )
			astCheck( innerVar->getOutermost() == dummyVar )
			astCheck( innerVar->isMemberVar() )
			{
				var::Variable innerTempVar{ EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type, var::Flag::eTemp };
				astCheck( innerTempVar.getId() == testCounts.nextVarId )
				astCheck( innerTempVar.getOuter() == innerVar )
				astCheck( innerTempVar.getOutermost() == dummyVar )
				astCheck( innerTempVar.isMemberVar() )
				astCheck( innerTempVar.isTempVar() )
			}
			{
				auto innerTempVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type );
				astCheck( innerTempVar->getId() == testCounts.nextVarId )
				astCheck( innerTempVar->getOuter() == innerVar )
				astCheck( innerTempVar->getOutermost() == dummyVar )
				astCheck( innerTempVar->isMemberVar() )
				astCheck( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = var::makeVariable( testCounts.getNextVarId(), innerVar, type, "innerTempVar" );
				astCheck( innerTempVar->getId() == testCounts.nextVarId )
				astCheck( innerTempVar->getOuter() == innerVar )
				astCheck( innerTempVar->getOutermost() == dummyVar )
				astCheck( innerTempVar->isMemberVar() )
				astCheck( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type, var::Flag::eTemp );
				astCheck( innerTempVar->getId() == testCounts.nextVarId )
				astCheck( innerTempVar->getOuter() == innerVar )
				astCheck( innerTempVar->getOutermost() == dummyVar )
				astCheck( innerTempVar->isMemberVar() )
				astCheck( innerTempVar->isTempVar() )
				astCheck( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = var::makeVariable( testCounts.getNextVarId(), innerVar, type, "innerTempVar", var::Flag::eTemp );
				astCheck( innerTempVar->getId() == testCounts.nextVarId )
				astCheck( innerTempVar->getOuter() == innerVar )
				astCheck( innerTempVar->getOutermost() == dummyVar )
				astCheck( innerTempVar->isMemberVar() )
				astCheck( innerTempVar->isTempVar() )
				astCheck( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "innerTempVar" }, innerVar, type, uint64_t( var::Flag::eTemp ) );
				astCheck( innerTempVar->getId() == testCounts.nextVarId )
				astCheck( innerTempVar->getOuter() == innerVar )
				astCheck( innerTempVar->getOutermost() == dummyVar )
				astCheck( innerTempVar->isMemberVar() )
				astCheck( innerTempVar->isTempVar() )
				astCheck( getOutermost( innerTempVar ) == dummyVar )
			}
			{
				auto innerTempVar = var::makeVariable( testCounts.getNextVarId(), innerVar, type, "innerTempVar", uint64_t( var::Flag::eTemp ) );
				astCheck( innerTempVar->getId() == testCounts.nextVarId )
				astCheck( innerTempVar->getOuter() == innerVar )
				astCheck( innerTempVar->getOutermost() == dummyVar )
				astCheck( innerTempVar->isMemberVar() )
				astCheck( innerTempVar->isTempVar() )
				astCheck( getOutermost( innerTempVar ) == dummyVar )
			}
		}
		astCheck( getNonArrayKind( dummyVar->getType() ) == kind )
		astCheck( getArraySize( dummyVar->getType() ) == arraySize )
		astCheck( dummyVar->getName() == "dummyVar" )
		{
			astCheck( !dummyVar->isShaderOutput() )
			dummyVar->updateFlag( var::Flag::eShaderOutput );
			astCheck( dummyVar->isShaderOutput() )
			astCheck( !dummyVar->isShaderInput() )
			dummyVar->updateFlag( var::Flag::eShaderInput );
			astCheck( dummyVar->isShaderInput() )
			astCheck( !dummyVar->isLocale() )
			dummyVar->updateFlag( var::Flag::eLocale );
			astCheck( dummyVar->isLocale() )
			astCheck( !dummyVar->isUniform() )
			dummyVar->updateFlag( var::Flag::eUniform );
			astCheck( dummyVar->isUniform() )
			astCheck( !dummyVar->isImplicit() )
			dummyVar->updateFlag( var::Flag::eImplicit );
			astCheck( dummyVar->isImplicit() )
			astCheck( !dummyVar->isFlat() )
			dummyVar->updateFlag( var::Flag::eFlat );
			astCheck( dummyVar->isFlat() )
			astCheck( !dummyVar->isLoopVar() )
			dummyVar->updateFlag( var::Flag::eLoopVar );
			astCheck( dummyVar->isLoopVar() )
			astCheck( !dummyVar->isMember() )
			dummyVar->updateFlag( var::Flag::eMember );
			astCheck( dummyVar->isMember() )
			astCheck( !dummyVar->isNoPerspective() )
			dummyVar->updateFlag( var::Flag::eNoPerspective );
			astCheck( dummyVar->isNoPerspective() )
			astCheck( !dummyVar->isPatch() )
			astCheck( !dummyVar->isPatchInput() )
			dummyVar->updateFlag( var::Flag::ePatchInput );
			astCheck( dummyVar->isPatchInput() )
			astCheck( !dummyVar->isPatchOutput() )
			dummyVar->updateFlag( var::Flag::ePatchOutput );
			astCheck( dummyVar->isPatchOutput() )
			astCheck( dummyVar->isPatch() )
			astCheck( !dummyVar->isCentroid() )
			dummyVar->updateFlag( var::Flag::eCentroid );
			astCheck( dummyVar->isCentroid() )
			astCheck( !dummyVar->isPerSample() )
			dummyVar->updateFlag( var::Flag::ePerSample );
			astCheck( dummyVar->isPerSample() )
			astCheck( !dummyVar->isGeometryStream() )
			dummyVar->updateFlag( var::Flag::eGeometryStream );
			astCheck( dummyVar->isGeometryStream() )
			astCheck( !dummyVar->isBlendIndex() )
			dummyVar->updateFlag( var::Flag::eBlendIndex );
			astCheck( dummyVar->isBlendIndex() )
			astCheck( !dummyVar->isTempVar() )
			dummyVar->updateFlag( var::Flag::eTemp );
			astCheck( dummyVar->isTempVar() )
			astCheck( !dummyVar->isAlias() )
			dummyVar->updateFlag( var::Flag::eAlias );
			astCheck( dummyVar->isAlias() )
			astCheck( !dummyVar->isStorageBuffer() )
			dummyVar->updateFlag( var::Flag::eStorageBuffer );
			astCheck( dummyVar->isStorageBuffer() )
			astCheck( !dummyVar->isIncomingRayPayload() )
			dummyVar->updateFlag( var::Flag::eIncomingRayPayload );
			astCheck( dummyVar->isIncomingRayPayload() )
			astCheck( !dummyVar->isRayPayload() )
			dummyVar->updateFlag( var::Flag::eRayPayload );
			astCheck( dummyVar->isRayPayload() )
			astCheck( !dummyVar->isIncomingCallableData() )
			dummyVar->updateFlag( var::Flag::eIncomingCallableData );
			astCheck( dummyVar->isIncomingCallableData() )
			astCheck( !dummyVar->isCallableData() )
			dummyVar->updateFlag( var::Flag::eCallableData );
			astCheck( dummyVar->isCallableData() )
			astCheck( !dummyVar->isHitAttribute() )
			dummyVar->updateFlag( var::Flag::eHitAttribute );
			astCheck( dummyVar->isHitAttribute() )
			astCheck( !dummyVar->isBufferReference() )
			dummyVar->updateFlag( var::Flag::eBufferReference );
			astCheck( dummyVar->isBufferReference() )
			astCheck( !dummyVar->isPerPrimitive() )
			dummyVar->updateFlag( var::Flag::ePerPrimitive );
			astCheck( dummyVar->isPerPrimitive() )
			astCheck( !dummyVar->isPerView() )
			dummyVar->updateFlag( var::Flag::ePerView );
			astCheck( dummyVar->isPerView() )
			astCheck( !dummyVar->isPerTaskNV() )
			dummyVar->updateFlag( var::Flag::ePerTaskNV );
			astCheck( dummyVar->isPerTaskNV() )
			astCheck( !dummyVar->isPerTask() )
			dummyVar->updateFlag( var::Flag::ePerTask );
			astCheck( dummyVar->isPerTask() )
			astCheck( !dummyVar->isShared() )
			dummyVar->updateFlag( var::Flag::eShared );
			astCheck( dummyVar->isShared() )
			dummyVar->updateFlag( var::Flag::eShared, false );
			astCheck( !dummyVar->isShared() )
		}
		{
			uint64_t flags{};
			flags = flags | var::Flag::eShared;
			astCheck( checkFlag( flags, var::Flag::eShared ) )
			flags = var::Flag::ePerTask | flags;
			astCheck( checkFlag( flags, var::Flag::ePerTask ) )
		}
		astTestEnd()
	}
}

astTestSuiteMain( TestASTVariables )
{
	astTestSuiteBegin();
	for ( uint8_t i = uint8_t( type::Kind::eMin ); i < uint8_t( type::Kind::eArray ); ++i )
	{
		testVariable( type::Kind( i ), type::NotArray, testCounts );
	}

	for ( uint8_t i = uint8_t( type::Kind::eMin ); i < uint8_t( type::Kind::eArray ); ++i )
	{
		testVariable( type::Kind( i ), type::UnknownArraySize, testCounts );
	}

	for ( uint8_t i = uint8_t( type::Kind::eMin ); i < uint8_t( type::Kind::eArray ); ++i )
	{
		testVariable( type::Kind( i ), 3u, testCounts );
	}
	astTestSuiteEnd();
}

astTestSuiteLaunch( TestASTVariables )
