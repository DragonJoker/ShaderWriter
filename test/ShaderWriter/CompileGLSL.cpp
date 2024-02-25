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
				getFunction( "glCompileShader", glCompileShader );
				getFunction( "glCreateShader", glCreateShader );
				getFunction( "glDeleteShader", glDeleteShader );
				getFunction( "glGetShaderInfoLog", glGetShaderInfoLog );
				getFunction( "glGetShaderiv", glGetShaderiv );
				getFunction( "glShaderSource", glShaderSource );
				endCurrent();
				doCreateModernContext( version );
				initialiseGLSLVersions( version, versions );
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

		std::vector< uint32_t > getGLSLVersions()
		{
			return m_glslVersions;
		}

		PFN_glCompileShader glCompileShader;
		PFN_glCreateShader glCreateShader;
		PFN_glDeleteShader glDeleteShader;
		PFN_glGetShaderInfoLog glGetShaderInfoLog;
		PFN_glGetShaderiv glGetShaderiv;
		PFN_glShaderSource glShaderSource;

	private:
		void loadDebugFunctions()
		{
			auto ext = ( char const * )glGetString( GL_EXTENSIONS );
			std::string extensions = ext ? ext : "";
			getFunction( "glDebugMessageCallback", glDebugMessageCallback );
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
		std::vector< uint32_t > m_glslVersions;
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
			getFunction( "glCompileShader", glCompileShader );
			getFunction( "glCreateShader", glCreateShader );
			getFunction( "glDeleteShader", glDeleteShader );
			getFunction( "glGetShaderInfoLog", glGetShaderInfoLog );
			getFunction( "glGetShaderiv", glGetShaderiv );
			getFunction( "glShaderSource", glShaderSource );
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

		std::vector< uint32_t > getGLSLVersions()
		{
			return m_glslVersions;
		}

		PFN_glCompileShader glCompileShader;
		PFN_glCreateShader glCreateShader;
		PFN_glDeleteShader glDeleteShader;
		PFN_glGetShaderInfoLog glGetShaderInfoLog;
		PFN_glGetShaderiv glGetShaderiv;
		PFN_glShaderSource glShaderSource;

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

	private:
		Colormap m_map{ 0 };
		Display * m_display{ nullptr };
		Window m_xWindow{ 0 };
		GLXWindow m_glxWindow{ 0 };
		GLXFBConfig m_fbConfig{ nullptr };
		GLXContext m_glxContext;
		std::vector< uint32_t > m_glslVersions;
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
				errors = "GLSL Shader compilation failed - Unknown reason";
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
				return GL_VERTEX_SHADER;
			}
		}
	}

	namespace sdw_test
	{
		struct GLSLContext
		{
			static constexpr GLSLVersions glslVersions{ 330u
				, 400u
				, 410u
				, 420u
				, 430u
				, 440u
				, 450u
				, 460u };

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
#if SDW_Test_Coverage
		return testCounts.glsl->window.getGLSLVersions().back();
#else
		return testCounts.glsl->window.getGLSLVersions()[infoIndex];
#endif
	}

	uint32_t retrieveGLSLInfosSize( [[maybe_unused]] sdw_test::TestCounts const & testCounts )
	{
#if SDW_Test_Coverage
		return 1u;
#else
		return uint32_t( testCounts.glsl->window.getGLSLVersions().size() );
#endif
	}

	bool createGLSLContext( sdw_test::TestCounts & testCounts )
	{
		bool result = false;

		try
		{
			testCounts.glsl = std::make_shared< sdw_test::GLSLContext >();
			result = true;
		}
		catch ( std::exception & exc )
		{
			testCounts << exc.what() << endl;
		}

		return result;
	}

	void destroyGLSLContext( sdw_test::TestCounts & testCounts )
	{
		testCounts.glsl.reset();
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
		auto & window = testCounts.glsl->window;

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
}

#else

namespace test
{
	static std::vector< uint32_t > getShaderModels()
	{
		static const std::vector< uint32_t > glslVersions{ 330u
			, 400u
			, 410u
			, 420u
			, 430u
			, 440u
			, 450u
			, 460u };
		return glslVersions;
	}

	bool retrieveIsGLSLInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return true;
	}

	uint32_t retrieveGLSLInfosSize( sdw_test::TestCounts const & testCounts )
	{
#if SDW_Test_Coverage
		return 1u;
#else
		return uint32_t( getShaderModels().size() );
#endif
	}

	uint32_t retrieveGLSLVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
#if SDW_Test_Coverage
		return getShaderModels().back();
#else
		return getShaderModels()[infoIndex];
#endif
	}

	bool createGLSLContext( sdw_test::TestCounts & testCounts )
	{
		return true;
	}

	void destroyGLSLContext( sdw_test::TestCounts & testCounts )
	{
	}

	bool compileGlsl( std::string_view source
		, ast::ShaderStage stage
		, std::string & errors
		, sdw_test::TestCounts & testCounts )
	{
		return true;
	}
}

#endif
