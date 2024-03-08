/*
See LICENSE file in root folder
*/
#ifndef ___AST_ShaderLog_H___
#define ___AST_ShaderLog_H___

#include "ShaderASTPrerequisites.hpp"

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <functional>
#include <memory>
#include <sstream>
#include <string>
#pragma warning( pop )

namespace ast
{
	class Logger
	{
	public:
		using LogCallback = std::function< void( std::string const & msg, bool newLine ) >;

	public:
		/**
		*\brief
		*	Logs an error message.
		*/
		SDAST_API static void logError( std::string const & message, bool newLine = true );
		/**
		*\brief
		*	Sets the error callback.
		*/
		SDAST_API static void setErrorCallback( LogCallback callback );

	private:
		Logger() = default;

		static Logger & doGetInstance();

	private:
		LogCallback m_error{ []( std::string const &, bool ){} };
	};
}

#endif
