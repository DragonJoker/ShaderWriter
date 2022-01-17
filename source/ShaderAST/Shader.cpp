/*
See LICENSE file in root folder
*/
#include "ShaderAST/Shader.hpp"

#include "ShaderAST/Stmt/StmtSimple.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"

#include <algorithm>

namespace ast
{
	namespace
	{
		auto findVariable( std::set< var::VariablePtr > const & vars
			, std::string const & name )
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
			, std::string const & name )
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

	Shader::Shader( ast::ShaderStage type )
		: m_type{ type }
		, m_typesCache{ std::make_unique< ast::type::TypesCache >() }
		, m_container{ stmt::makeContainer() }
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
			auto result = ExprCloner::submit( static_cast< ast::stmt::Simple const & >( *m_savedStmt ).getExpr() );
			m_savedStmt = nullptr;
			return result;
		}

		m_ignore = false;
		return expr;
	}

	bool Shader::hasVariable( std::string const & name )const
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
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type
		, uint64_t flags )
	{
		auto var = var::makeVariable( ++m_data.nextVarId
			, type
			, name
			, flags );
		registerVariable( var );
		return var;
	}

	var::VariablePtr Shader::registerName( std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerName( name
			, type
			, uint64_t( flag ) );
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
		, uint64_t flags )
	{
		flags |= uint64_t( var::Flag::eMember );
		auto result = var::makeVariable( ++m_data.nextVarId
			, outer
			, type
			, name
			, flags );
		registerVariable( result );
		return result;
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type
		, var::Flag flag )
	{
		return registerMember( std::move( outer )
			, name
			, type
			, uint64_t( flag ) );
	}

	var::VariablePtr Shader::registerMember( var::VariablePtr outer
		, std::string const & name
		, type::TypePtr type )
	{
		auto flags = outer->isUniform()
			? ast::var::Flag::eUniform
			: ast::var::Flag( 0u );
		return registerMember( std::move( outer )
			, name
			, type
			, flags );
	}

	var::VariablePtr Shader::registerStaticConstant( std::string const & name
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eStatic | var::Flag::eConstant );
		m_data.constants.emplace( name, type );
		return result;
	}

	var::VariablePtr Shader::registerConstant( std::string const & name
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eShaderConstant );
		m_data.constants.emplace( name, type );
		return result;
	}

	var::VariablePtr Shader::registerSpecConstant( std::string const & name
		, uint32_t location
		, type::TypePtr type )
	{
		auto result = registerName( name
			, type
			, var::Flag::eSpecialisationConstant );
		m_data.specConstants.emplace( name, SpecConstantInfo{ { type, location } } );
		return result;
	}

	var::VariablePtr Shader::registerAccelerationStructure( std::string const & name
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
			auto accType = getNonArrayType( type );
			assert( accType->getKind() == ast::type::Kind::eAccelerationStructure );
			m_data.accelerationStruct = AccStructInfo{ std::static_pointer_cast< type::AccelerationStructure >( accType )
				, binding
				, set };
		}

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
			auto imgType = getNonArrayType( type );
			assert( imgType->getKind() == ast::type::Kind::eSampledImage );

			if ( static_cast< ast::type::SampledImage const & >( *imgType ).getConfig().dimension == ast::type::ImageDim::eBuffer )
			{
				m_data.uniformTexels.emplace( name, SamplerInfo{ { type, { binding, set } } } );
			}
			else
			{
				m_data.samplers.emplace( name, SamplerInfo{ { type, { binding, set } } } );
			}
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
			auto imgType = getNonArrayType( type );
			assert( imgType->getKind() == ast::type::Kind::eImage );

			if ( static_cast< ast::type::Image const & >( *imgType ).getConfig().dimension == ast::type::ImageDim::eBuffer )
			{
				m_data.storageTexels.emplace( name, ImageInfo{ { type, { binding, set } } } );
			}
			else
			{
				m_data.images.emplace( name, ImageInfo{ { type, { binding, set } } } );
			}
		}

		return result;
	}

	var::VariablePtr Shader::registerInput( std::string const & name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		auto it = std::find_if( m_data.inputs.begin()
			, m_data.inputs.end()
			, [&location]( std::map< std::string, InputInfo >::value_type const & lookup )
			{
				return lookup.second.location == location;
			} );

		if ( m_data.inputs.end() == it )
		{
			m_data.inputs.emplace( name, InputInfo{ { type, location } } );
		}

		if ( hasVar( name ) )
		{
			return getVar( name );
		}

		auto kind = getNonArrayType( type )->getKind();
		auto flags = attributes;

		if ( ( m_type != ast::ShaderStage::eVertex && m_type != ast::ShaderStage::eCompute )
			&& ( isSignedIntType( kind )
				|| isUnsignedIntType( kind ) ) )
		{
			flags = flags | var::Flag::eFlat;
		}

		auto result = registerName( name
			, type
			, flags | var::Flag::eShaderInput );
		return result;
	}

	var::VariablePtr Shader::registerOutput( std::string const & name
		, uint32_t location
		, uint64_t attributes
		, type::TypePtr type )
	{
		auto it = std::find_if( m_data.outputs.begin()
			, m_data.outputs.end()
			, [&location]( std::map< std::string, OutputInfo >::value_type const & lookup )
			{
				return lookup.second.location == location;
			} );

		if ( m_data.outputs.end() == it )
		{
			m_data.outputs.emplace( name, OutputInfo{ { type, location } } );
		}

		if ( hasVar( name ) )
		{
			return getVar( name );
		}

		auto kind = getNonArrayType( type )->getKind();
		auto flags = attributes;

		if ( ( m_type != ast::ShaderStage::eFragment && m_type != ast::ShaderStage::eCompute )
			&& ( isSignedIntType( kind )
				|| isUnsignedIntType( kind ) ) )
		{
			flags = flags | var::Flag::eFlat;
		}

		auto result = registerName( name
			, type
			, flags | var::Flag::eShaderOutput );
		return result;
	}

	var::VariablePtr Shader::registerInOut( std::string const & name
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

		auto result = registerName( name
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

	var::VariablePtr Shader::registerBlockVariable( std::string const & name
		, type::TypePtr type )
	{
		return registerLocale( name, type );
	}

	var::VariablePtr Shader::registerLocale( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eLocale );
	}

	var::VariablePtr Shader::registerLoopVar( std::string const & name
		, type::TypePtr type )
	{
		return registerName( name
			, type
			, var::Flag::eLocale | var::Flag::eLoopVar );
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
			, uint64_t( var::Flag::eInputParam ) | uint64_t( var::Flag::eOutputParam ) );
	}

	bool Shader::hasVar( std::string const & name )const
	{
		auto & block = m_blocks.back();
		auto it = findVariable( block.registered, name );

		if ( it != block.registered.end() )
		{
			return true;
		}

		it = findVariable( m_blocks.front().registered, name );

		if ( it != m_blocks.front().registered.end() )
		{
			return true;
		}

		return false;
	}

	var::VariablePtr Shader::getVar( std::string const & name )const
	{
		auto & block = m_blocks.back();
		auto it = findVariable( block.registered, name );

		if ( it == block.registered.end() )
		{
			it = findVariable( m_blocks.front().registered, name );

			if ( it == m_blocks.front().registered.end() )
			{
				std::string text;
				text += "No registered variable with the name [" + name + "].";
				throw std::runtime_error{ text };
			}
		}

		return *it;
	}

	var::VariablePtr Shader::getMemberVar( var::VariablePtr outer
		, std::string const & name )const
	{
		auto & block = m_blocks.back();
		auto it = findMbrVariable( block.registered, outer, name );

		if ( it == block.registered.end() )
		{
			it = findMbrVariable( m_blocks.front().registered, outer, name );

			if ( it == m_blocks.front().registered.end() )
			{
				std::string text;
				text += "No registered member variable with the name [" + name + "].";
				throw std::runtime_error{ text };
			}
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

	void Shader::addFuncStmt( stmt::StmtPtr stmt )
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
			getFuncContainer()->addStmt( std::move( stmt ) );
		}
	}

	void Shader::registerSsbo( std::string const & name
		, SsboInfo const & info )
	{
		m_data.ssbos.emplace( name, info );
	}

	void Shader::registerUbo( std::string const & name
		, UboInfo const & info )
	{
		m_data.ubos.emplace( name, info );
	}

	void Shader::registerPcb( std::string const & name
		, InterfaceBlock const & info )
	{
		m_data.pcbs.emplace( name, info );
	}

	void Shader::registerShaderRecord( std::string const & name
		, ShaderRecordInfo const & info )
	{
		m_data.shaderRecords.emplace( name, info );
	}

	expr::ExprPtr Shader::getDummyExpr( type::TypePtr type )const
	{
		return std::make_unique< expr::Expr >( *m_typesCache
			, type
			, expr::Kind::eIdentifier
			, expr::Flag::eDummy );
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
