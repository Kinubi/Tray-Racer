#pragma once

#include "Shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall())


namespace TrayRacer {

	static void GLClearError()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	static bool GLLogCall()
	{
		while (GLenum error = glGetError())
		{
			HZ_CORE_TRACE("OpenGL error {0}", error);
			return false;
		}
		return true;
	}

	struct Renderer2DData
	{
		Ref<Shader> Shader;

		uint32_t s_VBO, s_VAO;
	};

	class Renderer2D
	{
	public:
		Renderer2D();

		static Ref<Renderer2D> Init();

		static void OnUpdate();

		static void BindVertexBuffer(float* positions, uint32_t start, uint32_t stride, void* offset);

		static void BindIndexBuffer();

		static void CreateBuffer(uint32_t& buffer);

		static Renderer2DData LoadShaders();

		static void Draw();

		static void BindShaders();
		
	};

}