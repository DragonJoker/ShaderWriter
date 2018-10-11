/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Prerequisites_H___
#define ___Writer_Prerequisites_H___

#include <ASTGenerator/Expr/ExprList.hpp>
#include <ASTGenerator/Type/Type.hpp>
#include <ASTGenerator/Stmt/Stmt.hpp>
#include <ASTGenerator/Stmt/StmtContainer.hpp>
#include <ASTGenerator/Var/Variable.hpp>

#include <map>

#define Writer_Parameter( TypeName )\
	using In##TypeName = sdw::InParam< TypeName >;\
	using Out##TypeName = sdw::OutParam< TypeName >;\
	using InOut##TypeName = sdw::InOutParam< TypeName >\

namespace sdw
{
	using namespace ast;
	class Shader;

	enum class SamplerType
	{
		eBuffer,
		e1D,
		e2D,
		e3D,
		eCube,
		e2DRect,
		e1DArray,
		e2DArray,
		eCubeArray,
		e1DShadow,
		e2DShadow,
		eCubeShadow,
		e2DRectShadow,
		e1DArrayShadow,
		e2DArrayShadow,
		eCubeArrayShadow,
	};

	template< typename T >
	struct Array;
	template< typename TypeT >
	struct InParam;
	template< typename TypeT >
	struct OutParam;
	template< typename TypeT >
	struct InOutParam;
	template< typename TypeT >
	struct Optional;
	template< typename TypeT >
	struct Vec2T;
	template< typename TypeT >
	struct Vec3T;
	template< typename TypeT >
	struct Vec4T;
	template< typename TypeT >
	struct Mat2T;
	template< typename TypeT >
	struct Mat3T;
	template< typename TypeT >
	struct Mat4T;
	template< SamplerType T >
	struct SamplerT;

	struct Value;
	struct Void;
	struct Boolean;
	struct Int;
	struct UInt;
	struct Float;

	using Vec2 = Vec2T< Float >;
	using Vec3 = Vec3T< Float >;
	using Vec4 = Vec4T< Float >;
	using IVec2 = Vec2T< Int >;
	using IVec3 = Vec3T< Int >;
	using IVec4 = Vec4T< Int >;
	using UVec2 = Vec2T< UInt >;
	using UVec3 = Vec3T< UInt >;
	using UVec4 = Vec4T< UInt >;
	using BVec2 = Vec2T< Boolean >;
	using BVec3 = Vec3T< Boolean >;
	using BVec4 = Vec4T< Boolean >;
	using Mat2 = Mat2T< Float >;
	using Mat3 = Mat3T< Float >;
	using Mat4 = Mat4T< Float >;
	using IMat2 = Mat2T< Int >;
	using IMat3 = Mat3T< Int >;
	using IMat4 = Mat4T< Int >;
	using UMat2 = Mat2T< UInt >;
	using UMat3 = Mat3T< UInt >;
	using UMat4 = Mat4T< UInt >;
	using BMat2 = Mat2T< Boolean >;
	using BMat3 = Mat3T< Boolean >;
	using BMat4 = Mat4T< Boolean >;

	using SamplerBuffer = SamplerT< SamplerType::eBuffer >;
	using Sampler1D = SamplerT< SamplerType::e1D >;
	using Sampler2D = SamplerT< SamplerType::e2D >;
	using Sampler3D = SamplerT< SamplerType::e3D >;
	using SamplerCube = SamplerT< SamplerType::eCube >;
	using Sampler2DRect = SamplerT< SamplerType::e2DRect >;
	using Sampler1DArray = SamplerT< SamplerType::e1DArray >;
	using Sampler2DArray = SamplerT< SamplerType::e2DArray >;
	using SamplerCubeArray = SamplerT< SamplerType::eCubeArray >;
	using Sampler1DShadow = SamplerT< SamplerType::e1DShadow >;
	using Sampler2DShadow = SamplerT< SamplerType::e2DShadow >;
	using SamplerCubeShadow = SamplerT< SamplerType::eCubeShadow >;
	using Sampler2DRectShadow = SamplerT< SamplerType::e2DRectShadow >;
	using Sampler1DArrayShadow = SamplerT< SamplerType::e1DArrayShadow >;
	using Sampler2DArrayShadow = SamplerT< SamplerType::e2DArrayShadow >;
	using SamplerCubeArrayShadow = SamplerT< SamplerType::eCubeArrayShadow >;

	Writer_Parameter( Float );
	Writer_Parameter( Int );
	Writer_Parameter( UInt );
	Writer_Parameter( Boolean );
	Writer_Parameter( Vec2 );
	Writer_Parameter( Vec3 );
	Writer_Parameter( Vec4 );
	Writer_Parameter( IVec2 );
	Writer_Parameter( IVec3 );
	Writer_Parameter( IVec4 );
	Writer_Parameter( UVec2 );
	Writer_Parameter( UVec3 );
	Writer_Parameter( UVec4 );
	Writer_Parameter( BVec2 );
	Writer_Parameter( BVec3 );
	Writer_Parameter( BVec4 );
	Writer_Parameter( Mat2 );
	Writer_Parameter( Mat3 );
	Writer_Parameter( Mat4 );
	Writer_Parameter( IMat2 );
	Writer_Parameter( IMat3 );
	Writer_Parameter( IMat4 );
	Writer_Parameter( UMat2 );
	Writer_Parameter( UMat3 );
	Writer_Parameter( UMat4 );
	Writer_Parameter( BMat2 );
	Writer_Parameter( BMat3 );
	Writer_Parameter( BMat4 );
	Writer_Parameter( SamplerBuffer );
	Writer_Parameter( Sampler1D );
	Writer_Parameter( Sampler2D );
	Writer_Parameter( Sampler3D );
	Writer_Parameter( SamplerCube );
	Writer_Parameter( Sampler2DRect );
	Writer_Parameter( Sampler1DArray );
	Writer_Parameter( Sampler2DArray );
	Writer_Parameter( SamplerCubeArray );
	Writer_Parameter( Sampler1DShadow );
	Writer_Parameter( Sampler2DShadow );
	Writer_Parameter( SamplerCubeShadow );
	Writer_Parameter( Sampler2DRectShadow );
	Writer_Parameter( Sampler1DArrayShadow );
	Writer_Parameter( Sampler2DArrayShadow );
	Writer_Parameter( SamplerCubeArrayShadow );

	template< typename RetT, typename ... ParamsT >
	struct Function;

	template< typename T >
	struct TypeTraits;
	template< SamplerType ST >
	struct SamplerTypeTraits;
	template< typename T >
	struct TypeOf
	{
		using Type = T;
	};

	struct Endl
	{
	};
	struct Endi
	{
	};
	struct Version
	{
	};
	struct Attribute
	{
	};
	struct In
	{
	};
	struct Out
	{
	};
	struct Layout
	{
		int m_location;
	};
	struct Uniform
	{
	};

	static Endi endi;
	static Endl endl;

	std::string getTypeName( expr::ExprPtr const & expr );
	expr::ExprPtr makeExpr( expr::Expr * expr );
	expr::ExprPtr makeExpr( expr::ExprPtr const & expr );
	expr::ExprPtr makeExpr( var::VariablePtr const & var );
	expr::ExprPtr makeExpr( bool value );
	expr::ExprPtr makeExpr( int32_t value );
	expr::ExprPtr makeExpr( int64_t value );
	expr::ExprPtr makeExpr( uint32_t value );
	expr::ExprPtr makeExpr( uint64_t value );
	expr::ExprPtr makeExpr( float value );
	expr::ExprPtr makeExpr( double value );
	expr::ExprPtr makeExpr( long double value );
	template< typename T >
	expr::ExprList makeExpr( std::vector< T > const & values );
	void addStmt( Shader & shader
		, stmt::StmtPtr stmt );
	void addStmt( stmt::Container & container
		, stmt::StmtPtr stmt );
	void registerName( Shader & shader
		, std::string const & name
		, type::Kind type );
	void checkNameExists( Shader & shader
		, std::string const & name
		, type::Kind type );
}

#include "ShaderWriterPrerequisites.inl"

#endif
