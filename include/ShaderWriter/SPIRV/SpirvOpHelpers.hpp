/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvOpHelpers_H___
#define ___SDW_SpirvOpHelpers_H___
#pragma once

#include "SpirvModule.hpp"

#include <optional>
#include <string>
#include <vector>

namespace sdw::spirv
{
	uint16_t getOpBaseSize( spv::Op op );
	std::string getOpName( spv::Op op );
	spv::Op getOpCode( type::Kind kind );
	spv::Op getOpCode( expr::Kind exprKind
		, type::Kind typeKind );
	spv::Op getBinOpCode( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, bool & switchParams );
	spv::Op getOpCode( type::TypePtr type );
}

#endif
