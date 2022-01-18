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
            uint m_id;
            int m_shaderIds[PROGRAMMABLE_SHADER_COUNT];
            int m_shaderCount;
            uint m_transformMatrixId;
            
            const std::string matrixName = "transformMatrix";
        public:
            ShaderProgram();
            void AttachShader(const std::string& address, uint type);
            void Link();
            void Use();
            void SendTransformMatrix(const glm::mat3& matrix);
            void SendTransformMatrix(const glm::mat4& matrix);
        };
    }
}