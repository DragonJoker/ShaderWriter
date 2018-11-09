import os, re, sys

def typeKindToGlslType( kind ):
	result = kind.replace( "type::Kind::e", "" )
	result = result.lower()
	return result

def printHeader( outs, match ):
	enumName = match.group( 1 )
	outs.write( "#ifndef ___AST_ExprMake" + enumName + "_H___\n" )
	outs.write( "#define ___AST_ExprMake" + enumName + "_H___\n" )
	outs.write( "#pragma once\n" )
	outs.write( "\n" )
	outs.write( '#include "Expr' + enumName + 'Call.hpp"\n' )
	outs.write( "\n" )
	outs.write( "namespace ast::expr\n" )
	outs.write( "{" )
	return enumName

def computeName( name ):
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
			sep = ","
			index += 2
	return result

def computeParamsDoc( params ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("ASTIntrParam\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index:
			typeName = typeKindToGlslType( resParam[index] )
			index += 1
			result += "\n\t*@param " + discardArray( resParam[index] )
			result += "\n\t*\t" + typeName
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

def getTextureName( texType, name ):
	result = texType
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
	postfix = ""
	if resName6:
		postfix += resName6.group( 3 )
	elif resName5:
		postfix += resName5.group( 3 )
	elif resName4:
		postfix += resName4.group( 3 )
	elif resName3:
		postfix += resName3.group( 3 )
	elif resName2:
		postfix += resName2.group( 3 )
	elif resName1:
		postfix += resName1.group( 3 )
	intrNameF = re.compile( "([^F]*)([F])" )
	intrNameIU = re.compile( "([^IU]*)([IU])" )
	resNameF = intrNameF.match( postfix )
	resNameIU = intrNameIU.match( postfix )
	if resNameF:
		result = texType + resNameF.group( 1 )
	elif resNameIU:
		result = resNameIU.group( 2 ).lower() + texType + resNameIU.group( 1 )
	return result

def printDoc( outs, enumName, match ):
	outs.write( "\n\t/**" )
	outs.write( "\n\t*@return" )
	outs.write( "\n\t*\t" + typeKindToGlslType( match.group( 1 ) ) )
	if enumName == "TextureAccess":
		outs.write( "\n\t*@param texture" )
		outs.write( "\n\t*\t" + getTextureName( "sampler", match.group( 2 ) ) )
		outs.write( computeParamsDoc( match.group( 3 ) ) )
	elif enumName == "ImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + getTextureName( "sampler", match.group( 2 ) ) )
		outs.write( computeParamsDoc( match.group( 3 ) ) )
	else:
		outs.write( computeParamsDoc( match.group( 3 ) ) )
	outs.write( "\n\t*/" )

def printValue( outs, enumName, match ):
	printDoc( outs, enumName, match )
	outs.write( "\n\t" + enumName + "CallPtr make" + computeName( match.group( 2 ) ) + "(" )
	if enumName == "TextureAccess":
		outs.write( " ExprPtr texture" )
		outs.write( computeParams( match.group( 3 ), "," ) + " );" )
	elif enumName == "ImageAccess":
		outs.write( " ExprPtr image" )
		outs.write( computeParams( match.group( 3 ), "," ) + " );" )
	else:
		outs.write( computeParams( match.group( 3 ), "" ) + " );" )

def printFooter( outs ):
	outs.write( "}\n" )
	outs.write( "\n" )
	outs.write( "#endif\n" )

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
					printValue( outs, enumName, resultValue )
				elif resultEnd:
					printFooter( outs )
				else:
					outs.write( line )

if __name__ == "__main__":
  main(sys.argv)
