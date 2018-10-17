/*
See LICENSE file in root folder
*/
#ifndef ___Writer_Utils_H___
#define ___Writer_Utils_H___

#include "Function.hpp"

namespace sdw
{
	class Utils
	{
	public:
		Utils( ShaderWriter & writer );
		void declareCalcTexCoord();
		void declareCalcVSPosition();
		void declareCalcWSPosition();
		void declareApplyGamma();
		void declareRemoveGamma();
		void declareLineariseDepth();
		void declareComputeAccumulation();
		void declareGetMapNormal();
		void declareFresnelSchlick();
		void declareComputeIBL();
		Vec2 calcTexCoord( Vec2 const & renderSize );
		Vec3 calcVSPosition( Vec2 const & uv
			, Float const & depth
			, Mat4 const & invProj );
		Vec3 calcWSPosition( Vec2 const & uv
			, Float const & depth
			, Mat4 const & invViewProj );
		Vec3 applyGamma( Float const & gamma
			, Vec3 const & HDR );
		Vec3 removeGamma( Float const & gamma
			, Vec3 const & sRGB );
		Vec3 getMapNormal( Vec2 const & uv
			, Vec3 const & normal
			, Vec3 const & position );
		Float lineariseDepth( Float const & depth
			, Float const & nearPlane
			, Float const & farPlane );
		Vec4 computeAccumulation( Float const & depth
			, Vec3 const & colour
			, Float const & alpha
			, Float const & nearPlane
			, Float const & farPlane );
		Vec3 fresnelSchlick( Float const & product
			, Vec3 const & f0
			, Float const & roughness );
		Vec3 computeMetallicIBL( Vec3 const & normal
			, Vec3 const & position
			, Vec3 const & albedo
			, Float const & metalness
			, Float const & roughness
			, Vec3 const & worldEye
			, SamplerCube const & irradiance
			, SamplerCube const & prefiltered
			, Sampler2D const & brdf );
		Vec3 computeSpecularIBL( Vec3 const & normal
			, Vec3 const & position
			, Vec3 const & diffuse
			, Vec3 const & specular
			, Float const & glossiness
			, Vec3 const & worldEye
			, SamplerCube const & irradiance
			, SamplerCube const & prefiltered
			, Sampler2D const & brdf );
	public:
		static uint32_t const MaxIblReflectionLod;

	private:
		ShaderWriter & m_writer;
		Function< Vec2
			, InVec2 > m_calcTexCoord;
		Function< Vec3
			, InVec2
			, InFloat
			, InMat4 > m_calcVSPosition;
		Function< Vec3
			, InVec2
			, InFloat
			, InMat4 > m_calcWSPosition;
		Function< Vec3
			, InFloat
			, InVec3 > m_applyGamma;
		Function< Vec3
			, InFloat
			, InVec3 > m_removeGamma;
		Function< Vec3
			, InVec2
			, InVec3
			, InVec3 > m_getMapNormal;
		Function< Float
			, InFloat
			, InFloat
			, InFloat > m_lineariseDepth;
		Function< Vec4
			, InFloat
			, InVec3
			, InFloat
			, InFloat
			, InFloat > m_computeAccumulation;
		Function< Vec3
			, InFloat
			, InVec3
			, InFloat > m_fresnelSchlick;
		Function< Vec3
			, InVec3
			, InVec3
			, InVec3
			, InVec3
			, InFloat
			, InFloat
			, InVec3
			, InParam< SamplerCube >
			, InParam< SamplerCube >
			, InParam< Sampler2D > > m_computeIBL;
	};
}

#endif
