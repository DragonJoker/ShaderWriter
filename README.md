<p align="center">
  <a href="https://github.com/DragonJoker/ShaderWriter/actions?query=workflow%3ABuild"><img alt="Build status" src="https://github.com/DragonJoker/ShaderWriter/workflows/Build/badge.svg"></a>
</p>


ShaderWriter
============

This library is used to write shaders directly from C++ code.

It is split in two main libraries (ShaderAST and ShaderWriter) and a "compiler" library for each front end language (CompilerGLSL, CompilerHLSL and CompilerSpirV).

ShaderAST holds the base architecture (expressions and statements, roughly) used to describe a shader.

ShaderWriter is based on ShaderAST, and is fully typed, to be able to write GLSL-like shaders in C++.

The compiler libraries allow exporting the generated AST in either of these shader languages. 

Examples
--------

Let's take the following vertex shader code, written in C++:

```cpp
void vertex()
{
	using namespace sdw;
	VertexWriter writer;

	// Shader inputs
	auto position = writer.declInput< Vec2 >( "position", 0u );
	auto texcoord = writer.declInput< Vec2 >( "texcoord", 1u );

	// Shader outputs
	auto vtx_texture = writer.declOutput< Vec2 >( "vtx_texture", 0u );
	auto out = writer.getOut();

	writer.implementFunction< sdw::Void >( "main", [&]()
		{
			vtx_texture = texcoord;
			out.vtx.position = vec4( position.x(), position.y(), 0.0, 1.0 );
		} );

	// Select your weapon !
	auto glsl = compileGlsl( writer.getShader()
		, SpecialisationInfo{} );
	auto hlsl = compileHlsl( writer.getShader()
		, SpecialisationInfo{} );
	auto binSpirV = serialiseSpirv( writer.getShader() );
	auto textSpirV = writeSpirv( writer.getShader() );
}
```

This shader will generate the following GLSL:
```glsl
#version 430
layout(location=0) in vec2 position;
layout(location=1) in vec2 texcoord;
layout(location=0) out vec2 vtx_texture;

out gl_PerVertex
{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[];
	float gl_CullDistance[];
};

void main()
{
	vtx_texture = texcoord;
	gl_Position = vec4(position.x, position.y, 0.0f, 1.0f);
}
```

The following HLSL (Shader Model 5):
```hlsl
struct HLSL_SDW_MainInput
{
	float2 position: TEXCOORD0;
	float2 texcoord: TEXCOORD1;
};

struct HLSL_SDW_Input
{
	float2 position;
	float2 texcoord;
};

struct HLSL_SDW_MainOutput
{
	float2 vtx_texture: TEXCOORD0;
	float4 gl_Position: SV_Position;
};

struct HLSL_SDW_Output
{
	float2 vtx_texture;
	float4 gl_Position;
};
static HLSL_SDW_Input sdwInput;
static HLSL_SDW_Output sdwOutput;

void SDW_main()
{
	sdwOutput.vtx_texture = sdwInput.texcoord;
	sdwOutput.gl_Position = float4(sdwInput.position.x, sdwInput.position.y, 0.0f, 1.0f);
}

HLSL_SDW_MainOutput main(HLSL_SDW_MainInput sdwMainInput)
{
	sdwInput = sdwMainInput;
	SDW_main();
	HLSL_SDW_MainOutput sdwMainOutput;
	sdwMainOutput = sdwOutput;
	return sdwMainOutput;
}
```

And the following SPIR-V listing:
```
; Magic:     0x07230203
; Version:   0x00010000
; Generator: 0x00100001
; Bound:     33
; Schema:    0

        OpCapability Shader
   %1 = OpExtInstImport "GLSL.std.450"
        OpMemoryModel Logical GLSL450
        OpEntryPoint Vertex %17 "main" %2 %6 %7 %9

; Debug
        OpSource GLSL 460
        OpName %2(position) "position"
        OpName %6(texcoord) "texcoord"
        OpName %7(vtx_texture) "vtx_texture"
        OpName %9() ""
        OpName %10(gl_PerVertex) "gl_PerVertex"
        OpMemberName %10(gl_PerVertex) 0 "gl_Position"
        OpMemberName %10(gl_PerVertex) 1 "gl_PointSize"
        OpMemberName %10(gl_PerVertex) 2 "gl_ClipDistance"
        OpMemberName %10(gl_PerVertex) 3 "gl_CullDistance"
        OpName %17(main) "main"

; Decorations
        OpDecorate %14 ArrayStride 4
        OpMemberDecorate %10(gl_PerVertex) 0 BuiltIn Position
        OpMemberDecorate %10(gl_PerVertex) 1 BuiltIn PointSize
        OpMemberDecorate %10(gl_PerVertex) 2 BuiltIn ClipDistance
        OpMemberDecorate %10(gl_PerVertex) 3 BuiltIn CullDistance
        OpDecorate %10(gl_PerVertex) Block
        OpDecorate %2(position) Location 0
        OpDecorate %6(texcoord) Location 1
        OpDecorate %7(vtx_texture) Location 0

; Types, Constants, and Global Variables
   %3 = OpTypeFloat 32
   %4 = OpTypeVector %3(float) 2
   %5 = OpTypePointer Input %4(v2float)
   %2 = OpVariable %5(v2floatInputPtr) Input
   %6 = OpVariable %5(v2floatInputPtr) Input
   %8 = OpTypePointer Output %4(v2float)
   %7 = OpVariable %8(v2floatOutputPtr) Output
  %11 = OpTypeVector %3(float) 4
  %13 = OpTypeInt 32 0
  %12 = OpConstant %13(uint) 8
  %14 = OpTypeArray %3(float) %12(8)
  %10 = OpTypeStruct %11(v4float) %3(float) %14(array) %14(array)
  %15 = OpTypePointer Output %10(gl_PerVertex)
   %9 = OpVariable %15(structOutputPtr) Output
  %16 = OpTypeVoid
  %18 = OpTypeFunction %16
  %21 = OpConstant %13(uint) 0
  %22 = OpTypePointer Output %11(v4float)
  %24 = OpTypePointer Input %3(float)
  %27 = OpConstant %13(uint) 1
  %30 = OpConstant %3(float) 0
  %31 = OpConstant %3(float) 1

; Functions
  %17 = OpFunction %16 [None]  %18(func)
  %19 = OpLabel
  %20 = OpLoad %4(v2float) %6(texcoord)
        OpStore %7(vtx_texture) %20
  %23 = OpAccessChain %22(v4floatOutputPtr) %9() %21(0)
  %25 = OpAccessChain %24(floatInputPtr) %2(position) %21(0)
  %26 = OpLoad %3(float) %25
  %28 = OpAccessChain %24(floatInputPtr) %2(position) %27(1)
  %29 = OpLoad %3(float) %28
  %32 = OpCompositeConstruct %11(v4float) %26 %29 %30(0.000000) %31(1.000000)
        OpStore %23 %32
        OpReturn
        OpFunctionEnd
```

Some optimisations have been done, but more could be, with SPIR-V.

There is also an internal debug format :
```
STINOUTVARDECL LOC(0) VAR(INATTR,FVEC2) position
STINOUTVARDECL LOC(1) VAR(INATTR,FVEC2) texcoord
STINOUTVARDECL LOC(0) VAR(OUTATTR,FVEC2) vtx_texture
STPERVERTEXDECL VERTOUT
STFUNCDECL VOID main()
        STSIMPLE ASSIGN (IDENT vtx_texture) (IDENT texcoord)
        STSIMPLE ASSIGN (MBRSELECT (IDENT ) (IDENT gl_Position)) (COMPOSITECONSTRUCT VEC4 FLOAT ((SWIZZLE x (IDENT position)), (SWIZZLE y (IDENT position)), (LITERAL 0.0), (LITERAL 1.0)))
```

Contact
-------

You can reach me on the Discord server dedicated to my projects: [DragonJoker's Lair](https://discord.gg/jue8kW)
