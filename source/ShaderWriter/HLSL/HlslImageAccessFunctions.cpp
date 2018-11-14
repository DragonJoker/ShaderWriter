/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslIntrinsicFunctions.hpp"

#include <ASTGenerator/Expr/EnumIntrinsic.hpp>
#include <ASTGenerator/Expr/ExprBitAnd.hpp>
#include <ASTGenerator/Expr/ExprBitOr.hpp>
#include <ASTGenerator/Expr/ExprCast.hpp>
#include <ASTGenerator/Expr/ExprDivide.hpp>
#include <ASTGenerator/Expr/ExprEqual.hpp>
#include <ASTGenerator/Expr/ExprInit.hpp>
#include <ASTGenerator/Expr/ExprIntrinsicCall.hpp>
#include <ASTGenerator/expr/ExprLiteral.hpp>
#include <ASTGenerator/expr/ExprLShift.hpp>
#include <ASTGenerator/expr/ExprLShiftAssign.hpp>
#include <ASTGenerator/expr/ExprMbrSelect.hpp>
#include <ASTGenerator/expr/ExprOrAssign.hpp>
#include <ASTGenerator/expr/ExprRShift.hpp>
#include <ASTGenerator/expr/ExprRShiftAssign.hpp>
#include <ASTGenerator/expr/ExprTimes.hpp>

#include <ASTGenerator/Stmt/StmtFunctionDecl.hpp>
#include <ASTGenerator/Stmt/StmtReturn.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>
#include <ASTGenerator/Stmt/StmtVariableDecl.hpp>

#include <string>

namespace sdw::hlsl
{
	namespace details
	{
		using namespace ast;

		inline void writeImageSamples2DMS( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageSamples(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpY;" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dumpX, dumpY, res);" ) );
			cont->addStmt( stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageSamples2DMSArray( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageSamples(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dumpZ;" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dumpX, dumpY, dumpZ, res);" ) );
			cont->addStmt( stmt::makeComment( "	return int(res);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAdd(" + type + " image, int P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAdd(" + type + " image, int2 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAdd(" + type + " image, int3 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAdd(" + type + " image, int P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAdd(" + type + " image, int2 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAdd(" + type + " image, int3 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMin(" + type + " image, int P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMin(" + type + " image, int2 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMin(" + type + " image, int3 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMin(" + type + " image, int P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMin(" + type + " image, int2 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMin(" + type + " image, int3 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMax(" + type + " image, int P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMax(" + type + " image, int2 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMax(" + type + " image, int3 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMax(" + type + " image, int P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMax(" + type + " image, int2 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMax(" + type + " image, int3 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAnd(" + type + " image, int P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAnd(" + type + " image, int2 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAnd(" + type + " image, int3 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAnd(" + type + " image, int P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAnd(" + type + " image, int2 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAnd(" + type + " image, int3 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicOr(" + type + " image, int P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicOr(" + type + " image, int2 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicOr(" + type + " image, int3 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicOr(" + type + " image, int P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicOr(" + type + " image, int2 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicOr(" + type + " image, int3 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicXor(" + type + " image, int P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicXor(" + type + " image, int2 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicXor(" + type + " image, int3 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicXor(" + type + " image, int P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicXor(" + type + " image, int2 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicXor(" + type + " image, int3 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicExchange(" + type + " image, int P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicExchange(" + type + " image, int2 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicExchange(" + type + " image, int3 P, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicExchange(" + type + " image, int P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image[uint(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicExchange(" + type + " image, int2 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image[uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicExchange(" + type + " image, int3 P, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image[uint3(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap1DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicCompSwap(" + type + " image, int P, uint compare, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image[uint(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap2DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicCompSwap(" + type + " image, int2 P, uint compare, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image[uint2(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap3DU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicCompSwap(" + type + " image, int3 P, uint compare, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image[uint3(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap1DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicCompSwap(" + type + " image, int P, int compare, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image[uint(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap2DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicCompSwap(" + type + " image, int2 P, int compare, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image[uint2(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap3DI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicCompSwap(" + type + " image, int3 P, int compare, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image[uint3(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
	}

	void writeHlslImageAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
		//if ( config.requiresImageSamples2DMSF )
		//{
		//	details::writeImageSamples2DMS( container, "RWTexture2D<float4>" );
		//}
		//if ( config.requiresImageSamples2DMSI )
		//{
		//	details::writeImageSamples2DMS( container, "RWTexture2D<int4>" );
		//}
		//if ( config.requiresImageSamples2DMSU )
		//{
		//	details::writeImageSamples2DMS( container, "RWTexture2D<uint4>" );
		//}
		//if ( config.requiresImageSamples2DMSArrayF )
		//{
		//	details::writeImageSamples2DMSArray( container, "RWTexture2DArray<float4>" );
		//}
		//if ( config.requiresImageSamples2DMSArrayI )
		//{
		//	details::writeImageSamples2DMSArray( container, "RWTexture2DArray<int4>" );
		//}
		//if ( config.requiresImageSamples2DMSArrayU )
		//{
		//	details::writeImageSamples2DMSArray( container, "RWTexture2DArray<uint4>" );
		//}
		if ( config.requiresImageAtomicAddBufferU )
		{
			details::writeImageAtomicAdd1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicAdd1DU )
		{
			details::writeImageAtomicAdd1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicAdd2DU
			|| config.requiresImageAtomicAdd2DRectU
			|| config.requiresImageAtomicAdd2DMSU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayU
			|| config.requiresImageAtomicAddCubeU
			|| config.requiresImageAtomicAddCubeArrayU
			|| config.requiresImageAtomicAdd2DMSArrayU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicAdd3DU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicAddBufferI )
		{
			details::writeImageAtomicAdd1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicAdd1DI )
		{
			details::writeImageAtomicAdd1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicAdd2DI
			|| config.requiresImageAtomicAdd2DRectI
			|| config.requiresImageAtomicAdd2DMSI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayI
			|| config.requiresImageAtomicAddCubeI
			|| config.requiresImageAtomicAddCubeArrayI
			|| config.requiresImageAtomicAdd2DMSArrayI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicAdd3DI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture3D<int>" );
		}
		if ( config.requiresImageAtomicMinBufferU )
		{
			details::writeImageAtomicMin1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicMin1DU )
		{
			details::writeImageAtomicMin1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicMin1DArrayU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicMin2DU
			|| config.requiresImageAtomicMin2DRectU
			|| config.requiresImageAtomicMin2DMSU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicMin2DArrayU
			|| config.requiresImageAtomicMinCubeU
			|| config.requiresImageAtomicMinCubeArrayU
			|| config.requiresImageAtomicMin2DMSArrayU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicMin3DU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicMinBufferI )
		{
			details::writeImageAtomicMin1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicMin1DI )
		{
			details::writeImageAtomicMin1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicMin1DArrayI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicMin2DI
			|| config.requiresImageAtomicMin2DRectI
			|| config.requiresImageAtomicMin2DMSI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicMin2DArrayI
			|| config.requiresImageAtomicMinCubeI
			|| config.requiresImageAtomicMinCubeArrayI
			|| config.requiresImageAtomicMin2DMSArrayI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicMin3DI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture3D<int>" );
		}
		if ( config.requiresImageAtomicMaxBufferU )
		{
			details::writeImageAtomicMax1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicMax1DU )
		{
			details::writeImageAtomicMax1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicMax1DArrayU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicMax2DU
			|| config.requiresImageAtomicMax2DRectU
			|| config.requiresImageAtomicMax2DMSU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicMax2DArrayU
			|| config.requiresImageAtomicMaxCubeU
			|| config.requiresImageAtomicMaxCubeArrayU
			|| config.requiresImageAtomicMax2DMSArrayU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicMax3DU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicMaxBufferI )
		{
			details::writeImageAtomicMax1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicMax1DI )
		{
			details::writeImageAtomicMax1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicMax1DArrayI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicMax2DI
			|| config.requiresImageAtomicMax2DRectI
			|| config.requiresImageAtomicMax2DMSI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicMax2DArrayI
			|| config.requiresImageAtomicMaxCubeI
			|| config.requiresImageAtomicMaxCubeArrayI
			|| config.requiresImageAtomicMax2DMSArrayI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicMax3DI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture3D<int>" );
		}
		if ( config.requiresImageAtomicAndBufferU )
		{
			details::writeImageAtomicAnd1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicAnd1DU )
		{
			details::writeImageAtomicAnd1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicAnd2DU
			|| config.requiresImageAtomicAnd2DRectU
			|| config.requiresImageAtomicAnd2DMSU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayU
			|| config.requiresImageAtomicAndCubeU
			|| config.requiresImageAtomicAndCubeArrayU
			|| config.requiresImageAtomicAnd2DMSArrayU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicAnd3DU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicAndBufferI )
		{
			details::writeImageAtomicAnd1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicAnd1DI )
		{
			details::writeImageAtomicAnd1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicAnd2DI
			|| config.requiresImageAtomicAnd2DRectI
			|| config.requiresImageAtomicAnd2DMSI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayI
			|| config.requiresImageAtomicAndCubeI
			|| config.requiresImageAtomicAndCubeArrayI
			|| config.requiresImageAtomicAnd2DMSArrayI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicAnd3DI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture3D<int>" );
		}
		if ( config.requiresImageAtomicOrBufferU )
		{
			details::writeImageAtomicOr1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicOr1DU )
		{
			details::writeImageAtomicOr1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicOr1DArrayU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicOr2DU
			|| config.requiresImageAtomicOr2DRectU
			|| config.requiresImageAtomicOr2DMSU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicOr2DArrayU
			|| config.requiresImageAtomicOrCubeU
			|| config.requiresImageAtomicOrCubeArrayU
			|| config.requiresImageAtomicOr2DMSArrayU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicOr3DU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicOrBufferI )
		{
			details::writeImageAtomicOr1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicOr1DI )
		{
			details::writeImageAtomicOr1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicOr1DArrayI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicOr2DI
			|| config.requiresImageAtomicOr2DRectI
			|| config.requiresImageAtomicOr2DMSI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicOr2DArrayI
			|| config.requiresImageAtomicOrCubeI
			|| config.requiresImageAtomicOrCubeArrayI
			|| config.requiresImageAtomicOr2DMSArrayI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicOr3DI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture3D<int>" );
		}
		if ( config.requiresImageAtomicXorBufferU )
		{
			details::writeImageAtomicXor1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicXor1DU )
		{
			details::writeImageAtomicXor1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicXor1DArrayU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicXor2DU
			|| config.requiresImageAtomicXor2DRectU
			|| config.requiresImageAtomicXor2DMSU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicXor2DArrayU
			|| config.requiresImageAtomicXorCubeU
			|| config.requiresImageAtomicXorCubeArrayU
			|| config.requiresImageAtomicXor2DMSArrayU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicXor3DU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicXorBufferI )
		{
			details::writeImageAtomicXor1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicXor1DI )
		{
			details::writeImageAtomicXor1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicXor1DArrayI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicXor2DI
			|| config.requiresImageAtomicXor2DRectI
			|| config.requiresImageAtomicXor2DMSI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicXor2DArrayI
			|| config.requiresImageAtomicXorCubeI
			|| config.requiresImageAtomicXorCubeArrayI
			|| config.requiresImageAtomicXor2DMSArrayI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicXor3DI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture3D<int>" );
		}
		if ( config.requiresImageAtomicExchangeBufferU )
		{
			details::writeImageAtomicExchange1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicExchange1DU )
		{
			details::writeImageAtomicExchange1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicExchange2DU
			|| config.requiresImageAtomicExchange2DRectU
			|| config.requiresImageAtomicExchange2DMSU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayU
			|| config.requiresImageAtomicExchangeCubeU
			|| config.requiresImageAtomicExchangeCubeArrayU
			|| config.requiresImageAtomicExchange2DMSArrayU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicExchange3DU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicExchangeBufferI )
		{
			details::writeImageAtomicExchange1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicExchange1DI )
		{
			details::writeImageAtomicExchange1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicExchange2DI
			|| config.requiresImageAtomicExchange2DRectI
			|| config.requiresImageAtomicExchange2DMSI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayI
			|| config.requiresImageAtomicExchangeCubeI
			|| config.requiresImageAtomicExchangeCubeArrayI
			|| config.requiresImageAtomicExchange2DMSArrayI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicExchange3DI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture3D<int>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWBuffer<uint>" );
		}
		if ( config.requiresImageAtomicCompSwap1DU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWTexture1D<uint>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture1DArray<uint>" );
		}
		if ( config.requiresImageAtomicCompSwap2DU
			|| config.requiresImageAtomicCompSwap2DRectU
			|| config.requiresImageAtomicCompSwap2DMSU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2D<uint>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayU
			|| config.requiresImageAtomicCompSwapCubeU
			|| config.requiresImageAtomicCompSwapCubeArrayU
			|| config.requiresImageAtomicCompSwap2DMSArrayU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture2DArray<uint>" );
		}
		if ( config.requiresImageAtomicCompSwap3DU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture3D<uint>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferI )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWBuffer<int>" );
		}
		if ( config.requiresImageAtomicCompSwap1DI )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWTexture1D<int>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture1DArray<int>" );
		}
		if ( config.requiresImageAtomicCompSwap2DI
			|| config.requiresImageAtomicCompSwap2DRectI
			|| config.requiresImageAtomicCompSwap2DMSI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2D<int>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayI
			|| config.requiresImageAtomicCompSwapCubeI
			|| config.requiresImageAtomicCompSwapCubeArrayI
			|| config.requiresImageAtomicCompSwap2DMSArrayI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture2DArray<int>" );
		}
		if ( config.requiresImageAtomicCompSwap3DI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture3D<int>" );
		}
	}
}
