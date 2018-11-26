ShaderWriter
============

This library is used to write shaders directly from C++ code.
It is split in two main libraries (ShaderAST and ShaderWriter) and a "compiler" library for each front end language (CompilerGLSL, CompilerHLSL and CompilerSpirV).
ShaderAST holds the base architecture (expressions and statements, roughly) used to describe a shader.
ShaderWriter is based on ShaderAST, and is fully typed, to be able to write GLSL-like shaders in C++.
The compiler libraries allow exporting the generated AST in either of these shader languages.

Examples
--------

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
#version 450
#extension GL_KHR_vulkan_glsl : enable
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

The following HLSL:
```hlsl
struct HLSL_SDW_Input
{
	float2 position: TEXCOORD0;
	float2 texcoord: TEXCOORD1;
};

struct HLSL_SDW_Output
{
	float2 vtx_texture: TEXCOORD0;
	float4 gl_Position: SV_Position;
};

HLSL_SDW_Output main(in HLSL_SDW_Input sdwInput)
{
	HLSL_SDW_Output sdwOutput;
	sdwOutput.vtx_texture = sdwInput.texcoord;
	sdwOutput.gl_Position = float4(sdwInput.position.x, sdwInput.position.y, 0.0, 1.0);
	return sdwOutput;
}
```

And the following SPIR-V listing:
```
; Magic:     0x07230203
; Version:   0x00010200
; Generator: 0x00100001
; Bound:     26
; Schema:    0

        OpCapability Shader
   %1 = OpExtInstImport "GLSL.std.450"
        OpMemoryModel Logical GLSL450
        OpEntryPoint Vertex %11 "main" %2 %6 %7

; Debug
        OpSource GLSL 450
        OpName %2(position) "position"
        OpName %6(texcoord) "texcoord"
        OpName %7(vtx_texture) "vtx_texture"
        OpName %11(main) "main"
        OpName %15(gl_Position) "gl_Position"

; Decorations
        OpDecorate %2(position) Location 0
        OpDecorate %6(texcoord) Location 1
        OpDecorate %7(vtx_texture) Location 0
        OpDecorate %15(gl_Position) BuiltIn Position

; Types, Constants, and Global Variables
   %3 = OpTypeFloat 32
   %4 = OpTypeVector %3(float) 2
   %5 = OpTypePointer Input %4(vec)
   %2 = OpVariable %5(ptr) Input
   %6 = OpVariable %5(ptr) Input
   %8 = OpTypePointer Output %4(vec)
   %7 = OpVariable %8(ptr) Output
   %9 = OpTypeVoid
  %10 = OpTypeFunction %9
  %14 = OpTypeVector %3(float) 4
  %16 = OpTypeVector %3(float) 4
  %17 = OpTypePointer Output %16(vec)
  %15 = OpVariable %17(ptr) Output
  %19 = OpTypePointer Function %3(float)
  %23 = OpConstant %3(float) 0
  %24 = OpConstant %3(float) 1

; Functions
  %11 = OpFunction %9 [None]  %10(func)
  %12 = OpLabel
  %13 = OpLoad %4(vec) %6(texcoord)
        OpStore %7(vtx_texture) %13
  %18 = OpLoad %4(vec) %2(position)
  %20 = OpVectorShuffle %19(ptr) %18 Undef 0
  %21 = OpLoad %4(vec) %2(position)
  %22 = OpVectorShuffle %19(ptr) %21 Undef 1
  %25 = OpCompositeConstruct %14(vec) %20 %22 %23(0.000000) %24(1.000000)
        OpStore %15(gl_Position) %25
        OpReturn
        OpFunctionEnd
```

Some optimisations are still needed, with SPIR-V (for example here, we have a duplicate for vec4 OpTypeVector)