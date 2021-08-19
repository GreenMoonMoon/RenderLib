#include "app.h"
#include "mesh.h"
#include "shader.h"

using namespace renderlib;

int main() {
    Window window = Window();

    Mesh cube = Cube(1, 1, 1);
    Shader shader = Shader();
    shader.LoadFromFile(
            R"(./shader/basic.vert)",
            R"(./shader/basic.frag)"
    );

    while (!window.ShouldClose()) {
        cube.Draw(shader);
        window.Update();
    }

    window.Close();
    return 0;
}
