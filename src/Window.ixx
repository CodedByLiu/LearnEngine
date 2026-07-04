module;

#include <GLFW/glfw3.h>
#include <string>

export module Window;

import Log;

static GLFWwindow* s_window = nullptr;

static void GLFWErrorCallback(int code, const char* description)
{
    LogError(std::string("GLFW 错误: (") + std::to_string(code) + "): " + description);
}

export void WindowInit(int width, int height, const std::string& title)
{
    glfwSetErrorCallback(GLFWErrorCallback);
    glfwInit();

    s_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!s_window) {LogError("窗口创建失败! "); return;}

    glfwMakeContextCurrent(s_window);
    glfwSwapInterval(1);

    LogInfo("窗口创建成功! ");
}

export bool WindowShouldClose()
{
    return glfwWindowShouldClose(s_window);
}

export void WindowClear(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

export void WindowUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(s_window);
}

export void WindowShutdown()
{
    glfwDestroyWindow(s_window);
    glfwTerminate();
}