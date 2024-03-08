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
		astCheckEqual( dummyVar->getId(), testCounts.nextVarId )
		astCheckEqual( dummyVar->getBuiltin(), Builtin::eNone )
		astCheck( !dummyVar->isMemberVar() )
		astCheck( !dummyVar->getOuter() )
		astCheckEqual( dummyVar->getFullName(), "dummyVar" )
		{
			var::Variable var{ EntityName{ testCounts.getNextVarId(), "var" }, type };
			astCheckEqual( var.getId(), testCounts.nextVarId )
			astCheck( !var.isMemberVar() )
			astCheck( !var.getOuter() )
			astCheckEqual( var.getFullName(), "var" )
		}
		{
			var::Variable var{ EntityName{ testCounts.getNextVarId(), "var" }, dummyVar, type };
			astCheckEqual( var.getId(), testCounts.nextVarId )
			astCheck( var.getOuter() == dummyVar )
			astCheck( var.getOutermost() == dummyVar )
			astCheck( var.isMemberVar() )
			astCheckEqual( var.getFullName(), "dummyVar.var" )
		}
		{
			var::Variable var{ testCounts.getNextVarId(), Builtin::eBaseInstance, type, uint64_t( var::Flag::eShaderInput ) };
			astCheckEqual( var.getId(), testCounts.nextVarId )
			astCheck( var.isBuiltin() )
			astCheckEqual( var.getBuiltin(), Builtin::eBaseInstance )
			astCheck( !var.isMemberVar() )
			astCheck( !var.getOuter() )
		}
		{
			auto var = var::makeFunction( testCounts.getNextVarId()
				, cache.getFunction( type, {} )
				, "func" );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isBuiltin() )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeFunction( testCounts.getNextVarId()
				, cache.getFunction( type, {} )
				, "func"
				, uint64_t( var::Flag::eConstant ) );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isBuiltin() )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeFunction( { testCounts.getNextVarId(), "func" }
				, cache.getFunction( type, {} ) );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isBuiltin() )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeFunction( { testCounts.getNextVarId(), "func" }
				, cache.getFunction( type, {} )
				, uint64_t( var::Flag::eConstant ) );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isBuiltin() )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeBuiltin( testCounts.getNextVarId(), Builtin::eBaseInstance, type, var::Flag::eShaderInput );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( var->isBuiltin() )
			astCheckEqual( var->getBuiltin(),Builtin::eBaseInstance )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeBuiltin( testCounts.getNextVarId(), Builtin::eBaseInstance, type, uint64_t( var::Flag::eShaderInput ) );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( var->isBuiltin() )
			astCheckEqual( var->getBuiltin(),Builtin::eBaseInstance )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeBuiltin( testCounts.getNextVarId(), Builtin::ePrimitiveID, type, var::Flag::eShaderOutput );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( var->isBuiltin() )
			astCheckEqual( var->getBuiltin(),Builtin::ePrimitiveID )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeBuiltin( testCounts.getNextVarId(), Builtin::ePrimitiveID, type, uint64_t( var::Flag::eShaderOutput ) );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( var->isBuiltin() )
			astCheckEqual( var->getBuiltin(),Builtin::ePrimitiveID )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeVariable( EntityName{ testCounts.getNextVarId(), "var" }, type );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeVariable( testCounts.getNextVarId(), type, "var" );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
		}
		{
			auto var = var::makeVariable( EntityName{ testCounts.getNextVarId(), "var" }, type, var::Flag::eAlias );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
			astCheck( var->isAlias() )
		}
		{
			auto var = var::makeVariable( testCounts.getNextVarId(), type, "var", var::Flag::eAlias );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
			astCheck( var->isAlias() )
		}
		{
			auto var = var::makeVariable( EntityName{ testCounts.getNextVarId(), "var" }, type, uint64_t( var::Flag::eAlias ) );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
			astCheck( var->isAlias() )
		}
		{
			auto var = var::makeVariable( testCounts.getNextVarId(), type, "var", uint64_t( var::Flag::eAlias ) );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( !var->isMemberVar() )
			astCheck( !var->getOuter() )
			astCheck( var->isAlias() )
		}
		{
			auto var = var::makeVariable( EntityName{ testCounts.getNextVarId(), "var" }, dummyVar, type );
			astCheckEqual( var->getId(), testCounts.nextVarId )
			astCheck( var->getOuter() == dummyVar )
			astCheck( var->getOutermost() == dummyVar )
			astCheck( var->isMemberVar() )
			{
				var::Variable tempVar{ EntityName{ testCounts.getNextVarId(), "tempVar" }, var, type, var::Flag::eTemp };
				astCheck( tempVar.getId() == testCounts.nextVarId )
				astCheck( tempVar.getOuter() == var )
				astCheck( tempVar.getOutermost() == dummyVar )
				astCheck( tempVar.isMemberVar() )
				astCheck( tempVar.isTempVar() )
			}
			{
				auto tempVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "tempVar" }, var, type );
				astCheckEqual( tempVar->getId(), testCounts.nextVarId )
				astCheck( tempVar->getOuter() == var )
				astCheckEqual( tempVar->getOutermost(), dummyVar )
				astCheck( tempVar->isMemberVar() )
				astCheck( getOutermost( tempVar ) == dummyVar )
			}
			{
				auto tempVar = var::makeVariable( testCounts.getNextVarId(), var, type, "tempVar" );
				astCheckEqual( tempVar->getId(), testCounts.nextVarId )
				astCheck( tempVar->getOuter() == var )
				astCheckEqual( tempVar->getOutermost(), dummyVar )
				astCheck( tempVar->isMemberVar() )
				astCheck( getOutermost( tempVar ) == dummyVar )
			}
			{
				auto tempVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "tempVar" }, var, type, var::Flag::eTemp );
				astCheckEqual( tempVar->getId(), testCounts.nextVarId )
				astCheck( tempVar->getOuter() == var )
				astCheckEqual( tempVar->getOutermost(), dummyVar )
				astCheck( tempVar->isMemberVar() )
				astCheck( tempVar->isTempVar() )
				astCheck( getOutermost( tempVar ) == dummyVar )
			}
			{
				auto tempVar = var::makeVariable( testCounts.getNextVarId(), var, type, "tempVar", var::Flag::eTemp );
				astCheckEqual( tempVar->getId(), testCounts.nextVarId )
				astCheck( tempVar->getOuter() == var )
				astCheckEqual( tempVar->getOutermost(), dummyVar )
				astCheck( tempVar->isMemberVar() )
				astCheck( tempVar->isTempVar() )
				astCheck( getOutermost( tempVar ) == dummyVar )
			}
			{
				auto tempVar = var::makeVariable( EntityName{ testCounts.getNextVarId(), "tempVar" }, var, type, uint64_t( var::Flag::eTemp ) );
				astCheckEqual( tempVar->getId(), testCounts.nextVarId )
				astCheck( tempVar->getOuter() == var )
				astCheckEqual( tempVar->getOutermost(), dummyVar )
				astCheck( tempVar->isMemberVar() )
				astCheck( tempVar->isTempVar() )
				astCheck( getOutermost( tempVar ) == dummyVar )
			}
			{
				auto tempVar = var::makeVariable( testCounts.getNextVarId(), var, type, "tempVar", uint64_t( var::Flag::eTemp ) );
				astCheckEqual( tempVar->getId(), testCounts.nextVarId )
				astCheck( tempVar->getOuter() == var )
				astCheckEqual( tempVar->getOutermost(), dummyVar )
				astCheck( tempVar->isMemberVar() )
				astCheck( tempVar->isTempVar() )
				astCheck( getOutermost( tempVar ) == dummyVar )
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
	for ( auto i = uint8_t( type::Kind::eMin ); i < uint8_t( type::Kind::eArray ); ++i )
	{
		testVariable( type::Kind( i ), type::NotArray, testCounts );
	}

	for ( auto i = uint8_t( type::Kind::eMin ); i < uint8_t( type::Kind::eArray ); ++i )
	{
		testVariable( type::Kind( i ), type::UnknownArraySize, testCounts );
	}

	for ( auto i = uint8_t( type::Kind::eMin ); i < uint8_t( type::Kind::eArray ); ++i )
	{
		testVariable( type::Kind( i ), 3u, testCounts );
	}
	astTestSuiteEnd()
}

astTestSuiteLaunch( TestASTVariables )
