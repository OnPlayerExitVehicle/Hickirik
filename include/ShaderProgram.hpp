#pragma once

#include "DefaultDefinitons.hpp"
#include <fstream>
#include <GLM/mat3x3.hpp>
#define PROGRAMMABLE_SHADER_COUNT 5

namespace Hickirik
{
    namespace Shaders
    {
        class ShaderProgram
        {
        private:
            unsigned int m_id;
            int m_shaderIds[PROGRAMMABLE_SHADER_COUNT];
            int m_shaderCount;
            unsigned int m_transformMatrixId;
            unsigned int m_viewMatrixId;
            unsigned int m_projectionMatrixId;
            
            const std::string transformMatrixName   = "transformMatrix";
            const std::string viewMatrixName        = "viewMatrix";
            const std::string projectionMatrixName  = "projectionMatrix";
        public:
            ShaderProgram();
            void AttachShader(const std::string& address, unsigned int type);
            void Link();
            void Use();
            void SendTransformMatrix(const glm::mat3& matrix);

            void SendTransformMatrix(const glm::mat4& matrix);
            void SendViewMatrix(const glm::mat4& matrix);
            void SendProjectionMatrix(const glm::mat4& matrix);
        };
    }
}