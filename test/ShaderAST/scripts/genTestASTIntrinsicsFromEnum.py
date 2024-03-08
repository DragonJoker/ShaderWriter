import os, re, sys

def typeKindToGlslType( kind ):
	result = kind.replace( "type::Kind::e", "" )
	result = result.lower()
	return result

def printHeader( outs, match ):
	enumName = match.group( 1 )
	outs.write( '#include "Common.hpp"\n' )
	outs.write( '\n' )
	outs.write( '#include <ShaderAST/Expr/Expr' + enumName + 'Call.hpp>\n' )
	outs.write( '#include <ShaderAST/Expr/Make' + enumName + '.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/DebugDisplayStatements.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/GetExprName.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/GetOutermostExpr.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/ResolveConstants.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/SimplifyStatements.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/SpecialiseStatements.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/TransformSSA.hpp>\n' )
	outs.write( '\n' )
	outs.write( 'namespace checks\n' )
	outs.write( '{\n' )
	outs.write( '\tusing namespace ast;\n' )
	outs.write( '\n' )
	outs.write( '\tstatic expr::ExprList makeList( expr::ExprPtr arg0\n' )
	outs.write( '\t\t, expr::ExprPtr arg1 )\n' )
	outs.write( '\t{\n' )
	outs.write( '\t\texpr::ExprList result;\n' )
	outs.write( '\t\tresult.push_back( std::move( arg0 ) );\n' )
	outs.write( '\t\tresult.push_back( std::move( arg1 ) );\n' )
	outs.write( '\t\treturn result;\n' )
	outs.write( '\t}\n' )
	outs.write( '\n' )
	outs.write( '\tstatic expr::ExprList makeList( expr::ExprPtr arg0\n' )
	outs.write( '\t\t, expr::ExprPtr arg1\n' )
	outs.write( '\t\t, expr::ExprPtr arg2 )\n' )
	outs.write( '\t{\n' )
	outs.write( '\t\texpr::ExprList result;\n' )
	outs.write( '\t\tresult.push_back( std::move( arg0 ) );\n' )
	outs.write( '\t\tresult.push_back( std::move( arg1 ) );\n' )
	outs.write( '\t\tresult.push_back( std::move( arg2 ) );\n' )
	outs.write( '\t\treturn result;\n' )
	outs.write( '\t}\n' )
	outs.write( '\n' )
	outs.write( '\tstatic expr::ExprList makeList( expr::ExprPtr arg0\n' )
	outs.write( '\t\t, expr::ExprPtr arg1\n' )
	outs.write( '\t\t, expr::ExprPtr arg2\n' )
	outs.write( '\t\t, expr::ExprPtr arg3 )\n' )
	outs.write( '\t{\n' )
	outs.write( '\t\texpr::ExprList result;\n' )
	outs.write( '\t\tresult.push_back( std::move( arg0 ) );\n' )
	outs.write( '\t\tresult.push_back( std::move( arg1 ) );\n' )
	outs.write( '\t\tresult.push_back( std::move( arg2 ) );\n' )
	outs.write( '\t\tresult.push_back( std::move( arg3 ) );\n' )
	outs.write( '\t\treturn result;\n' )
	outs.write( '\t}\n' )
	outs.write( '\n' )
	outs.write( '\tstatic stmt::ContainerPtr makeContainer( stmt::StmtCache & stmtCache\n' )
	outs.write( '\t\t, expr::Expr const & expr )\n' )
	outs.write( '\t{\n' )
	outs.write( '\t\tauto container = stmtCache.makeContainer();\n' )
	outs.write( '\t\tcontainer->addStmt( stmtCache.makeSimple( expr.clone() ) );\n' )
	outs.write( '\t\treturn container;\n' )
	outs.write( '\t}\n' )
	outs.write( '\n' )
	outs.write( '\tstatic void checkExprDependant( test::TestCounts & testCounts\n' )
	outs.write( '\t\t, expr::' + enumName + 'Call const & expr\n' )
	outs.write( '\t\t, std::string const & function\n' )
	outs.write( '\t\t, int line )\n' )
	outs.write( '\t{\n' )
	outs.write( '\t\tauto & exprCache = expr.getExprCache();\n' )
	outs.write( '\t\tauto & typesCache = expr.getTypesCache();\n' )
	outs.write( '\n' )
	outs.write( '\t\tif ( astOn( debug::displayExpression( expr ) ) )\n' )
	outs.write( '\t\t{\n' )
	outs.write( '\t\t\texpr::ExprPtr tmp;\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, tmp = simplify( exprCache, typesCache, expr ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, resolveConstants( exprCache, *tmp ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, getOutermostExpr( expr ) )\n' )
	outs.write( '\n' )
	outs.write( '\t\t\tauto clone = expr.clone();\n' )
	outs.write( '\t\t\tclone->updateFlag( expr::Flag::eNonUniform );\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, debug::displayExpression( *clone ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, tmp = simplify( exprCache, typesCache, *clone ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, resolveConstants( exprCache, *tmp ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, getOutermostExpr( *clone ) )\n' )
	outs.write( '\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, listCommaIdentifiers( expr ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, listIdentifiers( expr ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, listIdentifiers( expr, type::Kind::eInt32 ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, listIdentifiers( expr, type::Kind::eUndefined, var::Flag::eAlias ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, listIdentifiers( expr, type::Kind::eInt32, var::Flag::eAlias ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findIdentifier( expr ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findIdentifier( expr, type::Kind::eInt32 ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findIdentifier( expr, type::Kind::eUndefined, var::Flag::eAlias ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findIdentifier( expr, type::Kind::eInt32, var::Flag::eAlias ) )\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findName( expr ) );\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findName( expr, type::Kind::eInt32 ) );\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findName( expr, type::Kind::eUndefined, var::Flag::eAlias ) );\n' )
	outs.write( '\t\t\tastSubCheckNoThrow( function, line, findName( expr, type::Kind::eInt32, var::Flag::eAlias ) );\n' )
	outs.write( '\n' )
	outs.write( '\t\t\tstmt::StmtCache stmtCache{ *testCounts.allocatorBlock };\n' )
	outs.write( '\t\t\tif ( astWhen( "SSA transform without normalised structs" ) )\n' )
	outs.write( '\t\t\t{\n' )
	outs.write( '\t\t\t\tSSAData data{ testCounts.nextVarId, 0u };\n' )
	outs.write( '\t\t\t\tauto container = makeContainer( stmtCache, expr );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = transformSSA( stmtCache, exprCache, typesCache, *container, data, false ) );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = simplify( stmtCache, exprCache, typesCache, *container ) );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = resolveConstants( stmtCache, exprCache, *container ) );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) );\n' )
	outs.write( '\t\t\t}\n' )
	outs.write( '\t\t\tif ( astWhen( "SSA transform with normalised structs" ) )\n' )
	outs.write( '\t\t\t{\n' )
	outs.write( '\t\t\t\tSSAData data{ testCounts.nextVarId, 0u };\n' )
	outs.write( '\t\t\t\tauto container = makeContainer( stmtCache, expr );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = transformSSA( stmtCache, exprCache, typesCache, *container, data, true ) );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = simplify( stmtCache, exprCache, typesCache, *container ) );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = resolveConstants( stmtCache, exprCache, *container ) );\n' )
	outs.write( '\t\t\t\tastSubCheckNoThrow( function, line, container = specialiseStatements( stmtCache, exprCache, typesCache, *container, {} ) );\n' )
	outs.write( '\t\t\t}\n' )
	outs.write( '\t\t}\n' )
	outs.write( '\t}\n' )

	return enumName

def computeIntrinsicName( name ):
	result = name
	intrName6 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName5 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName4 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName3 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName2 = re.compile( "([\w]*), ([\w]*), ([\w]*)" )
	intrName1 = re.compile( "([\w]*), ([\w]*)" )
	resName6 = intrName6.match( name )
	resName5 = intrName5.match( name )
	resName4 = intrName4.match( name )
	resName3 = intrName3.match( name )
	resName2 = intrName2.match( name )
	resName1 = intrName1.match( name )
	if resName6:
		result = resName6.group( 2 ) + resName6.group( 3 ) + resName6.group( 4 ) + resName6.group( 5 ) + resName6.group( 6 ) + resName6.group( 7 )
	elif resName5:
		result = resName5.group( 2 ) + resName5.group( 3 ) + resName5.group( 4 ) + resName5.group( 5 ) + resName5.group( 6 )
	elif resName4:
		result = resName4.group( 2 ) + resName4.group( 3 ) + resName4.group( 4 ) + resName4.group( 5 )
	elif resName3:
		result = resName3.group( 2 ) + resName3.group( 3 ) + resName3.group( 4 )
	elif resName2:
		result = resName2.group( 2 ) + resName2.group( 3 )
	elif resName1:
		result = resName1.group( 2 )
	return result

def computeEnum( enumName, name ):
	result = enumName + "::e"
	intrName6 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName5 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName4 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName3 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName2 = re.compile( "([\w]*), ([\w]*), ([\w]*)" )
	intrName1 = re.compile( "([\w]*), ([\w]*)" )
	resName6 = intrName6.match( name )
	resName5 = intrName5.match( name )
	resName4 = intrName4.match( name )
	resName3 = intrName3.match( name )
	resName2 = intrName2.match( name )
	resName1 = intrName1.match( name )
	if resName6:
		result += resName6.group( 2 ) + resName6.group( 3 ) + resName6.group( 4 ) + resName6.group( 5 ) + resName6.group( 6 ) + resName6.group( 7 )
	elif resName5:
		result += resName5.group( 2 ) + resName5.group( 3 ) + resName5.group( 4 ) + resName5.group( 5 ) + resName5.group( 6 )
	elif resName4:
		result += resName4.group( 2 ) + resName4.group( 3 ) + resName4.group( 4 ) + resName4.group( 5 )
	elif resName3:
		result += resName3.group( 2 ) + resName3.group( 3 ) + resName3.group( 4 )
	elif resName2:
		result += resName2.group( 2 ) + resName2.group( 3 )
	elif resName1:
		result += resName1.group( 2 )
	return result
	
def discardArray( name ):
	result = re.sub( "\[\d*\]", "", name )
	return result

def isArray( name ):
	return name.find( "[" ) != -1

def computeGetTypeCall( paramType ):
	rawParamType = paramType.replace( "type::Kind::e", "" )
	if rawParamType == "UInt":
		rawParamType += "32"
	result = "typesCache.get" + rawParamType + "("
	if rawParamType == "HitAttribute" or rawParamType == "TaskPayloadNV":
		result += " typesCache.getVoid() "
	elif rawParamType == "CallableData" or rawParamType == "RayPayload":
		result += " typesCache.getVoid(), 0u "
	return result + ")"

def computeParams( params, tabs ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index + 2:
			if resParam[index] == "ASTCppParam":
				index += 4
			else:
				index += 1
				paramType = resParam[index]
				index += 1
				paramName = discardArray( resParam[index] )
				if isArray( resParam[index] ):
					index += 2
					result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( " + computeGetTypeCall( paramType ) + ", 4u ), \"" + paramName + "\" ) );\n"
				else:
					index += 2
					result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), " + computeGetTypeCall( paramType ) + ", \"" + paramName + "\" ) );\n"
	return result

def computeTexParams( params, tabs, lastType ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index + 2:
			if resParam[index] == "ASTCppParam":
				index += 4
			else:
				index += 1
				paramType = resParam[index]
				index += 1
				paramName = discardArray( resParam[index] )
				if len( resParam ) <= index + 2:
					paramType = lastType
				if isArray( resParam[index] ):
					index += 2
					result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( " + computeGetTypeCall( paramType ) + ", 4u ), \"" + paramName + "\" ) );\n"
				else:
					index += 2
					result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), " + computeGetTypeCall( paramType ) + ", \"" + paramName + "\" ) );\n"
	return result

def isLiteral( paramType ):
	literals = ["Boolean", "Vec2B", "Vec3B", "Vec4B"]
	literals.extend( ["Int8", "Int16", "Int32", "Int64", "Int", "Vec2I8", "Vec3I8", "Vec4I8"] )
	literals.extend( ["Vec2I16", "Vec3I16", "Vec4I16"] )
	literals.extend( ["Vec2I32", "Vec3I32", "Vec4I32"] )
	literals.extend( ["Vec2I64", "Vec3I64", "Vec4I64"] )
	literals.extend( ["UInt8", "UInt16", "UInt32", "UInt64", "UInt"] )
	literals.extend( ["Vec2U8", "Vec3U8", "Vec4U8"] )
	literals.extend( ["Vec2U16", "Vec3U16", "Vec4U16"] )
	literals.extend( ["Vec2U32", "Vec3U32", "Vec4U32"] )
	literals.extend( ["Vec2U64", "Vec3U64", "Vec4U64"] )
	literals.extend( ["Float", "Double"] )
	literals.extend( ["Vec2F", "Vec3F", "Vec4F"] )
	literals.extend( ["Vec2D", "Vec3D", "Vec4D"] )
	rawParamType = paramType.replace( "type::Kind::e", "" )
	return rawParamType in literals

def computeComponentValue( litType ):
	result = ""
	if litType == "Boolean":
		result = "exprCache.makeLiteral( typesCache, true )"
	if litType == "Int8":
		result = "exprCache.makeLiteral( typesCache, int8_t( 1 ) )"
	elif litType == "Int16":
		result = "exprCache.makeLiteral( typesCache, int16_t( 1 ) )"
	elif litType == "Int32":
		result = "exprCache.makeLiteral( typesCache, int32_t( 1 ) )"
	elif litType == "Int":
		result = "exprCache.makeLiteral( typesCache, int32_t( 1 ) )"
	elif litType == "Int64":
		result = "exprCache.makeLiteral( typesCache, int64_t( 1 ) )"
	elif litType == "UInt8":
		result = "exprCache.makeLiteral( typesCache, uint8_t( 1 ) )"
	elif litType == "UInt16":
		result = "exprCache.makeLiteral( typesCache, uint16_t( 1 ) )"
	elif litType == "UInt32":
		result = "exprCache.makeLiteral( typesCache, uint32_t( 1 ) )"
	elif litType == "UInt":
		result = "exprCache.makeLiteral( typesCache, uint32_t( 1 ) )"
	elif litType == "UInt64":
		result = "exprCache.makeLiteral( typesCache, uint64_t( 1 ) )"
	elif litType == "Float":
		result = "exprCache.makeLiteral( typesCache, 1.0f )"
	elif litType == "Double":
		result = "exprCache.makeLiteral( typesCache, 1.0 )"
	return result

def makeCompositeCtor( compType, compCount ):
	compValue = computeComponentValue( compType )
	result = "exprCache.makeCompositeConstruct( expr::CompositeType::eVec" + str( compCount ) + ", type::Kind::e" + compType
	result += ", makeList( " + compValue
	for i in range( 1, compCount ):
		result += ", " + compValue
	result += " ) )"
	return result

def computeLiteralValue( paramType ):
	litType = paramType.replace( "type::Kind::e", "" )
	result = ""
	if litType == "Boolean":
		result = computeComponentValue( litType )
	elif litType == "Int8":
		result = computeComponentValue( litType )
	elif litType == "Int16":
		result = computeComponentValue( litType )
	elif litType == "Int32":
		result = computeComponentValue( litType )
	elif litType == "Int":
		result = computeComponentValue( litType )
	elif litType == "Int64":
		result = computeComponentValue( litType )
	elif litType == "UInt8":
		result = computeComponentValue( litType )
	elif litType == "UInt16":
		result = computeComponentValue( litType )
	elif litType == "UInt32":
		result = computeComponentValue( litType )
	elif litType == "UInt":
		result = computeComponentValue( litType )
	elif litType == "UInt64":
		result = computeComponentValue( litType )
	elif litType == "Float":
		result = computeComponentValue( litType )
	elif litType == "Double":
		result = computeComponentValue( litType )
	elif litType == "Vec2B":
		result = makeCompositeCtor( "Boolean", 2 )
	elif litType == "Vec3B":
		result = makeCompositeCtor( "Boolean", 3 )
	elif litType == "Vec4B":
		result = makeCompositeCtor( "Boolean", 4 )
	elif litType == "Vec2I8":
		result = makeCompositeCtor( "Int8", 2 )
	elif litType == "Vec3I8":
		result = makeCompositeCtor( "Int8", 3 )
	elif litType == "Vec4I8":
		result = makeCompositeCtor( "Int8", 4 )
	elif litType == "Vec2I16":
		result = makeCompositeCtor( "Int16", 2 )
	elif litType == "Vec3I16":
		result = makeCompositeCtor( "Int16", 3 )
	elif litType == "Vec4I16":
		result = makeCompositeCtor( "Int16", 4 )
	elif litType == "Vec2I32":
		result = makeCompositeCtor( "Int32", 2 )
	elif litType == "Vec3I32":
		result = makeCompositeCtor( "Int32", 3 )
	elif litType == "Vec4I32":
		result = makeCompositeCtor( "Int32", 4 )
	elif litType == "Vec2I64":
		result = makeCompositeCtor( "Int64", 2 )
	elif litType == "Vec3I64":
		result = makeCompositeCtor( "Int64", 3 )
	elif litType == "Vec4I64":
		result = makeCompositeCtor( "Int64", 4 )
	elif litType == "Vec2U8":
		result = makeCompositeCtor( "UInt8", 2 )
	elif litType == "Vec3U8":
		result = makeCompositeCtor( "UInt8", 3 )
	elif litType == "Vec4U8":
		result = makeCompositeCtor( "UInt8", 4 )
	elif litType == "Vec2U16":
		result = makeCompositeCtor( "UInt16", 2 )
	elif litType == "Vec3U16":
		result = makeCompositeCtor( "UInt16", 3 )
	elif litType == "Vec4U16":
		result = makeCompositeCtor( "UInt16", 4 )
	elif litType == "Vec2U32":
		result = makeCompositeCtor( "UInt32", 2 )
	elif litType == "Vec3U32":
		result = makeCompositeCtor( "UInt32", 3 )
	elif litType == "Vec4U32":
		result = makeCompositeCtor( "UInt32", 4 )
	elif litType == "Vec2U64":
		result = makeCompositeCtor( "UInt64", 2 )
	elif litType == "Vec3U64":
		result = makeCompositeCtor( "UInt64", 3 )
	elif litType == "Vec4U64":
		result = makeCompositeCtor( "UInt64", 4 )
	elif litType == "Vec2F":
		result = makeCompositeCtor( "Float", 2 )
	elif litType == "Vec3F":
		result = makeCompositeCtor( "Float", 3 )
	elif litType == "Vec4F":
		result = makeCompositeCtor( "Float", 4 )
	elif litType == "Vec2D":
		result = makeCompositeCtor( "Double", 2 )
	elif litType == "Vec3D":
		result = makeCompositeCtor( "Double", 3 )
	elif litType == "Vec4D":
		result = makeCompositeCtor( "Double", 4 )
	return result

def computeLiteralParams( params, tabs ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index + 2:
			if resParam[index] == "ASTCppParam":
				index += 4
			else:
				index += 1
				paramType = resParam[index]
				index += 1
				paramName = discardArray( resParam[index] )
				if isLiteral( paramType ):
					paramInit = computeLiteralValue( paramType )
					if isArray( resParam[index] ):
						index += 2
						result += tabs + "auto " + paramName + " = exprCache.makeAggrInit( typesCache.getArray( " + computeGetTypeCall( paramType ) + ", 4u ), makeList( " + paramInit + ", " + paramInit + ", " + paramInit + ", " + paramInit + " ) );\n"
					else:
						index += 2
						result += tabs + "auto " + paramName + " = " + paramInit + ";\n"
				else:
					if isArray( resParam[index] ):
						index += 2
						result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( " + computeGetTypeCall( paramType ) + ", 4u ), \"" + paramName + "\" ) );\n"
					else:
						index += 2
						result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), " + computeGetTypeCall( paramType ) + ", \"" + paramName + "\" ) );\n"
	return result

def computeTexLiteralParams( params, tabs, lastType ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index + 2:
			if resParam[index] == "ASTCppParam":
				index += 4
			else:
				index += 1
				paramType = resParam[index]
				index += 1
				paramName = discardArray( resParam[index] )
				if len( resParam ) <= index + 2:
					paramType = lastType
				if isLiteral( paramType ):
					paramInit = computeLiteralValue( paramType )
					if isArray( resParam[index] ):
						index += 2
						result += tabs + "auto " + paramName + " = exprCache.makeAggrInit( typesCache.getArray( " + computeGetTypeCall( paramType ) + ", 4u ), makeList( " + paramInit + ", " + paramInit + ", " + paramInit + ", " + paramInit + " ) );\n"
					else:
						index += 2
						result += tabs + "auto " + paramName + " = " + paramInit + ";\n"
				else:
					if isArray( resParam[index] ):
						index += 2
						result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( " + computeGetTypeCall( paramType ) + ", 4u ), \"" + paramName + "\" ) );\n"
					else:
						index += 2
						result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), " + computeGetTypeCall( paramType ) + ", \"" + paramName + "\" ) );\n"
	return result

def computeArgs( args ):
	result = ""
	intrArgs = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resArgs = intrArgs.match( args )
	if resArgs:
		intrArg = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resArg = intrArg.split( resArgs.group( 1 ) )
		index = 2
		while len( resArg ) > index:
			index += 1
			result += "\n\t\t\t\t, std::move( " + discardArray( resArg[index] ) + " )"
			index += 3
	return result

def getPostfix( functionGroup ):
	intrName6 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName5 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName4 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName3 = re.compile( "([\w]*), ([\w]*), ([\w]*), ([\w]*)" )
	intrName2 = re.compile( "([\w]*), ([\w]*), ([\w]*)" )
	intrName1 = re.compile( "([\w]*), ([\w]*)" )
	resName6 = intrName6.match( functionGroup )
	resName5 = intrName5.match( functionGroup )
	resName4 = intrName4.match( functionGroup )
	resName3 = intrName3.match( functionGroup )
	resName2 = intrName2.match( functionGroup )
	resName1 = intrName1.match( functionGroup )
	result = ""
	if resName6:
		result += resName6.group( 3 )
	elif resName5:
		result += resName5.group( 3 )
	elif resName4:
		result += resName4.group( 3 )
	elif resName3:
		result += resName3.group( 3 )
	elif resName2:
		result += resName2.group( 3 )
	elif resName1:
		result += resName1.group( 3 )
	return result

def getDepthType( name ):
	result = re.sub( "Shadow", "", name )
	return "Shadow" if result != name else ""

def getImageSampledTypePostfix( postfix ):
	sampled = postfix[len( postfix ) - 1]
	result = ""
	if sampled == "I" or sampled == "U":
		result = sampled
	return result

def printTextureFunction( outs, enumName, imgSplInputs, imgSplMoves, match ):
	returnGroup = match.group( 1 )
	functionGroup = match.group( 2 )
	paramsGroup = match.group( 3 )
	postfix = getPostfix( functionGroup )
	sampled = getImageSampledTypePostfix( postfix )
	depth = getDepthType( postfix )
	retType = returnGroup
	intrinsicName = computeIntrinsicName( functionGroup )
	formats = list()
	if sampled == 'I':
		if intrinsicName.find( "Atomic" ) != -1:
			formats.append( ( 'R32', 'type::Kind::eInt32' ) )
		elif intrinsicName.find( "Size" ) != -1 or intrinsicName.find( "Samples" ) != -1 or intrinsicName.find( "Query" ) != -1 or intrinsicName.find( "Gather" ) != -1:
			formats.append( ( 'Rgba32', retType ) )
			formats.append( ( 'Rgba16', retType ) )
			formats.append( ( 'Rgba8', retType ) )
			formats.append( ( 'Rg32', retType ) )
			formats.append( ( 'Rg16', retType ) )
			formats.append( ( 'Rg8', retType ) )
			formats.append( ( 'R32', retType ) )
			formats.append( ( 'R16', retType ) )
			formats.append( ( 'R8', retType ) )
		else:
			formats.append( ( 'Rgba32', 'type::Kind::eVec4I32' ) )
			formats.append( ( 'Rgba16', 'type::Kind::eVec4I32' ) )
			formats.append( ( 'Rgba8', 'type::Kind::eVec4I32' ) )
			formats.append( ( 'Rg32', 'type::Kind::eVec2I32' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2I32' ) )
			formats.append( ( 'Rg8', 'type::Kind::eVec2I32' ) )
			formats.append( ( 'R32', 'type::Kind::eInt32' ) )
			formats.append( ( 'R16', 'type::Kind::eInt32' ) )
			formats.append( ( 'R8', 'type::Kind::eInt32' ) )
	elif sampled == 'U':
		if intrinsicName.find( "Atomic" ) != -1:
			formats.append( ( 'R32', 'type::Kind::eUInt' ) )
		elif intrinsicName.find( "Size" ) != -1 or intrinsicName.find( "Samples" ) != -1 or intrinsicName.find( "Query" ) != -1 or intrinsicName.find( "Gather" ) != -1:
			formats.append( ( 'Rgba32', retType ) )
			formats.append( ( 'Rgba16', retType ) )
			formats.append( ( 'Rgba8', retType ) )
			formats.append( ( 'Rg32', retType ) )
			formats.append( ( 'Rg16', retType ) )
			formats.append( ( 'Rg8', retType ) )
			formats.append( ( 'R32', retType ) )
			formats.append( ( 'R16', retType ) )
			formats.append( ( 'R8', retType ) )
		else:
			formats.append( ( 'Rgba32', 'type::Kind::eVec4U32' ) )
			formats.append( ( 'Rgba16', 'type::Kind::eVec4U32' ) )
			formats.append( ( 'Rgba8', 'type::Kind::eVec4U32' ) )
			formats.append( ( 'Rg32', 'type::Kind::eVec2U32' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2U32' ) )
			formats.append( ( 'Rg8', 'type::Kind::eVec2U32' ) )
			formats.append( ( 'R32', 'type::Kind::eUInt32' ) )
			formats.append( ( 'R16', 'type::Kind::eUInt32' ) )
			formats.append( ( 'R8', 'type::Kind::eUInt32' ) )
	else:
		if intrinsicName.find( "Atomic" ) != -1:
			formats.append( ( 'Rgba16', 'type::Kind::eVec4H' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2H' ) )
			formats.append( ( 'R32', 'type::Kind::eFloat' ) )
		elif depth == "Shadow":
			if intrinsicName.find( "Size" ) != -1 or intrinsicName.find( "Samples" ) != -1 or intrinsicName.find( "Query" ) != -1 or intrinsicName.find( "Gather" ) != -1:
				formats.append( ( 'R32', retType ) )
				formats.append( ( 'R16', retType ) )
			else:
				formats.append( ( 'R32', 'type::Kind::eFloat' ) )
				formats.append( ( 'R16', 'type::Kind::eFloat' ) )
		elif intrinsicName.find( "Size" ) != -1 or intrinsicName.find( "Samples" ) != -1 or intrinsicName.find( "Query" ) != -1 or intrinsicName.find( "Gather" ) != -1:
			formats.append( ( 'Rgba32', retType ) )
			formats.append( ( 'Rgba16', retType ) )
			formats.append( ( 'Rg32', retType ) )
			formats.append( ( 'Rg16', retType ) )
			formats.append( ( 'R32', retType ) )
			formats.append( ( 'R16', retType ) )
		elif enumName == "StorageImageAccess":
			formats.append( ( 'Rgba32', 'type::Kind::eVec4F' ) )
			formats.append( ( 'Rgba16', 'type::Kind::eVec4H' ) )
			formats.append( ( 'Rg32', 'type::Kind::eVec2F' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2H' ) )
			formats.append( ( 'R32', 'type::Kind::eFloat' ) )
			formats.append( ( 'R16', 'type::Kind::eHalf' ) )
		else:
			formats.append( ( 'Rgba32', 'type::Kind::eVec4F' ) )
			formats.append( ( 'Rgba16', 'type::Kind::eVec4F' ) )
			formats.append( ( 'Rg32', 'type::Kind::eVec2F' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2F' ) )
			formats.append( ( 'R32', 'type::Kind::eFloat' ) )
			formats.append( ( 'R16', 'type::Kind::eFloat' ) )
	result = ""
	for fmt, ret in formats:
		outs.write( "\n\tstatic void test" + intrinsicName + fmt + "(test::TestCounts & testCounts )\n" )
		outs.write( "\t{\n" )
		outs.write( "\t\tastTestBegin( \"test" + intrinsicName + fmt + "\" );\n" )
		outs.write( "\t\texpr::ExprCache exprCache{ *testCounts.allocatorBlock };\n" )
		outs.write( "\t\ttype::TypesCache typesCache;\n" )
		outs.write( '\t\tif ( astWhen( "Using identifier parameters" ) )\n' )
		outs.write( "\t\t{\n" )
		outs.write( imgSplInputs )
		if intrinsicName.find( "Store" ) != -1:
			outs.write( computeTexParams( paramsGroup, "\t\t\t", ret ) )
		elif intrinsicName.find( "Atomic" ) != -1:
			outs.write( computeTexParams( paramsGroup, "\t\t\t", ret ) )
		else:
			outs.write( computeParams( paramsGroup, "\t\t\t" ) )
		outs.write( "\t\t\tauto result = expr::make" + computeEnum( enumName, functionGroup ).replace( enumName + "::e", "" ) + fmt + "( exprCache\n" )
		outs.write( "\t\t\t\t, typesCache" )
		outs.write( imgSplMoves )
		outs.write( computeArgs( paramsGroup ) + " );\n" )
		outs.write( "\t\t\tcheckExprDependant( testCounts, *result, \"test" + intrinsicName + fmt + "\", __LINE__ );\n" )
		outs.write( "\t\t}\n" )
		outs.write( '\t\tif ( astWhen( "Using literal parameters" ) )\n' )
		outs.write( "\t\t{\n" )
		outs.write( imgSplInputs )
		if intrinsicName.find( "Store" ) != -1:
			outs.write( computeTexLiteralParams( paramsGroup, "\t\t\t", ret ) )
		elif intrinsicName.find( "Atomic" ) != -1:
			outs.write( computeTexLiteralParams( paramsGroup, "\t\t\t", ret ) )
		else:
			outs.write( computeLiteralParams( paramsGroup, "\t\t\t" ) )
		outs.write( "\t\t\tauto result = expr::make" + computeEnum( enumName, functionGroup ).replace( enumName + "::e", "" ) + fmt + "( exprCache\n" )
		outs.write( "\t\t\t\t, typesCache" )
		outs.write( imgSplMoves )
		outs.write( computeArgs( paramsGroup ) + " );\n" )
		outs.write( "\t\t\tcheckExprDependant( testCounts, *result, \"test" + intrinsicName + fmt + "\", __LINE__ );\n" )
		outs.write( "\t\t}\n" )
		outs.write( "\t\tastTestEnd()\n" )
		outs.write( "\t}" )
		result += "\n\tchecks::test" + intrinsicName + fmt + "( testCounts );"
	return result

def printIntrinsic( outs, enumName, match ):
	returnGroup = match.group( 1 )
	functionGroup = match.group( 2 )
	paramsGroup = match.group( 3 )
	intrinsicName = computeIntrinsicName( functionGroup )
	outs.write( "\n\tstatic void test" + intrinsicName + "(test::TestCounts & testCounts )\n" )
	outs.write( "\t{\n" )
	outs.write( "\t\tastTestBegin( \"test" + intrinsicName + "\" );\n" )
	outs.write( "\t\texpr::ExprCache exprCache{ *testCounts.allocatorBlock };\n" )
	outs.write( "\t\ttype::TypesCache typesCache;\n" )
	outs.write( '\t\tif ( astWhen( "Using identifier parameters" ) )\n' )
	outs.write( "\t\t{\n" )
	outs.write( computeParams( paramsGroup, "\t\t\t" ) )
	outs.write( "\t\t\tauto result = expr::make" + computeEnum( enumName, functionGroup ).replace( enumName + "::e", "" ) + "( exprCache\n" )
	outs.write( "\t\t\t\t, typesCache" )
	outs.write( computeArgs( paramsGroup ) + " );\n" )
	outs.write( "\t\t\tcheckExprDependant( testCounts, *result, \"test" + intrinsicName + "\", __LINE__ );\n" )
	outs.write( "\t\t}\n" )
	outs.write( '\t\tif ( astWhen( "Using literal parameters" ) )\n' )
	outs.write( "\t\t{\n" )
	outs.write( computeLiteralParams( paramsGroup, "\t\t\t" ) )
	outs.write( "\t\t\tauto result = expr::make" + computeEnum( enumName, functionGroup ).replace( enumName + "::e", "" ) + "( exprCache\n" )
	outs.write( "\t\t\t\t, typesCache" )
	outs.write( computeArgs( paramsGroup ) + " );\n" )
	outs.write( "\t\t\tcheckExprDependant( testCounts, *result, \"test" + intrinsicName + "\", __LINE__ );\n" )
	outs.write( "\t\t}\n" )
	outs.write( "\t\tastTestEnd()\n" )
	outs.write( "\t}" )
	return "\n\tchecks::test" + intrinsicName + "( testCounts );"

def printFunction( outs, enumName, match ):
	functionGroup = match.group( 2 )
	intrinsicName = computeIntrinsicName( functionGroup )
	test = ""
	if intrinsicName.find( "Barrier" ) == -1:
		if enumName == "CombinedImageAccess":
			imgSplInputs = '\t\t\texpr::ExprPtr texture = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getCombinedImage( type::ImageConfiguration{} ), "texture" ) );\n'
			test = printTextureFunction( outs, enumName, imgSplInputs, "\n\t\t\t\t, std::move( texture )", match )
		elif enumName == "StorageImageAccess":
			imgSplInputs = '\t\t\texpr::ExprPtr image = exprCache.makeIdentifier( typesCache, var::makeVariable( testCounts.getNextVarId(), typesCache.getImage( type::ImageConfiguration{} ), "image" ) );\n'
			test = printTextureFunction( outs, enumName, imgSplInputs, "\n\t\t\t\t, std::move( image )", match )
		else:
			test = printIntrinsic( outs, enumName, match )
	return test

def printFooter( outFile, outs, testsList ):
	testsName = os.path.basename(outFile)
	testsName = testsName.replace( ".cpp", "" )

	outs.write( "\n}" )
	outs.write( "\n" )
	outs.write( "\nastTestSuiteMain( " + testsName + " )" )
	outs.write( "\n{" )
	outs.write( "\n\tastTestSuiteBegin()" )
	outs.write( testsList )
	outs.write( "\n\tastTestSuiteEnd()" )
	outs.write( "\n}" )
	outs.write( "\n" )
	outs.write( "\nastTestSuiteLaunch( " + testsName + " )" )
	outs.write( "\n" )

def main( argv ):
	inEnumFile = sys.argv[1]
	outFile = sys.argv[2]

	if not inEnumFile or not outFile:
		print("Usage: python genTestASTIntrinsicsFromEnum.py <inEnumFile> <outFile>\n")
		print("  <inEnumFile> is the file describing the intrinsics.")
		print("  <outFile> is the resulting file.")
		return

	if not os.path.isfile(inEnumFile):
		print(inEnumFile + " is not an existing file.")
		return

	intrDecl = re.compile("^ASTIntrDecl\( ([^ ]*) \)$")
	intrEnd = re.compile("^ASTIntrEnd$")
	intrValue = re.compile("^\s*ASTIntrValue\( ([^,]*), ASTIntrName\( ([^)]*) \)([\w:, ()\[\]]*) \)$")
	enumName = ""
	testsList = ""
	with open( inEnumFile, "r" ) as ins:
		with open( outFile, "w", newline='\r\n' ) as outs:
			array = []
			for line in ins:
				array.append( line )
				resultDecl = intrDecl.match( line )
				resultValue = intrValue.match( line )
				resultEnd = intrEnd.match( line )
				if resultDecl:
					enumName = printHeader( outs, resultDecl )
				elif resultValue:
					testsList += printFunction( outs, enumName, resultValue )
				elif resultEnd:
					printFooter( outFile, outs, testsList )
				else:
					outs.write( line )

if __name__ == "__main__":
  main(sys.argv)
