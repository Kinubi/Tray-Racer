#include "hzpch.h"
#include "Window.h"



namespace TrayRacer {

	Window::Window(WindowProps& windowprops)
	{
		m_Success = Window::Init(windowprops);
	}

	bool Window::Init(WindowProps& windowprops)
	{
		m_Data.Height = windowprops.Height;
		m_Data.Width = windowprops.Width;
		m_Data.Title = windowprops.Title;


		if (!glfwInit())
			return false;

		//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), NULL, NULL);

		if (!m_Window)
			return false;
		
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		HZ_CORE_ASSERT(status, "Failed to initialize glad");

		std::cout << glGetString(GL_VERSION) << std::endl;

		float positions[] = {
			-0.5f, -0.5f,
			 0.0f,  0.5f,
			 0.5f, -0.5f
		};

		
		Renderer2DData rendererData = Renderer2D::LoadShaders();
		Renderer2D::BindVertexBuffer(positions, 0, 2, 0);
		


		return true;

	}

	void Window::OnUpdate()
	{
		

		
		
		glfwSwapBuffers(m_Window);
		Renderer2D::OnUpdate();
		/* Poll for and process events */
		glfwPollEvents();
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}
	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_Window);
	}
}

