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
		: m_accelerationStructure{ std::make_shared< AccelerationStructure >( *this ) }
		, m_image{ [this]( ImageConfiguration config )
			{
				return std::make_shared< Image >( *this, std::move( config ) );
			}
			, []( ImageConfiguration const & config )noexcept
			{
				return ast::type::getHash( config );
			} }
		, m_texture{ [this]( ImageConfiguration config, bool isComparison )
			{
				return std::make_shared< CombinedImage >( *this, std::move( config ), isComparison );
			}
			, []( ImageConfiguration const & config, bool isComparison )noexcept
			{
				return ast::type::getHash( config, isComparison );
			} }
		, m_sampledImage{ [this]( ImageConfiguration config, Trinary comparison )
			{
				return std::make_shared< SampledImage >( *this, std::move( config ), comparison );
			}
			, []( ImageConfiguration const & config, Trinary )noexcept
			{
				return ast::type::getHash( config );
			} }
		, m_sampler{ [this]( bool comparison )
			{
				return std::make_shared< Sampler >( *this, comparison );
			}
			, []( bool comparison )noexcept
			{
				return comparison ? 1u : 0u;
			} }
		, m_function{ []( TypePtr returnType
				, var::VariableList parameters )
			{
				return std::make_shared< Function >( returnType
					, std::move( parameters ) );
			}
			, []( TypePtr returnType
				, var::VariableList const & parameters )noexcept
			{
				return ast::type::getHash( returnType, parameters );
			} }
		, m_struct{ [this]( MemoryLayout layout
				, std::string name )
			{
				return std::make_shared< BaseStruct >( *this
					, layout
					, std::move( name ) );
			}
			, []( MemoryLayout layout
				, std::string const & name )noexcept
			{
				return ast::type::getHash( layout, name );
			} }
		, m_inputStruct{ [this]( MemoryLayout layout
				, std::string name
				, EntryPoint entryPoint
				, var::Flag flag )
			{
				return std::make_shared< IOStruct >( *this
					, layout
					, std::move( name )
					, entryPoint
					, flag );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, EntryPoint entryPoint
				, var::Flag flag )noexcept
			{
				return ast::type::getHash( layout, name, entryPoint, flag );
			} }
		, m_outputStruct{ [this]( MemoryLayout layout
				, std::string name
				, EntryPoint entryPoint
				, var::Flag flag )
			{
				return std::make_shared< IOStruct >( *this
					, layout
					, std::move( name )
					, entryPoint
					, flag );
			}
			, []( MemoryLayout layout
				, std::string const & name
				, EntryPoint entryPoint
				, var::Flag flag )noexcept
			{
				return ast::type::getHash( layout, name, entryPoint, flag );
			} }
		, m_array{ []( TypePtr type
				, uint32_t arraySize )
			{
				return std::make_shared< Array >( std::move( type )
					, arraySize );
			}
			, []( TypePtr type
				, uint32_t arraySize )noexcept
			{
				return ast::type::getHash( type, arraySize );
			} }
		, m_pointer{ []( TypePtr pointerType
				, Storage storage
				, bool isForward )
			{
				return std::make_shared< Pointer >( std::move( pointerType )
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
				return std::make_shared< RayPayload >( std::move( type )
					, location );
			}
			, []( TypePtr type
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location );
			} }
		, m_callableData{ []( TypePtr type
				, uint32_t location )
			{
				return std::make_shared< CallableData >( std::move( type )
					, location );
			}
			, []( TypePtr type
				, uint32_t location )noexcept
			{
				return ast::type::getHash( type, location );
			} }
		, m_hitAttribute{ []( TypePtr type )
			{
				return std::make_shared< HitAttribute >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_meshVertexOutput{ []( TypePtr type
			, uint32_t maxVertices )
			{
				return std::make_shared< MeshVertexOutput >( type, maxVertices );
			}
			, []( TypePtr type
				, uint32_t maxVertices )noexcept
			{
				return getHash( type, maxVertices );
			} }
		, m_meshPrimitiveOutput{ []( TypePtr type
			, OutputTopology topology
			, uint32_t maxPrimitives )
			{
				return std::make_shared< MeshPrimitiveOutput >( type, topology, maxPrimitives );
			}
			, []( TypePtr type
				, OutputTopology topology
				, uint32_t maxPrimitives )noexcept
			{
				return getHash( type, topology, maxPrimitives );
			} }
		, m_taskPayloadNV{ []( TypePtr type )
			{
				return std::make_shared< TaskPayloadNV >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_taskPayloadInNV{ []( TypePtr type )
			{
				return std::make_shared< TaskPayloadInNV >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_taskPayload{ []( TypePtr type )
			{
				return std::make_shared< TaskPayload >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
		, m_taskPayloadIn{ []( TypePtr type )
			{
				return std::make_shared< TaskPayloadIn >( type );
			}
			, []( TypePtr type )noexcept
			{
				return std::hash< TypePtr >{}( type );
			} }
	{
		for ( auto i = uint32_t( Kind::eUndefined ); i <= uint32_t( Kind::eBasicTypesMax ); ++i )
		{
			m_basicTypes[i] = std::make_shared< Type >( *this, Kind( i ) );
		}

		m_rayDesc = std::make_shared< RayDesc >( *this );
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

	TypePtr TypesCache::getMat2x2F()
	{
		return getBasicType( Kind::eMat2x2F );
	}

	TypePtr TypesCache::getMat2x3F()
	{
		return getBasicType( Kind::eMat2x3F );
	}

	TypePtr TypesCache::getMat2x4F()
	{
		return getBasicType( Kind::eMat2x4F );
	}

	TypePtr TypesCache::getMat3x2F()
	{
		return getBasicType( Kind::eMat3x2F );
	}

	TypePtr TypesCache::getMat3x3F()
	{
		return getBasicType( Kind::eMat3x3F );
	}

	TypePtr TypesCache::getMat3x4F()
	{
		return getBasicType( Kind::eMat3x4F );
	}

	TypePtr TypesCache::getMat4x2F()
	{
		return getBasicType( Kind::eMat4x2F );
	}

	TypePtr TypesCache::getMat4x3F()
	{
		return getBasicType( Kind::eMat4x3F );
	}

	TypePtr TypesCache::getMat4x4F()
	{
		return getBasicType( Kind::eMat4x4F );
	}

	TypePtr TypesCache::getMat2x2D()
	{
		return getBasicType( Kind::eMat2x2D );
	}

	TypePtr TypesCache::getMat2x3D()
	{
		return getBasicType( Kind::eMat2x3D );
	}

	TypePtr TypesCache::getMat2x4D()
	{
		return getBasicType( Kind::eMat2x4D );
	}

	TypePtr TypesCache::getMat3x2D()
	{
		return getBasicType( Kind::eMat3x2D );
	}

	TypePtr TypesCache::getMat3x3D()
	{
		return getBasicType( Kind::eMat3x3D );
	}

	TypePtr TypesCache::getMat3x4D()
	{
		return getBasicType( Kind::eMat3x4D );
	}

	TypePtr TypesCache::getMat4x2D()
	{
		return getBasicType( Kind::eMat4x2D );
	}

	TypePtr TypesCache::getMat4x3D()
	{
		return getBasicType( Kind::eMat4x3D );
	}

	TypePtr TypesCache::getMat4x4D()
	{
		return getBasicType( Kind::eMat4x4D );
	}

	TypePtr TypesCache::getBasicType( Kind kind )
	{
		assert( kind >= Kind::eUndefined
			&& kind <= Kind::eBasicTypesMax );
		TypePtr result{};

		switch ( kind )
		{
		case Kind::eUndefined:
			result = m_basicTypes[size_t( Kind::eUndefined )];
			break;
		case Kind::eVoid:
			result = m_basicTypes[size_t( Kind::eVoid )];
			break;
		case Kind::eBoolean:
			result = m_basicTypes[size_t( Kind::eBoolean )];
			break;
		case Kind::eInt8:
			result = m_basicTypes[size_t( Kind::eInt8 )];
			break;
		case Kind::eInt16:
			result = m_basicTypes[size_t( Kind::eInt16 )];
			break;
		case Kind::eInt32:
			result = m_basicTypes[size_t( Kind::eInt32 )];
			break;
		case Kind::eInt64:
			result = m_basicTypes[size_t( Kind::eInt64 )];
			break;
		case Kind::eUInt8:
			result = m_basicTypes[size_t( Kind::eUInt8 )];
			break;
		case Kind::eUInt16:
			result = m_basicTypes[size_t( Kind::eUInt16 )];
			break;
		case Kind::eUInt32:
			result = m_basicTypes[size_t( Kind::eUInt32 )];
			break;
		case Kind::eUInt64:
			result = m_basicTypes[size_t( Kind::eUInt64 )];
			break;
		case Kind::eHalf:
			result = m_basicTypes[size_t( Kind::eHalf )];
			break;
		case Kind::eFloat:
			result = m_basicTypes[size_t( Kind::eFloat )];
			break;
		case Kind::eDouble:
			result = m_basicTypes[size_t( Kind::eDouble )];
			break;
		case Kind::eVec2B:
			result = m_basicTypes[size_t( Kind::eVec2B )];
			break;
		case Kind::eVec3B:
			result = m_basicTypes[size_t( Kind::eVec3B )];
			break;
		case Kind::eVec4B:
			result = m_basicTypes[size_t( Kind::eVec4B )];
			break;
		case Kind::eVec2I8:
			result = m_basicTypes[size_t( Kind::eVec2I8 )];
			break;
		case Kind::eVec3I8:
			result = m_basicTypes[size_t( Kind::eVec3I8 )];
			break;
		case Kind::eVec4I8:
			result = m_basicTypes[size_t( Kind::eVec4I8 )];
			break;
		case Kind::eVec2I16:
			result = m_basicTypes[size_t( Kind::eVec2I16 )];
			break;
		case Kind::eVec3I16:
			result = m_basicTypes[size_t( Kind::eVec3I16 )];
			break;
		case Kind::eVec4I16:
			result = m_basicTypes[size_t( Kind::eVec4I16 )];
			break;
		case Kind::eVec2I32:
			result = m_basicTypes[size_t( Kind::eVec2I32 )];
			break;
		case Kind::eVec3I32:
			result = m_basicTypes[size_t( Kind::eVec3I32 )];
			break;
		case Kind::eVec4I32:
			result = m_basicTypes[size_t( Kind::eVec4I32 )];
			break;
		case Kind::eVec2I64:
			result = m_basicTypes[size_t( Kind::eVec2I64 )];
			break;
		case Kind::eVec3I64:
			result = m_basicTypes[size_t( Kind::eVec3I64 )];
			break;
		case Kind::eVec4I64:
			result = m_basicTypes[size_t( Kind::eVec4I64 )];
			break;
		case Kind::eVec2U8:
			result = m_basicTypes[size_t( Kind::eVec2U8 )];
			break;
		case Kind::eVec3U8:
			result = m_basicTypes[size_t( Kind::eVec3U8 )];
			break;
		case Kind::eVec4U8:
			result = m_basicTypes[size_t( Kind::eVec4U8 )];
			break;
		case Kind::eVec2U16:
			result = m_basicTypes[size_t( Kind::eVec2U16 )];
			break;
		case Kind::eVec3U16:
			result = m_basicTypes[size_t( Kind::eVec3U16 )];
			break;
		case Kind::eVec4U16:
			result = m_basicTypes[size_t( Kind::eVec4U16 )];
			break;
		case Kind::eVec2U32:
			result = m_basicTypes[size_t( Kind::eVec2U32 )];
			break;
		case Kind::eVec3U32:
			result = m_basicTypes[size_t( Kind::eVec3U32 )];
			break;
		case Kind::eVec4U32:
			result = m_basicTypes[size_t( Kind::eVec4U32 )];
			break;
		case Kind::eVec2U64:
			result = m_basicTypes[size_t( Kind::eVec2U64 )];
			break;
		case Kind::eVec3U64:
			result = m_basicTypes[size_t( Kind::eVec3U64 )];
			break;
		case Kind::eVec4U64:
			result = m_basicTypes[size_t( Kind::eVec4U64 )];
			break;
		case Kind::eVec2H:
			result = m_basicTypes[size_t( Kind::eVec2H )];
			break;
		case Kind::eVec4H:
			result = m_basicTypes[size_t( Kind::eVec4H )];
			break;
		case Kind::eVec2F:
			result = m_basicTypes[size_t( Kind::eVec2F )];
			break;
		case Kind::eVec3F:
			result = m_basicTypes[size_t( Kind::eVec3F )];
			break;
		case Kind::eVec4F:
			result = m_basicTypes[size_t( Kind::eVec4F )];
			break;
		case Kind::eVec2D:
			result = m_basicTypes[size_t( Kind::eVec2D )];
			break;
		case Kind::eVec3D:
			result = m_basicTypes[size_t( Kind::eVec3D )];
			break;
		case Kind::eVec4D:
			result = m_basicTypes[size_t( Kind::eVec4D )];
			break;
		case Kind::eMat2x2F:
			result = m_basicTypes[size_t( Kind::eMat2x2F )];
			break;
		case Kind::eMat2x3F:
			result = m_basicTypes[size_t( Kind::eMat2x3F )];
			break;
		case Kind::eMat2x4F:
			result = m_basicTypes[size_t( Kind::eMat2x4F )];
			break;
		case Kind::eMat3x2F:
			result = m_basicTypes[size_t( Kind::eMat3x2F )];
			break;
		case Kind::eMat3x3F:
			result = m_basicTypes[size_t( Kind::eMat3x3F )];
			break;
		case Kind::eMat3x4F:
			result = m_basicTypes[size_t( Kind::eMat3x4F )];
			break;
		case Kind::eMat4x2F:
			result = m_basicTypes[size_t( Kind::eMat4x2F )];
			break;
		case Kind::eMat4x3F:
			result = m_basicTypes[size_t( Kind::eMat4x3F )];
			break;
		case Kind::eMat4x4F:
			result = m_basicTypes[size_t( Kind::eMat4x4F )];
			break;
		case Kind::eMat2x2D:
			result = m_basicTypes[size_t( Kind::eMat2x2D )];
			break;
		case Kind::eMat2x3D:
			result = m_basicTypes[size_t( Kind::eMat2x3D )];
			break;
		case Kind::eMat2x4D:
			result = m_basicTypes[size_t( Kind::eMat2x4D )];
			break;
		case Kind::eMat3x2D:
			result = m_basicTypes[size_t( Kind::eMat3x2D )];
			break;
		case Kind::eMat3x3D:
			result = m_basicTypes[size_t( Kind::eMat3x3D )];
			break;
		case Kind::eMat3x4D:
			result = m_basicTypes[size_t( Kind::eMat3x4D )];
			break;
		case Kind::eMat4x2D:
			result = m_basicTypes[size_t( Kind::eMat4x2D )];
			break;
		case Kind::eMat4x3D:
			result = m_basicTypes[size_t( Kind::eMat4x3D )];
			break;
		case Kind::eMat4x4D:
			result = m_basicTypes[size_t( Kind::eMat4x4D )];
			break;
		default:
			break;
		}

		assert( result && "Unsupported Kind" );
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

	TypePtr TypesCache::getMat2Type( Kind kind )
	{
		kind = getMat2Kind( kind );
		return kind == Kind::eUndefined
			? nullptr
			: getBasicType( kind );
	}

	TypePtr TypesCache::getMat3Type( Kind kind )
	{
		kind = getMat3Kind( kind );
		return kind == Kind::eUndefined
			? nullptr
			: getBasicType( kind );
	}

	TypePtr TypesCache::getMat4Type( Kind kind )
	{
		kind = getMat4Kind( kind );
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

		assert( result != Kind::eUndefined && "Unsupported component type" );
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

		assert( result != Kind::eUndefined && "Unsupported component type" );
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

		assert( result != Kind::eUndefined && "Unsupported component type" );
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

		assert( result != Kind::eUndefined && "Unsupported component type" );
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

		assert( result != Kind::eUndefined && "Unsupported component type" );
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

		assert( result != Kind::eUndefined && "Unsupported component type" );
		return result;
	}

	TypePtr TypesCache::getVector( Kind kind, uint32_t count )
	{
		assert( isScalarType( kind ) );
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

		assert( result && "Unsupported component type" );
		return result;
	}

	AccelerationStructurePtr TypesCache::getAccelerationStructure()
	{
		return m_accelerationStructure;
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
		return m_rayDesc;
	}

	MeshVertexOutputPtr TypesCache::getMeshVertexOutput( TypePtr type
		, uint32_t maxVertices )
	{
		return m_meshVertexOutput.getType( type, maxVertices );
	}

	MeshPrimitiveOutputPtr TypesCache::getMeshPrimitiveOutput( TypePtr type
		, OutputTopology topology
		, uint32_t maxPrimitives )
	{
		return m_meshPrimitiveOutput.getType( type, topology, maxPrimitives );
	}

	TaskPayloadNVPtr TypesCache::getTaskPayloadNV( TypePtr type )
	{
		return m_taskPayloadNV.getType( type );
	}

	TaskPayloadInNVPtr TypesCache::getTaskPayloadInNV( TypePtr type )
	{
		return m_taskPayloadInNV.getType( type );
	}

	TaskPayloadPtr TypesCache::getTaskPayload( TypePtr type )
	{
		return m_taskPayload.getType( type );
	}

	TaskPayloadInPtr TypesCache::getTaskPayloadIn( TypePtr type )
	{
		return m_taskPayloadIn.getType( type );
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
		default:
			break;
		}

		assert( result && "getSampledType: Unsupported ImageFormat" );
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
		default:
			break;
		}

		assert( result && "getTexelType: Unsupported ImageFormat" );
		return result;
	}

	FunctionPtr TypesCache::getFunction( TypePtr returnType
		, var::VariableList parameters )
	{
		return m_function.getType( std::move( returnType )
			, std::move( parameters ) );
	}

	BaseStructPtr TypesCache::getStruct( MemoryLayout layout
		, std::string const & name )
	{
		return m_struct.getType( layout, name );
	}

	IOStructPtr TypesCache::getIOStruct( std::string name
		, ast::EntryPoint entryPoint
		, var::Flag flag )
	{
		if ( !hasFlag( uint64_t( flag ), var::Flag::eShaderInput )
			&& !hasFlag( uint64_t( flag ), var::Flag::eShaderOutput )
			&& !hasFlag( uint64_t( flag ), var::Flag::ePatchOutput )
			&& !hasFlag( uint64_t( flag ), var::Flag::ePatchInput )
			&& !hasFlag( uint64_t( flag ), var::Flag::ePerTask ) )
		{
			throw Exception{ "Non I/O structure." };
		}

		name += getName( entryPoint );
		name += ( ( hasFlag( uint64_t( flag ), ast::var::Flag::ePatchInput ) || hasFlag( uint64_t( flag ), ast::var::Flag::ePatchOutput ) )
			? std::string{ "Patch" }
			: std::string{} );
		name += ( ( hasFlag( uint64_t( flag ), ast::var::Flag::eShaderOutput ) || hasFlag( uint64_t( flag ), ast::var::Flag::ePatchOutput ) )
			? std::string{ "Output" }
			: ( ( hasFlag( uint64_t( flag ), ast::var::Flag::eShaderInput ) || hasFlag( uint64_t( flag ), ast::var::Flag::ePatchInput ) )
				? std::string{ "Input" }
				: std::string{} ) );
		return ( hasFlag( uint64_t( flag ), var::Flag::eShaderInput )
			? m_inputStruct.getType( MemoryLayout::eC, std::move( name ), entryPoint, flag )
			: m_outputStruct.getType( MemoryLayout::eC, std::move( name ), entryPoint, flag ) );
	}

	ArrayPtr TypesCache::getArray( TypePtr type
		, uint32_t arraySize )
	{
		return m_array.getType( type, arraySize );
	}

	TypePtr TypesCache::getMemberType( TypePtr type
		, Struct & parent
		, uint32_t memberIndex )const
	{
		return type->getMemberType( parent, memberIndex );
	}

	Type const * TypesCache::getNonMemberType( TypePtr type )const
	{
		return type->getNonMemberType();
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
