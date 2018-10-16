/*
See LICENSE file in root folder
*/
#ifndef ___Writer_SWIZZLE_H___
#define ___Writer_SWIZZLE_H___

#include "Value.hpp"

#include <ASTGenerator/Expr/ExprMbrSelect.hpp>

#define Writer_UseSwizzle 0

#if defined( RGB )
#	undef RGB
#endif

namespace sdw
{
#if Writer_UseSwizzle
	template< typename Input, typename Output >
	struct Swizzle
		: public Expr
	{
		inline Swizzle( std::string const & p_name
			, Input * input );
		inline Swizzle & operator=( Swizzle const & rhs );
		template< typename T > inline Swizzle & operator=( T const & rhs );
		inline operator Output()const;
		template< typename UInput, typename UOutput > inline Swizzle & operator+=( Swizzle< UInput, UOutput > const & rhs );
		template< typename UInput, typename UOutput > inline Swizzle & operator-=( Swizzle< UInput, UOutput > const & rhs );
		template< typename UInput, typename UOutput > inline Swizzle & operator*=( Swizzle< UInput, UOutput > const & rhs );
		template< typename UInput, typename UOutput > inline Swizzle & operator/=( Swizzle< UInput, UOutput > const & rhs );
		inline Swizzle & operator+=( float rhs );
		inline Swizzle & operator-=( float rhs );
		inline Swizzle & operator*=( float rhs );
		inline Swizzle & operator/=( float rhs );
		inline Swizzle & operator+=( int rhs );
		inline Swizzle & operator-=( int rhs );
		inline Swizzle & operator*=( int rhs );
		inline Swizzle & operator/=( int rhs );

		Input * m_input;
	};

	template< typename TInput, typename UInput, typename Output > inline Output operator+( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Output > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator-( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Output > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator*( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Output > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator/( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Output > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator+( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Float > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator-( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Float > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator*( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Float > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator/( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Float > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator+( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Int > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator-( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Int > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator*( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Int > const & rhs );
	template< typename TInput, typename UInput, typename Output > inline Output operator/( Swizzle< TInput, Output > const & lhs, Swizzle< UInput, Int > const & rhs );
	template< typename Input, typename Output > inline Output operator+( Swizzle< Input, Output > const & lhs, float rhs );
	template< typename Input, typename Output > inline Output operator-( Swizzle< Input, Output > const & lhs, float rhs );
	template< typename Input, typename Output > inline Output operator*( Swizzle< Input, Output > const & lhs, float rhs );
	template< typename Input, typename Output > inline Output operator/( Swizzle< Input, Output > const & lhs, float rhs );
	template< typename Input, typename Output > inline Output operator+( Swizzle< Input, Output > const & lhs, int rhs );
	template< typename Input, typename Output > inline Output operator-( Swizzle< Input, Output > const & lhs, int rhs );
	template< typename Input, typename Output > inline Output operator*( Swizzle< Input, Output > const & lhs, int rhs );
	template< typename Input, typename Output > inline Output operator/( Swizzle< Input, Output > const & lhs, int rhs );

#	define Writer_Swizzle( Input, Output, Name )\
	Swizzle< Input, Output > Name;

#	define Writer_FirstSwizzle( Input, Output, Name )\
	Swizzle< Input, Output > Name = Swizzle< Input, Output >( castor::string::stringCast< char >( #Name ), this )

#	define Writer_LastSwizzle( Input, Output, Name )\
	Swizzle< Input, Output > Name = Swizzle< Input, Output >( castor::string::stringCast< char >( #Name ), this )

#	define Swizzle_X x
#	define Swizzle_Y y
#	define Swizzle_Z z
#	define Swizzle_W w
#	define Swizzle_R r
#	define Swizzle_G g
#	define Swizzle_B b
#	define Swizzle_A a
#	define Swizzle_XY xy
#	define Swizzle_XZ xz
#	define Swizzle_XW xw
#	define Swizzle_YX yx
#	define Swizzle_YZ yz
#	define Swizzle_YW yw
#	define Swizzle_ZX zx
#	define Swizzle_ZY zy
#	define Swizzle_ZW zw
#	define Swizzle_WX wx
#	define Swizzle_WY wy
#	define Swizzle_WZ wz
#	define Swizzle_RG rg
#	define Swizzle_RB rb
#	define Swizzle_RA ra
#	define Swizzle_GR gr
#	define Swizzle_GB gb
#	define Swizzle_GA ga
#	define Swizzle_BR br
#	define Swizzle_BG bg
#	define Swizzle_BA ba
#	define Swizzle_AR ar
#	define Swizzle_AG ag
#	define Swizzle_AB ab
#	define Swizzle_XYZ xyz
#	define Swizzle_XYW xyw
#	define Swizzle_XZY xzy
#	define Swizzle_XZW xzw
#	define Swizzle_XWY xwy
#	define Swizzle_XWZ xwz
#	define Swizzle_YXZ yxz
#	define Swizzle_YXW yxw
#	define Swizzle_YZX yzx
#	define Swizzle_YZW yzw
#	define Swizzle_YWX ywx
#	define Swizzle_YWZ ywz
#	define Swizzle_ZXY zxy
#	define Swizzle_ZXW zxw
#	define Swizzle_ZYX zyx
#	define Swizzle_ZYW zyw
#	define Swizzle_ZWX zwx
#	define Swizzle_ZWY zwy
#	define Swizzle_WXY wxy
#	define Swizzle_WXZ wxz
#	define Swizzle_WYX wyx
#	define Swizzle_WYZ wyz
#	define Swizzle_WZX wzx
#	define Swizzle_WZY wzy
#	define Swizzle_RGB rgb
#	define Swizzle_RGA rga
#	define Swizzle_RBG rbg
#	define Swizzle_RBA rba
#	define Swizzle_RAG rag
#	define Swizzle_RAB rab
#	define Swizzle_GRB grb
#	define Swizzle_GRA gra
#	define Swizzle_GBR gbr
#	define Swizzle_GBA gba
#	define Swizzle_GAR gar
#	define Swizzle_GAB gab
#	define Swizzle_BRG brg
#	define Swizzle_BRA bra
#	define Swizzle_BGR bgr
#	define Swizzle_BGA bga
#	define Swizzle_BAR bar
#	define Swizzle_BAG bag
#	define Swizzle_ARG arg
#	define Swizzle_ARB arb
#	define Swizzle_AGR agr
#	define Swizzle_AGB agb
#	define Swizzle_ABR abr
#	define Swizzle_ABG abg
#	define Swizzle_XYZW xyzw
#	define Swizzle_XYWW xyww
#	define Swizzle_XYWZ xywz
#	define Swizzle_XZYW xzyw
#	define Swizzle_XZWY xzwy
#	define Swizzle_XWYZ xwyz
#	define Swizzle_XWZY xwzy
#	define Swizzle_YXZW yxzw
#	define Swizzle_YXWZ yxwz
#	define Swizzle_YZXW yzxw
#	define Swizzle_YZWX yzwx
#	define Swizzle_YWXZ ywxz
#	define Swizzle_YWZX ywzx
#	define Swizzle_ZXYW zxyw
#	define Swizzle_ZXWY zxwy
#	define Swizzle_ZYXW zyxw
#	define Swizzle_ZYWX zywx
#	define Swizzle_ZWXY zwxy
#	define Swizzle_ZWYX zwyx
#	define Swizzle_WXYZ wxyz
#	define Swizzle_WXZY wxzy
#	define Swizzle_WYXZ wyxz
#	define Swizzle_WYZX wyzx
#	define Swizzle_WZXY wzxy
#	define Swizzle_WZYX wzyx
#	define Swizzle_RGBA rgba
#	define Swizzle_RGAB rgab
#	define Swizzle_RBGA rbga
#	define Swizzle_RBAG rbag
#	define Swizzle_RAGB ragb
#	define Swizzle_RABG rabg
#	define Swizzle_GRBA grba
#	define Swizzle_GRAB grab
#	define Swizzle_GBRA gbra
#	define Swizzle_GBAR gbar
#	define Swizzle_GARB garb
#	define Swizzle_GABR gabr
#	define Swizzle_BRGA brga
#	define Swizzle_BRAG brag
#	define Swizzle_BGRA bgra
#	define Swizzle_BGAR bgar
#	define Swizzle_BARG barg
#	define Swizzle_BAGR bagr
#	define Swizzle_ARGB argb
#	define Swizzle_ARBG arbg
#	define Swizzle_AGRB agrb
#	define Swizzle_AGBR agbr
#	define Swizzle_ABRG abrg
#	define Swizzle_ABGR abgr

#else

#	define Writer_Swizzle( Input, Output, Name )\
	inline Output Name()const\
	{\
		return Output{ findShader( *this )\
			, expr::makeMbrSelect( makeExpr( this->getExpr() )\
				, expr::makeIdentifier( var::makeVariable( type::makeType( typeEnum< Output > )\
					, #Name ) ) ) };\
	}

#	define Writer_FirstSwizzle( Input, Output, Name )\
	Writer_Swizzle( Input, Output, Name )

#	define Writer_LastSwizzle( Input, Output, Name )\
	Writer_Swizzle( Input, Output, Name )

#	define Writer_OptSwizzle( Input, Output, Name )\
	inline Output Name()const\
	{\
		return Output{ findShader( *this )\
			, expr::makeMbrSelect( makeExpr( this->getExpr() )\
				, expr::makeIdentifier( var::makeVariable( type::makeType( typeEnum< Output > )\
					, #Name ) ) )\
			, this->isEnabled() };\
	}

#	define Writer_FirstOptSwizzle( Input, Output, Name )\
	Writer_OptSwizzle( Input, Output, Name )

#	define Writer_LastOptSwizzle( Input, Output, Name )\
	Writer_OptSwizzle( Input, Output, Name )


#	define Swizzle_X x()
#	define Swizzle_Y y()
#	define Swizzle_Z z()
#	define Swizzle_W w()
#	define Swizzle_R r()
#	define Swizzle_G g()
#	define Swizzle_B b()
#	define Swizzle_A a()
#	define Swizzle_XY xy()
#	define Swizzle_XZ xz()
#	define Swizzle_XW xw()
#	define Swizzle_YX yx()
#	define Swizzle_YZ yz()
#	define Swizzle_YW yw()
#	define Swizzle_ZX zx()
#	define Swizzle_ZY zy()
#	define Swizzle_ZW zw()
#	define Swizzle_WX wx()
#	define Swizzle_WY wy()
#	define Swizzle_WZ wz()
#	define Swizzle_RG rg()
#	define Swizzle_RB rb()
#	define Swizzle_RA ra()
#	define Swizzle_GR gr()
#	define Swizzle_GB gb()
#	define Swizzle_GA ga()
#	define Swizzle_BR br()
#	define Swizzle_BG bg()
#	define Swizzle_BA ba()
#	define Swizzle_AR ar()
#	define Swizzle_AG ag()
#	define Swizzle_AB ab()
#	define Swizzle_XYZ xyz()
#	define Swizzle_XYW xyw()
#	define Swizzle_XZY xzy()
#	define Swizzle_XZW xzw()
#	define Swizzle_XWY xwy()
#	define Swizzle_XWZ xwz()
#	define Swizzle_YXZ yxz()
#	define Swizzle_YXW yxw()
#	define Swizzle_YZX yzx()
#	define Swizzle_YZW yzw()
#	define Swizzle_YWX ywx()
#	define Swizzle_YWZ ywz()
#	define Swizzle_ZXY zxy()
#	define Swizzle_ZXW zxw()
#	define Swizzle_ZYX zyx()
#	define Swizzle_ZYW zyw()
#	define Swizzle_ZWX zwx()
#	define Swizzle_ZWY zwy()
#	define Swizzle_WXY wxy()
#	define Swizzle_WXZ wxz()
#	define Swizzle_WYX wyx()
#	define Swizzle_WYZ wyz()
#	define Swizzle_WZX wzx()
#	define Swizzle_WZY wzy()
#	define Swizzle_RGB rgb()
#	define Swizzle_RGA rga()
#	define Swizzle_RBG rbg()
#	define Swizzle_RBA rba()
#	define Swizzle_RAG rag()
#	define Swizzle_RAB rab()
#	define Swizzle_GRB grb()
#	define Swizzle_GRA gra()
#	define Swizzle_GBR gbr()
#	define Swizzle_GBA gba()
#	define Swizzle_GAR gar()
#	define Swizzle_GAB gab()
#	define Swizzle_BRG brg()
#	define Swizzle_BRA bra()
#	define Swizzle_BGR bgr()
#	define Swizzle_BGA bga()
#	define Swizzle_BAR bar()
#	define Swizzle_BAG bag()
#	define Swizzle_ARG arg()
#	define Swizzle_ARB arb()
#	define Swizzle_AGR agr()
#	define Swizzle_AGB agb()
#	define Swizzle_ABR abr()
#	define Swizzle_ABG abg()
#	define Swizzle_XYZW xyzw()
#	define Swizzle_XYWW xyww()
#	define Swizzle_XYWZ xywz()
#	define Swizzle_XZYW xzyw()
#	define Swizzle_XZWY xzwy()
#	define Swizzle_XWYZ xwyz()
#	define Swizzle_XWZY xwzy()
#	define Swizzle_YXZW yxzw()
#	define Swizzle_YXWZ yxwz()
#	define Swizzle_YZXW yzxw()
#	define Swizzle_YZWX yzwx()
#	define Swizzle_YWXZ ywxz()
#	define Swizzle_YWZX ywzx()
#	define Swizzle_ZXYW zxyw()
#	define Swizzle_ZXWY zxwy()
#	define Swizzle_ZYXW zyxw()
#	define Swizzle_ZYWX zywx()
#	define Swizzle_ZWXY zwxy()
#	define Swizzle_ZWYX zwyx()
#	define Swizzle_WXYZ wxyz()
#	define Swizzle_WXZY wxzy()
#	define Swizzle_WYXZ wyxz()
#	define Swizzle_WYZX wyzx()
#	define Swizzle_WZXY wzxy()
#	define Swizzle_WZYX wzyx()
#	define Swizzle_RGBA rgba()
#	define Swizzle_RGAB rgab()
#	define Swizzle_RBGA rbga()
#	define Swizzle_RBAG rbag()
#	define Swizzle_RAGB ragb()
#	define Swizzle_RABG rabg()
#	define Swizzle_GRBA grba()
#	define Swizzle_GRAB grab()
#	define Swizzle_GBRA gbra()
#	define Swizzle_GBAR gbar()
#	define Swizzle_GARB garb()
#	define Swizzle_GABR gabr()
#	define Swizzle_BRGA brga()
#	define Swizzle_BRAG brag()
#	define Swizzle_BGRA bgra()
#	define Swizzle_BGAR bgar()
#	define Swizzle_BARG barg()
#	define Swizzle_BAGR bagr()
#	define Swizzle_ARGB argb()
#	define Swizzle_ARBG arbg()
#	define Swizzle_AGRB agrb()
#	define Swizzle_AGBR agbr()
#	define Swizzle_ABRG abrg()
#	define Swizzle_ABGR abgr()

#endif
}

#include "Swizzle.inl"

#endif
