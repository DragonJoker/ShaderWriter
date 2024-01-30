/*
See LICENSE file in root folder
*/
#include "VulkanLayer/ShaderDataPtr.hpp"

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <iostream>
#pragma warning( pop )

namespace ast::vk
{
	//*********************************************************************************************

	namespace shddtptr
	{
		static std::ostream & operator<<( std::ostream & stream
			, DescriptorBinding const & obj )
		{
			stream << obj.set << "." << obj.binding;
			return stream;
		}

		static std::ostream & operator<<( std::ostream & stream
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
			case DescriptorType::eSampler:
				stream << "Sampler";
				break;
			case DescriptorType::eTexture:
				stream << "Texture";
				break;
			case DescriptorType::eStorageImage:
				stream << "StorageImage";
				break;

			default:
				AST_Failure( "Unexpected DescriptorType" );
				break;
			}

			return stream;
		}

		static std::ostream & operator<<( std::ostream & stream
			, ShaderDataPtr::DescriptorMap::value_type const & obj )
		{
			stream << obj.first << "(" << obj.second << ")";
			return stream;
		}

		template< typename DescT >
		static std::map< DescriptorBinding, DescT const * > mergeDescriptors( std::map< DescriptorBinding, DescT const * > const & lhs
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
// WTF ???
#pragma warning( push )
#pragma warning( disable: 5233 )
					, [&rit]( DescriptorMapVt const & lookup )
#pragma warning( pop )
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

		static ShaderDataPtr::DescriptorsMap mergeDescriptors( ShaderDataPtr::DescriptorsMap const & lhs
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
			result.resize( maxSet );
			auto lit = result.begin();
			auto rit = rhs.begin();

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
				*lit = *rit;
				++lit;
				++rit;
			}

			return result;
		}

		static ShaderDataPtr::PcbMap mergePcbs( ShaderDataPtr::PcbMap const & lhs
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
						if ( auto lit = std::find_if( result.begin()
							, result.end()
							, [&rit]( DescriptorMapVt const & lookup )
							{
								return lookup->getType() == rit->getType();
							} );
							lit == result.end() )
						{
							result.emplace_back( rit );
						}
					}
				}
			}

			return result;
		}

		template< typename ResT, typename LhsT, typename FuncT >
		static void mergeAttributes( std::map< AttributeInfo, ResT const * > & result
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
		static std::map< AttributeInfo, ResT const * > exclAttributes( std::map< AttributeInfo, LhsT const * > const & lhs
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
		static std::map< AttributeInfo, ResT const * > interAttributes( std::map< AttributeInfo, LhsT const * > const & lhs
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
		static std::map< AttributeInfo, ResT const * > unionAttributes( std::map< AttributeInfo, LhsT const * > const & lhs
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

			for ( auto & lit : lhs )
			{
				result.emplace( *lit.second, static_cast< ResT const * >( lit.second ) );
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
		static std::map< InOutInfo, ResT const * > unionAttributes( std::map< InOutInfo, LhsT const * > const & lhs
			, std::map< InOutInfo, RhsT const * > const & rhs )
		{
			std::map< InOutInfo, ResT const * > result;

			if ( lhs.empty() )
			{
				for ( auto & rit : rhs )
				{
					result.emplace( rit.first, static_cast< ResT const * >( rit.second ) );
				}

				return result;
			}

			for ( auto & lit : lhs )
			{
				result.emplace( *lit.second, static_cast< ResT const * >( lit.second ) );
			}

			return result;
		}

		template< typename DescT >
		static std::map< DescriptorBinding, DescT const * > getPtr( std::map< std::string, DescT, std::less<> > const & rhs )
		{
			std::map< DescriptorBinding, DescT const * > result;

			for ( auto & v : rhs )
			{
				result.emplace( v.second.binding, &v.second );
			}

			return result;
		}

		static ShaderDataPtr::PcbMap getPtr( ShaderData::PcbMap const & rhs )
		{
			ShaderDataPtr::PcbMap result;
			result.reserve( rhs.size() );

			for ( auto & [_, data] : rhs )
			{
				result.emplace_back( &data );
			}

			return result;
		}

		static ShaderDataPtr::InputMap getPtr( std::map< EntryPoint, ShaderData::InputMap, std::less<> > const & rhs
			, EntryPoint entryPoint )
		{
			auto it = rhs.find( entryPoint );
			ShaderDataPtr::InputMap result;

			if ( it != rhs.end() )
			{
				for ( auto & [_, data] : it->second )
				{
					result.try_emplace( data, &data );
				}
			}

			return result;
		}

		static ShaderDataPtr::OutputMap getPtr( std::map< EntryPoint, ShaderData::OutputMap, std::less<> > const & rhs
			, EntryPoint entryPoint )
		{
			auto it = rhs.find( entryPoint );
			ShaderDataPtr::OutputMap result;

			if ( it != rhs.end() )
			{
				for ( auto & [_, data] : it->second )
				{
					result.try_emplace( data, &data );
				}
			}

			return result;
		}

		static ShaderDataPtr::InOutMap getPtr( ShaderData::InOutMap const & rhs )
		{
			ShaderDataPtr::InOutMap result;

			for ( auto & [_, data] : rhs )
			{
				result.try_emplace( data, &data );
			}

			return result;
		}
	}

	//*********************************************************************************************

	ShaderDataPtr::ShaderDataPtr( ShaderData const & rhs
		, EntryPoint entryPoint
		, ShaderStageFlags stages )
		: ssbos{ shddtptr::getPtr( rhs.ssbos ) }
		, ubos{ shddtptr::getPtr( rhs.ubos ) }
		, samplers{ shddtptr::getPtr( rhs.samplers ) }
		, textures{ shddtptr::getPtr( rhs.textures ) }
		, uniformTexels{ shddtptr::getPtr( rhs.uniformTexels ) }
		, images{ shddtptr::getPtr( rhs.images ) }
		, storageTexels{ shddtptr::getPtr( rhs.storageTexels ) }
		, descriptors{ gatherDescriptors( stages ) }
		, pcbs{ shddtptr::getPtr( rhs.pcbs ) }
		, inputs{ shddtptr::getPtr( rhs.inputs, entryPoint ) }
		, outputs{ shddtptr::getPtr( rhs.outputs, entryPoint ) }
		, inOuts{ shddtptr::getPtr( rhs.inOuts ) }
		, accelerationStruct{ &rhs.accelerationStruct }
		, tessellationControlPoints{ rhs.tessellationControlPoints }
	{
	}

	void ShaderDataPtr::merge( ShaderDataPtr const & rhs )
	{
		images = shddtptr::mergeDescriptors( images, rhs.images );
		textures = shddtptr::mergeDescriptors( textures, rhs.textures );
		samplers = shddtptr::mergeDescriptors( samplers, rhs.samplers );
		storageTexels = shddtptr::mergeDescriptors( storageTexels, rhs.storageTexels );
		uniformTexels = shddtptr::mergeDescriptors( uniformTexels, rhs.uniformTexels );
		ssbos = shddtptr::mergeDescriptors( ssbos, rhs.ssbos );
		ubos = shddtptr::mergeDescriptors( ubos, rhs.ubos );
		descriptors = shddtptr::mergeDescriptors( descriptors, rhs.descriptors );

		pcbs = shddtptr::mergePcbs( pcbs, rhs.pcbs );

		auto rhsInputs = rhs.inputs;
		// Retrieve intersection of current outputs and rhs inputs
		auto intersection = shddtptr::interAttributes< AttributeInfo >( outputs, rhsInputs );
		// Remove this intersection from current outputs.
		outputs = shddtptr::exclAttributes< OutputInfo >( outputs, intersection );
		// Remove it from rhs inputs too.
		rhsInputs = shddtptr::exclAttributes< InputInfo >( rhsInputs, intersection );
		// Add remaining rhsInputs to current inputs.
		inputs = shddtptr::unionAttributes< InputInfo >( inputs, rhsInputs );
		// Add the rhs outputs to remaining current outputs.
		outputs = shddtptr::unionAttributes< OutputInfo >( outputs, rhs.outputs );

		specConstants = shddtptr::unionAttributes< SpecConstantInfo >( specConstants, rhs.specConstants );
		inOuts = shddtptr::unionAttributes< InOutInfo >( inOuts, rhs.inOuts );

		if ( rhs.accelerationStruct && !accelerationStruct )
		{
			accelerationStruct = rhs.accelerationStruct;
		}

		if ( rhs.tessellationControlPoints && !tessellationControlPoints )
		{
			tessellationControlPoints = rhs.tessellationControlPoints;
		}
	}

	ShaderDataPtr::DescriptorsMap ShaderDataPtr::gatherDescriptors( ShaderStageFlags stages )const
	{
		DescriptorsMap result;
		DescriptorMap all;

		for ( auto & [binding, data] : ssbos )
		{
			auto arraySize = getArraySize( data->type );
			all.emplace( binding
				, DescriptorData{ DescriptorType::eStorageBuffer
					, ( arraySize != type::NotArray ? arraySize : 1u )
					, stages } );
		}

		for ( auto & [binding, data] : ubos )
		{
			auto arraySize = getArraySize( data->type );
			all.emplace( binding
				, DescriptorData{ DescriptorType::eUniformBuffer
					, ( arraySize != type::NotArray ? arraySize : 1u )
					, stages } );
		}

		for ( auto & [binding, data] : samplers )
		{
			auto arraySize = getArraySize( data->type );
			all.emplace( binding
				, DescriptorData{ DescriptorType::eSampler
					, ( arraySize != type::NotArray ? arraySize : 1u )
					, stages } );
		}

		for ( auto & [binding, data] : textures )
		{
			auto arraySize = getArraySize( data->type );
			all.emplace( binding
				, DescriptorData{ DescriptorType::eTexture
					, ( arraySize != type::NotArray ? arraySize : 1u )
					, stages } );
		}

		for ( auto & [binding, data] : uniformTexels )
		{
			auto arraySize = getArraySize( data->type );
			all.emplace( binding
				, DescriptorData{ DescriptorType::eUniformTexelBuffer
					, ( arraySize != type::NotArray ? arraySize : 1u )
					, stages } );
		}

		for ( auto & [binding, data] : images )
		{
			auto arraySize = getArraySize( data->type );
			all.emplace( binding
				, DescriptorData{ DescriptorType::eStorageImage
					, ( arraySize != type::NotArray ? arraySize : 1u )
					, stages } );
		}

		for ( auto & [binding, data] : storageTexels )
		{
			auto arraySize = getArraySize( data->type );
			all.emplace( binding
				, DescriptorData{ DescriptorType::eStorageTexelBuffer
					, ( arraySize != type::NotArray ? arraySize : 1u )
					, stages } );
		}

		if ( !all.empty() )
		{
			auto maxSet = all.rbegin()->first.set + 1u;
			result.resize( maxSet );

			for ( uint32_t setIndex = 0u; setIndex < maxSet; ++setIndex )
			{
				for ( auto & [binding, data] : all )
				{
					if ( binding.set == setIndex )
					{
						result[setIndex].emplace( binding, data );
					}
				}
			}
		}

		return result;
	}

	//*********************************************************************************************
}
