/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirVDebugHelpers_H___
#define ___SDW_SpirVDebugHelpers_H___
#pragma once

#include "CompilerSpirV/SpirvInstruction.hpp"

#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

namespace spirv::debug
{
	namespace details
	{
		template< typename Param, typename ... Params >
		inline void makeValueIdListRec( ValueIdList & result, Param const & current, Params ... params );

		inline void makeValueIdListRec( ValueIdList & result, ValueId const & param )
		{
			result.push_back( param );
		}

		inline void makeValueIdListRec( ValueIdList & result, TypeId const & param )
		{
			if ( param.debug )
			{
				result.push_back( param.debug );
			}
		}

		inline void makeValueIdListRec( ValueIdList & result, uint16_t param )
		{
			result.push_back( ValueId{ spv::Id{ param } } );
		}

		inline void makeValueIdListRec( ValueIdList & result, uint32_t param )
		{
			result.push_back( ValueId{ spv::Id{ param } } );
		}

		inline void makeValueIdListRec( ValueIdList & result, ValueIdList const & param )
		{
			result.insert( result.end(), param.begin(), param.end() );
		}

		inline void makeValueIdListRec( ValueIdList & result, TypeIdList const & param )
		{
			for ( auto & value : param )
			{
				makeValueIdListRec( result, value );
			}
		}

		inline void makeValueIdListRec( ValueIdList & result, IdList const & param )
		{
			makeValueIdListRec( result, convert( param ) );
		}

		template< typename Param, typename ... Params >
		inline void makeValueIdListRec( ValueIdList & result, Param const & current, Params ... params )
		{
			makeValueIdListRec( result, current );
			makeValueIdListRec( result, params... );
		}
	}

	template< typename ... Params >
	inline ValueIdList makeValueIdList( ast::ShaderAllocatorBlock * alloc
		, Params ... params )
	{
		ValueIdList result{ alloc };
		details::makeValueIdListRec( result, params... );
		return result;
	}

	ValueIdList convert( DebugIdList const & in );

	uint32_t getSize( ast::type::Kind kind );
	uint32_t getEncoding( ast::type::Kind kind );
	uint32_t getFlags( uint64_t varFlags );
}

#endif
