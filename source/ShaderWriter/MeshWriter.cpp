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

namespace compile
{
	using namespace sdw;

	void pointX()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void pointXY()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void pointXYZ()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void point()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( MeshInT < VoidT >{ writer, 64u, 1u, 1u }
			, MeshVertexListOutT< VoidT >{ writer, 64u }
			, PointsMeshPrimitiveListOutT< VoidT >{ writer, 126u }
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void lineX()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void lineXY()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void lineXYZ()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void line()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( MeshInT < VoidT >{ writer, 64u, 1u, 1u }
			, MeshVertexListOutT< VoidT >{ writer, 64u }
			, LinesMeshPrimitiveListOutT< VoidT >{ writer, 126u }
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void triangleX()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void triangleXY()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void triangleXYZ()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( 64u
			, 64u
			, 64u
			, 64u
			, 126u
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}

	void triangle()
	{
		MeshWriter writer;
		writer.implementMainT< VoidT, VoidT, VoidT >( MeshInT < VoidT >{ writer, 64u, 1u, 1u }
			, MeshVertexListOutT< VoidT >{ writer, 64u }
			, TrianglesMeshPrimitiveListOutT< VoidT >{ writer, 126u }
			, [&]( MeshInT< VoidT > in
				, MeshVertexListOutT< VoidT > vtxOut
				, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
	}
}
