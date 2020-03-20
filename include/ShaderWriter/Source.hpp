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

#include "ShaderWriter/MaybeOptional/MaybeOptionalMat2.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat2x3.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat2x4.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat3.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat3x2.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat3x4.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat4.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat4x2.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalMat4x3.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalVec2.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalVec3.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptionalVec4.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

#include "ShaderWriter/Writer.hpp"
