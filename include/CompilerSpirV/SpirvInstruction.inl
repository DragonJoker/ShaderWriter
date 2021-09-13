/*
See LICENSE file in root folder
*/
namespace spirv
{
	//*************************************************************************

	namespace details
	{
		template< typename ... Params >
		IdList makeOperandsRec( IdList & result, Params ... params );

		inline void makeOperandsRec( IdList & result, spv::Id param )
		{
			result.push_back( param );
		}

		inline void makeOperandsRec( IdList & result, IdList const & param )
		{
			result.insert( result.end(), param.begin(), param.end() );
		}

		template< typename ... Params >
		inline void makeOperandsRec( IdList & result, spv::Id current, Params ... params )
		{
			makeOperandsRec( result, current );
			makeOperandsRec( result, params... );
		}

		template< typename ... Params >
		inline void makeOperandsRec( IdList & result, IdList const & current, Params ... params )
		{
			makeOperandsRec( result, current );
			makeOperandsRec( result, params... );
		}
	}

	template< typename ... Params >
	inline IdList makeOperands( Params ... params )
	{
		IdList result;
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
	inline InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >::InstructionT( Optional< spv::Id > preturnTypeId
		, Optional< spv::Id > presultId
		, IdList poperands
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
	inline VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >::VariadicInstructionT( Optional< spv::Id > preturnTypeId
		, Optional< spv::Id > presultId
		, IdList poperands )
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
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id operand, std::string const & name )
		{
			IdList list;
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

		static inline InstructionTypePtr make( spv::Id operand0, spv::Id operand1, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, IdList{ { operand0, operand1 } }
				, name
				, nullopt );
		}

		static inline InstructionTypePtr make( IdList operands, std::string const & name )
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

		static inline InstructionTypePtr make( IdList operands, std::string const & name )
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

		static inline InstructionTypePtr make( spv::Id resultId, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id resultId, spv::Id operand, std::string const & name )
		{
			IdList list;
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

		static inline InstructionTypePtr make( spv::Id resultId, spv::Id operand0, spv::Id operand1, std::string const & name )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, IdList{ { operand0, operand1 } }
				, name
				, nullopt );
		}

		static inline InstructionTypePtr make( spv::Id resultId, IdList const & operands, std::string const & name )
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

		static inline InstructionTypePtr make( spv::Id resultId, IdList const & operands, std::string const & name )
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, spv::Id operand )
		{
			IdList list;
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, spv::Id operand0, spv::Id operand1 )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, IdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, IdList const & operands )
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, IdList const & operands )
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, IdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands );
		}

		template< typename ... Params >
		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, Params ... params )
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

		static inline InstructionTypePtr make( spv::Id returnTypeId )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id operand )
		{
			IdList list;
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id operand0, spv::Id operand1 )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, nullopt
				, IdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( spv::Id returnTypeId, IdList const & operands )
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, IdList const & operands )
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, IdList const & operands )
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

		static inline InstructionTypePtr make( spv::Id resultId )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id resultId, spv::Id operand )
		{
			IdList list;
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

		static inline InstructionTypePtr make( spv::Id resultId, spv::Id operand0, spv::Id operand1 )
		{
			return std::make_unique< InstructionType >( nullopt
				, resultId
				, IdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( spv::Id resultId, IdList const & operands )
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

		static inline InstructionTypePtr make( spv::Id resultId, IdList const & operands )
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

		static inline InstructionTypePtr make( spv::Id resultId, IdList const & operands )
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
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id operand )
		{
			IdList list;
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

		static inline InstructionTypePtr make( spv::Id operand0, spv::Id operand1 )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, IdList{ { operand0, operand1 } }
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( IdList const & operands )
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

		static inline InstructionTypePtr make( IdList const & operands )
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

		static inline InstructionTypePtr make( IdList const & operands )
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
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id operand, std::map< int32_t, spv::Id > const & labels )
		{
			IdList list;
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

		static inline InstructionTypePtr make( spv::Id operand0, spv::Id operand1, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nullopt
				, nullopt
				, IdList{ { operand0, operand1 } }
				, nullopt
				, labels );
		}

		static inline InstructionTypePtr make( IdList const & operands
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

		static inline InstructionTypePtr make( IdList const & operands, std::map< int32_t, spv::Id > const & labels )
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, IdList{}
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, spv::Id operand, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, IdList{ operand }
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, spv::Id operand0, spv::Id operand1, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, IdList{ operand0, operand1 }
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

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, IdList const & operands, std::string const & name )
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

	template< typename InstructionType, typename ... Params >
	inline std::unique_ptr< InstructionType > makeInstruction( Params && ... params )
	{
		return InstructionTMaker< InstructionType::op
			, InstructionType::hasReturnTypeId
			, InstructionType::hasResultId
			, InstructionType::operandsCount
			, InstructionType::hasName
			, InstructionType::hasLabels >::make( std::forward< Params >( params )... );
	}

	//*************************************************************************
}
