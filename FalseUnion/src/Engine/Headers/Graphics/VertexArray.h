#pragma once

#include "Buffer.h"
#include <memory>


namespace FalseUnion
{
    class VertexArray
    {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void AddVertexBuffer(Ref<VertexBuffer> vertexBuffer) = 0;
        virtual void SetIndexBuffer(Ref<IndexBuffer> indexBuffer)  = 0;
        virtual const Ref<IndexBuffer>& GetIndexBuffer() = 0;

        static VertexArray* Create();
    };
}
