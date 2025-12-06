// //
// // Created by SkyTFB on 10/7/2025.
// //
//
 #include "fupch.h"
#include "../../Headers/Graphics/Renderer.h"

namespace FalseUnion
{
 Renderer::SceneData* Renderer::m_SceneData = new SceneData;
 
 void Renderer::BeginScene(OrthographicCamera& camera)
 {
   m_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
 }

 void Renderer::EndScene()
 {
 }

 void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, const glm::mat4& transform)
 {
  shader->Bind();
  shader->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
  shader->UploadUniformMat4("u_Transform", transform);
  
  vertexArray->Bind();
  RenderCommand::DrawIndexed(vertexArray);
 }
}
