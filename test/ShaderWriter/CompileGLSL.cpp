#include "CompileGLSL.hpp"

#if SDW_Test_HasOpenGL

#if _WIN32
#	include <Windows.h>
#elif __linux__
#	include <X11/X.h>
#	include <X11/Xlib.h>
#	include <GL/glx.h>
#endif

#if defined( __APPLE__ )
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#pragma warning( disable: 5262 )
#include <iostream>
#include <sstream>

namespace test
{
	using GLSLVersions = std::array< uint32_t, 8u >;
	using GLExtensions = std::set< std::string >;

#if _WIN32 || __APPLE__

	enum ContextFlag
	{
		GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x0001,
		GL_CONTEXT_FLAG_DEBUG_BIT = 0x0002,
	};

	enum ContextMaskFlag
	{
		GL_CONTEXT_CORE_PROFILE_BIT = 0x00000001,
	};

	enum GlDebugOutput
		: GLenum
	{
		GL_DEBUG_OUTPUT_SYNCHRONOUS = 0x8242,
	};

	enum GlDebugSource
		: GLenum
	{
		GL_DEBUG_SOURCE_API = 0x8246,
		GL_DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247,
		GL_DEBUG_SOURCE_SHADER_COMPILER = 0x8248,
		GL_DEBUG_SOURCE_THIRD_PARTY = 0x8249,
		GL_DEBUG_SOURCE_APPLICATION = 0x824A,
		GL_DEBUG_SOURCE_OTHER = 0x824B,
	};

	enum GlDebugType
	{
		GL_DEBUG_TYPE_ERROR = 0x824C,
		GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D,
		GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E,
		GL_DEBUG_TYPE_PORTABILITY = 0x824F,
		GL_DEBUG_TYPE_PERFORMANCE = 0x8250,
		GL_DEBUG_TYPE_OTHER = 0x8251,
		GL_DEBUG_TYPE_MARKER = 0x8268,
		GL_DEBUG_TYPE_PUSH_GROUP = 0x8269,
		GL_DEBUG_TYPE_POP_GROUP = 0x826A,
	};

	enum GlDebugSeverity
	{
		GL_DEBUG_SEVERITY_NOTIFICATION = 0x826B,
		GL_DEBUG_SEVERITY_HIGH = 0x9146,
		GL_DEBUG_SEVERITY_MEDIUM = 0x9147,
		GL_DEBUG_SEVERITY_LOW = 0x9148,
	};

	enum GlDebugCategory
	{
		GL_DEBUG_CATEGORY_API_ERROR_AMD = 0x9149,
		GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD = 0x914A,
		GL_DEBUG_CATEGORY_DEPRECATION_AMD = 0x914B,
		GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD = 0x914C,
		GL_DEBUG_CATEGORY_PERFORMANCE_AMD = 0x914D,
		GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD = 0x914E,
		GL_DEBUG_CATEGORY_APPLICATION_AMD = 0x914F,
		GL_DEBUG_CATEGORY_OTHER_AMD = 0x9150,
	};

	enum GlGet
	{
		GL_GET_NUM_EXTENSIONS = 0x821D,
	};

#if _WIN32
#	define GLAPIENTRY __stdcall

	enum GlShaderInfo
	{
		GL_COMPILE_STATUS = 0x8B81,
		GL_LINK_STATUS = 0x8B82,
		GL_VALIDATE_STATUS = 0x8B83,
		GL_INFO_LOG_LENGTH = 0x8B84,
		GL_ATTACHED_SHADERS = 0x8B85,
	};

	enum GlShaderStageFlag
	{
		GL_FRAGMENT_SHADER = 0x8B30,
		GL_VERTEX_SHADER = 0x8B31,
		GL_GEOMETRY_SHADER = 0x8DD9,
		GL_TESS_CONTROL_SHADER = 0x8E88,
		GL_TESS_EVALUATION_SHADER = 0x8E87,
		GL_COMPUTE_SHADER = 0x91B9,
		GL_MESH_SHADER = 0x9559,
		GL_TASK_SHADER = 0x955A,
	};

#else
#	define GLAPIENTRY
#endif

#else
#	define GLAPIENTRY
#endif

	static const int GL_CONTEXT_CREATION_DEFAULT_FLAGS = GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT | GL_CONTEXT_FLAG_DEBUG_BIT;
	static const int GL_CONTEXT_CREATION_DEFAULT_MASK = GL_CONTEXT_CORE_PROFILE_BIT;

	using PFN_glCompileShader = void ( GLAPIENTRY * )( GLuint shader );
	using PFN_glCreateShader = GLuint( GLAPIENTRY * )( GLenum type );
	using PFN_glDeleteShader = void ( GLAPIENTRY * )( GLuint shader );
	using PFN_glGetShaderInfoLog = void ( GLAPIENTRY * )( GLuint shader, GLsizei bufSize, GLsizei* length, char * infoLog );
	using PFN_glGetShaderiv = void ( GLAPIENTRY * )( GLuint shader, GLenum pname, GLint * param );
	using PFN_glShaderSource = void ( GLAPIENTRY * )( GLuint shader, GLsizei count, const char * const * string, const GLint * length );
	using PFN_glGetStringi = const GLubyte * ( GLAPIENTRY * )( GLenum name, GLuint index );

	using PFNGLDEBUGPROC = void ( GLAPIENTRY * )( uint32_t source, uint32_t type, uint32_t id, uint32_t severity, int length, const char * message, void * userParam );
	using PFNGLDEBUGAMDPROC = void ( GLAPIENTRY * )( uint32_t id, uint32_t category, uint32_t severity, int length, const char* message, void* userParam );
	using PFNGLDEBUGMESSAGECALLBACK = void ( GLAPIENTRY * )( PFNGLDEBUGPROC callback, void * userParam );
	using PFNGLDEBUGMESSAGECALLBACKAMD = void ( GLAPIENTRY * )( PFNGLDEBUGAMDPROC callback, void * userParam );

	PFNGLDEBUGMESSAGECALLBACK glDebugMessageCallback = nullptr;
	PFNGLDEBUGMESSAGECALLBACKAMD glDebugMessageCallbackAMD = nullptr;

	namespace
	{
		struct Version
		{
			int major{};
			int minor{};
		};

		Version checkGLVersion()
		{
			Version result;
			char const* const cversion = ( char const* )glGetString( GL_VERSION );

			if ( cversion )
			{
				std::string sversion = cversion;
				std::stringstream stream( sversion );
				float fversion;
				stream >> fversion;
				auto version = int( fversion * 10 );
				result.major = version / 10;
				result.minor = version % 10;
			}

			return result;
		}

#if !defined( NDEBUG )
		std::string getErrorName( uint32_t code, uint32_t category )
		{
			static uint32_t constexpr InvalidEnum = 0x0500;
			static uint32_t constexpr InvalidValue = 0x0501;
			static uint32_t constexpr InvalidOperation = 0x0502;
			static uint32_t constexpr StackOverflow = 0x0503;
			static uint32_t constexpr StackUnderflow = 0x0504;
			static uint32_t constexpr OutOfMemory = 0x0505;
			static uint32_t constexpr InvalidFramebufferOperation = 0x0506;

			static std::map< uint32_t, std::string > const errors
			{
				{ InvalidEnum, "Invalid Enum" },
				{ InvalidValue, "Invalid Value" },
				{ InvalidOperation, "Invalid Operation" },
				{ StackOverflow, "Stack Overflow" },
				{ StackUnderflow, "Stack Underflow" },
				{ OutOfMemory, "Out of memory" },
				{ InvalidFramebufferOperation, "Invalid frame buffer operation" },
			};

			if ( category == GL_DEBUG_CATEGORY_API_ERROR_AMD
				|| category == GL_DEBUG_TYPE_ERROR )
			{
				auto it = errors.find( code );

				if ( it == errors.end() )
				{
					return "UNKNOWN_ERROR";
				}

				return it->second;
			}
			else
			{
				return std::string{};
			}
		}

		void GLAPIENTRY callbackDebugLog( uint32_t source, uint32_t type, uint32_t id, uint32_t severity, int length, const char * message, void * userParam )
		{
			std::locale loc{ "C" };
			std::stringstream stream;
			stream.imbue( loc );
			stream << "OpenGL Debug\n";

			switch ( source )
			{
			case GL_DEBUG_SOURCE_API:				stream << "    Source: OpenGL\n";			break;
			case GL_DEBUG_SOURCE_WINDOW_SYSTEM:		stream << "    Source: Windows\n";			break;
			case GL_DEBUG_SOURCE_SHADER_COMPILER:	stream << "    Source: Shader compiler\n";	break;
			case GL_DEBUG_SOURCE_THIRD_PARTY:		stream << "    Source: Third party\n";		break;
			case GL_DEBUG_SOURCE_APPLICATION:		stream << "    Source: Application\n";		break;
			case GL_DEBUG_SOURCE_OTHER:				stream << "    Source: Other\n";			break;
			}

			switch ( type )
			{
			case GL_DEBUG_TYPE_ERROR:				stream << "    Type: Error\n";					break;
			case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:	stream << "    Type: Deprecated behavior\n";	break;
			case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:	stream << "    Type: Undefined behavior\n";		break;
			case GL_DEBUG_TYPE_PORTABILITY:			stream << "    Type: Portability\n";			break;
			case GL_DEBUG_TYPE_PERFORMANCE:			stream << "    Type: Performance\n";			break;
			case GL_DEBUG_TYPE_OTHER:				stream << "    Type: Other\n";					break;
			}

			stream << "    ID: 0x" << std::hex << id << " (" << getErrorName( id, type ) << ")\n";

			switch ( severity )
			{
			case GL_DEBUG_SEVERITY_HIGH:			stream << "    Severity: High\n";			break;
			case GL_DEBUG_SEVERITY_MEDIUM:			stream << "    Severity: Medium\n";			break;
			case GL_DEBUG_SEVERITY_LOW:				stream << "    Severity: Low\n";			break;
			case GL_DEBUG_SEVERITY_NOTIFICATION:	stream << "    Severity: Notification\n";	break;
			}

			stream << "    Message: " << message;
			std::cout << stream.str() << std::endl;
		}
#endif
	}

	template< typename FuncT >
	void getFunction( char const * const name, FuncT & function );

	class RenderWindowBase
	{
	public:
		std::vector< uint32_t > const & getGLSLVersions()const
		{
			return m_glslVersions;
		}

		bool hasExtension( std::string_view name )const
		{
			return m_glExtensions.find( std::string{ name } ) != m_glExtensions.end();
		}

		PFN_glCompileShader glCompileShader;
		PFN_glCreateShader glCreateShader;
		PFN_glDeleteShader glDeleteShader;
		PFN_glGetShaderInfoLog glGetShaderInfoLog;
		PFN_glGetShaderiv glGetShaderiv;
		PFN_glShaderSource glShaderSource;
		PFN_glGetStringi glGetStringi;

	protected:
		void loadBaseFunctions()
		{
			getFunction( "glCompileShader", glCompileShader );
			getFunction( "glCreateShader", glCreateShader );
			getFunction( "glDeleteShader", glDeleteShader );
			getFunction( "glGetShaderInfoLog", glGetShaderInfoLog );
			getFunction( "glGetShaderiv", glGetShaderiv );
			getFunction( "glShaderSource", glShaderSource );
			getFunction( "glGetStringi", glGetStringi );
		}

		void initialiseGLSLVersions( Version const & glVersion
			, GLSLVersions const & glslVersions )
		{
			auto v = glVersion.major * 100u + glVersion.minor * 10u;

			for ( auto & glslV : glslVersions )
			{
				if ( glslV <= v )
				{
					m_glslVersions.push_back( glslV );
				}
			}
		}

		void initialiseGLExtensions()
		{
			GLint count{};
			glGetIntegerv( GL_GET_NUM_EXTENSIONS, &count );

			for ( GLuint i = 0; i < GLuint( count ); i++ )
			{
				const char * extension = ( const char * )glGetStringi( GL_EXTENSIONS, i );
				m_glExtensions.emplace( extension );
			}
		}

		void initialiseDebugFunctions()
		{
#if !defined( NDEBUG )
			if ( glDebugMessageCallback )
			{
				glDebugMessageCallback( PFNGLDEBUGPROC( &callbackDebugLog ), nullptr );
				glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );
			}
#endif
		}

	private:
		std::vector< uint32_t > m_glslVersions;
		GLExtensions m_glExtensions;
	};

#if defined( _WIN32 )

#pragma warning( push )
#pragma warning( disable: 4191 )
	template< typename FuncT >
	void getFunction( char const * const name, FuncT & function )
	{
		function = reinterpret_cast< FuncT >( wglGetProcAddress( name ) );

		if ( function == nullptr )
		{
			throw std::runtime_error{ std::string( "Couldn't load function" ) + name };
		}
	}
#pragma warning( pop )

	enum ContextParameter
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB = 0x2091,
		WGL_CONTEXT_MINOR_VERSION_ARB = 0x2092,
		WGL_CONTEXT_FLAGS_ARB = 0x2094,
		WGL_CONTEXT_PROFILE_MASK_ARB = 0x9126,
	};

	class RenderWindow
		: public RenderWindowBase
	{
	public:
		RenderWindow( GLSLVersions const & versions )
		{
			try
			{
				m_wc.lpfnWndProc = RenderWindow::WndProc;
				m_wc.hInstance = ::GetModuleHandle( nullptr );
				m_wc.hbrBackground = ( HBRUSH )( COLOR_BACKGROUND );
				m_wc.lpszClassName = "DummyWindow";
				m_wc.style = CS_OWNDC;

				if ( !RegisterClassA( &m_wc ) )
				{
					throw std::runtime_error{ "Couldn't register window class" };
				}

				m_hWnd = CreateWindowA( m_wc.lpszClassName
					, "DummyWindow"
					, WS_OVERLAPPEDWINDOW
					, 0
					, 0
					, 640
					, 480
					, nullptr
					, nullptr
					, m_wc.hInstance
					, nullptr );

				if ( !m_hWnd )
				{
					throw std::runtime_error{ "Couldn't create window" };
				}

				m_hDC = ::GetDC( m_hWnd );

				if ( doSelectFormat() )
				{
					m_hContext = wglCreateContext( m_hDC );

					if ( !m_hContext )
					{
						throw std::runtime_error{ "Couldn't create the context" };
					}
				}
				else
				{
					throw std::runtime_error{ "Couldn't find an appropriate pixel format" };
				}

				setCurrent();
				auto version = checkGLVersion();
				initialiseDebugFunctions();
				loadBaseFunctions();
				endCurrent();
				doCreateModernContext( version );
				initialiseGLSLVersions( version, versions );
				setCurrent();
				initialiseGLExtensions();
				endCurrent();
			}
			catch ( std::exception & )
			{
				endCurrent();

				if ( m_hDC )
				{
					::ReleaseDC( m_hWnd, m_hDC );
				}

				if ( m_hWnd )
				{
					::DestroyWindow( m_hWnd );
				}

				throw;
			}
		}

		~RenderWindow()
		{
			wglDeleteContext( m_hContext );
			::ReleaseDC( m_hWnd, m_hDC );
			::DestroyWindow( m_hWnd );
			UnregisterClassA( m_wc.lpszClassName, m_wc.hInstance );
		}

		void setCurrent()const
		{
			wglMakeCurrent( m_hDC, m_hContext );
		}

		void endCurrent()const
		{
			wglMakeCurrent( nullptr, nullptr );
		}

	private:
		bool doSelectFormat()
		{
			bool result = false;
			PIXELFORMATDESCRIPTOR pfd = { 0 };
			pfd.nSize = sizeof( PIXELFORMATDESCRIPTOR );
			pfd.nVersion = 1;
			pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pfd.iPixelType = PFD_TYPE_RGBA;
			pfd.iLayerType = PFD_MAIN_PLANE;
			pfd.cColorBits = 24;
			pfd.cRedBits = 8;
			pfd.cGreenBits = 8;
			pfd.cBlueBits = 8;
			pfd.cDepthBits = 24;
			pfd.cStencilBits = 8;

			int pixelFormats = ::ChoosePixelFormat( m_hDC, &pfd );

			if ( pixelFormats )
			{
				result = ::SetPixelFormat( m_hDC, pixelFormats, &pfd ) != FALSE;
			}

			return result;
		}

		void doCreateModernContext( Version const & version )
		{
			using PFNGLCREATECONTEXTATTRIBS = HGLRC( *)( HDC hDC, HGLRC hShareContext, int const * attribList );
			PFNGLCREATECONTEXTATTRIBS glCreateContextAttribs;
			HGLRC hContext = m_hContext;
			std::vector< int > attribList
			{
				WGL_CONTEXT_MAJOR_VERSION_ARB, version.major,
				WGL_CONTEXT_MINOR_VERSION_ARB, version.minor,
				WGL_CONTEXT_FLAGS_ARB, GL_CONTEXT_CREATION_DEFAULT_FLAGS,
				WGL_CONTEXT_PROFILE_MASK_ARB, GL_CONTEXT_CREATION_DEFAULT_MASK,
				0
			};

			setCurrent();
			::glGetError();
			getFunction( "wglCreateContextAttribsARB", glCreateContextAttribs );
			hContext = glCreateContextAttribs( m_hDC
				, nullptr
				, attribList.data() );
			endCurrent();
			wglDeleteContext( m_hContext );
			m_hContext = hContext;

			if ( m_hContext == nullptr )
			{
				std::stringstream error;
				error << "Failed to create an OpenGL " << version.major << "." << version.minor << " context (0x" << std::hex << ::glGetError() << ").";
				throw std::runtime_error{ error.str() };
			}
		}

		static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
		{
			switch ( message )
			{
			case WM_CREATE:
				break;

			default:
				return DefWindowProc( hWnd, message, wParam, lParam );
			}

			return 0;
		}

	private:
		HWND m_hWnd{ nullptr };
		HDC m_hDC{ nullptr };
		HGLRC m_hContext{ nullptr };
		WNDCLASSA m_wc{};
	};

#elif defined( __linux__ )

	template< typename FuncT >
	void getFunction( char const * const name, FuncT & function )
	{
		function = reinterpret_cast< FuncT >( glXGetProcAddressARB( reinterpret_cast< GLubyte const * >( name ) ) );

		if ( function == nullptr )
		{
			throw std::runtime_error{ std::string( "Couldn't load function" ) + name };
		}
	}

	class RenderWindow
		: public RenderWindowBase
	{
	public:
		RenderWindow( GLSLVersions const & versions ) try
		{
			m_display = XOpenDisplay( NULL );

			if ( !m_display )
			{
				throw std::runtime_error{ "Couldn't open X Display" };
			}

			int attributes[] =
			{
				GLX_X_RENDERABLE, True,
				GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
				GLX_RENDER_TYPE, GLX_RGBA_BIT,
				GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
				GLX_DOUBLEBUFFER, GL_TRUE,
				GLX_RED_SIZE, 1,
				GLX_GREEN_SIZE, 1,
				GLX_BLUE_SIZE, 1,
				0
			};

			int fbcount = 0;
			GLXFBConfig * config = glXChooseFBConfig( m_display, DefaultScreen( m_display ), attributes, &fbcount );
			int bestFbcIndex = -1;
			int worstFbcIndex = -1;
			int bestNumSamp = -1;
			int worstNumSamp = 999;

			for ( int i = 0; i < fbcount; ++i )
			{
				XVisualInfo * vi = glXGetVisualFromFBConfig( m_display, config[i] );

				if ( vi )
				{
					int sampleBuffers;
					int samples;
					glXGetFBConfigAttrib( m_display, config[i], GLX_SAMPLE_BUFFERS, &sampleBuffers );
					glXGetFBConfigAttrib( m_display, config[i], GLX_SAMPLES, &samples );

					if ( bestFbcIndex < 0 || sampleBuffers && samples > bestNumSamp )
					{
						bestFbcIndex = i;
						bestNumSamp = samples;
					}

					if ( worstFbcIndex < 0 || !sampleBuffers || samples < worstNumSamp )
					{
						worstFbcIndex = i;
						worstNumSamp = samples;
					}
				}

				XFree( vi );
			}

			if ( bestFbcIndex == -1 )
			{
				throw std::runtime_error{ "Couldn't find appropriate GLXFBConfig" };
			}

			m_fbConfig = config[bestFbcIndex];
			XVisualInfo * vi = glXGetVisualFromFBConfig( m_display, m_fbConfig );

			if ( !vi )
			{
				throw std::runtime_error{ "Couldn't find get XVisualInfo" };
			}

			Window root = RootWindow( m_display, vi->screen );
			m_map = XCreateColormap( m_display, root, vi->visual, AllocNone );

			if ( !m_map )
			{
				throw std::runtime_error{ "Couldn't create X Colormap" };
			}

			XSetWindowAttributes swa;
			swa.colormap = m_map;
			swa.background_pixmap = 0;
			swa.border_pixel = 0;
			swa.event_mask = StructureNotifyMask;
			m_xWindow = XCreateWindow( m_display, root, 0, 0, 640, 480, 0, vi->depth, InputOutput, vi->visual, CWBorderPixel | CWColormap | CWEventMask, &swa );

			if ( !m_xWindow )
			{
				throw std::runtime_error{ "Couldn't create X Window" };
			}

			XStoreName( m_display, m_xWindow, "DummyWindow" );
			XSync( m_display, False );

			int screen = DefaultScreen( m_display );
			int major{ 0 };
			int minor{ 0 };
			bool ok = glXQueryVersion( m_display, &major, &minor );

			m_glxContext = glXCreateContext( m_display, vi, nullptr, GL_TRUE );

			if ( !m_glxContext )
			{
				throw std::runtime_error{ "Could not create a rendering context->" };
			}

			XFree( vi );

			auto version = checkGLVersion();
			doCreateModernContext( version );
			initialiseGLSLVersions( version, versions );

			setCurrent();
			loadBaseFunctions();
			initialiseGLExtensions();
			endCurrent();
		}
		catch ( std::exception & p_exc )
		{
			endCurrent();

			if ( m_glxContext )
			{
				glXDestroyContext( m_display, m_glxContext );
			}

			if ( m_xWindow )
			{
				XDestroyWindow( m_display, m_xWindow );
			}

			if ( m_map )
			{
				XFreeColormap( m_display, m_map );
			}

			if ( m_display )
			{
				XCloseDisplay( m_display );
			}

			throw;
		}

		~RenderWindow()
		{
			glXDestroyContext( m_display, m_glxContext );
			XFree( m_fbConfig );

			if ( m_xWindow )
			{
				XDestroyWindow( m_display, m_xWindow );
			}

			if ( m_map )
			{
				XFreeColormap( m_display, m_map );
			}

			if ( m_display )
			{
				XCloseDisplay( m_display );
			}
		}

		void setCurrent()const
		{
			glXMakeCurrent( m_display, m_xWindow, m_glxContext );
		}

		void endCurrent()const
		{
			glXMakeCurrent( m_display, 0, nullptr );
		}

	private:
		void doCreateModernContext( Version const & version )
		{
			using PFNGLCREATECONTEXTATTRIBS = GLXContext( *)( Display *dpy, GLXFBConfig, GLXContext, Bool, const int * );
			PFNGLCREATECONTEXTATTRIBS glCreateContextAttribs;
			std::vector< int > attribList
			{
				GLX_CONTEXT_MAJOR_VERSION_ARB, version.major,
				GLX_CONTEXT_MINOR_VERSION_ARB, version.minor,
				GLX_CONTEXT_FLAGS_ARB, GL_CONTEXT_CREATION_DEFAULT_FLAGS,
				GLX_CONTEXT_PROFILE_MASK_ARB, GL_CONTEXT_CREATION_DEFAULT_MASK,
				0
			};

			setCurrent();
			::glGetError();

			getFunction( "glXCreateContextAttribsARB", glCreateContextAttribs );
			endCurrent();

			auto glxContext = glCreateContextAttribs( m_display
				, m_fbConfig
				, nullptr
				, true
				, attribList.data() );
			glXDestroyContext( m_display, m_glxContext );
			m_glxContext = glxContext;

			if ( m_glxContext == nullptr )
			{
				std::stringstream stream;
				stream << "Failed to create an OpenGL " << version.major << "." << version.minor << " context.";
				throw std::runtime_error{ stream.str() };
			}

			m_glslVersion = version.major * 100u + version.minor * 10u;
		}

	private:
		Colormap m_map{ 0 };
		Display * m_display{ nullptr };
		Window m_xWindow{ 0 };
		GLXWindow m_glxWindow{ 0 };
		GLXFBConfig m_fbConfig{ nullptr };
		GLXContext m_glxContext;
	};

#else

#error "Unsupported platform yet, feel free to implement support for RenderWindow ;)."

#endif

	namespace
	{
		std::string doRetrieveCompilerLog( RenderWindow const & window
			, GLuint shaderName )
		{
			std::string log;
			int infologLength = 0;
			int charsWritten = 0;
			window.glGetShaderiv( shaderName
				, GL_INFO_LOG_LENGTH
				, &infologLength );

			if ( infologLength > 0 )
			{
				std::vector< char > infoLog( size_t( infologLength + 1 ) );
				window.glGetShaderInfoLog( shaderName
					, infologLength
					, &charsWritten
					, infoLog.data() );
				log = infoLog.data();
			}

			if ( !log.empty() )
			{
				log = log.substr( 0, log.size() - 1 );
			}

			return log;
		}

		bool doCheckCompileErrors( RenderWindow const & window
			, bool compiled
			, GLuint shaderName
			, std::string_view source
			, std::string & errors )
		{
			auto compilerLog = doRetrieveCompilerLog( window, shaderName );

			if ( !compilerLog.empty() )
			{
				errors = compilerLog;
			}
			else if ( !compiled )
			{
				errors = "GLSL Shader by API compilation failed - Unknown reason";
			}

			return compiled;
		}

		GLenum convert( ast::ShaderStage stage )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				return GL_VERTEX_SHADER;
			case ast::ShaderStage::eTessellationControl:
				return GL_TESS_CONTROL_SHADER;
			case ast::ShaderStage::eTessellationEvaluation:
				return GL_TESS_EVALUATION_SHADER;
			case ast::ShaderStage::eGeometry:
				return GL_GEOMETRY_SHADER;
			case ast::ShaderStage::eFragment:
				return GL_FRAGMENT_SHADER;
			case ast::ShaderStage::eTaskNV:
			case ast::ShaderStage::eTask:
				return GL_TASK_SHADER;
			case ast::ShaderStage::eMeshNV:
			case ast::ShaderStage::eMesh:
				return GL_MESH_SHADER;
			case ast::ShaderStage::eCompute:
				return GL_COMPUTE_SHADER;
			default:
				AST_Failure( "Unsupported ShaderType." );
#if !SDAST_ExceptAssert
				return GL_VERTEX_SHADER;
#endif
			}
		}
	}

	namespace sdw_test
	{
		struct GLSLContext
		{
#if SDW_Test_Coverage
			static constexpr GLSLVersions glslVersions{ 330u, 420u, 460u };
#else
			static constexpr GLSLVersions glslVersions{ 330u, 400u, 410u, 420u, 430u, 440u, 450u, 460u };
#endif

			GLSLContext()
				: window{ glslVersions }
			{
			}

			RenderWindow window;
		};
	}

	bool retrieveIsGLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return true;
	}

	uint32_t retrieveGLSLVersion( sdw_test::TestCounts const & testCounts
		, [[maybe_unused]] uint32_t infoIndex )
	{
		return testCounts.glsl().window.getGLSLVersions()[infoIndex];
	}

	uint32_t retrieveGLSLInfosSize( [[maybe_unused]] sdw_test::TestCounts const & testCounts )
	{
		return uint32_t( testCounts.glsl().window.getGLSLVersions().size() );
	}

	bool createGLSLContext()
	{
		bool result = false;

		try
		{
			SDWTest::glsl = std::make_shared< sdw_test::GLSLContext >();
			result = true;
		}
		catch ( std::exception & exc )
		{
			std::cout << exc.what() << std::endl;
		}

		return result;
	}

	void destroyGLSLContext()
	{
		SDWTest::glsl.reset();
	}

	bool compileGlsl( std::string_view source
		, ast::ShaderStage stage
		, std::string & errors
		, sdw_test::TestCounts & testCounts )
	{
		if ( isRayTraceStage( stage ) )
		{
			return true;
		}

		bool result = false;
		auto const & window = testCounts.glsl().window;

		window.setCurrent();
		auto length = int( source.size() );
		char const * data = source.data();
		auto shader = window.glCreateShader( convert( stage ) );
		window.glShaderSource( shader
			, 1
			, &data
			, &length );
		window.glCompileShader( shader );
		int compiled = 0;
		window.glGetShaderiv( shader
			, GL_COMPILE_STATUS
			, &compiled );

		result = doCheckCompileErrors( window
			, compiled != 0
			, shader
			, source
			, errors );
		window.glDeleteShader( shader );
		window.endCurrent();
		return result;
	}

#if SDW_HasCompilerGlsl

	glsl::GlslExtensionSet getExtensions( uint32_t glslVersion
		, sdw_test::TestCounts & testCounts )
	{
		glsl::GlslExtensionSet result;
		auto const & window = testCounts.glsl().window;

		auto insertExt = [&]( glsl::GlslExtension const & ext )
			{
				if ( window.hasExtension( ext.name ) )
					result.insert( ext );
			};

		if ( glslVersion >= glsl::v4_6 )
		{
			insertExt( glsl::EXT_shader_atomic_float );
			insertExt( glsl::EXT_ray_tracing );
			insertExt( glsl::EXT_ray_query );
			insertExt( glsl::EXT_scalar_block_layout );
		}

		if ( glslVersion >= glsl::v4_5 )
		{
			insertExt( glsl::ARB_shader_ballot );
			insertExt( glsl::ARB_shader_viewport_layer_array );
			insertExt( glsl::NV_stereo_view_rendering );
			insertExt( glsl::NVX_multiview_per_view_attributes );
			insertExt( glsl::EXT_nonuniform_qualifier );
			insertExt( glsl::NV_mesh_shader );
			insertExt( glsl::EXT_mesh_shader );
			insertExt( glsl::EXT_buffer_reference2 );
			insertExt( glsl::EXT_maximal_reconvergence );
			insertExt( glsl::EXT_shader_quad );
		}

		if ( glslVersion >= glsl::v4_3 )
		{
			insertExt( glsl::NV_viewport_array2 );
			insertExt( glsl::NV_shader_atomic_fp16_vector );
		}

		if ( glslVersion >= glsl::v4_2 )
		{
			insertExt( glsl::ARB_compute_shader );
			insertExt( glsl::ARB_explicit_uniform_location );
			insertExt( glsl::ARB_shading_language_420pack );
			insertExt( glsl::NV_shader_atomic_float );
		}

		if ( glslVersion >= glsl::v4_1 )
		{
			insertExt( glsl::ARB_shading_language_packing );
		}

		if ( glslVersion >= glsl::v4_0 )
		{
			insertExt( glsl::ARB_separate_shader_objects );
			insertExt( glsl::ARB_texture_cube_map_array );
			insertExt( glsl::ARB_texture_gather );
			insertExt( glsl::ARB_gpu_shader_int64 );
		}

		if ( glslVersion >= glsl::v3_3 )
		{
			insertExt( glsl::ARB_shader_stencil_export );
			insertExt( glsl::KHR_vulkan_glsl );
			insertExt( glsl::EXT_multiview );
			insertExt( glsl::ARB_explicit_attrib_location );
			insertExt( glsl::ARB_shader_image_load_store );
			insertExt( glsl::EXT_gpu_shader4 );
			insertExt( glsl::ARB_gpu_shader5 );
			insertExt( glsl::EXT_gpu_shader4_1 );
			insertExt( glsl::ARB_texture_query_lod );
			insertExt( glsl::ARB_texture_query_levels );
			insertExt( glsl::ARB_shader_draw_parameters );
			insertExt( glsl::ARB_fragment_layer_viewport );
			insertExt( glsl::ARB_tessellation_shader );
			insertExt( glsl::EXT_texture_shadow_lod );
		}

		if ( glslVersion >= glsl::v1_5 )
		{
			insertExt( glsl::NV_gpu_shader5 );
		}

		if ( glslVersion >= glsl::v1_4 )
		{
			insertExt( glsl::EXT_shader_explicit_arithmetic_types_int8 );
			insertExt( glsl::EXT_shader_explicit_arithmetic_types_int16 );
			insertExt( glsl::EXT_shader_explicit_arithmetic_types_int64 );
			insertExt( glsl::EXT_demote_to_helper_invocation );
		}

		return result;
	}

	glsl::GlslConfig getGlslConfig( uint32_t glslVersion
		, sdw_test::TestCounts & testCounts )
	{
		glsl::GlslConfig const result
		{
			ast::ShaderStage::eCompute, // shaderStage;
			glslVersion, // shaderLanguageVersion;
			getExtensions( glslVersion, testCounts ), // availableExtensions;
			( glslVersion >= glsl::v4_6 ), // vulkanGlsl;
			false, // flipVertY;
			false, // fixupClipDepth;
			true, // hasStd430Layout;
			true, // hasShaderStorageBuffers;
			true, // hasDescriptorSets;
			true, // hasBaseInstance;
		};
		return result;
	}

#endif
}

#else

namespace test
{
	static std::vector< uint32_t > getShaderModels()
	{
#if SDW_Test_Coverage
		static const std::vector< uint32_t > glslVersions{ 330u, 420u, 460u };
#else
		static const std::vector< uint32_t > glslVersions{ 330u, 400u, 410u, 420u, 430u, 440u, 450u, 460u };
#endif
		return glslVersions;
	}

	bool retrieveIsGLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return true;
	}

	uint32_t retrieveGLSLInfosSize( sdw_test::TestCounts const & testCounts )
	{
		return uint32_t( getShaderModels().size() );
	}

	uint32_t retrieveGLSLVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return getShaderModels()[infoIndex];
	}

	bool createGLSLContext()
	{
		return true;
	}

	void destroyGLSLContext()
	{
	}

	bool compileGlsl( std::string_view source
		, ast::ShaderStage stage
		, std::string & errors
		, sdw_test::TestCounts & testCounts )
	{
		return true;
	}

#if SDW_HasCompilerGlsl

	glsl::GlslExtensionSet getExtensions( uint32_t glslVersion
		, sdw_test::TestCounts & testCounts )
	{
		glsl::GlslExtensionSet result;

		if ( glslVersion >= glsl::v4_6 )
		{
			result.insert( glsl::EXT_shader_atomic_float );
			result.insert( glsl::EXT_ray_tracing );
			result.insert( glsl::EXT_ray_query );
			result.insert( glsl::EXT_scalar_block_layout );
		}

		if ( glslVersion >= glsl::v4_5 )
		{
			result.insert( glsl::ARB_shader_ballot );
			result.insert( glsl::ARB_shader_viewport_layer_array );
			result.insert( glsl::NV_stereo_view_rendering );
			result.insert( glsl::NVX_multiview_per_view_attributes );
			result.insert( glsl::EXT_nonuniform_qualifier );
			result.insert( glsl::NV_mesh_shader );
			result.insert( glsl::EXT_mesh_shader );
			result.insert( glsl::EXT_buffer_reference2 );
			result.insert( glsl::EXT_maximal_reconvergence );
			result.insert( glsl::EXT_shader_quad );
		}

		if ( glslVersion >= glsl::v4_3 )
		{
			result.insert( glsl::NV_viewport_array2 );
			result.insert( glsl::NV_shader_atomic_fp16_vector );
		}

		if ( glslVersion >= glsl::v4_2 )
		{
			result.insert( glsl::ARB_compute_shader );
			result.insert( glsl::ARB_explicit_uniform_location );
			result.insert( glsl::ARB_shading_language_420pack );
			result.insert( glsl::NV_shader_atomic_float );
		}

		if ( glslVersion >= glsl::v4_1 )
		{
			result.insert( glsl::ARB_shading_language_packing );
		}

		if ( glslVersion >= glsl::v4_0 )
		{
			result.insert( glsl::ARB_separate_shader_objects );
			result.insert( glsl::ARB_texture_cube_map_array );
			result.insert( glsl::ARB_texture_gather );
			result.insert( glsl::ARB_gpu_shader_int64 );
		}

		if ( glslVersion >= glsl::v3_3 )
		{
			result.insert( glsl::ARB_shader_stencil_export );
			result.insert( glsl::KHR_vulkan_glsl );
			result.insert( glsl::EXT_multiview );
			result.insert( glsl::ARB_explicit_attrib_location );
			result.insert( glsl::ARB_shader_image_load_store );
			result.insert( glsl::EXT_gpu_shader4 );
			result.insert( glsl::ARB_gpu_shader5 );
			result.insert( glsl::EXT_gpu_shader4_1 );
			result.insert( glsl::ARB_texture_query_lod );
			result.insert( glsl::ARB_texture_query_levels );
			result.insert( glsl::ARB_shader_draw_parameters );
			result.insert( glsl::ARB_fragment_layer_viewport );
			result.insert( glsl::ARB_tessellation_shader );
			result.insert( glsl::EXT_texture_shadow_lod );
		}

		if ( glslVersion >= glsl::v1_5 )
		{
			result.insert( glsl::NV_gpu_shader5 );
		}

		if ( glslVersion >= glsl::v1_4 )
		{
			result.insert( glsl::EXT_shader_explicit_arithmetic_types_int8 );
			result.insert( glsl::EXT_shader_explicit_arithmetic_types_int16 );
			result.insert( glsl::EXT_shader_explicit_arithmetic_types_int64 );
			result.insert( glsl::EXT_demote_to_helper_invocation );
		}

		return result;
	}

	glsl::GlslConfig getGlslConfig( uint32_t glslVersion
		, sdw_test::TestCounts & testCounts )
	{
		glsl::GlslConfig const result
		{
			ast::ShaderStage::eCompute, // shaderStage;
			glslVersion, // shaderLanguageVersion;
			getExtensions( glslVersion, testCounts ), // availableExtensions;
			( glslVersion >= glsl::v4_6 ), // vulkanGlsl;
			false, // flipVertY;
			false, // fixupClipDepth;
			true, // hasStd430Layout;
			true, // hasShaderStorageBuffers;
			true, // hasDescriptorSets;
			true, // hasBaseInstance;
		};
		return result;
	}

#endif
}

#endif
