import os, re, sys

def typeKindToSdwType( kind ):
	result = kind.replace( "type::Kind::e", "" )
	result = result.replace( "Vec2F", "Vec2" )
	result = result.replace( "Vec3F", "Vec3" )
	result = result.replace( "Vec4F", "Vec4" )
	result = result.replace( "Vec2I", "IVec2" )
	result = result.replace( "Vec3I", "IVec3" )
	result = result.replace( "Vec4I", "IVec4" )
	result = result.replace( "Vec2U", "UVec2" )
	result = result.replace( "Vec3U", "UVec3" )
	result = result.replace( "Vec4U", "UVec4" )
	result = result.replace( "Vec2B", "BVec2" )
	result = result.replace( "Vec3B", "BVec3" )
	result = result.replace( "Vec4B", "BVec4" )
	result = result.replace( "Vec2D", "DVec2" )
	result = result.replace( "Vec3D", "DVec3" )
	result = result.replace( "Vec4D", "DVec4" )
	result = result.replace( "Mat2x2F", "Mat2" )
	result = result.replace( "Mat2x3F", "Mat2x3" )
	result = result.replace( "Mat2x4F", "Mat2x4" )
	result = result.replace( "Mat3x2F", "Mat3x2" )
	result = result.replace( "Mat3x3F", "Mat3" )
	result = result.replace( "Mat3x4F", "Mat3x4" )
	result = result.replace( "Mat4x2F", "Mat4x2" )
	result = result.replace( "Mat4x3F", "Mat4x3" )
	result = result.replace( "Mat4x4F", "Mat4" )
	result = result.replace( "Mat2x2D", "DMat2" )
	result = result.replace( "Mat2x3D", "DMat2x3" )
	result = result.replace( "Mat2x4D", "DMat2x4" )
	result = result.replace( "Mat3x2D", "DMat3x2" )
	result = result.replace( "Mat3x3D", "DMat3" )
	result = result.replace( "Mat3x4D", "DMat3x4" )
	result = result.replace( "Mat4x2D", "DMat4x2" )
	result = result.replace( "Mat4x3D", "DMat4x3" )
	result = result.replace( "Mat4x4D", "DMat4" )
	return result

def printHeader( outs, match ):
	enumName = match.group( 1 )
	outs.write( "\n/*" )
	outs.write( "\nSee LICENSE file in root folder" )
	outs.write( "\n*/" )
	outs.write( "\n" )
	outs.write( '\n#include "ShaderWriter/Intrinsics/' + enumName + 'Functions.hpp"' )
	outs.write( "\n" )
	outs.write( '\n#include <ShaderAST/Expr/Make' + enumName + '.hpp>' )
	outs.write( "\n" )
	outs.write( "\nnamespace sdw" )
	outs.write( "\n{" )
	return enumName

def computeIntrinsicName( functionGroup ):
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
		result = resName6.group( 1 )
	elif resName5:
		result = resName5.group( 1 )
	elif resName4:
		result = resName4.group( 1 )
	elif resName3:
		result = resName3.group( 1 )
	elif resName2:
		result = resName2.group( 1 )
	elif resName1:
		result = resName1.group( 1 )
	return result

def computeFullName( functionGroup ):
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

def getDoublePostfix( postfix ):
	if postfix.endswith( "Comp" ):
		return "Comp"
	if postfix.endswith( "Bias" ):
		return "Bias"
	if postfix.endswith( "FI" ) or postfix.endswith( "UI" ) or postfix.endswith( "II" ):
		return "I"
	if postfix.endswith( "FU" ) or postfix.endswith( "UU" ) or postfix.endswith( "IU" ):
		return "U"
	if postfix.endswith( "FF" ) or postfix.endswith( "UF" ) or postfix.endswith( "IF" ):
		return "F"
	return ""

def isArray( name ):
	result = re.sub( "\[\d*\]", "", name )
	return result != name

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
			paramType = typeKindToSdwType( resParam[index] )
			index = index + 1
			if isArray( resParam[index] ):
				result += sep + " MaybeOptional< Array< " + paramType + " > > const & " + discardArray( resParam[index] )
			else:
				result += sep + " MaybeOptional< " + paramType + " > const & " + resParam[index]
			sep = "\n\t\t,"
			index += 2
	return result

def listParams( params, sep ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("ASTIntrParam\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 2
		while len( resParam ) > index:
			result += sep + " " + discardArray( resParam[index] )
			sep = ","
			index += 3
	return result

def computeArgs( args, indent, sep ):
	result = ""
	intrArgs = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resArgs = intrArgs.match( args )
	if resArgs:
		intrArg = re.compile("ASTIntrParam\( ([^,]*), ([^ ]*) \)")
		resArg = intrArg.split( resArgs.group( 1 ) )
		index = 2
		while len( resArg ) > index:
			result += sep + " makeExpr( " + discardArray( resArg[index] ) + " )"
			sep = "\n" + indent + ","
			index += 3
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
		result = "2DRect"
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
	result = ""
	if sampled == "I" or sampled == "U":
		result = sampled
	return result

def getPostfixedFunctionName( functionGroup ):
	functionName = computeIntrinsicName( functionGroup )
	postfix = getDoublePostfix( computeFullName( functionGroup ) )
	return functionName + postfix

def beginFunctionGroup( outs, functionsName ):
	# Write structure base declaration
	outs.write( "\n#pragma region " + functionsName )
	outs.write( "\n\t/**" )
	outs.write( "\n\t*name" )
	outs.write( "\n\t*	" + functionsName )
	outs.write( "\n\t*/" )
	outs.write( "\n\t/**@{*/" )

def computeImageFullType( imageType, postfix, sampled, depth ):
	dim = getImageDim( postfix )
	array = getArrayType( postfix )
	ms = getMSType( postfix )
	return sampled + imageType + dim + ms + array + depth

def printImageFunction( outs, returnGroup, functionGroup, paramsGroup, imageType ):
	retType = typeKindToSdwType( returnGroup )
	fullName = computeFullName( functionGroup )
	postfix = getPostfix( functionGroup )
	sampled = getImageSampledType( postfix )
	depth = getDepthType( postfix )
	formats = list()
	intrinsicName = computeIntrinsicName( functionGroup )
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
			formats.append( ( 'Rgba32', 'IVec4' ) )
			formats.append( ( 'Rgba16', 'IVec4' ) )
			formats.append( ( 'Rgba8', 'IVec4' ) )
			formats.append( ( 'Rg32', 'IVec2' ) )
			formats.append( ( 'Rg16', 'IVec2' ) )
			formats.append( ( 'Rg8', 'IVec2' ) )
			formats.append( ( 'R32', 'Int' ) )
			formats.append( ( 'R16', 'Int' ) )
			formats.append( ( 'R8', 'Int' ) )
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
			formats.append( ( 'Rgba32', 'UVec4' ) )
			formats.append( ( 'Rgba16', 'UVec4' ) )
			formats.append( ( 'Rgba8', 'UVec4' ) )
			formats.append( ( 'Rg32', 'UVec2' ) )
			formats.append( ( 'Rg16', 'UVec2' ) )
			formats.append( ( 'Rg8', 'UVec2' ) )
			formats.append( ( 'R32', 'UInt' ) )
			formats.append( ( 'R16', 'UInt' ) )
			formats.append( ( 'R8', 'UInt' ) )
	else:
		if depth == "Shadow":
			if intrinsicName.find( "Size" ) != -1 or intrinsicName.find( "Samples" ) != -1 or intrinsicName.find( "Query" ) != -1 or intrinsicName.find( "Gather" ) != -1:
				formats.append( ( 'R32', retType ) )
				formats.append( ( 'R16', retType ) )
			else:
				formats.append( ( 'R32', 'Float' ) )
				formats.append( ( 'R16', 'Float' ) )
		elif intrinsicName.find( "Size" ) != -1 or intrinsicName.find( "Samples" ) != -1 or intrinsicName.find( "Query" ) != -1 or intrinsicName.find( "Gather" ) != -1:
			formats.append( ( 'Rgba32', retType ) )
			formats.append( ( 'Rgba16', retType ) )
			formats.append( ( 'Rg32', retType ) )
			formats.append( ( 'Rg16', retType ) )
			formats.append( ( 'R32', retType ) )
			formats.append( ( 'R16', retType ) )
		else:
			formats.append( ( 'Rgba32', 'Vec4' ) )
			formats.append( ( 'Rgba16', 'Vec4' ) )
			formats.append( ( 'Rg32', 'Vec2' ) )
			formats.append( ( 'Rg16', 'Vec2' ) )
			formats.append( ( 'R32', 'Float' ) )
			formats.append( ( 'R16', 'Float' ) )
	dim = getImageDim( postfix )
	if dim != "2DRect":
		imageFullType = computeImageFullType( imageType, postfix, sampled, depth )
		for fmt, ret in formats:
			# Write function name and return
			outs.write( "\n\tMaybeOptional< " + ret + " > " + computeIntrinsicName( functionGroup ) + "(" )
			# Write parameters
			#	Image parameter
			outs.write( " MaybeOptional< " + imageFullType + fmt + " > const & image" )
			#	Remaining function parameters
			outs.write( computeParams( paramsGroup, "\n\t\t," ) + " )" )
			# Header finished, write content
			outs.write( "\n\t{" )
			outs.write( "\n\t\tif ( isAnyOptional( image" + listParams( paramsGroup, "," ) + " ) )" )
			outs.write( "\n\t\t{" )
			outs.write( "\n\t\t\treturn Optional< " + ret + " >{ findShader( image" + listParams( paramsGroup, "," ) + " )" )
			# Write arguments
			outs.write( "\n\t\t\t\t, expr::make" + fullName + fmt + "( findTypesCache( image" + listParams( paramsGroup, "," ) + " )" )
			#	Image argument
			outs.write( "\n\t\t\t\t\t, makeExpr( image )" )
			#	Remaining arguments
			outs.write( computeArgs( paramsGroup, "\t\t\t\t\t", "\n\t\t\t\t\t," ) + " )" )
			outs.write( "\n\t\t\t\t, areOptionalEnabled( image" + listParams( paramsGroup, "," ) + " ) };" )
			outs.write( "\n\t\t}" )
			outs.write( "\n" )
			outs.write( "\n\t\treturn " + ret + "{ findShader( image" + listParams( paramsGroup, "," ) + " )" )
			# Write arguments
			outs.write( "\n\t\t\t, expr::make" + fullName + fmt + "( findTypesCache( image" + listParams( paramsGroup, "," ) + " )" )
			#	Image argument
			outs.write( "\n\t\t\t\t, makeExpr( image )" )
			#	Remaining arguments
			outs.write( computeArgs( paramsGroup, "\t\t\t\t", "\n\t\t\t\t," ) + " ) };" )
			outs.write( "\n\t}" )

def printIntrinsicFunction( outs, returnGroup, functionGroup, paramsGroup ):
	retType = typeKindToSdwType( returnGroup )
	fullName = computeFullName( functionGroup )
	# Write function name and return
	outs.write( "\n\tMaybeOptional< " + retType + " > " + computeIntrinsicName( functionGroup ) + "(" )
	# Write function parameters
	outs.write( computeParams( paramsGroup, "" ) + " )" )
	# Header finished, write content
	outs.write( "\n\t{" )
	outs.write( "\n\t\tif ( isAnyOptional(" + listParams( paramsGroup, "" ) + " ) )" )
	outs.write( "\n\t\t{" )
	outs.write( "\n\t\t\treturn Optional< " + retType + " >{ findShader(" + listParams( paramsGroup, "" ) + " )" )
	outs.write( "\n\t\t\t\t, expr::make" + fullName + "( findTypesCache(" + listParams( paramsGroup, "" ) + " )" )
	outs.write( computeArgs( paramsGroup, "\t\t\t\t\t", "\n\t\t\t\t\t," ) + " )" )
	outs.write( "\n\t\t\t\t, areOptionalEnabled(" + listParams( paramsGroup, "" ) + " ) };" )
	outs.write( "\n\t\t}" )
	outs.write( "\n" )
	outs.write( "\n\t\treturn " + retType + "{ findShader(" + listParams( paramsGroup, "" ) + " )" )
	outs.write( "\n\t\t\t, expr::make" + fullName + "( findTypesCache(" + listParams( paramsGroup, "" ) + " )" )
	outs.write( computeArgs( paramsGroup, "\t\t\t\t", "\n\t\t\t\t\t," ) + " ) };" )
	outs.write( "\n\t}" )
	
def endFunctionGroup( outs ):
	outs.write( "\n\t/**@}*/" )
	outs.write( "\n#pragma endregion" )

def printFooter( outs ):
	outs.write( "\n}\n" )

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
	prvFunctionGroup = ""
	prvParamsGroup = ""
	with open(inEnumFile, "r") as ins:
		with open(outEnumFile, "w") as outs:
			array = []
			functionGroups = dict()
			imageType = "Image"
			for line in ins:
				array.append( line )
				resultDecl = intrDecl.match( line )
				resultValue = intrValue.match( line )
				resultEnd = intrEnd.match( line )
				if resultDecl:
					enumName = printHeader( outs, resultDecl )
					if enumName == "TextureAccess":
						imageType = "SampledImage"
				elif resultValue:
					returnGroup = resultValue.group( 1 )
					functionGroup = resultValue.group( 2 )
					paramsGroup = resultValue.group( 3 )
					groupName = getPostfixedFunctionName( functionGroup )
					if groupName not in functionGroups:
						functionGroups[groupName] = dict()
					paramsList = listParams( paramsGroup, "" )
					if paramsList not in functionGroups[groupName]:
						functionGroups[groupName][paramsList] = list()
					functionGroups[groupName][paramsList].append( [returnGroup, functionGroup, paramsGroup] )
				elif resultEnd:
					if enumName == "TextureAccess" or enumName == "ImageAccess":
						for functionsName, functionsSubGroup in functionGroups.items():
							beginFunctionGroup( outs, functionsName )
							for paramsList, functionsList in functionsSubGroup.items():
								for function in functionsList:
									returnGroup = function[0]
									functionGroup = function[1]
									paramsGroup = function[2]
									printImageFunction( outs, returnGroup, functionGroup, paramsGroup, imageType )
							endFunctionGroup( outs )
					else:
						for functionsName, functionsSubGroup in functionGroups.items():
							beginFunctionGroup( outs, functionsName )
							for paramsList, functionsList in functionsSubGroup.items():
								for function in functionsList:
									returnGroup = function[0]
									functionGroup = function[1]
									paramsGroup = function[2]
									printIntrinsicFunction( outs, returnGroup, functionGroup, paramsGroup )
							endFunctionGroup( outs )
					printFooter( outs )

if __name__ == "__main__":
  main(sys.argv)
