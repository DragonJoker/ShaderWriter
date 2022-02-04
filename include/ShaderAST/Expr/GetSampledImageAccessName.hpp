/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprGetSampledImageAccessName_H___
#define ___AST_ExprGetSampledImageAccessName_H___
#pragma once

#include "EnumSampledImageAccess.hpp"

#include <string>

namespace ast::expr
{
	inline std::string getName( SampledImageAccess value )
	{
		std::string result;

		switch ( value )
		{
		case SampledImageAccess::eUndefined:
			result = "UNDEFINED";
			break;

		case SampledImageAccess::eCount:
			result = "COUNT";
			break;

		case SampledImageAccess::eInvalid:
			result = "INVALID";
			break;

	// Texel Lookup Functions
		case SampledImageAccess::eSample1DF:
			result = "SAMPLE1DF";
			break;

		case SampledImageAccess::eSample1DFBias:
			result = "SAMPLE1DFBIAS";
			break;

		case SampledImageAccess::eSample2DF:
			result = "SAMPLE2DF";
			break;

		case SampledImageAccess::eSample2DFBias:
			result = "SAMPLE2DFBIAS";
			break;

		case SampledImageAccess::eSample3DF:
			result = "SAMPLE3DF";
			break;

		case SampledImageAccess::eSample3DFBias:
			result = "SAMPLE3DFBIAS";
			break;

		case SampledImageAccess::eSampleCubeF:
			result = "SAMPLECUBEF";
			break;

		case SampledImageAccess::eSampleCubeFBias:
			result = "SAMPLECUBEFBIAS";
			break;

		case SampledImageAccess::eSample1DArrayF:
			result = "SAMPLE1DARRAYF";
			break;

		case SampledImageAccess::eSample1DArrayFBias:
			result = "SAMPLE1DARRAYFBIAS";
			break;

		case SampledImageAccess::eSample2DArrayF:
			result = "SAMPLE2DARRAYF";
			break;

		case SampledImageAccess::eSample2DArrayFBias:
			result = "SAMPLE2DARRAYFBIAS";
			break;

		case SampledImageAccess::eSampleCubeArrayF:
			result = "SAMPLECUBEARRAYF";
			break;

		case SampledImageAccess::eSampleCubeArrayFBias:
			result = "SAMPLECUBEARRAYFBIAS";
			break;

		case SampledImageAccess::eSample2DRectF:
			result = "SAMPLE2DRECTF";
			break;

		case SampledImageAccess::eSample1DI:
			result = "SAMPLE1DI";
			break;

		case SampledImageAccess::eSample1DIBias:
			result = "SAMPLE1DIBIAS";
			break;

		case SampledImageAccess::eSample2DI:
			result = "SAMPLE2DI";
			break;

		case SampledImageAccess::eSample2DIBias:
			result = "SAMPLE2DIBIAS";
			break;

		case SampledImageAccess::eSample3DI:
			result = "SAMPLE3DI";
			break;

		case SampledImageAccess::eSample3DIBias:
			result = "SAMPLE3DIBIAS";
			break;

		case SampledImageAccess::eSampleCubeI:
			result = "SAMPLECUBEI";
			break;

		case SampledImageAccess::eSampleCubeIBias:
			result = "SAMPLECUBEIBIAS";
			break;

		case SampledImageAccess::eSample1DArrayI:
			result = "SAMPLE1DARRAYI";
			break;

		case SampledImageAccess::eSample1DArrayIBias:
			result = "SAMPLE1DARRAYIBIAS";
			break;

		case SampledImageAccess::eSample2DArrayI:
			result = "SAMPLE2DARRAYI";
			break;

		case SampledImageAccess::eSample2DArrayIBias:
			result = "SAMPLE2DARRAYIBIAS";
			break;

		case SampledImageAccess::eSampleCubeArrayI:
			result = "SAMPLECUBEARRAYI";
			break;

		case SampledImageAccess::eSampleCubeArrayIBias:
			result = "SAMPLECUBEARRAYIBIAS";
			break;

		case SampledImageAccess::eSample2DRectI:
			result = "SAMPLE2DRECTI";
			break;

		case SampledImageAccess::eSample1DU:
			result = "SAMPLE1DU";
			break;

		case SampledImageAccess::eSample1DUBias:
			result = "SAMPLE1DUBIAS";
			break;

		case SampledImageAccess::eSample2DU:
			result = "SAMPLE2DU";
			break;

		case SampledImageAccess::eSample2DUBias:
			result = "SAMPLE2DUBIAS";
			break;

		case SampledImageAccess::eSample3DU:
			result = "SAMPLE3DU";
			break;

		case SampledImageAccess::eSample3DUBias:
			result = "SAMPLE3DUBIAS";
			break;

		case SampledImageAccess::eSampleCubeU:
			result = "SAMPLECUBEU";
			break;

		case SampledImageAccess::eSampleCubeUBias:
			result = "SAMPLECUBEUBIAS";
			break;

		case SampledImageAccess::eSample1DArrayU:
			result = "SAMPLE1DARRAYU";
			break;

		case SampledImageAccess::eSample1DArrayUBias:
			result = "SAMPLE1DARRAYUBIAS";
			break;

		case SampledImageAccess::eSample2DArrayU:
			result = "SAMPLE2DARRAYU";
			break;

		case SampledImageAccess::eSample2DArrayUBias:
			result = "SAMPLE2DARRAYUBIAS";
			break;

		case SampledImageAccess::eSampleCubeArrayU:
			result = "SAMPLECUBEARRAYU";
			break;

		case SampledImageAccess::eSampleCubeArrayUBias:
			result = "SAMPLECUBEARRAYUBIAS";
			break;

		case SampledImageAccess::eSample2DRectU:
			result = "SAMPLE2DRECTU";
			break;

		case SampledImageAccess::eSampleProj1DF2:
			result = "SAMPLEPROJ1DF2";
			break;

		case SampledImageAccess::eSampleProj1DF2Bias:
			result = "SAMPLEPROJ1DF2BIAS";
			break;

		case SampledImageAccess::eSampleProj1DF4:
			result = "SAMPLEPROJ1DF4";
			break;

		case SampledImageAccess::eSampleProj1DF4Bias:
			result = "SAMPLEPROJ1DF4BIAS";
			break;

		case SampledImageAccess::eSampleProj2DF3:
			result = "SAMPLEPROJ2DF3";
			break;

		case SampledImageAccess::eSampleProj2DF3Bias:
			result = "SAMPLEPROJ2DF3BIAS";
			break;

		case SampledImageAccess::eSampleProj2DF4:
			result = "SAMPLEPROJ2DF4";
			break;

		case SampledImageAccess::eSampleProj2DF4Bias:
			result = "SAMPLEPROJ2DF4BIAS";
			break;

		case SampledImageAccess::eSampleProj3DF:
			result = "SAMPLEPROJ3DF";
			break;

		case SampledImageAccess::eSampleProj3DFBias:
			result = "SAMPLEPROJ3DFBIAS";
			break;

		case SampledImageAccess::eSampleProj2DRectF3:
			result = "SAMPLEPROJ2DRECTF3";
			break;

		case SampledImageAccess::eSampleProj2DRectF4:
			result = "SAMPLEPROJ2DRECTF4";
			break;

		case SampledImageAccess::eSampleProj1DI2:
			result = "SAMPLEPROJ1DI2";
			break;

		case SampledImageAccess::eSampleProj1DI2Bias:
			result = "SAMPLEPROJ1DI2BIAS";
			break;

		case SampledImageAccess::eSampleProj1DI4:
			result = "SAMPLEPROJ1DI4";
			break;

		case SampledImageAccess::eSampleProj1DI4Bias:
			result = "SAMPLEPROJ1DI4BIAS";
			break;

		case SampledImageAccess::eSampleProj2DI3:
			result = "SAMPLEPROJ2DI3";
			break;

		case SampledImageAccess::eSampleProj2DI3Bias:
			result = "SAMPLEPROJ2DI3BIAS";
			break;

		case SampledImageAccess::eSampleProj2DI4:
			result = "SAMPLEPROJ2DI4";
			break;

		case SampledImageAccess::eSampleProj2DI4Bias:
			result = "SAMPLEPROJ2DI4BIAS";
			break;

		case SampledImageAccess::eSampleProj3DI:
			result = "SAMPLEPROJ3DI";
			break;

		case SampledImageAccess::eSampleProj3DIBias:
			result = "SAMPLEPROJ3DIBIAS";
			break;

		case SampledImageAccess::eSampleProj2DRectI3:
			result = "SAMPLEPROJ2DRECTI3";
			break;

		case SampledImageAccess::eSampleProj2DRectI4:
			result = "SAMPLEPROJ2DRECTI4";
			break;

		case SampledImageAccess::eSampleProj1DU2:
			result = "SAMPLEPROJ1DU2";
			break;

		case SampledImageAccess::eSampleProj1DU2Bias:
			result = "SAMPLEPROJ1DU2BIAS";
			break;

		case SampledImageAccess::eSampleProj1DU4:
			result = "SAMPLEPROJ1DU4";
			break;

		case SampledImageAccess::eSampleProj1DU4Bias:
			result = "SAMPLEPROJ1DU4BIAS";
			break;

		case SampledImageAccess::eSampleProj2DU3:
			result = "SAMPLEPROJ2DU3";
			break;

		case SampledImageAccess::eSampleProj2DU3Bias:
			result = "SAMPLEPROJ2DU3BIAS";
			break;

		case SampledImageAccess::eSampleProj2DU4:
			result = "SAMPLEPROJ2DU4";
			break;

		case SampledImageAccess::eSampleProj2DU4Bias:
			result = "SAMPLEPROJ2DU4BIAS";
			break;

		case SampledImageAccess::eSampleProj3DU:
			result = "SAMPLEPROJ3DU";
			break;

		case SampledImageAccess::eSampleProj3DUBias:
			result = "SAMPLEPROJ3DUBIAS";
			break;

		case SampledImageAccess::eSampleProj2DRectU3:
			result = "SAMPLEPROJ2DRECTU3";
			break;

		case SampledImageAccess::eSampleProj2DRectU4:
			result = "SAMPLEPROJ2DRECTU4";
			break;

		case SampledImageAccess::eSampleLod1DF:
			result = "SAMPLELOD1DF";
			break;

		case SampledImageAccess::eSampleLod2DF:
			result = "SAMPLELOD2DF";
			break;

		case SampledImageAccess::eSampleLod3DF:
			result = "SAMPLELOD3DF";
			break;

		case SampledImageAccess::eSampleLodCubeF:
			result = "SAMPLELODCUBEF";
			break;

		case SampledImageAccess::eSampleLod1DArrayF:
			result = "SAMPLELOD1DARRAYF";
			break;

		case SampledImageAccess::eSampleLod2DArrayF:
			result = "SAMPLELOD2DARRAYF";
			break;

		case SampledImageAccess::eSampleLodCubeArrayF:
			result = "SAMPLELODCUBEARRAYF";
			break;

		case SampledImageAccess::eSampleLod1DI:
			result = "SAMPLELOD1DI";
			break;

		case SampledImageAccess::eSampleLod2DI:
			result = "SAMPLELOD2DI";
			break;

		case SampledImageAccess::eSampleLod3DI:
			result = "SAMPLELOD3DI";
			break;

		case SampledImageAccess::eSampleLodCubeI:
			result = "SAMPLELODCUBEI";
			break;

		case SampledImageAccess::eSampleLod1DArrayI:
			result = "SAMPLELOD1DARRAYI";
			break;

		case SampledImageAccess::eSampleLod2DArrayI:
			result = "SAMPLELOD2DARRAYI";
			break;

		case SampledImageAccess::eSampleLodCubeArrayI:
			result = "SAMPLELODCUBEARRAYI";
			break;

		case SampledImageAccess::eSampleLod1DU:
			result = "SAMPLELOD1DU";
			break;

		case SampledImageAccess::eSampleLod2DU:
			result = "SAMPLELOD2DU";
			break;

		case SampledImageAccess::eSampleLod3DU:
			result = "SAMPLELOD3DU";
			break;

		case SampledImageAccess::eSampleLodCubeU:
			result = "SAMPLELODCUBEU";
			break;

		case SampledImageAccess::eSampleLod1DArrayU:
			result = "SAMPLELOD1DARRAYU";
			break;

		case SampledImageAccess::eSampleLod2DArrayU:
			result = "SAMPLELOD2DARRAYU";
			break;

		case SampledImageAccess::eSampleLodCubeArrayU:
			result = "SAMPLELODCUBEARRAYU";
			break;

		case SampledImageAccess::eSampleOffset1DF:
			result = "SAMPLEOFFSET1DF";
			break;

		case SampledImageAccess::eSampleOffset1DFBias:
			result = "SAMPLEOFFSET1DFBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DF:
			result = "SAMPLEOFFSET2DF";
			break;

		case SampledImageAccess::eSampleOffset2DFBias:
			result = "SAMPLEOFFSET2DFBIAS";
			break;

		case SampledImageAccess::eSampleOffset3DF:
			result = "SAMPLEOFFSET3DF";
			break;

		case SampledImageAccess::eSampleOffset3DFBias:
			result = "SAMPLEOFFSET3DFBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DRectF:
			result = "SAMPLEOFFSET2DRECTF";
			break;

		case SampledImageAccess::eSampleOffset1DArrayF:
			result = "SAMPLEOFFSET1DARRAYF";
			break;

		case SampledImageAccess::eSampleOffset1DArrayFBias:
			result = "SAMPLEOFFSET1DARRAYFBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DArrayF:
			result = "SAMPLEOFFSET2DARRAYF";
			break;

		case SampledImageAccess::eSampleOffset2DArrayFBias:
			result = "SAMPLEOFFSET2DARRAYFBIAS";
			break;

		case SampledImageAccess::eSampleOffset1DI:
			result = "SAMPLEOFFSET1DI";
			break;

		case SampledImageAccess::eSampleOffset1DIBias:
			result = "SAMPLEOFFSET1DIBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DI:
			result = "SAMPLEOFFSET2DI";
			break;

		case SampledImageAccess::eSampleOffset2DIBias:
			result = "SAMPLEOFFSET2DIBIAS";
			break;

		case SampledImageAccess::eSampleOffset3DI:
			result = "SAMPLEOFFSET3DI";
			break;

		case SampledImageAccess::eSampleOffset3DIBias:
			result = "SAMPLEOFFSET3DIBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DRectI:
			result = "SAMPLEOFFSET2DRECTI";
			break;

		case SampledImageAccess::eSampleOffset1DArrayI:
			result = "SAMPLEOFFSET1DARRAYI";
			break;

		case SampledImageAccess::eSampleOffset1DArrayIBias:
			result = "SAMPLEOFFSET1DARRAYIBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DArrayI:
			result = "SAMPLEOFFSET2DARRAYI";
			break;

		case SampledImageAccess::eSampleOffset2DArrayIBias:
			result = "SAMPLEOFFSET2DARRAYIBIAS";
			break;

		case SampledImageAccess::eSampleOffset1DU:
			result = "SAMPLEOFFSET1DU";
			break;

		case SampledImageAccess::eSampleOffset1DUBias:
			result = "SAMPLEOFFSET1DUBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DU:
			result = "SAMPLEOFFSET2DU";
			break;

		case SampledImageAccess::eSampleOffset2DUBias:
			result = "SAMPLEOFFSET2DUBIAS";
			break;

		case SampledImageAccess::eSampleOffset3DU:
			result = "SAMPLEOFFSET3DU";
			break;

		case SampledImageAccess::eSampleOffset3DUBias:
			result = "SAMPLEOFFSET3DUBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DRectU:
			result = "SAMPLEOFFSET2DRECTU";
			break;

		case SampledImageAccess::eSampleOffset1DArrayU:
			result = "SAMPLEOFFSET1DARRAYU";
			break;

		case SampledImageAccess::eSampleOffset1DArrayUBias:
			result = "SAMPLEOFFSET1DARRAYUBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DArrayU:
			result = "SAMPLEOFFSET2DARRAYU";
			break;

		case SampledImageAccess::eSampleOffset2DArrayUBias:
			result = "SAMPLEOFFSET2DARRAYUBIAS";
			break;

		case SampledImageAccess::eSampleProjOffset1DF2:
			result = "SAMPLEPROJOFFSET1DF2";
			break;

		case SampledImageAccess::eSampleProjOffset1DF2Bias:
			result = "SAMPLEPROJOFFSET1DF2BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset1DF4:
			result = "SAMPLEPROJOFFSET1DF4";
			break;

		case SampledImageAccess::eSampleProjOffset1DF4Bias:
			result = "SAMPLEPROJOFFSET1DF4BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DF3:
			result = "SAMPLEPROJOFFSET2DF3";
			break;

		case SampledImageAccess::eSampleProjOffset2DF3Bias:
			result = "SAMPLEPROJOFFSET2DF3BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DF4:
			result = "SAMPLEPROJOFFSET2DF4";
			break;

		case SampledImageAccess::eSampleProjOffset2DF4Bias:
			result = "SAMPLEPROJOFFSET2DF4BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset3DF:
			result = "SAMPLEPROJOFFSET3DF";
			break;

		case SampledImageAccess::eSampleProjOffset3DFBias:
			result = "SAMPLEPROJOFFSET3DFBIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DRectF3:
			result = "SAMPLEPROJOFFSET2DRECTF3";
			break;

		case SampledImageAccess::eSampleProjOffset2DRectF4:
			result = "SAMPLEPROJOFFSET2DRECTF4";
			break;

		case SampledImageAccess::eSampleProjOffset1DI2:
			result = "SAMPLEPROJOFFSET1DI2";
			break;

		case SampledImageAccess::eSampleProjOffset1DI2Bias:
			result = "SAMPLEPROJOFFSET1DI2BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset1DI4:
			result = "SAMPLEPROJOFFSET1DI4";
			break;

		case SampledImageAccess::eSampleProjOffset1DI4Bias:
			result = "SAMPLEPROJOFFSET1DI4BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DI3:
			result = "SAMPLEPROJOFFSET2DI3";
			break;

		case SampledImageAccess::eSampleProjOffset2DI3Bias:
			result = "SAMPLEPROJOFFSET2DI3BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DI4:
			result = "SAMPLEPROJOFFSET2DI4";
			break;

		case SampledImageAccess::eSampleProjOffset2DI4Bias:
			result = "SAMPLEPROJOFFSET2DI4BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset3DI:
			result = "SAMPLEPROJOFFSET3DI";
			break;

		case SampledImageAccess::eSampleProjOffset3DIBias:
			result = "SAMPLEPROJOFFSET3DIBIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DRectI3:
			result = "SAMPLEPROJOFFSET2DRECTI3";
			break;

		case SampledImageAccess::eSampleProjOffset2DRectI4:
			result = "SAMPLEPROJOFFSET2DRECTI4";
			break;

		case SampledImageAccess::eSampleProjOffset1DU2:
			result = "SAMPLEPROJOFFSET1DU2";
			break;

		case SampledImageAccess::eSampleProjOffset1DU2Bias:
			result = "SAMPLEPROJOFFSET1DU2BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset1DU4:
			result = "SAMPLEPROJOFFSET1DU4";
			break;

		case SampledImageAccess::eSampleProjOffset1DU4Bias:
			result = "SAMPLEPROJOFFSET1DU4BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DU3:
			result = "SAMPLEPROJOFFSET2DU3";
			break;

		case SampledImageAccess::eSampleProjOffset2DU3Bias:
			result = "SAMPLEPROJOFFSET2DU3BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DU4:
			result = "SAMPLEPROJOFFSET2DU4";
			break;

		case SampledImageAccess::eSampleProjOffset2DU4Bias:
			result = "SAMPLEPROJOFFSET2DU4BIAS";
			break;

		case SampledImageAccess::eSampleProjOffset3DU:
			result = "SAMPLEPROJOFFSET3DU";
			break;

		case SampledImageAccess::eSampleProjOffset3DUBias:
			result = "SAMPLEPROJOFFSET3DUBIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DRectU3:
			result = "SAMPLEPROJOFFSET2DRECTU3";
			break;

		case SampledImageAccess::eSampleProjOffset2DRectU4:
			result = "SAMPLEPROJOFFSET2DRECTU4";
			break;

		case SampledImageAccess::eSampleLodOffset1DF:
			result = "SAMPLELODOFFSET1DF";
			break;

		case SampledImageAccess::eSampleLodOffset2DF:
			result = "SAMPLELODOFFSET2DF";
			break;

		case SampledImageAccess::eSampleLodOffset3DF:
			result = "SAMPLELODOFFSET3DF";
			break;

		case SampledImageAccess::eSampleLodOffset1DArrayF:
			result = "SAMPLELODOFFSET1DARRAYF";
			break;

		case SampledImageAccess::eSampleLodOffset2DArrayF:
			result = "SAMPLELODOFFSET2DARRAYF";
			break;

		case SampledImageAccess::eSampleLodOffset1DI:
			result = "SAMPLELODOFFSET1DI";
			break;

		case SampledImageAccess::eSampleLodOffset2DI:
			result = "SAMPLELODOFFSET2DI";
			break;

		case SampledImageAccess::eSampleLodOffset3DI:
			result = "SAMPLELODOFFSET3DI";
			break;

		case SampledImageAccess::eSampleLodOffset1DArrayI:
			result = "SAMPLELODOFFSET1DARRAYI";
			break;

		case SampledImageAccess::eSampleLodOffset2DArrayI:
			result = "SAMPLELODOFFSET2DARRAYI";
			break;

		case SampledImageAccess::eSampleLodOffset1DU:
			result = "SAMPLELODOFFSET1DU";
			break;

		case SampledImageAccess::eSampleLodOffset2DU:
			result = "SAMPLELODOFFSET2DU";
			break;

		case SampledImageAccess::eSampleLodOffset3DU:
			result = "SAMPLELODOFFSET3DU";
			break;

		case SampledImageAccess::eSampleLodOffset1DArrayU:
			result = "SAMPLELODOFFSET1DARRAYU";
			break;

		case SampledImageAccess::eSampleLodOffset2DArrayU:
			result = "SAMPLELODOFFSET2DARRAYU";
			break;

		case SampledImageAccess::eSampleProjLod1DF2:
			result = "SAMPLEPROJLOD1DF2";
			break;

		case SampledImageAccess::eSampleProjLod1DF4:
			result = "SAMPLEPROJLOD1DF4";
			break;

		case SampledImageAccess::eSampleProjLod2DF3:
			result = "SAMPLEPROJLOD2DF3";
			break;

		case SampledImageAccess::eSampleProjLod2DF4:
			result = "SAMPLEPROJLOD2DF4";
			break;

		case SampledImageAccess::eSampleProjLod3DF:
			result = "SAMPLEPROJLOD3DF";
			break;

		case SampledImageAccess::eSampleProjLod1DI2:
			result = "SAMPLEPROJLOD1DI2";
			break;

		case SampledImageAccess::eSampleProjLod1DI4:
			result = "SAMPLEPROJLOD1DI4";
			break;

		case SampledImageAccess::eSampleProjLod2DI3:
			result = "SAMPLEPROJLOD2DI3";
			break;

		case SampledImageAccess::eSampleProjLod2DI4:
			result = "SAMPLEPROJLOD2DI4";
			break;

		case SampledImageAccess::eSampleProjLod3DI:
			result = "SAMPLEPROJLOD3DI";
			break;

		case SampledImageAccess::eSampleProjLod1DU2:
			result = "SAMPLEPROJLOD1DU2";
			break;

		case SampledImageAccess::eSampleProjLod1DU4:
			result = "SAMPLEPROJLOD1DU4";
			break;

		case SampledImageAccess::eSampleProjLod2DU3:
			result = "SAMPLEPROJLOD2DU3";
			break;

		case SampledImageAccess::eSampleProjLod2DU4:
			result = "SAMPLEPROJLOD2DU4";
			break;

		case SampledImageAccess::eSampleProjLod3DU:
			result = "SAMPLEPROJLOD3DU";
			break;

		case SampledImageAccess::eSampleProjLodOffset1DF2:
			result = "SAMPLEPROJLODOFFSET1DF2";
			break;

		case SampledImageAccess::eSampleProjLodOffset1DF4:
			result = "SAMPLEPROJLODOFFSET1DF4";
			break;

		case SampledImageAccess::eSampleProjLodOffset2DF3:
			result = "SAMPLEPROJLODOFFSET2DF3";
			break;

		case SampledImageAccess::eSampleProjLodOffset2DF4:
			result = "SAMPLEPROJLODOFFSET2DF4";
			break;

		case SampledImageAccess::eSampleProjLodOffset3DF:
			result = "SAMPLEPROJLODOFFSET3DF";
			break;

		case SampledImageAccess::eSampleProjLodOffset1DI2:
			result = "SAMPLEPROJLODOFFSET1DI2";
			break;

		case SampledImageAccess::eSampleProjLodOffset1DI4:
			result = "SAMPLEPROJLODOFFSET1DI4";
			break;

		case SampledImageAccess::eSampleProjLodOffset2DI3:
			result = "SAMPLEPROJLODOFFSET2DI3";
			break;

		case SampledImageAccess::eSampleProjLodOffset2DI4:
			result = "SAMPLEPROJLODOFFSET2DI4";
			break;

		case SampledImageAccess::eSampleProjLodOffset3DI:
			result = "SAMPLEPROJLODOFFSET3DI";
			break;

		case SampledImageAccess::eSampleProjLodOffset1DU2:
			result = "SAMPLEPROJLODOFFSET1DU2";
			break;

		case SampledImageAccess::eSampleProjLodOffset1DU4:
			result = "SAMPLEPROJLODOFFSET1DU4";
			break;

		case SampledImageAccess::eSampleProjLodOffset2DU3:
			result = "SAMPLEPROJLODOFFSET2DU3";
			break;

		case SampledImageAccess::eSampleProjLodOffset2DU4:
			result = "SAMPLEPROJLODOFFSET2DU4";
			break;

		case SampledImageAccess::eSampleProjLodOffset3DU:
			result = "SAMPLEPROJLODOFFSET3DU";
			break;

		case SampledImageAccess::eSampleGrad1DF:
			result = "SAMPLEGRAD1DF";
			break;

		case SampledImageAccess::eSampleGrad2DF:
			result = "SAMPLEGRAD2DF";
			break;

		case SampledImageAccess::eSampleGrad3DF:
			result = "SAMPLEGRAD3DF";
			break;

		case SampledImageAccess::eSampleGradCubeF:
			result = "SAMPLEGRADCUBEF";
			break;

		case SampledImageAccess::eSampleGrad2DRectF:
			result = "SAMPLEGRAD2DRECTF";
			break;

		case SampledImageAccess::eSampleGrad1DArrayF:
			result = "SAMPLEGRAD1DARRAYF";
			break;

		case SampledImageAccess::eSampleGrad2DArrayF:
			result = "SAMPLEGRAD2DARRAYF";
			break;

		case SampledImageAccess::eSampleGradCubeArrayF:
			result = "SAMPLEGRADCUBEARRAYF";
			break;

		case SampledImageAccess::eSampleGrad1DI:
			result = "SAMPLEGRAD1DI";
			break;

		case SampledImageAccess::eSampleGrad2DI:
			result = "SAMPLEGRAD2DI";
			break;

		case SampledImageAccess::eSampleGrad3DI:
			result = "SAMPLEGRAD3DI";
			break;

		case SampledImageAccess::eSampleGradCubeI:
			result = "SAMPLEGRADCUBEI";
			break;

		case SampledImageAccess::eSampleGrad2DRectI:
			result = "SAMPLEGRAD2DRECTI";
			break;

		case SampledImageAccess::eSampleGrad1DArrayI:
			result = "SAMPLEGRAD1DARRAYI";
			break;

		case SampledImageAccess::eSampleGrad2DArrayI:
			result = "SAMPLEGRAD2DARRAYI";
			break;

		case SampledImageAccess::eSampleGradCubeArrayI:
			result = "SAMPLEGRADCUBEARRAYI";
			break;

		case SampledImageAccess::eSampleGrad1DU:
			result = "SAMPLEGRAD1DU";
			break;

		case SampledImageAccess::eSampleGrad2DU:
			result = "SAMPLEGRAD2DU";
			break;

		case SampledImageAccess::eSampleGrad3DU:
			result = "SAMPLEGRAD3DU";
			break;

		case SampledImageAccess::eSampleGradCubeU:
			result = "SAMPLEGRADCUBEU";
			break;

		case SampledImageAccess::eSampleGrad2DRectU:
			result = "SAMPLEGRAD2DRECTU";
			break;

		case SampledImageAccess::eSampleGrad1DArrayU:
			result = "SAMPLEGRAD1DARRAYU";
			break;

		case SampledImageAccess::eSampleGrad2DArrayU:
			result = "SAMPLEGRAD2DARRAYU";
			break;

		case SampledImageAccess::eSampleGradCubeArrayU:
			result = "SAMPLEGRADCUBEARRAYU";
			break;

		case SampledImageAccess::eSampleGradOffset1DF:
			result = "SAMPLEGRADOFFSET1DF";
			break;

		case SampledImageAccess::eSampleGradOffset2DF:
			result = "SAMPLEGRADOFFSET2DF";
			break;

		case SampledImageAccess::eSampleGradOffset3DF:
			result = "SAMPLEGRADOFFSET3DF";
			break;

		case SampledImageAccess::eSampleGradOffset2DRectF:
			result = "SAMPLEGRADOFFSET2DRECTF";
			break;

		case SampledImageAccess::eSampleGradOffset1DArrayF:
			result = "SAMPLEGRADOFFSET1DARRAYF";
			break;

		case SampledImageAccess::eSampleGradOffset2DArrayF:
			result = "SAMPLEGRADOFFSET2DARRAYF";
			break;

		case SampledImageAccess::eSampleGradOffset1DI:
			result = "SAMPLEGRADOFFSET1DI";
			break;

		case SampledImageAccess::eSampleGradOffset2DI:
			result = "SAMPLEGRADOFFSET2DI";
			break;

		case SampledImageAccess::eSampleGradOffset3DI:
			result = "SAMPLEGRADOFFSET3DI";
			break;

		case SampledImageAccess::eSampleGradOffset2DRectI:
			result = "SAMPLEGRADOFFSET2DRECTI";
			break;

		case SampledImageAccess::eSampleGradOffset1DArrayI:
			result = "SAMPLEGRADOFFSET1DARRAYI";
			break;

		case SampledImageAccess::eSampleGradOffset2DArrayI:
			result = "SAMPLEGRADOFFSET2DARRAYI";
			break;

		case SampledImageAccess::eSampleGradOffset1DU:
			result = "SAMPLEGRADOFFSET1DU";
			break;

		case SampledImageAccess::eSampleGradOffset2DU:
			result = "SAMPLEGRADOFFSET2DU";
			break;

		case SampledImageAccess::eSampleGradOffset3DU:
			result = "SAMPLEGRADOFFSET3DU";
			break;

		case SampledImageAccess::eSampleGradOffset2DRectU:
			result = "SAMPLEGRADOFFSET2DRECTU";
			break;

		case SampledImageAccess::eSampleGradOffset1DArrayU:
			result = "SAMPLEGRADOFFSET1DARRAYU";
			break;

		case SampledImageAccess::eSampleGradOffset2DArrayU:
			result = "SAMPLEGRADOFFSET2DARRAYU";
			break;

		case SampledImageAccess::eSampleProjGrad1DF2:
			result = "SAMPLEPROJGRAD1DF2";
			break;

		case SampledImageAccess::eSampleProjGrad1DF4:
			result = "SAMPLEPROJGRAD1DF4";
			break;

		case SampledImageAccess::eSampleProjGrad2DF3:
			result = "SAMPLEPROJGRAD2DF3";
			break;

		case SampledImageAccess::eSampleProjGrad2DF4:
			result = "SAMPLEPROJGRAD2DF4";
			break;

		case SampledImageAccess::eSampleProjGrad3DF:
			result = "SAMPLEPROJGRAD3DF";
			break;

		case SampledImageAccess::eSampleProjGrad2DRectF3:
			result = "SAMPLEPROJGRAD2DRECTF3";
			break;

		case SampledImageAccess::eSampleProjGrad2DRectF4:
			result = "SAMPLEPROJGRAD2DRECTF4";
			break;

		case SampledImageAccess::eSampleProjGrad1DI2:
			result = "SAMPLEPROJGRAD1DI2";
			break;

		case SampledImageAccess::eSampleProjGrad1DI4:
			result = "SAMPLEPROJGRAD1DI4";
			break;

		case SampledImageAccess::eSampleProjGrad2DI3:
			result = "SAMPLEPROJGRAD2DI3";
			break;

		case SampledImageAccess::eSampleProjGrad2DI4:
			result = "SAMPLEPROJGRAD2DI4";
			break;

		case SampledImageAccess::eSampleProjGrad3DI:
			result = "SAMPLEPROJGRAD3DI";
			break;

		case SampledImageAccess::eSampleProjGrad2DRectI3:
			result = "SAMPLEPROJGRAD2DRECTI3";
			break;

		case SampledImageAccess::eSampleProjGrad2DRectI4:
			result = "SAMPLEPROJGRAD2DRECTI4";
			break;

		case SampledImageAccess::eSampleProjGrad1DU2:
			result = "SAMPLEPROJGRAD1DU2";
			break;

		case SampledImageAccess::eSampleProjGrad1DU4:
			result = "SAMPLEPROJGRAD1DU4";
			break;

		case SampledImageAccess::eSampleProjGrad2DU3:
			result = "SAMPLEPROJGRAD2DU3";
			break;

		case SampledImageAccess::eSampleProjGrad2DU4:
			result = "SAMPLEPROJGRAD2DU4";
			break;

		case SampledImageAccess::eSampleProjGrad3DU:
			result = "SAMPLEPROJGRAD3DU";
			break;

		case SampledImageAccess::eSampleProjGrad2DRectU3:
			result = "SAMPLEPROJGRAD2DRECTU3";
			break;

		case SampledImageAccess::eSampleProjGrad2DRectU4:
			result = "SAMPLEPROJGRAD2DRECTU4";
			break;

		case SampledImageAccess::eSampleProjGradOffset1DF2:
			result = "SAMPLEPROJGRADOFFSET1DF2";
			break;

		case SampledImageAccess::eSampleProjGradOffset1DF4:
			result = "SAMPLEPROJGRADOFFSET1DF4";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DF3:
			result = "SAMPLEPROJGRADOFFSET2DF3";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DF4:
			result = "SAMPLEPROJGRADOFFSET2DF4";
			break;

		case SampledImageAccess::eSampleProjGradOffset3DF:
			result = "SAMPLEPROJGRADOFFSET3DF";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DRectF3:
			result = "SAMPLEPROJGRADOFFSET2DRECTF3";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DRectF4:
			result = "SAMPLEPROJGRADOFFSET2DRECTF4";
			break;

		case SampledImageAccess::eSampleProjGradOffset1DI2:
			result = "SAMPLEPROJGRADOFFSET1DI2";
			break;

		case SampledImageAccess::eSampleProjGradOffset1DI4:
			result = "SAMPLEPROJGRADOFFSET1DI4";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DI3:
			result = "SAMPLEPROJGRADOFFSET2DI3";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DI4:
			result = "SAMPLEPROJGRADOFFSET2DI4";
			break;

		case SampledImageAccess::eSampleProjGradOffset3DI:
			result = "SAMPLEPROJGRADOFFSET3DI";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DRectI3:
			result = "SAMPLEPROJGRADOFFSET2DRECTI3";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DRectI4:
			result = "SAMPLEPROJGRADOFFSET2DRECTI4";
			break;

		case SampledImageAccess::eSampleProjGradOffset1DU2:
			result = "SAMPLEPROJGRADOFFSET1DU2";
			break;

		case SampledImageAccess::eSampleProjGradOffset1DU4:
			result = "SAMPLEPROJGRADOFFSET1DU4";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DU3:
			result = "SAMPLEPROJGRADOFFSET2DU3";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DU4:
			result = "SAMPLEPROJGRADOFFSET2DU4";
			break;

		case SampledImageAccess::eSampleProjGradOffset3DU:
			result = "SAMPLEPROJGRADOFFSET3DU";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DRectU3:
			result = "SAMPLEPROJGRADOFFSET2DRECTU3";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DRectU4:
			result = "SAMPLEPROJGRADOFFSET2DRECTU4";
			break;

	
	// Texel Compare Functions
		case SampledImageAccess::eSample1DShadowF:
			result = "SAMPLE1DSHADOWF";
			break;

		case SampledImageAccess::eSample1DShadowFBias:
			result = "SAMPLE1DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSample2DShadowF:
			result = "SAMPLE2DSHADOWF";
			break;

		case SampledImageAccess::eSample2DShadowFBias:
			result = "SAMPLE2DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSampleCubeShadowF:
			result = "SAMPLECUBESHADOWF";
			break;

		case SampledImageAccess::eSampleCubeShadowFBias:
			result = "SAMPLECUBESHADOWFBIAS";
			break;

		case SampledImageAccess::eSample1DArrayShadowF:
			result = "SAMPLE1DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSample1DArrayShadowFBias:
			result = "SAMPLE1DARRAYSHADOWFBIAS";
			break;

		case SampledImageAccess::eSample2DArrayShadowF:
			result = "SAMPLE2DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSample2DRectShadowF:
			result = "SAMPLE2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleCubeArrayShadowF:
			result = "SAMPLECUBEARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleProj1DShadowF:
			result = "SAMPLEPROJ1DSHADOWF";
			break;

		case SampledImageAccess::eSampleProj1DShadowFBias:
			result = "SAMPLEPROJ1DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSampleProj2DShadowF:
			result = "SAMPLEPROJ2DSHADOWF";
			break;

		case SampledImageAccess::eSampleProj2DShadowFBias:
			result = "SAMPLEPROJ2DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSampleProj2DRectShadowF:
			result = "SAMPLEPROJ2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleLod1DShadowF:
			result = "SAMPLELOD1DSHADOWF";
			break;

		case SampledImageAccess::eSampleLod2DShadowF:
			result = "SAMPLELOD2DSHADOWF";
			break;

		case SampledImageAccess::eSampleLod1DArrayShadowF:
			result = "SAMPLELOD1DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleOffset2DRectShadowF:
			result = "SAMPLEOFFSET2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleOffset1DShadowF:
			result = "SAMPLEOFFSET1DSHADOWF";
			break;

		case SampledImageAccess::eSampleOffset1DShadowFBias:
			result = "SAMPLEOFFSET1DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSampleOffset2DShadowF:
			result = "SAMPLEOFFSET2DSHADOWF";
			break;

		case SampledImageAccess::eSampleOffset2DShadowFBias:
			result = "SAMPLEOFFSET2DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSampleOffset1DArrayShadowF:
			result = "SAMPLEOFFSET1DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleOffset2DArrayShadowF:
			result = "SAMPLEOFFSET2DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleProjOffset1DShadowF:
			result = "SAMPLEPROJOFFSET1DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjOffset1DShadowFBias:
			result = "SAMPLEPROJOFFSET1DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DShadowF:
			result = "SAMPLEPROJOFFSET2DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjOffset2DShadowFBias:
			result = "SAMPLEPROJOFFSET2DSHADOWFBIAS";
			break;

		case SampledImageAccess::eSampleProjOffset2DRectShadowF:
			result = "SAMPLEPROJOFFSET2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleLodOffset1DShadowF:
			result = "SAMPLELODOFFSET1DSHADOWF";
			break;

		case SampledImageAccess::eSampleLodOffset2DShadowF:
			result = "SAMPLELODOFFSET2DSHADOWF";
			break;

		case SampledImageAccess::eSampleLodOffset1DArrayShadowF:
			result = "SAMPLELODOFFSET1DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleProjLod1DShadowF:
			result = "SAMPLEPROJLOD1DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjLod2DShadowF:
			result = "SAMPLEPROJLOD2DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjLodOffset1DShadowF:
			result = "SAMPLEPROJLODOFFSET1DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjLodOffset2DShadowF:
			result = "SAMPLEPROJLODOFFSET2DSHADOWF";
			break;

		case SampledImageAccess::eSampleGrad2DRectShadowF:
			result = "SAMPLEGRAD2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleGrad1DShadowF:
			result = "SAMPLEGRAD1DSHADOWF";
			break;

		case SampledImageAccess::eSampleGrad2DShadowF:
			result = "SAMPLEGRAD2DSHADOWF";
			break;

		case SampledImageAccess::eSampleGrad1DArrayShadowF:
			result = "SAMPLEGRAD1DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleGradOffset2DRectShadowF:
			result = "SAMPLEGRADOFFSET2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleGradOffset1DShadowF:
			result = "SAMPLEGRADOFFSET1DSHADOWF";
			break;

		case SampledImageAccess::eSampleGradOffset2DShadowF:
			result = "SAMPLEGRADOFFSET2DSHADOWF";
			break;

		case SampledImageAccess::eSampleGradOffset1DArrayShadowF:
			result = "SAMPLEGRADOFFSET1DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleGradOffset2DArrayShadowF:
			result = "SAMPLEGRADOFFSET2DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleProjGrad1DShadowF:
			result = "SAMPLEPROJGRAD1DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjGrad2DShadowF:
			result = "SAMPLEPROJGRAD2DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjGrad2DRectShadowF:
			result = "SAMPLEPROJGRAD2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleProjGradOffset1DShadowF:
			result = "SAMPLEPROJGRADOFFSET1DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DShadowF:
			result = "SAMPLEPROJGRADOFFSET2DSHADOWF";
			break;

		case SampledImageAccess::eSampleProjGradOffset2DRectShadowF:
			result = "SAMPLEPROJGRADOFFSET2DRECTSHADOWF";
			break;


	// Texture Gather Functions
		case SampledImageAccess::eSampleGather2DF:
			result = "SAMPLEGATHER2DF";
			break;

		case SampledImageAccess::eSampleGather2DArrayF:
			result = "SAMPLEGATHER2DARRAYF";
			break;

		case SampledImageAccess::eSampleGatherCubeF:
			result = "SAMPLEGATHERCUBEF";
			break;

		case SampledImageAccess::eSampleGatherCubeArrayF:
			result = "SAMPLEGATHERCUBEARRAYF";
			break;

		case SampledImageAccess::eSampleGather2DRectF:
			result = "SAMPLEGATHER2DRECTF";
			break;

		case SampledImageAccess::eSampleGather2DI:
			result = "SAMPLEGATHER2DI";
			break;

		case SampledImageAccess::eSampleGather2DArrayI:
			result = "SAMPLEGATHER2DARRAYI";
			break;

		case SampledImageAccess::eSampleGatherCubeI:
			result = "SAMPLEGATHERCUBEI";
			break;

		case SampledImageAccess::eSampleGatherCubeArrayI:
			result = "SAMPLEGATHERCUBEARRAYI";
			break;

		case SampledImageAccess::eSampleGather2DRectI:
			result = "SAMPLEGATHER2DRECTI";
			break;

		case SampledImageAccess::eSampleGather2DU:
			result = "SAMPLEGATHER2DU";
			break;

		case SampledImageAccess::eSampleGather2DArrayU:
			result = "SAMPLEGATHER2DARRAYU";
			break;

		case SampledImageAccess::eSampleGatherCubeU:
			result = "SAMPLEGATHERCUBEU";
			break;

		case SampledImageAccess::eSampleGatherCubeArrayU:
			result = "SAMPLEGATHERCUBEARRAYU";
			break;

		case SampledImageAccess::eSampleGather2DRectU:
			result = "SAMPLEGATHER2DRECTU";
			break;

		case SampledImageAccess::eSampleGatherOffset2DF:
			result = "SAMPLEGATHEROFFSET2DF";
			break;

		case SampledImageAccess::eSampleGatherOffset2DArrayF:
			result = "SAMPLEGATHEROFFSET2DARRAYF";
			break;

		case SampledImageAccess::eSampleGatherOffset2DRectF:
			result = "SAMPLEGATHEROFFSET2DRECTF";
			break;

		case SampledImageAccess::eSampleGatherOffset2DI:
			result = "SAMPLEGATHEROFFSET2DI";
			break;

		case SampledImageAccess::eSampleGatherOffset2DArrayI:
			result = "SAMPLEGATHEROFFSET2DARRAYI";
			break;

		case SampledImageAccess::eSampleGatherOffset2DRectI:
			result = "SAMPLEGATHEROFFSET2DRECTI";
			break;

		case SampledImageAccess::eSampleGatherOffset2DU:
			result = "SAMPLEGATHEROFFSET2DU";
			break;

		case SampledImageAccess::eSampleGatherOffset2DArrayU:
			result = "SAMPLEGATHEROFFSET2DARRAYU";
			break;

		case SampledImageAccess::eSampleGatherOffset2DRectU:
			result = "SAMPLEGATHEROFFSET2DRECTU";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DF:
			result = "SAMPLEGATHEROFFSETS2DF";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DArrayF:
			result = "SAMPLEGATHEROFFSETS2DARRAYF";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DRectF:
			result = "SAMPLEGATHEROFFSETS2DRECTF";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DI:
			result = "SAMPLEGATHEROFFSETS2DI";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DArrayI:
			result = "SAMPLEGATHEROFFSETS2DARRAYI";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DRectI:
			result = "SAMPLEGATHEROFFSETS2DRECTI";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DU:
			result = "SAMPLEGATHEROFFSETS2DU";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DArrayU:
			result = "SAMPLEGATHEROFFSETS2DARRAYU";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DRectU:
			result = "SAMPLEGATHEROFFSETS2DRECTU";
			break;


	// Texture Gather Compare Functions
		case SampledImageAccess::eSampleGather2DShadowF:
			result = "SAMPLEGATHER2DSHADOWF";
			break;

		case SampledImageAccess::eSampleGather2DArrayShadowF:
			result = "SAMPLEGATHER2DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleGatherCubeShadowF:
			result = "SAMPLEGATHERCUBESHADOWF";
			break;

		case SampledImageAccess::eSampleGatherCubeArrayShadowF:
			result = "SAMPLEGATHERCUBEARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleGather2DRectShadowF:
			result = "SAMPLEGATHER2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleGatherOffset2DShadowF:
			result = "SAMPLEGATHEROFFSET2DSHADOWF";
			break;

		case SampledImageAccess::eSampleGatherOffset2DArrayShadowF:
			result = "SAMPLEGATHEROFFSET2DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleGatherOffset2DRectShadowF:
			result = "SAMPLEGATHEROFFSET2DRECTSHADOWF";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DShadowF:
			result = "SAMPLEGATHEROFFSETS2DSHADOWF";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DArrayShadowF:
			result = "SAMPLEGATHEROFFSETS2DARRAYSHADOWF";
			break;

		case SampledImageAccess::eSampleGatherOffsets2DRectShadowF:
			result = "SAMPLEGATHEROFFSETS2DRECTSHADOWF";
			break;

		default:
			throw std::runtime_error{ "Unsupported SampledImageAccess type." };
		}

		return result;
	}
}

#endif
