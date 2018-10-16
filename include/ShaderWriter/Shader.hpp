/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Shader_H___
#define ___Writer_Shader_H___
#pragma once

#include "Function.hpp"
#include "Struct.hpp"
#include "Ssbo.hpp"
#include "Ubo.hpp"
#include "Pcb.hpp"
#include "Optional.hpp"

#include <ASTGenerator/Stmt/StmtInputGeometryLayout.hpp>
#include <ASTGenerator/Stmt/StmtOutputGeometryLayout.hpp>

#include <stack>

namespace sdw
{
	struct ShaderConfig
	{
		uint32_t shaderLanguageVersion{ 430 };
		bool hasConstantsBuffers{ true };
		bool hasTextureBuffers{ true };
		bool hasShaderStorageBuffers{ true };
		bool hasPushConstants{ true };
		bool zeroToOneDepth{ true };
		bool isTopDown{ true };
		bool hasInstanceIndex{ true };
		bool hasVertexIndex{ true };
		bool hasSpecialisationConstants{ true };
	};

	struct UniformInfo
	{
		type::Kind m_type;
		uint32_t m_location;
		uint32_t m_count;
	};

	struct InputInfo
	{
		type::Kind m_type;
		uint32_t m_location;
	};

	struct OutputInfo
	{
		type::Kind m_type;
		uint32_t m_location;
	};

	struct SamplerInfo
	{
		type::Kind m_type;
		uint32_t m_binding;
		uint32_t m_set;
		uint32_t m_count;
	};

	class Shader
	{
	public:
		Shader( ShaderConfig config = ShaderConfig{} );
#pragma region Variables registration
		/**
		*name
		*	Control statements.
		*/
		/**@{*/
		void registerName( std::string const & name
			, type::Kind type );
		void checkNameExists( std::string const & name
			, type::Kind type );
		void addStmt( stmt::StmtPtr stmt );
		void registerSsbo( std::string const & name
			, Ssbo::Info const & info );
		void registerUbo( std::string const & name
			, Ubo::Info const & info );
		/**@}*/
#pragma endregion
		void inlineComment( std::string const & comment );
		void multilineComment( std::string const & comment );
		void enableExtension( std::string const & name, uint32_t inCoreVersion );
		void emitVertex();
		void endPrimitive();
		void discard();
		void inputComputeLayout( uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ );
		void inputGeometryLayout( stmt::InputLayout layout );
		void outputGeometryLayout( stmt::OutputLayout layout, uint32_t count );
		sdw::Vec2 bottomUpToTopDown( sdw::Vec2 const & texCoord );
		sdw::Vec2 topDownToBottomUp( sdw::Vec2 const & texCoord );
		sdw::Vec3 bottomUpToTopDown( sdw::Vec3 const & texCoord );
		sdw::Vec3 topDownToBottomUp( sdw::Vec3 const & texCoord );
		template< typename ReturnT, typename ... ParamsT >
		inline Function< ReturnT, ParamsT... > implementFunction( std::string const & name
				, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
				, ParamsT && ... params );
		void returnStmt();
		template< typename RetType >
		void returnStmt( RetType const & value );
		template< typename DestT >
		inline DestT cast( Value const & from );
		template< typename ValueT >
		inline ValueT paren( ValueT const & content );
#pragma region Control statements
		/**
		*name
		*	Control statements.
		*/
		/**@{*/
		template< typename ExprType >
		ExprType ternary( expr::ExprPtr condition
			, expr::ExprPtr left
			, expr::ExprPtr right );
		void forStmt( expr::ExprPtr init
			, expr::ExprPtr condition
			, expr::ExprPtr increment
			, std::function< void() > function );
		void doWhileStmt( expr::ExprPtr condition
			, std::function< void() > function );
		void whileStmt( expr::ExprPtr condition
			, std::function< void() > function );
		Shader & ifStmt( expr::ExprPtr condition
			, std::function< void() > function );
		Shader & elseIfStmt( expr::ExprPtr condition
			, std::function< void() > function );
		void elseStmt( std::function< void() > function );
		/**@}*/
#pragma endregion
#pragma region Constant declaration
		/**
		*name
		*	Constant declaration (#define name value).
		*/
		/**@{*/
		template< typename T >
		inline T declConstant( std::string const & name
			, T const & rhs );
		template< typename T >
		inline Optional< T > declConstant( std::string const & name
			, T const & rhs, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Specialisation constant declaration
		/**
		*name
		*	Specialisation constant declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declSpecConstant( std::string const & name
			, uint32_t location
			, T const & rhs );
		template< typename T >
		inline Optional< T > declSpecConstant( std::string const & name
			, uint32_t location
			, T const & rhs
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Sampler declaration
		/**
		*name
		*	Sampler declaration.
		*/
		/**@{*/
		template< SamplerType SamplerT >
		inline typename SamplerTypeTraits< SamplerT >::Type declSampler( std::string const & name
			, uint32_t binding
			, uint32_t set );
		template< SamplerType SamplerT >
		inline Optional< typename SamplerTypeTraits< SamplerT >::Type > declSampler( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled );
		template< SamplerType SamplerT >
		inline Array< typename SamplerTypeTraits< SamplerT >::Type > declSamplerArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension );
		template< SamplerType SamplerT >
		inline Optional< Array< typename SamplerTypeTraits< SamplerT >::Type > > declSamplerArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Input declaration
		/**
		*name
		*	Input declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declInput( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< T > declInput( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< Array< T > > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declInputArray( std::string const & name
			, uint32_t location
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Output declaration
		/**
		*name
		*	Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declOutput( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Array< T > declOutputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declOutputArray( std::string const & name
			, uint32_t location );
		template< typename T >
		inline Optional< T > declOutput( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declOutputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declOutputArray( std::string const & name
			, uint32_t location
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Locale declaration
		/**
		*name
		*	Locale variable declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declLocale( std::string const & name );
		template< typename T >
		inline T declLocale( std::string const & name
			, T const & rhs );
		template< typename T >
		inline Optional< T > declLocale( std::string const & name
			, bool enabled );
		template< typename T >
		inline Optional< T > declLocale( std::string const & name
			, Optional< T > const & rhs );
		template< typename T >
		inline Optional< T > declLocale( std::string const & name
			, T const & rhs
			, bool enabled );
		template< typename T >
		inline Array< T > declLocaleArray( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declLocaleArray( std::string const & name
			, uint32_t dimension
			, std::vector< T > const & rhs );
		template< typename T >
		inline Optional< Array< T > > declLocaleArray( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declLocaleArray( std::string const & name
			, uint32_t dimension
			, std::vector< T > const & rhs
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Built-in declaration
		/**
		*name
		*	Built-in variable declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declBuiltin( std::string const & name );
		template< typename T >
		inline Optional< T > declBuiltin( std::string const & name
			, bool enabled );
		template< typename T >
		inline Array< T > declBuiltinArray( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declBuiltinArray( std::string const & name );
		template< typename T >
		inline Optional< Array< T > > declBuiltinArray( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declBuiltinArray( std::string const & name
			, bool enabled );

		template< typename T >
		inline T getBuiltin( std::string const & name );
		template< typename T >
		inline Optional< T > getBuiltin( std::string const & name
			, bool enabled );
		template< typename T >
		inline Array< T > getBuiltinArray( std::string const & name );
		template< typename T >
		inline Optional< Array< T > > getBuiltinArray( std::string const & name
			, bool enabled );
		template< typename T >
		inline Array< T > getBuiltinArray( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Optional< Array< T > > getBuiltinArray( std::string const & name
			, uint32_t dimension
			, bool enabled );
		/**@}*/
#pragma endregion

		inline uint32_t getShaderLanguageVersion()const
		{
			return m_config.shaderLanguageVersion;
		}

		inline bool hasConstantsBuffers()const
		{
			return m_config.hasConstantsBuffers;
		}

		inline bool hasTextureBuffers()const
		{
			return m_config.hasTextureBuffers;
		}

		inline bool hasShaderStorageBuffers()const
		{
			return m_config.hasShaderStorageBuffers;
		}

		inline bool hasPushConstants()const
		{
			return m_config.hasPushConstants;
		}

		inline bool isZeroToOneDepth()const
		{
			return m_config.zeroToOneDepth;
		}

		inline bool isTopDown()const
		{
			return m_config.isTopDown;
		}

		inline Ssbo::Info const & getSsboInfo( std::string const & name )const
		{
			return m_ssbos.at( name );
		}

		inline Ubo::Info const & getUboInfo( std::string const & name )const
		{
			return m_ubos.at( name );
		}

		inline type::Kind getInput( std::string const & name )const
		{
			return m_inputs.at( name ).m_type;
		}

		inline type::Kind getOutput( std::string const & name )const
		{
			return m_outputs.at( name ).m_type;
		}

		inline std::map< std::string, Ubo::Info > const & getUbos()const
		{
			return m_ubos;
		}

		inline std::map< std::string, Ssbo::Info > const & getSsbos()const
		{
			return m_ssbos;
		}

		inline std::map< std::string, InputInfo > const & getInputs()const
		{
			return m_inputs;
		}

		inline std::map< std::string, OutputInfo > const & getOutputs()const
		{
			return m_outputs;
		}

		inline stmt::Container * getStatements()
		{
			return &m_container;
		}

		inline stmt::Container * getContainer()
		{
			return m_blocks.top().container;
		}

	private:
		void declareInvertVec2Y();
		void declareInvertVec3Y();
		void registerConstant( std::string const & name
			, type::Kind type );
		void registerSampler( std::string const & name
			, type::Kind type
			, uint32_t binding
			, uint32_t set
			, uint32_t count
			, bool enabled = true );
		void registerInput( std::string const & name
			, uint32_t location
			, type::Kind type );
		void registerOutput( std::string const & name
			, uint32_t location
			, type::Kind type );

	private:
		struct Block
		{
			std::map< std::string, type::Kind > registered;
			stmt::Container * container;
		};
		ShaderConfig m_config;
		std::stack< Block > m_blocks;
		stmt::Container m_container;
		std::map< std::string, Ssbo::Info > m_ssbos;
		std::map< std::string, Ubo::Info > m_ubos;
		std::map< std::string, type::Kind > m_constants;
		std::map< std::string, SamplerInfo > m_samplers;
		std::map< std::string, InputInfo > m_inputs;
		std::map< std::string, OutputInfo > m_outputs;
		Function< Vec2, InVec2 > m_invertVec2Y;
		Function< Vec3, InVec3 > m_invertVec3Y;
	};
}

#define FOR( Shader, Type, Name, Init, Cond, Incr )\
	{\
		Type Name{ &( Shader )\
			, sdw::makeExpr( sdw::var::makeVariable( sdw::type::makeType( sdw::typeEnum<Type> ), #Name ) ) };\
		Type incr##Name{ &( Shader ), sdw::makeExpr( Incr ) };\
		Name.updateExpr( sdw::makeExpr( sdw::var::makeVariable( sdw::type::makeType( sdw::typeEnum<Type> ), #Name ) ) );\
		Type cond##Name{ &( Shader ), sdw::makeExpr( Cond ) };\
		( Shader ).forStmt( sdw::makeInit( sdw::typeEnum<Type>\
				, #Name\
				, sdw::makeExpr( Init ) )\
			, sdw::makeExpr( cond##Name )\
			, sdw::makeExpr( incr##Name )\
			, [&]()

#define ROF\
 );\
	}

#define WHILE( Shader, Condition )\
	( Shader ).whileStmt( sdw::makeExpr( Condition )\
		, [&]()

#define ELIHW\
 );

#define DOWHILE( Shader, Condition )\
	( Shader ).doWhileStmt( sdw::makeExpr( Condition )\
		, [&]()

#define ELIHWOD\
 );

#define IF( Shader, Condition )\
	( Shader ).ifStmt( sdw::makeExpr( Condition )\
		, [&]()

#define ELSE\
 ).elseStmt( [&]()

#define ELSEIF( Condition )\
 ).elseIfStmt( sdw::makeExpr( Condition )\
		, [&]()

#define FI\
 );

#define TERNARY( Shader, ExprType, Condition, Left, Right )\
	( Shader ).ternary< ExprType >( Condition, Left, Right )

#include "Shader.inl"

#endif
