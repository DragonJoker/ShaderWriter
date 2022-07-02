<p align="center">
  <a href="https://github.com/DragonJoker/ShaderWriter/actions?query=workflow%3ABuild"><img alt="Build status" src="https://github.com/DragonJoker/ShaderWriter/workflows/Build/badge.svg"></a>
</p>


# ShaderWriter

This library is used to write shaders directly from C++ code.

It is split in two main libraries (ShaderAST and ShaderWriter) and a "compiler" library for each front end language (CompilerGLSL, CompilerHLSL and CompilerSpirV).

ShaderAST holds the base architecture (expressions and statements, roughly) used to describe a shader.

ShaderWriter is based on ShaderAST, and is fully typed, to be able to write GLSL-like shaders in C++.

The compiler libraries allow exporting the generated AST in either of these shader languages. 

## How to build
### Using packages repositories
You can find shaderwriter on several packages repositories:
- ArchLinux's <a href="https://aur.archlinux.org/packages/shaderwriter-git/">AUR</a> (thanks to <a href="https://github.com/Arthapz">Arthapz</a>)
- <a href="https://github.com/xmake-io/xmake-repo">xmake-repo</a> (thanks to <a href="https://github.com/WubiCookie">WubiCookie</a>)
- <a href="https://github.com/microsoft/vcpkg">vcpkg</a>

### Using cmake
The following command line should be a good start to build ShaderWriter:
```bash
cmake <shaderwriter_root> -DCMAKE_BUILD_TYPE=Release
```

By default, all libraries (ShaderAST, ShaderWriter and all compilers) will be built as dynamic libraries.

You can use the option `-DSDW_BUILD_STATIC=ON` to force static build for all of them.

## Examples

Let's take the following vertex shader code, written in C++:

```cpp
template< sdw::var::Flag FlagT >
using PosColStructT = sdw::IOStructInstanceHelperT< FlagT
	, "PosCol"
	, sdw::IOStructFieldT< sdw::Vec4, "position", 0u >
	, sdw::IOStructFieldT< sdw::Vec4, "colour", 1u > >;

template< sdw::var::Flag FlagT >
struct PosColT
	: public PosColStructT< FlagT >
{
	PosColT( sdw::ShaderWriter & writer
		, sdw::expr::ExprPtr expr
		, bool enabled = true )
		: PosColStructT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	auto position()const { return this->getMember< "position" >(); }
	auto colour()const { return this->getMember< "colour" >(); }
};

void vertex()
{
	using namespace sdw;
	VertexWriter writer;

	writer.implementMainT< PosColT, PosColT >( [&]( VertexInT< PosColT > in
		, VertexOutT< PosColT > out )
		{
			out.colour() = in.colour();
			out.position() = in.position();
			out.vtx.position = in.position();
		} );

	// Select your weapon !
	auto glsl = compileGlsl( writer.getShader()
		, SpecialisationInfo{}
		, glsl::GlslConfig{} );
	auto hlsl = compileHlsl( writer.getShader()
		, SpecialisationInfo{}
		, hlsl::HlslConfig{} );
	auto binSpirV = serialiseSpirv( writer.getShader()
		, spirv::SpirVConfig{} );
	auto textSpirV = writeSpirv( writer.getShader()
		, spirv::SpirVConfig{} );
}
```

This shader will generate the following GLSL:
```glsl
#version 430
layout(location=0) in vec4 sdwIn_position;
layout(location=1) in vec4 sdwIn_colour;
layout(location=0) out vec4 sdwOut_position;
layout(location=1) out vec4 sdwOut_colour;

out gl_PerVertex
{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[];
	float gl_CullDistance[];
};

void main()
{
	sdwOut_colour = sdwIn_colour;
	sdwOut_position = sdwIn_position;
	gl_Position = sdwIn_position;
}
```

The following HLSL (Shader Model 5):
```hlsl
struct HLSL_SDW_GlobalInput
{
	float4 colour: TEXCOORD1;
	float4 position: TEXCOORD0;
};

struct HLSL_SDW_MainOutput
{
	float4 colour: TEXCOORD1;
	float4 position: TEXCOORD0;
	float4 Position: SV_Position;
};

void main(in HLSL_SDW_GlobalInput sdwGlobalInput
	, out HLSL_SDW_MainOutput sdwMainOutput)
{
	sdwMainOutput.colour = sdwGlobalInput.colour;
	sdwMainOutput.position = sdwGlobalInput.position;
	sdwMainOutput.Position = sdwGlobalInput.position;
}
```

And the following SPIR-V listing:
```
; Magic:     0x07230203
; Version:   0x00010300
; Generator: 0x00210012
; Bound:     18
; Schema:    0

        Capability Shader

        MemoryModel Logical GLSL450
        EntryPoint Vertex %12 "main" %2 %6 %7 %9 %10

; Debug
        Source LanguageGLSL 460
        Name %2(sdwIn_colour) "sdwIn_colour"
        Name %6(sdwIn_position) "sdwIn_position"
        Name %7(sdwOut_colour) "sdwOut_colour"
        Name %9(sdwOut_position) "sdwOut_position"
        Name %10(OutPosition) "OutPosition"
        Name %12(main) "main"

; Decorations
        Decorate %10(OutPosition) BuiltIn Position
        Decorate %7(sdwOut_colour) Location 1
        Decorate %2(sdwIn_colour) Location 1
        Decorate %9(sdwOut_position) Location 0
        Decorate %6(sdwIn_position) Location 0

; Types, Constants, and Global Variables
   %3 = TypeFloat 32
   %4 = TypeVector %3(f32) 4
   %5 = TypePointer Input %4(v4f32)
   %2 = Variable %5(InputPtr<v4f32>) Input
   %6 = Variable %5(InputPtr<v4f32>) Input
   %8 = TypePointer Output %4(v4f32)
   %7 = Variable %8(OutputPtr<v4f32>) Output
   %9 = Variable %8(OutputPtr<v4f32>) Output
  %10 = Variable %8(OutputPtr<v4f32>) Output
  %11 = TypeVoid
  %13 = TypeFunction %11

; Functions
  %12 = Function %11 [None]  %13(func)
  %14 = Label
  %15 = Load %4(v4f32) %2(sdwIn_colour)
        Store %7(sdwOut_colour) %15
  %16 = Load %4(v4f32) %6(sdwIn_position)
        Store %9(sdwOut_position) %16
  %17 = Load %4(v4f32) %6(sdwIn_position)
        Store %10(OutPosition) %17
        Return
        FunctionEnd
```

Some optimisations have been done, but more could be, with SPIR-V (the double load of `sdwIn_position`, for example, in this case).

## Contact

You can reach me on the Discord server dedicated to my projects: [DragonJoker's Lair](https://discord.gg/9A97r44tgP)
