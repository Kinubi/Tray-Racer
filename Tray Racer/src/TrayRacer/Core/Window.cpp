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

		m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), NULL, NULL);

		if (!m_Window)
			return false;
		
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		HZ_CORE_ASSERT(status, "Failed to initialize glad");


		float positions[6] = {
			-0.5f, -0.5f,
			0.0f, 0.5f,
			0.5f, -0.5f,
		};

		glGenBuffers(1, &m_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_buffer);
		glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
		return true;


	}

	void Window::OnUpdate()
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back b */
		//
		glDrawArrays(GL_TRIANGLES, 0, 3);
		

		glfwSwapBuffers(m_Window);

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

