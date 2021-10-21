/*
See LICENSE file in root folder
*/
#ifndef ___AST_FlagHolder_H___
#define ___AST_FlagHolder_H___
#pragma once

namespace ast::var
{
	enum class Flag
		: uint32_t
	{
		eNone = 0,
		eParam = 1 << 0,
		eInputParam = 1 << 1,
		eOutputParam = 1 << 2,
		eUniform = 1 << 3,
		eConstant = 1 << 4,
		eShaderInput = 1 << 5,
		eShaderOutput = 1 << 6,
		eShaderConstant = 1 << 7,
		eSpecialisationConstant = 1 << 8,
		ePushConstant = 1 << 9,
		eLocale = 1 << 10,
		eBuiltin = 1 << 11,
		eImplicit = 1 << 12,
		eMember = 1 << 13,
		eFunction = 1 << 14,
		eStatic = 1 << 15,
		eFlat = 1 << 16,
		eNoPerspective = 1 << 17,
		ePatchInput = 1 << 18,
		ePatchOutput = 1 << 19,
		eCentroid = 1 << 20,
		ePerSample = 1 << 21,
		eGeometryStream = 1 << 22,
		eBlendIndex = 1 << 23,
		eLoopVar = 1 << 24,
		eTemp = 1 << 25,
		eAlias = 1 << 26,
	};

	class FlagHolder
	{
	protected:
		~FlagHolder() = default;

	public:
		FlagHolder( Flag flag )
			: m_flags{ uint32_t( flag ) }
		{
		}

		FlagHolder( uint32_t flags )
			: m_flags{ flags }
		{
		}

		uint32_t getFlags()const
		{
			return m_flags;
		}

		void updateFlag( Flag flag, bool set = true )
		{
			if ( set )
			{
				m_flags |= uint32_t( flag );
			}
			else
			{
				m_flags &= ~uint32_t( flag );
			}
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

		bool hasFlag( Flag flag )const
		{
			return flag == Flag::eNone
				? false
				: Flag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		uint32_t m_flags;
	};

	inline uint32_t operator|( Flag const lhs, Flag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( Flag const lhs, uint32_t const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( uint32_t const lhs, Flag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}
}

#endif
