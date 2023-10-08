/*
See LICENSE file in root folder
*/
#ifndef NonSemanticShaderDebugInfo100_H_
#define NonSemanticShaderDebugInfo100_H_

namespace spv
{
	enum class NonSemanticShaderDebugInfo100Version
	{
		Version = 100,
		BitWidthPadding = 0x7fffffff
	};

	enum class NonSemanticShaderDebugInfo100Revision
	{
		Revision = 9,
		BitWidthPadding = 0x7fffffff
	};

	enum class NonSemanticShaderDebugInfo100Instructions
	{
		InfoNone = 0,
		CompilationUnit = 1,
		TypeBasic = 2,
		TypePointer = 3,
		TypeQualifier = 4,
		TypeArray = 5,
		TypeVector = 6,
		Typedef = 7,
		TypeFunction = 8,
		TypeEnum = 9,
		TypeComposite = 10,
		TypeMember = 11,
		TypeInheritance = 12,
		TypePtrToMember = 13,
		TypeTemplate = 14,
		TypeTemplateParameter = 15,
		TypeTemplateTemplateParameter = 16,
		TypeTemplateParameterPack = 17,
		GlobalVariable = 18,
		FunctionDeclaration = 19,
		Function = 20,
		LexicalBlock = 21,
		LexicalBlockDiscriminator = 22,
		Scope = 23,
		NoScope = 24,
		InlinedAt = 25,
		LocalVariable = 26,
		InlinedVariable = 27,
		Declare = 28,
		Value = 29,
		Operation = 30,
		Expression = 31,
		MacroDef = 32,
		MacroUndef = 33,
		ImportedEntity = 34,
		Source = 35,
		FunctionDefinition = 101,
		SourceContinued = 102,
		Line = 103,
		NoLine = 104,
		BuildIdentifier = 105,
		StoragePath = 106,
		EntryPoint = 107,
		TypeMatrix = 108,
		Max = 0x7fffffff,
	};

	enum class NonSemanticShaderDebugInfo100DebugInfoFlags
	{
		IsProtected = 1 << 0,
		IsPrivate = 1 << 1,
		IsPublic = 1 << 1 | 1 << 0,
		IsLocal = 1 << 2,
		IsDefinition = 1 << 3,
		FwdDecl = 1 << 4,
		Artificial = 1 << 5,
		Explicit = 1 << 6,
		Prototyped = 1 << 7,
		ObjectPointer = 1 << 8,
		StaticMember = 1 << 9,
		IndirectVariable = 1 << 10,
		LValueReference = 1 << 11,
		RValueReference = 1 << 12,
		IsOptimized = 1 << 13,
		IsEnumClass = 1 << 14,
		TypePassByValue = 1 << 15,
		TypePassByReference = 1 << 16,
		UnknownPhysicalLayout = 1 << 17,
		Max = 0x7fffffff,
	};

	enum class NonSemanticShaderDebugInfo100BuildIdentifierFlags
	{
		PossibleDuplicates = 1 << 0,
		Max = 0x7fffffff,
	};

	enum class NonSemanticShaderDebugInfo100DebugBaseTypeAttributeEncoding
	{
		Unspecified = 0,
		Address = 1,
		Boolean = 2,
		Float = 3,
		Signed = 4,
		SignedChar = 5,
		Unsigned = 6,
		UnsignedChar = 7,
		EncodingMax = 0x7fffffff,
	};

	enum class NonSemanticShaderDebugInfo100DebugCompositeType
	{
		Class = 0,
		Struct = 1,
		Union = 2,
		Max = 0x7fffffff,
	};

	enum class NonSemanticShaderDebugInfo100DebugTypeQualifier
	{
		ConstType = 0,
		VolatileType = 1,
		RestrictType = 2,
		AtomicType = 3,
		Max = 0x7fffffff,
	};

	enum class NonSemanticShaderDebugInfo100DebugOperation
	{
		Deref = 0,
		Plus = 1,
		Minus = 2,
		PlusUconst = 3,
		BitPiece = 4,
		Swap = 5,
		Xderef = 6,
		StackValue = 7,
		Constu = 8,
		Fragment = 9,
		Max = 0x7fffffff,
	};

	enum class NonSemanticShaderDebugInfo100DebugImportedEntity
	{
		Module = 0,
		Declaration = 1,
		Max = 0x7fffffff,
	};
}

#endif  // #ifndef NonSemanticShaderDebugInfo100_H_

