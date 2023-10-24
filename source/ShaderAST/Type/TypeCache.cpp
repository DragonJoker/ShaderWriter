/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeCache.hpp"

#include "ShaderAST/Type/TypeImage.hpp"
#include "ShaderAST/Type/TypeCombinedImage.hpp"
#include "ShaderAST/Type/TypeSampler.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

#include <stdexcept>

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
		for ( uint32_t i = uint32_t( Kind::eUndefined ); i <= uint32_t( Kind::eBasicTypesMax ); ++i )
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

		switch ( kind )
		{
		case Kind::eUndefined:
			return m_basicTypes[size_t( Kind::eUndefined )];
		case Kind::eVoid:
			return m_basicTypes[size_t( Kind::eVoid )];
		case Kind::eFunction:
			return m_basicTypes[size_t( Kind::eFunction )];
		case Kind::eBoolean:
			return m_basicTypes[size_t( Kind::eBoolean )];
		case Kind::eInt8:
			return m_basicTypes[size_t( Kind::eInt8 )];
		case Kind::eInt16:
			return m_basicTypes[size_t( Kind::eInt16 )];
		case Kind::eInt32:
			return m_basicTypes[size_t( Kind::eInt32 )];
		case Kind::eInt64:
			return m_basicTypes[size_t( Kind::eInt64 )];
		case Kind::eUInt8:
			return m_basicTypes[size_t( Kind::eUInt8 )];
		case Kind::eUInt16:
			return m_basicTypes[size_t( Kind::eUInt16 )];
		case Kind::eUInt32:
			return m_basicTypes[size_t( Kind::eUInt32 )];
		case Kind::eUInt64:
			return m_basicTypes[size_t( Kind::eUInt64 )];
		case Kind::eHalf:
			return m_basicTypes[size_t( Kind::eHalf )];
		case Kind::eFloat:
			return m_basicTypes[size_t( Kind::eFloat )];
		case Kind::eDouble:
			return m_basicTypes[size_t( Kind::eDouble )];
		case Kind::eVec2B:
			return m_basicTypes[size_t( Kind::eVec2B )];
		case Kind::eVec3B:
			return m_basicTypes[size_t( Kind::eVec3B )];
		case Kind::eVec4B:
			return m_basicTypes[size_t( Kind::eVec4B )];
		case Kind::eVec2I8:
			return m_basicTypes[size_t( Kind::eVec2I8 )];
		case Kind::eVec3I8:
			return m_basicTypes[size_t( Kind::eVec3I8 )];
		case Kind::eVec4I8:
			return m_basicTypes[size_t( Kind::eVec4I8 )];
		case Kind::eVec2I16:
			return m_basicTypes[size_t( Kind::eVec2I16 )];
		case Kind::eVec3I16:
			return m_basicTypes[size_t( Kind::eVec3I16 )];
		case Kind::eVec4I16:
			return m_basicTypes[size_t( Kind::eVec4I16 )];
		case Kind::eVec2I32:
			return m_basicTypes[size_t( Kind::eVec2I32 )];
		case Kind::eVec3I32:
			return m_basicTypes[size_t( Kind::eVec3I32 )];
		case Kind::eVec4I32:
			return m_basicTypes[size_t( Kind::eVec4I32 )];
		case Kind::eVec2I64:
			return m_basicTypes[size_t( Kind::eVec2I64 )];
		case Kind::eVec3I64:
			return m_basicTypes[size_t( Kind::eVec3I64 )];
		case Kind::eVec4I64:
			return m_basicTypes[size_t( Kind::eVec4I64 )];
		case Kind::eVec2U8:
			return m_basicTypes[size_t( Kind::eVec2U8 )];
		case Kind::eVec3U8:
			return m_basicTypes[size_t( Kind::eVec3U8 )];
		case Kind::eVec4U8:
			return m_basicTypes[size_t( Kind::eVec4U8 )];
		case Kind::eVec2U16:
			return m_basicTypes[size_t( Kind::eVec2U16 )];
		case Kind::eVec3U16:
			return m_basicTypes[size_t( Kind::eVec3U16 )];
		case Kind::eVec4U16:
			return m_basicTypes[size_t( Kind::eVec4U16 )];
		case Kind::eVec2U32:
			return m_basicTypes[size_t( Kind::eVec2U32 )];
		case Kind::eVec3U32:
			return m_basicTypes[size_t( Kind::eVec3U32 )];
		case Kind::eVec4U32:
			return m_basicTypes[size_t( Kind::eVec4U32 )];
		case Kind::eVec2U64:
			return m_basicTypes[size_t( Kind::eVec2U64 )];
		case Kind::eVec3U64:
			return m_basicTypes[size_t( Kind::eVec3U64 )];
		case Kind::eVec4U64:
			return m_basicTypes[size_t( Kind::eVec4U64 )];
		case Kind::eVec2H:
			return m_basicTypes[size_t( Kind::eVec2H )];
		case Kind::eVec4H:
			return m_basicTypes[size_t( Kind::eVec4H )];
		case Kind::eVec2F:
			return m_basicTypes[size_t( Kind::eVec2F )];
		case Kind::eVec3F:
			return m_basicTypes[size_t( Kind::eVec3F )];
		case Kind::eVec4F:
			return m_basicTypes[size_t( Kind::eVec4F )];
		case Kind::eVec2D:
			return m_basicTypes[size_t( Kind::eVec2D )];
		case Kind::eVec3D:
			return m_basicTypes[size_t( Kind::eVec3D )];
		case Kind::eVec4D:
			return m_basicTypes[size_t( Kind::eVec4D )];
		case Kind::eMat2x2F:
			return m_basicTypes[size_t( Kind::eMat2x2F )];
		case Kind::eMat2x3F:
			return m_basicTypes[size_t( Kind::eMat2x3F )];
		case Kind::eMat2x4F:
			return m_basicTypes[size_t( Kind::eMat2x4F )];
		case Kind::eMat3x2F:
			return m_basicTypes[size_t( Kind::eMat3x2F )];
		case Kind::eMat3x3F:
			return m_basicTypes[size_t( Kind::eMat3x3F )];
		case Kind::eMat3x4F:
			return m_basicTypes[size_t( Kind::eMat3x4F )];
		case Kind::eMat4x2F:
			return m_basicTypes[size_t( Kind::eMat4x2F )];
		case Kind::eMat4x3F:
			return m_basicTypes[size_t( Kind::eMat4x3F )];
		case Kind::eMat4x4F:
			return m_basicTypes[size_t( Kind::eMat4x4F )];
		case Kind::eMat2x2D:
			return m_basicTypes[size_t( Kind::eMat2x2D )];
		case Kind::eMat2x3D:
			return m_basicTypes[size_t( Kind::eMat2x3D )];
		case Kind::eMat2x4D:
			return m_basicTypes[size_t( Kind::eMat2x4D )];
		case Kind::eMat3x2D:
			return m_basicTypes[size_t( Kind::eMat3x2D )];
		case Kind::eMat3x3D:
			return m_basicTypes[size_t( Kind::eMat3x3D )];
		case Kind::eMat3x4D:
			return m_basicTypes[size_t( Kind::eMat3x4D )];
		case Kind::eMat4x2D:
			return m_basicTypes[size_t( Kind::eMat4x2D )];
		case Kind::eMat4x3D:
			return m_basicTypes[size_t( Kind::eMat4x3D )];
		case Kind::eMat4x4D:
			return m_basicTypes[size_t( Kind::eMat4x4D )];
		case Kind::eAccelerationStructure:
			return m_basicTypes[size_t( Kind::eAccelerationStructure )];
		default:
			AST_Failure( "Unexpected Kind" );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVec2Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec2B();
		case Kind::eInt8:
			return getVec2I8();
		case Kind::eInt16:
			return getVec2I16();
		case Kind::eInt32:
			return getVec2I32();
		case Kind::eInt64:
			return getVec2I64();
		case Kind::eUInt8:
			return getVec2U8();
		case Kind::eUInt16:
			return getVec2U16();
		case Kind::eUInt32:
			return getVec2U32();
		case Kind::eUInt64:
			return getVec2U64();
		case Kind::eHalf:
			return getVec2H();
		case Kind::eFloat:
			return getVec2F();
		case Kind::eDouble:
			return getVec2D();
		default:
			AST_Failure( "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVec3Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec3B();
		case Kind::eInt8:
			return getVec3I8();
		case Kind::eInt16:
			return getVec3I16();
		case Kind::eInt32:
			return getVec3I32();
		case Kind::eInt64:
			return getVec3I64();
		case Kind::eUInt8:
			return getVec3U8();
		case Kind::eUInt16:
			return getVec3U16();
		case Kind::eUInt32:
			return getVec3U32();
		case Kind::eUInt64:
			return getVec3U64();
		case Kind::eFloat:
			return getVec3F();
		case Kind::eDouble:
			return getVec3D();
		default:
			AST_Failure( "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVec4Type( Kind kind )
	{
		switch ( kind )
		{
		case Kind::eBoolean:
			return getVec4B();
		case Kind::eInt8:
			return getVec4I8();
		case Kind::eInt16:
			return getVec4I16();
		case Kind::eInt32:
			return getVec4I32();
		case Kind::eInt64:
			return getVec4I64();
		case Kind::eUInt8:
			return getVec4U8();
		case Kind::eUInt16:
			return getVec4U16();
		case Kind::eUInt32:
			return getVec4U32();
		case Kind::eUInt64:
			return getVec4U64();
		case Kind::eHalf:
			return getVec4H();
		case Kind::eFloat:
			return getVec4F();
		case Kind::eDouble:
			return getVec4D();
		default:
			AST_Failure( "Unsupported component type." );
			return nullptr;
		}
	}

	TypePtr TypesCache::getVector( Kind kind, uint32_t count )
	{
		assert( isScalarType( kind ) );

		switch ( count )
		{
		case 1:
			return getBasicType( kind );
		case 2:
			return getVec2Type( kind );
		case 3:
			return getVec3Type( kind );
		case 4:
			return getVec4Type( kind );
		}

		return nullptr;
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
		switch ( format )
		{
		case ImageFormat::eUnknown:
			return getBasicType( sampledType< ImageFormat::eUnknown > );
		case ImageFormat::eRgba32f:
			return getBasicType( sampledType< ImageFormat::eRgba32f > );
		case ImageFormat::eRgba16f:
			return getBasicType( sampledType< ImageFormat::eRgba16f > );
		case ImageFormat::eRg32f:
			return getBasicType( sampledType< ImageFormat::eRg32f > );
		case ImageFormat::eRg16f:
			return getBasicType( sampledType< ImageFormat::eRg16f > );
		case ImageFormat::eR32f:
			return getBasicType( sampledType< ImageFormat::eR32f > );
		case ImageFormat::eR16f:
			return getBasicType( sampledType< ImageFormat::eR16f > );
		case ImageFormat::eRgba32i:
			return getBasicType( sampledType< ImageFormat::eRgba32i > );
		case ImageFormat::eRgba16i:
			return getBasicType( sampledType< ImageFormat::eRgba16i > );
		case ImageFormat::eRgba8i:
			return getBasicType( sampledType< ImageFormat::eRgba8i > );
		case ImageFormat::eRg32i:
			return getBasicType( sampledType< ImageFormat::eRg32i > );
		case ImageFormat::eRg16i:
			return getBasicType( sampledType< ImageFormat::eRg16i > );
		case ImageFormat::eRg8i:
			return getBasicType( sampledType< ImageFormat::eRg8i > );
		case ImageFormat::eR32i:
			return getBasicType( sampledType< ImageFormat::eR32i > );
		case ImageFormat::eR16i:
			return getBasicType( sampledType< ImageFormat::eR16i > );
		case ImageFormat::eR8i:
			return getBasicType( sampledType< ImageFormat::eR8i > );
		case ImageFormat::eRgba32u:
			return getBasicType( sampledType< ImageFormat::eRgba32u > );
		case ImageFormat::eRgba16u:
			return getBasicType( sampledType< ImageFormat::eRgba16u > );
		case ImageFormat::eRgba8u:
			return getBasicType( sampledType< ImageFormat::eRgba8u > );
		case ImageFormat::eRg32u:
			return getBasicType( sampledType< ImageFormat::eRg32u > );
		case ImageFormat::eRg16u:
			return getBasicType( sampledType< ImageFormat::eRg16u > );
		case ImageFormat::eRg8u:
			return getBasicType( sampledType< ImageFormat::eRg8u > );
		case ImageFormat::eR32u:
			return getBasicType( sampledType< ImageFormat::eR32u > );
		case ImageFormat::eR16u:
			return getBasicType( sampledType< ImageFormat::eR16u > );
		case ImageFormat::eR8u:
			return getBasicType( sampledType< ImageFormat::eR8u > );
		default:
			AST_Failure( "getSampledType: Unsupported ImageFormat" );
			return nullptr;
		}
	}

	TypePtr TypesCache::getTexelType( ImageFormat format )
	{
		switch ( format )
		{
		case ImageFormat::eUnknown:
			return getBasicType( texelType< ImageFormat::eUnknown > );
		case ImageFormat::eRgba32f:
			return getBasicType( texelType< ImageFormat::eRgba32f > );
		case ImageFormat::eRgba16f:
			return getBasicType( texelType< ImageFormat::eRgba16f > );
		case ImageFormat::eRg32f:
			return getBasicType( texelType< ImageFormat::eRg32f > );
		case ImageFormat::eRg16f:
			return getBasicType( texelType< ImageFormat::eRg16f > );
		case ImageFormat::eR32f:
			return getBasicType( texelType< ImageFormat::eR32f > );
		case ImageFormat::eR16f:
			return getBasicType( texelType< ImageFormat::eR16f > );
		case ImageFormat::eRgba32i:
			return getBasicType( texelType< ImageFormat::eRgba32i > );
		case ImageFormat::eRgba16i:
			return getBasicType( texelType< ImageFormat::eRgba16i > );
		case ImageFormat::eRgba8i:
			return getBasicType( texelType< ImageFormat::eRgba8i > );
		case ImageFormat::eRg32i:
			return getBasicType( texelType< ImageFormat::eRg32i > );
		case ImageFormat::eRg16i:
			return getBasicType( texelType< ImageFormat::eRg16i > );
		case ImageFormat::eRg8i:
			return getBasicType( texelType< ImageFormat::eRg8i > );
		case ImageFormat::eR32i:
			return getBasicType( texelType< ImageFormat::eR32i > );
		case ImageFormat::eR16i:
			return getBasicType( texelType< ImageFormat::eR16i > );
		case ImageFormat::eR8i:
			return getBasicType( texelType< ImageFormat::eR8i > );
		case ImageFormat::eRgba32u:
			return getBasicType( texelType< ImageFormat::eRgba32u > );
		case ImageFormat::eRgba16u:
			return getBasicType( texelType< ImageFormat::eRgba16u > );
		case ImageFormat::eRgba8u:
			return getBasicType( texelType< ImageFormat::eRgba8u > );
		case ImageFormat::eRg32u:
			return getBasicType( texelType< ImageFormat::eRg32u > );
		case ImageFormat::eRg16u:
			return getBasicType( texelType< ImageFormat::eRg16u > );
		case ImageFormat::eRg8u:
			return getBasicType( texelType< ImageFormat::eRg8u > );
		case ImageFormat::eR32u:
			return getBasicType( texelType< ImageFormat::eR32u > );
		case ImageFormat::eR16u:
			return getBasicType( texelType< ImageFormat::eR16u > );
		case ImageFormat::eR8u:
			return getBasicType( texelType< ImageFormat::eR8u > );
		default:
			AST_Failure( "getTexelType: Unsupported ImageFormat" );
			return nullptr;
		}
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
			throw std::runtime_error{ "Non I/O structure." };
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
		, uint32_t memberIndex )
	{
		return type->getMemberType( parent, memberIndex );
	}

	Type const * TypesCache::getNonMemberType( TypePtr type )
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
