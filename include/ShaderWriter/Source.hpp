/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Function.hpp"
#include "ShaderWriter/CompositeTypes/Pcb.hpp"
#include "ShaderWriter/CompositeTypes/Ssbo.hpp"
#include "ShaderWriter/CompositeTypes/Struct.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"
#include "ShaderWriter/CompositeTypes/StructuredSsbo.hpp"
#include "ShaderWriter/CompositeTypes/Ubo.hpp"

#include "ShaderWriter/MatTypes/Mat2.hpp"
#include "ShaderWriter/MatTypes/Mat2x3.hpp"
#include "ShaderWriter/MatTypes/Mat2x4.hpp"
#include "ShaderWriter/MatTypes/Mat3.hpp"
#include "ShaderWriter/MatTypes/Mat3x2.hpp"
#include "ShaderWriter/MatTypes/Mat3x4.hpp"
#include "ShaderWriter/MatTypes/Mat4.hpp"
#include "ShaderWriter/MatTypes/Mat4x2.hpp"
#include "ShaderWriter/MatTypes/Mat4x3.hpp"

#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

#include "ShaderWriter/Writer.hpp"
