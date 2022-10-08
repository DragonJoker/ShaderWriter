/*
See LICENSE file in root folder
*/
#ifndef ___SDW_BufferReference_H___
#define ___SDW_BufferReference_H___

#include "ShaderWriter/CompositeTypes/ArrayStorageBuffer.hpp"
#include "ShaderWriter/CompositeTypes/StorageBuffer.hpp"

namespace sdw
{
	template< typename BufferT >
	class BufferReferenceT
	{
	public:
		template< typename ... ParamsT >
		BufferReferenceT( ShaderWriter & writer
			, std::string name
			, ast::type::MemoryLayout layout
			, ast::type::Storage storage
			, bool enabled
			, ParamsT && ... params );

		BufferT operator()( std::string instanceName
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
