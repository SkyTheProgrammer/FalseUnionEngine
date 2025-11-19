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

    private:
        uint32_t m_RendererID;
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
