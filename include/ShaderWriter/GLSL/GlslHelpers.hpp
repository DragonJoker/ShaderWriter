/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GLSLHelpers_H___
#define ___SDW_GLSLHelpers_H___
#pragma once

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

namespace sdw::glsl
{
	std::string getTypeName( type::Kind kind );
	std::string getTypeName( type::TypePtr type );
	std::string getLocationName( var::Variable const & var );
	std::string getDirectionName( var::Variable const & var );
	std::string getStatusName( stmt::PreprocExtension::Status status );
	std::string getOperatorName( expr::Kind kind );
	std::string getLayoutName( stmt::InputLayout layout );
	std::string getLayoutName( stmt::OutputLayout layout );
	std::string getCtorName( expr::CompositeType composite
		, type::Kind component );
	bool isUnaryPre( expr::Kind kind );

	struct IntrinsicsConfig
	{
		bool requiresTexture1DShadowF{ false };
		bool requiresTexture1DShadowFBias{ false };
		bool requiresTexture2DShadowF{ false };
		bool requiresTexture2DShadowFBias{ false };
		bool requiresTextureCubeShadowF{ false };
		bool requiresTextureCubeShadowFBias{ false };
		bool requiresTexture1DArrayShadowF{ false };
		bool requiresTexture1DArrayShadowFBias{ false };
		bool requiresTexture2DArrayShadowF{ false };
		bool requiresTexture2DArrayShadowFBias{ false };
		bool requiresTexture2DRectShadowF{ false };
		bool requiresTextureProj1DShadowF{ false };
		bool requiresTextureProj1DShadowFBias{ false };
		bool requiresTextureProj2DShadowF{ false };
		bool requiresTextureProj2DShadowFBias{ false };
		bool requiresTextureProj2DRectShadowF{ false };
		bool requiresTextureLod1DShadowF{ false };
		bool requiresTextureLod2DShadowF{ false };
		bool requiresTextureLod1DArrayShadowF{ false };
		bool requiresTextureOffset2DRectShadowF{ false };
		bool requiresTextureOffset1DShadowF{ false };
		bool requiresTextureOffset1DShadowFBias{ false };
		bool requiresTextureOffset2DShadowF{ false };
		bool requiresTextureOffset2DShadowFBias{ false };
		bool requiresTextureOffset1DArrayShadowF{ false };
		bool requiresTextureOffset2DArrayShadowF{ false };
		bool requiresTextureProjOffset1DShadowF{ false };
		bool requiresTextureProjOffset1DShadowFBias{ false };
		bool requiresTextureProjOffset2DShadowF{ false };
		bool requiresTextureProjOffset2DShadowFBias{ false };
		bool requiresTextureProjOffset2DRectShadowF{ false };
		bool requiresTextureLodOffset1DShadowF{ false };
		bool requiresTextureLodOffset2DShadowF{ false };
		bool requiresTextureLodOffset1DArrayShadowF{ false };
		bool requiresTextureProjLod1DShadowF{ false };
		bool requiresTextureProjLod2DShadowF{ false };
		bool requiresTextureProjLodOffset1DShadowF{ false };
		bool requiresTextureProjLodOffset2DShadowF{ false };
		bool requiresTextureGrad2DRectShadowF{ false };
		bool requiresTextureGrad1DShadowF{ false };
		bool requiresTextureGrad2DShadowF{ false };
		bool requiresTextureGrad1DArrayShadowF{ false };
		bool requiresTextureGradOffset2DRectShadowF{ false };
		bool requiresTextureGradOffset1DShadowF{ false };
		bool requiresTextureGradOffset2DShadowF{ false };
		bool requiresTextureGradOffset1DArrayShadowF{ false };
		bool requiresTextureGradOffset2DArrayShadowF{ false };
		bool requiresTextureProjGrad1DShadowF{ false };
		bool requiresTextureProjGrad2DShadowF{ false };
		bool requiresTextureProjGrad2DRectShadowF{ false };
		bool requiresTextureProjGradOffset1DShadowF{ false };
		bool requiresTextureProjGradOffset2DShadowF{ false };
		bool requiresTextureProjGradOffset2DRectShadowF{ false };
	};
}

#endif
