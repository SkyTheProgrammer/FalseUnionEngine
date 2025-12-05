// //
// // Created by SkyTFB on 10/7/2025.
// //
//
 #include "fupch.h"
#include "../../Headers/Graphics/Renderer.h"

namespace FalseUnion
{
 void Renderer::BeginScene()
 {
 }

 void Renderer::EndScene()
 {
 }

 void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
 {
  vertexArray->Bind();
  RenderCommand::DrawIndexed(vertexArray);
 }
}
