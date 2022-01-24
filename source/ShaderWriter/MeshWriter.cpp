/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriter.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	PrimitiveIndexT< ast::type::OutputTopology::ePoint >::FnType const PrimitiveIndexT< ast::type::OutputTopology::ePoint >::getMember = getUIntMember;
	PrimitiveIndexT< ast::type::OutputTopology::eLine >::FnType const PrimitiveIndexT< ast::type::OutputTopology::eLine >::getMember = getUVec2Member;
	PrimitiveIndexT< ast::type::OutputTopology::eTriangle >::FnType const PrimitiveIndexT< ast::type::OutputTopology::eTriangle >::getMember = getUVec3Member;

	MeshWriter::MeshWriter()
		: ShaderWriter{ ast::ShaderStage::eMesh }
	{
	}
}
