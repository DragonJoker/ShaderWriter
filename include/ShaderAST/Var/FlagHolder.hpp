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
		eParam = 1ULL << 0,
		eInputParam = 1ULL << 1,
		eOutputParam = 1ULL << 2,
		eUniform = 1ULL << 3,
		eConstant = 1ULL << 4,
		eShaderInput = 1ULL << 5,
		eShaderOutput = 1ULL << 6,
		eShaderConstant = 1ULL << 7,
		eSpecialisationConstant = 1ULL << 8,
		ePushConstant = 1ULL << 9,
		eLocale = 1ULL << 10,
		eBuiltin = 1ULL << 11,
		eImplicit = 1ULL << 12,
		eMember = 1ULL << 13,
		eFunction = 1ULL << 14,
		eStatic = 1ULL << 15,
		eFlat = 1ULL << 16,
		eNoPerspective = 1ULL << 17,
		ePatchInput = 1ULL << 18,
		ePatchOutput = 1ULL << 19,
		eCentroid = 1ULL << 20,
		ePerSample = 1ULL << 21,
		eGeometryStream = 1ULL << 22,
		eBlendIndex = 1ULL << 23,
		eLoopVar = 1ULL << 24,
		eTemp = 1ULL << 25,
		eAlias = 1ULL << 26,
		eStorageBuffer = 1ULL << 27,
		eIncomingRayPayload = 1ULL << 28,
		eRayPayload = 1ULL << 29,
		eIncomingCallableData = 1ULL << 30,
		eCallableData = 1ULL << 31,
		eHitAttribute = 1ULL << 32,
		eBufferReference = 1ULL << 33,
		ePerPrimitive = 1ULL << 34,
		ePerView = 1ULL << 35,
		ePerTaskNV = 1ULL << 36,
		ePerTask = 1ULL << 37,
		eShared = 1ULL << 38,
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

		bool isPerTaskNV()const
		{
			return hasFlag( Flag::ePerTaskNV );
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
	constexpr bool checkFlag( T const & value, U const & flag )noexcept
	{
		static_assert( sizeof( T ) == sizeof( U )
			, "Can't check flags for different size parameters" );
		return U( value & T( flag ) ) == flag;
	}
}

#endif
