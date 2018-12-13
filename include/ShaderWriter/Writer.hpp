/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Writer_H___
#define ___SDW_Writer_H___

#include "ShaderWriter/CompositeTypes/Builtins.hpp"
#include "Shader.hpp"
#include <ShaderAST/Stmt/StmtIf.hpp>

namespace sdw
{
	class ShaderWriter
	{
	protected:
		SDW_API ShaderWriter( ShaderType type );
		SDW_API virtual ~ShaderWriter();

	public:
#pragma region Variables registration
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		SDW_API var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		SDW_API var::VariablePtr registerLocale( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr registerInOutParam( std::string const & name
			, type::TypePtr type );
		SDW_API var::VariablePtr getVar( std::string const & name );
		SDW_API void addStmt( stmt::StmtPtr stmt );
		SDW_API void registerSsbo( std::string const & name
			, SsboInfo const & info );
		SDW_API void registerUbo( std::string const & name
			, UboInfo const & info );
		/**@}*/
#pragma endregion
		SDW_API void inlineComment( std::string const & comment );
		SDW_API void multilineComment( std::string const & comment );
		SDW_API void discard();
		template< typename ReturnT, typename ... ParamsT >
		inline Function< ReturnT, ParamsT... > implementFunction( std::string const & name
			, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
			, ParamsT && ... params );
		SDW_API void returnStmt();
		template< typename RetType >
		void returnStmt( RetType const & value );
		template< typename ValueT >
		inline ValueT paren( ValueT const & content );
		template< typename ValueT >
		inline Optional< ValueT > paren( Optional< ValueT > const & content );
		template< typename ValueT >
		inline MaybeOptional< ValueT > paren( MaybeOptional< ValueT > const & content );
		template< typename ReturnT >
		void callFunction( ReturnT const & functionResult );
#pragma region Cast
		/**
		*name
		*	Cast.
		*/
		/**@{*/
		template< typename DestT >
		inline DestT cast( Value const & from );
		template< typename DestT, typename SrcT >
		inline Optional< DestT > cast( Optional< SrcT > const & from );
		template< typename DestT >
		inline DestT cast( int32_t from );
		template< typename DestT >
		inline DestT cast( uint32_t from );
		template< typename DestT >
		inline DestT cast( float from );
		template< typename DestT >
		inline DestT cast( double from );
		/**@}*/
#pragma endregion
#pragma region Control statements
		/**
		*name
		*	Control statements.
		*/
		/**@{*/
		SDW_API void pushScope();
		SDW_API void popScope();
		SDW_API void saveNextExpr();
		SDW_API ast::expr::ExprPtr loadExpr( Value const & value );
		template< typename ExprType >
		ExprType ternary( expr::ExprPtr condition
			, expr::ExprPtr left
			, expr::ExprPtr right );
		template< typename ExprType >
		ExprType ternary( Bool condition
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
			, T const & rhs
			, bool enabled );
		template< typename T >
		inline Array< T > declConstantArray( std::string const & name
			, std::vector< T > const & rhs );
		template< typename T >
		inline Optional< Array< T > > declConstantArray( std::string const & name
			, std::vector< T > const & rhs
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Specialisation constant declaration
		/**
		*name
		*	Specialisation constant declaration.
		*/
		/**@{*/
		SDW_API Bool declSpecConstant( std::string const & name
			, uint32_t location
			, bool rhs );
		SDW_API Optional< Bool > declSpecConstant( std::string const & name
			, uint32_t location
			, bool rhs
			, bool enabled );
		SDW_API Int declSpecConstant( std::string const & name
			, uint32_t location
			, int32_t rhs );
		SDW_API Optional< Int > declSpecConstant( std::string const & name
			, uint32_t location
			, int32_t rhs
			, bool enabled );
		SDW_API UInt declSpecConstant( std::string const & name
			, uint32_t location
			, uint32_t rhs );
		SDW_API Optional< UInt > declSpecConstant( std::string const & name
			, uint32_t location
			, uint32_t rhs
			, bool enabled );
		SDW_API Float declSpecConstant( std::string const & name
			, uint32_t location
			, float rhs );
		SDW_API Optional< Float > declSpecConstant( std::string const & name
			, uint32_t location
			, float rhs
			, bool enabled );
		SDW_API Double declSpecConstant( std::string const & name
			, uint32_t location
			, double rhs );
		SDW_API Optional< Double > declSpecConstant( std::string const & name
			, uint32_t location
			, double rhs
			, bool enabled );
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
			, bool MsT>
		inline SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > declSampledImage( std::string const & name
			, uint32_t binding
			, uint32_t set );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Optional< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > declSampledImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Array< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > declSampledImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Optional< Array< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > > declSampledImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Image declaration
		/**
		*name
		*	Image declaration.
		*/
		/**@{*/
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > declImage( std::string const & name
			, uint32_t binding
			, uint32_t set );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Optional< ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > declImage( std::string const & name
			, uint32_t binding
			, uint32_t set
			, bool enabled );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Array< ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > declImageArray( std::string const & name
			, uint32_t binding
			, uint32_t set
			, uint32_t dimension );
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		inline Optional< Array< ImageT< FormatT, DimT, ArrayedT, DepthT, MsT > > > declImageArray( std::string const & name
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
		inline Optional< Array< T > > declInputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
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
		inline Optional< T > declOutput( std::string const & name
			, uint32_t location
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declOutputArray( std::string const & name
			, uint32_t location
			, uint32_t dimension
			, bool enabled );
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
			, Struct const & type );
		template< typename T >
		inline T declLocale( std::string const & name );
		template< typename T >
		inline T declLocale( std::string const & name
			, T const & rhs );
		template< typename T >
		inline MaybeOptional< T > declLocale( std::string const & name
			, MaybeOptional< T > const & rhs );
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
		inline MaybeOptional< Array< T > > declLocale( std::string const & name
			, MaybeOptional< Array< T > > const & rhs );
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
#pragma region Already declared variable getters
		/**
		*name
		*	Already declared variable getters.
		*/
		/**@{*/
		template< typename T >
		inline T getVariable( std::string const & name );
		template< typename T >
		inline Optional< T > getVariable( std::string const & name
			, bool enabled );
		template< typename T >
		inline Array< T > getVariableArray( std::string const & name );
		template< typename T >
		inline Optional< Array< T > > getVariableArray( std::string const & name
			, bool enabled );
		/**@}*/
#pragma endregion
#pragma region Getters
		/**
		*name
		*	Getters.
		*/
		/**@{*/
		inline Shader const & getShader()const
		{
			return m_shader;
		}

		inline Shader & getShader()
		{
			return m_shader;
		}

		inline ast::type::TypesCache & getTypesCache()const
		{
			return m_shader.getTypesCache();
		}
		/**@}*/
#pragma endregion

	private:
		SDW_API void doPushScope( ast::stmt::ContainerPtr && container );
		SDW_API void doPushScope( ast::stmt::Container * container );
		SDW_API void doPopScope();
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
			, type::TypePtr type );
		SDW_API var::VariablePtr registerOutput( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		SDW_API var::VariablePtr registerBuiltin( std::string const & name
			, type::TypePtr type
			, var::Flag flag );

	private:
		Shader m_shader;
		Function< Vec2, InVec2 > m_invertVec2Y;
		Function< Vec3, InVec3 > m_invertVec3Y;
		std::vector< stmt::If * > m_ifStmt;
		std::vector< ast::stmt::ContainerPtr > m_currentStmts;
	};

	class VertexWriter
		: public ShaderWriter
	{
	public:
		SDW_API VertexWriter();

		SDW_API InVertex getIn();
		SDW_API OutVertex getOut();
	};

	class TessellationControlWriter
		: public ShaderWriter
	{
	public:
		SDW_API TessellationControlWriter();

		SDW_API InTessellationControl getIn();
		SDW_API OutTessellationControl getOut();
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
	public:
		SDW_API GeometryWriter();

		SDW_API void inputLayout( stmt::InputLayout layout );
		SDW_API void outputLayout( stmt::OutputLayout layout, uint32_t count );
		SDW_API InGeometry getIn();
		SDW_API OutGeometry getOut();
	};

	class FragmentWriter
		: public ShaderWriter
	{
	public:
		SDW_API FragmentWriter();

		SDW_API InFragment getIn();
		SDW_API OutFragment getOut();
	};

	class ComputeWriter
		: public ShaderWriter
	{
	public:
		SDW_API ComputeWriter();

		SDW_API void inputLayout( uint32_t localSizeX );
		SDW_API void inputLayout( uint32_t localSizeX, uint32_t localSizeY );
		SDW_API void inputLayout( uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ );
		SDW_API InCompute getIn();
	};
}

#define FOR( Writer, Type, Name, Init, Cond, Incr )\
	{\
		auto & writer_int = ( Writer );\
		auto & shader_int = writer_int.getShader();\
		writer_int.pushScope();\
		auto ctrlVar##Name = writer_int.registerLocale( #Name, Type::makeType( shader_int.getTypesCache() ) );\
		Type Name{ &shader_int\
			, sdw::makeExpr( shader_int, ctrlVar##Name ) };\
		writer_int.saveNextExpr();\
		Type incr##Name{ &shader_int, writer_int.loadExpr( Incr ) };\
		Name.updateExpr( sdw::makeExpr( shader_int, ctrlVar##Name ) );\
		Type cond##Name{ &shader_int, sdw::makeCondition( Cond ) };\
		writer_int.forStmt( sdw::makeInit( ctrlVar##Name\
				, sdw::makeExpr( shader_int, Init ) )\
			, sdw::makeExpr( shader_int, cond##Name )\
			, sdw::makeExpr( shader_int, incr##Name )\
			, [&]()

#define ROF\
 );\
		writer_int.popScope();\
	}

#define WHILE( Writer, Condition )\
	( Writer ).whileStmt( sdw::makeCondition( Condition )\
		, [&]()

#define ELIHW\
 );

#define DOWHILE( Writer, Condition )\
	( Writer ).doWhileStmt( sdw::makeCondition( Condition )\
		, [&]()

#define ELIHWOD\
 );

#define IF( Writer, Condition )\
	( Writer ).ifStmt( sdw::makeCondition( Condition )\
		, [&]()

#define ELSE\
 ).elseStmt( [&]()

#define ELSEIF( Condition )\
 ).elseIfStmt( sdw::makeCondition( Condition )\
		, [&]()

#define FI\
 ).endIf();

#define TERNARY( Writer, ExprType, Condition, Left, Right )\
	( Writer ).ternary< ExprType >( sdw::makeCondition( Condition )\
		, sdw::makeExpr( Writer.getShader(), Left )\
		, sdw::makeExpr( Writer.getShader(), Right ) )

#include "Writer.inl"

#endif
