#include "ShaderWriter/Pcb.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Pcb::Pcb( Shader & shader
		, std::string const & name
		, std::string const & instance )
		: m_shader{ shader }
		, m_name{ name }
	{
	}

	void Pcb::end()
	{
	}
}
