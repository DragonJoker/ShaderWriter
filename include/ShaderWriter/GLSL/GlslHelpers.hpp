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
	bool isUnaryPre( expr::Kind kind );
}

#endif
