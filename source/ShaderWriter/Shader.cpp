/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Shader.hpp"

#include <ShaderAST/Stmt/StmtSimple.hpp>

#include <algorithm>

namespace sdw
{
	Shader::Shader( ShaderType type )
		: m_container{ stmt::makeContainer() }
		, m_type{ type }
		, m_typesCache{ std::make_unique< ast::type::TypesCache >() }
	{
		push( m_container.get() );
	}

	void Shader::push( stmt::Container * container )
	{
		m_blocks.push_back( { {}, container } );
	}

	void Shader::pop()
	{
		m_blocks.erase( m_blocks.begin() + m_blocks.size() - 1u );
	}

	void Shader::saveNextExpr()
	{
		assert( m_savedStmt == nullptr );
		m_ignore = true;
	}

	ast::expr::ExprPtr Shader::loadExpr( ast::expr::ExprPtr expr )
	{
		if ( m_savedStmt != nullptr )
		{
			auto result = makeExpr( *this, static_cast< ast::stmt::Simple const & >( *m_savedStmt ).getExpr() );
			m_savedStmt = nullptr;
			return result;
		}

		m_ignore = false;
		return std::move( expr );
	}

	void Shader::registerVariable( var::VariablePtr var )
	{
		auto & block = m_blocks.back();
		auto it = block.registered.find( var->getName() );
		assert( it == block.registered.end() );
		block.registered.emplace( var->getName(), var );
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		auto var = var::makeVariable( type, name, flags );
		registerVariable( var );
		return var;
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerName( name
			, type
			, uint32_t( flag ) );
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, 0u );
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type
		, uint32_t flags )
	{
		auto & block = m_blocks.back();
		auto it = block.registered.find( name );
		assert( it == block.registered.end() );
		it = block.registered.emplace( name, var::makeVariable( outer, type, name, flags | var::Flag::eMember ) ).first;
		return it->second;
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerMember( std::move( outer )
			, name
			, type
			, uint32_t( flag ) );
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type )
	{
		return registerMember( std::move( outer )
			, name
			, type
			, outer->isUniform() ? ast::var::Flag::eUniform : ast::var::Flag( 0u ) );
	}

	var::VariablePtr Shader::registerConstant( std::string const & name
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eShaderConstant );
		m_constants.emplace( name, type );
		return result;
	}

	var::VariablePtr Shader::registerSpecConstant( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eSpecialisationConstant );
		m_specConstants.emplace( name, SpecConstantInfo{ type, location } );
		return result;
	}

	var::VariablePtr Shader::registerSampledImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eUniform | var::Flag::eConstant );

		if ( enabled )
		{
			m_samplers.emplace( name, SamplerInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr Shader::registerImage( std::string const & name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( name
			, type
			, var::Flag::eUniform | var::Flag::eConstant );

		if ( enabled )
		{
			m_images.emplace( name, ImageInfo{ type, binding, set } );
		}

		return result;
	}

	var::VariablePtr Shader::registerInput( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		auto kind = getNonArrayType( type )->getKind();
		uint32_t flags = 0u;

		if ( isSignedIntType( type->getKind() )
			|| isUnsignedIntType( type->getKind() ) )
		{
			flags = flags | var::Flag::eFlat;
		}

		auto result = registerName( name
			, type
			, flags | var::Flag::eShaderInput );
		m_inputs.emplace( name, InputInfo{ type, location } );
		return result;
	}

	var::VariablePtr Shader::registerOutput( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		assert( m_outputs.end() == std::find_if( m_outputs.begin()
			, m_outputs.end()
			, [&location]( std::map< std::string, OutputInfo >::value_type const & lookup )
			{
				return lookup.second.location == location;
			} )
			&& "Output already existing at given location" );
		auto kind = getNonArrayType( type )->getKind();
		uint32_t flags = 0u;

		if ( isSignedIntType( type->getKind() )
			|| isUnsignedIntType( type->getKind() ) )
		{
			flags = flags | var::Flag::eFlat;
		}

		auto result = registerName( name
			, type
			, flags | var::Flag::eShaderOutput );
		m_outputs.emplace( name, OutputInfo{ type, location } );
		return result;
	}

	var::VariablePtr Shader::registerBuiltin( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		var::VariablePtr result = registerName( name
			, type
			, var::Flag::eBuiltin | flag );
		return result;
	}

	var::VariablePtr Shader::registerBlockVariable( std::string const & name
		, type::TypePtr type )
	{
		if ( m_blocks.size() > 1u )
		{
			return registerLocale( name, type );
		}

		return registerConstant( name, type );
	}

	var::VariablePtr Shader::registerLocale( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eLocale );
	}

	var::VariablePtr Shader::registerParam( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eParam );
	}

	var::VariablePtr Shader::registerInParam( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eInputParam );
	}

	var::VariablePtr Shader::registerOutParam( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eOutputParam );
	}

	var::VariablePtr Shader::registerInOutParam( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, uint32_t( var::Flag::eInputParam ) | uint32_t( var::Flag::eOutputParam ) );
	}

	var::VariablePtr Shader::getVar( std::string const & name )const
	{
		auto & block = m_blocks.back();
		auto it = block.registered.find( name );

		if ( it == block.registered.end() )
		{
			it = m_blocks.front().registered.find( name );

			if ( it == m_blocks.front().registered.end() )
			{
				std::string text;
				text += "No registered variable with the name [" + name + "].";
				throw std::runtime_error{ text };
			}
		}

		return it->second;
	}

	void Shader::addStmt( stmt::StmtPtr stmt )
	{
		if ( m_ignore )
		{
			if ( stmt->getKind() == ast::stmt::Kind::eSimple )
			{
				m_savedStmt = std::move( stmt );
			}

			m_ignore = false;
		}
		else
		{
			getContainer()->addStmt( std::move( stmt ) );
		}
	}

	void Shader::registerSsbo( std::string const & name
		, SsboInfo const & info )
	{
		m_ssbos.emplace( name, info );
	}

	void Shader::registerUbo( std::string const & name
		, UboInfo const & info )
	{
		m_ubos.emplace( name, info );
	}
}
