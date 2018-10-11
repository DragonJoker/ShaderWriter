/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Writer_H___
#define ___Writer_Writer_H___

#include "Function.hpp"
#include "IndentBlock.hpp"
#include "InputLayout.hpp"
#include "OutputLayout.hpp"
#include "Shader.hpp"
#include "Struct.hpp"

#include <Design/OwnedBy.hpp>

#include <map>
#include <locale>

namespace sdw
{
	class GlslWriter
	{
		friend struct IndentBlock;
		friend class Pcb;
		friend class Ubo;
		friend class Ssbo;

	public:
		GlslWriter();
		void registerName( std::string const & name, type::Kind type );
		void checkNameExists( std::string const & name, type::Kind type );
		void inlineComment( std::string const & comment );
		void multilineComment( std::string const & comment );
		void enableExtension( std::string const & name, uint32_t inCoreVersion );
		std::string getInstanceID();
		std::string getVertexID();
		sdw::Vec2 ashesBottomUpToTopDown( sdw::Vec2 const & texCoord );
		sdw::Vec2 ashesTopDownToBottomUp( sdw::Vec2 const & texCoord );
		sdw::Vec3 ashesBottomUpToTopDown( sdw::Vec3 const & texCoord );
		sdw::Vec3 ashesTopDownToBottomUp( sdw::Vec3 const & texCoord );

		Shader finalise();
		void writeAssign( Type const & p_lhs, Type const & rhs );
		void writeAssign( Type const & p_lhs, int const & rhs );
		void writeAssign( Type const & p_lhs, unsigned int const & rhs );
		void writeAssign( Type const & p_lhs, float const & rhs );
		void forStmt( Type && p_init, Expr const & p_cond, Expr const & p_incr, std::function< void() > p_function );
		void whileStmt( Expr const & p_cond, std::function< void() > p_function );
		GlslWriter & ifStmt( Expr const & p_cond, std::function< void() > p_function );
		GlslWriter & elseIfStmt( Expr const & p_cond, std::function< void() > p_function );
		void elseStmt( std::function< void() > p_function );
		Struct getStruct( std::string const & name );
		void emitVertex();
		void endPrimitive();
		void discard();
		void inputGeometryLayout( std::string const & p_layout );
		void outputGeometryLayout( std::string const & p_layout );
		void outputGeometryLayout( std::string const & p_layout, uint32_t p_count );
		void outputVertexCount( uint32_t p_count );
		void returnStmt();
		/**
		*name
		*	Texture sampling / fetching.
		*/
		/**@{*/
		Vec4 texture( Sampler1D const & p_sampler, Float const & p_value );
		Vec4 texture( Sampler1D const & p_sampler, Float const & p_value, Float const & p_lod );
		Vec4 texture( Sampler2D const & p_sampler, Vec2 const & p_value );
		Vec4 texture( Sampler2D const & p_sampler, Vec2 const & p_value, Float const & p_lod );
		Vec4 texture( Sampler3D const & p_sampler, Vec3 const & p_value );
		Vec4 texture( Sampler3D const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Vec4 texture( SamplerCube const & p_sampler, Vec3 const & p_value );
		Vec4 texture( SamplerCube const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Vec4 textureOffset( Sampler1D const & p_sampler, Float const & p_value, Int const & p_offset );
		Vec4 textureOffset( Sampler1D const & p_sampler, Float const & p_value, Int const & p_offset, Float const & p_lod );
		Vec4 textureOffset( Sampler2D const & p_sampler, Vec2 const & p_value, IVec2 const & p_offset );
		Vec4 textureOffset( Sampler2D const & p_sampler, Vec2 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Vec4 textureOffset( Sampler3D const & p_sampler, Vec3 const & p_value, IVec3 const & p_offset );
		Vec4 textureOffset( Sampler3D const & p_sampler, Vec3 const & p_value, IVec3 const & p_offset, Float const & p_lod );
		Vec4 textureLodOffset( Sampler1D const & p_sampler, Float const & p_value, Float const & p_lod, Int const & p_offset );
		Vec4 textureLodOffset( Sampler2D const & p_sampler, Vec2 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		Vec4 textureLodOffset( Sampler3D const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec3 const & p_offset );
		Vec4 texelFetch( SamplerBuffer const & p_sampler, Type const & p_value );
		Vec4 texelFetch( Sampler1D const & p_sampler, Type const & p_value, Int const & p_modif );
		Vec4 texelFetch( Sampler2D const & p_sampler, Type const & p_value, Int const & p_modif );
		Vec4 texelFetch( Sampler3D const & p_sampler, Type const & p_value, Int const & p_modif );
		Vec4 texture( Sampler1DArray const & p_sampler, Vec2 const & p_value );
		Vec4 texture( Sampler1DArray const & p_sampler, Vec2 const & p_value, Float const & p_lod );
		Vec4 texture( Sampler2DArray const & p_sampler, Vec3 const & p_value );
		Vec4 texture( Sampler2DArray const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Vec4 texture( SamplerCubeArray const & p_sampler, Vec4 const & p_value );
		Vec4 texture( SamplerCubeArray const & p_sampler, Vec4 const & p_value, Float const & p_lod );
		Vec4 textureOffset( Sampler1DArray const & p_sampler, Vec2 const & p_value, Int const & p_offset );
		Vec4 textureOffset( Sampler1DArray const & p_sampler, Vec2 const & p_value, Int const & p_offset, Float const & p_lod );
		Vec4 textureOffset( Sampler2DArray const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset );
		Vec4 textureOffset( Sampler2DArray const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Vec4 textureLodOffset( Sampler1DArray const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const & p_offset );
		Vec4 textureLodOffset( Sampler2DArray const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		Float texture( Sampler1DShadow const & p_sampler, Vec2 const & p_value );
		Float texture( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Float const & p_lod );
		Float texture( Sampler2DShadow const & p_sampler, Vec3 const & p_value );
		Float texture( Sampler2DShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Float texture( SamplerCubeShadow const & p_sampler, Vec4 const & p_value );
		Float texture( SamplerCubeShadow const & p_sampler, Vec4 const & p_value, Float const & p_lod );
		Float textureOffset( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Int const & p_offset );
		Float textureOffset( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Int const & p_offset, Float const & p_lod );
		Float textureOffset( Sampler2DShadow const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset );
		Float textureOffset( Sampler2DShadow const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Float textureLodOffset( Sampler1DShadow const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const & p_offset );
		Float textureLodOffset( Sampler2DShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		Float texture( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value );
		Float texture( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Float texture( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value );
		Float texture( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_lod );
		Float texture( SamplerCubeArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_layer );
		Float texture( SamplerCubeArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_layer, Float const & p_lod );
		Float textureOffset( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Int const & p_offset );
		Float textureOffset( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Int const & p_offset, Float const & p_lod );
		Float textureOffset( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, IVec2 const & p_offset );
		Float textureOffset( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Float textureLodOffset( Sampler1DArrayShadow const & p_sampler, Vec3 const & p_value, Float const & p_lod, Int const & p_offset );
		Float textureLodOffset( Sampler2DArrayShadow const & p_sampler, Vec4 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		Optional< Vec4 > texture( Optional< Sampler1D > const & p_sampler, Float const & p_value );
		Optional< Vec4 > texture( Optional< Sampler1D > const & p_sampler, Float const & p_value, Float const & p_lod );
		Optional< Vec4 > texture( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value );
		Optional< Vec4 > texture( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, Float const & p_lod );
		Optional< Vec4 > texture( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value );
		Optional< Vec4 > texture( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Optional< Vec4 > texture( Optional< SamplerCube > const & p_sampler, Vec3 const & p_value );
		Optional< Vec4 > texture( Optional< SamplerCube > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Optional< Vec4 > textureOffset( Optional< Sampler1D > const & p_sampler, Float const & p_value, Int const & p_offset );
		Optional< Vec4 > textureOffset( Optional< Sampler1D > const & p_sampler, Float const & p_value, Int const & p_offset, Float const & p_lod );
		Optional< Vec4 > textureOffset( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, IVec2 const & p_offset );
		Optional< Vec4 > textureOffset( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Optional< Vec4 > textureOffset( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, IVec3 const & p_offset );
		Optional< Vec4 > textureOffset( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, IVec3 const & p_offset, Float const & p_lod );
		Optional< Vec4 > textureLodOffset( Optional< Sampler1D > const & p_sampler, Float const & p_value, Float const & p_lod, Int const & p_offset );
		Optional< Vec4 > textureLodOffset( Optional< Sampler2D > const & p_sampler, Vec2 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		Optional< Vec4 > textureLodOffset( Optional< Sampler3D > const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec3 const & p_offset );
		Optional< Vec4 > texelFetch( Optional< SamplerBuffer > const & p_sampler, Type const & p_value );
		Optional< Vec4 > texelFetch( Optional< Sampler1D > const & p_sampler, Type const & p_value, Int const & p_modif );
		Optional< Vec4 > texelFetch( Optional< Sampler2D > const & p_sampler, Type const & p_value, Int const & p_modif );
		Optional< Vec4 > texelFetch( Optional< Sampler3D > const & p_sampler, Type const & p_value, Int const & p_modif );
		Optional< Vec4 > texture( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value );
		Optional< Vec4 > texture( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Float const & p_lod );
		Optional< Vec4 > texture( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value );
		Optional< Vec4 > texture( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Optional< Vec4 > texture( Optional< SamplerCubeArray > const & p_sampler, Vec4 const & p_value );
		Optional< Vec4 > texture( Optional< SamplerCubeArray > const & p_sampler, Vec4 const & p_value, Float const & p_lod );
		Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Int const & p_offset );
		Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Int const & p_offset, Float const & p_lod );
		Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset );
		Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Optional< Vec4 > textureLodOffset( Optional< Sampler1DArray > const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const & p_offset );
		Optional< Vec4 > textureLodOffset( Optional< Sampler2DArray > const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		Optional< Float > texture( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value );
		Optional< Float > texture( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Float const & p_lod );
		Optional< Float > texture( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value );
		Optional< Float > texture( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Optional< Float > texture( Optional< SamplerCubeShadow > const & p_sampler, Vec4 const & p_value );
		Optional< Float > texture( Optional< SamplerCubeShadow > const & p_sampler, Vec4 const & p_value, Float const & p_lod );
		Optional< Float > textureOffset( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Int const & p_offset );
		Optional< Float > textureOffset( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Int const & p_offset, Float const & p_lod );
		Optional< Float > textureOffset( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset );
		Optional< Float > textureOffset( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Optional< Float > textureLodOffset( Optional< Sampler1DShadow > const & p_sampler, Vec2 const & p_value, Float const & p_lod, Int const & p_offset );
		Optional< Float > textureLodOffset( Optional< Sampler2DShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		Optional< Float > texture( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value );
		Optional< Float > texture( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod );
		Optional< Float > texture( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value );
		Optional< Float > texture( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_lod );
		Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_layer );
		Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_layer, Float const & p_lod );
		Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Int const & p_offset );
		Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Int const & p_offset, Float const & p_lod );
		Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, IVec2 const & p_offset );
		Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, IVec2 const & p_offset, Float const & p_lod );
		Optional< Float > textureLodOffset( Optional< Sampler1DArrayShadow > const & p_sampler, Vec3 const & p_value, Float const & p_lod, Int const & p_offset );
		Optional< Float > textureLodOffset( Optional< Sampler2DArrayShadow > const & p_sampler, Vec4 const & p_value, Float const & p_lod, IVec2 const & p_offset );
		/**@}*/
		template< typename T > void writeAssign( Type const & p_lhs, Optional< T > const & rhs );
		template< typename RetType
			, typename ... Params >
		inline Function< RetType, Params... > implementFunction( std::string const & name
			, std::function< void( typename ParamTranslater< Params >::Type... ) > const & function
			, Params && ... params );
		template< typename RetType > void returnStmt( RetType const & p_return );
		template< typename ExprType > ExprType paren( ExprType const p_expr );
		template< typename ExprType > ExprType ternary( Type const & p_condition, ExprType const & p_left, ExprType const & p_right );
		template< typename T > inline T cast( Type const & p_from );
		/**
		*name
		*	Constant declaration (#define name value).
		*/
		/**@{*/
		template< typename T > inline T declConstant( std::string const & name, T const & rhs );
		template< typename T > inline Optional< T > declConstant( std::string const & name, T const & rhs, bool enabled );
		/**
		*name
		*	Specialisation constant declaration.
		*/
		/**@{*/
		template< typename T > inline T declSpecConstant( std::string const & name, uint32_t location, T const & rhs );
		template< typename T > inline Optional< T > declSpecConstant( std::string const & name, uint32_t location, T const & rhs, bool enabled );
		/**@}*/
		/**
		*name
		*	Sampler declaration.
		*/
		/**@{*/
		template< typename T > inline T declSampler( std::string const & name, uint32_t binding );
		template< typename T > inline T declSampler( std::string const & name, uint32_t binding, uint32_t set );
		template< typename T > inline Optional< T > declSampler( std::string const & name, uint32_t binding, bool enabled );
		template< typename T > inline Optional< T > declSampler( std::string const & name, uint32_t binding, uint32_t set, bool enabled );
		template< typename T > inline Array< T > declSamplerArray( std::string const & name, uint32_t binding, uint32_t dimension );
		template< typename T > inline Array< T > declSamplerArray( std::string const & name, uint32_t binding, uint32_t set, uint32_t dimension );
		template< typename T > inline Optional< Array< T > > declSamplerArray( std::string const & name, uint32_t binding, uint32_t dimension, bool enabled );
		template< typename T > inline Optional< Array< T > > declSamplerArray( std::string const & name, uint32_t binding, uint32_t set, uint32_t dimension, bool enabled );
		/**@}*/
		/**
		*name
		*	Uniform declaration.
		*/
		/**@{*/
		template< typename T > inline T declUniform( std::string const & name, uint32_t location );
		template< typename T > inline T declUniform( std::string const & name, uint32_t location, T const & rhs );
		template< typename T > inline Optional< T > declUniform( std::string const & name, uint32_t location, bool enabled );
		template< typename T > inline Optional< T > declUniform( std::string const & name, uint32_t location, bool enabled, T const & rhs );
		template< typename T > inline Array< T > declUniformArray( std::string const & name, uint32_t location, uint32_t dimension );
		template< typename T > inline Array< T > declUniformArray( std::string const & name, uint32_t location );
		template< typename T > inline Array< T > declUniformArray( std::string const & name, uint32_t location, uint32_t dimension, std::vector< T > const & rhs );
		template< typename T > inline Optional< Array< T > > declUniformArray( std::string const & name, uint32_t location, uint32_t dimension, bool enabled );
		template< typename T > inline Optional< Array< T > > declUniformArray( std::string const & name, uint32_t location, bool enabled );
		template< typename T > inline Optional< Array< T > > declUniformArray( std::string const & name, uint32_t location, uint32_t dimension, bool enabled, std::vector< T > const & rhs );
		/**@}*/
		/**
		*name
		*	Input declaration.
		*/
		/**@{*/
		template< typename T > inline T declAttribute( std::string const & name, uint32_t location );
		template< typename T > inline Optional< T > declAttribute( std::string const & name, uint32_t location, bool enabled );
		template< typename T > inline Array< T > declAttributeArray( std::string const & name, uint32_t location, uint32_t dimension );
		template< typename T > inline Optional< Array< T > > declAttributeArray( std::string const & name, uint32_t location, uint32_t dimension, bool enabled );

		template< typename T > inline T declInput( std::string const & name, uint32_t location );
		template< typename T > inline Optional< T > declInput( std::string const & name, uint32_t location, bool enabled );
		template< typename T > inline Array< T > declInputArray( std::string const & name, uint32_t location, uint32_t dimension );
		template< typename T > inline Array< T > declInputArray( std::string const & name, uint32_t location );
		template< typename T > inline Optional< Array< T > > declInputArray( std::string const & name, uint32_t location, uint32_t dimension, bool enabled );
		template< typename T > inline Optional< Array< T > > declInputArray( std::string const & name, uint32_t location, bool enabled );
		/**@}*/
		/**
		*name
		*	Output declaration.
		*/
		/**@{*/
		template< typename T > inline T declFragData( std::string const & name, uint32_t location );
		template< typename T > inline T declOutput( std::string const & name, uint32_t location );
		template< typename T > inline Array< T > declOutputArray( std::string const & name, uint32_t location, uint32_t dimension );
		template< typename T > inline Array< T > declOutputArray( std::string const & name, uint32_t location );
		template< typename T > inline Optional< T > declOutput( std::string const & name, uint32_t location, bool enabled );
		template< typename T > inline Optional< Array< T > > declOutputArray( std::string const & name, uint32_t location, uint32_t dimension, bool enabled );
		template< typename T > inline Optional< Array< T > > declOutputArray( std::string const & name, uint32_t location, bool enabled );
		/**@}*/
		/**
		*name
		*	Locale variable declaration.
		*/
		/**@{*/
		template< typename T > inline T declLocale( std::string const & name );
		template< typename T > inline T declLocale( std::string const & name, T const & rhs );
		template< typename T > inline Optional< T > declLocale( std::string const & name, bool enabled );
		template< typename T > inline Optional< T > declLocale( std::string const & name, Optional< T > const & rhs );
		template< typename T > inline Optional< T > declLocale( std::string const & name, bool enabled, T const & rhs );
		template< typename T > inline Array< T > declLocaleArray( std::string const & name, uint32_t dimension );
		template< typename T > inline Array< T > declLocaleArray( std::string const & name, uint32_t dimension, std::vector< T > const & rhs );
		template< typename T > inline Optional< Array< T > > declLocaleArray( std::string const & name, uint32_t dimension, bool enabled );
		template< typename T > inline Optional< Array< T > > declLocaleArray( std::string const & name, uint32_t dimension, bool enabled, std::vector< T > const & rhs );
		/**@}*/
		/**
		*name
		*	Built-in variable declaration.
		*/
		/**@{*/
		template< typename T > inline T declBuiltin( std::string const & name );
		template< typename T > inline Optional< T > declBuiltin( std::string const & name, bool enabled );
		template< typename T > inline Array< T > declBuiltinArray( std::string const & name, uint32_t dimension );
		template< typename T > inline Array< T > declBuiltinArray( std::string const & name );
		template< typename T > inline Optional< Array< T > > declBuiltinArray( std::string const & name, uint32_t dimension, bool enabled );
		template< typename T > inline Optional< Array< T > > declBuiltinArray( std::string const & name, bool enabled );

		template< typename T > inline T getBuiltin( std::string const & name );
		template< typename T > inline Optional< T > getBuiltin( std::string const & name, bool enabled );
		template< typename T > inline Array< T > getBuiltinArray( std::string const & name );
		template< typename T > inline Optional< Array< T > > getBuiltinArray( std::string const & name, bool enabled );
		template< typename T > inline Array< T > getBuiltinArray( std::string const & name, uint32_t dimension );
		template< typename T > inline Optional< Array< T > > getBuiltinArray( std::string const & name, uint32_t dimension, bool enabled );
		/**@}*/
		/**
		*name
		*	Stream operators.
		*/
		/**@{*/
		GlslWriter & operator<<( Version const & rhs );
		GlslWriter & operator<<( Attribute const & rhs );
		GlslWriter & operator<<( In const & rhs );
		GlslWriter & operator<<( Out const & rhs );
		GlslWriter & operator<<( Layout const & rhs );
		GlslWriter & operator<<( Uniform const & rhs );
		GlslWriter & operator<<( InputLayout const & rhs );
		GlslWriter & operator<<( OutputLayout const & rhs );

		GlslWriter & operator<<( Endl const & rhs );
		GlslWriter & operator<<( Endi const & rhs );
		GlslWriter & operator<<( std::string const & rhs );
		GlslWriter & operator<<( uint32_t const & rhs );
		/**@}*/

	private:
		std::map< std::string, type::Kind > m_registered;
		GlslWriterConfig m_config;
		std::string m_uniform;
		std::unique_ptr< KeywordsBase > m_keywords;
		castor::StringStream m_stream;
		uint32_t m_attributeIndex{ 0u };
		uint32_t m_layoutIndex{ 0u };
		Shader m_container;
	};

#define FOR( Writer, Type, Name, Init, Cond, Incr )\
	{\
		Type Name( &Writer, cuT( #Name ) );\
		Name.m_value << Type().m_type << cuT( #Name ) << cuT( " = " ) << cuT( #Init );\
		( Writer ).forStmt( std::move( Name ), sdw::Expr( &( Writer ), std::string( Cond ) ), sdw::Expr( &( Writer ), std::string( Incr ) ), [&]()

#define ROF\
	 );\
	}

#define WHILE( Writer, Cond )\
	{\
		( Writer ).whileStmt( sdw::Expr( &( Writer ), std::string( Cond ) ), [&]()

#define ELIHW\
	 );\
	}

#define IF( Writer, Condition )\
	( Writer ).ifStmt( sdw::Expr( &( Writer ), std::string( Condition ) ), [&]()

#define ELSE\
 ).elseStmt( [&]()

#define ELSEIF( Writer, Condition )\
 ).elseIfStmt( sdw::Expr( &( Writer ), std::string( Condition ) ), [&]()

#define FI\
 );
}

#define TERNARY( Writer, ExprType, Condition, Left, Right )\
	Writer.ternary< ExprType >( Condition, Left, Right )

#include "Writer.inl"

#endif
