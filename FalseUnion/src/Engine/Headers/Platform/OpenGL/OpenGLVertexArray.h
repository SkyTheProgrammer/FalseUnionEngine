#pragma once

#include "../../Graphics/VertexArray.h"

namespace FalseUnion
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();
        
        void Bind() const override;
        void Unbind() const override;
        void AddVertexBuffer(Ref<VertexBuffer> vertexBuffer) override;
        void SetIndexBuffer(Ref<IndexBuffer> indexBuffer) override;
        const Ref<IndexBuffer>& GetIndexBuffer() override;

    private:
        uint32_t m_RendererID;
        std::vector<Ref<VertexBuffer>> m_VertexBuffers;
        Ref<IndexBuffer> m_IndexBuffer;
    };
}
