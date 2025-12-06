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

 void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, std::shared_ptr<Shader> shader)
 {
  shader->Bind();
  shader->UploadUniformMat4("u_ViewProjection", m_SceneData->ViewProjectionMatrix);
  
  vertexArray->Bind();
  RenderCommand::DrawIndexed(vertexArray);
 }
}
