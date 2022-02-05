/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCompositeConstruct_H___
#define ___AST_ExprCompositeConstruct_H___
#pragma once

#include "ExprIdentifier.hpp"
#include "ExprList.hpp"

namespace ast::expr
{
	class CompositeConstruct
		: public Expr
	{
	public:
		SDAST_API CompositeConstruct( CompositeType composite
			, type::Kind component
			, ExprList && argList );
		SDAST_API CompositeConstruct( ExprPtr image
			, ExprPtr sampler );

		SDAST_API void accept( VisitorPtr vis )override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline CompositeType getComposite()const
		{
			return m_composite;
		}

		inline type::Kind getComponent()const
		{
			return m_component;
		}

	private:
		CompositeType m_composite;
		type::Kind m_component;
		ExprList m_argList;
	};
	using CompositeConstructPtr = std::unique_ptr< CompositeConstruct >;

	uint32_t getComponentCount( CompositeType value );
	type::TypePtr getCompositeType( type::TypesCache & cache
		, CompositeType composite
		, type::Kind component );
	type::TypePtr getCompositeType( type::TypesCache & cache
		, type::ImageConfiguration config
		, bool isComparison );
	type::TypePtr getCombinedType( type::TypePtr image
		, type::TypePtr sampler );

	inline CompositeConstructPtr makeCompositeConstruct( CompositeType composite
		, type::Kind component
		, ExprList && argList )
	{
		return std::make_unique< CompositeConstruct >( composite
			, component
			, std::move( argList ) );
	}

	inline CompositeConstructPtr makeCompositeConstruct( ExprPtr image
		, ExprPtr sampler )
	{
		return std::make_unique< CompositeConstruct >( std::move( image )
			, std::move( sampler ) );
	}
}

#endif
