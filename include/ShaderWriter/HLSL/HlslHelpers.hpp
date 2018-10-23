/*
See LICENSE file in root folder
*/
#ifndef ___ShaderWriter_HlslHelpers_H___
#define ___ShaderWriter_HlslHelpers_H___
#pragma once

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

namespace sdw::hlsl
{
	bool isSampler( type::Kind kind );
	std::string getTypeName( type::Kind kind );
	std::string getTypeName( type::TypePtr type );
	std::string getLocationName( var::Variable const & var );
	std::string getDirectionName( var::Variable const & var );
	std::string getOperatorName( expr::Kind kind );
	std::string getLayoutName( stmt::InputLayout layout );
	std::string getLayoutName( stmt::OutputLayout layout );
	bool isUnaryPre( expr::Kind kind );

	using LinkedVars = std::map< var::VariablePtr, std::pair< var::VariablePtr, var::VariablePtr > >;
	using VariableExprMap = std::map< var::VariablePtr, expr::ExprPtr >;

	class SamplerState
		: public type::Type
	{
	public:
		SamplerState()
			: type::Type{ type::Kind::eCount }
		{
		}
	};

	using SamplerStatePtr = std::shared_ptr< SamplerState >;

	inline SamplerStatePtr makeSampler()
	{
		return std::make_shared< SamplerState >();
	}

	struct IntrinsicsConfig
	{
		bool requiresRoundEven1F{ false };
		bool requiresRoundEven2F{ false };
		bool requiresRoundEven3F{ false };
		bool requiresRoundEven4F{ false };
		bool requiresRoundEven1D{ false };
		bool requiresRoundEven2D{ false };
		bool requiresRoundEven3D{ false };
		bool requiresRoundEven4D{ false };
		bool requiresPackDouble2x32{ false };
		bool requiresPackHalf2x16{ false };
		bool requiresPackSnorm2x16{ false };
		bool requiresPackSnorm4x8{ false };
		bool requiresPackUnorm2x16{ false };
		bool requiresPackUnorm4x8{ false };
		bool requiresUnpackDouble2x32{ false };
		bool requiresUnpackHalf2x16{ false };
		bool requiresUnpackSnorm2x16{ false };
		bool requiresUnpackSnorm4x8{ false };
		bool requiresUnpackUnorm2x16{ false };
		bool requiresUnpackUnorm4x8{ false };
		bool requiresInverse2x2F{ false };
		bool requiresInverse3x3F{ false };
		bool requiresInverse4x4F{ false };
		bool requiresInverse2x2D{ false };
		bool requiresInverse3x3D{ false };
		bool requiresInverse4x4D{ false };
		bool requiresUaddCarry1{ false };
		bool requiresUaddCarry2{ false };
		bool requiresUaddCarry3{ false };
		bool requiresUaddCarry4{ false };
		bool requiresUsubBorrow1{ false };
		bool requiresUsubBorrow2{ false };
		bool requiresUsubBorrow3{ false };
		bool requiresUsubBorrow4{ false };
		bool requiresUmulExtended1{ false };
		bool requiresUmulExtended2{ false };
		bool requiresUmulExtended3{ false };
		bool requiresUmulExtended4{ false };
		bool requiresImulExtended1{ false };
		bool requiresImulExtended2{ false };
		bool requiresImulExtended3{ false };
		bool requiresImulExtended4{ false };
		bool requiresBitfieldExtract1I{ false };
		bool requiresBitfieldExtract2I{ false };
		bool requiresBitfieldExtract3I{ false };
		bool requiresBitfieldExtract4I{ false };
		bool requiresBitfieldExtract1U{ false };
		bool requiresBitfieldExtract2U{ false };
		bool requiresBitfieldExtract3U{ false };
		bool requiresBitfieldExtract4U{ false };
		bool requiresBitfieldInsert1I{ false };
		bool requiresBitfieldInsert2I{ false };
		bool requiresBitfieldInsert3I{ false };
		bool requiresBitfieldInsert4I{ false };
		bool requiresBitfieldInsert1U{ false };
		bool requiresBitfieldInsert2U{ false };
		bool requiresBitfieldInsert3U{ false };
		bool requiresBitfieldInsert4U{ false };

		bool requiresTextureSizeBufferF{ false };
		bool requiresTextureSize1DF{ false };
		bool requiresTextureSize2DF{ false };
		bool requiresTextureSize3DF{ false };
		bool requiresTextureSizeCubeF{ false };
		bool requiresTextureSize2DRectF{ false };
		bool requiresTextureSize1DArrayF{ false };
		bool requiresTextureSize2DArrayF{ false };
		bool requiresTextureSizeCubeArrayF{ false };
		bool requiresTextureSize1DShadowF{ false };
		bool requiresTextureSize2DShadowF{ false };
		bool requiresTextureSizeCubeShadowF{ false };
		bool requiresTextureSize2DRectShadowF{ false };
		bool requiresTextureSize1DArrayShadowF{ false };
		bool requiresTextureSize2DArrayShadowF{ false };
		bool requiresTextureSizeCubeArrayShadowF{ false };
		bool requiresTextureSizeBufferI{ false };
		bool requiresTextureSize1DI{ false };
		bool requiresTextureSize2DI{ false };
		bool requiresTextureSize3DI{ false };
		bool requiresTextureSizeCubeI{ false };
		bool requiresTextureSize2DRectI{ false };
		bool requiresTextureSize1DArrayI{ false };
		bool requiresTextureSize2DArrayI{ false };
		bool requiresTextureSizeCubeArrayI{ false };
		bool requiresTextureSizeBufferU{ false };
		bool requiresTextureSize1DU{ false };
		bool requiresTextureSize2DU{ false };
		bool requiresTextureSize3DU{ false };
		bool requiresTextureSizeCubeU{ false };
		bool requiresTextureSize2DRectU{ false };
		bool requiresTextureSize1DArrayU{ false };
		bool requiresTextureSize2DArrayU{ false };
		bool requiresTextureSizeCubeArrayU{ false };
		bool requiresTextureQueryLod1DF{ false };
		bool requiresTextureQueryLod2DF{ false };
		bool requiresTextureQueryLod3DF{ false };
		bool requiresTextureQueryLodCubeF{ false };
		bool requiresTextureQueryLod1DArrayF{ false };
		bool requiresTextureQueryLod2DArrayF{ false };
		bool requiresTextureQueryLodCubeArrayF{ false };
		bool requiresTextureQueryLod1DShadowF{ false };
		bool requiresTextureQueryLod2DShadowF{ false };
		bool requiresTextureQueryLodCubeShadowF{ false };
		bool requiresTextureQueryLod1DArrayShadowF{ false };
		bool requiresTextureQueryLod2DArrayShadowF{ false };
		bool requiresTextureQueryLodCubeArrayShadowF{ false };
		bool requiresTextureQueryLod1DI{ false };
		bool requiresTextureQueryLod2DI{ false };
		bool requiresTextureQueryLod3DI{ false };
		bool requiresTextureQueryLodCubeI{ false };
		bool requiresTextureQueryLod1DArrayI{ false };
		bool requiresTextureQueryLod2DArrayI{ false };
		bool requiresTextureQueryLodCubeArrayI{ false };
		bool requiresTextureQueryLod1DU{ false };
		bool requiresTextureQueryLod2DU{ false };
		bool requiresTextureQueryLod3DU{ false };
		bool requiresTextureQueryLodCubeU{ false };
		bool requiresTextureQueryLod1DArrayU{ false };
		bool requiresTextureQueryLod2DArrayU{ false };
		bool requiresTextureQueryLodCubeArrayU{ false };
		bool requiresTextureQueryLevels1DF{ false };
		bool requiresTextureQueryLevels2DF{ false };
		bool requiresTextureQueryLevels3DF{ false };
		bool requiresTextureQueryLevelsCubeF{ false };
		bool requiresTextureQueryLevels1DArrayF{ false };
		bool requiresTextureQueryLevels2DArrayF{ false };
		bool requiresTextureQueryLevelsCubeArrayF{ false };
		bool requiresTextureQueryLevels1DShadowF{ false };
		bool requiresTextureQueryLevels2DShadowF{ false };
		bool requiresTextureQueryLevelsCubeShadowF{ false };
		bool requiresTextureQueryLevels1DArrayShadowF{ false };
		bool requiresTextureQueryLevels2DArrayShadowF{ false };
		bool requiresTextureQueryLevelsCubeArrayShadowF{ false };
		bool requiresTextureQueryLevels1DI{ false };
		bool requiresTextureQueryLevels2DI{ false };
		bool requiresTextureQueryLevels3DI{ false };
		bool requiresTextureQueryLevelsCubeI{ false };
		bool requiresTextureQueryLevels1DArrayI{ false };
		bool requiresTextureQueryLevels2DArrayI{ false };
		bool requiresTextureQueryLevelsCubeArrayI{ false };
		bool requiresTextureQueryLevels1DU{ false };
		bool requiresTextureQueryLevels2DU{ false };
		bool requiresTextureQueryLevels3DU{ false };
		bool requiresTextureQueryLevelsCubeU{ false };
		bool requiresTextureQueryLevels1DArrayU{ false };
		bool requiresTextureQueryLevels2DArrayU{ false };
		bool requiresTextureQueryLevelsCubeArrayU{ false };
		bool requiresProjectTexCoords2{ false };
		bool requiresProjectTexCoords3{ false };
		bool requiresProjectTexCoords4To1{ false };
		bool requiresProjectTexCoords4To2{ false };
		bool requiresProjectTexCoords4{ false };
	};
}

#endif
