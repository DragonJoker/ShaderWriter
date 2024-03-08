#include "ShaderAST/ShaderLog.hpp"

#pragma warning( push )
#pragma warning( disable: 5262 )
#include <iostream>
#include <sstream>
#include <mutex>
#pragma warning( pop )

namespace ast
{
	namespace log
	{
		using lock_type = std::unique_lock< std::mutex >;
	}

	void Logger::logError( std::string const & message, bool newLine )
	{
		doGetInstance().m_error( message, newLine );
	}

	void Logger::setErrorCallback( LogCallback callback )
	{
		doGetInstance().m_error = std::move( callback );
	}

	Logger & Logger::doGetInstance()
	{
		static Logger instance;
		static std::mutex mutex;

		log::lock_type lock{ mutex };
		return instance;
	}
}
