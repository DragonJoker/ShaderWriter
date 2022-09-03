/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CallableWriter_H___
#define ___SDW_CallableWriter_H___

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/BaseTypes/CallableData.hpp"

namespace sdw
{
	/**
	*name
	*	Callable.
	*/
	/**@{*/
	/**
	*	Holds input data for a callable shader.
	*/
	struct CallableIn
		: StructInstance
	{
		SDW_API explicit CallableIn( ShaderWriter & writer );
		SDW_API CallableIn( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		SDW_API static ast::type::StructPtr makeType( ast::type::TypesCache & cache );

		// Work dimensions
		//in uvec3 gl_LaunchIDEXT;
		U32Vec3 launchID;
		//in uvec3 gl_LaunchSizeEXT;
		U32Vec3 launchSize;
	};

	template< typename ValueT >
	using CallableMainFuncT = std::function< void( CallableIn, CallableDataInT< ValueT > ) >;

	class CallableWriter
		: public ShaderWriter
	{
	public:
		SDW_API CallableWriter();

		template< typename ValueT >
		void implementMainT( uint32_t dataLocation
			, CallableMainFuncT< ValueT > const & function );
		template< typename ValueT >
		void implementMainT( CallableDataInT< ValueT > data
			, CallableMainFuncT< ValueT > const & function );
	};
	/**@}*/
}

#include "CallableWriter.inl"

#endif
