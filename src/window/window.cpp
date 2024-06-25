#include "window.hpp"
#include "../util/log.hpp"
#include "GLFW/glfw3.h"

Window::Window (std::string title, int width, int height) : width (width), height (height) {
    glfwInit ();
    glfwWindowHint (GLFW_CLIENT_API, GLFW_NO_API);

    // glfwWindowHint (GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow (width, height, title.c_str (), nullptr, nullptr);

    if (!window) {
        Log::Warn ("Window failed to instantiate.");
    }

    glfwMakeContextCurrent (window);
}

Window::~Window () {
    glfwDestroyWindow (window);
    glfwTerminate ();
}

/**
 * @brief Poll the window to check if its alive. Takes in a reference to a double to track deltatime.
 * @param dt double&
 * @return boolean
 */
bool Window::Alive (double& dt) {
    float delta = glfwGetTime () - m_FrameTime;
    dt          = delta * 1000;

    m_FrameTime = glfwGetTime ();

    for (auto bind : m_Keybinds) {
        bool keyUp = glfwGetKey (window, bind.first.first) == GLFW_RELEASE;

        if (bind.first.second) {
            // Fire once
            if (m_Keybind_Debounce.contains (bind.first.first)) {

                if (m_Keybind_Debounce.at (bind.first.first) == keyUp) {
                    m_Keybind_Debounce.at (bind.first.first) = !keyUp;
                    bind.second (keyUp);
                }
            }
        } else {
            bind.second (keyUp);
        }
    }

    glfwGetWindowSize (window, &width, &height);
    glfwSwapBuffers (window);
    glfwPollEvents ();
    return !glfwWindowShouldClose (window);
}


GLFWwindow* Window::GetWindow () { return window; }
