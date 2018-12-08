/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GLSLHelpers_H___
#define ___SDW_GLSLHelpers_H___
#pragma once

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

#include <ShaderAST/Stmt/PreprocExtension.hpp>

namespace glsl
{
	std::string getTypeName( ast::type::Kind kind );
	std::string getTypeName( ast::type::TypePtr type );
	std::string getTypeArraySize( ast::type::TypePtr type );
	std::string getLocationName( ast::var::Variable const & var );
	std::string getDirectionName( ast::var::Variable const & var );
	std::string getStatusName( ast::stmt::PreprocExtension::Status status );
	std::string getOperatorName( ast::expr::Kind kind );
	std::string getLayoutName( ast::stmt::InputLayout layout );
	std::string getLayoutName( ast::stmt::OutputLayout layout );
	std::string getCtorName( ast::expr::CompositeType composite
		, ast::type::Kind component );
	bool isUnaryPre( ast::expr::Kind kind );

	struct IntrinsicsConfig
	{
		bool requiresFma1F{ false };
		bool requiresFma2F{ false };
		bool requiresFma3F{ false };
		bool requiresFma4F{ false };
		bool requiresFma1D{ false };
		bool requiresFma2D{ false };
		bool requiresFma3D{ false };
		bool requiresFma4D{ false };

		bool requiresCubeMapArray{ false };
		bool requiresTextureGather{ false };
	};
}

#endif
