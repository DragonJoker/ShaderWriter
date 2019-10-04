|         Server     | Result |
|:------------------:|--------|
| AppVeyor           | [![Build Status](https://ci.appveyor.com/api/projects/status/github/DragonJoker/shaderwriter?branch=master&svg=true)](https://ci.appveyor.com/project/DragonJoker/shaderwriter) |


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

	writer.implementFunction< void >( "main", [&]()
		{
			vtx_texture = texcoord;
			out.gl_out.gl_Position = vec4( position.x(), position.y(), 0.0, 1.0 );
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
};

void main()
{
	vtx_texture = texcoord;
	gl_Position = vec4(position.x, position.y, 0.0, 1.0);
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
	sdwOutput.gl_Position = float4(sdwInput.position.x, sdwInput.position.y, 0.0, 1.0);
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
; Bound:     37
; Schema:    0

        OpCapability Shader
        OpCapability Float64
   %1 = OpExtInstImport "GLSL.std.450"
        OpMemoryModel Logical GLSL450
        OpEntryPoint Vertex %20 "main" %2 %6 %7 %9 %14 %14 %17

; Debug
        OpSource GLSL 460
        OpName %2(position) "position"
        OpName %6(texcoord) "texcoord"
        OpName %7(gl_PointSize) "gl_PointSize"
        OpName %9(gl_ClipDistance) "gl_ClipDistance"
        OpName %14(gl_Position) "gl_Position"
        OpName %17(vtx_texture) "vtx_texture"
        OpName %20(main) "main"

; Decorations
        OpDecorate %7(gl_PointSize) BuiltIn PointSize
        OpDecorate %9(gl_ClipDistance) BuiltIn ClipDistance
        OpDecorate %12 ArrayStride 0
        OpDecorate %14(gl_Position) BuiltIn Position
        OpDecorate %2(position) Location 0
        OpDecorate %6(texcoord) Location 1
        OpDecorate %17(vtx_texture) Location 0

; Types, Constants, and Global Variables
   %3 = OpTypeFloat 32
   %4 = OpTypeVector %3(float) 2
   %5 = OpTypePointer Input %4(v2float)
   %2 = OpVariable %5(v2floatInputPtr) Input
   %6 = OpVariable %5(v2floatInputPtr) Input
   %8 = OpTypePointer Output %3(float)
   %7 = OpVariable %8(floatOutputPtr) Output
  %11 = OpTypeInt 32 0
  %10 = OpConstant %11(uint) 8
  %12 = OpTypeArray %3(float) %10(8)
  %13 = OpTypePointer Output %12(array)
   %9 = OpVariable %13(arrayOutputPtr) Output
  %15 = OpTypeVector %3(float) 4
  %16 = OpTypePointer Output %15(v4float)
  %14 = OpVariable %16(v4floatOutputPtr) Output
  %18 = OpTypePointer Output %4(v2float)
  %17 = OpVariable %18(v2floatOutputPtr) Output
  %19 = OpTypeVoid
  %21 = OpTypeFunction %19
  %24 = OpConstant %11(uint) 0
  %25 = OpTypePointer Input %3(float)
  %28 = OpConstant %11(uint) 1
  %32 = OpTypeFloat 64
  %31 = OpConstant %32(double) 0
  %34 = OpConstant %32(double) 1

; Functions
  %20 = OpFunction %19 [None]  %21(func)
  %22 = OpLabel
  %23 = OpLoad %4(v2float) %6(texcoord)
        OpStore %17(vtx_texture) %23
  %26 = OpAccessChain %25(floatInputPtr) %2(position) %24(0)
  %27 = OpLoad %3(float) %26
  %29 = OpAccessChain %25(floatInputPtr) %2(position) %28(1)
  %30 = OpLoad %3(float) %29
  %33 = OpFConvert %3(float) %31(0.000000)
  %35 = OpFConvert %3(float) %34(1.000000)
  %36 = OpCompositeConstruct %15(v4float) %27 %30 %33 %35
        OpStore %14(gl_Position) %36
        OpReturn
        OpFunctionEnd
```

Some optimisations are still needed, with SPIR-V.

There is also an internal debug format :
```
STINOUTVARDECL LOC(0) VAR(INATTR,FVEC2) position
STINOUTVARDECL LOC(1) VAR(INATTR,FVEC2) texcoord
STINOUTVARDECL LOC(0) VAR(OUTATTR,FVEC2) vtx_texture
STPERVERTEXDECL VERTOUT
STFUNCDECL VOID main()
        STSIMPLE ASSIGN (IDENT vtx_texture) (IDENT texcoord)
        STSIMPLE ASSIGN (IDENT gl_Position) (COMPOSITECONSTRUCT VEC4 FLOAT ((SWIZZLE x (IDENT position)), (SWIZZLE y (IDENT position)), (LITERAL 0.0), (LITERAL 1.0)))
```