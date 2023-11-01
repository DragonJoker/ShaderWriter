/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModuleLiterals_H___
#define ___SDW_SpirvModuleLiterals_H___
#pragma once

#include "CompilerSpirV/SpirVFunction.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

#include <map>
#include <unordered_map>

namespace spirv
{
	class ModuleLiterals
	{
	public:
		ModuleLiterals( ast::ShaderAllocatorBlock * allocator
			, Module & module
			, InstructionList & declarations );

		DebugId registerLiteral( bool value );
		DebugId registerLiteral( int8_t value );
		DebugId registerLiteral( int16_t value );
		DebugId registerLiteral( int32_t value );
		DebugId registerLiteral( uint8_t value );
		DebugId registerLiteral( uint16_t value );
		DebugId registerLiteral( uint32_t value );
		DebugId registerLiteral( int64_t value );
		DebugId registerLiteral( uint64_t value );
		DebugId registerLiteral( float value );
		DebugId registerLiteral( double value );
		DebugId registerLiteral( DebugIdList const & initialisers
			, ast::type::TypePtr type );
		void registerConstant( DebugId const & id
			, ast::type::TypePtr type );

		void deserialize( spv::Op opCode
			, Instruction const & instruction );

	private:
		DebugId doFindConstant( spv::Id id );

	private:
		Module & m_module;
		InstructionList & m_declarations;
		ast::ShaderAllocatorBlock * m_allocator;
		ast::Map< bool, DebugId > m_registeredBoolConstants;
		ast::Map< int8_t, DebugId > m_registeredInt8Constants;
		ast::Map< int16_t, DebugId > m_registeredInt16Constants;
		ast::Map< int32_t, DebugId > m_registeredInt32Constants;
		ast::Map< int64_t, DebugId > m_registeredInt64Constants;
		ast::Map< uint8_t, DebugId > m_registeredUInt8Constants;
		ast::Map< uint16_t, DebugId > m_registeredUInt16Constants;
		ast::Map< uint32_t, DebugId > m_registeredUInt32Constants;
		ast::Map< uint64_t, DebugId > m_registeredUInt64Constants;
		ast::Map< float, DebugId > m_registeredFloatConstants;
		ast::Map< double, DebugId > m_registeredDoubleConstants;
		ast::Vector< std::pair< DebugIdList, DebugId > > m_registeredCompositeConstants;
		ast::UnorderedMap< DebugId, ast::type::TypePtr, DebugIdHasher > m_registeredConstants;
	};
}

#endif
