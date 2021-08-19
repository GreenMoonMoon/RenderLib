//
// Created by jboisvert on 2021-07-15.
//

#ifndef RENDERLIB_APP_H
#define RENDERLIB_APP_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace renderlib {
    class Window {
    public:
        GLFWwindow *window;
    public:
        Window();
        void Update() const;
        [[nodiscard]] bool ShouldClose() const;
        void ProcessInput() const;
        void Close();
    };
}

#endif //RENDERLIB_APP_H
