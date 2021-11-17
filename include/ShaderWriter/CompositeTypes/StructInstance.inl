/*
See LICENSE file in root folder
*/
#include <ShaderAST/Shader.hpp>

#include <stdexcept>

#pragma warning( push )
#pragma warning( disable:4365 )
#include <iostream>
#pragma warning( pop )

namespace sdw
{
	template< typename T >
	inline T StructInstance::getMember( std::string const & name
		, bool optional )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto mbrFlags = m_type->getFlag();

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchOutput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderOutput;
		}

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchInput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderInput;
		}

		auto mbrIndex = m_type->findMember( name );
		auto & writer = findWriterMandat( *this );

		if ( mbrIndex == ast::type::Struct::NotFound )
		{
			if ( mbrFlags )
			{
				std::clog << "Struct member [" << name << "] was not found, creating dummy one." << std::endl;
			}
			else if ( !optional )
			{
				throw std::runtime_error{ "Struct member [" + name + "] was not found." };
			}

			return T{ writer
				, std::make_unique< expr::Expr >( m_type->getCache()
					, T::makeType( m_type->getCache() )
					, expr::Kind::eIdentifier
					, expr::Flag::eDummy )
				, false };
		}

		auto member = m_type->getMember( mbrIndex );

		if ( mbrFlags )
		{
			auto & shader = *getShader();

			if ( checkFlag( mbrFlags, ast::var::Flag::eShaderInput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					shader.registerInput( "in::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
			else if ( checkFlag( mbrFlags, ast::var::Flag::eShaderOutput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					shader.registerOutput( "out::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
		}

		return T{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, mbrFlags )
			, true};
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( std::string const & name
		, bool optional )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto mbrFlags = m_type->getFlag();

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchOutput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderOutput;
		}

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchInput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderInput;
		}

		auto mbrIndex = m_type->findMember( name );
		auto & writer = findWriterMandat( *this );

		if ( mbrIndex == ast::type::Struct::NotFound )
		{
			if ( mbrFlags )
			{
				std::clog << "Struct member [" << name << "] was not found, creating dummy one." << std::endl;
			}
			else if ( !optional )
			{
				throw std::runtime_error{ "Struct member [" + name + "] was not found." };
			}

			return Array< T >{ writer
				, std::make_unique< expr::Expr >( m_type->getCache()
					, m_type->getCache().getArray( T::makeType( m_type->getCache() ) )
					, expr::Kind::eIdentifier
					, expr::Flag::eDummy )
				, false };
		}
		auto member = m_type->getMember( mbrIndex );

		if ( mbrFlags )
		{
			auto & shader = *getShader();

			if ( checkFlag( mbrFlags, ast::var::Flag::eShaderInput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					shader.registerInput( "in::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
			else if ( checkFlag( mbrFlags, ast::var::Flag::eShaderOutput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					shader.registerOutput( "out::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
		}

		return Array< T >{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, mbrFlags )
			, true };
	}

	template< typename T >
	inline T StructInstance::getMember( ast::Builtin builtin )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto mbrFlags = m_type->getFlag() | ast::var::Flag::eBuiltin;

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchOutput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderOutput;
		}

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchInput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderInput;
		}

		auto member = m_type->getMember( builtin );
		ShaderWriter & writer = findWriterMandat( *this );
		return T{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, mbrFlags )
			, true};
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( ast::Builtin builtin )const
	{
		assert( m_type->getKind() == type::Kind::eStruct );
		auto mbrFlags = m_type->getFlag() | ast::var::Flag::eBuiltin;

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchOutput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderOutput;
		}

		if ( checkFlag( m_type->getFlag(), ast::var::Flag::ePatchInput ) )
		{
			mbrFlags = mbrFlags | ast::var::Flag::eShaderInput;
		}

		auto member = m_type->getMember( builtin );
		auto & writer = findWriterMandat( *this );
		return Array< T >{ writer
			, sdw::makeMbrSelect( makeExpr( writer, *this )
				, member.type->getIndex()
				, mbrFlags )
			, true };
	}
}
