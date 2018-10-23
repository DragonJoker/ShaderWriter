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

		inline void writeImageSize1D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageSize(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dimX);" ) );
			cont->addStmt( stmt::makeComment( "	return int(dimX);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageSize2D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int2 SDW_imageSize(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dimX, dimY);" ) );
			cont->addStmt( stmt::makeComment( "	return int2(dimX, dimY);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageSize3D( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int3 SDW_imageSize(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimZ;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dimX, dimY, dimZ);" ) );
			cont->addStmt( stmt::makeComment( "	return int3(dimX, dimY, dimZ);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageSize2DMS( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int2 SDW_imageSize(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dump;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dimX, dimY, dump);" ) );
			cont->addStmt( stmt::makeComment( "	return int2(dimX, dimY);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageSize2DMSArray( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int3 SDW_imageSize(" + type + " image)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint dimX;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimY;" ) );
			cont->addStmt( stmt::makeComment( "	uint dimZ;" ) );
			cont->addStmt( stmt::makeComment( "	uint dump;" ) );
			cont->addStmt( stmt::makeComment( "	image.GetDimensions(dimX, dimY, dimZ, dump);" ) );
			cont->addStmt( stmt::makeComment( "	return int3(dimX, dimY, dimZ);" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

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

		inline void writeImageAtomicAdd2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAdd(" + type + " image, int2 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAdd(" + type + " image, int3 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicAdd2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAdd(" + type + " image, int2 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAdd2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAdd(" + type + " image, int3 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAdd(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicMin2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMin(" + type + " image, int2 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMin(" + type + " image, int3 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicMin2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMin(" + type + " image, int2 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMin2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMin(" + type + " image, int3 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMin(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicMax2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMax(" + type + " image, int2 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicMax(" + type + " image, int3 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicMax2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMax(" + type + " image, int2 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicMax2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicMax(" + type + " image, int3 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedMax(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicAnd2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAnd(" + type + " image, int2 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicAnd(" + type + " image, int3 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicAnd2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAnd(" + type + " image, int2 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicAnd2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicAnd(" + type + " image, int3 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedAnd(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicOr2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicOr(" + type + " image, int2 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicOr(" + type + " image, int3 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicOr2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicOr(" + type + " image, int2 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicOr2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicOr(" + type + " image, int3 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedOr(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicXor2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicXor(" + type + " image, int2 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicXor(" + type + " image, int3 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicXor2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicXor(" + type + " image, int2 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicXor2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicXor(" + type + " image, int3 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedXor(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicExchange2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicExchange(" + type + " image, int2 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicExchange(" + type + " image, int3 P, int sample, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicExchange2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicExchange(" + type + " image, int2 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image.sample[sample][uint2(P)], data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicExchange2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicExchange(" + type + " image, int3 P, int sample, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedExchange(image.sample[sample][uint3(P)], data, res);" ) );
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

		inline void writeImageAtomicCompSwap2DMSU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicCompSwap(" + type + " image, int2 P, int sample, uint compare, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image.sample[sample][uint2(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap2DMSArrayU( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "uint SDW_imageAtomicCompSwap(" + type + " image, int3 P, int sample, uint compare, uint data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	uint res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image.sample[sample][uint3(P)], compare, data, res);" ) );
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

		inline void writeImageAtomicCompSwap2DMSI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicCompSwap(" + type + " image, int2 P, int sample, int compare, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image.sample[sample][uint2(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}

		inline void writeImageAtomicCompSwap2DMSArrayI( stmt::Container * container, std::string const & type )
		{
			auto cont = stmt::makeContainer();
			cont->addStmt( stmt::makeComment( "int SDW_imageAtomicCompSwap(" + type + " image, int3 P, int sample, int compare, int data)" ) );
			cont->addStmt( stmt::makeComment( "{" ) );
			cont->addStmt( stmt::makeComment( "	int res;" ) );
			cont->addStmt( stmt::makeComment( "	InterlockedCompareExchange(image.sample[sample][uint3(P)], compare, data, res);" ) );
			cont->addStmt( stmt::makeComment( "	return res;" ) );
			cont->addStmt( stmt::makeComment( "}" ) );
			container->addStmt( std::move( cont ) );
		}
	}

	void writeHlslImageAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config )
	{
		if ( config.requiresImageSizeBufferF )
		{
			details::writeImageSize1D( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageSizeBufferI )
		{
			details::writeImageSize1D( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageSizeBufferU )
		{
			details::writeImageSize1D( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageSize1DF )
		{
			details::writeImageSize1D( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageSize1DI )
		{
			details::writeImageSize1D( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageSize1DU )
		{
			details::writeImageSize1D( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageSize1DArrayF )
		{
			details::writeImageSize2D( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageSize1DArrayI )
		{
			details::writeImageSize2D( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageSize1DArrayU )
		{
			details::writeImageSize2D( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageSize2DF )
		{
			details::writeImageSize2D( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageSize2DRectF )
		{
			details::writeImageSize2D( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageSize2DI )
		{
			details::writeImageSize2D( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageSize2DRectI )
		{
			details::writeImageSize2D( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageSize2DU )
		{
			details::writeImageSize2D( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageSize2DRectU )
		{
			details::writeImageSize2D( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageSize2DArrayF )
		{
			details::writeImageSize3D( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageSize2DArrayI )
		{
			details::writeImageSize3D( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageSize2DArrayU )
		{
			details::writeImageSize3D( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageSize3DF )
		{
			details::writeImageSize3D( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageSize3DI )
		{
			details::writeImageSize3D( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageSize3DU )
		{
			details::writeImageSize3D( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageSizeCubeF )
		{
			details::writeImageSize2D( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageSizeCubeI )
		{
			details::writeImageSize2D( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageSizeCubeU )
		{
			details::writeImageSize2D( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageSizeCubeArrayF )
		{
			details::writeImageSize3D( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageSizeCubeArrayI )
		{
			details::writeImageSize3D( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageSizeCubeArrayU )
		{
			details::writeImageSize3D( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageSize2DMSF )
		{
			details::writeImageSize2DMS( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageSize2DMSI )
		{
			details::writeImageSize2DMS( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageSize2DMSU )
		{
			details::writeImageSize2DMS( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageSize2DMSArrayF )
		{
			details::writeImageSize2DMSArray( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageSize2DMSArrayI )
		{
			details::writeImageSize2DMSArray( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageSize2DMSArrayU )
		{
			details::writeImageSize2DMSArray( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageSamples2DMSF )
		{
			details::writeImageSamples2DMS( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageSamples2DMSI )
		{
			details::writeImageSamples2DMS( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageSamples2DMSU )
		{
			details::writeImageSamples2DMS( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageSamples2DMSArrayF )
		{
			details::writeImageSamples2DMSArray( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageSamples2DMSArrayI )
		{
			details::writeImageSamples2DMSArray( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageSamples2DMSArrayU )
		{
			details::writeImageSamples2DMSArray( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicAddBufferFU )
		{
			details::writeImageAtomicAdd1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicAddBufferIU )
		{
			details::writeImageAtomicAdd1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicAddBufferUU )
		{
			details::writeImageAtomicAdd1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicAdd1DFU )
		{
			details::writeImageAtomicAdd1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicAdd1DIU )
		{
			details::writeImageAtomicAdd1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicAdd1DUU )
		{
			details::writeImageAtomicAdd1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayFU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayIU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayUU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DFU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DRectFU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DIU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DRectIU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DUU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DRectUU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayFU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayIU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayUU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAdd3DFU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicAdd3DIU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicAdd3DUU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicAddCubeFU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAddCubeIU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAddCubeUU )
		{
			details::writeImageAtomicAdd2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAddCubeArrayFU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAddCubeArrayIU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAddCubeArrayUU )
		{
			details::writeImageAtomicAdd3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSFU )
		{
			details::writeImageAtomicAdd2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSIU )
		{
			details::writeImageAtomicAdd2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSUU )
		{
			details::writeImageAtomicAdd2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSArrayFU )
		{
			details::writeImageAtomicAdd2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSArrayIU )
		{
			details::writeImageAtomicAdd2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSArrayUU )
		{
			details::writeImageAtomicAdd2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicAddBufferFI )
		{
			details::writeImageAtomicAdd1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicAddBufferII )
		{
			details::writeImageAtomicAdd1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicAddBufferUI )
		{
			details::writeImageAtomicAdd1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicAdd1DFI )
		{
			details::writeImageAtomicAdd1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicAdd1DII )
		{
			details::writeImageAtomicAdd1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicAdd1DUI )
		{
			details::writeImageAtomicAdd1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayFI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayII )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicAdd1DArrayUI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DFI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DRectFI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DII )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DRectII )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DUI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DRectUI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayFI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayII )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DArrayUI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAdd3DFI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicAdd3DII )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicAdd3DUI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicAddCubeFI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAddCubeII )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAddCubeUI )
		{
			details::writeImageAtomicAdd2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAddCubeArrayFI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAddCubeArrayII )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAddCubeArrayUI )
		{
			details::writeImageAtomicAdd3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSFI )
		{
			details::writeImageAtomicAdd2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSII )
		{
			details::writeImageAtomicAdd2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSUI )
		{
			details::writeImageAtomicAdd2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSArrayFI )
		{
			details::writeImageAtomicAdd2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSArrayII )
		{
			details::writeImageAtomicAdd2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicAdd2DMSArrayUI )
		{
			details::writeImageAtomicAdd2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicMinBufferFU )
		{
			details::writeImageAtomicMin1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicMinBufferIU )
		{
			details::writeImageAtomicMin1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicMinBufferUU )
		{
			details::writeImageAtomicMin1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicMin1DFU )
		{
			details::writeImageAtomicMin1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicMin1DIU )
		{
			details::writeImageAtomicMin1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicMin1DUU )
		{
			details::writeImageAtomicMin1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicMin1DArrayFU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicMin1DArrayIU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicMin1DArrayUU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DFU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMin2DRectFU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMin2DIU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMin2DRectIU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMin2DUU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DRectUU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DArrayFU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMin2DArrayIU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMin2DArrayUU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMin3DFU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicMin3DIU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicMin3DUU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicMinCubeFU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMinCubeIU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMinCubeUU )
		{
			details::writeImageAtomicMin2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMinCubeArrayFU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMinCubeArrayIU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMinCubeArrayUU )
		{
			details::writeImageAtomicMin3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DMSFU )
		{
			details::writeImageAtomicMin2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicMin2DMSIU )
		{
			details::writeImageAtomicMin2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicMin2DMSUU )
		{
			details::writeImageAtomicMin2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DMSArrayFU )
		{
			details::writeImageAtomicMin2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicMin2DMSArrayIU )
		{
			details::writeImageAtomicMin2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicMin2DMSArrayUU )
		{
			details::writeImageAtomicMin2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicMinBufferFI )
		{
			details::writeImageAtomicMin1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicMinBufferII )
		{
			details::writeImageAtomicMin1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicMinBufferUI )
		{
			details::writeImageAtomicMin1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicMin1DFI )
		{
			details::writeImageAtomicMin1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicMin1DII )
		{
			details::writeImageAtomicMin1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicMin1DUI )
		{
			details::writeImageAtomicMin1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicMin1DArrayFI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicMin1DArrayII )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicMin1DArrayUI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DFI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMin2DRectFI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMin2DII )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMin2DRectII )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMin2DUI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DRectUI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DArrayFI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMin2DArrayII )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMin2DArrayUI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMin3DFI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicMin3DII )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicMin3DUI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicMinCubeFI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMinCubeII )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMinCubeUI )
		{
			details::writeImageAtomicMin2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMinCubeArrayFI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMinCubeArrayII )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMinCubeArrayUI )
		{
			details::writeImageAtomicMin3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DMSFI )
		{
			details::writeImageAtomicMin2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicMin2DMSII )
		{
			details::writeImageAtomicMin2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicMin2DMSUI )
		{
			details::writeImageAtomicMin2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicMin2DMSArrayFI )
		{
			details::writeImageAtomicMin2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicMin2DMSArrayII )
		{
			details::writeImageAtomicMin2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicMin2DMSArrayUI )
		{
			details::writeImageAtomicMin2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicMaxBufferFU )
		{
			details::writeImageAtomicMax1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicMaxBufferIU )
		{
			details::writeImageAtomicMax1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicMaxBufferUU )
		{
			details::writeImageAtomicMax1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicMax1DFU )
		{
			details::writeImageAtomicMax1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicMax1DIU )
		{
			details::writeImageAtomicMax1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicMax1DUU )
		{
			details::writeImageAtomicMax1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicMax1DArrayFU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicMax1DArrayIU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicMax1DArrayUU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DFU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMax2DRectFU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMax2DIU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMax2DRectIU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMax2DUU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DRectUU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DArrayFU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMax2DArrayIU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMax2DArrayUU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMax3DFU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicMax3DIU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicMax3DUU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicMaxCubeFU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMaxCubeIU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMaxCubeUU )
		{
			details::writeImageAtomicMax2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMaxCubeArrayFU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMaxCubeArrayIU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMaxCubeArrayUU )
		{
			details::writeImageAtomicMax3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DMSFU )
		{
			details::writeImageAtomicMax2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicMax2DMSIU )
		{
			details::writeImageAtomicMax2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicMax2DMSUU )
		{
			details::writeImageAtomicMax2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DMSArrayFU )
		{
			details::writeImageAtomicMax2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicMax2DMSArrayIU )
		{
			details::writeImageAtomicMax2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicMax2DMSArrayUU )
		{
			details::writeImageAtomicMax2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicMaxBufferFI )
		{
			details::writeImageAtomicMax1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicMaxBufferII )
		{
			details::writeImageAtomicMax1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicMaxBufferUI )
		{
			details::writeImageAtomicMax1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicMax1DFI )
		{
			details::writeImageAtomicMax1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicMax1DII )
		{
			details::writeImageAtomicMax1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicMax1DUI )
		{
			details::writeImageAtomicMax1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicMax1DArrayFI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicMax1DArrayII )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicMax1DArrayUI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DFI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMax2DRectFI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicMax2DII )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMax2DRectII )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicMax2DUI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DRectUI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DArrayFI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMax2DArrayII )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMax2DArrayUI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMax3DFI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicMax3DII )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicMax3DUI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicMaxCubeFI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMaxCubeII )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMaxCubeUI )
		{
			details::writeImageAtomicMax2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMaxCubeArrayFI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicMaxCubeArrayII )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicMaxCubeArrayUI )
		{
			details::writeImageAtomicMax3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DMSFI )
		{
			details::writeImageAtomicMax2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicMax2DMSII )
		{
			details::writeImageAtomicMax2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicMax2DMSUI )
		{
			details::writeImageAtomicMax2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicMax2DMSArrayFI )
		{
			details::writeImageAtomicMax2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicMax2DMSArrayII )
		{
			details::writeImageAtomicMax2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicMax2DMSArrayUI )
		{
			details::writeImageAtomicMax2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicAndBufferFU )
		{
			details::writeImageAtomicAnd1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicAndBufferIU )
		{
			details::writeImageAtomicAnd1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicAndBufferUU )
		{
			details::writeImageAtomicAnd1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicAnd1DFU )
		{
			details::writeImageAtomicAnd1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicAnd1DIU )
		{
			details::writeImageAtomicAnd1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicAnd1DUU )
		{
			details::writeImageAtomicAnd1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayFU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayIU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayUU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DFU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DRectFU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DIU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DRectIU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DUU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DRectUU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayFU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayIU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayUU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAnd3DFU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicAnd3DIU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicAnd3DUU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicAndCubeFU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAndCubeIU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAndCubeUU )
		{
			details::writeImageAtomicAnd2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAndCubeArrayFU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAndCubeArrayIU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAndCubeArrayUU )
		{
			details::writeImageAtomicAnd3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSFU )
		{
			details::writeImageAtomicAnd2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSIU )
		{
			details::writeImageAtomicAnd2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSUU )
		{
			details::writeImageAtomicAnd2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSArrayFU )
		{
			details::writeImageAtomicAnd2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSArrayIU )
		{
			details::writeImageAtomicAnd2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSArrayUU )
		{
			details::writeImageAtomicAnd2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicAndBufferFI )
		{
			details::writeImageAtomicAnd1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicAndBufferII )
		{
			details::writeImageAtomicAnd1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicAndBufferUI )
		{
			details::writeImageAtomicAnd1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicAnd1DFI )
		{
			details::writeImageAtomicAnd1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicAnd1DII )
		{
			details::writeImageAtomicAnd1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicAnd1DUI )
		{
			details::writeImageAtomicAnd1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayFI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayII )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicAnd1DArrayUI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DFI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DRectFI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DII )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DRectII )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DUI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DRectUI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayFI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayII )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DArrayUI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAnd3DFI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicAnd3DII )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicAnd3DUI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicAndCubeFI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAndCubeII )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAndCubeUI )
		{
			details::writeImageAtomicAnd2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAndCubeArrayFI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicAndCubeArrayII )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicAndCubeArrayUI )
		{
			details::writeImageAtomicAnd3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSFI )
		{
			details::writeImageAtomicAnd2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSII )
		{
			details::writeImageAtomicAnd2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSUI )
		{
			details::writeImageAtomicAnd2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSArrayFI )
		{
			details::writeImageAtomicAnd2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSArrayII )
		{
			details::writeImageAtomicAnd2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicAnd2DMSArrayUI )
		{
			details::writeImageAtomicAnd2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicOrBufferFU )
		{
			details::writeImageAtomicOr1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicOrBufferIU )
		{
			details::writeImageAtomicOr1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicOrBufferUU )
		{
			details::writeImageAtomicOr1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicOr1DFU )
		{
			details::writeImageAtomicOr1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicOr1DIU )
		{
			details::writeImageAtomicOr1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicOr1DUU )
		{
			details::writeImageAtomicOr1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicOr1DArrayFU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicOr1DArrayIU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicOr1DArrayUU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DFU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicOr2DRectFU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicOr2DIU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicOr2DRectIU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicOr2DUU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DRectUU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DArrayFU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicOr2DArrayIU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicOr2DArrayUU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOr3DFU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicOr3DIU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicOr3DUU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicOrCubeFU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicOrCubeIU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicOrCubeUU )
		{
			details::writeImageAtomicOr2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOrCubeArrayFU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicOrCubeArrayIU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicOrCubeArrayUU )
		{
			details::writeImageAtomicOr3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DMSFU )
		{
			details::writeImageAtomicOr2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicOr2DMSIU )
		{
			details::writeImageAtomicOr2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicOr2DMSUU )
		{
			details::writeImageAtomicOr2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DMSArrayFU )
		{
			details::writeImageAtomicOr2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicOr2DMSArrayIU )
		{
			details::writeImageAtomicOr2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicOr2DMSArrayUU )
		{
			details::writeImageAtomicOr2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicOrBufferFI )
		{
			details::writeImageAtomicOr1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicOrBufferII )
		{
			details::writeImageAtomicOr1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicOrBufferUI )
		{
			details::writeImageAtomicOr1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicOr1DFI )
		{
			details::writeImageAtomicOr1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicOr1DII )
		{
			details::writeImageAtomicOr1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicOr1DUI )
		{
			details::writeImageAtomicOr1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicOr1DArrayFI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicOr1DArrayII )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicOr1DArrayUI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DFI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicOr2DRectFI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicOr2DII )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicOr2DRectII )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicOr2DUI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DRectUI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DArrayFI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicOr2DArrayII )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicOr2DArrayUI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOr3DFI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicOr3DII )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicOr3DUI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicOrCubeFI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicOrCubeII )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicOrCubeUI )
		{
			details::writeImageAtomicOr2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOrCubeArrayFI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicOrCubeArrayII )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicOrCubeArrayUI )
		{
			details::writeImageAtomicOr3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DMSFI )
		{
			details::writeImageAtomicOr2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicOr2DMSII )
		{
			details::writeImageAtomicOr2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicOr2DMSUI )
		{
			details::writeImageAtomicOr2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicOr2DMSArrayFI )
		{
			details::writeImageAtomicOr2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicOr2DMSArrayII )
		{
			details::writeImageAtomicOr2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicOr2DMSArrayUI )
		{
			details::writeImageAtomicOr2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicXorBufferFU )
		{
			details::writeImageAtomicXor1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicXorBufferIU )
		{
			details::writeImageAtomicXor1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicXorBufferUU )
		{
			details::writeImageAtomicXor1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicXor1DFU )
		{
			details::writeImageAtomicXor1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicXor1DIU )
		{
			details::writeImageAtomicXor1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicXor1DUU )
		{
			details::writeImageAtomicXor1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicXor1DArrayFU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicXor1DArrayIU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicXor1DArrayUU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DFU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicXor2DRectFU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicXor2DIU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicXor2DRectIU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicXor2DUU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DRectUU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DArrayFU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicXor2DArrayIU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicXor2DArrayUU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXor3DFU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicXor3DIU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicXor3DUU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicXorCubeFU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicXorCubeIU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicXorCubeUU )
		{
			details::writeImageAtomicXor2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXorCubeArrayFU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicXorCubeArrayIU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicXorCubeArrayUU )
		{
			details::writeImageAtomicXor3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DMSFU )
		{
			details::writeImageAtomicXor2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicXor2DMSIU )
		{
			details::writeImageAtomicXor2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicXor2DMSUU )
		{
			details::writeImageAtomicXor2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DMSArrayFU )
		{
			details::writeImageAtomicXor2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicXor2DMSArrayIU )
		{
			details::writeImageAtomicXor2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicXor2DMSArrayUU )
		{
			details::writeImageAtomicXor2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicXorBufferFI )
		{
			details::writeImageAtomicXor1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicXorBufferII )
		{
			details::writeImageAtomicXor1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicXorBufferUI )
		{
			details::writeImageAtomicXor1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicXor1DFI )
		{
			details::writeImageAtomicXor1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicXor1DII )
		{
			details::writeImageAtomicXor1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicXor1DUI )
		{
			details::writeImageAtomicXor1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicXor1DArrayFI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicXor1DArrayII )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicXor1DArrayUI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DFI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicXor2DRectFI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicXor2DII )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicXor2DRectII )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicXor2DUI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DRectUI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DArrayFI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicXor2DArrayII )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicXor2DArrayUI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXor3DFI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicXor3DII )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicXor3DUI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicXorCubeFI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicXorCubeII )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicXorCubeUI )
		{
			details::writeImageAtomicXor2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXorCubeArrayFI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicXorCubeArrayII )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicXorCubeArrayUI )
		{
			details::writeImageAtomicXor3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DMSFI )
		{
			details::writeImageAtomicXor2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicXor2DMSII )
		{
			details::writeImageAtomicXor2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicXor2DMSUI )
		{
			details::writeImageAtomicXor2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicXor2DMSArrayFI )
		{
			details::writeImageAtomicXor2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicXor2DMSArrayII )
		{
			details::writeImageAtomicXor2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicXor2DMSArrayUI )
		{
			details::writeImageAtomicXor2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchangeBufferFU )
		{
			details::writeImageAtomicExchange1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicExchangeBufferIU )
		{
			details::writeImageAtomicExchange1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicExchangeBufferUU )
		{
			details::writeImageAtomicExchange1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicExchange1DFU )
		{
			details::writeImageAtomicExchange1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicExchange1DIU )
		{
			details::writeImageAtomicExchange1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicExchange1DUU )
		{
			details::writeImageAtomicExchange1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayFU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayIU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayUU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DFU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DRectFU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DIU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DRectIU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DUU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DRectUU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayFU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayIU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayUU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchange3DFU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicExchange3DIU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicExchange3DUU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeFU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeIU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeUU )
		{
			details::writeImageAtomicExchange2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeArrayFU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeArrayIU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeArrayUU )
		{
			details::writeImageAtomicExchange3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSFU )
		{
			details::writeImageAtomicExchange2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSIU )
		{
			details::writeImageAtomicExchange2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSUU )
		{
			details::writeImageAtomicExchange2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSArrayFU )
		{
			details::writeImageAtomicExchange2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSArrayIU )
		{
			details::writeImageAtomicExchange2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSArrayUU )
		{
			details::writeImageAtomicExchange2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchangeBufferFI )
		{
			details::writeImageAtomicExchange1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicExchangeBufferII )
		{
			details::writeImageAtomicExchange1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicExchangeBufferUI )
		{
			details::writeImageAtomicExchange1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicExchange1DFI )
		{
			details::writeImageAtomicExchange1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicExchange1DII )
		{
			details::writeImageAtomicExchange1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicExchange1DUI )
		{
			details::writeImageAtomicExchange1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayFI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayII )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchange1DArrayUI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DFI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DRectFI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DII )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DRectII )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DUI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DRectUI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayFI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayII )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DArrayUI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchange3DFI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicExchange3DII )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicExchange3DUI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeFI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeII )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeUI )
		{
			details::writeImageAtomicExchange2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeArrayFI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeArrayII )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicExchangeCubeArrayUI )
		{
			details::writeImageAtomicExchange3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSFI )
		{
			details::writeImageAtomicExchange2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSII )
		{
			details::writeImageAtomicExchange2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSUI )
		{
			details::writeImageAtomicExchange2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSArrayFI )
		{
			details::writeImageAtomicExchange2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSArrayII )
		{
			details::writeImageAtomicExchange2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicExchange2DMSArrayUI )
		{
			details::writeImageAtomicExchange2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferFU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferIU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferUU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DFU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DIU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DUU )
		{
			details::writeImageAtomicCompSwap1DU( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayFU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayIU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayUU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DFU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DRectFU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DIU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DRectIU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DUU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DRectUU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayFU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayIU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayUU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap3DFU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap3DIU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap3DUU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeFU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeIU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeUU )
		{
			details::writeImageAtomicCompSwap2DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeArrayFU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeArrayIU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeArrayUU )
		{
			details::writeImageAtomicCompSwap3DU( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSFU )
		{
			details::writeImageAtomicCompSwap2DMSU( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSIU )
		{
			details::writeImageAtomicCompSwap2DMSU( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSUU )
		{
			details::writeImageAtomicCompSwap2DMSU( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSArrayFU )
		{
			details::writeImageAtomicCompSwap2DMSArrayU( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSArrayIU )
		{
			details::writeImageAtomicCompSwap2DMSArrayU( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSArrayUU )
		{
			details::writeImageAtomicCompSwap2DMSArrayU( container, "Texture2DMSArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferFI )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWBuffer<float4>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferII )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWBuffer<int4>" );
		}
		if ( config.requiresImageAtomicCompSwapBufferUI )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWBuffer<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DFI )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWTexture1D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DII )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWTexture1D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DUI )
		{
			details::writeImageAtomicCompSwap1DI( container, "RWTexture1D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayFI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture1DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayII )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture1DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap1DArrayUI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture1DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DFI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DRectFI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DII )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DRectII )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DUI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DRectUI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayFI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayII )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DArrayUI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap3DFI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture3D<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap3DII )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture3D<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap3DUI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture3D<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeFI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeII )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeUI )
		{
			details::writeImageAtomicCompSwap2DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeArrayFI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture2DArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeArrayII )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture2DArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwapCubeArrayUI )
		{
			details::writeImageAtomicCompSwap3DI( container, "RWTexture2DArray<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSFI )
		{
			details::writeImageAtomicCompSwap2DMSI( container, "Texture2DMS<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSII )
		{
			details::writeImageAtomicCompSwap2DMSI( container, "Texture2DMS<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSUI )
		{
			details::writeImageAtomicCompSwap2DMSI( container, "Texture2DMS<uint4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSArrayFI )
		{
			details::writeImageAtomicCompSwap2DMSArrayI( container, "Texture2DMSArray<float4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSArrayII )
		{
			details::writeImageAtomicCompSwap2DMSArrayI( container, "Texture2DMSArray<int4>" );
		}
		if ( config.requiresImageAtomicCompSwap2DMSArrayUI )
		{
			details::writeImageAtomicCompSwap2DMSArrayI( container, "Texture2DMSArray<uint4>" );
		}
	}
}
