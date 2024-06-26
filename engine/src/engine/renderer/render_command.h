#pragma once

#include "engine/core/core.h"
#include "rendererAPI.h"

namespace prime {

	class RenderCommand
	{
	public:
		static void SetClearColor(const glm::vec4& color)
		{
			s_rendererAPI->SetClearColor(color);
		}

		static void Clear()
		{
			s_rendererAPI->Clear();
		}
		
		static void Submit(const Ref<VertexArray>& vertexArray, uint32_t indexCount)
		{
			vertexArray->Bind();
			s_rendererAPI->Submit(vertexArray, indexCount);
		}

		static void SubmitLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount)
		{
			vertexArray->Bind();
			s_rendererAPI->SubmitLines(vertexArray, vertexCount);
		}

		static void SetViewport(uint32_t width, uint32_t height)
		{
			if (width > 0 && height > 0) { s_rendererAPI->SetViewport(width, height); }
		}

	private:
		static void Init()
		{
			if (!s_rendererAPI.get()) { s_rendererAPI = RendererAPI::Create(); }
			s_rendererAPI->Init();
		}

	private:
		PINLINE static std::unique_ptr<RendererAPI> s_rendererAPI;
		friend class Engine;
	};
}