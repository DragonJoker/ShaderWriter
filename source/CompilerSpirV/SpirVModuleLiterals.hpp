/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvModuleLiterals_H___
#define ___SDW_SpirvModuleLiterals_H___
#pragma once

#include "CompilerSpirV/SpirVFunction.hpp"

#include <ShaderAST/Expr/ExprLiteral.hpp>

#include <map>

namespace spirv
{
	class ModuleLiterals
	{
	public:
		ModuleLiterals( ast::ShaderAllocatorBlock * allocator
			, Module & shaderModule
			, InstructionList & declarations );

		DebugId registerLiteral( bool value );
		DebugId registerLiteral( signed char value );
		DebugId registerLiteral( signed short value );
		DebugId registerLiteral( signed int value );
		DebugId registerLiteral( signed long value );
		DebugId registerLiteral( signed long long value );
		DebugId registerLiteral( unsigned char value );
		DebugId registerLiteral( unsigned short value );
		DebugId registerLiteral( unsigned int value );
		DebugId registerLiteral( unsigned long value );
		DebugId registerLiteral( unsigned long long value );
		DebugId registerLiteral( float value );
		DebugId registerLiteral( double value );
		DebugId registerLiteral( DebugIdList const & initialisers
			, ast::type::TypePtr type );
		void registerConstant( DebugId const & id
			, ast::type::TypePtr type );

		void deserialize( spv::Op opCode
			, Instruction const & instruction );

	private:
		Module & m_module;
		InstructionList & m_declarations;
		ast::ShaderAllocatorBlock * m_allocator;
		ast::Map< ast::expr::LitBool, DebugId > m_registeredBoolConstants;
		ast::Map< ast::expr::LitInt8, DebugId > m_registeredInt8Constants;
		ast::Map< ast::expr::LitInt16, DebugId > m_registeredInt16Constants;
		ast::Map< ast::expr::LitInt32, DebugId > m_registeredInt32Constants;
		ast::Map< ast::expr::LitInt64, DebugId > m_registeredInt64Constants;
		ast::Map< ast::expr::LitUInt8, DebugId > m_registeredUInt8Constants;
		ast::Map< ast::expr::LitUInt16, DebugId > m_registeredUInt16Constants;
		ast::Map< ast::expr::LitUInt32, DebugId > m_registeredUInt32Constants;
		ast::Map< ast::expr::LitUInt64, DebugId > m_registeredUInt64Constants;
		ast::Map< ast::expr::LitFloat32, DebugId > m_registeredFloatConstants;
		ast::Map< ast::expr::LitFloat64, DebugId > m_registeredDoubleConstants;
		ast::Vector< std::pair< DebugIdList, DebugId > > m_registeredCompositeConstants;
		ast::UnorderedMap< DebugId, ast::type::TypePtr, DebugIdHasher > m_registeredConstants;
	};
}

#endif
