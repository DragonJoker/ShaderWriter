import os, re, sys

def typeKindToSdwType( kind ):
	result = kind.replace( "type::Kind::e", "" )
	result = result.replace( "Vec2F", "Vec2" )
	result = result.replace( "Vec3F", "Vec3" )
	result = result.replace( "Vec4F", "Vec4" )
	result = result.replace( "Vec2I8", "I8Vec2" )
	result = result.replace( "Vec3I8", "I8Vec3" )
	result = result.replace( "Vec4I8", "I8Vec4" )
	result = result.replace( "Vec2I16", "I16Vec2" )
	result = result.replace( "Vec3I16", "I16Vec3" )
	result = result.replace( "Vec4I16", "I16Vec4" )
	result = result.replace( "Vec2I32", "I32Vec2" )
	result = result.replace( "Vec3I32", "I32Vec3" )
	result = result.replace( "Vec4I32", "I32Vec4" )
	result = result.replace( "Vec2I64", "I64Vec2" )
	result = result.replace( "Vec3I64", "I64Vec3" )
	result = result.replace( "Vec4I64", "I64Vec4" )
	result = result.replace( "Vec2U8", "U8Vec2" )
	result = result.replace( "Vec3U8", "U8Vec3" )
	result = result.replace( "Vec4U8", "U8Vec4" )
	result = result.replace( "Vec2U16", "U16Vec2" )
	result = result.replace( "Vec3U16", "U16Vec3" )
	result = result.replace( "Vec4U16", "U16Vec4" )
	result = result.replace( "Vec2U32", "U32Vec2" )
	result = result.replace( "Vec3U32", "U32Vec3" )
	result = result.replace( "Vec4U32", "U32Vec4" )
	result = result.replace( "Vec2U64", "U64Vec2" )
	result = result.replace( "Vec3U64", "U64Vec3" )
	result = result.replace( "Vec4U64", "U64Vec4" )
	result = result.replace( "Vec2B", "BVec2" )
	result = result.replace( "Vec3B", "BVec3" )
	result = result.replace( "Vec4B", "BVec4" )
	result = result.replace( "Vec2D", "DVec2" )
	result = result.replace( "Vec3D", "DVec3" )
	result = result.replace( "Vec4D", "DVec4" )
	result = result.replace( "Vec2H", "HVec2" )
	result = result.replace( "Vec3H", "HVec3" )
	result = result.replace( "Vec4H", "HVec4" )
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
	outs.write( "/*" )
	outs.write( "\nSee LICENSE file in root folder" )
	outs.write( "\n*/" )
	outs.write( "\n/*" )
	outs.write( "\nThis file is generated, don't modify it!" )
	outs.write( "\n*/" )
	outs.write( '\n#include "ShaderWriter/Helpers.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/AccelerationStructure.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/Void.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/Array.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/Boolean.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/Double.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/Float.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/Int.hpp"' )
	outs.write( '\n#include "ShaderWriter/BaseTypes/UInt.hpp"' )
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

def computeParams( params, sep, allowEmpty ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index:
			if resParam[index] == "ASTIntrParam":
				typeQualifier = "const"
			else:
				typeQualifier = ""
			index += 1
			paramType = typeKindToSdwType( resParam[index] )
			index += 1
			if len(typeQualifier) > 0:
				if isArray( resParam[index] ):
					result += sep + " Array< " + paramType + " > " + typeQualifier + " " + discardArray( resParam[index] )
				else:
					result += sep + " " + paramType + " " + typeQualifier + " " + resParam[index]
			else:
				if isArray( resParam[index] ):
					result += sep + " Array< " + paramType + " > " + discardArray( resParam[index] )
				else:
					result += sep + " " + paramType + " " + resParam[index]
			sep = "\n\t\t,"
			index += 2
	elif allowEmpty == 0:
		result = " ShaderWriter & writer"
	return result

def computeParamsEx( params, sep, lastType ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 1
		while len( resParam ) > index:
			if resParam[index] == "ASTIntrParam":
				typeQualifier = "const"
			else:
				typeQualifier = ""
			index += 1
			paramType = typeKindToSdwType( resParam[index] )
			index += 1
			curIndex = index
			index += 2

			if (len( resParam ) <= index):
				paramType = lastType

			if len(typeQualifier) > 0:
				if isArray( resParam[curIndex] ):
					result += sep + " Array< " + paramType + " > " + typeQualifier + " " + discardArray( resParam[curIndex] )
				else:
					result += sep + " " + paramType + " " + typeQualifier + " " + resParam[curIndex]
			else:
				if isArray( resParam[curIndex] ):
					result += sep + " Array< " + paramType + " > " + discardArray( resParam[curIndex] )
				else:
					result += sep + " " + paramType + " " + resParam[curIndex]
			sep = "\n\t\t,"
	return result

def listParams( params, sep, allowEmpty ):
	result = ""
	intrParams = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resParams = intrParams.match( params )
	if resParams:
		intrParam = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resParam = intrParam.split( resParams.group( 1 ) )
		index = 2
		while len( resParam ) > index:
			index += 1
			result += sep + " " + discardArray( resParam[index] )
			sep = ","
			index += 3
	elif allowEmpty == 0:
		result = " writer"
	return result

def computeArgs( args, indent, sep ):
	result = ""
	intrArgs = re.compile("[, ]*ASTIntrParams\( ([\w, :()\[\]]*) \)$")
	resArgs = intrArgs.match( args )
	if resArgs:
		intrArg = re.compile("(ASTIntrParam|ASTCppParam|ASTIntrOutParam)\( ([^,]*), ([^ ]*) \)")
		resArg = intrArg.split( resArgs.group( 1 ) )
		index = 2
		while len( resArg ) > index:
			index += 1
			if resArg[index - 2] == "ASTCppParam":
				result += sep + " " + discardArray( resArg[index] )
			else:
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

def computeImageFullTypes( imageType, postfix, sampled, depth, prefixes ):
	tmp = computeImageFullType( imageType, postfix, sampled, depth )
	result = list()
	for prefix in prefixes:
		result.append( prefix + tmp )
	return result

def getTexImgFormats( sampled, depth, retType, intrinsicName ):
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
		if intrinsicName.find( "Atomic" ) != -1:
			formats.append( ( 'Rgba16', 'HVec4' ) )
			formats.append( ( 'Rg16', 'HVec2' ) )
			formats.append( ( 'R32', 'Float' ) )
		elif depth == "Shadow":
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
		elif intrinsicName.find( "texture" ) != -1 or intrinsicName.find( "texel" ) != -1:
			formats.append( ( 'Rgba32', 'Vec4' ) )
			formats.append( ( 'Rgba16', 'Vec4' ) )
			formats.append( ( 'Rg32', 'Vec2' ) )
			formats.append( ( 'Rg16', 'Vec2' ) )
			formats.append( ( 'R32', 'Float' ) )
			formats.append( ( 'R16', 'Float' ) )
		else:
			formats.append( ( 'Rgba32', 'Vec4' ) )
			formats.append( ( 'Rgba16', 'HVec4' ) )
			formats.append( ( 'Rg32', 'Vec2' ) )
			formats.append( ( 'Rg16', 'HVec2' ) )
			formats.append( ( 'R32', 'Float' ) )
			formats.append( ( 'R16', 'Half' ) )
	return formats

def printTextureFunction( outs, returnGroup, functionGroup, paramsGroup, imageType ):
	retType = typeKindToSdwType( returnGroup )
	fullName = computeFullName( functionGroup )
	postfix = getPostfix( functionGroup )
	sampled = getImageSampledType( postfix )
	depth = getDepthType( postfix )
	intrinsicName = computeIntrinsicName( functionGroup )
	dim = getImageDim( postfix )
	formats = getTexImgFormats( sampled, depth, retType, intrinsicName )
	imageFullType = computeImageFullType( imageType, postfix, sampled, depth )
	for fmt, ret in formats:
		# Write function name and return
		outs.write( "\n\tRet" + ret + " " + computeIntrinsicName( functionGroup ) + "(" )
		# Write parameters
		#	Image parameter
		outs.write( " " + imageFullType + fmt + " const & image" )
		#	Remaining function parameters
		outs.write( computeParams( paramsGroup, "\n\t\t,", 1 ) + " )" )
		# Header finished, write content
		outs.write( "\n\t{" )
		outs.write( "\n\t\treturn Ret" + ret + "{ *findWriter( image" + listParams( paramsGroup, ",", 1 ) + " )" )
		# Write arguments
		outs.write( "\n\t\t\t, expr::make" + fullName + fmt + "( findExprCache( image" + listParams( paramsGroup, ",", 1 ) + " )" )
		#	Types cache argument
		outs.write( "\n\t\t\t\t, findTypesCache( image" + listParams( paramsGroup, ",", 1 ) + " )" )
		#	Image argument
		outs.write( "\n\t\t\t\t, makeExpr( image )" )
		#	Remaining arguments
		outs.write( computeArgs( paramsGroup, "\t\t\t\t", "\n\t\t\t\t," ) + " )" )
		outs.write( "\n\t\t\t, areOptionalEnabled( image" + listParams( paramsGroup, ",", 1 ) + " ) };" )
		outs.write( "\n\t}" )

def printImageFunction( outs, returnGroup, functionGroup, paramsGroup, imageType ):
	retType = typeKindToSdwType( returnGroup )
	fullName = computeFullName( functionGroup )
	postfix = getPostfix( functionGroup )
	sampled = getImageSampledType( postfix )
	depth = getDepthType( postfix )
	intrinsicName = computeIntrinsicName( functionGroup )
	dim = getImageDim( postfix )
	formats = getTexImgFormats( sampled, depth, retType, intrinsicName )
	isStore = intrinsicName.find( "Store" ) != -1
	if isStore:
		imageFullTypes = computeImageFullTypes( imageType, postfix, sampled, depth, ["W", "RW"] )
	elif intrinsicName.find( "Load" ) != -1:
		imageFullTypes = computeImageFullTypes( imageType, postfix, sampled, depth, ["R", "RW"] )
	elif intrinsicName.find( "Atomic" ) != -1:
		imageFullTypes = computeImageFullTypes( imageType, postfix, sampled, depth, ["RW"] )
	else:
		imageFullTypes = computeImageFullTypes( imageType, postfix, sampled, depth, ["R", "RW", "W"] )
	for imageFullType in imageFullTypes:
		for fmt, ret in formats:
			if isStore:
				# Write function name and return
				outs.write( "\n\tRetVoid " + computeIntrinsicName( functionGroup ) + "(" )
				# Write parameters
				#	Image parameter
				outs.write( " " + imageFullType + fmt + " const & image" )
				#	Remaining function parameters
				outs.write( computeParamsEx( paramsGroup, "\n\t\t,", ret ) + " )" )
				# Header finished, write content
				outs.write( "\n\t{" )
				outs.write( "\n\t\treturn RetVoid{ *findWriter( image" + listParams( paramsGroup, ",", 1 ) + " )" )
			else:
				# Write function name and return
				outs.write( "\n\tRet" + ret + " " + computeIntrinsicName( functionGroup ) + "(" )
				# Write parameters
				#	Image parameter
				outs.write( " " + imageFullType + fmt + " const & image" )
				#	Remaining function parameters
				if intrinsicName.find( "Atomic" ) != -1:
					outs.write( computeParamsEx( paramsGroup, "\n\t\t,", ret ) + " )" )
				else:
					outs.write( computeParams( paramsGroup, "\n\t\t,", 1 ) + " )" )
				# Header finished, write content
				outs.write( "\n\t{" )
				outs.write( "\n\t\treturn Ret" + ret + "{ *findWriter( image" + listParams( paramsGroup, ",", 1 ) + " )" )
			# Write arguments
			outs.write( "\n\t\t\t, expr::make" + fullName + fmt + "( findExprCache( image" + listParams( paramsGroup, ",", 1 ) + " )" )
			#	Types cache
			outs.write( "\n\t\t\t\t, findTypesCache( image" + listParams( paramsGroup, ",", 1 ) + " )" )
			#	Image argument
			outs.write( "\n\t\t\t\t, makeExpr( image )" )
			#	Remaining arguments
			outs.write( computeArgs( paramsGroup, "\t\t\t\t", "\n\t\t\t\t," ) + " )" )
			outs.write( "\n\t\t\t, areOptionalEnabled( image" + listParams( paramsGroup, ",", 1 ) + " ) };" )
			outs.write( "\n\t}" )

def printIntrinsicFunction( outs, returnGroup, functionGroup, paramsGroup ):
	retType = typeKindToSdwType( returnGroup )
	fullName = computeFullName( functionGroup )
	intrinsicName = computeIntrinsicName( functionGroup )
	# Write function name and return
	outs.write( "\n\tRet" + retType + " " + intrinsicName + "(" )
	# Write function parameters
	outs.write( computeParams( paramsGroup, "", 0 ) + " )" )
	# Header finished, write content
	outs.write( "\n\t{" )
	outs.write( "\n\t\treturn Ret" + retType + "{ *findWriter(" + listParams( paramsGroup, "", 0 ) + " )" )
	outs.write( "\n\t\t\t, expr::make" + fullName + "( findExprCache(" + listParams( paramsGroup, "", 0 ) + " )" )
	#	Types cache
	outs.write( "\n\t\t\t\t, findTypesCache(" + listParams( paramsGroup, "", 0 ) + " )" )
	# Other arguments
	outs.write( computeArgs( paramsGroup, "\t\t\t\t", "\n\t\t\t\t," ) + " )" )
	outs.write( "\n\t\t\t, areOptionalEnabled(" + listParams( paramsGroup, "", 0 ) + " ) };" )
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
		with open(outEnumFile, "w", newline='\r\n') as outs:
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
					if enumName == "CombinedImageAccess":
						imageType = "CombinedImage"
					elif enumName == "SampledImageAccess":
						imageType = "SampledImage"
					elif enumName == "StorageImageAccess":
						imageType = "StorageImage"
				elif resultValue:
					returnGroup = resultValue.group( 1 )
					functionGroup = resultValue.group( 2 )
					paramsGroup = resultValue.group( 3 )
					groupName = getPostfixedFunctionName( functionGroup )
					if groupName not in functionGroups:
						functionGroups[groupName] = dict()
					paramsList = listParams( paramsGroup, "", 1 )
					if paramsList not in functionGroups[groupName]:
						functionGroups[groupName][paramsList] = list()
					functionGroups[groupName][paramsList].append( [returnGroup, functionGroup, paramsGroup] )
				elif resultEnd:
					if enumName == "CombinedImageAccess":
						for functionsName, functionsSubGroup in functionGroups.items():
							beginFunctionGroup( outs, functionsName )
							for paramsList, functionsList in functionsSubGroup.items():
								for function in functionsList:
									returnGroup = function[0]
									functionGroup = function[1]
									paramsGroup = function[2]
									printTextureFunction( outs, returnGroup, functionGroup, paramsGroup, imageType )
							endFunctionGroup( outs )
					elif enumName == "SampledImageAccess":
						for functionsName, functionsSubGroup in functionGroups.items():
							beginFunctionGroup( outs, functionsName )
							for paramsList, functionsList in functionsSubGroup.items():
								for function in functionsList:
									returnGroup = function[0]
									functionGroup = function[1]
									paramsGroup = function[2]
									printTextureFunction( outs, returnGroup, functionGroup, paramsGroup, imageType )
							endFunctionGroup( outs )
					elif enumName == "StorageImageAccess":
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
