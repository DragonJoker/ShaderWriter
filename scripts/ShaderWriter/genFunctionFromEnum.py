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
	outs.write( "#ifndef ___ShaderWriter_Get" + enumName + "Functions_H___\n" )
	outs.write( "#define ___ShaderWriter_Get" + enumName + "Functions_H___\n" )
	outs.write( "#pragma once\n" )
	outs.write( "\n" )
	outs.write( '#include "Function.hpp"\n' )
	outs.write( '#include "FunctionParam.hpp"\n' )
	outs.write( '#include "Bool.hpp"\n' )
	outs.write( '#include "Image.hpp"\n' )
	outs.write( '#include "OptionalMat2.hpp"\n' )
	outs.write( '#include "OptionalMat2x3.hpp"\n' )
	outs.write( '#include "OptionalMat2x4.hpp"\n' )
	outs.write( '#include "OptionalMat3.hpp"\n' )
	outs.write( '#include "OptionalMat3x2.hpp"\n' )
	outs.write( '#include "OptionalMat3x4.hpp"\n' )
	outs.write( '#include "OptionalMat4.hpp"\n' )
	outs.write( '#include "OptionalMat4x2.hpp"\n' )
	outs.write( '#include "OptionalMat4x3.hpp"\n' )
	outs.write( '#include "Sampler.hpp"\n' )
	outs.write( "\n" )
	outs.write( '#include <ASTGenerator/Expr/Make' + enumName + '.hpp>\n' )
	outs.write( "\n" )
	outs.write( "namespace sdw\n" )
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

def computeFullName( name ):
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
				result += sep + " Array< " + paramType + " > const & " + discardArray( resParam[index] )
			else:
				result += sep + " " + paramType + " const & " + resParam[index]
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

def computeArgs( args, sep ):
	result = ""
	intrArgs = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resArgs = intrArgs.match( args )
	if resArgs:
		intrArg = re.compile("ASTIntrParam\( ([^,]*), ([^ ]*) \)")
		resArg = intrArg.split( resArgs.group( 1 ) )
		index = 2
		while len( resArg ) > index:
			result += sep + " makeExpr( " + discardArray( resArg[index] ) + " )"
			sep = "\n\t\t\t\t,"
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
		result = resNameIU.group( 2 ) + texType + resNameIU.group( 1 )
	return result

def printValue( outs, enumName, match ):
	retType = typeKindToSdwType( match.group( 1 ) )
	fullName = computeFullName( match.group( 2 ) )
	outs.write( "\n\tinline " + retType + " " + computeIntrinsicName( match.group( 2 ) ) + "(" )
	if enumName == "TextureAccess":
		outs.write( " " + getTextureName( "Sampler", match.group( 2 ) ) + " const & texture" )
		outs.write( computeParams( match.group( 3 ), "\n\t\t," ) + " )\n" )
	elif enumName == "ImageAccess":
		outs.write( " " + getTextureName( "Image", match.group( 2 ) ) + " const & image" )
		outs.write( computeParams( match.group( 3 ), "\n\t\t," ) + " )\n" )
	else:
		outs.write( computeParams( match.group( 3 ), "" ) + " )\n" )
	outs.write( "\t{\n" )
	if enumName == "TextureAccess":
		outs.write( "\t\treturn " + retType + "{ findShader( texture" + listParams( match.group( 3 ), "," ) + " )" )
	elif enumName == "ImageAccess":
		outs.write( "\t\treturn " + retType + "{ findShader( image" + listParams( match.group( 3 ), "," ) + " )" )
	else:
		outs.write( "\t\treturn " + retType + "{ findShader(" + listParams( match.group( 3 ), "" ) + " )" )
	outs.write( "\n\t\t\t, expr::make" + fullName + "(" )
	if enumName == "TextureAccess":
		outs.write( " makeExpr( texture )" )
		outs.write( computeArgs( match.group( 3 ), "\n\t\t\t\t," ) + " ) };\n" )
	elif enumName == "ImageAccess":
		outs.write( " makeExpr( image )" )
		outs.write( computeArgs( match.group( 3 ), "\n\t\t\t\t," ) + " ) };\n" )
	else:
		outs.write( computeArgs( match.group( 3 ), "" ) + " ) };\n" )
	outs.write( "\t}\n" )

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
