/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Ssbo_H___
#define ___SDW_Ssbo_H___

#include "BoInfo.hpp"

#include <ASTGenerator/Stmt/StmtShaderBufferDecl.hpp>

namespace sdw
{
	class Ssbo
	{
	public:
		enum class Layout
		{
			eStd140,
			eStd430,
			ePacked,
			eShared
		};

		using Info = BoInfo;

		Ssbo( ShaderWriter & writer
			, std::string const & name
			, uint32_t bind
			, uint32_t set = 0u
			, Layout layout = Layout::eStd430 );
		void end();

		template< typename T >
		inline T declMember( std::string const & name );
		template< typename T >
		inline Array< T > declMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > declMemberArray( std::string const & name );
		template< typename T >
		inline Optional< T > declMember( std::string const & name
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declMember( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > declMemberArray( std::string const & name
			, bool enabled );
		template< typename T >
		inline T getMember( std::string const & name );
		template< typename T >
		inline Array< T > getMember( std::string const & name
			, uint32_t dimension );
		template< typename T >
		inline Array< T > getMemberArray( std::string const & name );
		template< typename T >
		inline Optional< T > getMember( std::string const & name
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > getMember( std::string const & name
			, uint32_t dimension
			, bool enabled );
		template< typename T >
		inline Optional< Array< T > > getMemberArray( std::string const & name
			, bool enabled );

	private:
		Shader & m_shader;
		stmt::ShaderBufferDeclPtr m_stmt;
		std::string m_name;
		Info m_info;
	};
}

#include "Ssbo.inl"

#endif
