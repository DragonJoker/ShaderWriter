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

def discardArray( name ):
	result = re.sub( "\[\d*\]", "", name )
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

def computeParams( paramsGroup, sep ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( paramsGroup )
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

def computeParamsDoc( paramsGroup ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( paramsGroup )
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
	if name.find( "Rect" ) != -1:
		result = "Rect"
	elif name.find( "1D" ) != -1:
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
	if enumName == "TextureAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "SampledImage", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "ImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "Image", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	else:
		outs.write( computeParamsDoc( paramsGroup ) )
	outs.write( "\n\t*/" )

def printTextureFunction( outs, enumName, match ):
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
			formats.append( ( 'R32', 'Int' ) )
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
			formats.append( ( 'R32', 'UInt' ) )
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
		printTextureFunctionDoc( outs, enumName, ret, functionGroup, paramsGroup )
		outs.write( "\n\t" + enumName + "CallPtr make" + intrinsicName + fmt + "(" )
		outs.write( " type::TypesCache & cache" )
		outs.write( ", ExprPtr image" )
		outs.write( computeParams( paramsGroup, "," ) + " );" )

def printIntrinsicDoc( outs, enumName, returnGroup, functionGroup, paramsGroup ):
	outs.write( "\n\t/**" )
	outs.write( "\n\t*@return" )
	outs.write( "\n\t*\t" + typeKindToGlslType( returnGroup ) )
	if enumName == "TextureAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "SampledImage", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	elif enumName == "ImageAccess":
		outs.write( "\n\t*@param image" )
		outs.write( "\n\t*\t" + computeImageFullType( "Image", functionGroup ) )
		outs.write( computeParamsDoc( paramsGroup ) )
	else:
		outs.write( computeParamsDoc( paramsGroup ) )
	outs.write( "\n\t*/" )

def printIntrinsic( outs, enumName, match ):
	returnGroup = match.group( 1 )
	functionGroup = match.group( 2 )
	paramsGroup = match.group( 3 )
	printIntrinsicDoc( outs, enumName, returnGroup, functionGroup, paramsGroup )
	outs.write( "\n\t" + enumName + "CallPtr make" + computeIntrinsicName( functionGroup ) + "(" )
	outs.write( " type::TypesCache & cache" )
	outs.write( computeParams( paramsGroup, "," ) + " );" )

def printFunction( outs, enumName, match ):
	if enumName == "TextureAccess" or enumName == "ImageAccess":
		printTextureFunction( outs, enumName, match )
	else:
		printIntrinsic( outs, enumName, match )

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
					printFunction( outs, enumName, resultValue )
				elif resultEnd:
					printFooter( outs )
				else:
					outs.write( line )

if __name__ == "__main__":
  main(sys.argv)
