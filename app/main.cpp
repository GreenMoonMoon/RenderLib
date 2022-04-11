#include "renderer/gl.h"

int main() {
    auto window = initialize();
    print_gl_infos();
    cleanup(window);

    return 0;
}
