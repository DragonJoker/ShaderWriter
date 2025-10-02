#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	using namespace test;

	template< typename T >
	struct CompilerHolderT
	{
		static constexpr test::Compilers value = CurrentCompilers;
	};

	template<>
	struct CompilerHolderT< sdw::Double >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DVec2 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DVec3 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DVec4 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DMat2x2 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DMat3x3 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template<>
	struct CompilerHolderT< sdw::DMat4x4 >
	{
		static constexpr test::Compilers value = Compilers_NoHLSL;
	};

	template< typename T >
	inline constexpr test::Compilers CompilersT = CompilerHolderT< T >::value;

	inline constexpr test::Compilers AllCompilers = CurrentCompilers;

	template< typename ParamT >
	struct FloatParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct DoubleParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct UIntParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct IntParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct FloatDoubleParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct IntUIntParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct IntUIntBoolParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct FloatDoubleIntParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct FloatDoubleIntUIntParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct FloatDoubleIntUIntBoolParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct VecBoolParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct VecFloatDoubleParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct VecFloatDoubleIntUIntParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct Vec3FloatDoubleParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct MatFloatDoubleParamsT : public SDWTest
	{
	};

	template< typename ParamT >
	struct SqMatFloatDoubleParamsT : public SDWTest
	{
	};

	TYPED_TEST_SUITE( FloatParamsT, FloatTypes, TypesNames );
	TYPED_TEST_SUITE( DoubleParamsT, DoubleTypes, TypesNames );
	TYPED_TEST_SUITE( UIntParamsT, UIntTypes, TypesNames );
	TYPED_TEST_SUITE( IntParamsT, IntTypes, TypesNames );
	TYPED_TEST_SUITE( FloatDoubleParamsT, FloatDoubleTypes, TypesNames );
	TYPED_TEST_SUITE( IntUIntParamsT, IntUIntTypes, TypesNames );
	TYPED_TEST_SUITE( IntUIntBoolParamsT, IntUIntBoolTypes, TypesNames );
	TYPED_TEST_SUITE( FloatDoubleIntParamsT, FloatDoubleIntTypes, TypesNames );
	TYPED_TEST_SUITE( FloatDoubleIntUIntParamsT, FloatDoubleIntUIntTypes, TypesNames );
	TYPED_TEST_SUITE( FloatDoubleIntUIntBoolParamsT, FloatDoubleIntUIntBoolTypes, TypesNames );
	TYPED_TEST_SUITE( VecBoolParamsT, VecBoolTypes, TypesNames );
	TYPED_TEST_SUITE( VecFloatDoubleParamsT, VecFloatDoubleTypes, TypesNames );
	TYPED_TEST_SUITE( VecFloatDoubleIntUIntParamsT, VecFloatDoubleIntUIntTypes, TypesNames );
	TYPED_TEST_SUITE( Vec3FloatDoubleParamsT, Vec3FloatDoubleTypes, TypesNames );
	TYPED_TEST_SUITE( MatFloatDoubleParamsT, MatFloatDoubleTypes, TypesNames );
	TYPED_TEST_SUITE( SqMatFloatDoubleParamsT, SqMatFloatDoubleTypes, TypesNames );

	TYPED_TEST( FloatParamsT, testDegrees )
	{
		sdwTestBegin( "testDegrees" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = degrees( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testRadians )
	{
		sdwTestBegin( "testRadians" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = radians( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testCosh )
	{
		sdwTestBegin( "testCosh" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = cosh( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testSinh )
	{
		sdwTestBegin( "testSinh" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = sinh( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testTanh )
	{
		sdwTestBegin( "testTanh" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = tanh( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testCos )
	{
		sdwTestBegin( "testCos" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = cos( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testSin )
	{
		sdwTestBegin( "testSin" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = sin( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testTan )
	{
		sdwTestBegin( "testTan" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = tan( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testACos )
	{
		sdwTestBegin( "testACos" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = acos( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testASin )
	{
		sdwTestBegin( "testASin" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = asin( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testATan )
	{
		sdwTestBegin( "testATan" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = atan( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testATan2 )
	{
		sdwTestBegin( "testATan2" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto y = writer.declLocale< TypeParam >( "y" );
					auto x = writer.declLocale< TypeParam >( "x" );
					x = atan2( y, x );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testACosh )
	{
		sdwTestBegin( "testACosh" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = acosh( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testASinh )
	{
		sdwTestBegin( "testASinh" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = asinh( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testATanh )
	{
		sdwTestBegin( "testATanh" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = atanh( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testPow )
	{
		sdwTestBegin( "testPow" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					v1 = pow( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testExp )
	{
		sdwTestBegin( "testExp" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = exp( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testLog )
	{
		sdwTestBegin( "testLog" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = log( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testExp2 )
	{
		sdwTestBegin( "testExp2" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = exp2( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testLog2 )
	{
		sdwTestBegin( "testLog2" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = log2( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testSqrt )
	{
		sdwTestBegin( "testSqrt" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testInverseSqrt )
	{
		sdwTestBegin( "testInverseSqrt" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntParamsT, testAbs )
	{
		sdwTestBegin( "testAbs" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntParamsT, testSign )
	{
		sdwTestBegin( "testSign" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testFloor )
	{
		sdwTestBegin( "testFloor" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testTrunc )
	{
		sdwTestBegin( "testTrunc" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testRound )
	{
		sdwTestBegin( "testRound" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testRoundEven )
	{
		sdwTestBegin( "testRoundEven" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testCeil )
	{
		sdwTestBegin( "testCeil" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testFract )
	{
		sdwTestBegin( "testFract" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testMod )
	{
		sdwTestBegin( "testMod" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testModf )
	{
		sdwTestBegin( "testModf" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testMin )
	{
		sdwTestBegin( "testMin" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testMax )
	{
		sdwTestBegin( "testMax" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testClamp )
	{
		sdwTestBegin( "testClamp" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					auto v3 = writer.declLocale< TypeParam >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testMix )
	{
		sdwTestBegin( "testMix" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					auto v3 = writer.declLocale< TypeParam >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testStep )
	{
		sdwTestBegin( "testStep" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testSmoothStep )
	{
		sdwTestBegin( "testSmoothStep" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					auto v3 = writer.declLocale< TypeParam >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testIsnan )
	{
		sdwTestBegin( "testIsnan" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					writer.declLocale( "r", sdw::isnan( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testIsinf )
	{
		sdwTestBegin( "testIsinf" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					writer.declLocale( "r", sdw::isinf( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testFloatBitsToInt )
	{
		sdwTestBegin( "testFloatBitsToInt" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testFloatBitsToUInt )
	{
		sdwTestBegin( "testFloatBitsToUInt" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToUInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntParamsT, testIntBitsToFloat )
	{
		sdwTestBegin( "testIntBitsToFloat" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto res = writer.declLocale( "res"
						, intBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( UIntParamsT, testUIntBitsToFloat )
	{
		sdwTestBegin( "testUIntBitsToFloat" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto res = writer.declLocale( "res"
						, uintBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testFma )
	{
		sdwTestBegin( "testFma" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					auto v3 = writer.declLocale< TypeParam >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	template< typename TypeParam, typename ValueU >
	void testFrexpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFrexp" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< ValueU >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testFrexp )
	{
		sdwTestBegin( "testFrexp" );
		testFrexpT< sdw::Float, sdw::Int >( "1F", testCounts );
		testFrexpT< sdw::Vec2, sdw::IVec2 >( "2F", testCounts );
		testFrexpT< sdw::Vec3, sdw::IVec3 >( "3F", testCounts );
		testFrexpT< sdw::Vec4, sdw::IVec4 >( "4F", testCounts );
		testFrexpT< sdw::Double, sdw::Int >( "1D", testCounts );
		testFrexpT< sdw::DVec2, sdw::IVec2 >( "2D", testCounts );
		testFrexpT< sdw::DVec3, sdw::IVec3 >( "3D", testCounts );
		testFrexpT< sdw::DVec4, sdw::IVec4 >( "4D", testCounts );
		sdwTestEnd()
	}

	template< typename TypeParam, typename ValueU >
	void testLdexpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testLdexp" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< ValueU >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testLdexp )
	{
		sdwTestBegin( "testLdexp" );
		testLdexpT< sdw::Float, sdw::Int >( "1F", testCounts );
		testLdexpT< sdw::Vec2, sdw::IVec2 >( "2F", testCounts );
		testLdexpT< sdw::Vec3, sdw::IVec3 >( "3F", testCounts );
		testLdexpT< sdw::Vec4, sdw::IVec4 >( "4F", testCounts );
		testLdexpT< sdw::Double, sdw::Int >( "1D", testCounts );
		testLdexpT< sdw::DVec2, sdw::IVec2 >( "2D", testCounts );
		testLdexpT< sdw::DVec3, sdw::IVec3 >( "3D", testCounts );
		testLdexpT< sdw::DVec4, sdw::IVec4 >( "4D", testCounts );
		sdwTestEnd()
	}

	TEST_F( SDWTest, testPackDouble2x32 )
	{
		sdwTestBegin( "testPackDouble2x32" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UVec2 >( "v" );
					auto r = writer.declLocale< Double >( "r" );
					r = packDouble2x32( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testPackHalf2x16 )
	{
		sdwTestBegin( "testPackHalf2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packHalf2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testPackSnorm2x16 )
	{
		sdwTestBegin( "testPackSnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testPackUnorm2x16 )
	{
		sdwTestBegin( "testPackUnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testPackSnorm4x8 )
	{
		sdwTestBegin( "testPackSnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testPackUnorm4x8 )
	{
		sdwTestBegin( "testPackUnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUnpackDouble2x32 )
	{
		sdwTestBegin( "testUnpackDouble2x32" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Double >( "v" );
					auto r = writer.declLocale< UVec2 >( "r" );
					r = unpackDouble2x32( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUnpackHalf2x16 )
	{
		sdwTestBegin( "testUnpackHalf2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackHalf2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUnpackSnorm2x16 )
	{
		sdwTestBegin( "testUnpackSnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackSnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUnpackUnorm2x16 )
	{
		sdwTestBegin( "testUnpackUnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackUnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUnpackSnorm4x8 )
	{
		sdwTestBegin( "testUnpackSnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackSnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testUnpackUnorm4x8 )
	{
		sdwTestBegin( "testUnpackUnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackUnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testLength )
	{
		sdwTestBegin( "testLength" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					writer.declLocale( "r", length( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testDistance )
	{
		sdwTestBegin( "testDistance" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					writer.declLocale( "r", distance( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecFloatDoubleParamsT, testDot )
	{
		sdwTestBegin( "testDot" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					writer.declLocale( "r", dot( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( Vec3FloatDoubleParamsT, testCross )
	{
		sdwTestBegin( "testCross" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					writer.declLocale( "r", cross( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testNormalize )
	{
		sdwTestBegin( "testNormalize" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					writer.declLocale( "r", normalize( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testFaceForward )
	{
		sdwTestBegin( "testFaceForward" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					auto v3 = writer.declLocale< TypeParam >( "v3" );
					writer.declLocale( "r", faceForward( v1, v2, v3 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testReflect )
	{
		sdwTestBegin( "testReflect" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					writer.declLocale( "r", reflect( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleParamsT, testRefract )
	{
		sdwTestBegin( "testRefract" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto v2 = writer.declLocale< TypeParam >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					writer.declLocale( "r", refract( v1, v2, v3 ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( MatFloatDoubleParamsT, testMatrixCompMult )
	{
		sdwTestBegin( "testMatrixCompMult" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, matrixCompMult( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SqMatFloatDoubleParamsT, testMatrixMult )
	{
		sdwTestBegin( "testMatrixMult" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, lhs * rhs );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	template< typename LhsT, typename RhsT >
	void testOuterProductT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testOuterProduct" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< LhsT >( "lhs" );
					auto rhs = writer.declLocale< RhsT >( "rhs" );
					auto res = writer.declLocale( "res"
						, outerProduct( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testOuterProduct )
	{
		sdwTestBegin( "testOuterProduct" );
		testOuterProductT< sdw::Vec2, sdw::Vec2 >( "2x2F", testCounts );
		testOuterProductT< sdw::Vec2, sdw::Vec3 >( "2x3F", testCounts );
		testOuterProductT< sdw::Vec2, sdw::Vec4 >( "2x4F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec2 >( "3x2F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec3 >( "3x3F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec4 >( "3x4F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec2 >( "4x2F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec3 >( "4x3F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec4 >( "4x4F", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec2 >( "2x2D", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec3 >( "2x3D", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec4 >( "2x4D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec2 >( "3x2D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec3 >( "3x3D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec4 >( "3x4D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec2 >( "4x2D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec3 >( "4x3D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec4 >( "4x4D", testCounts );
		sdwTestEnd()
	}

	TYPED_TEST( MatFloatDoubleParamsT, testTranspose )
	{
		sdwTestBegin( "testTranspose" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< TypeParam >( "v" );
					auto r = writer.declLocale( "r"
						, transpose( v ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SqMatFloatDoubleParamsT, testDeterminant )
	{
		sdwTestBegin( "testDeterminant" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto m = writer.declLocale< TypeParam >( "m" );
					writer.declLocale( "r", determinant( m ) );
				} );
			test::writeShader( writer
				, testCounts, CompilersT< TypeParam > );
		}
		sdwTestEnd()
	}

	TYPED_TEST( SqMatFloatDoubleParamsT, testInverse )
	{
		sdwTestBegin( "testInverse" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto m = writer.declLocale< TypeParam >( "m" );
					writer.declLocale( "r", inverse( m ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecFloatDoubleIntUIntParamsT, testLessThan )
	{
		sdwTestBegin( "testLessThan" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThan( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecFloatDoubleIntUIntParamsT, testLessThanEqual )
	{
		sdwTestBegin( "testLessThanEqual" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecFloatDoubleIntUIntParamsT, testGreaterThan )
	{
		sdwTestBegin( "testGreaterThan" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThan( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecFloatDoubleIntUIntParamsT, testGreaterThanEqual )
	{
		sdwTestBegin( "testGreaterThanEqual" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecFloatDoubleIntUIntParamsT, testEqual )
	{
		sdwTestBegin( "testEqual" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, equal( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecFloatDoubleIntUIntParamsT, testNotEqual )
	{
		sdwTestBegin( "testNotEqual" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< TypeParam >( "lhs" );
					auto rhs = writer.declLocale< TypeParam >( "rhs" );
					auto res = writer.declLocale( "res"
						, notEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecBoolParamsT, testAll )
	{
		sdwTestBegin( "testAll" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto operand = writer.declLocale< TypeParam >( "operand" );
					auto res = writer.declLocale( "res"
						, all( operand ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecBoolParamsT, testAny )
	{
		sdwTestBegin( "testAny" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto operand = writer.declLocale< TypeParam >( "operand" );
					auto res = writer.declLocale( "res"
						, any( operand ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( VecBoolParamsT, testNot )
	{
		sdwTestBegin( "testNot" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto operand = writer.declLocale< TypeParam >( "operand" );
					auto res = writer.declLocale( "res"
						, binNot( operand ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( UIntParamsT, testUaddCarry )
	{
		sdwTestBegin( "testUaddCarry" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto y = writer.declLocale< TypeParam >( "y" );
					auto c = writer.declLocale< TypeParam >( "c" );
					auto r = writer.declLocale< TypeParam >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TYPED_TEST( UIntParamsT, testUsubBorrow )
	{
		sdwTestBegin( "testUsubBorrow" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto y = writer.declLocale< TypeParam >( "y" );
					auto b = writer.declLocale< TypeParam >( "b" );
					auto r = writer.declLocale< TypeParam >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TYPED_TEST( UIntParamsT, testUmulExtended )
	{
		sdwTestBegin( "testUmulExtended" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto y = writer.declLocale< TypeParam >( "y" );
					auto h = writer.declLocale< TypeParam >( "h" );
					auto l = writer.declLocale< TypeParam >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntParamsT, testImulExtended )
	{
		sdwTestBegin( "testImulExtended" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto y = writer.declLocale< TypeParam >( "y" );
					auto h = writer.declLocale< TypeParam >( "h" );
					auto l = writer.declLocale< TypeParam >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntParamsT, testBitfieldExtract )
	{
		sdwTestBegin( "testBitfieldExtract" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntParamsT, testBitfieldInsert )
	{
		sdwTestBegin( "testBitfieldInsert" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto y = writer.declLocale< TypeParam >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntParamsT, testBitfieldReverse )
	{
		sdwTestBegin( "testBitfieldReverse" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntParamsT, testBitCount )
	{
		sdwTestBegin( "testBitCount" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntParamsT, testFindLSB )
	{
		sdwTestBegin( "testFindLSB" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntParamsT, testFindMSB )
	{
		sdwTestBegin( "testFindMSB" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers compilers = CurrentCompilers )
	{
		astOn( "testAtomicAdd" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicAdd( bo[0].getMember< TypeParam >( mbrName ), x ) );
					atomicAdd( bo[0].getMember< TypeParam >( mbrName ), x );
					atomicAdd( bo[0].getMember< TypeParam >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testAtomicAdd )
	{
		sdwTestBegin( "testAtomicAdd" );
		testAtomicAddT< sdw::Int >( "I", testCounts );
		testAtomicAddT< sdw::UInt >( "U", testCounts );
		testAtomicAddT< sdw::Float >( "F", testCounts );
		//testAtomicAddT< sdw::HVec2 >( "2H", testCounts, Compilers_NoHLSL );
		//testAtomicAddT< sdw::HVec4 >( "4H", testCounts, Compilers_NoHLSL );
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicMin" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicMin( bo[0].getMember< TypeParam >( mbrName ), x ) );
					atomicMin( bo[0].getMember< TypeParam >( mbrName ), x );
					atomicMin( bo[0].getMember< TypeParam >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicMin )
	{
		sdwTestBegin( "testAtomicMin" );
		testAtomicMinT< sdw::Int >( "I", testCounts );
		testAtomicMinT< sdw::UInt >( "U", testCounts );
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicMax" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicMax( bo[0].getMember< TypeParam >( mbrName ), x ) );
					atomicMax( bo[0].getMember< TypeParam >( mbrName ), x );
					atomicMax( bo[0].getMember< TypeParam >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicMax )
	{
		sdwTestBegin( "testAtomicMax" );
		testAtomicMaxT< sdw::Int >( "I", testCounts );
		testAtomicMaxT< sdw::UInt >( "U", testCounts );
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicAnd" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicAnd( bo[0].getMember< TypeParam >( mbrName ), x ) );
					atomicAnd( bo[0].getMember< TypeParam >( mbrName ), x );
					atomicAnd( bo[0].getMember< TypeParam >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicAnd )
	{
		sdwTestBegin( "testAtomicAnd" );
		testAtomicAndT< sdw::Int >( "I", testCounts );
		testAtomicAndT< sdw::UInt >( "U", testCounts );
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicOr" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicOr( bo[0].getMember< TypeParam >( mbrName ), x ) );
					atomicOr( bo[0].getMember< TypeParam >( mbrName ), x );
					atomicOr( bo[0].getMember< TypeParam >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicOr )
	{
		sdwTestBegin( "testAtomicOr" );
		testAtomicOrT< sdw::Int >( "I", testCounts );
		testAtomicOrT< sdw::UInt >( "U", testCounts );
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicXor" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicXor( bo[0].getMember< TypeParam >( mbrName ), x ) );
					atomicXor( bo[0].getMember< TypeParam >( mbrName ), x );
					atomicXor( bo[0].getMember< TypeParam >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicXor )
	{
		sdwTestBegin( "testAtomicXor" );
		testAtomicXorT< sdw::Int >( "I", testCounts );
		testAtomicXorT< sdw::UInt >( "U", testCounts );
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicExchangeT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers compilers = CurrentCompilers )
	{
		astOn( "testAtomicExchange" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< TypeParam >( "x", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicExchange( bo[0].getMember< TypeParam >( mbrName ), x ) );
					atomicExchange( bo[0].getMember< TypeParam >( mbrName ), x );
					atomicExchange( bo[0].getMember< TypeParam >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testAtomicExchange )
	{
		sdwTestBegin( "testAtomicExchange" );
		testAtomicExchangeT< sdw::Int >( "I", testCounts );
		testAtomicExchangeT< sdw::UInt >( "U", testCounts );
		testAtomicExchangeT< sdw::Float >( "F", testCounts, Compilers_NoHLSL );
		//testAtomicExchangeT< sdw::HVec2 >( "2H", testCounts, Compilers_NoHLSL );
		//testAtomicExchangeT< sdw::HVec4 >( "4H", testCounts, Compilers_NoHLSL );
		sdwTestEnd()
	}

	template< typename TypeParam >
	void testAtomicCompSwapT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicCompSwap" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< TypeParam >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto c = writer.declLocale< TypeParam >( "c", test::getDefault< TypeParam >( writer ) );
					auto v = writer.declLocale< TypeParam >( "v", test::getDefault< TypeParam >( writer ) );
					writer.declLocale( "r"
						, atomicCompSwap( bo[0].getMember< TypeParam >( mbrName ), c, v ) );
					atomicCompSwap( bo[0].getMember< TypeParam >( mbrName ), c, v );
					atomicCompSwap( bo[0].getMember< TypeParam >( mbrName ), c, v ) * c;
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicCompSwap )
	{
		sdwTestBegin( "testAtomicCompSwap" );
		testAtomicCompSwapT< sdw::Int >( "I", testCounts );
		testAtomicCompSwapT< sdw::UInt >( "U", testCounts );
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testDFdx )
	{
		sdwTestBegin( "testDFdx" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto r = writer.declLocale( "r", dFdx( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testDFdxCoarse )
	{
		sdwTestBegin( "testDFdxCoarse" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto r = writer.declLocale( "r", dFdxCoarse( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testDFdxFine )
	{
		sdwTestBegin( "testDFdxFine" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto r = writer.declLocale( "r", dFdxFine( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testDFdy )
	{
		sdwTestBegin( "testDFdy" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto r = writer.declLocale( "r", dFdy( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testDFdyCoarse )
	{
		sdwTestBegin( "testDFdyCoarse" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto r = writer.declLocale( "r", dFdyCoarse( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testDFdyFine )
	{
		sdwTestBegin( "testDFdyFine" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto r = writer.declLocale( "r", dFdyFine( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testFwidth )
	{
		sdwTestBegin( "testFwidth" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< TypeParam >( "v1" );
					auto r = writer.declLocale( "r", fwidth( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testInterpolateAtCentroid )
	{
		sdwTestBegin( "testInterpolateAtCentroid" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto inputs = writer.declInput< TypeParam >( "inputs", 0u );
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto r = writer.declLocale( "r", interpolateAtCentroid( inputs ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testInterpolateAtSample )
	{
		sdwTestBegin( "testInterpolateAtSample" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto inputs = writer.declInput< TypeParam >( "inputs", 0u );
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto r = writer.declLocale( "r", interpolateAtSample( inputs, 0_i ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatParamsT, testInterpolateAtOffset )
	{
		sdwTestBegin( "testInterpolateAtOffset" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto inputs = writer.declInput< TypeParam >( "inputs", 0u );
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto r = writer.declLocale( "r", interpolateAtOffset( inputs, vec2( -0.5_f ) ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_NoHLSL );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testBarrier )
	{
		sdwTestBegin( "testBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.barrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		{
			static constexpr uint32_t MaxPoints = 1u;
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[in.primitiveID].vtx.position.w();
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					writer.barrier();
					listOut.vtx.position = listIn[in.invocationID].vtx.position * 2.0_f;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testMemoryBarrier )
	{
		sdwTestBegin( "testMemoryBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testMemoryBarrierBuffer )
	{
		sdwTestBegin( "testMemoryBarrierBuffer" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrierBuffer();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testMemoryBarrierShared )
	{
		sdwTestBegin( "testMemoryBarrierShared" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrierShared();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testMemoryBarrierImage )
	{
		sdwTestBegin( "testMemoryBarrierImage" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrierImage();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testGroupMemoryBarrier )
	{
		sdwTestBegin( "testGroupMemoryBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.groupMemoryBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	template< sdw::var::Flag FlagT >
	struct PayloadT
		: public sdw::StructInstance
	{
		PayloadT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, meshletIndices{ getMemberArray< sdw::UInt >( "meshletIndices" ) }
		{
		}

		SDW_DeclStructInstance( , PayloadT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Payload"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "meshletIndices"
					, sdw::type::Kind::eUInt
					, 32u
					, ast::type::Struct::InvalidLocation );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Payload" );

			if ( result->empty() )
			{
				result->declMember( "meshletIndices"
					, sdw::type::Kind::eUInt
					, 32u );
			}

			return result;
		}

		sdw::Array< sdw::UInt > meshletIndices;
	};

	TEST_F( SDWTest, testSetMeshOutputCountsNV )
	{
		sdwTestBegin( "testSetMeshOutputCountsNV" );
		using namespace sdw;
		{
			sdw::MeshWriterNV writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshInNV in
					, TaskPayloadInNVT< PayloadT > payload
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshNVPrimitiveListOutT< VoidT > primOut )
				{
					auto index = writer.declLocale( "index"
						, payload.meshletIndices[0_u] );
					primOut.setMeshOutputCounts( 3_u, 1_u );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSetMeshOutputCounts )
	{
		sdwTestBegin( "testSetMeshOutputCounts" );
		using namespace sdw;
		{
			sdw::MeshWriterEXT writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT, VoidT, VoidT >( 32u, 1u, 1u
				, 64u
				, 126u
				, [&]( MeshInEXT in
					, TaskPayloadInEXTT< PayloadT > payload
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshEXTPrimitiveListOutT< VoidT > primOut )
				{
					auto index = writer.declLocale( "index"
						, payload.meshletIndices[0_u] );
					primOut.setMeshOutputCounts( 3_u, 1_u );
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts, Compilers_NoGLSL );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testDispatchMeshNV )
	{
		sdwTestBegin( "testDispatchMeshNV" );
		using namespace sdw;
		{
			sdw::TaskWriterNV writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( 32u
				, TaskPayloadOutNVT< PayloadT >{ writer }
				, [&]( TaskInNV in
					, TaskPayloadOutNVT< PayloadT > payload )
				{
					payload.meshletIndices[0_u] = 1_u;
					payload.dispatchMesh( 1_u );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testDispatchMesh )
	{
		sdwTestBegin( "testDispatchMesh" );
		using namespace sdw;
		{
			sdw::TaskWriterEXT writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( 32u, 1u, 1u
				, TaskPayloadOutEXTT< PayloadT >{ writer }
				, [&]( TaskInEXT in
					, TaskPayloadOutEXTT< PayloadT > payload )
				{
					payload.meshletIndices[0_u] = 1_u;
					payload.dispatchMesh( 1_u, 1_u, 1_u );
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts, Compilers_NoGLSL );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testHelperInvocation )
	{
		sdwTestBegin( "testHelperInvocation" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto isHelper = writer.declLocale( "isHelper"
						, helperInvocation( writer ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_SPIRV );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBarrier )
	{
		sdwTestBegin( "testSubgroupBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrier )
	{
		sdwTestBegin( "testSubgroupMemoryBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrierBuffer )
	{
		sdwTestBegin( "testSubgroupMemoryBarrierBuffer" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrierBuffer();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrierShared )
	{
		sdwTestBegin( "testSubgroupMemoryBarrierShared" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrierShared();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrierImage )
	{
		sdwTestBegin( "testSubgroupMemoryBarrierImage" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrierImage();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupElect )
	{
		sdwTestBegin( "testSubgroupElect" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					auto result = writer.declLocale( "result"
						, subgroupElect( writer ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupAll )
	{
		sdwTestBegin( "testSubgroupAll" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					auto op = writer.declLocale< Boolean >( "op"
						, test::getDefault< Boolean >( writer ) );
					auto result = writer.declLocale( "result"
						, subgroupAll( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupAny )
	{
		sdwTestBegin( "testSubgroupAny" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					auto op = writer.declLocale< Boolean >( "op"
						, test::getDefault< Boolean >( writer ) );
					auto result = writer.declLocale( "result"
						, subgroupAny( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupAllEqual )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupAllEqual" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op" );
					auto res = writer.declLocale( "res"
						, subgroupAllEqual( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupBroadcast )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupBroadcast" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBroadcast( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupBroadcastFirst )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupBroadcastFirst" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBroadcastFirst( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBallot )
	{
		sdwTestBegin( "testSubgroupBallot" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< Boolean >( "op"
						, test::getDefault< Boolean >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallot( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupInverseBallot )
	{
		sdwTestBegin( "testSubgroupInverseBallot" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupInverseBallot( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBallotBitExtract )
	{
		sdwTestBegin( "testSubgroupBallotBitExtract" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotBitExtract( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBallotBitCount )
	{
		sdwTestBegin( "testSubgroupBallotBitCount" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotBitCount( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBallotInclusiveBitCount )
	{
		sdwTestBegin( "testSubgroupBallotInclusiveBitCount" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotInclusiveBitCount( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBallotExclusiveBitCount )
	{
		sdwTestBegin( "testSubgroupBallotExclusiveBitCount" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotExclusiveBitCount( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBallotFindLSB )
	{
		sdwTestBegin( "testSubgroupBallotFindLSB" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotFindLSB( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, testSubgroupBallotFindMSB )
	{
		sdwTestBegin( "testSubgroupBallotFindMSB" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op"  
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotFindMSB( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupShuffle )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupShuffle" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op" 
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffle( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupShuffleXor )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupShuffleXor" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffle( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupShuffleUp )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupShuffleUp" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffleUp( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupShuffleDown )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupShuffleDown" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffleDown( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupAdd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupAdd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupInclusiveAdd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupInclusiveAdd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupExclusiveAdd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupExclusiveAdd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupClusterAdd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupClusterAdd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupMul )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupMul" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupInclusiveMul )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupInclusiveMul" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupExclusiveMul )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupExclusiveMul" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupClusterMul )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupClusterMul" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupMin )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupMin" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupInclusiveMin )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupInclusiveMin" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupExclusiveMin )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupExclusiveMin" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupClusterMin )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupClusterMin" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupMax )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupMax" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupInclusiveMax )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupInclusiveMax" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupExclusiveMax )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupExclusiveMax" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testSubgroupClusterMax )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupClusterMax" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupAnd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupAnd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupInclusiveAnd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupInclusiveAnd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupExclusiveAnd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupExclusiveAnd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupClusterAnd )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupClusterAnd" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupOr )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupOr" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupInclusiveOr )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupInclusiveOr" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupExclusiveOr )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupExclusiveOr" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupClusterOr )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupClusterOr" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupXor )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupXor" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupInclusiveXor )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupInclusiveXor" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupExclusiveXor )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupExclusiveXor" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( IntUIntBoolParamsT, testSubgroupClusterXor )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupClusterXor" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupQuadBroadcast )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupQuadBroadcast" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadBroadcast( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupQuadSwapHorizontal )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupQuadSwapHorizontal" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadSwapHorizontal( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupQuadSwapVertical )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupQuadSwapVertical" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadSwapVertical( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntBoolParamsT, testSubgroupQuadSwapDiagonal )
	{
		using namespace sdw;
		sdwTestBegin( "testSubgroupQuadSwapDiagonal" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadSwapDiagonal( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testReadInvocation )
	{
		using namespace sdw;
		sdwTestBegin( "testReadInvocation" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, readInvocation( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}

	TYPED_TEST( FloatDoubleIntUIntParamsT, testReadFirstInvocation )
	{
		using namespace sdw;
		sdwTestBegin( "testReadFirstInvocation" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< TypeParam >( "op"
						, test::getDefault< TypeParam >( writer ) );
					auto res = writer.declLocale( "res"
						, readFirstInvocation( op ) );
				} );
			test::writeShader( writer
				, testCounts, AllCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
