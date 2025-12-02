#pragma once
#include "../../Graphics/Buffer.h"

namespace FalseUnion
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        virtual ~OpenGLVertexBuffer();
        OpenGLVertexBuffer(float* vertices, uint32_t size);

        void Bind() const override;
        void Unbind() const override;

        const BufferLayout& GetLayout() const override
        {
            return m_Layout;
        }
        void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

    private:
        uint32_t m_RendererID;
        BufferLayout m_Layout;
    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        virtual ~OpenGLIndexBuffer();
        OpenGLIndexBuffer(uint32_t* indices, uint32_t size);

        void Bind() const override;
        void Unbind() const override;
        
        uint32_t GetCount() const override { return m_Count; };

    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}
