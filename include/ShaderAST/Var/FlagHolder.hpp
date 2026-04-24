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

	inline bool hasFlag( uint64_t flags, Flag flag )noexcept
	{
		return flag == Flag::eNone
			? false
			: Flag( flags & uint64_t( flag ) ) == flag;
	}

	class FlagHolder
	{
	public:
		explicit FlagHolder( Flag flag )noexcept
			: m_flags{ uint64_t( flag ) }
		{
		}

		explicit FlagHolder( uint64_t flags )noexcept
			: m_flags{ flags }
		{
		}

		uint64_t getFlags()const noexcept
		{
			return m_flags;
		}

		void updateFlag( Flag flag, bool set = true )noexcept
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

		bool hasFlag( Flag flag )const noexcept
		{
			return ast::var::hasFlag( m_flags, flag );
		}

		bool isParam()const noexcept
		{
			return hasFlag( Flag::eParam )
				|| hasFlag( Flag::eInputParam )
				|| hasFlag( Flag::eOutputParam );
		}

		bool isStatic()const noexcept
		{
			return hasFlag( Flag::eStatic );
		}

		bool isInputParam()const noexcept
		{
			return hasFlag( Flag::eInputParam );
		}

		bool isOutputParam()const noexcept
		{
			return hasFlag( Flag::eOutputParam );
		}

		bool isShaderInput()const noexcept
		{
			return hasFlag( Flag::eShaderInput );
		}

		bool isShaderOutput()const noexcept
		{
			return hasFlag( Flag::eShaderOutput );
		}

		bool isPushConstant()const noexcept
		{
			return hasFlag( Flag::ePushConstant );
		}

		bool isShaderConstant()const noexcept
		{
			return hasFlag( Flag::eShaderConstant );
		}

		bool isSpecialisationConstant()const noexcept
		{
			return hasFlag( Flag::eSpecialisationConstant );
		}

		bool isLocale()const noexcept
		{
			return hasFlag( Flag::eLocale );
		}

		bool isBuiltin()const noexcept
		{
			return hasFlag( Flag::eBuiltin );
		}

		bool isUniform()const noexcept
		{
			return hasFlag( Flag::eUniform );
		}

		bool isConstant()const noexcept
		{
			return hasFlag( Flag::eConstant );
		}

		bool isImplicit()const noexcept
		{
			return hasFlag( Flag::eImplicit );
		}

		bool isFlat()const noexcept
		{
			return hasFlag( Flag::eFlat );
		}

		bool isLoopVar()const noexcept
		{
			return hasFlag( Flag::eLoopVar );
		}

		bool isMember()const noexcept
		{
			return hasFlag( Flag::eMember );
		}

		bool isNoPerspective()const noexcept
		{
			return hasFlag( Flag::eNoPerspective );
		}

		bool isPatchInput()const noexcept
		{
			return hasFlag( Flag::ePatchInput );
		}

		bool isPatchOutput()const noexcept
		{
			return hasFlag( Flag::ePatchOutput );
		}

		bool isCentroid()const noexcept
		{
			return hasFlag( Flag::eCentroid );
		}

		bool isPerSample()const noexcept
		{
			return hasFlag( Flag::ePerSample );
		}

		bool isGeometryStream()const noexcept
		{
			return hasFlag( Flag::eGeometryStream );
		}

		bool isBlendIndex()const noexcept
		{
			return hasFlag( Flag::eBlendIndex );
		}

		bool isTempVar()const noexcept
		{
			return hasFlag( Flag::eTemp );
		}

		bool isAlias()const noexcept
		{
			return hasFlag( Flag::eAlias );
		}

		bool isStorageBuffer()const noexcept
		{
			return hasFlag( Flag::eStorageBuffer );
		}

		bool isIncomingRayPayload()const noexcept
		{
			return hasFlag( Flag::eIncomingRayPayload );
		}

		bool isRayPayload()const noexcept
		{
			return hasFlag( Flag::eRayPayload );
		}

		bool isIncomingCallableData()const noexcept
		{
			return hasFlag( Flag::eIncomingCallableData );
		}

		bool isCallableData()const noexcept
		{
			return hasFlag( Flag::eCallableData );
		}

		bool isHitAttribute()const noexcept
		{
			return hasFlag( Flag::eHitAttribute );
		}

		bool isBufferReference()const noexcept
		{
			return hasFlag( Flag::eBufferReference );
		}

		bool isPerPrimitive()const noexcept
		{
			return hasFlag( Flag::ePerPrimitive );
		}

		bool isPerView()const noexcept
		{
			return hasFlag( Flag::ePerView );
		}

		bool isPerTaskNV()const noexcept
		{
			return hasFlag( Flag::ePerTaskNV );
		}

		bool isPerTask()const noexcept
		{
			return hasFlag( Flag::ePerTask );
		}

		bool isShared()const noexcept
		{
			return hasFlag( Flag::eShared );
		}

		bool isPatch()const noexcept
		{
			return isPatchInput() || isPatchOutput();
		}

		bool isInput()const noexcept
		{
			return isShaderInput() || isPatchInput();
		}

		bool isOutput()const noexcept
		{
			return isShaderOutput() || isPatchOutput();
		}

	private:
		uint64_t m_flags;
	};

	inline uint64_t operator|( Flag const lhs, Flag const rhs )noexcept
	{
		return uint64_t( lhs ) | uint64_t( rhs );
	}

	inline uint64_t operator|( Flag const lhs, uint64_t const rhs )noexcept
	{
		return uint64_t( lhs ) | uint64_t( rhs );
	}

	inline uint64_t operator|( uint64_t const lhs, Flag const rhs )noexcept
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
