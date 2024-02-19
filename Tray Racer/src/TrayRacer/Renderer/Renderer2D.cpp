#include "hzpch.h"
#include "Renderer2D.h"
#include <iostream>

namespace TrayRacer {

	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)

	{
		std::cout << message<<std::endl;
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         HZ_CORE_CRITICAL(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       HZ_CORE_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          HZ_CORE_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: HZ_CORE_TRACE(message); return;
		}

		HZ_CORE_ASSERT(false, "Unknown severity level!");
	}





	Renderer2DData s_Data;

	

	Renderer2D::Renderer2D()
	{
#ifdef HZ_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif
	}

	Ref<Renderer2D> Renderer2D::Init()
	{
		return CreateRef<Renderer2D>();

	}

	void Renderer2D::OnUpdate()
	{
		Draw();
	}

	void Renderer2D::BindVertexBuffer(float* positions, uint32_t start, uint32_t stride, void* offset)
	{
		GLCall(glGenVertexArrays(1, &s_Data.s_VAO));
		GLCall(glBindVertexArray(s_Data.s_VAO));

		GLCall(glGenBuffers(1,&s_Data.s_VBO));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, s_Data.s_VBO));
		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, positions, GL_STATIC_DRAW));
		
		GLCall(glEnableVertexAttribArray(0));
		GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (GLvoid*)0));
		GLCall(glBindVertexArray(s_Data.s_VAO));
		
	}
	void Renderer2D::BindIndexBuffer()
	{
	}
	void Renderer2D::CreateBuffer(uint32_t& buffer)
	{
		
	}
	Renderer2DData Renderer2D::LoadShaders()
	{
		s_Data.Shader = Shader::Create("assets/shaders/fragment.glsl");

		return s_Data;
	}

	void Renderer2D::Draw()
	{	
		BindShaders();
		GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		GLCall(glDrawArrays(GL_TRIANGLES, 0, 3));
		
		
	}

	void Renderer2D::BindShaders()
	{
		s_Data.Shader->Bind();
	}


}