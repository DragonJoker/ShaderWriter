namespace sdw
{
	Void::Void()
		: Type( cuT( "void " ) )
	{
	}

	Void::Void( Shader * shader )
		: Type( cuT( "void " ), writer, std::string() )
	{
	}
}
