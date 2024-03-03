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
	outs.write( '#include <ShaderAST/Visitors/ResolveConstants.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/SimplifyStatements.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/SpecialiseStatements.hpp>\n' )
	outs.write( '#include <ShaderAST/Visitors/TransformSSA.hpp>\n' )
	outs.write( '\n' )
	outs.write( 'namespace checks\n' )
	outs.write( '{\n' )
	outs.write( '\tusing namespace ast;\n' )
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
	outs.write( '\t\t, expr::IntrinsicCall const & expr )\n' )
	outs.write( '\t{\n' )
	outs.write( '\t\tauto & exprCache = expr.getExprCache();\n' )
	outs.write( '\t\tauto & typesCache = expr.getTypesCache();\n' )
	outs.write( '\n' )
	outs.write( '\t\ttestCounts << "Expr: " << ast::debug::displayExpression( expr ) << test::endl;\n' )
	outs.write( '\t\tcheckNoThrow( ast::resolveConstants( exprCache, expr ) )\n' )
	outs.write( '\n' )
	outs.write( '\t\tauto clone = expr.clone();\n' )
	outs.write( '\t\tclone->updateFlag( ast::expr::Flag::eNonUniform );\n' )
	outs.write( '\t\ttestCounts << "NonUniform Clone: " << ast::debug::displayExpression( *clone ) << test::endl;\n' )
	outs.write( '\t\tcheckNoThrow( ast::resolveConstants( exprCache, *clone ) )\n' )
	outs.write( '\n' )
	outs.write( '\t\tcheckNoThrow( ast::listCommaIdentifiers( expr ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::listIdentifiers( expr ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::listIdentifiers( expr, ast::type::Kind::eInt32 ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::listIdentifiers( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::listIdentifiers( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::findIdentifier( expr ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::findIdentifier( expr, ast::type::Kind::eInt32 ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::findIdentifier( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) )\n' )
	outs.write( '\t\tcheckNoThrow( ast::findIdentifier( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) )\n' )
	outs.write( '\t\ttestCounts << "Find default params: [" << ast::findName( expr ) << "]" << test::endl;\n' )
	outs.write( '\t\ttestCounts << "Find typed: [" << ast::findName( expr, ast::type::Kind::eInt32 ) << "]" << test::endl;\n' )
	outs.write( '\t\ttestCounts << "Find flagged: [" << ast::findName( expr, ast::type::Kind::eUndefined, ast::var::Flag::eAlias ) << "]" << test::endl;\n' )
	outs.write( '\t\ttestCounts << "Find typed and flagged: [" << ast::findName( expr, ast::type::Kind::eInt32, ast::var::Flag::eAlias ) << "]" << test::endl;\n' )
	outs.write( '\n' )
	outs.write( '\t\tast::stmt::StmtCache stmtCache{ *testCounts.allocatorBlock };\n' )
	outs.write( '\t\t{\n' )
	outs.write( '\t\t\tast::SSAData data{ testCounts.nextVarId, 0u };\n' )
	outs.write( '\t\t\tauto container = makeContainer( stmtCache, expr );\n' )
	outs.write( '\t\t\tcontainer = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, false );\n' )
	outs.write( '\t\t\tcontainer = ast::resolveConstants( stmtCache, exprCache, typesCache, *container );\n' )
	outs.write( '\t\t\tcontainer = ast::simplify( stmtCache, exprCache, typesCache, *container );\n' )
	outs.write( '\t\t\tcontainer = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, {} );\n' )
	outs.write( '\t\t}\n' )
	outs.write( '\t\t{\n' )
	outs.write( '\t\t\tast::SSAData data{ testCounts.nextVarId, 0u };\n' )
	outs.write( '\t\t\tauto container = makeContainer( stmtCache, expr );\n' )
	outs.write( '\t\t\tcontainer = ast::transformSSA( stmtCache, exprCache, typesCache, *container, data, true );\n' )
	outs.write( '\t\t\tcontainer = ast::resolveConstants( stmtCache, exprCache, typesCache, *container );\n' )
	outs.write( '\t\t\tcontainer = ast::simplify( stmtCache, exprCache, typesCache, *container );\n' )
	outs.write( '\t\t\tcontainer = ast::specialiseStatements( stmtCache, exprCache, typesCache, *container, {} );\n' )
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
	result = "get" + rawParamType + "("
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
					result += tabs + "auto " + paramName + "Var = var::makeVariable( testCounts.getNextVarId(), typesCache.getArray( " + computeGetTypeCall( paramType ) + ", 4u ), \"" + paramName + "\" );\n"
				else:
					index += 2
					result += tabs + "auto " + paramName + "Var = var::makeVariable( testCounts.getNextVarId(), typesCache." + computeGetTypeCall( paramType ) + ", \"" + paramName + "\" );\n"
				result += tabs + "auto " + paramName + " = exprCache.makeIdentifier( typesCache, " + paramName + "Var );\n"
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
			result += "\n\t\t\t, std::move( " + discardArray( resArg[index] ) + " )"
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

def getTextureName( texType, name ):
	result = texType
	postfix = getPostfix( name )
	intrNameF = re.compile( "([^F]*)([F])" )
	intrNameIU = re.compile( "([^IU]*)([IU])" )
	resNameF = intrNameF.match( postfix )
	resNameIU = intrNameIU.match( postfix )
	if resNameF:
		result = texType + resNameF.group( 1 )
	elif resNameIU:
		result = resNameIU.group( 2 ).lower() + texType + resNameIU.group( 1 )
	return result

def getDepthType( name ):
	result = re.sub( "Shadow", "", name )
	return "Shadow" if result != name else ""

def getArrayType( name ):
	result = re.sub( "Array", "", name )
	return "Array" if result != name else ""

def getDepthType( name ):
	result = re.sub( "Shadow", "", name )
	return "Shadow" if result != name else ""

def getMSType( name ):
	result = re.sub( "MS", "", name )
	return "MS" if result != name else ""

def getImageDim( name ):
	result = ""
	if name.find( "1D" ) != -1:
		result = "1D"
	elif name.find( "2D" ) != -1:
		result = "2D"
	elif name.find( "3D" ) != -1:
		result = "3D"
	elif name.find( "Cube" ) != -1:
		result = "Cube"
	elif name.find( "Buffer" ) != -1:
		result = "Buffer"
	return result
	
def getImageSampledType( postfix ):
	sampled = postfix[len( postfix ) - 1]
	result = "Float"
	if sampled == "I":
		result = "Int"
	elif sampled == "U":
		result = "UInt"
	return result

def getImageSampledTypePostfix( postfix ):
	sampled = postfix[len( postfix ) - 1]
	result = ""
	if sampled == "I" or sampled == "U":
		result = sampled
	return result

def computeImageFullType( imageType, functionGroup ):
	postfix = getPostfix( functionGroup )
	sampled = getImageSampledType( postfix )
	dim = getImageDim( postfix )
	ms = getMSType( postfix )
	array = getArrayType( postfix )
	depth = getDepthType( postfix )
	sep = ", "
	seq = [sampled, dim]
	if len( ms ):
		seq.append( ms )
	if len( array ):
		seq.append( array )
	if len( depth ):
		seq.append( depth )
	return imageType + "<" + ', '.join( seq ) + ">"

def printTextureFunctionDoc( outs, enumName, returnGroup, functionGroup, paramsGroup ):
	outs.write( "\n\t/**" )
	outs.write( "\n\t*@return" )
	outs.write( "\n\t*\t" + typeKindToGlslType( returnGroup ) )
	if enumName == "CombinedImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "CombinedImage", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "SampledImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "SampledImage", functionGroup ) )
		outs.write( "\n\t*@param sampler" )
		outs.write( "\n\t*\tSampler" )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "StorageImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "StorageImage", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	else:
		outs.write( computeParamsDoc( paramsGroup ) )
	outs.write( "\n\t*/" )

def printTextureFunctionDocExNR( outs, enumName, lastGroup, functionGroup, paramsGroup ):
	outs.write( "\n\t/**" )
	if enumName == "CombinedImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "CombinedImage", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "SampledImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "SampledImage", functionGroup ) )
		outs.write( "\n\t*@param sampler" )
		outs.write( "\n\t*\tSampler" )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "StorageImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "StorageImage", functionGroup ) )
		outs.write( computeParamsDocEx( paramsGroup, lastGroup ) )
	else:
		outs.write( computeParamsDoc( paramsGroup ) )
	outs.write( "\n\t*/" )

def printTextureFunctionDocEx( outs, enumName, returnGroup, functionGroup, paramsGroup ):
	outs.write( "\n\t/**" )
	outs.write( "\n\t*@return" )
	outs.write( "\n\t*\t" + typeKindToGlslType( returnGroup ) )
	if enumName == "CombinedImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "CombinedImage", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "SampledImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "SampledImage", functionGroup ) )
		outs.write( "\n\t*@param sampler" )
		outs.write( "\n\t*\tSampler" )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "StorageImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "Image", functionGroup ) )
		outs.write( computeParamsDocEx( paramsGroup, returnGroup ) )
	else:
		outs.write( computeParamsDoc( paramsGroup ) )
	outs.write( "\n\t*/" )

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
			formats.append( ( 'R32', 'type::Kind::eInt' ) )
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
			formats.append( ( 'Rgba32', 'type::Kind::eVec4I' ) )
			formats.append( ( 'Rgba16', 'type::Kind::eVec4I' ) )
			formats.append( ( 'Rgba8', 'type::Kind::eVec4I' ) )
			formats.append( ( 'Rg32', 'type::Kind::eVec2I' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2I' ) )
			formats.append( ( 'Rg8', 'type::Kind::eVec2I' ) )
			formats.append( ( 'R32', 'type::Kind::eInt' ) )
			formats.append( ( 'R16', 'type::Kind::eInt' ) )
			formats.append( ( 'R8', 'type::Kind::eInt' ) )
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
			formats.append( ( 'Rgba32', 'type::Kind::eVec4U' ) )
			formats.append( ( 'Rgba16', 'type::Kind::eVec4U' ) )
			formats.append( ( 'Rgba8', 'type::Kind::eVec4U' ) )
			formats.append( ( 'Rg32', 'type::Kind::eVec2U' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2U' ) )
			formats.append( ( 'Rg8', 'type::Kind::eVec2U' ) )
			formats.append( ( 'R32', 'type::Kind::eUInt' ) )
			formats.append( ( 'R16', 'type::Kind::eUInt' ) )
			formats.append( ( 'R8', 'type::Kind::eUInt' ) )
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
	for fmt, ret in formats:
		if intrinsicName.find( "Store" ) != -1:
			printTextureFunctionDocExNR( outs, enumName, ret, functionGroup, paramsGroup )
		elif intrinsicName.find( "Atomic" ) != -1:
			printTextureFunctionDocEx( outs, enumName, ret, functionGroup, paramsGroup )
		else:
			printTextureFunctionDoc( outs, enumName, ret, functionGroup, paramsGroup )

		outs.write( "\n\tinline " + enumName + "CallPtr make" + intrinsicName + fmt + "(" )
		outs.write( " ExprCache & exprCache" )
		outs.write( "\n\t\t, type::TypesCache & typesCache" )
		outs.write( imgSplInputs )
		outs.write( computeParams( paramsGroup, "\n\t\t," ) + " )\n" )
		outs.write( "\t{\n" )

		if intrinsicName.find( "Store" ) != -1:
			outs.write( assertParamsEx( paramsGroup, "\t\t", ret ) )
			outs.write( "\t\treturn exprCache.make" + enumName + "Call( typesCache.getBasicType( type::Kind::eVoid )\n" )
		else:
			if intrinsicName.find( "Atomic" ) != -1:
				outs.write( assertParamsEx( paramsGroup, "\t\t", ret ) )
			else:
				outs.write( assertParams( paramsGroup, "\t\t" ) )
			outs.write( "\t\treturn exprCache.make" + enumName + "Call( typesCache.getBasicType( " + ret + " )\n" )

		outs.write( "\t\t\t, " + computeEnum( enumName, functionGroup ) )
		outs.write( imgSplMoves )
		outs.write( computeArgs( paramsGroup ) + " );\n" )
		outs.write( "\t}" )

def printIntrinsic( outs, enumName, match ):
	returnGroup = match.group( 1 )
	functionGroup = match.group( 2 )
	paramsGroup = match.group( 3 )
	outs.write( "\n\tstatic void test" + computeIntrinsicName( functionGroup ) + "(test::TestCounts & testCounts )\n" )
	outs.write( "\t{\n" )
	outs.write( "\t\ttestBegin( \"test" + computeIntrinsicName( functionGroup ) + "\" );\n" )
	outs.write( "\t\texpr::ExprCache exprCache{ *testCounts.allocatorBlock };\n" )
	outs.write( "\t\ttype::TypesCache typesCache;\n" )
	outs.write( computeParams( paramsGroup, "\t\t" ) )
	outs.write( "\t\tauto result = expr::make" + computeEnum( enumName, functionGroup ).replace( enumName + "::e", "" ) + "( exprCache\n" )
	outs.write( "\t\t\t, typesCache" )
	if enumName == "CombinedImageAccess":
		outs.write( "\n\t\t\t, std::move( texture )" )
	elif enumName == "SampledImageAccess":
		outs.write( "\n\t\t\t, std::move( image )" )
		outs.write( "\n\t\t\t, std::move( sampler )" )
	elif enumName == "StorageImageAccess":
		outs.write( "\n\t\t\t, std::move( image )" )
	outs.write( computeArgs( paramsGroup ) + " );\n" )
	outs.write( "\t\tcheckExprDependant( testCounts, *result );\n" )
	outs.write( "\t\ttestEnd()\n" )
	outs.write( "\t}" )
	return "\n\tchecks::test" + computeIntrinsicName( functionGroup ) + "( testCounts );"

def printFunction( outs, enumName, match ):
	functionGroup = match.group( 2 )
	intrinsicName = computeIntrinsicName( functionGroup )
	test = ""
	if intrinsicName.find( "Barrier" ) == -1:
		if enumName == "CombinedImageAccess":
			test = printTextureFunction( outs, enumName, "\n\t\t, ExprPtr texture", "\n\t\t\t, std::move( texture )", match )
		elif enumName == "SampledImageAccess":
			test = printTextureFunction( outs, enumName, "\n\t\t, ExprPtr image\n\t\t, ExprPtr sampler", "\n\t\t\t, std::move( image )\n\t\t\t, std::move( sampler )", match )
		elif enumName == "StorageImageAccess":
			test = printTextureFunction( outs, enumName, "\n\t\t, ExprPtr image", "\n\t\t\t, std::move( image )", match )
		else:
			test = printIntrinsic( outs, enumName, match )
	return test

def printFooter( outFile, outs, testsList ):
	testsName = os.path.basename(outFile)
	testsName = testsName.replace( ".cpp", "" )

	outs.write( "\n}" )
	outs.write( "\n" )
	outs.write( "\ntestSuiteMain( " + testsName + " )" )
	outs.write( "\n{" )
	outs.write( "\n\ttestSuiteBegin()" )
	outs.write( testsList )
	outs.write( "\n\ttestSuiteEnd()" )
	outs.write( "\n}" )
	outs.write( "\n" )
	outs.write( "\ntestSuiteLaunch( " + testsName + " )" )
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
