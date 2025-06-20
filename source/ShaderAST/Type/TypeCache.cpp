/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeCache.hpp"

#include "ShaderAST/Shader.hpp"
#include "ShaderAST/Type/TypeImage.hpp"
#include "ShaderAST/Type/TypeCombinedImage.hpp"
#include "ShaderAST/Type/TypeSampler.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::type
{
	//*************************************************************************

	TypesCache::TypesCache()
		: m_accelerationStructure{ std::make_unique< AccelerationStructure >( *this ) }
		, m_basic{ [this]( ast::type::Kind kind, bool explicitLayout )
			{
				return std::make_unique< Type >( *this, kind, explicitLayout );
			}
			, []( ast::type::Kind kind, bool explicitLayout )noexcept
			{
				return ast::type::getHash( kind, explicitLayout );
			} }
		, m_member{ [this]( TypePtr type, StructPtr parent, uint32_t mbrIndex )
			{
				return std::make_unique< Type >( *this, parent, mbrIndex, *type );
			}
			, []( TypePtr type, StructPtr parent, uint32_t mbrIndex )noexcept
			{
				return ast::type::getHash( type, parent, mbrIndex );
			} }
		, m_image{ [this]( ImageConfiguration config )
			{
				return std::make_unique< Image >( *this, std::move( config ) );
			}
			, []( ImageConfiguration const & config )noexcept
			{
				return ast::type::getHash( config );
			} }
		, m_texture{ [this]( ImageConfiguration config, bool isComparison )
			{
				return std::make_unique< CombinedImage >( *this, std::move( config ), isComparison );
			}
			, []( ImageConfiguration const & config, bool isComparison )noexcept
			{
				return ast::type::getHash( config, isComparison );
			} }
		, m_sampledImage{ [this]( ImageConfiguration config, Trinary comparison )
			{
				return std::make_unique< SampledImage >( *this, std::move( config ), comparison );
			}
			, []( ImageConfiguration const & config, Trinary )noexcept
			{
				return ast::type::getHash( config );
			} }
		, m_sampler{ [this]( bool comparison )
			{
				return std::make_unique< Sampler >( *this, comparison );
			}
			, []( bool comparison )noexcept
			{
				return comparison ? 1u : 0u;
			} }
		, m_function{ []( TypePtr returnType
				, var::VariableList parameters )
			{
				return std::make_unique< Function >( returnType
					, std::move( parameters ) );
			}
			, []( TypePtr returnType
				, var::VariableList const & parameters )noexcept
			{
				return ast::type::getHash( returnType, parameters );
			} }
		, m_struct{ [this]( MemoryLayout layout
				, std::string name
				, bool explicitLayout )
			{
				return std::make_unique< BaseStruct >( *this
					, layout
					, std::move( name )
					, explicitLayout );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( layout, name, explicitLayout );
			} }
		, m_inputStruct{ [this]( MemoryLayout layout
				, std::string name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )
			{
				return std::make_unique< IOStruct >( *this
					, layout
					, std::move( name )
					, entryPoint
					, flag
					, explicitLayout );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( layout, name, entryPoint, flag, explicitLayout );
			} }
		, m_outputStruct{ [this]( MemoryLayout layout
				, std::string name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )
			{
				return std::make_unique< IOStruct >( *this
					, layout
					, std::move( name )
					, entryPoint
					, flag
					, explicitLayout );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, EntryPoint entryPoint
				, var::Flag flag
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( layout, name, entryPoint, flag, explicitLayout );
			} }
		, m_array{ []( TypePtr type
				, uint32_t arraySize
				, bool explicitLayout )
			{
				return std::make_unique< Array >( std::move( type )
					, arraySize
					, explicitLayout );
			}
			, []( TypePtr type
				, uint32_t arraySize
				, bool explicitLayout )noexcept
			{
				return ast::type::getHash( type, arraySize, explicitLayout );
			} }
		, m_pointer{ []( TypePtr pointerType
				, Storage storage
				, bool isForward )
			{
				return std::make_unique< Pointer >( std::move( pointerType )
					, storage
					, isForward );
			}
			, []( TypePtr pointerType
				, Storage storage
				, bool isForward )noexcept
			{
				return ast::type::getHash( pointerType, storage, isForward );
			} }
		, m_rayPayload{ []( TypePtr type
				, uint32_t location )
			{
				return std::make_unique< RayPayload >( std::move( type )
					, location );
			}
			, []( TypePtr type
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location, false );
			} }
		, m_callableData{ []( TypePtr type
				, uint32_t location )
			{
				return std::make_unique< CallableData >( std::move( type )
					, location );
			}
			, []( TypePtr type
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location, false );
			} }
		, m_hitAttribute{ []( TypePtr type )
			{
				return std::make_unique< HitAttribute >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_meshVertexOutput{ []( TypePtr type
			, uint32_t maxVertices )
			{
				return std::make_unique< MeshVertexOutput >( type, maxVertices );
			}
			, []( TypePtr type
				, uint32_t maxVertices )noexcept
			{
				return getHash( type, maxVertices, false );
			} }
		, m_meshPrimitiveOutput{ []( TypePtr type
			, OutputTopology topology
			, uint32_t maxPrimitives )
			{
				return std::make_unique< MeshPrimitiveOutput >( type, topology, maxPrimitives );
			}
			, []( TypePtr type
				, OutputTopology topology
				, uint32_t maxPrimitives )noexcept
			{
				return getHash( type, topology, maxPrimitives );
			} }
		, m_taskPayloadNV{ []( TypePtr type )
			{
				return std::make_unique< TaskPayloadNV >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_taskPayloadInNV{ []( TypePtr type )
			{
				return std::make_unique< TaskPayloadInNV >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_taskPayload{ []( TypePtr type )
			{
				return std::make_unique< TaskPayload >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_taskPayloadIn{ []( TypePtr type )
			{
				return std::make_unique< TaskPayloadIn >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_compute{ []( TypePtr type, uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ )
			{
				return std::make_unique< ComputeInput >( type, localSizeX, localSizeY, localSizeZ );
			}
			, []( TypePtr type, uint32_t localSizeX, uint32_t localSizeY, uint32_t localSizeZ )noexcept
			{
				return getHash( type, localSizeX, localSizeY, localSizeZ );
			} }
		, m_fragment{ []( TypePtr type, FragmentOrigin origin, FragmentCenter center, InvocationOrdering ordering )
			{
				return std::make_unique< FragmentInput >( type, origin, center, ordering );
			}
			, []( TypePtr type, FragmentOrigin origin, FragmentCenter center, InvocationOrdering ordering )noexcept
			{
				return getHash( type, origin, center, ordering );
			} }
		, m_geometryInput{ []( TypePtr type, InputLayout layout )
			{
				return std::make_unique< GeometryInput >( type, layout );
			}
			, []( TypePtr type, InputLayout layout )noexcept
			{
				return getHash( type, layout );
			} }
		, m_geometryOutput{ []( TypePtr type, OutputLayout layout, uint32_t count )
			{
				return std::make_unique< GeometryOutput >( type, layout, count );
			}
			, []( TypePtr type, OutputLayout layout, uint32_t count )noexcept
			{
				return getHash( type, layout, count );
			} }
		, m_tessellationOutputPatch{ []( TypePtr type, uint32_t location )
			{
				return std::make_unique< TessellationOutputPatch >( type, location );
			}
			, []( TypePtr type, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location, false );
			} }
		, m_tessellationControlInput{ []( TypePtr type, uint32_t inputVertices )
			{
				return std::make_unique< TessellationControlInput >( type, inputVertices );
			}
			, []( TypePtr type, uint32_t inputVertices )noexcept
			{
				return ast::type::getHash( type, inputVertices, false );
			} }
		, m_tessellationControlOutput{ []( TypePtr type, PatchDomain domain, Partitioning partitioning, OutputTopology topology, PrimitiveOrdering order, uint32_t outputVertices )
			{
				return std::make_unique< TessellationControlOutput >( type, domain, partitioning, topology, order, outputVertices );
			}
			, []( TypePtr type, PatchDomain domain, Partitioning partitioning, OutputTopology topology, PrimitiveOrdering order, uint32_t outputVertices )noexcept
			{
				return getHash( type, domain, partitioning, topology, order, outputVertices );
			} }
		, m_tessellationInputPatch{ []( TypePtr type, PatchDomain domain, uint32_t location )
			{
				return std::make_unique< TessellationInputPatch >( type, domain, location );
			}
			, []( TypePtr type, PatchDomain domain, uint32_t location )noexcept
			{
				return ast::type::getHash( type, domain, location );
			} }
		, m_tessellationEvaluationInput{ []( TypePtr type, PatchDomain domain, Partitioning partitioning, PrimitiveOrdering order, uint32_t outputVertices )
			{
				return std::make_unique< TessellationEvaluationInput >( type, domain, partitioning, order, outputVertices );
			}
			, []( TypePtr type, PatchDomain domain, Partitioning partitioning, PrimitiveOrdering order, uint32_t outputVertices )noexcept
			{
				return getHash( type, domain, partitioning, order, outputVertices );
			} }
	{
		m_rayDesc = std::make_unique< RayDesc >( *this );
	}

	TypePtr TypesCache::getUndefined()
	{
		return getBasicType( Kind::eUndefined );
	}

	TypePtr TypesCache::getVoid()
	{
		return getBasicType( Kind::eVoid );
	}

	TypePtr TypesCache::getBool()
	{
		return getBasicType( Kind::eBoolean );
	}

	TypePtr TypesCache::getBoolean()
	{
		return getBasicType( Kind::eBoolean );
	}

	TypePtr TypesCache::getInt8()
	{
		return getBasicType( Kind::eInt8 );
	}

	TypePtr TypesCache::getInt16()
	{
		return getBasicType( Kind::eInt16 );
	}

	TypePtr TypesCache::getInt32()
	{
		return getBasicType( Kind::eInt32 );
	}

	TypePtr TypesCache::getInt64()
	{
		return getBasicType( Kind::eInt64 );
	}

	TypePtr TypesCache::getUInt8()
	{
		return getBasicType( Kind::eUInt8 );
	}

	TypePtr TypesCache::getUInt16()
	{
		return getBasicType( Kind::eUInt16 );
	}

	TypePtr TypesCache::getUInt32()
	{
		return getBasicType( Kind::eUInt32 );
	}

	TypePtr TypesCache::getUInt64()
	{
		return getBasicType( Kind::eUInt64 );
	}

	TypePtr TypesCache::getHalf()
	{
		return getBasicType( Kind::eHalf );
	}

	TypePtr TypesCache::getFloat()
	{
		return getBasicType( Kind::eFloat );
	}

	TypePtr TypesCache::getDouble()
	{
		return getBasicType( Kind::eDouble );
	}

	TypePtr TypesCache::getVec2B()
	{
		return getBasicType( Kind::eVec2B );
	}

	TypePtr TypesCache::getVec3B()
	{
		return getBasicType( Kind::eVec3B );
	}

	TypePtr TypesCache::getVec4B()
	{
		return getBasicType( Kind::eVec4B );
	}

	TypePtr TypesCache::getVec2I8()
	{
		return getBasicType( Kind::eVec2I8 );
	}

	TypePtr TypesCache::getVec3I8()
	{
		return getBasicType( Kind::eVec3I8 );
	}

	TypePtr TypesCache::getVec4I8()
	{
		return getBasicType( Kind::eVec4I8 );
	}

	TypePtr TypesCache::getVec2I16()
	{
		return getBasicType( Kind::eVec2I16 );
	}

	TypePtr TypesCache::getVec3I16()
	{
		return getBasicType( Kind::eVec3I16 );
	}

	TypePtr TypesCache::getVec4I16()
	{
		return getBasicType( Kind::eVec4I16 );
	}

	TypePtr TypesCache::getVec2I32()
	{
		return getBasicType( Kind::eVec2I32 );
	}

	TypePtr TypesCache::getVec3I32()
	{
		return getBasicType( Kind::eVec3I32 );
	}

	TypePtr TypesCache::getVec4I32()
	{
		return getBasicType( Kind::eVec4I32 );
	}

	TypePtr TypesCache::getVec2I64()
	{
		return getBasicType( Kind::eVec2I64 );
	}

	TypePtr TypesCache::getVec3I64()
	{
		return getBasicType( Kind::eVec3I64 );
	}

	TypePtr TypesCache::getVec4I64()
	{
		return getBasicType( Kind::eVec4I64 );
	}

	TypePtr TypesCache::getVec2U8()
	{
		return getBasicType( Kind::eVec2U8 );
	}

	TypePtr TypesCache::getVec3U8()
	{
		return getBasicType( Kind::eVec3U8 );
	}

	TypePtr TypesCache::getVec4U8()
	{
		return getBasicType( Kind::eVec4U8 );
	}

	TypePtr TypesCache::getVec2U16()
	{
		return getBasicType( Kind::eVec2U16 );
	}

	TypePtr TypesCache::getVec3U16()
	{
		return getBasicType( Kind::eVec3U16 );
	}

	TypePtr TypesCache::getVec4U16()
	{
		return getBasicType( Kind::eVec4U16 );
	}

	TypePtr TypesCache::getVec2U32()
	{
		return getBasicType( Kind::eVec2U32 );
	}

	TypePtr TypesCache::getVec3U32()
	{
		return getBasicType( Kind::eVec3U32 );
	}

	TypePtr TypesCache::getVec4U32()
	{
		return getBasicType( Kind::eVec4U32 );
	}

	TypePtr TypesCache::getVec2U64()
	{
		return getBasicType( Kind::eVec2U64 );
	}

	TypePtr TypesCache::getVec3U64()
	{
		return getBasicType( Kind::eVec3U64 );
	}

	TypePtr TypesCache::getVec4U64()
	{
		return getBasicType( Kind::eVec4U64 );
	}

	TypePtr TypesCache::getVec2H()
	{
		return getBasicType( Kind::eVec2H );
	}

	TypePtr TypesCache::getVec4H()
	{
		return getBasicType( Kind::eVec4H );
	}

	TypePtr TypesCache::getVec2F()
	{
		return getBasicType( Kind::eVec2F );
	}

	TypePtr TypesCache::getVec3F()
	{
		return getBasicType( Kind::eVec3F );
	}

	TypePtr TypesCache::getVec4F()
	{
		return getBasicType( Kind::eVec4F );
	}

	TypePtr TypesCache::getVec2D()
	{
		return getBasicType( Kind::eVec2D );
	}

	TypePtr TypesCache::getVec3D()
	{
		return getBasicType( Kind::eVec3D );
	}

	TypePtr TypesCache::getVec4D()
	{
		return getBasicType( Kind::eVec4D );
	}

	TypePtr TypesCache::getMat2x2F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat2x2F, explicitLayout );
	}

	TypePtr TypesCache::getMat2x3F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat2x3F, explicitLayout );
	}

	TypePtr TypesCache::getMat2x4F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat2x4F, explicitLayout );
	}

	TypePtr TypesCache::getMat3x2F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat3x2F, explicitLayout );
	}

	TypePtr TypesCache::getMat3x3F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat3x3F, explicitLayout );
	}

	TypePtr TypesCache::getMat3x4F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat3x4F, explicitLayout );
	}

	TypePtr TypesCache::getMat4x2F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat4x2F, explicitLayout );
	}

	TypePtr TypesCache::getMat4x3F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat4x3F, explicitLayout );
	}

	TypePtr TypesCache::getMat4x4F( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat4x4F, explicitLayout );
	}

	TypePtr TypesCache::getMat2x2D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat2x2D, explicitLayout );
	}

	TypePtr TypesCache::getMat2x3D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat2x3D, explicitLayout );
	}

	TypePtr TypesCache::getMat2x4D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat2x4D, explicitLayout );
	}

	TypePtr TypesCache::getMat3x2D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat3x2D, explicitLayout );
	}

	TypePtr TypesCache::getMat3x3D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat3x3D, explicitLayout );
	}

	TypePtr TypesCache::getMat3x4D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat3x4D, explicitLayout );
	}

	TypePtr TypesCache::getMat4x2D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat4x2D, explicitLayout );
	}

	TypePtr TypesCache::getMat4x3D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat4x3D, explicitLayout );
	}

	TypePtr TypesCache::getMat4x4D( bool explicitLayout )
	{
		return m_basic.getType( Kind::eMat4x4D, explicitLayout );
	}

	TypePtr TypesCache::getBasicType( Kind kind, bool explicitLayout )
	{
		TypePtr result{};

		if ( kind == Kind::eUndefined
			|| isBasicType( kind ) )
		{
			result = m_basic.getType( kind, explicitLayout );
		}

		AST_Assert( result && "Unsupported Kind" );
		return result;
	}

	TypePtr TypesCache::getVec2Type( Kind kind )
	{
		kind = getVec2Kind( kind );
		return kind == Kind::eUndefined
			? nullptr
			: getBasicType( kind );
	}

	TypePtr TypesCache::getVec3Type( Kind kind )
	{
		kind = getVec3Kind( kind );
		return kind == Kind::eUndefined
			? nullptr
			: getBasicType( kind );
	}

	TypePtr TypesCache::getVec4Type( Kind kind )
	{
		kind = getVec4Kind( kind );
		return kind == Kind::eUndefined
			? nullptr
			: getBasicType( kind );
	}

	Kind TypesCache::getVec2Kind( Kind kind )const
	{
		Kind result{ Kind::eUndefined };

		switch ( kind )
		{
		case Kind::eBoolean:
			result = Kind::eVec2B;
			break;
		case Kind::eInt8:
			result = Kind::eVec2I8;
			break;
		case Kind::eInt16:
			result = Kind::eVec2I16;
			break;
		case Kind::eInt32:
			result = Kind::eVec2I32;
			break;
		case Kind::eInt64:
			result = Kind::eVec2I64;
			break;
		case Kind::eUInt8:
			result = Kind::eVec2U8;
			break;
		case Kind::eUInt16:
			result = Kind::eVec2U16;
			break;
		case Kind::eUInt32:
			result = Kind::eVec2U32;
			break;
		case Kind::eUInt64:
			result = Kind::eVec2U64;
			break;
		case Kind::eHalf:
			result = Kind::eVec2H;
			break;
		case Kind::eFloat:
			result = Kind::eVec2F;
			break;
		case Kind::eDouble:
			result = Kind::eVec2D;
			break;
		default:
			break;
		}

		AST_Assert( result != Kind::eUndefined && "Unsupported component type" );
		return result;
	}

	Kind TypesCache::getVec3Kind( Kind kind )const
	{
		Kind result{ Kind::eUndefined };

		switch ( kind )
		{
		case Kind::eBoolean:
			result = Kind::eVec3B;
			break;
		case Kind::eInt8:
			result = Kind::eVec3I8;
			break;
		case Kind::eInt16:
			result = Kind::eVec3I16;
			break;
		case Kind::eInt32:
			result = Kind::eVec3I32;
			break;
		case Kind::eInt64:
			result = Kind::eVec3I64;
			break;
		case Kind::eUInt8:
			result = Kind::eVec3U8;
			break;
		case Kind::eUInt16:
			result = Kind::eVec3U16;
			break;
		case Kind::eUInt32:
			result = Kind::eVec3U32;
			break;
		case Kind::eUInt64:
			result = Kind::eVec3U64;
			break;
		case Kind::eFloat:
			result = Kind::eVec3F;
			break;
		case Kind::eDouble:
			result = Kind::eVec3D;
			break;
		default:
			break;
		}

		AST_Assert( result != Kind::eUndefined && "Unsupported component type" );
		return result;
	}

	Kind TypesCache::getVec4Kind( Kind kind )const
	{
		Kind result{ Kind::eUndefined };

		switch ( kind )
		{
		case Kind::eBoolean:
			result = Kind::eVec4B;
			break;
		case Kind::eInt8:
			result = Kind::eVec4I8;
			break;
		case Kind::eInt16:
			result = Kind::eVec4I16;
			break;
		case Kind::eInt32:
			result = Kind::eVec4I32;
			break;
		case Kind::eInt64:
			result = Kind::eVec4I64;
			break;
		case Kind::eUInt8:
			result = Kind::eVec4U8;
			break;
		case Kind::eUInt16:
			result = Kind::eVec4U16;
			break;
		case Kind::eUInt32:
			result = Kind::eVec4U32;
			break;
		case Kind::eUInt64:
			result = Kind::eVec4U64;
			break;
		case Kind::eHalf:
			result = Kind::eVec4H;
			break;
		case Kind::eFloat:
			result = Kind::eVec4F;
			break;
		case Kind::eDouble:
			result = Kind::eVec4D;
			break;
		default:
			break;
		}

		AST_Assert( result != Kind::eUndefined && "Unsupported component type" );
		return result;
	}

	Kind TypesCache::getMat2Kind( Kind kind )const
	{
		Kind result{ Kind::eUndefined };

		switch ( kind )
		{
		case Kind::eVec2F:
			result = Kind::eMat2x2F;
			break;
		case Kind::eVec2D:
			result = Kind::eMat2x2D;
			break;
		case Kind::eVec3F:
			result = Kind::eMat2x3F;
			break;
		case Kind::eVec3D:
			result = Kind::eMat2x3D;
			break;
		case Kind::eVec4F:
			result = Kind::eMat2x4F;
			break;
		case Kind::eVec4D:
			result = Kind::eMat2x4D;
			break;
		default:
			break;
		}

		AST_Assert( result != Kind::eUndefined && "Unsupported component type" );
		return result;
	}

	Kind TypesCache::getMat3Kind( Kind kind )const
	{
		Kind result{ Kind::eUndefined };

		switch ( kind )
		{
		case Kind::eVec2F:
			result = Kind::eMat3x2F;
			break;
		case Kind::eVec2D:
			result = Kind::eMat3x2D;
			break;
		case Kind::eVec3F:
			result = Kind::eMat3x3F;
			break;
		case Kind::eVec3D:
			result = Kind::eMat3x3D;
			break;
		case Kind::eVec4F:
			result = Kind::eMat3x4F;
			break;
		case Kind::eVec4D:
			result = Kind::eMat3x4D;
			break;
		default:
			break;
		}

		AST_Assert( result != Kind::eUndefined && "Unsupported component type" );
		return result;
	}

	Kind TypesCache::getMat4Kind( Kind kind )const
	{
		Kind result{ Kind::eUndefined };

		switch ( kind )
		{
		case Kind::eVec2F:
			result = Kind::eMat4x2F;
			break;
		case Kind::eVec2D:
			result = Kind::eMat4x2D;
			break;
		case Kind::eVec3F:
			result = Kind::eMat4x3F;
			break;
		case Kind::eVec3D:
			result = Kind::eMat4x3D;
			break;
		case Kind::eVec4F:
			result = Kind::eMat4x4F;
			break;
		case Kind::eVec4D:
			result = Kind::eMat4x4D;
			break;
		default:
			break;
		}

		AST_Assert( result != Kind::eUndefined && "Unsupported component type" );
		return result;
	}

	TypePtr TypesCache::getVector( Kind kind, uint32_t count )
	{
		AST_Assert( isScalarType( kind ) );
		TypePtr result{};

		switch ( count )
		{
		case 1:
			result = getBasicType( kind );
			break;
		case 2:
			result = getVec2Type( kind );
			break;
		case 3:
			result = getVec3Type( kind );
			break;
		case 4:
			result = getVec4Type( kind );
			break;
		default:
			break;
		}

		AST_Assert( result && "Unsupported component type" );
		return result;
	}

	ComputeInputPtr TypesCache::getComputeInput( TypePtr type
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
	{
		return m_compute.getType( type, localSizeX, localSizeY, localSizeZ );
	}

	FragmentInputPtr TypesCache::getFragmentInput( TypePtr type
		, FragmentOrigin origin
		, FragmentCenter center
		, InvocationOrdering ordering )
	{
		return m_fragment.getType( type, origin, center, ordering );
	}

	GeometryInputPtr TypesCache::getGeometryInput( TypePtr type
		, InputLayout layout )
	{
		return m_geometryInput.getType( type, layout );
	}

	GeometryOutputPtr TypesCache::getGeometryOutput( TypePtr type
		, OutputLayout layout
		, uint32_t count )
	{
		return m_geometryOutput.getType( type, layout, count );
	}

	TessellationOutputPatchPtr TypesCache::getTessellationOutputPatch( TypePtr type, uint32_t location )
	{
		return m_tessellationOutputPatch.getType( type, location );
	}

	TessellationControlInputPtr TypesCache::getTessellationControlInput( TypePtr type, uint32_t inputVertices )
	{
		return m_tessellationControlInput.getType( type, inputVertices );
	}

	TessellationControlOutputPtr TypesCache::getTessellationControlOutput( TypePtr type
		, PatchDomain domain
		, Partitioning partitioning
		, OutputTopology topology
		, PrimitiveOrdering order
		, uint32_t outputVertices )
	{
		return m_tessellationControlOutput.getType( type, domain, partitioning, topology, order, outputVertices );
	}

	TessellationInputPatchPtr TypesCache::getTessellationInputPatch( TypePtr type, PatchDomain domain, uint32_t location )
	{
		return m_tessellationInputPatch.getType( type, domain, location );
	}

	TessellationEvaluationInputPtr TypesCache::getTessellationEvaluationInput( TypePtr type
		, PatchDomain domain
		, Partitioning partitioning
		, PrimitiveOrdering order
		, uint32_t inputVertices )
	{
		return m_tessellationEvaluationInput.getType( type, domain, partitioning, order, inputVertices );
	}

	MeshPrimitiveOutputPtr TypesCache::getMeshPrimitiveOutput( TypePtr type
		, OutputTopology topology
		, uint32_t maxPrimitives )
	{
		return m_meshPrimitiveOutput.getType( type, topology, maxPrimitives );
	}

	MeshVertexOutputPtr TypesCache::getMeshVertexOutput( TypePtr type
		, uint32_t maxVertices )
	{
		return m_meshVertexOutput.getType( type, maxVertices );
	}

	TaskPayloadInPtr TypesCache::getTaskPayloadIn( TypePtr type )
	{
		return m_taskPayloadIn.getType( type );
	}

	TaskPayloadInNVPtr TypesCache::getTaskPayloadInNV( TypePtr type )
	{
		return m_taskPayloadInNV.getType( type );
	}

	TaskPayloadPtr TypesCache::getTaskPayload( TypePtr type )
	{
		return m_taskPayload.getType( type );
	}

	TaskPayloadNVPtr TypesCache::getTaskPayloadNV( TypePtr type )
	{
		return m_taskPayloadNV.getType( type );
	}

	AccelerationStructurePtr TypesCache::getAccelerationStructure()
	{
		return m_accelerationStructure.get();
	}

	HitAttributePtr TypesCache::getHitAttribute( TypePtr dataType )
	{
		return m_hitAttribute.getType( dataType );
	}

	RayPayloadPtr TypesCache::getRayPayload( TypePtr dataType, uint32_t location )
	{
		return m_rayPayload.getType( dataType, location );
	}

	CallableDataPtr TypesCache::getCallableData( TypePtr dataType, uint32_t location )
	{
		return m_callableData.getType( dataType, location );
	}

	RayDescPtr TypesCache::getRayDesc()
	{
		return m_rayDesc.get();
	}

	ImagePtr TypesCache::getImage( ImageConfiguration config )
	{
		return m_image.getType( std::move( config ) );
	}

	SampledImagePtr TypesCache::getSampledImage( ImageConfiguration config, Trinary comparison )
	{
		return m_sampledImage.getType( std::move( config ), comparison );
	}

	CombinedImagePtr TypesCache::getCombinedImage( ImageConfiguration config
		, bool isComparison )
	{
		return m_texture.getType( std::move( config ), isComparison );
	}

	SamplerPtr TypesCache::getSampler( bool comparison )
	{
		return m_sampler.getType( comparison );
	}

	TypePtr TypesCache::getSampledType( ImageFormat format )
	{
		TypePtr result{};

		switch ( format )
		{
		case ImageFormat::eUnknown:
			result = getBasicType( sampledType< ImageFormat::eUnknown > );
			break;
		case ImageFormat::eRgba32f:
			result = getBasicType( sampledType< ImageFormat::eRgba32f > );
			break;
		case ImageFormat::eRgba16f:
			result = getBasicType( sampledType< ImageFormat::eRgba16f > );
			break;
		case ImageFormat::eRg32f:
			result = getBasicType( sampledType< ImageFormat::eRg32f > );
			break;
		case ImageFormat::eRg16f:
			result = getBasicType( sampledType< ImageFormat::eRg16f > );
			break;
		case ImageFormat::eR32f:
			result = getBasicType( sampledType< ImageFormat::eR32f > );
			break;
		case ImageFormat::eR16f:
			result = getBasicType( sampledType< ImageFormat::eR16f > );
			break;
		case ImageFormat::eR11fG11fB10f:
			result = getBasicType( sampledType< ImageFormat::eR11fG11fB10f > );
			break;
		case ImageFormat::eRgba32i:
			result = getBasicType( sampledType< ImageFormat::eRgba32i > );
			break;
		case ImageFormat::eRgba16i:
			result = getBasicType( sampledType< ImageFormat::eRgba16i > );
			break;
		case ImageFormat::eRgba8i:
			result = getBasicType( sampledType< ImageFormat::eRgba8i > );
			break;
		case ImageFormat::eRg32i:
			result = getBasicType( sampledType< ImageFormat::eRg32i > );
			break;
		case ImageFormat::eRg16i:
			result = getBasicType( sampledType< ImageFormat::eRg16i > );
			break;
		case ImageFormat::eRg8i:
			result = getBasicType( sampledType< ImageFormat::eRg8i > );
			break;
		case ImageFormat::eR32i:
			result = getBasicType( sampledType< ImageFormat::eR32i > );
			break;
		case ImageFormat::eR16i:
			result = getBasicType( sampledType< ImageFormat::eR16i > );
			break;
		case ImageFormat::eR8i:
			result = getBasicType( sampledType< ImageFormat::eR8i > );
			break;
		case ImageFormat::eRgba32u:
			result = getBasicType( sampledType< ImageFormat::eRgba32u > );
			break;
		case ImageFormat::eRgba16u:
			result = getBasicType( sampledType< ImageFormat::eRgba16u > );
			break;
		case ImageFormat::eRgba8u:
			result = getBasicType( sampledType< ImageFormat::eRgba8u > );
			break;
		case ImageFormat::eRg32u:
			result = getBasicType( sampledType< ImageFormat::eRg32u > );
			break;
		case ImageFormat::eRg16u:
			result = getBasicType( sampledType< ImageFormat::eRg16u > );
			break;
		case ImageFormat::eRg8u:
			result = getBasicType( sampledType< ImageFormat::eRg8u > );
			break;
		case ImageFormat::eR32u:
			result = getBasicType( sampledType< ImageFormat::eR32u > );
			break;
		case ImageFormat::eR16u:
			result = getBasicType( sampledType< ImageFormat::eR16u > );
			break;
		case ImageFormat::eR8u:
			result = getBasicType( sampledType< ImageFormat::eR8u > );
			break;
		case ImageFormat::eRgb10A2u:
			result = getBasicType( sampledType< ImageFormat::eRgb10A2u > );
			break;
		case ImageFormat::eRgba16Snorm:
			result = getBasicType( sampledType< ImageFormat::eRgba16Snorm > );
			break;
		case ImageFormat::eRgba8Snorm:
			result = getBasicType( sampledType< ImageFormat::eRgba8Snorm > );
			break;
		case ImageFormat::eRg16Snorm:
			result = getBasicType( sampledType< ImageFormat::eRg16Snorm > );
			break;
		case ImageFormat::eRg8Snorm:
			result = getBasicType( sampledType< ImageFormat::eRg8Snorm > );
			break;
		case ImageFormat::eR16Snorm:
			result = getBasicType( sampledType< ImageFormat::eR16Snorm > );
			break;
		case ImageFormat::eR8Snorm:
			result = getBasicType( sampledType< ImageFormat::eR8Snorm > );
			break;
		case ImageFormat::eRgba16Unorm:
			result = getBasicType( sampledType< ImageFormat::eRgba16Unorm > );
			break;
		case ImageFormat::eRgba8Unorm:
			result = getBasicType( sampledType< ImageFormat::eRgba8Unorm > );
			break;
		case ImageFormat::eRg16Unorm:
			result = getBasicType( sampledType< ImageFormat::eRg16Unorm > );
			break;
		case ImageFormat::eRg8Unorm:
			result = getBasicType( sampledType< ImageFormat::eRg8Unorm > );
			break;
		case ImageFormat::eR16Unorm:
			result = getBasicType( sampledType< ImageFormat::eR16Unorm > );
			break;
		case ImageFormat::eR8Unorm:
			result = getBasicType( sampledType< ImageFormat::eR8Unorm > );
			break;
		case ImageFormat::eRgb10A2Unorm:
			result = getBasicType( sampledType< ImageFormat::eRgb10A2Unorm > );
			break;
		default:
			break;
		}

		AST_Assert( result && "getSampledType: Unsupported ImageFormat" );
		return result;
	}

	TypePtr TypesCache::getTexelType( ImageFormat format )
	{
		TypePtr result{};

		switch ( format )
		{
		case ImageFormat::eUnknown:
			result = getBasicType( texelType< ImageFormat::eUnknown > );
			break;
		case ImageFormat::eRgba32f:
			result = getBasicType( texelType< ImageFormat::eRgba32f > );
			break;
		case ImageFormat::eRgba16f:
			result = getBasicType( texelType< ImageFormat::eRgba16f > );
			break;
		case ImageFormat::eRg32f:
			result = getBasicType( texelType< ImageFormat::eRg32f > );
			break;
		case ImageFormat::eRg16f:
			result = getBasicType( texelType< ImageFormat::eRg16f > );
			break;
		case ImageFormat::eR32f:
			result = getBasicType( texelType< ImageFormat::eR32f > );
			break;
		case ImageFormat::eR16f:
			result = getBasicType( texelType< ImageFormat::eR16f > );
			break;
		case ImageFormat::eR11fG11fB10f:
			result = getBasicType( texelType< ImageFormat::eR11fG11fB10f > );
			break;
		case ImageFormat::eRgba32i:
			result = getBasicType( texelType< ImageFormat::eRgba32i > );
			break;
		case ImageFormat::eRgba16i:
			result = getBasicType( texelType< ImageFormat::eRgba16i > );
			break;
		case ImageFormat::eRgba8i:
			result = getBasicType( texelType< ImageFormat::eRgba8i > );
			break;
		case ImageFormat::eRg32i:
			result = getBasicType( texelType< ImageFormat::eRg32i > );
			break;
		case ImageFormat::eRg16i:
			result = getBasicType( texelType< ImageFormat::eRg16i > );
			break;
		case ImageFormat::eRg8i:
			result = getBasicType( texelType< ImageFormat::eRg8i > );
			break;
		case ImageFormat::eR32i:
			result = getBasicType( texelType< ImageFormat::eR32i > );
			break;
		case ImageFormat::eR16i:
			result = getBasicType( texelType< ImageFormat::eR16i > );
			break;
		case ImageFormat::eR8i:
			result = getBasicType( texelType< ImageFormat::eR8i > );
			break;
		case ImageFormat::eRgba32u:
			result = getBasicType( texelType< ImageFormat::eRgba32u > );
			break;
		case ImageFormat::eRgba16u:
			result = getBasicType( texelType< ImageFormat::eRgba16u > );
			break;
		case ImageFormat::eRgba8u:
			result = getBasicType( texelType< ImageFormat::eRgba8u > );
			break;
		case ImageFormat::eRg32u:
			result = getBasicType( texelType< ImageFormat::eRg32u > );
			break;
		case ImageFormat::eRg16u:
			result = getBasicType( texelType< ImageFormat::eRg16u > );
			break;
		case ImageFormat::eRg8u:
			result = getBasicType( texelType< ImageFormat::eRg8u > );
			break;
		case ImageFormat::eR32u:
			result = getBasicType( texelType< ImageFormat::eR32u > );
			break;
		case ImageFormat::eR16u:
			result = getBasicType( texelType< ImageFormat::eR16u > );
			break;
		case ImageFormat::eR8u:
			result = getBasicType( texelType< ImageFormat::eR8u > );
			break;
		case ImageFormat::eRgb10A2u:
			result = getBasicType( texelType< ImageFormat::eRgb10A2u > );
			break;
		case ImageFormat::eRgba16Snorm:
			result = getBasicType( texelType< ImageFormat::eRgba16Snorm > );
			break;
		case ImageFormat::eRgba8Snorm:
			result = getBasicType( texelType< ImageFormat::eRgba8Snorm > );
			break;
		case ImageFormat::eRg16Snorm:
			result = getBasicType( texelType< ImageFormat::eRg16Snorm > );
			break;
		case ImageFormat::eRg8Snorm:
			result = getBasicType( texelType< ImageFormat::eRg8Snorm > );
			break;
		case ImageFormat::eR16Snorm:
			result = getBasicType( texelType< ImageFormat::eR16Snorm > );
			break;
		case ImageFormat::eR8Snorm:
			result = getBasicType( texelType< ImageFormat::eR8Snorm > );
			break;
		case ImageFormat::eRgba16Unorm:
			result = getBasicType( texelType< ImageFormat::eRgba16Unorm > );
			break;
		case ImageFormat::eRgba8Unorm:
			result = getBasicType( texelType< ImageFormat::eRgba8Unorm > );
			break;
		case ImageFormat::eRg16Unorm:
			result = getBasicType( texelType< ImageFormat::eRg16Unorm > );
			break;
		case ImageFormat::eRg8Unorm:
			result = getBasicType( texelType< ImageFormat::eRg8Unorm > );
			break;
		case ImageFormat::eR16Unorm:
			result = getBasicType( texelType< ImageFormat::eR16Unorm > );
			break;
		case ImageFormat::eR8Unorm:
			result = getBasicType( texelType< ImageFormat::eR8Unorm > );
			break;
		case ImageFormat::eRgb10A2Unorm:
			result = getBasicType( texelType< ImageFormat::eRgb10A2Unorm > );
			break;
		default:
			break;
		}

		AST_Assert( result && "getTexelType: Unsupported ImageFormat" );
		return result;
	}

	FunctionPtr TypesCache::getFunction( TypePtr returnType
		, var::VariableList parameters )
	{
		return m_function.getType( std::move( returnType )
			, std::move( parameters ) );
	}

	BaseStructPtr TypesCache::getStruct( MemoryLayout layout
		, std::string const & name
		, bool explicitLayout )
	{
		return m_struct.getType( layout, name, explicitLayout );
	}

	IOStructPtr TypesCache::getIOStruct( std::string const & name
		, ast::EntryPoint entryPoint
		, var::Flag flag )
	{
		return getIOStruct( name, entryPoint, MemoryLayout::eC, flag );
	}

	IOStructPtr TypesCache::getIOStruct( std::string const & name
		, ast::EntryPoint entryPoint
		, ast::type::MemoryLayout layout
		, var::Flag flag
		, bool explicitLayout )
	{
		if ( !hasFlag( uint64_t( flag ), var::Flag::eShaderInput )
			&& !hasFlag( uint64_t( flag ), var::Flag::eShaderOutput )
			&& !hasFlag( uint64_t( flag ), var::Flag::ePatchOutput )
			&& !hasFlag( uint64_t( flag ), var::Flag::ePatchInput )
			&& !hasFlag( uint64_t( flag ), var::Flag::ePerTask )
			&& !hasFlag( uint64_t( flag ), var::Flag::ePerTaskNV ) )
		{
			throw Exception{ "Non I/O structure." };
		}

		return ( ( hasFlag( uint64_t( flag ), var::Flag::eShaderInput ) || hasFlag( uint64_t( flag ), var::Flag::ePatchInput ) )
			? m_inputStruct.getType( layout, name, entryPoint, flag, explicitLayout )
			: m_outputStruct.getType( layout, name, entryPoint, flag, explicitLayout ) );
	}

	ArrayPtr TypesCache::getArray( TypePtr type
		, uint32_t arraySize
		, bool explicitLayout )
	{
		return m_array.getType( type, arraySize, explicitLayout );
	}

	Type const * TypesCache::getNonMemberType( TypePtr type )const
	{
		return type->getNonMemberType();
	}

	TypePtr TypesCache::getMemberType( TypePtr type, Struct & parent, uint32_t memberIndex )
	{
		if ( type->getKind() == Kind::eArray )
			return getMemberType( static_cast< Array * >( type ), parent, memberIndex );
		if ( type->getKind() == Kind::eStruct )
			return getMemberType( static_cast< Struct * >( type ), parent, memberIndex );
		return m_member.registerType( type, &parent, memberIndex
			, *this, parent, memberIndex, *type );
	}

	ArrayPtr TypesCache::getMemberType( ArrayPtr type, Struct & parent, uint32_t memberIndex )
	{
		return static_cast< ArrayPtr >( m_member.registerTypeT< Array >( type, &parent, memberIndex
			, &parent, memberIndex, type->getType(), *type ) );
	}

	StructPtr TypesCache::getMemberType( StructPtr type, Struct & parent, uint32_t memberIndex )
	{
		return static_cast< StructPtr >( m_member.tryAddType( type, &parent, memberIndex
			, std::unique_ptr< Struct >{ new Struct{ *this, parent, memberIndex, *type } } ) );
	}

	TypePtr TypesCache::getExplicitLayoutType( TypePtr type )
	{
		if ( type->getKind() == Kind::eArray )
			return getExplicitLayoutType( static_cast< Array * >( type ) );
		if ( type->getKind() == Kind::eStruct )
		{
			auto structType = static_cast< Struct * >( type );
			return structType->isIOStruct()
				? static_cast< TypePtr >( getExplicitLayoutType( static_cast< IOStructPtr >( type ) ) )
				: static_cast< TypePtr >( getExplicitLayoutType( static_cast< BaseStructPtr >( type ) ) );
		}
		if ( isBasicType( type ) )
			return getBasicType( type->getKind(), true );
		return type;
	}

	ArrayPtr TypesCache::getExplicitLayoutType( ArrayPtr type )
	{
		auto elementType = getExplicitLayoutType( type->getType() );
		return getArray( elementType, type->getArraySize(), true );
	}

	BaseStructPtr TypesCache::getExplicitLayoutType( BaseStructPtr type )
	{
		auto result = getStruct( type->getMemoryLayout(), type->getName(), true );

		if ( result->empty() )
		{
			for ( auto mbr : *type )
			{
				if ( mbr.builtin != Builtin::eNone )
					result->declMember( mbr.builtin, getNonArrayKind( mbr.type ), getArraySize( mbr.type ) );
				else
					result->declMember( mbr.name, getExplicitLayoutType( getNonArrayType( mbr.type ) ), getArraySize( mbr.type ) );
			}
		}

		return result;
	}

	IOStructPtr TypesCache::getExplicitLayoutType( IOStructPtr type )
	{
		auto result = getIOStruct( type->getName(), type->getEntryPoint(), type->getMemoryLayout(), var::Flag( type->getFlag() ), true );

		if ( result->empty() )
		{
			for ( auto mbr : *type )
			{
				if ( mbr.builtin != Builtin::eNone )
					result->declMember( mbr.builtin, getNonArrayKind( mbr.type ), getArraySize( mbr.type ) );
				else
					result->declMember( mbr.name, getExplicitLayoutType( getNonArrayType( mbr.type ) ), getArraySize( mbr.type ), mbr.location );
			}
		}

		return result;
	}

	TypePtr TypesCache::getNonExplicitLayoutType( TypePtr type )
	{
		if ( type->getKind() == Kind::eArray )
			return getNonExplicitLayoutType( static_cast< Array * >( type ) );
		if ( type->getKind() == Kind::eStruct )
		{
			auto structType = static_cast< Struct * >( type );
			return structType->isIOStruct()
				? static_cast< TypePtr >( getNonExplicitLayoutType( static_cast< IOStructPtr >( type ) ) )
				: static_cast< TypePtr >( getNonExplicitLayoutType( static_cast< BaseStructPtr >( type ) ) );
		}
		if (isBasicType( type ))
			return getBasicType( type->getKind(), false );
		return type;
	}

	ArrayPtr TypesCache::getNonExplicitLayoutType( ArrayPtr type )
	{
		auto elementType = getExplicitLayoutType( type->getType() );
		return getArray( elementType, type->getArraySize(), false );
	}

	BaseStructPtr TypesCache::getNonExplicitLayoutType( BaseStructPtr type )
	{
		auto result = getStruct( type->getMemoryLayout(), type->getName(), false );

		if ( result->empty() )
		{
			for ( auto mbr : *type )
			{
				if ( mbr.builtin != Builtin::eNone )
					result->declMember( mbr.builtin, mbr.type->getKind(), getArraySize( mbr.type ) );
				else
					result->declMember( mbr.name, getExplicitLayoutType( mbr.type ), getArraySize( mbr.type ) );
			}
		}

		return result;
	}

	IOStructPtr TypesCache::getNonExplicitLayoutType( IOStructPtr type )
	{
		auto result = getIOStruct( type->getName(), type->getEntryPoint(), type->getMemoryLayout(), var::Flag( type->getFlag() ) );

		if ( result->empty() )
		{
			for ( auto mbr : *type )
			{
				if ( mbr.builtin != Builtin::eNone )
					result->declMember( mbr.builtin, mbr.type->getKind(), getArraySize( mbr.type ) );
				else
					result->declMember( mbr.name, getExplicitLayoutType( mbr.type ), getArraySize( mbr.type ) );
			}
		}

		return result;
	}

	TypePtr TypesCache::getPointerType( TypePtr pointerType, Storage storage )
	{
		return m_pointer.getType( pointerType, storage, false );
	}

	TypePtr TypesCache::getForwardPointerType( TypePtr pointerType, Storage storage )
	{
		return m_pointer.getType( pointerType, storage, true );
	}

	//*************************************************************************
}
