/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Writer_H___
#define ___SDW_Writer_H___

#include "ShaderWriter/CompositeTypes/ArraySsbo.hpp"
#include "ShaderWriter/CompositeTypes/Builtins.hpp"
#include "ShaderWriter/CompositeTypes/Function.hpp"
#include "ShaderWriter/CompositeTypes/Pcb.hpp"
#include "ShaderWriter/CompositeTypes/Ssbo.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/Ubo.hpp"

#include <ShaderAST/Shader.hpp>
#include <ShaderAST/Stmt/StmtIf.hpp>
#include <ShaderAST/Stmt/StmtSwitch.hpp>

#include <functional>

#pragma GCC diagnostic ignored "-Wshadow"

namespace sdw
{
	class ShaderWriter
	{
	protected:
		SDW_API ShaderWriter( ast::ShaderStage type );
		SDW_API virtual ~ShaderWriter();

	public:
#pragma region Type registration
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		template< typename TypeT >
		inline type::StructPtr declType();
		/**@}*/
#pragma endregion
#pragma region Variables registration
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		SDW_API bool hasVariable( std::string const & name )const;
		SDW_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		SDW_API var::VariablePtr registerLocale( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerLoopVar( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInOutParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr getVar( std::string const & name );
		SDW_API void addStmt( stmt::StmtPtr stmt );
		SDW_API void addFuncStmt( stmt::StmtPtr stmt );
		SDW_API void registerSsbo( std::string const & name
			, SsboInfo const & info );
		SDW_API void registerUbo( std::string const & name
			, UboInfo const & info );
		/**@}*/
#pragma endregion
#pragma region Comments
		/**
		*name
		*	Comments
		*/
		/**@{*/
		SDW_API void inlineComment( std::string const & comment );
		SDW_API void multilineComment( std::string const & comment );
		/**@}*/
#pragma endregion
#pragma region Functions
		/**
		*name
		*	Functions
		*/
		/**@{*/
		template< typename ReturnT, typename ... ParamsT >
		inline Function< ReturnT, ParamsT... > implementFunction( std::string const & name
			, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
			, ParamsT && ... params );
		template< typename ReturnT, typename ... ParamsT >
		inline Function< ReturnT, ParamsT... > implementFunction( std::string const & name
			, ast::stmt::FunctionFlag flag
			, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
			, ParamsT && ... params );
		inline void implementMain( std::function< void() > const & function );
		/**@}*/
#pragma endregion
#pragma region Cast
		/**
		*name
		*	Cast.
		*/
		/**@{*/
		template< typename DestT >
		inline DestT cast( int32_t from );
		template< typename DestT >
		inline DestT cast( uint32_t from );
		template< typename DestT >
		inline DestT cast( float from );
		template< typename DestT >
		inline DestT cast( double from );
		template< typename DestT, typename SourceT >
		inline DestT cast( SourceT const & from );
		/**@}*/
#pragma endregion
#pragma region Control statements
		/**
		*name
		*	Control statements.
		*/
		/**@{*/
		SDW_API void discard();
		SDW_API void returnStmt();
		template< typename RetType >
		void returnStmt( RetType const & value );
		SDW_API void pushScope();
		SDW_API void popScope();
		SDW_API void saveNextExpr();
		SDW_API ast::expr::ExprPtr loadExpr( Value const & value );
		template< typename ExprType >
		ExprType ternary( expr::ExprPtr condition
			, expr::ExprPtr left
			, expr::ExprPtr right );
		template< typename ExprType >
		ExprType ternary( Boolean condition
			, ExprType left
			, ExprType right );
		SDW_API void forStmt( expr::ExprPtr init
			, expr::ExprPtr condition
			, expr::ExprPtr increment
			, std::function< void() > function );
		SDW_API void doWhileStmt( expr::ExprPtr condition
			, std::function< void() > function );
		SDW_API void whileStmt( expr::ExprPtr condition
			, std::function< void() > function );
		SDW_API ShaderWriter & ifStmt( expr::ExprPtr condition
			, std::function< void() > function );
		SDW_API ShaderWriter & elseIfStmt( expr::ExprPtr condition
			, std::function< void() > function );
		SDW_API ShaderWriter & elseStmt( std::function< void() > function );
		SDW_API void endIf();
		SDW_API ShaderWriter & switchStmt( expr::ExprPtr value
			, std::function< void() > function );
		SDW_API void endSwitch();
		SDW_API void caseStmt( expr::LiteralPtr literal
			, std::function< void() > function );
		SDW_API void caseBreakStmt();
		SDW_API void loopBreakStmt();
		SDW_API void loopContinueStmt();
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
			, T const & rhs
			, bool enabled = true );
		template< typename T >
		inline Array< T > declConstantArray( std::string const & name
			, std::vector< T > const & rhs
			, bool enabled = true );
		template< ast::type::Kind KindT >
		inline IntegerValue< KindT > declConstant( std::string const & name
			, ReturnWrapperT< IntegerValue< KindT > > rhs
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Specialisation constant declaration
		/**
		*name
		*	Specialisation constant declaration.
		*/
		/**@{*/
		SDW_API Boolean declSpecConstant( std::string const & name
			, uint32_t location
			, bool rhs
			, bool enabled = true );
		SDW_API Int declSpecConstant( std::string const & name
			, uint32_t location
			, int32_t rhs
			, bool enabled = true );
		SDW_API UInt declSpecConstant( std::string const & name
			, uint32_t location
			, uint32_t rhs
			, bool enabled = true );
		SDW_API Float declSpecConstant( std::string const & name
			, uint32_t location
			, float rhs
			, bool enabled = true );
		SDW_API Double declSpecConstant( std::string const & name
			, uint32_t location
			, double rhs
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Sampled Image declaration
		/**
		*name
		*	Sampled Image declaration.
		*/
		/**@{*/
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > declSampledImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		template< typename T >
		inline T declSampledImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Array< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > declSampledImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declSampledImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Image declaration
		/**
		*name
		*	Image declaration.
		*/
		/**@{*/
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > declImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		template< typename T >
		inline T declImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Array< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > > declImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled = true );
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
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		inline T declInput( std::string const & name
			, uint32_t location
			, uint32_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, uint32_t attributes
			, bool enabled = true );
		template< typename T >
		inline T declInput( std::string const & name
			, uint32_t location
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		inline T declInput( std::string const & name
			, uint32_t location
			, uint32_t attributes
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, uint32_t attributes
			, bool enabled
			, std::vector< T > const & defaultValue );
		template< typename T >
		inline Array< T > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled
			, std::vector< T > const & defaultValue );
		/**@}*/
#pragma endregion
#pragma region Uniform buffer declaration
		/**
		*name
		*	Uniform buffer declaration.
		*/
		/**@{*/
		template< typename T = Ubo >
		inline T declUniformBuffer( std::string const & name
			, uint32_t binding
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd140
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Shader storage buffer declaration
		/**
		*name
		*	Shader storage buffer declaration.
		*/
		/**@{*/
		template< typename T = Ssbo >
		inline T declShaderStorageBuffer( std::string const & name
			, uint32_t binding
			, uint32_t set
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eStd430
			, bool enabled = true );
		template< typename T >
		inline ArraySsboT< T > declArrayShaderStorageBuffer( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Push constants buffer declaration
		/**
		*name
		*	Push constants buffer declaration.
		*/
		/**@{*/
		template< typename T = Pcb >
		inline T declPushConstantsBuffer( std::string const & name
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eC
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Struct declaration
		/**
		*name
		*	Struct declaration.
		*/
		/**@{*/
		template< typename T = Struct >
		inline T declStruct( std::string const & name
			, ast::type::MemoryLayout layout = ast::type::MemoryLayout::eC );
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
			, uint32_t location
			, bool enabled = true );
		template< typename T >
		inline T declOutput( std::string const & name
			, uint32_t location
			, uint32_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declOutputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declOutputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, uint32_t attributes
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Locale declaration
		/**
		*name
		*	Locale variable declaration.
		*/
		/**@{*/
		template< typename InstanceT >
		inline InstanceT declLocale( std::string const & name
			, Struct const & type
			, bool enabled = true );
		template< typename T >
		inline T declLocale( std::string const & name
			, bool enabled = true );
		template< typename T >
		inline T declLocale( std::string const & name
			, T const & rhs );
		template< typename T >
		inline T declLocale( std::string const & name
			, T const & rhs
			, bool enabled );
		template< typename T >
		inline T declLocale( std::string const & name
			, bool enabled
			, T const & defaultValue );
		template< typename T >
		inline Array< T > declLocaleArray( std::string const & name
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declLocaleArray( std::string const & name
			, uint32_t dimension
			, std::vector< T > const & rhs
			, bool enabled = true );
		template< typename T >
		inline Array< T > declLocale( std::string const & name
			, Array< T > const & rhs );
		template< typename T >
		inline Array< T > declLocale( std::string const & name
			, Array< T > const & rhs
			, bool enabled );
		template< typename T >
		inline Array< T > declLocaleArray( std::string const & name
			, uint32_t dimension
			, bool enabled
			, std::vector< T > const & defaultValue );
		template< typename T >
		inline T declLocale( std::string const & name
			, ReturnWrapperT< T > rhs
			, bool enabled = true );
		template< typename T >
		inline T declLocale( std::string const & name
			, bool enabled
			, ReturnWrapperT< T > defaultValue );
		template< typename BaseT, typename DerivedT >
		inline std::unique_ptr< BaseT > declDerivedLocale( std::string const & name
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Already declared variable getters
		/**
		*name
		*	Already declared variable getters.
		*/
		/**@{*/
		template< typename T >
		inline T getVariable( std::string const & name
			, bool enabled = true );
		template< typename T >
		inline Array< T > getVariableArray( std::string const & name
			, bool enabled = true );
		/**@}*/
#pragma endregion
#pragma region Getters
		/**
		*name
		*	Getters.
		*/
		/**@{*/
		inline ast::Shader & getShader()const
		{
			return *m_shader;
		}

		inline ast::type::TypesCache & getTypesCache()const
		{
			return m_shader->getTypesCache();
		}
		/**@}*/
#pragma endregion

	private:
		SDW_API void doPushScope( ast::stmt::ContainerPtr && container );
		SDW_API void doPushScope( ast::stmt::ContainerPtr && container
			, ast::var::VariableList vars );
		SDW_API void doPushScope( ast::stmt::Container * container
			, ast::var::VariableList vars );
		SDW_API void doPopScope();

	protected:
		SDW_API var::VariablePtr registerStaticConstant( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerConstant( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerSpecConstant( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		SDW_API var::VariablePtr registerSampledImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		SDW_API var::VariablePtr registerInput( std::string const & name
			, uint32_t location
			, uint32_t attributes
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutput( std::string const & name
			, uint32_t location
			, uint32_t attributes
			, type::TypePtr type );
		SDW_API var::VariablePtr registerBuiltin( std::string const & name
			, type::TypePtr type
			, var::Flag flag );

	private:
		std::unique_ptr< ast::Shader > m_shader;
		Function< Vec2, InVec2 > m_invertVec2Y;
		Function< Vec3, InVec3 > m_invertVec3Y;
		std::vector< stmt::If * > m_ifStmt;
		std::vector< stmt::Switch * > m_switchStmt;
		std::vector< ast::stmt::ContainerPtr > m_currentStmts;
	};

	class VertexWriter
		: public ShaderWriter
	{
	public:
		SDW_API VertexWriter();
#pragma region I/O declaration
		/**
		*name
		*	I/O declaration.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( VertexMainFuncT< InT, OutT > const & function );
		/**@}*/
#pragma endregion
	};

	class TessellationControlWriter
		: public ShaderWriter
	{
	public:
		SDW_API TessellationControlWriter();
#pragma region I/O declaration
		/**
		*name
		*	I/O declaration.
		*/
		/**@{*/
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementPatchRoutineT( TessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function );
		template< template< ast::var::Flag FlagT > typename InT
			, uint32_t MaxPointsT
			, template< ast::var::Flag FlagT > typename OutT
			, template< ast::var::Flag FlagT > typename PatchT >
		inline void implementMainT( TessControlMainFuncT< InT, MaxPointsT, OutT, PatchT > const & function );
		/**@}*/
#pragma endregion
	};

	class TessellationEvaluationWriter
		: public ShaderWriter
	{
	public:
		SDW_API TessellationEvaluationWriter();

		SDW_API InTessellationEvaluation getIn();
		SDW_API OutTessellationEvaluation getOut();
	};

	class GeometryWriter
		: public ShaderWriter
	{
	private:
		using ShaderWriter::implementMain;

	public:
		SDW_API GeometryWriter();

#pragma region I/O layout declaration
		/**
		*name
		*	I/O layout declaration.
		*/
		/**@{*/
		template< uint32_t MaxPrimCountT, typename InputArrT, typename OutStreamT >
		inline void implementMainT( GeometryMainFuncT< InputArrT, OutStreamT > const & function );
		/**@}*/
#pragma endregion
#pragma region Stream Output declaration
		/**
		*name
		*	Stream Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declStreamOutput( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, bool enabled = true );
		template< typename T >
		inline T declStreamOutput( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declStreamOutputArray( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declStreamOutputArray( std::string const & name
			, uint32_t location
			, uint32_t streamIndex
			, uint32_t dimension
			, uint32_t attributes
			, bool enabled = true );
		/**@}*/
#pragma endregion
	};

	class FragmentWriter
		: public ShaderWriter
	{
	public:
		SDW_API FragmentWriter();
#pragma region I/O layout declaration
		/**
		*name
		*	I/O layout declaration.
		*/
		/**@{*/
		SDW_API void fragmentLayout( ast::FragmentOrigin origin
			, ast::FragmentCenter center );

		template< template< ast::var::Flag FlagT > typename InT
			, template< ast::var::Flag FlagT > typename OutT >
		inline void implementMainT( FragmentMainFuncT< InT, OutT > const & function );
		/**@}*/
#pragma endregion
#pragma region Blend Output declaration
		/**
		*name
		*	Blend Output declaration.
		*/
		/**@{*/
		template< typename T >
		inline T declBlendOutput( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, bool enabled = true );
		template< typename T >
		inline T declBlendOutput( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t attributes
			, bool enabled = true );
		template< typename T >
		inline Array< T > declBlendOutputArray( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t dimension
			, bool enabled = true );
		template< typename T >
		inline Array< T > declBlendOutputArray( std::string const & name
			, uint32_t location
			, uint32_t blendIndex
			, uint32_t dimension
			, uint32_t attributes
			, bool enabled = true );
		/**@}*/
#pragma endregion
	};

	class ComputeWriter
		: public ShaderWriter
	{
	public:
		SDW_API ComputeWriter();

#pragma region Input layout declaration
		/**
		*name
		*	I/O layout declaration.
		*/
		/**@{*/
		SDW_API void inputLayout( uint32_t localSizeX );
		SDW_API void inputLayout( uint32_t localSizeX, uint32_t localSizeY );
		SDW_API void inputLayout( uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ );

		template< template< ast::var::Flag FlagT > typename DataT >
		inline void implementMainT( ComputeMainFuncT< DataT > const & function );
		/**@}*/
#pragma endregion
	};

	template< typename WriterT >
	struct WriterScopeT
	{
	public:
		WriterScopeT( WriterScopeT const & rhs ) = delete;
		WriterScopeT & operator=( WriterScopeT const& rhs ) = delete;

		WriterScopeT( WriterScopeT && rhs )
			: m_writer{ rhs.m_writer }
		{
			rhs.m_writer = nullptr;
		}

		WriterScopeT & operator=( WriterScopeT && rhs )
		{
			m_writer = rhs.m_writer;
			rhs.m_writer = nullptr;
			return *this;
		}

		WriterScopeT( WriterT & writer )
			: m_writer{ &writer }
		{
			m_writer->pushScope();
		}

		~WriterScopeT()
		{
			if ( m_writer )
			{
				m_writer->popScope();
			}
		}

		operator bool()const
		{
			return m_writer != nullptr;
		}

		WriterT * operator->()const
		{
			return m_writer;
		}

		WriterT & operator*()const
		{
			return *m_writer;
		}

	private:
		WriterT * m_writer;
	};

	template< typename WriterT >
	WriterScopeT< WriterT > makeScope( WriterT & writer )
	{
		return WriterScopeT< WriterT >{ writer };
	}
}

#define FOR( Writer, Type, Name, Init, Cond, Incr )\
	if ( auto writerScope = makeScope( Writer ) )\
	{\
		auto ctrlVar##Name = Writer.registerLoopVar( #Name, Type::makeType( Writer.getTypesCache() ) );\
		Type Name{ Writer, sdw::makeExpr( Writer, ctrlVar##Name ), true };\
		Writer.saveNextExpr();\
		Type incr##Name{ Writer, Writer.loadExpr( Type{ Incr } ), true };\
		Name.updateExpr( sdw::makeExpr( Writer, ctrlVar##Name ) );\
		sdw::Boolean cond##Name{ Writer, sdw::makeCondition( Cond ), true };\
		Writer.forStmt( sdw::makeInit( ctrlVar##Name\
			, sdw::makeExpr( Writer, Init ) )\
			, sdw::makeExpr( Writer, cond##Name )\
			, sdw::makeExpr( Writer, incr##Name )\
			, [&]()noexcept

#define ROF\
 );\
	}

#define WHILE( Writer, Condition )\
	( Writer ).whileStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define ELIHW\
 );

#define DOWHILE( Writer, Condition )\
	( Writer ).doWhileStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define ELIHWOD\
 );

#define IF( Writer, Condition )\
	( Writer ).ifStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define ELSE\
 ).elseStmt( [&]()noexcept

#define ELSEIF( Condition )\
 ).elseIfStmt( sdw::makeCondition( Condition )\
		, [&]()noexcept

#define FI\
 ).endIf();

#define SWITCH( Writer, Value )\
	if ( auto writerScope = makeScope( Writer ) )\
	{\
		writerScope->switchStmt( sdw::makeExpr( *writerScope, Value )\
			, [&]()noexcept

#define CASE( Literal )\
			writerScope->caseStmt( sdw::makeLiteral( *writerScope, Literal )\
				, [&]()noexcept

#define ESAC\
 )

#define HCTIWS\
 ).endSwitch();\
	}

#include "Writer.inl"

#endif
