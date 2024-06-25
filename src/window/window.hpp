#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <functional>

class Window {
  public:
    Window (std::string title, int width, int height);
    ~Window ();

    bool Alive (double& time);
    GLFWwindow* GetWindow ();

    inline void BindKey (int keycode, bool fireOnce, std::function<void (bool)> fn) {
        m_Keybinds.push_back ({ { keycode, fireOnce }, fn });

        if (fireOnce) {
            m_Keybind_Debounce.insert ({ keycode, false });
        }
    };

    int height, width;

  private:
    std::vector<std::pair<std::pair<int, bool>, std::function<void (bool)>>> m_Keybinds;
    std::unordered_map<int, bool> m_Keybind_Debounce;

    float m_FrameTime = glfwGetTime ();
    GLFWwindow* window;
};