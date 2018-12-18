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
	inline InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >::InstructionT( std::optional< spv::Id > returnTypeId
		, std::optional< spv::Id > resultId
		, IdList operands
		, std::optional< std::string > name
		, std::optional< std::map< int32_t, spv::Id > > labels )
		: Instruction{ config, Operator, returnTypeId, resultId, operands, name, labels }
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
		: Instruction{ config, Operator, buffer, hasReturnTypeId, hasResultId, operandsCount, hasName, hasLabels }
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
	inline InstructionT< Operator, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >::InstructionT( UInt32ListCIt & buffer )
		: Instruction{ config, Operator, buffer, hasReturnTypeId, hasResultId, operandsCount, hasName, hasLabels }
	{
		assertType< Operator
			, hasReturnTypeId
			, hasResultId
			, operandsCount
			, hasName
			, hasLabels >( *this );
	}

	//*************************************************************************

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId >
	inline VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >::VariadicInstructionT( std::optional< spv::Id > returnTypeId
		, std::optional< spv::Id > resultId
		, IdList operands )
		: InstructionT{ returnTypeId, resultId, operands, std::nullopt, std::nullopt }
	{
	}

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId >
	inline VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >::VariadicInstructionT( UInt32ListIt & buffer )
		: InstructionT{ buffer, hasReturnTypeId, hasResultId, operandsCount, hasName, hasLabels }
	{
	}

	template< spv::Op Operator
		, bool HasReturnTypeId
		, bool HasResultId >
	inline VariadicInstructionT< Operator, HasReturnTypeId, HasResultId >::VariadicInstructionT( UInt32ListCIt & buffer )
		: InstructionT{ buffer, hasReturnTypeId, hasResultId, operandsCount, hasName, hasLabels }
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{}
				, name
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{ { operand } }
				, name
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{ { operand0, operand1 } }
				, name
				, std::nullopt );
		}

		static inline InstructionTypePtr make( IdList operands, std::string const & name )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, operands
				, name
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, operands
				, name
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, IdList{}
				, name
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, IdList{ { operand } }
				, name
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, IdList{ { operand0, operand1 } }
				, name
				, std::nullopt );
		}

		static inline InstructionTypePtr make( spv::Id resultId, IdList const & operands, std::string const & name )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, operands
				, name
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, operands
				, name
				, std::nullopt );
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
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, IdList{ { operand } }
				, std::nullopt
				, std::nullopt );
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
				, std::nullopt
				, std::nullopt );
		}

		static inline InstructionTypePtr make( spv::Id returnTypeId, spv::Id resultId, IdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands
				, std::nullopt
				, std::nullopt );
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
				, std::nullopt
				, std::nullopt );
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
				, std::nullopt
				, IdList{}
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( returnTypeId
				, std::nullopt
				, IdList{ { operand } }
				, std::nullopt
				, std::nullopt );
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
				, std::nullopt
				, IdList{ { operand0, operand1 } }
				, std::nullopt
				, std::nullopt );
		}

		static inline InstructionTypePtr make( spv::Id returnTypeId, IdList const & operands )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, std::nullopt
				, operands
				, std::nullopt
				, std::nullopt );
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
				, std::nullopt
				, operands
				, std::nullopt
				, std::nullopt );
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
				, std::nullopt
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, IdList{}
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, IdList{ { operand } }
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, IdList{ { operand0, operand1 } }
				, std::nullopt
				, std::nullopt );
		}

		static inline InstructionTypePtr make( spv::Id resultId, IdList const & operands )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, operands
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, resultId
				, operands
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{}
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{ { operand } }
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{ { operand0, operand1 } }
				, std::nullopt
				, std::nullopt );
		}

		static inline InstructionTypePtr make( IdList const & operands )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, operands
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, operands
				, std::nullopt
				, std::nullopt );
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
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
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{}
				, std::nullopt
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

		static inline InstructionTypePtr make( spv::Id operand
			, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{ { operand } }
				, std::nullopt
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

		static inline InstructionTypePtr make( spv::Id operand0, spv::Id operand1
			, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, IdList{ { operand0, operand1 } }
				, std::nullopt
				, labels );
		}

		static inline InstructionTypePtr make( IdList const & operands
			, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, operands
				, std::nullopt
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

		static inline InstructionTypePtr make( IdList const & operands
			, std::map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( std::nullopt
				, std::nullopt
				, operands
				, std::nullopt
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
				, std::nullopt );
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
				, std::nullopt );
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
				, std::nullopt );
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

		static inline InstructionTypePtr make( spv::Id returnTypeId
			, spv::Id resultId
			, IdList const & operands
			, std::string const & name )
		{
			return std::make_unique< InstructionType >( returnTypeId
				, resultId
				, operands
				, name
				, std::nullopt );
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
		assert( spv::Op( instruction.op.opCode ) == op );
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
