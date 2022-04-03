/*
See LICENSE file in root folder
*/
#ifndef ___AST_FlagHolder_H___
#define ___AST_FlagHolder_H___
#pragma once

namespace ast::var
{
	enum class Flag
		: uint64_t
	{
		eNone = 0,
		eParam = 1ull << 0,
		eInputParam = 1ull << 1,
		eOutputParam = 1ull << 2,
		eUniform = 1ull << 3,
		eConstant = 1ull << 4,
		eShaderInput = 1ull << 5,
		eShaderOutput = 1ull << 6,
		eShaderConstant = 1ull << 7,
		eSpecialisationConstant = 1ull << 8,
		ePushConstant = 1ull << 9,
		eLocale = 1ull << 10,
		eBuiltin = 1ull << 11,
		eImplicit = 1ull << 12,
		eMember = 1ull << 13,
		eFunction = 1ull << 14,
		eStatic = 1ull << 15,
		eFlat = 1ull << 16,
		eNoPerspective = 1ull << 17,
		ePatchInput = 1ull << 18,
		ePatchOutput = 1ull << 19,
		eCentroid = 1ull << 20,
		ePerSample = 1ull << 21,
		eGeometryStream = 1ull << 22,
		eBlendIndex = 1ull << 23,
		eLoopVar = 1ull << 24,
		eTemp = 1ull << 25,
		eAlias = 1ull << 26,
		eStorageBuffer = 1ull << 27,
		eIncomingRayPayload = 1ull << 28,
		eRayPayload = 1ull << 29,
		eIncomingCallableData = 1ull << 30,
		eCallableData = 1ull << 31,
		eHitAttribute = 1ull << 32,
		eBufferReference = 1ull << 33,
		ePerPrimitive = 1ull << 34,
		ePerView = 1ull << 35,
		ePerTask = 1ull << 36,
		eShared = 1ull << 37,
	};

	inline bool hasFlag( uint64_t flags, Flag flag )
	{
		return flag == Flag::eNone
			? false
			: Flag( flags & uint64_t( flag ) ) == flag;
	}

	class FlagHolder
	{
	public:
		explicit FlagHolder( Flag flag )
			: m_flags{ uint64_t( flag ) }
		{
		}

		explicit FlagHolder( uint64_t flags )
			: m_flags{ flags }
		{
		}

		uint64_t getFlags()const
		{
			return m_flags;
		}

		void updateFlag( Flag flag, bool set = true )
		{
			if ( set )
			{
				m_flags |= uint64_t( flag );
			}
			else
			{
				m_flags &= ~uint64_t( flag );
			}
		}

		bool hasFlag( Flag flag )const
		{
			return ast::var::hasFlag( m_flags, flag );
		}

		bool isParam()const
		{
			return hasFlag( Flag::eParam )
				|| hasFlag( Flag::eInputParam )
				|| hasFlag( Flag::eOutputParam );
		}

		bool isStatic()const
		{
			return hasFlag( Flag::eStatic );
		}

		bool isInputParam()const
		{
			return hasFlag( Flag::eInputParam );
		}

		bool isOutputParam()const
		{
			return hasFlag( Flag::eOutputParam );
		}

		bool isShaderInput()const
		{
			return hasFlag( Flag::eShaderInput );
		}

		bool isShaderOutput()const
		{
			return hasFlag( Flag::eShaderOutput );
		}

		bool isPushConstant()const
		{
			return hasFlag( Flag::ePushConstant );
		}

		bool isShaderConstant()const
		{
			return hasFlag( Flag::eShaderConstant );
		}

		bool isSpecialisationConstant()const
		{
			return hasFlag( Flag::eSpecialisationConstant );
		}

		bool isLocale()const
		{
			return hasFlag( Flag::eLocale );
		}

		bool isBuiltin()const
		{
			return hasFlag( Flag::eBuiltin );
		}

		bool isUniform()const
		{
			return hasFlag( Flag::eUniform );
		}

		bool isConstant()const
		{
			return hasFlag( Flag::eConstant );
		}

		bool isImplicit()const
		{
			return hasFlag( Flag::eImplicit );
		}

		bool isFlat()const
		{
			return hasFlag( Flag::eFlat );
		}

		bool isLoopVar()const
		{
			return hasFlag( Flag::eLoopVar );
		}

		bool isMember()const
		{
			return hasFlag( Flag::eMember );
		}

		bool isNoPerspective()const
		{
			return hasFlag( Flag::eNoPerspective );
		}

		bool isPatchInput()const
		{
			return hasFlag( Flag::ePatchInput );
		}

		bool isPatchOutput()const
		{
			return hasFlag( Flag::ePatchOutput );
		}

		bool isPatch()const
		{
			return isPatchInput() || isPatchOutput();
		}

		bool isCentroid()const
		{
			return hasFlag( Flag::eCentroid );
		}

		bool isPerSample()const
		{
			return hasFlag( Flag::ePerSample );
		}

		bool isGeometryStream()const
		{
			return hasFlag( Flag::eGeometryStream );
		}

		bool isBlendIndex()const
		{
			return hasFlag( Flag::eBlendIndex );
		}

		bool isTempVar()const
		{
			return hasFlag( Flag::eTemp );
		}

		bool isAlias()const
		{
			return hasFlag( Flag::eAlias );
		}

		bool isStorageBuffer()const
		{
			return hasFlag( Flag::eStorageBuffer );
		}

		bool isIncomingRayPayload()const
		{
			return hasFlag( Flag::eIncomingRayPayload );
		}

		bool isRayPayload()const
		{
			return hasFlag( Flag::eRayPayload );
		}

		bool isIncomingCallableData()const
		{
			return hasFlag( Flag::eIncomingCallableData );
		}

		bool isCallableData()const
		{
			return hasFlag( Flag::eCallableData );
		}

		bool isHitAttribute()const
		{
			return hasFlag( Flag::eHitAttribute );
		}

		bool isBufferReference()const
		{
			return hasFlag( Flag::eBufferReference );
		}

		bool isPerPrimitive()const
		{
			return hasFlag( Flag::ePerPrimitive );
		}

		bool isPerView()const
		{
			return hasFlag( Flag::ePerView );
		}

		bool isPerTask()const
		{
			return hasFlag( Flag::ePerTask );
		}

		bool isShared()const
		{
			return hasFlag( Flag::eShared );
		}

	private:
		uint64_t m_flags;
	};

	inline uint64_t operator|( Flag const lhs, Flag const rhs )
	{
		return uint64_t( lhs ) | uint64_t( rhs );
	}

	inline uint64_t operator|( Flag const lhs, uint64_t const rhs )
	{
		return uint64_t( lhs ) | uint64_t( rhs );
	}

	inline uint64_t operator|( uint64_t const lhs, Flag const rhs )
	{
		return uint64_t( lhs ) | uint64_t( rhs );
	}


	template< typename T, typename U >
	inline constexpr bool checkFlag( T const & value, U const & flag )noexcept
	{
		static_assert( sizeof( T ) == sizeof( U )
			, "Can't check flags for different size parameters" );
		return U( value & T( flag ) ) == flag;
	}
}

#endif
