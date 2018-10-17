/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Writer_H___
#define ___Writer_Writer_H___

#include "Shader.hpp"

namespace sdw
{
	struct Config
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

	class ShaderWriter
	{
	public:
		ShaderWriter( bool writeInvertFuncs = true
			, Config config = Config{} );
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
		ShaderWriter & ifStmt( expr::ExprPtr condition
			, std::function< void() > function );
		ShaderWriter & elseIfStmt( expr::ExprPtr condition
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

		inline Shader const & getShader()const
		{
			return m_shader;
		}

		inline Shader & getShader()
		{
			return m_shader;
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
		Config m_config;
		Shader m_shader;
		Function< Vec2, InVec2 > m_invertVec2Y;
		Function< Vec3, InVec3 > m_invertVec3Y;
	};
}

#define FOR( Writer, Type, Name, Init, Cond, Incr )\
	{\
		Type Name{ &( Writer ).getShader()\
			, sdw::makeExpr( sdw::var::makeVariable( sdw::type::makeType( sdw::typeEnum<Type> ), #Name ) ) };\
		Type incr##Name{ &( Writer ).getShader(), sdw::makeExpr( Incr ) };\
		Name.updateExpr( sdw::makeExpr( sdw::var::makeVariable( sdw::type::makeType( sdw::typeEnum<Type> ), #Name ) ) );\
		Type cond##Name{ &( Writer ).getShader(), sdw::makeExpr( Cond ) };\
		( Writer ).forStmt( sdw::makeInit( sdw::typeEnum<Type>\
				, #Name\
				, sdw::makeExpr( Init ) )\
			, sdw::makeExpr( cond##Name )\
			, sdw::makeExpr( incr##Name )\
			, [&]()

#define ROF\
 );\
	}

#define WHILE( Writer, Condition )\
	( Writer ).whileStmt( sdw::makeExpr( Condition )\
		, [&]()

#define ELIHW\
 );

#define DOWHILE( Writer, Condition )\
	( Writer ).doWhileStmt( sdw::makeExpr( Condition )\
		, [&]()

#define ELIHWOD\
 );

#define IF( Writer, Condition )\
	( Writer ).ifStmt( sdw::makeExpr( Condition )\
		, [&]()

#define ELSE\
 ).elseStmt( [&]()

#define ELSEIF( Condition )\
 ).elseIfStmt( sdw::makeExpr( Condition )\
		, [&]()

#define FI\
 );

#define TERNARY( Writer, ExprType, Condition, Left, Right )\
	( Writer ).ternary< ExprType >( Condition, Left, Right )

#include "Writer.inl"

#endif
