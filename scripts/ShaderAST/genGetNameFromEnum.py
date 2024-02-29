import os, re, sys

def printHeader( outs, match ):
	enumName = match.group( 1 )
	outs.write( "/*\n" )
	outs.write( "This file is generated, don't modify it!\n" )
	outs.write( "*/\n" )
	outs.write( '#ifndef ___AST_ExprGet' + enumName + 'Name_H___\n' )
	outs.write( '#define ___AST_ExprGet' + enumName + 'Name_H___\n' )
	outs.write( '#pragma once\n' )
	outs.write( "\n" )
	outs.write( '#include "Enum' + enumName + '.hpp"\n' )
	outs.write( '#include "ShaderAST/Shader.hpp"\n' )
	outs.write( "\n" )
	outs.write( '#include <string>\n' )
	outs.write( "\n" )
	outs.write( "namespace ast::expr\n" )
	outs.write( "{\n" )
	outs.write( "\tinline std::string getName( " + enumName + " value )\n" )
	outs.write( "\t{\n" )
	outs.write( "\t\tstd::string result;\n" )
	outs.write( "\n" )
	outs.write( "\t\tswitch ( value )\n" )
	outs.write( "\t\t{\n" )
	outs.write( "\t\tcase " + enumName + "::eUndefined:\n" )
	outs.write( '\t\t\tresult = "Undefined";\n' )
	outs.write( '\t\t\tbreak;\n' )
	outs.write( '\n' )
	outs.write( "\t\tcase " + enumName + "::eCount:\n" )
	outs.write( '\t\t\tresult = "Count";\n' )
	outs.write( '\t\t\tbreak;\n' )
	outs.write( '\n' )
	outs.write( "\t\tcase " + enumName + "::eInvalid:\n" )
	outs.write( '\t\t\tresult = "Invalid";\n' )
	outs.write( '\t\t\tbreak;\n' )
	outs.write( '\n' )
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

def printValue( outs, enumName, match ):
	name = computeName( match.group( 2 ) )
	outs.write( "\t\tcase " + enumName + "::e" + name + ":\n" )
	outs.write( '\t\t\tresult = "' + name + '";\n' )
	outs.write( '\t\t\tbreak;\n' )
	outs.write( '\n' )

def printFooter( outs, enumName ):
	outs.write( "\t\tdefault:\n" )
	outs.write( '\t\t\tthrow Exception{ "Unsupported ' + enumName + ' type." };\n' )
	outs.write( "\t\t}\n" )
	outs.write( "\n" )
	outs.write( "\t\treturn result;\n" )
	outs.write( "\t}\n" )
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
	with open(inEnumFile, "r") as ins:
		with open(outEnumFile, "w", newline='\r\n') as outs:
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
					printFooter( outs, enumName )
				else:
					outs.write( line )

if __name__ == "__main__":
  main(sys.argv)
