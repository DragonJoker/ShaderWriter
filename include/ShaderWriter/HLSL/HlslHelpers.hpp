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

	struct Config
	{
		bool requiresRoundEven1F = false;
		bool requiresRoundEven2F = false;
		bool requiresRoundEven3F = false;
		bool requiresRoundEven4F = false;
		bool requiresRoundEven1D = false;
		bool requiresRoundEven2D = false;
		bool requiresRoundEven3D = false;
		bool requiresRoundEven4D = false;
		bool requiresPackDouble2x32 = false;
		bool requiresPackHalf2x16 = false;
		bool requiresPackSnorm2x16 = false;
		bool requiresPackSnorm4x8 = false;
		bool requiresPackUnorm2x16 = false;
		bool requiresPackUnorm4x8 = false;
		bool requiresUnpackDouble2x32 = false;
		bool requiresUnpackHalf2x16 = false;
		bool requiresUnpackSnorm2x16 = false;
		bool requiresUnpackSnorm4x8 = false;
		bool requiresUnpackUnorm2x16 = false;
		bool requiresUnpackUnorm4x8 = false;
		bool requiresInverse2x2F = false;
		bool requiresInverse3x3F = false;
		bool requiresInverse4x4F = false;
		bool requiresInverse2x2D = false;
		bool requiresInverse3x3D = false;
		bool requiresInverse4x4D = false;
		bool requiresUaddCarry1 = false;
		bool requiresUaddCarry2 = false;
		bool requiresUaddCarry3 = false;
		bool requiresUaddCarry4 = false;
		bool requiresUsubBorrow1 = false;
		bool requiresUsubBorrow2 = false;
		bool requiresUsubBorrow3 = false;
		bool requiresUsubBorrow4 = false;
		bool requiresUmulExtended1 = false;
		bool requiresUmulExtended2 = false;
		bool requiresUmulExtended3 = false;
		bool requiresUmulExtended4 = false;
		bool requiresImulExtended1 = false;
		bool requiresImulExtended2 = false;
		bool requiresImulExtended3 = false;
		bool requiresImulExtended4 = false;
		bool requiresBitfieldExtract1I = false;
		bool requiresBitfieldExtract2I = false;
		bool requiresBitfieldExtract3I = false;
		bool requiresBitfieldExtract4I = false;
		bool requiresBitfieldExtract1U = false;
		bool requiresBitfieldExtract2U = false;
		bool requiresBitfieldExtract3U = false;
		bool requiresBitfieldExtract4U = false;
		bool requiresBitfieldInsert1I = false;
		bool requiresBitfieldInsert2I = false;
		bool requiresBitfieldInsert3I = false;
		bool requiresBitfieldInsert4I = false;
		bool requiresBitfieldInsert1U = false;
		bool requiresBitfieldInsert2U = false;
		bool requiresBitfieldInsert3U = false;
		bool requiresBitfieldInsert4U = false;
	};
}

#endif
