#include "renderlib.h"

using namespace renderlib;

int main() {
    auto window = initialize("Example App", 800, 600);
    set_clear_color(0.2f, 0.2f, 0.2f, 1.0f);

    //TODO: encapsulate this in a class
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
