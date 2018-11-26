import os, re, sys

def typeKindToGlslType( kind ):
	result = kind.replace( "type::Kind::e", "" )
	result = result.lower()
	return result

def printHeader( outs, match ):
	enumName = match.group( 1 )
	outs.write( '#include "ASTGenerator/Expr/Make' + enumName + '.hpp"\n' )
	outs.write( "\n" )
	outs.write( "namespace ast::expr\n" )
	outs.write( "{" )
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

def computeParams( params, sep ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("ASTIntrParam\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index:
			result += sep + " ExprPtr "
			index += 1
			result += discardArray( resParam[index] )
			sep = "\n\t\t,"
			index += 2
	return result

def computeArgs( args ):
	result = ""
	intrArgs = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resArgs = intrArgs.match( args )
	if resArgs:
		intrArg = re.compile("ASTIntrParam\( ([^,]*), ([^ ]*) \)")
		resArg = intrArg.split( resArgs.group( 1 ) )
		index = 2
		while len( resArg ) > index:
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

def getImageSampledType( postfix ):
	sampled = postfix[len( postfix ) - 1]
	result = ""
	if sampled == "I" or sampled == "U":
		result = sampled
	return result

def getDepthType( name ):
	result = re.sub( "Shadow", "", name )
	return "Shadow" if result != name else ""

def printTextureFunction( outs, enumName, match ):
	returnGroup = match.group( 1 )
	functionGroup = match.group( 2 )
	paramsGroup = match.group( 3 )
	postfix = getPostfix( functionGroup )
	sampled = getImageSampledType( postfix )
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
		if depth == "Shadow":
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
		else:
			formats.append( ( 'Rgba32', 'type::Kind::eVec4F' ) )
			formats.append( ( 'Rgba16', 'type::Kind::eVec4F' ) )
			formats.append( ( 'Rg32', 'type::Kind::eVec2F' ) )
			formats.append( ( 'Rg16', 'type::Kind::eVec2F' ) )
			formats.append( ( 'R32', 'type::Kind::eFloat' ) )
			formats.append( ( 'R16', 'type::Kind::eFloat' ) )
	for fmt, ret in formats:
		outs.write( "\n\t" + enumName + "CallPtr make" + intrinsicName + fmt + "(" )
		outs.write( " ExprPtr image" )
		outs.write( computeParams( paramsGroup, "\n\t\t," ) + " )\n" )
		outs.write( "\t{\n" )
		outs.write( "\t\treturn make" + enumName + "Call( makeType( " + ret + " )\n" )
		outs.write( "\t\t\t, " + computeEnum( enumName, functionGroup ) )
		outs.write( "\n\t\t\t, std::move( image )" )
		outs.write( computeArgs( paramsGroup ) + " );\n" )
		outs.write( "\t}\n" )

def printIntrinsic( outs, enumName, match ):
	outs.write( "\n\t" + enumName + "CallPtr make" + computeIntrinsicName( match.group( 2 ) ) + "(" )
	outs.write( computeParams( match.group( 3 ), "" ) + " )\n" )
	outs.write( "\t{\n" )
	outs.write( "\t\treturn make" + enumName + "Call( makeType( " + match.group( 1 ) + " )\n" )
	outs.write( "\t\t\t, " + computeEnum( enumName, match.group( 2 ) ) )
	if enumName == "TextureAccess":
		outs.write( "\n\t\t\t, std::move( texture )" )
	elif enumName == "ImageAccess":
		outs.write( "\n\t\t\t, std::move( image )" )
	outs.write( computeArgs( match.group( 3 ) ) + " );\n" )
	outs.write( "\t}\n" )

def printFunction( outs, enumName, match ):
	if enumName == "TextureAccess" or enumName == "ImageAccess":
		printTextureFunction( outs, enumName, match )
	else:
		printIntrinsic( outs, enumName, match )

def printFooter( outs ):
	outs.write( "}\n" )

def main( argv ):
	inEnumFile = sys.argv[1]
	outEnumFile = sys.argv[2]

	if not inEnumFile or not outEnumFile:
		print("Usage: python genEnumFromEnum.py <inEnumFile> <outEnumFile>\n")
		print("  <inEnumFile> is the file describing the intrinsics.")
		print("  <outEnumFile> is the resulting file.")
		return

	if not os.path.isfile(inEnumFile):
		print(inEnumFile + " is not an existing file.")
		return

	intrDecl = re.compile("^ASTIntrDecl\( ([^ ]*) \)$")
	intrEnd = re.compile("^ASTIntrEnd$")
	intrValue = re.compile("^\s*ASTIntrValue\( ([^,]*), ASTIntrName\( ([^)]*) \)([\w:, ()\[\]]*) \)$")
	enumName = ""
	with open(inEnumFile, "r") as ins:
		with open(outEnumFile, "w") as outs:
			array = []
			for line in ins:
				array.append( line )
				resultDecl = intrDecl.match( line )
				resultValue = intrValue.match( line )
				resultEnd = intrEnd.match( line )
				if resultDecl:
					enumName = printHeader( outs, resultDecl )
				elif resultValue:
					printFunction( outs, enumName, resultValue )
				elif resultEnd:
					printFooter( outs )
				else:
					outs.write( line )

if __name__ == "__main__":
  main(sys.argv)
