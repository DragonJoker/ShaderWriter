/*
See LICENSE file in root folder
*/
#include "ShaderAST/Shader.hpp"

#include "ShaderAST/Stmt/StmtSimple.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"

#include <algorithm>
#include <string_view>

namespace ast
{
	namespace shader
	{
		static auto findVariable( Set< var::VariablePtr > const & vars
			, std::string_view name )
		{
			return std::find_if( vars.begin()
				, vars.end()
				, [name]( var::VariablePtr const & var )
				{
					return ( var->getFullName() == name
						|| var->getName() == name );
				} );
		}
	}

	Shader::Shader( Shader && rhs )noexcept
		: m_type{ rhs.m_type }
		, m_ownAllocator{ std::move( rhs.m_ownAllocator ) }
		, m_allocator{ std::move( rhs.m_allocator ) }
		, m_typesCache{ std::move( rhs.m_typesCache ) }
		, m_stmtCache{ std::move( rhs.m_stmtCache ) }
		, m_exprCache{ std::move( rhs.m_exprCache ) }
		, m_container{ std::move( rhs.m_container ) }
		, m_globalVariables{ std::move( rhs.m_globalVariables ) }
	{
		rhs.m_ownAllocator = std::make_unique< ShaderAllocator >();
		rhs.m_allocator = rhs.m_ownAllocator->getBlock();
		rhs.m_globalVariables = Set< var::VariablePtr >{ rhs.m_allocator.get() };
	}

	Shader::Shader( ast::ShaderStage type
		, ShaderAllocator * allocator )
		: m_type{ type }
		, m_ownAllocator{ allocator ? nullptr : std::make_unique< ShaderAllocator >() }
		, m_allocator{ allocator ? allocator->getBlock() : m_ownAllocator->getBlock() }
		, m_typesCache{ std::make_unique< ast::type::TypesCache >() }
		, m_stmtCache{ std::make_unique< ast::stmt::StmtCache >( *m_allocator ) }
		, m_exprCache{ std::make_unique< ast::expr::ExprCache >( *m_allocator ) }
		, m_container{ m_stmtCache->makeContainer() }
		, m_globalVariables{ m_allocator.get() }
	{
	}

	bool Shader::hasGlobalVariable( std::string_view const & name )const
	{
		return shader::findVariable( m_globalVariables, name ) != m_globalVariables.end();
	}

	var::VariablePtr Shader::getGlobalVariable( std::string_view const & name )const
	{
		auto it = shader::findVariable( m_globalVariables, name );

		if ( it == m_globalVariables.end() )
		{
			throw Exception{ "No registered variable with the name [" + std::string( name ) + "]." };
		}

		return *it;
	}

	void Shader::registerGlobalVariable( var::VariablePtr var )
	{
		m_globalVariables.emplace( std::move( var ) );
	}

	uint32_t Shader::getNextVarId()
	{
		return ++m_data.nextVarId;
	}

	void Shader::setTessellationControlPoints( uint32_t v )
	{
		m_data.tessellationControlPoints = v;
	}

	void Shader::registerConstant( std::string name, type::TypePtr type )
	{
		m_data.constants.try_emplace( std::move( name )
			, std::move( type ) );
	}

	void Shader::registerSpecConstant( std::string name, type::TypePtr type, uint32_t location )
	{
		m_data.specConstants.try_emplace( std::move( name )
			, SpecConstantInfo{ { type, location } } );
	}

	void Shader::registerSampler( std::string name, type::TypePtr type, uint32_t binding, uint32_t set )
	{
		m_data.samplers.try_emplace( std::move( name )
				, SamplerInfo{ { std::move( type ), { binding, set } } } );
	}

	void Shader::registerUniformTexelBuffer( std::string name, type::TypePtr type, uint32_t binding, uint32_t set )
	{
		m_data.uniformTexels.try_emplace( std::move( name )
				, TextureInfo{ { std::move( type ), { binding, set } } } );
	}

	void Shader::registerStorageTexelBuffer( std::string name, type::TypePtr type, uint32_t binding, uint32_t set )
	{
		m_data.storageTexels.try_emplace( std::move( name )
				, ImageInfo{ { std::move( type ), { binding, set } } } );
	}

	void Shader::registerSampledImage( std::string name, type::TypePtr type, uint32_t binding, uint32_t set )
	{
		m_data.sampled.try_emplace( std::move( name )
				, TextureInfo{ { std::move( type ), { binding, set } } } );
	}

	void Shader::registerCombinedImage( std::string name, type::TypePtr type, uint32_t binding, uint32_t set )
	{
		m_data.textures.try_emplace( std::move( name )
				, TextureInfo{ { std::move( type ), { binding, set } } } );
	}

	void Shader::registerStorageImage( std::string name, type::TypePtr type, uint32_t binding, uint32_t set )
	{
		m_data.images.try_emplace( std::move( name )
				, ImageInfo{ { std::move( type ), { binding, set } } } );
	}

	void Shader::setAccelerationStruct( type::TypePtr type, uint32_t binding, uint32_t set )
	{
		m_data.accelerationStruct = AccStructInfo{ std::static_pointer_cast< type::AccelerationStructure >( type )
			, binding
			, set };
	}

	void Shader::registerInput( EntryPoint entryPoint
		, std::string name
		, uint32_t location
		, type::TypePtr type )
	{
		auto & inputs = m_data.inputs.try_emplace( entryPoint ).first->second;

		if ( auto it = std::find_if( inputs.begin()
			, inputs.end()
			, [&location]( std::map< std::string, InputInfo >::value_type const & lookup )
			{
				return lookup.second.location == location;
			} );
			inputs.end() == it )
		{
			inputs.try_emplace( std::move( name ), InputInfo{ { std::move( type ), location } } );
		}
	}

	void Shader::registerOutput( EntryPoint entryPoint
		, std::string name
		, uint32_t location
		, type::TypePtr type )
	{
		auto & outputs = m_data.outputs.try_emplace( entryPoint ).first->second;

		if ( auto it = std::find_if( outputs.begin()
			, outputs.end()
			, [&location]( std::map< std::string, OutputInfo >::value_type const & lookup )
			{
				return lookup.second.location == location;
			} );
			outputs.end() == it )
		{
			outputs.try_emplace( std::move( name ), OutputInfo{ { std::move( type ), location } } );
		}
	}

	void Shader::registerInOut( std::string name, type::TypePtr type )
	{
		if ( m_data.inOuts.empty() )
		{
			m_data.inOuts.try_emplace( std::move( name )
				, InOutInfo{ { std::move( type  )} } );
		}
	}

	void Shader::registerSsbo( std::string name
		, SsboInfo const & info )
	{
		m_data.ssbos.try_emplace( std::move( name ), info );
	}

	void Shader::registerUbo( std::string name
		, UboInfo const & info )
	{
		m_data.ubos.try_emplace( std::move( name ), info );
	}

	void Shader::registerPcb( std::string name
		, InterfaceBlock const & info )
	{
		m_data.pcbs.try_emplace( std::move( name ), info );
	}

	void Shader::registerShaderRecord( std::string name
		, ShaderRecordInfo const & info )
	{
		m_data.shaderRecords.try_emplace( std::move( name ), info );
	}

	AstShader Shader::getOpaqueHandle()const
	{
		return reinterpret_cast< AstShader >( this );
	}

	Shader const & Shader::fromOpaqueHandle( AstShader shader )
	{
		AST_Assert( shader != nullptr );

		return *reinterpret_cast< Shader const * >( shader );
	}
}
