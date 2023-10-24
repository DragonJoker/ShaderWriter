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
	namespace
	{
		auto findVariable( std::set< var::VariablePtr > const & vars
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

		auto findMbrVariable( std::set< var::VariablePtr > const & vars
			, var::VariablePtr outer
			, std::string_view name )
		{
			return std::find_if( vars.begin()
				, vars.end()
				, [name, &outer]( var::VariablePtr const & var )
				{
					return var->isMember()
						&& var->getOuter() == outer
						&& ( var->getFullName() == name
							|| var->getName() == name );
				} );
		}
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
	{
		push( m_container.get(), ast::var::VariableList{} );
	}

	void Shader::push( stmt::Container * container
		, ast::var::VariableList vars )
	{
		m_blocks.push_back( { {}, container } );

		if ( m_blocks.size() > 1u )
		{
			auto it = m_blocks.begin() + ptrdiff_t( m_blocks.size() - 2 );
			// move variables contained in the given list to the new scope.
			for ( auto & var : vars )
			{
				auto itVar = it->registered.find( var );

				if ( itVar != it->registered.end() )
				{
					it->registered.erase( itVar );
				}

				registerVariable( var );
			}

			// Add variables from previous scopes to current scope.
			it = m_blocks.begin();
			auto end = m_blocks.begin() + ptrdiff_t( m_blocks.size() - 1 );
			auto & block = m_blocks.back();

			while ( it != end )
			{
				for ( auto var : it->registered )
				{
					block.registered.insert( var );
				}

				++it;
			}
		}
	}

	void Shader::pop()
	{
		m_blocks.erase( m_blocks.begin() + ptrdiff_t( m_blocks.size() - 1 ) );
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
			auto result = ExprCloner::submit( expr->getExprCache()
				, static_cast< ast::stmt::Simple const & >( *m_savedStmt ).getExpr() );
			m_savedStmt = nullptr;
			return result;
		}

		m_ignore = false;
		return expr;
	}

	bool Shader::hasFunction( std::string_view name )const
	{
		auto it = findVariable( m_blocks.front().registered, name );
		return m_blocks.front().registered.end() != it;
	}

	var::VariablePtr Shader::getFunction( std::string name )
	{
		auto it = findVariable( m_blocks.front().registered, name );

		if ( it == m_blocks.front().registered.end() )
		{
			std::string text;
			text += "No registered function with the name [" + std::string( name ) + "].";
			throw std::runtime_error{ text };
		}

		return *it;
	}

	var::VariablePtr Shader::registerFunction( std::string name
		, type::FunctionPtr type )
	{
		auto it = findVariable( m_blocks.front().registered, name );

		if ( it != m_blocks.front().registered.end()
			&& type != it->get()->getType() )
		{
			std::string text;
			text += "A function with the name [" + std::string( name ) + "] is already registered, with a different type.";
			throw std::runtime_error{ text };
		}

		return *m_blocks.front().registered.emplace( ast::var::makeFunction( ++m_data.nextVarId
			, std::move( type )
			, std::move( name ) ) ).first;
	}

	bool Shader::hasVariable( std::string_view name )const
	{
		auto & block = m_blocks.back();
		auto it = findVariable( block.registered, name );
		return it != block.registered.end();
	}

	void Shader::registerVariable( var::VariablePtr var )
	{
		auto & block = m_blocks.back();
#if !defined( NDEBUG )
		auto ires = block.registered.emplace( var );
		assert( ires.second );
#else
		block.registered.emplace( var );
#endif

		if ( var->getType()->getRawKind() == type::Kind::eTessellationControlInput )
		{
			m_data.tessellationControlPoints = static_cast< type::TessellationControlInput const & >( *var->getType() ).getInputVertices();
		}
	}

	var::VariablePtr Shader::registerName( std::string name
		, type::TypePtr type
		, uint64_t flags )
	{
		auto var = var::makeVariable( ++m_data.nextVarId
			, type
			, std::move( name )
			, flags );
		registerVariable( var );
		return var;
	}

	var::VariablePtr Shader::registerName( std::string name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerName( std::move( name )
			, type
			, uint64_t( flag ) );
	}

	var::VariablePtr Shader::registerName( std::string name
		, type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, 0u );
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string name
		, type::TypePtr type
		, uint64_t flags )
	{
		flags |= uint64_t( var::Flag::eMember );
		auto result = var::makeVariable( ++m_data.nextVarId
			, outer
			, type
			, std::move( name )
			, flags );
		registerVariable( result );
		return result;
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerMember( std::move( outer )
			, std::move( name )
			, type
			, uint64_t( flag ) );
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string name
		, type::TypePtr type )
	{
		auto flags = outer->isUniform()
			? ast::var::Flag::eUniform
			: ast::var::Flag( 0u );
		return registerMember( std::move( outer )
			, std::move( name )
			, type
			, flags );
	}

	var::VariablePtr Shader::registerStaticConstant( std::string name
		, type::TypePtr type )
	{
		auto it = findVariable( m_blocks.front().registered, name );

		if ( it != m_blocks.front().registered.end()
			&& type != it->get()->getType() )
		{
			std::string text;
			text += "A static constant with the name [" + std::string( name ) + "] is already registered, with a different type.";
			throw std::runtime_error{ text };
		}

		auto result = m_blocks.front().registered.emplace( ast::var::makeVariable( ++m_data.nextVarId
			, std::move( type )
			, std::move( name )
			, var::Flag::eStatic | var::Flag::eConstant ) ).first;
		m_data.constants.emplace( std::move( name ), type );
		return *result;
	}

	var::VariablePtr Shader::registerSpecConstant( std::string name
		, uint32_t location
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eSpecialisationConstant );
		m_data.specConstants.emplace( std::move( name ), SpecConstantInfo{ { type, location } } );
		return result;
	}

	var::VariablePtr Shader::registerAccelerationStructure( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		auto result = registerName( std::move( name )
			, type
			, var::Flag::eUniform | var::Flag::eConstant );

		if ( enabled )
		{
			auto accType = getNonArrayType( type );
			assert( accType->getKind() == ast::type::Kind::eAccelerationStructure );
			m_data.accelerationStruct = AccStructInfo{ std::static_pointer_cast< type::AccelerationStructure >( accType )
				, binding
				, set };
		}

		return result;
	}

	var::VariablePtr Shader::registerSampler( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		var::VariablePtr result;

		if ( enabled )
		{
			result = registerName( name
				, type
				, var::Flag::eUniform | var::Flag::eConstant );

			auto splType = getNonArrayType( type );
			assert( splType->getKind() == ast::type::Kind::eSampler );
			m_data.samplers.emplace( std::move( name ), SamplerInfo{ { type, { binding, set } } } );
		}
		else
		{
			result = registerName( std::move( name )
				, type
				, var::Flag::eUniform | var::Flag::eConstant );
		}

		return result;
	}

	var::VariablePtr Shader::registerSampledImage( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		var::VariablePtr result;

		if ( enabled )
		{
			result = registerName( name
				, type
				, var::Flag::eUniform | var::Flag::eConstant );

			auto splType = getNonArrayType( type );
			assert( splType->getKind() == ast::type::Kind::eSampledImage );

			if ( static_cast< ast::type::SampledImage const & >( *splType ).getConfig().dimension == ast::type::ImageDim::eBuffer )
			{
				m_data.uniformTexels.emplace( std::move( name ), TextureInfo{ { type, { binding, set } } } );
			}
			else
			{
				m_data.sampled.emplace( std::move( name ), TextureInfo{ { type, { binding, set } } } );
			}
		}
		else
		{
			result = registerName( std::move( name )
				, type
				, var::Flag::eUniform | var::Flag::eConstant );
		}

		return result;
	}

	var::VariablePtr Shader::registerTexture( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		var::VariablePtr result;

		if ( enabled )
		{
			result = registerName( name
				, type
				, var::Flag::eUniform | var::Flag::eConstant );

			auto imgType = getNonArrayType( type );
			assert( imgType->getKind() == ast::type::Kind::eCombinedImage );

			if ( static_cast< ast::type::CombinedImage const & >( *imgType ).getConfig().dimension == ast::type::ImageDim::eBuffer )
			{
				m_data.uniformTexels.emplace( std::move( name ), TextureInfo{ { type, { binding, set } } } );
			}
			else
			{
				m_data.textures.emplace( std::move( name ), TextureInfo{ { type, { binding, set } } } );
			}
		}
		else
		{
			result = registerName( std::move( name )
				, type
				, var::Flag::eUniform | var::Flag::eConstant );
		}

		return result;
	}

	var::VariablePtr Shader::registerImage( std::string name
		, type::TypePtr type
		, uint32_t binding
		, uint32_t set
		, bool enabled )
	{
		var::VariablePtr result;

		if ( enabled )
		{
			result = registerName( name
				, type
				, var::Flag::eUniform | var::Flag::eConstant );

			auto imgType = getNonArrayType( type );
			assert( imgType->getKind() == ast::type::Kind::eImage );

			if ( static_cast< ast::type::Image const & >( *imgType ).getConfig().dimension == ast::type::ImageDim::eBuffer )
			{
				m_data.storageTexels.emplace( std::move( name ), ImageInfo{ { type, { binding, set } } } );
			}
			else
			{
				m_data.images.emplace( std::move( name ), ImageInfo{ { type, { binding, set } } } );
			}
		}
		else
		{
			result = registerName( std::move( name )
				, type
				, var::Flag::eUniform | var::Flag::eConstant );
		}

		return result;
	}

	var::VariablePtr Shader::registerInput( EntryPoint entryPoint
		, std::string name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		auto & inputs = m_data.inputs.emplace( entryPoint, ShaderData::InputMap{} ).first->second;
		auto it = std::find_if( inputs.begin()
			, inputs.end()
			, [&location]( std::map< std::string, InputInfo >::value_type const & lookup )
			{
				return lookup.second.location == location;
			} );

		if ( inputs.end() == it )
		{
			inputs.emplace( name, InputInfo{ { type, location } } );
		}

		if ( hasVar( name ) )
		{
			return getVar( name );
		}

		auto kind = getNonArrayType( type )->getKind();
		auto flags = attributes;

		if ( ( m_type != ast::ShaderStage::eVertex && m_type != ast::ShaderStage::eCompute )
			&& !isMeshStage( m_type )
			&& !isRayTraceStage( m_type )
			&& ( isSignedIntType( kind ) || isUnsignedIntType( kind ) ) )
		{
			flags = flags | var::Flag::eFlat;
		}

		auto result = registerName( std::move( name )
			, type
			, flags | var::Flag::eShaderInput );
		return result;
	}

	var::VariablePtr Shader::registerOutput( EntryPoint entryPoint
		, std::string name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		auto & outputs = m_data.outputs.emplace( entryPoint, ShaderData::OutputMap{} ).first->second;
		auto it = std::find_if( outputs.begin()
			, outputs.end()
			, [&location]( std::map< std::string, OutputInfo >::value_type const & lookup )
			{
				return lookup.second.location == location;
			} );

		if ( outputs.end() == it )
		{
			outputs.emplace( name, OutputInfo{ { type, location } } );
		}

		if ( hasVar( name ) )
		{
			return getVar( name );
		}

		auto kind = getNonArrayType( type )->getKind();
		auto flags = attributes;

		if ( ( m_type != ast::ShaderStage::eFragment && m_type != ast::ShaderStage::eCompute )
			&& !isMeshStage( m_type )
			&& !isRayTraceStage( m_type )
			&& ( isSignedIntType( kind ) || isUnsignedIntType( kind ) ) )
		{
			flags = flags | var::Flag::eFlat;
		}

		auto result = registerName( std::move( name )
			, type
			, flags | var::Flag::eShaderOutput );
		return result;
	}

	var::VariablePtr Shader::registerInOut( std::string name
		, uint64_t attributes
		, type::TypePtr type )
	{
		if ( m_data.inOuts.empty() )
		{
			m_data.inOuts.emplace( name, InOutInfo{ { type } } );
		}

		if ( hasVar( name ) )
		{
			return getVar( name );
		}

		auto result = registerName( std::move( name )
			, type
			, attributes | var::Flag::eShaderOutput | var::Flag::eShaderInput );
		return result;
	}

	var::VariablePtr Shader::registerBuiltin( ast::Builtin builtin
		, type::TypePtr type
		, var::Flag flag )
	{
		auto result = var::makeBuiltin( ++m_data.nextVarId
			, builtin
			, type
			, flag );
		registerVariable( result );
		return result;
	}

	var::VariablePtr Shader::registerBlockVariable( std::string name
		, type::TypePtr type )
	{
		return registerLocale( std::move( name ), type );
	}

	var::VariablePtr Shader::registerLocale( std::string name
		, type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, var::Flag::eLocale );
	}

	var::VariablePtr Shader::registerLoopVar( std::string name
		, type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, var::Flag::eLocale | var::Flag::eLoopVar );
	}

	var::VariablePtr Shader::registerParam( std::string name
		, type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, var::Flag::eParam );
	}

	var::VariablePtr Shader::registerInParam( std::string name
		, type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, var::Flag::eInputParam );
	}

	var::VariablePtr Shader::registerOutParam( std::string name
		, type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, var::Flag::eOutputParam );
	}

	var::VariablePtr Shader::registerInOutParam( std::string name
		, type::TypePtr type )
	{
		return registerName( std::move( name )
			, type
			, uint64_t( var::Flag::eInputParam ) | uint64_t( var::Flag::eOutputParam ) );
	}

	bool Shader::hasVar( std::string_view name )const
	{
		auto curBlockIt = std::find_if( m_blocks.crbegin()
			, m_blocks.crend()
			, [&name]( Block const & lookup )
			{
				return findVariable( lookup.registered, name ) != lookup.registered.end();
			} );
		return curBlockIt != m_blocks.rend();
	}

	var::VariablePtr Shader::getVar( std::string_view name )const
	{
		std::set< var::VariablePtr >::const_iterator it;
		auto curBlockIt = std::find_if( m_blocks.crbegin()
			, m_blocks.crend()
			, [&name, &it]( Block const & lookup )
			{
				it = findVariable( lookup.registered, name );
				return it != lookup.registered.end();
			} );

		if ( curBlockIt == m_blocks.rend() )
		{
			std::string text;
			text += "No registered variable with the name [" + std::string( name ) + "].";
			throw std::runtime_error{ text };
		}

		return *it;
	}

	var::VariablePtr Shader::getMemberVar( var::VariablePtr outer
		, std::string_view name )const
	{
		std::set< var::VariablePtr >::const_iterator it;
		auto curBlockIt = std::find_if( m_blocks.crbegin()
			, m_blocks.crend()
			, [&outer, &name, &it]( Block const & lookup )
			{
				it = findMbrVariable( lookup.registered, outer, name );
				return it != lookup.registered.end();
			} );

		if ( curBlockIt == m_blocks.rend() )
		{
			std::string text;
			text += "No registered member variable with the name [" + std::string( name ) + "].";
			throw std::runtime_error{ text };
		}

		return *it;
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

	void Shader::addGlobalStmt( stmt::StmtPtr stmt )
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
			getGlobalContainer()->addStmt( std::move( stmt ) );
		}
	}

	void Shader::registerSsbo( std::string name
		, SsboInfo const & info )
	{
		m_data.ssbos.emplace( std::move( name ), info );
	}

	void Shader::registerUbo( std::string name
		, UboInfo const & info )
	{
		m_data.ubos.emplace( std::move( name ), info );
	}

	void Shader::registerPcb( std::string name
		, InterfaceBlock const & info )
	{
		m_data.pcbs.emplace( std::move( name ), info );
	}

	void Shader::registerShaderRecord( std::string name
		, ShaderRecordInfo const & info )
	{
		m_data.shaderRecords.emplace( std::move( name ), info );
	}

	expr::ExprPtr Shader::getDummyExpr( type::TypePtr type )const
	{
		return m_exprCache->makeDummyExpr( type );
	}

	SdwShader Shader::getOpaqueHandle()const
	{
		return reinterpret_cast<SdwShader>(this);
	}

	Shader const & Shader::fromOpaqueHandle(SdwShader shader)
	{
		assert( shader != nullptr );

		return *reinterpret_cast<Shader const*>( shader );
	}
}
