/*
See LICENSE file in root folder
*/
namespace spirv
{
	//*************************************************************************

	namespace details
	{
		template< typename Param, typename ... Params >
		inline void makeOperandsRec( ValueIdList & result, Param current, Params ... params );

		inline void makeOperandsRec( ValueIdList & result, ValueId param )
		{
			result.push_back( param );
		}

		inline void makeOperandsRec( ValueIdList & result, DebugId param )
		{
			result.push_back( param.id );
		}

		inline void makeOperandsRec( ValueIdList & result, uint16_t param )
		{
			result.push_back( ValueId{ spv::Id{ param } } );
		}

		inline void makeOperandsRec( ValueIdList & result, uint32_t param )
		{
			result.push_back( ValueId{ spv::Id{ param } } );
		}

		inline void makeOperandsRec( ValueIdList & result, ValueIdList const & param )
		{
			result.insert( result.end(), param.begin(), param.end() );
		}

		inline void makeOperandsRec( ValueIdList & result, IdList const & param )
		{
			makeOperandsRec( result, convert( param ) );
		}

		inline void makeOperandsRec( ValueIdList & result, DebugIdList const & param )
		{
			makeOperandsRec( result, convert( param ) );
		}

		template< typename Param, typename ... Params >
		inline void makeOperandsRec( ValueIdList & result, Param current, Params ... params )
		{
			makeOperandsRec( result, current );
			makeOperandsRec( result, params... );
		}

		template< typename Param, typename ... Params >
		inline void makeIdListRec( IdList & result, Param current, Params ... params );

		inline void makeIdListRec( IdList & result, ValueId param )
		{
			result.push_back( param.id );
		}

		inline void makeIdListRec( IdList & result, DebugId param )
		{
			result.push_back( param->id );
		}

		inline void makeIdListRec( IdList & result, uint16_t param )
		{
			result.push_back( spv::Id{ param } );
		}

		inline void makeIdListRec( IdList & result, uint32_t param )
		{
			result.push_back( spv::Id{ param } );
		}

		inline void makeIdListRec( IdList & result, IdList const & param )
		{
			result.insert( result.end(), param.begin(), param.end() );
		}

		inline void makeIdListRec( IdList & result, ValueIdList const & param )
		{
			makeIdListRec( result, convert( param ) );
		}

		inline void makeIdListRec( IdList & result, DebugIdList const & param )
		{
			makeIdListRec( result, convert( param ) );
		}

		template< typename Param, typename ... Params >
		inline void makeIdListRec( IdList & result, Param current, Params ... params )
		{
			makeIdListRec( result, current );
			makeIdListRec( result, params... );
		}
	}

	template< typename ... Params >
	inline ValueIdList makeOperands( ast::ShaderAllocatorBlock * alloc
		, Params ... params )
	{
		ValueIdList result{ alloc };
		details::makeOperandsRec( result, params... );
		return result;
	}

	template< typename ... Params >
	inline IdList makeIdList( ast::ShaderAllocatorBlock * alloc
		, Params ... params )
	{
		IdList result{ alloc };
		details::makeIdListRec( result, params... );
		return result;
	}

	//*************************************************************************

	template< typename IterT >
	InstructionPtr BufferItT< IterT >::popInstruction( ast::ShaderAllocatorBlock * alloc )
	{
		return spirv::Instruction::deserialize( alloc, *this );
	}

	//*************************************************************************

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::InstructionT( NamesCache & nameCache
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList poperands
		, Optional< std::string > pname
		, Optional< ast::Map< int32_t, spv::Id > > plabels )
		: Instruction{ nameCache, Config, OperatorT, preturnTypeId, presultId, poperands, std::move( pname ), plabels }
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
	inline InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::InstructionT( NamesCache & nameCache
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId )
		: InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >{ nameCache, Config, OperatorT, preturnTypeId, presultId, ValueIdList{ nameCache.get_allocator() } }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::InstructionT( ast::ShaderAllocatorBlock * alloc
		, BufferIt & buffer )
		: Instruction{ alloc, Config, OperatorT, buffer }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT
		, uint32_t OperandsCountT
		, bool HasNameT
		, bool HasLabelsT >
	inline InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, OperandsCountT, HasNameT, HasLabelsT >::InstructionT( ast::ShaderAllocatorBlock * alloc
		, BufferCIt & buffer )
		: Instruction{ alloc, Config, OperatorT, buffer }
	{
	}

	//*************************************************************************

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	inline VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >::VariadicInstructionT( NamesCache & nameCache
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId
		, ValueIdList poperands )
		: InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false >{ nameCache, preturnTypeId, presultId, poperands, nullopt, nullopt }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	inline VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >::VariadicInstructionT( NamesCache & nameCache
		, Optional< ValueId > preturnTypeId
		, Optional< ValueId > presultId )
		: VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >{ nameCache, preturnTypeId, presultId, ValueIdList{ nameCache.get_allocator() } }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	inline VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >::VariadicInstructionT( ast::ShaderAllocatorBlock * alloc
		, BufferIt & buffer )
		: InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false >{ alloc, buffer, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false }
	{
	}

	template< spv::Op OperatorT
		, bool HasReturnTypeIdT
		, bool HasResultIdT >
	inline VariadicInstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT >::VariadicInstructionT( ast::ShaderAllocatorBlock * alloc
		, BufferCIt & buffer )
		: InstructionT< OperatorT, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false >{ alloc, buffer, HasReturnTypeIdT, HasResultIdT, dynamicOperandCount, false, false }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, nullopt
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId operand
			, std::string name )
		{
			ValueIdList list{ nameCache.get_allocator() };
			list.push_back( operand );
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId operand0
			, ValueId operand1
			, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, nullopt
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
				, std::move( name )
				, nullopt );
		}

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueIdList operands, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueIdList operands, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, resultId
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueId operand, std::string name )
		{
			ValueIdList list{ nameCache.get_allocator() };
			list.push_back( operand );
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueId operand0, ValueId operand1, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, resultId
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
				, std::move( name )
				, nullopt );
		}

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueIdList const & operands, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueIdList const & operands, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, resultId
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueId operand )
		{
			ValueIdList list{ nameCache.get_allocator() };
			list.push_back( operand );
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, resultId
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, resultId
				, operands );
		}

		template< typename ... Params >
		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, Params ... params )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, resultId
				, makeOperands( nameCache.get_allocator().getAllocator(), params... ) );
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, nullopt
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId operand )
		{
			ValueIdList list{ nameCache.get_allocator() };
			list.push_back( operand );
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, nullopt
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, resultId
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueId operand )
		{
			ValueIdList list{ nameCache.get_allocator() };
			list.push_back( operand );
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, resultId
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId resultId, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, nullopt
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId operand )
		{
			ValueIdList list{ nameCache.get_allocator() };
			list.push_back( operand );
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId operand0, ValueId operand1 )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, nullopt
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
				, nullopt
				, nullopt );
		}

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueIdList const & operands )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ast::Map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, nullopt
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId operand, ast::Map< int32_t, spv::Id > const & labels )
		{
			ValueIdList list{ nameCache.get_allocator() };
			list.push_back( operand );
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId operand0, ValueId operand1, ast::Map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
				, nullopt
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
				, nullopt
				, labels );
		}

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueIdList const & operands
			, ast::Map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueIdList const & operands
			, ast::Map< int32_t, spv::Id > const & labels )
		{
			return std::make_unique< InstructionType >( nameCache
				, nullopt
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, resultId
				, ValueIdList{ nameCache.get_allocator() }
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueId operand, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, resultId
				, makeOperands( nameCache.get_allocator().getAllocator(), operand )
				, std::move( name )
				, nullopt );
		}
	};

	template< spv::Op OperatorT >
	struct InstructionTMaker< OperatorT, true, false, 1u, true, false >
	{
		static bool constexpr HasReturnTypeId = true;
		static bool constexpr HasResultId = false;
		static uint32_t constexpr OperandsCount = 1u;
		static bool constexpr HasName = true;
		static bool constexpr HasLabels = false;
		using InstructionType = InstructionT< OperatorT, HasReturnTypeId, HasResultId, OperandsCount, HasName, HasLabels >;
		using InstructionTypePtr = std::unique_ptr< InstructionType >;

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId operand, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, nullopt
				, makeOperands( nameCache.get_allocator().getAllocator(), operand )
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueId operand0, ValueId operand1, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
				, resultId
				, makeOperands( nameCache.get_allocator().getAllocator(), operand0, operand1 )
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

		static inline InstructionTypePtr make( NamesCache & nameCache
			, ValueId returnTypeId, ValueId resultId, ValueIdList const & operands, std::string name )
		{
			return std::make_unique< InstructionType >( nameCache
				, returnTypeId
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
		assert( spv::Op( instruction.op.getOpData().opCount ) != 0u );
		assert( spv::Op( instruction.op.getOpData().opCode ) == op );
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
		static void checkParams( Params const & ... )
		{
		}
	};

	template< typename InstructionType, typename ... Params >
	inline std::unique_ptr< InstructionType > makeInstruction( NamesCache & nameCache
		, Params && ... params )
	{
		OpInstructionCheckerT< InstructionType::Op >::checkParams( std::forward< Params const & >( params )... );
		return InstructionTMaker< InstructionType::Op
			, InstructionType::HasReturnTypeId
			, InstructionType::HasResultId
			, InstructionType::OperandsCount
			, InstructionType::HasName
			, InstructionType::HasLabels >::make( nameCache, std::forward< Params >( params )... );
	}

	//*************************************************************************
}
