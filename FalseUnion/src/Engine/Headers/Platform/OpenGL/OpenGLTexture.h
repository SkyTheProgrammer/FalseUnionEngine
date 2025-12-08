#pragma once
#include "OpenGLShader.h"
#include "../../Graphics/Texture.h"
namespace FalseUnion
{

    class OpenGLTexture2D : public Texture2D
    {
        public:
        OpenGLTexture2D(const std::string& path);
        OpenGLTexture2D(uint32_t width, uint32_t height);
        virtual ~OpenGLTexture2D();

        virtual uint32_t GetWidth() const override {return m_Width;}
        virtual uint32_t GetHeight() const override {return m_Height;}

        void SetData(void* data, uint32_t size) override;
        
        virtual void Bind(uint32_t slot) const override;

    private:
        std::string m_Path; // Path to texture
        uint32_t m_Width, m_Height; // Textures width and height.
        uint32_t m_RendererID; // Int for renderer id
        GLenum m_InternalFormat, m_DataFormat;
    };
}
