/*
See LICENSE file in root folder
*/
#include "VulkanLayer/ShaderDataPtr.hpp"

#include <iostream>

namespace ast::vk
{
	//*********************************************************************************************

	namespace
	{
		std::ostream & operator<<( std::ostream & stream
			, DescriptorBinding const & obj )
		{
			stream << obj.set << "." << obj.binding;
			return stream;
		}

		std::ostream & operator<<( std::ostream & stream
			, ShaderDataPtr::DescriptorData const & obj )
		{
			switch ( obj.type )
			{
			case DescriptorType::eUniformBuffer:
				stream << "UniformBuffer";
				break;
			case DescriptorType::eStorageBuffer:
				stream << "StorageBuffer";
				break;
			case DescriptorType::eCombinedSamplerImage:
				stream << "CombinedSamplerImage";
				break;
			case DescriptorType::eStorageImage:
				stream << "StorageImage";
				break;

			default:
				assert( false && "Unexpected DescriptorType" );
				break;
			}

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream
			, ShaderDataPtr::DescriptorMap::value_type const & obj )
		{
			stream << obj.first << "(" << obj.second << ")";
			return stream;
		}

		template< typename DescT >
		std::map< DescriptorBinding, DescT const * > mergeDescriptors( std::map< DescriptorBinding, DescT const * > const & lhs
			, std::map< DescriptorBinding, DescT const * > const & rhs )
		{
			if ( rhs.empty() )
			{
				return lhs;
			}

			if ( lhs.empty() )
			{
				return rhs;
			}

			using DescriptorMapT = std::map< DescriptorBinding, DescT const * >;
			using DescriptorMapVt = typename DescriptorMapT::value_type;
			DescriptorMapT result{ lhs };

			for ( auto & rit : rhs )
			{
				auto lit = std::find_if( result.begin()
					, result.end()
					, [&rit]( DescriptorMapVt const & lookup )
					{
						return lookup.second->binding == rit.second->binding;
					} );

				if ( lit == result.end() )
				{
					result.emplace( rit);
				}
			}

			return result;
		}

		ShaderDataPtr::DescriptorsMap mergeDescriptors( ShaderDataPtr::DescriptorsMap const & lhs
			, ShaderDataPtr::DescriptorsMap const & rhs )
		{
			if ( rhs.empty() )
			{
				return lhs;
			}

			if ( lhs.empty() )
			{
				return rhs;
			}

			ShaderDataPtr::DescriptorsMap result{ lhs };

			auto minSet = std::min( result.size(), rhs.size() );
			auto maxSet = std::max( result.size(), rhs.size() );
			auto lit = result.begin();
			auto rit = rhs.begin();
			result.resize( maxSet );

			for ( uint32_t i = 0u; i < minSet; ++i )
			{
				for ( auto rdesc : *rit )
				{
					auto ldesc = lit->find( rdesc.first );

					if ( lit->end() == ldesc )
					{
						lit->emplace( rdesc );
					}
					else if ( rdesc.second.type != ldesc->second.type )
					{
						std::cerr << "Descriptor type mismatch for descriptors "
							<< ( *ldesc ) << " and " << rdesc << std::endl;
					}
					else
					{
						ldesc->second.stages |= rdesc.second.stages;
					}
				}

				++lit;
				++rit;
			}

			for ( size_t i = lhs.size(); i < rhs.size(); ++i )
			{
				result.push_back( *rit );
				++rit;
			}

			return result;
		}

		ShaderDataPtr::PcbMap mergePcbs( ShaderDataPtr::PcbMap const & lhs
			, ShaderDataPtr::PcbMap const & rhs )
		{
			using DescriptorMapT = ShaderDataPtr::PcbMap;
			using DescriptorMapVt = typename DescriptorMapT::value_type;
			DescriptorMapT result{ lhs };

			if ( !rhs.empty() )
			{
				if ( result.empty() )
				{
					for ( auto & rit : rhs )
					{
						result.emplace_back( rit );
					}
				}
				else
				{
					for ( auto & rit : rhs )
					{
						auto lit = std::find_if( result.begin()
							, result.end()
							, [&rit]( DescriptorMapVt const & lookup )
							{
								return lookup->getType() == rit->getType();
							} );

						if ( lit == result.end() )
						{
							result.emplace_back( rit );
						}
					}
				}
			}

			return result;
		}

		template< typename ResT, typename LhsT, typename FuncT >
		void mergeAttributes( std::map< AttributeInfo, ResT const * > & result
			, std::map< AttributeInfo, LhsT const * > const & lhs
			, FuncT func )
		{
			for ( auto & lit : lhs )
			{
				if ( func( lit ) )
				{
					result.emplace( *lit.second, static_cast< ResT const * >( lit.second ) );
				}
			}
		}

		template< typename ResT, typename LhsT, typename RhsT >
		std::map< AttributeInfo, ResT const * > exclAttributes( std::map< AttributeInfo, LhsT const * > const & lhs
			, std::map< AttributeInfo, RhsT const * > const & rhs )
		{
			using LhsMapT = std::map< AttributeInfo, LhsT const * >;
			using LhsMapVt = typename LhsMapT::value_type;
			using RhsMapT = std::map< AttributeInfo, RhsT const * >;
			using RhsMapVt = typename RhsMapT::value_type;
			std::map< AttributeInfo, ResT const * > result;

			if ( lhs.empty() )
			{
				for ( auto & rit : rhs )
				{
					result.emplace( rit.first, static_cast< ResT const * >( rit.second ) );
				}

				return result;
			}

			mergeAttributes( result
				, lhs
				, [&rhs]( LhsMapVt const & itLhs )
				{
					return rhs.end() == std::find_if( rhs.begin()
						, rhs.end()
						, [&itLhs]( RhsMapVt const & itRhs )
						{
							return itRhs.second->location == itLhs.second->location;
						} );
				} );
			return result;
		}

		template< typename ResT, typename LhsT, typename RhsT >
		std::map< AttributeInfo, ResT const * > interAttributes( std::map< AttributeInfo, LhsT const * > const & lhs
			, std::map< AttributeInfo, RhsT const * > const & rhs )
		{
			using LhsMapT = std::map< AttributeInfo, LhsT const * >;
			using LhsMapVt = typename LhsMapT::value_type;
			using RhsMapT = std::map< AttributeInfo, RhsT const * >;
			using RhsMapVt = typename RhsMapT::value_type;
			std::map< AttributeInfo, ResT const * > result;
			mergeAttributes( result
				, lhs
				, [&rhs]( LhsMapVt const & itLhs )
				{
					return rhs.end() != std::find_if( rhs.begin()
						, rhs.end()
						, [&itLhs]( RhsMapVt const & itRhs )
						{
							return itRhs.second->location == itLhs.second->location;
						} );
				} );
			return result;
		}

		template< typename ResT, typename LhsT, typename RhsT >
		std::map< AttributeInfo, ResT const * > unionAttributes( std::map< AttributeInfo, LhsT const * > const & lhs
			, std::map< AttributeInfo, RhsT const * > const & rhs )
		{
			using LhsMapT = std::map< AttributeInfo, LhsT const * >;
			using LhsMapVt = typename LhsMapT::value_type;
			using RhsMapT = std::map< AttributeInfo, RhsT const * >;
			using RhsMapVt = typename RhsMapT::value_type;
			std::map< AttributeInfo, ResT const * > result;

			if ( lhs.empty() )
			{
				for ( auto & rit : rhs )
				{
					result.emplace( rit.first, static_cast< ResT const * >( rit.second ) );
				}

				return result;
			}

			mergeAttributes( result
				, lhs
				, [&rhs]( LhsMapVt const & itLhs )
				{
					return rhs.end() == std::find_if( rhs.begin()
						, rhs.end()
						, [&itLhs]( RhsMapVt const & itRhs )
						{
							return itRhs.second->location == itLhs.second->location;
						} );
				} );
			return result;
		}

		template< typename DescT >
		static std::map< DescriptorBinding, DescT const * > getPtr( std::map< std::string, DescT > const & rhs )
		{
			std::map< DescriptorBinding, DescT const * > result;

			for ( auto & v : rhs )
			{
				result.emplace( v.second.binding, &v.second );
			}

			return result;
		}

		static inline ShaderDataPtr::PcbMap getPtr( ShaderData::PcbMap const & rhs )
		{
			ShaderDataPtr::PcbMap result;
			result.reserve( rhs.size() );

			for ( auto & v : rhs )
			{
				result.emplace_back( &v.second );
			}

			return result;
		}

		static inline ShaderDataPtr::InputMap getPtr( ShaderData::InputMap const & rhs )
		{
			ShaderDataPtr::InputMap result;

			for ( auto & v : rhs )
			{
				result.emplace( v.second, &v.second );
			}

			return result;
		}

		static inline ShaderDataPtr::OutputMap getPtr( ShaderData::OutputMap const & rhs )
		{
			ShaderDataPtr::OutputMap result;

			for ( auto & v : rhs )
			{
				result.emplace( v.second, &v.second );
			}

			return result;
		}
	}

	//*********************************************************************************************

	ShaderDataPtr::ShaderDataPtr( ShaderData const & rhs
		, ShaderStageFlags stages )
		: ssbos{ getPtr( rhs.ssbos ) }
		, ubos{ getPtr( rhs.ubos ) }
		, samplers{ getPtr( rhs.samplers ) }
		, images{ getPtr( rhs.images ) }
		, descriptors{ gatherDescriptors( stages ) }
		, pcbs{ getPtr( rhs.pcbs ) }
		, inputs{ getPtr( rhs.inputs ) }
		, outputs{ getPtr( rhs.outputs ) }
	{
	}

	void ShaderDataPtr::merge( ShaderDataPtr const & rhs )
	{
		images = mergeDescriptors( images, rhs.images );
		samplers = mergeDescriptors( samplers, rhs.samplers );
		ssbos = mergeDescriptors( ssbos, rhs.ssbos );
		ubos = mergeDescriptors( ubos, rhs.ubos );
		descriptors = mergeDescriptors( descriptors, rhs.descriptors );

		pcbs = mergePcbs( pcbs, rhs.pcbs );

		auto rhsInputs = rhs.inputs;
		// Retrieve intersection of current outputs and rhs inputs
		auto intersection = interAttributes< AttributeInfo >( outputs, rhsInputs );
		// Remove this intersection from current outputs.
		outputs = exclAttributes< OutputInfo >( outputs, intersection );
		// Remove it from rhs inputs too.
		rhsInputs = exclAttributes< InputInfo >( rhsInputs, intersection );
		// Add remaining rhsInputs to current inputs.
		inputs = unionAttributes< InputInfo >( inputs, rhsInputs );
		// Add the rhs outputs to remaining current outputs.
		outputs = unionAttributes< OutputInfo >( outputs, rhs.outputs );

		specConstants = unionAttributes< SpecConstantInfo >( specConstants, rhs.specConstants );
	}

	ShaderDataPtr::DescriptorsMap ShaderDataPtr::gatherDescriptors( ShaderStageFlags stages )
	{
		DescriptorsMap result;
		DescriptorMap all;

		for ( auto & desc : ssbos )
		{
			all.emplace( desc.first, DescriptorData{ DescriptorType::eStorageBuffer, stages } );
		}

		for ( auto & desc : ubos )
		{
			all.emplace( desc.first, DescriptorData{ DescriptorType::eUniformBuffer, stages } );
		}

		for ( auto & desc : samplers )
		{
			all.emplace( desc.first, DescriptorData{ DescriptorType::eCombinedSamplerImage, stages } );
		}

		for ( auto & desc : images )
		{
			all.emplace( desc.first, DescriptorData{ DescriptorType::eStorageImage, stages } );
		}

		if ( !all.empty() )
		{
			auto maxSet = all.rbegin()->first.set + 1u;
			result.resize( maxSet );

			for ( uint32_t setIndex = 0u; setIndex < maxSet; ++setIndex )
			{
				for ( auto & set : all )
				{
					if ( set.first.set == setIndex )
					{
						result[setIndex].emplace( set.first, set.second );
					}
				}
			}
		}

		return result;
	}

	//*********************************************************************************************
}
