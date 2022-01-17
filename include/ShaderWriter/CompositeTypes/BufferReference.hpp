/*
See LICENSE file in root folder
*/
#ifndef ___SDW_BufferReference_H___
#define ___SDW_BufferReference_H___

#include "ShaderWriter/CompositeTypes/ArraySsbo.hpp"
#include "ShaderWriter/CompositeTypes/Ssbo.hpp"

namespace sdw
{
	template< typename BufferT >
	class BufferReferenceT
	{
	public:
		BufferReferenceT( ShaderWriter & writer
			, std::string const & name
			, ast::type::MemoryLayout layout
			, ast::type::Storage storage
			, bool enabled );

		BufferT operator()( std::string const & instanceName
			, UInt64 address );

		bool isEnabled()const
		{
			return m_enabled;
		}

	private:
		ShaderWriter & m_writer;
		ast::type::TypePtr m_type;
		ast::type::TypePtr m_pointer;
		bool m_enabled;
	};
}

#include "BufferReference.inl"

#endif
