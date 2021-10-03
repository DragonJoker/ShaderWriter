/*
See LICENSE file in root folder
*/
namespace spirv
{
	//*************************************************************************

	namespace details
	{
		enum class ValueType : uint32_t
		{
			eVoid = 0x00000001,
			eLiteral = 0x00000002,
			eBool = 0x00000004,
			eInteger = 0x00000008,
			eFloat = 0x00000010,
			eVector = 0x00000020,
			eMatrix = 0x00000040,
			eImage = 0x00000080,
			eSampler = 0x00000100,
			eSampledImage = 0x00000200,
			eArray = 0x00000400,
			eRuntimeArray = 0x00000800,
			eStruct = 0x00001000,
			ePointer = 0x00002000,
			eFunction = 0x00004000,
			eComposite = 0x00008000,

			eIntegerOrFloat = eInteger | eFloat,
			eScalar = eBool | eIntegerOrFloat,
			eScalarOrVoid = eVoid | eScalar,
			eAny = 0xFFFFFFFF,
			eNonPointer = ( eAny & ~( ePointer ) )
		};

		template< ValueType ... ParamsT >
		struct ValueTypeListT
		{
		};

		template< spv::Op OpT >
		struct OpParamsT
		{
			using ArePointer = ValueTypeListT<>;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpMemberDecorate >
		{
			using ArePointer = ValueTypeListT< ValueType::eStruct, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpMemberName >
		{
			using ArePointer = ValueTypeListT< ValueType::eStruct, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeBool >
		{
			using ArePointer = ValueTypeListT< ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeInt >
		{
			using ArePointer = ValueTypeListT< ValueType::eInteger, ValueType::eLiteral, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeFloat >
		{
			using ArePointer = ValueTypeListT< ValueType::eFloat, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeVector >
		{
			using ArePointer = ValueTypeListT< ValueType::eVector, ValueType::eScalar, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeMatrix >
		{
			using ArePointer = ValueTypeListT< ValueType::eMatrix, ValueType::eVector, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeImage >
		{
			using ArePointer = ValueTypeListT< ValueType::eImage, ValueType::eScalarOrVoid, ValueType::eAny, ValueType::eAny, ValueType::eAny, ValueType::eAny, ValueType::eAny, ValueType::eAny >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeSampler >
		{
			using ArePointer = ValueTypeListT< ValueType::eSampler >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeSampledImage >
		{
			using ArePointer = ValueTypeListT< ValueType::eSampledImage, ValueType::eImage >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeArray >
		{
			using ArePointer = ValueTypeListT< ValueType::eArray, ValueType::eAny, ValueType::eInteger >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeRuntimeArray >
		{
			using ArePointer = ValueTypeListT< ValueType::eRuntimeArray, ValueType::eAny >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeStruct >
		{
			using ArePointer = ValueTypeListT< ValueType::eStruct >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypePointer >
		{
			using ArePointer = ValueTypeListT< ValueType::ePointer, ValueType::eInteger >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpTypeFunction >
		{
			using ArePointer = ValueTypeListT< ValueType::eFunction >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpConstantTrue >
		{
			using ArePointer = ValueTypeListT< ValueType::eBool, ValueType::eNonPointer >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpConstantFalse >
		{
			using ArePointer = ValueTypeListT< ValueType::eBool, ValueType::eNonPointer >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpConstant >
		{
			using ArePointer = ValueTypeListT< ValueType::eIntegerOrFloat, ValueType::eNonPointer, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpConstantComposite >
		{
			using ArePointer = ValueTypeListT< ValueType::eComposite, ValueType::eNonPointer >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpSpecConstantTrue >
		{
			using ArePointer = ValueTypeListT< ValueType::eBool, ValueType::eNonPointer >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpSpecConstantFalse >
		{
			using ArePointer = ValueTypeListT< ValueType::eBool, ValueType::eNonPointer >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpSpecConstant >
		{
			using ArePointer = ValueTypeListT< ValueType::eIntegerOrFloat, ValueType::eNonPointer, ValueType::eLiteral >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpSpecConstantComposite >
		{
			using ArePointer = ValueTypeListT< ValueType::eComposite, ValueType::eNonPointer >;
		};

		template< spv::Op OpT >
		struct OpParamsT;
		template<> struct OpParamsT< spv::OpSpecConstantOp >
		{
			using ArePointer = ValueTypeListT< ValueType::eNonPointer, ValueType::eNonPointer, ValueType::eLiteral >;
		};

		//using SwitchInstruction = InstructionT< spv::OpSwitch, false, false, 2u, false, true >;
		//using SelectInstruction = InstructionT< spv::OpSelect, true, true, 3u, false, false >;
		//using LoadInstruction = InstructionT< spv::OpLoad, true, true, 1u, false, false >;
		//using StoreInstruction = InstructionT< spv::OpStore, false, false, 2u, false, false >;
		//using CopyMemoryInstruction = VariadicInstructionT< spv::OpCopyMemory, false, false >;
		//using VariableInstruction = VariadicInstructionT< spv::OpVariable, true, true >;
		//using CompositeExtractInstruction = VariadicInstructionT< spv::OpCompositeExtract, true, true >;
		//using CompositeConstructInstruction = VariadicInstructionT< spv::OpCompositeConstruct, true, true >;
		//using VectorShuffleInstruction = VariadicInstructionT< spv::OpVectorShuffle, true, true >;
		//using AccessChainInstruction = VariadicInstructionT< spv::OpAccessChain, true, true >;
		//using FunctionCallInstruction = VariadicInstructionT< spv::OpFunctionCall, true, true >;
		//using ImageTexelPointerInstruction = VariadicInstructionT< spv::OpImageTexelPointer, true, true >;
		//using ImageInstruction = InstructionT< spv::OpImage, true, true, 1u, false, false >;
		//using ImageStoreInstruction = VariadicInstructionT< spv::OpImageWrite, false, false >;
		//using ExtInstInstruction = VariadicInstructionT< spv::OpExtInst, true, true >;
		//using FunctionParameterInstruction = InstructionT< spv::OpFunctionParameter, true, true, 0u, false, false >;
		//using LabelInstruction = InstructionT< spv::OpLabel, false, true, 0u, false, false >;
		//using FunctionInstruction = InstructionT< spv::OpFunction, true, true, 2u, false, false >;

		//using KillInstruction = InstructionT< spv::OpKill, false, false, 0u, false, false >;
		//using BranchInstruction = InstructionT< spv::OpBranch, false, false, 1u, false, false >;
		//using BranchConditionalInstruction = VariadicInstructionT< spv::OpBranchConditional, false, false >;
		//using SelectionMergeInstruction = InstructionT< spv::OpSelectionMerge, false, false, 2u, false, false >;
		//using LoopMergeInstruction = InstructionT< spv::OpLoopMerge, false, false, 3u, false, false >;
		//using ReturnInstruction = InstructionT< spv::OpReturn, false, false, 0u, false, false >;
		//using ReturnValueInstruction = InstructionT< spv::OpReturnValue, false, false, 1u, false, false >;
		//using UndefInstruction = InstructionT< spv::OpUndef, true, true, 0u, false, false >;
		//using FunctionEndInstruction = InstructionT< spv::OpFunctionEnd, false, false, 0u, false, false >;

		template< typename ... Params >
		ValueIdList makeOperandsRec( ValueIdList & result, Params ... params );

		inline void makeOperandsRec( ValueIdList & result, ValueId param )
		{
			result.push_back( param );
		}

		inline void makeOperandsRec( ValueIdList & result, spv::Id param )
		{
			makeOperandsRec( result, ValueId{ param } );
		}

		inline void makeOperandsRec( ValueIdList & result, ValueIdList const & param )
		{
			result.insert( result.end(), param.begin(), param.end() );
		}

		inline void makeOperandsRec( ValueIdList & result, IdList const & param )
		{
			makeOperandsRec( result, convert( param ) );
		}

		template< typename ... Params >
		inline void makeOperandsRec( ValueIdList & result, ValueId current, Params ... params )
		{
			makeOperandsRec( result, current );
			makeOperandsRec( result, params... );
		}

		template< typename ... Params >
		inline void makeOperandsRec( ValueIdList & result, spv::Id current, Params ... params )
		{
			makeOperandsRec( result, ValueId{ current }, params... );
		}

		template< typename ... Params >
		inline void makeOperandsRec( ValueIdList & result, ValueIdList const & current, Params ... params )
		{
			makeOperandsRec( result, current );
			makeOperandsRec( result, params... );
		}

		template< typename ... Params >
		inline void makeOperandsRec( ValueIdList & result, IdList const & current, Params ... params )
		{
			makeOperandsRec( result, convert( current ), params... );
		}
	}

	template< typename ... Params >
	inline ValueIdList makeOperands( Params ... params )
	{
		ValueIdList result;
		details::makeOperandsRec( result, params... );
		return result;
	}

	//*************************************************************************

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	inline InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >::InstructionT( Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList poperands
		, Optional< std::string > pname
		, Optional< std::map< int32_t, spv::Id > > plabels )
		: Instruction{ config, Operator, preturnTypeId, presultId, poperands, pname, plabels }
	{
		assertType< Operator
			, hasReturnTypeId
			, hasResultId
			, operandsCount
			, hasName
			, hasLabels >( *this );
	}

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	inline InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >::InstructionT( UInt32ListIt & buffer )
		: Instruction{ config, Operator, buffer }
	{
	}

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	inline InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >::InstructionT( UInt32ListCIt & buffer )
		: Instruction{ config, Operator, buffer }
	{
	}

	//*************************************************************************

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId >
	inline VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >::VariadicInstructionT( Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList poperands )
		: InstructionT< Operator, HasReturnTypeId, HasResultId, dynamicOperandCount, false, false >{ preturnTypeId, presultId, poperands, nullopt, nullopt }
	{
	}

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId >
	inline VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >::VariadicInstructionT( UInt32ListIt & buffer )
		: InstructionT< Operator, HasReturnTypeId, HasResultId, dynamicOperandCount, false, false >{ buffer, hasReturnTypeId, hasResultId, operandsCount, hasName, hasLabels }
	{
	}

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId >
	inline VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >::VariadicInstructionT( UInt32ListCIt & buffer )
		: InstructionT< Operator, HasReturnTypeId, HasResultId, dynamicOperandCount, false, false >{ buffer, hasReturnTypeId, hasResultId, operandsCount, hasName, hasLabels }
	{
	}

	//*************************************************************************

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 0u, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{}
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 1u, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand, std::string const & name )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, list
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 2u, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand0, ValueId operand1, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{ { operand0, operand1 } }
				, name
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueIdList operands, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, false, false, OperandsCount, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueIdList operands, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, true, 0u, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, ValueIdList{}
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, true, 1u, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueId operand, std::string const & name )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, list
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, true, 2u, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueId operand0, ValueId operand1, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, ValueIdList{ { operand0, operand1 } }
				, name
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, false, true, OperandsCount, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, true, 0u, false, false>
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{}
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, true, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueId operand )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, list
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, true, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, true, true, OperandsCount, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, true, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands );
		}

		template< typename ... Params >
		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, Params ... params )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, makeOperands( params... ) );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, false, 0u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, ValueIdList{}
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, false, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId operand )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, list
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, false, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, ValueIdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, true, false, OperandsCount, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, false, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, operands );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, true, 0u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, ValueIdList{}
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, true, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueId operand )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, list
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, true, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, ValueIdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, false, true, OperandsCount, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, true, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 0u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make()
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{}
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, list
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, false, false, OperandsCount, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, nullopt
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 0u, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{}
				, nullopt
				, labels );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 1u, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand, std::map< int32_t, spv::Id > const & labels )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, list
				, nullopt
				, labels );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, false, false, 2u, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand0, ValueId operand1, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{ { operand0, operand1 } }
				, nullopt
				, labels );
		}

		static inline InstructionTypePtr make( ValueIdList const & operands
			, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, nullopt
				, labels );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, false, false, OperandsCount, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueIdList const & operands, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, nullopt
				, labels );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, true, 0u, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{}
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, true, 1u, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueId operand, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{ operand }
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator >
	struct InstructionTMaker< Operator, true, true, 2u, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueId operand0, ValueId operand1, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{ operand0, operand1 }
				, name
				, nullopt );
		}
	};

	template< spv::Op Operator, uint32_t OperandsCount >
	struct InstructionTMaker< Operator, true, true, OperandsCount, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueIdList const & operands, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands
				, name
				, nullopt );
		}
	};

	//*************************************************************************

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId
		, uint32_t OperandsCount
		, bool HasName
		, bool HasLabels >
	inline void assertType( Instruction const & instruction )
	{
		assertType( instruction
			, Operator
			, HasReturnTypeId
			, HasResultId
			, OperandsCount
			, HasName
			, HasLabels );
	}

	inline void assertType( Instruction const & instruction
		, Instruction::Config const & config )
	{
		assertType( instruction
			, config.op
			, config.hasReturnTypeId
			, config.hasResultId
			, config.operandsCount
			, config.hasName
			, config.hasLabels );
	}

	inline void assertType( Instruction const & instruction
		, spv::Op op
		, bool hasReturnTypeId
		, bool hasResultId
		, uint32_t operandsCount
		, bool hasName
		, bool hasLabels )
	{
		assert( spv::OpNop != op );
		assert( spv::Op( instruction.op.opData.opCount ) != 0u );
		assert( spv::Op( instruction.op.opData.opCode ) == op );
		assert( bool( instruction.returnTypeId ) == hasReturnTypeId );
		assert( bool( instruction.resultId ) == hasResultId );
		assert( operandsCount == dynamicOperandCount || uint32_t( instruction.operands.size() ) == operandsCount );
		assert( bool( instruction.packedName ) == hasName );
		assert( bool( instruction.labels ) == hasLabels );
	}

	template< spv::Op OpT >
	struct OpInstructionCheckerT
	{
		template< typename ... Params >
		static void checkParams( Params const & ... params )
		{
		}
	};

	template< typename InstructionType, typename ... Params >
	inline std::unique_ptr< InstructionType > makeInstruction( Params && ... params )
	{
		OpInstructionCheckerT< InstructionType::op >::checkParams( std::forward< Params const & >( params )... );
		return InstructionTMaker< InstructionType::op
			, InstructionType::hasReturnTypeId
			, InstructionType::hasResultId
			, InstructionType::operandsCount
			, InstructionType::hasName
			, InstructionType::hasLabels >::make( std::forward< Params >( params )... );
	}

	//*************************************************************************
}
