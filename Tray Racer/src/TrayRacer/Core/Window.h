#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "TrayRacer/Core/Base.h"
#include "TrayRacer/Events/Event.h"

#include <sstream>

namespace TrayRacer {

	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Tray Racer",
			uint32_t width = 1600,
			uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class Window
	{
	public:
		Window(WindowProps& windowprops);

		bool Init(WindowProps& windowprops);


		void OnUpdate();

		uint32_t GetWidth() const {  return m_Data.Width; }
		uint32_t GetHeight() const { return m_Data.Height; }

		// Window attributes
		void SetVSync(bool enabled) ;
		bool IsVSync() const { return m_Data.VSync; }

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
		};

		GLFWwindow* m_Window;

		WindowData m_Data;

		bool m_Success;

		uint32_t m_buffer;

		bool ShouldClose();
	};

}
