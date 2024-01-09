/*
See LICENSE file in root folder
*/
#include <ShaderAST/ShaderBuilder.hpp>

#include <stdexcept>

namespace sdw
{
	inline bool StructInstance::hasMember( std::string_view name )const
	{
		return ast::type::Struct::NotFound != m_type->findMember( name );
	}

	template< typename T >
	inline T StructInstance::getMember( std::string_view name
		, bool optional )const
	{
		assert( m_type->getKind() == type::Kind::eStruct
			|| m_type->getKind() == type::Kind::eRayDesc );
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
			if ( !mbrFlags && !optional )
			{
				throw ast::Exception{ "Struct member [" + std::string( name ) + "] was not found." };
			}

			return T{ writer
				, getExprCache( writer ).makeDummyExpr( T::makeType( m_type->getTypesCache() ) )
				, false };
		}

		auto member = m_type->getMember( mbrIndex );

		if ( mbrFlags )
		{
			auto & builder = getBuilder();

			if ( checkFlag( mbrFlags, ast::var::Flag::eShaderInput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					builder.registerInput( m_type->getEntryPoint()
						, "in::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
			else if ( checkFlag( mbrFlags, ast::var::Flag::eShaderOutput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					builder.registerOutput( m_type->getEntryPoint()
						, "out::" + member.name
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
			, true };
	}

	template< ValueT T >
	DefaultedT< T > StructInstance::getMember( std::string_view name
		, T optionalValue )const
	{
		return DefaultedT< T >( getMember< T >( std::move( name ), true )
			, std::move( optionalValue ) );
	}

	template< typename T >
	inline Array< T > StructInstance::getMemberArray( std::string_view name
		, bool optional )const
	{
		assert( m_type->getKind() == type::Kind::eStruct
			|| m_type->getKind() == type::Kind::eRayDesc );
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
			if ( !mbrFlags && !optional )
			{
				throw ast::Exception{ "Struct member [" + std::string( name ) + "] was not found." };
			}

			return Array< T >{ writer
				, getExprCache( writer ).makeDummyExpr( m_type->getTypesCache().getArray( T::makeType( m_type->getTypesCache() ) ) )
				, false };
		}
		auto member = m_type->getMember( mbrIndex );

		if ( mbrFlags )
		{
			auto & builder = getBuilder();

			if ( checkFlag( mbrFlags, ast::var::Flag::eShaderInput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					builder.registerInput( m_type->getEntryPoint()
						, "in::" + member.name
						, member.location
						, mbrFlags
						, member.type );
				}
			}
			else if ( checkFlag( mbrFlags, ast::var::Flag::eShaderOutput ) )
			{
				if ( member.builtin == ast::Builtin::eNone )
				{
					builder.registerOutput( m_type->getEntryPoint()
						, "out::" + member.name
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

	template< ValueT T >
	inline DefaultedT< Array< T > > StructInstance::getMemberArray( std::string_view name
		, Array< T > optionalValue )const
	{
		return DefaultedT< Array< T > >( getMemberArray< Array< T > >( std::move( name ), true )
			, std::move( optionalValue ) );
	}

	inline bool StructInstance::hasMember( ast::Builtin builtin )
	{
		return ast::type::Struct::NotFound != m_type->findMember( builtin );
	}

	template< typename T >
	inline T StructInstance::getMember( ast::Builtin builtin )const
	{
		assert( m_type->getKind() == type::Kind::eStruct
			|| m_type->getKind() == type::Kind::eRayDesc );
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
		assert( m_type->getKind() == type::Kind::eStruct
			|| m_type->getKind() == type::Kind::eRayDesc );
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
