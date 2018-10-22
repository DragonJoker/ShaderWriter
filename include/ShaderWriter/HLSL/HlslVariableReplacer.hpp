/*
See LICENSE file in root folder
*/
#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

#include "ShaderWriter/CloneExpr.hpp"

namespace sdw::hlsl
{
	class VariableReplacer
		: public ExprCloner
	{
	public:
		static expr::ExprPtr submit( expr::Expr * expr
			, var::VariablePtr origin
			, var::VariablePtr replacement );
		static expr::ExprPtr submit( expr::ExprPtr const & expr
			, var::VariablePtr origin
			, var::VariablePtr replacement );                       

	private:
		VariableReplacer( expr::ExprPtr & result
			, var::VariablePtr origin
			, var::VariablePtr replacement );

		ast::expr::ExprPtr doSubmit( ast::expr::Expr * expr )override;
		void visitIdentifierExpr( expr::Identifier * expr )override;

	private:
		var::VariablePtr m_origin;
		var::VariablePtr m_replacement;
	};
}
