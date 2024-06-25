#include "util/log.hpp"
#include "window/window.hpp"
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <string>

int main () {
    // Window Obj
    Window window ("GL Engine", 1200, 800);

    // Keybinds
    window.BindKey (GLFW_KEY_G, true, [&] (bool up) {
        if (!up)
            Log::Warn ("G PRESSED");
    });

    // Runtime
    double deltaTime;
    while (window.Alive (deltaTime)) {
        // Log::Ok (std::to_string (deltaTime));
    }

    return 0;
}
