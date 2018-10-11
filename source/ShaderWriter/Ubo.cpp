/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Ubo.hpp"

#include "ShaderWriter/Shader.hpp"

namespace sdw
{
	Ubo::Ubo( Shader & shader
		, std::string const & name
		, uint32_t bind
		, uint32_t set )
		: m_shader{ shader }
		, m_stmt{ stmt::makeConstantBufferDecl( name, bind, set ) }
		, m_name{ name }
		, m_info{ bind, set }
	{
	}

	void Ubo::end()
	{
		addStmt( m_shader, std::move( m_stmt ) );
		m_shader.registerUbo( m_name, m_info );
	}
}
