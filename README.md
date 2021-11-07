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
struct SurfaceT
	: sdw::StructInstance
{
	SurfaceT( sdw::ShaderWriter & writer
		, sdw::expr::ExprPtr expr
		, bool enabled = true )
		: sdw::StructInstance{ writer, std::move( expr ), enabled }
		, position{ getMember< sdw::Vec2 >( "position" ) }
		, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
	{
	}

	SDW_DeclStructInstance( , SurfaceT );

	static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
			, ( FlagT == sdw::var::Flag::eShaderOutput
				? std::string{ "Out" }
				: std::string{ "In" } ) + "Position"
			, FlagT );

		if ( result->empty() )
		{
			result->declMember( "position"
				, sdw::type::Kind::eVec2F
				, sdw::type::NotArray
				, 0u );
			result->declMember( "texcoord"
				, sdw::type::Kind::eVec2F
				, sdw::type::NotArray
				, 1u );
		}

		return result;
	}

	sdw::Vec2 position;
	sdw::Vec2 texcoord;
};

void vertex()
{
	using namespace sdw;
	VertexWriter writer;

	writer.implementMainT< SurfaceT, SurfaceT >( [&]( sdw::VertexInT< SurfaceT > in
		, sdw::VertexOutT< SurfaceT > out )
		{
			out.texcoord = in.texcoord;
			out.position = in.position;
			out.vtx.position = vec4( in.position.xy(), 0.0, 1.0 );
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
layout(location=0) in vec2 sdwIn_position;
layout(location=1) in vec2 sdwIn_texcoord;
layout(location=0) out vec2 sdwOut_position;
layout(location=1) out vec2 sdwOut_texcoord;

out gl_PerVertex
{
	vec4 gl_Position;
	float gl_PointSize;
	float gl_ClipDistance[];
	float gl_CullDistance[];
};

void main()
{
	sdwOut_texcoord = sdwIn_texcoord;
	sdwOut_position = sdwIn_position;
	gl_Position = vec4(sdwIn_position, 0.0f, 1.0f);
}
```

The following HLSL (Shader Model 5):
```hlsl
struct HLSL_SDW_ParamHighFreqInput
{
	float2 texcoord: TEXCOORD1;
	float2 position: TEXCOORD0;
};

struct HLSL_SDW_ParamMainHighFreqOutput
{
	float2 texcoord: TEXCOORD1;
	float2 position: TEXCOORD0;
	float4 Position: SV_Position;
};

void main(in HLSL_SDW_ParamHighFreqInput sdwHighFreqInputParam
	, out HLSL_SDW_ParamMainHighFreqOutput sdwMainHighFreqOutputParam)
{
	sdwMainHighFreqOutputParam.texcoord = sdwHighFreqInputParam.texcoord;
	sdwMainHighFreqOutputParam.position = sdwHighFreqInputParam.position;
	sdwMainHighFreqOutputParam.Position = float4(sdwHighFreqInputParam.position, 0.0f, 1.0f);
}
```

And the following SPIR-V listing:
```
; Magic:     0x07230203
; Version:   0x00010300
; Generator: 0x00100001
; Bound:     23
; Schema:    0

        OpCapability Shader
   %1 = OpExtInstImport "GLSL.std.450"
        OpMemoryModel Logical GLSL450
        OpEntryPoint Vertex %14 "main" %2 %6 %7 %9 %10

; Debug
        OpSource GLSL 460
        OpName %2(sdwIn_texcoord) "sdwIn_texcoord"
        OpName %6(sdwIn_position) "sdwIn_position"
        OpName %7(sdwOut_texcoord) "sdwOut_texcoord"
        OpName %9(sdwOut_position) "sdwOut_position"
        OpName %10(OutPosition) "OutPosition"
        OpName %14(main) "main"

; Decorations
        OpDecorate %10(OutPosition) BuiltIn Position
        OpDecorate %2(sdwIn_texcoord) Location 1
        OpDecorate %7(sdwOut_texcoord) Location 1
        OpDecorate %6(sdwIn_position) Location 0
        OpDecorate %9(sdwOut_position) Location 0

; Types, Constants, and Global Variables
   %3 = OpTypeFloat 32
   %4 = OpTypeVector %3(f32) 2
   %5 = OpTypePointer Input %4(v2f32)
   %2 = OpVariable %5(InputPtr<v2f32>) Input
   %6 = OpVariable %5(InputPtr<v2f32>) Input
   %8 = OpTypePointer Output %4(v2f32)
   %7 = OpVariable %8(OutputPtr<v2f32>) Output
   %9 = OpVariable %8(OutputPtr<v2f32>) Output
  %11 = OpTypeVector %3(f32) 4
  %12 = OpTypePointer Output %11(v4f32)
  %10 = OpVariable %12(OutputPtr<v4f32>) Output
  %13 = OpTypeVoid
  %15 = OpTypeFunction %13
  %20 = OpConstant %3(f32) 0
  %21 = OpConstant %3(f32) 1

; Functions
  %14 = OpFunction %13 [None]  %15(func)
  %16 = OpLabel
  %17 = OpLoad %4(v2f32) %2(sdwIn_texcoord)
        OpStore %7(sdwOut_texcoord) %17
  %18 = OpLoad %4(v2f32) %6(sdwIn_position)
        OpStore %9(sdwOut_position) %18
  %19 = OpLoad %4(v2f32) %6(sdwIn_position)
  %22 = OpCompositeConstruct %11(v4f32) %19 %20(0.000000) %21(1.000000)
        OpStore %10(OutPosition) %22
        OpReturn
        OpFunctionEnd
```

Some optimisations have been done, but more could be, with SPIR-V (the double load of `sdwIn_position`, for example, in this case).

There is also an internal debug format :
```
STFUNCDECL VOID main(VAR(INATTR,STRUCT(InPosTex,C)) vertIn, VAR(OUTATTR,STRUCT(OutPosTex,C)) vertOut)
	STSIMPLE ASSIGN (MBRSELECT (IDENT vertOut) (texcoord)) (MBRSELECT (IDENT vertIn) (texcoord))
	STSIMPLE ASSIGN (MBRSELECT (IDENT vertOut) (position)) (MBRSELECT (IDENT vertIn) (position))
	STSIMPLE ASSIGN (MBRSELECT (IDENT vertOut) (Position)) (COMPOSITECONSTRUCT VEC4 FLOAT ((SWIZZLE xy (MBRSELECT (IDENT vertIn) (position))), (LITERAL 0.0), (LITERAL 1.0)))
```

## Contact

You can reach me on the Discord server dedicated to my projects: [DragonJoker's Lair](https://discord.gg/9A97r44tgP)
