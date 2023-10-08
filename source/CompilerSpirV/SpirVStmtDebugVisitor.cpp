/*
See LICENSE file in root folder
*/
#include "SpirVStmtDebugVisitor.hpp"

#include "SpirVDebugHelpers.hpp"
#include "SpirVHelpers.hpp"

#include <ShaderAST/Expr/ExprVisitor.hpp>
#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <sstream>
#pragma warning( pop )

namespace spirv
{
	namespace debug
	{
		//*****************************************************************************************

		namespace helpers
		{
			static uint32_t constexpr InvalidIndex = ~( 0u );

			template< typename ValueT >
			static std::string writeValue( ValueT const & v )
			{
				std::stringstream stream;
				stream.imbue( std::locale{ "C" } );
				stream << v;
				return stream.str();
			}

			std::string getTypeArraySize( ast::type::TypePtr type );

			static std::string getTypeArraySize( ast::type::ArrayPtr type )
			{
				std::string result;
				auto arraySize = getArraySize( type );

				if ( arraySize != ast::type::NotArray )
				{
					if ( arraySize == ast::type::UnknownArraySize )
					{
						result += "[]";
					}
					else
					{
						result += "[" + writeValue( arraySize ) + "]";
					}
				}

				return getTypeArraySize( type->getType() ) + result;
			}

			static std::string getDimension( ast::type::ImageDim value )
			{
				switch ( value )
				{
				case ast::type::ImageDim::e1D:
					return "1D";
				case ast::type::ImageDim::e2D:
					return "2D";
				case ast::type::ImageDim::e3D:
					return "3D";
				case ast::type::ImageDim::eCube:
					return "Cube";
				case ast::type::ImageDim::eRect:
					return "2DRect";
				case ast::type::ImageDim::eBuffer:
					return "Buffer";
				default:
					AST_Failure( "Unsupported ast::type::ImageDim" );
					return "Undefined";
				}
			}

			static std::string getPrefix( ast::type::Kind value )
			{
				switch ( value )
				{
				case ast::type::Kind::eInt8:
					return "i8";
				case ast::type::Kind::eInt16:
					return "i16";
				case ast::type::Kind::eInt32:
					return "i";
				case ast::type::Kind::eInt64:
					return "i64";
				case ast::type::Kind::eUInt8:
					return "u8";
				case ast::type::Kind::eUInt16:
					return "u16";
				case ast::type::Kind::eUInt32:
					return "u";
				case ast::type::Kind::eUInt64:
					return "ul";
				case ast::type::Kind::eFloat:
					return std::string{};
				case ast::type::Kind::eHalf:
					return "h";
				default:
					AST_Failure( "Unsupported ast::type::Kind" );
					return std::string{};
				}
			}

			static std::string getArray( bool value )
			{
				return value
					? "Array"
					: std::string{};
			}

			static std::string getMS( bool value )
			{
				return value
					? "MS"
					: std::string{};
			}

			static std::string getType( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config )
			{
				return ( kind == ast::type::Kind::eImage )
					? "image"
					: ( ( kind == ast::type::Kind::eSampledImage )
						? "texture"
						: "sampler" );
			}

			static std::string getShadow( bool isComparison )
			{
				return isComparison
					? "Shadow"
					: std::string{};
			}

			static std::string getShadow( ast::type::Trinary comparison )
			{
				return comparison == ast::type::Trinary::eTrue
					? "Shadow"
					: std::string{};
			}

			std::string getTypeArraySize( ast::type::TypePtr type )
			{
				std::string result;

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					result = getTypeArraySize( std::static_pointer_cast< ast::type::Array >( type ) );
				}

				return result;
			}

			std::string getInterpolationQualifier( ast::var::Variable const & var )
			{
				std::string result;

				if ( var.isFlat() )
				{
					result = "flat";
				}
				else if ( var.isNoPerspective() )
				{
					result = "noperspective";
				}
				else if ( var.isPatchInput()
					|| var.isPatchOutput() )
				{
					result = "patch";
				}
				else if ( var.isCentroid() )
				{
					result = "centroid";
				}
				else if ( var.isPerSample() )
				{
					result = "sample";
				}
				else if ( var.isShared() )
				{
					result = "shared";
				}
				else if ( var.isPerPrimitive() )
				{
					result = "perprimitive";
				}

				return result;
			}

			std::string getLocationName( ast::var::Variable const & var )
			{
				std::string result;

				if ( var.isShaderConstant() )
				{
					result = "constant_id";
				}
				else if ( var.isShaderInput()
					|| var.isShaderOutput()
					|| var.isPatchOutput()
					|| var.isPatchInput() )
				{
					result = "location";
				}

				return result;
			}

			std::string getAccessQualifierName( ast::type::ImageConfiguration const & config )
			{
				std::string result;

				if ( config.accessKind == ast::type::AccessKind::eRead )
				{
					result = "readonly";
				}
				else if ( config.accessKind == ast::type::AccessKind::eWrite )
				{
					result = "writeonly";
				}
				else
				{
					result = "readonly writeonly";
				}

				return result;
			}

			std::string getDirectionName( ast::var::Variable const & var )
			{
				std::string result;

				if ( isOpaqueType( var.getType() ) )
				{
					if ( isImageType( var.getType()->getKind() ) )
					{
						auto & imageType = static_cast< ast::type::Image const & >( *var.getType() );
						return getAccessQualifierName( imageType.getConfig() );
					}

					return result;
				}

				if ( var.isInputParam()
					&& var.isOutputParam() )
				{
					result = "inout";
				}
				else if ( var.isInputParam()
					|| var.isShaderInput()
					|| var.isPatchInput() )
				{
					result = "in";
				}
				else if ( var.isOutputParam()
					|| var.isShaderOutput()
					|| var.isPatchOutput() )
				{
					result = "out";
				}
				else if ( var.isShaderConstant() )
				{
					result = "const";
				}

				return result;
			}

			static std::string getFormatName( ast::type::ImageFormat format )
			{
				switch ( format )
				{
				case ast::type::ImageFormat::eUnknown:
					return "rgba32f";
				case ast::type::ImageFormat::eRgba32f:
					return "rgba32f";
				case ast::type::ImageFormat::eRgba16f:
					return "rgba16f";
				case ast::type::ImageFormat::eRg32f:
					return "rg32f";
				case ast::type::ImageFormat::eRg16f:
					return "rg16f";
				case ast::type::ImageFormat::eR32f:
					return "r32f";
				case ast::type::ImageFormat::eR16f:
					return "r16f";
				case ast::type::ImageFormat::eRgba32i:
					return "rgba32i";
				case ast::type::ImageFormat::eRgba16i:
					return "rgba16i";
				case ast::type::ImageFormat::eRgba8i:
					return "rgba8i";
				case ast::type::ImageFormat::eRg32i:
					return "rg32i";
				case ast::type::ImageFormat::eRg16i:
					return "rg16i";
				case ast::type::ImageFormat::eRg8i:
					return "rg8i";
				case ast::type::ImageFormat::eR32i:
					return "r32i";
				case ast::type::ImageFormat::eR16i:
					return "r16i";
				case ast::type::ImageFormat::eR8i:
					return "r8i";
				case ast::type::ImageFormat::eRgba32u:
					return "rgba32ui";
				case ast::type::ImageFormat::eRgba16u:
					return "rgba16ui";
				case ast::type::ImageFormat::eRgba8u:
					return "rgba8ui";
				case ast::type::ImageFormat::eRg32u:
					return "rg32ui";
				case ast::type::ImageFormat::eRg16u:
					return "rg16ui";
				case ast::type::ImageFormat::eRg8u:
					return "rg8ui";
				case ast::type::ImageFormat::eR32u:
					return "r32ui";
				case ast::type::ImageFormat::eR16u:
					return "r16ui";
				case ast::type::ImageFormat::eR8u:
					return "r8ui";
				default:
					AST_Failure( "Unsupported ast::type::ImageFormat" );
					return "rgba32f";
				}
			}

			static std::string getMemoryLayoutName( ast::type::MemoryLayout layout )
			{
				switch ( layout )
				{
				case ast::type::MemoryLayout::eStd140:
				case ast::type::MemoryLayout::eC:
					return "std140";
				case ast::type::MemoryLayout::eStd430:
					return "std430";
				case ast::type::MemoryLayout::eScalar:
					return "scalar";
				default:
					AST_Failure( "Unsupported ast::type::MemoryLayout" );
					return "std140";
				}
			}

			static std::string getInOutLayout( ast::ShaderStage shaderStage
				, ast::stmt::InOutVariableDecl const & stmt )
			{
				if ( stmt.getVariable()->isBuiltin() )
				{
					return "builtin(" + getName( stmt.getVariable()->getBuiltin() ) + ")";
				}

				std::string result = "layout(";
				std::string sep;

				result += getLocationName( *stmt.getVariable() ) + "=" + writeValue( stmt.getLocation() );
				sep = ", ";

				if ( shaderStage == ast::ShaderStage::eGeometry
					&& stmt.getVariable()->isGeometryStream() )
				{
					result += sep + "stream=" + writeValue( stmt.getStreamIndex() );
					sep = ", ";
				}

				if ( shaderStage == ast::ShaderStage::eFragment
					&& stmt.getVariable()->isBlendIndex() )
				{
					result += sep + "index=" + writeValue( stmt.getBlendIndex() );
				}

				result += ")";

				if ( result == "layout()" )
				{
					result.clear();
				}

				return result;
			}

			static std::string getLayoutName( ast::FragmentOrigin value )
			{
				switch ( value )
				{
				case ast::FragmentOrigin::eLowerLeft:
					return "origin_lower_left";
				case ast::FragmentOrigin::eUpperLeft:
					return "origin_upper_left";
				default:
					AST_Failure( "Unsupported FragmentOrigin" );
					return std::string{};
				}
			}

			static std::string getLayoutName( ast::FragmentCenter value )
			{
				switch ( value )
				{
				case ast::FragmentCenter::eHalfPixel:
					return std::string{};
				case ast::FragmentCenter::eCenterInteger:
					return "pixel_center_integer";
				default:
					AST_Failure( "Unsupported FragmentCenter" );
					return std::string{};
				}
			}

			static std::string getOperatorName( ast::expr::Kind kind )
			{
				std::string result;

				switch ( kind )
				{
				case ast::expr::Kind::eCopy:
					break;
				case ast::expr::Kind::eAdd:
					result = "+";
					break;
				case ast::expr::Kind::eMinus:
					result = "-";
					break;
				case ast::expr::Kind::eTimes:
					result = "*";
					break;
				case ast::expr::Kind::eDivide:
					result = "/";
					break;
				case ast::expr::Kind::eModulo:
					result = "%";
					break;
				case ast::expr::Kind::eLShift:
					result = "<<";
					break;
				case ast::expr::Kind::eRShift:
					result = ">>";
					break;
				case ast::expr::Kind::eBitAnd:
					result = "&";
					break;
				case ast::expr::Kind::eBitNot:
					result = "~";
					break;
				case ast::expr::Kind::eBitOr:
					result = "|";
					break;
				case ast::expr::Kind::eBitXor:
					result = "^";
					break;
				case ast::expr::Kind::eLogAnd:
					result = "&&";
					break;
				case ast::expr::Kind::eLogNot:
					result = "!";
					break;
				case ast::expr::Kind::eLogOr:
					result = "||";
					break;
				case ast::expr::Kind::eCast:
					result = "cast";
					break;
				case ast::expr::Kind::eEqual:
					result = "==";
					break;
				case ast::expr::Kind::eGreater:
					result = ">";
					break;
				case ast::expr::Kind::eGreaterEqual:
					result = ">=";
					break;
				case ast::expr::Kind::eLess:
					result = "<";
					break;
				case ast::expr::Kind::eLessEqual:
					result = "<=";
					break;
				case ast::expr::Kind::eNotEqual:
					result = "!=";
					break;
				case ast::expr::Kind::eComma:
					result = ",";
					break;
				case ast::expr::Kind::eMbrSelect:
					result = ".";
					break;
				case ast::expr::Kind::ePreIncrement:
					result = "++";
					break;
				case ast::expr::Kind::ePreDecrement:
					result = "--";
					break;
				case ast::expr::Kind::ePostIncrement:
					result = "++";
					break;
				case ast::expr::Kind::ePostDecrement:
					result = "--";
					break;
				case ast::expr::Kind::eUnaryMinus:
					result = "-";
					break;
				case ast::expr::Kind::eUnaryPlus:
					result = "+";
					break;
				case ast::expr::Kind::eAssign:
					result = "=";
					break;
				case ast::expr::Kind::eAddAssign:
					result = "+=";
					break;
				case ast::expr::Kind::eMinusAssign:
					result = "-=";
					break;
				case ast::expr::Kind::eTimesAssign:
					result = "*=";
					break;
				case ast::expr::Kind::eDivideAssign:
					result = "/=";
					break;
				case ast::expr::Kind::eModuloAssign:
					result = "%=";
					break;
				case ast::expr::Kind::eLShiftAssign:
					result = "<<=";
					break;
				case ast::expr::Kind::eRShiftAssign:
					result = ">>=";
					break;
				case ast::expr::Kind::eAndAssign:
					result = "&=";
					break;
				case ast::expr::Kind::eNotAssign:
					result = "!=";
					break;
				case ast::expr::Kind::eOrAssign:
					result = "|=";
					break;
				case ast::expr::Kind::eXorAssign:
					result = "^=";
					break;
				default:
					throw std::runtime_error{ "Non operation expression" };
				}

				return result;
			}

			static std::string getLayoutName( ast::type::InputLayout layout )
			{
				std::string result;

				switch ( layout )
				{
				case ast::type::InputLayout::ePointList:
					result = "points";
					break;
				case ast::type::InputLayout::eLineList:
					result = "lines";
					break;
				case ast::type::InputLayout::eLineStrip:
					result = "lines";
					break;
				case ast::type::InputLayout::eTriangleList:
					result = "triangles";
					break;
				case ast::type::InputLayout::eTriangleStrip:
					result = "triangles";
					break;
				case ast::type::InputLayout::eTriangleFan:
					result = "triangles";
					break;
				case ast::type::InputLayout::eLineListWithAdjacency:
					result = "lines_adjacency";
					break;
				case ast::type::InputLayout::eLineStripWithAdjacency:
					result = "lines_adjacency";
					break;
				case ast::type::InputLayout::eTriangleListWithAdjacency:
					result = "triangles_adjacency";
					break;
				case ast::type::InputLayout::eTriangleStripWithAdjacency:
					result = "triangles_adjacency";
					break;
				default:
					throw std::runtime_error{ "Unsupported input layout." };
				}

				return result;
			}

			static std::string getLayoutName( ast::type::OutputLayout layout )
			{
				std::string result;

				switch ( layout )
				{
				case ast::type::OutputLayout::ePointList:
					result = "points";
					break;
				case ast::type::OutputLayout::eLineStrip:
					result = "line_strip";
					break;
				case ast::type::OutputLayout::eTriangleStrip:
					result = "triangle_strip";
					break;
				default:
					throw std::runtime_error{ "Unsupported output layout." };
				}

				return result;
			}

			static std::string getLayoutName( ast::type::PatchDomain value )
			{
				switch ( value )
				{
				case ast::type::PatchDomain::eIsolines:
					return "isolines";
				case ast::type::PatchDomain::eTriangles:
					return "triangles";
				case ast::type::PatchDomain::eQuads:
					return "quads";
				default:
					throw std::runtime_error{ "Unsupported ast::type::PatchDomain." };
				}
			}

			static std::string getLayoutName( ast::type::PrimitiveOrdering value )
			{
				switch ( value )
				{
				case ast::type::PrimitiveOrdering::eCW:
					return "cw";
				case ast::type::PrimitiveOrdering::eCCW:
					return "ccw";
				default:
					throw std::runtime_error{ "Unsupported ast::type::PatchDomain." };
				}
			}

			static std::string getLayoutName( ast::type::Partitioning value )
			{
				switch ( value )
				{
				case ast::type::Partitioning::eEqual:
					return "equal_spacing";
				case ast::type::Partitioning::eFractionalEven:
					return "fractional_even_spacing";
				case ast::type::Partitioning::eFractionalOdd:
					return "fractional_odd_spacing";
				default:
					throw std::runtime_error{ "Unsupported ast::type::Partitioning." };
				}
			}

			static std::string getLayoutName( ast::type::OutputTopology value )
			{
				switch ( value )
				{
				case ast::type::OutputTopology::ePoint:
					return "points";
				case ast::type::OutputTopology::eLine:
					return "lines";
				case ast::type::OutputTopology::eTriangle:
					return "triangles";
				case ast::type::OutputTopology::eQuad:
					return "quads";
				default:
					throw std::runtime_error{ "Unsupported ast::type::OutputTopology." };
				}
			}

			static std::string getQualifiedName( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config )
			{
				return getPrefix( config.sampledType )
					+ getType( kind, config )
					+ getDimension( config.dimension )
					+ getMS( config.isMS )
					+ getArray( config.isArrayed );
			}

			static std::string getQualifiedName( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config
				, bool isComparison )
			{
				return getQualifiedName( kind, config )
					+ getShadow( isComparison );
			}

			static std::string getQualifiedName( ast::type::Kind kind
				, ast::type::ImageConfiguration const & config
				, ast::type::Trinary comparison )
			{
				return getQualifiedName( kind, config )
					+ getShadow( comparison );
			}

			static void join( std::string & lhs
				, std::string const & rhs
				, std::string const & sep )
			{
				if ( lhs.empty() )
				{
					lhs = rhs;
					return;
				}

				if ( rhs.empty() )
				{
					return;
				}

				lhs = lhs + sep + rhs;
			}

			static bool isUnaryPre( ast::expr::Kind kind )
			{
				bool result;

				switch ( kind )
				{
				case ast::expr::Kind::eMbrSelect:
				case ast::expr::Kind::ePostIncrement:
				case ast::expr::Kind::ePostDecrement:
					result = false;
					break;
				case ast::expr::Kind::eBitNot:
				case ast::expr::Kind::eLogNot:
				case ast::expr::Kind::eCast:
				case ast::expr::Kind::eCopy:
				case ast::expr::Kind::ePreIncrement:
				case ast::expr::Kind::ePreDecrement:
				case ast::expr::Kind::eUnaryMinus:
				case ast::expr::Kind::eUnaryPlus:
					result = true;
					break;
				default:
					throw std::runtime_error{ "Non unary expression" };
				}

				return result;
			}

			static std::string getCtorName( ast::expr::Expr const & image
				, ast::expr::Expr const & sampler )
			{
				if ( image.getType()->getKind() == ast::type::Kind::eSampledImage
					&& sampler.getType()->getKind() == ast::type::Kind::eSampler )
				{
					auto & config = static_cast< ast::type::SampledImage const & >( *image.getType() ).getConfig();
					auto isComparison = static_cast< ast::type::Sampler const & >( *sampler.getType() ).isComparison();
					return getPrefix( config.sampledType )
						+ getType( ast::type::Kind::eSampler, config )
						+ getDimension( config.dimension )
						+ getMS( config.isMS )
						+ getArray( config.isArrayed )
						+ getShadow( isComparison );
				}

				return "combine";
			}

			static std::string getCtorName( ast::expr::CompositeType composite
				, ast::type::Kind component )
			{
				std::string result;

				switch ( composite )
				{
				case ast::expr::CompositeType::eVec2:
					switch ( component )
					{
					case ast::type::Kind::eBoolean:
						result = "bvec2";
						break;
					case ast::type::Kind::eInt8:
						result = "i8vec2";
						break;
					case ast::type::Kind::eInt16:
						result = "i16vec2";
						break;
					case ast::type::Kind::eInt32:
						result = "ivec2";
						break;
					case ast::type::Kind::eInt64:
						result = "i64vec2";
						break;
					case ast::type::Kind::eUInt8:
						result = "u8vec2";
						break;
					case ast::type::Kind::eUInt16:
						result = "u16vec2";
						break;
					case ast::type::Kind::eUInt32:
						result = "uvec2";
						break;
					case ast::type::Kind::eUInt64:
						result = "u64vec2";
						break;
					case ast::type::Kind::eFloat:
						result = "vec2";
						break;
					case ast::type::Kind::eDouble:
						result = "dvec2";
						break;
					case ast::type::Kind::eHalf:
						result = "f16vec2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eVec3:
					switch ( component )
					{
					case ast::type::Kind::eBoolean:
						result = "bvec3";
						break;
					case ast::type::Kind::eInt8:
						result = "i8vec3";
						break;
					case ast::type::Kind::eInt16:
						result = "i16vec3";
						break;
					case ast::type::Kind::eInt32:
						result = "ivec3";
						break;
					case ast::type::Kind::eInt64:
						result = "i64vec3";
						break;
					case ast::type::Kind::eUInt8:
						result = "u8vec3";
						break;
					case ast::type::Kind::eUInt16:
						result = "u16vec3";
						break;
					case ast::type::Kind::eUInt32:
						result = "uvec3";
						break;
					case ast::type::Kind::eUInt64:
						result = "u64vec3";
						break;
					case ast::type::Kind::eFloat:
						result = "vec3";
						break;
					case ast::type::Kind::eDouble:
						result = "dvec3";
						break;
					case ast::type::Kind::eHalf:
						result = "f16vec3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eVec4:
					switch ( component )
					{
					case ast::type::Kind::eBoolean:
						result = "bvec4";
						break;
					case ast::type::Kind::eInt8:
						result = "i8vec4";
						break;
					case ast::type::Kind::eInt16:
						result = "i16vec4";
						break;
					case ast::type::Kind::eInt32:
						result = "ivec4";
						break;
					case ast::type::Kind::eInt64:
						result = "i64vec4";
						break;
					case ast::type::Kind::eUInt8:
						result = "u8vec4";
						break;
					case ast::type::Kind::eUInt16:
						result = "u16vec4";
						break;
					case ast::type::Kind::eUInt32:
						result = "uvec4";
						break;
					case ast::type::Kind::eUInt64:
						result = "u64vec4";
						break;
					case ast::type::Kind::eFloat:
						result = "vec4";
						break;
					case ast::type::Kind::eDouble:
						result = "dvec4";
						break;
					case ast::type::Kind::eHalf:
						result = "f16vec4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat2x2:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat2";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat2x3:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat2x3";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat2x3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat2x4:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat2x4";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat2x4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat3x2:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat3x2";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat3x2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat3x3:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat3";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat3x4:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat3x4";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat3x4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat4x2:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat4x2";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat4x2";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat4x3:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat4x3";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat4x3";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eMat4x4:
					switch ( component )
					{
					case ast::type::Kind::eFloat:
						result = "mat4";
						break;
					case ast::type::Kind::eDouble:
						result = "dmat4";
						break;
					default:
						AST_Failure( "Unsupported type::Kind" );
						break;
					}
					break;
				case ast::expr::CompositeType::eCombine:
					result = "combine";
					break;
				default:
					AST_Failure( "Unsupported expr::CompositeType" );
					break;
				}

				return result;
			}

			static bool checkBufferMemoryBarrier( ast::type::MemorySemantics semantics )
			{
				return ( semantics & ast::type::MemorySemanticsMask::eUniformMemory ) == ast::type::MemorySemanticsMask::eUniformMemory;
			}

			static bool checkSharedMemoryBarrier( ast::type::MemorySemantics semantics )
			{
				return ( semantics & ast::type::MemorySemanticsMask::eWorkgroupMemory ) == ast::type::MemorySemanticsMask::eWorkgroupMemory;
			}

			static bool checkImageMemoryBarrier( ast::type::MemorySemantics semantics )
			{
				return ( semantics & ast::type::MemorySemanticsMask::eImageMemory ) == ast::type::MemorySemanticsMask::eImageMemory;
			}

			static bool checkAllMemoryBarrier( ast::type::MemorySemantics semantics )
			{
				return checkBufferMemoryBarrier( semantics ) && checkSharedMemoryBarrier( semantics ) && checkImageMemoryBarrier( semantics );
			}

			static bool checkAnyMemoryBarrier( ast::type::MemorySemantics semantics )
			{
				return checkBufferMemoryBarrier( semantics ) || checkSharedMemoryBarrier( semantics ) || checkImageMemoryBarrier( semantics );
			}

			static std::string getIntrinsicName( ast::expr::CombinedImageAccess value )
			{
				std::string result;

				switch ( value )
				{
			// Texture Query Functions
				case ast::expr::CombinedImageAccess::eTextureSize1DF:
				case ast::expr::CombinedImageAccess::eTextureSize2DF:
				case ast::expr::CombinedImageAccess::eTextureSize3DF:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeF:
				case ast::expr::CombinedImageAccess::eTextureSize1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureSize2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureSize2DRectF:
				case ast::expr::CombinedImageAccess::eTextureSize2DRectShadowF:
				case ast::expr::CombinedImageAccess::eTextureSize1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureSize2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureSize1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureSize2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureSizeBufferF:
				case ast::expr::CombinedImageAccess::eTextureSize1DI:
				case ast::expr::CombinedImageAccess::eTextureSize2DI:
				case ast::expr::CombinedImageAccess::eTextureSize3DI:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeI:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureSize2DRectI:
				case ast::expr::CombinedImageAccess::eTextureSize1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureSize2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureSizeBufferI:
				case ast::expr::CombinedImageAccess::eTextureSize1DU:
				case ast::expr::CombinedImageAccess::eTextureSize2DU:
				case ast::expr::CombinedImageAccess::eTextureSize3DU:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeU:
				case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayU:
				case ast::expr::CombinedImageAccess::eTextureSize2DRectU:
				case ast::expr::CombinedImageAccess::eTextureSize1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureSize2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureSizeBufferU:
					result = "textureSize";
					break;

				case ast::expr::CombinedImageAccess::eTextureQueryLod1DF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod3DF:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLod1DI:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DI:
				case ast::expr::CombinedImageAccess::eTextureQueryLod3DI:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeI:
				case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureQueryLod1DU:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DU:
				case ast::expr::CombinedImageAccess::eTextureQueryLod3DU:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeU:
				case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU:
					result = "textureQueryLod";
					break;

				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels3DF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DI:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DI:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels3DI:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeI:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DU:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DU:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels3DU:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeU:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU:
					result = "textureQueryLevels";
					break;


			// Texel Lookup Functions
				case ast::expr::CombinedImageAccess::eTexture1DF:
				case ast::expr::CombinedImageAccess::eTexture1DFBias:
				case ast::expr::CombinedImageAccess::eTexture2DF:
				case ast::expr::CombinedImageAccess::eTexture2DFBias:
				case ast::expr::CombinedImageAccess::eTexture3DF:
				case ast::expr::CombinedImageAccess::eTexture3DFBias:
				case ast::expr::CombinedImageAccess::eTextureCubeF:
				case ast::expr::CombinedImageAccess::eTextureCubeFBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayF:
				case ast::expr::CombinedImageAccess::eTexture1DArrayFBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayF:
				case ast::expr::CombinedImageAccess::eTexture2DArrayFBias:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayFBias:
				case ast::expr::CombinedImageAccess::eTexture2DRectF:
				case ast::expr::CombinedImageAccess::eTexture1DI:
				case ast::expr::CombinedImageAccess::eTexture1DIBias:
				case ast::expr::CombinedImageAccess::eTexture2DI:
				case ast::expr::CombinedImageAccess::eTexture2DIBias:
				case ast::expr::CombinedImageAccess::eTexture3DI:
				case ast::expr::CombinedImageAccess::eTexture3DIBias:
				case ast::expr::CombinedImageAccess::eTextureCubeI:
				case ast::expr::CombinedImageAccess::eTextureCubeIBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayI:
				case ast::expr::CombinedImageAccess::eTexture1DArrayIBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayI:
				case ast::expr::CombinedImageAccess::eTexture2DArrayIBias:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayIBias:
				case ast::expr::CombinedImageAccess::eTexture2DRectI:
				case ast::expr::CombinedImageAccess::eTexture1DU:
				case ast::expr::CombinedImageAccess::eTexture1DUBias:
				case ast::expr::CombinedImageAccess::eTexture2DU:
				case ast::expr::CombinedImageAccess::eTexture2DUBias:
				case ast::expr::CombinedImageAccess::eTexture3DU:
				case ast::expr::CombinedImageAccess::eTexture3DUBias:
				case ast::expr::CombinedImageAccess::eTextureCubeU:
				case ast::expr::CombinedImageAccess::eTextureCubeUBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayU:
				case ast::expr::CombinedImageAccess::eTexture1DArrayUBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayU:
				case ast::expr::CombinedImageAccess::eTexture2DArrayUBias:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayU:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayUBias:
				case ast::expr::CombinedImageAccess::eTexture2DRectU:
					result = "texture";
					break;

				case ast::expr::CombinedImageAccess::eTextureProj1DF2:
				case ast::expr::CombinedImageAccess::eTextureProj1DF2Bias:
				case ast::expr::CombinedImageAccess::eTextureProj1DF4:
				case ast::expr::CombinedImageAccess::eTextureProj1DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DF3:
				case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DF4:
				case ast::expr::CombinedImageAccess::eTextureProj2DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj3DF:
				case ast::expr::CombinedImageAccess::eTextureProj3DFBias:
				case ast::expr::CombinedImageAccess::eTextureProj2DRectF3:
				case ast::expr::CombinedImageAccess::eTextureProj2DRectF4:
				case ast::expr::CombinedImageAccess::eTextureProj1DI2:
				case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
				case ast::expr::CombinedImageAccess::eTextureProj1DI4:
				case ast::expr::CombinedImageAccess::eTextureProj1DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DI3:
				case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DI4:
				case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj3DI:
				case ast::expr::CombinedImageAccess::eTextureProj3DIBias:
				case ast::expr::CombinedImageAccess::eTextureProj2DRectI3:
				case ast::expr::CombinedImageAccess::eTextureProj2DRectI4:
				case ast::expr::CombinedImageAccess::eTextureProj1DU2:
				case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
				case ast::expr::CombinedImageAccess::eTextureProj1DU4:
				case ast::expr::CombinedImageAccess::eTextureProj1DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DU3:
				case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DU4:
				case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj3DU:
				case ast::expr::CombinedImageAccess::eTextureProj3DUBias:
				case ast::expr::CombinedImageAccess::eTextureProj2DRectU3:
				case ast::expr::CombinedImageAccess::eTextureProj2DRectU4:
					result = "textureProj";
					break;

				case ast::expr::CombinedImageAccess::eTextureLod1DF:
				case ast::expr::CombinedImageAccess::eTextureLod2DF:
				case ast::expr::CombinedImageAccess::eTextureLod3DF:
				case ast::expr::CombinedImageAccess::eTextureLodCubeF:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLod2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLodCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureLod1DI:
				case ast::expr::CombinedImageAccess::eTextureLod2DI:
				case ast::expr::CombinedImageAccess::eTextureLod3DI:
				case ast::expr::CombinedImageAccess::eTextureLodCubeI:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLod2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLodCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureLod1DU:
				case ast::expr::CombinedImageAccess::eTextureLod2DU:
				case ast::expr::CombinedImageAccess::eTextureLod3DU:
				case ast::expr::CombinedImageAccess::eTextureLodCubeU:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureLod2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureLodCubeArrayU:
					result = "textureLod";
					break;

				case ast::expr::CombinedImageAccess::eTextureOffset1DF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureOffset3DFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DRectF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DI:
				case ast::expr::CombinedImageAccess::eTextureOffset1DIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureOffset2DIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureOffset3DIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DRectI:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DU:
				case ast::expr::CombinedImageAccess::eTextureOffset1DUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureOffset2DUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureOffset3DUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DRectU:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayUBias:
					result = "textureOffset";
					break;

				case ast::expr::CombinedImageAccess::eTexelFetch1DF:
				case ast::expr::CombinedImageAccess::eTexelFetch2DF:
				case ast::expr::CombinedImageAccess::eTexelFetch3DF:
				case ast::expr::CombinedImageAccess::eTexelFetch2DRectF:
				case ast::expr::CombinedImageAccess::eTexelFetch1DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetch2DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetchBufferF:
				case ast::expr::CombinedImageAccess::eTexelFetch1DI:
				case ast::expr::CombinedImageAccess::eTexelFetch2DI:
				case ast::expr::CombinedImageAccess::eTexelFetch3DI:
				case ast::expr::CombinedImageAccess::eTexelFetch2DRectI:
				case ast::expr::CombinedImageAccess::eTexelFetch1DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetch2DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetchBufferI:
				case ast::expr::CombinedImageAccess::eTexelFetch1DU:
				case ast::expr::CombinedImageAccess::eTexelFetch2DU:
				case ast::expr::CombinedImageAccess::eTexelFetch3DU:
				case ast::expr::CombinedImageAccess::eTexelFetch2DRectU:
				case ast::expr::CombinedImageAccess::eTexelFetch1DArrayU:
				case ast::expr::CombinedImageAccess::eTexelFetch2DArrayU:
				case ast::expr::CombinedImageAccess::eTexelFetchBufferU:
					result = "texelFetch";
					break;

				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset3DF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset3DI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset3DU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayU:
					result = "texelFetchOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DFBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DIBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DUBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU4:
					result = "textureProjOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureLodOffset1DF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayU:
					result = "textureLodOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjLod1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLod3DF:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLod3DI:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLod3DU:
					result = "textureProjLod";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DU:
					result = "textureProjLodOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureGrad1DF:
				case ast::expr::CombinedImageAccess::eTextureGrad2DF:
				case ast::expr::CombinedImageAccess::eTextureGrad3DF:
				case ast::expr::CombinedImageAccess::eTextureGradCubeF:
				case ast::expr::CombinedImageAccess::eTextureGrad2DRectF:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGrad2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGradCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureGrad1DI:
				case ast::expr::CombinedImageAccess::eTextureGrad2DI:
				case ast::expr::CombinedImageAccess::eTextureGrad3DI:
				case ast::expr::CombinedImageAccess::eTextureGradCubeI:
				case ast::expr::CombinedImageAccess::eTextureGrad2DRectI:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGrad2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGradCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureGrad1DU:
				case ast::expr::CombinedImageAccess::eTextureGrad2DU:
				case ast::expr::CombinedImageAccess::eTextureGrad3DU:
				case ast::expr::CombinedImageAccess::eTextureGradCubeU:
				case ast::expr::CombinedImageAccess::eTextureGrad2DRectU:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGrad2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGradCubeArrayU:
					result = "textureGrad";
					break;

				case ast::expr::CombinedImageAccess::eTextureGradOffset1DF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayU:
					result = "textureGradOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjGrad1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad3DF:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad3DI:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad3DU:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU4:
					result = "textureProjGrad";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU4:
					result = "textureProjGradOffset";
					break;


			// Texel Compare Functions
				case ast::expr::CombinedImageAccess::eTexture1DShadowF:
				case ast::expr::CombinedImageAccess::eTexture1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTexture2DShadowF:
				case ast::expr::CombinedImageAccess::eTexture2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureCubeShadowFBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTexture1DArrayShadowFBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTexture2DRectShadowF:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayShadowF:
					result = "texture";
					break;

				case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProj2DRectShadowF:
					result = "textureProj";
					break;

				case ast::expr::CombinedImageAccess::eTextureLod1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLod2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
					result = "textureLod";
					break;

				case ast::expr::CombinedImageAccess::eTextureOffset2DRectShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
					result = "textureOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectShadowF:
					result = "textureProjOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
					result = "textureLodOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
					result = "textureProjLod";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
					result = "textureProjLodOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureGrad2DRectShadowF:
				case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
					result = "textureGrad";
					break;

				case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
					result = "textureGradOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectShadowF:
					result = "textureProjGrad";
					break;

				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectShadowF:
					result = "textureProjGradOffset";
					break;


			// Texture Gather Functions
				case ast::expr::CombinedImageAccess::eTextureGather2DF:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureGather2DRectF:
				case ast::expr::CombinedImageAccess::eTextureGather2DI:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeI:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureGather2DRectI:
				case ast::expr::CombinedImageAccess::eTextureGather2DU:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeU:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayU:
				case ast::expr::CombinedImageAccess::eTextureGather2DRectU:
					result = "textureGather";
					break;

				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectU:
					result = "textureGatherOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectU:
					result = "textureGatherOffsets";
					break;


			// Texture Gather Compare Functions
				case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGather2DRectShadowF:
					result = "textureGather";
					break;

				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectShadowF:
					result = "textureGatherOffset";
					break;

				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectShadowF:
					result = "textureGatherOffsets";
					break;

				default:
					throw std::runtime_error{ "Unsupported CombinedImageAccess type." };
				}

				return result;
			}

			static std::string getIntrinsicName( ast::expr::Intrinsic value )
			{
				std::string result;

				switch ( value )
				{
			// Angle and Trigonometry Functions
				case ast::expr::Intrinsic::eDegrees1:
				case ast::expr::Intrinsic::eDegrees2:
				case ast::expr::Intrinsic::eDegrees3:
				case ast::expr::Intrinsic::eDegrees4:
					result = "degrees";
					break;

				case ast::expr::Intrinsic::eRadians1F:
				case ast::expr::Intrinsic::eRadians2F:
				case ast::expr::Intrinsic::eRadians3F:
				case ast::expr::Intrinsic::eRadians4F:
					result = "radians";
					break;

				case ast::expr::Intrinsic::eCos1:
				case ast::expr::Intrinsic::eCos2:
				case ast::expr::Intrinsic::eCos3:
				case ast::expr::Intrinsic::eCos4:
					result = "cos";
					break;

				case ast::expr::Intrinsic::eSin1:
				case ast::expr::Intrinsic::eSin2:
				case ast::expr::Intrinsic::eSin3:
				case ast::expr::Intrinsic::eSin4:
					result = "sin";
					break;

				case ast::expr::Intrinsic::eTan1:
				case ast::expr::Intrinsic::eTan2:
				case ast::expr::Intrinsic::eTan3:
				case ast::expr::Intrinsic::eTan4:
					result = "tan";
					break;

				case ast::expr::Intrinsic::eCosh1:
				case ast::expr::Intrinsic::eCosh2:
				case ast::expr::Intrinsic::eCosh3:
				case ast::expr::Intrinsic::eCosh4:
					result = "cosh";
					break;

				case ast::expr::Intrinsic::eSinh1:
				case ast::expr::Intrinsic::eSinh2:
				case ast::expr::Intrinsic::eSinh3:
				case ast::expr::Intrinsic::eSinh4:
					result = "sinh";
					break;

				case ast::expr::Intrinsic::eTanh1:
				case ast::expr::Intrinsic::eTanh2:
				case ast::expr::Intrinsic::eTanh3:
				case ast::expr::Intrinsic::eTanh4:
					result = "tanh";
					break;

				case ast::expr::Intrinsic::eAcos1:
				case ast::expr::Intrinsic::eAcos2:
				case ast::expr::Intrinsic::eAcos3:
				case ast::expr::Intrinsic::eAcos4:
					result = "acos";
					break;

				case ast::expr::Intrinsic::eAsin1:
				case ast::expr::Intrinsic::eAsin2:
				case ast::expr::Intrinsic::eAsin3:
				case ast::expr::Intrinsic::eAsin4:
					result = "asin";
					break;

				case ast::expr::Intrinsic::eAtan1:
				case ast::expr::Intrinsic::eAtan2:
				case ast::expr::Intrinsic::eAtan3:
				case ast::expr::Intrinsic::eAtan4:
				case ast::expr::Intrinsic::eAtan21:
				case ast::expr::Intrinsic::eAtan22:
				case ast::expr::Intrinsic::eAtan23:
				case ast::expr::Intrinsic::eAtan24:
					result = "atan";
					break;

				case ast::expr::Intrinsic::eAcosh1:
				case ast::expr::Intrinsic::eAcosh2:
				case ast::expr::Intrinsic::eAcosh3:
				case ast::expr::Intrinsic::eAcosh4:
					result = "acosh";
					break;

				case ast::expr::Intrinsic::eAsinh1:
				case ast::expr::Intrinsic::eAsinh2:
				case ast::expr::Intrinsic::eAsinh3:
				case ast::expr::Intrinsic::eAsinh4:
					result = "asinh";
					break;

				case ast::expr::Intrinsic::eAtanh1:
				case ast::expr::Intrinsic::eAtanh2:
				case ast::expr::Intrinsic::eAtanh3:
				case ast::expr::Intrinsic::eAtanh4:
					result = "atanh";
					break;


			// Exponential Functions
				case ast::expr::Intrinsic::ePow1:
				case ast::expr::Intrinsic::ePow2:
				case ast::expr::Intrinsic::ePow3:
				case ast::expr::Intrinsic::ePow4:
					result = "pow";
					break;

				case ast::expr::Intrinsic::eExp1:
				case ast::expr::Intrinsic::eExp2:
				case ast::expr::Intrinsic::eExp3:
				case ast::expr::Intrinsic::eExp4:
					result = "exp";
					break;

				case ast::expr::Intrinsic::eLog1:
				case ast::expr::Intrinsic::eLog2:
				case ast::expr::Intrinsic::eLog3:
				case ast::expr::Intrinsic::eLog4:
					result = "log";
					break;

				case ast::expr::Intrinsic::eExp21:
				case ast::expr::Intrinsic::eExp22:
				case ast::expr::Intrinsic::eExp23:
				case ast::expr::Intrinsic::eExp24:
					result = "exp2";
					break;

				case ast::expr::Intrinsic::eLog21:
				case ast::expr::Intrinsic::eLog22:
				case ast::expr::Intrinsic::eLog23:
				case ast::expr::Intrinsic::eLog24:
					result = "log2";
					break;

				case ast::expr::Intrinsic::eSqrt1F:
				case ast::expr::Intrinsic::eSqrt2F:
				case ast::expr::Intrinsic::eSqrt3F:
				case ast::expr::Intrinsic::eSqrt4F:
				case ast::expr::Intrinsic::eSqrt1D:
				case ast::expr::Intrinsic::eSqrt2D:
				case ast::expr::Intrinsic::eSqrt3D:
				case ast::expr::Intrinsic::eSqrt4D:
					result = "sqrt";
					break;

				case ast::expr::Intrinsic::eInverseSqrt1F:
				case ast::expr::Intrinsic::eInverseSqrt2F:
				case ast::expr::Intrinsic::eInverseSqrt3F:
				case ast::expr::Intrinsic::eInverseSqrt4F:
				case ast::expr::Intrinsic::eInverseSqrt1D:
				case ast::expr::Intrinsic::eInverseSqrt2D:
				case ast::expr::Intrinsic::eInverseSqrt3D:
				case ast::expr::Intrinsic::eInverseSqrt4D:
					result = "inversesqrt";
					break;


			// Common Functions
				case ast::expr::Intrinsic::eAbs1F:
				case ast::expr::Intrinsic::eAbs2F:
				case ast::expr::Intrinsic::eAbs3F:
				case ast::expr::Intrinsic::eAbs4F:
				case ast::expr::Intrinsic::eAbs1I:
				case ast::expr::Intrinsic::eAbs2I:
				case ast::expr::Intrinsic::eAbs3I:
				case ast::expr::Intrinsic::eAbs4I:
				case ast::expr::Intrinsic::eAbs1D:
				case ast::expr::Intrinsic::eAbs2D:
				case ast::expr::Intrinsic::eAbs3D:
				case ast::expr::Intrinsic::eAbs4D:
					result = "abs";
					break;

				case ast::expr::Intrinsic::eSign1F:
				case ast::expr::Intrinsic::eSign2F:
				case ast::expr::Intrinsic::eSign3F:
				case ast::expr::Intrinsic::eSign4F:
				case ast::expr::Intrinsic::eSign1I:
				case ast::expr::Intrinsic::eSign2I:
				case ast::expr::Intrinsic::eSign3I:
				case ast::expr::Intrinsic::eSign4I:
				case ast::expr::Intrinsic::eSign1D:
				case ast::expr::Intrinsic::eSign2D:
				case ast::expr::Intrinsic::eSign3D:
				case ast::expr::Intrinsic::eSign4D:
					result = "sign";
					break;

				case ast::expr::Intrinsic::eFloor1F:
				case ast::expr::Intrinsic::eFloor2F:
				case ast::expr::Intrinsic::eFloor3F:
				case ast::expr::Intrinsic::eFloor4F:
				case ast::expr::Intrinsic::eFloor1D:
				case ast::expr::Intrinsic::eFloor2D:
				case ast::expr::Intrinsic::eFloor3D:
				case ast::expr::Intrinsic::eFloor4D:
					result = "floor";
					break;

				case ast::expr::Intrinsic::eTrunc1F:
				case ast::expr::Intrinsic::eTrunc2F:
				case ast::expr::Intrinsic::eTrunc3F:
				case ast::expr::Intrinsic::eTrunc4F:
				case ast::expr::Intrinsic::eTrunc1D:
				case ast::expr::Intrinsic::eTrunc2D:
				case ast::expr::Intrinsic::eTrunc3D:
				case ast::expr::Intrinsic::eTrunc4D:
					result = "trunc";
					break;

				case ast::expr::Intrinsic::eRound1F:
				case ast::expr::Intrinsic::eRound2F:
				case ast::expr::Intrinsic::eRound3F:
				case ast::expr::Intrinsic::eRound4F:
				case ast::expr::Intrinsic::eRound1D:
				case ast::expr::Intrinsic::eRound2D:
				case ast::expr::Intrinsic::eRound3D:
				case ast::expr::Intrinsic::eRound4D:
					result = "round";
					break;

				case ast::expr::Intrinsic::eRoundEven1F:
				case ast::expr::Intrinsic::eRoundEven2F:
				case ast::expr::Intrinsic::eRoundEven3F:
				case ast::expr::Intrinsic::eRoundEven4F:
				case ast::expr::Intrinsic::eRoundEven1D:
				case ast::expr::Intrinsic::eRoundEven2D:
				case ast::expr::Intrinsic::eRoundEven3D:
				case ast::expr::Intrinsic::eRoundEven4D:
					result = "roundEven";
					break;

				case ast::expr::Intrinsic::eCeil1F:
				case ast::expr::Intrinsic::eCeil2F:
				case ast::expr::Intrinsic::eCeil3F:
				case ast::expr::Intrinsic::eCeil4F:
				case ast::expr::Intrinsic::eCeil1D:
				case ast::expr::Intrinsic::eCeil2D:
				case ast::expr::Intrinsic::eCeil3D:
				case ast::expr::Intrinsic::eCeil4D:
					result = "ceil";
					break;

				case ast::expr::Intrinsic::eFract1F:
				case ast::expr::Intrinsic::eFract2F:
				case ast::expr::Intrinsic::eFract3F:
				case ast::expr::Intrinsic::eFract4F:
				case ast::expr::Intrinsic::eFract1D:
				case ast::expr::Intrinsic::eFract2D:
				case ast::expr::Intrinsic::eFract3D:
				case ast::expr::Intrinsic::eFract4D:
					result = "fract";
					break;

				case ast::expr::Intrinsic::eMod1F:
				case ast::expr::Intrinsic::eMod2F:
				case ast::expr::Intrinsic::eMod3F:
				case ast::expr::Intrinsic::eMod4F:
				case ast::expr::Intrinsic::eMod1D:
				case ast::expr::Intrinsic::eMod2D:
				case ast::expr::Intrinsic::eMod3D:
				case ast::expr::Intrinsic::eMod4D:
					result = "mod";
					break;

				case ast::expr::Intrinsic::eModf1F:
				case ast::expr::Intrinsic::eModf2F:
				case ast::expr::Intrinsic::eModf3F:
				case ast::expr::Intrinsic::eModf4F:
				case ast::expr::Intrinsic::eModf1D:
				case ast::expr::Intrinsic::eModf2D:
				case ast::expr::Intrinsic::eModf3D:
				case ast::expr::Intrinsic::eModf4D:
					result = "modf";
					break;

				case ast::expr::Intrinsic::eMin1F:
				case ast::expr::Intrinsic::eMin2F:
				case ast::expr::Intrinsic::eMin3F:
				case ast::expr::Intrinsic::eMin4F:
				case ast::expr::Intrinsic::eMin1D:
				case ast::expr::Intrinsic::eMin2D:
				case ast::expr::Intrinsic::eMin3D:
				case ast::expr::Intrinsic::eMin4D:
				case ast::expr::Intrinsic::eMin1I:
				case ast::expr::Intrinsic::eMin2I:
				case ast::expr::Intrinsic::eMin3I:
				case ast::expr::Intrinsic::eMin4I:
				case ast::expr::Intrinsic::eMin1U:
				case ast::expr::Intrinsic::eMin2U:
				case ast::expr::Intrinsic::eMin3U:
				case ast::expr::Intrinsic::eMin4U:
					result = "min";
					break;

				case ast::expr::Intrinsic::eMax1F:
				case ast::expr::Intrinsic::eMax2F:
				case ast::expr::Intrinsic::eMax3F:
				case ast::expr::Intrinsic::eMax4F:
				case ast::expr::Intrinsic::eMax1D:
				case ast::expr::Intrinsic::eMax2D:
				case ast::expr::Intrinsic::eMax3D:
				case ast::expr::Intrinsic::eMax4D:
				case ast::expr::Intrinsic::eMax1I:
				case ast::expr::Intrinsic::eMax2I:
				case ast::expr::Intrinsic::eMax3I:
				case ast::expr::Intrinsic::eMax4I:
				case ast::expr::Intrinsic::eMax1U:
				case ast::expr::Intrinsic::eMax2U:
				case ast::expr::Intrinsic::eMax3U:
				case ast::expr::Intrinsic::eMax4U:
					result = "max";
					break;

				case ast::expr::Intrinsic::eClamp1F:
				case ast::expr::Intrinsic::eClamp2F:
				case ast::expr::Intrinsic::eClamp3F:
				case ast::expr::Intrinsic::eClamp4F:
				case ast::expr::Intrinsic::eClamp1D:
				case ast::expr::Intrinsic::eClamp2D:
				case ast::expr::Intrinsic::eClamp3D:
				case ast::expr::Intrinsic::eClamp4D:
				case ast::expr::Intrinsic::eClamp1I:
				case ast::expr::Intrinsic::eClamp2I:
				case ast::expr::Intrinsic::eClamp3I:
				case ast::expr::Intrinsic::eClamp4I:
				case ast::expr::Intrinsic::eClamp1U:
				case ast::expr::Intrinsic::eClamp2U:
				case ast::expr::Intrinsic::eClamp3U:
				case ast::expr::Intrinsic::eClamp4U:
					result = "clamp";
					break;

				case ast::expr::Intrinsic::eMix1F:
				case ast::expr::Intrinsic::eMix2F:
				case ast::expr::Intrinsic::eMix3F:
				case ast::expr::Intrinsic::eMix4F:
				case ast::expr::Intrinsic::eMix1D:
				case ast::expr::Intrinsic::eMix2D:
				case ast::expr::Intrinsic::eMix3D:
				case ast::expr::Intrinsic::eMix4D:
					result = "mix";
					break;

				case ast::expr::Intrinsic::eStep1F:
				case ast::expr::Intrinsic::eStep2F:
				case ast::expr::Intrinsic::eStep3F:
				case ast::expr::Intrinsic::eStep4F:
				case ast::expr::Intrinsic::eStep1D:
				case ast::expr::Intrinsic::eStep2D:
				case ast::expr::Intrinsic::eStep3D:
				case ast::expr::Intrinsic::eStep4D:
					result = "step";
					break;

				case ast::expr::Intrinsic::eSmoothStep1F:
				case ast::expr::Intrinsic::eSmoothStep2F:
				case ast::expr::Intrinsic::eSmoothStep3F:
				case ast::expr::Intrinsic::eSmoothStep4F:
				case ast::expr::Intrinsic::eSmoothStep1D:
				case ast::expr::Intrinsic::eSmoothStep2D:
				case ast::expr::Intrinsic::eSmoothStep3D:
				case ast::expr::Intrinsic::eSmoothStep4D:
					result = "smoothstep";
					break;

				case ast::expr::Intrinsic::eIsnan1F:
				case ast::expr::Intrinsic::eIsnan2F:
				case ast::expr::Intrinsic::eIsnan3F:
				case ast::expr::Intrinsic::eIsnan4F:
				case ast::expr::Intrinsic::eIsnan1D:
				case ast::expr::Intrinsic::eIsnan2D:
				case ast::expr::Intrinsic::eIsnan3D:
				case ast::expr::Intrinsic::eIsnan4D:
					result = "isnan";
					break;

				case ast::expr::Intrinsic::eIsinf1F:
				case ast::expr::Intrinsic::eIsinf2F:
				case ast::expr::Intrinsic::eIsinf3F:
				case ast::expr::Intrinsic::eIsinf4F:
				case ast::expr::Intrinsic::eIsinf1D:
				case ast::expr::Intrinsic::eIsinf2D:
				case ast::expr::Intrinsic::eIsinf3D:
				case ast::expr::Intrinsic::eIsinf4D:
					result = "isinf";
					break;

				case ast::expr::Intrinsic::eFloatBitsToInt1:
				case ast::expr::Intrinsic::eFloatBitsToInt2:
				case ast::expr::Intrinsic::eFloatBitsToInt3:
				case ast::expr::Intrinsic::eFloatBitsToInt4:
					result = "floatBitsToInt";
					break;

				case ast::expr::Intrinsic::eFloatBitsToUInt1:
				case ast::expr::Intrinsic::eFloatBitsToUInt2:
				case ast::expr::Intrinsic::eFloatBitsToUInt3:
				case ast::expr::Intrinsic::eFloatBitsToUInt4:
					result = "floatBitsToUint";
					break;

				case ast::expr::Intrinsic::eIntBitsToFloat1:
				case ast::expr::Intrinsic::eIntBitsToFloat2:
				case ast::expr::Intrinsic::eIntBitsToFloat3:
				case ast::expr::Intrinsic::eIntBitsToFloat4:
					result = "intBitsToFloat";
					break;

				case ast::expr::Intrinsic::eUintBitsToFloat1:
				case ast::expr::Intrinsic::eUintBitsToFloat2:
				case ast::expr::Intrinsic::eUintBitsToFloat3:
				case ast::expr::Intrinsic::eUintBitsToFloat4:
					result = "uintBitsToFloat";
					break;

				case ast::expr::Intrinsic::eFma1F:
				case ast::expr::Intrinsic::eFma2F:
				case ast::expr::Intrinsic::eFma3F:
				case ast::expr::Intrinsic::eFma4F:
				case ast::expr::Intrinsic::eFma1D:
				case ast::expr::Intrinsic::eFma2D:
				case ast::expr::Intrinsic::eFma3D:
				case ast::expr::Intrinsic::eFma4D:
					result = "fma";
					break;

				case ast::expr::Intrinsic::eFrexp1F:
				case ast::expr::Intrinsic::eFrexp2F:
				case ast::expr::Intrinsic::eFrexp3F:
				case ast::expr::Intrinsic::eFrexp4F:
				case ast::expr::Intrinsic::eFrexp1D:
				case ast::expr::Intrinsic::eFrexp2D:
				case ast::expr::Intrinsic::eFrexp3D:
				case ast::expr::Intrinsic::eFrexp4D:
					result = "frexp";
					break;

				case ast::expr::Intrinsic::eLdexp1F:
				case ast::expr::Intrinsic::eLdexp2F:
				case ast::expr::Intrinsic::eLdexp3F:
				case ast::expr::Intrinsic::eLdexp4F:
				case ast::expr::Intrinsic::eLdexp1D:
				case ast::expr::Intrinsic::eLdexp2D:
				case ast::expr::Intrinsic::eLdexp3D:
				case ast::expr::Intrinsic::eLdexp4D:
					result = "ldexp";
					break;


			// Floating-point Pack and Unpack Functions
				case ast::expr::Intrinsic::ePackDouble2x32:
					result = "packDouble2x32";
					break;

				case ast::expr::Intrinsic::ePackHalf2x16:
					result = "packHalf2x16";
					break;

				case ast::expr::Intrinsic::ePackSnorm2x16:
					result = "packSnorm2x16";
					break;

				case ast::expr::Intrinsic::ePackSnorm4x8:
					result = "packSnorm4x8";
					break;

				case ast::expr::Intrinsic::ePackUnorm2x16:
					result = "packUnorm2x16";
					break;

				case ast::expr::Intrinsic::ePackUnorm4x8:
					result = "packUnorm4x8";
					break;

				case ast::expr::Intrinsic::eUnpackDouble2x32:
					result = "unpackDouble2x32";
					break;

				case ast::expr::Intrinsic::eUnpackHalf2x16:
					result = "unpackHalf2x16";
					break;

				case ast::expr::Intrinsic::eUnpackSnorm2x16:
					result = "unpackSnorm2x16";
					break;

				case ast::expr::Intrinsic::eUnpackSnorm4x8:
					result = "unpackSnorm4x8";
					break;

				case ast::expr::Intrinsic::eUnpackUnorm2x16:
					result = "unpackUnorm2x16";
					break;

				case ast::expr::Intrinsic::eUnpackUnorm4x8:
					result = "unpackUnorm4x8";
					break;


			// Geometric Functions
				case ast::expr::Intrinsic::eLength1F:
				case ast::expr::Intrinsic::eLength2F:
				case ast::expr::Intrinsic::eLength3F:
				case ast::expr::Intrinsic::eLength4F:
				case ast::expr::Intrinsic::eLength1D:
				case ast::expr::Intrinsic::eLength2D:
				case ast::expr::Intrinsic::eLength3D:
				case ast::expr::Intrinsic::eLength4D:
					result = "length";
					break;

				case ast::expr::Intrinsic::eDistance1F:
				case ast::expr::Intrinsic::eDistance2F:
				case ast::expr::Intrinsic::eDistance3F:
				case ast::expr::Intrinsic::eDistance4F:
				case ast::expr::Intrinsic::eDistance1D:
				case ast::expr::Intrinsic::eDistance2D:
				case ast::expr::Intrinsic::eDistance3D:
				case ast::expr::Intrinsic::eDistance4D:
					result = "distance";
					break;

				case ast::expr::Intrinsic::eDot1F:
				case ast::expr::Intrinsic::eDot2F:
				case ast::expr::Intrinsic::eDot3F:
				case ast::expr::Intrinsic::eDot4F:
				case ast::expr::Intrinsic::eDot1D:
				case ast::expr::Intrinsic::eDot2D:
				case ast::expr::Intrinsic::eDot3D:
				case ast::expr::Intrinsic::eDot4D:
					result = "dot";
					break;

				case ast::expr::Intrinsic::eCrossF:
				case ast::expr::Intrinsic::eCrossD:
					result = "cross";
					break;

				case ast::expr::Intrinsic::eNormalize1F:
				case ast::expr::Intrinsic::eNormalize2F:
				case ast::expr::Intrinsic::eNormalize3F:
				case ast::expr::Intrinsic::eNormalize4F:
				case ast::expr::Intrinsic::eNormalize1D:
				case ast::expr::Intrinsic::eNormalize2D:
				case ast::expr::Intrinsic::eNormalize3D:
				case ast::expr::Intrinsic::eNormalize4D:
					result = "normalize";
					break;

				case ast::expr::Intrinsic::eFaceForward1F:
				case ast::expr::Intrinsic::eFaceForward2F:
				case ast::expr::Intrinsic::eFaceForward3F:
				case ast::expr::Intrinsic::eFaceForward4F:
				case ast::expr::Intrinsic::eFaceForward1D:
				case ast::expr::Intrinsic::eFaceForward2D:
				case ast::expr::Intrinsic::eFaceForward3D:
				case ast::expr::Intrinsic::eFaceForward4D:
					result = "faceforward";
					break;

				case ast::expr::Intrinsic::eReflect1F:
				case ast::expr::Intrinsic::eReflect2F:
				case ast::expr::Intrinsic::eReflect3F:
				case ast::expr::Intrinsic::eReflect4F:
				case ast::expr::Intrinsic::eReflect1D:
				case ast::expr::Intrinsic::eReflect2D:
				case ast::expr::Intrinsic::eReflect3D:
				case ast::expr::Intrinsic::eReflect4D:
					result = "reflect";
					break;

				case ast::expr::Intrinsic::eRefract1F:
				case ast::expr::Intrinsic::eRefract2F:
				case ast::expr::Intrinsic::eRefract3F:
				case ast::expr::Intrinsic::eRefract4F:
				case ast::expr::Intrinsic::eRefract1D:
				case ast::expr::Intrinsic::eRefract2D:
				case ast::expr::Intrinsic::eRefract3D:
				case ast::expr::Intrinsic::eRefract4D:
					result = "refract";
					break;


			// Matrix Functions
				case ast::expr::Intrinsic::eMatrixCompMult2x2F:
				case ast::expr::Intrinsic::eMatrixCompMult2x3F:
				case ast::expr::Intrinsic::eMatrixCompMult2x4F:
				case ast::expr::Intrinsic::eMatrixCompMult3x2F:
				case ast::expr::Intrinsic::eMatrixCompMult3x3F:
				case ast::expr::Intrinsic::eMatrixCompMult3x4F:
				case ast::expr::Intrinsic::eMatrixCompMult4x2F:
				case ast::expr::Intrinsic::eMatrixCompMult4x3F:
				case ast::expr::Intrinsic::eMatrixCompMult4x4F:
				case ast::expr::Intrinsic::eMatrixCompMult2x2D:
				case ast::expr::Intrinsic::eMatrixCompMult2x3D:
				case ast::expr::Intrinsic::eMatrixCompMult2x4D:
				case ast::expr::Intrinsic::eMatrixCompMult3x2D:
				case ast::expr::Intrinsic::eMatrixCompMult3x3D:
				case ast::expr::Intrinsic::eMatrixCompMult3x4D:
				case ast::expr::Intrinsic::eMatrixCompMult4x2D:
				case ast::expr::Intrinsic::eMatrixCompMult4x3D:
				case ast::expr::Intrinsic::eMatrixCompMult4x4D:
					result = "matrixCompMult";
					break;

				case ast::expr::Intrinsic::eOuterProduct2x2F:
				case ast::expr::Intrinsic::eOuterProduct3x3F:
				case ast::expr::Intrinsic::eOuterProduct4x4F:
				case ast::expr::Intrinsic::eOuterProduct3x2F:
				case ast::expr::Intrinsic::eOuterProduct2x3F:
				case ast::expr::Intrinsic::eOuterProduct4x2F:
				case ast::expr::Intrinsic::eOuterProduct2x4F:
				case ast::expr::Intrinsic::eOuterProduct4x3F:
				case ast::expr::Intrinsic::eOuterProduct3x4F:
				case ast::expr::Intrinsic::eOuterProduct2x2D:
				case ast::expr::Intrinsic::eOuterProduct3x3D:
				case ast::expr::Intrinsic::eOuterProduct4x4D:
				case ast::expr::Intrinsic::eOuterProduct3x2D:
				case ast::expr::Intrinsic::eOuterProduct2x3D:
				case ast::expr::Intrinsic::eOuterProduct4x2D:
				case ast::expr::Intrinsic::eOuterProduct2x4D:
				case ast::expr::Intrinsic::eOuterProduct4x3D:
				case ast::expr::Intrinsic::eOuterProduct3x4D:
					result = "outerProduct";
					break;

				case ast::expr::Intrinsic::eTranspose2x2F:
				case ast::expr::Intrinsic::eTranspose2x3F:
				case ast::expr::Intrinsic::eTranspose2x4F:
				case ast::expr::Intrinsic::eTranspose3x2F:
				case ast::expr::Intrinsic::eTranspose3x3F:
				case ast::expr::Intrinsic::eTranspose3x4F:
				case ast::expr::Intrinsic::eTranspose4x2F:
				case ast::expr::Intrinsic::eTranspose4x3F:
				case ast::expr::Intrinsic::eTranspose4x4F:
				case ast::expr::Intrinsic::eTranspose2x2D:
				case ast::expr::Intrinsic::eTranspose2x3D:
				case ast::expr::Intrinsic::eTranspose2x4D:
				case ast::expr::Intrinsic::eTranspose3x2D:
				case ast::expr::Intrinsic::eTranspose3x3D:
				case ast::expr::Intrinsic::eTranspose3x4D:
				case ast::expr::Intrinsic::eTranspose4x2D:
				case ast::expr::Intrinsic::eTranspose4x3D:
				case ast::expr::Intrinsic::eTranspose4x4D:
					result = "transpose";
					break;

				case ast::expr::Intrinsic::eDeterminant2x2F:
				case ast::expr::Intrinsic::eDeterminant3x3F:
				case ast::expr::Intrinsic::eDeterminant4x4F:
				case ast::expr::Intrinsic::eDeterminant2x2D:
				case ast::expr::Intrinsic::eDeterminant3x3D:
				case ast::expr::Intrinsic::eDeterminant4x4D:
					result = "determinant";
					break;

				case ast::expr::Intrinsic::eInverse2x2F:
				case ast::expr::Intrinsic::eInverse3x3F:
				case ast::expr::Intrinsic::eInverse4x4F:
				case ast::expr::Intrinsic::eInverse2x2D:
				case ast::expr::Intrinsic::eInverse3x3D:
				case ast::expr::Intrinsic::eInverse4x4D:
					result = "inverse";
					break;


			// Vector Relational Functions
				case ast::expr::Intrinsic::eLessThan2F:
				case ast::expr::Intrinsic::eLessThan3F:
				case ast::expr::Intrinsic::eLessThan4F:
				case ast::expr::Intrinsic::eLessThan2D:
				case ast::expr::Intrinsic::eLessThan3D:
				case ast::expr::Intrinsic::eLessThan4D:
				case ast::expr::Intrinsic::eLessThan2I:
				case ast::expr::Intrinsic::eLessThan3I:
				case ast::expr::Intrinsic::eLessThan4I:
				case ast::expr::Intrinsic::eLessThan2U:
				case ast::expr::Intrinsic::eLessThan3U:
				case ast::expr::Intrinsic::eLessThan4U:
					result = "lessThan";
					break;

				case ast::expr::Intrinsic::eLessThanEqual2F:
				case ast::expr::Intrinsic::eLessThanEqual3F:
				case ast::expr::Intrinsic::eLessThanEqual4F:
				case ast::expr::Intrinsic::eLessThanEqual2D:
				case ast::expr::Intrinsic::eLessThanEqual3D:
				case ast::expr::Intrinsic::eLessThanEqual4D:
				case ast::expr::Intrinsic::eLessThanEqual2I:
				case ast::expr::Intrinsic::eLessThanEqual3I:
				case ast::expr::Intrinsic::eLessThanEqual4I:
				case ast::expr::Intrinsic::eLessThanEqual2U:
				case ast::expr::Intrinsic::eLessThanEqual3U:
				case ast::expr::Intrinsic::eLessThanEqual4U:
					result = "lessThanEqual";
					break;

				case ast::expr::Intrinsic::eGreaterThan2F:
				case ast::expr::Intrinsic::eGreaterThan3F:
				case ast::expr::Intrinsic::eGreaterThan4F:
				case ast::expr::Intrinsic::eGreaterThan2D:
				case ast::expr::Intrinsic::eGreaterThan3D:
				case ast::expr::Intrinsic::eGreaterThan4D:
				case ast::expr::Intrinsic::eGreaterThan2I:
				case ast::expr::Intrinsic::eGreaterThan3I:
				case ast::expr::Intrinsic::eGreaterThan4I:
				case ast::expr::Intrinsic::eGreaterThan2U:
				case ast::expr::Intrinsic::eGreaterThan3U:
				case ast::expr::Intrinsic::eGreaterThan4U:
					result = "greaterThan";
					break;

				case ast::expr::Intrinsic::eGreaterThanEqual2F:
				case ast::expr::Intrinsic::eGreaterThanEqual3F:
				case ast::expr::Intrinsic::eGreaterThanEqual4F:
				case ast::expr::Intrinsic::eGreaterThanEqual2D:
				case ast::expr::Intrinsic::eGreaterThanEqual3D:
				case ast::expr::Intrinsic::eGreaterThanEqual4D:
				case ast::expr::Intrinsic::eGreaterThanEqual2I:
				case ast::expr::Intrinsic::eGreaterThanEqual3I:
				case ast::expr::Intrinsic::eGreaterThanEqual4I:
				case ast::expr::Intrinsic::eGreaterThanEqual2U:
				case ast::expr::Intrinsic::eGreaterThanEqual3U:
				case ast::expr::Intrinsic::eGreaterThanEqual4U:
					result = "greaterThanEqual";
					break;

				case ast::expr::Intrinsic::eEqual2F:
				case ast::expr::Intrinsic::eEqual3F:
				case ast::expr::Intrinsic::eEqual4F:
				case ast::expr::Intrinsic::eEqual2D:
				case ast::expr::Intrinsic::eEqual3D:
				case ast::expr::Intrinsic::eEqual4D:
				case ast::expr::Intrinsic::eEqual2I:
				case ast::expr::Intrinsic::eEqual3I:
				case ast::expr::Intrinsic::eEqual4I:
				case ast::expr::Intrinsic::eEqual2U:
				case ast::expr::Intrinsic::eEqual3U:
				case ast::expr::Intrinsic::eEqual4U:
					result = "equal";
					break;

				case ast::expr::Intrinsic::eNotEqual2F:
				case ast::expr::Intrinsic::eNotEqual3F:
				case ast::expr::Intrinsic::eNotEqual4F:
				case ast::expr::Intrinsic::eNotEqual2D:
				case ast::expr::Intrinsic::eNotEqual3D:
				case ast::expr::Intrinsic::eNotEqual4D:
				case ast::expr::Intrinsic::eNotEqual2I:
				case ast::expr::Intrinsic::eNotEqual3I:
				case ast::expr::Intrinsic::eNotEqual4I:
				case ast::expr::Intrinsic::eNotEqual2U:
				case ast::expr::Intrinsic::eNotEqual3U:
				case ast::expr::Intrinsic::eNotEqual4U:
					result = "notEqual";
					break;

				case ast::expr::Intrinsic::eAll2:
				case ast::expr::Intrinsic::eAll3:
				case ast::expr::Intrinsic::eAll4:
					result = "all";
					break;

				case ast::expr::Intrinsic::eAny2:
				case ast::expr::Intrinsic::eAny3:
				case ast::expr::Intrinsic::eAny4:
					result = "any";
					break;

				case ast::expr::Intrinsic::eNot2:
				case ast::expr::Intrinsic::eNot3:
				case ast::expr::Intrinsic::eNot4:
					result = "not";
					break;


			// Integer Functions
				case ast::expr::Intrinsic::eUaddCarry1:
				case ast::expr::Intrinsic::eUaddCarry2:
				case ast::expr::Intrinsic::eUaddCarry3:
				case ast::expr::Intrinsic::eUaddCarry4:
					result = "uaddCarry";
					break;

				case ast::expr::Intrinsic::eUsubBorrow1:
				case ast::expr::Intrinsic::eUsubBorrow2:
				case ast::expr::Intrinsic::eUsubBorrow3:
				case ast::expr::Intrinsic::eUsubBorrow4:
					result = "usubBorrow";
					break;

				case ast::expr::Intrinsic::eUmulExtended1:
				case ast::expr::Intrinsic::eUmulExtended2:
				case ast::expr::Intrinsic::eUmulExtended3:
				case ast::expr::Intrinsic::eUmulExtended4:
					result = "umulExtended";
					break;

				case ast::expr::Intrinsic::eImulExtended1:
				case ast::expr::Intrinsic::eImulExtended2:
				case ast::expr::Intrinsic::eImulExtended3:
				case ast::expr::Intrinsic::eImulExtended4:
					result = "imulExtended";
					break;

				case ast::expr::Intrinsic::eBitfieldExtract1I:
				case ast::expr::Intrinsic::eBitfieldExtract2I:
				case ast::expr::Intrinsic::eBitfieldExtract3I:
				case ast::expr::Intrinsic::eBitfieldExtract4I:
				case ast::expr::Intrinsic::eBitfieldExtract1U:
				case ast::expr::Intrinsic::eBitfieldExtract2U:
				case ast::expr::Intrinsic::eBitfieldExtract3U:
				case ast::expr::Intrinsic::eBitfieldExtract4U:
					result = "bitfieldExtract";
					break;

				case ast::expr::Intrinsic::eBitfieldInsert1I:
				case ast::expr::Intrinsic::eBitfieldInsert2I:
				case ast::expr::Intrinsic::eBitfieldInsert3I:
				case ast::expr::Intrinsic::eBitfieldInsert4I:
				case ast::expr::Intrinsic::eBitfieldInsert1U:
				case ast::expr::Intrinsic::eBitfieldInsert2U:
				case ast::expr::Intrinsic::eBitfieldInsert3U:
				case ast::expr::Intrinsic::eBitfieldInsert4U:
					result = "bitfieldInsert";
					break;

				case ast::expr::Intrinsic::eBitfieldReverse1I:
				case ast::expr::Intrinsic::eBitfieldReverse2I:
				case ast::expr::Intrinsic::eBitfieldReverse3I:
				case ast::expr::Intrinsic::eBitfieldReverse4I:
				case ast::expr::Intrinsic::eBitfieldReverse1U:
				case ast::expr::Intrinsic::eBitfieldReverse2U:
				case ast::expr::Intrinsic::eBitfieldReverse3U:
				case ast::expr::Intrinsic::eBitfieldReverse4U:
					result = "bitfieldReverse";
					break;

				case ast::expr::Intrinsic::eBitCount1I:
				case ast::expr::Intrinsic::eBitCount2I:
				case ast::expr::Intrinsic::eBitCount3I:
				case ast::expr::Intrinsic::eBitCount4I:
				case ast::expr::Intrinsic::eBitCount1U:
				case ast::expr::Intrinsic::eBitCount2U:
				case ast::expr::Intrinsic::eBitCount3U:
				case ast::expr::Intrinsic::eBitCount4U:
					result = "bitCount";
					break;

				case ast::expr::Intrinsic::eFindLSB1I:
				case ast::expr::Intrinsic::eFindLSB2I:
				case ast::expr::Intrinsic::eFindLSB3I:
				case ast::expr::Intrinsic::eFindLSB4I:
				case ast::expr::Intrinsic::eFindLSB1U:
				case ast::expr::Intrinsic::eFindLSB2U:
				case ast::expr::Intrinsic::eFindLSB3U:
				case ast::expr::Intrinsic::eFindLSB4U:
					result = "findLSB";
					break;

				case ast::expr::Intrinsic::eFindMSB1I:
				case ast::expr::Intrinsic::eFindMSB2I:
				case ast::expr::Intrinsic::eFindMSB3I:
				case ast::expr::Intrinsic::eFindMSB4I:
				case ast::expr::Intrinsic::eFindMSB1U:
				case ast::expr::Intrinsic::eFindMSB2U:
				case ast::expr::Intrinsic::eFindMSB3U:
				case ast::expr::Intrinsic::eFindMSB4U:
					result = "findMSB";
					break;


			// Atomic Memory Functions
				case ast::expr::Intrinsic::eAtomicAddI:
				case ast::expr::Intrinsic::eAtomicAddU:
				case ast::expr::Intrinsic::eAtomicAddF:
				case ast::expr::Intrinsic::eAtomicAdd2H:
				case ast::expr::Intrinsic::eAtomicAdd4H:
					result = "atomicAdd";
					break;

				case ast::expr::Intrinsic::eAtomicMinI:
				case ast::expr::Intrinsic::eAtomicMinU:
					result = "atomicMin";
					break;

				case ast::expr::Intrinsic::eAtomicMaxI:
				case ast::expr::Intrinsic::eAtomicMaxU:
					result = "atomicMax";
					break;

				case ast::expr::Intrinsic::eAtomicAndI:
				case ast::expr::Intrinsic::eAtomicAndU:
					result = "atomicAnd";
					break;

				case ast::expr::Intrinsic::eAtomicOrI:
				case ast::expr::Intrinsic::eAtomicOrU:
					result = "atomicOr";
					break;

				case ast::expr::Intrinsic::eAtomicXorI:
				case ast::expr::Intrinsic::eAtomicXorU:
					result = "atomicXor";
					break;

				case ast::expr::Intrinsic::eAtomicExchangeI:
				case ast::expr::Intrinsic::eAtomicExchangeU:
				case ast::expr::Intrinsic::eAtomicExchangeF:
				case ast::expr::Intrinsic::eAtomicExchange2H:
				case ast::expr::Intrinsic::eAtomicExchange4H:
					result = "atomicExchange";
					break;

				case ast::expr::Intrinsic::eAtomicCompSwapI:
				case ast::expr::Intrinsic::eAtomicCompSwapU:
					result = "atomicCompSwap";
					break;


			// Derivative Functions
				case ast::expr::Intrinsic::eDFdx1:
				case ast::expr::Intrinsic::eDFdx2:
				case ast::expr::Intrinsic::eDFdx3:
				case ast::expr::Intrinsic::eDFdx4:
					result = "dFdx";
					break;

				case ast::expr::Intrinsic::eDFdxCoarse1:
				case ast::expr::Intrinsic::eDFdxCoarse2:
				case ast::expr::Intrinsic::eDFdxCoarse3:
				case ast::expr::Intrinsic::eDFdxCoarse4:
					result = "dFdxCoarse";
					break;

				case ast::expr::Intrinsic::eDFdxFine1:
				case ast::expr::Intrinsic::eDFdxFine2:
				case ast::expr::Intrinsic::eDFdxFine3:
				case ast::expr::Intrinsic::eDFdxFine4:
					result = "dFdxFine";
					break;

				case ast::expr::Intrinsic::eDFdy1:
				case ast::expr::Intrinsic::eDFdy2:
				case ast::expr::Intrinsic::eDFdy3:
				case ast::expr::Intrinsic::eDFdy4:
					result = "dFdy";
					break;

				case ast::expr::Intrinsic::eDFdyCoarse1:
				case ast::expr::Intrinsic::eDFdyCoarse2:
				case ast::expr::Intrinsic::eDFdyCoarse3:
				case ast::expr::Intrinsic::eDFdyCoarse4:
					result = "dFdyCoarse";
					break;

				case ast::expr::Intrinsic::eDFdyFine1:
				case ast::expr::Intrinsic::eDFdyFine2:
				case ast::expr::Intrinsic::eDFdyFine3:
				case ast::expr::Intrinsic::eDFdyFine4:
					result = "dFdyFine";
					break;

				case ast::expr::Intrinsic::eFwidth1:
				case ast::expr::Intrinsic::eFwidth2:
				case ast::expr::Intrinsic::eFwidth3:
				case ast::expr::Intrinsic::eFwidth4:
					result = "fwidth";
					break;


			// Interpolation Functions
				case ast::expr::Intrinsic::eInterpolateAtCentroid1:
				case ast::expr::Intrinsic::eInterpolateAtCentroid2:
				case ast::expr::Intrinsic::eInterpolateAtCentroid3:
				case ast::expr::Intrinsic::eInterpolateAtCentroid4:
					result = "interpolateAtCentroid";
					break;

				case ast::expr::Intrinsic::eInterpolateAtSample1:
				case ast::expr::Intrinsic::eInterpolateAtSample2:
				case ast::expr::Intrinsic::eInterpolateAtSample3:
				case ast::expr::Intrinsic::eInterpolateAtSample4:
					result = "interpolateAtSample";
					break;

				case ast::expr::Intrinsic::eInterpolateAtOffset1:
				case ast::expr::Intrinsic::eInterpolateAtOffset2:
				case ast::expr::Intrinsic::eInterpolateAtOffset3:
				case ast::expr::Intrinsic::eInterpolateAtOffset4:
					result = "interpolateAtOffset";
					break;


			// Geometry Shader Functions
				case ast::expr::Intrinsic::eEmitStreamVertex:
					result = "emitStreamVertex";
					break;

				case ast::expr::Intrinsic::eEndStreamPrimitive:
					result = "endStreamPrimitive";
					break;

				case ast::expr::Intrinsic::eEmitVertex:
					result = "emitVertex";
					break;

				case ast::expr::Intrinsic::eEndPrimitive:
					result = "endPrimitive";
					break;


			// Miscellaneous Functions
				case ast::expr::Intrinsic::eHelperInvocation:
					result = "helperInvocation";
					break;

				case ast::expr::Intrinsic::eTraceRay:
					result = "traceRay";
					break;

				case ast::expr::Intrinsic::eReportIntersection:
					result = "reportIntersection";
					break;

				case ast::expr::Intrinsic::eExecuteCallable:
					result = "executeCallable";
					break;


			//Mesh Shader Functions
				case ast::expr::Intrinsic::eWritePackedPrimitiveIndices4x8NV:
					result = "writePackedPrimitiveIndices4x8";
					break;

				case ast::expr::Intrinsic::eSetMeshOutputCounts:
					result = "SetMeshOutputs";
					break;


			//Shader Subgroup Functions
				case ast::expr::Intrinsic::eSubgroupElect:
					result = "subgroupElect";
					break;

				case ast::expr::Intrinsic::eSubgroupAll:
					result = "subgroupAll";
					break;

				case ast::expr::Intrinsic::eSubgroupAny:
					result = "subgroupAny";
					break;

				case ast::expr::Intrinsic::eSubgroupAllEqual1F:
				case ast::expr::Intrinsic::eSubgroupAllEqual2F:
				case ast::expr::Intrinsic::eSubgroupAllEqual3F:
				case ast::expr::Intrinsic::eSubgroupAllEqual4F:
				case ast::expr::Intrinsic::eSubgroupAllEqual1I:
				case ast::expr::Intrinsic::eSubgroupAllEqual2I:
				case ast::expr::Intrinsic::eSubgroupAllEqual3I:
				case ast::expr::Intrinsic::eSubgroupAllEqual4I:
				case ast::expr::Intrinsic::eSubgroupAllEqual1U:
				case ast::expr::Intrinsic::eSubgroupAllEqual2U:
				case ast::expr::Intrinsic::eSubgroupAllEqual3U:
				case ast::expr::Intrinsic::eSubgroupAllEqual4U:
				case ast::expr::Intrinsic::eSubgroupAllEqual1B:
				case ast::expr::Intrinsic::eSubgroupAllEqual2B:
				case ast::expr::Intrinsic::eSubgroupAllEqual3B:
				case ast::expr::Intrinsic::eSubgroupAllEqual4B:
				case ast::expr::Intrinsic::eSubgroupAllEqual1D:
				case ast::expr::Intrinsic::eSubgroupAllEqual2D:
				case ast::expr::Intrinsic::eSubgroupAllEqual3D:
				case ast::expr::Intrinsic::eSubgroupAllEqual4D:
					result = "subgroupAllEqual";
					break;

				case ast::expr::Intrinsic::eSubgroupBroadcast1F:
				case ast::expr::Intrinsic::eSubgroupBroadcast2F:
				case ast::expr::Intrinsic::eSubgroupBroadcast3F:
				case ast::expr::Intrinsic::eSubgroupBroadcast4F:
				case ast::expr::Intrinsic::eSubgroupBroadcast1I:
				case ast::expr::Intrinsic::eSubgroupBroadcast2I:
				case ast::expr::Intrinsic::eSubgroupBroadcast3I:
				case ast::expr::Intrinsic::eSubgroupBroadcast4I:
				case ast::expr::Intrinsic::eSubgroupBroadcast1U:
				case ast::expr::Intrinsic::eSubgroupBroadcast2U:
				case ast::expr::Intrinsic::eSubgroupBroadcast3U:
				case ast::expr::Intrinsic::eSubgroupBroadcast4U:
				case ast::expr::Intrinsic::eSubgroupBroadcast1B:
				case ast::expr::Intrinsic::eSubgroupBroadcast2B:
				case ast::expr::Intrinsic::eSubgroupBroadcast3B:
				case ast::expr::Intrinsic::eSubgroupBroadcast4B:
				case ast::expr::Intrinsic::eSubgroupBroadcast1D:
				case ast::expr::Intrinsic::eSubgroupBroadcast2D:
				case ast::expr::Intrinsic::eSubgroupBroadcast3D:
				case ast::expr::Intrinsic::eSubgroupBroadcast4D:
					result = "subgroupBroadcast";
					break;

				case ast::expr::Intrinsic::eSubgroupBroadcastFirst1F:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst2F:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst3F:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst4F:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst1I:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst2I:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst3I:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst4I:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst1U:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst2U:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst3U:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst4U:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst1B:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst2B:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst3B:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst4B:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst1D:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst2D:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst3D:
				case ast::expr::Intrinsic::eSubgroupBroadcastFirst4D:
					result = "subgroupBroadcastFirst";
					break;

				case ast::expr::Intrinsic::eSubgroupBallot:
					result = "subgroupBallot";
					break;

				case ast::expr::Intrinsic::eSubgroupInverseBallot:
					result = "subgroupInverseBallot";
					break;

				case ast::expr::Intrinsic::eSubgroupBallotBitExtract:
					result = "subgroupBallotBitExtract";
					break;

				case ast::expr::Intrinsic::eSubgroupBallotBitCount:
					result = "subgroupBallotBitCount";
					break;

				case ast::expr::Intrinsic::eSubgroupBallotInclusiveBitCount:
					result = "subgroupBallotInclusiveBitCount";
					break;

				case ast::expr::Intrinsic::eSubgroupBallotExclusiveBitCount:
					result = "subgroupBallotExclusiveBitCount";
					break;

				case ast::expr::Intrinsic::eSubgroupBallotFindLSB:
					result = "subgroupBallotFindLSB";
					break;

				case ast::expr::Intrinsic::eSubgroupBallotFindMSB:
					result = "subgroupBallotFindMSB";
					break;

				case ast::expr::Intrinsic::eSubgroupShuffle1F:
				case ast::expr::Intrinsic::eSubgroupShuffle2F:
				case ast::expr::Intrinsic::eSubgroupShuffle3F:
				case ast::expr::Intrinsic::eSubgroupShuffle4F:
				case ast::expr::Intrinsic::eSubgroupShuffle1I:
				case ast::expr::Intrinsic::eSubgroupShuffle2I:
				case ast::expr::Intrinsic::eSubgroupShuffle3I:
				case ast::expr::Intrinsic::eSubgroupShuffle4I:
				case ast::expr::Intrinsic::eSubgroupShuffle1U:
				case ast::expr::Intrinsic::eSubgroupShuffle2U:
				case ast::expr::Intrinsic::eSubgroupShuffle3U:
				case ast::expr::Intrinsic::eSubgroupShuffle4U:
				case ast::expr::Intrinsic::eSubgroupShuffle1B:
				case ast::expr::Intrinsic::eSubgroupShuffle2B:
				case ast::expr::Intrinsic::eSubgroupShuffle3B:
				case ast::expr::Intrinsic::eSubgroupShuffle4B:
				case ast::expr::Intrinsic::eSubgroupShuffle1D:
				case ast::expr::Intrinsic::eSubgroupShuffle2D:
				case ast::expr::Intrinsic::eSubgroupShuffle3D:
				case ast::expr::Intrinsic::eSubgroupShuffle4D:
					result = "subgroupShuffle";
					break;

				case ast::expr::Intrinsic::eSubgroupShuffleXor1F:
				case ast::expr::Intrinsic::eSubgroupShuffleXor2F:
				case ast::expr::Intrinsic::eSubgroupShuffleXor3F:
				case ast::expr::Intrinsic::eSubgroupShuffleXor4F:
				case ast::expr::Intrinsic::eSubgroupShuffleXor1I:
				case ast::expr::Intrinsic::eSubgroupShuffleXor2I:
				case ast::expr::Intrinsic::eSubgroupShuffleXor3I:
				case ast::expr::Intrinsic::eSubgroupShuffleXor4I:
				case ast::expr::Intrinsic::eSubgroupShuffleXor1U:
				case ast::expr::Intrinsic::eSubgroupShuffleXor2U:
				case ast::expr::Intrinsic::eSubgroupShuffleXor3U:
				case ast::expr::Intrinsic::eSubgroupShuffleXor4U:
				case ast::expr::Intrinsic::eSubgroupShuffleXor1B:
				case ast::expr::Intrinsic::eSubgroupShuffleXor2B:
				case ast::expr::Intrinsic::eSubgroupShuffleXor3B:
				case ast::expr::Intrinsic::eSubgroupShuffleXor4B:
				case ast::expr::Intrinsic::eSubgroupShuffleXor1D:
				case ast::expr::Intrinsic::eSubgroupShuffleXor2D:
				case ast::expr::Intrinsic::eSubgroupShuffleXor3D:
				case ast::expr::Intrinsic::eSubgroupShuffleXor4D:
					result = "subgroupShuffleXor";
					break;

				case ast::expr::Intrinsic::eSubgroupShuffleUp1F:
				case ast::expr::Intrinsic::eSubgroupShuffleUp2F:
				case ast::expr::Intrinsic::eSubgroupShuffleUp3F:
				case ast::expr::Intrinsic::eSubgroupShuffleUp4F:
				case ast::expr::Intrinsic::eSubgroupShuffleUp1I:
				case ast::expr::Intrinsic::eSubgroupShuffleUp2I:
				case ast::expr::Intrinsic::eSubgroupShuffleUp3I:
				case ast::expr::Intrinsic::eSubgroupShuffleUp4I:
				case ast::expr::Intrinsic::eSubgroupShuffleUp1U:
				case ast::expr::Intrinsic::eSubgroupShuffleUp2U:
				case ast::expr::Intrinsic::eSubgroupShuffleUp3U:
				case ast::expr::Intrinsic::eSubgroupShuffleUp4U:
				case ast::expr::Intrinsic::eSubgroupShuffleUp1B:
				case ast::expr::Intrinsic::eSubgroupShuffleUp2B:
				case ast::expr::Intrinsic::eSubgroupShuffleUp3B:
				case ast::expr::Intrinsic::eSubgroupShuffleUp4B:
				case ast::expr::Intrinsic::eSubgroupShuffleUp1D:
				case ast::expr::Intrinsic::eSubgroupShuffleUp2D:
				case ast::expr::Intrinsic::eSubgroupShuffleUp3D:
				case ast::expr::Intrinsic::eSubgroupShuffleUp4D:
					result = "subgroupShuffleUp";
					break;

				case ast::expr::Intrinsic::eSubgroupShuffleDown1F:
				case ast::expr::Intrinsic::eSubgroupShuffleDown2F:
				case ast::expr::Intrinsic::eSubgroupShuffleDown3F:
				case ast::expr::Intrinsic::eSubgroupShuffleDown4F:
				case ast::expr::Intrinsic::eSubgroupShuffleDown1I:
				case ast::expr::Intrinsic::eSubgroupShuffleDown2I:
				case ast::expr::Intrinsic::eSubgroupShuffleDown3I:
				case ast::expr::Intrinsic::eSubgroupShuffleDown4I:
				case ast::expr::Intrinsic::eSubgroupShuffleDown1U:
				case ast::expr::Intrinsic::eSubgroupShuffleDown2U:
				case ast::expr::Intrinsic::eSubgroupShuffleDown3U:
				case ast::expr::Intrinsic::eSubgroupShuffleDown4U:
				case ast::expr::Intrinsic::eSubgroupShuffleDown1B:
				case ast::expr::Intrinsic::eSubgroupShuffleDown2B:
				case ast::expr::Intrinsic::eSubgroupShuffleDown3B:
				case ast::expr::Intrinsic::eSubgroupShuffleDown4B:
				case ast::expr::Intrinsic::eSubgroupShuffleDown1D:
				case ast::expr::Intrinsic::eSubgroupShuffleDown2D:
				case ast::expr::Intrinsic::eSubgroupShuffleDown3D:
				case ast::expr::Intrinsic::eSubgroupShuffleDown4D:
					result = "subgroupShuffleDown";
					break;

				case ast::expr::Intrinsic::eSubgroupAdd1F:
				case ast::expr::Intrinsic::eSubgroupAdd2F:
				case ast::expr::Intrinsic::eSubgroupAdd3F:
				case ast::expr::Intrinsic::eSubgroupAdd4F:
				case ast::expr::Intrinsic::eSubgroupAdd1I:
				case ast::expr::Intrinsic::eSubgroupAdd2I:
				case ast::expr::Intrinsic::eSubgroupAdd3I:
				case ast::expr::Intrinsic::eSubgroupAdd4I:
				case ast::expr::Intrinsic::eSubgroupAdd1U:
				case ast::expr::Intrinsic::eSubgroupAdd2U:
				case ast::expr::Intrinsic::eSubgroupAdd3U:
				case ast::expr::Intrinsic::eSubgroupAdd4U:
				case ast::expr::Intrinsic::eSubgroupAdd1D:
				case ast::expr::Intrinsic::eSubgroupAdd2D:
				case ast::expr::Intrinsic::eSubgroupAdd3D:
				case ast::expr::Intrinsic::eSubgroupAdd4D:
					result = "subgroupAdd";
					break;

				case ast::expr::Intrinsic::eSubgroupMul1F:
				case ast::expr::Intrinsic::eSubgroupMul2F:
				case ast::expr::Intrinsic::eSubgroupMul3F:
				case ast::expr::Intrinsic::eSubgroupMul4F:
				case ast::expr::Intrinsic::eSubgroupMul1I:
				case ast::expr::Intrinsic::eSubgroupMul2I:
				case ast::expr::Intrinsic::eSubgroupMul3I:
				case ast::expr::Intrinsic::eSubgroupMul4I:
				case ast::expr::Intrinsic::eSubgroupMul1U:
				case ast::expr::Intrinsic::eSubgroupMul2U:
				case ast::expr::Intrinsic::eSubgroupMul3U:
				case ast::expr::Intrinsic::eSubgroupMul4U:
				case ast::expr::Intrinsic::eSubgroupMul1D:
				case ast::expr::Intrinsic::eSubgroupMul2D:
				case ast::expr::Intrinsic::eSubgroupMul3D:
				case ast::expr::Intrinsic::eSubgroupMul4D:
					result = "subgroupMul";
					break;

				case ast::expr::Intrinsic::eSubgroupMin1F:
				case ast::expr::Intrinsic::eSubgroupMin2F:
				case ast::expr::Intrinsic::eSubgroupMin3F:
				case ast::expr::Intrinsic::eSubgroupMin4F:
				case ast::expr::Intrinsic::eSubgroupMin1I:
				case ast::expr::Intrinsic::eSubgroupMin2I:
				case ast::expr::Intrinsic::eSubgroupMin3I:
				case ast::expr::Intrinsic::eSubgroupMin4I:
				case ast::expr::Intrinsic::eSubgroupMin1U:
				case ast::expr::Intrinsic::eSubgroupMin2U:
				case ast::expr::Intrinsic::eSubgroupMin3U:
				case ast::expr::Intrinsic::eSubgroupMin4U:
				case ast::expr::Intrinsic::eSubgroupMin1D:
				case ast::expr::Intrinsic::eSubgroupMin2D:
				case ast::expr::Intrinsic::eSubgroupMin3D:
				case ast::expr::Intrinsic::eSubgroupMin4D:
					result = "subgroupMin";
					break;

				case ast::expr::Intrinsic::eSubgroupMax1F:
				case ast::expr::Intrinsic::eSubgroupMax2F:
				case ast::expr::Intrinsic::eSubgroupMax3F:
				case ast::expr::Intrinsic::eSubgroupMax4F:
				case ast::expr::Intrinsic::eSubgroupMax1I:
				case ast::expr::Intrinsic::eSubgroupMax2I:
				case ast::expr::Intrinsic::eSubgroupMax3I:
				case ast::expr::Intrinsic::eSubgroupMax4I:
				case ast::expr::Intrinsic::eSubgroupMax1U:
				case ast::expr::Intrinsic::eSubgroupMax2U:
				case ast::expr::Intrinsic::eSubgroupMax3U:
				case ast::expr::Intrinsic::eSubgroupMax4U:
				case ast::expr::Intrinsic::eSubgroupMax1D:
				case ast::expr::Intrinsic::eSubgroupMax2D:
				case ast::expr::Intrinsic::eSubgroupMax3D:
				case ast::expr::Intrinsic::eSubgroupMax4D:
					result = "subgroupMax";
					break;

				case ast::expr::Intrinsic::eSubgroupAnd1I:
				case ast::expr::Intrinsic::eSubgroupAnd2I:
				case ast::expr::Intrinsic::eSubgroupAnd3I:
				case ast::expr::Intrinsic::eSubgroupAnd4I:
				case ast::expr::Intrinsic::eSubgroupAnd1U:
				case ast::expr::Intrinsic::eSubgroupAnd2U:
				case ast::expr::Intrinsic::eSubgroupAnd3U:
				case ast::expr::Intrinsic::eSubgroupAnd4U:
				case ast::expr::Intrinsic::eSubgroupAnd1B:
				case ast::expr::Intrinsic::eSubgroupAnd2B:
				case ast::expr::Intrinsic::eSubgroupAnd3B:
				case ast::expr::Intrinsic::eSubgroupAnd4B:
					result = "subgroupAnd";
					break;

				case ast::expr::Intrinsic::eSubgroupOr1I:
				case ast::expr::Intrinsic::eSubgroupOr2I:
				case ast::expr::Intrinsic::eSubgroupOr3I:
				case ast::expr::Intrinsic::eSubgroupOr4I:
				case ast::expr::Intrinsic::eSubgroupOr1U:
				case ast::expr::Intrinsic::eSubgroupOr2U:
				case ast::expr::Intrinsic::eSubgroupOr3U:
				case ast::expr::Intrinsic::eSubgroupOr4U:
				case ast::expr::Intrinsic::eSubgroupOr1B:
				case ast::expr::Intrinsic::eSubgroupOr2B:
				case ast::expr::Intrinsic::eSubgroupOr3B:
				case ast::expr::Intrinsic::eSubgroupOr4B:
					result = "subgroupOr";
					break;

				case ast::expr::Intrinsic::eSubgroupXor1I:
				case ast::expr::Intrinsic::eSubgroupXor2I:
				case ast::expr::Intrinsic::eSubgroupXor3I:
				case ast::expr::Intrinsic::eSubgroupXor4I:
				case ast::expr::Intrinsic::eSubgroupXor1U:
				case ast::expr::Intrinsic::eSubgroupXor2U:
				case ast::expr::Intrinsic::eSubgroupXor3U:
				case ast::expr::Intrinsic::eSubgroupXor4U:
				case ast::expr::Intrinsic::eSubgroupXor1B:
				case ast::expr::Intrinsic::eSubgroupXor2B:
				case ast::expr::Intrinsic::eSubgroupXor3B:
				case ast::expr::Intrinsic::eSubgroupXor4B:
					result = "subgroupXor";
					break;

				case ast::expr::Intrinsic::eSubgroupInclusiveAdd1F:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd2F:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd3F:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd4F:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd1I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd2I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd3I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd4I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd1U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd2U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd3U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd4U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd1D:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd2D:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd3D:
				case ast::expr::Intrinsic::eSubgroupInclusiveAdd4D:
					result = "subgroupInclusiveAdd";
					break;

				case ast::expr::Intrinsic::eSubgroupInclusiveMul1F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul2F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul3F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul4F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul1I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul2I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul3I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul4I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul1U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul2U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul3U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul4U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul1D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul2D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul3D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMul4D:
					result = "subgroupInclusiveMul";
					break;

				case ast::expr::Intrinsic::eSubgroupInclusiveMin1F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin2F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin3F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin4F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin1I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin2I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin3I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin4I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin1U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin2U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin3U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin4U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin1D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin2D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin3D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMin4D:
					result = "subgroupInclusiveMin";
					break;

				case ast::expr::Intrinsic::eSubgroupInclusiveMax1F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax2F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax3F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax4F:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax1I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax2I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax3I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax4I:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax1U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax2U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax3U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax4U:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax1D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax2D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax3D:
				case ast::expr::Intrinsic::eSubgroupInclusiveMax4D:
					result = "subgroupInclusiveMax";
					break;

				case ast::expr::Intrinsic::eSubgroupInclusiveAnd1I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd2I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd3I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd4I:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd1U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd2U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd3U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd4U:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd1B:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd2B:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd3B:
				case ast::expr::Intrinsic::eSubgroupInclusiveAnd4B:
					result = "subgroupInclusiveAnd";
					break;

				case ast::expr::Intrinsic::eSubgroupInclusiveOr1I:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr2I:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr3I:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr4I:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr1U:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr2U:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr3U:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr4U:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr1B:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr2B:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr3B:
				case ast::expr::Intrinsic::eSubgroupInclusiveOr4B:
					result = "subgroupInclusiveOr";
					break;

				case ast::expr::Intrinsic::eSubgroupInclusiveXor1I:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor2I:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor3I:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor4I:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor1U:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor2U:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor3U:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor4U:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor1B:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor2B:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor3B:
				case ast::expr::Intrinsic::eSubgroupInclusiveXor4B:
					result = "subgroupInclusiveXor";
					break;

				case ast::expr::Intrinsic::eSubgroupExclusiveAdd1F:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd2F:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd3F:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd4F:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd1I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd2I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd3I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd4I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd1U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd2U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd3U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd4U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd1D:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd2D:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd3D:
				case ast::expr::Intrinsic::eSubgroupExclusiveAdd4D:
					result = "subgroupExclusiveAdd";
					break;

				case ast::expr::Intrinsic::eSubgroupExclusiveMul1F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul2F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul3F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul4F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul1I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul2I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul3I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul4I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul1U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul2U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul3U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul4U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul1D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul2D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul3D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMul4D:
					result = "subgroupExclusiveMul";
					break;

				case ast::expr::Intrinsic::eSubgroupExclusiveMin1F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin2F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin3F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin4F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin1I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin2I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin3I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin4I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin1U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin2U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin3U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin4U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin1D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin2D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin3D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMin4D:
					result = "subgroupExclusiveMin";
					break;

				case ast::expr::Intrinsic::eSubgroupExclusiveMax1F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax2F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax3F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax4F:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax1I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax2I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax3I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax4I:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax1U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax2U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax3U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax4U:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax1D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax2D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax3D:
				case ast::expr::Intrinsic::eSubgroupExclusiveMax4D:
					result = "subgroupExclusiveMax";
					break;

				case ast::expr::Intrinsic::eSubgroupExclusiveAnd1I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd2I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd3I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd4I:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd1U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd2U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd3U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd4U:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd1B:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd2B:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd3B:
				case ast::expr::Intrinsic::eSubgroupExclusiveAnd4B:
					result = "subgroupExclusiveAnd";
					break;

				case ast::expr::Intrinsic::eSubgroupExclusiveOr1I:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr2I:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr3I:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr4I:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr1U:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr2U:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr3U:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr4U:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr1B:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr2B:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr3B:
				case ast::expr::Intrinsic::eSubgroupExclusiveOr4B:
					result = "subgroupExclusiveOr";
					break;

				case ast::expr::Intrinsic::eSubgroupExclusiveXor1I:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor2I:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor3I:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor4I:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor1U:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor2U:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor3U:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor4U:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor1B:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor2B:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor3B:
				case ast::expr::Intrinsic::eSubgroupExclusiveXor4B:
					result = "subgroupExclusiveXor";
					break;

				case ast::expr::Intrinsic::eSubgroupClusterAdd1F:
				case ast::expr::Intrinsic::eSubgroupClusterAdd2F:
				case ast::expr::Intrinsic::eSubgroupClusterAdd3F:
				case ast::expr::Intrinsic::eSubgroupClusterAdd4F:
				case ast::expr::Intrinsic::eSubgroupClusterAdd1I:
				case ast::expr::Intrinsic::eSubgroupClusterAdd2I:
				case ast::expr::Intrinsic::eSubgroupClusterAdd3I:
				case ast::expr::Intrinsic::eSubgroupClusterAdd4I:
				case ast::expr::Intrinsic::eSubgroupClusterAdd1U:
				case ast::expr::Intrinsic::eSubgroupClusterAdd2U:
				case ast::expr::Intrinsic::eSubgroupClusterAdd3U:
				case ast::expr::Intrinsic::eSubgroupClusterAdd4U:
				case ast::expr::Intrinsic::eSubgroupClusterAdd1D:
				case ast::expr::Intrinsic::eSubgroupClusterAdd2D:
				case ast::expr::Intrinsic::eSubgroupClusterAdd3D:
				case ast::expr::Intrinsic::eSubgroupClusterAdd4D:
					result = "subgroupClusterAdd";
					break;

				case ast::expr::Intrinsic::eSubgroupClusterMul1F:
				case ast::expr::Intrinsic::eSubgroupClusterMul2F:
				case ast::expr::Intrinsic::eSubgroupClusterMul3F:
				case ast::expr::Intrinsic::eSubgroupClusterMul4F:
				case ast::expr::Intrinsic::eSubgroupClusterMul1I:
				case ast::expr::Intrinsic::eSubgroupClusterMul2I:
				case ast::expr::Intrinsic::eSubgroupClusterMul3I:
				case ast::expr::Intrinsic::eSubgroupClusterMul4I:
				case ast::expr::Intrinsic::eSubgroupClusterMul1U:
				case ast::expr::Intrinsic::eSubgroupClusterMul2U:
				case ast::expr::Intrinsic::eSubgroupClusterMul3U:
				case ast::expr::Intrinsic::eSubgroupClusterMul4U:
				case ast::expr::Intrinsic::eSubgroupClusterMul1D:
				case ast::expr::Intrinsic::eSubgroupClusterMul2D:
				case ast::expr::Intrinsic::eSubgroupClusterMul3D:
				case ast::expr::Intrinsic::eSubgroupClusterMul4D:
					result = "subgroupClusterMul";
					break;

				case ast::expr::Intrinsic::eSubgroupClusterMin1F:
				case ast::expr::Intrinsic::eSubgroupClusterMin2F:
				case ast::expr::Intrinsic::eSubgroupClusterMin3F:
				case ast::expr::Intrinsic::eSubgroupClusterMin4F:
				case ast::expr::Intrinsic::eSubgroupClusterMin1I:
				case ast::expr::Intrinsic::eSubgroupClusterMin2I:
				case ast::expr::Intrinsic::eSubgroupClusterMin3I:
				case ast::expr::Intrinsic::eSubgroupClusterMin4I:
				case ast::expr::Intrinsic::eSubgroupClusterMin1U:
				case ast::expr::Intrinsic::eSubgroupClusterMin2U:
				case ast::expr::Intrinsic::eSubgroupClusterMin3U:
				case ast::expr::Intrinsic::eSubgroupClusterMin4U:
				case ast::expr::Intrinsic::eSubgroupClusterMin1D:
				case ast::expr::Intrinsic::eSubgroupClusterMin2D:
				case ast::expr::Intrinsic::eSubgroupClusterMin3D:
				case ast::expr::Intrinsic::eSubgroupClusterMin4D:
					result = "subgroupClusterMin";
					break;

				case ast::expr::Intrinsic::eSubgroupClusterMax1F:
				case ast::expr::Intrinsic::eSubgroupClusterMax2F:
				case ast::expr::Intrinsic::eSubgroupClusterMax3F:
				case ast::expr::Intrinsic::eSubgroupClusterMax4F:
				case ast::expr::Intrinsic::eSubgroupClusterMax1I:
				case ast::expr::Intrinsic::eSubgroupClusterMax2I:
				case ast::expr::Intrinsic::eSubgroupClusterMax3I:
				case ast::expr::Intrinsic::eSubgroupClusterMax4I:
				case ast::expr::Intrinsic::eSubgroupClusterMax1U:
				case ast::expr::Intrinsic::eSubgroupClusterMax2U:
				case ast::expr::Intrinsic::eSubgroupClusterMax3U:
				case ast::expr::Intrinsic::eSubgroupClusterMax4U:
				case ast::expr::Intrinsic::eSubgroupClusterMax1D:
				case ast::expr::Intrinsic::eSubgroupClusterMax2D:
				case ast::expr::Intrinsic::eSubgroupClusterMax3D:
				case ast::expr::Intrinsic::eSubgroupClusterMax4D:
					result = "subgroupClusterMax";
					break;

				case ast::expr::Intrinsic::eSubgroupClusterAnd1I:
				case ast::expr::Intrinsic::eSubgroupClusterAnd2I:
				case ast::expr::Intrinsic::eSubgroupClusterAnd3I:
				case ast::expr::Intrinsic::eSubgroupClusterAnd4I:
				case ast::expr::Intrinsic::eSubgroupClusterAnd1U:
				case ast::expr::Intrinsic::eSubgroupClusterAnd2U:
				case ast::expr::Intrinsic::eSubgroupClusterAnd3U:
				case ast::expr::Intrinsic::eSubgroupClusterAnd4U:
				case ast::expr::Intrinsic::eSubgroupClusterAnd1B:
				case ast::expr::Intrinsic::eSubgroupClusterAnd2B:
				case ast::expr::Intrinsic::eSubgroupClusterAnd3B:
				case ast::expr::Intrinsic::eSubgroupClusterAnd4B:
					result = "subgroupClusterAnd";
					break;

				case ast::expr::Intrinsic::eSubgroupClusterOr1I:
				case ast::expr::Intrinsic::eSubgroupClusterOr2I:
				case ast::expr::Intrinsic::eSubgroupClusterOr3I:
				case ast::expr::Intrinsic::eSubgroupClusterOr4I:
				case ast::expr::Intrinsic::eSubgroupClusterOr1U:
				case ast::expr::Intrinsic::eSubgroupClusterOr2U:
				case ast::expr::Intrinsic::eSubgroupClusterOr3U:
				case ast::expr::Intrinsic::eSubgroupClusterOr4U:
				case ast::expr::Intrinsic::eSubgroupClusterOr1B:
				case ast::expr::Intrinsic::eSubgroupClusterOr2B:
				case ast::expr::Intrinsic::eSubgroupClusterOr3B:
				case ast::expr::Intrinsic::eSubgroupClusterOr4B:
					result = "subgroupClusterOr";
					break;

				case ast::expr::Intrinsic::eSubgroupClusterXor1I:
				case ast::expr::Intrinsic::eSubgroupClusterXor2I:
				case ast::expr::Intrinsic::eSubgroupClusterXor3I:
				case ast::expr::Intrinsic::eSubgroupClusterXor4I:
				case ast::expr::Intrinsic::eSubgroupClusterXor1U:
				case ast::expr::Intrinsic::eSubgroupClusterXor2U:
				case ast::expr::Intrinsic::eSubgroupClusterXor3U:
				case ast::expr::Intrinsic::eSubgroupClusterXor4U:
				case ast::expr::Intrinsic::eSubgroupClusterXor1B:
				case ast::expr::Intrinsic::eSubgroupClusterXor2B:
				case ast::expr::Intrinsic::eSubgroupClusterXor3B:
				case ast::expr::Intrinsic::eSubgroupClusterXor4B:
					result = "subgroupClusterXor";
					break;

				case ast::expr::Intrinsic::eSubgroupQuadBroadcast1F:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast2F:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast3F:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast4F:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast1I:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast2I:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast3I:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast4I:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast1U:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast2U:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast3U:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast4U:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast1B:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast2B:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast3B:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast4B:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast1D:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast2D:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast3D:
				case ast::expr::Intrinsic::eSubgroupQuadBroadcast4D:
					result = "subgroupQuadBroadcast";
					break;

				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal1D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal2D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal3D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapHorizontal4D:
					result = "subgroupQuadSwapHorizontal";
					break;

				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical1D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical2D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical3D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapVertical4D:
					result = "subgroupQuadSwapVertical";
					break;

				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4F:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4I:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4U:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4B:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal1D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal2D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal3D:
				case ast::expr::Intrinsic::eSubgroupQuadSwapDiagonal4D:
					result = "subgroupQuadSwapDiagonal";
					break;

				case ast::expr::Intrinsic::eReadInvocation1F:
				case ast::expr::Intrinsic::eReadInvocation2F:
				case ast::expr::Intrinsic::eReadInvocation3F:
				case ast::expr::Intrinsic::eReadInvocation4F:
				case ast::expr::Intrinsic::eReadInvocation1I:
				case ast::expr::Intrinsic::eReadInvocation2I:
				case ast::expr::Intrinsic::eReadInvocation3I:
				case ast::expr::Intrinsic::eReadInvocation4I:
				case ast::expr::Intrinsic::eReadInvocation1U:
				case ast::expr::Intrinsic::eReadInvocation2U:
				case ast::expr::Intrinsic::eReadInvocation3U:
				case ast::expr::Intrinsic::eReadInvocation4U:
				case ast::expr::Intrinsic::eReadInvocation1D:
				case ast::expr::Intrinsic::eReadInvocation2D:
				case ast::expr::Intrinsic::eReadInvocation3D:
				case ast::expr::Intrinsic::eReadInvocation4D:
					result = "readInvocation";
					break;

				case ast::expr::Intrinsic::eReadFirstInvocation1F:
				case ast::expr::Intrinsic::eReadFirstInvocation2F:
				case ast::expr::Intrinsic::eReadFirstInvocation3F:
				case ast::expr::Intrinsic::eReadFirstInvocation4F:
				case ast::expr::Intrinsic::eReadFirstInvocation1I:
				case ast::expr::Intrinsic::eReadFirstInvocation2I:
				case ast::expr::Intrinsic::eReadFirstInvocation3I:
				case ast::expr::Intrinsic::eReadFirstInvocation4I:
				case ast::expr::Intrinsic::eReadFirstInvocation1U:
				case ast::expr::Intrinsic::eReadFirstInvocation2U:
				case ast::expr::Intrinsic::eReadFirstInvocation3U:
				case ast::expr::Intrinsic::eReadFirstInvocation4U:
				case ast::expr::Intrinsic::eReadFirstInvocation1D:
				case ast::expr::Intrinsic::eReadFirstInvocation2D:
				case ast::expr::Intrinsic::eReadFirstInvocation3D:
				case ast::expr::Intrinsic::eReadFirstInvocation4D:
					result = "readFirstInvocation";
					break;

				default:
					throw std::runtime_error{ "Unsupported Intrinsic type." };
				}

				return result;
			}

			inline std::string getIntrinsicName( ast::expr::StorageImageAccess value )
			{
				std::string result;

				switch ( value )
				{
			// Image Query Functions
				case ast::expr::StorageImageAccess::eImageSize1DF:
				case ast::expr::StorageImageAccess::eImageSize2DF:
				case ast::expr::StorageImageAccess::eImageSize3DF:
				case ast::expr::StorageImageAccess::eImageSizeCubeF:
				case ast::expr::StorageImageAccess::eImageSizeCubeArrayF:
				case ast::expr::StorageImageAccess::eImageSize2DRectF:
				case ast::expr::StorageImageAccess::eImageSize1DArrayF:
				case ast::expr::StorageImageAccess::eImageSize2DArrayF:
				case ast::expr::StorageImageAccess::eImageSizeBufferF:
				case ast::expr::StorageImageAccess::eImageSize2DMSF:
				case ast::expr::StorageImageAccess::eImageSize2DMSArrayF:
				case ast::expr::StorageImageAccess::eImageSize1DI:
				case ast::expr::StorageImageAccess::eImageSize2DI:
				case ast::expr::StorageImageAccess::eImageSize3DI:
				case ast::expr::StorageImageAccess::eImageSizeCubeI:
				case ast::expr::StorageImageAccess::eImageSizeCubeArrayI:
				case ast::expr::StorageImageAccess::eImageSize2DRectI:
				case ast::expr::StorageImageAccess::eImageSize1DArrayI:
				case ast::expr::StorageImageAccess::eImageSize2DArrayI:
				case ast::expr::StorageImageAccess::eImageSizeBufferI:
				case ast::expr::StorageImageAccess::eImageSize2DMSI:
				case ast::expr::StorageImageAccess::eImageSize2DMSArrayI:
				case ast::expr::StorageImageAccess::eImageSize1DU:
				case ast::expr::StorageImageAccess::eImageSize2DU:
				case ast::expr::StorageImageAccess::eImageSize3DU:
				case ast::expr::StorageImageAccess::eImageSizeCubeU:
				case ast::expr::StorageImageAccess::eImageSizeCubeArrayU:
				case ast::expr::StorageImageAccess::eImageSize2DRectU:
				case ast::expr::StorageImageAccess::eImageSize1DArrayU:
				case ast::expr::StorageImageAccess::eImageSize2DArrayU:
				case ast::expr::StorageImageAccess::eImageSizeBufferU:
				case ast::expr::StorageImageAccess::eImageSize2DMSU:
				case ast::expr::StorageImageAccess::eImageSize2DMSArrayU:
					result = "imageSize";
					break;

				case ast::expr::StorageImageAccess::eImageSamples2DMSF:
				case ast::expr::StorageImageAccess::eImageSamples2DMSArrayF:
				case ast::expr::StorageImageAccess::eImageSamples2DMSI:
				case ast::expr::StorageImageAccess::eImageSamples2DMSArrayI:
				case ast::expr::StorageImageAccess::eImageSamples2DMSU:
				case ast::expr::StorageImageAccess::eImageSamples2DMSArrayU:
					result = "imageSamples";
					break;


			// Image texel load
				case ast::expr::StorageImageAccess::eImageLoad1DF:
				case ast::expr::StorageImageAccess::eImageLoad2DF:
				case ast::expr::StorageImageAccess::eImageLoad3DF:
				case ast::expr::StorageImageAccess::eImageLoad2DRectF:
				case ast::expr::StorageImageAccess::eImageLoadCubeF:
				case ast::expr::StorageImageAccess::eImageLoadBufferF:
				case ast::expr::StorageImageAccess::eImageLoad1DArrayF:
				case ast::expr::StorageImageAccess::eImageLoad2DArrayF:
				case ast::expr::StorageImageAccess::eImageLoadCubeArrayF:
				case ast::expr::StorageImageAccess::eImageLoad2DMSF:
				case ast::expr::StorageImageAccess::eImageLoad2DMSArrayF:
				case ast::expr::StorageImageAccess::eImageLoad1DI:
				case ast::expr::StorageImageAccess::eImageLoad2DI:
				case ast::expr::StorageImageAccess::eImageLoad3DI:
				case ast::expr::StorageImageAccess::eImageLoad2DRectI:
				case ast::expr::StorageImageAccess::eImageLoadCubeI:
				case ast::expr::StorageImageAccess::eImageLoadBufferI:
				case ast::expr::StorageImageAccess::eImageLoad1DArrayI:
				case ast::expr::StorageImageAccess::eImageLoad2DArrayI:
				case ast::expr::StorageImageAccess::eImageLoadCubeArrayI:
				case ast::expr::StorageImageAccess::eImageLoad2DMSI:
				case ast::expr::StorageImageAccess::eImageLoad2DMSArrayI:
				case ast::expr::StorageImageAccess::eImageLoad1DU:
				case ast::expr::StorageImageAccess::eImageLoad2DU:
				case ast::expr::StorageImageAccess::eImageLoad3DU:
				case ast::expr::StorageImageAccess::eImageLoad2DRectU:
				case ast::expr::StorageImageAccess::eImageLoadCubeU:
				case ast::expr::StorageImageAccess::eImageLoadBufferU:
				case ast::expr::StorageImageAccess::eImageLoad1DArrayU:
				case ast::expr::StorageImageAccess::eImageLoad2DArrayU:
				case ast::expr::StorageImageAccess::eImageLoadCubeArrayU:
				case ast::expr::StorageImageAccess::eImageLoad2DMSU:
				case ast::expr::StorageImageAccess::eImageLoad2DMSArrayU:
					result = "imageLoad";
					break;


			// Image texel store
				case ast::expr::StorageImageAccess::eImageStore1DF:
				case ast::expr::StorageImageAccess::eImageStore2DF:
				case ast::expr::StorageImageAccess::eImageStore3DF:
				case ast::expr::StorageImageAccess::eImageStore2DRectF:
				case ast::expr::StorageImageAccess::eImageStoreCubeF:
				case ast::expr::StorageImageAccess::eImageStoreBufferF:
				case ast::expr::StorageImageAccess::eImageStore1DArrayF:
				case ast::expr::StorageImageAccess::eImageStore2DArrayF:
				case ast::expr::StorageImageAccess::eImageStoreCubeArrayF:
				case ast::expr::StorageImageAccess::eImageStore2DMSF:
				case ast::expr::StorageImageAccess::eImageStore2DMSArrayF:
				case ast::expr::StorageImageAccess::eImageStore1DI:
				case ast::expr::StorageImageAccess::eImageStore2DI:
				case ast::expr::StorageImageAccess::eImageStore3DI:
				case ast::expr::StorageImageAccess::eImageStore2DRectI:
				case ast::expr::StorageImageAccess::eImageStoreCubeI:
				case ast::expr::StorageImageAccess::eImageStoreBufferI:
				case ast::expr::StorageImageAccess::eImageStore1DArrayI:
				case ast::expr::StorageImageAccess::eImageStore2DArrayI:
				case ast::expr::StorageImageAccess::eImageStoreCubeArrayI:
				case ast::expr::StorageImageAccess::eImageStore2DMSI:
				case ast::expr::StorageImageAccess::eImageStore2DMSArrayI:
				case ast::expr::StorageImageAccess::eImageStore1DU:
				case ast::expr::StorageImageAccess::eImageStore2DU:
				case ast::expr::StorageImageAccess::eImageStore3DU:
				case ast::expr::StorageImageAccess::eImageStore2DRectU:
				case ast::expr::StorageImageAccess::eImageStoreCubeU:
				case ast::expr::StorageImageAccess::eImageStoreBufferU:
				case ast::expr::StorageImageAccess::eImageStore1DArrayU:
				case ast::expr::StorageImageAccess::eImageStore2DArrayU:
				case ast::expr::StorageImageAccess::eImageStoreCubeArrayU:
				case ast::expr::StorageImageAccess::eImageStore2DMSU:
				case ast::expr::StorageImageAccess::eImageStore2DMSArrayU:
					result = "imageStore";
					break;


			// Image atomics
				case ast::expr::StorageImageAccess::eImageAtomicAdd1DU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd3DU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicAddCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicAddBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAdd1DI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd3DI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicAddCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicAddBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicAdd1DF:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DF:
				case ast::expr::StorageImageAccess::eImageAtomicAdd3DF:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DRectF:
				case ast::expr::StorageImageAccess::eImageAtomicAddCubeF:
				case ast::expr::StorageImageAccess::eImageAtomicAddBufferF:
				case ast::expr::StorageImageAccess::eImageAtomicAdd1DArrayF:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DArrayF:
				case ast::expr::StorageImageAccess::eImageAtomicAddCubeArrayF:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSF:
				case ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF:
					result = "imageAtomicAdd";
					break;

				case ast::expr::StorageImageAccess::eImageAtomicMin1DU:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DU:
				case ast::expr::StorageImageAccess::eImageAtomicMin3DU:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicMinCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicMinBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicMin1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMinCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMin1DI:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DI:
				case ast::expr::StorageImageAccess::eImageAtomicMin3DI:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicMinCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicMinBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicMin1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicMinCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayI:
					result = "imageAtomicMin";
					break;

				case ast::expr::StorageImageAccess::eImageAtomicMax1DU:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DU:
				case ast::expr::StorageImageAccess::eImageAtomicMax3DU:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicMaxCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicMaxBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicMax1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMaxCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicMax1DI:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DI:
				case ast::expr::StorageImageAccess::eImageAtomicMax3DI:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicMaxCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicMaxBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicMax1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicMaxCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayI:
					result = "imageAtomicMax";
					break;

				case ast::expr::StorageImageAccess::eImageAtomicAnd1DU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd3DU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicAndCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicAndBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAndCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicAnd1DI:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DI:
				case ast::expr::StorageImageAccess::eImageAtomicAnd3DI:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicAndCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicAndBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicAnd1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicAndCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayI:
					result = "imageAtomicAnd";
					break;

				case ast::expr::StorageImageAccess::eImageAtomicOr1DU:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DU:
				case ast::expr::StorageImageAccess::eImageAtomicOr3DU:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicOrCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicOrBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicOr1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicOrCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicOr1DI:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DI:
				case ast::expr::StorageImageAccess::eImageAtomicOr3DI:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicOrCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicOrBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicOr1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicOrCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayI:
					result = "imageAtomicOr";
					break;

				case ast::expr::StorageImageAccess::eImageAtomicXor1DU:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DU:
				case ast::expr::StorageImageAccess::eImageAtomicXor3DU:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicXorCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicXorBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicXor1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicXorCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicXor1DI:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DI:
				case ast::expr::StorageImageAccess::eImageAtomicXor3DI:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicXorCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicXorBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicXor1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicXorCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayI:
					result = "imageAtomicXor";
					break;

				case ast::expr::StorageImageAccess::eImageAtomicExchange1DU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange3DU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicExchange1DI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange3DI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicExchange1DF:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DF:
				case ast::expr::StorageImageAccess::eImageAtomicExchange3DF:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DRectF:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeF:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeBufferF:
				case ast::expr::StorageImageAccess::eImageAtomicExchange1DArrayF:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DArrayF:
				case ast::expr::StorageImageAccess::eImageAtomicExchangeCubeArrayF:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSF:
				case ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF:
					result = "imageAtomicExchange";
					break;

				case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap3DU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DRectU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwapBufferU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayU:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap3DI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DRectI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwapBufferI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap1DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSI:
				case ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayI:
					result = "imageAtomicCompSwap";
					break;

				default:
					throw std::runtime_error{ "Unsupported StorageImageAccess type." };
				}

				return result;
			}

			bool isScopeBeginStatement( DebugStatementType value )
			{
				switch ( value )
				{
				case spirv::debug::DebugStatementType::eNone:
				case spirv::debug::DebugStatementType::eStructureDecl:
				case spirv::debug::DebugStatementType::eStructureMemberDecl:
				case spirv::debug::DebugStatementType::eFunctionDecl:
				case spirv::debug::DebugStatementType::eVariableDecl:
				case spirv::debug::DebugStatementType::eScopeLine:
				case spirv::debug::DebugStatementType::eStructureScopeEnd:
				case spirv::debug::DebugStatementType::eFunctionScopeEnd:
				case spirv::debug::DebugStatementType::eLexicalScopeEnd:
				case spirv::debug::DebugStatementType::eControlBegin:
				case spirv::debug::DebugStatementType::eControlEnd:
					return false;
				case spirv::debug::DebugStatementType::eStructureScopeBegin:
				case spirv::debug::DebugStatementType::eFunctionScopeBegin:
				case spirv::debug::DebugStatementType::eLexicalScopeBegin:
					return true;
				default:
					AST_Failure( "Unsupported DebugStatementType." );
					return false;
				}
			}

			bool isScopeEndStatement( DebugStatementType value )
			{
				switch ( value )
				{
				case spirv::debug::DebugStatementType::eNone:
				case spirv::debug::DebugStatementType::eStructureDecl:
				case spirv::debug::DebugStatementType::eStructureMemberDecl:
				case spirv::debug::DebugStatementType::eFunctionDecl:
				case spirv::debug::DebugStatementType::eVariableDecl:
				case spirv::debug::DebugStatementType::eScopeLine:
				case spirv::debug::DebugStatementType::eStructureScopeBegin:
				case spirv::debug::DebugStatementType::eFunctionScopeBegin:
				case spirv::debug::DebugStatementType::eLexicalScopeBegin:
				case spirv::debug::DebugStatementType::eControlBegin:
					return false;
				case spirv::debug::DebugStatementType::eStructureScopeEnd:
				case spirv::debug::DebugStatementType::eFunctionScopeEnd:
				case spirv::debug::DebugStatementType::eLexicalScopeEnd:
				case spirv::debug::DebugStatementType::eControlEnd:
					return true;
				default:
					AST_Failure( "Unsupported DebugStatementType." );
					return false;
				}
			}

			bool isScopeDeclStatement( DebugStatementType value )
			{
				switch ( value )
				{
				case spirv::debug::DebugStatementType::eNone:
				case spirv::debug::DebugStatementType::eScopeLine:
				case spirv::debug::DebugStatementType::eStructureScopeBegin:
				case spirv::debug::DebugStatementType::eStructureScopeEnd:
				case spirv::debug::DebugStatementType::eFunctionScopeBegin:
				case spirv::debug::DebugStatementType::eFunctionScopeEnd:
				case spirv::debug::DebugStatementType::eLexicalScopeBegin:
				case spirv::debug::DebugStatementType::eLexicalScopeEnd:
				case spirv::debug::DebugStatementType::eStructureMemberDecl:
				case spirv::debug::DebugStatementType::eVariableDecl:
				case spirv::debug::DebugStatementType::eControlEnd:
					return false;
				case spirv::debug::DebugStatementType::eStructureDecl:
				case spirv::debug::DebugStatementType::eFunctionDecl:
				case spirv::debug::DebugStatementType::eControlBegin:
					return true;
				default:
					AST_Failure( "Unsupported DebugStatementType." );
					return false;
				}
			}
		}

		//*****************************************************************************************

		class ExprVisitor
			: public ast::expr::SimpleVisitor
		{
		public:
			static std::string submit( ast::expr::Expr * expr )
			{
				std::string result;
				ExprVisitor vis{ result };
				expr->accept( &vis );
				return result;
			}

		private:
			static void submit( ast::expr::Expr * expr
				, std::string & result )
			{
				ExprVisitor vis{ result };
				expr->accept( &vis );
			}

			ExprVisitor( std::string & result )
				: m_result{ result }
			{
			}

			void doSubmit( ast::expr::Expr * expr )
			{
				submit( expr, m_result );
			}

			void doSubmit( ast::expr::ExprPtr const & expr )
			{
				doSubmit( expr.get() );
			}

			void wrap( ast::expr::Expr * expr )
			{
				bool noParen = expr->getKind() == ast::expr::Kind::eFnCall
					|| expr->getKind() == ast::expr::Kind::eIdentifier
					|| expr->getKind() == ast::expr::Kind::eLiteral
					|| expr->getKind() == ast::expr::Kind::eMbrSelect
					|| expr->getKind() == ast::expr::Kind::eCast
					|| expr->getKind() == ast::expr::Kind::eSwizzle
					|| expr->getKind() == ast::expr::Kind::eArrayAccess
					|| expr->getKind() == ast::expr::Kind::eIntrinsicCall
					|| expr->getKind() == ast::expr::Kind::eCombinedImageAccessCall
					|| expr->getKind() == ast::expr::Kind::eImageAccessCall
					|| expr->getKind() == ast::expr::Kind::eUnaryMinus
					|| expr->getKind() == ast::expr::Kind::eUnaryPlus
					|| expr->getKind() == ast::expr::Kind::eCopy;

				if ( noParen )
				{
					doSubmit( expr );
				}
				else
				{
					m_result += "(";
					doSubmit( expr );
					m_result += ")";
				}
			}

			void visitAssignmentExpr( ast::expr::Binary * expr )
			{
				wrap( expr->getLHS() );
				m_result += " " + helpers::getOperatorName( expr->getKind() ) + " ";
				doSubmit( expr->getRHS() );
			}

			void visitUnaryExpr( ast::expr::Unary * expr )override
			{
				if ( expr->isNonUniform()
					&& !expr->getOperand()->isNonUniform() )
				{
					m_result += "nonuniformEXT(";
				}

				if ( helpers::isUnaryPre( expr->getKind() ) )
				{
					m_result += helpers::getOperatorName( expr->getKind() );
					wrap( expr->getOperand() );
				}
				else
				{
					wrap( expr->getOperand() );
					m_result += helpers::getOperatorName( expr->getKind() );
				}

				if ( expr->isNonUniform()
					&& !expr->getOperand()->isNonUniform() )
				{
					m_result += ")";
				}

			}

			void visitBinaryExpr( ast::expr::Binary * expr )override
			{
				wrap( expr->getLHS() );
				m_result += " " + helpers::getOperatorName( expr->getKind() ) + " ";
				wrap( expr->getRHS() );
			}

			void visitAddAssignExpr( ast::expr::AddAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAndAssignExpr( ast::expr::AndAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAssignExpr( ast::expr::Assign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitDivideAssignExpr( ast::expr::DivideAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitLShiftAssignExpr( ast::expr::LShiftAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitMinusAssignExpr( ast::expr::MinusAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitModuloAssignExpr( ast::expr::ModuloAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitOrAssignExpr( ast::expr::OrAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitRShiftAssignExpr( ast::expr::RShiftAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitTimesAssignExpr( ast::expr::TimesAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitXorAssignExpr( ast::expr::XorAssign * expr )override
			{
				visitAssignmentExpr( expr );
			}

			void visitAggrInitExpr( ast::expr::AggrInit * expr )override
			{
				if ( expr->getIdentifier() )
				{
					if ( expr->isConstant() )
					{
						m_result += "const ";
					}

					m_result += getTypeName( expr->getType() ) + " ";
					doSubmit( expr->getIdentifier() );
					m_result += helpers::getTypeArraySize( expr->getType() );
					m_result += " = ";
				}

				m_result += getTypeName( expr->getType() ) + "[](";
				std::string sep;

				for ( auto & init : expr->getInitialisers() )
				{
					m_result += sep;
					doSubmit( init );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitArrayAccessExpr( ast::expr::ArrayAccess * expr )override
			{
				wrap( expr->getLHS() );
				m_result += "[";
				wrap( expr->getRHS() );
				m_result += "]";
			}

			void visitCastExpr( ast::expr::Cast * expr )override
			{
				m_result += getTypeName( expr->getType() ) + "(";
				doSubmit( expr->getOperand() );
				m_result += ")";
			}

			void visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )override
			{
				if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
				{
					m_result += helpers::getCtorName( *expr->getArgList()[0]
						, *expr->getArgList()[1] );
				}
				else
				{
					m_result += helpers::getCtorName( expr->getComposite()
						, getScalarType( expr->getComponent() ) );
				}

				m_result += "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitMbrSelectExpr( ast::expr::MbrSelect * expr )override
			{
				wrap( expr->getOuterExpr() );

				if ( !m_result.empty() )
				{
					m_result += ".";
				}

				auto mbr = expr->getOuterType()->getMember( expr->getMemberIndex() );

				if ( mbr.builtin != ast::Builtin::eNone )
				{
					m_result += "gl_" + getName( mbr.builtin );
				}
				else
				{
					m_result += mbr.name;
				}
			}

			void visitFnCallExpr( ast::expr::FnCall * expr )override
			{
				if ( expr->isMember() )
				{
					wrap( expr->getInstance() );
					m_result += ".";
				}

				doSubmit( expr->getFn() );
				m_result += "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			std::string visitVariable( ast::var::VariablePtr var )
			{
				return var->getOuter()
					? visitVariable( var->getOuter() ) + "." + var->getName()
					: var->getName();
			}

			void visitIdentifierExpr( ast::expr::Identifier * expr )override
			{
				m_result += visitVariable( expr->getVariable() );
			}

			void visitImageAccessCallExpr( ast::expr::StorageImageAccessCall * expr )override
			{
				m_result += helpers::getIntrinsicName( expr->getImageAccess() ) + "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitInitExpr( ast::expr::Init * expr )override
			{
				if ( expr->isConstant() )
				{
					m_result += "const ";
				}

				m_result += getTypeName( expr->getType() ) + " ";
				doSubmit( expr->getIdentifier() );
				m_result += helpers::getTypeArraySize( expr->getIdentifier()->getType() );
				m_result += " = ";
				doSubmit( expr->getInitialiser() );
			}

			void visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )override
			{
				if ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier
					|| expr->getIntrinsic() == ast::expr::Intrinsic::eMemoryBarrier )
				{
					ast::type::Scope memory;
					ast::type::MemorySemantics semantics;
					bool isControlBarrier = ( expr->getIntrinsic() == ast::expr::Intrinsic::eControlBarrier );

					if ( isControlBarrier )
					{
						if ( expr->getArgList().size() < 3u )
						{
							throw std::runtime_error{ "Wrong number of parameters for a control barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
						semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[2] ) );
					}
					else
					{
						if ( expr->getArgList().size() < 2u )
						{
							throw std::runtime_error{ "Wrong number of parameters for a memory barrier" };
						}

						memory = ast::type::Scope( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[0] ) );
						semantics = ast::type::MemorySemantics( getLiteralValue< ast::expr::LiteralType::eUInt32 >( expr->getArgList()[1] ) );
					}

					if ( memory == ast::type::Scope::eWorkgroup )
					{
						if ( helpers::checkAllMemoryBarrier( semantics ) )
						{
							m_result = "groupMemoryBarrier()";
						}
						else
						{
							m_result = "barrier()";
						}
					}
					else if ( memory == ast::type::Scope::eSubgroup )
					{
						if ( helpers::checkAllMemoryBarrier( semantics ) )
						{
							if ( isControlBarrier )
							{
								m_result = "subgroupBarrier()";
							}
							else
							{
								m_result = "subgroupMemoryBarrier()";
							}
						}
						else if ( helpers::checkBufferMemoryBarrier( semantics ) )
						{
							m_result = "subgroupMemoryBarrierBuffer()";
						}
						else if ( helpers::checkSharedMemoryBarrier( semantics ) )
						{
							m_result = "subgroupMemoryBarrierShared()";
						}
						else if ( helpers::checkImageMemoryBarrier( semantics ) )
						{
							m_result = "subgroupMemoryBarrierImage()";
						}
						else
						{
							m_result = "subgroupBarrier()";
						}
					}
					else
					{
						if ( helpers::checkAllMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrier()";
						}
						else if ( helpers::checkBufferMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrierBuffer()";
						}
						else if ( helpers::checkSharedMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrierShared()";
						}
						else if ( helpers::checkImageMemoryBarrier( semantics ) )
						{
							m_result = "memoryBarrierImage()";
						}
						else
						{
							m_result = "barrier()";
						}
					}
				}
				else
				{
					m_result += helpers::getIntrinsicName( expr->getIntrinsic() ) + "(";
					std::string sep;

					for ( auto & arg : expr->getArgList() )
					{
						m_result += sep;
						doSubmit( arg );
						sep = ", ";
					}

					m_result += ")";
				}
			}

			void visitLiteralExpr( ast::expr::Literal * expr )override
			{
				std::locale loc{ "C" };
				std::stringstream stream;
				stream.imbue( loc );

				switch ( expr->getLiteralType() )
				{
				case ast::expr::LiteralType::eBool:
					stream << ( expr->getValue< ast::expr::LiteralType::eBool >()
						? std::string{ "true" }
					: std::string{ "false" } );
					break;
				case ast::expr::LiteralType::eInt8:
					stream << "int8_t(" << int16_t( expr->getValue< ast::expr::LiteralType::eInt8 >() ) << ")";
					break;
				case ast::expr::LiteralType::eInt16:
					stream << "int16_t(" << expr->getValue< ast::expr::LiteralType::eInt16 >() << ")";
					break;
				case ast::expr::LiteralType::eInt32:
					stream << expr->getValue< ast::expr::LiteralType::eInt32 >();
					break;
				case ast::expr::LiteralType::eInt64:
					stream << expr->getValue< ast::expr::LiteralType::eInt64 >() << "l";
					break;
				case ast::expr::LiteralType::eUInt8:
					stream << "uint8_t(" << uint16_t( expr->getValue< ast::expr::LiteralType::eUInt8 >() ) << "u)";
					break;
				case ast::expr::LiteralType::eUInt16:
					stream << "uint16_t(" << expr->getValue< ast::expr::LiteralType::eUInt16 >() << "u)";
					break;
				case ast::expr::LiteralType::eUInt32:
					stream << expr->getValue< ast::expr::LiteralType::eUInt32 >() << "u";
					break;
				case ast::expr::LiteralType::eUInt64:
					stream << expr->getValue< ast::expr::LiteralType::eUInt64 >() << "ul";
					break;
				case ast::expr::LiteralType::eFloat:
				{
					auto v = expr->getValue< ast::expr::LiteralType::eFloat >();
					stream << std::setprecision( 12u ) << v;

					if ( v == std::floor( v )
						&& stream.str().find( 'e' ) == std::string::npos )
					{
						stream << ".0";
					}

					stream << "f";
				}
				break;
				case ast::expr::LiteralType::eDouble:
				{
					auto v = expr->getValue< ast::expr::LiteralType::eDouble >();
					stream << std::setprecision( 16u ) << v;

					if ( v == std::floor( v )
						&& stream.str().find( 'e' ) == std::string::npos )
					{
						stream << ".0";
					}
				}
				break;
				default:
					AST_Failure( "Unsupported literal type" );
					break;
				}

				m_result += stream.str();
			}

			void visitQuestionExpr( ast::expr::Question * expr )override
			{
				m_result += "(";
				wrap( expr->getCtrlExpr() );
				m_result += " ? ";
				wrap( expr->getTrueExpr() );
				m_result += " : ";
				wrap( expr->getFalseExpr() );
				m_result += ")";
			}

			void visitStreamAppendExpr( ast::expr::StreamAppend * expr )override
			{
				AST_Failure( "Unexpected ast::expr::StreamAppend expression." );
			}

			void visitSwitchCaseExpr( ast::expr::SwitchCase * expr )override
			{
				doSubmit( expr->getLabel() );
			}

			void visitSwitchTestExpr( ast::expr::SwitchTest * expr )override
			{
				doSubmit( expr->getValue() );
			}

			void visitSwizzleExpr( ast::expr::Swizzle * expr )override
			{
				wrap( expr->getOuterExpr() );
				m_result += "." + getName( expr->getSwizzle() );
			}

			void visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )override
			{
				m_result += helpers::getIntrinsicName( expr->getCombinedImageAccess() ) + "(";
				std::string sep;

				for ( auto & arg : expr->getArgList() )
				{
					m_result += sep;
					doSubmit( arg );
					sep = ", ";
				}

				m_result += ")";
			}

			void visitAliasExpr( ast::expr::Alias * expr )override
			{
				doSubmit( expr->getLHS() );
				m_result += " = ";
				doSubmit( expr->getRHS() );
			}

		private:
			std::string & m_result;
		};

		//*****************************************************************************************

		class StmtDebugVisitor
			: public ast::stmt::Visitor
		{
		public:
			static DebugStatements submit( ast::ShaderStage shaderStage
				, ast::stmt::Stmt * stmt )
			{
				DebugStatements result{ std::string{}, DebugStatementsList{ &stmt->getStmtCache().getAllocator() } };
				submit( shaderStage, stmt, result );
				return result;
			}

		private:
			static void submit( ast::ShaderStage shaderStage
				, ast::stmt::Stmt * stmt
				, DebugStatements & result )
			{
				StmtDebugVisitor vis{ shaderStage, result };
				stmt->accept( &vis );
			}

			StmtDebugVisitor( ast::ShaderStage shaderStage
				, DebugStatements & result )
				: m_shaderStage{ shaderStage }
				, m_result{ result }
			{
			}

			std::string doSubmit( ast::expr::Expr * expr )
			{
				return debug::ExprVisitor::submit( expr );
			}

			ast::stmt::Stmt * getCurrentScope()
			{
				return m_scopes.back();
			}

			void doAddStatement( std::string text
				, DebugStatementType type
				, ast::stmt::Stmt * stmt
				, ast::stmt::Stmt * scope = nullptr )
			{
				if ( helpers::isScopeEndStatement( m_lastStmtType )
					&& !helpers::isScopeEndStatement( type ) )
				{
					++m_currentLine;
					m_result.source += "\n";
				}
				else if ( helpers::isScopeDeclStatement( type )
					&& !helpers::isScopeBeginStatement( m_lastStmtType ) )
				{
					++m_currentLine;
					m_result.source += "\n";
				}

				DebugStatement current;
				current.type = type;
				current.stmt = stmt;
				auto length = uint32_t( text.size() );
				m_result.source += m_indents.back() + std::move( text ) + "\n";
				current.source.lineStart = m_currentLine;
				current.source.columnStart = uint32_t( m_indents.back().size() );
				current.source.columnEnd = current.source.columnStart + length;
				current.source.scope = scope ? scope : getCurrentScope();
				m_result.statements.push_back( std::move( current ) );

				++m_currentLine;
				m_lastStmtType = type;
				m_currentText.clear();
			}

			void doAddSimpleStatement( std::string const & text
				, ast::stmt::Stmt * stmt )
			{
				doAddStatement( text + ";", m_scopeLines.back(), stmt );
			}

			void doAddVariableDeclStatement( std::string const & text
				, ast::stmt::Stmt * stmt )
			{
				doAddStatement( text + ";", DebugStatementType::eVariableDecl, stmt );
			}

			void doBeginScope( ast::stmt::Stmt * stmt
				, DebugStatementType scopeBegin
				, DebugStatementType scopeLine )
			{
				m_scopes.push_back( stmt );
				doAddStatement( "{", scopeBegin, stmt, stmt );
				m_scopeLines.push_back( scopeLine );
				m_indents.push_back( m_indents.back() + "    " );
			}

			void doEndScope( ast::stmt::Stmt * stmt
				, DebugStatementType scopeEnd )
			{
				m_indents.pop_back();
				m_scopeLines.pop_back();

				if ( scopeEnd == DebugStatementType::eStructureDecl )
				{
					doAddStatement( "};", scopeEnd, stmt, stmt );
				}
				else
				{
					doAddStatement( "}", scopeEnd, stmt, stmt );
				}

				m_scopes.pop_back();
			}

			void doParseScope( ast::stmt::Compound * stmt
				, DebugStatementType scopeBegin
				, DebugStatementType scopeLine
				, DebugStatementType scopeEnd )
			{
				doBeginScope( stmt, scopeBegin, scopeLine );
				visitCompoundStmt( stmt );
				doEndScope( stmt, scopeEnd );
			}

			void doParseStruct( ast::stmt::Stmt * stmt
				, ast::type::Struct const & structType )
			{
				if ( structType.empty() )
				{
					return;
				}

				doAddStatement( "struct " + structType.getName(), DebugStatementType::eStructureDecl, stmt );
				doBeginScope( stmt, DebugStatementType::eStructureScopeBegin, DebugStatementType::eStructureMemberDecl );

				for ( auto & mbr : structType )
				{
					std::string text;

					if ( mbr.location != ast::type::Struct::InvalidLocation
						&& !hasFlag( structType.getFlag(), ast::var::Flag::ePatchOutput )
						&& !hasFlag( structType.getFlag(), ast::var::Flag::ePatchInput ) )
					{
						text += "layout( location=" + helpers::writeValue( mbr.location ) + " ) ";
						text += ( structType.isShaderInput()
							? std::string{ "in" }
						: std::string{ "out" } ) + " ";
					}

					text += getTypeName( mbr.type ) + " " + mbr.name;
					text += helpers::getTypeArraySize( mbr.type );
					doAddSimpleStatement( std::move( text ), stmt );
				}

				doEndScope( stmt, DebugStatementType::eStructureScopeEnd );
			}

			void visitContainerStmt( ast::stmt::Container * stmt )override
			{
				for ( auto & curStmt : *stmt )
				{
					curStmt->accept( this );
				}
			}

			void visitBreakStmt( ast::stmt::Break * stmt )override
			{
				doAddSimpleStatement( "break", stmt );
			}

			void visitContinueStmt( ast::stmt::Continue * stmt )override
			{
				doAddSimpleStatement( "continue", stmt );
			}

			void visitConstantBufferDeclStmt( ast::stmt::ConstantBufferDecl * stmt )override
			{
				if ( !stmt->empty() )
				{
					doAddStatement( "struct " + stmt->getName() + "Block", DebugStatementType::eStructureDecl, stmt );
					doParseScope( stmt
						, DebugStatementType::eStructureScopeBegin
						, DebugStatementType::eStructureMemberDecl
						, DebugStatementType::eStructureScopeEnd );
					std::string text = "layout(";
					text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
					doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
					text += ") uniform " + stmt->getName() + "Block " + stmt->getName();
					doAddVariableDeclStatement( std::move( text ), stmt );
				}
			}

			void visitDemoteStmt( ast::stmt::Demote * stmt )override
			{
				doAddSimpleStatement( "demote", stmt );
			}

			void visitDispatchMeshStmt( ast::stmt::DispatchMesh * stmt )override
			{
				std::string text = "EmitMeshTasks";
				text += "(";
				text += doSubmit( stmt->getNumGroupsX() );
				text += ", ";
				text += doSubmit( stmt->getNumGroupsY() );
				text += ", ";
				text += doSubmit( stmt->getNumGroupsZ() );
				text += ")";
				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitTerminateInvocationStmt( ast::stmt::TerminateInvocation * stmt )override
			{
				doAddSimpleStatement( "terminate", stmt );
			}

			void visitPushConstantsBufferDeclStmt( ast::stmt::PushConstantsBufferDecl * stmt )override
			{
				if ( !stmt->empty() )
				{
					doAddStatement( "struct " + stmt->getName() + "Block", DebugStatementType::eStructureDecl, stmt );
					doParseScope( stmt
						, DebugStatementType::eStructureScopeBegin
						, DebugStatementType::eStructureMemberDecl
						, DebugStatementType::eStructureScopeEnd );
					std::string text = "layout(push_constant) ";
					text += "uniform " + stmt->getName() + "Block " + stmt->getName();
					doAddVariableDeclStatement( std::move( text ), stmt );
				}
			}

			void visitCommentStmt( ast::stmt::Comment * stmt )override
			{
			}

			void visitCompoundStmt( ast::stmt::Compound * stmt )override
			{
				visitContainerStmt( stmt );
			}

			void visitDoWhileStmt( ast::stmt::DoWhile * stmt )override
			{
				doAddStatement( "do", DebugStatementType::eControlBegin, stmt, stmt );
				doParseScope( stmt
					, DebugStatementType::eLexicalScopeBegin
					, DebugStatementType::eScopeLine
					, DebugStatementType::eLexicalScopeEnd );
				std::string text = "while (";
				text += doSubmit( stmt->getCtrlExpr() );
				text += ");";
				doAddStatement( std::move( text ), DebugStatementType::eControlEnd, stmt, stmt );
			}

			void visitElseIfStmt( ast::stmt::ElseIf * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else * stmt )override
			{
				doAddStatement( "else", DebugStatementType::eControlBegin, stmt, stmt );
				doParseScope( stmt
					, DebugStatementType::eLexicalScopeBegin
					, DebugStatementType::eScopeLine
					, DebugStatementType::eLexicalScopeEnd );
			}

			void visitForStmt( ast::stmt::For * stmt )override
			{
				AST_Failure( "Unexpected For statement." );
			}

			void visitFragmentLayoutStmt( ast::stmt::FragmentLayout * stmt )override
			{
				std::string origin = helpers::getLayoutName( stmt->getFragmentOrigin() );
				std::string center = helpers::getLayoutName( stmt->getFragmentCenter() );

				if ( !origin.empty() || !center.empty() )
				{
					std::string text = "layout(";
					text += origin;
					text += ( ( origin.empty() || center.empty() )
						? std::string{}
						: std::string{ ", " } );
					text += center;
					text += ") in vec4 gl_FragCoord";
					doAddVariableDeclStatement( std::move( text ), stmt );
				}
			}

			void visitFunctionDeclStmt( ast::stmt::FunctionDecl * stmt )override
			{
				auto type = stmt->getType();
				std::string text = getTypeName( type->getReturnType() );
				text += " " + stmt->getName() + "(";
				std::string sep;

				for ( auto & param : *type )
				{
					text += sep + helpers::getDirectionName( *param )
						+ " " + getTypeName( param->getType() )
						+ " " + param->getName() + helpers::getTypeArraySize( param->getType() );
					sep = ", ";
				}

				text += ")";
				doAddStatement( std::move( text ), DebugStatementType::eFunctionDecl, stmt );
				doParseScope( stmt
					, DebugStatementType::eFunctionScopeBegin
					, DebugStatementType::eScopeLine
					, DebugStatementType::eFunctionScopeEnd );
			}

			void visitHitAttributeVariableDeclStmt( ast::stmt::HitAttributeVariableDecl * stmt )override
			{
				std::string text = "hitAttribute";
				helpers::join( text, getTypeName( stmt->getVariable()->getType() ), " " );
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitIfStmt( ast::stmt::If * stmt )override
			{
				std::string text = "if (";
				text += doSubmit( stmt->getCtrlExpr() );
				text += ")";
				doAddStatement( std::move( text ), DebugStatementType::eControlBegin, stmt, stmt );
				doParseScope( stmt
					, DebugStatementType::eLexicalScopeBegin
					, DebugStatementType::eScopeLine
					, DebugStatementType::eLexicalScopeEnd );

				if ( stmt->getElse() )
				{
					stmt->getElse()->accept( this );
				}
			}

			void visitImageDeclStmt( ast::stmt::ImageDecl * stmt )override
			{
				auto type = stmt->getVariable()->getType();

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					type = std::static_pointer_cast< ast::type::Array >( type )->getType();
				}

				assert( type->getKind() == ast::type::Kind::eImage );
				auto image = std::static_pointer_cast< ast::type::Image >( type );
				std::string text = "layout(";
				text += helpers::getFormatName( image->getConfig().format );
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				text += ") ";
				text += "uniform ";
				//text += getAccessQualifierName( image->getConfig() ) + " ";
				text += helpers::getQualifiedName( ast::type::Kind::eImage, image->getConfig() ) + " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitIgnoreIntersectionStmt( ast::stmt::IgnoreIntersection * stmt )override
			{
				doAddSimpleStatement( "ignoreIntersection", stmt );
			}

			void visitBufferReferenceDeclStmt( ast::stmt::BufferReferenceDecl * stmt )override
			{
				std::string text = "layout(buffer_reference";

				if ( auto structType = getStructType( stmt->getType() ) )
				{
					text += ", " + helpers::getMemoryLayoutName( structType->getMemoryLayout() );
					text += ") buffer " + getTypeName( stmt->getType() ) + " { ";
					text += getTypeName( structType->front().type ) + " " + structType->front().name + helpers::getTypeArraySize( structType->front().type ) + "; }";
				}
				else
				{
					text += ") buffer " + getTypeName( stmt->getType() ) + "s { ";
					text += getTypeName( stmt->getType() ) + helpers::getTypeArraySize( stmt->getType() ) + "; }";
				}

				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitAccelerationStructureDeclStmt( ast::stmt::AccelerationStructureDecl * stmt )override
			{
				std::string text = "layout(";
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
				text += ") uniform accelerationStructure";
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitInOutCallableDataVariableDeclStmt( ast::stmt::InOutCallableDataVariableDecl * stmt )override
			{
				auto var = stmt->getVariable();
				std::string name = "callableData";

				if ( var->isIncomingCallableData() )
				{
					name = "callableDataIn";
				}

				std::string text = "layout(" + helpers::getLocationName( *var ) + "=" + helpers::writeValue( stmt->getLocation() ) + ")";
				helpers::join( text, name, " " );
				helpers::join( text, getTypeName( var->getType() ), " " );
				helpers::join( text, var->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitInOutRayPayloadVariableDeclStmt( ast::stmt::InOutRayPayloadVariableDecl * stmt )override
			{
				auto var = stmt->getVariable();
				std::string name = "rayPayload";

				if ( var->isIncomingRayPayload() )
				{
					name = "rayPayloadIn";
				}

				std::string text = "layout(" + helpers::getLocationName( *var ) + "=" + helpers::writeValue( stmt->getLocation() ) + ")";
				helpers::join( text, name, " " );
				helpers::join( text, getTypeName( stmt->getVariable()->getType() ), " " );
				helpers::join( text, stmt->getVariable()->getName(), " " );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitInOutVariableDeclStmt( ast::stmt::InOutVariableDecl * stmt )override
			{
				std::string text = helpers::getInOutLayout( m_shaderStage, *stmt );
				helpers::join( text, helpers::getInterpolationQualifier( *stmt->getVariable() ), " " );
				helpers::join( text, helpers::getDirectionName( *stmt->getVariable() ), " " );
				helpers::join( text, getTypeName( stmt->getVariable()->getType() ), " " );
				helpers::join( text, stmt->getVariable()->getName(), " " );

				if ( stmt->getVariable()->getType()->getKind() == ast::type::Kind::eArray
					&& ( m_shaderStage == ast::ShaderStage::eTessellationControl
						|| m_shaderStage == ast::ShaderStage::eTessellationEvaluation ) )
				{
					text += "[]";
				}
				else
				{
					text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				}

				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitSpecialisationConstantDeclStmt( ast::stmt::SpecialisationConstantDecl * stmt )override
			{
				AST_Failure( "No specialisation constant should remain at this stage" );
			}

			void visitInputComputeLayoutStmt( ast::stmt::InputComputeLayout * stmt )override
			{
				std::string text;

				if ( stmt->getWorkGroupsZ() == 1 )
				{
					if ( stmt->getWorkGroupsY() == 1 )
					{
						text = "layout(local_size_x=" + helpers::writeValue( stmt->getWorkGroupsX() ) + ") in";
					}
					else
					{
						text = "layout(local_size_x=" + helpers::writeValue( stmt->getWorkGroupsX() )
							+ ", local_size_y=" + helpers::writeValue( stmt->getWorkGroupsY() ) + ") in";
					}
				}
				else
				{
					text = "layout(local_size_x=" + helpers::writeValue( stmt->getWorkGroupsX() )
						+ ", local_size_y=" + helpers::writeValue( stmt->getWorkGroupsY() )
						+ ", local_size_z=" + helpers::writeValue( stmt->getWorkGroupsZ() ) + ") in";
				}

				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitInputGeometryLayoutStmt( ast::stmt::InputGeometryLayout * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getLayout() ) + ") in", stmt );
			}

			void visitOutputGeometryLayoutStmt( ast::stmt::OutputGeometryLayout * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getLayout() ) + ", max_vertices = " + helpers::writeValue( stmt->getPrimCount() ) + ") out", stmt );
			}

			void visitOutputMeshLayoutStmt( ast::stmt::OutputMeshLayout * stmt )override
			{
				doAddSimpleStatement( "layout(" + helpers::getLayoutName( stmt->getTopology() ) + ", max_vertices = " + helpers::writeValue( stmt->getMaxVertices() ) + ", max_primitives = " + helpers::writeValue( stmt->getMaxPrimitives() ) + ") out", stmt );
			}

			void visitOutputTessellationControlLayoutStmt( ast::stmt::OutputTessellationControlLayout * stmt )override
			{
				doAddSimpleStatement( "layout(vertices=" + helpers::writeValue( stmt->getOutputVertices() ) + ") out", stmt );
			}

			void visitInputTessellationEvaluationLayoutStmt( ast::stmt::InputTessellationEvaluationLayout * stmt )override
			{
				std::string text = "layout(" + helpers::getLayoutName( stmt->getDomain() );
				text += ", " + helpers::getLayoutName( stmt->getPartitioning() );
				text += ", " + helpers::getLayoutName( stmt->getPrimitiveOrdering() );
				text += ") in";
				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitPerPrimitiveDeclStmt( ast::stmt::PerPrimitiveDecl * stmt )override
			{
			}

			void visitPerVertexDeclStmt( ast::stmt::PerVertexDecl * stmt )override
			{
			}

			void visitReturnStmt( ast::stmt::Return * stmt )override
			{
				std::string text = "return";

				if ( stmt->getExpr() )
				{
					text += " "  + doSubmit( stmt->getExpr() );
				}

				doAddSimpleStatement( std::move( text ), stmt );
			}

			void visitSampledImageDeclStmt( ast::stmt::SampledImageDecl * stmt )override
			{
				auto type = stmt->getVariable()->getType();

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					type = std::static_pointer_cast< ast::type::Array >( type )->getType();
				}

				assert( type->getKind() == ast::type::Kind::eSampledImage );
				auto sampledImage = std::static_pointer_cast< ast::type::SampledImage >( type );

				std::string text = "layout(";
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
				text += ") ";
				text += "uniform " + helpers::getQualifiedName( ast::type::Kind::eSampledImage, sampledImage->getConfig() ) + " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitCombinedImageDeclStmt( ast::stmt::CombinedImageDecl * stmt )override
			{
				auto type = stmt->getVariable()->getType();

				if ( type->getKind() == ast::type::Kind::eArray )
				{
					type = std::static_pointer_cast< ast::type::Array >( type )->getType();
				}

				assert( type->getKind() == ast::type::Kind::eCombinedImage );
				auto sampledImage = std::static_pointer_cast< ast::type::CombinedImage >( type );

				std::string text = "layout(";
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
				text += ") ";
				text += "uniform " + helpers::getQualifiedName( ast::type::Kind::eCombinedImage, sampledImage->getConfig(), sampledImage->isComparison() ) + " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitSamplerDeclStmt( ast::stmt::SamplerDecl * stmt )override
			{
				std::string text = "layout(";
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), "", text );
				text += ") uniform sampler";

				if ( static_cast< ast::type::Sampler const & >( *getNonArrayType( stmt->getVariable()->getType() ) ).isComparison() )
				{
					text += "Shadow";
				}

				text += " " + stmt->getVariable()->getName();
				text += helpers::getTypeArraySize( stmt->getVariable()->getType() );
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitShaderBufferDeclStmt( ast::stmt::ShaderBufferDecl * stmt )override
			{
				doAddStatement( "struct " + stmt->getSsboName() + "Block", DebugStatementType::eStructureDecl, stmt );
				doParseScope( stmt
					, DebugStatementType::eStructureScopeBegin
					, DebugStatementType::eStructureMemberDecl
					, DebugStatementType::eStructureScopeEnd );
				std::string text = "layout(";
				text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				text += ") buffer " + stmt->getSsboName() + "Block " + stmt->getSsboName();
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitShaderStructBufferDeclStmt( ast::stmt::ShaderStructBufferDecl * stmt )override
			{
				doAddStatement( "struct " + stmt->getSsboName(), DebugStatementType::eStructureDecl, stmt );
				doBeginScope( stmt, DebugStatementType::eStructureScopeBegin, DebugStatementType::eStructureMemberDecl );
				auto data = stmt->getData();
				auto arrayType = std::static_pointer_cast< ast::type::Array >( data->getType() );
				std::string text = getTypeName( arrayType->getType() ) + " " + data->getName();
				text += helpers::getTypeArraySize( arrayType ) + "";
				doAddSimpleStatement( std::move( text ), stmt );
				doEndScope( stmt, DebugStatementType::eStructureScopeEnd );

				text = "layout(";
				text += helpers::getMemoryLayoutName( stmt->getMemoryLayout() );
				doWriteBinding( stmt->getBindingPoint(), stmt->getDescriptorSet(), ", ", text );
				text += ") buffer " + stmt->getSsboName() + " " + stmt->getSsboInstance()->getName();
				doAddVariableDeclStatement( std::move( text ), stmt );
			}

			void visitSimpleStmt( ast::stmt::Simple * stmt )override
			{
				doAddSimpleStatement( doSubmit( stmt->getExpr() ), stmt );
			}

			void visitStructureDeclStmt( ast::stmt::StructureDecl * stmt )override
			{
				doParseStruct( stmt, *stmt->getType() );
			}

			void visitSwitchCaseStmt( ast::stmt::SwitchCase * stmt )override
			{
				if ( stmt->getCaseExpr() )
				{
					doAddStatement( "case " + doSubmit( stmt->getCaseExpr() ) + ":", DebugStatementType::eControlBegin, stmt );
				}
				else
				{
					doAddStatement( "default:", DebugStatementType::eControlBegin, stmt );
				}

				doParseScope( stmt
					, DebugStatementType::eLexicalScopeBegin
					, DebugStatementType::eScopeLine
					, DebugStatementType::eLexicalScopeEnd );
			}

			void visitSwitchStmt( ast::stmt::Switch * stmt )override
			{
				doAddStatement( "switch (" + doSubmit( stmt->getTestExpr() ) + ")", DebugStatementType::eControlBegin, stmt );
				doParseScope( stmt
					, DebugStatementType::eLexicalScopeBegin
					, DebugStatementType::eScopeLine
					, DebugStatementType::eLexicalScopeEnd );
			}

			void visitTerminateRayStmt( ast::stmt::TerminateRay * stmt )override
			{
				doAddSimpleStatement( "terminateRay", stmt );
			}

			void visitVariableDeclStmt( ast::stmt::VariableDecl * stmt )override
			{
				if ( !stmt->getVariable()->isBuiltin() )
				{
					auto var = stmt->getVariable();

					if ( var->isPerTaskNV() )
					{
						auto structType = getStructType( var->getType() );

						if ( structType && !structType->empty() )
						{
							doParseStruct( stmt, *structType );
							std::string text = "task";
							helpers::join( text, helpers::getDirectionName( *var ), " " );
							text += " ";
							text += structType->getName();
							helpers::join( text, var->getName(), " " );
							doAddVariableDeclStatement( std::move( text ), stmt );
						}
					}
					else if ( var->isPerTask() )
					{
						auto structType = getStructType( var->getType() );

						if ( structType && !structType->empty() )
						{
							doParseStruct( stmt, *structType );
						}

						if ( !structType || !structType->empty() )
						{
							std::string text = "taskPayloadShared";
							helpers::join( text, getTypeName( var->getType() ), " " );
							helpers::join( text, var->getName(), " " );
							doAddVariableDeclStatement( std::move( text ), stmt );
						}
					}
					else
					{
						std::string text;
						helpers::join( text, helpers::getDirectionName( *var ), " " );
						helpers::join( text, helpers::getInterpolationQualifier( *var ), " " );
						helpers::join( text, getTypeName( var->getType() ), " " );
						helpers::join( text, var->getName(), " " );
						text += helpers::getTypeArraySize( var->getType() );
						doAddVariableDeclStatement( std::move( text ), stmt );
					}
				}
			}

			void visitWhileStmt( ast::stmt::While * stmt )override
			{
				AST_Failure( "Unexpected While statement." );
			}

			void visitPreprocDefine( ast::stmt::PreprocDefine * preproc )override
			{
				AST_Failure( "Unexpected PreprocDefine statement." );
			}

			void visitPreprocElif( ast::stmt::PreprocElif * preproc )override
			{
				AST_Failure( "Unexpected PreprocElif statement." );
			}

			void visitPreprocElse( ast::stmt::PreprocElse * preproc )override
			{
				AST_Failure( "Unexpected PreprocElse statement." );
			}

			void visitPreprocEndif( ast::stmt::PreprocEndif * preproc )override
			{
				AST_Failure( "Unexpected PreprocEndif statement." );
			}

			void visitPreprocExtension( ast::stmt::PreprocExtension * preproc )override
			{
			}

			void visitPreprocIf( ast::stmt::PreprocIf * preproc )override
			{
				AST_Failure( "Unexpected PreprocIf statement." );
			}

			void visitPreprocIfDef( ast::stmt::PreprocIfDef * preproc )override
			{
				AST_Failure( "Unexpected PreprocIfDef statement." );
			}

			void visitPreprocVersion( ast::stmt::PreprocVersion * preproc )override
			{
			}

			void doWriteBinding( uint32_t binding
				, uint32_t set
				, std::string sep
				, std::string & result )
			{
				if ( binding != helpers::InvalidIndex )
				{
					result += sep + "binding=" + helpers::writeValue( binding );
					result += ", set=" + helpers::writeValue( set );
				}
			}

		private:
			ast::ShaderStage m_shaderStage;
			std::vector< std::string > m_indents{ std::string{} };
			DebugStatements & m_result;
			std::vector< ast::stmt::Stmt * > m_scopes{ nullptr };
			uint32_t m_currentLine{ 1u };
			std::string m_currentText;
			std::vector< DebugStatementType > m_scopeLines{ DebugStatementType::eScopeLine };
			DebugStatementType m_lastStmtType{ DebugStatementType::eScopeLine };
		};

		//*****************************************************************************************
	}

	debug::DebugStatements addDebugData( ast::ShaderStage shaderStage
		, ast::stmt::Container * stmt )
	{
		return debug::StmtDebugVisitor::submit( shaderStage, stmt );
	}
}
