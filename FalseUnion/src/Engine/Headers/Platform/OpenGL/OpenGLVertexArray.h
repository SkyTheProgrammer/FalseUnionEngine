#pragma once

#include "../../Graphics/VertexArray.h"

namespace FalseUnion
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray() = default;
        
        void Bind() const override;
        void Unbind() const override;
        void AddVertexBuffer(std::shared_ptr<VertexBuffer> vertexBuffer) override;
        void SetIndexBuffer(std::shared_ptr<IndexBuffer> indexBuffer) override;
        const std::shared_ptr<IndexBuffer>& GetIndexBuffer() override;

    private:
        uint32_t m_RendererID;
        std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;
    };
}
