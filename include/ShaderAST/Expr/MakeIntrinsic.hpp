/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#ifndef ___AST_ExprMakeIntrinsic_H___
#define ___AST_ExprMakeIntrinsic_H___
#pragma once

#include "ExprCache.hpp"
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
	inline IntrinsicCallPtr makeDegrees1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDegrees1
			, std::move( radians ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] radians
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDegrees2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDegrees2
			, std::move( radians ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] radians
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDegrees3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDegrees3
			, std::move( radians ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] radians
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDegrees4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr radians )
	{
		assert( radians->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDegrees4
			, std::move( radians ) );
	}
	/**
	*@return
	*	float
	*@param[in] degrees
	*	float
	*/
	inline IntrinsicCallPtr makeRadians1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRadians1F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] degrees
	*	vec2f
	*/
	inline IntrinsicCallPtr makeRadians2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRadians2F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] degrees
	*	vec3f
	*/
	inline IntrinsicCallPtr makeRadians3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRadians3F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] degrees
	*	vec4f
	*/
	inline IntrinsicCallPtr makeRadians4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr degrees )
	{
		assert( degrees->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRadians4F
			, std::move( degrees ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeCos1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCos1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeCos2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCos2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeCos3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCos3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeCos4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCos4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSin1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSin1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSin2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSin2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSin3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSin3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSin4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSin4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeTan1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTan1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeTan2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTan2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeTan3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTan3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeTan4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTan4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeCosh1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCosh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeCosh2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCosh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeCosh3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCosh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeCosh4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCosh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSinh1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSinh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSinh2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSinh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSinh3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSinh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSinh4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSinh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeTanh1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTanh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeTanh2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTanh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeTanh3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTanh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeTanh4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTanh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAcos1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAcos1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAcos2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAcos2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAcos3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAcos3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAcos4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAcos4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAsin1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAsin1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAsin2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAsin2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAsin3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAsin3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAsin4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAsin4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] y_over_x
	*	float
	*/
	inline IntrinsicCallPtr makeAtan1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtan1
			, std::move( y_over_x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] y_over_x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAtan2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAtan2
			, std::move( y_over_x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] y_over_x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAtan3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAtan3
			, std::move( y_over_x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] y_over_x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAtan4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y_over_x )
	{
		assert( y_over_x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeAtan21( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeAtan22( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeAtan23( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeAtan24( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr y
		, ExprPtr x )
	{
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeAcosh1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAcosh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAcosh2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAcosh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAcosh3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAcosh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAcosh4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAcosh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAsinh1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAsinh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAsinh2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAsinh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAsinh3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAsinh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAsinh4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAsinh4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeAtanh1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtanh1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAtanh2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAtanh2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAtanh3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAtanh3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAtanh4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makePow1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makePow2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makePow3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makePow4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeExp1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eExp1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeExp2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eExp2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeExp3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eExp3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeExp4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eExp4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeLog1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLog1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLog2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLog2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLog3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLog3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLog4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLog4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeExp21( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eExp21
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeExp22( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eExp22
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeExp23( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eExp23
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeExp24( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eExp24
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeLog21( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLog21
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLog22( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLog22
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLog23( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLog23
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLog24( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLog24
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSqrt1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSqrt1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSqrt2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSqrt2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSqrt3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSqrt3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSqrt4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSqrt4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeSqrt1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSqrt1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSqrt2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSqrt2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSqrt3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSqrt3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSqrt4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSqrt4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeInverseSqrt1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInverseSqrt1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInverseSqrt2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInverseSqrt2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeInverseSqrt3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInverseSqrt3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeInverseSqrt4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInverseSqrt4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeInverseSqrt1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eInverseSqrt1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeInverseSqrt2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eInverseSqrt2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeInverseSqrt3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eInverseSqrt3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeInverseSqrt4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeAbs1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAbs1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeAbs2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAbs2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeAbs3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAbs3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeAbs4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAbs4F
			, std::move( x ) );
	}
	/**
	*@return
	*	int32
	*@param[in] x
	*	int32
	*/
	inline IntrinsicCallPtr makeAbs1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAbs1I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] x
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeAbs2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eAbs2I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] x
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeAbs3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eAbs3I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] x
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeAbs4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eAbs4I
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeAbs1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eAbs1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeAbs2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eAbs2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeAbs3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eAbs3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeAbs4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eAbs4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeSign1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSign1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSign2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSign2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSign3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSign3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSign4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSign4F
			, std::move( x ) );
	}
	/**
	*@return
	*	int32
	*@param[in] x
	*	int32
	*/
	inline IntrinsicCallPtr makeSign1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSign1I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] x
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSign2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSign2I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] x
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSign3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSign3I
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] x
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSign4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSign4I
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeSign1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSign1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSign2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSign2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSign3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSign3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSign4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSign4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeFloor1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFloor1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFloor2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFloor2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFloor3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFloor3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFloor4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFloor4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeFloor1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFloor1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeFloor2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFloor2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeFloor3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFloor3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeFloor4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFloor4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeTrunc1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTrunc1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeTrunc2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTrunc2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeTrunc3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTrunc3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeTrunc4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTrunc4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeTrunc1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eTrunc1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeTrunc2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eTrunc2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeTrunc3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eTrunc3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeTrunc4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eTrunc4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeRound1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRound1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeRound2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRound2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeRound3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRound3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeRound4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRound4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeRound1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRound1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeRound2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRound2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeRound3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRound3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeRound4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRound4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeRoundEven1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRoundEven1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeRoundEven2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRoundEven2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeRoundEven3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRoundEven3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeRoundEven4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRoundEven4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeRoundEven1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRoundEven1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeRoundEven2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRoundEven2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeRoundEven3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRoundEven3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeRoundEven4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRoundEven4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeCeil1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCeil1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeCeil2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCeil2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeCeil3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCeil3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeCeil4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCeil4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeCeil1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eCeil1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeCeil2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eCeil2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeCeil3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eCeil3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeCeil4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eCeil4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeFract1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFract1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFract2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFract2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFract3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFract3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFract4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFract4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeFract1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFract1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeFract2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFract2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeFract3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFract3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeFract4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeMod1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeMod2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeMod3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeMod4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeMod1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeMod2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeMod3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeMod4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeModf1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( i->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeModf2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( i->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeModf3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( i->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeModf4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( i->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeModf1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( i->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeModf2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( i->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeModf3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( i->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeModf4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr i )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( i->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeMin1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeMin2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeMin3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeMin4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeMin1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeMin2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeMin3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeMin4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMin4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	int32
	*@param[in] x
	*	int32
	*@param[in] y
	*	int32
	*/
	inline IntrinsicCallPtr makeMin1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eMin1I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeMin2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eMin2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeMin3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eMin3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeMin4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eMin4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] x
	*	uint32
	*@param[in] y
	*	uint32
	*/
	inline IntrinsicCallPtr makeMin1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eMin1U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeMin2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eMin2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeMin3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eMin3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeMin4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
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
	inline IntrinsicCallPtr makeMax1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeMax2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeMax3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeMax4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeMax1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeMax2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeMax3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeMax4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMax4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	int32
	*@param[in] x
	*	int32
	*@param[in] y
	*	int32
	*/
	inline IntrinsicCallPtr makeMax1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eMax1I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeMax2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eMax2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeMax3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eMax3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeMax4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eMax4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] x
	*	uint32
	*@param[in] y
	*	uint32
	*/
	inline IntrinsicCallPtr makeMax1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eMax1U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeMax2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eMax2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeMax3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eMax3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeMax4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
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
	inline IntrinsicCallPtr makeClamp1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( minVal->getType()->getRawKind() == type::Kind::eFloat );
		assert( maxVal->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeClamp2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2F );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeClamp3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3F );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeClamp4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4F );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeClamp1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( minVal->getType()->getRawKind() == type::Kind::eDouble );
		assert( maxVal->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeClamp2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2D );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeClamp3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3D );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeClamp4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4D );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eClamp4D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	int32
	*@param[in] x
	*	int32
	*@param[in] minVal
	*	int32
	*@param[in] maxVal
	*	int32
	*/
	inline IntrinsicCallPtr makeClamp1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eInt32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eClamp1I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] x
	*	vec2i32
	*@param[in] minVal
	*	vec2i32
	*@param[in] maxVal
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeClamp2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eClamp2I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] x
	*	vec3i32
	*@param[in] minVal
	*	vec3i32
	*@param[in] maxVal
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeClamp3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eClamp3I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] x
	*	vec4i32
	*@param[in] minVal
	*	vec4i32
	*@param[in] maxVal
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeClamp4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eClamp4I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] x
	*	uint32
	*@param[in] minVal
	*	uint32
	*@param[in] maxVal
	*	uint32
	*/
	inline IntrinsicCallPtr makeClamp1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eClamp1U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] x
	*	vec2u32
	*@param[in] minVal
	*	vec2u32
	*@param[in] maxVal
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeClamp2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eClamp2U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] x
	*	vec3u32
	*@param[in] minVal
	*	vec3u32
	*@param[in] maxVal
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeClamp3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eClamp3U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] x
	*	vec4u32
	*@param[in] minVal
	*	vec4u32
	*@param[in] maxVal
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeClamp4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( minVal->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( maxVal->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
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
	inline IntrinsicCallPtr makeMix1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		assert( a->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeMix2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		assert( a->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeMix3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		assert( a->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeMix4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		assert( a->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeMix1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		assert( a->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeMix2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		assert( a->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeMix3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		assert( a->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeMix4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		assert( a->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeStep1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eFloat );
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeStep2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec2F );
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeStep3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec3F );
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeStep4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec4F );
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeStep1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eDouble );
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeStep2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec2D );
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeStep3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec3D );
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeStep4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge
		, ExprPtr x )
	{
		assert( edge->getType()->getRawKind() == type::Kind::eVec4D );
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeSmoothStep1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eFloat );
		assert( edge1->getType()->getRawKind() == type::Kind::eFloat );
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeSmoothStep2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec2F );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec2F );
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeSmoothStep3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec3F );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec3F );
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeSmoothStep4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec4F );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec4F );
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeSmoothStep1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eDouble );
		assert( edge1->getType()->getRawKind() == type::Kind::eDouble );
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeSmoothStep2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec2D );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec2D );
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeSmoothStep3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec3D );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec3D );
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeSmoothStep4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		assert( edge0->getType()->getRawKind() == type::Kind::eVec4D );
		assert( edge1->getType()->getRawKind() == type::Kind::eVec4D );
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeIsnan1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeIsnan2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeIsnan3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeIsnan4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4F
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeIsnan1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeIsnan2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeIsnan3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeIsnan4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4D
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	float
	*/
	inline IntrinsicCallPtr makeIsinf1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeIsinf2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeIsinf3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeIsinf4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4F
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeIsinf1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeIsinf2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeIsinf3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeIsinf4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4D
			, std::move( x ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eFloatBitsToInt1
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eFloatBitsToInt2
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eFloatBitsToInt3
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFloatBitsToInt4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eFloatBitsToInt4
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eFloatBitsToUInt1
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eFloatBitsToUInt2
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eFloatBitsToUInt3
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFloatBitsToUInt4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eFloatBitsToUInt4
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	int32
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eIntBitsToFloat1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eIntBitsToFloat2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eIntBitsToFloat3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeIntBitsToFloat4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eIntBitsToFloat4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	uint32
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eUintBitsToFloat1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUintBitsToFloat2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eUintBitsToFloat3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeUintBitsToFloat4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeFma1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eFloat );
		assert( b->getType()->getRawKind() == type::Kind::eFloat );
		assert( c->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeFma2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec2F );
		assert( b->getType()->getRawKind() == type::Kind::eVec2F );
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeFma3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec3F );
		assert( b->getType()->getRawKind() == type::Kind::eVec3F );
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeFma4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec4F );
		assert( b->getType()->getRawKind() == type::Kind::eVec4F );
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeFma1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eDouble );
		assert( b->getType()->getRawKind() == type::Kind::eDouble );
		assert( c->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeFma2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec2D );
		assert( b->getType()->getRawKind() == type::Kind::eVec2D );
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeFma3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec3D );
		assert( b->getType()->getRawKind() == type::Kind::eVec3D );
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeFma4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		assert( a->getType()->getRawKind() == type::Kind::eVec4D );
		assert( b->getType()->getRawKind() == type::Kind::eVec4D );
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	*	int32
	*/
	inline IntrinsicCallPtr makeFrexp1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( exp->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeFrexp2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeFrexp3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeFrexp4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	*	int32
	*/
	inline IntrinsicCallPtr makeFrexp1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( exp->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeFrexp2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeFrexp3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeFrexp4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	*	int32
	*/
	inline IntrinsicCallPtr makeLdexp1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( exp->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeLdexp2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeLdexp3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeLdexp4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	*	int32
	*/
	inline IntrinsicCallPtr makeLdexp1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( exp->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeLdexp2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeLdexp3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeLdexp4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr exp )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( exp->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eLdexp4D
			, std::move( x )
			, std::move( exp ) );
	}
	// Floating-point Pack and Unpack Functions

	/**
	*@return
	*	double
	*@param[in] v
	*	vec2u32
	*/
	inline IntrinsicCallPtr makePackDouble2x32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::ePackDouble2x32
			, std::move( v ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] v
	*	vec2f
	*/
	inline IntrinsicCallPtr makePackHalf2x16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::ePackHalf2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] v
	*	vec2f
	*/
	inline IntrinsicCallPtr makePackSnorm2x16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::ePackSnorm2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] v
	*	vec4f
	*/
	inline IntrinsicCallPtr makePackSnorm4x8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::ePackSnorm4x8
			, std::move( v ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] v
	*	vec2f
	*/
	inline IntrinsicCallPtr makePackUnorm2x16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::ePackUnorm2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] v
	*	vec4f
	*/
	inline IntrinsicCallPtr makePackUnorm4x8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::ePackUnorm4x8
			, std::move( v ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] d
	*	double
	*/
	inline IntrinsicCallPtr makeUnpackDouble2x32( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr d )
	{
		assert( d->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eUnpackDouble2x32
			, std::move( d ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] v
	*	uint32
	*/
	inline IntrinsicCallPtr makeUnpackHalf2x16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr v )
	{
		assert( v->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackHalf2x16
			, std::move( v ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	uint32
	*/
	inline IntrinsicCallPtr makeUnpackSnorm2x16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackSnorm2x16
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	uint32
	*/
	inline IntrinsicCallPtr makeUnpackSnorm4x8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eUnpackSnorm4x8
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	uint32
	*/
	inline IntrinsicCallPtr makeUnpackUnorm2x16( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackUnorm2x16
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	uint32
	*/
	inline IntrinsicCallPtr makeUnpackUnorm4x8( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeLength1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength1F
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeLength2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength2F
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeLength3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength3F
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeLength4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeLength1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength1D
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeLength2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength2D
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeLength3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength3D
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeLength4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDistance1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eFloat );
		assert( p1->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDistance2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec2F );
		assert( p1->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDistance3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec3F );
		assert( p1->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDistance4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec4F );
		assert( p1->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDistance1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eDouble );
		assert( p1->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDistance2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec2D );
		assert( p1->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDistance3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec3D );
		assert( p1->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDistance4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		assert( p0->getType()->getRawKind() == type::Kind::eVec4D );
		assert( p1->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDot1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		assert( y->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDot2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDot3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDot4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeDot1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		assert( y->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDot2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDot3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeDot4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeCrossF( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeCrossD( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeNormalize1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eNormalize1F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeNormalize2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eNormalize2F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeNormalize3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eNormalize3F
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeNormalize4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eNormalize4F
			, std::move( x ) );
	}
	/**
	*@return
	*	double
	*@param[in] x
	*	double
	*/
	inline IntrinsicCallPtr makeNormalize1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eNormalize1D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] x
	*	vec2d
	*/
	inline IntrinsicCallPtr makeNormalize2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eNormalize2D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] x
	*	vec3d
	*/
	inline IntrinsicCallPtr makeNormalize3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eNormalize3D
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] x
	*	vec4d
	*/
	inline IntrinsicCallPtr makeNormalize4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeFaceForward1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eFloat );
		assert( I->getType()->getRawKind() == type::Kind::eFloat );
		assert( Nref->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeFaceForward2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec2F );
		assert( I->getType()->getRawKind() == type::Kind::eVec2F );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeFaceForward3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec3F );
		assert( I->getType()->getRawKind() == type::Kind::eVec3F );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeFaceForward4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec4F );
		assert( I->getType()->getRawKind() == type::Kind::eVec4F );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeFaceForward1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eDouble );
		assert( I->getType()->getRawKind() == type::Kind::eDouble );
		assert( Nref->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeFaceForward2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec2D );
		assert( I->getType()->getRawKind() == type::Kind::eVec2D );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeFaceForward3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec3D );
		assert( I->getType()->getRawKind() == type::Kind::eVec3D );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeFaceForward4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		assert( N->getType()->getRawKind() == type::Kind::eVec4D );
		assert( I->getType()->getRawKind() == type::Kind::eVec4D );
		assert( Nref->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeReflect1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eFloat );
		assert( N->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeReflect2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2F );
		assert( N->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeReflect3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3F );
		assert( N->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeReflect4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4F );
		assert( N->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeReflect1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eDouble );
		assert( N->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeReflect2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2D );
		assert( N->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeReflect3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3D );
		assert( N->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeReflect4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4D );
		assert( N->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeRefract1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eFloat );
		assert( N->getType()->getRawKind() == type::Kind::eFloat );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeRefract2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2F );
		assert( N->getType()->getRawKind() == type::Kind::eVec2F );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeRefract3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3F );
		assert( N->getType()->getRawKind() == type::Kind::eVec3F );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeRefract4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4F );
		assert( N->getType()->getRawKind() == type::Kind::eVec4F );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeRefract1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eDouble );
		assert( N->getType()->getRawKind() == type::Kind::eDouble );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
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
	inline IntrinsicCallPtr makeRefract2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec2D );
		assert( N->getType()->getRawKind() == type::Kind::eVec2D );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
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
	inline IntrinsicCallPtr makeRefract3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec3D );
		assert( N->getType()->getRawKind() == type::Kind::eVec3D );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
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
	inline IntrinsicCallPtr makeRefract4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		assert( I->getType()->getRawKind() == type::Kind::eVec4D );
		assert( N->getType()->getRawKind() == type::Kind::eVec4D );
		assert( eta->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
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
	inline IntrinsicCallPtr makeMatrixCompMult2x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2F );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2F )
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
	inline IntrinsicCallPtr makeMatrixCompMult2x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3F );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x3F )
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
	inline IntrinsicCallPtr makeMatrixCompMult2x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4F );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x4F )
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
	inline IntrinsicCallPtr makeMatrixCompMult3x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2F );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x2F )
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
	inline IntrinsicCallPtr makeMatrixCompMult3x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3F );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3F )
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
	inline IntrinsicCallPtr makeMatrixCompMult3x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4F );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x4F )
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
	inline IntrinsicCallPtr makeMatrixCompMult4x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2F );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x2F )
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
	inline IntrinsicCallPtr makeMatrixCompMult4x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3F );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x3F )
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
	inline IntrinsicCallPtr makeMatrixCompMult4x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4F );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4F )
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
	inline IntrinsicCallPtr makeMatrixCompMult2x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2D );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2D )
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
	inline IntrinsicCallPtr makeMatrixCompMult2x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3D );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x3D )
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
	inline IntrinsicCallPtr makeMatrixCompMult2x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4D );
		assert( y->getType()->getRawKind() == type::Kind::eMat2x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x4D )
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
	inline IntrinsicCallPtr makeMatrixCompMult3x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2D );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x2D )
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
	inline IntrinsicCallPtr makeMatrixCompMult3x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3D );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3D )
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
	inline IntrinsicCallPtr makeMatrixCompMult3x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4D );
		assert( y->getType()->getRawKind() == type::Kind::eMat3x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x4D )
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
	inline IntrinsicCallPtr makeMatrixCompMult4x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2D );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x2D )
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
	inline IntrinsicCallPtr makeMatrixCompMult4x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3D );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x3D )
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
	inline IntrinsicCallPtr makeMatrixCompMult4x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4D );
		assert( y->getType()->getRawKind() == type::Kind::eMat4x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4D )
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
	inline IntrinsicCallPtr makeOuterProduct2x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		assert( r->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2F )
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
	inline IntrinsicCallPtr makeOuterProduct3x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		assert( r->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3F )
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
	inline IntrinsicCallPtr makeOuterProduct4x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		assert( r->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4F )
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
	inline IntrinsicCallPtr makeOuterProduct3x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		assert( r->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x3F )
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
	inline IntrinsicCallPtr makeOuterProduct2x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		assert( r->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x2F )
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
	inline IntrinsicCallPtr makeOuterProduct4x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		assert( r->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x4F )
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
	inline IntrinsicCallPtr makeOuterProduct2x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2F );
		assert( r->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x2F )
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
	inline IntrinsicCallPtr makeOuterProduct4x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4F );
		assert( r->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x4F )
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
	inline IntrinsicCallPtr makeOuterProduct3x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3F );
		assert( r->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x3F )
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
	inline IntrinsicCallPtr makeOuterProduct2x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		assert( r->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2D )
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
	inline IntrinsicCallPtr makeOuterProduct3x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		assert( r->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3D )
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
	inline IntrinsicCallPtr makeOuterProduct4x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		assert( r->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4D )
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
	inline IntrinsicCallPtr makeOuterProduct3x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		assert( r->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x3D )
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
	inline IntrinsicCallPtr makeOuterProduct2x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		assert( r->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x2D )
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
	inline IntrinsicCallPtr makeOuterProduct4x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		assert( r->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x4D )
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
	inline IntrinsicCallPtr makeOuterProduct2x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec2D );
		assert( r->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x2D )
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
	inline IntrinsicCallPtr makeOuterProduct4x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec4D );
		assert( r->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x4D )
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
	inline IntrinsicCallPtr makeOuterProduct3x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr c
		, ExprPtr r )
	{
		assert( c->getType()->getRawKind() == type::Kind::eVec3D );
		assert( r->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x3D )
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
	inline IntrinsicCallPtr makeTranspose2x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eTranspose2x2F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x2f
	*@param[in] x
	*	mat2x3f
	*/
	inline IntrinsicCallPtr makeTranspose2x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x2F )
			, Intrinsic::eTranspose2x3F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x2f
	*@param[in] x
	*	mat2x4f
	*/
	inline IntrinsicCallPtr makeTranspose2x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x2F )
			, Intrinsic::eTranspose2x4F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x3f
	*@param[in] x
	*	mat3x2f
	*/
	inline IntrinsicCallPtr makeTranspose3x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x3F )
			, Intrinsic::eTranspose3x2F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x3f
	*@param[in] x
	*	mat3x3f
	*/
	inline IntrinsicCallPtr makeTranspose3x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eTranspose3x3F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x3f
	*@param[in] x
	*	mat3x4f
	*/
	inline IntrinsicCallPtr makeTranspose3x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x3F )
			, Intrinsic::eTranspose3x4F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x4f
	*@param[in] x
	*	mat4x2f
	*/
	inline IntrinsicCallPtr makeTranspose4x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x4F )
			, Intrinsic::eTranspose4x2F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x4f
	*@param[in] x
	*	mat4x3f
	*/
	inline IntrinsicCallPtr makeTranspose4x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x4F )
			, Intrinsic::eTranspose4x3F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x4f
	*@param[in] x
	*	mat4x4f
	*/
	inline IntrinsicCallPtr makeTranspose4x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eTranspose4x4F
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x2d
	*@param[in] x
	*	mat2x2d
	*/
	inline IntrinsicCallPtr makeTranspose2x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eTranspose2x2D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x2d
	*@param[in] x
	*	mat2x3d
	*/
	inline IntrinsicCallPtr makeTranspose2x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x2D )
			, Intrinsic::eTranspose2x3D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x2d
	*@param[in] x
	*	mat2x4d
	*/
	inline IntrinsicCallPtr makeTranspose2x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat2x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x2D )
			, Intrinsic::eTranspose2x4D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x3d
	*@param[in] x
	*	mat3x2d
	*/
	inline IntrinsicCallPtr makeTranspose3x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x3D )
			, Intrinsic::eTranspose3x2D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x3d
	*@param[in] x
	*	mat3x3d
	*/
	inline IntrinsicCallPtr makeTranspose3x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eTranspose3x3D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x3d
	*@param[in] x
	*	mat3x4d
	*/
	inline IntrinsicCallPtr makeTranspose3x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat3x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x3D )
			, Intrinsic::eTranspose3x4D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat2x4d
	*@param[in] x
	*	mat4x2d
	*/
	inline IntrinsicCallPtr makeTranspose4x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x4D )
			, Intrinsic::eTranspose4x2D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat3x4d
	*@param[in] x
	*	mat4x3d
	*/
	inline IntrinsicCallPtr makeTranspose4x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x4D )
			, Intrinsic::eTranspose4x3D
			, std::move( x ) );
	}
	/**
	*@return
	*	mat4x4d
	*@param[in] x
	*	mat4x4d
	*/
	inline IntrinsicCallPtr makeTranspose4x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eMat4x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eTranspose4x4D
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] m
	*	mat2x2f
	*/
	inline IntrinsicCallPtr makeDeterminant2x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant2x2F
			, std::move( m ) );
	}
	/**
	*@return
	*	float
	*@param[in] m
	*	mat3x3f
	*/
	inline IntrinsicCallPtr makeDeterminant3x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant3x3F
			, std::move( m ) );
	}
	/**
	*@return
	*	float
	*@param[in] m
	*	mat4x4f
	*/
	inline IntrinsicCallPtr makeDeterminant4x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant4x4F
			, std::move( m ) );
	}
	/**
	*@return
	*	double
	*@param[in] m
	*	mat2x2d
	*/
	inline IntrinsicCallPtr makeDeterminant2x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant2x2D
			, std::move( m ) );
	}
	/**
	*@return
	*	double
	*@param[in] m
	*	mat3x3d
	*/
	inline IntrinsicCallPtr makeDeterminant3x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant3x3D
			, std::move( m ) );
	}
	/**
	*@return
	*	double
	*@param[in] m
	*	mat4x4d
	*/
	inline IntrinsicCallPtr makeDeterminant4x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant4x4D
			, std::move( m ) );
	}
	/**
	*@return
	*	mat2x2f
	*@param[in] m
	*	mat2x2f
	*/
	inline IntrinsicCallPtr makeInverse2x2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eInverse2x2F
			, std::move( m ) );
	}
	/**
	*@return
	*	mat3x3f
	*@param[in] m
	*	mat3x3f
	*/
	inline IntrinsicCallPtr makeInverse3x3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eInverse3x3F
			, std::move( m ) );
	}
	/**
	*@return
	*	mat4x4f
	*@param[in] m
	*	mat4x4f
	*/
	inline IntrinsicCallPtr makeInverse4x4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eInverse4x4F
			, std::move( m ) );
	}
	/**
	*@return
	*	mat2x2d
	*@param[in] m
	*	mat2x2d
	*/
	inline IntrinsicCallPtr makeInverse2x2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat2x2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eInverse2x2D
			, std::move( m ) );
	}
	/**
	*@return
	*	mat3x3d
	*@param[in] m
	*	mat3x3d
	*/
	inline IntrinsicCallPtr makeInverse3x3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat3x3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eInverse3x3D
			, std::move( m ) );
	}
	/**
	*@return
	*	mat4x4d
	*@param[in] m
	*	mat4x4d
	*/
	inline IntrinsicCallPtr makeInverse4x4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr m )
	{
		assert( m->getType()->getRawKind() == type::Kind::eMat4x4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eMat4x4D )
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
	inline IntrinsicCallPtr makeLessThan2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeLessThan3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeLessThan4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeLessThan2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeLessThan3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeLessThan4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeLessThan2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeLessThan3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeLessThan4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeLessThan2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeLessThan3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeLessThan4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeLessThanEqual2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeLessThanEqual3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeLessThanEqual4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeLessThanEqual2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeLessThanEqual3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeLessThanEqual4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeLessThanEqual2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeLessThanEqual3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeLessThanEqual4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeLessThanEqual2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeLessThanEqual3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeLessThanEqual4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeGreaterThan2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeGreaterThan3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeGreaterThan4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeGreaterThan2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeGreaterThan3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeGreaterThan4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeGreaterThan2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeGreaterThan3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeGreaterThan4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeGreaterThan2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeGreaterThan3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeGreaterThan4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeGreaterThanEqual2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeGreaterThanEqual3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeGreaterThanEqual4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeGreaterThanEqual2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeGreaterThanEqual3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeGreaterThanEqual4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeGreaterThanEqual4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeEqual2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeEqual3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeEqual4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeEqual2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeEqual3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeEqual4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeEqual2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeEqual3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeEqual4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeEqual2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeEqual3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeEqual4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeNotEqual2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		assert( y->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeNotEqual3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		assert( y->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeNotEqual4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		assert( y->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeNotEqual2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2D );
		assert( y->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
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
	inline IntrinsicCallPtr makeNotEqual3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3D );
		assert( y->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
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
	inline IntrinsicCallPtr makeNotEqual4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4D );
		assert( y->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4D
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeNotEqual2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeNotEqual3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeNotEqual4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4I
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeNotEqual2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeNotEqual3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3U
			, std::move( x )
			, std::move( y ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeNotEqual4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
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
	inline IntrinsicCallPtr makeAll2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAll2
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec3b
	*/
	inline IntrinsicCallPtr makeAll3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAll3
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec4b
	*/
	inline IntrinsicCallPtr makeAll4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAll4
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec2b
	*/
	inline IntrinsicCallPtr makeAny2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAny2
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec3b
	*/
	inline IntrinsicCallPtr makeAny3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAny3
			, std::move( x ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] x
	*	vec4b
	*/
	inline IntrinsicCallPtr makeAny4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eAny4
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] x
	*	vec2b
	*/
	inline IntrinsicCallPtr makeNot2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNot2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] x
	*	vec3b
	*/
	inline IntrinsicCallPtr makeNot3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNot3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] x
	*	vec4b
	*/
	inline IntrinsicCallPtr makeNot4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNot4
			, std::move( x ) );
	}
	// Integer Functions

	/**
	*@return
	*	uint32
	*@param[in] x
	*	uint32
	*@param[in] y
	*	uint32
	*@param[in] carry
	*	uint32
	*/
	inline IntrinsicCallPtr makeUaddCarry1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( carry->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eUaddCarry1
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*@param[in] carry
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeUaddCarry2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( carry->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eUaddCarry2
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*@param[in] carry
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeUaddCarry3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( carry->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eUaddCarry3
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*@param[in] carry
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeUaddCarry4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( carry->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eUaddCarry4
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] x
	*	uint32
	*@param[in] y
	*	uint32
	*@param[in] borrow
	*	uint32
	*/
	inline IntrinsicCallPtr makeUsubBorrow1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( borrow->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eUsubBorrow1
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] x
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*@param[in] borrow
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeUsubBorrow2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( borrow->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eUsubBorrow2
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] x
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*@param[in] borrow
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeUsubBorrow3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( borrow->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eUsubBorrow3
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] x
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*@param[in] borrow
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeUsubBorrow4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( borrow->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eUsubBorrow4
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}
	/**
	*@return
	*	void
	*@param[in] x
	*	uint32
	*@param[in] y
	*	uint32
	*@param[in] msb
	*	uint32
	*@param[in] lsb
	*	uint32
	*/
	inline IntrinsicCallPtr makeUmulExtended1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( msb->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	vec2u32
	*@param[in] y
	*	vec2u32
	*@param[in] msb
	*	vec2u32
	*@param[in] lsb
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeUmulExtended2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( msb->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	vec3u32
	*@param[in] y
	*	vec3u32
	*@param[in] msb
	*	vec3u32
	*@param[in] lsb
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeUmulExtended3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( msb->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	vec4u32
	*@param[in] y
	*	vec4u32
	*@param[in] msb
	*	vec4u32
	*@param[in] lsb
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeUmulExtended4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( msb->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	int32
	*@param[in] y
	*	int32
	*@param[in] msb
	*	int32
	*@param[in] lsb
	*	int32
	*/
	inline IntrinsicCallPtr makeImulExtended1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eInt32 );
		assert( y->getType()->getRawKind() == type::Kind::eInt32 );
		assert( msb->getType()->getRawKind() == type::Kind::eInt32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	vec2i32
	*@param[in] y
	*	vec2i32
	*@param[in] msb
	*	vec2i32
	*@param[in] lsb
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeImulExtended2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( msb->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	vec3i32
	*@param[in] y
	*	vec3i32
	*@param[in] msb
	*	vec3i32
	*@param[in] lsb
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeImulExtended3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( msb->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	vec4i32
	*@param[in] y
	*	vec4i32
	*@param[in] msb
	*	vec4i32
	*@param[in] lsb
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeImulExtended4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( y->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( msb->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( lsb->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eBitfieldExtract1I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eBitfieldExtract2I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eBitfieldExtract3I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eBitfieldExtract4I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eBitfieldExtract1U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eBitfieldExtract2U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eBitfieldExtract3U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldExtract4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eBitfieldExtract4U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	int32
	*@param[in] base
	*	int32
	*@param[in] insert
	*	int32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eInt32 );
		assert( insert->getType()->getRawKind() == type::Kind::eInt32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eBitfieldInsert1I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] base
	*	vec2i32
	*@param[in] insert
	*	vec2i32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( insert->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eBitfieldInsert2I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] base
	*	vec3i32
	*@param[in] insert
	*	vec3i32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( insert->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eBitfieldInsert3I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] base
	*	vec4i32
	*@param[in] insert
	*	vec4i32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( insert->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eBitfieldInsert4I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] base
	*	uint32
	*@param[in] insert
	*	uint32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( insert->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eBitfieldInsert1U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] base
	*	vec2u32
	*@param[in] insert
	*	vec2u32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( insert->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eBitfieldInsert2U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] base
	*	vec3u32
	*@param[in] insert
	*	vec3u32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( insert->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eBitfieldInsert3U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] base
	*	vec4u32
	*@param[in] insert
	*	vec4u32
	*@param[in] offset
	*	int32
	*@param[in] bits
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldInsert4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		assert( base->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( insert->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( offset->getType()->getRawKind() == type::Kind::eInt32 );
		assert( bits->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eBitfieldInsert4U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eBitfieldReverse1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eBitfieldReverse2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eBitfieldReverse3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eBitfieldReverse4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eBitfieldReverse1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eBitfieldReverse2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eBitfieldReverse3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeBitfieldReverse4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eBitfieldReverse4U
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeBitCount1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eBitCount1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeBitCount2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eBitCount2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeBitCount3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eBitCount3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeBitCount4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eBitCount4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeBitCount1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eBitCount1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeBitCount2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eBitCount2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeBitCount3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eBitCount3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeBitCount4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eBitCount4U
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeFindLSB1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eFindLSB1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeFindLSB2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eFindLSB2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeFindLSB3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eFindLSB3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeFindLSB4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eFindLSB4I
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeFindLSB1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eFindLSB1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeFindLSB2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eFindLSB2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeFindLSB3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eFindLSB3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeFindLSB4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eFindLSB4U
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeFindMSB1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eFindMSB1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeFindMSB2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eFindMSB2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeFindMSB3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eFindMSB3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeFindMSB4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eFindMSB4I
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeFindMSB1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eFindMSB1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeFindMSB2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eFindMSB2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeFindMSB3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eFindMSB3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeFindMSB4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eFindMSB4U
			, std::move( value ) );
	}
	// Atomic Memory Functions

	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicAddI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicAddI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicAddU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
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
	inline IntrinsicCallPtr makeAtomicAddF( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eFloat );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeAtomicAdd2H( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec2H );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2H )
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
	inline IntrinsicCallPtr makeAtomicAdd4H( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec4H );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4H )
			, Intrinsic::eAtomicAdd4H
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicMinI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicMinI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicMinU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eAtomicMinU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicMaxI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicMaxI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicMaxU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eAtomicMaxU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicAndI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicAndI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicAndU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eAtomicAndU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicOrI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicOrI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicOrU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eAtomicOrU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicXorI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicXorI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicXorU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eAtomicXorU
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicExchangeI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicExchangeI
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicExchangeU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
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
	inline IntrinsicCallPtr makeAtomicExchangeF( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eFloat );
		assert( data->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeAtomicExchange2H( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec2H );
		assert( data->getType()->getRawKind() == type::Kind::eVec2H );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2H )
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
	inline IntrinsicCallPtr makeAtomicExchange4H( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eVec4H );
		assert( data->getType()->getRawKind() == type::Kind::eVec4H );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4H )
			, Intrinsic::eAtomicExchange4H
			, std::move( mem )
			, std::move( data ) );
	}
	/**
	*@return
	*	int32
	*@param[in] mem
	*	int32
	*@param[in] compare
	*	int32
	*@param[in] data
	*	int32
	*/
	inline IntrinsicCallPtr makeAtomicCompSwapI( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eInt32 );
		assert( compare->getType()->getRawKind() == type::Kind::eInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eAtomicCompSwapI
			, std::move( mem )
			, std::move( compare )
			, std::move( data ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] mem
	*	uint32
	*@param[in] compare
	*	uint32
	*@param[in] data
	*	uint32
	*/
	inline IntrinsicCallPtr makeAtomicCompSwapU( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr mem
		, ExprPtr compare
		, ExprPtr data )
	{
		assert( mem->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( compare->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( data->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
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
	inline IntrinsicCallPtr makeDFdx1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdx1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdx2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdx2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdx3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdx3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdx4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdx4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdxCoarse1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdxCoarse1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdxCoarse2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdxCoarse2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdxCoarse3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdxCoarse3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdxCoarse4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdxCoarse4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdxFine1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdxFine1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdxFine2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdxFine2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdxFine3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdxFine3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdxFine4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdxFine4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdy1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdy1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdy2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdy2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdy3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdy3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdy4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdy4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdyCoarse1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdyCoarse1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdyCoarse2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdyCoarse2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdyCoarse3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdyCoarse3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdyCoarse4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdyCoarse4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeDFdyFine1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdyFine1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeDFdyFine2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdyFine2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeDFdyFine3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdyFine3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeDFdyFine4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdyFine4
			, std::move( p ) );
	}
	/**
	*@return
	*	float
	*@param[in] p
	*	float
	*/
	inline IntrinsicCallPtr makeFwidth1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFwidth1
			, std::move( p ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] p
	*	vec2f
	*/
	inline IntrinsicCallPtr makeFwidth2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFwidth2
			, std::move( p ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] p
	*	vec3f
	*/
	inline IntrinsicCallPtr makeFwidth3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFwidth3
			, std::move( p ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] p
	*	vec4f
	*/
	inline IntrinsicCallPtr makeFwidth4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr p )
	{
		assert( p->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeInterpolateAtCentroid1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtCentroid1
			, std::move( x ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] x
	*	vec2f
	*/
	inline IntrinsicCallPtr makeInterpolateAtCentroid2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtCentroid2
			, std::move( x ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] x
	*	vec3f
	*/
	inline IntrinsicCallPtr makeInterpolateAtCentroid3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtCentroid3
			, std::move( x ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] x
	*	vec4f
	*/
	inline IntrinsicCallPtr makeInterpolateAtCentroid4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr x )
	{
		assert( x->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtCentroid4
			, std::move( x ) );
	}
	/**
	*@return
	*	float
	*@param[in] interpolant
	*	float
	*@param[in] sample
	*	int32
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eFloat );
		assert( sample->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	*	int32
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec2F );
		assert( sample->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	*	int32
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec3F );
		assert( sample->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	*	int32
	*/
	inline IntrinsicCallPtr makeInterpolateAtSample4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec4F );
		assert( sample->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
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
	inline IntrinsicCallPtr makeInterpolateAtOffset1( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eFloat );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
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
	inline IntrinsicCallPtr makeInterpolateAtOffset2( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec2F );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
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
	inline IntrinsicCallPtr makeInterpolateAtOffset3( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec3F );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
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
	inline IntrinsicCallPtr makeInterpolateAtOffset4( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		assert( interpolant->getType()->getRawKind() == type::Kind::eVec4F );
		assert( offset->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtOffset4
			, std::move( interpolant )
			, std::move( offset ) );
	}
	// Geometry Shader Functions

	/**
	*@return
	*	void
	*@param[in] stream
	*	int32
	*/
	inline IntrinsicCallPtr makeEmitStreamVertex( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr stream )
	{
		assert( stream->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEmitStreamVertex
			, std::move( stream ) );
	}
	/**
	*@return
	*	void
	*@param[in] stream
	*	int32
	*/
	inline IntrinsicCallPtr makeEndStreamPrimitive( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr stream )
	{
		assert( stream->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEndStreamPrimitive
			, std::move( stream ) );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeEmitVertex( ExprCache & exprCache
		, type::TypesCache & typesCache )
	{
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEmitVertex );
	}
	/**
	*@return
	*	void
	*/
	inline IntrinsicCallPtr makeEndPrimitive( ExprCache & exprCache
		, type::TypesCache & typesCache )
	{
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEndPrimitive );
	}
	// Miscellaneous Functions

	/**
	*@return
	*	boolean
	*/
	inline IntrinsicCallPtr makeHelperInvocation( ExprCache & exprCache
		, type::TypesCache & typesCache )
	{
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eHelperInvocation );
	}
	// Shader Invocation and Memory Control Functions

	// Ray tracing Shader Functions

	/**
	*@return
	*	void
	*@param[in] topLevel
	*	accelerationstructure
	*@param[in] rayFlags
	*	uint32
	*@param[in] cullMask
	*	uint32
	*@param[in] sbtRecordOffset
	*	uint32
	*@param[in] sbtRecordStride
	*	uint32
	*@param[in] missIndex
	*	uint32
	*@param[in] rayDesc
	*	raydesc
	*@param[in] payload
	*	raypayload
	*/
	inline IntrinsicCallPtr makeTraceRay( ExprCache & exprCache
		, type::TypesCache & typesCache
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
		assert( rayFlags->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( cullMask->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( sbtRecordOffset->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( sbtRecordStride->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( missIndex->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( rayDesc->getType()->getRawKind() == type::Kind::eRayDesc );
		assert( payload->getType()->getRawKind() == type::Kind::eRayPayload );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
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
	*	uint32
	*@param[in] attribs
	*	hitattribute
	*/
	inline IntrinsicCallPtr makeReportIntersection( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr hitT
		, ExprPtr hitKind
		, ExprPtr attribs )
	{
		assert( hitT->getType()->getRawKind() == type::Kind::eFloat );
		assert( hitKind->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( attribs->getType()->getRawKind() == type::Kind::eHitAttribute );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eReportIntersection
			, std::move( hitT )
			, std::move( hitKind )
			, std::move( attribs ) );
	}
	/**
	*@return
	*	void
	*@param[in] sbtRecordIndex
	*	uint32
	*@param[in] callable
	*	callabledata
	*/
	inline IntrinsicCallPtr makeExecuteCallable( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr sbtRecordIndex
		, ExprPtr callable )
	{
		assert( sbtRecordIndex->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( callable->getType()->getRawKind() == type::Kind::eCallableData );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eExecuteCallable
			, std::move( sbtRecordIndex )
			, std::move( callable ) );
	}
	//Mesh Shader NV Functions

	/**
	*@return
	*	void
	*@param[in] numVertices
	*	uint32
	*@param[in] numPrimitives
	*	uint32
	*/
	inline IntrinsicCallPtr makeSetMeshOutputCountsNV( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr numVertices
		, ExprPtr numPrimitives )
	{
		assert( numVertices->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( numPrimitives->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eSetMeshOutputCountsNV
			, std::move( numVertices )
			, std::move( numPrimitives ) );
	}
	/**
	*@return
	*	void
	*@param[in] payload
	*	taskpayloadnv
	*@param[in] numTasks
	*	uint32
	*/
	inline IntrinsicCallPtr makeDispatchMeshNV( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr payload
		, ExprPtr numTasks )
	{
		assert( payload->getType()->getRawKind() == type::Kind::eTaskPayloadNV );
		assert( numTasks->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eDispatchMeshNV
			, std::move( payload )
			, std::move( numTasks ) );
	}
	/**
	*@return
	*	void
	*@param[in] indexOffset
	*	uint32
	*@param[in] packedIndices
	*	uint32
	*/
	inline IntrinsicCallPtr makeWritePackedPrimitiveIndices4x8NV( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr indexOffset
		, ExprPtr packedIndices )
	{
		assert( indexOffset->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( packedIndices->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eWritePackedPrimitiveIndices4x8NV
			, std::move( indexOffset )
			, std::move( packedIndices ) );
	}
	//Mesh Shader Functions

	/**
	*@return
	*	void
	*@param[in] numVertices
	*	uint32
	*@param[in] numPrimitives
	*	uint32
	*/
	inline IntrinsicCallPtr makeSetMeshOutputCounts( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr numVertices
		, ExprPtr numPrimitives )
	{
		assert( numVertices->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( numPrimitives->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eSetMeshOutputCounts
			, std::move( numVertices )
			, std::move( numPrimitives ) );
	}
	//Shader Subgroup Functions

	/**
	*@return
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupElect( ExprCache & exprCache
		, type::TypesCache & typesCache )
	{
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupElect );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupAll( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAll
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupAny( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAny
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual1F
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual2F
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual3F
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual4F
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual1I
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual2I
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual3I
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual4I
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual1U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual2U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual3U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual1B
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual2B
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual3B
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual4B
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual1D
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual2D
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual3D
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupAllEqual4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAllEqual4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupBroadcast1F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupBroadcast2F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupBroadcast3F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupBroadcast4F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupBroadcast1I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupBroadcast2I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupBroadcast3I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupBroadcast4I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupBroadcast1U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupBroadcast2U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupBroadcast3U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupBroadcast4U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupBroadcast1B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupBroadcast2B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupBroadcast3B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupBroadcast4B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupBroadcast1D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupBroadcast2D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupBroadcast3D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcast4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupBroadcast4D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupBroadcastFirst1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupBroadcastFirst2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupBroadcastFirst3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupBroadcastFirst4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupBroadcastFirst1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupBroadcastFirst2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupBroadcastFirst3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupBroadcastFirst4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupBroadcastFirst1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupBroadcastFirst2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupBroadcastFirst3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupBroadcastFirst4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupBroadcastFirst1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupBroadcastFirst2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupBroadcastFirst3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupBroadcastFirst4B
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupBroadcastFirst1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupBroadcastFirst2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupBroadcastFirst3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupBroadcastFirst4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupBroadcastFirst4D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupBallot( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupBallot
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInverseBallot( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupInverseBallot
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	vec4u32
	*@param[in] index
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupBallotBitExtract( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr index )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( index->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupBallotBitExtract
			, std::move( value )
			, std::move( index ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupBallotBitCount( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupBallotBitCount
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupBallotInclusiveBitCount( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupBallotInclusiveBitCount
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupBallotExclusiveBitCount( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupBallotExclusiveBitCount
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupBallotFindLSB( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupBallotFindLSB
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupBallotFindMSB( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupBallotFindMSB
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupShuffle1F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupShuffle2F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupShuffle3F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupShuffle4F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupShuffle1I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupShuffle2I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupShuffle3I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupShuffle4I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupShuffle1U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupShuffle2U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupShuffle3U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupShuffle4U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupShuffle1B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupShuffle2B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupShuffle3B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupShuffle4B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupShuffle1D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupShuffle2D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupShuffle3D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffle4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupShuffle4D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupShuffleXor1F
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupShuffleXor2F
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupShuffleXor3F
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupShuffleXor4F
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupShuffleXor1I
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupShuffleXor2I
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupShuffleXor3I
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupShuffleXor4I
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupShuffleXor1U
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupShuffleXor2U
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupShuffleXor3U
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupShuffleXor4U
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupShuffleXor1B
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupShuffleXor2B
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupShuffleXor3B
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupShuffleXor4B
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupShuffleXor1D
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupShuffleXor2D
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupShuffleXor3D
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] mask
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleXor4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr mask )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( mask->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupShuffleXor4D
			, std::move( value )
			, std::move( mask ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupShuffleUp1F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupShuffleUp2F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupShuffleUp3F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupShuffleUp4F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupShuffleUp1I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupShuffleUp2I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupShuffleUp3I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupShuffleUp4I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupShuffleUp1U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupShuffleUp2U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupShuffleUp3U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupShuffleUp4U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupShuffleUp1B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupShuffleUp2B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupShuffleUp3B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupShuffleUp4B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupShuffleUp1D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupShuffleUp2D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupShuffleUp3D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleUp4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupShuffleUp4D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupShuffleDown1F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupShuffleDown2F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupShuffleDown3F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupShuffleDown4F
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupShuffleDown1I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupShuffleDown2I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupShuffleDown3I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupShuffleDown4I
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupShuffleDown1U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupShuffleDown2U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupShuffleDown3U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupShuffleDown4U
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupShuffleDown1B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupShuffleDown2B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupShuffleDown3B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupShuffleDown4B
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupShuffleDown1D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupShuffleDown2D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupShuffleDown3D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] delta
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupShuffleDown4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr delta )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( delta->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupShuffleDown4D
			, std::move( value )
			, std::move( delta ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupAdd1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupAdd1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupAdd2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupAdd2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupAdd3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupAdd3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupAdd4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupAdd4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupAdd1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupAdd2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupAdd3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupAdd4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupAdd1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupAdd2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupAdd3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupAdd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupAdd4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupAdd1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupAdd1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupAdd2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupAdd2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupAdd3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupAdd3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupAdd4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupAdd4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupMul1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupMul1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupMul2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupMul2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupMul3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupMul3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupMul4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupMul4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupMul1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupMul1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupMul2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupMul2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupMul3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupMul3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupMul4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupMul4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupMul1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupMul1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupMul2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupMul2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupMul3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupMul3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupMul4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupMul4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupMul1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupMul1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupMul2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupMul2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupMul3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupMul3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupMul4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupMul4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupMin1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupMin1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupMin2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupMin2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupMin3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupMin3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupMin4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupMin4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupMin1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupMin1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupMin2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupMin2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupMin3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupMin3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupMin4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupMin4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupMin1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupMin1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupMin2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupMin2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupMin3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupMin3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupMin4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupMin4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupMin1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupMin1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupMin2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupMin2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupMin3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupMin3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupMin4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupMin4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupMax1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupMax1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupMax2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupMax2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupMax3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupMax3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupMax4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupMax4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupMax1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupMax1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupMax2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupMax2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupMax3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupMax3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupMax4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupMax4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupMax1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupMax1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupMax2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupMax2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupMax3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupMax3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupMax4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupMax4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupMax1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupMax1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupMax2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupMax2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupMax3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupMax3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupMax4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupMax4D
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupAnd1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupAnd2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupAnd3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupAnd4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupAnd1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupAnd2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupAnd3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupAnd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupAnd4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupAnd1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupAnd1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupAnd2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupAnd2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupAnd3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupAnd3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupAnd4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupAnd4B
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupOr1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupOr1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupOr2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupOr2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupOr3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupOr3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupOr4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupOr4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupOr1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupOr1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupOr2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupOr2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupOr3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupOr3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupOr4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupOr4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupOr1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupOr1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupOr2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupOr2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupOr3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupOr3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupOr4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupOr4B
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupXor1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupXor1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupXor2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupXor2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupXor3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupXor3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupXor4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupXor4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupXor1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupXor1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupXor2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupXor2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupXor3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupXor3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupXor4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupXor4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupXor1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupXor1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupXor2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupXor2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupXor3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupXor3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupXor4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupXor4B
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupInclusiveAdd1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupInclusiveAdd2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupInclusiveAdd3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupInclusiveAdd4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupInclusiveAdd1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupInclusiveAdd2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupInclusiveAdd3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupInclusiveAdd4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupInclusiveAdd1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupInclusiveAdd2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupInclusiveAdd3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupInclusiveAdd4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupInclusiveAdd1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupInclusiveAdd2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupInclusiveAdd3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAdd4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupInclusiveAdd4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupInclusiveMul1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupInclusiveMul2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupInclusiveMul3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupInclusiveMul4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupInclusiveMul1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupInclusiveMul2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupInclusiveMul3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupInclusiveMul4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupInclusiveMul1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupInclusiveMul2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupInclusiveMul3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupInclusiveMul4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupInclusiveMul1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupInclusiveMul2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupInclusiveMul3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMul4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupInclusiveMul4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupInclusiveMin1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupInclusiveMin2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupInclusiveMin3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupInclusiveMin4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupInclusiveMin1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupInclusiveMin2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupInclusiveMin3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupInclusiveMin4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupInclusiveMin1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupInclusiveMin2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupInclusiveMin3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupInclusiveMin4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupInclusiveMin1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupInclusiveMin2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupInclusiveMin3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMin4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupInclusiveMin4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupInclusiveMax1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupInclusiveMax2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupInclusiveMax3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupInclusiveMax4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupInclusiveMax1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupInclusiveMax2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupInclusiveMax3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupInclusiveMax4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupInclusiveMax1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupInclusiveMax2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupInclusiveMax3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupInclusiveMax4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupInclusiveMax1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupInclusiveMax2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupInclusiveMax3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveMax4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupInclusiveMax4D
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupInclusiveAnd1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupInclusiveAnd2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupInclusiveAnd3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupInclusiveAnd4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupInclusiveAnd1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupInclusiveAnd2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupInclusiveAnd3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupInclusiveAnd4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupInclusiveAnd1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupInclusiveAnd2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupInclusiveAnd3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveAnd4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupInclusiveAnd4B
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupInclusiveOr1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupInclusiveOr2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupInclusiveOr3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupInclusiveOr4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupInclusiveOr1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupInclusiveOr2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupInclusiveOr3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupInclusiveOr4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupInclusiveOr1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupInclusiveOr2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupInclusiveOr3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveOr4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupInclusiveOr4B
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupInclusiveXor1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupInclusiveXor2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupInclusiveXor3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupInclusiveXor4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupInclusiveXor1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupInclusiveXor2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupInclusiveXor3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupInclusiveXor4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupInclusiveXor1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupInclusiveXor2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupInclusiveXor3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupInclusiveXor4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupInclusiveXor4B
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupExclusiveAdd1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupExclusiveAdd2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupExclusiveAdd3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupExclusiveAdd4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupExclusiveAdd1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupExclusiveAdd2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupExclusiveAdd3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupExclusiveAdd4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupExclusiveAdd1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupExclusiveAdd2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupExclusiveAdd3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupExclusiveAdd4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupExclusiveAdd1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupExclusiveAdd2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupExclusiveAdd3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAdd4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupExclusiveAdd4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupExclusiveMul1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupExclusiveMul2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupExclusiveMul3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupExclusiveMul4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupExclusiveMul1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupExclusiveMul2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupExclusiveMul3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupExclusiveMul4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupExclusiveMul1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupExclusiveMul2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupExclusiveMul3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupExclusiveMul4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupExclusiveMul1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupExclusiveMul2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupExclusiveMul3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMul4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupExclusiveMul4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupExclusiveMin1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupExclusiveMin2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupExclusiveMin3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupExclusiveMin4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupExclusiveMin1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupExclusiveMin2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupExclusiveMin3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupExclusiveMin4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupExclusiveMin1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupExclusiveMin2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupExclusiveMin3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupExclusiveMin4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupExclusiveMin1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupExclusiveMin2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupExclusiveMin3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMin4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupExclusiveMin4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupExclusiveMax1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupExclusiveMax2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupExclusiveMax3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupExclusiveMax4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupExclusiveMax1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupExclusiveMax2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupExclusiveMax3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupExclusiveMax4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupExclusiveMax1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupExclusiveMax2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupExclusiveMax3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupExclusiveMax4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupExclusiveMax1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupExclusiveMax2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupExclusiveMax3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveMax4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupExclusiveMax4D
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupExclusiveAnd1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupExclusiveAnd2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupExclusiveAnd3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupExclusiveAnd4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupExclusiveAnd1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupExclusiveAnd2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupExclusiveAnd3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupExclusiveAnd4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupExclusiveAnd1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupExclusiveAnd2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupExclusiveAnd3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveAnd4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupExclusiveAnd4B
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupExclusiveOr1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupExclusiveOr2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupExclusiveOr3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupExclusiveOr4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupExclusiveOr1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupExclusiveOr2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupExclusiveOr3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupExclusiveOr4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupExclusiveOr1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupExclusiveOr2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupExclusiveOr3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveOr4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupExclusiveOr4B
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupExclusiveXor1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupExclusiveXor2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupExclusiveXor3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupExclusiveXor4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupExclusiveXor1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupExclusiveXor2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupExclusiveXor3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupExclusiveXor4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupExclusiveXor1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupExclusiveXor2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupExclusiveXor3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupExclusiveXor4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupExclusiveXor4B
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupClusterAdd1F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupClusterAdd2F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupClusterAdd3F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupClusterAdd4F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupClusterAdd1I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupClusterAdd2I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupClusterAdd3I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupClusterAdd4I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupClusterAdd1U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupClusterAdd2U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupClusterAdd3U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupClusterAdd4U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupClusterAdd1D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupClusterAdd2D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupClusterAdd3D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAdd4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupClusterAdd4D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupClusterMul1F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupClusterMul2F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupClusterMul3F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupClusterMul4F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupClusterMul1I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupClusterMul2I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupClusterMul3I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupClusterMul4I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupClusterMul1U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupClusterMul2U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupClusterMul3U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupClusterMul4U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupClusterMul1D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupClusterMul2D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupClusterMul3D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMul4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupClusterMul4D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupClusterMin1F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupClusterMin2F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupClusterMin3F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupClusterMin4F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupClusterMin1I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupClusterMin2I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupClusterMin3I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupClusterMin4I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupClusterMin1U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupClusterMin2U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupClusterMin3U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupClusterMin4U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupClusterMin1D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupClusterMin2D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupClusterMin3D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMin4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupClusterMin4D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupClusterMax1F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupClusterMax2F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupClusterMax3F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupClusterMax4F
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupClusterMax1I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupClusterMax2I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupClusterMax3I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupClusterMax4I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupClusterMax1U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupClusterMax2U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupClusterMax3U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupClusterMax4U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupClusterMax1D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupClusterMax2D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupClusterMax3D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterMax4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupClusterMax4D
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupClusterAnd1I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupClusterAnd2I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupClusterAnd3I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupClusterAnd4I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupClusterAnd1U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupClusterAnd2U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupClusterAnd3U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupClusterAnd4U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupClusterAnd1B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupClusterAnd2B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupClusterAnd3B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterAnd4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupClusterAnd4B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupClusterOr1I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupClusterOr2I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupClusterOr3I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupClusterOr4I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupClusterOr1U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupClusterOr2U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupClusterOr3U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupClusterOr4U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupClusterOr1B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupClusterOr2B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupClusterOr3B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterOr4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupClusterOr4B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupClusterXor1I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupClusterXor2I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupClusterXor3I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupClusterXor4I
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupClusterXor1U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupClusterXor2U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupClusterXor3U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupClusterXor4U
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupClusterXor1B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupClusterXor2B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupClusterXor3B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] clusterSize
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupClusterXor4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr clusterSize )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( clusterSize->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupClusterXor4B
			, std::move( value )
			, std::move( clusterSize ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupQuadBroadcast1F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupQuadBroadcast2F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupQuadBroadcast3F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupQuadBroadcast4F
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupQuadBroadcast1I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupQuadBroadcast2I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupQuadBroadcast3I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupQuadBroadcast4I
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupQuadBroadcast1U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupQuadBroadcast2U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupQuadBroadcast3U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupQuadBroadcast4U
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupQuadBroadcast1B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupQuadBroadcast2B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupQuadBroadcast3B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupQuadBroadcast4B
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupQuadBroadcast1D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupQuadBroadcast2D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupQuadBroadcast3D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] id
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadBroadcast4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr id )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( id->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupQuadBroadcast4D
			, std::move( value )
			, std::move( id ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupQuadSwapHorizontal1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupQuadSwapHorizontal2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupQuadSwapHorizontal3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupQuadSwapHorizontal4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupQuadSwapHorizontal4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupQuadSwapHorizontal1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupQuadSwapHorizontal2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupQuadSwapHorizontal3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupQuadSwapHorizontal4B
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupQuadSwapHorizontal1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupQuadSwapHorizontal2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupQuadSwapHorizontal3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapHorizontal4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupQuadSwapHorizontal4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupQuadSwapVertical1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupQuadSwapVertical2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupQuadSwapVertical3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupQuadSwapVertical4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupQuadSwapVertical1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupQuadSwapVertical2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupQuadSwapVertical3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupQuadSwapVertical4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupQuadSwapVertical1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupQuadSwapVertical2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupQuadSwapVertical3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupQuadSwapVertical4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupQuadSwapVertical1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupQuadSwapVertical2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupQuadSwapVertical3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupQuadSwapVertical4B
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupQuadSwapVertical1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupQuadSwapVertical2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupQuadSwapVertical3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapVertical4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupQuadSwapVertical4D
			, std::move( value ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSubgroupQuadSwapDiagonal1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSubgroupQuadSwapDiagonal2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSubgroupQuadSwapDiagonal3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSubgroupQuadSwapDiagonal4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eSubgroupQuadSwapDiagonal4U
			, std::move( value ) );
	}
	/**
	*@return
	*	boolean
	*@param[in] value
	*	boolean
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal1B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eBoolean );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eBoolean )
			, Intrinsic::eSubgroupQuadSwapDiagonal1B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2b
	*@param[in] value
	*	vec2b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal2B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eSubgroupQuadSwapDiagonal2B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3b
	*@param[in] value
	*	vec3b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal3B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eSubgroupQuadSwapDiagonal3B
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4b
	*@param[in] value
	*	vec4b
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal4B( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4B );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eSubgroupQuadSwapDiagonal4B
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSubgroupQuadSwapDiagonal1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSubgroupQuadSwapDiagonal2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSubgroupQuadSwapDiagonal3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeSubgroupQuadSwapDiagonal4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSubgroupQuadSwapDiagonal4D
			, std::move( value ) );
	}
	//Shader Invocation Group Functions

	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eReadInvocation1F
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eReadInvocation2F
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eReadInvocation3F
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eReadInvocation4F
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eReadInvocation1I
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eReadInvocation2I
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eReadInvocation3I
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eReadInvocation4I
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eReadInvocation1U
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eReadInvocation2U
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eReadInvocation3U
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eReadInvocation4U
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eReadInvocation1D
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eReadInvocation2D
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eReadInvocation3D
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*@param[in] invocationIndex
	*	uint
	*/
	inline IntrinsicCallPtr makeReadInvocation4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value
		, ExprPtr invocationIndex )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		assert( invocationIndex->getType()->getRawKind() == type::Kind::eUInt );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eReadInvocation4D
			, std::move( value )
			, std::move( invocationIndex ) );
	}
	/**
	*@return
	*	float
	*@param[in] value
	*	float
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation1F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eFloat );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eReadFirstInvocation1F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2f
	*@param[in] value
	*	vec2f
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation2F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eReadFirstInvocation2F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3f
	*@param[in] value
	*	vec3f
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation3F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eReadFirstInvocation3F
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4f
	*@param[in] value
	*	vec4f
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation4F( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4F );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eReadFirstInvocation4F
			, std::move( value ) );
	}
	/**
	*@return
	*	int32
	*@param[in] value
	*	int32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation1I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eInt32 )
			, Intrinsic::eReadFirstInvocation1I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2i32
	*@param[in] value
	*	vec2i32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation2I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2I32 )
			, Intrinsic::eReadFirstInvocation2I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3i32
	*@param[in] value
	*	vec3i32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation3I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3I32 )
			, Intrinsic::eReadFirstInvocation3I
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4i32
	*@param[in] value
	*	vec4i32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation4I( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4I32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4I32 )
			, Intrinsic::eReadFirstInvocation4I
			, std::move( value ) );
	}
	/**
	*@return
	*	uint32
	*@param[in] value
	*	uint32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation1U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eUInt32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eUInt32 )
			, Intrinsic::eReadFirstInvocation1U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2u32
	*@param[in] value
	*	vec2u32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation2U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2U32 )
			, Intrinsic::eReadFirstInvocation2U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3u32
	*@param[in] value
	*	vec3u32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation3U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3U32 )
			, Intrinsic::eReadFirstInvocation3U
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4u32
	*@param[in] value
	*	vec4u32
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation4U( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4U32 );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4U32 )
			, Intrinsic::eReadFirstInvocation4U
			, std::move( value ) );
	}
	/**
	*@return
	*	double
	*@param[in] value
	*	double
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation1D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eDouble );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eReadFirstInvocation1D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec2d
	*@param[in] value
	*	vec2d
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation2D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec2D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eReadFirstInvocation2D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec3d
	*@param[in] value
	*	vec3d
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation3D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec3D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eReadFirstInvocation3D
			, std::move( value ) );
	}
	/**
	*@return
	*	vec4d
	*@param[in] value
	*	vec4d
	*/
	inline IntrinsicCallPtr makeReadFirstInvocation4D( ExprCache & exprCache
		, type::TypesCache & typesCache
		, ExprPtr value )
	{
		assert( value->getType()->getRawKind() == type::Kind::eVec4D );
		return exprCache.makeIntrinsicCall( typesCache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eReadFirstInvocation4D
			, std::move( value ) );
	}
}

#endif
