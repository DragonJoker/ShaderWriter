/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprMakeIntrinsic_H___
#define ___AST_ExprMakeIntrinsic_H___
#pragma once

#include "ExprIntrinsicCall.hpp"

#include <cassert>

namespace ast::expr
{	// Angle and Trigonometry Functions

	/**
	*@return
	*	float
	*@param[in] radians
	*	float
	*/
	inline IntrinsicCallPtr makeDegrees1( type::TypesCache & cache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDegrees1
			, std::move( radians ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] radians
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDegrees2( type::TypesCache & cache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDegrees2
			, std::move( radians ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] radians
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDegrees3( type::TypesCache & cache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDegrees3
			, std::move( radians ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] radians
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDegrees4( type::TypesCache & cache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDegrees4
			, std::move( radians ) );
	}
	/**
	*@return
	*	float
	*@param[in] degrees
	*	float
	*/
	inline IntrinsicCallPtr makeRadians1F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRadians1F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] degrees
	*	vec2f
	*/
	inline IntrinsicCallPtr makeRadians2F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRadians2F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] degrees
	*	vec3f
	*/
	inline IntrinsicCallPtr makeRadians3F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRadians3F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] degrees
	*	vec4f
	*/
	inline IntrinsicCallPtr makeRadians4F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRadians4F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeCos1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCos1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeCos2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCos2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeCos3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCos3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeCos4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCos4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSin1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSin1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSin2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSin2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSin3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSin3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSin4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSin4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeTan1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTan1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeTan2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTan2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeTan3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTan3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeTan4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTan4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeCosh1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCosh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeCosh2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCosh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeCosh3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCosh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeCosh4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCosh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSinh1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSinh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSinh2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSinh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSinh3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSinh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSinh4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSinh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeTanh1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTanh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeTanh2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTanh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeTanh3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTanh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeTanh4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTanh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAcos1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAcos1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAcos2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAcos2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAcos3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAcos3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAcos4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAcos4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAsin1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAsin1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAsin2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAsin2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAsin3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAsin3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAsin4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAsin4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] y_over_x
	*	float
	*/
	inline IntrinsicCallPtr makeAtan1( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtan1
			, std::move( y_over_x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] y_over_x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAtan2( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAtan2
			, std::move( y_over_x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] y_over_x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAtan3( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAtan3
			, std::move( y_over_x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] y_over_x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAtan4( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAtan4
			, std::move( y_over_x ) );
	}
	/**
	*@return
	*	float
	*@param[in] y
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAtan21( type::TypesCache & cache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtan21
			, std::move( y )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] y
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAtan22( type::TypesCache & cache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAtan22
			, std::move( y )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] y
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAtan23( type::TypesCache & cache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAtan23
			, std::move( y )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] y
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAtan24( type::TypesCache & cache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAtan24
			, std::move( y )
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAcosh1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAcosh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAcosh2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAcosh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAcosh3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAcosh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAcosh4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAcosh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAsinh1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAsinh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAsinh2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAsinh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAsinh3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAsinh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAsinh4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAsinh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAtanh1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtanh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAtanh2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAtanh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAtanh3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAtanh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAtanh4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAtanh4
			, std::move( x ) );
	}
	// Exponential Functions

	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] y
	*	float
	*/
	inline IntrinsicCallPtr makePow1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::ePow1
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makePow2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::ePow2
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makePow3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::ePow3
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makePow4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::ePow4
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeExp1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eExp1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeExp2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eExp2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeExp3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eExp3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeExp4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eExp4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeLog1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLog1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLog2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLog2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLog3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLog3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLog4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLog4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeExp21( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eExp21
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeExp22( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eExp22
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeExp23( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eExp23
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeExp24( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eExp24
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeLog21( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLog21
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLog22( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLog22
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLog23( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLog23
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLog24( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLog24
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSqrt1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSqrt1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSqrt2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSqrt2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSqrt3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSqrt3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSqrt4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSqrt4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeSqrt1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSqrt1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSqrt2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSqrt2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSqrt3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSqrt3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSqrt4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSqrt4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeInverseSqrt1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInverseSqrt1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInverseSqrt2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInverseSqrt2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeInverseSqrt3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInverseSqrt3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeInverseSqrt4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInverseSqrt4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeInverseSqrt1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eInverseSqrt1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeInverseSqrt2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eInverseSqrt2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeInverseSqrt3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eInverseSqrt3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeInverseSqrt4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eInverseSqrt4D
			, std::move( x ) );
	}
	// Common Functions

	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAbs1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAbs1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAbs2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAbs2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAbs3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAbs3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAbs4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAbs4F
			, std::move( x ) );
	}
	/**
	*@return
	*	int
	*@param[in] x
	*	int
	*/
	inline IntrinsicCallPtr makeAbs1I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAbs1I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] x
	*	vec2i
	*/
	inline IntrinsicCallPtr makeAbs2I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eAbs2I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] x
	*	vec3i
	*/
	inline IntrinsicCallPtr makeAbs3I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eAbs3I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] x
	*	vec4i
	*/
	inline IntrinsicCallPtr makeAbs4I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eAbs4I
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeAbs1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eAbs1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeAbs2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eAbs2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeAbs3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eAbs3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeAbs4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eAbs4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSign1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSign1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSign2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSign2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSign3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSign3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSign4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSign4F
			, std::move( x ) );
	}
	/**
	*@return
	*	int
	*@param[in] x
	*	int
	*/
	inline IntrinsicCallPtr makeSign1I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eSign1I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] x
	*	vec2i
	*/
	inline IntrinsicCallPtr makeSign2I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eSign2I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] x
	*	vec3i
	*/
	inline IntrinsicCallPtr makeSign3I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eSign3I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] x
	*	vec4i
	*/
	inline IntrinsicCallPtr makeSign4I( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eSign4I
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeSign1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSign1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSign2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSign2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSign3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSign3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSign4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSign4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeFloor1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFloor1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFloor2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFloor2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFloor3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFloor3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFloor4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFloor4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeFloor1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFloor1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeFloor2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFloor2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeFloor3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFloor3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeFloor4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFloor4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeTrunc1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTrunc1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeTrunc2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTrunc2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeTrunc3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTrunc3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeTrunc4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTrunc4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeTrunc1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eTrunc1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeTrunc2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eTrunc2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeTrunc3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eTrunc3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeTrunc4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eTrunc4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeRound1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRound1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeRound2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRound2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeRound3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRound3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeRound4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRound4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeRound1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRound1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeRound2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRound2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeRound3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRound3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeRound4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRound4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeRoundEven1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRoundEven1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeRoundEven2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRoundEven2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeRoundEven3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRoundEven3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeRoundEven4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRoundEven4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeRoundEven1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRoundEven1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeRoundEven2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRoundEven2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeRoundEven3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRoundEven3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeRoundEven4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRoundEven4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeCeil1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCeil1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeCeil2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCeil2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeCeil3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCeil3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeCeil4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCeil4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeCeil1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eCeil1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeCeil2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eCeil2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeCeil3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eCeil3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeCeil4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eCeil4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeFract1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFract1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFract2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFract2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFract3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFract3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFract4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFract4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeFract1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFract1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeFract2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFract2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeFract3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFract3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeFract4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFract4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] y
	*	float
	*/
	inline IntrinsicCallPtr makeMod1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMod1F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeMod2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMod2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeMod3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMod3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeMod4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMod4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] y
	*	double
	*/
	inline IntrinsicCallPtr makeMod1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMod1D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeMod2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMod2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeMod3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMod3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeMod4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMod4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] i
	*	float
	*/
	inline IntrinsicCallPtr makeModf1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( i->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eModf1F
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] i
	*	vec2f
	*/
	inline IntrinsicCallPtr makeModf2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( i->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eModf2F
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] i
	*	vec3f
	*/
	inline IntrinsicCallPtr makeModf3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( i->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eModf3F
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] i
	*	vec4f
	*/
	inline IntrinsicCallPtr makeModf4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( i->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eModf4F
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] i
	*	double
	*/
	inline IntrinsicCallPtr makeModf1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( i->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eModf1D
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[in] i
	*	vec2d
	*/
	inline IntrinsicCallPtr makeModf2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( i->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eModf2D
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] i
	*	vec3d
	*/
	inline IntrinsicCallPtr makeModf3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( i->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eModf3D
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[in] i
	*	vec4d
	*/
	inline IntrinsicCallPtr makeModf4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( i->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eModf4D
			, std::move( x )
			, std::move( i ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] y
	*	float
	*/
	inline IntrinsicCallPtr makeMin1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMin1F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeMin2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMin2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeMin3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMin3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeMin4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMin4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] y
	*	double
	*/
	inline IntrinsicCallPtr makeMin1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMin1D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeMin2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMin2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeMin3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMin3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeMin4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMin4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	int
	*@param[in] x
	*	int
	*@param[in] y
	*	int
	*/
	inline IntrinsicCallPtr makeMin1I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt );
		assert( y->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eMin1I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeMin2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eMin2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeMin3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eMin3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeMin4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eMin4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	uint
	*@param[in] x
	*	uint
	*@param[in] y
	*	uint
	*/
	inline IntrinsicCallPtr makeMin1U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt );
		assert( y->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eMin1U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeMin2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eMin2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeMin3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eMin3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeMin4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eMin4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] y
	*	float
	*/
	inline IntrinsicCallPtr makeMax1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMax1F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeMax2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMax2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeMax3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMax3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeMax4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMax4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] y
	*	double
	*/
	inline IntrinsicCallPtr makeMax1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMax1D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeMax2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMax2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeMax3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMax3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeMax4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMax4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	int
	*@param[in] x
	*	int
	*@param[in] y
	*	int
	*/
	inline IntrinsicCallPtr makeMax1I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt );
		assert( y->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eMax1I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeMax2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eMax2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeMax3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eMax3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeMax4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eMax4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	uint
	*@param[in] x
	*	uint
	*@param[in] y
	*	uint
	*/
	inline IntrinsicCallPtr makeMax1U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt );
		assert( y->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eMax1U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeMax2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eMax2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeMax3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eMax3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeMax4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eMax4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] minVal
	*	float
	*@param[in] maxVal
	*	float
	*/
	inline IntrinsicCallPtr makeClamp1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( minVal->getType()->getRawKind() == type::Kind::eFloat );
		assert( maxVal->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eClamp1F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] minVal
	*	vec2f
	*@param[in] maxVal
	*	vec2f
	*/
	inline IntrinsicCallPtr makeClamp2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2F );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eClamp2F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] minVal
	*	vec3f
	*@param[in] maxVal
	*	vec3f
	*/
	inline IntrinsicCallPtr makeClamp3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3F );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eClamp3F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] minVal
	*	vec4f
	*@param[in] maxVal
	*	vec4f
	*/
	inline IntrinsicCallPtr makeClamp4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4F );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eClamp4F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] minVal
	*	double
	*@param[in] maxVal
	*	double
	*/
	inline IntrinsicCallPtr makeClamp1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( minVal->getType()->getRawKind() == type::Kind::eDouble );
		assert( maxVal->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eClamp1D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[in] minVal
	*	vec2d
	*@param[in] maxVal
	*	vec2d
	*/
	inline IntrinsicCallPtr makeClamp2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2D );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eClamp2D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] minVal
	*	vec3d
	*@param[in] maxVal
	*	vec3d
	*/
	inline IntrinsicCallPtr makeClamp3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3D );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eClamp3D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[in] minVal
	*	vec4d
	*@param[in] maxVal
	*	vec4d
	*/
	inline IntrinsicCallPtr makeClamp4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4D );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eClamp4D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	int
	*@param[in] x
	*	int
	*@param[in] minVal
	*	int
	*@param[in] maxVal
	*	int
	*/
	inline IntrinsicCallPtr makeClamp1I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt );
		assert( minVal->getType()->getRawKind() == type::Kind::eInt );
		assert( maxVal->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eClamp1I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] x
	*	vec2i
	*@param[in] minVal
	*	vec2i
	*@param[in] maxVal
	*	vec2i
	*/
	inline IntrinsicCallPtr makeClamp2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2I );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eClamp2I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] x
	*	vec3i
	*@param[in] minVal
	*	vec3i
	*@param[in] maxVal
	*	vec3i
	*/
	inline IntrinsicCallPtr makeClamp3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3I );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eClamp3I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] x
	*	vec4i
	*@param[in] minVal
	*	vec4i
	*@param[in] maxVal
	*	vec4i
	*/
	inline IntrinsicCallPtr makeClamp4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4I );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eClamp4I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	uint
	*@param[in] x
	*	uint
	*@param[in] minVal
	*	uint
	*@param[in] maxVal
	*	uint
	*/
	inline IntrinsicCallPtr makeClamp1U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt );
		assert( minVal->getType()->getRawKind() == type::Kind::eUInt );
		assert( maxVal->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eClamp1U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] x
	*	vec2u
	*@param[in] minVal
	*	vec2u
	*@param[in] maxVal
	*	vec2u
	*/
	inline IntrinsicCallPtr makeClamp2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2U );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eClamp2U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] x
	*	vec3u
	*@param[in] minVal
	*	vec3u
	*@param[in] maxVal
	*	vec3u
	*/
	inline IntrinsicCallPtr makeClamp3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3U );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eClamp3U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] x
	*	vec4u
	*@param[in] minVal
	*	vec4u
	*@param[in] maxVal
	*	vec4u
	*/
	inline IntrinsicCallPtr makeClamp4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4U );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eClamp4U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] y
	*	float
	*@param[in] a
	*	float
	*/
	inline IntrinsicCallPtr makeMix1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		assert( a->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMix1F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*@param[in] a
	*	vec2f
	*/
	inline IntrinsicCallPtr makeMix2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		assert( a->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMix2F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*@param[in] a
	*	vec3f
	*/
	inline IntrinsicCallPtr makeMix3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		assert( a->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMix3F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*@param[in] a
	*	vec4f
	*/
	inline IntrinsicCallPtr makeMix4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		assert( a->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMix4F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] y
	*	double
	*@param[in] a
	*	double
	*/
	inline IntrinsicCallPtr makeMix1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		assert( a->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMix1D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*@param[in] a
	*	vec2d
	*/
	inline IntrinsicCallPtr makeMix2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		assert( a->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMix2D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*@param[in] a
	*	vec3d
	*/
	inline IntrinsicCallPtr makeMix3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		assert( a->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMix3D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*@param[in] a
	*	vec4d
	*/
	inline IntrinsicCallPtr makeMix4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		assert( a->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMix4D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}
	/**
	*@return
	*	float
	*@param[in] edge
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeStep1F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eFloat );
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eStep1F
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] edge
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeStep2F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec2F );
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eStep2F
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] edge
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeStep3F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec3F );
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eStep3F
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] edge
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeStep4F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec4F );
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eStep4F
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] edge
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeStep1D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eDouble );
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eStep1D
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] edge
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeStep2D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec2D );
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eStep2D
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] edge
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeStep3D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec3D );
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eStep3D
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] edge
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeStep4D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec4D );
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eStep4D
			, std::move( edge )
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] edge0
	*	float
	*@param[in] edge1
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSmoothStep1F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eFloat );
		assert( edge1->getType()->getRawKind() == type::Kind::eFloat );
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSmoothStep1F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] edge0
	*	vec2f
	*@param[in] edge1
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSmoothStep2F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec2F );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec2F );
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSmoothStep2F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] edge0
	*	vec3f
	*@param[in] edge1
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSmoothStep3F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec3F );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec3F );
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSmoothStep3F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] edge0
	*	vec4f
	*@param[in] edge1
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSmoothStep4F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec4F );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec4F );
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSmoothStep4F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] edge0
	*	double
	*@param[in] edge1
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeSmoothStep1D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eDouble );
		assert( edge1->getType()->getRawKind() == type::Kind::eDouble );
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSmoothStep1D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] edge0
	*	vec2d
	*@param[in] edge1
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSmoothStep2D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec2D );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec2D );
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSmoothStep2D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] edge0
	*	vec3d
	*@param[in] edge1
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSmoothStep3D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec3D );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec3D );
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSmoothStep3D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] edge0
	*	vec4d
	*@param[in] edge1
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSmoothStep4D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec4D );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec4D );
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSmoothStep4D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeIsnan1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeIsnan2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeIsnan3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeIsnan4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4F
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeIsnan1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeIsnan2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeIsnan3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeIsnan4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4D
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeIsinf1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeIsinf2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeIsinf3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeIsinf4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4F
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeIsinf1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeIsinf2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeIsinf3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeIsinf4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4D
			, std::move( x ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt1( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFloatBitsToInt1
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt2( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFloatBitsToInt2
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt3( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFloatBitsToInt3
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt4( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFloatBitsToInt4
			, std::move( value ) );
	}
	/**
	*@return
	*	uint
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt1( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eFloatBitsToUInt1
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt2( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eFloatBitsToUInt2
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt3( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eFloatBitsToUInt3
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt4( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eFloatBitsToUInt4
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	int
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eIntBitsToFloat1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2i
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eIntBitsToFloat2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3i
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eIntBitsToFloat3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4i
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eIntBitsToFloat4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	uint
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eUintBitsToFloat1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2u
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUintBitsToFloat2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3u
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eUintBitsToFloat3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4u
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eUintBitsToFloat4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] a
	*	float
	*@param[in] b
	*	float
	*@param[in] c
	*	float
	*/
	inline IntrinsicCallPtr makeFma1F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eFloat );
		assert( b->getType()->getRawKind() == type::Kind::eFloat );
		assert( c->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFma1F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] a
	*	vec2f
	*@param[in] b
	*	vec2f
	*@param[in] c
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFma2F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec2F );
		assert( b->getType()->getRawKind() == type::Kind::eVec2F );
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFma2F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] a
	*	vec3f
	*@param[in] b
	*	vec3f
	*@param[in] c
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFma3F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec3F );
		assert( b->getType()->getRawKind() == type::Kind::eVec3F );
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFma3F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] a
	*	vec4f
	*@param[in] b
	*	vec4f
	*@param[in] c
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFma4F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec4F );
		assert( b->getType()->getRawKind() == type::Kind::eVec4F );
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFma4F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	double
	*@param[in] a
	*	double
	*@param[in] b
	*	double
	*@param[in] c
	*	double
	*/
	inline IntrinsicCallPtr makeFma1D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eDouble );
		assert( b->getType()->getRawKind() == type::Kind::eDouble );
		assert( c->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFma1D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] a
	*	vec2d
	*@param[in] b
	*	vec2d
	*@param[in] c
	*	vec2d
	*/
	inline IntrinsicCallPtr makeFma2D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec2D );
		assert( b->getType()->getRawKind() == type::Kind::eVec2D );
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFma2D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] a
	*	vec3d
	*@param[in] b
	*	vec3d
	*@param[in] c
	*	vec3d
	*/
	inline IntrinsicCallPtr makeFma3D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec3D );
		assert( b->getType()->getRawKind() == type::Kind::eVec3D );
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFma3D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] a
	*	vec4d
	*@param[in] b
	*	vec4d
	*@param[in] c
	*	vec4d
	*/
	inline IntrinsicCallPtr makeFma4D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec4D );
		assert( b->getType()->getRawKind() == type::Kind::eVec4D );
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFma4D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[out] exp
	*	int
	*/
	inline IntrinsicCallPtr makeFrexp1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( exp->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFrexp1F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[out] exp
	*	vec2i
	*/
	inline IntrinsicCallPtr makeFrexp2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFrexp2F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[out] exp
	*	vec3i
	*/
	inline IntrinsicCallPtr makeFrexp3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFrexp3F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[out] exp
	*	vec4i
	*/
	inline IntrinsicCallPtr makeFrexp4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFrexp4F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[out] exp
	*	int
	*/
	inline IntrinsicCallPtr makeFrexp1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( exp->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFrexp1D
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[out] exp
	*	vec2i
	*/
	inline IntrinsicCallPtr makeFrexp2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFrexp2D
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[out] exp
	*	vec3i
	*/
	inline IntrinsicCallPtr makeFrexp3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFrexp3D
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[out] exp
	*	vec4i
	*/
	inline IntrinsicCallPtr makeFrexp4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFrexp4D
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] exp
	*	int
	*/
	inline IntrinsicCallPtr makeLdexp1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( exp->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLdexp1F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*@param[in] exp
	*	vec2i
	*/
	inline IntrinsicCallPtr makeLdexp2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLdexp2F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] exp
	*	vec3i
	*/
	inline IntrinsicCallPtr makeLdexp3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLdexp3F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*@param[in] exp
	*	vec4i
	*/
	inline IntrinsicCallPtr makeLdexp4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLdexp4F
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] exp
	*	int
	*/
	inline IntrinsicCallPtr makeLdexp1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( exp->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLdexp1D
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*@param[in] exp
	*	vec2i
	*/
	inline IntrinsicCallPtr makeLdexp2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eLdexp2D
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] exp
	*	vec3i
	*/
	inline IntrinsicCallPtr makeLdexp3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eLdexp3D
			, std::move( x )
			, std::move( exp ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*@param[in] exp
	*	vec4i
	*/
	inline IntrinsicCallPtr makeLdexp4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eLdexp4D
			, std::move( x )
			, std::move( exp ) );
	}
	// Floating-point Pack and Unpack Functions

	/**
	*@return
	*	double
	*@param[in] v
	*	vec2u
	*/
	inline IntrinsicCallPtr makePackDouble2x32( type::TypesCache & cache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::ePackDouble2x32
			, std::move( v ) );
	}
	/**
	*@return
	*	uint
	*@param[in] v
	*	vec2f
	*/
	inline IntrinsicCallPtr makePackHalf2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackHalf2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	uint
	*@param[in] v
	*	vec2f
	*/
	inline IntrinsicCallPtr makePackSnorm2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	uint
	*@param[in] v
	*	vec4f
	*/
	inline IntrinsicCallPtr makePackSnorm4x8( type::TypesCache & cache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm4x8
			, std::move( v ) );
	}
	/**
	*@return
	*	uint
	*@param[in] v
	*	vec2f
	*/
	inline IntrinsicCallPtr makePackUnorm2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	uint
	*@param[in] v
	*	vec4f
	*/
	inline IntrinsicCallPtr makePackUnorm4x8( type::TypesCache & cache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm4x8
			, std::move( v ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] d
	*	double
	*/
	inline IntrinsicCallPtr makeUnpackDouble2x32( type::TypesCache & cache
		, ExprPtr d )
	{
		assert( d->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eUnpackDouble2x32
			, std::move( d ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] v
	*	uint
	*/
	inline IntrinsicCallPtr makeUnpackHalf2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackHalf2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	uint
	*/
	inline IntrinsicCallPtr makeUnpackSnorm2x16( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackSnorm2x16
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	uint
	*/
	inline IntrinsicCallPtr makeUnpackSnorm4x8( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eUnpackSnorm4x8
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	uint
	*/
	inline IntrinsicCallPtr makeUnpackUnorm2x16( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackUnorm2x16
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	uint
	*/
	inline IntrinsicCallPtr makeUnpackUnorm4x8( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eUnpackUnorm4x8
			, std::move( p ) );
	}
	// Geometric Functions

	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeLength1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength1F
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLength2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength2F
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLength3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength3F
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLength4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeLength1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength1D
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeLength2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength2D
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeLength3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength3D
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeLength4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] p0
	*	float
	*@param[in] p1
	*	float
	*/
	inline IntrinsicCallPtr makeDistance1F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eFloat );
		assert( p1->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDistance1F
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	float
	*@param[in] p0
	*	vec2f
	*@param[in] p1
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDistance2F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec2F );
		assert( p1->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDistance2F
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	float
	*@param[in] p0
	*	vec3f
	*@param[in] p1
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDistance3F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec3F );
		assert( p1->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDistance3F
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	float
	*@param[in] p0
	*	vec4f
	*@param[in] p1
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDistance4F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec4F );
		assert( p1->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDistance4F
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	double
	*@param[in] p0
	*	double
	*@param[in] p1
	*	double
	*/
	inline IntrinsicCallPtr makeDistance1D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eDouble );
		assert( p1->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance1D
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	double
	*@param[in] p0
	*	vec2d
	*@param[in] p1
	*	vec2d
	*/
	inline IntrinsicCallPtr makeDistance2D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec2D );
		assert( p1->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance2D
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	double
	*@param[in] p0
	*	vec3d
	*@param[in] p1
	*	vec3d
	*/
	inline IntrinsicCallPtr makeDistance3D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec3D );
		assert( p1->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance3D
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	double
	*@param[in] p0
	*	vec4d
	*@param[in] p1
	*	vec4d
	*/
	inline IntrinsicCallPtr makeDistance4D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec4D );
		assert( p1->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance4D
			, std::move( p0 )
			, std::move( p1 ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*@param[in] y
	*	float
	*/
	inline IntrinsicCallPtr makeDot1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot1F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDot2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDot3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDot4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*@param[in] y
	*	double
	*/
	inline IntrinsicCallPtr makeDot1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot1D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeDot2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeDot3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeDot4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeCrossF( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCrossF
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeCrossD( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eCrossD
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeNormalize1F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eNormalize1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeNormalize2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eNormalize2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeNormalize3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eNormalize3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeNormalize4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eNormalize4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeNormalize1D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eNormalize1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeNormalize2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eNormalize2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeNormalize3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eNormalize3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeNormalize4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eNormalize4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] N
	*	float
	*@param[in] I
	*	float
	*@param[in] Nref
	*	float
	*/
	inline IntrinsicCallPtr makeFaceForward1F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eFloat );
		assert( I->getType()->getRawKind() == type::Kind::eFloat );
		assert( Nref->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFaceForward1F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] N
	*	vec2f
	*@param[in] I
	*	vec2f
	*@param[in] Nref
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFaceForward2F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec2F );
		assert( I->getType()->getRawKind() == type::Kind::eVec2F );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFaceForward2F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] N
	*	vec3f
	*@param[in] I
	*	vec3f
	*@param[in] Nref
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFaceForward3F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec3F );
		assert( I->getType()->getRawKind() == type::Kind::eVec3F );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFaceForward3F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] N
	*	vec4f
	*@param[in] I
	*	vec4f
	*@param[in] Nref
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFaceForward4F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec4F );
		assert( I->getType()->getRawKind() == type::Kind::eVec4F );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFaceForward4F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	double
	*@param[in] N
	*	double
	*@param[in] I
	*	double
	*@param[in] Nref
	*	double
	*/
	inline IntrinsicCallPtr makeFaceForward1D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eDouble );
		assert( I->getType()->getRawKind() == type::Kind::eDouble );
		assert( Nref->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFaceForward1D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] N
	*	vec2d
	*@param[in] I
	*	vec2d
	*@param[in] Nref
	*	vec2d
	*/
	inline IntrinsicCallPtr makeFaceForward2D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec2D );
		assert( I->getType()->getRawKind() == type::Kind::eVec2D );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFaceForward2D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] N
	*	vec3d
	*@param[in] I
	*	vec3d
	*@param[in] Nref
	*	vec3d
	*/
	inline IntrinsicCallPtr makeFaceForward3D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec3D );
		assert( I->getType()->getRawKind() == type::Kind::eVec3D );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFaceForward3D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] N
	*	vec4d
	*@param[in] I
	*	vec4d
	*@param[in] Nref
	*	vec4d
	*/
	inline IntrinsicCallPtr makeFaceForward4D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec4D );
		assert( I->getType()->getRawKind() == type::Kind::eVec4D );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFaceForward4D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}
	/**
	*@return
	*	float
	*@param[in] I
	*	float
	*@param[in] N
	*	float
	*/
	inline IntrinsicCallPtr makeReflect1F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eFloat );
		assert( N->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eReflect1F
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] I
	*	vec2f
	*@param[in] N
	*	vec2f
	*/
	inline IntrinsicCallPtr makeReflect2F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2F );
		assert( N->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eReflect2F
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] I
	*	vec3f
	*@param[in] N
	*	vec3f
	*/
	inline IntrinsicCallPtr makeReflect3F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3F );
		assert( N->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eReflect3F
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] I
	*	vec4f
	*@param[in] N
	*	vec4f
	*/
	inline IntrinsicCallPtr makeReflect4F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4F );
		assert( N->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eReflect4F
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	double
	*@param[in] I
	*	double
	*@param[in] N
	*	double
	*/
	inline IntrinsicCallPtr makeReflect1D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eDouble );
		assert( N->getType()->getRawKind() == type::Kind::eDouble );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eReflect1D
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] I
	*	vec2d
	*@param[in] N
	*	vec2d
	*/
	inline IntrinsicCallPtr makeReflect2D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2D );
		assert( N->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eReflect2D
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] I
	*	vec3d
	*@param[in] N
	*	vec3d
	*/
	inline IntrinsicCallPtr makeReflect3D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3D );
		assert( N->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eReflect3D
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] I
	*	vec4d
	*@param[in] N
	*	vec4d
	*/
	inline IntrinsicCallPtr makeReflect4D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4D );
		assert( N->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eReflect4D
			, std::move( I )
			, std::move( N ) );
	}
	/**
	*@return
	*	float
	*@param[in] I
	*	float
	*@param[in] N
	*	float
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract1F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eFloat );
		assert( N->getType()->getRawKind() == type::Kind::eFloat );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRefract1F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] I
	*	vec2f
	*@param[in] N
	*	vec2f
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract2F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2F );
		assert( N->getType()->getRawKind() == type::Kind::eVec2F );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRefract2F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] I
	*	vec3f
	*@param[in] N
	*	vec3f
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract3F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3F );
		assert( N->getType()->getRawKind() == type::Kind::eVec3F );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRefract3F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] I
	*	vec4f
	*@param[in] N
	*	vec4f
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract4F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4F );
		assert( N->getType()->getRawKind() == type::Kind::eVec4F );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRefract4F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	/**
	*@return
	*	double
	*@param[in] I
	*	double
	*@param[in] N
	*	double
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract1D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eDouble );
		assert( N->getType()->getRawKind() == type::Kind::eDouble );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRefract1D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] I
	*	vec2d
	*@param[in] N
	*	vec2d
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract2D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2D );
		assert( N->getType()->getRawKind() == type::Kind::eVec2D );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRefract2D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] I
	*	vec3d
	*@param[in] N
	*	vec3d
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract3D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3D );
		assert( N->getType()->getRawKind() == type::Kind::eVec3D );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRefract3D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] I
	*	vec4d
	*@param[in] N
	*	vec4d
	*@param[in] eta
	*	float
	*/
	inline IntrinsicCallPtr makeRefract4D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4D );
		assert( N->getType()->getRawKind() == type::Kind::eVec4D );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRefract4D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}
	// Matrix Functions

	/**
	*@return
	*	mat2x2f
	*@param[in] x
	*	mat2x2f
	*@param[in] y
	*	mat2x2f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult2x2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2F );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eMatrixCompMult2x2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat2x3f
	*@param[in] x
	*	mat2x3f
	*@param[in] y
	*	mat2x3f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult2x3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3F );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3F )
			, Intrinsic::eMatrixCompMult2x3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat2x4f
	*@param[in] x
	*	mat2x4f
	*@param[in] y
	*	mat2x4f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult2x4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4F );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4F )
			, Intrinsic::eMatrixCompMult2x4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat3x2f
	*@param[in] x
	*	mat3x2f
	*@param[in] y
	*	mat3x2f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult3x2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2F );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2F )
			, Intrinsic::eMatrixCompMult3x2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat3x3f
	*@param[in] x
	*	mat3x3f
	*@param[in] y
	*	mat3x3f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult3x3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3F );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eMatrixCompMult3x3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat3x4f
	*@param[in] x
	*	mat3x4f
	*@param[in] y
	*	mat3x4f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult3x4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4F );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4F )
			, Intrinsic::eMatrixCompMult3x4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat4x2f
	*@param[in] x
	*	mat4x2f
	*@param[in] y
	*	mat4x2f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult4x2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2F );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2F )
			, Intrinsic::eMatrixCompMult4x2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat4x3f
	*@param[in] x
	*	mat4x3f
	*@param[in] y
	*	mat4x3f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult4x3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3F );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3F )
			, Intrinsic::eMatrixCompMult4x3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat4x4f
	*@param[in] x
	*	mat4x4f
	*@param[in] y
	*	mat4x4f
	*/
	inline IntrinsicCallPtr makeMatrixCompMult4x4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4F );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eMatrixCompMult4x4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat2x2d
	*@param[in] x
	*	mat2x2d
	*@param[in] y
	*	mat2x2d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult2x2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2D );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eMatrixCompMult2x2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat2x3d
	*@param[in] x
	*	mat2x3d
	*@param[in] y
	*	mat2x3d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult2x3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3D );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3D )
			, Intrinsic::eMatrixCompMult2x3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat2x4d
	*@param[in] x
	*	mat2x4d
	*@param[in] y
	*	mat2x4d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult2x4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4D );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4D )
			, Intrinsic::eMatrixCompMult2x4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat3x2d
	*@param[in] x
	*	mat3x2d
	*@param[in] y
	*	mat3x2d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult3x2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2D );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2D )
			, Intrinsic::eMatrixCompMult3x2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat3x3d
	*@param[in] x
	*	mat3x3d
	*@param[in] y
	*	mat3x3d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult3x3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3D );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eMatrixCompMult3x3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat3x4d
	*@param[in] x
	*	mat3x4d
	*@param[in] y
	*	mat3x4d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult3x4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4D );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4D )
			, Intrinsic::eMatrixCompMult3x4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat4x2d
	*@param[in] x
	*	mat4x2d
	*@param[in] y
	*	mat4x2d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult4x2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2D );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2D )
			, Intrinsic::eMatrixCompMult4x2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat4x3d
	*@param[in] x
	*	mat4x3d
	*@param[in] y
	*	mat4x3d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult4x3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3D );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3D )
			, Intrinsic::eMatrixCompMult4x3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat4x4d
	*@param[in] x
	*	mat4x4d
	*@param[in] y
	*	mat4x4d
	*/
	inline IntrinsicCallPtr makeMatrixCompMult4x4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4D );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eMatrixCompMult4x4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	mat2x2f
	*@param[in] c
	*	vec2f
	*@param[in] r
	*	vec2f
	*/
	inline IntrinsicCallPtr makeOuterProduct2x2F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		assert( r->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eOuterProduct2x2F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat3x3f
	*@param[in] c
	*	vec3f
	*@param[in] r
	*	vec3f
	*/
	inline IntrinsicCallPtr makeOuterProduct3x3F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		assert( r->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eOuterProduct3x3F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat4x4f
	*@param[in] c
	*	vec4f
	*@param[in] r
	*	vec4f
	*/
	inline IntrinsicCallPtr makeOuterProduct4x4F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		assert( r->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eOuterProduct4x4F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat2x3f
	*@param[in] c
	*	vec3f
	*@param[in] r
	*	vec2f
	*/
	inline IntrinsicCallPtr makeOuterProduct3x2F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		assert( r->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3F )
			, Intrinsic::eOuterProduct3x2F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat3x2f
	*@param[in] c
	*	vec2f
	*@param[in] r
	*	vec3f
	*/
	inline IntrinsicCallPtr makeOuterProduct2x3F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		assert( r->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2F )
			, Intrinsic::eOuterProduct2x3F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat2x4f
	*@param[in] c
	*	vec4f
	*@param[in] r
	*	vec2f
	*/
	inline IntrinsicCallPtr makeOuterProduct4x2F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		assert( r->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4F )
			, Intrinsic::eOuterProduct4x2F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat4x2f
	*@param[in] c
	*	vec2f
	*@param[in] r
	*	vec4f
	*/
	inline IntrinsicCallPtr makeOuterProduct2x4F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		assert( r->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2F )
			, Intrinsic::eOuterProduct2x4F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat3x4f
	*@param[in] c
	*	vec4f
	*@param[in] r
	*	vec3f
	*/
	inline IntrinsicCallPtr makeOuterProduct4x3F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		assert( r->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4F )
			, Intrinsic::eOuterProduct4x3F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat4x3f
	*@param[in] c
	*	vec3f
	*@param[in] r
	*	vec4f
	*/
	inline IntrinsicCallPtr makeOuterProduct3x4F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		assert( r->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3F )
			, Intrinsic::eOuterProduct3x4F
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat2x2d
	*@param[in] c
	*	vec2d
	*@param[in] r
	*	vec2d
	*/
	inline IntrinsicCallPtr makeOuterProduct2x2D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		assert( r->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eOuterProduct2x2D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat3x3d
	*@param[in] c
	*	vec3d
	*@param[in] r
	*	vec3d
	*/
	inline IntrinsicCallPtr makeOuterProduct3x3D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		assert( r->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eOuterProduct3x3D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat4x4d
	*@param[in] c
	*	vec4d
	*@param[in] r
	*	vec4d
	*/
	inline IntrinsicCallPtr makeOuterProduct4x4D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		assert( r->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eOuterProduct4x4D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat2x3d
	*@param[in] c
	*	vec3d
	*@param[in] r
	*	vec2d
	*/
	inline IntrinsicCallPtr makeOuterProduct3x2D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		assert( r->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3D )
			, Intrinsic::eOuterProduct3x2D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat3x2d
	*@param[in] c
	*	vec2d
	*@param[in] r
	*	vec3d
	*/
	inline IntrinsicCallPtr makeOuterProduct2x3D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		assert( r->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2D )
			, Intrinsic::eOuterProduct2x3D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat2x4d
	*@param[in] c
	*	vec4d
	*@param[in] r
	*	vec2d
	*/
	inline IntrinsicCallPtr makeOuterProduct4x2D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		assert( r->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4D )
			, Intrinsic::eOuterProduct4x2D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat4x2d
	*@param[in] c
	*	vec2d
	*@param[in] r
	*	vec4d
	*/
	inline IntrinsicCallPtr makeOuterProduct2x4D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		assert( r->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2D )
			, Intrinsic::eOuterProduct2x4D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat3x4d
	*@param[in] c
	*	vec4d
	*@param[in] r
	*	vec3d
	*/
	inline IntrinsicCallPtr makeOuterProduct4x3D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		assert( r->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4D )
			, Intrinsic::eOuterProduct4x3D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat4x3d
	*@param[in] c
	*	vec3d
	*@param[in] r
	*	vec4d
	*/
	inline IntrinsicCallPtr makeOuterProduct3x4D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		assert( r->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3D )
			, Intrinsic::eOuterProduct3x4D
			, std::move( c )
			, std::move( r ) );
	}
	/**
	*@return
	*	mat2x2f
	*@param[in] x
	*	mat2x2f
	*/
	inline IntrinsicCallPtr makeTranspose2x2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eTranspose2x2F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x2f
	*@param[in] x
	*	mat2x3f
	*/
	inline IntrinsicCallPtr makeTranspose2x3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2F )
			, Intrinsic::eTranspose2x3F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x2f
	*@param[in] x
	*	mat2x4f
	*/
	inline IntrinsicCallPtr makeTranspose2x4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2F )
			, Intrinsic::eTranspose2x4F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x3f
	*@param[in] x
	*	mat3x2f
	*/
	inline IntrinsicCallPtr makeTranspose3x2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3F )
			, Intrinsic::eTranspose3x2F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x3f
	*@param[in] x
	*	mat3x3f
	*/
	inline IntrinsicCallPtr makeTranspose3x3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eTranspose3x3F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x3f
	*@param[in] x
	*	mat3x4f
	*/
	inline IntrinsicCallPtr makeTranspose3x4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3F )
			, Intrinsic::eTranspose3x4F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x4f
	*@param[in] x
	*	mat4x2f
	*/
	inline IntrinsicCallPtr makeTranspose4x2F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4F )
			, Intrinsic::eTranspose4x2F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x4f
	*@param[in] x
	*	mat4x3f
	*/
	inline IntrinsicCallPtr makeTranspose4x3F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4F )
			, Intrinsic::eTranspose4x3F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x4f
	*@param[in] x
	*	mat4x4f
	*/
	inline IntrinsicCallPtr makeTranspose4x4F( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eTranspose4x4F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x2d
	*@param[in] x
	*	mat2x2d
	*/
	inline IntrinsicCallPtr makeTranspose2x2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eTranspose2x2D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x2d
	*@param[in] x
	*	mat2x3d
	*/
	inline IntrinsicCallPtr makeTranspose2x3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2D )
			, Intrinsic::eTranspose2x3D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x2d
	*@param[in] x
	*	mat2x4d
	*/
	inline IntrinsicCallPtr makeTranspose2x4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2D )
			, Intrinsic::eTranspose2x4D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x3d
	*@param[in] x
	*	mat3x2d
	*/
	inline IntrinsicCallPtr makeTranspose3x2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3D )
			, Intrinsic::eTranspose3x2D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x3d
	*@param[in] x
	*	mat3x3d
	*/
	inline IntrinsicCallPtr makeTranspose3x3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eTranspose3x3D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x3d
	*@param[in] x
	*	mat3x4d
	*/
	inline IntrinsicCallPtr makeTranspose3x4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3D )
			, Intrinsic::eTranspose3x4D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x4d
	*@param[in] x
	*	mat4x2d
	*/
	inline IntrinsicCallPtr makeTranspose4x2D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4D )
			, Intrinsic::eTranspose4x2D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x4d
	*@param[in] x
	*	mat4x3d
	*/
	inline IntrinsicCallPtr makeTranspose4x3D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4D )
			, Intrinsic::eTranspose4x3D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x4d
	*@param[in] x
	*	mat4x4d
	*/
	inline IntrinsicCallPtr makeTranspose4x4D( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eTranspose4x4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] m
	*	mat2x2f
	*/
	inline IntrinsicCallPtr makeDeterminant2x2F( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant2x2F
			, std::move( m ) );
	}
	/**
	*@return
	*	float
	*@param[in] m
	*	mat3x3f
	*/
	inline IntrinsicCallPtr makeDeterminant3x3F( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant3x3F
			, std::move( m ) );
	}
	/**
	*@return
	*	float
	*@param[in] m
	*	mat4x4f
	*/
	inline IntrinsicCallPtr makeDeterminant4x4F( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant4x4F
			, std::move( m ) );
	}
	/**
	*@return
	*	double
	*@param[in] m
	*	mat2x2d
	*/
	inline IntrinsicCallPtr makeDeterminant2x2D( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant2x2D
			, std::move( m ) );
	}
	/**
	*@return
	*	double
	*@param[in] m
	*	mat3x3d
	*/
	inline IntrinsicCallPtr makeDeterminant3x3D( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant3x3D
			, std::move( m ) );
	}
	/**
	*@return
	*	double
	*@param[in] m
	*	mat4x4d
	*/
	inline IntrinsicCallPtr makeDeterminant4x4D( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant4x4D
			, std::move( m ) );
	}
	/**
	*@return
	*	mat2x2f
	*@param[in] m
	*	mat2x2f
	*/
	inline IntrinsicCallPtr makeInverse2x2F( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eInverse2x2F
			, std::move( m ) );
	}
	/**
	*@return
	*	mat3x3f
	*@param[in] m
	*	mat3x3f
	*/
	inline IntrinsicCallPtr makeInverse3x3F( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eInverse3x3F
			, std::move( m ) );
	}
	/**
	*@return
	*	mat4x4f
	*@param[in] m
	*	mat4x4f
	*/
	inline IntrinsicCallPtr makeInverse4x4F( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eInverse4x4F
			, std::move( m ) );
	}
	/**
	*@return
	*	mat2x2d
	*@param[in] m
	*	mat2x2d
	*/
	inline IntrinsicCallPtr makeInverse2x2D( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eInverse2x2D
			, std::move( m ) );
	}
	/**
	*@return
	*	mat3x3d
	*@param[in] m
	*	mat3x3d
	*/
	inline IntrinsicCallPtr makeInverse3x3D( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eInverse3x3D
			, std::move( m ) );
	}
	/**
	*@return
	*	mat4x4d
	*@param[in] m
	*	mat4x4d
	*/
	inline IntrinsicCallPtr makeInverse4x4D( type::TypesCache & cache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eInverse4x4D
			, std::move( m ) );
	}
	// Vector Relational Functions

	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLessThan2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLessThan3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLessThan4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeLessThan2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeLessThan3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeLessThan4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeLessThan2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeLessThan3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeLessThan4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeLessThan2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeLessThan3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeLessThan4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLessThanEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLessThanEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLessThanEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeLessThanEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeLessThanEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeLessThanEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeLessThanEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeLessThanEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeLessThanEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeLessThanEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeLessThanEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeLessThanEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeGreaterThan2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeGreaterThan3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeGreaterThan4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeGreaterThan2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeGreaterThan3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeGreaterThan4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeGreaterThan2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeGreaterThan3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeGreaterThan4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeGreaterThan2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeGreaterThan3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeGreaterThan4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*@param[in] y
	*	vec2f
	*/
	inline IntrinsicCallPtr makeNotEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*@param[in] y
	*	vec3f
	*/
	inline IntrinsicCallPtr makeNotEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*@param[in] y
	*	vec4f
	*/
	inline IntrinsicCallPtr makeNotEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4F
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*@param[in] y
	*	vec2d
	*/
	inline IntrinsicCallPtr makeNotEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*@param[in] y
	*	vec3d
	*/
	inline IntrinsicCallPtr makeNotEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*@param[in] y
	*	vec4d
	*/
	inline IntrinsicCallPtr makeNotEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*/
	inline IntrinsicCallPtr makeNotEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*/
	inline IntrinsicCallPtr makeNotEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*/
	inline IntrinsicCallPtr makeNotEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*/
	inline IntrinsicCallPtr makeNotEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*/
	inline IntrinsicCallPtr makeNotEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*/
	inline IntrinsicCallPtr makeNotEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec2b
	*/
	inline IntrinsicCallPtr makeAll2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAll2
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec3b
	*/
	inline IntrinsicCallPtr makeAll3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAll3
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec4b
	*/
	inline IntrinsicCallPtr makeAll4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAll4
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec2b
	*/
	inline IntrinsicCallPtr makeAny2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAny2
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec3b
	*/
	inline IntrinsicCallPtr makeAny3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAny3
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec4b
	*/
	inline IntrinsicCallPtr makeAny4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAny4
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2b
	*/
	inline IntrinsicCallPtr makeNot2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNot2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3b
	*/
	inline IntrinsicCallPtr makeNot3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNot3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4b
	*/
	inline IntrinsicCallPtr makeNot4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4B );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNot4
			, std::move( x ) );
	}
	// Integer Functions

	/**
	*@return
	*	uint
	*@param[in] x
	*	uint
	*@param[in] y
	*	uint
	*@param[in] carry
	*	uint
	*/
	inline IntrinsicCallPtr makeUaddCarry1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt );
		assert( y->getType()->getRawKind() == type::Kind::eUInt );
		assert( carry->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eUaddCarry1
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*@param[in] carry
	*	vec2u
	*/
	inline IntrinsicCallPtr makeUaddCarry2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		assert( carry->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eUaddCarry2
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*@param[in] carry
	*	vec3u
	*/
	inline IntrinsicCallPtr makeUaddCarry3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		assert( carry->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eUaddCarry3
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*@param[in] carry
	*	vec4u
	*/
	inline IntrinsicCallPtr makeUaddCarry4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		assert( carry->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eUaddCarry4
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	uint
	*@param[in] x
	*	uint
	*@param[in] y
	*	uint
	*@param[in] borrow
	*	uint
	*/
	inline IntrinsicCallPtr makeUsubBorrow1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt );
		assert( y->getType()->getRawKind() == type::Kind::eUInt );
		assert( borrow->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eUsubBorrow1
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*@param[in] borrow
	*	vec2u
	*/
	inline IntrinsicCallPtr makeUsubBorrow2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		assert( borrow->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eUsubBorrow2
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*@param[in] borrow
	*	vec3u
	*/
	inline IntrinsicCallPtr makeUsubBorrow3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		assert( borrow->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eUsubBorrow3
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*@param[in] borrow
	*	vec4u
	*/
	inline IntrinsicCallPtr makeUsubBorrow4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		assert( borrow->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eUsubBorrow4
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	uint
	*@param[in] y
	*	uint
	*@param[in] msb
	*	uint
	*@param[in] lsb
	*	uint
	*/
	inline IntrinsicCallPtr makeUmulExtended1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt );
		assert( y->getType()->getRawKind() == type::Kind::eUInt );
		assert( msb->getType()->getRawKind() == type::Kind::eUInt );
		assert( lsb->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	vec2u
	*@param[in] y
	*	vec2u
	*@param[in] msb
	*	vec2u
	*@param[in] lsb
	*	vec2u
	*/
	inline IntrinsicCallPtr makeUmulExtended2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U );
		assert( msb->getType()->getRawKind() == type::Kind::eVec2U );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	vec3u
	*@param[in] y
	*	vec3u
	*@param[in] msb
	*	vec3u
	*@param[in] lsb
	*	vec3u
	*/
	inline IntrinsicCallPtr makeUmulExtended3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U );
		assert( msb->getType()->getRawKind() == type::Kind::eVec3U );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	vec4u
	*@param[in] y
	*	vec4u
	*@param[in] msb
	*	vec4u
	*@param[in] lsb
	*	vec4u
	*/
	inline IntrinsicCallPtr makeUmulExtended4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U );
		assert( msb->getType()->getRawKind() == type::Kind::eVec4U );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	int
	*@param[in] y
	*	int
	*@param[in] msb
	*	int
	*@param[in] lsb
	*	int
	*/
	inline IntrinsicCallPtr makeImulExtended1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt );
		assert( y->getType()->getRawKind() == type::Kind::eInt );
		assert( msb->getType()->getRawKind() == type::Kind::eInt );
		assert( lsb->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	vec2i
	*@param[in] y
	*	vec2i
	*@param[in] msb
	*	vec2i
	*@param[in] lsb
	*	vec2i
	*/
	inline IntrinsicCallPtr makeImulExtended2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I );
		assert( msb->getType()->getRawKind() == type::Kind::eVec2I );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	vec3i
	*@param[in] y
	*	vec3i
	*@param[in] msb
	*	vec3i
	*@param[in] lsb
	*	vec3i
	*/
	inline IntrinsicCallPtr makeImulExtended3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I );
		assert( msb->getType()->getRawKind() == type::Kind::eVec3I );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	vec4i
	*@param[in] y
	*	vec4i
	*@param[in] msb
	*	vec4i
	*@param[in] lsb
	*	vec4i
	*/
	inline IntrinsicCallPtr makeImulExtended4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I );
		assert( msb->getType()->getRawKind() == type::Kind::eVec4I );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	int
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract1I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitfieldExtract1I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2i
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract2I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldExtract2I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3i
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract3I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldExtract3I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4i
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract4I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldExtract4I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	uint
	*@param[in] value
	*	uint
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract1U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitfieldExtract1U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] value
	*	vec2u
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract2U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldExtract2U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] value
	*	vec3u
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract3U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldExtract3U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] value
	*	vec4u
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldExtract4U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldExtract4U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	int
	*@param[in] base
	*	int
	*@param[in] insert
	*	int
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert1I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eInt );
		assert( insert->getType()->getRawKind() == type::Kind::eInt );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitfieldInsert1I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] base
	*	vec2i
	*@param[in] insert
	*	vec2i
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert2I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec2I );
		assert( insert->getType()->getRawKind() == type::Kind::eVec2I );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldInsert2I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] base
	*	vec3i
	*@param[in] insert
	*	vec3i
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert3I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec3I );
		assert( insert->getType()->getRawKind() == type::Kind::eVec3I );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldInsert3I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] base
	*	vec4i
	*@param[in] insert
	*	vec4i
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert4I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec4I );
		assert( insert->getType()->getRawKind() == type::Kind::eVec4I );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldInsert4I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	uint
	*@param[in] base
	*	uint
	*@param[in] insert
	*	uint
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert1U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eUInt );
		assert( insert->getType()->getRawKind() == type::Kind::eUInt );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitfieldInsert1U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] base
	*	vec2u
	*@param[in] insert
	*	vec2u
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert2U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec2U );
		assert( insert->getType()->getRawKind() == type::Kind::eVec2U );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldInsert2U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] base
	*	vec3u
	*@param[in] insert
	*	vec3u
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert3U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec3U );
		assert( insert->getType()->getRawKind() == type::Kind::eVec3U );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldInsert3U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] base
	*	vec4u
	*@param[in] insert
	*	vec4u
	*@param[in] offset
	*	int
	*@param[in] bits
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldInsert4U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec4U );
		assert( insert->getType()->getRawKind() == type::Kind::eVec4U );
		assert( offset->getType()->getRawKind() == type::Kind::eInt );
		assert( bits->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldInsert4U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	int
	*/
	inline IntrinsicCallPtr makeBitfieldReverse1I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitfieldReverse1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2i
	*/
	inline IntrinsicCallPtr makeBitfieldReverse2I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldReverse2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3i
	*/
	inline IntrinsicCallPtr makeBitfieldReverse3I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldReverse3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4i
	*/
	inline IntrinsicCallPtr makeBitfieldReverse4I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldReverse4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint
	*@param[in] value
	*	uint
	*/
	inline IntrinsicCallPtr makeBitfieldReverse1U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitfieldReverse1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] value
	*	vec2u
	*/
	inline IntrinsicCallPtr makeBitfieldReverse2U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldReverse2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] value
	*	vec3u
	*/
	inline IntrinsicCallPtr makeBitfieldReverse3U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldReverse3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] value
	*	vec4u
	*/
	inline IntrinsicCallPtr makeBitfieldReverse4U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldReverse4U
			, std::move( value ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	int
	*/
	inline IntrinsicCallPtr makeBitCount1I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitCount1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2i
	*/
	inline IntrinsicCallPtr makeBitCount2I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitCount2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3i
	*/
	inline IntrinsicCallPtr makeBitCount3I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitCount3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4i
	*/
	inline IntrinsicCallPtr makeBitCount4I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitCount4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint
	*@param[in] value
	*	uint
	*/
	inline IntrinsicCallPtr makeBitCount1U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitCount1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u
	*@param[in] value
	*	vec2u
	*/
	inline IntrinsicCallPtr makeBitCount2U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitCount2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u
	*@param[in] value
	*	vec3u
	*/
	inline IntrinsicCallPtr makeBitCount3U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitCount3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u
	*@param[in] value
	*	vec4u
	*/
	inline IntrinsicCallPtr makeBitCount4U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitCount4U
			, std::move( value ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	int
	*/
	inline IntrinsicCallPtr makeFindLSB1I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindLSB1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2i
	*/
	inline IntrinsicCallPtr makeFindLSB2I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3i
	*/
	inline IntrinsicCallPtr makeFindLSB3I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4i
	*/
	inline IntrinsicCallPtr makeFindLSB4I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4I
			, std::move( value ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	uint
	*/
	inline IntrinsicCallPtr makeFindLSB1U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindLSB1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2u
	*/
	inline IntrinsicCallPtr makeFindLSB2U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3u
	*/
	inline IntrinsicCallPtr makeFindLSB3U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4u
	*/
	inline IntrinsicCallPtr makeFindLSB4U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4U
			, std::move( value ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	int
	*/
	inline IntrinsicCallPtr makeFindMSB1I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindMSB1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2i
	*/
	inline IntrinsicCallPtr makeFindMSB2I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3i
	*/
	inline IntrinsicCallPtr makeFindMSB3I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4i
	*/
	inline IntrinsicCallPtr makeFindMSB4I( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4I
			, std::move( value ) );
	}
	/**
	*@return
	*	int
	*@param[in] value
	*	uint
	*/
	inline IntrinsicCallPtr makeFindMSB1U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindMSB1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i
	*@param[in] value
	*	vec2u
	*/
	inline IntrinsicCallPtr makeFindMSB2U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i
	*@param[in] value
	*	vec3u
	*/
	inline IntrinsicCallPtr makeFindMSB3U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i
	*@param[in] value
	*	vec4u
	*/
	inline IntrinsicCallPtr makeFindMSB4U( type::TypesCache & cache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4U
			, std::move( value ) );
	}
	// Atomic Memory Functions

	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicAddI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicAddI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicAddU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicAddU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param[in] mem
	*	float
	*@param[in] data
	*	float
	*/
	inline IntrinsicCallPtr makeAtomicAddF( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eFloat );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtomicAddF
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param[in] mem
	*	vec2h
	*@param[in] data
	*	vec2h
	*/
	inline IntrinsicCallPtr makeAtomicAdd2H( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec2H );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2H )
			, Intrinsic::eAtomicAdd2H
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param[in] mem
	*	vec4h
	*@param[in] data
	*	vec4h
	*/
	inline IntrinsicCallPtr makeAtomicAdd4H( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec4H );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4H )
			, Intrinsic::eAtomicAdd4H
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicMinI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicMinI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicMinU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicMinU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicMaxI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicMaxI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicMaxU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicMaxU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicAndI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicAndI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicAndU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicAndU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicOrI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicOrI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicOrU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicOrU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicXorI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicXorI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicXorU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicXorU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicExchangeI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicExchangeI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicExchangeU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicExchangeU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	float
	*@param[in] mem
	*	float
	*@param[in] data
	*	float
	*/
	inline IntrinsicCallPtr makeAtomicExchangeF( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eFloat );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtomicExchangeF
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec2h
	*@param[in] mem
	*	vec2h
	*@param[in] data
	*	vec2h
	*/
	inline IntrinsicCallPtr makeAtomicExchange2H( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec2H );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2H )
			, Intrinsic::eAtomicExchange2H
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	vec4h
	*@param[in] mem
	*	vec4h
	*@param[in] data
	*	vec4h
	*/
	inline IntrinsicCallPtr makeAtomicExchange4H( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec4H );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4H )
			, Intrinsic::eAtomicExchange4H
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int
	*@param[in] mem
	*	int
	*@param[in] compare
	*	int
	*@param[in] data
	*	int
	*/
	inline IntrinsicCallPtr makeAtomicCompSwapI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt );
		assert( compare->getType()->getRawKind() == type::Kind::eInt );
		assert( data->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicCompSwapI
			, std::move( mem )
			, std::move( compare )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint
	*@param[in] mem
	*	uint
	*@param[in] compare
	*	uint
	*@param[in] data
	*	uint
	*/
	inline IntrinsicCallPtr makeAtomicCompSwapU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt );
		assert( data->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicCompSwapU
			, std::move( mem )
			, std::move( compare )
			, std::move( data ) );
	}
	// Derivative Functions

	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdx1( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdx1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdx2( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdx2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdx3( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdx3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdx4( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdx4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdxCoarse1( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdxCoarse1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdxCoarse2( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdxCoarse2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdxCoarse3( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdxCoarse3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdxCoarse4( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdxCoarse4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdxFine1( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdxFine1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdxFine2( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdxFine2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdxFine3( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdxFine3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdxFine4( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdxFine4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdy1( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdy1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdy2( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdy2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdy3( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdy3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdy4( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdy4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdyCoarse1( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdyCoarse1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdyCoarse2( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdyCoarse2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdyCoarse3( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdyCoarse3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdyCoarse4( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdyCoarse4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdyFine1( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdyFine1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdyFine2( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdyFine2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdyFine3( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdyFine3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdyFine4( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdyFine4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeFwidth1( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFwidth1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFwidth2( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFwidth2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFwidth3( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFwidth3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFwidth4( type::TypesCache & cache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFwidth4
			, std::move( p ) );
	}
	// Interpolation Functions

	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeInterpolateAtCentroid1( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtCentroid1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInterpolateAtCentroid2( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtCentroid2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeInterpolateAtCentroid3( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtCentroid3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeInterpolateAtCentroid4( type::TypesCache & cache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtCentroid4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] interpolant
	*	float
	*@param[in] sample
	*	int
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample1( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eFloat );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtSample1
			, std::move( interpolant )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] interpolant
	*	vec2f
	*@param[in] sample
	*	int
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample2( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec2F );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtSample2
			, std::move( interpolant )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] interpolant
	*	vec3f
	*@param[in] sample
	*	int
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample3( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec3F );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtSample3
			, std::move( interpolant )
			, std::move( sample ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] interpolant
	*	vec4f
	*@param[in] sample
	*	int
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample4( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec4F );
		assert( sample->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtSample4
			, std::move( interpolant )
			, std::move( sample ) );
	}
	/**
	*@return
	*	float
	*@param[in] interpolant
	*	float
	*@param[in] offset
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInterpolateAtOffset1( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eFloat );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtOffset1
			, std::move( interpolant )
			, std::move( offset ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] interpolant
	*	vec2f
	*@param[in] offset
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInterpolateAtOffset2( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec2F );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtOffset2
			, std::move( interpolant )
			, std::move( offset ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] interpolant
	*	vec3f
	*@param[in] offset
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInterpolateAtOffset3( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec3F );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtOffset3
			, std::move( interpolant )
			, std::move( offset ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] interpolant
	*	vec4f
	*@param[in] offset
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInterpolateAtOffset4( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec4F );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtOffset4
			, std::move( interpolant )
			, std::move( offset ) );
	}
	// Geometry Shader Functions

	/**
	*@return
	*	void
	*@param[in] stream
	*	int
	*/
	inline IntrinsicCallPtr makeEmitStreamVertex( type::TypesCache & cache
		, ExprPtr stream )
	{
		assert( stream->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEmitStreamVertex
			, std::move( stream ) );
	}
	/**
	*@return
	*	void
	*@param[in] stream
	*	int
	*/
	inline IntrinsicCallPtr makeEndStreamPrimitive( type::TypesCache & cache
		, ExprPtr stream )
	{
		assert( stream->getType()->getRawKind() == type::Kind::eInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEndStreamPrimitive
			, std::move( stream ) );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeEmitVertex( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEmitVertex );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeEndPrimitive( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEndPrimitive );
	}
	// Shader Invocation Control Functions

	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeBarrier( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eBarrier );
	}
	// Shader Memory Control Functions

	/**
	*@return
	*	uint
	*/
	inline IntrinsicCallPtr makeMemoryBarrier( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eMemoryBarrier );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeMemoryBarrierBuffer( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierBuffer );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeMemoryBarrierShared( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierShared );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeMemoryBarrierImage( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierImage );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeGroupMemoryBarrier( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eGroupMemoryBarrier );
	}
	// Ray tracing Shader Functions

	/**
	*@return
	*	void
	*@param[in] topLevel
	*	accelerationstructure
	*@param[in] rayFlags
	*	uint
	*@param[in] cullMask
	*	uint
	*@param[in] sbtRecordOffset
	*	uint
	*@param[in] sbtRecordStride
	*	uint
	*@param[in] missIndex
	*	uint
	*@param[in] rayDesc
	*	raydesc
	*@param[in] payload
	*	raypayload
	*/
	inline IntrinsicCallPtr makeTraceRay( type::TypesCache & cache
		, ExprPtr topLevel
		, ExprPtr rayFlags
		, ExprPtr cullMask
		, ExprPtr sbtRecordOffset
		, ExprPtr sbtRecordStride
		, ExprPtr missIndex
		, ExprPtr rayDesc
		, ExprPtr payload )
	{
		assert( topLevel->getType()->getRawKind() == type::Kind::eAccelerationStructure );
		assert( rayFlags->getType()->getRawKind() == type::Kind::eUInt );
		assert( cullMask->getType()->getRawKind() == type::Kind::eUInt );
		assert( sbtRecordOffset->getType()->getRawKind() == type::Kind::eUInt );
		assert( sbtRecordStride->getType()->getRawKind() == type::Kind::eUInt );
		assert( missIndex->getType()->getRawKind() == type::Kind::eUInt );
		assert( rayDesc->getType()->getRawKind() == type::Kind::eRayDesc );
		assert( payload->getType()->getRawKind() == type::Kind::eRayPayload );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eTraceRay
			, std::move( topLevel )
			, std::move( rayFlags )
			, std::move( cullMask )
			, std::move( sbtRecordOffset )
			, std::move( sbtRecordStride )
			, std::move( missIndex )
			, std::move( rayDesc )
			, std::move( payload ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] hitT
	*	float
	*@param[in] hitKind
	*	uint
	*@param[in] attribs
	*	hitattribute
	*/
	inline IntrinsicCallPtr makeReportIntersection( type::TypesCache & cache
		, ExprPtr hitT
		, ExprPtr hitKind
		, ExprPtr attribs )
	{
		assert( hitT->getType()->getRawKind() == type::Kind::eFloat );
		assert( hitKind->getType()->getRawKind() == type::Kind::eUInt );
		assert( attribs->getType()->getRawKind() == type::Kind::eHitAttribute );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eReportIntersection
			, std::move( hitT )
			, std::move( hitKind )
			, std::move( attribs ) );
	}
	/**
	*@return
	*	void
	*@param[in] sbtRecordIndex
	*	uint
	*@param[in] callable
	*	callabledata
	*/
	inline IntrinsicCallPtr makeExecuteCallable( type::TypesCache & cache
		, ExprPtr sbtRecordIndex
		, ExprPtr callable )
	{
		assert( sbtRecordIndex->getType()->getRawKind() == type::Kind::eUInt );
		assert( callable->getType()->getRawKind() == type::Kind::eCallableData );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eExecuteCallable
			, std::move( sbtRecordIndex )
			, std::move( callable ) );
	}
	//Mesh Shader Functions

	/**
	*@return
	*	void
	*@param[in] numVertices
	*	uint
	*@param[in] numPrimitives
	*	uint
	*/
	inline IntrinsicCallPtr makeSetMeshOutputCounts( type::TypesCache & cache
		, ExprPtr numVertices
		, ExprPtr numPrimitives )
	{
		assert( numVertices->getType()->getRawKind() == type::Kind::eUInt );
		assert( numPrimitives->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eSetMeshOutputCounts
			, std::move( numVertices )
			, std::move( numPrimitives ) );
	}
	/**
	*@return
	*	void
	*@param[in] payload
	*	taskpayload
	*@param[in] numTasks
	*	uint
	*/
	inline IntrinsicCallPtr makeDispatchMesh( type::TypesCache & cache
		, ExprPtr payload
		, ExprPtr numTasks )
	{
		assert( payload->getType()->getRawKind() == type::Kind::eTaskPayload );
		assert( numTasks->getType()->getRawKind() == type::Kind::eUInt );
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eDispatchMesh
			, std::move( payload )
			, std::move( numTasks ) );
	}
}

#endif
