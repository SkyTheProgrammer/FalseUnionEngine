// //
// // Created by SkyTFB on 10/7/2025.
// //
//
 #include "fupch.h"
#include "../../Headers/Graphics/Renderer.h"

#include "../../Headers/Platform/OpenGL/OpenGLShader.h"

namespace FalseUnion
{
 Renderer::SceneData* Renderer::m_SceneData = new SceneData;

 void Renderer::Init()
 {
  RenderCommand::Init();
 }

 void Renderer::BeginScene(OrthographicCamera& camera)
 {
   m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
 }

 void Renderer::EndScene()
 {
 }

 void Renderer::Submit(const Ref<VertexArray>& vertexArray, const Ref<Shader>& shader, const glm::mat4& transform)
 {
  shader->Bind();
  std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
  std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);
  
  vertexArray->Bind();
  RenderCommand::DrawIndexed(vertexArray);
 }
}
