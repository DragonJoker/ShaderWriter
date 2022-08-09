/*
See LICENSE file in root folder
*/
namespace spirv
{
	//*************************************************************************

	namespace details
	{
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

	template< typename IterT >
	InstructionPtr BufferItT< IterT >::popInstruction()
	{
		return spirv::Instruction::deserialize( *this );
	}

	//*************************************************************************

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::InstructionT( Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList poperands
		, Optional< std::string > pname
		, Optional< std::map< int32_t, spv::Id > > plabels )
		: Instruction{ Config, OperatorT, preturnTypeId, presultId, poperands, std::move( pname ), plabels }
	{
		assertType< Op
			, HasReturnTypeId
			, HasResultId
			, OperandsCount
			, HasName
			, HasLabels >( *this );
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::InstructionT( BufferIt & buffer )
		: Instruction{ Config, OperatorT, buffer }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::InstructionT( BufferCIt & buffer )
		: Instruction{ Config, OperatorT, buffer }
	{
	}

	//*************************************************************************

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	inline VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >::VariadicInstructionT( Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList poperands )
		: InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false >{ preturnTypeId, presultId, poperands, nullopt, nullopt }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	inline VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >::VariadicInstructionT( BufferIt & buffer )
		: InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false >{ buffer, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	inline VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >::VariadicInstructionT( BufferCIt & buffer )
		: InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false >{ buffer, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false }
	{
	}

	//*************************************************************************

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 0u, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{}
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 1u, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand, std::string name )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, list
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 2u, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId operand0, ValueId operand1, std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, ValueIdList{ { operand0, operand1 } }
				, std::move( name )
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueIdList operands, std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, false, false, OperandsCountT, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueIdList operands, std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, true, 0u, true, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, ValueIdList{}
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, true, 1u, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueId operand, std::string name )
		{
			ValueIdList list;
			list.push_back( operand );
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, list
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, true, 2u, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueId operand0, ValueId operand1, std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, ValueIdList{ { operand0, operand1 } }
				, std::move( name )
				, nullopt );
		}

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands, std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, false, true, OperandsCountT, true, false>
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands, std::string name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, true, 0u, false, false>
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, true, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, true, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, true, true, OperandsCountT, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, true, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< OperatorT, HasReturnTypeId, HasResultId >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, false, 0u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, false, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, false, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, true, false, OperandsCountT, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, false, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< OperatorT, HasReturnTypeId, HasResultId >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, operands );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, true, 0u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, true, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, true, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, false, true, OperandsCountT, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, true, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< OperatorT, HasReturnTypeId, HasResultId >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, operands );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 0u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 1u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 2u, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, false, false, OperandsCountT, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, dynamicOperandCount, false, false >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = false;
		using InstructionType = VariadicInstructionT< OperatorT, HasReturnTypeId, HasResultId >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, operands );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 0u, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 1u, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, false, false, 2u, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
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

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, false, false, OperandsCountT, false, true >
	{
		static bool constexpr HasReturnTypeId = false;
		static bool constexpr HasResultId = false;
		static bool constexpr HasName = false;
		static bool constexpr HasLabels = true;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
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

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, true, 0u, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 0u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, std::string name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{}
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, true, 1u, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueId operand, std::string name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{ operand }
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, true, 2u, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static uint32_t constexpr OperandsCount = 2u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueId operand0, ValueId operand1, std::string name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, ValueIdList{ operand0, operand1 }
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT, uint32_t OperandsCountT >
	struct InstructionTMaker< OperatorT, true, true, OperandsCountT, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = true;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCountT, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( ValueId returnTypeId, ValueId resultId, ValueIdList const & operands, std::string name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands
				, std::move( name )
				, nullopt );
		}
	};

	//*************************************************************************

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline void assertType( Instruction const & instruction )
	{
		assertType( instruction
			, OperatorT
			, HasReturnTypeIdT
			, HasResultIdT
			, OperandsCountT
			, HasNameT
			, HasLabelsT );
	}

	inline void assertType( Instruction const & instruction
		, Instruction::Configuration const & config )
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

	template< spv::Op OperatorT >
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
		OpInstructionCheckerT< InstructionType::Op >::checkParams( std::forward< Params const & >( params )... );
		return InstructionTMaker< InstructionType::Op
			, InstructionType::HasReturnTypeId
			, InstructionType::HasResultId
			, InstructionType::OperandsCount
			, InstructionType::HasName
			, InstructionType::HasLabels >::make( std::forward< Params >( params )... );
	}

	//*************************************************************************
}
