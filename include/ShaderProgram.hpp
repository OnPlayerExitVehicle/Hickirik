#pragma once

#include "DefaultDefinitons.hpp"
#include <fstream>

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
        public:
            ShaderProgram();
            void AttachShader(const std::string& address, uint type);
        };
    }
}