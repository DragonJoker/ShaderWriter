#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	template< sdw::var::Flag FlagT >
	struct ColourT
		: sdw::StructInstance
	{
		ColourT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, colour{ getMember< sdw::Vec3 >( "colour" ) }
		{
		}

		SDW_DeclStructInstance( , ColourT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Colour"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 0u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Colour" );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 colour;
	};

	struct Light
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , Light );

		Light( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, colorIntensity{ getMember< sdw::Vec4 >( "colorIntensity" ) }
			, color{ colorIntensity.xyz() }
			, intensity{ colorIntensity.w() }
		{
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140
				, "Light" );

			if ( result->empty() )
			{
				result->declMember( "colorIntensity", ast::type::Kind::eVec4F );
			}

			return result;
		}

		sdw::Vec4 colorIntensity;
		sdw::Vec3 color;
		sdw::Float intensity;

	private:
		using sdw::StructInstance::getMember;
		using sdw::StructInstance::getMemberArray;
	};

	Writer_Parameter( Light );

	enum class Flags
	{
		None,
		Positions,
		Normals,
		Both,
	};
	std::string getFlagsName( Flags f )
	{
		switch ( f )
		{
		case Flags::None:
			return "None";
		case Flags::Positions:
			return "Positions";
		case Flags::Normals:
			return "Normals";
		case Flags::Both:
			return "Both";
		default:
			return "Undefined";
		}
	}

	struct Parameterized
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , Parameterized );

		Parameterized( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position", true ) }
			, normal{ getMember< sdw::Vec3 >( "normal", true ) }
		{
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache
			, Flags flags )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140
				, "Parameterized" + std::to_string( uint32_t( flags ) ) );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray
					, uint32_t( flags ) & 0x01 );
				result->declMember( "normal"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray
					, uint32_t( flags ) & 0x02 );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec3 normal;

	private:
		using sdw::StructInstance::getMember;
		using sdw::StructInstance::getMemberArray;
	};

	Writer_Parameter( Light );

#if SDW_EnableStructHelper

	struct Light2
		: public sdw::StructInstanceHelperT< "Light"
			, ast::type::MemoryLayout::eStd140
			, sdw::StructFieldT< sdw::Vec4, "colorIntensity" > >
	{
		Light2( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstanceHelperT{ writer, std::move( expr ), enabled }
		{
		}

		auto colorIntensity() { return getMember< "colorIntensity" >(); }
		auto color() { return colorIntensity().xyz(); }
		auto intensity() { return colorIntensity().w(); }
	};

	Writer_Parameter( Light2 );

#endif

	template< typename MbrTypeT, ast::var::Flag FlagT >
	struct IOTestMatStructT;

	template< typename MbrTypeT >
	using TestMatStructT = IOTestMatStructT< MbrTypeT, sdw::var::Flag::eNone >;

	template< typename MbrTypeT, ast::var::Flag FlagT >
	struct IOTestMatStructT
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , IOTestMatStructT );

		IOTestMatStructT( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, member{ sdw::StructInstance::getMember< MbrTypeT >( "member" ) }
		{
		}

		IOTestMatStructT( sdw::ShaderWriter & writer, TestMatStructT< MbrTypeT > const & rhs )
			: IOTestMatStructT{ writer
				, sdw::StructInstance::makeInitExpr( makeType( writer.getTypesCache() ), &rhs )
				, true }
		{
		}

		IOTestMatStructT( sdw::ShaderWriter & writer )
			: IOTestMatStructT{ writer
				, sdw::StructInstance::makeInitExpr( makeType( writer.getTypesCache() ), nullptr )
				, true }
		{
		}

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			ast::type::IOStructPtr result = cache.getIOStruct( "IOTestMatStruct", entryPoint, FlagT );

			if ( result->empty() )
			{
				uint32_t index{};
				result->declMember( "member", MbrTypeT::makeType( cache ), index ); ++index;
			}

			return result;
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eC
				, "TestMatStruct" );

			if ( result->empty() )
			{
				result->declMember( "member", MbrTypeT::makeType( cache ) );
			}

			return result;
		}

		MbrTypeT member;
	};

	template< ast::var::Flag FlagT >
	struct IOTestStructT;

	using TestStruct = IOTestStructT< sdw::var::Flag::eNone >;

	template< ast::var::Flag FlagT >
	struct IOTestStructT
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , IOTestStructT );

		IOTestStructT( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, booleanMember{ sdw::StructInstance::getMember< sdw::Boolean >( "booleanMember", true ) }
			, int8Member{ sdw::StructInstance::getMember< sdw::Int8 >( "int8Member" ) }
			, int16Member{ sdw::StructInstance::getMember< sdw::Int16 >( "int16Member" ) }
			, int32Member{ sdw::StructInstance::getMember< sdw::Int32 >( "int32Member" ) }
			, int64Member{ sdw::StructInstance::getMember< sdw::Int64 >( "int64Member" ) }
			, uInt8Member{ sdw::StructInstance::getMember< sdw::UInt8 >( "uInt8Member" ) }
			, uInt16Member{ sdw::StructInstance::getMember< sdw::UInt16 >( "uInt16Member" ) }
			, uInt32Member{ sdw::StructInstance::getMember< sdw::UInt32 >( "uInt32Member" ) }
			, uInt64Member{ sdw::StructInstance::getMember< sdw::UInt64 >( "uInt64Member" ) }
			, floatMember{ sdw::StructInstance::getMember< sdw::Float >( "floatMember" ) }
			, doubleMember{ sdw::StructInstance::getMember< sdw::Double >( "doubleMember" ) }
			, vec2BMember{ sdw::StructInstance::getMember< sdw::BVec2 >( "vec2BMember", true ) }
			, vec3BMember{ sdw::StructInstance::getMember< sdw::BVec3 >( "vec3BMember", true ) }
			, vec4BMember{ sdw::StructInstance::getMember< sdw::BVec4 >( "vec4BMember", true ) }
			, vec2I8Member{ sdw::StructInstance::getMember< sdw::I8Vec2 >( "vec2I8Member" ) }
			, vec3I8Member{ sdw::StructInstance::getMember< sdw::I8Vec3 >( "vec3I8Member" ) }
			, vec4I8Member{ sdw::StructInstance::getMember< sdw::I8Vec4 >( "vec4I8Member" ) }
			, vec2I16Member{ sdw::StructInstance::getMember< sdw::I16Vec2 >( "vec2I16Member" ) }
			, vec3I16Member{ sdw::StructInstance::getMember< sdw::I16Vec3 >( "vec3I16Member" ) }
			, vec4I16Member{ sdw::StructInstance::getMember< sdw::I16Vec4 >( "vec4I16Member" ) }
			, vec2I32Member{ sdw::StructInstance::getMember< sdw::I32Vec2 >( "vec2I32Member" ) }
			, vec3I32Member{ sdw::StructInstance::getMember< sdw::I32Vec3 >( "vec3I32Member" ) }
			, vec4I32Member{ sdw::StructInstance::getMember< sdw::I32Vec4 >( "vec4I32Member" ) }
			, vec2I64Member{ sdw::StructInstance::getMember< sdw::I64Vec2 >( "vec2I64Member" ) }
			, vec3I64Member{ sdw::StructInstance::getMember< sdw::I64Vec3 >( "vec3I64Member" ) }
			, vec4I64Member{ sdw::StructInstance::getMember< sdw::I64Vec4 >( "vec4I64Member" ) }
			, vec2U8Member{ sdw::StructInstance::getMember< sdw::U8Vec2 >( "vec2U8Member" ) }
			, vec3U8Member{ sdw::StructInstance::getMember< sdw::U8Vec3 >( "vec3U8Member" ) }
			, vec4U8Member{ sdw::StructInstance::getMember< sdw::U8Vec4 >( "vec4U8Member" ) }
			, vec2U16Member{ sdw::StructInstance::getMember< sdw::U16Vec2 >( "vec2U16Member" ) }
			, vec3U16Member{ sdw::StructInstance::getMember< sdw::U16Vec3 >( "vec3U16Member" ) }
			, vec4U16Member{ sdw::StructInstance::getMember< sdw::U16Vec4 >( "vec4U16Member" ) }
			, vec2U32Member{ sdw::StructInstance::getMember< sdw::U32Vec2 >( "vec2U32Member" ) }
			, vec3U32Member{ sdw::StructInstance::getMember< sdw::U32Vec3 >( "vec3U32Member" ) }
			, vec4U32Member{ sdw::StructInstance::getMember< sdw::U32Vec4 >( "vec4U32Member" ) }
			, vec2U64Member{ sdw::StructInstance::getMember< sdw::U64Vec2 >( "vec2U64Member" ) }
			, vec3U64Member{ sdw::StructInstance::getMember< sdw::U64Vec3 >( "vec3U64Member" ) }
			, vec4U64Member{ sdw::StructInstance::getMember< sdw::U64Vec4 >( "vec4U64Member" ) }
			, vec2FMember{ sdw::StructInstance::getMember< sdw::Vec2 >( "vec2FMember" ) }
			, vec3FMember{ sdw::StructInstance::getMember< sdw::Vec3 >( "vec3FMember" ) }
			, vec4FMember{ sdw::StructInstance::getMember< sdw::Vec4 >( "vec4FMember" ) }
			, vec2DMember{ sdw::StructInstance::getMember< sdw::DVec2 >( "vec2DMember" ) }
			, vec3DMember{ sdw::StructInstance::getMember< sdw::DVec3 >( "vec3DMember" ) }
			, vec4DMember{ sdw::StructInstance::getMember< sdw::DVec4 >( "vec4DMember" ) }
			, mat2x2FMember{ sdw::StructInstance::getMember< sdw::Mat2x2 >( "mat2x2FMember" ) }
			, mat2x3FMember{ sdw::StructInstance::getMember< sdw::Mat2x3 >( "mat2x3FMember" ) }
			, mat2x4FMember{ sdw::StructInstance::getMember< sdw::Mat2x4 >( "mat2x4FMember" ) }
			, mat3x2FMember{ sdw::StructInstance::getMember< sdw::Mat3x2 >( "mat3x2FMember" ) }
			, mat3x3FMember{ sdw::StructInstance::getMember< sdw::Mat3x3 >( "mat3x3FMember" ) }
			, mat3x4FMember{ sdw::StructInstance::getMember< sdw::Mat3x4 >( "mat3x4FMember" ) }
			, mat4x2FMember{ sdw::StructInstance::getMember< sdw::Mat4x2 >( "mat4x2FMember" ) }
			, mat4x3FMember{ sdw::StructInstance::getMember< sdw::Mat4x3 >( "mat4x3FMember" ) }
			, mat4x4FMember{ sdw::StructInstance::getMember< sdw::Mat4x4 >( "mat4x4FMember" ) }
			, mat2x2DMember{ sdw::StructInstance::getMember< sdw::DMat2x2 >( "mat2x2DMember" ) }
			, mat2x3DMember{ sdw::StructInstance::getMember< sdw::DMat2x3 >( "mat2x3DMember" ) }
			, mat2x4DMember{ sdw::StructInstance::getMember< sdw::DMat2x4 >( "mat2x4DMember" ) }
			, mat3x2DMember{ sdw::StructInstance::getMember< sdw::DMat3x2 >( "mat3x2DMember" ) }
			, mat3x3DMember{ sdw::StructInstance::getMember< sdw::DMat3x3 >( "mat3x3DMember" ) }
			, mat3x4DMember{ sdw::StructInstance::getMember< sdw::DMat3x4 >( "mat3x4DMember" ) }
			, mat4x2DMember{ sdw::StructInstance::getMember< sdw::DMat4x2 >( "mat4x2DMember" ) }
			, mat4x3DMember{ sdw::StructInstance::getMember< sdw::DMat4x3 >( "mat4x3DMember" ) }
			, mat4x4DMember{ sdw::StructInstance::getMember< sdw::DMat4x4 >( "mat4x4DMember" ) }
		{
		}

		IOTestStructT( sdw::ShaderWriter & writer, TestStruct const & rhs )
			: IOTestStructT{ writer
				, sdw::StructInstance::makeInitExpr( makeType( writer.getTypesCache() ), &rhs )
				, true }
		{
		}

		IOTestStructT( sdw::ShaderWriter & writer )
			: IOTestStructT{ writer
				, sdw::StructInstance::makeInitExpr( makeType( writer.getTypesCache() ), nullptr )
				, true }
		{
		}

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			ast::type::IOStructPtr result = cache.getIOStruct( "IOTestStruct", entryPoint, FlagT );

			if ( result->empty() )
			{
				uint32_t index{};
				result->declMember( "int8Member", ast::type::Kind::eInt8, index ); ++index;
				result->declMember( "int16Member", ast::type::Kind::eInt16, index ); ++index;
				result->declMember( "int32Member", ast::type::Kind::eInt32, index ); ++index;
				result->declMember( "int64Member", ast::type::Kind::eInt64, index ); ++index;
				result->declMember( "uInt16Member", ast::type::Kind::eUInt16, index ); ++index;
				result->declMember( "uInt32Member", ast::type::Kind::eUInt32, index ); ++index;
				result->declMember( "uInt64Member", ast::type::Kind::eUInt64, index ); ++index;
				result->declMember( "floatMember", ast::type::Kind::eFloat, index ); ++index;
				result->declMember( "doubleMember", ast::type::Kind::eDouble, index ); ++index;
				result->declMember( "vec2I8Member", ast::type::Kind::eVec2I8, index ); ++index;
				result->declMember( "vec3I8Member", ast::type::Kind::eVec3I8, index ); ++index;
				result->declMember( "vec4I8Member", ast::type::Kind::eVec4I8, index ); ++index;
				result->declMember( "vec2I16Member", ast::type::Kind::eVec2I16, index ); ++index;
				result->declMember( "vec3I16Member", ast::type::Kind::eVec3I16, index ); ++index;
				result->declMember( "vec4I16Member", ast::type::Kind::eVec4I16, index ); ++index;
				result->declMember( "vec2I32Member", ast::type::Kind::eVec2I32, index ); ++index;
				result->declMember( "vec3I32Member", ast::type::Kind::eVec3I32, index ); ++index;
				result->declMember( "vec4I32Member", ast::type::Kind::eVec4I32, index ); ++index;
				result->declMember( "vec2I64Member", ast::type::Kind::eVec2I64, index ); ++index;
				result->declMember( "vec3I64Member", ast::type::Kind::eVec3I64, index ); ++index;
				result->declMember( "vec4I64Member", ast::type::Kind::eVec4I64, index ); ++index;
				result->declMember( "vec2U8Member", ast::type::Kind::eVec2U8, index ); ++index;
				result->declMember( "vec3U8Member", ast::type::Kind::eVec3U8, index ); ++index;
				result->declMember( "vec4U8Member", ast::type::Kind::eVec4U8, index ); ++index;
				result->declMember( "vec2U16Member", ast::type::Kind::eVec2U16, index ); ++index;
				result->declMember( "vec3U16Member", ast::type::Kind::eVec3U16, index ); ++index;
				result->declMember( "vec4U16Member", ast::type::Kind::eVec4U16, index ); ++index;
				result->declMember( "vec2U32Member", ast::type::Kind::eVec2U32, index ); ++index;
				result->declMember( "vec3U32Member", ast::type::Kind::eVec3U32, index ); ++index;
				result->declMember( "vec4U32Member", ast::type::Kind::eVec4U32, index ); ++index;
				result->declMember( "vec2U64Member", ast::type::Kind::eVec2U64, index ); ++index;
				result->declMember( "vec3U64Member", ast::type::Kind::eVec3U64, index ); ++index;
				result->declMember( "vec4U64Member", ast::type::Kind::eVec4U64, index ); ++index;
				result->declMember( "vec2FMember", ast::type::Kind::eVec2F, index ); ++index;
				result->declMember( "vec3FMember", ast::type::Kind::eVec3F, index ); ++index;
				result->declMember( "vec4FMember", ast::type::Kind::eVec4F, index ); ++index;
				result->declMember( "vec2DMember", ast::type::Kind::eVec2D, index ); ++index;
				result->declMember( "vec3DMember", ast::type::Kind::eVec3D, index ); ++index;
				result->declMember( "vec4DMember", ast::type::Kind::eVec4D, index ); ++index;
				result->declMember( "mat2x2FMember", ast::type::Kind::eMat2x2F, index ); ++index;
				result->declMember( "mat2x3FMember", ast::type::Kind::eMat2x3F, index ); ++index;
				result->declMember( "mat2x4FMember", ast::type::Kind::eMat2x4F, index ); ++index;
				result->declMember( "mat3x2FMember", ast::type::Kind::eMat3x2F, index ); ++index;
				result->declMember( "mat3x3FMember", ast::type::Kind::eMat3x3F, index ); ++index;
				result->declMember( "mat3x4FMember", ast::type::Kind::eMat3x4F, index ); ++index;
				result->declMember( "mat4x2FMember", ast::type::Kind::eMat4x2F, index ); ++index;
				result->declMember( "mat4x3FMember", ast::type::Kind::eMat4x3F, index ); ++index;
				result->declMember( "mat4x4FMember", ast::type::Kind::eMat4x4F, index ); ++index;
				result->declMember( "mat2x2DMember", ast::type::Kind::eMat2x2D, index ); ++index;
				result->declMember( "mat2x3DMember", ast::type::Kind::eMat2x3D, index ); ++index;
				result->declMember( "mat2x4DMember", ast::type::Kind::eMat2x4D, index ); ++index;
				result->declMember( "mat3x2DMember", ast::type::Kind::eMat3x2D, index ); ++index;
				result->declMember( "mat3x3DMember", ast::type::Kind::eMat3x3D, index ); ++index;
				result->declMember( "mat3x4DMember", ast::type::Kind::eMat3x4D, index ); ++index;
				result->declMember( "mat4x2DMember", ast::type::Kind::eMat4x2D, index ); ++index;
				result->declMember( "mat4x3DMember", ast::type::Kind::eMat4x3D, index ); ++index;
				result->declMember( "mat4x4DMember", ast::type::Kind::eMat4x4D, index ); ++index;
			}

			return result;
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eC
				, "TestStruct" );

			if ( result->empty() )
			{
				result->declMember( "booleanMember", ast::type::Kind::eBoolean );
				result->declMember( "int8Member", ast::type::Kind::eInt8 );
				result->declMember( "int16Member", ast::type::Kind::eInt16 );
				result->declMember( "int32Member", ast::type::Kind::eInt32 );
				result->declMember( "int64Member", ast::type::Kind::eInt64 );
				result->declMember( "uInt8Member", ast::type::Kind::eUInt8 );
				result->declMember( "uInt16Member", ast::type::Kind::eUInt16 );
				result->declMember( "uInt32Member", ast::type::Kind::eUInt32 );
				result->declMember( "uInt64Member", ast::type::Kind::eUInt64 );
				result->declMember( "floatMember", ast::type::Kind::eFloat );
				result->declMember( "doubleMember", ast::type::Kind::eDouble );
				result->declMember( "vec2BMember", ast::type::Kind::eVec2B );
				result->declMember( "vec3BMember", ast::type::Kind::eVec3B );
				result->declMember( "vec4BMember", ast::type::Kind::eVec4B );
				result->declMember( "vec2I8Member", ast::type::Kind::eVec2I8 );
				result->declMember( "vec3I8Member", ast::type::Kind::eVec3I8 );
				result->declMember( "vec4I8Member", ast::type::Kind::eVec4I8 );
				result->declMember( "vec2I16Member", ast::type::Kind::eVec2I16 );
				result->declMember( "vec3I16Member", ast::type::Kind::eVec3I16 );
				result->declMember( "vec4I16Member", ast::type::Kind::eVec4I16 );
				result->declMember( "vec2I32Member", ast::type::Kind::eVec2I32 );
				result->declMember( "vec3I32Member", ast::type::Kind::eVec3I32 );
				result->declMember( "vec4I32Member", ast::type::Kind::eVec4I32 );
				result->declMember( "vec2I64Member", ast::type::Kind::eVec2I64 );
				result->declMember( "vec3I64Member", ast::type::Kind::eVec3I64 );
				result->declMember( "vec4I64Member", ast::type::Kind::eVec4I64 );
				result->declMember( "vec2U8Member", ast::type::Kind::eVec2U8 );
				result->declMember( "vec3U8Member", ast::type::Kind::eVec3U8 );
				result->declMember( "vec4U8Member", ast::type::Kind::eVec4U8 );
				result->declMember( "vec2U16Member", ast::type::Kind::eVec2U16 );
				result->declMember( "vec3U16Member", ast::type::Kind::eVec3U16 );
				result->declMember( "vec4U16Member", ast::type::Kind::eVec4U16 );
				result->declMember( "vec2U32Member", ast::type::Kind::eVec2U32 );
				result->declMember( "vec3U32Member", ast::type::Kind::eVec3U32 );
				result->declMember( "vec4U32Member", ast::type::Kind::eVec4U32 );
				result->declMember( "vec2U64Member", ast::type::Kind::eVec2U64 );
				result->declMember( "vec3U64Member", ast::type::Kind::eVec3U64 );
				result->declMember( "vec4U64Member", ast::type::Kind::eVec4U64 );
				result->declMember( "vec2FMember", ast::type::Kind::eVec2F );
				result->declMember( "vec3FMember", ast::type::Kind::eVec3F );
				result->declMember( "vec4FMember", ast::type::Kind::eVec4F );
				result->declMember( "vec2DMember", ast::type::Kind::eVec2D );
				result->declMember( "vec3DMember", ast::type::Kind::eVec3D );
				result->declMember( "vec4DMember", ast::type::Kind::eVec4D );
				result->declMember( "mat2x2FMember", ast::type::Kind::eMat2x2F );
				result->declMember( "mat2x3FMember", ast::type::Kind::eMat2x3F );
				result->declMember( "mat2x4FMember", ast::type::Kind::eMat2x4F );
				result->declMember( "mat3x2FMember", ast::type::Kind::eMat3x2F );
				result->declMember( "mat3x3FMember", ast::type::Kind::eMat3x3F );
				result->declMember( "mat3x4FMember", ast::type::Kind::eMat3x4F );
				result->declMember( "mat4x2FMember", ast::type::Kind::eMat4x2F );
				result->declMember( "mat4x3FMember", ast::type::Kind::eMat4x3F );
				result->declMember( "mat4x4FMember", ast::type::Kind::eMat4x4F );
				result->declMember( "mat2x2DMember", ast::type::Kind::eMat2x2D );
				result->declMember( "mat2x3DMember", ast::type::Kind::eMat2x3D );
				result->declMember( "mat2x4DMember", ast::type::Kind::eMat2x4D );
				result->declMember( "mat3x2DMember", ast::type::Kind::eMat3x2D );
				result->declMember( "mat3x3DMember", ast::type::Kind::eMat3x3D );
				result->declMember( "mat3x4DMember", ast::type::Kind::eMat3x4D );
				result->declMember( "mat4x2DMember", ast::type::Kind::eMat4x2D );
				result->declMember( "mat4x3DMember", ast::type::Kind::eMat4x3D );
				result->declMember( "mat4x4DMember", ast::type::Kind::eMat4x4D );
			}

			return result;
		}

		sdw::Boolean booleanMember;
		sdw::Int8 int8Member;
		sdw::Int16 int16Member;
		sdw::Int32 int32Member;
		sdw::Int64 int64Member;
		sdw::UInt8 uInt8Member;
		sdw::UInt16 uInt16Member;
		sdw::UInt32 uInt32Member;
		sdw::UInt64 uInt64Member;
		sdw::Float floatMember;
		sdw::Double doubleMember;
		sdw::BVec2 vec2BMember;
		sdw::BVec3 vec3BMember;
		sdw::BVec4 vec4BMember;
		sdw::I8Vec2 vec2I8Member;
		sdw::I8Vec3 vec3I8Member;
		sdw::I8Vec4 vec4I8Member;
		sdw::I16Vec2 vec2I16Member;
		sdw::I16Vec3 vec3I16Member;
		sdw::I16Vec4 vec4I16Member;
		sdw::I32Vec2 vec2I32Member;
		sdw::I32Vec3 vec3I32Member;
		sdw::I32Vec4 vec4I32Member;
		sdw::I64Vec2 vec2I64Member;
		sdw::I64Vec3 vec3I64Member;
		sdw::I64Vec4 vec4I64Member;
		sdw::U8Vec2 vec2U8Member;
		sdw::U8Vec3 vec3U8Member;
		sdw::U8Vec4 vec4U8Member;
		sdw::U16Vec2 vec2U16Member;
		sdw::U16Vec3 vec3U16Member;
		sdw::U16Vec4 vec4U16Member;
		sdw::U32Vec2 vec2U32Member;
		sdw::U32Vec3 vec3U32Member;
		sdw::U32Vec4 vec4U32Member;
		sdw::U64Vec2 vec2U64Member;
		sdw::U64Vec3 vec3U64Member;
		sdw::U64Vec4 vec4U64Member;
		sdw::Vec2 vec2FMember;
		sdw::Vec3 vec3FMember;
		sdw::Vec4 vec4FMember;
		sdw::DVec2 vec2DMember;
		sdw::DVec3 vec3DMember;
		sdw::DVec4 vec4DMember;
		sdw::Mat2x2 mat2x2FMember;
		sdw::Mat2x3 mat2x3FMember;
		sdw::Mat2x4 mat2x4FMember;
		sdw::Mat3x2 mat3x2FMember;
		sdw::Mat3x3 mat3x3FMember;
		sdw::Mat3x4 mat3x4FMember;
		sdw::Mat4x2 mat4x2FMember;
		sdw::Mat4x3 mat4x3FMember;
		sdw::Mat4x4 mat4x4FMember;
		sdw::DMat2x2 mat2x2DMember;
		sdw::DMat2x3 mat2x3DMember;
		sdw::DMat2x4 mat2x4DMember;
		sdw::DMat3x2 mat3x2DMember;
		sdw::DMat3x3 mat3x3DMember;
		sdw::DMat3x4 mat3x4DMember;
		sdw::DMat4x2 mat4x2DMember;
		sdw::DMat4x3 mat4x3DMember;
		sdw::DMat4x4 mat4x4DMember;

	private:
		using sdw::StructInstance::getMember;
		using sdw::StructInstance::getMemberArray;
	};

	struct TestStruct2
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , TestStruct2 );

		TestStruct2( sdw::ShaderWriter & writer, ast::expr::ExprPtr expr, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
		{
		}

		TestStruct2( sdw::ShaderWriter & writer, TestStruct const & rhs )
			: StructInstance{ writer
				, sdw::StructInstance::makeInitExpr( makeType( writer.getTypesCache() ), &rhs )
				, true }
		{
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eC
				, "TestStruct2" );

			if ( result->empty() )
			{
				result->declMember( "booleanMember", ast::type::Kind::eBoolean );
				result->declMember( "int8Member", ast::type::Kind::eInt8 );
				result->declMember( "int16Member", ast::type::Kind::eInt16 );
				result->declMember( "int32Member", ast::type::Kind::eInt32 );
				result->declMember( "int64Member", ast::type::Kind::eInt64 );
				result->declMember( "uInt8Member", ast::type::Kind::eUInt8 );
				result->declMember( "uInt16Member", ast::type::Kind::eUInt16 );
				result->declMember( "uInt32Member", ast::type::Kind::eUInt32 );
				result->declMember( "uInt64Member", ast::type::Kind::eUInt64 );
				result->declMember( "floatMember", ast::type::Kind::eFloat );
				result->declMember( "doubleMember", ast::type::Kind::eDouble );
				result->declMember( "vec2BMember", ast::type::Kind::eVec2B );
				result->declMember( "vec3BMember", ast::type::Kind::eVec3B );
				result->declMember( "vec4BMember", ast::type::Kind::eVec4B );
				result->declMember( "vec2I8Member", ast::type::Kind::eVec2I8 );
				result->declMember( "vec3I8Member", ast::type::Kind::eVec3I8 );
				result->declMember( "vec4I8Member", ast::type::Kind::eVec4I8 );
				result->declMember( "vec2I16Member", ast::type::Kind::eVec2I16 );
				result->declMember( "vec3I16Member", ast::type::Kind::eVec3I16 );
				result->declMember( "vec4I16Member", ast::type::Kind::eVec4I16 );
				result->declMember( "vec2I32Member", ast::type::Kind::eVec2I32 );
				result->declMember( "vec3I32Member", ast::type::Kind::eVec3I32 );
				result->declMember( "vec4I32Member", ast::type::Kind::eVec4I32 );
				result->declMember( "vec2I64Member", ast::type::Kind::eVec2I64 );
				result->declMember( "vec3I64Member", ast::type::Kind::eVec3I64 );
				result->declMember( "vec4I64Member", ast::type::Kind::eVec4I64 );
				result->declMember( "vec2U8Member", ast::type::Kind::eVec2U8 );
				result->declMember( "vec3U8Member", ast::type::Kind::eVec3U8 );
				result->declMember( "vec4U8Member", ast::type::Kind::eVec4U8 );
				result->declMember( "vec2U16Member", ast::type::Kind::eVec2U16 );
				result->declMember( "vec3U16Member", ast::type::Kind::eVec3U16 );
				result->declMember( "vec4U16Member", ast::type::Kind::eVec4U16 );
				result->declMember( "vec2U32Member", ast::type::Kind::eVec2U32 );
				result->declMember( "vec3U32Member", ast::type::Kind::eVec3U32 );
				result->declMember( "vec4U32Member", ast::type::Kind::eVec4U32 );
				result->declMember( "vec2U64Member", ast::type::Kind::eVec2U64 );
				result->declMember( "vec3U64Member", ast::type::Kind::eVec3U64 );
				result->declMember( "vec4U64Member", ast::type::Kind::eVec4U64 );
				result->declMember( "vec2FMember", ast::type::Kind::eVec2F );
				result->declMember( "vec3FMember", ast::type::Kind::eVec3F );
				result->declMember( "vec4FMember", ast::type::Kind::eVec4F );
				result->declMember( "vec2DMember", ast::type::Kind::eVec2D );
				result->declMember( "vec3DMember", ast::type::Kind::eVec3D );
				result->declMember( "vec4DMember", ast::type::Kind::eVec4D );
				result->declMember( "mat2x2FMember", ast::type::Kind::eMat2x2F );
				result->declMember( "mat2x3FMember", ast::type::Kind::eMat2x3F );
				result->declMember( "mat2x4FMember", ast::type::Kind::eMat2x4F );
				result->declMember( "mat3x2FMember", ast::type::Kind::eMat3x2F );
				result->declMember( "mat3x3FMember", ast::type::Kind::eMat3x3F );
				result->declMember( "mat3x4FMember", ast::type::Kind::eMat3x4F );
				result->declMember( "mat4x2FMember", ast::type::Kind::eMat4x2F );
				result->declMember( "mat4x3FMember", ast::type::Kind::eMat4x3F );
				result->declMember( "mat4x4FMember", ast::type::Kind::eMat4x4F );
				result->declMember( "mat2x2DMember", ast::type::Kind::eMat2x2D );
				result->declMember( "mat2x3DMember", ast::type::Kind::eMat2x3D );
				result->declMember( "mat2x4DMember", ast::type::Kind::eMat2x4D );
				result->declMember( "mat3x2DMember", ast::type::Kind::eMat3x2D );
				result->declMember( "mat3x3DMember", ast::type::Kind::eMat3x3D );
				result->declMember( "mat3x4DMember", ast::type::Kind::eMat3x4D );
				result->declMember( "mat4x2DMember", ast::type::Kind::eMat4x2D );
				result->declMember( "mat4x3DMember", ast::type::Kind::eMat4x3D );
				result->declMember( "mat4x4DMember", ast::type::Kind::eMat4x4D );
			}

			return result;
		}

	private:
		using sdw::StructInstance::getMember;
		using sdw::StructInstance::getMemberArray;
	};
}

namespace
{
	using TypeT = sdw::Mat2x3;
	template< sdw::var::Flag FlagT >
	using IOTestMatTypeStructT = IOTestMatStructT< TypeT, FlagT >;

	TEST_F( SDWTest, structInstanceMat2x3 )
	{

		sdwTestBegin( "structInstanceMat2x3" );
		sdw::VertexWriter writer{ &testCounts.allocator };
		auto light = writer.declGlobal< Light >( "light" );

		writer.implementMainT< sdw::VoidT, IOTestMatTypeStructT >( [&]( sdw::VertexIn in
			, sdw::VertexOutT< IOTestMatTypeStructT > out )
			{
				auto rhs = writer.declLocale( "rhs", TestMatStructT< TypeT >{ writer } );
				auto lhs1 = writer.declLocale( "lhs1", TestMatStructT < TypeT >{ writer, rhs } );
				auto iolhs1 = writer.declLocale( "iolhs1", IOTestMatStructT< sdw::Mat2x3, sdw::var::Flag::eShaderOutput >{ writer } );
				auto iolhs2 = writer.declLocale( "iolhs2", IOTestMatStructT< sdw::Mat2x3, sdw::var::Flag::eShaderOutput >{ writer, rhs } );
				auto iolhs3 = writer.declLocale( "iolhs3", IOTestMatStructT< sdw::Mat2x3, sdw::var::Flag::eShaderOutput >{ writer, light } );

				out.member = iolhs3.member;
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd();
	}

	TEST_F( SDWTest, structInstance )
	{
		sdwTestBegin( "structInstance" );
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			auto light = writer.declGlobal< Light >( "light" );
			astCheckThrow( getBoolMember( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getInt8Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getInt16Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getInt32Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIntMember( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getInt64Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUInt8Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUInt16Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUInt32Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUIntMember( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUInt64Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getFloatMember( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getVec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getVec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getVec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU8Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU8Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU8Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI8Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI8Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI8Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU16Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU16Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU16Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI16Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI16Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI16Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU32Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU32Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU32Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI32Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI32Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI32Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUVec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUVec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUVec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIVec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIVec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIVec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU64Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU64Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getU64Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI64Vec2Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI64Vec3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getI64Vec4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getMat4x3Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getMat3x4Member( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIntMemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUIntMemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getFloatMemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getVec4MemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUVec2MemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUVec3MemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getUVec4MemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIVec2MemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIVec3MemberArray( light, sdw::Builtin::eBaseInstance ) );
			astCheckThrow( getIVec4MemberArray( light, sdw::Builtin::eBaseInstance ) );

			writer.implementMainT< sdw::VoidT, IOTestStructT >( [&]( sdw::VertexIn in
				, sdw::VertexOutT< IOTestStructT > out )
				{
					auto rhs = writer.declLocale( "rhs", TestStruct{ writer } );
					auto lhs1 = writer.declLocale( "lhs1", TestStruct{ writer, rhs } );
					auto lhs2 = writer.declLocale( "lhs2", TestStruct2{ writer, rhs } );
					auto lhs3 = writer.declLocale( "lhs3", TestStruct2{ writer, light } );
					auto iolhs1 = writer.declLocale( "iolhs1", IOTestStructT< sdw::var::Flag::eShaderOutput >{ writer } );
					auto iolhs2 = writer.declLocale( "iolhs2", IOTestStructT< sdw::var::Flag::eShaderOutput >{ writer, rhs } );
					auto iolhs3 = writer.declLocale( "iolhs3", IOTestStructT< sdw::var::Flag::eShaderOutput >{ writer, light } );

					out.booleanMember = iolhs3.booleanMember;
					out.int8Member = iolhs3.int8Member;
					out.int16Member = iolhs3.int16Member;
					out.int32Member = iolhs3.int32Member;
					out.int64Member = iolhs3.int64Member;
					out.uInt8Member = iolhs3.uInt8Member;
					out.uInt16Member = iolhs3.uInt16Member;
					out.uInt32Member = iolhs3.uInt32Member;
					out.uInt64Member = iolhs3.uInt64Member;
					out.floatMember = iolhs3.floatMember;
					out.doubleMember = iolhs3.doubleMember;
					out.vec2BMember = iolhs3.vec2BMember;
					out.vec3BMember = iolhs3.vec3BMember;
					out.vec4BMember = iolhs3.vec4BMember;
					out.vec2I8Member = iolhs3.vec2I8Member;
					out.vec3I8Member = iolhs3.vec3I8Member;
					out.vec4I8Member = iolhs3.vec4I8Member;
					out.vec2I16Member = iolhs3.vec2I16Member;
					out.vec3I16Member = iolhs3.vec3I16Member;
					out.vec4I16Member = iolhs3.vec4I16Member;
					out.vec2I32Member = iolhs3.vec2I32Member;
					out.vec3I32Member = iolhs3.vec3I32Member;
					out.vec4I32Member = iolhs3.vec4I32Member;
					out.vec2I64Member = iolhs3.vec2I64Member;
					out.vec3I64Member = iolhs3.vec3I64Member;
					out.vec4I64Member = iolhs3.vec4I64Member;
					out.vec2U8Member = iolhs3.vec2U8Member;
					out.vec3U8Member = iolhs3.vec3U8Member;
					out.vec4U8Member = iolhs3.vec4U8Member;
					out.vec2U16Member = iolhs3.vec2U16Member;
					out.vec3U16Member = iolhs3.vec3U16Member;
					out.vec4U16Member = iolhs3.vec4U16Member;
					out.vec2U32Member = iolhs3.vec2U32Member;
					out.vec3U32Member = iolhs3.vec3U32Member;
					out.vec4U32Member = iolhs3.vec4U32Member;
					out.vec2U64Member = iolhs3.vec2U64Member;
					out.vec3U64Member = iolhs3.vec3U64Member;
					out.vec4U64Member = iolhs3.vec4U64Member;
					out.vec2FMember = iolhs3.vec2FMember;
					out.vec3FMember = iolhs3.vec3FMember;
					out.vec4FMember = iolhs3.vec4FMember;
					out.vec2DMember = iolhs3.vec2DMember;
					out.vec3DMember = iolhs3.vec3DMember;
					out.vec4DMember = iolhs3.vec4DMember;
					out.mat2x2FMember = iolhs3.mat2x2FMember;
					out.mat2x3FMember = iolhs3.mat2x3FMember;
					out.mat2x4FMember = iolhs3.mat2x4FMember;
					out.mat3x2FMember = iolhs3.mat3x2FMember;
					out.mat3x3FMember = iolhs3.mat3x3FMember;
					out.mat3x4FMember = iolhs3.mat3x4FMember;
					out.mat4x2FMember = iolhs3.mat4x2FMember;
					out.mat4x3FMember = iolhs3.mat4x3FMember;
					out.mat4x4FMember = iolhs3.mat4x4FMember;
					out.mat2x2DMember = iolhs3.mat2x2DMember;
					out.mat2x3DMember = iolhs3.mat2x3DMember;
					out.mat2x4DMember = iolhs3.mat2x4DMember;
					out.mat3x2DMember = iolhs3.mat3x2DMember;
					out.mat3x3DMember = iolhs3.mat3x3DMember;
					out.mat3x4DMember = iolhs3.mat3x4DMember;
					out.mat4x2DMember = iolhs3.mat4x2DMember;
					out.mat4x3DMember = iolhs3.mat4x3DMember;
					out.mat4x4DMember = iolhs3.mat4x4DMember;
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}

		sdwTestEnd();
	}

	TEST_F( SDWTest, singleLightUbo )
	{
		sdwTestBegin( "singleLightUbo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.declType< Light >();
			auto lightUbo = writer.declUniformBuffer<>( "LightUbo", 0u, 0u );
			auto light = lightUbo.declMember< Light >( "light" );
			lightUbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}
		
	TEST_F( SDWTest, lightArrayUbo )
	{
		sdwTestBegin( "lightArrayUbo" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };

		writer.declType< Light >();
		auto lightsUbo = writer.declUniformBuffer<>( "LightsUbo", 0u, 0u );
		auto lights = lightsUbo.declMember< Light >( "lights"
			, 2u );
		lightsUbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, singleLightSsbo )
	{
		sdwTestBegin( "singleLightSsbo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.declType< Light >();
			auto lightSsbo = writer.declUniformBuffer<>( "LightSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto light = lightSsbo.declMember< Light >( "light" );
			lightSsbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color * light.intensity;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, lightArraySsbo )
	{
		sdwTestBegin( "lightArraySsbo" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };

		writer.declType< Light >();
		auto lightsSsbo = writer.declUniformBuffer<>( "LightsSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
		auto lights = lightsSsbo.declMember< Light >( "lights"
			, 2u );
		lightsSsbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, arraySsboLight )
	{
		sdwTestBegin( "arraySsboLight" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto lights = writer.declArrayStorageBuffer< Light >( "LightsSsbo", 1u, 0u );

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color * lights[1].intensity;
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, singleLight2Ubo )
	{
#if SDW_EnableStructHelper

		sdwTestBegin( "singleLight2Ubo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.declType< Light2 >();
			auto lightUbo = writer.declUniformBuffer<>( "Light2Ubo", 0u, 0u );
			auto light = lightUbo.declMember< Light2 >( "light" );
			lightUbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color() * light.intensity();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()

#endif
	}
		
	TEST_F( SDWTest, light2ArrayUbo )
	{
#if SDW_EnableStructHelper

		sdwTestBegin( "light2ArrayUbo" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };

		writer.declType< Light2 >();
		auto lightsUbo = writer.declUniformBuffer<>( "Light2sUbo", 0u, 0u );
		auto lights = lightsUbo.declMember< Light2 >( "lights"
			, 2u );
		lightsUbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color() * lights[1].intensity();
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()

#endif
	}

	TEST_F( SDWTest, singleLight2Ssbo )
	{
#if SDW_EnableStructHelper

		sdwTestBegin( "singleLight2Ssbo" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.declType< Light2 >();
			auto lightSsbo = writer.declUniformBuffer<>( "Light2Ssbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto light = lightSsbo.declMember< Light2 >( "light" );
			lightSsbo.end();

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = light.color() * light.intensity();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()

#endif
	}

	TEST_F( SDWTest, light2ArraySsbo )
	{
#if SDW_EnableStructHelper

		sdwTestBegin( "light2ArraySsbo" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };

		writer.declType< Light2 >();
		auto lightsSsbo = writer.declUniformBuffer<>( "Light2sSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
		auto lights = lightsSsbo.declMember< Light2 >( "lights"
			, 2u );
		lightsSsbo.end();

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color() * lights[1].intensity();
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()

#endif
	}

	TEST_F( SDWTest, arraySsboLight2 )
	{
#if SDW_EnableStructHelper

		sdwTestBegin( "arraySsboLight2" );
		using namespace sdw;

		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto lights = writer.declArrayStorageBuffer< Light2 >( "Light2sSsbo", 1u, 0u );

		writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< ColourT > out )
			{
				out.colour = lights[0].color() * lights[1].intensity();
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()

#endif
	}

	class FlagsParam
		: public SDWTest
		, public ::testing::WithParamInterface< Flags >
	{
	};

	TEST_P( FlagsParam, singleParamUbo )
	{
		auto flags = GetParam();
		sdwTestBegin( "singleParamUbo" + getFlagsName( flags ) );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.declType< Parameterized >( flags );
			auto paramUbo = writer.declUniformBuffer<>( "ParamUbo", 0u, 0u );
			auto param = paramUbo.declMember< Parameterized >( "param", true, flags );
			paramUbo.end();

			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( param.position * param.normal, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = vec3( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_P( FlagsParam, paramArrayGlobal )
	{
		auto flags = GetParam();
		sdwTestBegin( "paramArrayGlobal" + getFlagsName( flags ) );
		using namespace sdw;

		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.declType< Parameterized >( flags );
		auto params = writer.declGlobalArray< Parameterized >( "params", 2u, true, flags );

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				out.vtx.position = vec4( params[0].position * params[0].normal, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_P( FlagsParam, paramArrayUbo )
	{
		auto flags = GetParam();
		sdwTestBegin( "paramArrayUbo" + getFlagsName( flags ) );
		using namespace sdw;

		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.declType< Parameterized >( flags );
		auto paramsUbo = writer.declUniformBuffer<>( "ParamsUbo", 0u, 0u );
		auto params = paramsUbo.declMember< Parameterized >( "params", 2u, true, flags );
		paramsUbo.end();

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				out.vtx.position = vec4( params[0].position * params[0].normal, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_P( FlagsParam, singleParamSsbo )
	{
		auto flags = GetParam();
		sdwTestBegin( "singleParamSsbo" + getFlagsName( flags ) );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.declType< Parameterized >( flags );
			auto paramSsbo = writer.declUniformBuffer<>( "ParamSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
			auto param = paramSsbo.declMember< Parameterized >( "param", true, flags );
			paramSsbo.end();

			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					out.vtx.position = vec4( param.position * param.normal, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, ColourT >( [&]( FragmentInT< VoidT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = vec3( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_P( FlagsParam, paramArraySsbo )
	{
		auto flags = GetParam();
		sdwTestBegin( "paramArraySsbo" + getFlagsName( flags ) );
		using namespace sdw;

		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.declType< Parameterized >( flags );
		auto paramsSsbo = writer.declUniformBuffer<>( "ParamsSsbo", 1u, 0u, type::MemoryLayout::eStd140 );
		auto params = paramsSsbo.declMember< Parameterized >( "params", 2u, true, flags );
		paramsSsbo.end();

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				out.vtx.position = vec4( params[0].position * params[0].normal, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_P( FlagsParam, arraySsboParam )
	{
		auto flags = GetParam();
		sdwTestBegin( "arraySsboParam" + getFlagsName( flags ) );
		using namespace sdw;

		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.declType< Parameterized >( flags );
		auto params = writer.declArrayStorageBuffer< Parameterized >( "Light2sSsbo"
			, 1u
			, 0u
			, true
			, flags );

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				out.vtx.position = vec4( params[0].position * params[0].normal, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}
	INSTANTIATE_TEST_SUITE_P( Parameterized
		, FlagsParam
		, testing::Values( Flags::Positions, Flags::Normals, Flags::Both )
		, astTestNameP( Flags, getFlagsName ) );
}

sdwTestSuiteMain()
