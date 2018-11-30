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
		ShaderWriter( ShaderType type );

	public:
#pragma region Variables registration
		/**
		*name
		*	Variables registration.
		*/
		/**@{*/
		var::VariablePtr registerName( std::string const & name
			, type::TypePtr type
			, uint32_t flags );
		var::VariablePtr registerLocale( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerInParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerOutParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerInOutParam( std::string const & name
			, type::TypePtr type );
		var::VariablePtr getVar( std::string const & name );
		void addStmt( stmt::StmtPtr stmt );
		void registerSsbo( std::string const & name
			, SsboInfo const & info );
		void registerUbo( std::string const & name
			, UboInfo const & info );
		/**@}*/
#pragma endregion
		void inlineComment( std::string const & comment );
		void multilineComment( std::string const & comment );
		void discard();
		template< typename ReturnT, typename ... ParamsT >
		inline Function< ReturnT, ParamsT... > implementFunction( std::string const & name
			, std::function< void( ParamTranslaterT< ParamsT >... ) > const & function
			, ParamsT && ... params );
		void returnStmt();
		template< typename RetType >
		void returnStmt( RetType const & value );
		template< typename ValueT >
		inline ValueT paren( ValueT const & content );
		template< typename FunctionT, typename ... ParamsT >
		void callFunction( FunctionT const & function
			, ParamsT && ... params );
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
		template< typename ExprType >
		ExprType ternary( expr::ExprPtr condition
			, expr::ExprPtr left
			, expr::ExprPtr right );
		template< typename ExprType >
		ExprType ternary( Boolean condition
			, ExprType left
			, ExprType right );
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
		ShaderWriter & elseStmt( std::function< void() > function );
		void endIf();
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
		Boolean declSpecConstant( std::string const & name
			, uint32_t location
			, bool rhs );
		Optional< Boolean > declSpecConstant( std::string const & name
			, uint32_t location
			, bool rhs
			, bool enabled );
		Int declSpecConstant( std::string const & name
			, uint32_t location
			, int32_t rhs );
		Optional< Int > declSpecConstant( std::string const & name
			, uint32_t location
			, int32_t rhs
			, bool enabled );
		UInt declSpecConstant( std::string const & name
			, uint32_t location
			, uint32_t rhs );
		Optional< UInt > declSpecConstant( std::string const & name
			, uint32_t location
			, uint32_t rhs
			, bool enabled );
		Float declSpecConstant( std::string const & name
			, uint32_t location
			, float rhs );
		Optional< Float > declSpecConstant( std::string const & name
			, uint32_t location
			, float rhs
			, bool enabled );
		Double declSpecConstant( std::string const & name
			, uint32_t location
			, double rhs );
		Optional< Double > declSpecConstant( std::string const & name
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
		/**@}*/
#pragma endregion

	private:
		var::VariablePtr registerConstant( std::string const & name
			, type::TypePtr type );
		var::VariablePtr registerSpecConstant( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		var::VariablePtr registerSampledImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		var::VariablePtr registerImage( std::string const & name
			, type::TypePtr type
			, uint32_t binding
			, uint32_t set
			, bool enabled = true );
		var::VariablePtr registerInput( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		var::VariablePtr registerOutput( std::string const & name
			, uint32_t location
			, type::TypePtr type );
		var::VariablePtr registerBuiltin( std::string const & name
			, type::TypePtr type
			, var::Flag flag );

	private:
		Shader m_shader;
		Function< Vec2, InVec2 > m_invertVec2Y;
		Function< Vec3, InVec3 > m_invertVec3Y;
		std::vector< stmt::If * > m_ifStmt;
	};

	class VertexWriter
		: public ShaderWriter
	{
	public:
		VertexWriter();

		InVertex getIn();
		OutVertex getOut();
	};

	class TessellationControlWriter
		: public ShaderWriter
	{
	public:
		TessellationControlWriter();

		InTessellationControl getIn();
		OutTessellationControl getOut();
	};

	class TessellationEvaluationWriter
		: public ShaderWriter
	{
	public:
		TessellationEvaluationWriter();

		InTessellationEvaluation getIn();
		OutTessellationEvaluation getOut();
	};

	class GeometryWriter
		: public ShaderWriter
	{
	public:
		GeometryWriter();

		void inputLayout( stmt::InputLayout layout );
		void outputLayout( stmt::OutputLayout layout, uint32_t count );
		InGeometry getIn();
		OutGeometry getOut();
	};

	class FragmentWriter
		: public ShaderWriter
	{
	public:
		FragmentWriter();

		InFragment getIn();
		OutFragment getOut();
	};

	class ComputeWriter
		: public ShaderWriter
	{
	public:
		ComputeWriter();

		void inputLayout( uint32_t localSizeX );
		void inputLayout( uint32_t localSizeX, uint32_t localSizeY );
		void inputLayout( uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ );
		InCompute getIn();
	};
}

#define FOR( Writer, Type, Name, Init, Cond, Incr )\
	{\
		auto ctrlVar##Name = ( Writer ).registerLocale( #Name, sdw::type::makeType( sdw::typeEnum<Type> ) );\
		Type Name{ &( Writer ).getShader()\
			, sdw::makeExpr( ctrlVar##Name ) };\
		Type incr##Name{ &( Writer ).getShader(), sdw::makeExpr( Incr ) };\
		Name.updateExpr( sdw::makeExpr( ctrlVar##Name ) );\
		Type cond##Name{ &( Writer ).getShader(), sdw::makeExpr( Cond ) };\
		( Writer ).forStmt( sdw::makeInit( ctrlVar##Name\
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
 ).endIf();

#define TERNARY( Writer, ExprType, Condition, Left, Right )\
	( Writer ).ternary< ExprType >( sdw::makeExpr( Condition ), sdw::makeExpr( Left ), sdw::makeExpr( Right ) )

#include "Writer.inl"

#endif
